# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/fapi2.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2022
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

HWP_PATH_1   += ${ROOTPATH}/src/import/chips/p10/procedures
HWP_PATH += ${HWP_PATH_1}/


EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/utils/shared/
EXTRAINCDIR += ${HWP_PATH}
EXTRAINCDIR += ${HWP_PATH_1}/hwp/memory/lib/freq
EXTRAINCDIR += ${HWP_PATH_1}/hwp/memory/lib/rosetta_map
EXTRAINCDIR += ${HWP_PATH_1}/hwp/perv
EXTRAINCDIR += ${HWP_PATH_1}/hwp/pm
EXTRAINCDIR += ${HWP_PATH_1}/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/usr/scom/
EXTRAINCDIR += ${ROOTPATH}/src/usr/vpd/
EXTRAINCDIR += ${ROOTPATH}/src/usr/fapi2/test/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/
EXTRAINCDIR += ${HWP_PATH_1}/hwp/accessors/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/eeprom/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/pnor/
EXTRAINCDIR += ${ROOTPATH}/src/import/tools/wof/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/

include ${ROOTPATH}/src/build/mkrules/verbose.rules.mk
define __CLEAN_TARGET
CLEAN_TARGETS += $(1)
endef

#Hostboot objects
OBJS += plat_utils.o
OBJS += attribute_service.o
#OBJS += plat_attribute_service.o
OBJS += plat_attr_override_sync.o
#OBJS += plat_hwp_invoker.o
OBJS += target.o
OBJS += plat_hw_access.o
OBJS += plat_spd_access.o
OBJS += plat_mvpd_access.o
OBJS += plat_vpd_access.o
OBJS += plat_wof_access.o
OBJS += dimmBadDqBitmapFuncs.o
OBJS += rowRepairsFuncs.o
OBJS += plat_i2c_access.o
OBJS += plat_mmio_access.o


#Required include before all the procedure.mk are included
include ${ROOTPATH}/procedure.rules.mk

include ${HWP_PATH_1}/hwp/accessors/ddimm_get_efd.mk

#EKB Objects (mirrored in src/import)
OBJS += error_info.o
OBJS += ffdc.o
OBJS += fapi2_utils.o
OBJS += p10_pm_get_poundv_bucket.o
OBJS += p10_pm_get_poundw_bucket.o
OBJS += p10_pm_get_poundv_bucket_attr.o
OBJS += p10_pm_get_poundw_bucket_attr.o

#Add any object files that are referenced for FFDC functions inside
# error xmls
#OBJS += p9_collect_some_ffdc.o

#Generated Objects
OBJS += fapi2_attribute_service.o
OBJS += collect_reg_ffdc_regs.o

#------------------------------------------------------------------------------
# Set fapi2 build environment
#------------------------------------------------------------------------------

# Chip directory
CHIPS += p10

#FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p9/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/generic/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/ocmb/explorer/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/ocmb/common/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p10/procedures/xml/error_info/*.xml)


# Attribute XML files.
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/generic/procedures/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/ocmb/explorer/procedures/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/ocmb/common/procedures/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p10/procedures/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/usr/targeting/common/xmltohb/deleteme_temp_hb_attrs.xml)


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

# force parseErrorInfo.mk to use the parseErrorInfo_p10.pl script
PROJECT_NAME = p10

include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/src/import/tools/build/common.dir/script.rules.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseErrorInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/parseAttributeInfo.mk
include ${ROOTPATH}/src/import/hwpf/fapi2/tools/createIfAttrService.mk
include $(ROOTPATH)/src/import/chips/p10/procedures/hwp/initfiles/p10_int_scom.mk

VPATH += ${HWP_PATH_1}/hwp/accessors
VPATH += ${ROOTPATH}/src/import/hwpf/fapi2/src/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
VPATH += ${HWP_PATH_1}/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/initfiles/
VPATH += ${GENPATH}
