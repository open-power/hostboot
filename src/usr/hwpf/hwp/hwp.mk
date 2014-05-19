# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/hwp.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat

#   CompressedScanData struct needed for getRepairRings()
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build

OBJS += dimmBadDqBitmapAccessHwp.o
OBJS += dimmBadDqBitmapFuncs.o
OBJS += fapiTestHwpError.o
OBJS += fapiTestHwpFfdc.o
OBJS += fapiTestHwpConfig.o

include ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors/mvpd.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/pll_accessors/pll.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/winkle_ring_accessors/winkle_ring.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/utility_procedures/utils.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/chip_accessors/chip.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/spd_accessors/spd.mk

