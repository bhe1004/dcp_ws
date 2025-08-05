// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fairino_interfaces:action/Gripper.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__GRIPPER__STRUCT_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__GRIPPER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_Goal __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_Goal __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_Goal_
{
  using Type = Gripper_Goal_<ContainerAllocator>;

  explicit Gripper_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grasp = false;
      this->position_percentage = 0;
      this->speed_percentage = 0;
      this->torque_percentage = 0;
    }
  }

  explicit Gripper_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grasp = false;
      this->position_percentage = 0;
      this->speed_percentage = 0;
      this->torque_percentage = 0;
    }
  }

  // field types and members
  using _grasp_type =
    bool;
  _grasp_type grasp;
  using _position_percentage_type =
    uint8_t;
  _position_percentage_type position_percentage;
  using _speed_percentage_type =
    uint8_t;
  _speed_percentage_type speed_percentage;
  using _torque_percentage_type =
    uint8_t;
  _torque_percentage_type torque_percentage;

  // setters for named parameter idiom
  Type & set__grasp(
    const bool & _arg)
  {
    this->grasp = _arg;
    return *this;
  }
  Type & set__position_percentage(
    const uint8_t & _arg)
  {
    this->position_percentage = _arg;
    return *this;
  }
  Type & set__speed_percentage(
    const uint8_t & _arg)
  {
    this->speed_percentage = _arg;
    return *this;
  }
  Type & set__torque_percentage(
    const uint8_t & _arg)
  {
    this->torque_percentage = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Goal
    std::shared_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Goal
    std::shared_ptr<fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_Goal_ & other) const
  {
    if (this->grasp != other.grasp) {
      return false;
    }
    if (this->position_percentage != other.position_percentage) {
      return false;
    }
    if (this->speed_percentage != other.speed_percentage) {
      return false;
    }
    if (this->torque_percentage != other.torque_percentage) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_Goal_

// alias to use template instance with default allocator
using Gripper_Goal =
  fairino_interfaces::action::Gripper_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_Result __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_Result __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_Result_
{
  using Type = Gripper_Result_<ContainerAllocator>;

  explicit Gripper_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_completed = false;
    }
  }

  explicit Gripper_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::Gripper_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Result
    std::shared_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Result
    std::shared_ptr<fairino_interfaces::action::Gripper_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_Result_ & other) const
  {
    if (this->is_completed != other.is_completed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_Result_

// alias to use template instance with default allocator
using Gripper_Result =
  fairino_interfaces::action::Gripper_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_Feedback __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_Feedback_
{
  using Type = Gripper_Feedback_<ContainerAllocator>;

  explicit Gripper_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percent_complete = 0.0f;
    }
  }

  explicit Gripper_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percent_complete = 0.0f;
    }
  }

  // field types and members
  using _percent_complete_type =
    float;
  _percent_complete_type percent_complete;

  // setters for named parameter idiom
  Type & set__percent_complete(
    const float & _arg)
  {
    this->percent_complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Feedback
    std::shared_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_Feedback
    std::shared_ptr<fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_Feedback_ & other) const
  {
    if (this->percent_complete != other.percent_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_Feedback_

// alias to use template instance with default allocator
using Gripper_Feedback =
  fairino_interfaces::action::Gripper_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "fairino_interfaces/action/detail/gripper__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Request __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_SendGoal_Request_
{
  using Type = Gripper_SendGoal_Request_<ContainerAllocator>;

  explicit Gripper_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Gripper_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    fairino_interfaces::action::Gripper_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const fairino_interfaces::action::Gripper_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Request
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Request
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_SendGoal_Request_

// alias to use template instance with default allocator
using Gripper_SendGoal_Request =
  fairino_interfaces::action::Gripper_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Response __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_SendGoal_Response_
{
  using Type = Gripper_SendGoal_Response_<ContainerAllocator>;

  explicit Gripper_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Gripper_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Response
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_SendGoal_Response
    std::shared_ptr<fairino_interfaces::action::Gripper_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_SendGoal_Response_

// alias to use template instance with default allocator
using Gripper_SendGoal_Response =
  fairino_interfaces::action::Gripper_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces

namespace fairino_interfaces
{

namespace action
{

struct Gripper_SendGoal
{
  using Request = fairino_interfaces::action::Gripper_SendGoal_Request;
  using Response = fairino_interfaces::action::Gripper_SendGoal_Response;
};

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Request __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_GetResult_Request_
{
  using Type = Gripper_GetResult_Request_<ContainerAllocator>;

  explicit Gripper_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Gripper_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Request
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Request
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_GetResult_Request_

// alias to use template instance with default allocator
using Gripper_GetResult_Request =
  fairino_interfaces::action::Gripper_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "fairino_interfaces/action/detail/gripper__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Response __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_GetResult_Response_
{
  using Type = Gripper_GetResult_Response_<ContainerAllocator>;

  explicit Gripper_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Gripper_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    fairino_interfaces::action::Gripper_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const fairino_interfaces::action::Gripper_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Response
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_GetResult_Response
    std::shared_ptr<fairino_interfaces::action::Gripper_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_GetResult_Response_

// alias to use template instance with default allocator
using Gripper_GetResult_Response =
  fairino_interfaces::action::Gripper_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces

namespace fairino_interfaces
{

namespace action
{

struct Gripper_GetResult
{
  using Request = fairino_interfaces::action::Gripper_GetResult_Request;
  using Response = fairino_interfaces::action::Gripper_GetResult_Response;
};

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "fairino_interfaces/action/detail/gripper__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__Gripper_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__Gripper_FeedbackMessage __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Gripper_FeedbackMessage_
{
  using Type = Gripper_FeedbackMessage_<ContainerAllocator>;

  explicit Gripper_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Gripper_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const fairino_interfaces::action::Gripper_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__Gripper_FeedbackMessage
    std::shared_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__Gripper_FeedbackMessage
    std::shared_ptr<fairino_interfaces::action::Gripper_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gripper_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gripper_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gripper_FeedbackMessage_

// alias to use template instance with default allocator
using Gripper_FeedbackMessage =
  fairino_interfaces::action::Gripper_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace fairino_interfaces
{

namespace action
{

struct Gripper
{
  /// The goal message defined in the action definition.
  using Goal = fairino_interfaces::action::Gripper_Goal;
  /// The result message defined in the action definition.
  using Result = fairino_interfaces::action::Gripper_Result;
  /// The feedback message defined in the action definition.
  using Feedback = fairino_interfaces::action::Gripper_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = fairino_interfaces::action::Gripper_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = fairino_interfaces::action::Gripper_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = fairino_interfaces::action::Gripper_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Gripper Gripper;

}  // namespace action

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__GRIPPER__STRUCT_HPP_
