#ifndef LOCAL_STREAM_PKG__LOCAL_STREAM_HPP_
#define LOCAL_STREAM_PKG__LOCAL_STREAM_HPP_


#include <chrono>
#include <cinttypes>
#include <cstdio>
#include <memory>
#include <string>
#include <utility>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int64.hpp"


class LocalStream : public rclcpp::Node
{
    public:
        LocalStream(
            const std::string& name,
            const int queueSize,
            const std::vector<std::string>& pubVec
        );
        

        void on_timer();


        rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr* m_pub;
        rclcpp::TimerBase::SharedPtr timer;
        int m_numPub;
};


#endif  // LOCAL_STREAM_PKG__LOCAL_STREAM_HPP_
