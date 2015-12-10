# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2016
# [+] International Business Machines Corp.
#
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
################################################################################
#
#  @file targeting/xmltohb/makefile
#
#  @brief Makefile for building Hostboot's xmltohb dir
#
################################################################################

ROOTPATH = ../../../..

# Point to the common targeting makefile for xmltohb
COMMON_XMLTOHB_DIR = xmltohb
COMMON_TARGETING_PATH_PREFIX = ../common
COMMON_TARGETING_REL_PATH = \
    ${COMMON_TARGETING_PATH_PREFIX}/${COMMON_XMLTOHB_DIR}
COMMON_TARGETING_MAKEFILE = \
    ${COMMON_TARGETING_REL_PATH}/common.mk

# Include the common targeting makefile for xmltohb verbatim
include ${COMMON_TARGETING_MAKEFILE}

VPATH = ${COMMON_TARGETING_REL_PATH}

FAPI_ATTR_SOURCE_DIR = ${ROOTPATH}/src/usr/hwpf/hwp


XMLTOHB_FAPIATTR_SOURCES += \
    ${addprefix ${FAPI_ATTR_SOURCE_DIR}/, ${FAPI_ATTR_SOURCES}}

# Attribute XML files.
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/chips/p9/procedures/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*)

XMLTOHB_FAPIATTR_SOURCES += ${FAPI2_ATTR_XML}

XMLTOHB_COMMON_ATTRIBUTE_SOURCES        = attribute_types.xml
XMLTOHB_COMMON_TARGET_SOURCES           = target_types.xml

XMLTOHB_HB_ATTRIBUTE_SOURCES            = attribute_types_hb.xml
XMLTOHB_HB_TARGET_SOURCES               = target_types_hb.xml

XMLTOHB_MERGED_COMMON_TARGET_SOURCES    = target_types_merged.xml

#Define XMLTOHB_GENERIC_SOURCES
XMLTOHB_GENERIC_SOURCES += ${XMLTOHB_COMMON_ATTRIBUTE_SOURCES}
XMLTOHB_GENERIC_SOURCES += ${XMLTOHB_HB_ATTRIBUTE_SOURCES}
XMLTOHB_GENERIC_SOURCES += ${GENDIR}/${XMLTOHB_MERGED_COMMON_TARGET_SOURCES}
XMLTOHB_GENERIC_SOURCES += ${XMLTOHB_HB_TARGET_SOURCES}

#XML target types merge script
XMLTOHB_TARGET_MERGE_SCRIPT = updatetargetxml.pl

VMM_CONSTS_FILE = \
    ${ROOTPATH}/src/include/usr/vmmconst.h

GENFILES = ${XMLTOHB_TARGETS}

#debug :
# 	@echo COMMON_TARGETING_PATH_PREFIX = ${COMMON_TARGETING_PATH_PREFIX}
# 	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
# 	@echo COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_MAKEFILE}
# 	@echo XMLTOHB_HEADER_TARGETS = ${XMLTOHB_HEADER_TARGETS}
# 	@echo XMLTOHB_SOURCE_TARGETS = ${XMLTOHB_SOURCE_TARGETS}
# 	@echo XMLTOHB_SYSTEM_BINARIES = ${XMLTOHB_SYSTEM_BINARIES}
# 	@echo XMLTOHB_TARGETS = ${XMLTOHB_TARGETS}
# 	@echo XMLTOHB_GENERIC_SOURCES = ${XMLTOHB_GENERIC_SOURCES}
# 	@echo FAPI_ATTR_SOURCES = ${FAPI_ATTR_SOURCES}
# 	@echo FAPI_ATTR_SOURCE_DIR = ${FAPI_ATTR_SOURCE_DIR}
# 	@echo XMLTOHB_FAPIATTR_SOURCES = ${XMLTOHB_FAPIATTR_SOURCES}
# 	@echo XMLTOHB_COMMON_ATTRIBUTE_SOURCES = ${XMLTOHB_COMMON_ATTRIBUTE_SOURCES}
# 	@echo XMLTOHB_COMMON_TARGET_SOURCES = ${XMLTOHB_COMMON_TARGET_SOURCES}
# 	@echo XMLTOHB_HB_ATTRIBUTE_SOURCES = ${XMLTOHB_HB_ATTRIBUTE_SOURCES}
# 	@echo XMLTOHB_HB_TARGET_SOURCES = ${XMLTOHB_HB_TARGET_SOURCES}
# 	@echo XMLTOHB_MERGED_COMMON_TARGET_SOURCES = ${XMLTOHB_MERGED_COMMON_TARGET_SOURCES}
# 	@echo VPATH = ${VPATH}

