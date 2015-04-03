# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/framework/rule/prdf_rule.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2015
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

# Add Rule tables here:
PRDR_RULE_TABLES += MuranoVeniceProc.prf
PRDR_RULE_TABLES += NaplesProc.prf
PRDR_RULE_TABLES += Ex.prf
PRDR_RULE_TABLES += Mcs.prf
PRDR_RULE_TABLES += Membuf.prf
PRDR_RULE_TABLES += Mba.prf

prd_rule_prf_targets  = ${PRDR_RULE_TABLES}
prd_rule_err_targets  = ${PRDR_RULE_TABLES:.prf=.prf.err.C}
prd_rule_reg_targets  = ${PRDR_RULE_TABLES:.prf=.prf.reg.C}
prd_rule_html_targets = ${PRDR_RULE_TABLES:.prf=.prf.html}

