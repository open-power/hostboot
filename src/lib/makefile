# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/lib/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2015
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

OBJS += string.o
OBJS += string_ext.o
OBJS += stdlib.o
OBJS += ctype.o
OBJS += assert.o
OBJS += stdio.o
OBJS += math.o
OBJS += sprintf.o

OBJS += syscall_stub.o
OBJS += syscall_task.o
OBJS += syscall_msg.o

OBJS += syscall_mmio.o
OBJS += syscall_time.o
OBJS += sync.o syscall_misc.o

OBJS += syscall_mm.o
OBJS += splaytree.o
OBJS += cxxtest_data.o
OBJS += crc32.o
OBJS += utilmisc.o

OBJS += tls.o

ifdef HOSTBOOT_MEMORY_LEAKS
COMMONFLAGS += -DHOSTBOOT_MEMORY_LEAKS=1
endif

include ${ROOTPATH}/config.mk
