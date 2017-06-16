# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/mss/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2018
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

PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/

MSS_LIB += ${PROCEDURES_PATH}/hwp/memory
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/ccs/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/ecc/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/eff_config/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/fir/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/freq/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/mc/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/mcbist/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/phy/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/power_thermal/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/spd/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/utils/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/workarounds/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/rosetta_map/
MSS_LIB += ${ROOTPATH}/src/import/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/lrdimm/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/rdimm/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/common/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/utils/

EXTRAINCDIR += ${MSS_LIB}

# Add common and generated parts to object list.

MSS_PATH := $(PROCEDURES_PATH)/hwp/memory/lib
MSS_SOURCE := $(shell find $(MSS_PATH) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_SOURCE))

MSS_PATH_GENERIC_MEMORY := ${ROOTPATH}/src/import/generic/memory/lib
MSS_GENERIC_MEMORY_SOURCE := $(shell find $(MSS_PATH_GENERIC_MEMORY) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_GENERIC_MEMORY_SOURCE))

MODULE = isteps_mss
OBJS += $(MSS_MODULE_OBJS)
$(call BUILD_MODULE)

#HWP build tool
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk

VPATH += ${MSS_LIB}
