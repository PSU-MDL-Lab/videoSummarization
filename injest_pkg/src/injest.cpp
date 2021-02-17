#include <cstdio>
#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "local_stream.hpp"
#include "onnx_pool/onnx_orch.hpp"
#include "onnx_pool/onnx_yolov3.hpp"
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
    std::vector<std::string> onnx_orch_sV;   
    std::vector<std::string> onnx_orch_pV;
    std::vector<std::string> onnx_yolov3_sV;    
    std::vector<std::string> onnx_yolov3_pV;

    
    // Construct Nodes
    local_stream_pV.push_back("LOCAL_STREAM_TOPIC");
    auto local_stream = std::make_shared<LocalStream>(        
        "Local_Stream", 
        10,
        local_stream_pV
    );
    onnx_orch_sV.push_back("LOCAL_STREAM_TOPIC");   
    onnx_orch_pV.push_back("ONNX_JOB_TOPIC");
    auto onnx_orch = std::make_shared<onnx_pool::OnnxOrch>(
        "Onnx_Orch", 
        10,
        10,
        onnx_orch_sV,    
        onnx_orch_pV
    );
    onnx_yolov3_sV.push_back("ONNX_JOB_TOPIC");   
    onnx_yolov3_pV.push_back("ONNX_POOL_OUT");
    auto onnx_yolov3_0 = std::make_shared<onnx_pool::OnnxYOLOv3>(
        "Onnx_YOLOV3_0", 
        10,
        10,
        onnx_yolov3_sV,
        onnx_yolov3_pV
    );

    // Wait for subscriptions to be established to avoid race conditions
    rclcpp::sleep_for(1s);  


    // Add nodes to the executor which provide work for the executor during its "spin" function.
    exec.add_node(local_stream); 
    exec.add_node(onnx_orch);
    exec.add_node(onnx_yolov3_0);

    // spin will block until work comes in, execute work as it becomes available, and keep blocking.
    // It will only be interrupted by Ctrl-C.
    exec.spin();

    // Clean up
    rclcpp::shutdown();
    
    return 0;
}
