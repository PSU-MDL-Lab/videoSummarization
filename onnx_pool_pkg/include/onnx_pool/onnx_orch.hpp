#ifndef ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_
#define ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_

#include <chrono>
#include <cinttypes>
#include <cstdio>
#include <memory>
#include <string>
#include <utility>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int64.hpp"
#include "onnx_pool/visibility_control.h"
#include "onnx_pool/onnx_job.hpp"


namespace onnx_pool
{
    class OnnxOrch : public rclcpp::Node
    {
        public:
            // Constructors
            OnnxOrch(const rclcpp::NodeOptions& options);      
            ONNX_POOL_PUBLIC
            explicit OnnxOrch(
                const std::string& name, 
                const int queueSize, 
                const std::vector<std::string>& pubVec, 
                const std::vector<std::string>& subVec
            );
            // Members
            rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr* m_pub;
            rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr* m_sub;
            int m_numPub;
            int m_numSub;
    };
}  // namespace onnx_pool


#endif  // ONNX_POOL__ONNX_ORCH_COMPONENT_HPP_
