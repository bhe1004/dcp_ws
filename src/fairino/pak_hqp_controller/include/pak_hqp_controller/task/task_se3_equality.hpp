#pragma once

#include "pak_hqp_controller/task/task_base.hpp"
#include <pinocchio/spatial/se3.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <Eigen/Dense>
#include <string>

namespace pak_hqp_controller {
    namespace task {

        class TaskSE3Equality : public TaskBase {
            public:
                // 생성자: task 이름, 로봇 wrapper, 트래킹할 frame 이름, (필요시) EE 오프셋
                TaskSE3Equality(const std::string& name,
                                RobotWrapper& robot,
                                const std::string& frame_name,
                                const Eigen::Vector3d& offset = Eigen::Vector3d::Zero());

                virtual ~TaskSE3Equality() {}

                // EE pose는 6차원 (position 3, orientation 3)
                int dim() const override { return 6; }

                // ref_pose는 pinocchio::SE3 타입 (tracking goal)
                void setReference(const pinocchio::SE3& ref_pose);

                // gain 조절 (position/orientation 별도)
                void setGains(double pos_gain, double ori_gain);

                // QP 제약 계산 (t, q, v 입력)
                const ConstraintBase& compute(double t,
                                            const Eigen::VectorXd& q,
                                            const Eigen::VectorXd& v) override;

                const ConstraintBase& getConstraint() const override { return constraint_; }

            protected:
                std::string frame_name_;
                Eigen::Vector3d offset_;       // EE 오프셋 (있을 경우)
                pinocchio::SE3 ref_pose_;      // EE 목표 pose
                double pos_gain_;              // 위치 gain
                double ori_gain_;              // 자세 gain

                int frame_id_;                 // 핀오키오 frame id

                ConstraintBase constraint_;    // 마지막 계산한 제약
        };

    } // namespace task
} // namespace pak_hqp_controller
