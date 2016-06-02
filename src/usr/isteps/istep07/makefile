# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep07/makefile $
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
MODULE = istep07
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
HWP_PATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory

#Add all the object files required for istep07 module
OBJS += call_mss_volt.o
OBJS += call_mss_freq.o
OBJS += call_mss_eff_config.o
OBJS += call_mss_attr_update.o

# library objects needed
OBJS += spd_decoder.o
OBJS += fake_spd.o
OBJS += c_str.o
OBJS += memory_size.o
OBJS += attr_setters.o
OBJS += cas_latency.o
OBJS += eff_config.o
OBJS += timing.o
OBJS += rank.o
OBJS += sync.o


#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += ${HWP_PATH}/lib/
EXTRAINCDIR += ${HWP_PATH}/lib/dimm/
EXTRAINCDIR += ${HWP_PATH}/lib/freq/
EXTRAINCDIR += ${HWP_PATH}/lib/utils/
EXTRAINCDIR += ${HWP_PATH}/lib/eff_config/
EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest

VPATH += ${HWP_PATH} ${HWP_PATH}/lib/spd
VPATH += $(PROCEDURES_PATH)/hwp/nest ${ROOTPATH}/src/usr/fapi2
VPATH += ${HWP_PATH}/lib ${HWP_PATH}/lib/utils ${HWP_PATH}/lib/eff_config
VPATH += ${HWP_PATH}/lib/freq ${HWP_PATH}/lib/dimm

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles

#mss_volt : Calc dimm voltage
include $(HWP_PATH)/p9_mss_volt.mk

#mss_freq : Calc dimm frequency
include $(HWP_PATH)/p9_mss_freq.mk
include $(HWP_PATH)/p9_mss_freq_system.mk

#mss_eff_config : Determine effective config
include $(PROCEDURES_PATH)/hwp/nest/p9_mss_eff_grouping.mk
include $(HWP_PATH)/p9_mss_eff_config.mk
include $(HWP_PATH)/p9_mss_eff_config_thermal.mk

#mss_attr_update : MSS ATTR Overrides
include $(HWP_PATH)/p9_mss_attr_update.mk


include ${ROOTPATH}/config.mk
