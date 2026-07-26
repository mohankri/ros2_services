// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/RoverEvents.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/rover_events__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_RoverEvents_waypoint_index
{
public:
  explicit Init_RoverEvents_waypoint_index(::custom_interfaces::msg::RoverEvents & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::RoverEvents waypoint_index(::custom_interfaces::msg::RoverEvents::_waypoint_index_type arg)
  {
    msg_.waypoint_index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

class Init_RoverEvents_obstacle_distance
{
public:
  explicit Init_RoverEvents_obstacle_distance(::custom_interfaces::msg::RoverEvents & msg)
  : msg_(msg)
  {}
  Init_RoverEvents_waypoint_index obstacle_distance(::custom_interfaces::msg::RoverEvents::_obstacle_distance_type arg)
  {
    msg_.obstacle_distance = std::move(arg);
    return Init_RoverEvents_waypoint_index(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

class Init_RoverEvents_pose
{
public:
  explicit Init_RoverEvents_pose(::custom_interfaces::msg::RoverEvents & msg)
  : msg_(msg)
  {}
  Init_RoverEvents_obstacle_distance pose(::custom_interfaces::msg::RoverEvents::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_RoverEvents_obstacle_distance(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

class Init_RoverEvents_description
{
public:
  explicit Init_RoverEvents_description(::custom_interfaces::msg::RoverEvents & msg)
  : msg_(msg)
  {}
  Init_RoverEvents_pose description(::custom_interfaces::msg::RoverEvents::_description_type arg)
  {
    msg_.description = std::move(arg);
    return Init_RoverEvents_pose(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

class Init_RoverEvents_event_type
{
public:
  explicit Init_RoverEvents_event_type(::custom_interfaces::msg::RoverEvents & msg)
  : msg_(msg)
  {}
  Init_RoverEvents_description event_type(::custom_interfaces::msg::RoverEvents::_event_type_type arg)
  {
    msg_.event_type = std::move(arg);
    return Init_RoverEvents_description(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

class Init_RoverEvents_header
{
public:
  Init_RoverEvents_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverEvents_event_type header(::custom_interfaces::msg::RoverEvents::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RoverEvents_event_type(msg_);
  }

private:
  ::custom_interfaces::msg::RoverEvents msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::RoverEvents>()
{
  return custom_interfaces::msg::builder::Init_RoverEvents_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__BUILDER_HPP_
