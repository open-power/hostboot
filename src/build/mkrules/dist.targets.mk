# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dist.targets.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2015
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

ROOTPATH = ../../..

#
# Makefile rules defining the Hostboot content delivery to various external
# entities.  Typically we release to 'fsp', 'vpo' and a full release.
#
# The fsp target is used for Simics testing and for delivering code and tools.
# The vpo target is used for VPO testing.
# The tools target is for offline debug (ex. hb-dump-debug) and misc tools.
#
# The release is created by generating all targets into their subdirectory:
#    ...release/fsp/...
#    ...release/vpo/...
#    ...reelase/tools/...
#

# Content targets.
VALID_TARGETS = fsp tools openpower

#
# Files which are to be directly copied into content targets.
#
# Format is <source file>:<comma separated targets>
#
COPY_FILES = \
    src/build/debug/hb-dump-debug:tools,vpo,openpower \
    src/build/debug/vpo-debug-framework.pl:vpo \
    src/build/debug/ecmd-debug-framework.pl:openpower \
    src/build/debug/fsp-memdump.sh:tools,vpo \
    src/build/vpo/hb-dump:vpo \
    src/build/vpo/hb-istep:vpo \
    src/build/vpo/hb-virtdebug.pl:vpo \
    src/build/vpo/VBU_Cacheline.pm:vpo \
    src/build/simics/hb-pnor-vpd-preload.pl:vpo \
    src/build/buildpnor/pnorLayoutVpo.xml:vpo \
    img/errlparser:tools,vpo,openpower \
    img/hbotStringFile:tools,vpo,openpower \
    img/isteplist.csv:tools,vpo,openpower \
    img/dimmspd.dat:vpo \
    img/procmvpd.dat:vpo \
    img/cvpd.dat:vpo \
    obj/genfiles/fapiAttrInfo.csv:vpo \
    obj/genfiles/fapiAttrEnumInfo.csv:vpo \
    obj/genfiles/targAttrInfo.csv:vpo \
    obj/genfiles/target_types_merged.xml:openpower \
    obj/genfiles/fapiattrs.xml:openpower \
    obj/genfiles/attributeOverride:tools,openpower \
    src/build/hwpf/prcd_compile.tcl:tools \
    src/usr/hwpf/hwp/initfiles/sample.initfile:tools \
    src/build/buildpnor/buildSbePart.pl:openpower \
    src/build/buildpnor/buildpnor.pl:openpower \
    src/usr/targeting/common/genHwsvMrwXml.pl:openpower \
    src/usr/targeting/common/xmltohb/mergexml.sh:openpower \
    src/usr/targeting/common/xmltohb/attribute_types.xml:openpower \
    src/usr/targeting/common/xmltohb/attribute_types_hb.xml:openpower \
    src/usr/targeting/common/xmltohb/target_types_hb.xml:openpower \
    src/usr/targeting/common/xmltohb/xmltohb.pl:openpower \
    src/include/usr/vmmconst.h:openpower \
    src/usr/targeting/common/xmltohb/bios.xsd:openpower \
    src/usr/targeting/common/xmltohb/bios_metadata_petitboot.xslt:openpower \
    $(foreach file, $(call ROOTPATH_WILDCARD,releaseNotes.html), $(file):fsp)\

#
# Files which are copied and renamed for targets.
#
# Format is <dest file>:<source file>:<comma separated targets>
#
COPY_RENAME_FILES = \
    makefile:src/build/mkrules/hbfw/makefile:fsp\
    img/makefile:src/build/mkrules/hbfw/img/makefile:fsp \
    hbicore.bin:img/hbicore$(UNDERSCORE_TEST).bin:vpo \
    img/hostboot.bin:img/hbicore$(UNDERSCORE_TEST).bin:fsp,openpower \
    img/hostboot_extended.bin:img/hbicore$(UNDERSCORE_TEST)_extended.bin:fsp,openpower \
    img/hostboot_runtime.bin:img/hbirt$(UNDERSCORE_TEST).bin:fsp,openpower \
    vbu_MURANO.pnor:img/vbu$(UNDERSCORE_TEST)_MURANO.pnor:vpo \
    vbu_VENICE.pnor:img/vbu$(UNDERSCORE_TEST)_VENICE.pnor:vpo \
    vbu_NAPLES.pnor:img/vbu$(UNDERSCORE_TEST)_NAPLES.pnor:vpo \
    hbicore.syms:img/hbicore$(UNDERSCORE_TEST).syms:tools,vpo,openpower \
    hbicore.list.bz2:img/hbicore$(UNDERSCORE_TEST).list.bz2:tools,vpo,openpower \
    hbicore.bin.modinfo:img/hbicore$(UNDERSCORE_TEST).bin.modinfo:tools,vpo,openpower \
    hbirt.syms:img/hbicore$(UNDERSCORE_TEST).syms:tools,vpo,openpower \
    hbirt.list.bz2:img/hbirt$(UNDERSCORE_TEST).list.bz2:tools,vpo,openpower \
    hbirt.bin.modinfo:img/hbirt$(UNDERSCORE_TEST).bin.modinfo:tools,vpo,openpower \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm), \
	Hostboot/$(notdir $(file)):$(file):tools,vpo,openpower)

#
# Symbolic links created in the target.
#
# Format is <dest link>:<source file>:<comma separated targets>
#
# Example:
#    Each debug framework module is symbolically linked against the
#    vpo-debug-framework.pl executable in the VPO target as 'hb-Tool'
#
#    hb-Printk:vpo-debug-framework.pl:vpo
#
LINK_FILES = \
    $(foreach file,\
	$(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/[^_]*.pm), \
	hb-$(basename $(notdir $(file))):vpo-debug-framework.pl:vpo)

