# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep18/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

NEST_HWP_PATH += ${PROCEDURES_PATH}/hwp/nest


VPATH += ${NEST_HWP_PATH}

#Add all the objs for istep 18
OBJS += tod_init.o

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include
EXTRAINCDIR += ${NEST_HWP_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/isteps

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init
EXTRAINCDIR += ${PROCEDURES_PATH}


#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

#Include all the procedure makefiles
include $(NEST_HWP_PATH)/p9_tod_utils.mk
include $(NEST_HWP_PATH)/p9_tod_setup.mk
include $(NEST_HWP_PATH)/p9_tod_init.mk

include ${ROOTPATH}/config.mk
