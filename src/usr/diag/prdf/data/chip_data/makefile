# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/data/chip_data/makefile $
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

# Relative path to root from this makefile
ROOTPATH = ../../../../../..

OBJ_DIR = ${ROOTPATH}/obj/modules/prdf/data

# All of the chip data targets are defined here.
include prdf_chip_data.mk

# Create a list of image targets.
PRD_IMG_PATHS += $(addprefix ${IMGDIR}/, ${prd_chip_data_targets})

# These lines are needed so that Hostboot knows what to build.
CODE_PASS_BODY += ${PRD_IMG_PATHS}
CLEAN_TARGETS  += ${PRD_IMG_PATHS}

# NOTE: All rules defined in this makefile must be done after this line.
#       Otherwise, the default rule 'all' will not be called.
include ${ROOTPATH}/config.mk

# Rule to create the obj directory, if it does not exist.
${OBJ_DIR}:
	$(C1)mkdir -p ${OBJ_DIR}

### IMPORTANT ###
# This template defines rules for each target. However, the build script will
# build all targets defined by the XML in the specified directory. Therefore,
# you should only see the rule called once per directory instead of each target.
define DIR_RULE
$(2): $(wildcard $(1)/*.xml) | $${OBJ_DIR}
	$(C2) "    MAKE       PRD chip data for $(1)"
	$(C1)./build_chip_data_binary -i $(1) -o $$|
endef

CDB_EXP = $(addprefix ${OBJ_DIR}/, ${prd_cd_exp_trgts})
CDB_P10 = $(addprefix ${OBJ_DIR}/, ${prd_cd_p10_trgts})

# Add a line here for each directory containing chip data XML. Make sure to add
# the targets to prdf_chip_data.mk.
$(eval $(call DIR_RULE,explorer,${CDB_EXP}))
$(eval $(call DIR_RULE,p10,     ${CDB_P10}))

$(addprefix ${OBJ_DIR}/, ${prd_cd_combined}): ${CDB_EXP} ${CDB_P10}
	$(C1)./build_table_of_contents -i ${OBJ_DIR} -o ${OBJ_DIR}

# Copy all of the built chip data binaries to the image directory.
${PRD_IMG_PATHS}: ${IMGDIR}/% : ${OBJ_DIR}/%
	$(C1)cp -f $^ $@

