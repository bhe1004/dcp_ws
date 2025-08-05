// skill_manager_pkg/src/place.cpp

#include "fairino_action_manager/servers/task/place.hpp"

bool Place::execute(const geometry_msgs::msg::Pose& target_pose, const float duration)
{
    RCLCPP_INFO(node_->get_logger(), "Executing Place Skill...");
    
    // Step 1: Move to target
    if (!move_to_pose(target_pose, duration)) {
        RCLCPP_ERROR(node_->get_logger(), "Place failed: Could not move to target pose.");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "Place step 1/2: Move successful.");

    // Step 2: Open gripper
    if (!control_gripper(false)) { // false for open/release
        RCLCPP_ERROR(node_->get_logger(), "Place failed: Could not open gripper.");
        return false;
    }
    RCLCPP_INFO(node_->get_logger(), "Place step 2/2: Gripper opened.");

    RCLCPP_INFO(node_->get_logger(), "Place skill executed successfully.");
    return true;
}