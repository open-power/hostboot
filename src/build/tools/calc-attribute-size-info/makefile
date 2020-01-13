# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/calc-attribute-size-info/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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

DEFINITIONS := -D__TARGETING_COMMON_TRACE_H -DTARG_ENTER=void -DTARG_EXIT=void -D_ASSERT_H -DTRACFCOMP=TRACDCOMP -D__HOSTBOOT_MODULE=yes
INCLUDEDIRS := -I $(PROJECT_ROOT)/obj/genfiles -idirafter $(PROJECT_ROOT)/src/include -I $(PROJECT_ROOT)/src/include/usr/
CXX := $(HOST_PREFIX)g++

calc-size-info: calc_attr_size.C
	$(CXX) $(DEFINITIONS) -std=c++11 $< $(PROJECT_ROOT)/obj/genfiles/mapattrmetadata.C $(INCLUDEDIRS) -o $@

.PHONY: clean
clean:
	rm -f calc-size-info
