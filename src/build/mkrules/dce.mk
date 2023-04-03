# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dce.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2023
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

bold=$(shell tput bold)
normal=$(shell tput sgr0)

ifdef DCE_NO_LISTING_FILE
DCE_LISTING_FILE :=
DCE_TEST_LISTING_FILE :=
else
DCE_LISTING_FILE := %.dce.lid.debug
DCE_TEST_LISTING_FILE := %.dce.test.lid.debug
endif

# Rules for creating the DCE lid and the debug listing file.

.PRECIOUS: %.dce.lid.debug
%.dce.lid.debug: %.C $(filter %.C %.H, $(DCE_EXTRA_FILES)) $(PROJECT_ROOT)/img/hbicore.list.bz2
	CXXFLAGS="$(filter-out -D__HOSTBOOT_MODULE=% -Werror, $(CXXFLAGS)) $(CXXFLAGS_DCE) -gz" $(ROOTPATH)/src/build/tools/dce/dce-compile "$<" $(filter %.C, $(DCE_EXTRA_FILES)) -o $@ $(INCFLAGS) >/dev/null 2>&1
	$(OBJDUMP) --source -d $@ > $@.list

.PRECIOUS: %.dce.lid.intermediate
%.dce.lid.intermediate: %.C $(filter %.C %.H, $(DCE_EXTRA_FILES)) $(PROJECT_ROOT)/img/hbicore.list.bz2
	CXXFLAGS="$(filter-out -D__HOSTBOOT_MODULE=% -Werror, $(CXXFLAGS)) $(CXXFLAGS_DCE) -s" $(ROOTPATH)/src/build/tools/dce/dce-compile "$<" $(filter %.C, $(DCE_EXTRA_FILES)) -o $@ $(INCFLAGS)
	$(ROOTPATH)/src/build/tools/dce/preplib.py $@

%.dce.lid: %.dce.lid.intermediate $(DCE_LISTING_FILE)
	cp $@.intermediate.lid $@
	@echo "$(bold)Build complete.$(normal)"
	@echo "$(bold)Copy $@ to the BMC to run it.$(normal)"
	@if [[ "$(DCE_LISTING_FILE)" ]] ; then \
	    echo "$(bold)Assembly listing file is at $@.debug.list for debugging crashes.$(normal)" ; \
	fi
	@if [[ ! "$(MAKEFLAGS)" =~ "-j" ]] ; then \
	    echo "$(bold)Note: Try running make with -j to speed things up.$(normal)"; \
	fi

# Test image versions of the above rules, for standalone SIMICS.

.PRECIOUS: %.dce.test.lid.debug
%.dce.test.lid.debug: %.C $(filter %.C %.H, $(DCE_EXTRA_FILES)) $(PROJECT_ROOT)/img/hbicore_test.list.bz2
	CXXFLAGS="$(filter-out -D__HOSTBOOT_MODULE=% -Werror, $(CXXFLAGS)) $(CXXFLAGS_DCE) -gz" $(ROOTPATH)/src/build/tools/dce/dce-compile "$<" $(filter %.C, $(DCE_EXTRA_FILES)) -o $@ $(INCFLAGS) >/dev/null 2>&1
	$(OBJDUMP) --source -d $@ > $@.list

.PRECIOUS: %.dce.test.lid.intermediate
%.dce.test.lid.intermediate: %.C $(filter %.C %.H, $(DCE_EXTRA_FILES)) $(PROJECT_ROOT)/img/hbicore_test.list.bz2
	CXXFLAGS="$(filter-out -D__HOSTBOOT_MODULE=% -Werror, $(CXXFLAGS)) $(CXXFLAGS_DCE) -s" $(ROOTPATH)/src/build/tools/dce/dce-compile "$<" $(filter %.C, $(DCE_EXTRA_FILES)) -o $@ $(INCFLAGS)
	HB_DCE_TEST_IMAGE=1 $(ROOTPATH)/src/build/tools/dce/preplib.py $@

%.dce.test.lid: %.dce.test.lid.intermediate $(DCE_TEST_LISTING_FILE)
	cp $@.intermediate.lid $@
	@echo "$(bold)Build complete.$(normal)"
	@echo "$(bold)Run $@ with hb-executeDCELid SIMICS.$(normal)"
	@if [[ "$(DCE_LISTING_FILE)" ]] ; then \
	    echo "$(bold)Assembly listing file is at $@.debug.list for debugging crashes.$(normal)" ; \
	fi
	@if [[ ! "$(MAKEFLAGS)" =~ "-j" ]] ; then \
	    echo "$(bold)Note: Try running make with -j to speed things up.$(normal)"; \
	fi
