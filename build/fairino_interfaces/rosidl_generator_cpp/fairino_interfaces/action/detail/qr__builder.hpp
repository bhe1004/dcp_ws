// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fairino_interfaces:action/QR.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__QR__BUILDER_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__QR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fairino_interfaces/action/detail/qr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_Goal_duration
{
public:
  explicit Init_QR_Goal_duration(::fairino_interfaces::action::QR_Goal & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::QR_Goal duration(::fairino_interfaces::action::QR_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_Goal msg_;
};

class Init_QR_Goal_target_pose
{
public:
  explicit Init_QR_Goal_target_pose(::fairino_interfaces::action::QR_Goal & msg)
  : msg_(msg)
  {}
  Init_QR_Goal_duration target_pose(::fairino_interfaces::action::QR_Goal::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_QR_Goal_duration(msg_);
  }

private:
  ::fairino_interfaces::action::QR_Goal msg_;
};

class Init_QR_Goal_qr_pose
{
public:
  Init_QR_Goal_qr_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QR_Goal_target_pose qr_pose(::fairino_interfaces::action::QR_Goal::_qr_pose_type arg)
  {
    msg_.qr_pose = std::move(arg);
    return Init_QR_Goal_target_pose(msg_);
  }

private:
  ::fairino_interfaces::action::QR_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_Goal>()
{
  return fairino_interfaces::action::builder::Init_QR_Goal_qr_pose();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_Result_is_completed
{
public:
  Init_QR_Result_is_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::QR_Result is_completed(::fairino_interfaces::action::QR_Result::_is_completed_type arg)
  {
    msg_.is_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_Result>()
{
  return fairino_interfaces::action::builder::Init_QR_Result_is_completed();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_Feedback_percent_complete
{
public:
  Init_QR_Feedback_percent_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::QR_Feedback percent_complete(::fairino_interfaces::action::QR_Feedback::_percent_complete_type arg)
  {
    msg_.percent_complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_Feedback>()
{
  return fairino_interfaces::action::builder::Init_QR_Feedback_percent_complete();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_SendGoal_Request_goal
{
public:
  explicit Init_QR_SendGoal_Request_goal(::fairino_interfaces::action::QR_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::QR_SendGoal_Request goal(::fairino_interfaces::action::QR_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_SendGoal_Request msg_;
};

class Init_QR_SendGoal_Request_goal_id
{
public:
  Init_QR_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QR_SendGoal_Request_goal goal_id(::fairino_interfaces::action::QR_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_QR_SendGoal_Request_goal(msg_);
  }

private:
  ::fairino_interfaces::action::QR_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_SendGoal_Request>()
{
  return fairino_interfaces::action::builder::Init_QR_SendGoal_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_SendGoal_Response_stamp
{
public:
  explicit Init_QR_SendGoal_Response_stamp(::fairino_interfaces::action::QR_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::QR_SendGoal_Response stamp(::fairino_interfaces::action::QR_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_SendGoal_Response msg_;
};

class Init_QR_SendGoal_Response_accepted
{
public:
  Init_QR_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QR_SendGoal_Response_stamp accepted(::fairino_interfaces::action::QR_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_QR_SendGoal_Response_stamp(msg_);
  }

private:
  ::fairino_interfaces::action::QR_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_SendGoal_Response>()
{
  return fairino_interfaces::action::builder::Init_QR_SendGoal_Response_accepted();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_GetResult_Request_goal_id
{
public:
  Init_QR_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::QR_GetResult_Request goal_id(::fairino_interfaces::action::QR_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_GetResult_Request>()
{
  return fairino_interfaces::action::builder::Init_QR_GetResult_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_GetResult_Response_result
{
public:
  explicit Init_QR_GetResult_Response_result(::fairino_interfaces::action::QR_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::QR_GetResult_Response result(::fairino_interfaces::action::QR_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_GetResult_Response msg_;
};

class Init_QR_GetResult_Response_status
{
public:
  Init_QR_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QR_GetResult_Response_result status(::fairino_interfaces::action::QR_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_QR_GetResult_Response_result(msg_);
  }

private:
  ::fairino_interfaces::action::QR_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_GetResult_Response>()
{
  return fairino_interfaces::action::builder::Init_QR_GetResult_Response_status();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_QR_FeedbackMessage_feedback
{
public:
  explicit Init_QR_FeedbackMessage_feedback(::fairino_interfaces::action::QR_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::QR_FeedbackMessage feedback(::fairino_interfaces::action::QR_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::QR_FeedbackMessage msg_;
};

class Init_QR_FeedbackMessage_goal_id
{
public:
  Init_QR_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QR_FeedbackMessage_feedback goal_id(::fairino_interfaces::action::QR_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_QR_FeedbackMessage_feedback(msg_);
  }

private:
  ::fairino_interfaces::action::QR_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::QR_FeedbackMessage>()
{
  return fairino_interfaces::action::builder::Init_QR_FeedbackMessage_goal_id();
}

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__QR__BUILDER_HPP_
