# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/simics/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

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
