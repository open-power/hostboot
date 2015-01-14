# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/dram_training/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
# [+] Google Inc.
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
ROOTPATH = ../../../../..

MODULE = dram_training

CFLAGS += $(if $(CONFIG_VPD_GETMACRO_USE_EFF_ATTR), -D FAPI_MSSLABONLY -D FAPI_LRDIMM)

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here. 
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/???
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_training
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_mc
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_startclocks
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_pll_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_lrdimm_funcs
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/cen_stopclocks
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dram_initialization/proc_throttle_sync

##  NOTE: add new object files when you add a new HWP
OBJS += dram_training.o
OBJS += mss_draminit.o
OBJS += mss_funcs.o
OBJS += mss_draminit_mc.o
OBJS += mss_draminit_training.o
OBJS += mss_ddr_phy_reset.o
OBJS += mss_termination_control.o
OBJS += cen_mem_startclocks.o
OBJS += mss_scominit.o
OBJS += cen_mem_pll_initf.o
OBJS += cen_mem_pll_setup.o
OBJS += mss_draminit_training_advanced.o
OBJS += mss_access_delay_reg.o
OBJS += mss_generic_shmoo.o
OBJS += mss_mcbist.o
OBJS += mss_mcbist_common.o
OBJS += mss_mcbist_address.o
OBJS += mss_lrdimm_funcs.o
OBJS += cen_stopclocks.o


#
OBJS += $(if $(CONFIG_PALMETTO_VDDR),palmetto_vddr.o, hbVddrMsg.o)

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_training
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_mc
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_ddr_phy_reset
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_startclocks
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mem_pll_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/mss_lrdimm_funcs
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dram_training/cen_stopclocks


include ${ROOTPATH}/config.mk
