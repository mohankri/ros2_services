# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:msg/RoverEvents.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoverEvents(type):
    """Metaclass of message 'RoverEvents'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'EVENT_NONE': 0,
        'EVENT_OBSTACLE_DETECTED': 1,
        'EVENT_OBSTACLE_CLEARED': 2,
        'EVENT_PATROL_STARTED': 3,
        'EVENT_PATROL_WAYPOINT_REACHED': 4,
        'EVENT_PATROL_COMPLETED': 5,
        'EVENT_NAV_GOAL_FAILED': 6,
        'EVENT_LOW_BATTERY': 7,
        'EVENT_EMERGENCY_STOP': 8,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.msg.RoverEvents')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rover_events
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rover_events
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rover_events
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rover_events
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rover_events

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'EVENT_NONE': cls.__constants['EVENT_NONE'],
            'EVENT_OBSTACLE_DETECTED': cls.__constants['EVENT_OBSTACLE_DETECTED'],
            'EVENT_OBSTACLE_CLEARED': cls.__constants['EVENT_OBSTACLE_CLEARED'],
            'EVENT_PATROL_STARTED': cls.__constants['EVENT_PATROL_STARTED'],
            'EVENT_PATROL_WAYPOINT_REACHED': cls.__constants['EVENT_PATROL_WAYPOINT_REACHED'],
            'EVENT_PATROL_COMPLETED': cls.__constants['EVENT_PATROL_COMPLETED'],
            'EVENT_NAV_GOAL_FAILED': cls.__constants['EVENT_NAV_GOAL_FAILED'],
            'EVENT_LOW_BATTERY': cls.__constants['EVENT_LOW_BATTERY'],
            'EVENT_EMERGENCY_STOP': cls.__constants['EVENT_EMERGENCY_STOP'],
        }

    @property
    def EVENT_NONE(self):
        """Message constant 'EVENT_NONE'."""
        return Metaclass_RoverEvents.__constants['EVENT_NONE']

    @property
    def EVENT_OBSTACLE_DETECTED(self):
        """Message constant 'EVENT_OBSTACLE_DETECTED'."""
        return Metaclass_RoverEvents.__constants['EVENT_OBSTACLE_DETECTED']

    @property
    def EVENT_OBSTACLE_CLEARED(self):
        """Message constant 'EVENT_OBSTACLE_CLEARED'."""
        return Metaclass_RoverEvents.__constants['EVENT_OBSTACLE_CLEARED']

    @property
    def EVENT_PATROL_STARTED(self):
        """Message constant 'EVENT_PATROL_STARTED'."""
        return Metaclass_RoverEvents.__constants['EVENT_PATROL_STARTED']

    @property
    def EVENT_PATROL_WAYPOINT_REACHED(self):
        """Message constant 'EVENT_PATROL_WAYPOINT_REACHED'."""
        return Metaclass_RoverEvents.__constants['EVENT_PATROL_WAYPOINT_REACHED']

    @property
    def EVENT_PATROL_COMPLETED(self):
        """Message constant 'EVENT_PATROL_COMPLETED'."""
        return Metaclass_RoverEvents.__constants['EVENT_PATROL_COMPLETED']

    @property
    def EVENT_NAV_GOAL_FAILED(self):
        """Message constant 'EVENT_NAV_GOAL_FAILED'."""
        return Metaclass_RoverEvents.__constants['EVENT_NAV_GOAL_FAILED']

    @property
    def EVENT_LOW_BATTERY(self):
        """Message constant 'EVENT_LOW_BATTERY'."""
        return Metaclass_RoverEvents.__constants['EVENT_LOW_BATTERY']

    @property
    def EVENT_EMERGENCY_STOP(self):
        """Message constant 'EVENT_EMERGENCY_STOP'."""
        return Metaclass_RoverEvents.__constants['EVENT_EMERGENCY_STOP']


class RoverEvents(metaclass=Metaclass_RoverEvents):
    """
    Message class 'RoverEvents'.

    Constants:
      EVENT_NONE
      EVENT_OBSTACLE_DETECTED
      EVENT_OBSTACLE_CLEARED
      EVENT_PATROL_STARTED
      EVENT_PATROL_WAYPOINT_REACHED
      EVENT_PATROL_COMPLETED
      EVENT_NAV_GOAL_FAILED
      EVENT_LOW_BATTERY
      EVENT_EMERGENCY_STOP
    """

    __slots__ = [
        '_header',
        '_event_type',
        '_description',
        '_pose',
        '_obstacle_distance',
        '_waypoint_index',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'event_type': 'uint8',
        'description': 'string',
        'pose': 'geometry_msgs/Pose',
        'obstacle_distance': 'float',
        'waypoint_index': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.event_type = kwargs.get('event_type', int())
        self.description = kwargs.get('description', str())
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        self.obstacle_distance = kwargs.get('obstacle_distance', float())
        self.waypoint_index = kwargs.get('waypoint_index', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.event_type != other.event_type:
            return False
        if self.description != other.description:
            return False
        if self.pose != other.pose:
            return False
        if self.obstacle_distance != other.obstacle_distance:
            return False
        if self.waypoint_index != other.waypoint_index:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def event_type(self):
        """Message field 'event_type'."""
        return self._event_type

    @event_type.setter
    def event_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'event_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'event_type' field must be an unsigned integer in [0, 255]"
        self._event_type = value

    @builtins.property
    def description(self):
        """Message field 'description'."""
        return self._description

    @description.setter
    def description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'description' field must be of type 'str'"
        self._description = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @builtins.property
    def obstacle_distance(self):
        """Message field 'obstacle_distance'."""
        return self._obstacle_distance

    @obstacle_distance.setter
    def obstacle_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'obstacle_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'obstacle_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._obstacle_distance = value

    @builtins.property
    def waypoint_index(self):
        """Message field 'waypoint_index'."""
        return self._waypoint_index

    @waypoint_index.setter
    def waypoint_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'waypoint_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'waypoint_index' field must be an integer in [-2147483648, 2147483647]"
        self._waypoint_index = value
