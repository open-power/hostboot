# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/bootloader/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2025
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
HWP_PATH = ${ROOTPATH}/src/import/chips/p10/procedures

# Bootloader omitted from profiling to keep size down
HOSTBOOT_PROFILE_ARTIFACT=

EXTRAINCDIR += ${ROOTPATH}/src/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/usr/lpc/
EXTRAINCDIR += ${ROOTPATH}/src/usr/console/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/lpc/

COMMONFLAGS += -DBOOTLOADER
COMMONFLAGS += -DFAPI2_NO_FFDC
COMMONFLAGS += -DFAPI_VARIABLE_BUFFER_NOT_SUPPORTED
COMMONFLAGS += -DFAPI_PLAT_MULTICAST_NOT_SUPPORTED
COMMONFLAGS += -DPLAT_EC_FEATURE_NOT_SUPPORTED
COMMONFLAGS += -DPLAT_NO_THREAD_LOCAL_STORAGE

# @TODO JIRA PFHB-921 remove these temporary flags that are needed for
# compiling MLCA and ecverify into the hostboot bootloader code
# once we get the V3 support into the securerom
# Flags for ecverify
COMMONFLAGS += -DBYTE_ORDER=BIG_ENDIAN
COMMONFLAGS += -DBN_POWER64_MUL
COMMONFLAGS += -DBN_POWER64_CMP
COMMONFLAGS += -DBN_POWER64_CPY
COMMONFLAGS += -DBN_POWER64_CLR
COMMONFLAGS += -DEC_POWER64_RED
COMMONFLAGS += -DEC_POWER64_ALG

# Flags for MLCA/mldsa_verify() to reduce size
COMMONFLAGS += -DNO_CRYSTALS_CIP
COMMONFLAGS += -DNO_CRYSTALS_KEX
COMMONFLAGS += -DNO_DILITHIUM_SIGN
COMMONFLAGS += -DNO_MLDSA_SIGN
COMMONFLAGS += -DNO_DILITHIUM_VERIFY
# Not supporting this last flag as it would require supporting a malloc()
# (for mlca_alloc()) and free() (for mlca_free()) in HBBL code
#COMMONFLAGS += -DUSE_DYNAMIC_ALLOC


EXTRAINCDIR += ${HWP_PATH}/hwp/nest/
EXTRAINCDIR += ${HWP_PATH}/hwp/spi/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/bootloader/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/

SUBDIRS += fapi2.d

OBJS += bl_start.o
OBJS += bootloader.o
OBJS += bl_pnorAccess.o
OBJS += bl_pnor_utils.o
OBJS += bl_pnor_ecc.o
OBJS += bl_builtins.o
OBJS += bl_terminate.o
OBJS += bl_string_utils.o
OBJS += bl_console.o
OBJS += bl_xscom.o
OBJS += bl_tpm_spidd.o
OBJS += p10_sbe_spi_cmd.o
OBJS += p10_spi_clear_status_errors.o

# @TODO JIRA PFHB-921 remove these OBJs and VPATHs that are needed for
# compiling MLCA and ecverify into the hostboot bootloader code
# once we get the V3 support into the securerom
# NOTE: needed to create bl_ecverify.C even though it just points to ecverify.C
# because the src/makefile puts the .o's it creates for BOOTLDR_OBJECTS and
# SECUREROM_OBJECTS into the same obj/core directory.  However, ecverify.C needs
# to be compiled differently here than it does for the Secure ROM
OBJS += keccak.o
OBJS += mlca.o
OBJS += ROM_v3.o
OBJS += bl_ecverify.o


# Add these VPATHs to find the above files
VPATH += ${ROOTPATH}/src/securerom/
VPATH += ${ROOTPATH}/src/securerom/contrib/

OPT_LEVEL = -Os

VPATH += ${HWP_PATH}/hwp/spi

include ${ROOTPATH}/config.mk

vpath ${ROOTPATH}/src/usr/console/uart.H  ${HWP_PATH}/hwp/spi/p10_sbe_spi_cmd.H
