# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/devtree/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2020
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
MODULE = devtree

CC_OVERRIDE = 1

EXTERN_PATH = ${ROOTPATH}/src/usr/devtree/extern

EXTRAINCDIR += ${EXTERN_PATH}
EXTRAINCDIR += ${EXTERN_PATH}/dtc/
EXTRAINCDIR += ${EXTERN_PATH}/dtc/libfdt/

# Include mk files
include extern/dtc/libfdt/libfdt.mk

OBJS += devtree.o

VPATH += ${EXTERN_PATH}/dtc/libfdt/


include ${ROOTPATH}/config.mk
