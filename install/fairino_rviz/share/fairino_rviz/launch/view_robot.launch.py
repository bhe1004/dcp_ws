import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():

    # Isaac Sim과 연동을 위해 use_sim_time을 true로 설정
    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="true",
        description="Use simulation (Isaac Sim) clock if true",
    )
    use_sim_time = LaunchConfiguration("use_sim_time")

    # 로봇 URDF 파일 경로 설정
    # Isaac Sim의 USD 파일과 관절/링크 이름이 일치하는 URDF/XACRO 파일을 사용해야 합니다.
    urdf_path = os.path.join(
        get_package_share_directory("fairino_description"), # 사용자 패키지 이름
        "urdf",
        "fr5_with_ag95.urdf",
    )

    # URDF 파일을 robot_description 파라미터로 로드
    # 만약 파일이 .xacro 파일이라면 Command(['xacro ', urdf_path]) 를 사용하세요.
    robot_description = {
        "robot_description": ParameterValue(Command(["cat ", urdf_path]), value_type=str)
    }

    # RViz2 노드 설정
    rviz_config_file = os.path.join(
        get_package_share_directory("fairino_rviz"), # 사용자 패키지 이름
        "rviz2",
        "fr5.rviz",
    )
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            robot_description,
            {"use_sim_time": use_sim_time},
        ],
    )

    # Static TF 발행 노드 설정 (world -> robot base)
    # Isaac Sim의 /robot Xform이 월드 원점에 있으므로 (0,0,0) 변환이 맞습니다.
    # 만약 Isaac Sim에서 로봇의 위치를 바꾸면 이 값도 수정해야 합니다.
    # URDF의 베이스 링크 이름이 'base_link'가 맞는지 확인해야 합니다.
    world_to_base_tf_node = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher_world_to_base",
        output="log",
        arguments=[
            # x, y, z, yaw, pitch, roll
            "0.0", "0.0", "0.0", "0.0", "0.0", "0.0",
            # frame_id, child_frame_id
            "world", "base_link" 
        ],
        parameters=[{"use_sim_time": use_sim_time}],
    )

    # Robot State Publisher 노드 설정
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="screen",
        parameters=[robot_description, {"use_sim_time": use_sim_time}],
        # =================================================================
        # === 핵심 수정 사항: Joint State 토픽 이름을 리매핑합니다. ===
        # Isaac Sim의 /isaac_joint_states 토픽을 /joint_states 로 변경하여
        # robot_state_publisher가 구독할 수 있도록 합니다.
        # =================================================================
        remappings=[
            ("/joint_states", "/isaac_joint_states")
        ]
    )

    return LaunchDescription(
        [
            use_sim_time_arg,
            world_to_base_tf_node,
            robot_state_publisher_node,
            rviz_node, # RViz는 다른 노드들이 TF를 발행한 후에 실행되는 것이 좋습니다.
        ]
    )