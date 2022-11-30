# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/rule/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2022
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

# Relative path to root from this makefile
ROOTPATH = ../../../../..

# Relative path to root from OBJ_RULE
OBJ_PLUG_LINK_PATH = ../../../..

OBJ_RULE = obj/modules/prdf/rule
OBJ_PLUG = obj/genfiles/plugins/prdf
SRC_USR  = src/usr/diag/prdf
SRC_INC  = src/include/usr/diag/prdf

OBJ_RULE_DIR = ${ROOTPATH}/${OBJ_RULE}
OBJ_PLUG_DIR = ${ROOTPATH}/${OBJ_PLUG}
SRC_USR_DIR  = ${ROOTPATH}/${SRC_USR}

OBJ_RULE_LINK_DIR = ${OBJ_PLUG_LINK_PATH}/${OBJ_RULE}

VPATH = ${SRC_USR_DIR}/common/rule

include ../common/rule/prdf_rule.mk

#------------------------------------------------------------------------------
# Generated files
#------------------------------------------------------------------------------

PRDR_CMP		= prdrCompile
PRDR_CMP_o		= ${PRDR_CMP}.o
PRDR_CMP_C		= ${PRDR_CMP}.C

PRDR_CMP_YACC   = ${PRDR_CMP}.y
PRDR_CMP_YACC_o = ${PRDR_CMP_YACC}.o
PRDR_CMP_YACC_C = ${PRDR_CMP_YACC}.C
PRDR_CMP_YACC_H = ${PRDR_CMP_YACC}.H

PRDR_CMP_FLEX   = ${PRDR_CMP}.lex
PRDR_CMP_FLEX_o = ${PRDR_CMP_FLEX}.o
PRDR_CMP_FLEX_C = ${PRDR_CMP_FLEX}.C

PRDR_CMP_PATH		 = ${OBJ_RULE_DIR}/${PRDR_CMP}
PRDR_CMP_o_PATH		 = ${OBJ_RULE_DIR}/${PRDR_CMP_o}

PRDR_CMP_YACC_o_PATH = ${OBJ_RULE_DIR}/${PRDR_CMP_YACC_o}
PRDR_CMP_YACC_C_PATH = ${OBJ_RULE_DIR}/${PRDR_CMP_YACC_C}
PRDR_CMP_YACC_H_PATH = ${OBJ_RULE_DIR}/${PRDR_CMP_YACC_H}

PRDR_CMP_FLEX_o_PATH = ${OBJ_RULE_DIR}/${PRDR_CMP_FLEX_o}
PRDR_CMP_FLEX_C_PATH = ${OBJ_RULE_DIR}/${PRDR_CMP_FLEX_C}

PRF_IMG_PATHS    = $(addprefix ${IMGDIR}/,       ${prd_rule_prf_targets})
ERR_PLUGIN_PATHS = $(addprefix ${OBJ_PLUG_DIR}/, ${prd_rule_err_targets})
ERR_DISPLAY_PATHS= $(addprefix ${OBJ_PLUG_DIR}/, ${prd_rule_disp_targets})
REG_PLUGIN_PATHS = $(addprefix ${OBJ_PLUG_DIR}/, ${prd_rule_reg_targets})

#-------------------------------------------------------------------------------
# Files linked to the error log plugins directory
#-------------------------------------------------------------------------------

# Entire directories to link.
SOURCE_PLUGIN_DIRS += ${SRC_USR}/common/plugins
SOURCE_PLUGIN_DIRS += ${SRC_USR}/plugins

