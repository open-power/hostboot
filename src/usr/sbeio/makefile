# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2024
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
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
MODULE = sbeio

# pull in .mk common between sbeio and sbeio_rt
include common/common.mk

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/sppe
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ocmbupd/

# sbeio's unique objects
OBJS += sbe_psudd.o
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
OBJS += sbe_setFFDCAddr.o
OBJS += sbe_codeUpdate.o
OBJS += sbe_memRegionMgr.o
OBJS += sbe_psuTPMExtendMode.o
OBJS += sbe_securityListBinDump.o
OBJS += sbe_exitCacheContained.o
OBJS += p10_extract_sbe_rc.o
OBJS += p10_ppe_utils.o
OBJS += p10_ppe_common.o
OBJS += sbe_psuSyncFabTopoIdTable.o
OBJS += sbe_halt.o
OBJS += p10_clock_test.o
OBJS += p10_clock_test_cmn.o
OBJS += ody_code_getlevels.o
OBJS += ody_code_update.o
OBJS += sbe_getCodeLevels.o
OBJS += errlud_sbeio.o
OBJS += sbe_flashCheck.o
OBJS += sbe_testFfdc.o
OBJS += sbe_ody_hw_dump.o

# sbeio's sub directories
SUBDIRS += test.d
SUBDIRS += runtime.d

VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/sppe

include ${ROOTPATH}/config.mk
