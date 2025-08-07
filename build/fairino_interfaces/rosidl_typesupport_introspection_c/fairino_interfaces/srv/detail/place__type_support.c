// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fairino_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fairino_interfaces/srv/detail/place__rosidl_typesupport_introspection_c.h"
#include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fairino_interfaces/srv/detail/place__functions.h"
#include "fairino_interfaces/srv/detail/place__struct.h"


// Include directives for member types
// Member `client_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_pose`
#include "geometry_msgs/msg/pose.h"
// Member `target_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__srv__Place_Request__init(message_memory);
}

void fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_fini_function(void * message_memory)
{
  fairino_interfaces__srv__Place_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_member_array[3] = {
  {
    "client_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__srv__Place_Request, client_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__srv__Place_Request, target_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__srv__Place_Request, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_members = {
  "fairino_interfaces__srv",  // message namespace
  "Place_Request",  // message name
  3,  // number of fields
  sizeof(fairino_interfaces__srv__Place_Request),
  fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_member_array,  // message members
  fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_type_support_handle = {
  0,
  &fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Request)() {
  fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__srv__Place_Request__rosidl_typesupport_introspection_c__Place_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "fairino_interfaces/srv/detail/place__rosidl_typesupport_introspection_c.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "fairino_interfaces/srv/detail/place__functions.h"
// already included above
// #include "fairino_interfaces/srv/detail/place__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fairino_interfaces__srv__Place_Response__init(message_memory);
}

void fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_fini_function(void * message_memory)
{
  fairino_interfaces__srv__Place_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_member_array[1] = {
  {
    "is_completed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fairino_interfaces__srv__Place_Response, is_completed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_members = {
  "fairino_interfaces__srv",  // message namespace
  "Place_Response",  // message name
  1,  // number of fields
  sizeof(fairino_interfaces__srv__Place_Response),
  fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_member_array,  // message members
  fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_type_support_handle = {
  0,
  &fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Response)() {
  if (!fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_type_support_handle.typesupport_identifier) {
    fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &fairino_interfaces__srv__Place_Response__rosidl_typesupport_introspection_c__Place_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fairino_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "fairino_interfaces/srv/detail/place__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_members = {
  "fairino_interfaces__srv",  // service namespace
  "Place",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_Request_message_type_support_handle,
  NULL  // response message
  // fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_Response_message_type_support_handle
};

static rosidl_service_type_support_t fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_type_support_handle = {
  0,
  &fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fairino_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place)() {
  if (!fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_type_support_handle.typesupport_identifier) {
    fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fairino_interfaces, srv, Place_Response)()->data;
  }

  return &fairino_interfaces__srv__detail__place__rosidl_typesupport_introspection_c__Place_service_type_support_handle;
}
