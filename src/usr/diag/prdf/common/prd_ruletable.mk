# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_ruletable.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2012
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

PRDR_RULE_TABLE_FILES =	\
	Proc.rule	\
	Ex.rule		\
	Mcs.rule	\
	Membuf.rule \
	Mba.rule

PRDR_RULE_TABLE_TARGETS = ${PRDR_RULE_TABLE_FILES:.rule=.prf}

prd_ruletable = \
 prdrLoadChip.o \
 prdrLoadChipCache.o \
 prdfRuleChip.o \
 prdfGroup.o \
 prdfPluginMap.o \
 prdfRuleFiles.o

