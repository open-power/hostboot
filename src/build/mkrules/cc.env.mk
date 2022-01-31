# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cc.env.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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

# File: cc.env.mk
# Description:
#     Configuration of the compiler settings.

CROSS_PREFIX ?= powerpc64-unknown-linux-gnu-
HOST_PREFIX ?= x86_64-pc-linux-gnu-

JAILCMD ?= $(HOST_PREFIX)jail

CC_RAW = $(CROSS_PREFIX)gcc -std=c99
CXX_RAW = $(CROSS_PREFIX)g++
CC = $(CCACHE) $(CC_RAW)
CXX = $(CCACHE) $(CXX_RAW)

AR = $(CROSS_PREFIX)ar
LD = $(CROSS_PREFIX)ld
STRIP = $(CROSS_PREFIX)strip
OBJDUMP = $(CROSS_PREFIX)objdump
GCOV = $(CROSS_PREFIX)gcov

CUSTOM_LINKER_EXE = $(ROOTPATH)/src/build/linker/linker
CUSTOM_LINKER = $(JAILCMD) $(CUSTOM_LINKER_EXE)

ifdef COMPILETIME_TRACEHASH
TRACEHASH_INPUT_NAME = $@
TRACE_HASHER_CLEANUP =
TRACE_HASHER_EXE = $(ROOTPATH)/src/build/trace/extracthash
else
TRACEHASH_INPUT_NAME = $@.trace
TRACE_HASHER_CLEANUP = rm $@.trace
TRACE_HASHER_EXE = $(ROOTPATH)/src/build/trace/tracehash
endif

TRACE_HASHER = $(JAILCMD) $(TRACE_HASHER_EXE)
