#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/hwp/core_activate/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
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
#  IBM_PROLOG_END_TAG
ROOTPATH = ../../../../..

MODULE = core_activate

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_switch_cfsim


##  NOTE: add new object files when you add a new HWP
OBJS =  core_activate.o \
        proc_prep_master_winkle.o   \
        proc_sbe_ffdc.o             \
        proc_stop_deadman_timer.o \
        proc_switch_cfsim.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/core_activate/proc_switch_cfsim


include ${ROOTPATH}/config.mk

