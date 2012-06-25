#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/fapi/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011-2012
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
ROOTPATH = ../../../..
MODULE = fapi

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp
CUSTOMFLAGS += -D_NO_SPY_ACCESS=1

OBJS =  fapiReturnCode.o \
        fapiReturnCodeDataRef.o \
        fapiTarget.o \
        fapiHwAccess.o \
        fapiErrorInfo.o \
        fapiAttributeService.o \
        fapiChipEcFeature.o \
        fapiAttributeOverride.o

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
