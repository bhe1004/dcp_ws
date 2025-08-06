// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from fairino_interfaces:action/JointPosture.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_Goal_type_support_ids_t;

static const _JointPosture_Goal_type_support_ids_t _JointPosture_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_Goal_type_support_symbol_names_t _JointPosture_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_Goal)),
  }
};

typedef struct _JointPosture_Goal_type_support_data_t
{
  void * data[2];
} _JointPosture_Goal_type_support_data_t;

static _JointPosture_Goal_type_support_data_t _JointPosture_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_Goal_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_Goal>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_Goal)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_Result_type_support_ids_t;

static const _JointPosture_Result_type_support_ids_t _JointPosture_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_Result_type_support_symbol_names_t _JointPosture_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_Result)),
  }
};

typedef struct _JointPosture_Result_type_support_data_t
{
  void * data[2];
} _JointPosture_Result_type_support_data_t;

static _JointPosture_Result_type_support_data_t _JointPosture_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_Result_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_Result_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_Result_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_Result>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_Result)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_Feedback_type_support_ids_t;

static const _JointPosture_Feedback_type_support_ids_t _JointPosture_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_Feedback_type_support_symbol_names_t _JointPosture_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_Feedback)),
  }
};

typedef struct _JointPosture_Feedback_type_support_data_t
{
  void * data[2];
} _JointPosture_Feedback_type_support_data_t;

static _JointPosture_Feedback_type_support_data_t _JointPosture_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_Feedback_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_Feedback>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_Feedback)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_SendGoal_Request_type_support_ids_t;

static const _JointPosture_SendGoal_Request_type_support_ids_t _JointPosture_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_SendGoal_Request_type_support_symbol_names_t _JointPosture_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_SendGoal_Request)),
  }
};

typedef struct _JointPosture_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _JointPosture_SendGoal_Request_type_support_data_t;

static _JointPosture_SendGoal_Request_type_support_data_t _JointPosture_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_SendGoal_Request_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal_Request>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_SendGoal_Request)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_SendGoal_Response_type_support_ids_t;

static const _JointPosture_SendGoal_Response_type_support_ids_t _JointPosture_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_SendGoal_Response_type_support_symbol_names_t _JointPosture_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_SendGoal_Response)),
  }
};

typedef struct _JointPosture_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _JointPosture_SendGoal_Response_type_support_data_t;

static _JointPosture_SendGoal_Response_type_support_data_t _JointPosture_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_SendGoal_Response_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal_Response>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_SendGoal_Response)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_SendGoal_type_support_ids_t;

static const _JointPosture_SendGoal_type_support_ids_t _JointPosture_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_SendGoal_type_support_symbol_names_t _JointPosture_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_SendGoal)),
  }
};

typedef struct _JointPosture_SendGoal_type_support_data_t
{
  void * data[2];
} _JointPosture_SendGoal_type_support_data_t;

static _JointPosture_SendGoal_type_support_data_t _JointPosture_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_SendGoal_service_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t JointPosture_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<fairino_interfaces::action::JointPosture_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_GetResult_Request_type_support_ids_t;

static const _JointPosture_GetResult_Request_type_support_ids_t _JointPosture_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_GetResult_Request_type_support_symbol_names_t _JointPosture_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_GetResult_Request)),
  }
};

typedef struct _JointPosture_GetResult_Request_type_support_data_t
{
  void * data[2];
} _JointPosture_GetResult_Request_type_support_data_t;

static _JointPosture_GetResult_Request_type_support_data_t _JointPosture_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_GetResult_Request_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_GetResult_Request>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_GetResult_Request)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_GetResult_Response_type_support_ids_t;

static const _JointPosture_GetResult_Response_type_support_ids_t _JointPosture_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_GetResult_Response_type_support_symbol_names_t _JointPosture_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_GetResult_Response)),
  }
};

typedef struct _JointPosture_GetResult_Response_type_support_data_t
{
  void * data[2];
} _JointPosture_GetResult_Response_type_support_data_t;

static _JointPosture_GetResult_Response_type_support_data_t _JointPosture_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_GetResult_Response_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_GetResult_Response>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_GetResult_Response)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_GetResult_type_support_ids_t;

static const _JointPosture_GetResult_type_support_ids_t _JointPosture_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_GetResult_type_support_symbol_names_t _JointPosture_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_GetResult)),
  }
};

typedef struct _JointPosture_GetResult_type_support_data_t
{
  void * data[2];
} _JointPosture_GetResult_type_support_data_t;

static _JointPosture_GetResult_type_support_data_t _JointPosture_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_GetResult_service_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t JointPosture_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<fairino_interfaces::action::JointPosture_GetResult>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<fairino_interfaces::action::JointPosture_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _JointPosture_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointPosture_FeedbackMessage_type_support_ids_t;

static const _JointPosture_FeedbackMessage_type_support_ids_t _JointPosture_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _JointPosture_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointPosture_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointPosture_FeedbackMessage_type_support_symbol_names_t _JointPosture_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fairino_interfaces, action, JointPosture_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fairino_interfaces, action, JointPosture_FeedbackMessage)),
  }
};

typedef struct _JointPosture_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _JointPosture_FeedbackMessage_type_support_data_t;

static _JointPosture_FeedbackMessage_type_support_data_t _JointPosture_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointPosture_FeedbackMessage_message_typesupport_map = {
  2,
  "fairino_interfaces",
  &_JointPosture_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_JointPosture_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_JointPosture_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointPosture_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointPosture_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fairino_interfaces::action::JointPosture_FeedbackMessage>()
{
  return &::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture_FeedbackMessage)() {
  return get_message_type_support_handle<fairino_interfaces::action::JointPosture_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "fairino_interfaces/action/detail/joint_posture__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace fairino_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t JointPosture_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace fairino_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<fairino_interfaces::action::JointPosture>()
{
  using ::fairino_interfaces::action::rosidl_typesupport_cpp::JointPosture_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  JointPosture_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::fairino_interfaces::action::JointPosture::Impl::SendGoalService>();
  JointPosture_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::fairino_interfaces::action::JointPosture::Impl::GetResultService>();
  JointPosture_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::fairino_interfaces::action::JointPosture::Impl::CancelGoalService>();
  JointPosture_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::fairino_interfaces::action::JointPosture::Impl::FeedbackMessage>();
  JointPosture_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::fairino_interfaces::action::JointPosture::Impl::GoalStatusMessage>();
  return &JointPosture_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, fairino_interfaces, action, JointPosture)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<fairino_interfaces::action::JointPosture>();
}

#ifdef __cplusplus
}
#endif
