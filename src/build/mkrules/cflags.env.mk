# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cflags.env.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2015
# [+] Google Inc.
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

# File: cflags.env.mk
# Description:
#     Configuration of the compiler, linker, etc. flags.

OPT_LEVEL ?= -O3

ifdef MODULE
COMMONFLAGS += -fPIC -Bsymbolic -Bsymbolic-functions
CFLAGS += -D__HOSTBOOT_MODULE=$(MODULE)
endif

COMMONFLAGS += $(OPT_LEVEL) -nostdlib
CFLAGS += $(COMMONFLAGS) -mcpu=power7 -nostdinc -g -mno-vsx -mno-altivec\
          -Wall -Werror -mtraceback=no -pipe \
	  -ffunction-sections -fdata-sections -ffreestanding -mbig-endian
ASMFLAGS += $(COMMONFLAGS) -mcpu=power7 -mbig-endian
CXXFLAGS += $(CFLAGS) -nostdinc++ -fno-rtti -fno-exceptions -Wall \
	    -fuse-cxa-atexit -std=gnu++11
LDFLAGS += --nostdlib --sort-common -EB $(COMMONFLAGS)

INCFLAGS = $(addprefix -I, $(INCDIR) )
ASMINCFLAGS = $(addprefix $(lastword -Wa,-I), $(INCDIR))

FLAGS_FILTER ?= $(1)

ifdef HOSTBOOT_RUNTIME
CFLAGS += -D__HOSTBOOT_RUNTIME=1
TRACE_FLAGS += --full-strings
else # just need one or the other
ifdef CONFIG_CONSOLE_OUTPUT_TRACE
TRACE_FLAGS += --full-strings
endif
endif
