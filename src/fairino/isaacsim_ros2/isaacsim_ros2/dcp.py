from abc import ABC, abstractmethod
from typing import Optional

import numpy as np
import omni
from isaacsim.core.api.objects import FixedCuboid
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
        self._robot_asset_path = self._asset_path + "/fr5_with_ag95/fr5_with_ag95.usd"
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
            scale = np.array([0.6, 1.2, 1.0]), # Virtual table size
            translation=np.array([0.5, 0.0, -0.5]),
        )
        table_2 = FixedCuboid(
            prim_path="/World/table2",
            name="table2",
            scale = np.array([0.6, 1.2, 1.0]), # Virtual table size
            translation=np.array([-0.5, 0.0, -0.5]),
        )

        # Add Shelf 1
        add_reference_to_stage(
            usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/EurekaConsole.usd",
            prim_path="/World/shelf0")
        
        shelf_1 = SingleXFormPrim(
            prim_path="/World/shelf0",
            name="shelf_1",
            scale=(0.008, 0.005, 0.006),
        )
        shelf_1.set_world_pose(
            position=(0.65, 0.0, 0.003),
            orientation=rot_utils.euler_angles_to_quats(np.array([0, 0, -90]), degrees=True),
        )

        # Add Shelf 2
        add_reference_to_stage(
            usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/EurekaConsole.usd",
            prim_path="/World/shelf1")
        
        shelf_2 = SingleXFormPrim(
            prim_path="/World/shelf1",
            name="shelf_2",
            scale=(0.8, 0.5, 0.6), # x100: Because of scale:unit resolve
        )
        shelf_2.set_world_pose(
            position=(-0.65, 0.0, 0.003),
            orientation=rot_utils.euler_angles_to_quats(np.array([0, 0, 90]), degrees=True),
        )

        self.set_objects()

        # Define the robot
        self._robot = self.set_robot()

        self.set_camera()

        # Add the robot and cameras to the scene
        scene.add(robot_base)
        scene.add(table_1)
        scene.add(table_2)
        # scene.add(shelf_1)
        # scene.add(shelf_2)
        scene.add(self._camera_fixed["front"]["rgb"])
        scene.add(self._camera_fixed["front"]["depth"])
        scene.add(self._camera_fixed["back"]["rgb"])
        scene.add(self._camera_fixed["back"]["depth"])
        scene.add(self._camera_wrist["rgb"])
        scene.add(self._camera_wrist["depth"])
        scene.add(self._robot)

        self._task_objects[self._robot.name] = self._robot
        self._task_objects[self._camera_fixed["front"]["rgb"].name] = self._camera_fixed["front"]["rgb"]
        self._task_objects[self._camera_fixed["front"]["depth"].name] = self._camera_fixed["front"]["depth"]
        self._task_objects[self._camera_fixed["back"]["rgb"].name] = self._camera_fixed["back"]["rgb"]
        self._task_objects[self._camera_fixed["back"]["depth"].name] = self._camera_fixed["back"]["depth"]
        self._task_objects[self._camera_wrist["rgb"].name] = self._camera_wrist["rgb"]
        self._task_objects[self._camera_wrist["depth"].name] = self._camera_wrist["depth"]

    
    def set_robot(self) -> SingleManipulator:
        robot_asset_path = "/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/fr5_with_ag95/fr5_with_ag95.usd"

        robot_prim_path = find_unique_string_name(
            initial_name=self._robot_stage_path, is_unique_fn=lambda x: not is_prim_path_valid(x)
        )

        add_reference_to_stage(usd_path=robot_asset_path, prim_path=robot_prim_path)

        # define the gripper
        gripper = ParallelGripper(
            end_effector_prim_path=robot_prim_path + "/wrist3_link",
            joint_prim_names=["gripper_finger1_joint", "gripper_finger2_joint"],
            joint_opened_positions=np.array([0.0]),
            joint_closed_positions=np.array([30.0]),
            action_deltas=np.array([5.0, 5.0]) / get_stage_units(),
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

        return manipulator
    
    def set_camera(self):
        # Define the fixed camera
        add_reference_to_stage(usd_path=self._camera_asset_path, prim_path=self._camera_stage_paths["fixed"]["front"])
        camera_fixed_front_xform_prim = SingleXFormPrim(
            prim_path=self._camera_stage_paths["fixed"]["front"],
            name="camera_fixed_front_xform",
        )
        camera_fixed_front_xform_prim.set_world_pose(
            position=(0.123, 0.0, 0.12),
            orientation=rot_utils.euler_angles_to_quats(np.array([0, -4, 180]), degrees=True),
        )
        self._camera_fixed["front"]["rgb"] = Camera(
            prim_path=self._camera_stage_paths["fixed"]["front"] + "/RSD455/Camera_OmniVision_OV9782_Color",
            name="camera_fixed_front_rgb",
            resolution=(640, 480),
            frequency=30
        )
        self._camera_fixed["front"]["depth"] = SingleViewDepthSensor(
            prim_path=self._camera_stage_paths["fixed"]["front"] + "/RSD455/Camera_Pseudo_Depth",
            name="camera_fixed_front_depth",
            resolution=(640, 480),
            frequency=30,
        )

        add_reference_to_stage(usd_path=self._camera_asset_path, prim_path=self._camera_stage_paths["fixed"]["back"])
        camera_fixed_back_xform_prim = SingleXFormPrim(
            prim_path=self._camera_stage_paths["fixed"]["back"],
            name="camera_fixed_back_xform",
        )
        camera_fixed_back_xform_prim.set_world_pose(
            position=(-0.123, 0.0, 0.12),
            orientation=rot_utils.euler_angles_to_quats(np.array([0, -4, 0]), degrees=True),
        )
        self._camera_fixed["back"]["rgb"] = Camera(
            prim_path=self._camera_stage_paths["fixed"]["back"] + "/RSD455/Camera_OmniVision_OV9782_Color",
            name="camera_fixed_back_rgb",
            resolution=(640, 480),
            frequency=30
        )
        self._camera_fixed["back"]["depth"] = SingleViewDepthSensor(
            prim_path=self._camera_stage_paths["fixed"]["back"] + "/RSD455/Camera_Pseudo_Depth",
            name="camera_fixed_back_depth",
            resolution=(640, 480),
            frequency=30,
        )

        # Define the camera on the robot's wrist
        add_reference_to_stage(usd_path=self._camera_asset_path, prim_path=self._robot_stage_path + "/wrist3_link/camera_wrist")
        camera_wrist_xform_prim = SingleXFormPrim(
            prim_path=self._camera_stage_paths["wrist"],
            name="camera_wrist_xform",
        )
        camera_wrist_xform_prim.set_local_pose(
            translation=(0.0, -0.07, 0.085),
            orientation=rot_utils.euler_angles_to_quats(np.array([90.0, 90.0, 0.0]), degrees=True),
        )
        self._camera_wrist["rgb"] = Camera(
            prim_path=self._camera_stage_paths["wrist"] + "/RSD455/Camera_OmniVision_OV9782_Color",
            name="camera_wrist_rgb",
            resolution=(640, 480),
            frequency=30,
        )
        self._camera_wrist["depth"] = SingleViewDepthSensor(
            prim_path=self._camera_stage_paths["wrist"] + "/RSD455/Camera_Pseudo_Depth",
            name="camera_wrist_depth",
            resolution=(640, 480),
            frequency=30,
        )

        # Initialize cameras
        self._camera_fixed["front"]["rgb"].initialize()
        self._camera_fixed["front"]["depth"].initialize()
        self._camera_fixed["back"]["rgb"].initialize()
        self._camera_fixed["back"]["depth"].initialize()
        self._camera_wrist["rgb"].initialize()
        self._camera_wrist["depth"].initialize()

        # Remove RGB from depth cameras and add distance to image plane
        self._camera_fixed["front"]["depth"].remove_rgb_from_frame()
        self._camera_fixed["back"]["depth"].remove_rgb_from_frame()
        self._camera_wrist["depth"].remove_rgb_from_frame()
        self._camera_fixed["front"]["depth"].add_distance_to_image_plane_to_frame()
        self._camera_fixed["back"]["depth"].add_distance_to_image_plane_to_frame()
        self._camera_wrist["depth"].add_distance_to_image_plane_to_frame()

    def set_object(
        self, usd_path: str, prim_path: Optional[str] = None, name: Optional[str] = None,
        scale: Optional[tuple] = None, position: Optional[tuple] = None, orientation: Optional[list] = None, degrees=True,
    ) -> None:
        
        prim_path = prim_path or find_unique_string_name(
            initial_name="/World/objects/" + name if name else "/World/objects/object",
            is_unique_fn=lambda x: not is_prim_path_valid(x)
        )
        name = name or prim_path.split("/")[-1]
        if scale is None:
            scale = (1.0, 1.0, 1.0)
        if position is None:
            position = (0.0, 0.0, 0.0)
        if orientation is None:
            orientation = [1.0, 0.0, 0.0, 0.0]
        
        add_reference_to_stage(
            usd_path=usd_path,
            prim_path=prim_path,
        )
        xform_prim = SingleXFormPrim(
            prim_path=prim_path,
            name=name,
            scale=scale
        )
        xform_prim.set_world_pose(
            position=position,
            orientation=rot_utils.euler_angles_to_quats(np.array(orientation), degrees=degrees),
        )

    def set_objects(self) -> None:
        """Set up the objects in the scene."""

        for i in range(7):
            self.set_object(
                usd_path=self._objects_asset_paths["beaker"],
                prim_path=f"/World/objects/beaker{i}",
                name=f"beaker{i}_xform",
                scale=(100.0, 100.0, 100.0),
                position=(0.64, -0.45 + 0.15*i, 0.099),
                orientation=[0, 0, 0], degrees=True
            )

        for i in range(7):
            self.set_object(
                usd_path=self._objects_asset_paths["flask"],
                prim_path=f"/World/objects/flask{i}",
                name=f"flask{i}_xform",
                scale=(1.0, 1.0, 1.0),
                position=(0.64, -0.45 + 0.15*i, 0.33),
                orientation=[0, 0, 0], degrees=True
            )

        for i in range(3):
            self.set_object(
                usd_path=self._objects_asset_paths["graduated_cylinder"]["1"],
                prim_path=f"/World/objects/cylinder1_{i}",
                name=f"cylinder1_{i}_xform",
                scale=(1.0, 1.0, 1.0),
                position=(-0.64, -0.45 + 0.15*i, 0.11807),
                orientation=[0, 0, 0], degrees=True
            )

        for i in range(4):
            self.set_object(
                usd_path=self._objects_asset_paths["graduated_cylinder"]["2"],
                prim_path=f"/World/objects/cylinder2_{i}",
                name=f"cylinder2_{i}_xform",
                scale=(1.0, 1.0, 1.0),
                position=(-0.64, 0.45 - 0.15*i, 0.11807),
                orientation=[0, 0, 0], degrees=True
            )

        for i in range(3):
            self.set_object(
                usd_path=self._objects_asset_paths["reagent_bottle"]["1"],
                prim_path=f"/World/objects/reagent_bottle1_{i}",
                name=f"reagent_bottle1_{i}_xform",
                scale=(1.0, 1.0, 1.0),
                position=(-0.64, -0.45 + 0.15*i, 0.30846),
                orientation=[0, 0, 0], degrees=True
            )

        for i in range(4):
            self.set_object(
                usd_path=self._objects_asset_paths["reagent_bottle"]["2"],
                prim_path=f"/World/objects/reagent_bottle2_{i}",
                name=f"reagent_bottle2_{i}_xform",
                scale=(1.0, 1.0, 1.0),
                position=(-0.64, 0.45 - 0.15*i, 0.30846),
                orientation=[0, 0, 0], degrees=True
            )

        self.set_object(
            usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/tscale.usd",
            prim_path="/World/objects/tscale_0",
            name="tscale_0_xform",
            scale=(0.05, 0.05, 0.05),
            position=(0.45787, 0.45, 0.02043),
            orientation=[0, 0, -90], degrees=True,
        )
        self.set_object(
            usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/tscale.usd",
            prim_path="/World/objects/tscale_1",
            name="tscale_1_xform",
            scale=(0.05, 0.05, 0.05),
            position=(-0.45787, -0.45, 0.02043),
            orientation=[0, 0, 90], degrees=True,
        )

        # add_reference_to_stage(
        #     usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/graduated_cylinder_1.usd",
        #     prim_path="/World/objects/cylinder0")
        # flask_xform_prim = SingleXFormPrim(
        #     prim_path="/World/objects/cylinder0",
        #     name="cylinder0_xform",
        #     scale=(1.0, 1.0, 1.0))
        # flask_xform_prim.set_world_pose(
        #     position=(-0.4, 0.4, 0.0),
        #     orientation=rot_utils.euler_angles_to_quats(np.array([0, 0, 0]), degrees=True),)
        
        # add_reference_to_stage(
        #     usd_path="/home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/assets/objects/graduated_cylinder_2.usd",
        #     prim_path="/World/objects/cylinder1")
        # flask_xform_prim = SingleXFormPrim(
        #     prim_path="/World/objects/cylinder1",
        #     name="cylinder1_xform",
        #     scale=(1.0, 1.0, 1.0))
        # flask_xform_prim.set_world_pose(
        #     position=(-0.4, -0.4, 0.0),
        #     orientation=rot_utils.euler_angles_to_quats(np.array([0, 0, 0]), degrees=True),)



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
                "camera": {
                    "fixed": {
                        "front": {
                            "rgb": self._camera_fixed["front"]["rgb"].get_rgb(),
                            "depth": self._camera_fixed["front"]["depth"].get_depth(),
                        },
                        "back": {
                            "rgb": self._camera_fixed["back"]["rgb"].get_rgb(),
                            "depth": self._camera_fixed["back"]["depth"].get_depth(),
                        },
                    },
                    "wrist": {
                        "rgb": self._camera_wrist["rgb"].get_rgb(),
                        "depth": self._camera_wrist["depth"].get_depth(),
                    }
                }
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


