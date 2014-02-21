# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/hwp.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat

#   CompressedScanData struct needed for getRepairRings()
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build

OBJS += dimmBadDqBitmapAccessHwp.o \
		dimmBadDqBitmapFuncs.o \
        fapiTestHwpError.o \
        fapiTestHwpFfdc.o \
        fapiTestHwpConfig.o

include ${ROOTPATH}/src/usr/hwpf/hwp/mvpd_accessors/mvpd.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/pll_accessors/pll.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/winkle_ring_accessors/winkle_ring.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/utility_procedures/utils.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/chip_accessors/chip.mk
include ${ROOTPATH}/src/usr/hwpf/hwp/spd_accessors/spd.mk

