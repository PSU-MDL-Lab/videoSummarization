#include "onnx_pool/onnx_orch.hpp"
using namespace std::chrono_literals;
using std::placeholders::_1;


// TODO (izo5011): Figure out how to remove this definition
onnx_pool::OnnxOrch::OnnxOrch(const rclcpp::NodeOptions& options)
    : rclcpp::Node("", rclcpp::NodeOptions().use_intra_process_comms(true)) { }


onnx_pool::OnnxOrch::OnnxOrch (
    const std::string& name,
    const int subQueSz,    
    const int pubQueSz,
    const std::vector<std::string>& subVec,
    const std::vector<std::string>& pubVec)
: rclcpp::Node(name, rclcpp::NodeOptions().use_intra_process_comms(true))
{
    m_numSub = subVec.size();
    m_numPub = pubVec.size();
    // Create the subscriptions
    m_sub = new rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr[m_numSub];
    for(int i = 0; i < m_numSub; i++)
    {
        m_sub[i] = this->create_subscription<std_msgs::msg::UInt64>(
            subVec[i], subQueSz, std::bind(&onnx_pool::OnnxOrch::onRecv, this, _1)
        );
    }    
    // Create Publishers
    m_pub = new rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr[m_numPub];
    for(int i = 0; i < m_numPub; i++)
    {
        m_pub[i] = this->create_publisher<std_msgs::msg::UInt64>(pubVec[i], pubQueSz);
    }
}


void onnx_pool::OnnxOrch::onRecv(const typename std_msgs::msg::UInt64::UniquePtr msg)
{   
    uint64_t randVal = msg->data;
    // Create Message
    OnnxJob* onnx_job = new OnnxJob();
    onnx_job->value = randVal;
    auto pubMsg = std::make_unique<std_msgs::msg::UInt64>();
    pubMsg->data = (uint64_t)onnx_job;
    // Send Message
    RCLCPP_INFO(this->get_logger(), "Sent onnx_job with value: %d at address 0x%" PRIXPTR, onnx_job->value, pubMsg->data);
    m_pub[0]->publish(std::move(pubMsg));
}


#include "rclcpp_components/register_node_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(onnx_pool::OnnxOrch)
