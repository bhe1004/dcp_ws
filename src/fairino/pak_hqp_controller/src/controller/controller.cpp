#include "pak_hqp_controller/controller/controller.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

namespace pak_hqp_controller {
    namespace controller {

        Controller::Controller(robot::RobotWrapper& robot)
            : robot_(robot)
            , dof_(robot.dof())
        {
        }

        void Controller::addTask(std::shared_ptr<task::TaskBase> task, int priority)
        {
            task_stack_[priority].push_back(task);
        }

        void Controller::removeTask(const std::string& name)
        {
            for (auto& level : task_stack_) {
                auto& tasks = level.second;
                tasks.erase(
                    std::remove_if(tasks.begin(), tasks.end(),
                        [&](const std::shared_ptr<task::TaskBase>& t) { return t->name() == name; }),
                    tasks.end());
            }
        }

        Eigen::VectorXd Controller::compute(double t, const Eigen::VectorXd& q, const Eigen::VectorXd& v)
        {
            // 1. 우선순위(priority) 순 정렬 (보통 0,1,2... 작은 숫자가 가장 상위계층)
            std::vector<int> levels;
            for (const auto& kv : task_stack_)
                levels.push_back(kv.first);
            std::sort(levels.begin(), levels.end());

            int n_levels = levels.size();
            if (n_levels == 0) {
                std::cerr << "[Controller] No task in HQP stack!" << std::endl;
                return Eigen::VectorXd::Zero(dof_);
            }
            if (n_levels == 1) {
                // 단일 QP
                std::vector<const task::ConstraintBase*> constraints;
                for (const auto& task_ptr : task_stack_[levels[0]])
                    constraints.push_back(&task_ptr->compute(t, q, v));
                return solver_.solve(constraints, dof_);
            }

            // --- 3계층 HQP ---
            // [각 단계에서: dq = dq_prev + N_prev * dq_current]
            Eigen::VectorXd dq_total = Eigen::VectorXd::Zero(dof_);
            Eigen::MatrixXd N_prev = Eigen::MatrixXd::Identity(dof_, dof_);

            for (size_t l = 0; l < n_levels; ++l) {
                // 1. 이번 계층의 모든 제약 뽑기
                std::vector<const task::ConstraintBase*> constraints;
                for (const auto& task_ptr : task_stack_[levels[l]])
                    constraints.push_back(&task_ptr->compute(t, q, v));

                // 2. QP 풀기
                Eigen::VectorXd dq_l = solver_.solve(constraints, dof_);

                // 3. null-space projector 계산 (계층 마지막이면 생략)
                Eigen::MatrixXd J_l;
                if (!constraints.empty()) {
                    int n_row = 0;
                    for (auto* c : constraints) n_row += c->A().rows();
                    J_l = Eigen::MatrixXd::Zero(n_row, dof_);
                    int row = 0;
                    for (auto* c : constraints) {
                        int m = c->A().rows();
                        J_l.block(row, 0, m, dof_) = c->A();
                        row += m;
                    }
                } else {
                    J_l = Eigen::MatrixXd::Zero(0, dof_);
                }

                Eigen::MatrixXd N_l = Eigen::MatrixXd::Identity(dof_, dof_);
                if (J_l.rows() > 0) {
        #if EIGEN_VERSION_AT_LEAST(3, 4, 0)
                    Eigen::MatrixXd J_pinv = J_l.completeOrthogonalDecomposition().pseudoInverse();
        #else
                    Eigen::JacobiSVD<Eigen::MatrixXd> svd(J_l, Eigen::ComputeThinU | Eigen::ComputeThinV);
                    double tol = 1e-8 * std::max(J_l.cols(), J_l.rows()) * svd.singularValues().array().abs().maxCoeff();
                    Eigen::MatrixXd S = svd.singularValues().asDiagonal();
                    for (int i = 0; i < S.diagonal().size(); ++i)
                        if (S.diagonal()(i) < tol) S.diagonal()(i) = 0;
                        else S.diagonal()(i) = 1.0 / S.diagonal()(i);
                    Eigen::MatrixXd J_pinv = svd.matrixV() * S * svd.matrixU().adjoint();
        #endif
                    N_l = Eigen::MatrixXd::Identity(dof_, dof_) - J_pinv * J_l;
                }

                // 4. 누적 solution 업데이트: dq = dq + N_prev * dq_l
                dq_total = dq_total + N_prev * dq_l;

                // 5. null-space projector 업데이트 (다음 계층을 위해)
                N_prev = N_prev * N_l;
            }

            return dq_total;
        }

    } // namespace controller
} // namespace pak_hqp_controller
