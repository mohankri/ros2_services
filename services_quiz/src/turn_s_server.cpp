#include "rclcpp/executors.hpp"
#include "rclcpp/logger.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/timer.hpp"
#include "rclcpp/utilities.hpp"
#include <cstdint>
#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <services_quiz_srv/srv/turn.hpp>


class TurnServiceServer : public rclcpp::Node 
{
public:
    TurnServiceServer() : Node("Turn_Service_Server")
    {
        std::string name_service = "/turn";
        auto qos = rclcpp::QoS(10).reliability(rclcpp::ReliabilityPolicy::Reliable);

        time_to_expire = -1;

        service_ = this->create_service<services_quiz_srv::srv::Turn>
            (name_service,
            std::bind(&TurnServiceServer::handle_turn_request,
            this,
            std::placeholders::_1, std::placeholders::_2));

        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
            //"/fastbot_1/cmd_vel", 
            "/cmd_vel", 
            qos);

        auto timer_period = std::chrono::milliseconds(100);

        timer_ = this->create_wall_timer(timer_period, 
            std::bind(&TurnServiceServer::timer_callback, this));
    }

private:
    void timer_callback() {
        geometry_msgs::msg::Twist cmd;

        cmd.linear.x = 0.0;

        if (time_to_expire >= 0) {
            cmd.angular.z = direction_;
           // RCLCPP_INFO(this->get_logger(), "Angular %.2f", cmd.angular.z);
            time_to_expire -= 0.1f;
            //RCLCPP_INFO(this->get_logger(), "Total time %f", time_to_expire);
        } else {
            cmd.angular.z = 0;
        }
        
        publisher_->publish(cmd);
    }

    void handle_turn_request(const std::shared_ptr<services_quiz_srv::srv::Turn::Request> request,
        std::shared_ptr<services_quiz_srv::srv::Turn::Response> response) {
        
        this->time_to_expire = request->time;
        this->direction_ = (request->direction == "right")
                ? -1 : 1;
        this->direction_ *= request->angular_velocity;

        RCLCPP_INFO(this->get_logger(), "Handle Turn Service Request %f %f",
            this->direction_,
            request->angular_velocity);

        if (this->time_to_expire > 0) {
            RCLCPP_INFO(this->get_logger(), "Send False as time as not expired");
            response->success = false;
        } else {
            RCLCPP_INFO(this->get_logger(), "Time expired return true");
            response->success = true;
        }
    }

    rclcpp::Service<services_quiz_srv::srv::Turn>::SharedPtr service_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    float time_to_expire;
    float direction_ = 0;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto server_ = std::make_shared<TurnServiceServer>();
    rclcpp::spin(server_);
    rclcpp::shutdown();

    return 0;
}

