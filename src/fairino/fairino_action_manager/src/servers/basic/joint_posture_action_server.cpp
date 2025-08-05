#include <fairino_action_manager/servers/basic/joint_posture_action_server.hpp>

JointPostureActionServer::JointPostureActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu)
    : ActionServerBase(node, name, mu)
{
    using namespace std::placeholders; // For _1, _2, etc. in std::bind

    this->action_server_ = rclcpp_action::create_server<JointPostureAction>(
        this->node_, // Or node, if node_ is not yet initialized by base (it is)
        name, // Action name
        std::bind(&JointPostureActionServer::handle_goal, this, _1, _2),
        std::bind(&JointPostureActionServer::handle_cancel, this, _1),
        std::bind(&JointPostureActionServer::handle_accepted, this, _1)
    );

    feedback_msg_ = std::make_shared<JointPostureAction::Feedback>();
    result_msg_ = std::make_shared<JointPostureAction::Result>();
}

rclcpp_action::GoalResponse JointPostureActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const JointPostureAction::Goal> goal)
{
    if (goal->target_joints.position.size() != 6) {
        RCLCPP_ERROR(node_->get_logger(), 
            "[%s] Goal rejected: target_joints.position has %zu elements, expected %d.",
            action_name_.c_str(), goal->target_joints.position.size(), 6);
        return rclcpp_action::GoalResponse::REJECT;
    }

    RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request: joint position: (%f, %f, %f, %f, %f, %f), duration %f", 
        action_name_.c_str(),
        goal->target_joints.position[0], goal->target_joints.position[1], goal->target_joints.position[2],
        goal->target_joints.position[3], goal->target_joints.position[4], goal->target_joints.position[5],
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

rclcpp_action::CancelResponse JointPostureActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleJointPosture> goal_handle)
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

void JointPostureActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleJointPosture> goal_handle)
{
    current_goal_handle_ = goal_handle; // Store the handle
    const auto goal = goal_handle->get_goal();
    
    for (int i=0; i<6; i++)
        mu_->state().fairino.q_ref(i) = goal->target_joints.position[i];
    mu_->state().fairino.duration = goal->duration;

    start_time_ = node_->now();
    mu_->init_joint_posture_ctrl(start_time_);
    control_running_ = true;
    
    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted. Control running.", action_name_.c_str());
}

bool JointPostureActionServer::compute(const rclcpp::Time& current_time)
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
    mu_->compute_joint_posture_ctrl(current_time); // Pass rclcpp::Time

    const auto goal = current_goal_handle_->get_goal(); // Get goal for duration check
    double elapsed_time_sec = (current_time - start_time_).seconds();

    // Publish feedback (percent_complete)
    float percent = static_cast<float>(
        std::min(100.0, (elapsed_time_sec / std::max(goal->duration, 0.001f)) * 100.0)
    );
    feedback_msg_->percent_complete = percent;
    current_goal_handle_->publish_feedback(feedback_msg_);

    auto& q_ref = mu_->state().fairino.q_ref;
    auto& q = mu_->state().fairino.q;
    double error_norm = (q_ref - q).norm();

    if (elapsed_time_sec > current_goal_handle_->get_goal()->duration && error_norm < 5e-3) {
        RCLCPP_INFO(node_->get_logger(), "[%s] Goal Succeeded. Error norm: %f", action_name_.c_str(), error_norm);
        result_msg_->is_completed = true;
        current_goal_handle_->succeed(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return true;
    }

    if (elapsed_time_sec > current_goal_handle_->get_goal()->duration + 2.0) {
        result_msg_->is_completed = false;
        current_goal_handle_->abort(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return false;
    }

    // Print debug info periodically
    if (print_count_++ % iter_per_print_ == 0) {
        DEBUG_FILE("Time: " << current_time.seconds() << ", Error: " << error_norm);
        // RCLCPP_DEBUG(node_->get_logger(), "[%s] Computing... Error norm: %f", action_name_.c_str(), error_norm);
    }

    return false;
}