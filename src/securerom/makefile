# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/securerom/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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

COMMONFLAGS += -DBYTE_ORDER=BIG_ENDIAN
COMMONFLAGS += -DBN_POWER64_MUL
COMMONFLAGS += -DBN_POWER64_CMP
COMMONFLAGS += -DBN_POWER64_CPY
COMMONFLAGS += -DBN_POWER64_CLR
COMMONFLAGS += -DEC_POWER64_RED
COMMONFLAGS += -DEC_POWER64_ALG
COMMONFLAGS += -DSHA512_FIX

LDFLAGS += -N

ASMFLAGS += -D__ASSEMBLER__

OBJS += branchtable.o
OBJS += ROM.o
OBJS += sha512.o
OBJS += ecverify.o
OBJS += hw_utils.o

OPT_LEVEL = -Os

include ${ROOTPATH}/config.mk
