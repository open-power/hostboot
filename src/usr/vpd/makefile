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
BINARY_FILES += $(IMGDIR)/procmvpd_p9n.dat:63898b079b07fdd997bafc6b3c45af96d1dc40a1
BINARY_FILES += $(IMGDIR)/vpo_sysmvpd.dat:b3b907c2e80b68ffe96e924b9cb0db6735fe4532
BINARY_FILES += $(IMGDIR)/vpo_djvpd.dat:cb2c6de3ad46cdd53605d156e22c4bda8d637a42


#Update to Centaur DD2.0 for CCIN 31E8
BINARY_FILES += $(IMGDIR)/cvpd.dat:2e33352ca95279b992927336567adf960dca7d46

#Direct memory vpd
BINARY_FILES += $(IMGDIR)/dvpd.dat:be4cd7ff59c75151920d17c636612d27caf991b6

include ${ROOTPATH}/config.mk
