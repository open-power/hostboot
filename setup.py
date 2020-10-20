# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: setup.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
import os.path
"""
 Setuptools is an open source package.
 Documentation on setuptools can be found on the web.

"""
from setuptools import setup


"""
 New modules should be added to this dictionary.
 Changes to a C++ UD Parser should also be made to the corresponding Python Parser.
 Helper files for the modules should be added to the directory corresponding to
 "helpers" in dirmap.
 Use "udparsers.helpers.helper_file_name" to include the file in a module.

"""
dirmap = {
    "b0300": "src/usr/scom/plugins/ebmc",
    "b0700": "src/usr/i2c/plugins/ebmc",
    "b0a00": "src/usr/fsi/plugins/ebmc",
    "b0e00": "src/usr/eeprom/plugins/ebmc",
    "b1a00": "src/usr/runtime/plugins/ebmc",
    "b1d00": "src/usr/vpd/plugins/ebmc",
    "b1e00": "src/usr/secureboot/common/plugins/ebmc",
    "b3600": "src/usr/expaccess/plugins/ebmc",
    "b4500": "src/usr/spi/plugins/ebmc",
    "be500": "src/usr/diag/prdf/plugins/ebmc",
    "helpers": "src/build/tools/ebmc"
}

"""Returns the package name for a parser module

@param[in] dirmap_key: a key from the dirmap dictionary
@returns: a string of the package name, "udparsers.dirmap_key"

"""
def get_package_name(dirmap_key):
    return "udparsers.{}".format(dirmap_key)

"""Takes an item from dirmap and gets the package name and directory for the module

@param[in] dirmap_item: a tuple of a key-value pair from dirmap
@returns: a tuple in the form (module package name, package directory)

"""
def get_package_dirent(dirmap_item):
    package_name = get_package_name(dirmap_item[0])
    package_dir = dirmap_item[1]
    return (package_name, package_dir)

"""Applies the get_package_name() function to each key in dirmap

@returns: a list of strings of the package names for each key

"""
def get_packages():
    return map(get_package_name, dirmap.keys())

"""Applies the get_package_dirent() function to each item in dirmap

@returns: a list of tuples in the form (module package name, package directory)

"""
def get_package_dirs():
    return map(get_package_dirent, dirmap.items())


setup(
        name="Hostboot",
        version="0.1",
        packages=list(get_packages()),
        package_dir=dict(get_package_dirs())
)
