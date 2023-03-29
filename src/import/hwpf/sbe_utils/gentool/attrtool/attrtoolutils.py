# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/sbe_utils/gentool/attrtool/attrtoolutils.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022,2023
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

class vprint:
    '''
    Class to support verbose logging based verbose flag
    '''
    cv_verbose:bool = False

    def set_verbose(verbose:bool):
        vprint.cv_verbose = verbose

    # log API is implemented inside the constructor to support simpe function
    # like API without any object.
    # eg;- vprint("message to be logged")
    def __init__(self, *args) -> None:
        if(vprint.cv_verbose):
            print(*args)


def hexint(arg):
    return int(arg, 16)
