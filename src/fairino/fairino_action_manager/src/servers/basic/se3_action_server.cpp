#include <fairino_action_manager/servers/basic/se3_action_server.hpp>
#include <pinocchio/fwd.hpp> // Assuming this is needed for RobotController
#include <pinocchio/spatial/se3.hpp> // For pinocchio::SE3 if used explicitly

SE3ActionServer::SE3ActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu)
: ActionServerBase(node, name, mu), // Pass node and mu to base
  is_relative_(true)
{
    using namespace std::placeholders; // For _1, _2, etc. in std::bind

    this->action_server_ = rclcpp_action::create_server<SE3Action>(
        this->node_, // Or node, if node_ is not yet initialized by base (it is)
        name, // Action name
        std::bind(&SE3ActionServer::handle_goal, this, _1, _2),
        std::bind(&SE3ActionServer::handle_cancel, this, _1),
        std::bind(&SE3ActionServer::handle_accepted, this, _1)
    );
    
    feedback_msg_ = std::make_shared<SE3Action::Feedback>();
    result_msg_ = std::make_shared<SE3Action::Result>();

    RCLCPP_INFO(node_->get_logger(), "SE3ActionServer [%s] started.", action_name_.c_str());
}

rclcpp_action::GoalResponse SE3ActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const SE3Action::Goal> goal)
{   
    std::string client_id = goal->client_id;
    RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request: pos(%f,%f,%f)\norientation:(%f, %f, %f, %f)\nduration %f", 
        action_name_.c_str(),
        goal->target_pose.position.x, goal->target_pose.position.y, goal->target_pose.position.z,
        goal->target_pose.orientation.x, goal->target_pose.orientation.y, goal->target_pose.orientation.z, goal->target_pose.orientation.w,
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

rclcpp_action::CancelResponse SE3ActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleSE3> goal_handle)
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

void SE3ActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleSE3> goal_handle)
{
    // This function is called when a goal is accepted.
    // It should not block. If long processing is needed, spawn a thread.
    // Here, we'll set up for the external 'compute' method.
    std::string client_id = goal_handle->get_goal()->client_id;

    current_goal_handle_ = goal_handle; // Store the handle
    const auto goal = goal_handle->get_goal();

    // feedback_header_stamp_ = 0; // If you re-introduce this for feedback messages

    mode_change_ = false; // Assuming this is an internal state flag
    is_relative_ = goal->relative;
    
    // Assuming mu_ and its state structure are ROS 2 compatible or agnostic
    mu_->state().fairino.isrelative = is_relative_;

    Eigen::Vector3d pos(goal->target_pose.position.x, goal->target_pose.position.y, goal->target_pose.position.z);
    Eigen::Quaterniond quat(goal->target_pose.orientation.w, goal->target_pose.orientation.x, goal->target_pose.orientation.y, goal->target_pose.orientation.z);
    
    // Assuming pinocchio::SE3 is compatible or you have a similar SE3 type
    pinocchio::SE3 oMi_ref(quat.toRotationMatrix(), pos); 
    mu_->state().fairino.H_ee_ref = oMi_ref;
    mu_->state().fairino.duration = goal->duration;

    start_time_ = node_->now(); // Use node's clock

    if (client_id == "pick") {
        mu_->init_se3_ctrl(start_time_);  // 기존 pick 동작
        RCLCPP_INFO(node_->get_logger(), "[%s] Pick: init_se3_ctrl() 호출", action_name_.c_str());
    }
    else if (client_id == "place") {
        mu_->init_place_ctrl(start_time_); // 새로운 place 동작
        RCLCPP_INFO(node_->get_logger(), "[%s] Place: init_place_ctrl() 호출", action_name_.c_str());
    }
    else {
        // 그 외 client_id면 pick 방식 기본값으로(혹은 에러)
        mu_->init_se3_ctrl(start_time_);
        RCLCPP_WARN(node_->get_logger(), "[%s] Unknown client_id: %s. 기본 init_se3_ctrl() 사용", action_name_.c_str(), client_id.c_str());
    }
    // mu_->init_se3_ctrl(start_time_); // Pass rclcpp::Time
    control_running_ = true;

    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted. Control running.", action_name_.c_str());
}

bool SE3ActionServer::compute(const rclcpp::Time& current_time)
{
    if (!control_running_ || !current_goal_handle_ || !current_goal_handle_->is_active()) {
        return false; // Not running or no active goal
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

    // Perform control computation
    mu_->compute_se3_ctrl(current_time); // Pass rclcpp::Time

    const auto goal = current_goal_handle_->get_goal(); // Get goal for duration check
    double elapsed_time_sec = (current_time - start_time_).seconds();

    // Publish feedback (percent_complete)
    float percent = static_cast<float>(
        std::min(100.0, (elapsed_time_sec / std::max(goal->duration, 0.001f)) * 100.0)
    );
    feedback_msg_->percent_complete = percent;
    current_goal_handle_->publish_feedback(feedback_msg_);

    // Check for success
    // Using Eigen::Vector3d for SE3 translation for norm calculation
    Eigen::Vector3d current_pos_eigen = mu_->state().fairino.H_ee.translation();
    Eigen::Vector3d ref_pos_eigen = mu_->state().fairino.H_ee_ref.translation();
    double error_norm = (current_pos_eigen - ref_pos_eigen).norm();

    if (elapsed_time_sec > goal->duration + 1.0 && error_norm < 6e-2) {
        result_msg_->is_completed = true;
        current_goal_handle_->succeed(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return true; // Indicate goal completion
    }

    // Check for abort (timeout)
    RCLCPP_INFO(node_->get_logger(), "[%s] Computing... Error norm: %f", action_name_.c_str(), error_norm);
    // RCLCPP_INFO(node_->get_logger(), "[%s] Elapsed time: %f seconds", action_name_.c_str(), elapsed_time_sec);
    // RCLCPP_INFO(node_->get_logger(), "[%s] Goal duration: %f seconds", action_name_.c_str(), goal->duration);
    if (elapsed_time_sec > goal->duration + 2.0) {
        RCLCPP_WARN(node_->get_logger(), "[%s] Goal Aborted (timeout). Error norm: %f", action_name_.c_str(), error_norm);
        result_msg_->is_completed = false;
        current_goal_handle_->abort(result_msg_);
        control_running_ = false;
        current_goal_handle_.reset();
        return false; // Indicate goal failure
    }

    // Print debug info periodically
    if (print_count_++ % iter_per_print_ == 0) {
        DEBUG_FILE("Time: " << current_time.seconds() << ", Error: " << error_norm);
        // RCLCPP_DEBUG(node_->get_logger(), "[%s] Computing... Error norm: %f", action_name_.c_str(), error_norm);
    }

    return true; // Indicate computation is ongoing for an active goal
}