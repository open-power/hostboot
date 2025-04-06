# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/securerom/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2025
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

ROOTPATH = ../..

# Bootloader omitted from profiling to keep size down
HOSTBOOT_PROFILE_ARTIFACT=

COMMONFLAGS += -DBYTE_ORDER=BIG_ENDIAN
COMMONFLAGS += -DBN_POWER64_MUL
COMMONFLAGS += -DBN_POWER64_CMP
COMMONFLAGS += -DBN_POWER64_CPY
COMMONFLAGS += -DBN_POWER64_CLR
COMMONFLAGS += -DEC_POWER64_RED
COMMONFLAGS += -DEC_POWER64_ALG
COMMONFLAGS += -DSHA512_FIX

# @TODO JIRA PFHB-921 use these flags for compiling MLCA into the securerom
# Flags for MLCA/mldsa_verify() to reduce size
#COMMONFLAGS += -DNO_CRYSTALS_CIP
#COMMONFLAGS += -DNO_CRYSTALS_KEX
#COMMONFLAGS += -DNO_DILITHIUM_SIGN
#COMMONFLAGS += -DNO_MLDSA_SIGN
#COMMONFLAGS += -DNO_DILITHIUM_VERIFY
#COMMONFLAGS += -DUSE_DYNAMIC_ALLOC


LDFLAGS += -N

ASMFLAGS += -D__ASSEMBLER__

OBJS += ROM.o
OBJS += sha512.o
OBJS += ecverify.o
OBJS += hw_utils.o
OBJS += rom_entry.o
OBJS += secureromasm.o

# @TODO JIRA PFHB-921 will move the V3 algorithm support back to securerom.
# In the meantime these .o files will be built into the bootloader and
# secureboot_base modules
#OBJS += ROM_v3.o
#OBJS += keccak.o
#OBJS += mlca.o


VPATH += contrib

OPT_LEVEL = -Os

include ${ROOTPATH}/config.mk
