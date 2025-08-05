#pragma once

#include "fairino_action_manager/servers/task/base_task.hpp"

class Place : public BaseTask
{
public:
    using BaseTask::BaseTask; // 부모 클래스의 생성자 상속
    bool execute(const geometry_msgs::msg::Pose& target_pose, const float duration) override;
};