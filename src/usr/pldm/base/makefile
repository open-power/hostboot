# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pldm/base/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2023
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
MODULE = pldm_base

# Force module's files to pull in the special libpldm_config.h file
# that is used to configure which libpldm APIs can be compiled (stable,
# deprecated, undergoing testing).  Only needed by libpldm files.
CFLAGS += -include ${ROOTPATH}/src/include/usr/pldm/libpldm_config.h

include ../common/common.mk

# From ../common/
OBJS += ${PLDM_BASE_COMMON_OBJS}
# From this directory
OBJS += pldm_msg_queues.o
OBJS += pldm_base_init.o
OBJS += pldm_msg_router.o
OBJS += pldm_requester.o
OBJS += pldm_msg_timeout.o
OBJS += pldm_shutdown.o
OBJS += pldm_fr.o
OBJS += errlud_pldm.o

include ${ROOTPATH}/config.mk
