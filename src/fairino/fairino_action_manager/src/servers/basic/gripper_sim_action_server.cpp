#include <fairino_action_manager/servers/basic/gripper_sim_action_server.hpp>

GripperSimActionServer::GripperSimActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu)
    : ActionServerBase(node, name, mu)
{
    using namespace std::placeholders; // For _1, _2, etc. in std::bind

    this->action_server_ = rclcpp_action::create_server<GripperAction>(
        this->node_, // Or node, if node_ is not yet initialized by base (it is)
        name, // Action name
        std::bind(&GripperSimActionServer::handle_goal, this, _1, _2),
        std::bind(&GripperSimActionServer::handle_cancel, this, _1),
        std::bind(&GripperSimActionServer::handle_accepted, this, _1)
    );

    feedback_msg_ = std::make_shared<GripperAction::Feedback>();
    result_msg_ = std::make_shared<GripperAction::Result>();
}

rclcpp_action::GoalResponse GripperSimActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const GripperAction::Goal> goal)
{
    if (goal->grasp) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request: Gripper Close",
        action_name_.c_str());
    } else {
        RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request: Gripper Close",
        action_name_.c_str());
    }

    // If another goal is active and this server only handles one at a time
    if (control_running_ || (current_goal_handle_ && current_goal_handle_->is_active())) {
        RCLCPP_WARN(node_->get_logger(), "[%s] Goal rejected: another goal is currently active.", action_name_.c_str());
        return rclcpp_action::GoalResponse::REJECT; // Or ACCEPT_AND_DEFER if you implement queuing
    }

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}


rclcpp_action::CancelResponse GripperSimActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleGripper> goal_handle)
{
    RCLCPP_INFO(node_->get_logger(), "[%s] Received request to cancel goal", action_name_.c_str());
    if (goal_handle == current_goal_handle_){ // Check if it's the current goal
        // No immediate action here, cancel request is noted.
        // The `compute` loop will check `is_cancel_requested()`
        // and then call `goal_handle->canceled()`
    } else {
        RCLCPP_WARN(node_->get_logger(), "[%s] Received cancel request for an unknown or non-current goal.", action_name_.c_str());
    }
    return rclcpp_action::CancelResponse::ACCEPT;
}

void GripperSimActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleGripper> goal_handle)
{
    current_goal_handle_ = goal_handle; // Store the handle
    const auto goal = goal_handle->get_goal();

    mu_->state().gripper.isgrasp = goal->grasp;
    mu_->state().gripper.isdone = false; // Reset the gripper state
    mu_->state().gripper.command_executed = false; // Reset command execution state
    mu_->state().gripper.position_percentage = goal->position_percentage;
    mu_->state().gripper.speed_percentage = goal->speed_percentage;
    mu_->state().gripper.torque_percentage = goal->torque_percentage;

    start_time_ = node_->now();
    mu_->init_joint_posture_ctrl(start_time_);
    control_running_ = true; // Set control running to true

    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted, starting control loop.", action_name_.c_str());
}

bool GripperSimActionServer::compute(const rclcpp::Time& /*current_time*/)
{
    if (!control_running_ || !current_goal_handle_ || !current_goal_handle_->is_active()) {
        return false;
    }

    // Check for cancellation first
    if (current_goal_handle_->is_canceling()) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Goal Canceled", action_name_.c_str());
        result_msg_->is_completed = false; // Populate result
        current_goal_handle_->canceled(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset(); // Release the handle
        return false; // Indicate computation related to this goal has stopped
    }

    const auto goal = current_goal_handle_->get_goal();
    
    // Publish feedback (percent_complete)
    double close_pos = 0.6542;
    // double open_pos = 0.0;
    float percent;
    if (goal->grasp) { // Close Command (95 -> 0)
        percent = static_cast<float>(
            std::min(100.0, mu_->state().gripper.current_sim_pos / close_pos * 100.0)
        );
    }
    else { // Open Command (0 -> 95)
        percent = static_cast<float>(
            std::min(100.0, (1 - mu_->state().gripper.current_sim_pos / close_pos) * 100.0)
        );
    }
    
    feedback_msg_->percent_complete = percent;
    current_goal_handle_->publish_feedback(feedback_msg_);

    bool motion_done = mu_->state().gripper.isdone;
    if (motion_done) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Goal Succeeded.", action_name_.c_str());
        result_msg_->is_completed = true;
        current_goal_handle_->succeed(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return true;
    }

    return false;
}