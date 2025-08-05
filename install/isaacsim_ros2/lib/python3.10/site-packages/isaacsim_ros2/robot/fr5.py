# Copyright (c) 2021-2024, NVIDIA CORPORATION. All rights reserved.
#
# NVIDIA CORPORATION and its licensors retain all intellectual property
# and proprietary rights in and to this software, related documentation
# and any modifications thereto. Any use, reproduction, disclosure or
# distribution of this software and related documentation without an express
# license agreement from NVIDIA CORPORATION is strictly prohibited.
#
from typing import List, Optional
import os
import carb
import numpy as np
from isaacsim.core.api.robots.robot import Robot
from isaacsim.core.prims import SingleRigidPrim
from isaacsim.core.utils.prims import get_prim_at_path
from isaacsim.core.utils.stage import add_reference_to_stage, get_stage_units
from isaacsim.storage.native import get_assets_root_path

class FR5(Robot):
    """[summary]

    Args:
        prim_path (str): [description]
        name (str, optional): [description]. Defaults to "fr5_robot".
        usd_path (Optional[str], optional): [description]. Defaults to None.
        position (Optional[np.ndarray], optional): [description]. Defaults to None.
        orientation (Optional[np.ndarray], optional): [description]. Defaults to None.
        end_effector_prim_name (Optional[str], optional): [description]. Defaults to None.

    Raises:
        NotImplementedError: [description]
    """

    def __init__(
        self,
        prim_path: str,
        name: str = "fr5_robot",
        usd_path: Optional[str] = None,
        position: Optional[np.ndarray] = None,
        orientation: Optional[np.ndarray] = None,
        end_effector_prim_name: Optional[str] = None,
    ) -> None:
        prim = get_prim_at_path(prim_path)
        self._end_effector = None
        self._end_effector_prim_name = end_effector_prim_name
        if not prim.IsValid():
            add_reference_to_stage(usd_path=usd_path, prim_path=prim_path)
            self._end_effector_prim_path = prim_path + "/" + end_effector_prim_name
            
        super().__init__(
            prim_path=prim_path, name=name, position=position, orientation=orientation, articulation_controller=None
        )
        return

    @property
    def end_effector(self) -> SingleRigidPrim:
        """[summary]

        Returns:
            SingleRigidPrim: [description]
        """
        return self._end_effector

    def initialize(self, physics_sim_view=None) -> None:
        """[summary]"""
        super().initialize(physics_sim_view)
        # self._end_effector = SingleRigidPrim(prim_path=self._end_effector_prim_path, name=self.name + "_end_effector")
        # self._end_effector.initialize(physics_sim_view)
        self.disable_gravity()
        
        return

    def post_reset(self) -> None:
        """[summary]"""
        Robot.post_reset(self)
        self._end_effector.post_reset()
        return