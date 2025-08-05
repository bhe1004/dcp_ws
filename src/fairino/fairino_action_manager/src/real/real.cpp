// Controller
#include "fairino_action_manager/controller/controller.hpp"
#include "fairino_action_manager/real/real.hpp"
#include <pinocchio/parsers/urdf.hpp>

using namespace std;
using namespace pinocchio;
using namespace Eigen;
using namespace RobotController;

FairinoController::FairinoController(const rclcpp::NodeOptions & opts)
  : rclcpp::Node("fairino_action_manager_real", opts)
{
  // 1. 파라미터 선언 (가장 중요!)
  // launch 파일과 동일하게 기본값을 지정하는 것이 좋습니다.
  this->declare_parameter<std::string>("robot_ip", "192.168.58.2");
  this->declare_parameter<std::string>("robot_group", "fr5");
  this->declare_parameter<std::string>("urdf_full", ""); // URDF 경로이므로 기본값으로 빈 문자열을 줍니다.
  this->declare_parameter<std::string>("model_path", "/home/home/dcp_ws/src/fairino/robotiq_description");
  this->declare_parameter<std::string>("urdf_name", "/urdf/fairino5_v6.urdf");

  // Robot Linking
  std::string robot_ip;
  this->get_parameter("robot_ip", robot_ip); // Parameter for GUI URDF
  RCLCPP_INFO(get_logger(), "Robot IP: %s", robot_ip.c_str());

  // Robot Initialization
  initializeRobot(robot_ip);
  initializeFTSensor();
  initializeGripper();
  initializeToolChanger();

  std::string urdfFileNameForGui;
  this->get_parameter("urdf_full", urdfFileNameForGui); // Parameter for GUI URDF

  pinocchio::Model gui_model;
  pinocchio::urdf::buildModel(urdfFileNameForGui, gui_model, false); // Use the correct variable

  gui_joint_msg_.name.resize(gui_model.nq);
  gui_joint_msg_.position.resize(gui_model.nq);
  gui_joint_msg_.velocity.resize(gui_model.nq);
  gui_joint_msg_.effort.resize(gui_model.nq);

  // Pinocchio's model.names includes "universe" as the first element (index 0).
  // Actual joint names start from index 1.
  if (gui_model.njoints > 1) { // Ensure there's more than just 'universe'
    for (int j = 0; j < gui_model.nq; j++) { // Assuming nq matches number of named joints after universe
      gui_joint_msg_.name[j] = gui_model.names[j + 1]; // Names[0] is universe
      gui_joint_msg_.position[j] = 0.0;
      gui_joint_msg_.velocity[j] = 0.0;
      gui_joint_msg_.effort[j] = 0.0;
    }
  } else {
      RCLCPP_WARN(get_logger(), "GUI URDF model has no joints (nq=%d, njoints=%d). JointState messages will be empty.", gui_model.nq, gui_model.njoints);
  }

  gui_joint_publisher_ = create_publisher<sensor_msgs::msg::JointState>("/joint_states", 100);
}

FairinoController::~FairinoController()
{
  // Stop the robot
  robot_.ServoMoveEnd();
  robot_.RobotEnable(0);
  robot_.CloseRPC();
}

