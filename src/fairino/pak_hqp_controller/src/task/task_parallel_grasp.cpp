#include "pak_hqp_controller/task/task_parallel_grasp.hpp"
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/kinematics.hpp>

namespace pak_hqp_controller {
    namespace task {

        TaskParallelGrasp::TaskParallelGrasp(const std::string& name,
                                             RobotWrapper& robot,
                                             const std::string& frame_name,
                                             const Eigen::Vector3d& offset)
            : TaskBase(name, robot)
            , frame_name_(frame_name)
            , offset_(offset)
            , pos_gain_(200.0)
            , ori_gain_(100.0)
            , ref_pose_(pinocchio::SE3::Identity())
            , base_pos_(Eigen::Vector3d::Zero())
            , constraint_(name, ConstraintType::Equality, Eigen::MatrixXd::Zero(6, robot.dof()), Eigen::VectorXd::Zero(6))
        {
            // frame_id는 생성자에서 lookup
            frame_id_ = robot.model().getFrameId(frame_name_);
        }

        void TaskParallelGrasp::setReference(const pinocchio::SE3& ref_pose) {
            ref_pose_ = ref_pose;
        }

        void TaskParallelGrasp::setBasePosition(const Eigen::Vector3d& base_pos) {
            base_pos_ = base_pos;
        }

        void TaskParallelGrasp::setGains(double pos_gain, double ori_gain) {
            pos_gain_ = pos_gain;
            ori_gain_ = ori_gain;
        }

        const ConstraintBase& TaskParallelGrasp::compute(double t,
                    const Eigen::VectorXd& q,
                    const Eigen::VectorXd& v)
        {
            auto& model = robot_.model();
            auto& data  = robot_.data();

            // Forward kinematics + frames update
            pinocchio::forwardKinematics(model, data, q);
            pinocchio::updateFramePlacements(model, data);

            // 현재 EE pose (SE3)
            const pinocchio::SE3& current_pose = data.oMf[frame_id_];

            // (1) 정면 접근: base → 목표 위치 벡터(정규화)
            Eigen::Vector3d approach_dir = (base_pos_ - ref_pose_.translation()).normalized();

            // (2) 그리퍼 x축 (집는 방향)
            Eigen::Vector3d gripper_x = current_pose.rotation().col(0);

            // (3) 정렬 오차 (외적)
            Eigen::Vector3d align_err = gripper_x.cross(approach_dir);

            // (4) 오직 orientation(방향 정렬)만 QP 제약
            Eigen::VectorXd x_dot_des = Eigen::VectorXd::Zero(6);
            // x_dot_des.head<3>().setZero(); // position은 제약하지 않음
            x_dot_des.tail<3>() = align_err * ori_gain_;

            // (5) EE Jacobian 계산 (6 x nq)
            Eigen::MatrixXd J(6, model.nv);
            pinocchio::computeFrameJacobian(model, data, q, frame_id_, pinocchio::LOCAL, J);

            // (6) QP equality 제약: J * dq = x_dot_des
            constraint_ = ConstraintBase(name_, ConstraintType::Equality, J, x_dot_des);

            std::cout << "[TaskParallelGrasp] approach_dir: " << approach_dir.transpose() << std::endl;

            return constraint_;
        }

    } // namespace task
} // namespace pak_hqp_controller
