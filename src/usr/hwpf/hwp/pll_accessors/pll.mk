# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/pll_accessors/pll.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2015
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
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/pll_accessors

VPATH += ${HWPPATH}/pll_accessors
CFLAGS += $(if $(CONFIG_VPO_COMPILE),-DFAPI_SIMULATION,)
OBJS += getPllRingAttr.o
OBJS += getPllRingInfoAttr.o

