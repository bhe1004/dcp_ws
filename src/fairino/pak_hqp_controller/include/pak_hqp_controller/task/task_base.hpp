#pragma once

#include <Eigen/Dense>
#include <string>
#include "pak_hqp_controller/task/constraint_base.hpp"
#include "pak_hqp_controller/robot/robot_wrapper.hpp"

namespace pak_hqp_controller {
    namespace task {

        /// Task의 추상 base 클래스 (EE, Posture, Singularity 등 모든 Task는 여기서 상속)
        class TaskBase {
        public:
            using ConstraintBase = pak_hqp_controller::task::ConstraintBase;
            using RobotWrapper = pak_hqp_controller::robot::RobotWrapper;

            TaskBase(const std::string& name, RobotWrapper& robot)
                : name_(name), robot_(robot) {}

            virtual ~TaskBase() {}

            /// Task의 이름
            const std::string& name() const { return name_; }
            void setName(const std::string& name) { name_ = name; }

            /// Task의 차원 (예: EE pose는 6, joint posture는 n 등)
            virtual int dim() const = 0;

            /**
             * @brief 제약 행렬/벡터를 계산해서 Constraint로 반환
             * @param t    현재 시각
             * @param q    현재 joint position
             * @param v    현재 joint velocity
             * @return     QP 제약(혹은 cost) 객체
             */
            virtual const ConstraintBase& compute(double t,
                                                const Eigen::VectorXd& q,
                                                const Eigen::VectorXd& v) = 0;

            /// 마지막으로 계산된 제약 반환
            virtual const ConstraintBase& getConstraint() const = 0;

        protected:
            std::string name_;
            RobotWrapper& robot_;   // 로봇 모델, kinematics, jacobian 등 접근
        };

    } // namespace task
} // namespace pak_hqp_controller
