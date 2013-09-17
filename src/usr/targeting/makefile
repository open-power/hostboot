# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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
################################################################################
#
#  @file src/usr/targeting/makefile
#
#  @brief Makefile for building Hostboot's targeting implementation
#
################################################################################

ROOTPATH = ../../..
MODULE = targeting

TARGETING_REL_PATH = .
include ${TARGETING_REL_PATH}/hostboot_common.mk

ATTR_RP_OBJS = \
    attrrp.o   \
    attrsync.o \
    targplatutil.o

ENTRY_POINT_OBJS =       \
    targetservicestart.o

DEBUG_OBJS =           \
    attributestrings.o

HOSTBOOT_SPECIFIC_OBJS =    \
    ${ENTRY_POINT_OBJS}     \
    ${ATTR_RP_OBJS}         \
    ${DEBUG_OBJS}           \
    namedtarget.o


#debug :
#	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
#	@echo COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_MAKEFILE}
#	@echo COMMON_TARGETING_SUBDIRS = ${COMMON_TARGETING_SUBDIRS}
#	@echo VPATH = ${VPATH}
#	@echo COMMON_TARGETING_OBJS = ${COMMON_TARGETING_OBJS}

OBJS = ${COMMON_TARGETING_OBJS} ${HOSTBOOT_SPECIFIC_OBJS}

SUBDIRS = test.d xmltohb.d runtime.d

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
