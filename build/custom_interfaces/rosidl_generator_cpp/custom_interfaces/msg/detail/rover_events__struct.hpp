// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/RoverEvents.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__RoverEvents __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__RoverEvents __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverEvents_
{
  using Type = RoverEvents_<ContainerAllocator>;

  explicit RoverEvents_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event_type = 0;
      this->description = "";
      this->obstacle_distance = 0.0f;
      this->waypoint_index = 0l;
    }
  }

  explicit RoverEvents_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    description(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->event_type = 0;
      this->description = "";
      this->obstacle_distance = 0.0f;
      this->waypoint_index = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _event_type_type =
    uint8_t;
  _event_type_type event_type;
  using _description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _description_type description;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _obstacle_distance_type =
    float;
  _obstacle_distance_type obstacle_distance;
  using _waypoint_index_type =
    int32_t;
  _waypoint_index_type waypoint_index;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__event_type(
    const uint8_t & _arg)
  {
    this->event_type = _arg;
    return *this;
  }
  Type & set__description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->description = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__obstacle_distance(
    const float & _arg)
  {
    this->obstacle_distance = _arg;
    return *this;
  }
  Type & set__waypoint_index(
    const int32_t & _arg)
  {
    this->waypoint_index = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t EVENT_NONE =
    0u;
  static constexpr uint8_t EVENT_OBSTACLE_DETECTED =
    1u;
  static constexpr uint8_t EVENT_OBSTACLE_CLEARED =
    2u;
  static constexpr uint8_t EVENT_PATROL_STARTED =
    3u;
  static constexpr uint8_t EVENT_PATROL_WAYPOINT_REACHED =
    4u;
  static constexpr uint8_t EVENT_PATROL_COMPLETED =
    5u;
  static constexpr uint8_t EVENT_NAV_GOAL_FAILED =
    6u;
  static constexpr uint8_t EVENT_LOW_BATTERY =
    7u;
  static constexpr uint8_t EVENT_EMERGENCY_STOP =
    8u;

  // pointer types
  using RawPtr =
    custom_interfaces::msg::RoverEvents_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::RoverEvents_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::RoverEvents_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::RoverEvents_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__RoverEvents
    std::shared_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__RoverEvents
    std::shared_ptr<custom_interfaces::msg::RoverEvents_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverEvents_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->event_type != other.event_type) {
      return false;
    }
    if (this->description != other.description) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->obstacle_distance != other.obstacle_distance) {
      return false;
    }
    if (this->waypoint_index != other.waypoint_index) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverEvents_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverEvents_

// alias to use template instance with default allocator
using RoverEvents =
  custom_interfaces::msg::RoverEvents_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_OBSTACLE_DETECTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_OBSTACLE_CLEARED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_PATROL_STARTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_PATROL_WAYPOINT_REACHED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_PATROL_COMPLETED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_NAV_GOAL_FAILED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_LOW_BATTERY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverEvents_<ContainerAllocator>::EVENT_EMERGENCY_STOP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_HPP_
