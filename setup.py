import os.path
from setuptools import setup

dirmap = {
    "bxxxx": "src/usr/secureboot",
    "bzzzz": "src/usr/hdat",
}


def get_package_name(dirmap_key):
    return "udparsers.{}".format(dirmap_key)


def get_package_dirent(dirmap_item):
    package_name = get_package_name(dirmap_item[0])
    package_dir = os.path.join(dirmap_item[1], 'plugins/ebmc')
    return (package_name, package_dir)


def get_packages():
    return map(get_package_name, dirmap.keys())


def get_package_dirs():
    return map(get_package_dirent, dirmap.items())


setup(
        name="Hostboot",
        version="0.1",
        packages=list(get_packages()),
        package_dir=dict(get_package_dirs())
)
