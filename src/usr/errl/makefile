# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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
MODULE = errl

#include common ojects between hostboot and runtime hostboot
include errl.mk

OBJS += errlmanager.o
OBJS += errludprintk.o

# We need this logic to be available very early so we will
# include it in here instead of libutil that is loaded later.
VPATH += ${ROOTPATH}/src/usr/util/
OBJS += utiltime.o
OBJS += utiltime_common.o

SUBDIRS += test.d
SUBDIRS += parser.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk

# to find errludtarget.[CH] - they are generated
#  by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
