# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/hostboot_common.mk $
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

COMMON_TARGETING_REL_PATH = ${TARGETING_REL_PATH}/common
COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_REL_PATH}/common.mk

include ${COMMON_TARGETING_MAKEFILE}

VPATH += ${TARGETING_REL_PATH}/adapters
VPATH += ${COMMON_TARGETING_REL_PATH}
VPATH += ${addprefix ${COMMON_TARGETING_REL_PATH}/, ${COMMON_TARGETING_SUBDIRS}}