#
# TAR files to create for each target.
#
# Format is <tar file>:<comma separated targets>
#
# The content for each tar file is in <tarfile>_CONTENTS.
#
# The format in the <tarfile>_CONTENTS variables is:
#     <file>[:<kept root of path>]
#
# Examples:
#     src/hbfw/simics/makefile on FSP is created from
#     src/build/mkrules/hbfw/simics/makefile on Hostboot and is added to the
#     root of the simics.tar file.
#         simics.tar_CONTENTS += src/build/mkrules/hbfw/simics/makefile
#
#     src/hbfw/fsp/targeting/common/target.C on FSP is created from
#     src/usr/targeting/common/target.C on Hostboot and is added to the
#     fsp.tar at targeting/common.
#         fsp.tar_CONTENTS += src/usr/targeting/common/target.C:targeting/
#
TAR_FILES = \
    simics.tar:fsp \
    fsp.tar:fsp

#
# Contents for the simics.tar.
#
# Tools for booting and debugging simics.
#
simics.tar_CONTENTS = \
    src/build/mkrules/hbfw/simics/makefile \
    src/build/simics/startup.simics \
    src/build/simics/standalone.simics \
    src/build/simics/combined.simics \
    src/build/simics/ipmi_bt_responder.py \
    src/build/simics/hb-simdebug.py \
    src/build/debug/hb-dump-debug \
    src/build/debug/ecmd-debug-framework.pl \
    src/build/debug/simics-debug-framework.py \
    src/build/debug/simics-debug-framework.pl \
    $(addsuffix :Hostboot/, \
	$(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm)) \
    img/hbicore$(UNDERSCORE_TEST).syms \
    img/hbicore$(UNDERSCORE_TEST).list.bz2 \
    img/hbicore$(UNDERSCORE_TEST).bin.modinfo \
    img/hbirt$(UNDERSCORE_TEST).syms \
    img/hbirt$(UNDERSCORE_TEST).list.bz2 \
    img/hbirt$(UNDERSCORE_TEST).bin.modinfo \
    img/errlparser \
    img/isteplist.csv \
    img/hbotStringFile \
    src/build/simics/hb-pnor-vpd-preload.py \
    src/build/simics/hb-pnor-vpd-preload.pl \
    img/dimmspd.dat \
    img/procmvpd.dat \
    img/procmvpd_ven.dat \
    img/cvpd.dat \
    obj/genfiles/fapiAttrInfo.csv \
    obj/genfiles/fapiAttrEnumInfo.csv \
    obj/genfiles/targAttrInfo.csv

#
# Contents for the fsp.tar.
#
# Common code delivered to FSP builds.
#
fsp.tar_CONTENTS = \
    obj/genfiles/hwp_id.html \
    src/build/mkrules/hbfw/fsp/makefile \
    src/build/buildpnor/buildSbePart.pl \
    src/build/buildpnor/buildpnor.pl \
    src/build/buildpnor/defaultPnorLayout.xml \
    img/simics_MURANO_targeting.bin \
    img/simics_VENICE_targeting.bin \
    img/simics_NAPLES_targeting.bin \
    obj/genfiles/fapiAttrInfo.csv \
    obj/genfiles/fapiAttrEnumInfo.csv \
    obj/genfiles/targAttrInfo.csv \
    $(addsuffix :targeting/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/targeting/common))\
    $(addsuffix :targeting/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/include/usr/targeting/common)) \
    $(addsuffix :hwas/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/hwas/common))\
    $(addsuffix :hwas/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/include/usr/hwas/common)) \
    $(addsuffix :pnor/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/pnor/common)) \
    src/include/kernel/hbdescriptor.H \
    src/include/kernel/hbterminatetypes.H \
    src/build/tools/hwp_id.pl \
    obj/genfiles/plugins/makefile:plugins/ \
    obj/genfiles/plugins/hbfwUdIds.H:plugins/ \
    src/include/usr/hbotcompid.H \
    src/include/usr/hwas/common/hwasCallout.H:hwas/ \
    src/include/usr/devicefw/driverif.H:devicefw/ \
    src/include/usr/devicefw/userif.H:devicefw/ \
    obj/genfiles/plugins/fapiPlatHwpErrParser.H:plugins/ \
    obj/genfiles/plugins/errludattribute.H:plugins/ \
    obj/genfiles/plugins/errludtarget.H:plugins/ \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/hbfwSrcParse*.C)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/prdf/*)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,src/usr/*/plugins/*)) \
    src/build/debug/fsp-memdump.sh:src/build/debug/ \
    obj/genfiles/hbfw_term_rc.H \
    obj/genfiles/srcListing

#
# Portions of the FSP sandbox which must be rebuilt based on file changes.
#
# Format is <fsp dir>:<mk target>:<context>:<dependency>.
#
# NOTARGET is a special target which indicates to just run 'mk'.
# FORCE_ALWAYS is a special dependency that causes the 'mk' to always be
# executed.
#
# Example:
# 	hbfw:expand_tars:ppc:FORCE_ALWAYS indicates that the src/hbfw
# 	directory should have 'mk expand_tars' executed in the ppc context.
#
fsp_ODE_REMAKES = \
    hbfw:expand_tars:ppc:FORCE_ALWAYS \
    hbfw/img:update_images_for_sandbox:ppc:FORCE_ALWAYS \
    hbfw/simics:NOTARGET:ppc:$(TARGET_DIR)/simics.tar

include dist.rules.mk
