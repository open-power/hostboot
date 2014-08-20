# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/mvpd_accessors/compressionTool/makefile $
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
ROOTPATH = ../../../../../..

OUT_FILE += $(ROOTPATH)/obj/modules/compression/compression

GEN_PASS_BODY += compression
CLEAN_TARGETS += $(OUT_FILE) compression.o

INC_DIRS += $(ROOTPATH)/src/include/usr/ecmddatabuffer
INC_DIRS += $(ROOTPATH)/src/include/usr/hwpf/hwp/mvpd_accessors
INC_DIRS += $(ROOTPATH)/src/usr/hwpf/hwp/mvpd_accessors/compressionTool
vpath %.C $(ROOTPATH)/src/usr/ecmddatabuffer

HCFLAGS += -DPRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS=1
HCFLAGS += -DPRDF_COMPRESSBUFFER_UNCOMPRESS_FUNCTIONS=1
HCFLAGS += -lz
HCFLAGS += -Di386=1

include $(ROOTPATH)/config.mk

compression: ecmdDataBufferBase.C DQCompressionLib.C EncodeDQMapping.C
	$(C2) "    CC         $(notdir $@)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 -g $^ -o $(OUT_FILE)\
			$(foreach dir,$(INC_DIRS), -I $(dir)) $(HCFLAGS)
