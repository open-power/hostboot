# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: framework/rule/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

ROOTPATH = ../../../../../..

RULEOBJDIR = ${ROOTPATH}/obj/modules/prdf/rule

PRD_USR_PATH = ${ROOTPATH}/src/usr/diag/prdf

VPATH = ${PRD_USR_PATH}/common/framework/rule

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

PRDR_CMP_PATH		 = ${RULEOBJDIR}/${PRDR_CMP}
PRDR_CMP_o_PATH		 = ${RULEOBJDIR}/${PRDR_CMP_o}

PRDR_CMP_YACC_o_PATH = ${RULEOBJDIR}/${PRDR_CMP_YACC_o}
PRDR_CMP_YACC_C_PATH = ${RULEOBJDIR}/${PRDR_CMP_YACC_C}
PRDR_CMP_YACC_H_PATH = ${RULEOBJDIR}/${PRDR_CMP_YACC_H}

PRDR_CMP_FLEX_o_PATH = ${RULEOBJDIR}/${PRDR_CMP_FLEX_o}
PRDR_CMP_FLEX_C_PATH = ${RULEOBJDIR}/${PRDR_CMP_FLEX_C}

include ../../common/prd_ruletable.mk # for PRDR_RULE_TABLE_TARGETS

#-------------------------------------------------------------------------------
# code_pass
#-------------------------------------------------------------------------------

# Build the .prf image files
EXTRA_PARTS = $(addprefix ${IMGDIR}/, ${PRDR_RULE_TABLE_TARGETS})

# Clean up the auto generate source files
EXTRA_CLEAN = ${PRDR_CMP_PATH} \
			  ${PRDR_CMP_o_PATH} \
			  ${PRDR_CMP_YACC_o_PATH} \
			  ${PRDR_CMP_YACC_C_PATH} \
			  ${PRDR_CMP_YACC_H_PATH} \
			  ${PRDR_CMP_FLEX_o_PATH} \
			  ${PRDR_CMP_FLEX_C_PATH} \
			  $(addprefix ${RULEOBJDIR}/, ${PRDR_RULE_TABLE_TARGETS})

# NOTE: All rules defined in this makefile must be done after this line
#       otherwise the default rule 'all' will not be called.
include ${ROOTPATH}/config.mk

#-------------------------------------------------------------------------------
# Build the flex/yacc source code
#-------------------------------------------------------------------------------

${PRDR_CMP_YACC_C_PATH} ${PRDR_CMP_YACC_H_PATH}: ${PRDR_CMP_YACC}
	mkdir -p ${RULEOBJDIR}
	bison -d -o ${PRDR_CMP_YACC_C_PATH} $^

PRDR_CMP_FLEX: ; # Discard implicit rule for %.lex <- %.lex.C
${PRDR_CMP_FLEX_C_PATH}: ${PRDR_CMP_FLEX}
	mkdir -p ${RULEOBJDIR}
	flex -o$@ $^

#------------------------------------------------------------------------------
# Build the PRD rule compiler
#------------------------------------------------------------------------------

USERDEFINES = -D__HOSTBOOT_MODULE -O3 -pipe

${PRDR_CMP_YACC_o_PATH}: ${PRDR_CMP_YACC_C_PATH} ${PRDR_CMP_YACC_H_PATH}
	i686-$(MCP_VER)-g++ -c $(USERDEFINES) $< \
		-I ${PRD_USR_PATH}/common/framework/rule \
		-I ${PRD_USR_PATH}/common/util -I ${RULEOBJDIR} \
		-o $@

${PRDR_CMP_FLEX_o_PATH}: ${PRDR_CMP_FLEX_C_PATH} ${PRDR_CMP_YACC_H_PATH}
	i686-$(MCP_VER)-g++ -c $(USERDEFINES) $< \
		-I ${PRD_USR_PATH}/common/framework/rule \
		-I ${PRD_USR_PATH}/common/util -I ${RULEOBJDIR} \
		-o $@

${PRDR_CMP_o_PATH}: ${PRDR_CMP_C}
	mkdir -p ${RULEOBJDIR}
	i686-$(MCP_VER)-g++ -c $(USERDEFINES) $< \
		-I ${PRD_USR_PATH}/common/framework/rule \
		-I ${PRD_USR_PATH}/common \
		-I ${PRD_USR_PATH}/common/util \
		-I ${GENDIR} -I ${RULEOBJDIR} \
		-I ${PRD_USR_PATH}/common/framework/resolution \
		-I ${PRD_USR_PATH}/common/framework/service \
		-o $@

${PRDR_CMP_PATH}: ${PRDR_CMP_YACC_o_PATH} ${PRDR_CMP_FLEX_o_PATH} \
				  ${PRDR_CMP_o_PATH}
	i686-$(MCP_VER)-g++ $(USERDEFINES) \
		${PRDR_CMP_YACC_o_PATH} ${PRDR_CMP_FLEX_o_PATH} ${PRDR_CMP_o_PATH} \
        -o $@

#------------------------------------------------------------------------------
# Build the .prf files
#------------------------------------------------------------------------------

vpath %.rule ../../common/plat/pegasus
PRDRPP_SEARCHDIRS = -I../../common/plat/pegasus

# Build .prf files from .rule files and store them in ${RULEOBJDIR}
${RULEOBJDIR}/%.prf : %.rule ${PRDR_CMP_PATH}
	cat $< | ${PRD_USR_PATH}/common/framework/rule/prdrpp ${PRDRPP_SEARCHDIRS} \
		   | i686-$(MCP_VER)-jail ${PRDR_CMP_PATH} $@

# Copy all .prf files from ${RULEOBJDIR} to ${IMGDIR}
${EXTRA_PARTS}: ${IMGDIR}/% : ${RULEOBJDIR}/%
	cp -f $^ $@

