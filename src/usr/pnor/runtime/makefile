# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pnor/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2023
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
MODULE = pnor_rt

PLDM_DEPS = pnor_pldmdd.o pnor_pldm_utils.o

OBJS += rt_pnor.o
OBJS += pnor_utils.o
OBJS += pnor_common.o
OBJS += ecc.o
OBJS += $(if $(CONFIG_FILE_XFER_VIA_PLDM),$(PLDM_DEPS))

SUBDIRS += test.d

EXTRAINCDIR += $(if $(CONFIG_FILE_XFER_VIA_PLDM),${ROOTPATH}/src/subtree/openbmc/pldm/libpldm/include/libpldm)

VPATH += ../

include $(ROOTPATH)/config.mk
