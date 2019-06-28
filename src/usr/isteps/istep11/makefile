# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep11/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2019
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
MODULE = istep11
# FIXME RTC: 210975 Uncomment the EKB paths when the time comes
#PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

#OBJS += call_host_prd_hwreconfig.o
#OBJS += call_cen_tp_chiplet_init1.o
#OBJS += call_cen_pll_initf.o
#OBJS += call_cen_pll_setup.o
#OBJS += call_cen_tp_chiplet_init2.o
#OBJS += call_cen_tp_arrayinit.o
#OBJS += call_cen_tp_chiplet_init3.o
#OBJS += call_cen_chiplet_init.o
#OBJS += call_cen_arrayinit.o
#OBJS += call_cen_initf.o
#OBJS += call_cen_do_manual_inits.o
#OBJS += call_cen_startclocks.o
#OBJS += call_cen_scominits.o

#Add all the extra include paths
#EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/sbe/
#EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
#EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
#EXTRAINCDIR += ${HWP_PATH}
#EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest/

#XIPPATH = ${ROOTPATH}/src/import/chips/p9/xip

#VPATH += $(PROCEDURES_PATH)/hwp/nest ${ROOTPATH}/src/usr/fapi2
#VPATH += ${ROOTPATH}/src/usr/sbe
#VPATH += ${XIPPATH}

#Required include before all the procedure.mk are included
#include ${ROOTPATH}/procedure.rules.mk

include ${ROOTPATH}/config.mk
