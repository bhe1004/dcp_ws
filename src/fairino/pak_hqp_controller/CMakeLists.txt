cmake_minimum_required(VERSION 3.10)
project(pak_hqp_controller)

find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(pinocchio REQUIRED)
find_package(eiquadprog REQUIRED)

# 소스/헤더 파일 자동 수집
file(GLOB_RECURSE PAKHQP_SRC
    "src/controller/*.cpp"
    "src/robot/*.cpp"
    "src/solver/*.cpp"
    "src/task/*.cpp"
    "src/utils/*.cpp"
)
file(GLOB_RECURSE PAKHQP_HEADERS
    "include/pak_hqp_controller/**/*.hpp"
)

# 라이브러리 생성
add_library(${PROJECT_NAME} SHARED
  ${PAKHQP_SRC}
)

# include path (빌드/설치 모두) — 반드시 add_library 뒤!
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${EIGEN3_INCLUDE_DIRS}
)

# ament dependencies 연결
ament_target_dependencies(${PROJECT_NAME}
  Eigen3
  pinocchio
  eiquadprog
)

# 설치 규칙 (헤더/라이브러리)
install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include/
)

# export 설정 (외부 find_package 지원)
ament_export_include_directories(include)
ament_export_targets(export_${PROJECT_NAME})
ament_export_libraries(${PROJECT_NAME})

ament_package()
