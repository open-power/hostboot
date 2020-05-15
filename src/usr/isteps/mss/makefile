# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/mss/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2020
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
ROOTPATH = ../../../..

IMPORT_PATH              = ${ROOTPATH}/src/import
PROCEDURES_PATH          = ${IMPORT_PATH}/chips/p10/procedures
EXPLORER_PROCEDURES_PATH = ${IMPORT_PATH}/chips/ocmb/explorer/procedures

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${IMPORT_PATH}/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/

MSS_LIB += ${PROCEDURES_PATH}/hwp/memory
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/plug_rules/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/ccs/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/ecc/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/eff_config/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/omi/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/fir/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/freq/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/plug_rules/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/mc/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/mcbist/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/phy/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/power_thermal/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/spd/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/utils/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/workarounds/
MSS_LIB += ${PROCEDURES_PATH}/hwp/memory/lib/rosetta_map/
MSS_LIB += ${ROOTPATH}/src/import/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/lrdimm/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/rdimm/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/common/ddr4/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/spd/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/ccs/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/ecc/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/utils/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/utils/shared/
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/utils/freq
MSS_LIB += ${ROOTPATH}/src/import/generic/memory/lib/utils/mcbist/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/dimm/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/dimm/ddr4/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/shared
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/ccs/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/mc/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/eff_config/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/utils/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/freq/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/power_thermal/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/omi/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/i2c/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/fir/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/mcbist/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/plug_rules/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/phy/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/ecc/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/inband/
MSS_LIB += ${EXPLORER_PROCEDURES_PATH}/hwp/memory/lib/workarounds/

EXTRAINCDIR += ${MSS_LIB}

include ${ROOTPATH}/src/build/mkrules/script.rules.mk
include ${ROOTPATH}/src/build/mkrules/verbose.rules.mk

# Generate generic_system_accessors header file
MSS_GENERIC_PATH := $(IMPORT_PATH)/generic/memory/lib
MSS_GENERIC_INCLUDES := $(shell find $(MSS_GENERIC_PATH) -type d)

GENERATED = generic_system_accessors
COMMAND = gen_accessors.pl
$(GENERATED)_COMMAND_PATH = $(IMPORT_PATH)/generic/memory/tools/

OUTPATH = ${ROOTPATH}/obj/genfiles/generic/memory/lib/
FILE_PREFIX = mss_generic_system

SOURCES += $(IMPORT_PATH)/hwpf/fapi2/xml/attribute_info/system_attributes.xml
SOURCES += $(IMPORT_PATH)/generic/procedures/xml/attribute_info/generic_memory_mrw_attributes.xml
SOURCES += $(IMPORT_PATH)/chips/p10/procedures/xml/attribute_info/p10_freq_attributes.xml

CLEAN_TARGETS += ${OUTPATH}/mss_generic_system_attribute_getters.H
CLEAN_TARGETS += ${OUTPATH}/.generic_system_accessors.built

define generic_system_accessors_RUN
		$(C1) mkdir $(OUTPATH) -p
		$(C1) $$< --system=P10 --output-dir=$(OUTPATH) --output-file-prefix=$(FILE_PREFIX) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

# Generate generic_memory_accessors header file
GENERATED = generic_accessors
COMMAND = gen_accessors.pl
$(GENERATED)_COMMAND_PATH = $(IMPORT_PATH)/generic/memory/tools/

OUTPATH = ${ROOTPATH}/obj/genfiles/generic/memory/lib
FILE_PREFIX = mss_generic

SOURCES += $(IMPORT_PATH)/generic/procedures/xml/attribute_info/generic_memory_attributes.xml
SOURCES += $(IMPORT_PATH)/generic/procedures/xml/attribute_info/generic_dq_attributes.xml
SOURCES += $(IMPORT_PATH)/generic/procedures/xml/attribute_info/generic_memory_eff_attributes.xml
SOURCES += $(IMPORT_PATH)/generic/procedures/xml/attribute_info/generic_memory_si_attributes.xml

CLEAN_TARGETS += ${OUTPATH}/mss_generic_attribute_getters.H
CLEAN_TARGETS += ${OUTPATH}/mss_generic_attribute_setters.H
CLEAN_TARGETS += ${OUTPATH}/.generic_accessors.built

define generic_accessors_RUN
		$(C1) mkdir $(OUTPATH) -p
		$(C1) $$< --system=P10 --output-dir=$(OUTPATH) --output-file-prefix=$(FILE_PREFIX) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

