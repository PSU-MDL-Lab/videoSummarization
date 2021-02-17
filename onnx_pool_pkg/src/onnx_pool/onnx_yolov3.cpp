#include "onnx_pool/onnx_yolov3.hpp"
using namespace std::chrono_literals;
using std::placeholders::_1;


// TODO (izo5011): Figure out how to remove this definition
onnx_pool::OnnxYOLOv3::OnnxYOLOv3(const rclcpp::NodeOptions& options)
    : rclcpp::Node("name", rclcpp::NodeOptions().use_intra_process_comms(true))
{

}


onnx_pool::OnnxYOLOv3::OnnxYOLOv3 (
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
            subVec[i], subQueSz, std::bind(&onnx_pool::OnnxYOLOv3::onRecv, this, _1)
        );
    }    
    // Create Publishers
    m_pub = new rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr[m_numPub];
    for(int i = 0; i < m_numPub; i++)
    {
        m_pub[i] = this->create_publisher<std_msgs::msg::UInt64>(pubVec[i], pubQueSz);
    }
}


void onnx_pool::OnnxYOLOv3::onRecv(const typename std_msgs::msg::UInt64::UniquePtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received: '%llu'", msg->data);
    OnnxJob* onnx_job = reinterpret_cast<OnnxJob*>(msg->data);
    RCLCPP_INFO(this->get_logger(), "Recvd onnx_job with value: %d", onnx_job->value);
}


#include "rclcpp_components/register_node_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(onnx_pool::OnnxYOLOv3)
