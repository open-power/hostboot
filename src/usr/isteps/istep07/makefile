# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep07/makefile $
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
ROOTPATH = ../../../..
MODULE = istep07
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
HWP_PATH_1 += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory
HWP_PATH_2 += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/memory
HWP_PATH += ${HWP_PATH_1}/ ${HWP_PATH_2}/

#Add all the object files required for istep07 module
OBJS += call_mss_volt.o
OBJS += call_mss_freq.o
OBJS += call_mss_eff_config.o
OBJS += call_mss_attr_update.o
OBJS += host_mss_attr_cleanup.o
#mss_eff_config - Need in istep07 to group memory
OBJS+=p9_mss_eff_grouping.o

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += ${HWP_PATH_1}/lib/
EXTRAINCDIR += ${HWP_PATH_1}/lib/dimm/
EXTRAINCDIR += ${HWP_PATH_1}/lib/freq/
EXTRAINCDIR += ${HWP_PATH_1}/lib/utils/
EXTRAINCDIR += ${HWP_PATH_1}/lib/eff_config/
EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest
EXTRAINCDIR += ${HWP_PATH_2}/lib/
EXTRAINCDIR += ${HWP_PATH_2}/lib/shared/
EXTRAINCDIR += ${HWP_PATH_2}/lib/utils/

VPATH += ${HWP_PATH} ${HWP_PATH_1}/lib/spd
VPATH += $(PROCEDURES_PATH)/hwp/nest ${ROOTPATH}/src/usr/fapi2
VPATH += ${HWP_PATH_1}/lib ${HWP_PATH_1}/lib/utils ${HWP_PATH_1}/lib/eff_config
VPATH += ${HWP_PATH_1}/lib/freq ${HWP_PATH_1}/lib/dimm
VPATH += ${ROOTPATH}/src/usr/sbe

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles

#mss_volt : Calc dimm voltage
include $(HWP_PATH_1)/p9_mss_volt.mk
include $(HWP_PATH_2)/p9c_mss_volt.mk

#mss_freq : Calc dimm frequency
include $(HWP_PATH_1)/p9_mss_freq.mk
include $(HWP_PATH_1)/p9_mss_freq_system.mk
include $(HWP_PATH_2)/p9c_mss_freq.mk
include $(HWP_PATH_1)/p9_mss_eff_config.mk
include $(HWP_PATH_1)/p9_mss_eff_config_thermal.mk
include $(HWP_PATH_1)/p9_mss_bulk_pwr_throttles.mk
include $(HWP_PATH_2)/p9c_mss_eff_config.mk
include $(HWP_PATH_2)/p9c_mss_eff_config_thermal.mk
include $(HWP_PATH_2)/p9c_mss_bulk_pwr_throttles.mk
include $(HWP_PATH_2)/p9c_mss_eff_mb_interleave.mk
#host_mss_attr_cleanup : MSS ATTR Cleanup
include $(HWP_PATH_2)/p9c_mss_attr_cleanup.mk

#mss_attr_update : MSS ATTR Overrides
include $(HWP_PATH_1)/p9_mss_attr_update.mk

include ${ROOTPATH}/config.mk
