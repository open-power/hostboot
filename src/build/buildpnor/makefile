# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
#Build PNOR Images for each platform.
#Also builds images which contain the test code.
ROOTPATH = ../../..

##############################################################
#Disabling this as our code size is getting too big for
#fake PNOR.  Only commenting out the bare minimum so it's easy
#to revive should the situation arise where we're forced
#to do so.  This also keeps the 'make clean' path working
#so people aren't stuck with dead files in their img directory.
#
##############################################################

# Default target to 'buildpnor'.  This way you can type make
# in this directory without a target and it will build the
# pnor images.  In the standard case, this makefile is called
# from somewhere else with the buildpnor target as well.
.DEFAULT_GOAL := buildpnor


PNOR_VBU_TARGETS = vbu_MURANO vbu_VENICE

define PNOR_vbu_template
$${IMGDIR}/$(1).pnor: $${IMGDIR}/hbicore_extended.bin $${IMGDIR}/$(1)_targeting.bin
#ifdef HOSTBOOT_PROFILE
#	@echo "  HOSTBOOT_PROFILE enabled."
#	@echo "  Build of vbu.pnor skipped due to space constraints."
#else
#	./buildpnorOld.pl --pnorLayout ./pnorLayoutVpo.xml \
#	    --genToc \
#	    --pnorOutBin $${IMGDIR}/$(1).pnor \
#	    --binFile_part $${IMGDIR}/$(1)_pnor.toc \
#	    --binFile_HBI $${IMGDIR}/hbicore_extended.bin \
#	    --binFile_HBD $${IMGDIR}/$(1)_targeting.bin
#endif
endef

PNOR_VBU_IMAGES =  $(addsuffix .pnor, $(addprefix $(IMGDIR)/, ${PNOR_VBU_TARGETS})) \

CLEAN_TARGETS += ${PNOR_VBU_IMAGES}
CLEAN_TARGETS += ${PNOR_VBU_IMAGES:.pnor=_pnor.toc}

include ${ROOTPATH}/config.mk

.PHONY: buildpnor
buildpnor: ${PNOR_VBU_IMAGES}

#VBU Specific images
$(foreach pnor,$(PNOR_VBU_TARGETS),$(eval $(call PNOR_vbu_template,$(pnor))))
