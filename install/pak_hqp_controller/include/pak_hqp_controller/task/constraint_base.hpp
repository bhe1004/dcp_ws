#pragma once
#include <Eigen/Dense>
#include <string>

namespace pak_hqp_controller {
    namespace task {

        enum class ConstraintType {
            Equality,   // Ax = b
            Inequality, // Ax <= b
            Cost        // 1/2 x'Qx + c'x
        };

        class ConstraintBase {
        public:
            ConstraintBase(const std::string& name, ConstraintType type,
                        const Eigen::MatrixXd& A, const Eigen::VectorXd& b)
                : name_(name), type_(type), A_(A), b_(b) {}

            virtual ~ConstraintBase() {}

            const std::string& name() const { return name_; }
            ConstraintType type() const { return type_; }
            const Eigen::MatrixXd& A() const { return A_; }
            const Eigen::VectorXd& b() const { return b_; }

        protected:
            std::string name_;
            ConstraintType type_;
            Eigen::MatrixXd A_;
            Eigen::VectorXd b_;
        };

    } // namespace task
} // namespace pak_hqp_controller
