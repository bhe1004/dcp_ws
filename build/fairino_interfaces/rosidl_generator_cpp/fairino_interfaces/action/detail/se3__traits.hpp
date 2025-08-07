// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fairino_interfaces:action/SE3.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__SE3__TRAITS_HPP_
#define FAIRINO_INTERFACES__ACTION__DETAIL__SE3__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fairino_interfaces/action/detail/se3__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_pose
  {
    out << "target_pose: ";
    to_flow_style_yaml(msg.target_pose, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << ", ";
  }

  // member: relative
  {
    out << "relative: ";
    rosidl_generator_traits::value_to_yaml(msg.relative, out);
    out << ", ";
  }

  // member: wholebody
  {
    out << "wholebody: ";
    rosidl_generator_traits::value_to_yaml(msg.wholebody, out);
    out << ", ";
  }

  // member: client_id
  {
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_pose:\n";
    to_block_style_yaml(msg.target_pose, out, indentation + 2);
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }

  // member: relative
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative: ";
    rosidl_generator_traits::value_to_yaml(msg.relative, out);
    out << "\n";
  }

  // member: wholebody
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wholebody: ";
    rosidl_generator_traits::value_to_yaml(msg.wholebody, out);
    out << "\n";
  }

  // member: client_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_Goal & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_Goal>()
{
  return "fairino_interfaces::action::SE3_Goal";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_Goal>()
{
  return "fairino_interfaces/action/SE3_Goal";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fairino_interfaces::action::SE3_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_completed
  {
    out << "is_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_completed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_completed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_Result & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_Result>()
{
  return "fairino_interfaces::action::SE3_Result";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_Result>()
{
  return "fairino_interfaces/action/SE3_Result";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fairino_interfaces::action::SE3_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: percent_complete
  {
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: percent_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_Feedback & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_Feedback>()
{
  return "fairino_interfaces::action::SE3_Feedback";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_Feedback>()
{
  return "fairino_interfaces/action/SE3_Feedback";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fairino_interfaces::action::SE3_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "fairino_interfaces/action/detail/se3__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_SendGoal_Request & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_SendGoal_Request>()
{
  return "fairino_interfaces::action::SE3_SendGoal_Request";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_SendGoal_Request>()
{
  return "fairino_interfaces/action/SE3_SendGoal_Request";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<fairino_interfaces::action::SE3_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<fairino_interfaces::action::SE3_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fairino_interfaces::action::SE3_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_SendGoal_Response & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_SendGoal_Response>()
{
  return "fairino_interfaces::action::SE3_SendGoal_Response";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_SendGoal_Response>()
{
  return "fairino_interfaces/action/SE3_SendGoal_Response";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<fairino_interfaces::action::SE3_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fairino_interfaces::action::SE3_SendGoal>()
{
  return "fairino_interfaces::action::SE3_SendGoal";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_SendGoal>()
{
  return "fairino_interfaces/action/SE3_SendGoal";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<fairino_interfaces::action::SE3_SendGoal_Request>::value &&
    has_fixed_size<fairino_interfaces::action::SE3_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<fairino_interfaces::action::SE3_SendGoal_Request>::value &&
    has_bounded_size<fairino_interfaces::action::SE3_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<fairino_interfaces::action::SE3_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<fairino_interfaces::action::SE3_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fairino_interfaces::action::SE3_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_GetResult_Request & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_GetResult_Request>()
{
  return "fairino_interfaces::action::SE3_GetResult_Request";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_GetResult_Request>()
{
  return "fairino_interfaces/action/SE3_GetResult_Request";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fairino_interfaces::action::SE3_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "fairino_interfaces/action/detail/se3__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_GetResult_Response & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_GetResult_Response>()
{
  return "fairino_interfaces::action::SE3_GetResult_Response";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_GetResult_Response>()
{
  return "fairino_interfaces/action/SE3_GetResult_Response";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<fairino_interfaces::action::SE3_Result>::value> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<fairino_interfaces::action::SE3_Result>::value> {};

template<>
struct is_message<fairino_interfaces::action::SE3_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fairino_interfaces::action::SE3_GetResult>()
{
  return "fairino_interfaces::action::SE3_GetResult";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_GetResult>()
{
  return "fairino_interfaces/action/SE3_GetResult";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<fairino_interfaces::action::SE3_GetResult_Request>::value &&
    has_fixed_size<fairino_interfaces::action::SE3_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<fairino_interfaces::action::SE3_GetResult_Request>::value &&
    has_bounded_size<fairino_interfaces::action::SE3_GetResult_Response>::value
  >
{
};

template<>
struct is_service<fairino_interfaces::action::SE3_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<fairino_interfaces::action::SE3_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fairino_interfaces::action::SE3_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "fairino_interfaces/action/detail/se3__traits.hpp"

namespace fairino_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const SE3_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SE3_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SE3_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::action::SE3_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::action::SE3_FeedbackMessage & msg)
{
  return fairino_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::action::SE3_FeedbackMessage>()
{
  return "fairino_interfaces::action::SE3_FeedbackMessage";
}

template<>
inline const char * name<fairino_interfaces::action::SE3_FeedbackMessage>()
{
  return "fairino_interfaces/action/SE3_FeedbackMessage";
}

template<>
struct has_fixed_size<fairino_interfaces::action::SE3_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<fairino_interfaces::action::SE3_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<fairino_interfaces::action::SE3_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<fairino_interfaces::action::SE3_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<fairino_interfaces::action::SE3_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<fairino_interfaces::action::SE3>
  : std::true_type
{
};

template<>
struct is_action_goal<fairino_interfaces::action::SE3_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<fairino_interfaces::action::SE3_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<fairino_interfaces::action::SE3_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__SE3__TRAITS_HPP_
