# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
# PRD rule plugin object files (Hostboot only).
################################################################################

PRDF_RULE_PLUGINS_PEGASUS_HB = \
	prdfPlatCenPll.o

################################################################################
# PRD object files (Hostboot only).
################################################################################

prd_config_HB += prdfMbaDomain.o

prd_mnfgtools_HB += prdfMfgThresholdFile.o
prd_mnfgtools_HB += prdfMfgSync.o

prd_plat_HB += prdfCenMbaIplCeStats.o
prd_plat_HB += prdfDramRepairs.o
prd_plat_HB += prdfRasServices.o
prd_plat_HB += prdfPlatCalloutUtil.o

prd_object_files_HB += ${prd_config_HB}
prd_object_files_HB += ${prd_mnfgtools_HB}
prd_object_files_HB += ${prd_plat_HB}
