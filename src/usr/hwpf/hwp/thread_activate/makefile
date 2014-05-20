# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/thread_activate/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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

MODULE = thread_activate

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/thread_activate

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/thread_activate/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/thread_activate/proc_thread_control
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/utility_procedures

##  NOTE: add new object files when you add a new HWP
OBJS += thread_activate.o
OBJS += proc_thread_control.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/thread_activate/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/thread_activate/proc_thread_control


include ${ROOTPATH}/config.mk

