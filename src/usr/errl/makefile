#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/makefile $
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
ROOTPATH = ../../..
MODULE = errl

OBJS = errlentry.o errlmanager.o errlsctn.o errlsctnhdr.o errlprvt.o errluh.o \
       errlud.o errlsrc.o errluserdetails.o backtrace.o errludtarget.o \
       errludstring.o errludbacktrace.o errludattribute.o errludlogregister.o \
       errludcallout.o

SUBDIRS = test.d  parser.d

include ${ROOTPATH}/config.mk

# to find errludattribute.C and .H
vpath %.C ${GENDIR}
