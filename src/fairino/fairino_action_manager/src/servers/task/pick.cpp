// skill_manager_pkg/src/pick.cpp

#include "fairino_action_manager/servers/task/pick.hpp"

bool Pick::execute(const geometry_msgs::msg::Pose& target_pose, const float duration)
{
    RCLCPP_INFO(node_->get_logger(), "Executing Pick Skill...");

    // Step 1: Open Gripper
    if (!control_gripper(false)) { // true for close/grasp
        RCLCPP_ERROR(node_->get_logger(), "Pick failed: Could not Open gripper.");
        return false;
    }
    
    // Step 2: Move to target
    if (!move_to_pose(target_pose, duration)) {
        RCLCPP_ERROR(node_->get_logger(), "Pick failed: Could not move to target pose.");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "Pick step 1/2: Move successful.");

    // Step 3: Close gripper
    if (!control_gripper(true)) { // true for close/grasp
        RCLCPP_ERROR(node_->get_logger(), "Pick failed: Could not close gripper.");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "Pick step 2/2: Gripper closed.");

    RCLCPP_INFO(node_->get_logger(), "Pick skill executed successfully.");
    return true;
}