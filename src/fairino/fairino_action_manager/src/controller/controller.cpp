#include "fairino_action_manager/controller/controller.hpp"

using namespace pinocchio;
using namespace Eigen;
using namespace std;
using namespace kimmhqp;
using namespace kimmhqp::trajectory;
using namespace kimmhqp::math;
using namespace kimmhqp::tasks;
using namespace kimmhqp::solver;
using namespace kimmhqp::robot;

namespace RobotController
{
    FairinoWrapper::FairinoWrapper(const std::string & robot_node, const rclcpp::Node::SharedPtr & node)
        : robot_node_(robot_node), n_node_(node)
    {
        time_ = 0.0;
        ctrl_mode_ = 999;
    }

    void FairinoWrapper::initialize(){
        std::string model_path, urdf_name;
        n_node_->get_parameter("model_path", model_path);
        n_node_->get_parameter("urdf_name", urdf_name);
        vector<string> package_dirs;
        package_dirs.push_back(model_path);
        string urdfFileName = package_dirs[0] + urdf_name;
        std::cout << "URDF file name: " << urdfFileName << std::endl;

        robot_ = std::make_shared<RobotWrapper>(urdfFileName, package_dirs, false, false); // mobile_flag_ = false
        model_ = robot_->model();
        na_ = robot_->na();
        nv_ = robot_->nv();
        nq_ = robot_->nq();

        // State
        state_.fairino.q.setZero(nq_);
        state_.fairino.v.setZero(nv_);
        state_.fairino.dv.setZero(nv_);
        state_.fairino.torque.setZero(na_);
        state_.gripper.isgrasp = false;
        state_.gripper.isdone = false;
        state_.reset = true;

        // Joint limits
        state_.q_min.resize(na_);
        state_.q_max.resize(na_);
        state_.v_min.resize(na_);
        state_.v_max.resize(na_);
        state_.q_min << -3.0543, -4.6251, -2.8274, -4.6251, -3.0543, -3.0543;
        state_.q_max << 3.0543, 1.4835, 2.8274, 1.4835, 3.0543, 3.0543;
        state_.v_min << -3.14, -3.14, -3.14, -3.14, -3.14, -3.14;
        state_.v_max << 3.14, 3.14, 3.14, 3.14, 3.14, 3.14;
        tsid_ = std::make_shared<InverseDynamicsFormulationAccForce>("tsid", *robot_);
        tsid_->computeProblemData(time_, state_.fairino.q, state_.fairino.v);
        data_ = tsid_->data();

        postureTask_ = std::make_shared<TaskJointPosture>("task-posture", *robot_);
        Vector6d posture_gain;

        posture_gain << 200., 200., 200., 200., 200., 200.;
        postureTask_->Kp(posture_gain);
        postureTask_->Kd(2.0*postureTask_->Kp().cwiseSqrt());

        Vector3d ee_offset(0.0, 0, 0.0);
        VectorXd ee_gain(6);
        ee_gain << 1200., 1200., 1200.,
                   1200., 1200., 1200.;
        eeTask_ = std::make_shared<TaskSE3Equality>("task-se3", *robot_, "j6", ee_offset);
        eeTask_->Kp(ee_gain); 
        eeTask_->Kd(1.4 * eeTask_->Kp().cwiseSqrt());
        
        torqueBoundsTask_ = std::make_shared<TaskJointBounds>("task-torque-bounds", *robot_);
        Eigen::VectorXd dq_max = 500000.0 * Eigen::VectorXd::Ones(na_); 
        dq_max(0) = 2000.;
        dq_max(1) = 2000.;
        Eigen::VectorXd dq_min = -dq_max;
        torqueBoundsTask_->setJointBounds(dq_min, dq_max);

        // trajecotries
        sampleEE_.resize(12, 6);
        samplePosture_.resize(na_);

        trajPosture_Cubic_ = std::make_shared<TrajectoryEuclidianCubic>("traj_posture");
        trajPosture_Constant_ = std::make_shared<TrajectoryEuclidianConstant>("traj_posture_constant");
        trajPosture_Timeopt_ = std::make_shared<TrajectoryEuclidianTimeopt>("traj_posture_timeopt");
        
        trajEE_Cubic_ = std::make_shared<TrajectorySE3Cubic>("traj_ee");
        trajEE_Constant_ = std::make_shared<TrajectorySE3Constant>("traj_ee_constant");
        Vector3d Maxvel_ee = Vector3d::Ones()*0.2;
        Vector3d Maxacc_ee = Vector3d::Ones()*0.2;
        trajEE_Timeopt_ = std::make_shared<TrajectorySE3Timeopt>("traj_ee_timeopt", Maxvel_ee, Maxacc_ee);

        // solver
        solver_ = SolverHQPFactory::createNewSolver(SOLVER_HQP_EIQUADPROG, "quadprog");  
        
        // Pak HQP Controller ///
        robot_wrapper_ = std::make_shared<pak_hqp_controller::robot::RobotWrapper>(urdfFileName);
        controller_ = std::make_shared<pak_hqp_controller::controller::Controller>(*robot_wrapper_);
    }

