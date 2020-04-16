# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pldm/extended/makefile $
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

ROOTPATH = ../../../..
MODULE = pldm_extended

include ../common/common.mk

# From ../extern/
OBJS += bios.o
OBJS += bios_table.o
OBJS += fru.o
OBJS += platform.o
OBJS += file_io.o
OBJS += pdr.o
# From ../requests/
OBJS += pldm_fru_requests.o
OBJS += pldm_pdr_requests.o
OBJS += pldm_fileio_requests.o
# From ../responses/
OBJS += pldm_monitor_control_responders.o
# From ../extended/
OBJS += hb_pdrs.o
OBJS += pdr_manager.o
OBJS += pldm_responder.o
OBJS += pldm_extended_init.o

SUBDIRS += test.d

include ${ROOTPATH}/config.mk
