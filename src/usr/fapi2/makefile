# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
#
# @file src/usr/fapi2/makefile
#
# @brief Makefile rule for fapi2 module
#

ROOTPATH = ../../..
GENPATH?=$(ROOTPATH)/obj/genfiles

MODULE = fapi2
SUBDIRS += test.d

EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/

include ${ROOTPATH}/src/build/mkrules/verbose.rules.mk
define __CLEAN_TARGET
CLEAN_TARGETS += $(1)
endef

include fapi2.mk

include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/src/import/tools/build/common.dir/script.rules.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseErrorInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseAttributeInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/createIfAttrService.mk
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket.mk

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR} $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/
