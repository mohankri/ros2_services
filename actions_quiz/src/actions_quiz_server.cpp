#include <chrono>
#include <functional>
#include <future>
#include <memory>
#include <string>
#include <thread>

#include "action_msgs/msg/goal_status.hpp"
#include "actions_quiz_msg/action/action_quiz_message.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

class ActionQuizServer : public rclcpp::Node {
public:

    using ActionQuizMessage = actions_quiz_msg::action::ActionQuizMessage;
    using GoalHandleActionQuizMessage = rclcpp_action::ServerGoalHandle<ActionQuizMessage>;
    using NavigateToPose = nav2_msgs::action::NavigateToPose;

    explicit ActionQuizServer(const rclcpp::NodeOptions &options = rclcpp::NodeOptions())
        : Node("ActionQuizServer", options)
    {
        using namespace std::placeholders;

        server_ = rclcpp_action::create_server<ActionQuizMessage>(
            this, 
            action_name_,
            std::bind(&ActionQuizServer::handle_goal, this, _1, _2),
            std::bind(&ActionQuizServer::handle_cancel, this, _1),
            std::bind(&ActionQuizServer::handle_accepted, this, _1));

        initial_pose_publisher_ =
            create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
            "/initialpose", 10);

        odom_sub_ = 
            create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10,
            std::bind(&ActionQuizServer::odom_callback, this, _1));

        nav_to_pose_client_ =
            rclcpp_action::create_client<NavigateToPose>(this, "/navigate_to_pose");

        wait_for_localization();

        set_initial_pose(0.0, 0.0, 0.0);
    }
