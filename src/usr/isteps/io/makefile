# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/io/makefile $
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

## ./import/chips/p9/procedures/hwp/io/p9_io_common.H

PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/

COMMON_LIB += ${PROCEDURES_PATH}/hwp/io

EXTRAINCDIR += ${COMMON_LIB}

# Add common and generated parts to object list.
MODULE = isteps_io
OBJS += p9_io_common.o
$(call BUILD_MODULE)

#HWP build tool
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk

## Needed?
VPATH += ${COMMON_LIB}
