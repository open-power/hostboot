# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwplibs/nest/nestmemutils.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2020
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

# NEST Memory utils functions
ROOTPATH=../../../..

HWP_NEST_MEM_UTILS_PATH := ${ROOTPATH}/src/build/tools/extern/ekb/chips/p10/procedures/hwp/nest

EXTRAINCDIR += ${HWP_NEST_MEM_UTILS_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs

VPATH += ${HWP_NEST_MEM_UTILS_PATH}

include ${ROOTPATH}/procedure.rules.mk
