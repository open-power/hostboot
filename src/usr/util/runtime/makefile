# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/util/runtime/makefile $
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
ROOTPATH = ../../../..
MODULE = util_rt

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/xip/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/utils/stopreg/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/


EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs

EXTRAINCDIR += ${ROOTPATH}/src/usr/pldm/extern/

OBJS += utilbase.o
OBJS += utilstream.o
OBJS += utilmem.o
OBJS += utillidmgr_rt.o
OBJS += utilfile.o
OBJS += utillidpnor.o
OBJS += rt_cmds.o
OBJS += util_rt.o
OBJS += utilrsvdmem.o
OBJS += utilxipimage.o
OBJS += utilcommonattr.o
OBJS += rt_fwnotify.o
OBJS += rt_fwreq_helper.o

SUBDIRS += test.d

VPATH += ..

# pull in pnor_utils explicitly without the rest of the module
VPATH += ${ROOTPATH}/src/usr/pnor/
OBJS += pnor_utils.o

include $(ROOTPATH)/config.mk
