# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_thermal_scan.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
PROCEDURE=centaur_thermal_scan
lib$(PROCEDURE)_COMMONFLAGS+=-DFAPI_SUPPORT_SPY_AS_STRING=1
$(call BUILD_PROCEDURE)

PROCEDURE=centaur_thermal_scan_ifCompiler
lib$(PROCEDURE)_COMMONFLAGS+=-DFAPI_SUPPORT_SPY_AS_STRING=1
lib$(PROCEDURE)_COMMONFLAGS+=-DIFCOMPILER_PLAT=1
FAPI=2_IFCOMPILER
OBJS+=centaur_thermal_scan.o
lib$(PROCEDURE)_LIBPATH=$(LIBPATH)/ifCompiler
lib$(PROCEDURE)_COMMONFLAGS+=-fno-var-tracking-assignments
$(call BUILD_PROCEDURE)