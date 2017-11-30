# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017
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
VPATH += ../
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

MODULE = sbeio_rt



EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe/

## Objects unique to HBRT
OBJS += rt_sbeio.o
OBJS += sbeio_attr_override.o
OBJS += sbe_attn.o
OBJS += sbe_retry_handler.o
#@todo - RTC:180241 - Add in error handlers by creating common mk

VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/sbe/
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/src/import/chips/p9/procedures/hwp/sbe/p9_get_sbe_msg_register.mk
include ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/p9_extract_sbe_rc.mk
include ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/p9_start_cbs.mk

SUBDIRS += test.d

include ${ROOTPATH}/config.mk
