#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/diag/prdf/makefile $
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
#  IBM_PROLOG_END


ROOTPATH = ../../../..

MODULE = prdf

#------------------------------------------------------------------------------
# paths
#------------------------------------------------------------------------------

VPATH = \
    framework: \


EXTRAINCDIR += ${ROOTPATH}/src/include
EXTRAINCDIR += ${ROOTPATH}/src/include/sys
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/util
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/targeting
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/errl
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer


EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/prdf
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/prdf
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/prdf/framework/service

#------------------------------------------------------------------------------
# objects
#------------------------------------------------------------------------------
include prd_framework.mk


OBJS = ${prd_framework}



SUBDIRS = test.d

include ${ROOTPATH}/config.mk
