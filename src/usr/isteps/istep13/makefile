# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep13/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2023
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

OCMB_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/ocmb/procedures
EXP_INCLUDE_PATH     = ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXPLORER_HWP_PATH  = ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
P10_PROCEDURE_PATH   = ${ROOTPATH}/src/import/chips/p10/procedures/hwp
ODYSSEY_HWP_PATH     = ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/
ODYSSEY_INC_PATH     = ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/

EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}
EXTRAINCDIR += ${OCMB_PROCEDURES_PATH}/hwp/initfiles/
EXTRAINCDIR += ${EXP_INCLUDE_PATH}
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/odyssey/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/memory/
EXTRAINCDIR += ${ODYSSEY_INC_PATH}
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib/phy
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib/workarounds
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib/fir
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib/power_thermal
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib

# from src/usr/isteps/istep13
OBJS += call_mss_scominit.o
OBJS += call_mss_draminit.o
OBJS += call_mss_draminit_mc.o

#HWP build tool
include ${ROOTPATH}/procedure.rules.mk

# EKB HWP
OBJS += exp_scominit.o
OBJS += explorer_mds_scom.o
OBJS += explorer_scom.o
OBJS += exp_draminit.o
OBJS += exp_draminit_mc.o
OBJS += p10_throttle_sync.o
OBJS += ody_scominit.o
OBJS += ody_ddrphyinit.o
OBJS += ody_load_imem.o
OBJS += ody_load_dmem.o
OBJS += ody_sppe_draminit.o
OBJS += ody_load_pie.o
OBJS += ody_draminit_mc.o
OBJS += ody_enable_ecc.o
OBJS += ody_draminit_utils.o
OBJS += ody_phy_utils.o
OBJS += ody_phy_reset.o
OBJS += ody_dfi_complete_workarounds.o
OBJS += odyssey_scom.o
OBJS += ody_fir.o
OBJS += ody_throttle.o
OBJS += ody_draminit_procedure.o
OBJS += odyssey_mp_scom.o
OBJS += ody_ddrphy_phyinit_config.o
OBJS += dwc_ddrphy_phyinit_I_loadPIEImage.o
OBJS += dwc_ddrphy_phyinit_LoadPieProdCode_rdimm.o
OBJS += dwc_ddrphy_phyinit_LoadPieProdCode.o


include ${ROOTPATH}/config.mk

VPATH += ${EXPLORER_HWP_PATH}
VPATH += ${OCMB_PROCEDURES_PATH}/hwp/initfiles/
VPATH += ${P10_PROCEDURE_PATH}/memory/
VPATH += ${ODYSSEY_HWP_PATH}/memory/
VPATH += ${ODYSSEY_HWP_PATH}/memory/lib/phy/
VPATH += ${ODYSSEY_HWP_PATH}/memory/lib/workarounds/
VPATH += ${ODYSSEY_HWP_PATH}/memory/lib/fir/
VPATH += ${ODYSSEY_HWP_PATH}/memory/lib/power_thermal/
