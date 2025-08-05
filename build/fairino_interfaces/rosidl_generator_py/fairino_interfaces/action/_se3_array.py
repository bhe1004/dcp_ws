# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fairino_interfaces:action/SE3Array.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SE3Array_Goal(type):
    """Metaclass of message 'SE3Array_Goal'."""

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
                'fairino_interfaces.action.SE3Array_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__goal

            from geometry_msgs.msg import PoseArray
            if PoseArray.__class__._TYPE_SUPPORT is None:
                PoseArray.__class__.__import_type_support__()

            from std_msgs.msg import Float32MultiArray
            if Float32MultiArray.__class__._TYPE_SUPPORT is None:
                Float32MultiArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_Goal(metaclass=Metaclass_SE3Array_Goal):
    """Message class 'SE3Array_Goal'."""

    __slots__ = [
        '_target_poses',
        '_durations',
        '_relative',
        '_wholebody',
    ]

    _fields_and_field_types = {
        'target_poses': 'geometry_msgs/PoseArray',
        'durations': 'std_msgs/Float32MultiArray',
        'relative': 'sequence<boolean>',
        'wholebody': 'sequence<boolean>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float32MultiArray'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('boolean')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('boolean')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PoseArray
        self.target_poses = kwargs.get('target_poses', PoseArray())
        from std_msgs.msg import Float32MultiArray
        self.durations = kwargs.get('durations', Float32MultiArray())
        self.relative = kwargs.get('relative', [])
        self.wholebody = kwargs.get('wholebody', [])

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
        if self.target_poses != other.target_poses:
            return False
        if self.durations != other.durations:
            return False
        if self.relative != other.relative:
            return False
        if self.wholebody != other.wholebody:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_poses(self):
        """Message field 'target_poses'."""
        return self._target_poses

    @target_poses.setter
    def target_poses(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseArray
            assert \
                isinstance(value, PoseArray), \
                "The 'target_poses' field must be a sub message of type 'PoseArray'"
        self._target_poses = value

    @builtins.property
    def durations(self):
        """Message field 'durations'."""
        return self._durations

    @durations.setter
    def durations(self, value):
        if __debug__:
            from std_msgs.msg import Float32MultiArray
            assert \
                isinstance(value, Float32MultiArray), \
                "The 'durations' field must be a sub message of type 'Float32MultiArray'"
        self._durations = value

    @builtins.property
    def relative(self):
        """Message field 'relative'."""
        return self._relative

    @relative.setter
    def relative(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'relative' field must be a set or sequence and each value of type 'bool'"
        self._relative = value

    @builtins.property
    def wholebody(self):
        """Message field 'wholebody'."""
        return self._wholebody

    @wholebody.setter
    def wholebody(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'wholebody' field must be a set or sequence and each value of type 'bool'"
        self._wholebody = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_Result(type):
    """Metaclass of message 'SE3Array_Result'."""

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
                'fairino_interfaces.action.SE3Array_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_Result(metaclass=Metaclass_SE3Array_Result):
    """Message class 'SE3Array_Result'."""

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


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_Feedback(type):
    """Metaclass of message 'SE3Array_Feedback'."""

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
                'fairino_interfaces.action.SE3Array_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_Feedback(metaclass=Metaclass_SE3Array_Feedback):
    """Message class 'SE3Array_Feedback'."""

    __slots__ = [
        '_percent_complete',
    ]

    _fields_and_field_types = {
        'percent_complete': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.percent_complete = kwargs.get('percent_complete', float())

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
        if self.percent_complete != other.percent_complete:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def percent_complete(self):
        """Message field 'percent_complete'."""
        return self._percent_complete

    @percent_complete.setter
    def percent_complete(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'percent_complete' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'percent_complete' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._percent_complete = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_SendGoal_Request(type):
    """Metaclass of message 'SE3Array_SendGoal_Request'."""

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
                'fairino_interfaces.action.SE3Array_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__send_goal__request

            from fairino_interfaces.action import SE3Array
            if SE3Array.Goal.__class__._TYPE_SUPPORT is None:
                SE3Array.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_SendGoal_Request(metaclass=Metaclass_SE3Array_SendGoal_Request):
    """Message class 'SE3Array_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'fairino_interfaces/SE3Array_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fairino_interfaces', 'action'], 'SE3Array_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from fairino_interfaces.action._se3_array import SE3Array_Goal
        self.goal = kwargs.get('goal', SE3Array_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from fairino_interfaces.action._se3_array import SE3Array_Goal
            assert \
                isinstance(value, SE3Array_Goal), \
                "The 'goal' field must be a sub message of type 'SE3Array_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_SendGoal_Response(type):
    """Metaclass of message 'SE3Array_SendGoal_Response'."""

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
                'fairino_interfaces.action.SE3Array_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_SendGoal_Response(metaclass=Metaclass_SE3Array_SendGoal_Response):
    """Message class 'SE3Array_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_SE3Array_SendGoal(type):
    """Metaclass of service 'SE3Array_SendGoal'."""

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
                'fairino_interfaces.action.SE3Array_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__se3_array__send_goal

            from fairino_interfaces.action import _se3_array
            if _se3_array.Metaclass_SE3Array_SendGoal_Request._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_SendGoal_Request.__import_type_support__()
            if _se3_array.Metaclass_SE3Array_SendGoal_Response._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_SendGoal_Response.__import_type_support__()


class SE3Array_SendGoal(metaclass=Metaclass_SE3Array_SendGoal):
    from fairino_interfaces.action._se3_array import SE3Array_SendGoal_Request as Request
    from fairino_interfaces.action._se3_array import SE3Array_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_GetResult_Request(type):
    """Metaclass of message 'SE3Array_GetResult_Request'."""

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
                'fairino_interfaces.action.SE3Array_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_GetResult_Request(metaclass=Metaclass_SE3Array_GetResult_Request):
    """Message class 'SE3Array_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_GetResult_Response(type):
    """Metaclass of message 'SE3Array_GetResult_Response'."""

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
                'fairino_interfaces.action.SE3Array_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__get_result__response

            from fairino_interfaces.action import SE3Array
            if SE3Array.Result.__class__._TYPE_SUPPORT is None:
                SE3Array.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_GetResult_Response(metaclass=Metaclass_SE3Array_GetResult_Response):
    """Message class 'SE3Array_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'fairino_interfaces/SE3Array_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fairino_interfaces', 'action'], 'SE3Array_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from fairino_interfaces.action._se3_array import SE3Array_Result
        self.result = kwargs.get('result', SE3Array_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from fairino_interfaces.action._se3_array import SE3Array_Result
            assert \
                isinstance(value, SE3Array_Result), \
                "The 'result' field must be a sub message of type 'SE3Array_Result'"
        self._result = value


class Metaclass_SE3Array_GetResult(type):
    """Metaclass of service 'SE3Array_GetResult'."""

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
                'fairino_interfaces.action.SE3Array_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__se3_array__get_result

            from fairino_interfaces.action import _se3_array
            if _se3_array.Metaclass_SE3Array_GetResult_Request._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_GetResult_Request.__import_type_support__()
            if _se3_array.Metaclass_SE3Array_GetResult_Response._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_GetResult_Response.__import_type_support__()


class SE3Array_GetResult(metaclass=Metaclass_SE3Array_GetResult):
    from fairino_interfaces.action._se3_array import SE3Array_GetResult_Request as Request
    from fairino_interfaces.action._se3_array import SE3Array_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SE3Array_FeedbackMessage(type):
    """Metaclass of message 'SE3Array_FeedbackMessage'."""

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
                'fairino_interfaces.action.SE3Array_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__se3_array__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__se3_array__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__se3_array__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__se3_array__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__se3_array__feedback_message

            from fairino_interfaces.action import SE3Array
            if SE3Array.Feedback.__class__._TYPE_SUPPORT is None:
                SE3Array.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SE3Array_FeedbackMessage(metaclass=Metaclass_SE3Array_FeedbackMessage):
    """Message class 'SE3Array_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'fairino_interfaces/SE3Array_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['fairino_interfaces', 'action'], 'SE3Array_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from fairino_interfaces.action._se3_array import SE3Array_Feedback
        self.feedback = kwargs.get('feedback', SE3Array_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from fairino_interfaces.action._se3_array import SE3Array_Feedback
            assert \
                isinstance(value, SE3Array_Feedback), \
                "The 'feedback' field must be a sub message of type 'SE3Array_Feedback'"
        self._feedback = value


class Metaclass_SE3Array(type):
    """Metaclass of action 'SE3Array'."""

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
                'fairino_interfaces.action.SE3Array')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__se3_array

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from fairino_interfaces.action import _se3_array
            if _se3_array.Metaclass_SE3Array_SendGoal._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_SendGoal.__import_type_support__()
            if _se3_array.Metaclass_SE3Array_GetResult._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_GetResult.__import_type_support__()
            if _se3_array.Metaclass_SE3Array_FeedbackMessage._TYPE_SUPPORT is None:
                _se3_array.Metaclass_SE3Array_FeedbackMessage.__import_type_support__()


class SE3Array(metaclass=Metaclass_SE3Array):

    # The goal message defined in the action definition.
    from fairino_interfaces.action._se3_array import SE3Array_Goal as Goal
    # The result message defined in the action definition.
    from fairino_interfaces.action._se3_array import SE3Array_Result as Result
    # The feedback message defined in the action definition.
    from fairino_interfaces.action._se3_array import SE3Array_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from fairino_interfaces.action._se3_array import SE3Array_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from fairino_interfaces.action._se3_array import SE3Array_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from fairino_interfaces.action._se3_array import SE3Array_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
