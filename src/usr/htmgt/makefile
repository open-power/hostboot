# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/htmgt/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2020
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
MODULE = htmgt

# objects common to hostboot and hbrt
include htmgt_common.mk

# RTC: 247144 - Add Mem Config Support
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory
#EXTRAINCDIR += $(PROCEDURES_PATH)/hwp/memory
#PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures
#include ${ROOTPATH}/procedure.rules.mk
#OBJS += $(PROCEDURES_PATH)/hwp/memory/p9_mss_utils_to_throttle.o
#OBJS += $(PROCEDURES_PATH)/hwp/memory/p9_mss_bulk_pwr_throttles.o

# objects unique to hostboot
#OBJS += htmgt_memthrottles.o

SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk
