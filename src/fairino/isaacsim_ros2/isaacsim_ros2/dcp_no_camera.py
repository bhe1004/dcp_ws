from abc import ABC, abstractmethod
from typing import Optional

import numpy as np
import omni
from isaacsim.core.api.objects import FixedCuboid, DynamicCuboid, DynamicCylinder
from isaacsim.core.api.scenes.scene import Scene
from isaacsim.core.api.tasks import BaseTask
from isaacsim.core.prims import SingleXFormPrim, SingleRigidPrim
from isaacsim.core.utils.prims import is_prim_path_valid
from isaacsim.core.utils.stage import get_stage_units, add_reference_to_stage
from isaacsim.core.utils.string import find_unique_string_name
from isaacsim.storage.native import get_assets_root_path
from isaacsim.sensors.camera import Camera, SingleViewDepthSensor
from isaacsim.robot.manipulators.grippers import Gripper, ParallelGripper
from isaacsim.robot.manipulators.manipulators import SingleManipulator
from assembler import Assembler
from pxr import Gf
import isaacsim.core.utils.numpy.rotations as rot_utils

class DCP(ABC, BaseTask):
    
    def __init__(
        self,
        name: str,
    ) -> None:
        BaseTask.__init__(self, name=name)
        self._robot = None
        self._camera_fixed = {
            "front": {
                "rgb": None,
                "depth": None,
            },
            "back": {
                "rgb": None,
                "depth": None,
            },
        }
        self._camera_wrist = {
            "rgb": None,
            "depth": None,
        }
        self._asset_root_path = get_assets_root_path()
        if self._asset_root_path is None:
            raise Exception("Could not find Isaac Sim assets folder")
        self._robot_stage_path = "/World/robot"
        self._camera_stage_paths = {
            "fixed": {
                "front": "/World/camera_fixed_front",
                "back": "/World/camera_fixed_back",
            },
            "wrist": self._robot_stage_path + "/wrist3_link/camera_wrist",
        }
        self._ee_xform_path = self._robot_stage_path + "/wrist3_link"
        self._asset_path = "/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets"
        self._robot_asset_path = self._asset_path + "/fairino5_v6_2f140/fairino5_v6_2f140.usd"
        self._camera_asset_path = self._asset_path + "/sensors/RSD455.usd"
        self._objects_asset_paths = {
            "beaker": self._asset_path + "/objects/beaker_1.usd",
            "flask": self._asset_path + "/objects/flask_1.usd",
            "graduated_cylinder": {
                "1": self._asset_path + "/objects/graduated_cylinder_1.usd",
                "2": self._asset_path + "/objects/graduated_cylinder_2.usd",
            },
            "reagent_bottle": {
                "1": self._asset_path + "/objects/reagent_bottle_1.usd",
                "2": self._asset_path + "/objects/reagent_bottle_2.usd",
            }
            
        }

        return

    def set_up_scene(self, scene: Scene) -> None:
        super().set_up_scene(scene)

        # Loading the simple_room environment
        # background_stage_path = "/background"
        # background_usd_path = "/Isaac/Environments/Simple_Room/simple_room.usd"
        # add_reference_to_stage(self._asset_root_path + background_usd_path, background_stage_path)

        scene.add_default_ground_plane(z_position = -0.80)

        robot_base = FixedCuboid(
            prim_path="/World/robot_base",
            name="robot_base",
            # scale=np.array([0.78, 0.84, 0.80]), # Real table size
            # translation=np.array([0.28, 0.0, -0.40]), # Real table position
            scale = np.array([0.3, 0.3, 0.80]), # Virtual table size
            translation=np.array([0.0, 0.0, -0.40]),
        )
        table_1 = FixedCuboid(
            prim_path="/World/table1",
            name="table1",
            # scale=np.array([0.78, 0.84, 0.80]), # Real table size
            # translation=np.array([0.28, 0.0, -0.40]), # Real table position
            scale = np.array([1.0, 1.2, 1.0]), # Virtual table size
            translation=np.array([0.7, 0.0, -0.5]),
        )
        table_2 = FixedCuboid(
            prim_path="/World/table2",
            name="table2",
            scale = np.array([1.0, 1.2, 1.0]), # Virtual table size
            translation=np.array([-0.7, 0.0, -0.5]),
        )

        cube1 = DynamicCuboid(
            prim_path="/World/cube1",
            name="cube1",
            size=0.05,
            position=np.array([0.64, 0.45, 0.1]),
        )

        cube2 = DynamicCuboid(
            prim_path="/World/cube2",
            name="cube2",
            size=0.05,
            position=np.array([0.64, 0.3, 0.1]),
        )

        cylinder_1 = DynamicCylinder(
            prim_path="/World/cylinder1",
            name="cylinder1",
            position=np.array([0.8, -0.146, 0.1]),
            radius=0.02,
            height=0.3)

        # Define the robot
        self._robot = self.set_robot()

        scene.add(self._robot)

        self._task_objects[self._robot.name] = self._robot

    
    def set_robot(self) -> SingleManipulator:

        robot_prim_path = find_unique_string_name(
            initial_name=self._robot_stage_path, is_unique_fn=lambda x: not is_prim_path_valid(x)
        )

        add_reference_to_stage(usd_path=self._robot_asset_path, prim_path=robot_prim_path)

        # define the gripper
        gripper = ParallelGripper(
            end_effector_prim_path=robot_prim_path + "/wrist3_link",
            joint_prim_names=["finger_joint"],
            joint_opened_positions=np.array([0.0]),
            joint_closed_positions=np.array([45.0]),
            action_deltas=np.array([5.0, 5.0]) / get_stage_units(),
            use_mimic_joints=True,
        )
        
        manipulator = SingleManipulator(
            prim_path=robot_prim_path,
            name="fr5_robot",
            end_effector_prim_path=self._ee_xform_path,
            gripper=gripper,
        )

        manipulator.set_joints_default_state(
            positions = np.array([0.0, -1.22,-1.92, -1.57, 1.57, 0.0, # Arm joint position
                                  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]), # Gripper joint position
        )

        print("robot ready")

        return manipulator



    def get_observations(self) -> dict:
        joints_state = self._robot.get_joints_state()
        end_effector_position, _ = self._robot.end_effector.get_local_pose()
        joint_forces = self._robot.get_measured_joint_forces(-1).flatten()
        return {
            self._robot.name: {
                "joint_position": joints_state.positions,
                "end_effector_position": end_effector_position,
            },
            "sensor": {
                "FT": {
                    "force": joint_forces[0:3],
                    "torque": joint_forces[3:6],
                },
            },
        }
    
    def pre_step(self, time_step_index: int, simulation_time: float) -> None:
        """[summary]

        Args:
            time_step_index (int): [description]
            simulation_time (float): [description]
        """
        return
    
    def post_reset(self) -> None:
        from isaacsim.robot.manipulators.grippers.parallel_gripper import ParallelGripper

        if isinstance(self._robot.gripper, ParallelGripper):
            self._robot.gripper.set_joint_positions(self._robot.gripper.joint_opened_positions)
        return


