#pragma once

#include <fairino_action_manager/servers/basic/action_server_base.hpp>
#include <fairino_interfaces/action/qr.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <tf2/transform_datatypes.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <fstream>

using namespace pinocchio;
using namespace Eigen;

class QRActionServer : public ActionServerBase
{
public:
    using QRAction = fairino_interfaces::action::QR;
    using GoalHandleQR = rclcpp_action::ServerGoalHandle<QRAction>;

    QRActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu);

    bool compute(const rclcpp::Time& current_time) override;

private:
    // ROS 2 Action Server Callbacks
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const QRAction::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleQR> goal_handle);

    void handle_accepted(
        const std::shared_ptr<GoalHandleQR> goal_handle);
        
    // ROS 2 Action Server
    rclcpp_action::Server<QRAction>::SharedPtr action_server_;
    std::shared_ptr<GoalHandleQR> current_goal_handle_; // Stores the currently active goal

    // Feedback and Result messages (smart pointers)
    std::shared_ptr<QRAction::Feedback> feedback_msg_;
    std::shared_ptr<QRAction::Result> result_msg_;

    bool is_relative_;

    geometry_msgs::msg::Pose qr_msg_;
    SE3 qr_tf_;
};