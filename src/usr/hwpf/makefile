#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/makefile $
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
ROOTPATH = ../../..
SUBDIRS = fapi.d hwp.d plat.d test.d

#------------------------------------------------------------------------------
# This makefile controls the generation of HWPF files
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Source XML files
#------------------------------------------------------------------------------
HWP_ERROR_XML_FILES = hwp/fapiHwpErrorInfo.xml   \
    hwp/dmi_training/proc_cen_framelock/proc_cen_framelock_errors.xml \
    hwp/dmi_training/dmi_io_run_training/io_run_training_errors.xml \
    hwp/dimm_errors.xml	\
    hwp/dram_training/memory_errors.xml \
    hwp/start_clocks_on_nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets_errors.xml

HWP_ATTR_XML_FILES = hwp/memory_attributes.xml \
                     hwp/L2_L3_attributes.xml \
                     hwp/scratch_attributes.xml \
                     hwp/system_attributes.xml \
                     hwp/chip_attributes.xml \
                     hwp/dimm_spd_attributes.xml \
                     hwp/dimm_attributes.xml \
                     hwp/unit_attributes.xml \
                     hwp/freq_attributes.xml \
                     hwp/proc_mvpd_attributes.xml

#------------------------------------------------------------------------------
# Initfiles
#------------------------------------------------------------------------------
HWP_INITFILES = hwp/initfiles/sample.initfile
HWP_IF_DEFINE_DIR = hwp/initfiles

#------------------------------------------------------------------------------
# Generated files
#------------------------------------------------------------------------------

# Initfile compiler files
IF_CMP_YACC_C_TARGET = y.tab.c
IF_CMP_YACC_H_TARGET = y.tab.h
IF_CMP_FLEX_TARGET = lex.yy.c
IF_CMP_COMPILER_TARGET = ifcompiler

# The FAPI return code and error info files generated from Error XML files
FAPI_ERROR_TARGETS = fapiHwpReturnCodes.H fapiHwpErrorInfo.H

# The PLAT HWP RC Decoder file generated from Error XML files
PLAT_ERROR_HWP_RC_DECODER = fapiPlatHwpRcDecode.H

# The FAPI attribute id file generated from Attribute XML files
FAPI_ATTR_ID_TARGET = fapiAttributeIds.H

# The FAPI attribute platform check file generated from Attribute XML files
FAPI_ATTR_PLAT_CHECK_TARGET = fapiAttributePlatCheck.H

# The FAPI attributes supported HTML file generated from Attribute XML files
FAPI_ATTRS_SUPPORTED_TARGET = fapiAttributesSupported.html

# The binary, list and attr files generated from Initfiles
# Generation depends on ifcompiler and fapiAttributeIds.H
HWP_IF_NAMES = $(notdir ${HWP_INITFILES})
HWP_IF_BASENAMES = $(basename ${HWP_IF_NAMES})
HWP_IF_BIN_TARGETS = $(addsuffix .if, ${HWP_IF_BASENAMES})
HWP_IF_LST_TARGETS = $(addsuffix .if.list, ${HWP_IF_BASENAMES})
HWP_IF_ATT_TARGETS = $(addsuffix .if.attr, ${HWP_IF_BASENAMES})
HWP_IF_ALL_TARGETS = ${HWP_IF_BIN_TARGETS} ${HWP_IF_LST_TARGETS} \
                     ${HWP_IF_ATT_TARGETS}

# The FAPI Initfile attribute service
# Generation depends on the Initfile <name>.if.attr files
FAPI_ATTR_IF_TARGET = fapiAttributeService.C

GENFILES = ${IF_CMP_YACC_C_TARGET} \
           ${IF_CMP_YACC_H_TARGET} \
           ${IF_CMP_FLEX_TARGET} \
           ${IF_CMP_COMPILER_TARGET} \
           ${FAPI_ERROR_TARGETS} \
           ${PLAT_ERROR_HWP_RC_DECODER} \
           ${FAPI_ATTR_ID_TARGET} \
           ${FAPI_ATTR_PLAT_CHECK_TARGET} \
           ${FAPI_ATTRS_SUPPORTED_TARGET} \
           ${HWP_IF_ALL_TARGETS} \
           ${FAPI_ATTR_IF_TARGET}

