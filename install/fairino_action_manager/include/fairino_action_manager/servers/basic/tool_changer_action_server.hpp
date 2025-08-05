#pragma once

#include <fairino_action_manager/servers/basic/action_server_base.hpp>
#include <fairino_interfaces/action/tool_changer.hpp>
#include <fairino_interfaces/action/se3.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <Eigen/Dense>

class ToolChangerActionServer : public ActionServerBase
{
public:
    using ToolChangerAction = fairino_interfaces::action::ToolChanger;
    using GoalHandleToolChanger = rclcpp_action::ServerGoalHandle<ToolChangerAction>;
    using SE3Action = fairino_interfaces::action::SE3;
    using GoalHandleSE3 = rclcpp_action::ServerGoalHandle<SE3Action>;

    ToolChangerActionServer(
        rclcpp::Node::SharedPtr node,
        const std::string& name,
        std::shared_ptr<RobotController::FairinoWrapper> mu
    );

    rclcpp_action::Client<SE3Action>::SharedPtr se3_ctrl_client_;

    bool compute(const rclcpp::Time& current_time) override;

private:
  // ROS 2 Action Server Callbacks
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const ToolChangerAction::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleToolChanger> goal_handle);

  void handle_accepted(
    const std::shared_ptr<GoalHandleToolChanger> goal_handle);

  // ROS 2 Action Server
  rclcpp_action::Server<ToolChangerAction>::SharedPtr action_server_;
  std::shared_ptr<GoalHandleToolChanger> current_goal_handle_; // Stores the currently active goal

  // Feedback and Result messages (smart pointers)
  std::shared_ptr<ToolChangerAction::Feedback> feedback_msg_;
  std::shared_ptr<ToolChangerAction::Result> result_msg_;
};