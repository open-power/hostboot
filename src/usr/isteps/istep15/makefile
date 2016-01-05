# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep15/makefile $
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
MODULE = istep15
PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
EXTRAINCDIR += ${PROCEDURES_PATH}/stop_reg/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib/
EXTRAINCDIR += ${PROCEDURES_PATH}/utils/stopreg/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/xip/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${PROCEDURES_PATH}/ppe/include/registers/

OBJS += host_build_stop_image.o
OBJS += proc_set_pba_homer_bar.o
OBJS += host_establish_ex_chiplet.o
OBJS += host_start_stop_engine.o

#@TODO RTC:147621 Pull p9_stop_util into a seperate library
OBJS += p9_stop_util.o


include ${ROOTPATH}/procedure.rules.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_pm_pfet_init.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_pm_pba_bar_config.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_pm_set_homer_bar.mk
# include $(PROCEDURES_PATH)/hwp/pm/p9_pm_stop_gpe_init.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_pm_utils.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_update_ec_eq_state.mk
include $(PROCEDURES_PATH)/hwp/pm/p9_hcode_image_build.mk
include $(PROCEDURES_PATH)/utils/stopreg/p9_stop_api.mk
# include $(PROCEDURES_PATH)/hwp/pm/p9_pm_pba_init.mk
include ${ROOTPATH}/src/import/chips/p9/xip/p9_xip_image.mk




include ${ROOTPATH}/config.mk

VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
VPATH += ${ROOTPATH}/src/import/chips/p9/xip/