#pragma once

#include "pak_hqp_controller/task/task_base.hpp"
#include <pinocchio/spatial/se3.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <Eigen/Dense>
#include <string>

namespace pak_hqp_controller {
    namespace task {

        // "Parallel Grasp" (정면 접근, 물체 orientation 무시) 태스크
        class TaskParallelGrasp : public TaskBase {
            public:
                // 생성자: 태스크 이름, 로봇 wrapper, 트래킹할 EE frame 이름, (필요시) EE 오프셋
                TaskParallelGrasp(const std::string& name,
                                  RobotWrapper& robot,
                                  const std::string& frame_name,
                                  const Eigen::Vector3d& offset = Eigen::Vector3d::Zero());

                virtual ~TaskParallelGrasp() {}

                // 태스크 차원 (위치3 + 정렬3)
                int dim() const override { return 6; }

                // 목표 pose(translation만 사용, orientation 무시)
                void setReference(const pinocchio::SE3& ref_pose);

                // 로봇 base의 월드 기준 위치 입력 (정면 접근 벡터 계산용)
                void setBasePosition(const Eigen::Vector3d& base_pos);

                // gain 조절 (position/orientation 정렬 별도)
                void setGains(double pos_gain, double ori_gain);

                // QP 제약 계산 (t, q, v 입력)
                const ConstraintBase& compute(double t,
                                              const Eigen::VectorXd& q,
                                              const Eigen::VectorXd& v) override;

                const ConstraintBase& getConstraint() const override { return constraint_; }

            protected:
                std::string frame_name_;
                Eigen::Vector3d offset_;         // EE 오프셋 (있을 경우)
                pinocchio::SE3 ref_pose_;        // EE 목표 pose (orientation 무시)
                Eigen::Vector3d base_pos_;       // 로봇 base 위치 (월드 기준)

                double pos_gain_;                // 위치 gain
                double ori_gain_;                // 정렬(orientation) gain

                int frame_id_;                   // 핀오키오 frame id

                ConstraintBase constraint_;      // 마지막 계산한 제약
        };

    } // namespace task
} // namespace pak_hqp_controller
