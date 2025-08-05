#pragma once

#include <vector>
#include <Eigen/Dense>
#include "pak_hqp_controller/task/constraint_base.hpp"

namespace pak_hqp_controller {
    namespace solver {

        class Solver {
            public:
                Solver() = default;
                virtual ~Solver() = default;

                // constraints: cost, equality, inequality 포함
                // QP: min 1/2 dq' Q dq + c' dq  s.t.  Aeq*dq = beq,  Aineq*dq <= bineq
                Eigen::VectorXd solve(
                    const std::vector<const task::ConstraintBase*>& constraints,
                    int dof);

            protected:
                // 내부 QP 임시 행렬
                Eigen::MatrixXd Q_;
                Eigen::VectorXd c_;
                Eigen::MatrixXd Aeq_;
                Eigen::VectorXd beq_;
                Eigen::MatrixXd Aineq_;
                Eigen::VectorXd bineq_;
    };

    } // namespace solver
} // namespace pak_hqp_controller