EXTRA_PARTS = ${ROOTPATH}/img/${HWP_IF_BIN_TARGETS}

include ${ROOTPATH}/config.mk

#------------------------------------------------------------------------------
# The Initfile compiler
#------------------------------------------------------------------------------
$(call GENTARGET, ${IF_CMP_YACC_C_TARGET} ${IF_CMP_YACC_H_TARGET}) : \
        ifcompiler/initCompiler.y
	yacc -d -o ${GENDIR}/${IF_CMP_YACC_C_TARGET} $^

$(call GENTARGET, ${IF_CMP_FLEX_TARGET}) : \
        ifcompiler/initCompiler.lex
	flex -o$@ $^

IF_COMPILER_C_FILES = ifcompiler/initCompiler.C \
                      ifcompiler/initRpn.C \
                      ifcompiler/initScom.C \
                      ifcompiler/initSymbols.C

IF_COMPILER_H_FILES = ifcompiler/initCompiler.H \
                      ifcompiler/initRpn.H \
                      ifcompiler/initScom.H \
                      ifcompiler/initSymbols.H

$(call GENTARGET, ${IF_CMP_COMPILER_TARGET}) : \
        ${GENDIR}/${IF_CMP_YACC_C_TARGET} \
        ${GENDIR}/${IF_CMP_YACC_H_TARGET} \
        ${GENDIR}/${IF_CMP_FLEX_TARGET} \
        ${IF_COMPILER_C_FILES} \
        ${IF_COMPILER_H_FILES}
	g++ ${IF_COMPILER_C_FILES} ${GENDIR}/${IF_CMP_FLEX_TARGET} \
        ${GENDIR}/${IF_CMP_YACC_C_TARGET} -I ifcompiler -I ${GENDIR} \
        -I ${ROOTPATH}/src/include/usr/hwpf/hwp -o $@

#------------------------------------------------------------------------------
# The FAPI return code and error info files generated from Error XML files
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ERROR_TARGETS}) : \
        fapi/fapiParseErrorInfo.pl ${HWP_ERROR_XML_FILES}
	$< $(dir $@) ${HWP_ERROR_XML_FILES}

#------------------------------------------------------------------------------
# The PLAT HWP RC Decoder file generated from Error XML files
#------------------------------------------------------------------------------
$(call GENTARGET, ${PLAT_ERROR_HWP_RC_DECODER}) : \
        plat/fapiPlatCreateHwpRcDecoder.pl ${HWP_ERROR_XML_FILES}
	$< $(dir $@) ${HWP_ERROR_XML_FILES}

#------------------------------------------------------------------------------
# The FAPI attribute id file, the FAPI attribute platform check file and the
# FAPI attributes supported file generated from Attribute XML files
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ATTR_ID_TARGET} ${FAPI_ATTR_PLAT_CHECK_TARGET} \
                  ${FAPI_ATTRS_SUPPORTED_TARGET}) : \
        fapi/fapiParseAttributeInfo.pl ${HWP_ATTR_XML_FILES}
	$< $(dir $@) ${HWP_ATTR_XML_FILES}

#------------------------------------------------------------------------------
# The binary, list and attr files generated from Initfiles
#------------------------------------------------------------------------------
$(call GENTARGET, ${HWP_IF_ALL_TARGETS}) : \
        ${GENDIR}/${IF_CMP_COMPILER_TARGET} ${HWP_INITFILES} ${GENDIR}/${FAPI_ATTR_ID_TARGET} ${HWP_IF_DEFINE_DIR}
	$< -init ${HWP_INITFILES} -outdir $(dir $@) -attr ${GENDIR}/${FAPI_ATTR_ID_TARGET} \
    -I ${HWP_IF_DEFINE_DIR}

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

#------------------------------------------------------------------------------
# The FAPI Initfile attribute service
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ATTR_IF_TARGET}) : \
        fapi/fapiCreateIfAttrService.pl ${HWP_ATTR_XML_FILES} \
        $(addprefix ${GENDIR}/, $(HWP_IF_ATT_TARGETS))
	$< $(dir $@) $(addprefix ${GENDIR}/, $(HWP_IF_ATT_TARGETS)) -a ${HWP_ATTR_XML_FILES}

