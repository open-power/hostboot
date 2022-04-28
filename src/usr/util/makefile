# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/util/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2022
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
MODULE = util

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/xip/

OBJS += threadpool.o
OBJS += utilbase.o
OBJS += utilstream.o
OBJS += utilmem.o
OBJS += utilfile.o
OBJS += utillidmgr.o
OBJS += utillidpnor.o
OBJS += utilmbox_scratch.o
OBJS += utiltcemgr.o
OBJS += utilsemipersist.o
OBJS += utilrsvdmem.o
OBJS += utilxipimage.o
OBJS += utilmclmgr.o
OBJS += utilcommonattr.o

# We need this logic to be available very early so we will
# include it in libpldm instead of here.
#OBJS += utiltime.o
#OBJS += utiltime_common.o

SUBDIRS += test.d
SUBDIRS += runtime.d

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include

include ${ROOTPATH}/config.mk
