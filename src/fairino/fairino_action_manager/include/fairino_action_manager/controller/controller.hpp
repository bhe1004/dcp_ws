#ifndef __fairino_ctrl__
#define __fairino_ctrl__

//Pinocchio Header
#include <pinocchio/fwd.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp> 
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/frames.hpp>

// ROS Header
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include "geometry_msgs/msg/transform.hpp"
#include "geometry_msgs/msg/pose2_d.hpp"
#include "std_msgs/msg/int16.hpp"
#include "tf2/transform_datatypes.hpp"

//SYSTEM Header
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

// C++ Header
#include <thread>
#include <atomic>
#include <mutex>

// Fairino SDK header
#include "robot.h"

//ROS Header
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <std_msgs/msg/float32.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/transform.hpp>
#include <geometry_msgs/msg/pose2_d.hpp>
#include <std_msgs/msg/int16.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

// for hqp controller
#include <kimm_hqp_controller/robot/robot_wrapper.hpp>
#include <kimm_hqp_controller/formulation/inverse_dynamics_formulation_acc.hpp>
#include <kimm_hqp_controller/tasks/task_se3_equality.hpp>
#include <kimm_hqp_controller/tasks/task_joint_posture.hpp>
#include <kimm_hqp_controller/tasks/task_joint_bound.hpp>
#include <kimm_hqp_controller/tasks/task_mobile_base.hpp>
#include <kimm_hqp_controller/trajectory/trajectory_euclidian.hpp>
#include <kimm_hqp_controller/trajectory/trajectory_se3.hpp>
#include <kimm_hqp_controller/solver/solver_HQP_factory.hxx>
#include <kimm_hqp_controller/solver/util.hpp>
#include <kimm_hqp_controller/math/util.hpp>

// pak hqp controller
#include "pak_hqp_controller/controller/controller.hpp"
#include "pak_hqp_controller/task/task_se3_equality.hpp"
#include "pak_hqp_controller/task/task_only_yaw_free.hpp"
#include "pak_hqp_controller/robot/robot_wrapper.hpp"

#include <pak_hqp_controller/solver/solver.hpp>
#include <pak_hqp_controller/robot/robot_wrapper.hpp>
#include <pak_hqp_controller/controller/controller.hpp>
#include <pak_hqp_controller/task/task_se3_equality.hpp>
#include <pak_hqp_controller/task/task_only_yaw_free.hpp>

using namespace std;
using namespace Eigen;
using namespace pinocchio;

typedef Eigen::Matrix<double, 2, 1> Vector2d;
typedef Eigen::Matrix<double, 5, 1> Vector5d;
typedef Eigen::Matrix<double, 6, 1> Vector6d;
typedef Eigen::Matrix<double, 7, 1> Vector7d;
typedef Eigen::Matrix<double, 6, 6> Matrix6d;

typedef struct Fairino_State {
    Vector6d q;
    Vector6d v;
    Vector6d dv;
    Vector6d q_ref;
    Vector6d v_ref;
    DescPose desc_pos_ref{};
    Vector6d torque;
    Vector6d acc;
    SE3 H_ee_ref;
    SE3 H_ee_init;
    SE3 H_ee;
    Motion ee_vel;
    Vector3d ee_offset;
    std::vector<SE3> H_ee_ref_array;
    std::vector<double> duration_array;
    int array_cnt;
    Matrix6d M;
    Vector6d G;
    Matrix6d J;
    Matrix6d Jinv;
    double duration;
    bool isrelative;
    std::vector<bool> isrelative_array;
    
} fairino_state;

typedef struct Gripper_State {
    bool isgrasp;
    int position_percentage;
    bool speed_percentage;
    bool torque_percentage;
    bool isdone;
    bool command_executed;
    uint8_t current_real_pos;
    float current_sim_pos;
} gripper_state;

typedef struct Sensor_State {
    ForceTorque ft_sensor_data_real{};
    geometry_msgs::msg::Wrench ft_sensor_data_sim;
} sensor_state;

