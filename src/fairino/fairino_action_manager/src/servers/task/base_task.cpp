#include "fairino_action_manager/servers/task/base_task.hpp"
#include "rclcpp/rclcpp.hpp"

BaseTask::BaseTask(
    rclcpp::Node::SharedPtr node,
    SE3ActionClient::SharedPtr se3_client,
    GripperActionClient::SharedPtr gripper_client)
: node_(node), se3_client_(se3_client), gripper_client_(gripper_client)
{}

bool BaseTask::move_to_pose(const geometry_msgs::msg::Pose& pose, float duration)
{
    if (!se3_client_->wait_for_action_server(std::chrono::seconds(5))) {
        RCLCPP_ERROR(node_->get_logger(), "SE3 action server not available after waiting");
        return false;
    }

    auto goal_msg = SE3Action::Goal();
    goal_msg.target_pose = pose;
    goal_msg.duration = duration;

    RCLCPP_INFO(node_->get_logger(), "Sending SE3 goal...");
    auto goal_handle_future = se3_client_->async_send_goal(goal_msg);

    // .get()을 사용해 goal_handle이 준비될 때까지 현재 스레드를 블로킹합니다.
    // MultiThreadedExecutor의 다른 스레드가 응답을 처리해줍니다.
    auto goal_handle = goal_handle_future.get();
    if (!goal_handle) {
        RCLCPP_ERROR(node_->get_logger(), "SE3 goal was rejected by server");
        return false;
    }

    // 결과 future를 얻습니다.
    auto result_future = se3_client_->async_get_result(goal_handle);

    RCLCPP_INFO(node_->get_logger(), "Waiting for SE3 result...");
    // .get()을 사용해 결과가 준비될 때까지 현재 스레드를 블로킹합니다.
    auto result_wrapper = result_future.get();
    
    if (result_wrapper.code == rclcpp_action::ResultCode::SUCCEEDED) {
        return true;
    } else {
        RCLCPP_ERROR(node_->get_logger(), "SE3 goal failed with result code: %d", static_cast<int>(result_wrapper.code));
        return false;
    }
}

bool BaseTask::control_gripper(bool grasp)
{
    if (!gripper_client_->wait_for_action_server(std::chrono::seconds(5))) {
        RCLCPP_ERROR(node_->get_logger(), "Gripper action server not available after waiting");
        return false;
    }

    auto goal_msg = GripperAction::Goal();
    goal_msg.grasp = grasp;
    goal_msg.position_percentage = 0;
    goal_msg.speed_percentage = 70;
    goal_msg.torque_percentage = 50;

    RCLCPP_INFO(node_->get_logger(), "Sending Gripper goal...");
    auto goal_handle_future = gripper_client_->async_send_goal(goal_msg);

    // .get()으로 동기 대기
    auto goal_handle = goal_handle_future.get();
    if (!goal_handle) {
        RCLCPP_ERROR(node_->get_logger(), "Gripper goal was rejected by server");
        return false;
    }

    auto result_future = gripper_client_->async_get_result(goal_handle);
    
    RCLCPP_INFO(node_->get_logger(), "Waiting for Gripper result...");
    // .get()으로 동기 대기
    auto result_wrapper = result_future.get();

    if (result_wrapper.code == rclcpp_action::ResultCode::SUCCEEDED) {
        return true;
    } else {
        RCLCPP_ERROR(node_->get_logger(), "Gripper goal failed with result code: %d", static_cast<int>(result_wrapper.code));
        return false;
    }
}