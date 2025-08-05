import omni.graph.core as og
import carb

def create_action_graph(articulation_root_path):
    # --- ROS 2 Bridge Utility (Simplified from your original) ---
    try:
        og.Controller.edit(
            {"graph_path": "/ActionGraph", "evaluator_name": "execution"},
            {
                og.Controller.Keys.CREATE_NODES: [
                    ("OnImpulseEvent", "omni.graph.action.OnImpulseEvent"),
                    ("ReadSimTime", "isaacsim.core.nodes.IsaacReadSimulationTime"),
                    ("Context", "isaacsim.ros2.bridge.ROS2Context"),
                    ("PublishJointState", "isaacsim.ros2.bridge.ROS2PublishJointState"),
                    ("SubscribeJointState", "isaacsim.ros2.bridge.ROS2SubscribeJointState"),
                    ("ArticulationController", "isaacsim.core.nodes.IsaacArticulationController"),
                    ("PublishClock", "isaacsim.ros2.bridge.ROS2PublishClock"),
                ],
                og.Controller.Keys.CONNECT: [
                    ("OnImpulseEvent.outputs:execOut", "PublishJointState.inputs:execIn"),
                    ("OnImpulseEvent.outputs:execOut", "SubscribeJointState.inputs:execIn"),
                    ("OnImpulseEvent.outputs:execOut", "PublishClock.inputs:execIn"),
                    ("OnImpulseEvent.outputs:execOut", "ArticulationController.inputs:execIn"),
                    ("Context.outputs:context", "PublishJointState.inputs:context"),
                    ("Context.outputs:context", "SubscribeJointState.inputs:context"),
                    ("Context.outputs:context", "PublishClock.inputs:context"),
                    ("ReadSimTime.outputs:simulationTime", "PublishJointState.inputs:timeStamp"),
                    ("ReadSimTime.outputs:simulationTime", "PublishClock.inputs:timeStamp"),
                    ("SubscribeJointState.outputs:jointNames", "ArticulationController.inputs:jointNames"),
                    (
                        "SubscribeJointState.outputs:positionCommand",
                        "ArticulationController.inputs:positionCommand",
                    ),
                    (
                        "SubscribeJointState.outputs:velocityCommand",
                        "ArticulationController.inputs:velocityCommand",
                    ),
                ],
                og.Controller.Keys.SET_VALUES: [
                    ("ArticulationController.inputs:robotPath", articulation_root_path),
                    ("PublishJointState.inputs:topicName", "/isaac_joint_states"),
                    ("PublishJointState.inputs:targetPrim", articulation_root_path), # Link to your robot
                    ("SubscribeJointState.inputs:topicName", "isaac_joint_command"),
                ],
            },
        )
        carb.log_info("Basic ROS2 ActionGraph created.")
    except Exception as e:
        carb.log_error(f"Error creating ROS2 ActionGraph: {e}")