# Individual source files to link.
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/rule/prdf_rule.mk
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/rule/tables.mk
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/util/prdfAssert.h
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/util/prdfBitString.C
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/util/prdfBitString.H
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/util/UtilHash.H
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/plat/mem/prdfMemConst.H
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/iipconst.h
SOURCE_PLUGIN_FILES += ${SRC_USR}/common/prdf_types.h
SOURCE_PLUGIN_FILES += ${SRC_INC}/common/prdf_service_codes.H
SOURCE_PLUGIN_FILES += ${SRC_INC}/common/prdfAttnTypes.H
SOURCE_PLUGIN_FILES += $(foreach d, ${SOURCE_PLUGIN_DIRS}, $(addprefix $(d)/, $(notdir $(wildcard ${ROOTPATH}/$(d)/*))))

LINK_PLUGIN_FILES += $(addprefix ${OBJ_PLUG_DIR}/,$(notdir ${SOURCE_PLUGIN_FILES}))

#-------------------------------------------------------------------------------
# CODE_PASS
#-------------------------------------------------------------------------------

CODE_PASS_BODY += ${PRF_IMG_PATHS}
CODE_PASS_BODY += ${ERR_PLUGIN_PATHS}
CODE_PASS_BODY += ${ERR_DISPLAY_PATHS}
CODE_PASS_BODY += ${REG_PLUGIN_PATHS}
CODE_PASS_BODY += ${LINK_PLUGIN_FILES}

CLEAN_TARGETS += ${PRDR_CMP_PATH}
CLEAN_TARGETS += ${PRDR_CMP_o_PATH}
CLEAN_TARGETS += ${PRDR_CMP_YACC_o_PATH}
CLEAN_TARGETS += ${PRDR_CMP_YACC_C_PATH}
CLEAN_TARGETS += ${PRDR_CMP_YACC_H_PATH}
CLEAN_TARGETS += ${PRDR_CMP_FLEX_o_PATH}
CLEAN_TARGETS += ${PRDR_CMP_FLEX_C_PATH}
CLEAN_TARGETS += $(addprefix ${OBJ_RULE_DIR}/, ${prd_rule_prf_targets})
CLEAN_TARGETS += $(addprefix ${OBJ_RULE_DIR}/, ${prd_rule_err_targets})
CLEAN_TARGETS += $(addprefix ${OBJ_RULE_DIR}/, ${prd_rule_disp_targets})
CLEAN_TARGETS += $(addprefix ${OBJ_RULE_DIR}/, ${prd_rule_reg_targets})
CLEAN_TARGETS += $(addprefix ${OBJ_RULE_DIR}/, ${prd_rule_html_targets})
CLEAN_TARGETS += ${PRF_IMG_PATHS}
CLEAN_TARGETS += ${ERR_PLUGIN_PATHS}
CLEAN_TARGETS += ${ERR_DISPLAY_PATHS}
CLEAN_TARGETS += ${REG_PLUGIN_PATHS}
CLEAN_TARGETS += ${LINK_PLUGIN_FILES}

# NOTE: All rules defined in this makefile must be done after this line
#       otherwise the default rule 'all' will not be called.
include ${ROOTPATH}/config.mk

# Special recipes to make the output less chatty
PRD_OUT_MAKE = $(C2) "    MAKE       $(notdir $@)"
PRD_OUT_LINK = $(C2) "    LINK       $(notdir $@)"

#-------------------------------------------------------------------------------
# Rules for directories that may not exist.
#-------------------------------------------------------------------------------

${OBJ_RULE_DIR}:
	$(C1)mkdir -p ${OBJ_RULE_DIR}

${OBJ_PLUG_DIR}:
	$(C1)mkdir -p ${OBJ_PLUG_DIR}

#-------------------------------------------------------------------------------
# Build the flex/yacc source code
#-------------------------------------------------------------------------------

${PRDR_CMP_YACC_C_PATH} \
${PRDR_CMP_YACC_H_PATH}: ${PRDR_CMP_YACC} | ${OBJ_RULE_DIR}
	${PRD_OUT_MAKE}
	$(C1)bison -d -o ${PRDR_CMP_YACC_C_PATH} $^

PRDR_CMP_FLEX: ; # Discard implicit rule for %.lex <- %.lex.C
${PRDR_CMP_FLEX_C_PATH}: ${PRDR_CMP_FLEX} | ${OBJ_RULE_DIR}
	${PRD_OUT_MAKE}
	$(C1)flex -o$@ $^

#------------------------------------------------------------------------------
# Build the PRD rule compiler
#------------------------------------------------------------------------------

USERDEFINES = -std=gnu++11 -D__HOSTBOOT_MODULE -O3 -pipe

${PRDR_CMP_YACC_o_PATH}: ${PRDR_CMP_YACC_C_PATH} ${PRDR_CMP_YACC_H_PATH}
	${PRD_OUT_MAKE}
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -c $(USERDEFINES) $< \
		-I ${SRC_USR_DIR}/common/rule \
		-I ${SRC_USR_DIR}/common/util -I ${OBJ_RULE_DIR} \
		-o $@

${PRDR_CMP_FLEX_o_PATH}: ${PRDR_CMP_FLEX_C_PATH} ${PRDR_CMP_YACC_H_PATH}
	${PRD_OUT_MAKE}
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -c $(USERDEFINES) $< \
		-I ${SRC_USR_DIR}/common/rule \
		-I ${SRC_USR_DIR}/common/util -I ${OBJ_RULE_DIR} \
		-o $@

${PRDR_CMP_o_PATH}: ${PRDR_CMP_C} | ${OBJ_RULE_DIR}
	${PRD_OUT_MAKE}
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -c $(USERDEFINES) -DPARSER $< \
		-I ${SRC_USR_DIR}/common/rule \
		-I ${SRC_USR_DIR}/common \
		-I ${SRC_USR_DIR}/common/plugins \
		-I ${SRC_USR_DIR}/common/util \
		-I ${GENDIR} -I ${OBJ_RULE_DIR} \
		-I ${SRC_USR_DIR}/common/framework/resolution \
		-I ${SRC_USR_DIR}/common/framework/service \
		-I $(ROOTPATH)/src/include/usr \
		-o $@

${PRDR_CMP_PATH}: ${PRDR_CMP_YACC_o_PATH} ${PRDR_CMP_FLEX_o_PATH} \
				  ${PRDR_CMP_o_PATH}
	${PRD_OUT_MAKE}
	$(C1)$(HOST_PREFIX)g++ $(USERDEFINES) \
		${PRDR_CMP_YACC_o_PATH} ${PRDR_CMP_FLEX_o_PATH} ${PRDR_CMP_o_PATH} \
        -o $@

#------------------------------------------------------------------------------
# Build the *.prf, *.err.C, and *.reg.C files
#------------------------------------------------------------------------------

vpath %.rule \
	  ../common/plat/p10 \
	  ../common/plat/explorer \
	  ../common/plat/odyssey \
	  ../common/plat/mem

PRDRPP_SEARCHDIRS = -I../common/plat/p10 \
				    -I../common/plat/explorer \
				    -I../common/plat/odyssey \
					-I../common/plat/mem

${OBJ_RULE_DIR}/%.prf \
${OBJ_RULE_DIR}/%.prf.err.C \
${OBJ_RULE_DIR}/%.prf.disp.C \
${OBJ_RULE_DIR}/%.prf.reg.C : %.rule ${PRDR_CMP_PATH}
	${PRD_OUT_MAKE}
	$(C1)cat $< | ${SRC_USR_DIR}/common/rule/prdrpp \
			 ${PRDRPP_SEARCHDIRS} | $(JAILCMD) ${PRDR_CMP_PATH} $@

# Copy all .prf files from ${OBJ_RULE_DIR} to ${IMGDIR}
${PRF_IMG_PATHS}: ${IMGDIR}/% : ${OBJ_RULE_DIR}/%
	$(C1)cp -f $^ $@

#------------------------------------------------------------------------------
# Link the necessary files to the plugins directory
#------------------------------------------------------------------------------

# Link all .prf.err.C and .prf.reg.C files from OBJ_RULE_DIR to OBJ_PLUG_DIR
${ERR_PLUGIN_PATHS} \
${ERR_DISPLAY_PATHS} \
${REG_PLUGIN_PATHS}: ${OBJ_PLUG_DIR}/% : ${OBJ_RULE_DIR}/% | ${OBJ_PLUG_DIR}
	${PRD_OUT_LINK}
	$(C1)ln -sf ${OBJ_RULE_LINK_DIR}/$(notdir $^) $@

# Link all individual header file needed to compile plugin code.
define LINK_RULE
${OBJ_PLUG_DIR}/$(notdir $(1)): $(ROOTPATH)/$(1) | ${OBJ_PLUG_DIR}
	$(C2) "    LINK       $$(notdir $$@)"
	$(C1)ln -sf ${OBJ_PLUG_LINK_PATH}/$(1) $$@
endef
$(foreach file,${SOURCE_PLUGIN_FILES}, $(eval $(call LINK_RULE,$(file))))

