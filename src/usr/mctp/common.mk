# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/mctp/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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

EXTRAINCDIR += ${ROOTPATH}/src/usr/mctp
EXTRAINCDIR += ${ROOTPATH}/src/usr/mctp/extern
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/mctp

OBJS += core.o
OBJS += alloc.o
OBJS += log.o

VPATH += ${ROOTPATH}/src/usr/mctp
VPATH += ${ROOTPATH}/src/usr/mctp/extern