EXTRA_PARTS = $(addprefix $(IMGDIR)/, $(XMLTOHB_SYSTEM_BINARIES))

CLEAN_TARGETS += $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES})
CLEAN_TARGETS += $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES:.bin=.xml})
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_GENERIC_XML}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_FAPI_XML}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_MERGED_COMMON_TARGET_SOURCES}
CLEAN_TARGETS += ${GENDIR}/errl/errludattribute.H
CLEAN_TARGETS += ${GENDIR}/errl/errludtarget.H

GENDIR_ERRL = $(ROOTPATH)/obj/genfiles/errl

XMLTOHB_RAN_INDICATION = $(GENDIR)/.called_xmltohb_compiler
CLEAN_TARGETS += $(XMLTOHB_RAN_INDICATION)

include ${ROOTPATH}/config.mk

# Delete any generated file on error
.DELETE_ON_ERROR:

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

# create merged target xml
${GENDIR}/${XMLTOHB_MERGED_COMMON_TARGET_SOURCES}: \
        ${XMLTOHB_TARGET_MERGE_SCRIPT} ${XMLTOHB_COMMON_TARGET_SOURCES} ${XMLTOHB_HB_TARGET_SOURCES}
	./${XMLTOHB_TARGET_MERGE_SCRIPT} $(addprefix --hb=,${COMMON_TARGETING_REL_PATH}/${XMLTOHB_HB_TARGET_SOURCES}) \
       $(addprefix --common=,${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_SOURCES}) > $@

# generic XML is created from the generic sources only
${GENDIR}/${XMLTOHB_GENERIC_XML}: \
        ${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_GENERIC_SOURCES}
	$< $(wordlist 2,$(words $^),$^) > $@

# merge all FAPI attribute files into one
${GENDIR}/${XMLTOHB_FAPI_XML}: ${XMLTOHB_MERGE_SCRIPT} \
        ${XMLTOHB_FAPIATTR_SOURCES}
	$< $(wordlist 2,$(words $^),$^) > $@

# create the header files, only needs generic xml
$(call GENTARGET,$(XMLTOHB_TARGETS)) : $(XMLTOHB_RAN_INDICATION)
$(XMLTOHB_RAN_INDICATION): ${XMLTOHB_COMPILER_SCRIPT} \
    ${GENDIR}/${XMLTOHB_GENERIC_XML} ${GENDIR}/${XMLTOHB_FAPI_XML}
	$< $(addprefix --hb-xml-file=,${GENDIR}/${XMLTOHB_GENERIC_XML}) \
       $(addprefix --fapi-attributes-xml-file=,${GENDIR}/${XMLTOHB_FAPI_XML}) \
         --src-output-dir=$(GENDIR) --img-output-dir=none \
         --img-output-file=none
	cp ${GENDIR_ERRL}/errludattribute.H ${GENDIR_PLUGINS}
	cp ${GENDIR_ERRL}/errludtarget.H ${GENDIR_PLUGINS}
	touch $(XMLTOHB_RAN_INDICATION)

# system-specific XML needs the generic plus the xxx.system.xml file + the
# MRW file
${GENDIR}/%.hb.xml: %.system.xml ${XMLTOHB_GENERIC_SOURCES} %.mrw.xml
	${COMMON_TARGETING_REL_PATH}/${XMLTOHB_MERGE_SCRIPT} $^ > $@

# create the binary files
${GENDIR}/%_targeting.bin: ${XMLTOHB_COMPILER_SCRIPT} ${GENDIR}/%.hb.xml \
        ${GENDIR}/${XMLTOHB_FAPI_XML} ${VMM_CONSTS_FILE}
	$< $(addprefix --hb-xml-file=,${GENDIR}/$*.hb.xml) \
        $(addprefix --fapi-attributes-xml-file=,${GENDIR}/${XMLTOHB_FAPI_XML}) \
         --src-output-dir=none --img-output-dir=$(dir $@) \
         --img-output-file=$(notdir $@) \
         --vmm-consts-file=$(VMM_CONSTS_FILE) --noshort-enums \
         --version-page

