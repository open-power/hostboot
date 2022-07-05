# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwas/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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
ROOTPATH = ../../..

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwas
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwas/common
EXTRAINCDIR += ${ROOTPATH}/src/usr/vpd/

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbe

##      support for pm_common
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/

VPATH += ${ROOTPATH}/src/usr/hwas/plat
VPATH += ${ROOTPATH}/src/usr/hwas/common
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/

MODULE = hwas

# files in hwas/common directory
OBJS += hwas.o
OBJS += hwasCallout.o
OBJS += deconfigGard.o
OBJS += pgLogic.o
OBJS += fieldCoreOverride.o

# files in this directory
OBJS += hwasPlat.o
OBJS += hwasPlatError.o
OBJS += hwasPlatCallout.o
OBJS += hwasPlatDeconfigGard.o
OBJS += errlud_pgData.o

# hardware procedures called in hwasPlat functions
OBJS += p10_determine_eco_mode.o

SUBDIRS = test.d

include ${ROOTPATH}/config.mk
