# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/makefile $
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
ROOTPATH = ../../..
MODULE = vpd

#include common objects between hb and runtime
include vpd.mk

#include unique objects
OBJS += vpd.o
OBJS += dimmPres.o
OBJS += rtvpd_load.o

SUBDIRS += test.d
SUBDIRS += runtime.d

BINARY_FILES = $(IMGDIR)/dimmspd.dat:3a9f53e3684e57401ed0aed75f25980fca99f40b
BINARY_FILES += $(IMGDIR)/procmvpd.dat:7dabbe4879dcdd19ed236573aa68e8671fa8c3c7
BINARY_FILES += $(IMGDIR)/cvpd.dat:0400a31bf0c8ecfefb3a21af50cf557c5def0352

include ${ROOTPATH}/config.mk
