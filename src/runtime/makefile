# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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
HOSTBOOT_RUNTIME = 1

# Currently Hostboot doesn't have a great way of passing this
# coverage flag to the runtime objects, so setting it here
# as a one off
ifdef HOSTBOOT_PROFILE
CFLAGS += -DPROFILE_CODE
endif

ROOTPATH = ../..
include ../usr/runtime/common/common.mk
VPATH += ../usr/runtime/common
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/

OBJS += rt_start.o
OBJS += rt_main.o
OBJS += rt_console.o
OBJS += rt_stdlib.o
OBJS += rt_sync.o
OBJS += rt_assert.o
OBJS += rt_vfs.o
OBJS += rt_task.o
OBJS += rt_time.o
OBJS += ${RUNTIME_COMMON_OBJS}

include ${ROOTPATH}/config.mk
