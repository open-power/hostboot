# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/secureboot/ext/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2023
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
SUBDIRS += test.d

PERV_HWP_PATH = $(ROOTPATH)/src/import/chips/p10/procedures/hwp/perv/

OBJS += $(if $(CONFIG_SECUREBOOT), service_ext.o)
OBJS += $(if $(CONFIG_PHYS_PRES_PWR_BUTTON), phys_presence.o)
OBJS += $(if $(CONFIG_KEY_CLEAR), key_clear.o)
OBJS += $(if $(CONFIG_SECUREBOOT), p10_update_security_ctrl.o)
OBJS += $(if $(CONFIG_SECUREBOOT), ody_secureboot.o)

VPATH += $(PERV_HWP_PATH)

EXTRAINCDIR += $(ROOTPATH)/src/usr/
EXTRAINCDIR += $(ROOTPATH)/src/usr/isteps/
EXTRAINCDIR += $(ROOTPATH)/src/include/usr/
EXTRAINCDIR += $(ROOTPATH)/src/include/usr/fapi2/
EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p10/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/

EXTRAINCDIR += $(PERV_HWP_PATH)

CFLAGS += -iquote ../
include ${ROOTPATH}/config.mk
