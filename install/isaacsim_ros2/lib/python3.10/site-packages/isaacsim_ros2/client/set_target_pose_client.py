import sys
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose

sys.path.append("/home/server1/fr5_ws/install/isaacsim_interfaces/lib/python3.10/site-packages")
from isaacsim_interfaces.srv import SetTargetPose

class SetTargetPoseClient(Node):
    def __init__(self):
        super().__init__('set_target_pose_client')
        self.cli = self.create_client(SetTargetPose, 'set_target_pose')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')
        self.req = SetTargetPose.Request()

    def send_request(self):
        self.req.pose = Pose()
        self.req.pose.position.x = 0.0
        self.req.pose.position.y = 0.1
        self.req.pose.position.z = 0.7
        self.req.pose.orientation.w = 1.0
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        if future.result():
            self.get_logger().info(f"Result: {future.result().message}")


def main():
    rclpy.init()
    client = SetTargetPoseClient()
    client.send_request()
    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
