# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep13/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
ROOTPATH = ../../../..
MODULE = istep13

PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/utils/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/

OBJS += call_host_disable_memvolt.o
OBJS += call_mem_pll_reset.o
OBJS += call_mem_pll_initf.o
OBJS += call_mem_pll_setup.o
OBJS += call_proc_mcs_skewadjust.o
OBJS += call_mem_startclocks.o
OBJS += call_host_enable_memvolt.o
OBJS += call_mss_scominit.o
OBJS += call_mss_ddr_phy_reset.o
OBJS += call_mss_draminit.o
OBJS += call_mss_draminit_training.o
OBJS += call_mss_draminit_trainadv.o
OBJS += call_mss_draminit_mc.o

OBJS += $(if $(CONFIG_PALMETTO_VDDR),palmetto_vddr.o,hbVddrMsg.o)


include ${ROOTPATH}/procedure.rules.mk

include ${PROCEDURES_PATH}/hwp/perv/p9_mem_pll_initf.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_mem_skewadjust.mk

#@TODO RTC:152210 Enable Istep 13 HWPs that are waiting on mirrored files
# include ${PROCEDURES_PATH}/hwp/memory/p9_mss_scominit.mk
# include ${PROCEDURES_PATH}/hwp/perv/p9_mem_pll_setup.mk
# include ${PROCEDURES_PATH}/hwp/perv/p9_mem_startclocks.mk
# include ${PROCEDURES_PATH}/hwp/nest/p9_throttle_sync.mk


#TODO RTC:152209 Implement std::enable_if in HB
# include ${PROCEDURES_PATH}/hwp/memory/p9_mss_draminit.mk
# include ${PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_training.mk
# include ${PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_mc.mk
# include ${PROCEDURES_PATH}/hwp/memory/p9_mss_ddr_phy_reset.mk

include ${ROOTPATH}/config.mk

VPATH    += ${PROCEDURES_PATH}/hwp/memory ${PROCEDURES_PATH}/hwp/nest ${PROCEDURES_PATH}/hwp/perv
