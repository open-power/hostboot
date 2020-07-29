# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep07/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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
MODULE = istep07
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
# P9 (NIMBUS / CUMULUS / AXONE shared)
HWP_PATH_P9  += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory
# Centaur
HWP_PATH_CEN += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/memory
# Axone
HWP_PATH_P9A += ${ROOTPATH}/src/import/chips/p9a/procedures/hwp/memory
HWP_PATH_P9A += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic
# Explorer
HWP_PATH_EXP += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory
HWP_PATH_EXP += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib

HWP_PATH += ${HWP_PATH_P9}/ ${HWP_PATH_CEN}/ ${HWP_PATH_P9A}/ ${HWP_PATH_EXP}/

EXP_COMMON_PATH = ${ROOTPATH}/src/import/chips/ocmb/explorer/common

#Add all the object files required for istep07 module
OBJS += call_mss_volt.o
OBJS += call_mss_freq.o
OBJS += call_mss_eff_config.o
OBJS += call_mss_attr_update.o
OBJS += host_mss_attr_cleanup.o
OBJS += p9c_mss_funcs.o

#mss_eff_config - Need in istep07 to group memory
OBJS+=p9_mss_eff_grouping.o

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += ${HWP_PATH_P9}/lib/
EXTRAINCDIR += ${HWP_PATH_P9}/lib/dimm/
EXTRAINCDIR += ${HWP_PATH_P9}/lib/freq/
EXTRAINCDIR += ${HWP_PATH_P9}/lib/utils/
EXTRAINCDIR += ${HWP_PATH_P9}/lib/eff_config/
EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv/
EXTRAINCDIR += ${HWP_PATH_CEN}/lib/
EXTRAINCDIR += ${HWP_PATH_CEN}/lib/shared/
EXTRAINCDIR += ${HWP_PATH_CEN}/lib/utils/
EXTRAINCDIR += ${HWP_PATH_EXP}/lib/eff_config/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${EXP_COMMON_PATH}/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/include
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib

VPATH += ${HWP_PATH} ${HWP_PATH_P9}/lib/spd
VPATH += $(PROCEDURES_PATH)/hwp/nest ${ROOTPATH}/src/usr/fapi2
VPATH += ${PROCEDURES_PATH}/hwp/perv
VPATH += ${HWP_PATH_P9}/lib ${HWP_PATH_P9}/lib/utils ${HWP_PATH_P9}/lib/eff_config
VPATH += ${HWP_PATH_P9A}/lib/eff_config
VPATH += ${HWP_PATH_P9}/lib/freq ${HWP_PATH_P9}/lib/dimm
VPATH += ${ROOTPATH}/src/usr/sbe

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles

#mss_volt : Calc dimm voltage
include $(HWP_PATH_P9)/p9_mss_volt.mk
include $(HWP_PATH_CEN)/p9c_mss_volt.mk
include $(HWP_PATH_CEN)/p9c_mss_volt_vddr_offset.mk
include $(HWP_PATH_CEN)/p9c_mss_volt_dimm_count.mk
include $(HWP_PATH_CEN)/mss_dynamic_vid_utils.mk


#mss_freq : Calc dimm frequency
include $(HWP_PATH_P9)/p9_mss_freq.mk
include $(HWP_PATH_P9)/p9_mss_freq_system.mk
include $(HWP_PATH_CEN)/p9c_mss_freq.mk
include $(HWP_PATH_P9)/p9_mss_eff_config.mk
include $(HWP_PATH_P9)/p9_mss_eff_config_thermal.mk
include $(HWP_PATH_P9)/p9_mss_bulk_pwr_throttles.mk
include $(HWP_PATH_CEN)/p9c_mss_eff_config.mk
include $(HWP_PATH_CEN)/p9c_mss_eff_config_thermal.mk
include $(HWP_PATH_CEN)/p9c_mss_bulk_pwr_throttles.mk
include $(HWP_PATH_CEN)/p9c_mss_eff_mb_interleave.mk


# Axone only objects
OBJS += $(if $(CONFIG_AXONE),p9a_mss_volt.o,)
OBJS += $(if $(CONFIG_AXONE),p9a_mss_freq.o,)
OBJS += $(if $(CONFIG_AXONE),p9a_mss_freq_system.o,)
OBJS += $(if $(CONFIG_AXONE),p9a_mss_eff_config.o,)
OBJS += $(if $(CONFIG_AXONE),exp_mss_eff_config_thermal.o,)
OBJS += $(if $(CONFIG_AXONE),pmic_efd_processing.o,)

#host_mss_attr_cleanup : MSS ATTR Cleanup
include $(HWP_PATH_CEN)/p9c_mss_attr_cleanup.mk

#mss_attr_update : MSS ATTR Overrides
include $(HWP_PATH_P9)/p9_mss_attr_update.mk

include ${ROOTPATH}/config.mk
