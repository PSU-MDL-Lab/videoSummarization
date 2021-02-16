#include "onnx_pool/onnx_orch.hpp"


namespace onnx_pool
{


OnnxOrch::OnnxOrch(
    const std::string& name, 
    const int queueSize, 
    const std::vector<std::string>& pubVec, 
    const std::vector<std::string>& subVec)
: Node(name, rclcpp::NodeOptions().use_intra_process_comms(true))
{
    // Create the subscriptions
    sub = this->create_subscription<std_msgs::msg::UInt64> (
        "LOCAL_STREAM_TOPIC", queueSize, [](std_msgs::msg::UInt64::UniquePtr msg) {
    uint64_t randVal = reinterpret_cast<std::uintptr_t>(msg.data())       
    onnx_job = new OnnxJob();
    onnx_job->value = randVal;
    msg->data = (uint64_t)&onnx_job;
    
    
    onnx_job = reinterpret_cast<onnx_pool::OnnxJob>(cls_ptr)
    printf("Received onnx_job with value: %d at address" PRIXPTR "\n", onnx_job->value, cls_ptr);
    });
}


OnnxOrch::~OnnxOrch()
{
}


}  // namespace onnx_orch_pkg
