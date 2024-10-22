# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/trace/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2024
# [+] Google Inc.
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
MODULE = trace

EXTRAINCDIR += ${ROOTPATH}/src/usr/

OBJS += buffer_common.o
OBJS += interface.o
OBJS += service.o
OBJS += compdesc.o
OBJS += buffer.o
OBJS += bufferpage.o
OBJS += daemonif.o
OBJS += debug.o
OBJS += assert.o
OBJS += complist.o

# We need the client interfaces for console available in the base image,
# similar to the client interfaces for trace.  Putting 'console.o' from the
# console component into libtrace.so instead of creating a whole new library
# for that purpose.
VPATH += ../console
OBJS += $(if $(CONFIG_CONSOLE),console.o)

SUBDIRS += daemon.d
SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk
