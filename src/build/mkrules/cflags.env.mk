# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cflags.env.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2021
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

OPT_LEVEL ?= -Os

ifdef MODULE
COMMONFLAGS += -fPIC -Bsymbolic -Bsymbolic-functions
CFLAGS += -D__HOSTBOOT_MODULE=$(MODULE)
CFLAGS += -DNO_INITIALIZER_LIST
CFLAGS += -DNO_PLAT_STD_STRING_SUPPORT
#CFLAGS += -DPLAT_NO_THREAD_LOCAL_STORAGE
CFLAGS += -D__FAPI
endif

# Force all files to pull in the CONFIG_ variables
CFLAGS += -include config.h

COMMONFLAGS += $(OPT_LEVEL) -nostdlib
CFLAGS += $(COMMONFLAGS) -mcpu=power7 -nostdinc -g -mno-vsx -mno-altivec\
          -Werror -Wall -mtraceback=no -pipe -mabi=elfv1 \
	  -ffunction-sections -fdata-sections -ffreestanding -mbig-endian
ASMFLAGS += $(COMMONFLAGS) -mcpu=power7 -mbig-endian -ffreestanding -mabi=elfv1
CXXFLAGS += $(CFLAGS) -nostdinc++ -fno-rtti -fno-exceptions -Werror -Wall \
	    -fuse-cxa-atexit -std=gnu++14
LDFLAGS += --nostdlib --sort-common -EB $(COMMONFLAGS)

INCFLAGS = $(addprefix -I, $(INCDIR) )
ASMINCFLAGS = $(addprefix $(lastword -Wa,-I), $(INCDIR))

FLAGS_FILTER ?= $(1)

CFLAGS+=-DFAPI2_ENABLE_PLATFORM_GET_TARGET
CFLAGS+=-DP10_RS4_CONTANER_SIZE_TRACING

ifdef COMPILETIME_TRACEHASH
CFLAGS+=-DCOMPILETIME_TRACEHASH
endif

ifdef HOSTBOOT_RUNTIME
CFLAGS += -D__HOSTBOOT_RUNTIME=1
CFLAGS += -DTRACEHASH_FULL_STRINGS
TRACE_FLAGS += --full-strings
else # just need one or the other
ifdef CONFIG_CONSOLE_OUTPUT_TRACE
CFLAGS += -DTRACEHASH_FULL_STRINGS
TRACE_FLAGS += --full-strings
endif
endif
