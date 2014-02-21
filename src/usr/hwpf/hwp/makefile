# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/makefile $
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
ROOTPATH = ../../../..
HWPPATH = ./
MODULE = hwp

EXTRAINCDIR += ${ROOTPATH}/src/usr/initservice/istepdispatcher

include hwp.mk

OBJS += fapiTestHwp.o \
        fapiTestHwpDq.o \
        fapiHwpExecInitFile.o \
        hwpisteperror.o  \
        hwpistepud.o

SUBDIRS	=   dmi_training.d  sbe_centaur_init.d mc_config.d \
            dram_training.d activate_powerbus.d build_winkle_images.d \
            core_activate.d dram_initialization.d edi_ei_initialization.d \
            establish_system_smp.d bus_training.d occ.d tod_init.d \
            nest_chiplets.d start_payload.d thread_activate.d slave_sbe.d \
            pstates.d proc_hwreconfig.d runtime.d


include ${ROOTPATH}/config.mk
