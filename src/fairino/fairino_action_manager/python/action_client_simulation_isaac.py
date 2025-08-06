#!/usr/bin/env python3
# control_suite_shell.py

import cmd
import sys
import numpy as np

import rclpy
from rclpy.action import ActionClient
from rclpy.client import Client
from action_msgs.msg import GoalStatus

# 메시지 / 액션 타입 ---------------------------
from fairino_interfaces.action import (
    JointPosture,
    SE3,
    QR,
    SE3Array,
    Gripper,
)
from fairino_interfaces.srv import (
    Pick,
    Place,
)
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Pose, PoseStamped, PoseArray
from std_msgs.msg import Float32MultiArray, Bool
# --------------------------------------------


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


class ControlSuiteShell(cmd.Cmd):
    intro = (
        bcolors.OKBLUE
        + "Welcome to the control suite shell.\nType help or ? to list commands.\n"
        + bcolors.ENDC
    )
    prompt = "(csuite) "

    def __init__(self):
        super().__init__()
        rclpy.init(args=None)
        self.node = rclpy.create_node("actions_client_simulation_isaac")

        # Action Clients
        self.joint_ctrl_client = ActionClient(
            self.node,
            JointPosture,
            "/fairino_action_manager/joint_posture_control",
        )
        self.se3_ctrl_client = ActionClient(
            self.node,
            SE3,
            "/fairino_action_manager/se3_control",
        )
        self.gripper_ctrl_client = ActionClient(
            self.node,
            Gripper,
            "/fairino_action_manager/gripper_control",
        )
        self.qr_ctrl_client = ActionClient(
            self.node,
            QR,
            "/fairino_action_manager/qr_control",
        )

        # Service Clients
        self.pick_ctrl_client = self.node.create_client(Pick, "/task_manager/pick")
        self.place_ctrl_client = self.node.create_client(Place, "/task_manager/place")

        # Wait for Servers
        for ac in [
            self.joint_ctrl_client,
            self.se3_ctrl_client,
            self.gripper_ctrl_client,
            self.qr_ctrl_client,
        ]:
            ac.wait_for_server()

        while not self.pick_ctrl_client.wait_for_service(timeout_sec=1.0):
            self.node.get_logger().info('Pick service not available, waiting again...')
        while not self.place_ctrl_client.wait_for_service(timeout_sec=1.0):
            self.node.get_logger().info('Place service not available, waiting again...')
        
        self.node.get_logger().info('All action and service servers are ready.')
        

    def do_home(self, arg):
        """Go to the home position using joint-posture control"""
        goal = JointPosture.Goal()
        goal.duration = 3.0
        goal.target_joints = JointState()

        goal.target_joints.position = [
            np.deg2rad(0.0),
            np.deg2rad(-70.0),
            np.deg2rad(-110.0),
            np.deg2rad(-90.0),
            np.deg2rad(90.0),
            np.deg2rad(0.0),
        ]
        if self._send_goal_and_wait(self.joint_ctrl_client, goal):
            print("action succeed")
        else:
            print("action failed")


    def do_joint(self, arg):
        """Go to the home position using joint-posture control"""
        goal = JointPosture.Goal()
        goal.duration = 3.0
        goal.target_joints = JointState()

        if arg.strip() == "0":
            goal.target_joints.position = [
                np.deg2rad(90.0),
                np.deg2rad(-110.0),
                np.deg2rad(-70.0),
                np.deg2rad(-90.0),
                np.deg2rad(90.0),
                np.deg2rad(-90.0),
            ]
        elif arg.strip() == "1":
            goal.target_joints.position = [
                np.deg2rad(0.0),
                np.deg2rad(-90.0),
                np.deg2rad(-70.0),
                np.deg2rad(-90.0),
                np.deg2rad(90.0),
                np.deg2rad(-120.0),
            ]
        if self._send_goal_and_wait(self.joint_ctrl_client, goal):
            print("action succeed")
        else:
            print("action failed")


    def do_se3(self, arg):
        """SE3 Ctrl - only arm (arg=0) or whole-body"""
        goal = SE3.Goal()
        goal.duration = 7.0
        goal.target_pose = Pose()

        if arg.strip() == "0":
            # ARM ONLY
            print("Absolute Pose Control")
            goal.target_pose.position.x = 0.0
            goal.target_pose.position.y = 0.4
            goal.target_pose.position.z = 0.5
            goal.target_pose.orientation.x = 0.5
            goal.target_pose.orientation.y = -0.5
            goal.target_pose.orientation.z = 0.5
            goal.target_pose.orientation.w = -0.5
            # goal.relative = True
        elif arg.strip() == "1":
            # ARM ONLY
            print("Absolute Pose Control")
            goal.target_pose.position.x = -0.1
            goal.target_pose.position.y = 0.4
            goal.target_pose.position.z = 0.5
            goal.target_pose.orientation.x = 0.0
            goal.target_pose.orientation.y = 1.0
            goal.target_pose.orientation.z = 0.0
            goal.target_pose.orientation.w = 0.0
            # goal.relative = True
        elif arg.strip() == "2":
            # ARM ONLY
            print("Absolute Pose Control")
            goal.target_pose.position.x = -0.2
            goal.target_pose.position.y = 0.4
            goal.target_pose.position.z = 0.6
            goal.target_pose.orientation.x = 0.0
            goal.target_pose.orientation.y = 1.0
            goal.target_pose.orientation.z = 0.0
            goal.target_pose.orientation.w = 0.0
            # goal.relative = True
        elif arg.strip() == "3":
            # ARM ONLY
            print("Absolute Pose Control")
            goal.target_pose.position.x = -0.2
            goal.target_pose.position.y = 0.4
            goal.target_pose.position.z = 0.4
            goal.target_pose.orientation.x = 0.0
            goal.target_pose.orientation.y = 1.0
            goal.target_pose.orientation.z = 0.0
            goal.target_pose.orientation.w = 0.0
            # goal.relative = True
        else:
            # WHOLE-BODY
            print("Relative Pose Control")
            goal.target_pose.position.x = -0.1
            goal.target_pose.position.y = 0.1
            goal.target_pose.position.z = 0.0
            goal.target_pose.orientation.x = 0.0
            goal.target_pose.orientation.y = 0.0
            goal.target_pose.orientation.z = 0.0
            goal.target_pose.orientation.w = 1.0
            goal.relative = True

        if self._send_goal_and_wait(self.se3_ctrl_client, goal):
            print("action succeed")
        else:
            print("action failed")


    def do_grasp(self, arg):
        """Gripper open / close   (arg=0 => close)"""
        goal = Gripper.Goal()
        goal.speed_percentage = 70
        goal.torque_percentage = 50
        goal.position_percentage = 0

        # 0: Open -> False
        # 1: Close -> True
        if arg.strip() == "0":
            goal.grasp = False

        elif arg.strip() == "1":
            goal.grasp = True
            
        print("Close" if goal.grasp else "Open")

        if self._send_goal_and_wait(self.gripper_ctrl_client, goal):
            print("action succeed")
        else:
            print("action failed")

    def do_qr(self, arg):
        """QR Ctrl"""
        goal = QR.Goal()
        goal.duration = 10.0

        # goal.target_pose.position.x = 0.0
        # goal.target_pose.position.y = 0.4
        # goal.target_pose.position.z = 0.5
        # goal.target_pose.orientation.x = 0.5
        # goal.target_pose.orientation.y = -0.5
        # goal.target_pose.orientation.z = 0.5
        # goal.target_pose.orientation.w = -0.5
        
        goal.qr_pose = Pose()
        goal.qr_pose.position.x = 0.2
        goal.qr_pose.position.y = -0.3
        goal.qr_pose.position.z = 0.4

        goal.qr_pose.orientation.x = 0.5
        goal.qr_pose.orientation.y = -0.5
        goal.qr_pose.orientation.z = 0.5
        goal.qr_pose.orientation.w = -0.5

        goal.target_pose = Pose()
        goal.target_pose.position.x = 0.15
        goal.target_pose.position.y = 0.0
        goal.target_pose.position.z = 0.2

        goal.target_pose.orientation.x = 0.0
        goal.target_pose.orientation.y = 0.0
        goal.target_pose.orientation.z = 0.0
        goal.target_pose.orientation.w = 1.0

        if self._send_goal_and_wait(self.qr_ctrl_client, goal):
            print("action succeed")
        else:
            print("action failed")


    def do_pick(self, arg):
        """Pick an object using the task manager"""
        request = Pick.Request()
        request.duration = 5.0

        if arg.strip() == "0":
            # request.target_pose.position.x = 0.0
            # request.target_pose.position.y = 0.4
            request.target_pose.position.x = 0.5
            request.target_pose.position.y = -0.15
            request.target_pose.position.z = 0.2
            request.target_pose.orientation.x = 0.5
            request.target_pose.orientation.y = -0.5
            request.target_pose.orientation.z = 0.5
            request.target_pose.orientation.w = -0.5
            # request.target_pose.orientation.x = 0.5
            # request.target_pose.orientation.y = -0.5
            # request.target_pose.orientation.z = 0.5
            # request.target_pose.orientation.w = -0.5
        else:
            request.target_pose.position.x = 0.2
            request.target_pose.position.y = 0.4
            request.target_pose.position.z = 0.5
            request.target_pose.orientation.x = 0.0
            request.target_pose.orientation.y = 1.0
            request.target_pose.orientation.z = 0.0
            request.target_pose.orientation.w = 0.0

        response = self._call_service_and_wait(self.pick_ctrl_client, request)

        if response:
            print(f"Service call successful, result: {response.is_completed}")
        else:
            print("Service call failed")

    def do_place(self, arg):
        """Pick an object using the task manager"""
        request = Place.Request()
        request.duration = 5.0

        if arg.strip() == "0":
            request.target_pose.position.x = 0.5
            request.target_pose.position.y = 0.45
            request.target_pose.position.z = 0.45
            request.target_pose.orientation.x = 0.5
            request.target_pose.orientation.y = -0.5
            request.target_pose.orientation.z = 0.5
            request.target_pose.orientation.w = -0.5
        else:
            request.target_pose.position.x = 0.4
            request.target_pose.position.y = 0.4
            request.target_pose.position.z = 0.5
            request.target_pose.orientation.x = 0.0
            request.target_pose.orientation.y = 1.0
            request.target_pose.orientation.z = 0.0
            request.target_pose.orientation.w = 0.0

        response = self._call_service_and_wait(self.place_ctrl_client, request)

        if response:
            print(f"Service call successful, result: {response.is_completed}")
        else:
            print("Service call failed")

    # def do_continous(self, arg):
    #     """Two-step SE3 array control example"""
    #     goal = SE3Array.Goal()

    #     # step 1
    #     goal.relative.append(True)
    #     pose1 = Pose()
    #     pose1.position.z = -0.2
    #     pose1.orientation.w = 1.0
    #     goal.target_poses.poses.append(pose1)
    #     goal.durations.data.append(2.0)

    #     # step 2
    #     goal.relative.append(True)
    #     pose2 = Pose()
    #     pose2.position.x = 0.2
    #     pose2.position.y = -0.2
    #     pose2.orientation.w = 1.0
    #     goal.target_poses.poses.append(pose2)
    #     goal.durations.data.append(3.0)

    #     if self._send_goal_and_wait(self.se3_array_ctrl_client, goal):
    #         print("action succeed")
    #     else:
    #         print("action failed")


    def do_quit(self, arg):
        """Quit shell"""
        print("Shutting down ROS 2 …")
        self.node.destroy_node()
        rclpy.shutdown()
        return True

    # 편의상 EOF (^D) 도 quit 으로 연결
    def do_EOF(self, arg):
        return self.do_quit(arg)
    
    ##################################
    

    # Helper Functions
    def _send_goal_and_wait(self, client: ActionClient, goal_msg) -> bool:
        send_goal_future = client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self.node, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            print("Goal rejected")
            return False

        get_result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self.node, get_result_future)
        result_status = get_result_future.result().status

        return result_status == GoalStatus.STATUS_SUCCEEDED
    
    # 서비스 호출 헬퍼 함수의 이름을 _call_service_and_wait로 변경하여 명확화
    def _call_service_and_wait(self, client: Client, request):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self.node, future)
        response = future.result()
        if response is not None:
            return response
        else:
            print(f"Exception while calling service: {future.exception()}")
            return None


if __name__ == "__main__":
    try:
        ControlSuiteShell().cmdloop()
    except KeyboardInterrupt:
        print("\nInterrupt - shutting down …")
        rclpy.shutdown()
        sys.exit(0)