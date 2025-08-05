// Controller
#include "fairino_action_manager/controller/controller.hpp"

// Fairino SDK header
#include "robot.h"

// Ros Header
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "geometry_msgs/msg/transform.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/wrench.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rosgraph_msgs/msg/clock.hpp"

//SYSTEM Header
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

// FairinoAction
#include <fairino_action_manager/servers/basic/joint_posture_action_server.hpp>
#include <fairino_action_manager/servers/basic/se3_action_server.hpp>
#include <fairino_action_manager/servers/basic/gripper_sim_action_server.hpp>
#include <fairino_action_manager/servers/basic/qr_action_server.hpp>

// #include <fairino_action_manager/servers/se3_array_action_server.hpp>

// Transform broadcaster & buffer/listener
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

using namespace Eigen;

class FairinoController : public rclcpp::Node
{
public:
    explicit FairinoController(const rclcpp::NodeOptions & opts = rclcpp::NodeOptions());
     ~FairinoController() = default;
    void post_construction_initialize();
    
    // void initialize_components();

private:
    std::shared_ptr<RobotController::FairinoWrapper> ctrl_;

    double time_;

    // Timer
    rclcpp::TimerBase::SharedPtr control_timer_;
    rclcpp::TimerBase::SharedPtr update_gripper_state_timer_;

    // Callbacks
    void JointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg);
    void simTimeCallback(const rosgraph_msgs::msg::Clock::SharedPtr msg);
    void controlLoopCallback();
    void updateGripperStateCallback();
    void updateSensorStateCallback(const geometry_msgs::msg::Wrench::SharedPtr msg);

    // publihser
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr isaac_joint_command_publisher_; // "/isaac_joint_command"

    // Subscription
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr isaac_joint_state_subscriber_; // "/isaac_joint_states"
    rclcpp::Subscription<rosgraph_msgs::msg::Clock>::SharedPtr isaac_time_subscriber_; // "/clock"
    rclcpp::Subscription<geometry_msgs::msg::Wrench>::SharedPtr isaac_sensor_state_subscriber_; // "/ft_sensor"

    // msg
    sensor_msgs::msg::JointState isaac_joint_command_msg_;

    // Action Server
    std::unique_ptr<JointPostureActionServer> joint_posture_action_server_;
    std::unique_ptr<SE3ActionServer> se3_action_server_;
    std::unique_ptr<GripperSimActionServer> gripper_sim_action_server_;
    std::unique_ptr<QRActionServer> qr_action_server_;
    // std::unique_ptr<SE3ArrayActionServer> se3_array_action_server_;
};