# Generate explorer_memory_accessors header file
GENERATED = gen_exp_accessors
COMMAND = gen_accessors.pl
$(GENERATED)_COMMAND_PATH = $(IMPORT_PATH)/generic/memory/tools/

OUTPATH = ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
FILE_PREFIX = mss_explorer

SOURCES += $(shell find $(IMPORT_PATH)/chips/ocmb/explorer/procedures/xml/attribute_info/ -type f)

CLEAN_TARGETS += ${OUTPATH}/mss_explorer_attribute_getters.H
CLEAN_TARGETS += ${OUTPATH}/mss_explorer_attribute_setters.H
CLEAN_TARGETS += ${OUTPATH}/.gen_exp_accessors.built

define gen_exp_accessors_RUN
		$(C1) mkdir $(OUTPATH) -p
		$(C1) $$< --system=P10 --output-dir=$(OUTPATH) --output-file-prefix=$(FILE_PREFIX) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

GENERATED = gen_p10_accessors
COMMAND= gen_accessors.pl
$(GENERATED)_COMMAND_PATH = $(IMPORT_PATH)/generic/memory/tools/

OUTPATH = ${ROOTPATH}/obj/genfiles/chips/p10/procedures/hwp/memory/lib/
FILE_PREFIX = mss_p10

SOURCES += $(ROOTPATH)/chips/p10/procedures/xml/attribute_info/p10_io_attributes.xml
SOURCES += $(ROOTPATH)/chips/p10/procedures/xml/attribute_info/p10_omi_setup_bars.xml
SOURCES += $(ROOTPATH)/chips/p10/procedures/xml/attribute_info/p10_omi_init.xml

CLEAN_TARGETS += ${OUTPATH}/mss_p10_attribute_getters.H
CLEAN_TARGETS += ${OUTPATH}/mss_p10_attribute_setters.H
CLEAN_TARGETS += ${OUTPATH}/.gen_p10_accessors.built

define gen_p10_accessors_RUN
		$(C1) mkdir $(OUTPATH) -p
		$(C1) $$< --system=P10 --output-dir=$(OUTPATH) --output-file-prefix=$(FILE_PREFIX) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)


## Generate pmic_accessors header file
#GENERATED = gen_pmic_accessors
#COMMAND = gen_accessors.pl
#$(GENERATED)_COMMAND_PATH = $(IMPORT_PATH)/generic/memory/tools/
#
#OUTPATH = ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib/
#FILE_PREFIX = mss_pmic
#
#SOURCES += $(ROOTPATH)/chips/ocmb/common/procedures/xml/attribute_info/pmic_eff_attributes.xml
#
#CLEAN_TARGETS += ${OUTPATH}/mss_pmic_attribute_getters.H
#CLEAN_TARGETS += ${OUTPATH}/mss_pmic_attribute_setters.H
#CLEAN_TARGETS += ${OUTPATH}/.gen_pmic_accessors.built
#
#define gen_pmic_accessors_RUN
#		$(C1) mkdir $(OUTPATH) -p
#		$(C1) $$< --system=AXONE --output-dir=$(OUTPATH) --output-file-prefix=$(FILE_PREFIX) $$(filter-out $$<,$$^)
#endef
#
#$(call BUILD_GENERATED)


# Add common and generated parts to object list.

MSS_PATH := $(PROCEDURES_PATH)/hwp/memory/lib
MSS_SOURCE := $(shell find $(MSS_PATH) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_SOURCE))

MSS_PATH_GENERIC_MEMORY := ${ROOTPATH}/src/import/generic/memory/lib
MSS_GENERIC_MEMORY_SOURCE := $(shell find $(MSS_PATH_GENERIC_MEMORY) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_GENERIC_MEMORY_SOURCE))

MSS_PATH_EXPLORER := $(EXPLORER_PROCEDURES_PATH)/hwp/memory/lib
MSS_EXPLORER_SOURCE := $(shell find $(MSS_PATH_EXPLORER) -name '*.C' -exec basename {} \;)
MSS_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_EXPLORER_SOURCE))

MODULE = isteps_mss

OBJS += $(MSS_MODULE_OBJS)
$(call BUILD_MODULE)

VPATH += ${MSS_LIB}

SUBDIRS += runtime

#HWP build tool
include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk
