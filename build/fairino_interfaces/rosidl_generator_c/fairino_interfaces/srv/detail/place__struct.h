// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fairino_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_
#define FAIRINO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'client_id'
#include "rosidl_runtime_c/string.h"
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/Place in the package fairino_interfaces.
typedef struct fairino_interfaces__srv__Place_Request
{
  rosidl_runtime_c__String client_id;
  geometry_msgs__msg__Pose target_pose;
  float duration;
} fairino_interfaces__srv__Place_Request;

// Struct for a sequence of fairino_interfaces__srv__Place_Request.
typedef struct fairino_interfaces__srv__Place_Request__Sequence
{
  fairino_interfaces__srv__Place_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__srv__Place_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Place in the package fairino_interfaces.
typedef struct fairino_interfaces__srv__Place_Response
{
  bool is_completed;
} fairino_interfaces__srv__Place_Response;

// Struct for a sequence of fairino_interfaces__srv__Place_Response.
typedef struct fairino_interfaces__srv__Place_Response__Sequence
{
  fairino_interfaces__srv__Place_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__srv__Place_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FAIRINO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_
