# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pldm/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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
HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../..
MODULE = pldm_rt

include ../common/common.mk

# From ../common/
OBJS += ${PLDM_BASE_COMMON_OBJS}
OBJS += ${PLDM_EXTENDED_COMMON_OBJS}

OBJS += pldmrp_rt.o

include ${ROOTPATH}/config.mk

VPATH += ${ROOTPATH}/src/usr/pldm/extended
VPATH += ${ROOTPATH}/src/usr/pldm/base