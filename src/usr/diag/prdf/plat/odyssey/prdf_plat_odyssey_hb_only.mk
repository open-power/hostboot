# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/plat/odyssey/prdf_plat_odyssey_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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
################################################################################
# Paths common to both IPL and runtime
################################################################################

prd_vpath += ${PRD_SRC_PATH}/plat/odyssey

prd_incpath += ${PRD_SRC_PATH}/plat/odyssey

################################################################################
# Hostboot only object files common to both IPL and runtime
################################################################################

# plat/odyssey/ (rule plugin related)

################################################################################
# Hostboot only object files (IPL only)
################################################################################

ifneq (${HOSTBOOT_RUNTIME},1)

# plat/odyssey/ (rule plugin related)
prd_rule_plugin += prdfOdysseyPlugins_ipl.o

endif

################################################################################
# Hostboot only object files (runtime only)
################################################################################

ifeq (${HOSTBOOT_RUNTIME},1)

# plat/odyssey/ (rule plugin related)
prd_rule_plugin += prdfOdysseyPlugins_rt.o

endif