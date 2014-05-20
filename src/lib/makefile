# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/lib/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2014
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

ifdef HOSTBOOT_MEMORY_LEAKS
COMMONFLAGS += -DHOSTBOOT_MEMORY_LEAKS=1
endif

include ${ROOTPATH}/config.mk
