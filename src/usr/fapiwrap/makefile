# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapiwrap/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2023
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
MODULE = fapiwrap

# Add the import path to the include path
EXTRAINCDIR += ${ROOTPATH}/src/import
# to get fapi2.H
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
# to get target.H
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
# to get common_ringId.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
# to get ffdc_includes.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
# to get chipids.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils

# HWP include directories :
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/spd_access/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/


# to get multicast_group_defs.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
# HWP objects
OBJS += exp_getidec.o
OBJS += ody_getidec.o

OBJS += fapiWrap.o

# Add HWP src directories to VPATH
VPATH += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/

include ${ROOTPATH}/config.mk
