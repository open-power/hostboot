# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/rules.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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

# File: rules.mk
# Description:
#     Root of the rules (ie. recipes) for the build system.

include $(MKRULESDIR)/verbose.rules.mk
include $(MKRULESDIR)/dep.rules.mk
include $(MKRULESDIR)/cxxtest.rules.mk
include $(MKRULESDIR)/cc.rules.mk
include $(MKRULESDIR)/binfile.rules.mk
include $(MKRULESDIR)/beam.rules.mk
include $(MKRULESDIR)/gcov.rules.mk
include $(MKRULESDIR)/images.rules.mk

