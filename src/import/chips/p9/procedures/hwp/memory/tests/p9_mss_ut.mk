# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/memory/tests/p9_mss_ut.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2018
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

-include 00common.mk

MSS_UT_SOURCE := $(shell find $(ROOTPATH)/chips/p9/procedures/hwp/memory/tests -name '*.C' -exec basename {} \;)

WRAPPER=p9_mss_ut
OBJS += $(patsubst %.C,%.o,$(MSS_UT_SOURCE))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(MSS_INCLUDES))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(MSS_LAB_SDK_INCLUDES))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(CATCH_UNIT_TESTS_INCLUDES))
$(call ADD_EXE_INCDIR,$(WRAPPER),$(SQLITE3_INCLUDE_DIR))
$(WRAPPER)_DEPLIBS+=mss mss_lab_tools p9_mss_ddr_phy_reset p9_mss_draminit p9_mss_draminit_training p9_mss_draminit_mc p9_mss_scrub p9_mss_freq p9_mss_eff_config
$(WRAPPER)_LDFLAGS+= -Wl,-rpath=$(SQLITE3_LIB_DIR) -L$(SQLITE3_LIB_DIR) -lsqlite3 -lrt
$(call BUILD_WRAPPER)