void FairinoController::initializeRobot(const std::string& ip)
{
  if (robot_.RPC(ip.c_str()) != 0) {
    RCLCPP_ERROR(get_logger(), "RPC connect failed");
    throw std::runtime_error("RPC connect failed");
  }

  if (robot_.ResetAllError() != 0) {
    RCLCPP_WARN(get_logger(), "ResetAllError failed or not needed");
  }

  if (robot_.RobotEnable(1) != 0) {
    RCLCPP_ERROR(get_logger(), "RobotEnable failed");
    throw std::runtime_error("RobotEnable failed");
  }

  if (robot_.Mode(0) != 0) {
    RCLCPP_WARN(get_logger(), "Initial Mode(0) failed. Trying again after resetting error...");

    robot_.ResetAllError();
    robot_.RobotEnable(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    robot_.RobotEnable(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if (robot_.Mode(0) != 0) {
      RCLCPP_ERROR(get_logger(), "SetRobotMode failed after retry");
      throw std::runtime_error("SetRobotMode failed after retry");
    }
  }

  if (robot_.ServoMoveStart() != 0) {
    RCLCPP_WARN(get_logger(), "ServoMoveStart failed (will retry on command)");
  }

  RCLCPP_INFO(get_logger(), "Robot initialization completed successfully");
}

void FairinoController::initializeFTSensor()
{
  int company = 22; // 22-Weihang Minxin
  int device = 0;
  int softversion = 0;
  int bus = 0;

  if (robot_.FT_SetConfig(company, device, softversion, bus) != 0) {
    RCLCPP_ERROR(get_logger(), "FT_SetConfig failed");
    return;
  }
  std::this_thread::sleep_for(1s);
  if (robot_.FT_Activate(1) != 0) {
    RCLCPP_ERROR(get_logger(), "FT_Activate failed");
    return;
  }
  std::this_thread::sleep_for(1s);

  if (robot_.SetLoadWeight(0, 0.0f) != 0) {
    RCLCPP_ERROR(get_logger(), "SetLoadWeight failed");
    return;
  }
  std::this_thread::sleep_for(1s);

  DescTran coord{};
  if (robot_.SetLoadCoord(&coord) != 0) {
    RCLCPP_ERROR(get_logger(), "SetLoadCoord failed");
    return;
  }
  std::this_thread::sleep_for(1s);

  if (robot_.FT_SetZero(1) != 0) {
    RCLCPP_ERROR(get_logger(), "FT_SetZero(1) failed");
    return;
  }

  RCLCPP_INFO(get_logger(), "FT sensor initialization completed successfully");
}

void FairinoController::initializeGripper()
{
  // Gripper Configuration
  int company = 4;
  int device = 0;
  int softversion = 0;
  int bus = 1;
  int index = 1;

  robot_.SetGripperConfig(company, device, softversion, bus);
  robot_.GetGripperConfig(&company, &device, &softversion, &bus);

  robot_.ActGripper(index, 0); // Reset
  robot_.ActGripper(index, 1); // Activate
  RCLCPP_INFO(get_logger(), "Gripper initialization completed successfully");
  RCLCPP_INFO(get_logger(), "Gripper config: %d, %d, %d, %d", company, device, softversion, bus);
}

void FairinoController::post_construction_initialize()
{
  ctrl_ = std::make_shared<FairinoWrapper>("fairino_real", this->shared_from_this());
  
  update_robot_state_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(3),
    std::bind(&FairinoController::updateRobotStateCallback, this)
  );

  update_sensor_state_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(3),
    std::bind(&FairinoController::updateSensorStateCallback, this)
  );

  update_gripper_state_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(3),
    std::bind(&FairinoController::updateGripperStateCallback, this)
  );

  if (ctrl_) {
    ctrl_->initialize();
    RCLCPP_INFO(get_logger(), "FairinoWrapper initialized.");
  } else {
    RCLCPP_ERROR(get_logger(), "Failed to create FairinoWrapper instance!");
    rclcpp::shutdown(); // 심각한 오류 시 종료
    return;
  }

  se3_action_server_ = std::make_unique<SE3ActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/se3_control",
      ctrl_
  );
  joint_posture_action_server_ = std::make_unique<JointPostureActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/joint_posture_control",
      ctrl_
  );
  gripper_real_action_server_ = std::make_unique<GripperRealActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/gripper_control",
      ctrl_
  );
  tool_changer_action_server_ = std::make_unique<ToolChangerActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/tool_changer_control",
      ctrl_
  );

  RCLCPP_INFO(get_logger(), "SE3ActionServer initialized.");
  // 다른 action server들도 필요하다면 여기서 초기화

  control_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(3),
    std::bind(&FairinoController::controlLoopCallback, this)
  );

  RCLCPP_INFO(this->get_logger(), "FairinoController initialization complete.");
}

