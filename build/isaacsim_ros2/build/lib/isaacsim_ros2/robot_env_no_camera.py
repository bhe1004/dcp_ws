import sys
import numpy as np
from isaacsim import SimulationApp

# Robot
ROBOT_PRIM_PATH = "/World/robot"
ACTUAL_ARTICULATION_ROOT_PATH = ROBOT_PRIM_PATH + "/root_joint"

CONFIG = {"renderer": "RaytracedLighting", "headless": False}

# and creation of ROS components
simulation_app = SimulationApp(CONFIG)

import omni.graph.core as og
from isaacsim.core.api import World
from isaacsim.core.utils import extensions, viewports

# enable extension
extensions.enable_extension("isaacsim.ros2.bridge")
extensions.enable_extension("isaacsim.robot_setup.assembler")

from dcp_no_camera import DCP
from action_graph import create_action_graph

import rclpy
from geometry_msgs.msg import Wrench

simulation_app.update()

# world = World(stage_units_in_meters=1.0, physics_dt=1 / 200, rendering_dt=20 / 200)
world = World(stage_units_in_meters=1.0)
world.initialize_physics()
simulation_app.update()

dcp_task = DCP(name="DCP_Task")
world.add_task(dcp_task)
world.reset()

# Preparing stage
viewports.set_camera_view(eye=np.array([1.2, 1.2, 0.8]), target=np.array([0, 0, 0.5]))

robot = world.scene.get_object("fr5_robot")
robot.post_reset()

# Camera objects
camera_fixed_rgb = world.scene.get_object("camera_fixed_rgb")
camera_wrist_rgb = world.scene.get_object("camera_wrist_rgb")
camera_fixed_depth = world.scene.get_object("camera_fixed_depth")
camera_wrist_depth = world.scene.get_object("camera_wrist_depth")

simulation_app.update()

world.play()

rclpy.init()
# print(f"robot.dof_names: {robot.dof_names}")

create_action_graph(articulation_root_path=ACTUAL_ARTICULATION_ROOT_PATH)

node = rclpy.create_node("fairino_ros2_simulation_node")
ft_sensor_pub = node.create_publisher(Wrench, "ft_sensor", 10)

frame = 0
while simulation_app.is_running():

    # Run with a fixed step size
    world.step(render=True)

    if world.is_playing():

        # Tick the Publish/Subscribe JointState and Publish Clock nodes each frame
        og.Controller.set(og.Controller.attribute("/ActionGraph/OnImpulseEvent.state:enableImpulse"), True)

        observations = dcp_task.get_observations()
        joint_state = observations[robot.name]["joint_position"]

        if frame % 2 == 0:
            ft_sensor_msg = Wrench()
            ft_sensor_msg.force.x = float(observations["sensor"]["FT"]["force"][0])
            ft_sensor_msg.force.y = float(observations["sensor"]["FT"]["force"][1])
            ft_sensor_msg.force.z = float(observations["sensor"]["FT"]["force"][2])
            ft_sensor_msg.torque.x = float(observations["sensor"]["FT"]["torque"][0])
            ft_sensor_msg.torque.y = float(observations["sensor"]["FT"]["torque"][1])
            ft_sensor_msg.torque.z = float(observations["sensor"]["FT"]["torque"][2])

            ft_sensor_pub.publish(ft_sensor_msg)

    frame += 1

world.stop()
if rclpy.ok():
    rclpy.shutdown()
simulation_app.close()