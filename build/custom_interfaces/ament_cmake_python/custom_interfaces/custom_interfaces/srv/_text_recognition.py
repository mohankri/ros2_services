# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:srv/TextRecognition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TextRecognition_Request(type):
    """Metaclass of message 'TextRecognition_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'custom_interfaces.srv.TextRecognition_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__text_recognition__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__text_recognition__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__text_recognition__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__text_recognition__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__text_recognition__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TextRecognition_Request(metaclass=Metaclass_TextRecognition_Request):
    """Message class 'TextRecognition_Request'."""

    __slots__ = [
        '_label',
    ]

    _fields_and_field_types = {
        'label': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.label = kwargs.get('label', str())

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
        if self.label != other.label:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def label(self):
        """Message field 'label'."""
        return self._label

    @label.setter
    def label(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'label' field must be of type 'str'"
        self._label = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TextRecognition_Response(type):
    """Metaclass of message 'TextRecognition_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'custom_interfaces.srv.TextRecognition_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__text_recognition__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__text_recognition__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__text_recognition__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__text_recognition__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__text_recognition__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TextRecognition_Response(metaclass=Metaclass_TextRecognition_Response):
    """Message class 'TextRecognition_Response'."""

    __slots__ = [
        '_success',
        '_start_x',
        '_start_y',
        '_end_x',
        '_end_y',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'start_x': 'int32',
        'start_y': 'int32',
        'end_x': 'int32',
        'end_y': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.start_x = kwargs.get('start_x', int())
        self.start_y = kwargs.get('start_y', int())
        self.end_x = kwargs.get('end_x', int())
        self.end_y = kwargs.get('end_y', int())

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
        if self.success != other.success:
            return False
        if self.start_x != other.start_x:
            return False
        if self.start_y != other.start_y:
            return False
        if self.end_x != other.end_x:
            return False
        if self.end_y != other.end_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def start_x(self):
        """Message field 'start_x'."""
        return self._start_x

    @start_x.setter
    def start_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'start_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'start_x' field must be an integer in [-2147483648, 2147483647]"
        self._start_x = value

    @builtins.property
    def start_y(self):
        """Message field 'start_y'."""
        return self._start_y

    @start_y.setter
    def start_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'start_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'start_y' field must be an integer in [-2147483648, 2147483647]"
        self._start_y = value

    @builtins.property
    def end_x(self):
        """Message field 'end_x'."""
        return self._end_x

    @end_x.setter
    def end_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'end_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'end_x' field must be an integer in [-2147483648, 2147483647]"
        self._end_x = value

    @builtins.property
    def end_y(self):
        """Message field 'end_y'."""
        return self._end_y

    @end_y.setter
    def end_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'end_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'end_y' field must be an integer in [-2147483648, 2147483647]"
        self._end_y = value


class Metaclass_TextRecognition(type):
    """Metaclass of service 'TextRecognition'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.TextRecognition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__text_recognition

            from custom_interfaces.srv import _text_recognition
            if _text_recognition.Metaclass_TextRecognition_Request._TYPE_SUPPORT is None:
                _text_recognition.Metaclass_TextRecognition_Request.__import_type_support__()
            if _text_recognition.Metaclass_TextRecognition_Response._TYPE_SUPPORT is None:
                _text_recognition.Metaclass_TextRecognition_Response.__import_type_support__()


class TextRecognition(metaclass=Metaclass_TextRecognition):
    from custom_interfaces.srv._text_recognition import TextRecognition_Request as Request
    from custom_interfaces.srv._text_recognition import TextRecognition_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
