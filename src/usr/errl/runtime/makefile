# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/trace/runtime/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
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
HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../..
MODULE = errl_rt

OBJS = errlentry.o rt_errlmanager.o errlsctn.o errlsctnhdr.o errlprvt.o errluh.o \
       errlud.o errlsrc.o errluserdetails.o backtrace.o errludtarget.o \
       errludstring.o errludbacktrace.o errludattribute.o \
       errludcallout.o

SUBDIRS = test.d

VPATH += ..
include $(ROOTPATH)/config.mk

# to find errludattribute.[CH] and errludtarget.[CH] - they are generated
#  by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
