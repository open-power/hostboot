# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_common_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014
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
# Hostboot only object files common to both IPL and runtime
################################################################################

# ./
prd_obj += prdfMain.o

# framework/config/
prd_obj += prdfMbaDomain.o

# framework/resolution/
prd_obj += prdfDumpResolution.o

# framework/service/
prd_obj_no_sim += prdfPlatServices.o

# plat/pegasus/ (non-rule plugin related)
prd_obj += prdfCenMbaTdCtlr.o
prd_obj += prdfPllUtils.o

# plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfP8TodPlugins.o
prd_rule_plugin += prdfPlatCenMba.o
prd_rule_plugin += prdfPlatCenMemUtils.o
prd_rule_plugin += prdfPlatP8Ex.o
prd_rule_plugin += prdfPlatP8Proc.o

