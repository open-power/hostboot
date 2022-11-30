# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/rule/prdf_rule.mk $
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

# P10 Chip
PRDR_RULE_TABLES += p10_proc.prf
PRDR_RULE_TABLES += p10_eq.prf
PRDR_RULE_TABLES += p10_core.prf
PRDR_RULE_TABLES += p10_nmmu.prf
PRDR_RULE_TABLES += p10_pec.prf
PRDR_RULE_TABLES += p10_phb.prf
PRDR_RULE_TABLES += p10_pauc.prf
PRDR_RULE_TABLES += p10_pau.prf
PRDR_RULE_TABLES += p10_iohs.prf
PRDR_RULE_TABLES += p10_mc.prf
PRDR_RULE_TABLES += p10_mcc.prf
PRDR_RULE_TABLES += p10_omic.prf

# Explorer Chip
PRDR_RULE_TABLES += explorer_ocmb.prf
PRDR_RULE_TABLES += odyssey_ocmb.prf

prd_rule_prf_targets  = ${PRDR_RULE_TABLES}
prd_rule_err_targets  = ${PRDR_RULE_TABLES:.prf=.prf.err.C}
prd_rule_disp_targets = ${PRDR_RULE_TABLES:.prf=.prf.disp.C}
prd_rule_reg_targets  = ${PRDR_RULE_TABLES:.prf=.prf.reg.C}
prd_rule_html_targets = ${PRDR_RULE_TABLES:.prf=.prf.html}

