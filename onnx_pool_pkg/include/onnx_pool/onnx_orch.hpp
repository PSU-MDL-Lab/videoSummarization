#ifndef ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_
#define ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_


#include "onnx_pool/visibility_control.h"
#include "onnx_pool/onnx_job.hpp"
#include "rclcpp/rclcpp.hpp"


namespace onnx_pool
{


class OnnxOrch : public rclcpp::Node
{
    public:
        ONNX_POOL
        explicit OnnxOrch(
            const std::string& name, 
            const int queueSize, 
            const std::vector<std::string>& pubVec, 
            const std::vector<std::string>& subVec
        );
        ~OnnxOrch();
        
        
        OnnxJob* onnx_job
        rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr pub;
        rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr sub;
};


}  // namespace onnx_pool

#endif  // ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_
