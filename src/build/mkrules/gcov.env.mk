# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/gcov.env.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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

ifdef MODULE
GCOVNAME = $(MODULE).lcov
ifndef TESTS
ifdef HOSTBOOT_PROFILE
vpath %.C $(ROOTPATH)/src/sys/prof
OBJS := gcov.o $(OBJS)
endif
endif
else
GCOVNAME = $(notdir $(shell pwd)).lcov
endif

## Disable coverage on test cases, any directory that sets
## HOSTBOOT_PROFILE_NO_INSTRUMENT or any file that has 'gcov' in the name.
ifndef TESTS
ifdef HOSTBOOT_PROFILE
ifndef HOSTBOOT_PROFILE_NO_INSTRUMENT
CFLAGS += --coverage
endif
endif
endif

ifdef HOSTBOOT_PROFILE
    PROFILE_FLAGS_FILTER = $(if $(findstring gcov,$(2)),\
                                $(filter-out --coverage,$(1)),\
                                $(1))
    FLAGS_FILTER = $(call PROFILE_FLAGS_FILTER, $(1), $(2))
endif

## Reduce the optimization level when profiling is enabled to ensure the
## base image fits in 512k still.
ifdef HOSTBOOT_PROFILE
OPT_LEVEL = -Os
endif
