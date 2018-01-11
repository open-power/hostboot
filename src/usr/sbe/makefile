# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbe/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2018
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
ROOTPATH = ../../..
MODULE = sbe

##      support for fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc
HWP_CUSTOMIZE_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/customize
EXTRAINCDIR += ${HWP_CUSTOMIZE_PATH}/
HWP_ACCESSORS_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/accessors
EXTRAINCDIR += ${HWP_ACCESSORS_PATH}/
HWP_XIP_PATH += ${ROOTPATH}/src/import/chips/p9/xip
EXTRAINCDIR += ${HWP_XIP_PATH}/
UTILS_PATH  += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
CEN_UTILS_PATH  += ${ROOTPATH}/src/import/chips/centaur/utils/imageProcs
COMMON_UTILS_PATH += ${ROOTPATH}/src/import/chips/common/utils/imageProcs

OBJS += sbe_update.o

SUBDIRS += test.d


include ${ROOTPATH}/config.mk
