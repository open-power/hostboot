# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: setup.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2022
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
New parsing modules should be added to this dictionary.
Changes to a C++ Parser should also be made to the corresponding Python Parser.

Helper files for the modules should be added to the directory corresponding to
"helpers" in dirmap.
Use "udparsers.helpers.helper_file_name" to include the file in a module.

"""

package_directories = {
    # User Data packages.
    # Component package names must be in the form of: `udparsers.bxxxx`. Where
    # 'xxxx' is the 4 digit component ID (lowercase).

    "udparsers.b0100":   "src/usr/errl/plugins/ebmc/b0100",
    "udparsers.b0300":   "src/usr/scom/plugins/ebmc",
    "udparsers.b0500":   "src/usr/initservice/plugins/ebmc",
    "udparsers.b0700":   "src/usr/i2c/plugins/ebmc",
    "udparsers.b0900":   "src/usr/isteps/plugins/ebmc",
    "udparsers.b0a00":   "src/usr/fsi/plugins/ebmc",
    "udparsers.b0c00":   "src/usr/hwas/plugins/ebmc",
    "udparsers.b0e00":   "src/usr/eeprom/plugins/ebmc",
    "udparsers.b1a00":   "src/usr/runtime/plugins/ebmc",
    "udparsers.b1d00":   "src/usr/vpd/plugins/ebmc",
    "udparsers.b1e00":   "src/usr/secureboot/common/plugins/ebmc",
    "udparsers.b2600":   "src/usr/htmgt/plugins/ebmc",
    "udparsers.b3100":   "src/usr/errl/plugins/ebmc/b3100",
    "udparsers.b3600":   "src/usr/expaccess/plugins/ebmc",
    "udparsers.b4500":   "src/usr/spi/plugins/ebmc",
    "udparsers.be500":   "src/usr/diag/prdf/peltool/ud",
    "udparsers.helpers": "src/build/tools/ebmc",

    # SRC parsers packages.
    # The only required package is 'srcparsers.bsrc', but other modules can be
    # used if called from 'srcparsers.bsrc'.

    "srcparsers.bsrc":  "src/usr/errl/parser/ebmc",
    "srcparsers.be500": "src/usr/diag/prdf/peltool/src",

    # Additional parser packages.
    # These are useful when functions may be needed for both SRC and user data
    # modules, or if there are any general utilities needed.

    "pel.prd": "src/usr/diag/prdf/peltool/common",
}

package_data = {
    "pel.prd":  [ "sigdata/*.json", "sigdata/*.py",
                  "regdata/*.json", "regdata/*.py" ]
}

setup(
    name            = "Hostboot",
    version         = "0.1",
    packages        = package_directories.keys(),
    package_dir     = package_directories,
    package_data    = package_data,
)
