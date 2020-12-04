# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/mbox/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2021
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
ROOTPATH = ../../..
MODULE = mbox

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
ifndef CONFIG_VPO_COMPILE
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/istep21/
endif

OBJS += mboxdd.o
OBJS += mailboxsp.o
OBJS += mbox_dma_buffer.o
OBJS += ipcSp.o
ifndef CONFIG_VPO_COMPILE
OBJS += freqAttrData.o
endif

SUBDIRS += test.d

ifndef CONFIG_VPO_COMPILE
VPATH += ${ROOTPATH}/src/usr/isteps/istep21/
endif

include ${ROOTPATH}/config.mk
