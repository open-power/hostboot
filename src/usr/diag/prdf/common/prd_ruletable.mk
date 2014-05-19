# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_ruletable.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2005,2014
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

