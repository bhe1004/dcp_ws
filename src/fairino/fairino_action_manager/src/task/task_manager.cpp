#include "fairino_action_manager/task/task_manager.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"

using namespace std::chrono_literals;

// [수정] 생성자는 액션 클라이언트만 생성하도록 단순화
TaskServiceManager::TaskServiceManager(const rclcpp::NodeOptions & options)
    : Node("task_manager", options)
{
    action_callback_group_ = this->create_callback_group(
        rclcpp::CallbackGroupType::Reentrant
    );

    // [수정] 액션 클라이언트를 생성할 때, 생성한 콜백 그룹을 전달합니다.
    se3_client_ = rclcpp_action::create_client<SE3Action>(
        this, 
        "/fairino_action_manager/se3_control", 
        action_callback_group_
    );
    gripper_client_ = rclcpp_action::create_client<GripperAction>(
        this, 
        "/fairino_action_manager/gripper_control", 
        action_callback_group_
    );
}

// [수정] 새로운 setup 함수에 초기화 로직 구현
void TaskServiceManager::setup()
{
    RCLCPP_INFO(this->get_logger(), "Waiting for action servers...");
    if (!se3_client_->wait_for_action_server(10s) || !gripper_client_->wait_for_action_server(10s)) {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting. Shutting down.");
        rclcpp::shutdown();
        return;
    }
    RCLCPP_INFO(this->get_logger(), "Action servers are ready.");

    pick_service_ = this->create_service<PickTask>(
        "task_manager/pick", 
        std::bind(&TaskServiceManager::handle_pick_request, this, std::placeholders::_1, std::placeholders::_2));
    
    place_service_ = this->create_service<PlaceTask>(
        "task_manager/place", 
        std::bind(&TaskServiceManager::handle_place_request, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "Task Service Manager is ready. 'pick' and 'place' services are available.");
}

void TaskServiceManager::handle_pick_request(
    const std::shared_ptr<PickTask::Request> request,
    std::shared_ptr<PickTask::Response> response)
{   
    RCLCPP_INFO(this->get_logger(), "Pick requested by: %s", request->client_id.c_str());

    Pick pick_task(shared_from_this(), se3_client_, gripper_client_, request->client_id);
    
    response->is_completed = pick_task.execute(request->target_pose, request->duration);
}

void TaskServiceManager::handle_place_request(
    const std::shared_ptr<PlaceTask::Request> request,
    std::shared_ptr<PlaceTask::Response> response)
{   
    RCLCPP_INFO(this->get_logger(), "Place requested by: %s", request->client_id.c_str());

    Place place_task(shared_from_this(), se3_client_, gripper_client_, request->client_id);
    
    response->is_completed = place_task.execute(request->target_pose, request->duration);
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true);
    auto task_service_manager = std::make_shared<TaskServiceManager>(node_options);
    task_service_manager->setup();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(task_service_manager);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}