#include "rclcpp/executors.hpp"
#include "rclcpp/logger.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/utilities.hpp"
#include <cstdint>
#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <services_quiz_srv/srv/turn.hpp>


class TurnServiceServer : public rclcpp::Node 
{
public:
    TurnServiceServer() : Node("Turn_Service_Server")
    {
        std::string name_service = "/turn";
        service_ = this->create_service<services_quiz_srv::srv::Turn>
            (name_service,
            std::bind(&TurnServiceServer::handle_turn_request,
            this,
            std::placeholders::_1, std::placeholders::_2));
    }

private:
    void handle_turn_request(const std::shared_ptr<services_quiz_srv::srv::Turn::Request> request,
        std::shared_ptr<services_quiz_srv::srv::Turn::Response> response) {
        
        RCLCPP_INFO(this->get_logger(), "Handle Turn Service Request %s %f %f",
            request->direction.c_str(),
            request->angular_velocity,
            request->time);
    }

    rclcpp::Service<services_quiz_srv::srv::Turn>::SharedPtr service_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto server_ = std::make_shared<TurnServiceServer>();
    rclcpp::spin(server_);
    rclcpp::shutdown();

    return 0;
}

