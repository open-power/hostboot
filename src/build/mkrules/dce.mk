# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dce.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2022
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

%.dce.lid: %.c++ $(DCE_EXTRA_FILES) $(PROJECT_ROOT)/img/hbicore.list.bz2
	$(ROOTPATH)/src/build/tools/dce/dce-compile "$<" $(filter %.c++, $(DCE_EXTRA_FILES)) -o $@.intermediate $(INCFLAGS)
	$(ROOTPATH)/src/build/tools/dce/preplib.py $@.intermediate
	mv $@.intermediate.lid $@
	@echo Copy $@ to the BMC
