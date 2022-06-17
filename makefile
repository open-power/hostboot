# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2022
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

SUBDIRS = src.d
ROOTPATH = .

CONFIG_FILE ?= default

GEN_PASS_PRE += $(GENDIR)/.$(notdir $(CONFIG_FILE)).config
CLEAN_TARGETS += $(wildcard $(GENDIR)/.*.config)
CLEAN_TARGETS += $(GENDIR)/config.mk $(GENDIR)/config.h
SKIP_CONFIG_FILE_LOAD = 1

IMAGE_PASS_POST += $(GENDIR)/hwp_id.html
CLEAN_TARGETS   += $(GENDIR)/hwp_id.html

# Name of file to indicate which release Hostboot is building for
HB_FSP_RELEASE = $(GENDIR)/hb_fsp_release
HB_AXONE_RELEASE = $(GENDIR)/hb_simics_axone_release

IMAGE_PASS_POST += check_istep_modules

# Variables used when running cppcheck tool.
# The actual commands are stored in CXX_CHECK and C_CHECK, which are created as
# dummy variables here, but will be set to the actual tool in the "cppcheck" rule
BUILDCPPCHECK := $(PROJECT_ROOT)/src/build/tools/build-cppcheck
CPPCHECKTOOL := $(PROJECT_ROOT)/src/build/tools/cpptools/cppcheck/cppcheck
CPPCHECKFLAGS := --inline-suppr --error-exitcode=1 --template='Error CPPCHECK {file}: line {line}\nSyntax error string: {id}\n{message}'
CPPCHECK := $(CPPCHECKTOOL) $(CPPCHECKFLAGS)
export CXX_CHECK ?= true
export C_CHECK ?= true

include ./config.mk

.PHONY: docs
docs: src/build/doxygen/doxygen.conf
	rm -rf obj/doxygen/*
	doxygen src/build/doxygen/doxygen.conf

.PHONY: citest
citest:
	src/build/citest/cxxtest-start.sh

gcov: HOSTBOOT_PROFILE := 1

export HOSTBOOT_PROFILE

.PHONY: gcov
gcov:
	@echo Building Hostboot with profiling enabled.
	$(MAKE)
	@echo Run simics and execute the hb-Gcov command at the end of the simulation to extract gcov data.
	@echo Then you can "make lcov" to generate the coverage report.

.PHONY: lcov
lcov:
	rm -f obj/lcov_data
	lcov -c --dir . -o obj/lcov_data --gcov-tool $(GCOV)
	rm -rf obj/gcov_report
	genhtml obj/lcov_data -o obj/gcov_report --ignore-errors source
	@echo Coverage report now available in obj/gcov_report

.PHONY: cppcheck
cppcheck:
	@echo Building with CPPCHECK tool
# TODO RTC: 215692
	${BUILDCPPCHECK}
	export CXX_CHECK="$(CPPCHECK) $(filter -D%, $(CXXFLAGS)) $(INCFLAGS)" && \
	export C_CHECK="$(CPPCHECK) $(filter -D%, $(CFLAGS)) $(INCFLAGS)" && \
	export DOCPPCHECK=1 && \
	${MAKE}

.PHONY: gcda_clean
gcda_clean:
	find -name '*.gcda' -exec rm -f {} \;

$(GENDIR)/hwp_id.html :
	$(ROOTPATH)/src/build/tools/hwp_id.pl -i -l > $@

.PHONY: check_istep_modules
check_istep_modules: $(OBJS)
	listdeps.pl $(IMGDIR)  -v

GENCONFIG_TOOL = src/build/tools/hbGenConfig

# At end of rule, create HB_FSP_RELEASE file if compiling with fsprelease.config
# or create HB_AXONE_RELEASE if compiling with simics_axone.config
$(GENDIR)/.$(notdir $(CONFIG_FILE)).config: \
    $(shell find -name HBconfig) \
    $(filter-out $(GENDIR)/.$(notdir $(CONFIG_FILE)).config,\
	    $(wildcard $(GENDIR)/.*.config)) \
    $(GENCONFIG_TOOL) \
    $(filter-out default,$(CONFIG_FILE))
	@mkdir -p $(GENDIR)
	$(C2) "    GENCONFIG"
	$(C1)$(GENCONFIG_TOOL) $(CONFIG_FILE) \
	    $(filter-out $(GENCONFIG_TOOL) $(CONFIG_FILE) \
			 $(wildcard $(GENDIR)/.*.config),$^)
	@rm -f $(wildcard $(GENDIR)/.*.config)
	@touch $@
	@rm -f $(HB_FSP_RELEASE)
	@rm -f $(HB_AXONE_RELEASE)
    ifneq (,$(findstring fsprelease.config, $(strip $(CONFIG_FILE))))
	    @touch $(HB_FSP_RELEASE)
    endif
    ifneq (,$(findstring simics_axone.config, $(strip $(CONFIG_FILE))))
	    @touch $(HB_AXONE_RELEASE)
    endif
