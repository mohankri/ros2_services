#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>

//#include "leo_description/action/rotate.hpp"
#include "action_msgs/msg/goal_status.hpp"
#include "actions_quiz_msg/action/action_quiz_message.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

class ActionQuizClient : public rclcpp::Node
{
public:
    using ActionQuizMessage = actions_quiz_msg::action::ActionQuizMessage;
    using GoalHandleActionQuizMessage = rclcpp_action::ClientGoalHandle<ActionQuizMessage>;

    explicit ActionQuizClient(const rclcpp::NodeOptions &options)
        : Node("ActionQuizClient", options)
    {
        this->client_ = rclcpp_action::create_client<ActionQuizMessage>(
            this,
            action_name_);

        timeout_timer_ = create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&ActionQuizClient::check_goal_timeout, this));
    }
    
    bool send_goal(double x, double y, double yaw) {
        using namespace std::placeholders;

        RCLCPP_INFO(get_logger(), "Waiting for action server '%s'...",
                action_name_.c_str());

        if (!client_->wait_for_action_server(std::chrono::seconds(10))) {
            if (rclcpp::ok()) {
                RCLCPP_ERROR(get_logger(),
                    "Action server '%s' was not available "
                    "after 10 seconds.",
                    action_name_.c_str());
            }
            return false;
        }

        ActionQuizMessage::Goal goal_msg;

        goal_msg.x = x;
        goal_msg.y = y;
        goal_msg.yaw = yaw;

        auto send_goal_options = rclcpp_action::Client<ActionQuizMessage>::SendGoalOptions();

        send_goal_options.goal_response_callback =
        std::bind(&ActionQuizClient::goal_response_callback, this, _1);

        send_goal_options.feedback_callback =
        std::bind(&ActionQuizClient::feedback_callback, this, _1, _2);

        send_goal_options.result_callback =
        std::bind(&ActionQuizClient::result_callback, this, _1);

        client_->async_send_goal(goal_msg, send_goal_options);

        return true;
    }

private:
    void
    goal_response_callback(const GoalHandleActionQuizMessage::SharedPtr &goal_handle)
    {
        RCLCPP_INFO(get_logger(), "Goal Response callback.");
        if (!goal_handle) {
            RCLCPP_ERROR(get_logger(), "Goal was rejected by the action server.");
            goal_active_ = false;
            return;
        }

        current_goal_handle_ = goal_handle;
        goal_start_time_ = now();
        goal_active_ = true;
        timeout_triggered_ = false;

        RCLCPP_INFO(get_logger(), "Goal accepted. Timeout starts now.");
    }

    void
    feedback_callback(GoalHandleActionQuizMessage::SharedPtr,
        const std::shared_ptr<const ActionQuizMessage::Feedback> feedback) 
    {
        //(void)feedback;
        RCLCPP_INFO(get_logger(), "Goal Feedback callback. %f ", feedback->distance_left);
    }

    void result_callback(const GoalHandleActionQuizMessage::WrappedResult &result)
    {
        RCLCPP_INFO(get_logger(), "Goal Result Callback....");
        goal_active_ = false;
        current_goal_handle_.reset();

        switch (result.code) {
        case rclcpp_action::ResultCode::SUCCEEDED:
            //RCLCPP_INFO(get_logger(), "The robot reached the goal. %f", result.distance_traveled);
            break;

        case rclcpp_action::ResultCode::ABORTED:
            //RCLCPP_WARN(get_logger(), "The action server aborted the goal %f.", result.distance_traveled);
            break;

        case rclcpp_action::ResultCode::CANCELED:
            if (timeout_triggered_) {
                RCLCPP_WARN(get_logger(),
                    "The goal was canceled because the timeout expired.");
            } else {
                RCLCPP_WARN(get_logger(), "The goal was canceled.");
            }
            break;

        default:
            RCLCPP_ERROR(get_logger(), "Unknown action result.");
            break;
        }
    }

    void check_goal_timeout() 
    {
        if (!goal_active_ || timeout_triggered_ || !current_goal_handle_) {
            return;
        }

        const double elapsed_seconds = (now() - goal_start_time_).seconds();

        if (elapsed_seconds < goal_timeout_seconds_) {
            return;
        }

        timeout_triggered_ = true;
        goal_active_ = false;

        RCLCPP_WARN(get_logger(),
            "The robot did not reach the goal within %.1f seconds.",
            goal_timeout_seconds_);

        RCLCPP_WARN(get_logger(), "Requesting cancellation of the current goal.");

        client_->async_cancel_goal(current_goal_handle_);
    }

    const std::string action_name_ = "/action_quiz_msg";
    rclcpp_action::Client<ActionQuizMessage>::SharedPtr client_;
    bool goal_active_ = false;
    GoalHandleActionQuizMessage::SharedPtr current_goal_handle_;
    const double goal_timeout_seconds_ = 30.0;
    bool timeout_triggered_ = false;
    rclcpp::Time goal_start_time_;
    rclcpp::TimerBase::SharedPtr timeout_timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto client_ = std::make_shared<ActionQuizClient>(rclcpp::NodeOptions());

    const bool goal_sent = client_->send_goal(8.3, -2.2, -0.2);

    if (!goal_sent && rclcpp::ok()) {
        rclcpp::shutdown();
        return 1;
    }

    rclcpp::spin(client_);
    rclcpp::shutdown();

    return 0;
}