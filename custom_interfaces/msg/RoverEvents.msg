# RoverEvents.msg — rover state/event notifications

# Event type constants
uint8 EVENT_NONE=0
uint8 EVENT_OBSTACLE_DETECTED=1
uint8 EVENT_OBSTACLE_CLEARED=2
uint8 EVENT_PATROL_STARTED=3
uint8 EVENT_PATROL_WAYPOINT_REACHED=4
uint8 EVENT_PATROL_COMPLETED=5
uint8 EVENT_NAV_GOAL_FAILED=6
uint8 EVENT_LOW_BATTERY=7
uint8 EVENT_EMERGENCY_STOP=8

std_msgs/Header header

uint8 event_type

# Human-readable detail (e.g. failure reason)
string description

# Pose where the event occurred
geometry_msgs/Pose pose

# Distance to obstacle in meters (valid for obstacle events)
float32 obstacle_distance

# Waypoint index (valid for patrol events)
int32 waypoint_index