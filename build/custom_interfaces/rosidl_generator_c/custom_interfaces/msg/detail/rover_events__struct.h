// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/RoverEvents.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'EVENT_NONE'.
/**
  * Event type constants
 */
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_NONE = 0
};

/// Constant 'EVENT_OBSTACLE_DETECTED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_OBSTACLE_DETECTED = 1
};

/// Constant 'EVENT_OBSTACLE_CLEARED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_OBSTACLE_CLEARED = 2
};

/// Constant 'EVENT_PATROL_STARTED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_PATROL_STARTED = 3
};

/// Constant 'EVENT_PATROL_WAYPOINT_REACHED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_PATROL_WAYPOINT_REACHED = 4
};

/// Constant 'EVENT_PATROL_COMPLETED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_PATROL_COMPLETED = 5
};

/// Constant 'EVENT_NAV_GOAL_FAILED'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_NAV_GOAL_FAILED = 6
};

/// Constant 'EVENT_LOW_BATTERY'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_LOW_BATTERY = 7
};

/// Constant 'EVENT_EMERGENCY_STOP'.
enum
{
  custom_interfaces__msg__RoverEvents__EVENT_EMERGENCY_STOP = 8
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'description'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/RoverEvents in the package custom_interfaces.
/**
  * RoverEvents.msg — rover state/event notifications
 */
typedef struct custom_interfaces__msg__RoverEvents
{
  std_msgs__msg__Header header;
  uint8_t event_type;
  /// Human-readable detail (e.g. failure reason)
  rosidl_runtime_c__String description;
  /// Pose where the event occurred
  geometry_msgs__msg__Pose pose;
  /// Distance to obstacle in meters (valid for obstacle events)
  float obstacle_distance;
  /// Waypoint index (valid for patrol events)
  int32_t waypoint_index;
} custom_interfaces__msg__RoverEvents;

// Struct for a sequence of custom_interfaces__msg__RoverEvents.
typedef struct custom_interfaces__msg__RoverEvents__Sequence
{
  custom_interfaces__msg__RoverEvents * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__RoverEvents__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ROVER_EVENTS__STRUCT_H_
