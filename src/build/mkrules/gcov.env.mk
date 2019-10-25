# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/gcov.env.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2019
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

# File: gcov.env.mk
# Description:
#     Configuration of the GCOV settings.

GCOVDIR = $(ROOTPATH)/obj/gcov
vpath %.C $(ROOTPATH)/src/sys/prof

LCOV_DIR := $(ROOTPATH)/src/build/tools/extern/lcov

LCOV_TOOL := $(LCOV_DIR)/bin/lcov
GENHTML_TOOL := $(LCOV_DIR)/bin/genhtml

$(LCOV_TOOL) $(GENHTML_TOOL):
	git submodule update --init --checkout -- $(LCOV_DIR)

ifdef MODULE

# Don't profile HBRT modules to keep size down
ifdef HOSTBOOT_RUNTIME
HOSTBOOT_PROFILE=
endif

## We don't want certain modules to be profiled (HBB, HBRT).

# This is replacing spaces with colons so that we can get an exact
# match on the module name in the list of unprofilable modules with
# findstring, which otherwise would find matches on "partial"
# substrings (i.e. we don't want to deprofile module ABC just because
# module ABCD is blacklisted, so we create a blacklist of modules
# separated by colons and search for :ABC:).
null :=
MODULE_PROFILE_BLACKLIST:=:$(subst ${null} ${null},:,$(BASE_MODULES_GCOV_BLACKLIST) $(RUNTIME_MODULES_GCOV_BLACKLIST)):

ifneq (,$(findstring :$(MODULE):,$(MODULE_PROFILE_BLACKLIST)))
HOSTBOOT_PROFILE=
endif

GCOVNAME := $(MODULE).lcov

ifdef HOSTBOOT_PROFILE
OBJS := gcov.o $(filter-out gcov.o,$(OBJS))
endif
else
GCOVNAME := $(notdir $(shell pwd)).lcov
endif

ifdef HOSTBOOT_PROFILE

## Disable coverage on any directory that sets
## HOSTBOOT_PROFILE_NO_INSTRUMENT

ifndef HOSTBOOT_PROFILE_NO_INSTRUMENT
CFLAGS += --coverage
endif

endif

ifdef HOSTBOOT_PROFILE
    PROFILE_FLAGS_FILTER = $(if $(findstring gcov,$(2)),\
                                $(filter-out --coverage,$(1)),\
                                $(1))
    FLAGS_FILTER = $(call PROFILE_FLAGS_FILTER, $(1), $(2))
endif
