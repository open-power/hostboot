#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/hwp/nest_chiplets/makefile $
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

MODULE = nest_chiplets

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets

##  NOTE: add new object files when you add a new HWP
OBJS =  nest_chiplets.o \
		proc_start_clocks_chiplets.o \
        proc_chiplet_scominit.o \
        proc_scomoverride_chiplets.o
        
##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets

include ${ROOTPATH}/config.mk

