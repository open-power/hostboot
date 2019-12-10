# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/trace/tracelite/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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

OUT_FILE += $(GENDIR)/weave
CLEAN_TARGETS += $(OUT_FILE) $(OUT_FILE).o

GEN_PASS_BODY += $(OUT_FILE)

include $(ROOTPATH)/config.mk

$(OUT_FILE): weave.C
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -std=gnu++11 -O3 -g -c $< -o $@.o
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g $@.o -o $@
	$(C1)rm $@.o
