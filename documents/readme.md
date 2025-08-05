# Build


```
$ cd ~/dcp_ws
$ colcon build
```

- source python3.11 environment for isaacsim
```
$ source $HOME/IsaacSim-ros_workspaces/build_ws/humble/humble_ws/install/local_setup.bash
$ source $HOME/IsaacSim-ros_workspaces/build_ws/humble/isaac_sim_ros_ws/install/local_setup.bash
```

- Run Simulation
```
$ ~/isaacsim/_build/linux-x86_64/release/python.sh /home/home/dcp_ws/src/fairino/isaacsim_ros2/isaacsim_ros2/robot_env.py
```

- Create another terminal
```
ros2 topic list
```