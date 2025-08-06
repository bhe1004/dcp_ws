#include "pak_hqp_controller/task/task_only_yaw_free.hpp"
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/spatial/se3.hpp>

namespace pak_hqp_controller {
    namespace task {

        // 생성자: 제약을 걸 프레임 이름(frame_name)을 받아서 초기화
        TaskOnlyYawFree::TaskOnlyYawFree(const std::string& name,
                                                       RobotWrapper& robot,
                                                       const std::string& frame_name)
            : TaskBase(name, robot)
            , frame_name_(frame_name)
            , ori_gain_(100.0)
            , ref_pose_(pinocchio::SE3::Identity())
            , constraint_(name, ConstraintType::Equality, Eigen::MatrixXd::Zero(2, robot.dof()), Eigen::VectorXd::Zero(2))
        {
            // 프레임 이름을 기반으로 frame_id를 피노키오 모델에서 찾음
            frame_id_ = robot.model().getFrameId(frame_name_);
        }

        // 목표 orientation(보통 "비커를 집을 때"의 orientation)을 저장
        void TaskOnlyYawFree::setReference(const pinocchio::SE3& ref_pose) {
            ref_pose_ = ref_pose;
        }

        // orientation gain(오차에 곱해지는 계수) 조정
        void TaskOnlyYawFree::setGain(double ori_gain) {
            ori_gain_ = ori_gain;
        }

        // QP에 넣을 yaw-free(roll/pitch 유지) orientation 제약 계산
        const ConstraintBase& TaskOnlyYawFree::compute(double t,
                                                              const Eigen::VectorXd& q,
                                                              const Eigen::VectorXd& v)
        {
            auto& model = robot_.model();
            auto& data  = robot_.data();

            // 1. (필수) joint값 q로 forward kinematics, 프레임 위치 업데이트
            pinocchio::forwardKinematics(model, data, q);
            pinocchio::updateFramePlacements(model, data);

            // 2. 현재 EE의 SE3 pose 얻기 (base -> ee)
            const pinocchio::SE3& current_pose = data.oMf[frame_id_];

            // 3. yaw(월드 기준 z축 회전)만 제외한 rotation을 만드는 함수 정의
            auto removeYaw = [](const Eigen::Matrix3d& R) {
                Eigen::Vector3d world_z = Eigen::Vector3d::UnitZ(); // 월드 z축 단위벡터
                // R의 x축에서 z축 성분만 빼고 정규화(수평 평면 투영)
                Eigen::Vector3d x_proj = R.col(0) - R.col(0).dot(world_z) * world_z;
                // 만약 x_proj가 너무 작으면(특이점 회피) y축 사용
                if (x_proj.norm() < 1e-8) x_proj = R.col(1) - R.col(1).dot(world_z) * world_z;
                x_proj.normalize();
                // 새 y축: z축과 x축의 외적
                Eigen::Vector3d y_proj = world_z.cross(x_proj);
                // 새 회전행렬: x_proj, y_proj, world_z로 구성 (yaw 성분만 제거)
                Eigen::Matrix3d R_no_yaw;
                R_no_yaw.col(0) = x_proj;
                R_no_yaw.col(1) = y_proj;
                R_no_yaw.col(2) = world_z;
                return R_no_yaw;
            };

            // 4. 현재 pose와 목표 pose(집을 때 orientation)에서 yaw만 제거
            Eigen::Matrix3d R_current_no_yaw = removeYaw(current_pose.rotation());
            Eigen::Matrix3d R_ref_no_yaw = removeYaw(ref_pose_.rotation());

            // 5. 두 "yaw-free" rotation 사이의 오차(R_err)를 SO(3) 로그맵(log3)으로 계산
            Eigen::Matrix3d R_err = R_current_no_yaw.transpose() * R_ref_no_yaw;
            Eigen::Vector3d ori_error = pinocchio::log3(R_err); // [roll, pitch, yaw] 오차 벡터

            // 6. roll/pitch 오차(=ori_error의 x, y 성분)만 QP 제약에 사용
            Eigen::VectorXd x_dot_des = Eigen::VectorXd::Zero(2);
            x_dot_des = ori_gain_ * ori_error.head<2>(); // [roll, pitch] error * gain

            // 7. EE Jacobian 계산 (6 x nq, 상위 3행: 선형속도, 하위 3행: 각속도)
            Eigen::MatrixXd J_full(6, model.nv);
            pinocchio::computeFrameJacobian(model, data, q, frame_id_, pinocchio::LOCAL, J_full);

            // 8. Jacobian의 angular part(각속도, 마지막 3행)에서 roll/pitch(x, y)만 뽑음
            Eigen::MatrixXd J_ori = J_full.bottomRows(3).topRows(2); // (3, nq)에서 상위 2행

            // 9. QP equality 제약 생성: J_ori * dq = x_dot_des (roll/pitch 제약)
            constraint_ = ConstraintBase(name_, ConstraintType::Equality, J_ori, x_dot_des);

            return constraint_;
        }

    } // namespace task
} // namespace pak_hqp_controller
