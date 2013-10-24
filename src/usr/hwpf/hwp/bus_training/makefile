# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/bus_training/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

ROOTPATH = ../../../../..

MODULE = bus_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

OBJS =  gcr_funcs.o io_funcs.o io_run_training.o pbusLinkSvc.o proc_fab_smp.o \
        io_dccal.o \
        io_power_down_lanes.o   \
        io_read_erepair.o   \
        io_clear_firs.o \
        io_fir_isolation.o \
        io_restore_erepair.o \
        erepairAccessorHwpFuncs.o \
        erepairGetFailedLanesHwp.o \
        erepairSetFailedLanesHwp.o \
        io_post_trainadv.o \
        io_pre_trainadv.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
## vpath   %.C proc_cen_framelock:io_run_training
## vpath   %.H proc_cen_framelock:io_run_training

include ${ROOTPATH}/config.mk
