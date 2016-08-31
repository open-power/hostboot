# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/mss/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/ccs/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/ecc/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/eff_config/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/fir/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/freq/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/mc/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/mcbist/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/phy/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/spd/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/spd/common/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/spd/rdimm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/termination/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/memory/lib/utils/

# Add common and generated parts to object list.

MSS_PATH := $(PROCEDURES_PATH)/hwp/memory/lib
MSS_SOURCE := $(shell find $(MSS_PATH) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_SOURCE))

MODULE = isteps_mss
OBJS += $(MSS_MODULE_OBJS)
$(call BUILD_MODULE)

#HWP build tool
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk

VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/ccs/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/ecc/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/eff_config/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/fir/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/freq/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/mc/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/mcbist/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/phy/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/spd/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/spd/common/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/spd/rdimm/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/spd/lrdimm/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/termination/
VPATH    += ${PROCEDURES_PATH}/hwp/memory/lib/utils/
