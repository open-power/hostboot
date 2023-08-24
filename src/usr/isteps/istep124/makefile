# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep124/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2023
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
MODULE = istep124

OCMB_PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/ocmb/procedures

ODYSSEY_HWP_PATH   = ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/
ODYSSEY_INC_PATH   = ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ocmbupd/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${OCMB_PROCEDURES_PATH}/hwp/initfiles
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/memory/lib
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/io
EXTRAINCDIR += ${ODYSSEY_HWP_PATH}/io/common
EXTRAINCDIR += ${ODYSSEY_INC_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/

# VPATH += $(P10_IO_HWP_PATH)

OBJS += call_ody_omi_hss_ppe_load.o
OBJS += call_ody_omi_hss_config.o
OBJS += call_ody_omi_hss_ppe_start.o
OBJS += call_ody_omi_hss_bist_init.o
OBJS += call_ody_omi_hss_bist_start.o
OBJS += call_ody_omi_hss_bist_poll.o
OBJS += call_ody_omi_hss_bist_cleanup.o
OBJS += call_ody_omi_hss_init.o
OBJS += call_ody_omi_hss_dccal_start.o
OBJS += call_ody_omi_hss_dccal_poll.o

#Required before all the <procedure>.mk are included
include ${ROOTPATH}/procedure.rules.mk

VPATH += ${ODYSSEY_HWP_PATH}/io
VPATH += ${ODYSSEY_HWP_PATH}/io/common

OBJS += ody_omi_hss_ppe_load.o
OBJS += ody_omi_hss_config.o
OBJS += ody_omi_hss_ppe_start.o
OBJS += ody_omi_hss_bist_init.o
OBJS += ody_omi_hss_bist_start.o
OBJS += ody_omi_hss_bist_poll.o
OBJS += ody_omi_hss_bist_cleanup.o
OBJS += ody_omi_hss_init.o
OBJS += ody_omi_hss_dccal_start.o
OBJS += ody_omi_hss_dccal_poll.o

include ${ROOTPATH}/config.mk
