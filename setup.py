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
import os
from setuptools.command.build_py import build_py
"""
 Setuptools is an open source package.
 Documentation on setuptools can be found on the web.

 Hostboot Usages:

 Command to run from Hostboot repo:
   python3 setup.py bdist_wheel

   dist/Hostboot-0.1-py3-none-any.whl will be produced.

   If desired, export PELTOOL_VERSION can be defined
   to customize the version before running setup.py
     export PELTOOL_VERSION=6.7.1006

 To install the Hostboot wheel:
   pip3 install --user Hostboot-0.1.py3-non-any.whl

 If necessary, setup the environment before starting:
   scl enable rh-python36 "bash"

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
    "udparsers.b2a00":   "src/usr/htmgt/plugins/ebmc",
    "udparsers.b3100":   "src/usr/errl/plugins/ebmc/b3100",
    "udparsers.b3600":   "src/usr/expaccess/plugins/ebmc",
    "udparsers.b4500":   "src/usr/spi/plugins/ebmc",
    "udparsers.b4700":   "src/usr/pldm/plugins/ebmc",
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

    # creator id + callouts = callouts for that subsystem
    # b = hostboot
    "calloutparsers.bcallouts": "src/usr/errl/plugins/ebmc/procedures",
}

package_data = {
    "pel.prd":  [ "sigdata/*.json", "sigdata/*.py",
                  "regdata/*.json", "regdata/*.py" ]
}

# Handy debug environment tips
# HERE = os.path.abspath(os.path.dirname(__file__))
# custom_data_files is a list of tuples
custom_data_files = [( 'hostboot_data', ['img/hbotStringFile', 'img/hbicore.syms'])]


def check_environment_files():
    """
    Check the environment for the needed files

    Hostboot setup.py is invoked in two contexts:
    1 - op-build, where the img files exist, post build
    2 - OpenBMC, where the img files do NOT exist
        OpenBMC clones a clean Hostboot repo (source only)

    setup.py will fail if data_files do not exist,
    so if we encounter a missing file, clear the
    expectation and only populate the wheel with
    the usual python source files.
    """
    for i in custom_data_files:
        for x in i[1]:
            if not os.path.isfile(x):
                custom_data_files.clear()
                return

class BuildCommand(build_py):
    """
    Subclass the build_py command

    This allows the capability to add custom build
    steps.
    """
    def run(self):
        # First run the regular build_py
        build_py.run(self)
        # Now run the custom step we need
        check_environment_files()

setup(
    name            = "Hostboot",
    cmdclass        = {'build_py': BuildCommand},
    version         = os.getenv('PELTOOL_VERSION', '0.1'),
    packages        = package_directories.keys(),
    data_files      = custom_data_files,
    package_dir     = package_directories,
    package_data    = package_data,
    scripts         = ['src/build/debug/hb-memdump.sh','src/build/trace/tracelite/weave.py'],
)
