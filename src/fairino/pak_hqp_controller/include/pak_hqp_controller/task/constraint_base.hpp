#pragma once
#include <Eigen/Dense>
#include <string>
#include <optional>

namespace pak_hqp_controller {
    namespace task {

        enum class ConstraintType {
            Equality,   // Ax = b
            Inequality, // l <= Ax <= u (또는 Ax <= b 만 지원할 수도 있음)
            Cost        // 1/2 x'Qx + c'x
        };

        class ConstraintBase {
            public:
                // (1) Equality: Ax = b
                ConstraintBase(const std::string& name, ConstraintType type,
                            const Eigen::MatrixXd& A, const Eigen::VectorXd& b)
                    : name_(name), type_(type), A_(A), b_(b), use_bounds_(false) {}

                // (2) Inequality: l <= Ax <= u
                ConstraintBase(const std::string& name, ConstraintType type,
                            const Eigen::MatrixXd& A, 
                            const Eigen::VectorXd& lower,
                            const Eigen::VectorXd& upper)
                    : name_(name), type_(type), A_(A), lower_(lower), upper_(upper), use_bounds_(true) {}

                virtual ~ConstraintBase() {}

                const std::string& name() const { return name_; }
                ConstraintType type() const { return type_; }
                const Eigen::MatrixXd& A() const { return A_; }

                // Equality
                const Eigen::VectorXd& b() const { return b_; }

                // Inequality
                const Eigen::VectorXd& lower() const { return lower_; }
                const Eigen::VectorXd& upper() const { return upper_; }
                bool uses_bounds() const { return use_bounds_; }

            protected:
                std::string name_;
                ConstraintType type_;
                Eigen::MatrixXd A_;

                // --- For Equality (Ax = b)
                Eigen::VectorXd b_;

                // --- For Inequality (l <= Ax <= u)
                Eigen::VectorXd lower_;
                Eigen::VectorXd upper_;
                bool use_bounds_; // true면 lower/upper 사용, false면 b_ 사용
        };

    } // namespace task
} // namespace pak_hqp_controller
