#include <cstdio>
#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "local_stream.hpp"
// #include "onnx_pool/onnx_orch.hpp"
// #include "onnx_pool/onnx_yolov3.hpp"
using namespace std::chrono_literals;


int main(int argc, char** argv)
{
    
    // Force flush of the stdout buffer.
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    // Initialize any global resources needed by the middleware and the client library.
    // This will also parse command line arguments one day (as of Beta 1 they are not used).
    // You must call this before using any other part of the ROS system.
    // This should be called once per process.
    rclcpp::init(argc, argv);
    
    // Create an executor that will be responsible for execution of callbacks for a set of nodes.
    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;
    std::vector<std::string> local_stream_pV;
    std::vector<std::string> local_stream_sV;
    std::vector<std::string> onnx_orch_pV;
    std::vector<std::string> onnx_orch_sV;
    std::vector<std::string> onnx_yolov3_pV;
    std::vector<std::string> onnx_yolov3_sV;
    
    // Add nodes to the executor which provide work for the executor during its "spin" function.
    auto local_stream = std::make_shared<LocalStream>(        
        "Local_Stream", 
        10, 
        local_stream_pV
    );
    // auto onnx_orch = std::make_shared<onnx_pool::OnnxOrch>(
    //     "Onnx_Orch", 
    //     10, 
    //     onnx_orch_pV, 
    //     onnx_orch_sV)
    // );
    // auto onnx_yolov3_0 = std::make_shared<onnx_pool::OnnxYOLOV3>("Onnx_YOLOV3_0");
    // auto onnx_yolov3_1 = std::make_shared<onnx_pool::OnnxYOLOV3>("Onnx_YOLOV3_1");
    // auto onnx_yolov3_2 = std::make_shared<onnx_pool::OnnxYOLOV3>("Onnx_Yolov3_2");
    rclcpp::sleep_for(1s);  // Wait for subscriptions to be established to avoid race conditions

    exec.add_node(local_stream);
    
    // exec.add_node(onnx_orch);
    // exec.add_node(onnx_yolov3_0);
    // exec.add_node(onnx_yolov3_1);
    // exec.add_node(onnx_yolov3_2);
  
    // spin will block until work comes in, execute work as it becomes available, and keep blocking.
    // It will only be interrupted by Ctrl-C.
    exec.spin();
    // Clean up
    rclcpp::shutdown();
    
    return 0;
}
