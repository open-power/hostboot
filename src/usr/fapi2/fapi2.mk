# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/fapi2.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
#
# @file src/usr/fapi2/fapi2.mk
#
# @brief Makefile for fapi2 module
#
GENPATH?=$(ROOTPATH)/obj/genfiles

HWP_PATH_1   += ${ROOTPATH}/src/import/chips/p9/procedures
HWP_PATH_2   += ${ROOTPATH}/src/import/chips/centaur/procedures
HWP_PATH += ${HWP_PATH_1}/ ${HWP_PATH_2}/

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/centaur/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/
EXTRAINCDIR += $(ROOTPATH)/src/import/chips/p9/procedures/hwp/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/accessors/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/initfiles/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += ${HWP_PATH_2}/hwp/memory
EXTRAINCDIR += ${HWP_PATH_2}/hwp/memory/lib/
EXTRAINCDIR += ${HWP_PATH_2}/hwp/memory/lib/shared/
EXTRAINCDIR += ${HWP_PATH_2}/hwp/memory/lib/utils/
EXTRAINCDIR += ${HWP_PATH_2}/vpd_accessors/

include ${ROOTPATH}/src/build/mkrules/verbose.rules.mk
define __CLEAN_TARGET
CLEAN_TARGETS += $(1)
endef

#Hostboot objects
OBJS += plat_utils.o
OBJS += attribute_service.o
OBJS += plat_attribute_service.o
OBJS += plat_attr_override_sync.o
OBJS += plat_hwp_invoker.o
OBJS += target.o
OBJS += plat_hw_access.o
OBJS += plat_spd_access.o
OBJS += plat_mvpd_access.o
OBJS += plat_mbvpd_access.o
OBJS += plat_vpd_access.o
OBJS += plat_wof_access.o
OBJS += dimmBadDqBitmapFuncs.o


#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

include ${HWP_PATH_1}/hwp/accessors/p9_get_mem_vpd_keyword.mk

#EKB Objects (mirrored in src/import)
OBJS += error_info.o
OBJS += ffdc.o
OBJS += fapi2_utils.o
OBJS += p9_collect_some_ffdc.o
OBJS += p9_pib2pcb_mux_seq.o
OBJS += p9_collect_ppe_state.o
OBJS += p9_ppe_state.o
OBJS += p9_ppe_utils.o
OBJS += p9_eq_clear_atomic_lock.o

#Generated Objects
OBJS += fapi2_attribute_service.o
OBJS += collect_reg_ffdc_regs.o

#------------------------------------------------------------------------------
# Set fapi2 build environment
#------------------------------------------------------------------------------

# Chip directory
CHIPS += p9

FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p9/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/centaur/procedures/xml/error_info/*.xml)

# Attribute XML files.
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p9/procedures/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/centaur/procedures/xml/attribute_info/*.xml)

# Filter out Temp defaults XML file from Attribute XML files.
# NOTE: The hb_temp_defaults.xml file is not a normal attribute file with the
#       normal structures that define the attribute itself.  It temporarily
#       provides default values for new attributes defined in other files.
HB_TEMP_DFLT_XML = $(wildcard \
    ${ROOTPATH}/src/import/hwpf/fapi2/xml/attribute_info/hb_temp_defaults.xml)
FAPI2_ATTR_XML := $(filter-out ${HB_TEMP_DFLT_XML},$(FAPI2_ATTR_XML))

# Chip SCOM address header files.
FAPI2_PLAT_INCLUDE += $(addsuffix /common/include, \
  $(addprefix $(ROOTPATH)/src/import/chips/, $(CHIPS)))

#------------------------------------------------------------------------------
# The PLAT HWP RC and FFDC parser file generated from Error XML files
#------------------------------------------------------------------------------
PLAT_HWP_ERR_PARSER = platHwpErrParser.H
GENDIR_PLUGINS = $(ROOTPATH)/obj/genfiles/plugins
GENPLUGINTARGET = $(addprefix $(GENDIR_PLUGINS)/, $(1))
GENFILES_PLUGINS = ${PLAT_HWP_ERR_PARSER}
$(call GENPLUGINTARGET, ${PLAT_HWP_ERR_PARSER}) : \
	$(ROOTPATH)/src/usr/fapi2/platCreateHwpErrParser.pl ${FAPI2_ERROR_XML}
	$< $(dir $@) ${FAPI2_ERROR_XML}


# Add targets from 'BUILD_GENERATED' into the Hostboot 'GEN_PASS'.
GEN_PASS_BODY += $(GEN_TARGETS)
CLEAN_TARGETS += $(GEN_TARGETS)

include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/src/import/tools/build/common.dir/script.rules.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseErrorInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseAttributeInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/createIfAttrService.mk
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket.mk
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket_attr.mk
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundw_bucket.mk
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundw_bucket_attr.mk

# We specifically removed this from the istep10.so and placed it here because
# we have to reapply this init on the shutdown path after the interrupt resource
# provider is shutdown
include $(ROOTPATH)/src/import/chips/p9/procedures/hwp/initfiles/p9_int_scom.mk

CENTAUR_VPD_PATH=${HWP_PATH_2}/vpd_accessors
include ${CENTAUR_VPD_PATH}/getControlCapableData.mk
include ${CENTAUR_VPD_PATH}/getDecompressedISDIMMAttrs.mk
include ${CENTAUR_VPD_PATH}/getISDIMMTOC4DAttrs.mk
include ${CENTAUR_VPD_PATH}/getDQAttrISDIMM.mk
include ${CENTAUR_VPD_PATH}/getDQSAttrISDIMM.mk
include ${CENTAUR_VPD_PATH}/getMBvpdAddrMirrorData.mk
include ${CENTAUR_VPD_PATH}/getMBvpdAttr.mk
include ${CENTAUR_VPD_PATH}/getMBvpdDram2NModeEnabled.mk
include ${CENTAUR_VPD_PATH}/getMBvpdMemoryDataVersion.mk
include ${CENTAUR_VPD_PATH}/getMBvpdSlopeInterceptData.mk
include ${CENTAUR_VPD_PATH}/getMBvpdSpareDramData.mk
include ${CENTAUR_VPD_PATH}/getMBvpdSPDXRecordVersion.mk
include ${CENTAUR_VPD_PATH}/getMBvpdVersion.mk
include ${CENTAUR_VPD_PATH}/getMBvpdVoltageSettingData.mk

VPATH += ${HWP_PATH_1}/hwp/accessors
VPATH += ${ROOTPATH}/src/import/hwpf/fapi2/src/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/initfiles/
VPATH += ${CENTAUR_VPD_PATH}/
VPATH += ${GENPATH}
