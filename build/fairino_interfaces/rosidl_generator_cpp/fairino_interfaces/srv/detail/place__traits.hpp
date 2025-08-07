// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fairino_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
#define FAIRINO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fairino_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace fairino_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: client_id
  {
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << ", ";
  }

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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: client_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "client_id: ";
    rosidl_generator_traits::value_to_yaml(msg.client_id, out);
    out << "\n";
  }

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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Place_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::srv::Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::srv::Place_Request & msg)
{
  return fairino_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::srv::Place_Request>()
{
  return "fairino_interfaces::srv::Place_Request";
}

template<>
inline const char * name<fairino_interfaces::srv::Place_Request>()
{
  return "fairino_interfaces/srv/Place_Request";
}

template<>
struct has_fixed_size<fairino_interfaces::srv::Place_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fairino_interfaces::srv::Place_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fairino_interfaces::srv::Place_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace fairino_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Response & msg,
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
  const Place_Response & msg,
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

inline std::string to_yaml(const Place_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fairino_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fairino_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fairino_interfaces::srv::Place_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fairino_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fairino_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fairino_interfaces::srv::Place_Response & msg)
{
  return fairino_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fairino_interfaces::srv::Place_Response>()
{
  return "fairino_interfaces::srv::Place_Response";
}

template<>
inline const char * name<fairino_interfaces::srv::Place_Response>()
{
  return "fairino_interfaces/srv/Place_Response";
}

template<>
struct has_fixed_size<fairino_interfaces::srv::Place_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fairino_interfaces::srv::Place_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fairino_interfaces::srv::Place_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fairino_interfaces::srv::Place>()
{
  return "fairino_interfaces::srv::Place";
}

template<>
inline const char * name<fairino_interfaces::srv::Place>()
{
  return "fairino_interfaces/srv/Place";
}

template<>
struct has_fixed_size<fairino_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_fixed_size<fairino_interfaces::srv::Place_Request>::value &&
    has_fixed_size<fairino_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct has_bounded_size<fairino_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_bounded_size<fairino_interfaces::srv::Place_Request>::value &&
    has_bounded_size<fairino_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct is_service<fairino_interfaces::srv::Place>
  : std::true_type
{
};

template<>
struct is_service_request<fairino_interfaces::srv::Place_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fairino_interfaces::srv::Place_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FAIRINO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
