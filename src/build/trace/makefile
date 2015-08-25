# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/trace/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2014
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

GEN_PASS_BODY += tracehash
CLEAN_TARGETS += tracehash tracehash.o

ifdef HOST_BINUTILS_DIR
BFD_CFLAGS = -I$(HOST_BINUTILS_DIR)/bfd/ -I$(HOST_BINUTILS_DIR)/include/
BFD_LDFLAGS = $(HOST_BINUTILS_DIR)/bfd/libbfd.a -ldl \
	      $(HOST_BINUTILS_DIR)/libiberty/libiberty.a -lz
else
BFD_LDFLAGS = -lbfd
endif

include $(ROOTPATH)/config.mk

tracehash: tracehash.c
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)gcc -std=c99 -O3 -g -c $< -o $@.o \
					 $(BFD_CFLAGS)
	$(C1)$(CCACHE) $(HOST_PREFIX)gcc -O3 -g $@.o -o $@ $(BFD_LDFLAGS)
	$(C1)rm $@.o
