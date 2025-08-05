// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fairino_interfaces:srv/Pick.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_H_
#define FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/Pick in the package fairino_interfaces.
typedef struct fairino_interfaces__srv__Pick_Request
{
  geometry_msgs__msg__Pose target_pose;
  float duration;
} fairino_interfaces__srv__Pick_Request;

// Struct for a sequence of fairino_interfaces__srv__Pick_Request.
typedef struct fairino_interfaces__srv__Pick_Request__Sequence
{
  fairino_interfaces__srv__Pick_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__srv__Pick_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Pick in the package fairino_interfaces.
typedef struct fairino_interfaces__srv__Pick_Response
{
  bool is_completed;
} fairino_interfaces__srv__Pick_Response;

// Struct for a sequence of fairino_interfaces__srv__Pick_Response.
typedef struct fairino_interfaces__srv__Pick_Response__Sequence
{
  fairino_interfaces__srv__Pick_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__srv__Pick_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FAIRINO_INTERFACES__SRV__DETAIL__PICK__STRUCT_H_
