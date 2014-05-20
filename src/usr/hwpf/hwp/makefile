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

OBJS += fapiTestHwp.o
OBJS += fapiTestHwpDq.o
OBJS += fapiHwpExecInitFile.o
OBJS += hwpisteperror.o
OBJS += hwpistepud.o

SUBDIRS	+= dmi_training.d
SUBDIRS	+= sbe_centaur_init.d
SUBDIRS	+= mc_config.d
SUBDIRS	+= dram_training.d
SUBDIRS	+= activate_powerbus.d
SUBDIRS	+= build_winkle_images.d
SUBDIRS	+= core_activate.d
SUBDIRS	+= dram_initialization.d
SUBDIRS	+= edi_ei_initialization.d
SUBDIRS	+= establish_system_smp.d
SUBDIRS	+= bus_training.d
SUBDIRS	+= occ.d
SUBDIRS	+= tod_init.d
SUBDIRS	+= nest_chiplets.d
SUBDIRS	+= start_payload.d
SUBDIRS	+= thread_activate.d
SUBDIRS	+= slave_sbe.d
SUBDIRS	+= pstates.d
SUBDIRS	+= proc_hwreconfig.d
SUBDIRS	+= runtime.d


include ${ROOTPATH}/config.mk
