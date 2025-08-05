#pragma once

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "fairino_action_manager/servers/task/pick.hpp"
#include "fairino_action_manager/servers/task/place.hpp"
#include <fairino_interfaces/srv/pick.hpp>
#include <fairino_interfaces/srv/place.hpp>

// 타입 별칭
using PickTask = fairino_interfaces::srv::Pick;
using PlaceTask = fairino_interfaces::srv::Place;

// [수정] std::enable_shared_from_this 추가
class TaskServiceManager : public rclcpp::Node
{
public:
    explicit TaskServiceManager(const rclcpp::NodeOptions & options);
    
    void setup();

private:
    // 서비스 콜백 함수
    void handle_pick_request(
        const std::shared_ptr<PickTask::Request> request,
        std::shared_ptr<PickTask::Response> response);
    
    void handle_place_request(
        const std::shared_ptr<PlaceTask::Request> request,
        std::shared_ptr<PlaceTask::Response> response);

    rclcpp::CallbackGroup::SharedPtr action_callback_group_;

    // 액션 클라이언트
    SE3ActionClient::SharedPtr se3_client_;
    GripperActionClient::SharedPtr gripper_client_;

    // 서비스 서버
    rclcpp::Service<PickTask>::SharedPtr pick_service_;
    rclcpp::Service<PlaceTask>::SharedPtr place_service_;
};