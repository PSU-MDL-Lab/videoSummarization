#include "onnx_yolov3_pkg/onnx_yolov3.hpp"


namespace onnx_yolov3_pkg
{


OnnxYolov3::OnnxYolov3()
{
    m_numPub = pubVec.size();
    m_numSub = subVec.size();
    // Create the subscriptions
    m_sub = new rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr[m_numSub];
    m_sub[0] = this->create_subscription<std_msgs::msg::UInt64> (
        "LOCAL_STREAM_TOPIC", queueSize, [](std_msgs::msg::UInt64::UniquePtr msg) 
    {
        OnnxJob* onnx_job;
        onnx_job = reinterpret_cast<onnx_pool::OnnxJob>(cls_ptr)
        printf("Received onnx_job with value: %d at address" PRIXPTR "\n", onnx_job->value, cls_ptr);
    });
}


OnnxYolov3::~OnnxYolov3()
{
}


}  // namespace onnx_yolov3_pkg
