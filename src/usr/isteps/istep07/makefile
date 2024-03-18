# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep07/makefile $
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
ROOTPATH = ../../../..
MODULE = istep07

PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
# P10
HWP_PATH_P10  += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/memory
# Explorer
HWP_PATH_EXP += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory
HWP_PATH_PMIC = $(ROOTPATH)/src/import/chips/ocmb/common/procedures/hwp/pmic
HWP_PATH_ODY = ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory

HWP_PATH += ${HWP_PATH_P10}/ ${HWP_PATH_EXP}/ ${HWP_PATH_PMIC}/ ${HWP_PATH_ODY}/

EXP_COMMON_PATH = ${ROOTPATH}/src/import/chips/ocmb/common

#Add all the object files required for istep07 module
OBJS += call_mss_volt.o
OBJS += call_mss_freq.o
OBJS += call_mss_eff_config.o
OBJS += call_mss_attr_update.o
OBJS += host_mss_attr_cleanup.o
OBJS += p10_fbc_utils.o
#mss_eff_config - Need in istep07 to group memory
OBJS += p10_mss_eff_grouping.o
OBJS += p10_sbe_scratch_regs.o
OBJS += mss_check_ddimm_config.o
OBJS += pmic_enable_utils_ddr5.o
OBJS += pmic_common_utils.o
OBJS += pmic_common_utils_ddr4.o
OBJS += pmic_common_utils_ddr5.o
OBJS += pmic_enable_utils.o
OBJS += pmic_health_check_utils_ddr5.o
OBJS += pmic_periodic_telemetry_utils_ddr5.o
OBJS += pmic_health_check_ddr5.o
OBJS += pmic_periodic_telemetry_ddr5.o
OBJS += mss_pmic_attribute_accessors_manual.o
OBJS += ody_mss_eff_config_thermal.o
OBJS += ody_throttle.o
OBJS += ody_decoder.o
OBJS += ody_kind.o
OBJS += exp_kind.o
OBJS += ody_temp_sensor_workarounds.o
OBJS += ody_thermal_init_utils.o
OBJS += ody_dts_read.o

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest
EXTRAINCDIR += ${HWP_PATH_EXP}/lib/
EXTRAINCDIR += ${HWP_PATH_EXP}/lib/shared/
EXTRAINCDIR += ${EXP_COMMON_PATH}/include/
EXTRAINCDIR += ${EXP_COMMON_PATH}/procedures/hwp/pmic/
EXTRAINCDIR += ${EXP_COMMON_PATH}/procedures/hwp/pmic/lib/
EXTRAINCDIR += $(ROOTPATH)/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/odyssey/procedures/hwp/memory/lib/
VPATH += ${HWP_PATH}
VPATH += $(PROCEDURES_PATH)/hwp/nest
VPATH += ${HWP_PATH_PMIC}/lib/eff_config
VPATH += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
VPATH += $(PROCEDURES_PATH)/hwp/perv
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/dimm/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/perv/

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles

#mss_volt : Calc dimm voltage
include $(HWP_PATH_P10)/p10_mss_volt.mk

#mss_freq : Calc dimm frequency
include $(HWP_PATH_P10)/p10_mss_freq.mk
include $(HWP_PATH_P10)/p10_mss_freq_system.mk
include $(HWP_PATH_P10)/p10_mss_eff_config.mk
include $(HWP_PATH_EXP)/exp_mss_eff_config_thermal.mk

#mss_attr_update : MSS ATTR Overrides
include $(HWP_PATH_P10)/p10_mss_attr_update.mk

include ${ROOTPATH}/config.mk
