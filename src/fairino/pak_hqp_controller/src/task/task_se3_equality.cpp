#include "pak_hqp_controller/task/task_se3_equality.hpp"
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/kinematics.hpp>

namespace pak_hqp_controller {
    namespace task {

        TaskSE3Equality::TaskSE3Equality(const std::string& name,
                                        RobotWrapper& robot,
                                        const std::string& frame_name,
                                        const Eigen::Vector3d& offset)
            : TaskBase(name, robot)
            , frame_name_(frame_name)
            , offset_(offset)
            , pos_gain_(200.0)
            , ori_gain_(100.0)
            , ref_pose_(pinocchio::SE3::Identity())
            , constraint_(name, ConstraintType::Equality, Eigen::MatrixXd::Zero(6, robot.dof()), Eigen::VectorXd::Zero(6))
        {
            // frame_id는 생성자에서 lookup
            frame_id_ = robot.model().getFrameId(frame_name_);
        }

        void TaskSE3Equality::setReference(const pinocchio::SE3& ref_pose) {
            ref_pose_ = ref_pose;
        }

        void TaskSE3Equality::setGains(double pos_gain, double ori_gain) {
            pos_gain_ = pos_gain;
            ori_gain_ = ori_gain;
        }

        const ConstraintBase& TaskSE3Equality::compute(double t,
                                                    const Eigen::VectorXd& q,
                                                    const Eigen::VectorXd& v)
        {
            // 1. 핀오키오로 frame 위치 계산
            auto& model = robot_.model();
            auto& data  = robot_.data();

            // Forward kinematics + frames update
            pinocchio::forwardKinematics(model, data, q);
            pinocchio::updateFramePlacements(model, data);

            // 2. 현재 EE pose (SE3)
            const pinocchio::SE3& current_pose = data.oMf[frame_id_];
            // (필요시 offset 적용: current_pose * offset)

            // 3. log맵으로 목표-현재 pose 차이 6D twist
            pinocchio::SE3 dMi = current_pose.inverse() * ref_pose_;
            pinocchio::Motion err_se3 = pinocchio::log6(dMi);

            Eigen::VectorXd x_dot_des = err_se3.toVector();
            x_dot_des.head<3>() *= pos_gain_;
            x_dot_des.tail<3>() *= ori_gain_;

            // 4. EE Jacobian 계산 (6 x nq)
            Eigen::MatrixXd J(6, model.nv);
            pinocchio::computeFrameJacobian(model, data, q, frame_id_, pinocchio::LOCAL, J);

            // 5. QP equality 제약: J * dq = x_dot_des
            // ConstraintBase(name, Equality, J, x_dot_des)
            constraint_ = ConstraintBase(name_, ConstraintType::Equality, J, x_dot_des);

            // std::cout<< "[task_se3]" << std::endl;

            return constraint_;
        }

    } // namespace task
} // namespace pak_hqp_controller
