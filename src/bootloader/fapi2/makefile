# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/bootloader/fapi2/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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

# Bootloader omitted from profiling to keep size down
HOSTBOOT_PROFILE_ARTIFACT=

COMMONFLAGS += -DBOOTLOADER
COMMONFLAGS += -DFAPI2_NO_FFDC
COMMONFLAGS += -DFAPI_VARIABLE_BUFFER_NOT_SUPPORTED
COMMONFLAGS += -DFAPI_PLAT_MULTICAST_NOT_SUPPORTED
COMMONFLAGS += -DNO_PLAT_STRING_SUPPORT
COMMONFLAGS += -DPLAT_NO_THREAD_LOCAL_STORAGE
COMMONFLAGS += -DPIB_ERROR_MASK_NOT_SUPPORTED

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/bootloader/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/
EXTRAINCDIR += ${ROOTPATH}/src/usr/pnor/

OBJS += hbbl_plat_hw_access.o
OBJS += hbbl_plat_utils.o
OBJS += hbbl_plat_attribute_service.o

include ${ROOTPATH}/config.mk
