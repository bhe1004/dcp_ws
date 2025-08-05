#pragma once

#include <fairino_action_manager/servers/basic/action_server_base.hpp>
#include <fairino_interfaces/action/se3.hpp> // Generated from SE3.action
#include <rclcpp_action/rclcpp_action.hpp>
#include <tf2_eigen/tf2_eigen.hpp> // For converting Eigen to geometry_msgs and vice-versa if needed
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> // For direct conversion of geometry_msgs

#include <fstream>
#include <Eigen/Dense> // Already in base, but good for clarity if used directly here

class SE3ActionServer : public ActionServerBase
{
public:
  // Define Action Type and Goal Handle Type for convenience
  using SE3Action = fairino_interfaces::action::SE3;
  using GoalHandleSE3 = rclcpp_action::ServerGoalHandle<SE3Action>;

  SE3ActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu);

  bool compute(const rclcpp::Time& current_time) override;

private:
  // ROS 2 Action Server Callbacks
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const SE3Action::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleSE3> goal_handle);

  void handle_accepted(
    const std::shared_ptr<GoalHandleSE3> goal_handle);

  // The actual execution logic that was previously triggered after goal acceptance
  // and driven by the external 'compute' calls.
  // This function can be called in a separate thread from handle_accepted,
  // or its state setup can be done in handle_accepted, and 'compute' does the work.
  // Given the original structure, we'll set up state in handle_accepted and let 'compute' do the work.

  // ROS 2 Action Server
  rclcpp_action::Server<SE3Action>::SharedPtr action_server_;
  std::shared_ptr<GoalHandleSE3> current_goal_handle_; // Stores the currently active goal

  // Goal properties (can be retrieved from current_goal_handle_->get_goal())
  // fairino_action_manager::action::SE3::GoalConstPtr goal_; // Not needed as member, get from handle
  bool is_relative_;

  // Feedback and Result messages (smart pointers)
  std::shared_ptr<SE3Action::Feedback> feedback_msg_;
  std::shared_ptr<SE3Action::Result> result_msg_;

  // Helper for internal logic, if needed (original had computeArm)
  // bool computeArm(const rclcpp::Time& time); // Example if you refactor
};