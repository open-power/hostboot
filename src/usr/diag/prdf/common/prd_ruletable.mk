# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_ruletable.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2014
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

PRDR_RULE_TABLE_FILES += Proc.rule
PRDR_RULE_TABLE_FILES += Ex.rule
PRDR_RULE_TABLE_FILES += Mcs.rule
PRDR_RULE_TABLE_FILES += Membuf.rule
PRDR_RULE_TABLE_FILES += Mba.rule

PRDR_RULE_TABLE_TARGETS = ${PRDR_RULE_TABLE_FILES:.rule=.prf}

prd_ruletable += prdrLoadChip.o
prd_ruletable += prdrLoadChipCache.o
prd_ruletable += prdfRuleMetaData.o
prd_ruletable += prdfRuleChip.o
prd_ruletable += prdfGroup.o
prd_ruletable += prdfPluginMap.o
prd_ruletable += prdfRuleFiles.o

