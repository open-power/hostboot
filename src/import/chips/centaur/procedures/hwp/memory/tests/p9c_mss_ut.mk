# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/centaur/procedures/hwp/memory/tests/p9c_mss_ut.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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

-include 01common.mk

CEN_UT_SOURCE := $(shell find $(ROOTPATH)/chips/centaur/procedures/hwp/memory/tests -name '*.C' -exec basename {} \;)

WRAPPER=p9c_mss_ut
OBJS += $(patsubst %.C,%.o,$(CEN_UT_SOURCE))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(CEN_INCLUDES))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(CEN_CATCH_UNIT_TESTS_INCLUDES))

$(WRAPPER)_DEPLIBS+=cen
$(WRAPPER)_DEPLIBS+=mss_generic

$(WRAPPER)_COMMONFLAGS+=-fno-var-tracking-assignments

$(WRAPPER)_LDFLAGS+= -Wl,-lrt
$(call BUILD_WRAPPER)
