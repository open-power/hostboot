# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/makefile $
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
MODULE = errl

OBJS += errlentry.o
OBJS += errlmanager.o
OBJS += errlsctn.o
OBJS += errlsctnhdr.o
OBJS += errlprvt.o
OBJS += errluh.o
OBJS += errlud.o
OBJS += errlsrc.o
OBJS += errluserdetails.o
OBJS += backtrace.o
OBJS += errludtarget.o
OBJS += errludstring.o
OBJS += errludbacktrace.o
OBJS += errludattribute.o
OBJS += errludlogregister.o
OBJS += errludcallout.o
OBJS += errludprintk.o

SUBDIRS += test.d
SUBDIRS += parser.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk

# to find errludattribute.[CH] and errludtarget.[CH] - they are generated
#  by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
