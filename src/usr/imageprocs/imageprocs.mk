# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/imageprocs/imageprocs.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018,2021
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
# ipl image processing functions
HWP_IPL_PATH := ${ROOTPATH}/src/import/chips/p10/ipl

# p10 ring id
HWP_IMAGEPROCS_PATH := ${ROOTPATH}/src/import/chips/p10/utils/imageProcs

# common ring id
HWP_COMMON_IMAGEPROCS_PATH += \
		 ${ROOTPATH}/src/import/chips/common/utils/imageProcs

# ipl customize path
IPL_CUSTOMIZE_PATH = ${ROOTPATH}/src/import/chips/p10/procedures/hwp/customize

# vpd accesssors
HWP_ACC_PATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/accessors

VPATH += ${HWP_IPL_PATH} ${HWP_IMAGEPROCS_PATH} \
		 ${HWP_COMMON_IMAGEPROCS_PATH} ${HWP_STOPUTIL_PATH}
VPATH += ${IPL_CUSTOMIZE_PATH} ${HWP_ACC_PATH}

# p10_fbc_async_utils
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest

EXTRAINCDIR += ${HWP_IPL_PATH} ${HWP_IMAGEPROCS_PATH}
EXTRAINCDIR += ${HWP_COMMON_IMAGEPROCS_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${IPL_CUSTOMIZE_PATH}
EXTRAINCDIR += ${HWP_ACC_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import

include ${ROOTPATH}/procedure.rules.mk

OBJS += p10_ipl_customize.o
OBJS += p10_ipl_section_append.o
OBJS += p10_ipl_image.o
OBJS += p10_ddco.o
OBJS += p10_tor.o
OBJS += p10_ringId.o
OBJS += common_ringId.o
OBJS += p10_scan_compression.o
OBJS += p10_get_mvpd_ring.o
OBJS += p10_mvpd_ring_funcs.o
OBJS += p10_boot_mode.o
OBJS += p10_dynamic.o
OBJS += p10_dyninit_bitvec_utils.o
OBJS += p10_fbc_async_utils.o
