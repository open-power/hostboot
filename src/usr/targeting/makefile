#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/targeting/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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

################################################################################
#
#  @file src/usr/targeting/makefile
#
#  @brief Makefile for building Hostboot's targeting implementation 
#
################################################################################

ROOTPATH = ../../..
MODULE = targeting

COMMON_TARGETING_REL_PATH = common
COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_REL_PATH}/common.mk

include ${COMMON_TARGETING_MAKEFILE}

VPATH = \
    adapters \
    ${COMMON_TARGETING_REL_PATH} \
    ${addprefix ${COMMON_TARGETING_REL_PATH}/, ${COMMON_TARGETING_SUBDIRS}}  

ATTR_RP_OBJS = \
    attrrp.o

ENTRY_POINT_OBJS =       \
    targetservicestart.o

DEBUG_OBJS =           \
    attributestrings.o \
    attributedump.o

HOSTBOOT_SPECIFIC_OBJS = ${ENTRY_POINT_OBJS} ${ATTR_RP_OBJS} ${DEBUG_OBJS}
    
#debug :
#	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
#	@echo COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_MAKEFILE}
#	@echo COMMON_TARGETING_SUBDIRS = ${COMMON_TARGETING_SUBDIRS}
#	@echo VPATH = ${VPATH}
#	@echo COMMON_TARGETING_OBJS = ${COMMON_TARGETING_OBJS}
    
OBJS = ${COMMON_TARGETING_OBJS} ${HOSTBOOT_SPECIFIC_OBJS}

SUBDIRS = test.d xmltohb.d

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
