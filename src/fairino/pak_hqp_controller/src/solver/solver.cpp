#include "pak_hqp_controller/solver/solver.hpp"
#include <eiquadprog/eiquadprog.hpp>
#include <iostream>

namespace pak_hqp_controller {
    namespace solver {

        Eigen::VectorXd Solver::solve(
            const std::vector<const task::ConstraintBase*>& constraints,
            int dof)
        {
            // 1. Cost, Equality, Inequality 분류 및 스택
            Q_ = Eigen::MatrixXd::Identity(dof, dof) * 1e-8; // 작은 regularizer
            c_ = Eigen::VectorXd::Zero(dof);

            std::vector<const task::ConstraintBase*> cost_constraints;
            std::vector<const task::ConstraintBase*> eq_constraints;
            std::vector<const task::ConstraintBase*> ineq_constraints;

            for (const auto* constraint : constraints) {
                switch (constraint->type()) {
                    case task::ConstraintType::Equality:
                        eq_constraints.push_back(constraint);
                        break;
                    case task::ConstraintType::Inequality:
                        ineq_constraints.push_back(constraint);
                        break;
                    case task::ConstraintType::Cost:
                        cost_constraints.push_back(constraint);
                        break;
                }
            }

            std::cout << "[pak_hqp_controller][Solver] Constraints: "
                    << eq_constraints.size() << " equality, "
                    << ineq_constraints.size() << " inequality, "
                    << cost_constraints.size() << " cost" << std::endl;

            // 2. Cost (최소 Q, c)
            for (const auto* cst : cost_constraints) {
                Q_ += cst->A().transpose() * cst->A(); // 단순 least squares 방식 예시
                c_ += -cst->A().transpose() * cst->b();
            }

            // 3. Equality stacking
            int n_eq = 0;
            for (const auto* c : eq_constraints)
                n_eq += c->A().rows();
            Aeq_ = Eigen::MatrixXd::Zero(n_eq, dof);
            beq_ = Eigen::VectorXd::Zero(n_eq);
            int row = 0;
            for (const auto* c : eq_constraints) {
                int m = c->A().rows();
                Aeq_.block(row, 0, m, dof) = c->A();
                beq_.segment(row, m) = c->b();
                row += m;
            }

            // 4. Inequality stacking
            int n_ineq = 0;
            for (const auto* c : ineq_constraints)
                n_ineq += c->A().rows();
            Aineq_ = Eigen::MatrixXd::Zero(n_ineq, dof);
            bineq_ = Eigen::VectorXd::Zero(n_ineq);
            row = 0;
            for (const auto* c : ineq_constraints) {
                int m = c->A().rows();
                Aineq_.block(row, 0, m, dof) = c->A();
                bineq_.segment(row, m) = c->b();
                row += m;
            }

            // 5. eiquadprog로 QP 풀기
            Eigen::VectorXd x = Eigen::VectorXd::Zero(dof);

            // eiquadprog는 다음 시그니처:
            // min 1/2 x' Q x + c' x
            // s.t. CE^T x + ce0 = 0  (equality)
            //      CI^T x + ci0 >= 0 (inequality, eiquadprog는 Ax <= b가 아니라 Ax + b >= 0)
            // 변환 필요
            Eigen::MatrixXd CE = Eigen::MatrixXd::Zero(dof, n_eq);
            Eigen::VectorXd ce0 = Eigen::VectorXd::Zero(n_eq);
            if (n_eq > 0) {
                CE = Aeq_.transpose();
                ce0 = -beq_;
            }

            Eigen::MatrixXd CI = Eigen::MatrixXd::Zero(dof, n_ineq);
            Eigen::VectorXd ci0 = Eigen::VectorXd::Zero(n_ineq);
            if (n_ineq > 0) {
                // Ax <= b → -Ax + b >= 0 → CI^T x + ci0 >= 0
                CI = -Aineq_.transpose();
                ci0 = bineq_;
            }

            Eigen::VectorXi activeSet;   // NEW
            size_t activeSetSize = 0;    // NEW 

            double qp_result = eiquadprog::solvers::solve_quadprog(Q_, c_, CE, ce0, CI, ci0, x, activeSet, activeSetSize);

            if (qp_result != std::numeric_limits<double>::infinity()) {
                std::cerr << "[Solver] =====QP solved======" << std::endl;
                return x;
            } else {
                std::cerr << "[Solver] QP failed, returning zeros." << std::endl;
                return Eigen::VectorXd::Zero(dof);
            }
        }

    } // namespace solver
} // namespace pak_hqp_controller
