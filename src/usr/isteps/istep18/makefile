# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep18/makefile $
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

MODULE = istep18

PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures/hwp
##      support for Targeting and fapi
EXTRAINCDIR += ${PROCEDURES_PATH}
EXTRAINCDIR += ${PROCEDURES_PATH}/nest
EXTRAINCDIR += ${PROCEDURES_PATH}/pm
EXTRAINCDIR += ${PROCEDURES_PATH}/lib
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/usr/initservice/istepdispatcher
EXTRAINCDIR += ${ROOTPATH}/src/usr/include/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps

## pointer to common HWP files

OBJS += call_tod_init.o
OBJS += call_tod_setup.o
OBJS += smp_unfencing_inter_enclosure_abus_links.o
OBJS += establish_system_smp.o

include ${ROOTPATH}/procedure.rules.mk
include ${PROCEDURES_PATH}/nest/p9_tod_init.mk
include ${PROCEDURES_PATH}/nest/p9_tod_setup.mk
include ${PROCEDURES_PATH}/nest/p9_tod_save_config.mk
include ${ROOTPATH}/config.mk

VPATH += ${PROCEDURES_PATH}
VPATH += ${PROCEDURES_PATH}/pm/
VPATH += ${PROCEDURES_PATH}/nest/
VPATH += ${PROCEDURES_PATH}/lib/
VPATH += ${ROOTPATH}/src/usr/include/isteps/
