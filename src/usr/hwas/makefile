# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwas/makefile $
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
ROOTPATH = ../../..

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwas
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwas/common
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/proc_hwreconfig/proc_enable_reconfig

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/usr/sbe

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

VPATH += ${ROOTPATH}/src/usr/hwas/plat
VPATH += ${ROOTPATH}/src/usr/hwas/common

MODULE = hwas

# files in hwas/common directory
OBJS += hwas.o
OBJS += hwasCallout.o
OBJS += deconfigGard.o

# files in this directory
OBJS += hwasPlat.o
OBJS += hostbootIstep.o
OBJS += hwasPlatError.o
OBJS += hwasPlatCallout.o
OBJS += hwasPlatDeconfigGard.o

SUBDIRS = test.d

include ${ROOTPATH}/config.mk
