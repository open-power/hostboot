# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2016
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
MODULE = vpd

#include common objects between hb and runtime
include vpd.mk

#include unique objects
OBJS += vpd.o
OBJS += dimmPres.o
OBJS += rtvpd_load.o

SUBDIRS += test.d
SUBDIRS += runtime.d

BINARY_FILES = $(IMGDIR)/dimmspd.dat:9852a0ed166442ef69ecd91a0379f282419a371f
#Updated mvpd to contain VRML so that part/serial numbers can be
#found for procs CCIN 54E3
BINARY_FILES += $(IMGDIR)/procmvpd.dat:65759fa4aebd2e3b42b25309504a3007b3b51036
BINARY_FILES += $(IMGDIR)/procmvpd_ven.dat:dd8507bec946283260f82af212ed32feaeb3363a
BINARY_FILES += $(IMGDIR)/procmvpd_p9n.dat:aee7240ae33ecd112aeae13a39958e5b713550a8
BINARY_FILES += $(IMGDIR)/vpo_sysmvpd.dat:800c06080f4c94b782f7b38a35bbe9ca88ef1ca9
BINARY_FILES += $(IMGDIR)/vpo_djvpd.dat:eb4dce98f19ebfe77243be1c56d3d0eaa1889d90


#Update to Centaur DD2.0 for CCIN 31E8
BINARY_FILES += $(IMGDIR)/cvpd.dat:2e33352ca95279b992927336567adf960dca7d46

#Direct memory vpd
BINARY_FILES += $(IMGDIR)/dvpd.dat:9292032f653710f92bbeb56b39582b2d0e5296b7

include ${ROOTPATH}/config.mk