    void FairinoWrapper::fairino_update(const Vector6d & q, const Vector6d & v) {
        state_.fairino.q = q;
        state_.fairino.v = v;
    }

    void FairinoWrapper::compute_all_terms() {
        robot_->computeAllTerms(data_, state_.fairino.q, state_.fairino.v);

        state_.fairino.H_ee = robot_->position(data_, robot_->model().getJointId("j6"));
        state_.fairino.ee_vel = robot_->velocity(data_, robot_->model().getJointId("j6"));
    }

    void FairinoWrapper::compute_default_ctrl(rclcpp::Time time) {
        if (state_.reset) {
            tsid_->removeTask("task-se3");
            tsid_->removeTask("task-posture");
            tsid_->removeTask("task-torque-bounds");

            tsid_->addMotionTask(*postureTask_, 1e-5, 1);
            tsid_->addMotionTask(*torqueBoundsTask_, 1.0, 0);

            trajPosture_Cubic_->setInitSample(state_.fairino.q);
            trajPosture_Cubic_->setDuration(0.1);
            trajPosture_Cubic_->setStartTime(time.seconds());
            trajPosture_Cubic_->setGoalSample(state_.fairino.q);

            cout << "state reset " << endl;
            state_.reset = false;
        }
        trajPosture_Cubic_->setCurrentTime(time.seconds());
        samplePosture_ = trajPosture_Cubic_->computeNext();

        state_.fairino.q_ref = samplePosture_.pos;
        state_.fairino.q_ref = state_.fairino.q_ref.cwiseMin(state_.q_max).cwiseMax(state_.q_min);
    }

    void FairinoWrapper::init_joint_posture_ctrl(rclcpp::Time time) {
        tsid_->removeTask("task-se3");
        tsid_->removeTask("task-posture");
        tsid_->removeTask("task-torque-bounds");

        tsid_->addMotionTask(*postureTask_, 1e-5, 1);
        tsid_->addMotionTask(*torqueBoundsTask_, 1.0, 0);

        trajPosture_Cubic_->setInitSample(state_.fairino.q);
        trajPosture_Cubic_->setDuration(state_.fairino.duration);
        trajPosture_Cubic_->setStartTime(time.seconds());
        trajPosture_Cubic_->setGoalSample(state_.fairino.q_ref);  
    }

    void FairinoWrapper::compute_joint_posture_ctrl(rclcpp::Time time){
        trajPosture_Cubic_->setCurrentTime(time.seconds());
        samplePosture_ = trajPosture_Cubic_->computeNext();

        state_.fairino.q_ref = samplePosture_.pos;
        state_.fairino.q_ref = state_.fairino.q_ref.cwiseMin(state_.q_max).cwiseMax(state_.q_min);

        state_.reset = true;
    }

    void FairinoWrapper::init_se3_ctrl(rclcpp::Time time) {
        state_.fairino.q_ref = state_.fairino.q;
    
        trajEE_Cubic_->setInitSample(state_.fairino.H_ee);
        trajEE_Cubic_->setDuration(state_.fairino.duration);
        trajEE_Cubic_->setStartTime(time.seconds());
        state_.fairino.H_ee_init = state_.fairino.H_ee;
        stime_ = time.seconds();
    
        if (state_.fairino.isrelative){
            state_.fairino.H_ee_ref.translation() = state_.fairino.H_ee.translation() + state_.fairino.H_ee_ref.translation();
            state_.fairino.H_ee_ref.rotation() = state_.fairino.H_ee.rotation() * state_.fairino.H_ee_ref.rotation();
        }
        trajEE_Cubic_->setGoalSample(state_.fairino.H_ee_ref);
    
        // --- 여기부터 HQP task 등록 ---
        // (기존 task 제거)
        controller_->removeTask("task-se3");
        controller_->removeTask("task-yaw-free");
    
        // [1] Yaw-free orientation 제약 task (priority 0)
        auto only_yaw_free_task = std::make_shared<pak_hqp_controller::task::TaskOnlyYawFree>(
            "task-yaw-free", *robot_wrapper_, "wrist3_link"
        );
        // 비커를 집었을 때 orientation을 기준(초기 orientation)
        only_yaw_free_task->setReference(state_.fairino.H_ee);
        only_yaw_free_task->setGain(100.0); // 필요시 gain 조정
    
        // [2] SE3 Equality 제약 task (priority 1)
        auto se3_task = std::make_shared<pak_hqp_controller::task::TaskSE3Equality>(
            "task-se3", *robot_wrapper_, "wrist3_link", Eigen::Vector3d::Zero() // 필요시 오프셋
        );
        se3_task->setReference(state_.fairino.H_ee);
        se3_task->setGains(200.0, 100.0);
    
        controller_->addTask(se3_task, 0);           // priority 1
    
        se3_task_ = se3_task;
    }

