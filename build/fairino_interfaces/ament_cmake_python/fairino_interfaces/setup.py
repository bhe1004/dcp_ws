from setuptools import find_packages
from setuptools import setup

setup(
    name='fairino_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('fairino_interfaces', 'fairino_interfaces.*')),
)
