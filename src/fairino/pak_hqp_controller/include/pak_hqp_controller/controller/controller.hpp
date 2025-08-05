#pragma once

#include <vector>
#include <map>
#include <memory>
#include <Eigen/Dense>
#include "pak_hqp_controller/robot/robot_wrapper.hpp"
#include "pak_hqp_controller/task/task_base.hpp"
#include "pak_hqp_controller/solver/solver.hpp"

namespace pak_hqp_controller {
    namespace controller {

        // 계층별 Task 리스트: (priority = 0,1,2,...)
        using TaskStack = std::map<int, std::vector<std::shared_ptr<task::TaskBase>>>;

        class Controller {
        public:
            Controller(robot::RobotWrapper& robot);

            void addTask(std::shared_ptr<task::TaskBase> task, int priority);
            void removeTask(const std::string& name);

            // 3계층 HQP 제어입력 계산 (dq)
            Eigen::VectorXd compute(double t, const Eigen::VectorXd& q, const Eigen::VectorXd& v);

            const TaskStack& getTaskStack() const { return task_stack_; }

        protected:
            robot::RobotWrapper& robot_;
            solver::Solver solver_;
            TaskStack task_stack_;
            int dof_;
        };

    } // namespace controller
} // namespace pak_hqp_controller
