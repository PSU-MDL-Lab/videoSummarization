#include "onnx_pool/onnx_orch.hpp"
using namespace std::chrono_literals;


onnx_pool::OnnxOrch::OnnxOrch(const rclcpp::NodeOptions& options)
    : rclcpp::Node("name", rclcpp::NodeOptions().use_intra_process_comms(true))
{

}


onnx_pool::OnnxOrch::OnnxOrch (
    const std::string& name, 
    const int queueSize, 
    const std::vector<std::string>& pubVec, 
    const std::vector<std::string>& subVec)
: rclcpp::Node(name, rclcpp::NodeOptions().use_intra_process_comms(true))
{
    m_numPub = pubVec.size();
    m_numSub = subVec.size();
    // Create Publishers
    m_pub = new rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr[m_numPub];
    m_pub[0] = this->create_publisher<std_msgs::msg::UInt64>("ONNX_JOB_TOPIC", queueSize);
    // Create callback
    auto callback =
    [this](const typename std_msgs::msg::UInt64::UniquePtr msg) -> void
    {
        RCLCPP_INFO(this->get_logger(), "Received: '%llu'", msg->data);       
        uint64_t randVal = msg->data;
        // Create Message
        OnnxJob* onnx_job = new OnnxJob();
        onnx_job->value = randVal;
        auto pubMsg = std::make_unique<std_msgs::msg::UInt64>();
        pubMsg->data = (uint64_t)onnx_job;
        // Send Message    
        RCLCPP_INFO(this->get_logger(), "Sent onnx_job with value: %d at address 0x%" PRIXPTR "\n", onnx_job->value, pubMsg->data);
    };
    // Create the subscriptions
    m_sub = new rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr[m_numSub];
    m_sub[0] = this->create_subscription<std_msgs::msg::UInt64>(
        "LOCAL_STREAM_TOPIC", queueSize, callback
    ); 
}


#include "rclcpp_components/register_node_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(onnx_pool::OnnxOrch)
