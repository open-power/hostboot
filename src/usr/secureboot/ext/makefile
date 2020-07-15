# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/secureboot/ext/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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
MODULE = secureboot_ext
SUBDIRS +=

# FIXME RTC:257489
#PERV_HWP_PATH = $(ROOTPATH)/src/import/chips/p9/procedures/hwp/perv

#OBJS += $(if $(CONFIG_SECUREBOOT), service_ext.o)
OBJS += $(if $(CONFIG_PHYS_PRES_PWR_BUTTON), phys_presence.o)
OBJS += $(if $(CONFIG_KEY_CLEAR), key_clear.o)

#VPATH += $(PERV_HWP_PATH)

EXTRAINCDIR += $(ROOTPATH)/src/include/usr
#EXTRAINCDIR += $(ROOTPATH)/src/include/usr/fapi2/
#EXTRAINCDIR += $(ROOTPATH)/src/import/hwpf/fapi2/include
#EXTRAINCDIR += $(ROOTPATH)/src/import/chips/common/utils/imageProcs
#EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p9/procedures/hwp/ffdc
#EXTRAINCDIR += $(PERV_HWP_PATH)

#Include HWP procedure makefiles
#include $(ROOTPATH)/procedure.rules.mk
#include $(PERV_HWP_PATH)/p9_update_security_ctrl.mk

CFLAGS += -iquote ../
include ${ROOTPATH}/config.mk
