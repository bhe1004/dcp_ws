// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fairino_interfaces:action/SE3.idl
// generated code does not contain a copyright notice

#ifndef FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_H_
#define FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_H_

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

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_Goal
{
  geometry_msgs__msg__Pose target_pose;
  float duration;
  bool relative;
  bool wholebody;
} fairino_interfaces__action__SE3_Goal;

// Struct for a sequence of fairino_interfaces__action__SE3_Goal.
typedef struct fairino_interfaces__action__SE3_Goal__Sequence
{
  fairino_interfaces__action__SE3_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_Result
{
  bool is_completed;
} fairino_interfaces__action__SE3_Result;

// Struct for a sequence of fairino_interfaces__action__SE3_Result.
typedef struct fairino_interfaces__action__SE3_Result__Sequence
{
  fairino_interfaces__action__SE3_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_Feedback
{
  float percent_complete;
} fairino_interfaces__action__SE3_Feedback;

// Struct for a sequence of fairino_interfaces__action__SE3_Feedback.
typedef struct fairino_interfaces__action__SE3_Feedback__Sequence
{
  fairino_interfaces__action__SE3_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "fairino_interfaces/action/detail/se3__struct.h"

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  fairino_interfaces__action__SE3_Goal goal;
} fairino_interfaces__action__SE3_SendGoal_Request;

// Struct for a sequence of fairino_interfaces__action__SE3_SendGoal_Request.
typedef struct fairino_interfaces__action__SE3_SendGoal_Request__Sequence
{
  fairino_interfaces__action__SE3_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} fairino_interfaces__action__SE3_SendGoal_Response;

// Struct for a sequence of fairino_interfaces__action__SE3_SendGoal_Response.
typedef struct fairino_interfaces__action__SE3_SendGoal_Response__Sequence
{
  fairino_interfaces__action__SE3_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} fairino_interfaces__action__SE3_GetResult_Request;

// Struct for a sequence of fairino_interfaces__action__SE3_GetResult_Request.
typedef struct fairino_interfaces__action__SE3_GetResult_Request__Sequence
{
  fairino_interfaces__action__SE3_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "fairino_interfaces/action/detail/se3__struct.h"

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_GetResult_Response
{
  int8_t status;
  fairino_interfaces__action__SE3_Result result;
} fairino_interfaces__action__SE3_GetResult_Response;

// Struct for a sequence of fairino_interfaces__action__SE3_GetResult_Response.
typedef struct fairino_interfaces__action__SE3_GetResult_Response__Sequence
{
  fairino_interfaces__action__SE3_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "fairino_interfaces/action/detail/se3__struct.h"

/// Struct defined in action/SE3 in the package fairino_interfaces.
typedef struct fairino_interfaces__action__SE3_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  fairino_interfaces__action__SE3_Feedback feedback;
} fairino_interfaces__action__SE3_FeedbackMessage;

// Struct for a sequence of fairino_interfaces__action__SE3_FeedbackMessage.
typedef struct fairino_interfaces__action__SE3_FeedbackMessage__Sequence
{
  fairino_interfaces__action__SE3_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fairino_interfaces__action__SE3_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FAIRINO_INTERFACES__ACTION__DETAIL__SE3__STRUCT_H_
