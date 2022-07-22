# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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

# Path to perl. So scripts can call perl explicitly, to run, rather than
# calling the script itself.
# Perl 5 removed the current working directory in the @INC and certain scripts
# are failing because they are unable to find the modules that are needed.
# Although these scripts may have #!/usr/bin/perl, calling perl explicitly
# allows for passing in an include directory (-I) which is needed to find
# certain include modules so as to not fail.
PERL_PATH="/usr/bin/perl"
PERL_INC_DIRS="-I../xmltohb"

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

FAPI2_ATTR_XML_DIR = ${ROOTPATH}/src/import/hwpf/fapi2/xml/attribute_info
HB_TEMP_DFLT_SOURCES = $(wildcard \
    ${FAPI2_ATTR_XML_DIR}/${HB_TEMP_DEFAULTS_XML})

FAPI2_INCLUDE_PATH = \
    ${ROOTPATH}/src/include/usr/fapi2
FAPIATTRSRVC_SOURCE = \
    ${FAPI2_INCLUDE_PATH}/${ATTRIBUTE_SERVICE_H}



# Attribute XML files.
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/chips/p10/procedures/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/generic/procedures/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/chips/ocmb/explorer/procedures/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/import/chips/ocmb/common/procedures/xml/attribute_info/*)
FAPI2_ATTR_XML += $(wildcard $(ROOTPATH)/src/usr/targeting/common/xmltohb/deleteme_temp_hb_attrs.xml)

# Filter out Temp defaults XML file from Attribute XML files.
# NOTE: The hb_temp_defaults.xml file is not a normal attribute file with the
#       normal structures that define the attribute itself.  It temporarily
#       provides default values for new attributes defined in other files.
FAPI2_ATTR_XML := $(filter-out $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/hb_temp_defaults.xml,$(FAPI2_ATTR_XML))
FAPI2_ATTR_XML := $(filter-out $(wildcard $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*~) ,$(FAPI2_ATTR_XML))
FAPI2_ATTR_XML := $(filter-out $(wildcard $(ROOTPATH)/src/import/chips/p9/procedures/xml/attribute_info/*~),$(FAPI2_ATTR_XML))

XMLTOHB_FAPIATTR_SOURCES += ${FAPI2_ATTR_XML}


# Manually generated sources

# Common
XMLTOHB_COMMON_ATTRIBUTE_TYPES        = attribute_types.xml
XMLTOHB_COMMON_TARGET_TYPES           = target_types.xml

# HB only
XMLTOHB_HB_ATTRIBUTE_TYPES            = attribute_types_hb.xml
XMLTOHB_HB_TARGET_TYPES               = target_types_hb.xml

# OP PowerVM only
XMLTOHB_OPPOWERVM_ATTRIBUTE_TYPES     = attribute_types_oppowervm.xml
XMLTOHB_OPPOWERVM_TARGET_TYPES        = target_types_oppowervm.xml

# Empty Targeting XML - Needed to generate XMLTOHB_CONFIG_ATTRIBUTE_SOURCES
XMLTOHB_EMPTY_TARGET_TYPES        = target_types_empty.xml

# OP only
XMLTOHB_OPENPOWER_ATTRIBUTE_TYPES     = attribute_types_openpower.xml
XMLTOHB_OPENPOWER_TARGET_TYPES        = target_types_openpower.xml

# Auto generated sources

# EKB
#    Common generated from EKB xml
XMLTOHB_EKB_ATTRIBUTE_TYPES           = attribute_types_ekb.xml
XMLTOHB_EKB_TARGET_TYPES              = target_types_ekb.xml

# Config Sources
#    Contains all sources in configuration
XMLTOHB_CONFIG_ATTRIBUTE_TYPES        = attribute_types_config.xml
XMLTOHB_CONFIG_TARGET_TYPES           = target_types_config.xml

# SP Sources
#    Contains xml that will be exported to SP
XMLTOHB_SP_ATTRIBUTE_TYPES        = attribute_types_sp.xml
XMLTOHB_SP_TARGET_TYPES           = target_types_sp.xml

# SRC
#    a_src = a + a_hb + a_xxx
#    t_src = t + merge_extension(t_hb + t_xxx)
XMLTOHB_SRC_ATTRIBUTE_TYPES           = attribute_types_src.xml
XMLTOHB_SRC_TARGET_TYPES              = target_types_src.xml


# HBX
#    a_hbx = a_ekb + a_xxx
#    t_hbx = merge_extension(t_ekb + t_xxx)
#XMLTOHB_HBX_ATTRIBUTE_TYPES           = attribute_types_hbx.xml
#XMLTOHB_HBX_TARGET_TYPES              = target_types_hbx.xml

# FULL
#    a_full = a_src + a_ekb
#    t_full = t_src + t_ekb
XMLTOHB_FULL_ATTRIBUTE_TYPES          = attribute_types_full.xml
XMLTOHB_FULL_TARGET_TYPES             = target_types_full.xml

# attribute_customization
# hb_temp_defaults.xml + hb_customized_attrs.xml ( + hb_customized_attrs_fsp.xml)
XMLTOHB_ATTRIBUTE_CUSTOMIZATION = attribute_customization.xml

#Note that order matters here , we want hb_customized_attrs to be first so it's defaults get picked up first
#if there are duplicates
XMLTOHB_ATTRIBUTE_CUSTOMIZATION_SOURCES += ${COMMON_TARGETING_REL_PATH}/${EKB_CUSTOMIZED_ATTRS_XML}
XMLTOHB_ATTRIBUTE_CUSTOMIZATION_SOURCES += ${ROOTPATH}/src/import/hwpf/fapi2/xml/attribute_info/hb_temp_defaults.xml
XMLTOHB_ATTRIBUTE_CUSTOMIZATION_SOURCES += $(if $(CONFIG_FSP_BUILD), \
                                           ${COMMON_TARGETING_REL_PATH}/${EKB_CUSTOMIZED_ATTRS_XML_FSP}, \
                                           ${COMMON_TARGETING_REL_PATH}/${EKB_CUSTOMIZED_ATTRS_XML_OP})


# SRC attribute sources
XMLTOHB_SRC_ATTRIBUTE_SOURCES += ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_ATTRIBUTE_TYPES}
XMLTOHB_SRC_ATTRIBUTE_SOURCES += ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_HB_ATTRIBUTE_TYPES}
XMLTOHB_SRC_ATTRIBUTE_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),${XMLTOHB_OPPOWERVM_ATTRIBUTE_TYPES})
XMLTOHB_SRC_ATTRIBUTE_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPENPOWER),${XMLTOHB_OPENPOWER_ATTRIBUTE_TYPES})

# Config Sources
XMLTOHB_CONFIG_ATTRIBUTE_SOURCES += ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_ATTRIBUTE_TYPES}
XMLTOHB_CONFIG_ATTRIBUTE_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),${XMLTOHB_OPPOWERVM_ATTRIBUTE_TYPES})
XMLTOHB_CONFIG_ATTRIBUTE_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPENPOWER),${XMLTOHB_OPENPOWER_ATTRIBUTE_TYPES})


# The customize target file combines all targetTypeExtension files before
# combining them with the common target_types.xml file. To include a new file,
# just add it to the XMLTOHB_*_EXT_TARGET_SOURCES.
XMLTOHB_SRC_CUSTOMIZE_TARGET_SOURCES    = target_types_customize_src.xml
XMLTOHB_CONFIG_CUSTOMIZE_TARGET_SOURCES    = target_types.customize_config.xml


XMLTOHB_SRC_EXT_TARGET_SOURCES += ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_HB_TARGET_TYPES}
XMLTOHB_SRC_EXT_TARGET_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),${XMLTOHB_OPPOWERVM_TARGET_TYPES})
XMLTOHB_SRC_EXT_TARGET_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPENPOWER),${XMLTOHB_OPENPOWER_TARGET_TYPES})

XMLTOHB_CONFIG_EXT_TARGET_SOURCES += ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_EMPTY_TARGET_TYPES}
XMLTOHB_CONFIG_EXT_TARGET_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),${XMLTOHB_OPPOWERVM_TARGET_TYPES})
XMLTOHB_CONFIG_EXT_TARGET_SOURCES += $(if $(CONFIG_INCLUDE_XML_OPENPOWER),${XMLTOHB_OPENPOWER_TARGET_TYPES})


#Define XMLTOHB_GENERIC_SOURCES
XMLTOHB_GENERIC_SOURCES += ${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES}
XMLTOHB_GENERIC_SOURCES += ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}

TEMP_DEFAULT_SOURCES                    = tempdefaults.xml

#XML target types merge script
XMLTOHB_TARGET_MERGE_SCRIPT = updatetargetxml.pl

#XML temp defaults merge script
XMLTOHB_TEMPS_MERGE_SCRIPT = updatetempsxml.pl

VMM_CONSTS_FILE = \
    ${ROOTPATH}/src/include/usr/vmmconst.h

GENFILES = ${XMLTOHB_TARGETS}

XMLTOHB_SYSTEM_BINARIES += $(if $(CONFIG_FSP_BUILD),,simics_P10_targeting.bin.protected)
XMLTOHB_SYSTEM_BINARIES += $(if $(CONFIG_FSP_BUILD),,simics_P10_targeting.bin.unprotected)

XMLTOHB_SYSTEM_BINARIES += $(if $(CONFIG_FSP_BUILD),,vbu_P10_targeting.bin.protected)
XMLTOHB_SYSTEM_BINARIES += $(if $(CONFIG_FSP_BUILD),,vbu_P10_targeting.bin.unprotected)
# debug :
# 	@echo COMMON_TARGETING_PATH_PREFIX = ${COMMON_TARGETING_PATH_PREFIX}
# 	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
# 	@echo COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_MAKEFILE}
# 	@echo XMLTOHB_HEADER_TARGETS = ${XMLTOHB_HEADER_TARGETS}
# 	@echo XMLTOHB_SOURCE_TARGETS = ${XMLTOHB_SOURCE_TARGETS}
# 	@echo XMLTOHB_SYSTEM_BINARIES = ${XMLTOHB_SYSTEM_BINARIES}
# 	@echo XMLTOHB_TARGETS = ${XMLTOHB_TARGETS}
# 	@echo XMLTOHB_GENERIC_SOURCES = ${XMLTOHB_GENERIC_SOURCES}
# 	@echo FAPI_ATTR_SOURCE_DIR = ${FAPI_ATTR_SOURCE_DIR}
# 	@echo FAPI_ATTR_SOURCES = ${FAPI_ATTR_SOURCES}
# 	@echo XMLTOHB_FAPIATTR_SOURCES = ${XMLTOHB_FAPIATTR_SOURCES}
# 	@echo HB_TEMP_DFLT_SOURCES = ${HB_TEMP_DFLT_SOURCES}
# 	@echo XMLTOHB_COMMON_ATTRIBUTE_TYPES = ${XMLTOHB_COMMON_ATTRIBUTE_TYPES}
# 	@echo XMLTOHB_COMMON_TARGET_TYPES = ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_TYPES}
# 	@echo TEMP_DEFAULT_SOURCES = ${TEMP_DEFAULT_SOURCES}
# 	@echo XMLTOHB_HB_ATTRIBUTE_TYPES = ${XMLTOHB_HB_ATTRIBUTE_TYPES}
# 	@echo XMLTOHB_HB_TARGET_TYPES = ${XMLTOHB_HB_TARGET_TYPES}
# 	@echo XMLTOHB_SRC_TARGET_TYPES = ${XMLTOHB_SRC_TARGET_TYPES}
# 	@echo TEMP_GENERIC_XML = ${TEMP_GENERIC_XML}
# 	@echo VPATH = ${VPATH}

EXTRA_PARTS = $(addprefix $(IMGDIR)/, $(XMLTOHB_SYSTEM_BINARIES))

CLEAN_TARGETS += $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES})
CLEAN_TARGETS += $(addprefix $(GENDIR)/, ${XMLTOHB_SYSTEM_BINARIES:.bin=.xml})
CLEAN_TARGETS += ${GENDIR}/${HB_PLAT_ATTR_SRVC_H}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_GENERIC_XML}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_FAPI_XML}
CLEAN_TARGETS += ${GENDIR}/errl/errludattributeP_gen.H
CLEAN_TARGETS += ${GENDIR}/errludattribute_gen.C
CLEAN_TARGETS += ${GENDIR}/errl/errludtarget.H
CLEAN_TARGETS += ${GENDIR}/targAttrInfo.csv
CLEAN_TARGETS += ${GENDIR}/targAttrOverrideData.H
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_SRC_TARGET_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_SRC_ATTRIBUTE_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_SRC_CUSTOMIZE_TARGET_SOURCES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_CONFIG_CUSTOMIZE_TARGET_SOURCES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}
CLEAN_TARGETS += ${GENDIR}/${XMLTOHB_ATTRIBUTE_CUSTOMIZATION}

GENDIR_ERRL = $(ROOTPATH)/obj/genfiles/errl

XMLTOHB_RAN_INDICATION = $(GENDIR)/.called_xmltohb_compiler
CLEAN_TARGETS += $(XMLTOHB_RAN_INDICATION)

COPYHDR_RAN_INDICATION = $(GENDIR)/.called_copy_attrsrvhdr
CLEAN_TARGETS += $(COPYHDR_RAN_INDICATION)

GEN_PASS_BODY += ${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES}
GEN_PASS_BODY += ${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES}
GEN_PASS_BODY += ${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}
GEN_PASS_BODY += ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}

include ${ROOTPATH}/config.mk

# Delete any generated file on error
# # .DELETE_ON_ERROR:

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

# create merged config attribute xml
${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES}: \
				${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_CONFIG_ATTRIBUTE_SOURCES}
		$< $(wordlist 2,$(words $^),$^) > $@

# create merged src attribute xml
${GENDIR}/${XMLTOHB_SRC_ATTRIBUTE_TYPES}: \
				${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_SRC_ATTRIBUTE_SOURCES}
		$< $(wordlist 2,$(words $^),$^) > $@

# create merged src target xml
${GENDIR}/${XMLTOHB_SRC_CUSTOMIZE_TARGET_SOURCES}: \
				${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_SRC_EXT_TARGET_SOURCES}
		$< $(wordlist 2,$(words $^),$^) > $@

# TODO RTC: 178228 Review usage of XMLTOHB_TARGET_MERGE_SCRIPT in this makefile
${GENDIR}/${XMLTOHB_SRC_TARGET_TYPES}: \
		${XMLTOHB_TARGET_MERGE_SCRIPT} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_TYPES} \
		${GENDIR}/${XMLTOHB_SRC_CUSTOMIZE_TARGET_SOURCES}
	./${XMLTOHB_TARGET_MERGE_SCRIPT} $(addprefix --hb=,${GENDIR}/${XMLTOHB_SRC_CUSTOMIZE_TARGET_SOURCES}) \
		$(addprefix --common=,${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_TYPES}) > $@

# create merged config target xml
${GENDIR}/${XMLTOHB_CONFIG_CUSTOMIZE_TARGET_SOURCES}: \
				${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_CONFIG_EXT_TARGET_SOURCES}
		$< $(wordlist 2,$(words $^),$^) > $@

# TODO RTC: 178228 Review usage of XMLTOHB_TARGET_MERGE_SCRIPT in this makefile
${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES}: \
		${XMLTOHB_TARGET_MERGE_SCRIPT} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_TYPES} \
		${GENDIR}/${XMLTOHB_CONFIG_CUSTOMIZE_TARGET_SOURCES}
	./${XMLTOHB_TARGET_MERGE_SCRIPT} $(addprefix --hb=,${GENDIR}/${XMLTOHB_CONFIG_CUSTOMIZE_TARGET_SOURCES}) \
		$(addprefix --common=,${COMMON_TARGETING_REL_PATH}/${XMLTOHB_COMMON_TARGET_TYPES}) > $@


# TODO RTC: 178228 Review usage of XMLTOHB_TARGET_MERGE_SCRIPT in this makefile
# create merged full target xml
${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}: \
		${XMLTOHB_TARGET_MERGE_SCRIPT} ${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES} \
		${GENDIR}/${XMLTOHB_SRC_TARGET_TYPES} ${GENDIR}/${XMLTOHB_SRC_ATTRIBUTE_TYPES} \
		${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES} ${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES}
	./${XMLTOHB_TARGET_MERGE_SCRIPT} $(addprefix --hb=,${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}) \
		$(addprefix --common=,${GENDIR}/${XMLTOHB_SRC_TARGET_TYPES}) > $@
	${PERL_PATH} ${PERL_INC_DIRS} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_SWAP_MAPPED_ATTR_SCRIPT} \
		$(addprefix --srcTargetXml=,${GENDIR}/${XMLTOHB_SRC_TARGET_TYPES}) \
		$(addprefix --ekbTargetXml=,${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}) \
		$(addprefix --fullAttrXml=,${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES}) \
		$(addprefix --fullTargetXml=,${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}) \
		$(addprefix --fapi2Header=,${ROOTPATH}/src/include/usr/fapi2/attribute_service.H)
		echo '<attributes>' | cat - ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES} > tempFull && mv tempFull ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}
		echo '</attributes>' | cat ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES} - > tempFull && mv tempFull ${GENDIR}/${XMLTOHB_FULL_TARGET_TYPES}

# TODO RTC: 178228 Review usage of XMLTOHB_TARGET_MERGE_SCRIPT in this makefile
# create merged sp target xml
${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}: \
		${XMLTOHB_TARGET_MERGE_SCRIPT} ${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES} \
		${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES} ${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES} \
		${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES} ${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}
	./${XMLTOHB_TARGET_MERGE_SCRIPT} $(addprefix --hb=,${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}) \
		$(addprefix --common=,${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES}) > $@
	${PERL_PATH} ${PERL_INC_DIRS} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_SWAP_MAPPED_ATTR_SCRIPT} \
		$(addprefix --srcTargetXml=,${GENDIR}/${XMLTOHB_CONFIG_TARGET_TYPES}) \
		$(addprefix --ekbTargetXml=,${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}) \
		$(addprefix --fullAttrXml=,${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}) \
		$(addprefix --fullTargetXml=,${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}) \
		$(addprefix --fapi2Header=,${ROOTPATH}/src/include/usr/fapi2/attribute_service.H)
		echo '<attributes>' | cat - ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES} > tempSp && mv tempSp ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}
		echo '</attributes>' | cat ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES} - > tempSp && mv tempSp ${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}
	${COMMON_TARGETING_REL_PATH}/${XMLTOHB_REMOVE_HB_MAPPED_ATTR_SCRIPT} \
	$(addprefix --spAttrXml=,${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}) \
	$(addprefix --spTargXml=,${GENDIR}/${XMLTOHB_SP_TARGET_TYPES}) \
	$(addprefix --hbAttrXml=,${COMMON_TARGETING_REL_PATH}/${XMLTOHB_HB_ATTRIBUTE_TYPES}) \



# merge all FAPI attribute files into one
${GENDIR}/${XMLTOHB_FAPI_XML}: ${XMLTOHB_MERGE_SCRIPT} \
        ${XMLTOHB_FAPIATTR_SOURCES}
	$< $(wordlist 2,$(words $^),$^) > $@

# copy FAPI attribute service header file
$(call GENTARGET,$(XMLTOHB_TARGETS)) : $(COPYHDR_RAN_INDICATION)
$(COPYHDR_RAN_INDICATION): ${FAPIATTRSRVC_SOURCE}
	cp ${FAPIATTRSRVC_SOURCE} ${GENDIR}/${HB_PLAT_ATTR_SRVC_H}
	touch $(COPYHDR_RAN_INDICATION)

# merge all attribute customization srcs together
${GENDIR}/${XMLTOHB_ATTRIBUTE_CUSTOMIZATION}: ${XMLTOHB_MERGE_SCRIPT} \
	${XMLTOHB_ATTRIBUTE_CUSTOMIZATION_SOURCES}
	$< $(wordlist 2,$(words $^),$^) > $@

# convert FAPI attrs to HB attrs
${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES} \
${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}: \
	${XMLTOHB_EKB_TARGATTR_SCRIPT} ${GENDIR}/${XMLTOHB_FAPI_XML} \
	fapi_utils.pl ${GENDIR}/${XMLTOHB_ATTRIBUTE_CUSTOMIZATION}
	${PERL_PATH} ${PERL_INC_DIRS} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_EKB_TARGATTR_SCRIPT} \
	$(addprefix --fapi=,${GENDIR}/${XMLTOHB_FAPI_XML}) \
	$(addprefix --attr=,${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES}) \
	$(addprefix --targ=,${GENDIR}/${XMLTOHB_EKB_TARGET_TYPES}) \
	$(addprefix --default=,${GENDIR}/${XMLTOHB_ATTRIBUTE_CUSTOMIZATION})\


# Add EKB attribute xml to src xml to produce the final output.
# Skip adding any attributes that already exists in the src xml
${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES}: \
	${XMLTOHB_DUPLICATE_SCRIPT} ${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES} \
	${GENDIR}/${XMLTOHB_SRC_ATTRIBUTE_TYPES}
	${PERL_PATH} ${PERL_INC_DIRS} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_DUPLICATE_SCRIPT} \
	$(addprefix --ekbXmlFile=,${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES}) \
	$(addprefix --hbXmlFile=,${GENDIR}/${XMLTOHB_SRC_ATTRIBUTE_TYPES}) \
	$(addprefix --fapi2Header=,${ROOTPATH}/src/include/usr/fapi2/attribute_service.H) \
	$(addprefix --outFile=,${GENDIR}/${XMLTOHB_FULL_ATTRIBUTE_TYPES})

# Add EKB attribute xml to config xml to produce the final output.
# Skip adding any attributes that already exists in the src xml
${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES}: \
	${XMLTOHB_DUPLICATE_SCRIPT} ${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES} \
	${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES}
	${PERL_PATH} ${PERL_INC_DIRS} ${COMMON_TARGETING_REL_PATH}/${XMLTOHB_DUPLICATE_SCRIPT} \
	$(addprefix --ekbXmlFile=,${GENDIR}/${XMLTOHB_EKB_ATTRIBUTE_TYPES}) \
	$(addprefix --hbXmlFile=,${GENDIR}/${XMLTOHB_CONFIG_ATTRIBUTE_TYPES}) \
	$(addprefix --fapi2Header=,${ROOTPATH}/src/include/usr/fapi2/attribute_service.H) \
	$(addprefix --outFile=,${GENDIR}/${XMLTOHB_SP_ATTRIBUTE_TYPES})

# generic XML is created from the generic sources only
${GENDIR}/${XMLTOHB_GENERIC_XML}: \
        ${XMLTOHB_MERGE_SCRIPT} ${XMLTOHB_GENERIC_SOURCES}
	$< $(wordlist 2,$(words $^),$^) > $@

# create the header files, only needs generic xml
$(call GENTARGET,$(XMLTOHB_TARGETS)) : $(XMLTOHB_RAN_INDICATION)
$(XMLTOHB_RAN_INDICATION): ${XMLTOHB_COMPILER_SCRIPT} \
    ${GENDIR}/${XMLTOHB_GENERIC_XML} ${GENDIR}/${XMLTOHB_FAPI_XML}
	$< $(addprefix --hb-xml-file=,${GENDIR}/${XMLTOHB_GENERIC_XML}) \
       $(addprefix --fapi-attributes-xml-file=,${GENDIR}/${XMLTOHB_FAPI_XML}) \
         --src-output-dir=$(GENDIR) --img-output-dir=none \
         --img-output-file=none
	cp ${GENDIR_ERRL}/errludattributeP_gen.H ${GENDIR_PLUGINS}
	cp ${GENDIR_ERRL}/errludtarget.H ${GENDIR_PLUGINS}
	touch $(XMLTOHB_RAN_INDICATION)

# .PRECIOUS: ${GENDIR}/%.hb.xml
# system-specific XML needs the generic xml plus the xxx.system.xml file + the
# MRW file
${GENDIR}/%.hb.xml: %.system.xml ${GENDIR}/${XMLTOHB_GENERIC_XML} %.mrw.xml
	${COMMON_TARGETING_REL_PATH}/${XMLTOHB_MERGE_SCRIPT} $^ > $@

# create the binary files
${GENDIR}/%_targeting.bin \
${GENDIR}/%_targeting.bin.protected \
${GENDIR}/%_targeting.bin.unprotected: \
        ${XMLTOHB_COMPILER_SCRIPT} ${GENDIR}/%.hb.xml \
        ${GENDIR}/${XMLTOHB_FAPI_XML} ${VMM_CONSTS_FILE}
	$< $(addprefix --hb-xml-file=,${GENDIR}/$*.hb.xml) \
        $(addprefix --fapi-attributes-xml-file=,${GENDIR}/${XMLTOHB_FAPI_XML}) \
         --src-output-dir=none --img-output-dir=$(dir $@) \
         --img-output-file=$*_targeting.bin \
         --vmm-consts-file=$(VMM_CONSTS_FILE) --noshort-enums
