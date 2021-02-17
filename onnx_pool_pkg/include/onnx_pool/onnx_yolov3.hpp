#ifndef ONNX_POOL__ONNX_YOLOV3_COMPONENT_HPP_
#define ONNX_POOL__ONNX_YOLOV3_COMPONENT_HPP_


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
    class OnnxYOLOv3 : public rclcpp::Node
    {
        public:
            // Constructors
            // TODO (izo5011): Figure out how to remove this constructor and its definition
            OnnxYOLOv3(const rclcpp::NodeOptions& options);      
            ONNX_POOL_PUBLIC
            OnnxYOLOv3(
                const std::string& name,
                const int subQueSz,
                const int pubQueSz,
                const std::vector<std::string>& subVec,                
                const std::vector<std::string>& pubVec
            );
            // Member functions
            void onRecv(const typename std_msgs::msg::UInt64::UniquePtr msg);
            // Attributes
            int m_numSub;
            int m_numPub;
            rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr* m_sub;
            rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr* m_pub;
    };
}  // namespace onnx_pool


#endif  // ONNX_POOL__ONNX_YOLOV3_COMPONENT_HPP_