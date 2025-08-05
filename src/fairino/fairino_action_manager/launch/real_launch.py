import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction, RegisterEventHandler, LogInfo, SetEnvironmentVariable
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution, FindExecutable, TextSubstitution
from launch_ros.actions import Node, PushRosNamespace
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    # 0. Declare Launch Arguments
    declared_args = []
    declared_args.append(DeclareLaunchArgument(
        'robot_ip',
        default_value='192.168.58.2',
        description='IP address of the Fairino robot.'
    ))
    declared_args.append(DeclareLaunchArgument(
        'robot_group',
        default_value='fr5',
        description='Robot group name, also used for namespacing relevant nodes.'
    ))
    declared_args.append(DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation (Gazebo/Mujoco) clock if true.'
    ))

    # Unified URDF path settings (used for GUI, RSP, and RobotWrapper)
    declared_args.append(DeclareLaunchArgument(
        'model_path',
        default_value='/home/home/dcp_ws/src/fairino/fairino_description',
        description="Package name containing the robot URDF."
    ))
    declared_args.append(DeclareLaunchArgument(
        'urdf_name',
        default_value='urdf/fairino5_v6.urdf',
        description="URDF filename relative to the package."
    ))

    urdf_full_path = PathJoinSubstitution([
        LaunchConfiguration('model_path'),
        LaunchConfiguration('urdf_name')
    ])

    declared_args.append(DeclareLaunchArgument(
        'urdf_full_path',
        default_value=urdf_full_path,
        description='Full path to the URDF file.'
    ))

    # 1. Get Launch Configurations
    robot_ip = LaunchConfiguration('robot_ip')
    robot_group = LaunchConfiguration('robot_group')
    use_sim_time = LaunchConfiguration('use_sim_time')
    model_path = LaunchConfiguration('model_path')
    urdf_name = LaunchConfiguration('urdf_name')
    urdf_full_path_lc = LaunchConfiguration('urdf_full_path')

    # 2. Define Node Parameters
    fairino_controller_params = [
        {'robot_ip': robot_ip},
        {'robot_group': robot_group},
        {'use_sim_time': use_sim_time},
        {'urdf_full': urdf_full_path_lc},
        {'wrapper_urdf_full_path': urdf_full_path_lc},
        {'wrapper_model_package_path': model_path}
    ]

    rsp_urdf_model_path = PathJoinSubstitution([
        model_path,
        urdf_name
    ])
    robot_description_content = ParameterValue(
        Command([FindExecutable(name='xacro'), ' ', rsp_urdf_model_path]),
        value_type=str
    )
    rsp_params = [
        {'robot_description': robot_description_content},
        {'publish_frequency': 100.0},
        {'use_sim_time': use_sim_time},
    ]

    # 3. Define Nodes
    fairino_controller_node = Node(
        package='fairino_action_manager',
        executable='fairino_action_manager_real',
        name='fairino_action_manager_real',
        output='screen',
        parameters=fairino_controller_params,
    )

    namespaced_group = GroupAction(
        actions=[
            PushRosNamespace(robot_group),
            Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                name='robot_state_publisher',
                output='screen',
                parameters=rsp_params
            )
        ]
    )

    # 4. Construct LaunchDescription
    ld = LaunchDescription()
    for arg in declared_args:
        ld.add_action(arg)
    ld.add_action(fairino_controller_node)
    ld.add_action(namespaced_group)

    return ld
