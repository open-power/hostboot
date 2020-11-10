# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2020
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
MODULE = sbeio_rt

VPATH += ../
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p10/procedures

# pull in .mk common between sbeio and sbeio_rt
include ../common/common.mk

## Objects unique to HBRT
OBJS += rt_sbeio.o
OBJS += rt_sbescom.o
OBJS += sbeio_attr_override.o
OBJS += sbeio_vital_attn.o
OBJS += p10_extract_sbe_rc.o
OBJS += p10_ppe_utils.o
OBJS += p10_ppe_common.o

# for PRDF channel failure cache registers
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/prdf

## sbeio_rt's sub directories
SUBDIRS += test.d

include ${ROOTPATH}/config.mk
