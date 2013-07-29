# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/dmi_training/makefile $
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

MODULE = dmi_training

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/mss_getecid
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_dccal
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit

OBJS =  dmi_training.o  \
        proc_cen_framelock.o    \
        dmi_io_run_training.o \
        proc_cen_set_inband_addr.o \
        mss_get_cen_ecid.o \
        dmi_io_dccal.o \
        proc_dmi_scominit.o \
        cen_dmi_scominit.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_framelock
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_run_training
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/mss_getecid
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/dmi_io_dccal
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_pre_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training/io_post_trainadv
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit

include ${ROOTPATH}/config.mk
