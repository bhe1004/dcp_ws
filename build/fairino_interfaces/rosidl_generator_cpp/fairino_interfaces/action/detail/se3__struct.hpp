// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fairino_interfaces:action/SE3.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_HPP_

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
# define DEPRECATED__fairino_interfaces__action__SE3_Goal __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_Goal __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_Goal_
{
  using Type = SE3_Goal_<ContainerAllocator>;

  explicit SE3_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0f;
      this->relative = false;
      this->wholebody = false;
      this->client_id = "";
    }
  }

  explicit SE3_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_alloc, _init),
    client_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0f;
      this->relative = false;
      this->wholebody = false;
      this->client_id = "";
    }
  }

  // field types and members
  using _target_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_pose_type target_pose;
  using _duration_type =
    float;
  _duration_type duration;
  using _relative_type =
    bool;
  _relative_type relative;
  using _wholebody_type =
    bool;
  _wholebody_type wholebody;
  using _client_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _client_id_type client_id;

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
  Type & set__relative(
    const bool & _arg)
  {
    this->relative = _arg;
    return *this;
  }
  Type & set__wholebody(
    const bool & _arg)
  {
    this->wholebody = _arg;
    return *this;
  }
  Type & set__client_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->client_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::SE3_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_Goal
    std::shared_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_Goal
    std::shared_ptr<fairino_interfaces::action::SE3_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_Goal_ & other) const
  {
    if (this->target_pose != other.target_pose) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->relative != other.relative) {
      return false;
    }
    if (this->wholebody != other.wholebody) {
      return false;
    }
    if (this->client_id != other.client_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_Goal_

// alias to use template instance with default allocator
using SE3_Goal =
  fairino_interfaces::action::SE3_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_Result __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_Result __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_Result_
{
  using Type = SE3_Result_<ContainerAllocator>;

  explicit SE3_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_completed = false;
    }
  }

  explicit SE3_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_Result
    std::shared_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_Result
    std::shared_ptr<fairino_interfaces::action::SE3_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_Result_ & other) const
  {
    if (this->is_completed != other.is_completed) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_Result_

// alias to use template instance with default allocator
using SE3_Result =
  fairino_interfaces::action::SE3_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_Feedback __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_Feedback_
{
  using Type = SE3_Feedback_<ContainerAllocator>;

  explicit SE3_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percent_complete = 0.0f;
    }
  }

  explicit SE3_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_Feedback
    std::shared_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_Feedback
    std::shared_ptr<fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_Feedback_ & other) const
  {
    if (this->percent_complete != other.percent_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_Feedback_

// alias to use template instance with default allocator
using SE3_Feedback =
  fairino_interfaces::action::SE3_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "fairino_interfaces/action/detail/se3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Request __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_SendGoal_Request_
{
  using Type = SE3_SendGoal_Request_<ContainerAllocator>;

  explicit SE3_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit SE3_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const fairino_interfaces::action::SE3_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Request
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Request
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_SendGoal_Request_

// alias to use template instance with default allocator
using SE3_SendGoal_Request =
  fairino_interfaces::action::SE3_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Response __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_SendGoal_Response_
{
  using Type = SE3_SendGoal_Response_<ContainerAllocator>;

  explicit SE3_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit SE3_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Response
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_SendGoal_Response
    std::shared_ptr<fairino_interfaces::action::SE3_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_SendGoal_Response_

// alias to use template instance with default allocator
using SE3_SendGoal_Response =
  fairino_interfaces::action::SE3_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces

namespace fairino_interfaces
{

namespace action
{

struct SE3_SendGoal
{
  using Request = fairino_interfaces::action::SE3_SendGoal_Request;
  using Response = fairino_interfaces::action::SE3_SendGoal_Response;
};

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_GetResult_Request __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_GetResult_Request_
{
  using Type = SE3_GetResult_Request_<ContainerAllocator>;

  explicit SE3_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit SE3_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_GetResult_Request
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_GetResult_Request
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_GetResult_Request_

// alias to use template instance with default allocator
using SE3_GetResult_Request =
  fairino_interfaces::action::SE3_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "fairino_interfaces/action/detail/se3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_GetResult_Response __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_GetResult_Response_
{
  using Type = SE3_GetResult_Response_<ContainerAllocator>;

  explicit SE3_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit SE3_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const fairino_interfaces::action::SE3_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_GetResult_Response
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_GetResult_Response
    std::shared_ptr<fairino_interfaces::action::SE3_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_GetResult_Response_

// alias to use template instance with default allocator
using SE3_GetResult_Response =
  fairino_interfaces::action::SE3_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace fairino_interfaces

namespace fairino_interfaces
{

namespace action
{

struct SE3_GetResult
{
  using Request = fairino_interfaces::action::SE3_GetResult_Request;
  using Response = fairino_interfaces::action::SE3_GetResult_Response;
};

}  // namespace action

}  // namespace fairino_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "fairino_interfaces/action/detail/se3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fairino_interfaces__action__SE3_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__fairino_interfaces__action__SE3_FeedbackMessage __declspec(deprecated)
#endif

namespace fairino_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SE3_FeedbackMessage_
{
  using Type = SE3_FeedbackMessage_<ContainerAllocator>;

  explicit SE3_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit SE3_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    fairino_interfaces::action::SE3_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const fairino_interfaces::action::SE3_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fairino_interfaces__action__SE3_FeedbackMessage
    std::shared_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fairino_interfaces__action__SE3_FeedbackMessage
    std::shared_ptr<fairino_interfaces::action::SE3_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SE3_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const SE3_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SE3_FeedbackMessage_

// alias to use template instance with default allocator
using SE3_FeedbackMessage =
  fairino_interfaces::action::SE3_FeedbackMessage_<std::allocator<void>>;

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

struct SE3
{
  /// The goal message defined in the action definition.
  using Goal = fairino_interfaces::action::SE3_Goal;
  /// The result message defined in the action definition.
  using Result = fairino_interfaces::action::SE3_Result;
  /// The feedback message defined in the action definition.
  using Feedback = fairino_interfaces::action::SE3_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = fairino_interfaces::action::SE3_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = fairino_interfaces::action::SE3_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = fairino_interfaces::action::SE3_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct SE3 SE3;

}  // namespace action

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_HPP_
