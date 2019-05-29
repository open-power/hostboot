# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2019
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

HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../../..
MODULE = prdf_rt

SUBDIRS += test.d

################################################################################

# ROOTPATH must be defined before including this file.
include ../prdf_hb_only.mk  # Will define PRD_SRC_PATH and PRD_INC_PATH

# PRD_SRC_PATH and PRD_INC_PATH must be defined before including these files.
include ../common/prdf_common_fsp_and_hb.mk
include ../common/framework/prdf_framework.mk
include ../common/plat/p9/prdf_plat_p9.mk
include ../common/plat/cen/prdf_plat_cen.mk
include ../common/plat/mem/prdf_plat_mem.mk
include ../common/plat/centaur/prdf_plat_centaur.mk
include ../common/plat/cumulus/prdf_plat_cumulus.mk
include ../common/plat/nimbus/prdf_plat_nimbus.mk
include ../common/plat/explorer/prdf_plat_explorer.mk
include ../plat/cen/prdf_plat_cen_hb_only.mk
include ../plat/mem/prdf_plat_mem_hb_only.mk
include ../plat/explorer/prdf_plat_explorer_hb_only.mk
include ../plat/p9/prdf_plat_p9_hb_only.mk

VPATH += ${prd_vpath}

EXTRAINCDIR += ${prd_incpath}

OBJS += ${prd_obj}
OBJS += ${prd_obj_no_sim}
OBJS += ${prd_rule_plugin}

################################################################################

include $(ROOTPATH)/config.mk

