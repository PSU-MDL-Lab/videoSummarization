cmake_minimum_required(VERSION 3.5)
project(injest_pkg)


# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()


# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)
find_package(std_msgs REQUIRED)


add_executable(injest src/injest.cpp)
target_include_directories(
    injest PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../local_stream_pkg/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../onnx_pool_pkg/include>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(injest
    -L${CMAKE_CURRENT_SOURCE_DIR}/../local_stream_pkg/build/local_stream_pkg/
    -L${CMAKE_CURRENT_SOURCE_DIR}/../onnx_pool_pkg/build/onnx_pool/
    -lonnx_orch
    -lonnx_job 
    -llocal_stream_pkg
)
ament_target_dependencies( 
    injest
    "class_loader"
    "rclcpp"
    "rclcpp_components"
)


install(TARGETS injest DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


ament_package()
