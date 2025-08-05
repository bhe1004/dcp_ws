#pragma once

#include <pinocchio/multibody/model.hpp>
#include <pinocchio/multibody/data.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <string>
#include <Eigen/Dense>

namespace pak_hqp_controller {
    namespace robot {

        class RobotWrapper {
            public:
                // URDF 경로로부터 모델/데이터 초기화
                RobotWrapper(const std::string& urdf_path);

                pinocchio::Model& model() { return model_; }
                pinocchio::Data& data() { return data_; }

                int dof() const { return model_.nv; }
                int getFrameId(const std::string& frame_name) const;

                // FK: q -> frame pose (pinocchio::SE3)
                pinocchio::SE3 getFramePose(const Eigen::VectorXd& q, const std::string& frame_name);

                // Jacobian: q -> frame Jacobian (6 x nv)
                Eigen::MatrixXd getFrameJacobian(const Eigen::VectorXd& q, const std::string& frame_name);

                // (필요시 joint limit, inertia 등 함수 추가 가능)

            protected:
                pinocchio::Model model_;
                pinocchio::Data data_;
        };

    } // namespace robot
} // namespace pak_hqp_controller
