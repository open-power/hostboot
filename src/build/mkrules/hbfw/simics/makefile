#   IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/mkrules/hbfw/simics/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
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

#
# FSP Destination: src/hbfw/simics/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.

.include <${RULES_MK}>

OTHERS = copy_scripts

HBFW_SIMICS_PATH = ${MAKETOP}simu/scripts/hbfw/

HBFW_SRC_PATHS = ${.PATH:M*src*hbfw*} ${.PATH:M*obj*hbfw*}
HBFW_SRC_DIRS = ${HBFW_SRC_PATHS:XD}
HBFW_SRC_FILES = ${:!${HBFW_SRC_DIRS:@path@ls ${path};@}!}

HBFW_SCRIPTS_TO_COPY = ${HBFW_SRC_FILES:Nmakefile}
HBFW_SCRIPTS_PATHS = ${HBFW_SCRIPTS_TO_COPY:p}

HBFW_COPY_COMMAND = \
    ${HBFW_SCRIPTS_PATHS:@file@cp -r ${file} ${HBFW_SIMICS_PATH}; @}
HBFW_REMOVE_COMMAND = \
    ${HBFW_SCRIPTS_TO_COPY:@file@rm -rf ${HBFW_SIMICS_PATH}${file}; @}

copy_scripts:
	mkdir -p ${HBFW_SIMICS_PATH}
	${HBFW_COPY_COMMAND}

clobber_copy_scripts:
	${HBFW_REMOVE_COMMAND}
