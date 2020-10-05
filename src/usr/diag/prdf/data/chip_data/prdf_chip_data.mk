# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/data/chip_data/prdf_chip_data.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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

# Chip Data Binary targets for the Explorer Chip
prd_cd_exp_trgts += chip_data_explorer_10.cdb

# Chip Data Binary targets for the P10 Chip
prd_cd_p10_trgts += chip_data_p10_10.cdb

prd_cd_combined += chip_data_combined.cdb

# All Chip Data Binary targets
prd_chip_data_targets += ${prd_cd_exp_trgts}
prd_chip_data_targets += ${prd_cd_p10_trgts}
prd_chip_data_targets += ${prd_cd_combined}
