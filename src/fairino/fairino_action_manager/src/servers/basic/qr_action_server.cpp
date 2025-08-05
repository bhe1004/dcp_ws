#include <fairino_action_manager/servers/basic/qr_action_server.hpp>
#include <pinocchio/fwd.hpp>

using namespace pinocchio;

QRActionServer::QRActionServer(rclcpp::Node::SharedPtr node, const std::string& name, std::shared_ptr<RobotController::FairinoWrapper> mu)
: ActionServerBase(node, name, mu), is_relative_(true)
{
    using namespace std::placeholders;

    this->action_server_ = rclcpp_action::create_server<QRAction>(
        this->node_, // Or node, if node_ is not yet initialized by base (it is)
        name, // Action name
        std::bind(&QRActionServer::handle_goal, this, _1, _2),
        std::bind(&QRActionServer::handle_cancel, this, _1),
        std::bind(&QRActionServer::handle_accepted, this, _1)
    );

    feedback_msg_ = std::make_shared<QRAction::Feedback>();
    result_msg_ = std::make_shared<QRAction::Result>();

    RCLCPP_INFO(node_->get_logger(), "QRActionServer [%s] started.", action_name_.c_str());
}

rclcpp_action::GoalResponse QRActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const QRAction::Goal> goal)
{
    RCLCPP_INFO(node_->get_logger(), "[%s] Received goal request", action_name_.c_str());
    RCLCPP_INFO(node_->get_logger(), "QR pos: (%f, %f, %f), orientation: (%f, %f, %f, %f), duration: %f",
        goal->qr_pose.position.x, goal->qr_pose.position.y, goal->qr_pose.position.z,
        goal->qr_pose.orientation.x, goal->qr_pose.orientation.y, goal->qr_pose.orientation.z, goal->qr_pose.orientation.w,
        goal->duration
    );
    RCLCPP_INFO(node_->get_logger(), "Target pos: (%f, %f, %f), orientation: (%f, %f, %f, %f), duration: %f",
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

rclcpp_action::CancelResponse QRActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleQR> goal_handle)
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

void QRActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleQR> goal_handle)
{
    current_goal_handle_ = goal_handle; // Store the handle
    const auto goal = goal_handle->get_goal();

    mu_->state().fairino.isrelative = false;

    Eigen::Matrix3d rot_offset;
    rot_offset.setZero();
    rot_offset.col(0) << cos(M_PI/4.0), sin(M_PI/4.0), 0;
    rot_offset.col(1) << cos(M_PI/4.0), -sin(M_PI/4.0), 0;
    rot_offset.col(2) << 0, 0, -1;

    SE3 target_tf;
    qr_tf_ = SE3(Eigen::Quaterniond(goal->qr_pose.orientation.w, goal->qr_pose.orientation.x, goal->qr_pose.orientation.y, goal->qr_pose.orientation.z).toRotationMatrix(),
                 Eigen::Vector3d(goal->qr_pose.position.x, goal->qr_pose.position.y, goal->qr_pose.position.z));
    target_tf = SE3(Eigen::Quaterniond(goal->target_pose.orientation.w, goal->target_pose.orientation.x, goal->target_pose.orientation.y, goal->target_pose.orientation.z).toRotationMatrix(),
                    Eigen::Vector3d(goal->target_pose.position.x, goal->target_pose.position.y, goal->target_pose.position.z));             

    SE3 oMi_ref = qr_tf_ * target_tf;
    oMi_ref.rotation() = oMi_ref.rotation() * rot_offset;
    mu_->state().fairino.H_ee_ref = oMi_ref;
    mu_->state().fairino.duration = goal->duration;

    start_time_ = node_->now();
    mu_->init_se3_ctrl(start_time_);
    control_running_ = true;

    RCLCPP_INFO(node_->get_logger(), "[%s] Goal accepted. Control running.", action_name_.c_str());
}

bool QRActionServer::compute(const rclcpp::Time& current_time)
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