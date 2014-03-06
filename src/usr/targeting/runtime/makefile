# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/runtime/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
MODULE = targeting_rt

SUBDIRS = test.d

TARGETING_REL_PATH = ..
include ${TARGETING_REL_PATH}/hostboot_common.mk
vpath %.C ${TARGETING_REL_PATH}

HOSTBOOT_RUNTIME_SPECIFIC_OBJS = attrrp_rt.o start_rt.o targplatutil.o \
                                 rt_targeting.o

OBJS = ${COMMON_TARGETING_OBJS} ${HOSTBOOT_RUNTIME_SPECIFIC_OBJS}

include $(ROOTPATH)/config.mk
vpath %.C ${GENDIR}
