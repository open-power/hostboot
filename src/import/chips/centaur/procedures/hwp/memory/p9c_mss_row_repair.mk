# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_row_repair.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018
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

PROCEDURE=p9c_mss_row_repair
$(eval $(call ADD_MEMORY_INCDIRS,$(PROCEDURE)))
lib${PROCEDURE}_DEPLIBS+=p9c_mss_ddr4_funcs
lib${PROCEDURE}_DEPLIBS+=p9c_mss_funcs
lib${PROCEDURE}_DEPLIBS+=p9c_dimmBadDqBitmapFuncs
lib${PROCEDURE}_DEPLIBS+=p9c_mss_rowRepairFuncs
$(call BUILD_PROCEDURE)
