// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fairino_interfaces:action/ToolChanger.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__TOOL_CHANGER__BUILDER_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__TOOL_CHANGER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fairino_interfaces/action/detail/tool_changer__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_Goal_duration
{
public:
  explicit Init_ToolChanger_Goal_duration(::fairino_interfaces::action::ToolChanger_Goal & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_Goal duration(::fairino_interfaces::action::ToolChanger_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Goal msg_;
};

class Init_ToolChanger_Goal_tool_id
{
public:
  explicit Init_ToolChanger_Goal_tool_id(::fairino_interfaces::action::ToolChanger_Goal & msg)
  : msg_(msg)
  {}
  Init_ToolChanger_Goal_duration tool_id(::fairino_interfaces::action::ToolChanger_Goal::_tool_id_type arg)
  {
    msg_.tool_id = std::move(arg);
    return Init_ToolChanger_Goal_duration(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Goal msg_;
};

class Init_ToolChanger_Goal_grip
{
public:
  Init_ToolChanger_Goal_grip()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_Goal_tool_id grip(::fairino_interfaces::action::ToolChanger_Goal::_grip_type arg)
  {
    msg_.grip = std::move(arg);
    return Init_ToolChanger_Goal_tool_id(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_Goal>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_Goal_grip();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_Result_tool_change_completed
{
public:
  explicit Init_ToolChanger_Result_tool_change_completed(::fairino_interfaces::action::ToolChanger_Result & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_Result tool_change_completed(::fairino_interfaces::action::ToolChanger_Result::_tool_change_completed_type arg)
  {
    msg_.tool_change_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Result msg_;
};

class Init_ToolChanger_Result_reach_completed
{
public:
  Init_ToolChanger_Result_reach_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_Result_tool_change_completed reach_completed(::fairino_interfaces::action::ToolChanger_Result::_reach_completed_type arg)
  {
    msg_.reach_completed = std::move(arg);
    return Init_ToolChanger_Result_tool_change_completed(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_Result>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_Result_reach_completed();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_Feedback_percent_complete
{
public:
  Init_ToolChanger_Feedback_percent_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::ToolChanger_Feedback percent_complete(::fairino_interfaces::action::ToolChanger_Feedback::_percent_complete_type arg)
  {
    msg_.percent_complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_Feedback>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_Feedback_percent_complete();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_SendGoal_Request_goal
{
public:
  explicit Init_ToolChanger_SendGoal_Request_goal(::fairino_interfaces::action::ToolChanger_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_SendGoal_Request goal(::fairino_interfaces::action::ToolChanger_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_SendGoal_Request msg_;
};

class Init_ToolChanger_SendGoal_Request_goal_id
{
public:
  Init_ToolChanger_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_SendGoal_Request_goal goal_id(::fairino_interfaces::action::ToolChanger_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ToolChanger_SendGoal_Request_goal(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_SendGoal_Request>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_SendGoal_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_SendGoal_Response_stamp
{
public:
  explicit Init_ToolChanger_SendGoal_Response_stamp(::fairino_interfaces::action::ToolChanger_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_SendGoal_Response stamp(::fairino_interfaces::action::ToolChanger_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_SendGoal_Response msg_;
};

class Init_ToolChanger_SendGoal_Response_accepted
{
public:
  Init_ToolChanger_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_SendGoal_Response_stamp accepted(::fairino_interfaces::action::ToolChanger_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ToolChanger_SendGoal_Response_stamp(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_SendGoal_Response>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_SendGoal_Response_accepted();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_GetResult_Request_goal_id
{
public:
  Init_ToolChanger_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fairino_interfaces::action::ToolChanger_GetResult_Request goal_id(::fairino_interfaces::action::ToolChanger_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_GetResult_Request>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_GetResult_Request_goal_id();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_GetResult_Response_result
{
public:
  explicit Init_ToolChanger_GetResult_Response_result(::fairino_interfaces::action::ToolChanger_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_GetResult_Response result(::fairino_interfaces::action::ToolChanger_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_GetResult_Response msg_;
};

class Init_ToolChanger_GetResult_Response_status
{
public:
  Init_ToolChanger_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_GetResult_Response_result status(::fairino_interfaces::action::ToolChanger_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ToolChanger_GetResult_Response_result(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_GetResult_Response>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_GetResult_Response_status();
}

}  // namespace fairino_interfaces


namespace fairino_interfaces
{

namespace action
{

namespace builder
{

class Init_ToolChanger_FeedbackMessage_feedback
{
public:
  explicit Init_ToolChanger_FeedbackMessage_feedback(::fairino_interfaces::action::ToolChanger_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::fairino_interfaces::action::ToolChanger_FeedbackMessage feedback(::fairino_interfaces::action::ToolChanger_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_FeedbackMessage msg_;
};

class Init_ToolChanger_FeedbackMessage_goal_id
{
public:
  Init_ToolChanger_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolChanger_FeedbackMessage_feedback goal_id(::fairino_interfaces::action::ToolChanger_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ToolChanger_FeedbackMessage_feedback(msg_);
  }

private:
  ::fairino_interfaces::action::ToolChanger_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::fairino_interfaces::action::ToolChanger_FeedbackMessage>()
{
  return fairino_interfaces::action::builder::Init_ToolChanger_FeedbackMessage_goal_id();
}

}  // namespace fairino_interfaces

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__TOOL_CHANGER__BUILDER_HPP_
