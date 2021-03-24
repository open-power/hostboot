# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep13/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
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
GEM_PROCEDURES_PATH  = ${ROOTPATH}/src/import/chips/ocmb/gemini/procedures

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
EXTRAINCDIR += ${GEM_PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${GEM_PROCEDURES_PATH}/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils

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
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_scominit.o)

include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_ddrphy_scom.mk
include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_mca_scom.mk
include ${P9_PROCEDURES_PATH}/hwp/initfiles/p9n_mcbist_scom.mk

#Dram init
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_training.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_mc.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_ddr_phy_reset.mk
include ${P9_PROCEDURES_PATH}/hwp/memory/p9_mss_draminit_training_adv.mk

OBJS += $(if $(CONFIG_AXONE),,p9c_mss_mcbist.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_mcbist_common.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_mcbist_address.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_generic_shmoo.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_draminit.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_draminit_mc.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_draminit_training.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_ddr_phy_reset.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_draminit_training_advanced.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_mrs6_DDR4.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_ddr4_pda.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_ddr4_funcs.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_termination_control.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_access_delay_reg.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_unmask_errors.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_dimmBadDqBitmapFuncs.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_funcs.o)
OBJS += $(if $(CONFIG_AXONE),,centaur_mbs_scom.o)
OBJS += $(if $(CONFIG_AXONE),,centaur_mba_scom.o)
OBJS += $(if $(CONFIG_AXONE),,centaur_ddrphy_scom.o)
OBJS += $(if $(CONFIG_AXONE),,p9c_mss_row_repair.o)

OBJS += $(if $(CONFIG_AXONE),exp_scominit.o,)
OBJS += $(if $(CONFIG_AXONE),explorer_scom.o,)
OBJS += $(if $(CONFIG_AXONE),exp_draminit_mc.o,)
OBJS += $(if $(CONFIG_AXONE),exp_draminit.o,)
OBJS += $(if $(CONFIG_AXONE),gem_draminit.o,)
OBJS += $(if $(CONFIG_AXONE),explorer_mds_scom.o,)

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
VPATH += $(if $(CONFIG_AXONE),${GEM_PROCEDURES_PATH}/hwp/memory,)
VPATH += $(if $(CONFIG_AXONE),${OCMB_PROCEDURES_PATH}/hwp/initfiles/,)
