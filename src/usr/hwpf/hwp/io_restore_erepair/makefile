# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/io_restore_erepair/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012
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

MODULE = io_restore_erepair

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

OBJS =  io_restore_erepair.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/io_restore_erepair

include ${ROOTPATH}/config.mk
