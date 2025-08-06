#pragma once

#include "pak_hqp_controller/task/task_base.hpp"
#include <pinocchio/spatial/se3.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <Eigen/Dense>
#include <string>

namespace pak_hqp_controller {
    namespace task {

        class TaskOnlyYawFree : public TaskBase {
            public:
                // 생성자: task 이름, 로봇 wrapper, 프레임 이름
                TaskOnlyYawFree(const std::string& name,
                                       RobotWrapper& robot,
                                       const std::string& frame_name);

                virtual ~TaskOnlyYawFree() {}

                // orientation 2D (roll/pitch)만 제약
                int dim() const override { return 2; }

                // ref_pose는 pinocchio::SE3 타입 (tracking goal)
                void setReference(const pinocchio::SE3& ref_pose);

                // gain 조절 (orientation)
                void setGain(double ori_gain);

                // QP 제약 계산 (t, q, v 입력)
                const ConstraintBase& compute(double t,
                                              const Eigen::VectorXd& q,
                                              const Eigen::VectorXd& v) override;

                const ConstraintBase& getConstraint() const override { return constraint_; }

            protected:
                std::string frame_name_;
                pinocchio::SE3 ref_pose_;      // EE 목표 pose (orientation만 사용)
                double ori_gain_;              // 자세 gain

                int frame_id_;                 // 핀오키오 frame id

                ConstraintBase constraint_;    // 마지막 계산한 제약
        };

    } // namespace task
} // namespace pak_hqp_controller
