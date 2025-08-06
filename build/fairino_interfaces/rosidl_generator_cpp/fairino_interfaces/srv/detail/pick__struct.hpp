// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fairino_interfaces:srv/Pick.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_HPP_
#define FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__srv__Pick_Request __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__srv__Pick_Request __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Pick_Request_
{
  using Type = Pick_Request_<ContainerAllocator>;

  explicit Pick_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0f;
    }
  }

  explicit Pick_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0f;
    }
  }

  // field types and members
  using _target_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_pose_type target_pose;
  using _duration_type =
    float;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__target_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target_pose = _arg;
    return *this;
  }
  Type & set__duration(
    const float & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::srv::Pick_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::srv::Pick_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::srv::Pick_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::srv::Pick_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__srv__Pick_Request
    std::shared_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__srv__Pick_Request
    std::shared_ptr<fairino_interfaces::srv::Pick_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pick_Request_ & other) const
  {
    if (this->target_pose != other.target_pose) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pick_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pick_Request_

// alias to use template instance with default allocator
using Pick_Request =
  fairino_interfaces::srv::Pick_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fairino_interfaces


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__srv__Pick_Response __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__srv__Pick_Response __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Pick_Response_
{
  using Type = Pick_Response_<ContainerAllocator>;

  explicit Pick_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_completed = false;
    }
  }

  explicit Pick_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_completed = false;
    }
  }

  // field types and members
  using _is_completed_type =
    bool;
  _is_completed_type is_completed;

  // setters for named parameter idiom
  Type & set__is_completed(
    const bool & _arg)
  {
    this->is_completed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::srv::Pick_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::srv::Pick_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::srv::Pick_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::srv::Pick_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__srv__Pick_Response
    std::shared_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__srv__Pick_Response
    std::shared_ptr<fairino_interfaces::srv::Pick_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pick_Response_ & other) const
  {
    if (this->is_completed != other.is_completed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pick_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pick_Response_

// alias to use template instance with default allocator
using Pick_Response =
  fairino_interfaces::srv::Pick_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fairino_interfaces

namespace fairino_interfaces
{

namespace srv
{

struct Pick
{
  using Request = fairino_interfaces::srv::Pick_Request;
  using Response = fairino_interfaces::srv::Pick_Response;
};

}  // namespace srv

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_HPP_
