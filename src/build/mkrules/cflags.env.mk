# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cflags.env.mk $
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
          -Wall -Werror -mtraceback=no -pipe
ASMFLAGS += $(COMMONFLAGS) -mcpu=power7
CXXFLAGS += $(CFLAGS) -nostdinc++ -fno-rtti -fno-exceptions -Wall
LDFLAGS += --nostdlib --sort-common $(COMMONFLAGS)

INCFLAGS = $(addprefix -I, $(INCDIR) )
ASMINCFLAGS = $(addprefix $(lastword -Wa,-I), $(INCDIR))

FLAGS_FILTER ?= $(1)
