# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep15/makefile $
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
MODULE = istep15

PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p10/procedures

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib/
EXTRAINCDIR += ${PROCEDURES_PATH}/utils/stopreg/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/customize/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/corecache/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/

OBJS += host_build_stop_image.o
OBJS += proc_set_homer_bar.o
OBJS += host_start_stop_engine.o
OBJS += host_establish_ec_chiplet.o
OBJS += p10_stop_api.o
OBJS += p10_stop_util.o

include ${ROOTPATH}/procedure.rules.mk
include $(PROCEDURES_PATH)/hwp/pm/p10_pm_set_homer_bar.mk
include $(PROCEDURES_PATH)/hwp/corecache/p10_hcd_corecache_clock_control.mk
include $(PROCEDURES_PATH)/hwp/corecache/p10_hcd_core_poweroff.mk
include $(PROCEDURES_PATH)/hwp/pm/p10_update_ec_state.mk

# This line is required by p10_update_ec_state.mk for pulling in
# additional modules required by that procedure.
OBJS += ${OBJ}

include ${ROOTPATH}/config.mk

VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
VPATH += ${PROCEDURES_PATH}/hwp/corecache/
VPATH += ${PROCEDURES_PATH}/hwp/perv
VPATH += ${PROCEDURES_PATH}/utils/stopreg/
