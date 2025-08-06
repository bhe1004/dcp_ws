# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_fairino_rviz_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED fairino_rviz_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(fairino_rviz_FOUND FALSE)
  elseif(NOT fairino_rviz_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(fairino_rviz_FOUND FALSE)
  endif()
  return()
endif()
set(_fairino_rviz_CONFIG_INCLUDED TRUE)

# output package information
if(NOT fairino_rviz_FIND_QUIETLY)
  message(STATUS "Found fairino_rviz: 0.1.0 (${fairino_rviz_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'fairino_rviz' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${fairino_rviz_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(fairino_rviz_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${fairino_rviz_DIR}/${_extra}")
endforeach()
