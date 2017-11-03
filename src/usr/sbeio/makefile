# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2018
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
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
MODULE = sbeio

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe/

OBJS += sbe_psudd.o
OBJS += sbe_utils.o
OBJS += sbe_secureHwp.o
OBJS += sbe_coreStateControl.o
OBJS += sbe_psuReadSeeprom.o
OBJS += sbe_psuQuiesce.o
OBJS += sbe_stashKeyAddr.o
OBJS += sbe_continueMpipl.o
OBJS += sbe_systemConfig.o
OBJS += sbe_fifodd.o
OBJS += sbe_scomAccess.o
OBJS += sbe_scomAccessdd.o
OBJS += sbe_ffdc_parser.o
OBJS += sbe_setFFDCAddr.o
OBJS += sbe_getSBEFFDC.o
OBJS += sbe_memRegionMgr.o
OBJS += sbe_fifo_buffer.o
OBJS += sbe_ffdc_package_parser.o
OBJS += sbe_attn.o
OBJS += sbe_retry_handler.o

VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/

include ${ROOTPATH}/procedure.rules.mk

#Not using the ekb mk file because it includes extra files
# that we already include in libfapi2:
# - p9_ppe_utils.o
#include ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.mk
OBJS += p9_extract_sbe_rc.o
OBJS += p9_ppe_common.o


SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk
