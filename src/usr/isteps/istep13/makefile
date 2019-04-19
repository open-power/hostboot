# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep13/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2019
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

P9_PROCEDURES_PATH   = ${ROOTPATH}/src/import/chips/p9/procedures
CEN_PROCEDURES_PATH  = ${ROOTPATH}/src/import/chips/centaur/procedures
OCMB_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/ocmb/procedures
EXP_PROCEDURES_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures
EXP_INCLUDE_PATH     = ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/


#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2

EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/memory/lib
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/memory/lib/utils
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/memory/lib/mc/
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/memory/lib/fir/
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/nest
EXTRAINCDIR += ${P9_PROCEDURES_PATH}/hwp/initfiles
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/
EXTRAINCDIR += ${CEN_PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/
EXTRAINCDIR += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/shared/
EXTRAINCDIR += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/utils/
EXTRAINCDIR += ${CEN_PROCEDURES_PATH}/hwp/initfiles
EXTRAINCDIR += ${EXP_PROCEDURES_PATH}/hwp/memory/
EXTRAINCDIR += ${OCMB_PROCEDURES_PATH}/hwp/initfiles/
EXTRAINCDIR += ${EXP_INCLUDE_PATH}/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/

# from src/usr/isteps/istep13
OBJS += call_host_disable_memvolt.o
OBJS += call_mem_pll_reset.o
OBJS += call_mem_pll_initf.o
OBJS += call_mem_pll_setup.o
OBJS += call_mem_startclocks.o
OBJS += call_host_enable_memvolt.o
OBJS += call_mss_scominit.o
OBJS += call_mss_ddr_phy_reset.o
OBJS += call_mss_draminit.o
OBJS += call_mss_draminit_training.o
OBJS += call_mss_draminit_trainadv.o
OBJS += call_mss_draminit_mc.o


#HWP build tool
include ${ROOTPATH}/procedure.rules.mk

# PLL HWPs
include ${P9_PROCEDURES_PATH}/hwp/perv/p9_mem_pll_initf.mk
include ${P9_PROCEDURES_PATH}/hwp/perv/p9_mem_pll_setup.mk
include ${P9_PROCEDURES_PATH}/hwp/perv/p9_mem_pll_reset.mk

#Start Memclocks
include ${P9_PROCEDURES_PATH}/hwp/perv/p9_mem_startclocks.mk

#Scom init
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_scominit.mk
include ${P9_PROCEDURES_PATH}/hwp/nest/p9_throttle_sync.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_scominit.mk

include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_ddrphy_scom.mk
include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_mca_scom.mk
include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_mcbist_scom.mk

#Dram init
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_training.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_mc.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_ddr_phy_reset.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_training_adv.mk

include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_mcbist.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_mcbist_common.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_mcbist_address.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_generic_shmoo.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_draminit.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_draminit_mc.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_draminit_training.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_ddr_phy_reset.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_draminit_training_advanced.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_mrs6_DDR4.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_ddr4_pda.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_ddr4_funcs.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_termination_control.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_access_delay_reg.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_unmask_errors.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_dimmBadDqBitmapFuncs.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_funcs.mk
include ${CEN_PROCEDURES_PATH}/hwp/initfiles/centaur_mbs_scom.mk
include ${CEN_PROCEDURES_PATH}/hwp/initfiles/centaur_mba_scom.mk
include ${CEN_PROCEDURES_PATH}/hwp/initfiles/centaur_ddrphy_scom.mk
include ${CEN_PROCEDURES_PATH}/hwp/memory/p9c_mss_row_repair.mk

OBJS += $(if $(CONFIG_AXONE),exp_scominit.o,)
OBJS += $(if $(CONFIG_AXONE),explorer_scom.o,)
OBJS += $(if $(CONFIG_AXONE),exp_draminit_mc.o,)

include ${ROOTPATH}/config.mk

VPATH    += ${P9_PROCEDURES_PATH}/hwp/memory ${P9_PROCEDURES_PATH}/hwp/nest ${P9_PROCEDURES_PATH}/hwp/perv ${P9_PROCEDURES_PATH}/hwp/initfiles/
VPATH    += ${P9_PROCEDURES_PATH}/hwp/memory/lib/ccs/ ${P9_PROCEDURES_PATH}/hwp/memory/lib/dimm/ ${P9_PROCEDURES_PATH}/hwp/memory/lib/utils/ ${P9_PROCEDURES_PATH}/hwp/memory/lib/phy/
VPATH    += ${P9_PROCEDURES_PATH}/hwp/memory/lib/mc/
VPATH    += ${P9_PROCEDURES_PATH}/hwp/memory/lib/fir/
VPATH    += ${P9_PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4/
VPATH    += ${CEN_PROCEDURES_PATH}
VPATH    += ${CEN_PROCEDURES_PATH}/hwp/memory/
VPATH    += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/
VPATH    += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/shared/
VPATH    += ${CEN_PROCEDURES_PATH}/hwp/memory/lib/utils/
VPATH    += ${CEN_PROCEDURES_PATH}/hwp/initfiles

VPATH += $(if $(CONFIG_AXONE),${EXP_PROCEDURES_PATH}/hwp/memory,)
VPATH += $(if $(CONFIG_AXONE),${OCMB_PROCEDURES_PATH}/hwp/initfiles/,)
