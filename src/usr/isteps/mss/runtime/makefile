# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/mss/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2023
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

HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../../..
MODULE = mss_rt

IMPORT_PATH        = ${ROOTPATH}/src/import
PROCEDURES_PATH    = ${IMPORT_PATH}/chips/p10/procedures

include ${ROOTPATH}/src/build/mkrules/script.rules.mk
include ${ROOTPATH}/src/build/mkrules/verbose.rules.mk

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${IMPORT_PATH}/

# Generic support
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
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/spd/lrdimm/ddr4/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/spd/rdimm/ddr4/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/spd/common/ddr4/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/spd/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/utils/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/utils/shared/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/utils/freq/
MSS_LIB += ${IMPORT_PATH}/generic/memory/lib/utils/mcbist
MSS_LIB += ${IMPORT_PATH}/generic/memory/

MSS_LIB += ${IMPORT_PATH}/chips/p10/procedures/hwp/memory/lib/utils/
MSS_LIB += ${IMPORT_PATH}/chips/ocmb/explorer/procedures/hwp/memory/lib/

EXTRAINCDIR += ${MSS_LIB}

VPATH += ${MSS_LIB}

#######
# Add the specific files we need for HBRT
OBJS += gen_mss_mcbist_patterns.o
OBJS += exp_attribute_accessors_manual.o


#HWP build tool
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk
