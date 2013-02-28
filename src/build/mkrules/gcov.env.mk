# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/gcov.env.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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
