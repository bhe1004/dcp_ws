// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fairino_interfaces:action/SE3.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__SE3__BUILDER_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__SE3__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fairino_interfaces/action/detail/se3__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_Goal_client_id
{
public:
  explicit Init_SE3_Goal_client_id(::fairino_interfaces::action::SE3_Goal & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::SE3_Goal client_id(::fairino_interfaces::action::SE3_Goal::_client_id_type arg)
  {
    msg_.client_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Goal msg_;
};

class Init_SE3_Goal_wholebody
{
public:
  explicit Init_SE3_Goal_wholebody(::fairino_interfaces::action::SE3_Goal & msg)
  : msg_(msg)
  {}
  Init_SE3_Goal_client_id wholebody(::fairino_interfaces::action::SE3_Goal::_wholebody_type arg)
  {
    msg_.wholebody = std::move(arg);
    return Init_SE3_Goal_client_id(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Goal msg_;
};

class Init_SE3_Goal_relative
{
public:
  explicit Init_SE3_Goal_relative(::fairino_interfaces::action::SE3_Goal & msg)
  : msg_(msg)
  {}
  Init_SE3_Goal_wholebody relative(::fairino_interfaces::action::SE3_Goal::_relative_type arg)
  {
    msg_.relative = std::move(arg);
    return Init_SE3_Goal_wholebody(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Goal msg_;
};

class Init_SE3_Goal_duration
{
public:
  explicit Init_SE3_Goal_duration(::fairino_interfaces::action::SE3_Goal & msg)
  : msg_(msg)
  {}
  Init_SE3_Goal_relative duration(::fairino_interfaces::action::SE3_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_SE3_Goal_relative(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Goal msg_;
};

class Init_SE3_Goal_target_pose
{
public:
  Init_SE3_Goal_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SE3_Goal_duration target_pose(::fairino_interfaces::action::SE3_Goal::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_SE3_Goal_duration(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_Goal>()
{
  return fairino_interfaces::action::builder::Init_SE3_Goal_target_pose();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_Result_is_completed
{
public:
  Init_SE3_Result_is_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::SE3_Result is_completed(::fairino_interfaces::action::SE3_Result::_is_completed_type arg)
  {
    msg_.is_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_Result>()
{
  return fairino_interfaces::action::builder::Init_SE3_Result_is_completed();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_Feedback_percent_complete
{
public:
  Init_SE3_Feedback_percent_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::SE3_Feedback percent_complete(::fairino_interfaces::action::SE3_Feedback::_percent_complete_type arg)
  {
    msg_.percent_complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_Feedback>()
{
  return fairino_interfaces::action::builder::Init_SE3_Feedback_percent_complete();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_SendGoal_Request_goal
{
public:
  explicit Init_SE3_SendGoal_Request_goal(::fairino_interfaces::action::SE3_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::SE3_SendGoal_Request goal(::fairino_interfaces::action::SE3_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_SendGoal_Request msg_;
};

class Init_SE3_SendGoal_Request_goal_id
{
public:
  Init_SE3_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SE3_SendGoal_Request_goal goal_id(::fairino_interfaces::action::SE3_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SE3_SendGoal_Request_goal(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_SendGoal_Request>()
{
  return fairino_interfaces::action::builder::Init_SE3_SendGoal_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_SendGoal_Response_stamp
{
public:
  explicit Init_SE3_SendGoal_Response_stamp(::fairino_interfaces::action::SE3_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::SE3_SendGoal_Response stamp(::fairino_interfaces::action::SE3_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_SendGoal_Response msg_;
};

class Init_SE3_SendGoal_Response_accepted
{
public:
  Init_SE3_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SE3_SendGoal_Response_stamp accepted(::fairino_interfaces::action::SE3_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SE3_SendGoal_Response_stamp(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_SendGoal_Response>()
{
  return fairino_interfaces::action::builder::Init_SE3_SendGoal_Response_accepted();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_GetResult_Request_goal_id
{
public:
  Init_SE3_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::SE3_GetResult_Request goal_id(::fairino_interfaces::action::SE3_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_GetResult_Request>()
{
  return fairino_interfaces::action::builder::Init_SE3_GetResult_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_GetResult_Response_result
{
public:
  explicit Init_SE3_GetResult_Response_result(::fairino_interfaces::action::SE3_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::SE3_GetResult_Response result(::fairino_interfaces::action::SE3_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_GetResult_Response msg_;
};

class Init_SE3_GetResult_Response_status
{
public:
  Init_SE3_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SE3_GetResult_Response_result status(::fairino_interfaces::action::SE3_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SE3_GetResult_Response_result(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_GetResult_Response>()
{
  return fairino_interfaces::action::builder::Init_SE3_GetResult_Response_status();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_SE3_FeedbackMessage_feedback
{
public:
  explicit Init_SE3_FeedbackMessage_feedback(::fairino_interfaces::action::SE3_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::SE3_FeedbackMessage feedback(::fairino_interfaces::action::SE3_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_FeedbackMessage msg_;
};

class Init_SE3_FeedbackMessage_goal_id
{
public:
  Init_SE3_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SE3_FeedbackMessage_feedback goal_id(::fairino_interfaces::action::SE3_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SE3_FeedbackMessage_feedback(msg_);
  }

private:
  ::fairino_interfaces::action::SE3_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::SE3_FeedbackMessage>()
{
  return fairino_interfaces::action::builder::Init_SE3_FeedbackMessage_goal_id();
}

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__SE3__BUILDER_HPP_
