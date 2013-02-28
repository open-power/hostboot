# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/lib/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2013
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
ROOTPATH = ../..

OBJS = string.o string_ext.o stdlib.o ctype.o assert.o stdio.o math.o
OBJS += syscall_stub.o syscall_task.o syscall_msg.o
OBJS += syscall_mmio.o syscall_time.o sync.o syscall_misc.o
OBJS += syscall_mm.o splaytree.o cxxtest_data.o

ifdef HOSTBOOT_MEMORY_LEAKS
COMMONFLAGS += -DHOSTBOOT_MEMORY_LEAKS=1
endif

include ${ROOTPATH}/config.mk
