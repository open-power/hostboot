# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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
#
# @file src/usr/fapi2/runtime/makefile
#
# @brief Makefile rule for runtime fapi2 module
#

HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../..
MODULE = fapi2_rt

# include common objects between hostboot and runtime hostboot
include ../fapi2.mk

SUBDIRS += test.d

VPATH += ..

# Pull in ecc.o module needed to remove ECC
VPATH += ${ROOTPATH}/src/usr/pnor/
OBJS += ecc.o

include ${ROOTPATH}/config.mk
