#include "rclcpp/rclcpp.hpp"
#include <cstdint>
#include <std_srvs/srv/trigger.hpp>
#include <services_quiz_srv/srv/turn.hpp>
#include <chrono>

using namespace std::chrono_literals;

class TurnServiceClient : public rclcpp::Node 
{
public:
    TurnServiceClient() : Node("Turn_Service_Client")
    {
        std::string name_service = "/turn";
        
        client_ = this->create_client<services_quiz_srv::srv::Turn>
            (name_service);

        // Wait for the service to be available (checks every second)
        while (!client_->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Service %s not available, waiting again...", name_service.c_str());
        }
        
    }

    void send_turn_request(std::string direction, float angular_velocity, float delay) {
        RCLCPP_INFO(this->get_logger(), "Send Turn Service Request");
        
        //auto request = std::make_shared<std_srvs::srv::Turn::Request>();
        auto request = std::make_shared<services_quiz_srv::srv::Turn::Request>();
        
        request->direction = direction;
        request->angular_velocity = angular_velocity;
        request->time = delay;

        auto result_future = client_->async_send_request(request);

        // Wait for the result
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(),
            result_future) == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = result_future.get();
            // Log the service response
            RCLCPP_INFO(this->get_logger(), "Success: %s", 
                response->success ? "true" : "false");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service");
        }
    }
private:
    rclcpp::Client<services_quiz_srv::srv::Turn>::SharedPtr client_;

};

int
main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto client_ = std::make_shared<TurnServiceClient>();
    
    std::string direction = "right";
    float angular_velocity = 0.2; //rad/s
    float time = 10; //10sec

    client_->send_turn_request(direction, angular_velocity, time);

    rclcpp::shutdown();

    return 0;
}