void FairinoController::controlLoopCallback()
{
  if (!ctrl_) {
    RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 5000, "Controller (ctrl_) not initialized. Skipping control loop.");
    return;
  }

  ctrl_->compute_all_terms(); // 실제 제어 계산

  if (se3_action_server_ && se3_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      se3_action_server_->compute(this->now());
  }
  else if (joint_posture_action_server_ && joint_posture_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      joint_posture_action_server_->compute(this->now());
  }
  else if (gripper_real_action_server_ && gripper_real_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      gripper_real_action_server_->compute(this->now());
  }
  else if (tool_changer_action_server_ && tool_changer_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      tool_changer_action_server_->compute(this->now());
  }
  else {
      ctrl_->compute_default_ctrl(this->now());
  }

  // Servo Parameter
  constexpr float acc     = 0.0;
  constexpr float vel     = 0.0;
  constexpr float cmdT    = 0.001;
  constexpr float filterT = 0.0;
  constexpr float gain    = 0.0;
  ExaxisPos ex_axis{};

  // Arm Command
  for (int i=0; i<6; i++) {
    robot_command_.jPos[i] = static_cast<float>(ctrl_->state().fairino.q_ref(i) * 180.0 / M_PI); // deg
  }
  int ret = robot_.ServoJ(&robot_command_, &ex_axis, acc, vel, cmdT, filterT, gain);
  if (ret != 0) {
    RCLCPP_ERROR_THROTTLE(get_logger(), *this->get_clock(), 1000, "ServoJ failed (%d)", ret);
  }

  // Gripper Command
  int index = 1;
  int max_time = 5000;
  uint8_t block = 1; // 0-blocking, 1-non-blocking
  int type = 0; // 0-parallel gripper; 1-rotary gripper;

  if (!ctrl_->state().gripper.isdone) {
    if (ctrl_->state().gripper.isgrasp) {
      robot_.MoveGripper(
        index,
        ctrl_->state().gripper.position_percentage,
        ctrl_->state().gripper.speed_percentage,
        ctrl_->state().gripper.torque_percentage, max_time, block, type,
        0, 0.0, 0.0
      );
    }
    else {
      robot_.MoveGripper(
        index,
        ctrl_->state().gripper.position_percentage,
        ctrl_->state().gripper.speed_percentage,
        ctrl_->state().gripper.torque_percentage, max_time, block, type,
        0, 0.0, 0.0
      );
    }
  }

  // Tool Changer Command
  if (!ctrl_->state().tool_changer.isdone) {
    if (ctrl_->state().tool_changer.isgripped) {
      gripToolChanger();
    } else {
      releaseToolChanger();
    }
    ctrl_->state().tool_changer.isdone = true;
  }

  // Publish GUI JointState message
  gui_joint_msg_.header.stamp = this->now();
  gui_joint_publisher_->publish(gui_joint_msg_);
}



void FairinoController::updateRobotStateCallback()
{
  int flag = 1; // 0: wait for robot's response, 1: no wait
  JointPos q_deg{};
  float v_deg[6] = {0.0f};

  if (robot_.GetActualJointPosDegree(flag, &q_deg) != 0) return;
  if (robot_.GetActualJointSpeedsDegree(flag, v_deg) != 0) return;

  Vector6d q, v;
  for (int i=0; i<6; i++) {
    q(i) = static_cast<double>(q_deg.jPos[i] * M_PI / 180);   // rad
    v(i) = static_cast<double>(v_deg[i] * M_PI / 180);   // rad / s
    gui_joint_msg_.position[i] = ctrl_->state().fairino.q(i);
  }
  ctrl_->fairino_update(q, v);
}

void FairinoController::updateSensorStateCallback()
{
  if (robot_.FT_GetForceTorqueRCS(1, &ctrl_->state().sensor.ft_sensor_data_real) != 0) return;
}

void FairinoController::updateGripperStateCallback()
{
  uint16_t fault;
  uint8_t status;
  uint8_t current_pos;

  robot_.GetGripperMotionDone(&fault, &status);
  robot_.GetGripperCurPosition(&fault, &current_pos);

  if (!ctrl_->state().gripper.isdone) { // Only update if not already done
    ctrl_->state().gripper.isdone = static_cast<bool>(status);
  }
  ctrl_->state().gripper.current_real_pos = current_pos;
}


void FairinoController::initializeToolChanger()
{
  // Initialize Tool Changer
  // robot_.SetDO(0, 0, 0, 1);
  // robot_.SetDO(1, 0, 0, 1);
  RCLCPP_INFO(get_logger(), "Tool Changer initialized");
}
void FairinoController::releaseToolChanger()
{
  // Release Control
  // White(DO0) -> 0V, Green -> 24V(200ms)
  robot_.SetDO(0, 0, 0, 1); // Set DO0 to 0V
  robot_.SetDO(1, 1, 0, 1); // Set DO1 to 24V
  robot_.Sleep(200); // Sleep for 200 ms
  robot_.SetDO(1, 0, 0, 1); // Set DO1 back to 0V
  RCLCPP_INFO(get_logger(), "Tool Changer released");
}
void FairinoController::gripToolChanger()
{
  // Grip Control
  // Green(DO1) -> 0V, White(DO0) -> 24V(200ms)
  robot_.SetDO(1, 0, 0, 1); // Set DO1 to 0V
  robot_.SetDO(0, 1, 0, 1); // Set DO0 to 24V
  robot_.Sleep(200); // Sleep for 200 ms
  robot_.SetDO(0, 0, 0, 1); // Set DO0 back to 0V
  RCLCPP_INFO(get_logger(), "Tool Changer gripped");
}


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  options.automatically_declare_parameters_from_overrides(true);
  auto node = std::make_shared<FairinoController>();

  node->post_construction_initialize();

  rclcpp::spin(node);
  
  rclcpp::shutdown();
  return 0;
}