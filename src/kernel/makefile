# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2019
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

COMMONFLAGS += -DHOSTBOOT_KERNEL

OBJS += start.o
OBJS += kernel.o
OBJS += console.o
OBJS += pagemgr.o
OBJS += heapmgr.o
OBJS += taskmgr.o
OBJS += cpumgr.o

OBJS += syscall.o
OBJS += scheduler.o
OBJS += spinlock.o
OBJS += exception.o
OBJS += vmmmgr.o
OBJS += timemgr.o

OBJS += futexmgr.o
OBJS += ptmgr.o
OBJS += segmentmgr.o
OBJS += devicesegment.o
OBJS += basesegment.o

OBJS += block.o
OBJS += cpuid.o
OBJS += misc.o
OBJS += msghandler.o
OBJS += blockmsghdlr.o
OBJS += stacksegment.o

OBJS += softpatch_p8.o
OBJS += barrier.o
OBJS += idebug.o
OBJS += intmsghandler.o
OBJS += deferred.o

OBJS += shutdown.o
OBJS += forceattn_p9.o
OBJS += terminate.o
OBJS += ipc.o
OBJS += machchk.o

OBJS += doorbell.o
OBJS += workitem.o

OBJS += bltohbdatamgr.o

EXTRAINCDIR += ${ROOTPATH}/src/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr

include ${ROOTPATH}/config.mk

