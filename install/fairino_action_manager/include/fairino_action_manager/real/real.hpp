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

//SYSTEM Header
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

// FairinoAction
#include <fairino_action_manager/servers/basic/joint_posture_action_server.hpp>
#include <fairino_action_manager/servers/basic/se3_action_server.hpp>
#include <fairino_action_manager/servers/basic/gripper_real_action_server.hpp>
#include <fairino_action_manager/servers/basic/tool_changer_action_server.hpp>
// #include <fairino_action_manager/servers/basic/se3_array_action_server.hpp>

// Transform broadcaster & buffer/listener
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

using namespace Eigen;

class FairinoController : public rclcpp::Node
{
public:
    explicit FairinoController(const rclcpp::NodeOptions & opts = rclcpp::NodeOptions());
    ~FairinoController();
    
    void post_construction_initialize();

private:
    FRRobot robot_;
    std::shared_ptr<RobotController::FairinoWrapper> ctrl_;

    double time_;

    // Timer
    rclcpp::TimerBase::SharedPtr control_timer_;
    rclcpp::TimerBase::SharedPtr update_robot_state_timer_;
    rclcpp::TimerBase::SharedPtr update_sensor_state_timer_;
    rclcpp::TimerBase::SharedPtr update_gripper_state_timer_;

    // Callbacks
    void controlLoopCallback();
    void updateRobotStateCallback();
    void updateSensorStateCallback();
    void updateGripperStateCallback();

    // publihser
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr gui_joint_publisher_;

    // msg
    JointPos robot_command_{};
    sensor_msgs::msg::JointState gui_joint_msg_;

    // Action Server
    std::unique_ptr<JointPostureActionServer> joint_posture_action_server_;
    std::unique_ptr<SE3ActionServer> se3_action_server_;
    std::unique_ptr<GripperRealActionServer> gripper_real_action_server_;
    std::unique_ptr<ToolChangerActionServer> tool_changer_action_server_;
    // std::unique_ptr<SE3ArrayActionServer> se3_array_action_server_;

    // Robot State Update
    void initializeRobot(const std::string& ip);
    void updateJointState();
    void initializeFTSensor();
    void updateSensorState();
    void initializeGripper();
    void initializeToolChanger();
    void releaseToolChanger();
    void gripToolChanger();
};