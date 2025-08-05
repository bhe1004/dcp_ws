// Controller
#include "fairino_action_manager/controller/controller.hpp"
#include "fairino_action_manager/simulation/simulation_isaac.hpp"
#include <pinocchio/parsers/urdf.hpp>

using namespace std;
using namespace pinocchio;
using namespace Eigen;
using namespace RobotController;

FairinoController::FairinoController(const rclcpp::NodeOptions & opts)
  : rclcpp::Node("fairino_action_manager_simulation_isaac", opts)
{
  this->declare_parameter<std::string>("robot_ip", "192.168.58.2");
  this->declare_parameter<std::string>("model_path", "/home/home/dcp_ws/src/fairino/fairino_description");
  this->declare_parameter<std::string>("urdf_name", "/urdf/fairino5_v6.urdf");

  // Publisher
  isaac_joint_command_publisher_ = create_publisher<sensor_msgs::msg::JointState>(
    "/isaac_joint_command", 10
  );
}

void FairinoController::post_construction_initialize()
{
  ctrl_ = std::make_shared<FairinoWrapper>("fairino_isaac", this->shared_from_this());
  
  isaac_joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(
    "/isaac_joint_states", 1,
    std::bind(&FairinoController::JointStateCallback, this, std::placeholders::_1)
  );
  isaac_time_subscriber_ = this->create_subscription<rosgraph_msgs::msg::Clock>(
    "/clock", 1,
    std::bind(&FairinoController::simTimeCallback, this, std::placeholders::_1)
  );
  update_gripper_state_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(3),
    std::bind(&FairinoController::updateGripperStateCallback, this)
  );
  isaac_sensor_state_subscriber_ = this->create_subscription<geometry_msgs::msg::Wrench>(
    "/ft_sensor", 1,
    std::bind(&FairinoController::updateSensorStateCallback, this, std::placeholders::_1)
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
  gripper_sim_action_server_ = std::make_unique<GripperSimActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/gripper_control",
      ctrl_
  );
  qr_action_server_ = std::make_unique<QRActionServer>(
      this->shared_from_this(),
      "fairino_action_manager/qr_control",
      ctrl_
  );

  RCLCPP_INFO(get_logger(), "SE3ActionServer initialized.");

  control_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(1), // 1000 Hz (1ms 주기). 만약 1Hz가 맞다면 그대로 1000.
    std::bind(&FairinoController::controlLoopCallback, this)
  );

  RCLCPP_INFO(this->get_logger(), "FairinoController initialization complete.");
}


void FairinoController::JointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
{   
    Vector6d q, v;
    for (int i=0; i<6; i++) {
        q(i) = msg->position[i];
        v(i) = msg->velocity[i];
        // gui_joint_msg_.position[i] = ctrl_->state().fairino.q(i);
    }

    ctrl_->fairino_update(q, v);
    ctrl_->state().gripper.current_sim_pos = msg->position[6];
}

void FairinoController::simTimeCallback(const rosgraph_msgs::msg::Clock::SharedPtr msg)
{
    time_ = msg->clock.sec + msg->clock.nanosec * 1e-9;
}

void FairinoController::controlLoopCallback()
{
  if (!ctrl_) {
    RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 5000, "Controller (ctrl_) not initialized. Skipping control loop.");
    return;
  }

  // rclcpp::Time current_time = this->now();

  ctrl_->compute_all_terms(); // 실제 제어 계산

  if (se3_action_server_ && se3_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      se3_action_server_->compute(this->now());
  }
  else if (joint_posture_action_server_ && joint_posture_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      joint_posture_action_server_->compute(this->now());
  }
  else if (gripper_sim_action_server_ && gripper_sim_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      gripper_sim_action_server_->compute(this->now());
  }
  else if (qr_action_server_ && qr_action_server_->isrunning()) { // isrunning()이 goal active 상태를 확인한다고 가정
      qr_action_server_->compute(this->now());
  }
  else {
      ctrl_->compute_default_ctrl(this->now());
  }

  // // Command
  isaac_joint_command_msg_.header.stamp = this->now();
  isaac_joint_command_msg_.name = {"j1", "j2", "j3", "j4", "j5", "j6", "finger_joint"};
  isaac_joint_command_msg_.position.resize(7);

  for (size_t i = 0; i < 6; ++i) { // Arm Commands
      isaac_joint_command_msg_.position[i] = ctrl_->state().fairino.q_ref(i);
  }
  if (ctrl_->state().gripper.isgrasp) {
    // Gripper Close Command
    isaac_joint_command_msg_.position[6] = 0.78;
  } else {
    // Gripper Open Command
    isaac_joint_command_msg_.position[6] = 0.0; // Open position
  }
  
  isaac_joint_command_publisher_->publish(isaac_joint_command_msg_);
}

void FairinoController::updateGripperStateCallback()
{
  float percent;
  if (ctrl_->state().gripper.isgrasp) {
    percent = static_cast<float>(
      std::min(100.0, ctrl_->state().gripper.current_sim_pos / 0.78 * 100.0)
    );
    ctrl_->state().gripper.isdone = (percent >= 5.0);
  }
  else {
    percent = static_cast<float>(
        std::min(100.0, (1 - ctrl_->state().gripper.current_sim_pos / 0.78) * 100.0)
    );
    ctrl_->state().gripper.isdone = (percent >= 5.0);
  }
}

void FairinoController::updateSensorStateCallback(geometry_msgs::msg::Wrench::SharedPtr msg)
{
  ctrl_->state().sensor.ft_sensor_data_sim = *msg; // Update the sensor state with the received message
}


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options; // NodeOptions 사용 권장
  options.automatically_declare_parameters_from_overrides(true);
  auto node = std::make_shared<FairinoController>(options);

  node->post_construction_initialize(); // Post construction initialization

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}