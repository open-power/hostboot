# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep11/makefile $
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
MODULE = istep11
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
HWP_PATH += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/perv

OBJS += call_host_prd_hwreconfig.o
OBJS += call_cen_tp_chiplet_init1.o
OBJS += call_cen_pll_initf.o
OBJS += call_cen_pll_setup.o
OBJS += call_cen_tp_chiplet_init2.o
OBJS += call_cen_tp_arrayinit.o
OBJS += call_cen_tp_chiplet_init3.o
OBJS += call_cen_chiplet_init.o
OBJS += call_cen_arrayinit.o
OBJS += call_cen_initf.o
OBJS += call_cen_do_manual_inits.o
OBJS += call_cen_startclocks.o
OBJS += call_cen_scominits.o

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${HWP_PATH}
#EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/nest/

XIPPATH = ${ROOTPATH}/src/import/chips/p9/xip

VPATH += $(PROCEDURES_PATH)/hwp/nest ${ROOTPATH}/src/usr/fapi2
VPATH += ${ROOTPATH}/src/usr/sbe
VPATH += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/perv
VPATH += ${XIPPATH}

#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles
# Centaur common functions
include $(HWP_PATH)/cen_common_funcs.mk

#11.2 : Centaur TP chiplet init, stage #1
include $(HWP_PATH)/cen_tp_chiplet_init1.mk

#11.3 : Program Nest PLL
include $(HWP_PATH)/cen_pll_initf.mk

#11.4 : Setup Nest PLL
include $(HWP_PATH)/cen_pll_setup.mk

#11.5 : Centaur TP chiplet init, stage #2
include $(HWP_PATH)/cen_tp_chiplet_init2.mk

#11.6 : Centaur TP chiplet array init
include $(HWP_PATH)/cen_tp_arrayinit.mk

#11.7 : Centaur TP chiplet init, stage #3
include $(HWP_PATH)/cen_tp_chiplet_init3.mk

#11.8 : Centaur chiplet init
include $(HWP_PATH)/cen_chiplet_init.mk

#11.9 : Centaur chiplet array init
include $(HWP_PATH)/cen_arrayinit.mk

#11.10 : Centaur Scan overrides
include $(HWP_PATH)/cen_initf.mk

#11.11 : Manual Centaur Scans
include $(HWP_PATH)/cen_do_manual_inits.mk

#11.12 : Start Centaur Nest/MEM clocks
include $(HWP_PATH)/cen_startclocks.mk

#11.13 : Perform Centaur SCOM inits
include $(HWP_PATH)/cen_scominits.mk

include ${ROOTPATH}/config.mk
