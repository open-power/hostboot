# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pldm/common/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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


# This .mk is included in both src/usr/pldm/base/makefile and
# src/usr/pldm/extended/makefile so it is expected to include
# anything common between those two makefiles

COMMON_ROOTPATH = ../../../..

#external pldm libs
EXTERN_PLDM_PATH = ${COMMON_ROOTPATH}/src/subtree/openbmc/pldm
EXTERN_LIBPLDM_PATH = ${COMMON_ROOTPATH}/src/subtree/openbmc/pldm/libpldm
EXTERN_LIBPLDM_OEM_PATH = ${COMMON_ROOTPATH}/src/subtree/openbmc/pldm/oem/ibm/libpldm

EXTRAINCDIR += ${EXTERN_PLDM_PATH}
EXTRAINCDIR += ${EXTERN_LIBPLDM_PATH}
EXTRAINCDIR += ${EXTERN_LIBPLDM_OEM_PATH}
EXTRAINCDIR += ${COMMON_IMPORT_PATH}

PLDM_BASE_COMMON_OBJS += pldmtrace.o
PLDM_BASE_COMMON_OBJS += pldm_utils.o
PLDM_BASE_COMMON_OBJS += base.o
PLDM_BASE_COMMON_OBJS += utils.o
PLDM_BASE_COMMON_OBJS += bios.o
PLDM_BASE_COMMON_OBJS += bios_table.o
PLDM_BASE_COMMON_OBJS += hb_bios_attrs.o
PLDM_BASE_COMMON_OBJS += pldm_bios_attr_requests.o
PLDM_BASE_COMMON_OBJS += pldm_tid_requests.o
PLDM_BASE_COMMON_OBJS += file_io.o
PLDM_BASE_COMMON_OBJS += pldm_fileio_requests.o

PLDM_EXTENDED_COMMON_OBJS += fru.o
PLDM_EXTENDED_COMMON_OBJS += platform.o

PLDM_EXTENDED_COMMON_OBJS += pdr.o
PLDM_EXTENDED_COMMON_OBJS += pldm_fru_requests.o
PLDM_EXTENDED_COMMON_OBJS += pldm_pdr_requests.o

PLDM_EXTENDED_COMMON_OBJS += hb_fru.o
PLDM_EXTENDED_COMMON_OBJS += hb_pdrs.o
PLDM_EXTENDED_COMMON_OBJS += pldm_responder.o
PLDM_EXTENDED_COMMON_OBJS += pdr_manager.o
PLDM_EXTENDED_COMMON_OBJS += pldm_fru.o
PLDM_EXTENDED_COMMON_OBJS += pldm_monitor_control_responders.o
PLDM_EXTENDED_COMMON_OBJS += pldm_fru_data_responders.o
PLDM_EXTENDED_COMMON_OBJS += pldm_watchdog.o

# add these paths to VPATH so compiler knows
# where to find the .C/.c files we need
VPATH += ${EXTERN_LIBPLDM_PATH}
VPATH += ${EXTERN_LIBPLDM_OEM_PATH}
VPATH += ${COMMON_ROOTPATH}/src/usr/pldm/common
VPATH += ${COMMON_ROOTPATH}/src/usr/pldm/requests
VPATH += ${COMMON_ROOTPATH}/src/usr/pldm/responses
