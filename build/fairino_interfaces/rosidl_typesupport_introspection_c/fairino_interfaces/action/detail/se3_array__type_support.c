// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fairino_interfaces:action/SE3Array.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
#include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fairino_interfaces/action/detail/se3_array__functions.h"
#include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `target_poses`
#include "geometry_msgs/msg/pose_array.h"
// Member `target_poses`
#include "geometry_msgs/msg/detail/pose_array__rosidl_typesupport_introspection_c.h"
// Member `durations`
#include "std_msgs/msg/float32_multi_array.h"
// Member `durations`
#include "std_msgs/msg/detail/float32_multi_array__rosidl_typesupport_introspection_c.h"
// Member `relative`
// Member `wholebody`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_Goal__init(message_memory);
}

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_Goal__fini(message_memory);
}

size_t fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__size_function__SE3Array_Goal__relative(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__relative(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__relative(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__fetch_function__SE3Array_Goal__relative(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__relative(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__assign_function__SE3Array_Goal__relative(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__relative(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__resize_function__SE3Array_Goal__relative(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

size_t fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__size_function__SE3Array_Goal__wholebody(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__wholebody(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__wholebody(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__fetch_function__SE3Array_Goal__wholebody(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__wholebody(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__assign_function__SE3Array_Goal__wholebody(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__wholebody(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__resize_function__SE3Array_Goal__wholebody(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_member_array[4] = {
  {
    "target_poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Goal, target_poses),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "durations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Goal, durations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Goal, relative),  // bytes offset in struct
    NULL,  // default value
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__size_function__SE3Array_Goal__relative,  // size() function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__relative,  // get_const(index) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__relative,  // get(index) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__fetch_function__SE3Array_Goal__relative,  // fetch(index, &value) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__assign_function__SE3Array_Goal__relative,  // assign(index, value) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__resize_function__SE3Array_Goal__relative  // resize(index) function pointer
  },
  {
    "wholebody",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Goal, wholebody),  // bytes offset in struct
    NULL,  // default value
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__size_function__SE3Array_Goal__wholebody,  // size() function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_const_function__SE3Array_Goal__wholebody,  // get_const(index) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__get_function__SE3Array_Goal__wholebody,  // get(index) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__fetch_function__SE3Array_Goal__wholebody,  // fetch(index, &value) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__assign_function__SE3Array_Goal__wholebody,  // assign(index, value) function pointer
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__resize_function__SE3Array_Goal__wholebody  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_Goal",  // message name
  4,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_Goal),
  fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Goal)() {
  fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseArray)();
  fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  if (!fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_Goal__rosidl_typesupport_introspection_c__SE3Array_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_Result__init(message_memory);
}

void fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_member_array[1] = {
  {
    "is_completed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Result, is_completed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_Result",  // message name
  1,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_Result),
  fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Result)() {
  if (!fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_Result__rosidl_typesupport_introspection_c__SE3Array_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_Feedback__init(message_memory);
}

void fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_member_array[1] = {
  {
    "percent_complete",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_Feedback, percent_complete),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_Feedback",  // message name
  1,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_Feedback),
  fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Feedback)() {
  if (!fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_Feedback__rosidl_typesupport_introspection_c__SE3Array_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "fairino_interfaces/action/se3_array.h"
// Member `goal`
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_SendGoal_Request__init(message_memory);
}

void fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_SendGoal_Request),
  fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Request)() {
  fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Goal)();
  if (!fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_SendGoal_Request__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_SendGoal_Response__init(message_memory);
}

void fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_SendGoal_Response),
  fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Response)() {
  fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_SendGoal_Response__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_members = {
  "fairino_interfaces__action",  // service namespace
  "SE3Array_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_type_support_handle = {
  0,
  &fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal)() {
  if (!fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_SendGoal_Response)()->data;
  }

  return &fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_GetResult_Request__init(message_memory);
}

void fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_GetResult_Request),
  fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Request)() {
  fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_GetResult_Request__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "fairino_interfaces/action/se3_array.h"
// Member `result`
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_GetResult_Response__init(message_memory);
}

void fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_GetResult_Response),
  fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Response)() {
  fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Result)();
  if (!fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_GetResult_Response__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_members = {
  "fairino_interfaces__action",  // service namespace
  "SE3Array_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_type_support_handle = {
  0,
  &fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult)() {
  if (!fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_GetResult_Response)()->data;
  }

  return &fairino_interfaces__action__detail__se3_array__rosidl_typesupport_introspection_c__SE3Array_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__functions.h"
// already included above
// #include "fairino_interfaces/action/detail/se3_array__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "fairino_interfaces/action/se3_array.h"
// Member `feedback`
// already included above
// #include "fairino_interfaces/action/detail/se3_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__action__SE3Array_FeedbackMessage__init(message_memory);
}

void fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_fini_function(void * message_memory)
{
  fairino_interfaces__action__SE3Array_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__action__SE3Array_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_members = {
  "fairino_interfaces__action",  // message namespace
  "SE3Array_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(fairino_interfaces__action__SE3Array_FeedbackMessage),
  fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_member_array,  // message members
  fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_type_support_handle = {
  0,
  &fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_FeedbackMessage)() {
  fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, action, SE3Array_Feedback)();
  if (!fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__action__SE3Array_FeedbackMessage__rosidl_typesupport_introspection_c__SE3Array_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
