# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/secureboot/base/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2026
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
ROOTPATH = ../../../..
MODULE = secureboot_base
include ../common/common.mk
SUBDIRS += test.d

OBJS += service.o
OBJS += settings.o
OBJS += header.o
OBJS += securerommgr.o
OBJS += rom_entry.o
OBJS += trustedboot_base.o
OBJS += $(if $(CONFIG_TPMDD),trustedbootMsg.o,)
OBJS += ${SECUREBOOT_COMMON_OBJS}
OBJS += targutilbase.o

# Flags for ecverify
CFLAGS += -DBYTE_ORDER=BIG_ENDIAN
CFLAGS += -DBN_POWER64_MUL
CFLAGS += -DBN_POWER64_CMP
CFLAGS += -DBN_POWER64_CPY
CFLAGS += -DBN_POWER64_CLR
CFLAGS += -DEC_POWER64_RED
CFLAGS += -DEC_POWER64_ALG

# Flags for MLCA/mldsa_verify() to reduce size
CFLAGS += -DNO_CRYSTALS_CIP
CFLAGS += -DNO_CRYSTALS_KEX
CFLAGS += -DNO_DILITHIUM_SIGN
CFLAGS += -DNO_MLDSA_SIGN
CFLAGS += -DNO_DILITHIUM_VERIFY
CFLAGS += -DUSE_STATIC_MLCA
CFLAGS += -DNO_MLCA_RANDOM

OBJS += keccak.o
OBJS += mlca.o
OBJS += ROM_v3.o
OBJS += ecverify.o

# add this VPATH to find the above files
VPATH += ${ROOTPATH}/src/securerom/contrib/
EXTRAINCDIR += $(ROOTPATH)/src/include/securerom/

VPATH += $(ROOTPATH)/src/usr/targeting/common
EXTRAINCDIR += $(ROOTPATH)/src/include/usr

VPATH += ../common

EXTRAINCDIR += ${ROOTPATH}/src/usr/secureboot/trusted/base
VPATH += ${ROOTPATH}/src/usr/secureboot/trusted/base
VPATH += ${ROOTPATH}/src/securerom

CFLAGS += -iquote ../
include ${ROOTPATH}/config.mk
