# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/fapi2.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/

#Hostboot objects
OBJS += plat_utils.o
OBJS += attribute_service.o
OBJS += plat_attribute_service.o
OBJS += plat_attr_override_sync.o
OBJS += plat_hwp_invoker.o
OBJS += target.o
OBJS += plat_hw_access.o

#EKB Objects (mirrored in src/import)
OBJS += error_info.o
OBJS += ffdc.o

#Generated Objects
OBJS += fapi2_attribute_service.o
OBJS += fapi2_chip_ec_feature.o

#------------------------------------------------------------------------------
# Set fapi2 build environment
#------------------------------------------------------------------------------

# Chip directory
CHIPS += p9

FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p9/procedures/xml/error_info/*.xml)
FAPI2_ERROR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/error_info/*.xml)

# Attribute XML files.
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/hwpf/fapi2/xml/attribute_info/*.xml)
FAPI2_ATTR_XML += $(wildcard \
  $(ROOTPATH)/src/import/chips/p9/procedures/xml/attribute_info/*.xml)

# Filter out Temp defaults XML file from Attribute XML files.
# NOTE: The hb_temp_defaults.xml file is not a normal attribute file with the
#       normal structures that define the attribute itself.  It temporarily
#       provides default values for new attributes defined in other files.
HB_TEMP_DFLT_XML = $(wildcard \
    ${ROOTPATH}/src/import/hwpf/fapi2/xml/attribute_info/hb_temp_defaults.xml)
FAPI2_ATTR_XML := $(filter-out ${HB_TEMP_DFLT_XML},$(FAPI2_ATTR_XML))

# Chip SCOM address header files.
FAPI2_PLAT_INCLUDE += $(addsuffix /common/include, \
  $(addprefix $(ROOTPATH)/src/import/chips/$CHIPS))

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

VPATH += ${ROOTPATH}/src/import/hwpf/fapi2/src/
VPATH += ${GENPATH}
