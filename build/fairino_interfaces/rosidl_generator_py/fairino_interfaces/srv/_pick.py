# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fairino_interfaces:srv/Pick.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Pick_Request(type):
    """Metaclass of message 'Pick_Request'."""

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
            module = import_type_support('fairino_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fairino_interfaces.srv.Pick_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__pick__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__pick__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__pick__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__pick__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__pick__request

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Pick_Request(metaclass=Metaclass_Pick_Request):
    """Message class 'Pick_Request'."""

    __slots__ = [
        '_client_id',
        '_target_pose',
        '_duration',
    ]

    _fields_and_field_types = {
        'client_id': 'string',
        'target_pose': 'geometry_msgs/Pose',
        'duration': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.client_id = kwargs.get('client_id', str())
        from geometry_msgs.msg import Pose
        self.target_pose = kwargs.get('target_pose', Pose())
        self.duration = kwargs.get('duration', float())

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
        if self.client_id != other.client_id:
            return False
        if self.target_pose != other.target_pose:
            return False
        if self.duration != other.duration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def client_id(self):
        """Message field 'client_id'."""
        return self._client_id

    @client_id.setter
    def client_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'client_id' field must be of type 'str'"
        self._client_id = value

    @builtins.property
    def target_pose(self):
        """Message field 'target_pose'."""
        return self._target_pose

    @target_pose.setter
    def target_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'target_pose' field must be a sub message of type 'Pose'"
        self._target_pose = value

    @builtins.property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'duration' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'duration' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._duration = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Pick_Response(type):
    """Metaclass of message 'Pick_Response'."""

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
            module = import_type_support('fairino_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fairino_interfaces.srv.Pick_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__pick__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__pick__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__pick__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__pick__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__pick__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Pick_Response(metaclass=Metaclass_Pick_Response):
    """Message class 'Pick_Response'."""

    __slots__ = [
        '_is_completed',
    ]

    _fields_and_field_types = {
        'is_completed': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_completed = kwargs.get('is_completed', bool())

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
        if self.is_completed != other.is_completed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_completed(self):
        """Message field 'is_completed'."""
        return self._is_completed

    @is_completed.setter
    def is_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_completed' field must be of type 'bool'"
        self._is_completed = value


class Metaclass_Pick(type):
    """Metaclass of service 'Pick'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fairino_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fairino_interfaces.srv.Pick')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__pick

            from fairino_interfaces.srv import _pick
            if _pick.Metaclass_Pick_Request._TYPE_SUPPORT is None:
                _pick.Metaclass_Pick_Request.__import_type_support__()
            if _pick.Metaclass_Pick_Response._TYPE_SUPPORT is None:
                _pick.Metaclass_Pick_Response.__import_type_support__()


class Pick(metaclass=Metaclass_Pick):
    from fairino_interfaces.srv._pick import Pick_Request as Request
    from fairino_interfaces.srv._pick import Pick_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
