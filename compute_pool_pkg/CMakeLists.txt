cmake_minimum_required(VERSION 3.5)
project(compute_pool)


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
find_package(rcutils REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)


include_directories(include)


# create ament index resource which references the libraries in the binary dir
set(node_plugins "")


### Add Onnx Job Spec
add_library(compute_job SHARED src/compute_pool/compute_job.cpp)
target_include_directories(compute_job PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


### Add Onnx Orchrestator
add_library(compute_orch SHARED src/compute_pool/compute_orch.cpp)
target_include_directories(compute_orch PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(compute_orch
    "rclcpp"
    "rcutils"
    "std_msgs"
    "rclcpp_components"
)
rclcpp_components_register_nodes(compute_orch "compute_pool::OnnxOrch")
set(node_plugins "${node_plugins}compute_pool::OnnxOrch;$<TARGET_FILE:compute_orch>\n")
# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(compute_orch PRIVATE "ONNX_ORCH_PKG_BUILDING_LIBRARY")


### Add Onnx YOLOv3
add_library(onnx_yolov3 SHARED src/compute_pool/onnx_yolov3.cpp)
target_include_directories(onnx_yolov3 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(onnx_yolov3
    "rclcpp"
    "rcutils"
    "std_msgs"
    "rclcpp_components"
)
rclcpp_components_register_nodes(onnx_yolov3 "compute_pool::OnnxYOLOv3")
set(node_plugins "${node_plugins}compute_pool::OnnxYOLOv3;$<TARGET_FILE:onnx_yolov3>\n")
# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(onnx_yolov3 PRIVATE "ONNX_YOLOV3_PKG_BUILDING_LIBRARY")


install(
    DIRECTORY include/
    DESTINATION include
)
install(TARGETS
    compute_job
    compute_orch
    onnx_yolov3
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
  compute_orch
  onnx_yolov3
)
ament_export_targets(
  export_${PROJECT_NAME}
)
ament_package()
