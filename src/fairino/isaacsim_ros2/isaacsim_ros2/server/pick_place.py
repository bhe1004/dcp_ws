# Copyright (c) 2021-2024, NVIDIA CORPORATION. All rights reserved.
#
# NVIDIA CORPORATION and its licensors retain all intellectual property
# and proprietary rights in and to this software, related documentation
# and any modifications thereto. Any use, reproduction, disclosure or
# distribution of this software and related documentation without an express
# license agreement from NVIDIA CORPORATION is strictly prohibited.
#
import numpy as np
import sys
import threading
import queue

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose

sys.path.append("/home/home/fr5_ws/install/isaacsim_interfaces/lib/python3.10/site-packages")

from isaacsim_interfaces.srv import SetTargetPose

from isaacsim import SimulationApp

FR5_STAGE_PATH = "/World/fairino5_v6_robot"
FR5_USD_PATH = "/home/home/fr5_ws/src/isaacsim_ros2/isaacsim_ros2/robot/fr5_with_ag95/fr5_with_ag95.usd"
BACKGROUND_STAGE_PATH = "/background"
BACKGROUND_USD_PATH = "/Isaac/Environments/Simple_Room/simple_room.usd"

CONFIG = {"renderer": "RaytracedLighting", "headless": False}

simulation_app = SimulationApp(CONFIG)

import carb
import omni.graph.core as og
import usdrt.Sdf
from isaacsim.core.api import SimulationContext
from isaacsim.core.utils import extensions, prims, rotations, stage, viewports
from isaacsim.storage.native import get_assets_root_path
from pxr import Gf
from isaacsim.core.api import World

sys.path.append("/home/home/fr5_ws/src/isaacsim_ros2/isaacsim_ros2")
from controller.pick_place_controller import PickPlaceController
from tasks.pick_place import PickPlace
from ros2_bridge.ros2_bridge import start_ros2_bridge
from isaacsim.core.utils.prims import get_prim_at_path

# enable ROS2 bridge extension
extensions.enable_extension("isaacsim.ros2.bridge")

simulation_app.update()

# Locate Isaac Sim assets folder to load environment and robot stages
assets_root_path = get_assets_root_path()
if assets_root_path is None:
    carb.log_error("Could not find Isaac Sim assets folder")
    simulation_app.close()
    sys.exit()

SUCTION_SHORT_GRIPPER_USD_PATH = assets_root_path + "/Isaac/Robots/UR10/Props/short_gripper.usd"
SUCTION_LONG_GRIPPER_USD_PATH = assets_root_path + "/Isaac/Robots/UR10/Props/long_gripper.usd"

# PARALLEL_GRIPPER_USD_PATH = assets_root_path + 

# Preparing stage
viewports.set_camera_view(eye=np.array([1.2, 1.2, 0.8]), target=np.array([0, 0, 0.5]))

# Loading the simple_room environment
stage.add_reference_to_stage(assets_root_path + BACKGROUND_USD_PATH, BACKGROUND_STAGE_PATH)

my_world = World(stage_units_in_meters=1.0)
my_task = PickPlace(fr5_usd_path=FR5_USD_PATH, attach_gripper=True)
my_world.add_task(my_task)
my_world.reset()
task_params = my_task.get_params()

my_fr5 = my_world.scene.get_object(task_params["robot_name"]["value"])
my_controller = PickPlaceController(
    name="pick_place_controller",
    gripper=my_fr5._gripper,
    end_effector_initial_height=0.25,
    robot_articulation=my_fr5
)
articulation_controller = my_fr5.get_articulation_controller()

from isaacsim.core.utils.stage import add_reference_to_stage
short_gripper_prim_path = "/World/ToolChanger/SuctionShortGripper"
long_gripper_prim_path = "/World/ToolChanger/SuctionLongGripper"
add_reference_to_stage(
    usd_path=SUCTION_SHORT_GRIPPER_USD_PATH,
    prim_path=short_gripper_prim_path
)
add_reference_to_stage(
    usd_path=SUCTION_LONG_GRIPPER_USD_PATH,
    prim_path=long_gripper_prim_path
)
from isaacsim.core.prims import SingleRigidPrim
short_gripper= SingleRigidPrim(
    prim_path=short_gripper_prim_path, name="short_gripper"
)
short_gripper.set_world_pose(
    position=np.array([0.8, -0.2, 0.5]),
    orientation=np.array([1, 0, 0, 0])
)
long_gripper= SingleRigidPrim(
    prim_path=long_gripper_prim_path, name="long_gripper"
)
long_gripper.set_world_pose(
    position=np.array([0.8, 0.2, 0.5]),
    orientation=np.array([1, 0, 0, 0])
)

simulation_app.update()
short_gripper.disable_rigid_body_physics()
long_gripper.disable_rigid_body_physics()

# Creating a action graph with ROS component nodes
start_ros2_bridge(my_fr5)

reset_needed = False
while simulation_app.is_running():
    og.Controller.set(
        og.Controller.attribute("/ActionGraph/OnImpulseEvent.state:enableImpulse"), True
    )

    # 로봇의 end effector pose
    robot_ee_pose = my_fr5.get_world_pose()
    robot_ee_position = robot_ee_pose[0]
    robot_ee_orientation = robot_ee_pose[1]  # (w, x, y, z) 형식

    ### ===== 시뮬레이션 진행 =====
    my_world.step(render=True)

    if my_world.is_stopped() and not reset_needed:
        reset_needed = True
    if my_world.is_playing():
        if reset_needed:
            my_world.reset()
            my_controller.reset()
            reset_needed = False
        observations = my_world.get_observations()
        actions = my_controller.forward(
            picking_position=observations[task_params["cube_name"]["value"]]["position"],
            placing_position=observations[task_params["cube_name"]["value"]]["target_position"],
            current_joint_positions=observations[task_params["robot_name"]["value"]]["joint_positions"],
            end_effector_offset=np.array([0, 0, 0.2]),
            end_effector_orientation=np.array([1, 0, 0, 0]), # quaternion
        )
        if my_controller.is_done():
            print("done picking and placing")
        articulation_controller.apply_action(actions)

        # F/T 센서 데이터 (필요 시)
        F_T_data = (
            my_controller._rmpflow_controller.articulation_rmp._robot_articulation._articulation_view.get_measured_joint_forces()
        )[0, -1, :]
        # print(f"ee_pos: {observations[fr5_name]['ee_pos']}")
        # print(f"ee_quat: {observations[fr5_name]['ee_quat']}")


# 종료 처리
rclpy.shutdown()
simulation_app.close()