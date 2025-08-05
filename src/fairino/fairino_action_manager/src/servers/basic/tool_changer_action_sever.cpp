#include <fairino_action_manager/servers/basic/tool_changer_action_server.hpp>
#include <pinocchio/fwd.hpp> // Assuming this is needed for RobotController
#include <pinocchio/spatial/se3.hpp> // For pinocchio::SE3 if used explicitly

ToolChangerActionServer::ToolChangerActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu)
: ActionServerBase(node, name, mu)
{
    using namespace std::placeholders; // For _1, _2, etc. in std::bind

    this->action_server_ = rclcpp_action::create_server<ToolChangerAction>(
        this->node_, // Or node, if node_ is not yet initialized by base (it is)
        name, // Action name
        std::bind(&ToolChangerActionServer::handle_goal, this, _1, _2),
        std::bind(&ToolChangerActionServer::handle_cancel, this, _1),
        std::bind(&ToolChangerActionServer::handle_accepted, this, _1)
    );

    // this->se3_ctrl_client_ = rclcpp_action::create_client<SE3Action>(
    //     this->node_,
    //     "/fairino_action_manager/se3_control"
    // );

    // if (!this->se3_ctrl_client_->wait_for_action_server(std::chrono::seconds(10))) {
    //   RCLCPP_ERROR(node_->get_logger(), "Action server not available after waiting");
    // } else {
    //   RCLCPP_INFO(node_->get_logger(), "SE3 Action server is ready.");
    // }

    feedback_msg_ = std::make_shared<ToolChangerAction::Feedback>();
    result_msg_ = std::make_shared<ToolChangerAction::Result>();

    mu_->state().tool_changer.isdone = true;

    RCLCPP_INFO(node_->get_logger(), "ToolChangerActionServer [%s] started.", action_name_.c_str());
}

rclcpp_action::GoalResponse ToolChangerActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const ToolChangerAction::Goal> goal)
{
    RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request: %s, tool_id: %d, duration: %f", 
        action_name_.c_str(),
        goal->grip ? "grip" : "release",
        goal->tool_id,
        goal->duration
    );

    // Basic validation (add more if needed)
    if (goal->duration <= 0) {
        RCLCPP_ERROR(node_->get_logger(), "[%s] Goal rejected: duration must be positive.", action_name_.c_str());
        return rclcpp_action::GoalResponse::REJECT;
    }
    // If another goal is active and this server only handles one at a time
    if (control_running_ || (current_goal_handle_ && current_goal_handle_->is_active())) {
        RCLCPP_WARN(node_->get_logger(), "[%s] Goal rejected: another goal is currently active.", action_name_.c_str());
        return rclcpp_action::GoalResponse::REJECT; // Or ACCEPT_AND_DEFER if you implement queuing
    }

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse ToolChangerActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleToolChanger> goal_handle)
{
    RCLCPP_INFO(node_->get_logger(), "[%s] Received request to cancel goal", action_name_.c_str());
    if (goal_handle == current_goal_handle_) { // Check if it's the current goal
        // No immediate action here, cancel request is noted.
        // The `compute` loop will check `is_cancel_requested()`
        // and then call `goal_handle->canceled()`
    } else {
        RCLCPP_WARN(node_->get_logger(), "[%s] Received cancel request for an unknown or non-current goal.", action_name_.c_str());
    }

    return rclcpp_action::CancelResponse::ACCEPT;
}

void ToolChangerActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleToolChanger> goal_handle)
{
    current_goal_handle_ = goal_handle; // Store the current goal handle
    const auto goal = goal_handle->get_goal();
    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted.", action_name_.c_str());

    mu_->state().tool_changer.isdone = false;
    mu_->state().tool_changer.isgripped = goal->grip;
    mu_->state().tool_changer.duration = goal->duration;

    feedback_msg_->percent_complete = 0;
    result_msg_->reach_completed = false;
    result_msg_->tool_change_completed = false;

    control_running_ = true;

    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted. Control running.", action_name_.c_str());
}

bool ToolChangerActionServer::compute(const rclcpp::Time& current_time)
{
    if (!control_running_ || !current_goal_handle_ || !current_goal_handle_->is_active()) {
        return false; // Not running or no active goal
    }
    // Check for cancellation first
    if (current_goal_handle_->is_canceling()) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Goal Canceled", action_name_.c_str());
        result_msg_->reach_completed = false; // Populate result
        result_msg_->tool_change_completed = false;
        current_goal_handle_->canceled(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset(); // Release the handle
        return false; // Indicate computation related to this goal has stopped
    }

    const auto goal = current_goal_handle_->get_goal();

    // isreached is changed by another 
    mu_->state().tool_changer.isreached = true; // Simulate reaching the position, replace with actual logic
    if (mu_->state().tool_changer.isreached) {
        RCLCPP_INFO(node_->get_logger(), "[%s] SE3 goal sent successfully.", action_name_.c_str());
        result_msg_->reach_completed = true;
        feedback_msg_->percent_complete = 50; // Populate feedback
    }
    else {
        RCLCPP_ERROR(node_->get_logger(), "[%s] Failed to send SE3 goal.", action_name_.c_str());
        return false;
    }

    if (mu_->state().tool_changer.isreached && mu_->state().tool_changer.isdone) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Goal Succeeded.", action_name_.c_str());
        feedback_msg_->percent_complete = 100; // Populate feedback
        result_msg_->reach_completed = true;
        result_msg_->tool_change_completed = true;
        current_goal_handle_->succeed(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return true;
    }

    current_goal_handle_->publish_feedback(feedback_msg_);

    return true;
}