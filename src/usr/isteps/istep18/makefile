# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep18/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2022
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
MODULE = istep18

# Create some aliases for paths
SRC_IMPORT_PATH = ${ROOTPATH}/src/import
P10_PATH = ${SRC_IMPORT_PATH}/chips/p10
P10_PROCEDURES_PATH = ${P10_PATH}/procedures/hwp
OCMB_PATH = ${SRC_IMPORT_PATH}/chips/ocmb
EXP_PROCEDURES_PATH = ${OCMB_PATH}/explorer/procedures/hwp

# Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/usr/initservice/istepdispatcher
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/common/utils/imageProcs
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/common/utils/scomt
EXTRAINCDIR += ${SRC_IMPORT_PATH}/hwpf/fapi2/include
EXTRAINCDIR += ${P10_PROCEDURES_PATH}/lib
EXTRAINCDIR += ${P10_PROCEDURES_PATH}/nest
EXTRAINCDIR += ${P10_PROCEDURES_PATH}/pm
EXTRAINCDIR += ${P10_PROCEDURES_PATH}/perv
EXTRAINCDIR += ${P10_PROCEDURES_PATH}/memory
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/ocmb/explorer/procedures/hwp/memory
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/ocmb/explorer/procedures/hwp/memory/lib
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/ocmb/explorer/common/include
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/odyssey/procedures/hwp/memory/lib/
EXTRAINCDIR += ${SRC_IMPORT_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/istep18

# Add the sub step object files
OBJS += call_tod_setup.o
OBJS += call_tod_init.o
# Istep 18 support for multinode stitching
OBJS += establish_system_smp.o
OBJS += htmgt_memthrottles.o
OBJS += p10_mss_utils_to_throttle.o
OBJS += exp_bulk_pwr_throttles.o

# Include the makefiles to compile the HWPs needed by the sub steps
include ${ROOTPATH}/procedure.rules.mk
include ${P10_PROCEDURES_PATH}/nest/p10_tod_init.mk
include ${P10_PROCEDURES_PATH}/nest/p10_tod_setup.mk
include ${P10_PROCEDURES_PATH}/nest/p10_tod_save_config.mk
include ${P10_PROCEDURES_PATH}/pm/p10_block_wakeup_intr.mk

# Add the path where HWPs object files are located
VPATH += ${P10_PROCEDURES_PATH}/nest
VPATH += ${P10_PROCEDURES_PATH}/pm
VPATH += ${P10_PROCEDURES_PATH}/memory
VPATH += ${EXP_PROCEDURES_PATH}/memory

# Include the configuration after everything else has been added
include ${ROOTPATH}/config.mk

