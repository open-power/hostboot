# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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
ROOTPATH = ../../../..
MODULE = hwp

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat

#   CompressedScanData struct needed for getRepairRings()
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_slw_build

OBJS = fapiTestHwp.o \
       fapiTestHwpError.o \
       fapiTestHwpFfdc.o \
       fapiTestHwpConfig.o \
       fapiTestHwpAttr.o \
       fapiTestHwpDq.o \
       fapiHwpExecInitFile.o \
       dimmBadDqBitmapFuncs.o \
       dimmBadDqBitmapAccessHwp.o \
       erepairAccessorHwpFuncs.o \
       erepairGetFailedLanesHwp.o \
       erepairGetMnfgFailedLanesHwp.o \
       hwpisteperror.o  \
       hwpistepud.o

SUBDIRS	=   dmi_training.d  sbe_centaur_init.d mc_config.d \
            dram_training.d activate_powerbus.d build_winkle_images.d \
            core_activate.d dram_initialization.d edi_ei_initialization.d \
            establish_system_smp.d bus_training.d \
            nest_chiplets.d start_payload.d thread_activate.d slave_sbe.d

include mvpd_accessors/mvpd.mk
include utility_procedures/utils.mk
include io_restore_erepair/restore.mk

include ${ROOTPATH}/config.mk
