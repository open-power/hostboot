# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbe/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2017
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

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
HWP_CUSTOMIZE_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/customize
EXTRAINCDIR += ${HWP_CUSTOMIZE_PATH}/
HWP_ACCESSORS_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/accessors
EXTRAINCDIR += ${HWP_ACCESSORS_PATH}/
HWP_XIP_PATH += ${ROOTPATH}/src/import/chips/p9/xip
EXTRAINCDIR += ${HWP_XIP_PATH}/
UTILS_PATH  += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${UTILS_PATH}/

OBJS += sbe_update.o

SUBDIRS += test.d

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${HWP_CUSTOMIZE_PATH} ${HWP_ACCESSORS_PATH} ${HWP_XIP_PATH}
VPATH += ${UTILS_PATH}

include ${ROOTPATH}/procedure.rules.mk

include ${UTILS_PATH}/p9_dd_container.mk
include ${HWP_CUSTOMIZE_PATH}/p9_xip_customize.mk
include ${HWP_CUSTOMIZE_PATH}/p9_xip_section_append.mk
include ${HWP_ACCESSORS_PATH}/p9_get_mvpd_ring.mk
include ${HWP_ACCESSORS_PATH}/p9_mvpd_ring_funcs.mk
include ${HWP_XIP_PATH}/p9_xip_image.mk
include ${UTILS_PATH}/p9_ring_identification.mk
include ${UTILS_PATH}/p9_ringId.mk
include ${UTILS_PATH}/p9_scan_compression.mk
include ${UTILS_PATH}/p9_tor.mk

include ${ROOTPATH}/config.mk
