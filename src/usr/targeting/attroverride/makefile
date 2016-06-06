# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/attroverride/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2016
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

OUT_FILE += $(GENDIR)/attributeOverride
CLEAN_TARGETS += $(OUT_FILE)

CODE_PASS_BODY += $(OUT_FILE)

INC_DIRS += $(ROOTPATH)/src/usr/targeting/
INC_DIRS += $(GENDIR)
INC_DIRS += $(ROOTPATH)/src/include/usr
INC_DIRS += $(ROOTPATH)/src/include/usr/fapi2
INC_DIRS += $(ROOTPATH)/src/import/hwpf/fapi2/include
VPATH += $(ROOTPATH)/src/usr/pnor


C_FILES = attrTextToBinaryBlob.C ecc.C
H_FILES = targAttrOverrideData.H fapi2AttrOverrideData.H\
		  fapi2AttrOverrideEnums.H

include $(ROOTPATH)/config.mk
vpath %.C $(GENDIR)
vpath %.H $(GENDIR)

$(OUT_FILE): $(C_FILES) $(H_FILES)
	$(C2) "    CC         $(notdir $@)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -std=gnu++11 -O3 -g -o $(OUT_FILE)\
			$(foreach dir,$(INC_DIRS), -I $(dir)) -iquote.\
			$(foreach file,$^,$(if $(findstring .H,$(file)),,$(file)))
