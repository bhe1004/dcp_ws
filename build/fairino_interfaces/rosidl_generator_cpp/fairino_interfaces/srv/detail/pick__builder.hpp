// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fairino_interfaces:srv/Pick.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__SRV__DETAIL__PICK__BUILDER_HPP_
#define FAIRINO_INTERFACES__SRV__DETAIL__PICK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fairino_interfaces/srv/detail/pick__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fairino_interfaces
{

namespace srv
{

namespace builder
{

class Init_Pick_Request_duration
{
public:
  explicit Init_Pick_Request_duration(::fairino_interfaces::srv::Pick_Request & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::srv::Pick_Request duration(::fairino_interfaces::srv::Pick_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::srv::Pick_Request msg_;
};

class Init_Pick_Request_target_pose
{
public:
  Init_Pick_Request_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pick_Request_duration target_pose(::fairino_interfaces::srv::Pick_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_Pick_Request_duration(msg_);
  }

private:
  ::fairino_interfaces::srv::Pick_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::srv::Pick_Request>()
{
  return fairino_interfaces::srv::builder::Init_Pick_Request_target_pose();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace srv
{

namespace builder
{

class Init_Pick_Response_is_completed
{
public:
  Init_Pick_Response_is_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::srv::Pick_Response is_completed(::fairino_interfaces::srv::Pick_Response::_is_completed_type arg)
  {
    msg_.is_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::srv::Pick_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::srv::Pick_Response>()
{
  return fairino_interfaces::srv::builder::Init_Pick_Response_is_completed();
}

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__SRV__DETAIL__PICK__BUILDER_HPP_
