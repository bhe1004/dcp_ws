import omni
from isaacsim.robot_setup.assembler import RobotAssembler, AssembledRobot
from pxr import Gf, UsdGeom


class Assembler:
    def __init__(self, robot_base: str, robot_base_mount: str):
        self.robot_assembler = RobotAssembler()
        self.stage = omni.usd.get_context().get_stage()
        self._robot_base = robot_base
        self._robot_base_mount = robot_base + "/" + robot_base_mount
        self._robot_attach = None
        self._robot_attach_mount = None
        self._variant_set = "Gripper"
        self._gripper_name = None

    def set_gripper(self, robot_attach, robot_attach_mount, gripper_name):
        self._robot_attach = robot_attach
        self._robot_attach_mount = robot_attach + "/" + robot_attach_mount
        self._gripper_name = gripper_name

    def begin_assembly(self):
        self.robot_assembler.begin_assembly(
            stage=self.stage,
            base_prim_path=self._robot_base,
            base_mount_path=self._robot_base_mount,
            attachment_prim_path=self._robot_attach,
            attachment_mount_path=self._robot_attach_mount,
            variant_set="Gripper",
            variant_name=self._gripper_name,
        )

    def assemble(self):
        # 수정: assemble_articulations를 사용하고 single_robot 플래그를 True로 설정
        self.robot_assembler.assemble_articulations(
            base_robot_path=self._robot_base,
            attach_robot_path=self._robot_attach,
            base_robot_mount_frame=self._robot_base_mount,
            attach_robot_mount_frame=self._robot_attach_mount,
            single_robot=True  # 이 플래그가 closed articulation 문제를 해결합니다.
        )

    def apply_translation(self, offset):
        prim_path = self.robot_assembler._attachment_robot_prim
        prim = self.stage.GetPrimAtPath(prim_path)

        if not prim.IsValid():
            print(f"[Error] Prim at path '{prim_path}' is not valid. Cannot apply translation.")
            return

        xformable = UsdGeom.Xformable(prim)
        
        old_matrix = xformable.GetLocalTransformation()
        translation_matrix = Gf.Matrix4d().SetTranslateOnly(offset)
        new_matrix = translation_matrix * old_matrix

        omni.kit.commands.execute(
            "TransformPrimCommand",
            path=prim.GetPath(),
            old_transform_matrix=old_matrix,
            new_transform_matrix=new_matrix,
        )

    def apply_rotation(self, axis, angle):
        prim = self.stage.GetPrimAtPath(self.robot_assembler._attachment_robot_prim)

        xformable = UsdGeom.Xformable(prim)
        old_matrix = xformable.GetLocalTransformation()
        rotation = Gf.Rotation(axis, angle)
        new_matrix = Gf.Matrix4d().SetRotateOnly(rotation) * old_matrix

        omni.kit.commands.execute(
            "TransformPrimCommand",
            path=prim.GetPath(),
            old_transform_matrix=old_matrix,
            new_transform_matrix=new_matrix,
        )

    def finish_assemble(self):
        self.robot_assembler.finish_assemble()