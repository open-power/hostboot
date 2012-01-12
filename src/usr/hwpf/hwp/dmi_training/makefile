#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwas/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

ROOTPATH = ../../../../..

MODULE = dmi_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training

OBJS =  dmi_training.o  \
        proc_cen_framelock.o    \
        io_run_training.o gcr_funcs.o io_funcs.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training
## vpath   %.C proc_cen_framelock:io_run_training
## vpath   %.H proc_cen_framelock:io_run_training

include ${ROOTPATH}/config.mk
