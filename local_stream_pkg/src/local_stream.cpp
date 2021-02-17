#include "local_stream.hpp"
using namespace std::chrono_literals;


LocalStream::LocalStream(
    const std::string& name,
    const int queueSize,
    const std::vector<std::string>& pubVec)
: rclcpp::Node(name, rclcpp::NodeOptions().use_intra_process_comms(true))
{
    // Create publisher
    m_numPub = pubVec.size();
    m_pub = new rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr[m_numPub];
    m_pub[0] = this->create_publisher<std_msgs::msg::UInt64>("LOCAL_STREAM_TOPIC", queueSize);  
    // Use a timer to schedule periodic message publishing.
    timer = create_wall_timer(1s, std::bind(&LocalStream::on_timer, this));
}


void LocalStream::on_timer()
{
    // Create Message
    auto msg = std::make_unique<std_msgs::msg::UInt64>();
    msg->data = (uint64_t)rand();
    RCLCPP_INFO(this->get_logger(), "Publishing: '%llu'", msg->data);
    std::flush(std::cout);
    // Put the message into a queue to be processed by the middleware.
    // This call is non-blocking.
    m_pub[0]->publish(std::move(msg));
}
