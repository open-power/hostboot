# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/linker/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2015
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

ifdef HOST_BINUTILS_DIR
BFD_CFLAGS = -I$(HOST_BINUTILS_DIR)/bfd/ -I$(HOST_BINUTILS_DIR)/include/
BFD_LDFLAGS = $(HOST_BINUTILS_DIR)/bfd/libbfd.a -ldl \
	      $(HOST_BINUTILS_DIR)/libiberty/libiberty.a -lz
else
BFD_LDFLAGS = -lbfd -liberty -lz
endif

CODE_PASS_POST += linker gensyms genlist
CLEAN_TARGETS += linker linker.o gensyms gensyms.o genlist genlist.o

include $(ROOTPATH)/config.mk

linker: linker.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g linker.C -o linker.o -c \
					 $(BFD_CFLAGS)
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g linker.o -o linker \
				         $(BFD_LDFLAGS)
	$(C1)rm linker.o

gensyms: gensyms.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g gensyms.C -o gensyms.o -c
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g gensyms.o -o gensyms
	$(C1)rm gensyms.o

genlist: genlist.C
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g genlist.C -o genlist.o -c
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g genlist.o -o genlist
	$(C1)rm genlist.o
