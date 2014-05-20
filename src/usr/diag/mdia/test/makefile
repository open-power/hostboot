# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/mdia/test/makefile $
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

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag

##########################################################
# Following are needed to include hwpf/hwp/fapi.H
##########################################################
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
##########################################################
# Following is needed to include mss_maint_cmds.H
##########################################################
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp

OBJS += mdiafakesm.o
OBJS += mdiafakecm.o

MODULE = testmdia

TESTS = *.H

include ${ROOTPATH}/config.mk