    void FairinoWrapper::init_place_ctrl(rclcpp::Time time) {
        state_.fairino.q_ref = state_.fairino.q;
    
        trajEE_Cubic_->setInitSample(state_.fairino.H_ee);
        trajEE_Cubic_->setDuration(state_.fairino.duration);
        trajEE_Cubic_->setStartTime(time.seconds());
        state_.fairino.H_ee_init = state_.fairino.H_ee;
        stime_ = time.seconds();
    
        if (state_.fairino.isrelative){
            state_.fairino.H_ee_ref.translation() = state_.fairino.H_ee.translation() + state_.fairino.H_ee_ref.translation();
            state_.fairino.H_ee_ref.rotation() = state_.fairino.H_ee.rotation() * state_.fairino.H_ee_ref.rotation();
        }
        trajEE_Cubic_->setGoalSample(state_.fairino.H_ee_ref);
    
        // --- 여기부터 HQP task 등록 ---
        // (기존 task 제거)
        controller_->removeTask("task-se3");
        controller_->removeTask("task-yaw-free");
    
        // [1] Yaw-free orientation 제약 task (priority 0)
        auto only_yaw_free_task = std::make_shared<pak_hqp_controller::task::TaskOnlyYawFree>(
            "task-yaw-free", *robot_wrapper_, "wrist3_link"
        );
        // 비커를 집었을 때 orientation을 기준(초기 orientation)
        only_yaw_free_task->setReference(state_.fairino.H_ee);
        only_yaw_free_task->setGain(200.0); // 필요시 gain 조정
    
        // [2] SE3 Equality 제약 task (priority 1)
        auto se3_task = std::make_shared<pak_hqp_controller::task::TaskSE3Equality>(
            "task-se3", *robot_wrapper_, "wrist3_link", Eigen::Vector3d::Zero() // 필요시 오프셋
        );
        se3_task->setReference(state_.fairino.H_ee);
        se3_task->setGains(200.0, 100.0);
    
        // [3] HQP controller에 task 추가 (priority 순서 지켜야 함)
        controller_->addTask(only_yaw_free_task, 0); // priority 0 (최상위)
        controller_->addTask(se3_task, 1);           // priority 1
    
        // [4] (선택) 멤버 변수에 저장
        yaw_free_task_ = only_yaw_free_task;
        se3_task_ = se3_task;
    }
    
    

    void FairinoWrapper::compute_se3_ctrl(rclcpp::Time time) {
        // Trajectory 진행 → EE 목표 pose 뽑기
        trajEE_Cubic_->setCurrentTime(time.seconds());
        sampleEE_ = trajEE_Cubic_->computeNext();
    
        // 목표 EE pose 생성 (pinocchio::SE3)
        pinocchio::SE3 targetEE;
        targetEE.translation() = sampleEE_.pos.head<3>();
        targetEE.rotation() = Eigen::Map<const Eigen::Matrix3d>(sampleEE_.pos.segment<9>(3).data());
    
        // [1] 최신 목표로 Task reference 갱신
        if (yaw_free_task_)  // (init에서 멤버로 보관해두었을 경우)
            yaw_free_task_->setReference(targetEE);
        if (se3_task_)  // (init에서 멤버로 보관해두었을 경우)
            se3_task_->setReference(targetEE);
    
        // [2] 현재 상태
        Eigen::VectorXd q = state_.fairino.q;
        Eigen::VectorXd v = state_.fairino.v;
    
        // [3] HQP Controller에서 qdot 계산
        Eigen::VectorXd qdot = controller_->compute(time.seconds(), q, v);
    
        // [4] 적분하여 q_ref 갱신
        double dt = 0.003;
        state_.fairino.q_ref = pinocchio::integrate(robot_wrapper_->model(), q, dt * qdot);
    
        state_.reset = true;
    }
    
} // namespace