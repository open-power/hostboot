# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/ecc/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022
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

ROOTPATH = ../../..
MODULE = ecc

OBJDIR = $(ROOTPATH)/obj/modules/$(MODULE)

# Path to the ibm-fw-proprietary repository, starting from the project root.
IBM_ECC_PATH := src/build/tools/extern/ibm-fw-proprietary

# Name of the file that contains the commit hash we want to check out
# in the ibm-fw-proprietary repository.
IBM_FW_PROPRIETARY_COMMIT := LIBECC_COMMIT_HASH

# Path to the ibm-fw-proprietary source code from this directory.
IBM_ECC_PREFIX=$(ROOTPATH)/src/build/tools/extern/ibm-fw-proprietary/vpd

# Directory containing optional precompiled binaries, including
# libecc_static.a. Take them from the root project directory unless
# the variable is already defined.
HOSTBOOT_PRECOMPILED_LIBRARIES ?= $(ROOTPATH)

# Make the IBM proprietary source code include files accessible.
EXTRAINCDIR += $(IBM_ECC_PREFIX)

# Search for source files in the ibm-fw-proprietary repository.
vpath %.c $(IBM_ECC_PREFIX)

# These files will comprise the static library that will contain the ECC implementation.
ARCHIVE_OBJECTS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), $(OBJDIR)/vpdecc.o)
ARCHIVE_OBJECTS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), $(OBJDIR)/vpdecc_support.o)
ARCHIVE_OBJECTS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), $(OBJDIR)/vpd_ecc_api.o)
ARCHIVE_OBJECTS += $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), , $(OBJDIR)/vpd_ecc_api_no_op.o)

# Pass the git hash of the IBM ECC repository to the compiler so that
# it can be included in libecc.so.  This command tries to find a .git
# repository first and use the real hash that the repo is checked out
# at. If there is no repo (as is the case with op-build environments),
# then it expects the hash to be stored in the file called
# $(IBM_FW_PROPRIETARY_COMMIT). In the case where we compile the
# no-op ECC implementation, this value won't be used.
COMMIT_HASH_DEFINITION = $(if $(CONFIG_COMPILE_VPD_ECC_ALGORITHMS), -DIBM_FW_PROPRIETARY_COMMIT_HASH=$$(cd $(IBM_ECC_PREFIX)/.. && (git --git-dir=.git rev-parse HEAD 2>/dev/null || cat $(IBM_FW_PROPRIETARY_COMMIT) 2>/dev/null)))

CXXFLAGS += $(COMMIT_HASH_DEFINITION)
CFLAGS += $(COMMIT_HASH_DEFINITION)

# libecc.o is an alias for the static library/archive that contains
# all the other sub-objects that implement the ECC algorithm. It will
# be the only object used to produce libecc.so. Only files matching
# the pattern %.o should be added to OBJS (otherwise makefile chaos
# ensues), which is why we don't add libecc_static.a directly here.
OBJS += libecc.o

# Tell the linker to include all symbols from the static library
# (libecc_static.a) when it creates the shared library (libecc.so).
LDFLAGS += --whole-archive

# Strip debug symbols from the static library we create for the ECC
# functions. This will remove source file names etc. from the archive.
STRIP_ARCHIVES = 1

# Do not run the git command to check out the submodule multiple times
# when doing a parallel build.
.NOTPARALLEL: $(IBM_ECC_PREFIX)/vpdecc.h $(IBM_ECC_PREFIX)/vpdecc.c $(IBM_ECC_PREFIX)/vpdecc_support.h $(IBM_ECC_PREFIX)/vpdecc_support.c

# This rule will only be executed if these source files are required.
$(IBM_ECC_PREFIX)/vpdecc.h $(IBM_ECC_PREFIX)/vpdecc.c $(IBM_ECC_PREFIX)/vpdecc_support.h $(IBM_ECC_PREFIX)/vpdecc_support.c :
	cd $(ROOTPATH)/$(IBM_ECC_PATH) && \
	git init && \
	git fetch git@github.ibm.com:open-power/ibm-fw-proprietary.git && \
	git checkout $$(cat $(IBM_FW_PROPRIETARY_COMMIT))

# Copy libecc_static.a from the precompiled libraries directory if it
# exists. This allows users to provide their own binary instead of
# compiling it from source. If it doesn't exist, this rule won't run,
# and libecc_static.a will be handled by the general static archive
# rule and created from ARCHIVE_OBJECTS.
$(OBJDIR)/%.a: $(HOSTBOOT_PRECOMPILED_LIBRARIES)/%.a
	mkdir -p $(OBJDIR)
	cp "$<" "$@"

# Create libecc.o from libecc_static.a.
$(OBJDIR)/libecc.o: $(OBJDIR)/libecc_static.a
	@strings "$<" | if grep debug_str >/dev/null ; then echo "$< was not stripped"; exit 1 ; fi
	cp "$<" "$@"

CLEAN_PASS:
	rm -f $(ARCHIVE_OBJECTS) $(OBJDIR)/libecc_static.a

include ${ROOTPATH}/config.mk

$(ARCHIVE_OBJECTS) : $(GENDIR)/config.h
