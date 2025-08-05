#pragma once

#include <string>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "fairino_interfaces/action/se3.hpp"
#include "fairino_interfaces/action/gripper.hpp"
#include "geometry_msgs/msg/pose.hpp"

// 타입 별칭
using SE3Action = fairino_interfaces::action::SE3;
using GripperAction = fairino_interfaces::action::Gripper;
using SE3ActionClient = rclcpp_action::Client<SE3Action>;
using GripperActionClient = rclcpp_action::Client<GripperAction>;

class BaseTask
{
public:
    // 생성자: 노드 포인터와 액션 클라이언트를 전달받음
    BaseTask(
        rclcpp::Node::SharedPtr node,
        SE3ActionClient::SharedPtr se3_client,
        GripperActionClient::SharedPtr gripper_client);

    virtual ~BaseTask() = default;

    // 순수 가상 함수: 파생 클래스에서 반드시 구현해야 할 스킬 실행 함수
    virtual bool execute(
        const geometry_msgs::msg::Pose& target_pose, 
        const float duration) = 0;

protected:
    // 공통 헬퍼 함수
    bool move_to_pose(const geometry_msgs::msg::Pose& pose, float duration);
    bool control_gripper(bool grasp);

    // 멤버 변수
    rclcpp::Node::SharedPtr node_;
    SE3ActionClient::SharedPtr se3_client_;
    GripperActionClient::SharedPtr gripper_client_;
};