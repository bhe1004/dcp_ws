import rosbag2_py
import numpy as np
import matplotlib.pyplot as plt
from geometry_msgs.msg import Wrench

def read_wrench_bag(bag_path, topic_name='/ft_sensor'):
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id='sqlite3')
    converter_options = rosbag2_py.ConverterOptions('', '')
    reader = rosbag2_py.SequentialReader()
    reader.open(storage_options, converter_options)
    topic_types = reader.get_all_topics_and_types()
    type_map = {t.name: t.type for t in topic_types}
    reader.set_filter(rosbag2_py.StorageFilter(topics=[topic_name]))

    from rclpy.serialization import deserialize_message
    from rosidl_runtime_py.utilities import get_message

    msg_type = get_message(type_map[topic_name])
    
    timestamps = []
    fx, fy, fz = [], [], []
    tx, ty, tz = [], [], []

    while reader.has_next():
        topic, data, timestamp_ns = reader.read_next()
        msg = deserialize_message(data, msg_type)

        timestamps.append(timestamp_ns * 1e-9)  # convert nanoseconds to seconds

        fx.append(msg.force.x)
        fy.append(msg.force.y)
        fz.append(msg.force.z)
        tx.append(msg.torque.x)
        ty.append(msg.torque.y)
        tz.append(msg.torque.z)

    return timestamps, fx, fy, fz, tx, ty, tz

def plot_force_torque(t, fx, fy, fz, tx, ty, tz):
    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(t, fx, label='Fx')
    plt.plot(t, fy, label='Fy')
    plt.plot(t, fz, label='Fz')
    plt.title('Force')
    plt.xlabel('Time [s]')
    plt.ylabel('Force [N]')
    plt.legend()
    plt.grid()

    plt.subplot(1, 2, 2)
    plt.plot(t, tx, label='Tx')
    plt.plot(t, ty, label='Ty')
    plt.plot(t, tz, label='Tz')
    plt.title('Torque')
    plt.xlabel('Time [s]')
    plt.ylabel('Torque [Nm]')
    plt.legend()
    plt.grid()

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("Usage: python3 plot_ft_sensor.py <bag_directory>")
        sys.exit(1)

    bag_path = sys.argv[1]
    t, fx, fy, fz, tx, ty, tz = read_wrench_bag(bag_path)
    plot_force_torque(t, fx, fy, fz, tx, ty, tz)
