from setuptools import find_packages, setup

package_name = 'isaacsim_ros2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(include=[package_name, f"{package_name}.*"]),
    data_files=[
        ('share/ament_index/resource_index/packages',
         [f'resource/{package_name}']),
        (f'share/{package_name}', ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='server1',
    maintainer_email='server1@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'set_target_pose_client = isaacsim_ros2.client.set_target_pose_client:main',
        ],
    },
)