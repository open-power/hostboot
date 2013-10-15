# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/runtime/makefile $
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
# common objects with runtime
HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../..
MODULE = vpd_rt

#include common objects between hostboot and runtime hostboot
include ../vpd.mk

#add unique object modules
OBJS += rt_vpd.o 

SUBDIRS = test.d

VPATH += ..

include $(ROOTPATH)/config.mk