typedef struct ToolChanger_State {
    bool isgripped;
    bool isreached;
    int tool_id;
    float duration;
    bool isdone;
} tool_changer_state;

typedef struct State {
    fairino_state fairino;
    gripper_state gripper;
    sensor_state sensor;
    tool_changer_state tool_changer;

    double time;
    bool reset;
    Vector6d q_min;
    Vector6d q_max;
    Vector6d v_min;
    Vector6d v_max;
} state;

namespace RobotController
{
    class FairinoWrapper
    {
    public:
        FairinoWrapper(const std::string & robot_node, const rclcpp::Node::SharedPtr & node);
        ~FairinoWrapper() {};

        void initialize();
        void compute_default_ctrl(rclcpp::Time time);

        State & state() { return state_; }

        void computeAllTerms() {
            robot_->computeAllTerms(data_, state_.fairino.q, state_.fairino.v);
            state_.fairino.v.setZero();
        }
        void fairino_update(const Vector6d & q, const Vector6d & v);

        // HQP solver
        void init_joint_posture_ctrl(rclcpp::Time time);
        void compute_joint_posture_ctrl(rclcpp::Time time);
        void init_se3_ctrl(rclcpp::Time time);
        void compute_se3_ctrl(rclcpp::Time time);
        void init_se3_array_ctrl(rclcpp::Time time);
        void compute_se3_array_ctrl(rclcpp::Time time);
        void compute_all_terms();


    private:
        bool fairino_gripper_;
        std::string robot_node_;

        State state_;
        double time_;
        double stime_;
        int ctrl_mode_;
        int array_cnt_;
        int na_, nv_, nq_;
        bool isfinished_;

        rclcpp::Node::SharedPtr n_node_;

        std::shared_ptr<kimmhqp::robot::RobotWrapper> robot_;
        pinocchio::Model model_;
        pinocchio::Data data_;

        std::shared_ptr<kimmhqp::InverseDynamicsFormulationAccForce> tsid_;           
        std::shared_ptr<kimmhqp::tasks::TaskJointPosture> postureTask_;
        std::shared_ptr<kimmhqp::tasks::TaskSE3Equality> eeTask_;
        std::shared_ptr<kimmhqp::tasks::TaskJointBounds> torqueBoundsTask_;
        std::shared_ptr<kimmhqp::tasks::TaskMobileEquality> mobileTask_, mobileTask2_;

        std::shared_ptr<kimmhqp::trajectory::TrajectoryEuclidianCubic> trajPosture_Cubic_;
        std::shared_ptr<kimmhqp::trajectory::TrajectoryEuclidianConstant> trajPosture_Constant_;
        std::shared_ptr<kimmhqp::trajectory::TrajectoryEuclidianTimeopt> trajPosture_Timeopt_;
        std::shared_ptr<kimmhqp::trajectory::TrajectorySE3Cubic> trajEE_Cubic_, trajMobile_Cubic_;
        std::shared_ptr<kimmhqp::trajectory::TrajectorySE3Constant> trajEE_Constant_, trajMobile_Constant_;
        std::shared_ptr<kimmhqp::trajectory::TrajectorySE3Timeopt> trajEE_Timeopt_, trajMobile_Timeopt_;            

        kimmhqp::trajectory::TrajectorySample sampleEE_, samplePosture_, sampleMobile_;
        kimmhqp::solver::SolverHQPBase * solver_;

        std::shared_ptr<pak_hqp_controller::robot::RobotWrapper> robot_wrapper_;
        std::shared_ptr<pak_hqp_controller::controller::Controller> controller_;
        std::shared_ptr<pak_hqp_controller::task::TaskSE3Equality> se3_task_;
        std::shared_ptr<pak_hqp_controller::task::TaskOnlyYawFree> yaw_free_task_;

        Eigen::Vector3d base_pos_; 
    };
}

#endif