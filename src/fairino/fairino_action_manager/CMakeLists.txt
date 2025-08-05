cmake_minimum_required(VERSION 3.8)
project(fairino_action_manager)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(pinocchio REQUIRED)
find_package(kimm_qpoases REQUIRED)
find_package(kimm_trajectory_smoother REQUIRED)
find_package(kimm_hqp_controller REQUIRED)
find_package(pak_hqp_controller REQUIRED)
find_package(eiquadprog REQUIRED)
find_package(fairino_interfaces REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(rclpy REQUIRED)
find_package(action_msgs REQUIRED)
find_package(fmt REQUIRED)

# Include headers from SDK
include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
  ${pinocchio_INCLUDE_DIRS}
  ../libfairino/include
  ${kimm_hqp_controller_INCLUDE_DIRS}
  ${pak_hqp_controller_INCLUDE_DIRS}
  ${kimm_trajectory_smoother_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}  # for generated action headers
)

# Link to libfairino.so
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libfairino/lib
    ${Boost_LIBRARY_DIR}
)


# Add library
add_library(controller SHARED
  src/controller/controller.cpp
  src/servers/basic/joint_posture_action_server.cpp
  src/servers/basic/se3_action_server.cpp
  src/servers/basic/gripper_real_action_server.cpp
  src/servers/basic/gripper_sim_action_server.cpp
  src/servers/basic/tool_changer_action_sever.cpp
  src/servers/basic/qr_action_server.cpp
  # src/servers/basic/se3_array_action_server.cpp
)

add_library(task SHARED
  src/servers/task/base_task.cpp
  src/servers/task/pick.cpp
  src/servers/task/place.cpp
)



# Specify dependencies for robot_wrapper
ament_target_dependencies(controller
  rclcpp
  rclcpp_action
  rclcpp_components
  sensor_msgs
  geometry_msgs
  std_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
  tf2_eigen
  pinocchio
  Eigen3
  kimm_qpoases
  kimm_trajectory_smoother
  kimm_hqp_controller
  pak_hqp_controller
  fairino_interfaces
  rosgraph_msgs
  fmt
)
ament_target_dependencies(task
  rclcpp
  rclcpp_action
  rclcpp_components
  sensor_msgs
  geometry_msgs
  std_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
  tf2_eigen
  pinocchio
  Eigen3
  kimm_qpoases
  kimm_trajectory_smoother
  kimm_hqp_controller
  pak_hqp_controller
  fairino_interfaces
)

target_link_libraries(controller
  ${kimm_qpoases_LIBRARIES}
  ${kimm_trajectory_smoother_LIBRARIES}
  ${kimm_hqp_controller_LIBRARIES}
  ${pak_hqp_controller_LIBRARIES}
  eiquadprog::eiquadprog -lpthread
)

# Action Manager - Main
add_executable(${PROJECT_NAME}_real src/real/real.cpp)
target_link_libraries(${PROJECT_NAME}_real
  controller
  fairino
)
add_executable(${PROJECT_NAME}_simulation_isaac src/simulation/simulation_isaac.cpp)
target_link_libraries(${PROJECT_NAME}_simulation_isaac
  controller
  fairino
)

# Task Manager
add_executable(task_manager src/task/task_manager.cpp)
target_link_libraries(task_manager
  task
)


# Installation
install(TARGETS
  controller
  task
  ${PROJECT_NAME}_real
  ${PROJECT_NAME}_simulation_isaac
  task_manager
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

# Install include directory
install(DIRECTORY include/
  DESTINATION include
)

# Install launch directory
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()