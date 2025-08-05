# Copyright (c) 2021-2024, NVIDIA CORPORATION. All rights reserved.
#
# NVIDIA CORPORATION and its licensors retain all intellectual property
# and proprietary rights in and to this software, related documentation
# and any modifications thereto. Any use, reproduction, disclosure or
# distribution of this software and related documentation without an express
# license agreement from NVIDIA CORPORATION is strictly prohibited.
#
from typing import Optional

import isaacsim.core.api.tasks as tasks
import numpy as np
from isaacsim.core.utils.prims import is_prim_path_valid
from isaacsim.core.utils.rotations import euler_angles_to_quat
from isaacsim.core.utils.string import find_unique_string_name
import sys
sys.path.append("/home/server1/fr5_ws/src/isaacsim_ros2/src")
from robot.fr5 import FR5
from .follow_target import FollowTarget


class FollowTargetWithRmpFlow(FollowTarget):
    """[summary]

    Args:
        name (str, optional): [description]. Defaults to "fr5_follow_target".
        target_prim_path (Optional[str], optional): [description]. Defaults to None.
        target_name (Optional[str], optional): [description]. Defaults to None.
        target_position (Optional[np.ndarray], optional): [description]. Defaults to None.
        target_orientation (Optional[np.ndarray], optional): [description]. Defaults to None.
        offset (Optional[np.ndarray], optional): [description]. Defaults to None.
        fr5_prim_path (Optional[str], optional): [description]. Defaults to None.
        fr5_robot_name (Optional[str], optional): [description]. Defaults to None.
        attach_gripper (bool, optional): [description]. Defaults to False.
    """

    def __init__(
        self,
        name: str = "fr5_follow_target",
        target_prim_path: Optional[str] = None,
        target_name: Optional[str] = None,
        target_position: Optional[np.ndarray] = None,
        target_orientation: Optional[np.ndarray] = None,
        offset: Optional[np.ndarray] = None,
        fr5_prim_path: Optional[str] = None,
        fr5_robot_name: Optional[str] = None,
        fr5_usd_path: Optional[str] = None,
        attach_gripper: bool = False,
    ) -> None:
        if target_orientation is None:
            target_orientation = euler_angles_to_quat(np.array([0, 0, 0]))
        FollowTarget.__init__(
            self,
            name=name,
            target_prim_path=target_prim_path,
            target_name=target_name,
            target_position=target_position,
            target_orientation=target_orientation,
            offset=offset,
        )
        self._fr5_prim_path = fr5_prim_path
        self._fr5_robot_name = fr5_robot_name
        self._fr5_usd_path = fr5_usd_path
        self._attach_gripper = attach_gripper
        return

    def set_robot(self) -> FR5:
        """[summary]

        Returns:
            FR5: [description]
        """
        if self._fr5_prim_path is None:
            self._fr5_prim_path = find_unique_string_name(
                initial_name="/World/fairino5_v6_robot", is_unique_fn=lambda x: not is_prim_path_valid(x)
            )
        if self._fr5_robot_name is None:
            self._fr5_robot_name = find_unique_string_name(
                initial_name="my_fr5", is_unique_fn=lambda x: not self.scene.object_exists(x)
            )
        self._fr5_robot = FR5(
            prim_path=self._fr5_prim_path,
            name=self._fr5_robot_name,
            usd_path=self._fr5_usd_path,
            attach_gripper=self._attach_gripper
        )
        self._fr5_robot.set_joints_default_state(
            positions=np.array([0, 0, 0, 0, 0, 0, # arm
                                0, 0, 0, 0, 0, 0, 0, 0]), # gripper
        )
        return self._fr5_robot
