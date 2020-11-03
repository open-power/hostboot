# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/runtime/makefile $
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
# common objects with runtime

HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../..
MODULE = vpd_rt

# include common objects between hostboot and runtime hostboot
include ../vpd.mk
# include the VPD ECC update/validate APIs for HB and runtime
include ../vpd_ecc_api.mk

# add unique object modules
OBJS += rt_vpd.o

SUBDIRS += test.d

VPATH += ..
CFLAGS += -iquote ../

include $(ROOTPATH)/config.mk

