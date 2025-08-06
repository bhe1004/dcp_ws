# Install script for directory: /home/home/dcp_ws/src/fairino/fairino_action_manager

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/home/dcp_ws/install/fairino_action_manager")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/home/dcp_ws/build/fairino_action_manager/ament_cmake_symlink_install/ament_cmake_symlink_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/home/dcp_ws/build/fairino_action_manager/libcontroller.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so"
         OLD_RPATH "/home/home/dcp_ws/src/fairino/fairino_action_manager/../libfairino/lib:/opt/ros/humble/lib:/home/home/dcp_ws/install/kimm_hqp_controller/lib:/home/home/dcp_ws/install/pak_hqp_controller/lib:/home/home/dcp_ws/install/fairino_interfaces/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/home/dcp_ws/install/kimm_qpoases/lib:/home/home/dcp_ws/install/kimm_trajectory_smoother/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcontroller.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/home/dcp_ws/build/fairino_action_manager/libtask.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so"
         OLD_RPATH "/home/home/dcp_ws/src/fairino/fairino_action_manager/../libfairino/lib:/opt/ros/humble/lib:/home/home/dcp_ws/install/kimm_hqp_controller/lib:/home/home/dcp_ws/install/pak_hqp_controller/lib:/home/home/dcp_ws/install/fairino_interfaces/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/home/dcp_ws/install/kimm_qpoases/lib:/home/home/dcp_ws/install/kimm_trajectory_smoother/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtask.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager" TYPE EXECUTABLE FILES "/home/home/dcp_ws/build/fairino_action_manager/fairino_action_manager_real")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real"
         OLD_RPATH "/home/home/dcp_ws/src/fairino/fairino_action_manager/../libfairino/lib:/home/home/dcp_ws/build/fairino_action_manager:/opt/ros/humble/lib:/home/home/dcp_ws/install/kimm_hqp_controller/lib:/home/home/dcp_ws/install/pak_hqp_controller/lib:/home/home/dcp_ws/install/fairino_interfaces/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/home/dcp_ws/install/kimm_qpoases/lib:/home/home/dcp_ws/install/kimm_trajectory_smoother/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_real")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager" TYPE EXECUTABLE FILES "/home/home/dcp_ws/build/fairino_action_manager/fairino_action_manager_simulation_isaac")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac"
         OLD_RPATH "/home/home/dcp_ws/src/fairino/fairino_action_manager/../libfairino/lib:/home/home/dcp_ws/build/fairino_action_manager:/opt/ros/humble/lib:/home/home/dcp_ws/install/kimm_hqp_controller/lib:/home/home/dcp_ws/install/pak_hqp_controller/lib:/home/home/dcp_ws/install/fairino_interfaces/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/home/dcp_ws/install/kimm_qpoases/lib:/home/home/dcp_ws/install/kimm_trajectory_smoother/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/fairino_action_manager_simulation_isaac")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager" TYPE EXECUTABLE FILES "/home/home/dcp_ws/build/fairino_action_manager/task_manager")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager"
         OLD_RPATH "/home/home/dcp_ws/src/fairino/fairino_action_manager/../libfairino/lib:/home/home/dcp_ws/build/fairino_action_manager:/opt/ros/humble/lib:/home/home/dcp_ws/install/kimm_hqp_controller/lib:/home/home/dcp_ws/install/pak_hqp_controller/lib:/home/home/dcp_ws/install/fairino_interfaces/lib:/opt/ros/humble/lib/x86_64-linux-gnu:/home/home/dcp_ws/install/kimm_qpoases/lib:/home/home/dcp_ws/install/kimm_trajectory_smoother/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/fairino_action_manager/task_manager")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/home/dcp_ws/build/fairino_action_manager/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
