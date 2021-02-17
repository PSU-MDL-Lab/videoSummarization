cmake_minimum_required(VERSION 3.5)
project(onnx_pool)

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
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

# create ament index resource which references the libraries in the binary dir
set(node_plugins "")


add_library(onnx_job SHARED src/onnx_pool/onnx_job.cpp)
target_include_directories(onnx_job PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library(onnx_orch SHARED src/onnx_pool/onnx_orch.cpp)
target_include_directories(onnx_orch PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
ament_target_dependencies(onnx_orch
    "rclcpp"
    "rclcpp_components"
    "std_msgs")
rclcpp_components_register_nodes(onnx_orch "onnx_pool::OnnxOrch")
set(node_plugins "${node_plugins}onnx_pool::OnnxOrch;$<TARGET_FILE:onnx_orch>\n")

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(onnx_orch PRIVATE "ONNX_ORCH_PKG_BUILDING_LIBRARY")

install(
DIRECTORY include/
DESTINATION include
)
install(TARGETS
    onnx_job
    onnx_orch
    EXPORT export_${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

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

ament_export_include_directories(
  include
)
ament_export_libraries(
  onnx_orch
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
