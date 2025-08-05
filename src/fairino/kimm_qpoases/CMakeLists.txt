cmake_minimum_required(VERSION 3.8)
project(kimm_qpoases)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c++17 -O3 -DNDEBUG)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)

# Header and source files
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS
  include/*.hpp
  include/qpOASES/*.hpp
  include/qpOASES/*.ipp
  include/qpOASES/extras/*.hpp
  include/qpOASES/extras/*.ipp
)

file(GLOB ${PROJECT_NAME}_SRCS src/*.cpp)

# Include directories
include_directories(include)

# Add library
add_library(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SRCS}
  ${${PROJECT_NAME}_HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(${PROJECT_NAME} Eigen3)

# Install targets
install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include
)

# Export package
ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_package()
