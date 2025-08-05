#include "pak_hqp_controller/robot/robot_wrapper.hpp"
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <stdexcept>

namespace pak_hqp_controller {
    namespace robot {

        RobotWrapper::RobotWrapper(const std::string& urdf_path)
            : model_(), data_(model_)
        {
            pinocchio::urdf::buildModel(urdf_path, model_);
            data_ = pinocchio::Data(model_);
        }

        int RobotWrapper::getFrameId(const std::string& frame_name) const
        {
            if (!model_.existFrame(frame_name))
                throw std::runtime_error("[RobotWrapper] Frame name not found: " + frame_name);
            return model_.getFrameId(frame_name);
        }

        pinocchio::SE3 RobotWrapper::getFramePose(const Eigen::VectorXd& q, const std::string& frame_name)
        {
            pinocchio::forwardKinematics(model_, data_, q);
            pinocchio::updateFramePlacements(model_, data_);
            int frame_id = getFrameId(frame_name);
            return data_.oMf[frame_id];
        }

        Eigen::MatrixXd RobotWrapper::getFrameJacobian(const Eigen::VectorXd& q, const std::string& frame_name)
        {
            int nv = model_.nv;
            Eigen::MatrixXd J(6, nv);
            int frame_id = getFrameId(frame_name);

            pinocchio::forwardKinematics(model_, data_, q);
            pinocchio::computeFrameJacobian(model_, data_, q, frame_id, pinocchio::LOCAL, J);

            return J;
        }

    } // namespace robot
} // namespace pak_hqp_controller
