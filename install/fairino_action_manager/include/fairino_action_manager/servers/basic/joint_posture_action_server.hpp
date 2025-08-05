#pragma once

#include <fairino_action_manager/servers/basic/action_server_base.hpp>
#include <fairino_interfaces/action/joint_posture.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

using namespace pinocchio;
using namespace Eigen;

class JointPostureActionServer : public ActionServerBase
{
public:
    using JointPostureAction = fairino_interfaces::action::JointPosture;
    using GoalHandleJointPosture = rclcpp_action::ServerGoalHandle<JointPostureAction>;
    
    JointPostureActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu);
    
    bool compute(const rclcpp::Time& current_time) override;

private:
  // ROS 2 Action Server Callbacks
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const JointPostureAction::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleJointPosture> goal_handle);

  void handle_accepted(
    const std::shared_ptr<GoalHandleJointPosture> goal_handle);

  // ROS 2 Action Server
  rclcpp_action::Server<JointPostureAction>::SharedPtr action_server_;
  std::shared_ptr<GoalHandleJointPosture> current_goal_handle_; // Stores the currently active goal

  // Feedback and Result messages (smart pointers)
  std::shared_ptr<JointPostureAction::Feedback> feedback_msg_;
  std::shared_ptr<JointPostureAction::Result> result_msg_;
};