private:
    
    bool topic_exists(const std::string &topic_name) {
        const auto topics = get_topic_names_and_types();

        for (const auto &topic : topics) {
            if (topic.first == topic_name) {
                return true;
            }
        }
        return false;
    }

    void set_initial_pose(double x, double y, double yaw) {
        geometry_msgs::msg::PoseWithCovarianceStamped initial_pose;

        initial_pose.header.frame_id = "map";
        initial_pose.header.stamp = get_clock()->now();

        initial_pose.pose.pose.position.x = x;
        initial_pose.pose.pose.position.y = y;

        tf2::Quaternion q;
        q.setRPY(0.0, 0.0, yaw);

        initial_pose.pose.pose.orientation = tf2::toMsg(q);

        for (int i = 0; i < 10; ++i) {
            initial_pose.header.stamp = get_clock()->now();
            initial_pose_publisher_->publish(initial_pose);

            RCLCPP_INFO(get_logger(), "Publishing initial pose (%d/10)", i + 1);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        RCLCPP_INFO(get_logger(), "Initial pose set to x: %.2f, y: %.2f, yaw: %.2f",
            x, y, yaw);
    }

    void wait_for_localization() {
        RCLCPP_INFO(get_logger(), "Waiting for localization to be active...");

        while (count_subscribers("/initialpose") == 0) {
            RCLCPP_INFO(get_logger(), "Waiting for subscribers to /initialpose...");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        while (!topic_exists("/amcl_pose")) {
            RCLCPP_INFO(get_logger(), "Waiting for /amcl_pose topic...");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        RCLCPP_INFO(get_logger(), "Localization is active.");
  }

    rclcpp_action::GoalResponse
    handle_goal(const rclcpp_action::GoalUUID &uuid,
              std::shared_ptr<const ActionQuizMessage::Goal> goal) {
        (void)uuid;

        RCLCPP_INFO(get_logger(),
                "Received goal request: "
                "x=%.2f, y=%.2f, yaw=%.2f",
                goal->x, goal->y, goal->yaw);

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse
    handle_cancel(const std::shared_ptr<GoalHandleActionQuizMessage> goal_handle) {
        (void)goal_handle;

        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal.");

        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleActionQuizMessage> goal_handle) {
        using namespace std::placeholders;

        std::thread{std::bind(&ActionQuizServer::execute, this, _1), goal_handle}
            .detach();
    }

    void execute(const std::shared_ptr<GoalHandleActionQuizMessage> goal_handle) {
        RCLCPP_INFO(get_logger(), "Executing goal.");
        const auto goal = goal_handle->get_goal();

        auto feedback = std::make_shared<ActionQuizMessage::Feedback>();

        auto result = std::make_shared<ActionQuizMessage::Result>();

        auto timer = create_wall_timer(
            std::chrono::milliseconds(100),  // 10 Hz
                [this, goal_handle, feedback]() {
                    const auto goal = goal_handle->get_goal();
                    feedback->distance_left = compute_distance_left(goal);
                    goal_handle->publish_feedback(feedback);
        });
        //feedback->distance_left = compute_distance_left(goal);
        //goal_handle->publish_feedback(feedback);

        const bool navigation_result =
            send_navigation_goal(goal->x, goal->y, goal->yaw);

        if (navigation_result) {
            RCLCPP_INFO(get_logger(), "Goal reached successfully.");
            result->distance_traveled = total_distance_traveled_;
            result->success = true;
            goal_handle->succeed(result);
        } else {
            RCLCPP_WARN(get_logger(), "Failed to reach goal.");
            result->success = false;
            result->distance_traveled = total_distance_traveled_;
            goal_handle->abort(result);
        }

        timer->cancel();
    }

    bool send_navigation_goal(double x, double y, double yaw) {
        NavigateToPose::Goal goal_msg;
        
        goal_msg.pose.pose.position.x = x;
        goal_msg.pose.pose.position.y = y;

        tf2::Quaternion q;
        q.setRPY(0.0, 0.0, yaw);

        goal_msg.pose.pose.orientation = tf2::toMsg(q);

        goal_msg.pose.header.frame_id = "map";
        goal_msg.pose.header.stamp = get_clock()->now();

        RCLCPP_INFO(get_logger(), "Waiting for NavigateToPose action server...");

        if (!nav_to_pose_client_->wait_for_action_server(
            std::chrono::seconds(10))) {
            RCLCPP_ERROR(get_logger(),
                   "NavigateToPose action server is not available.");
            return false;
        }

        RCLCPP_INFO(get_logger(), "Sending navigation goal: "
            "x=%.2f, y=%.2f, yaw=%.2f",
            x, y, yaw);

        auto send_goal_future = nav_to_pose_client_->async_send_goal(goal_msg);

        if (send_goal_future.wait_for(std::chrono::seconds(10)) !=
            std::future_status::ready) {
            RCLCPP_ERROR(get_logger(), "Timed out while sending navigation goal.");

            return false;
        }

        auto nav_goal_handle = send_goal_future.get();

        if (!nav_goal_handle) {
            RCLCPP_WARN(get_logger(), "Navigation goal was rejected.");
            return false;
        }

        RCLCPP_INFO(get_logger(), "Navigation goal accepted.");

        auto result_future = nav_to_pose_client_->async_get_result(nav_goal_handle);

        result_future.wait();

        const auto nav_result = result_future.get();

        if (nav_result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(get_logger(), "Navigation succeeded.");
            return true;
        }

        RCLCPP_WARN(get_logger(), "Navigation failed with result code: %d",
            static_cast<int>(nav_result.code));

        return false;
    }

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        current_x_ = msg->pose.pose.position.x;
        current_y_ = msg->pose.pose.position.y;

        if (first_odom_) {
            last_x_ = current_x_;
            last_y_ = current_y_;
            first_odom_ = false;
            return;
        }

        double dx = current_x_ - last_x_;
        double dy = current_y_ - last_y_;
        total_distance_traveled_ += std::sqrt(dx * dx + dy * dy);

        last_x_ = current_x_;
        last_y_ = current_y_;
    }

    double compute_distance_left(auto &goal) {
       // RCLCPP_INFO(get_logger(), "Compute distance left : "
        //        "x=%.2f, y=%.2f, yaw=%.2f",
        //        goal->x, goal->y, goal->yaw);
        return std::sqrt(std::pow(goal->x - current_x_, 2) +
            std::pow(goal->y - current_y_, 2));
    }

    const std::string action_name_ = "/action_quiz_msg";
    rclcpp_action::Server<ActionQuizMessage>::SharedPtr server_;
    rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
        initial_pose_publisher_;
    rclcpp_action::Client<NavigateToPose>::SharedPtr nav_to_pose_client_;
    bool first_odom_ = true;
    double total_distance_traveled_ = 0.0;
    double current_x_ = 0.0, current_y_ = 0.0;
    double last_x_ = 0.0, last_y_ = 0.0;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto server_ = std::make_shared<ActionQuizServer>();

    rclcpp::spin(server_);
    rclcpp::shutdown();

    return 0;
}