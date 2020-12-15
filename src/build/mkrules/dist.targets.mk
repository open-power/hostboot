# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dist.targets.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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
#    ...release/tools/...
#

# Content targets.
VALID_TARGETS = fsp tools openpower vpo errltool openpower-sim
RELEASE_TARGETS = fsp tools errltool

# TODO RTC: 250794PM: Enable WOFDATA generation for op-build
# Remove wof-tables-img file from being delivered to FSP or OP tars.

#
# Files which are to be directly copied into content targets.
#
# Format is <source file>:<comma separated targets>
#
COPY_FILES = \
    src/build/debug/hb-dump-debug:tools,vpo,openpower,openpower-sim \
    src/build/debug/vpo-debug-framework.pl:vpo \
    src/build/debug/ecmd-debug-framework.pl:openpower,openpower-sim \
    src/build/debug/simics-debug-framework.py:openpower-sim \
    src/build/debug/simics-debug-framework.pl:openpower-sim \
    src/build/tools/eecache_editor.pl:openpower \
    src/build/simics/combined.simics:openpower-sim \
    src/build/simics/startup.simics:openpower-sim \
    src/build/simics/rainier_hb.simics:openpower-sim\
    src/build/simics/morecache.simics:openpower-sim \
    src/build/simics/hb-simdebug.py:openpower-sim \
    src/build/simics/eecache-gen.py:openpower-sim \
    src/build/simics/ecc.py:openpower-sim \
    src/build/debug/eSEL.pl:openpower,openpower-sim \
    src/build/debug/hb-memdump.sh:tools,vpo \
    src/build/debug/ffdcExpander:openpower,tools \
    src/build/tools/genIstepWaitOverride.pl:tools,openpower,openpower-sim \
    src/build/vpo/hb-dump:vpo \
    src/build/vpo/hb-istep:vpo \
    src/build/vpo/hb-virtdebug.pl:vpo \
    src/build/vpo/VBU_Cacheline.pm:vpo \
    src/build/simics/hb-pnor-vpd-preload.pl:vpo \
    src/build/buildpnor/pnorLayoutFake.xml:vpo \
    img/errlparser:tools,vpo,openpower,openpower-sim \
    img/hbotStringFile:tools,vpo,openpower,openpower-sim \
    img/isteplist.csv:tools,vpo,openpower,openpower-sim \
    obj/genfiles/attrInfo.csv:vpo,openpower,openpower-sim \
    obj/genfiles/attrEnumInfo.csv:vpo \
    obj/genfiles/targAttrInfo.csv:vpo \
    obj/genfiles/fapiattrs.xml:openpower,openpower-sim \
    obj/genfiles/config.h:openpower,openpower-sim \
    obj/genfiles/attribute_types_full.xml:openpower,openpower-sim \
    obj/genfiles/target_types_full.xml:openpower,openpower-sim \
    src/usr/targeting/attroverride/README.attr_override:tools,openpower,openpower-sim \
    src/build/hwpf/prcd_compile.tcl:tools \
    src/build/buildpnor/buildSbePart.pl:openpower,openpower-sim \
    src/build/buildpnor/buildpnor.pl:openpower,openpower-sim \
    src/build/buildpnor/genfakeheader.pl:openpower,openpower-sim \
    src/build/buildpnor/genPnorImages.pl:openpower,openpower-sim \
    src/build/buildpnor/buildUcdFlashImages.pl:openpower,openpower-sim \
    src/build/buildpnor/PnorUtils.pm:openpower,openpower-sim \
    src/build/buildpnor/imprintHwKeyHash:openpower,openpower-sim \
    src/build/buildpnor/wof-tables-img:openpower,openpower-sim \
    src/import/tools/wof/wof_data_xlator.pl:openpower,openpower-sim \
    src/build/buildpnor/memd_creation.pl:openpower,openpower-sim \
    src/build/buildpnor/pkgOcmbFw.pl:openpower,openpower-sim \
    src/usr/targeting/common/processMrw.pl:openpower,openpower-sim \
    src/usr/targeting/common/Targets.pm:openpower,openpower-sim \
    src/usr/targeting/common/genHDATstructures.pl:openpower,openpower-sim \
    src/usr/hdat/genHdatBin.pl:openpower,openpower-sim \
    src/usr/targeting/common/filter_out_unwanted_attributes.pl:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/mergexml.sh:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/attribute_types.xml:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/attribute_types_hb.xml:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/target_types_hb.xml:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/simics_P10.system.xml:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/vbu_P10.system.xml:vpo \
    src/usr/targeting/common/xmltohb/xmltohb.pl:openpower,openpower-sim \
    src/usr/hdat/hdatBinLayout.xml:openpower,openpower-sim \
    src/usr/targeting/xmltohb/updatetempsxml.pl:openpower,openpower-sim \
    src/include/usr/vmmconst.h:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/bios.xsd:openpower,openpower-sim \
    src/usr/targeting/common/xmltohb/bios_metadata_petitboot.xslt:openpower,openpower-sim \
    $(foreach file, $(call ROOTPATH_WILDCARD,releaseNotes.html), $(file):fsp)\

ifeq ($(call try-cflag,$(CCACHE) $(HOST_PREFIX)g++,-std=gnu++11),-std=gnu++11)
COPY_FILES += obj/genfiles/attributeOverride:tools,openpower,openpower-sim
else
COPY_FILES += obj/genfiles/attributeOverride:tools
endif

include ${ROOTPATH}/config.mk
COPY_FILES += $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),src/usr/targeting/common/xmltohb/target_types_oppowervm.xml:openpower,openpower-sim) \
    $(if $(CONFIG_INCLUDE_XML_OPPOWERVM),src/usr/targeting/common/xmltohb/attribute_types_oppowervm.xml:openpower,openpower-sim) \
    $(if $(CONFIG_INCLUDE_XML_OPENPOWER),src/usr/targeting/common/xmltohb/target_types_openpower.xml:openpower,openpower-sim) \
    $(if $(CONFIG_INCLUDE_XML_OPENPOWER),src/usr/targeting/common/xmltohb/attribute_types_openpower.xml:openpower,openpower-sim) \

#
# Files which are copied and renamed for targets.
#
# Format is <dest file>:<source file>:<comma separated targets>
#
COPY_RENAME_FILES = \
    attribute_types.xml:obj/genfiles/attribute_types_full.xml:openpower,openpower-sim \
    target_types_merged.xml:obj/genfiles/target_types_full.xml:openpower,openpower-sim \
    attribute_types_hb.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    target_types_hb.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    attribute_types_oppowervm.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    target_types_oppowervm.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    attribute_types_openpower.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    target_types_openpower.xml:src/usr/targeting/common/xmltohb/target_types_empty.xml:openpower,openpower-sim \
    makefile:src/build/mkrules/hbfw/makefile:fsp \
    img/makefile:src/build/mkrules/hbfw/img/makefile:fsp \
    hbicore.bin:img/hbicore$(UNDERSCORE_TEST).bin:vpo \
    img/hostboot_bootloader.bin:img/hbibl.bin:fsp,openpower,openpower-sim,vpo \
    img/hostboot_securerom.bin:img/securerom.bin:fsp,openpower,openpower-sim,vpo \
    img/hostboot.bin:img/hbicore$(UNDERSCORE_TEST).bin:fsp,openpower,openpower-sim \
    img/hostboot_extended.bin:img/hbicore$(UNDERSCORE_TEST)_extended.bin:fsp,openpower,openpower-sim \
    img/hostboot_runtime.bin:img/hbirt$(UNDERSCORE_TEST).bin:fsp,openpower,openpower-sim \
    hbicore.syms:img/hbicore$(UNDERSCORE_TEST).syms:tools,vpo,openpower,openpower-sim \
    hbicore.list.bz2:img/hbicore$(UNDERSCORE_TEST).list.bz2:tools,vpo,openpower,openpower-sim \
    hbicore.bin.modinfo:img/hbicore$(UNDERSCORE_TEST).bin.modinfo:tools,vpo,openpower,openpower-sim \
    hbirt.syms:img/hbicore$(UNDERSCORE_TEST).syms:tools,vpo,openpower,openpower-sim \
    hbirt.list.bz2:img/hbirt$(UNDERSCORE_TEST).list.bz2:tools,vpo,openpower,openpower-sim \
    hbirt.bin.modinfo:img/hbirt$(UNDERSCORE_TEST).bin.modinfo:tools,vpo,openpower,openpower-sim \
    hbibl.syms:img/hbibl.syms:tools,vpo,openpower,openpower-sim \
    hbibl.list.bz2:img/hbibl.list.bz2:tools,vpo,openpower,openpower-sim \
    hbibl.bin.modinfo:img/hbibl.bin.modinfo:tools,vpo,openpower,openpower-sim \
    securerom.syms:img/securerom.syms:tools,vpo,openpower,openpower-sim \
    securerom.list.bz2:img/securerom.list.bz2:tools,vpo,openpower,openpower-sim \
    securerom.bin.modinfo:img/securerom.bin.modinfo:tools,vpo,openpower,openpower-sim \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm), \
    Hostboot/$(notdir $(file)):$(file):tools,vpo,openpower,openpower-sim) \
    $(foreach file, $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    hbplugins/Makefile:obj/genfiles/plugins/Makefile:errltool \
    hbplugins/prdf/Makefile:obj/genfiles/plugins/prdf/Makefile_errl:errltool \
    $(foreach file, $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/prdf/*.h), \
    hbplugins/prdf/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/prdf/*.C), \
    hbplugins/prdf/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/prdf/*.H), \
    hbplugins/prdf/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/sbeio/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/initservice/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/mbox/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/secureboot/common/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/errl/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/fsi/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/vpd/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/i2c/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/runtime/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/isteps/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/usr/scom/plugins/*.*), \
    hbplugins/$(notdir $(file)):$(file):errltool) \
    hwas/common/hwasCallout.H:src/include/usr/hwas/common/hwasCallout.H:errltool \
    devicefw/driverif.H:src/include/usr/devicefw/driverif.H:errltool \
    devicefw/userif.H:src/include/usr/devicefw/userif.H:errltool

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
    src/build/simics/morecache.simics \
    src/build/simics/startup.simics \
    src/build/simics/standalone.simics \
    src/build/simics/combined.simics \
    src/build/simics/run_as_vpo.simics \
    src/build/simics/fake_mem.simics \
    src/build/simics/ipmi_bt_responder.py \
    src/build/simics/hb-simdebug.py \
    src/build/debug/hb-dump-debug \
    src/build/debug/ecmd-debug-framework.pl \
    src/build/debug/simics-debug-framework.py \
    src/build/debug/simics-debug-framework.pl \
    src/build/simics/validate-hb-nfs-dir.py \
    src/build/simics/fsp_autoboot.simics \
    src/build/simics/denali_hb.simics \
    src/build/simics/rainier_hb.simics \
    src/build/simics/eecache-gen.py \
    src/build/simics/ecc.py \
    $(addsuffix :Hostboot/, \
	$(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm)) \
    img/hbicore$(UNDERSCORE_TEST).syms \
    img/hbicore$(UNDERSCORE_TEST).list.bz2 \
    img/hbicore$(UNDERSCORE_TEST).bin.modinfo \
    img/hbirt$(UNDERSCORE_TEST).syms \
    img/hbirt$(UNDERSCORE_TEST).list.bz2 \
    img/hbirt$(UNDERSCORE_TEST).bin.modinfo \
    img/hbibl.syms \
    img/hbibl.list.bz2 \
    img/hbibl.bin.modinfo \
    img/securerom.syms \
    img/securerom.list.bz2 \
    img/securerom.bin.modinfo \
    img/errlparser \
    img/isteplist.csv \
    img/hbotStringFile \
    src/build/simics/hb-pnor-vpd-preload.py \
    src/build/simics/hb-pnor-vpd-preload.pl \
    obj/genfiles/attrInfo.csv \
    obj/genfiles/attrEnumInfo.csv \
    obj/genfiles/targAttrInfo.csv

#
# Contents for the fsp.tar.
#
# Common code delivered to FSP builds.
#
fsp.tar_CONTENTS = \
    obj/genfiles/hwp_id.html \
    src/build/mkrules/hbfw/fsp/makefile \
    src/build/tools/eecache_editor.pl \
    src/build/buildpnor/wof-tables-img \
    src/import/tools/wof/wof_data_xlator.pl \
    src/build/buildpnor/memd_creation.pl \
    src/build/buildpnor/buildSbePart.pl \
    src/build/buildpnor/buildpnor.pl \
    src/build/buildpnor/genfakeheader.pl \
    src/build/buildpnor/genPnorImages.pl \
    src/build/buildpnor/buildUcdFlashImages.pl \
    src/build/buildpnor/buildBpmFlashImages.pl \
    src/build/buildpnor/PnorUtils.pm \
    src/build/buildpnor/imprintHwKeyHash \
    src/build/buildpnor/pkgOcmbFw.pl \
    src/build/buildpnor/defaultPnorLayout.xml \
    src/build/buildpnor/pnorLayoutFSP.xml \
    src/build/buildpnor/pnorLayoutP10.xml \
    $(if $(FAKEPNOR), src/build/buildpnor/pnorLayoutFake.xml, ) \
    obj/genfiles/config.h \
    obj/genfiles/fapiattrs.xml \
    obj/genfiles/attribute_types_sp.xml \
    obj/genfiles/target_types_sp.xml \
    obj/genfiles/hb_plat_attr_srvc.H \
    src/import/hwpf/fapi2/xml/attribute_info/hb_temp_defaults.xml \
    $(addsuffix :targeting/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/targeting/common))\
    $(addsuffix :targeting/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/include/usr/targeting/common)) \
    $(addsuffix :targeting/,\
	$(call ROOTPATH_WILDCARD,src/usr/targeting/xmltohb/updatetempsxml.pl))\
    $(addsuffix :hwas/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/hwas/common))\
    $(addsuffix :hwas/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/include/usr/hwas/common)) \
    $(addsuffix :pnor/,\
	$(call ROOTPATH_WILDCARD_RECURSIVE,src/usr/pnor/common)) \
    src/include/kernel/hbdescriptor.H \
    src/include/kernel/hbterminatetypes.H \
    src/build/tools/hwp_id.pl \
    src/build/tools/genIstepWaitOverride.pl \
    src/build/tools/editimgid \
    obj/genfiles/plugins/makefile:plugins/ \
    obj/genfiles/plugins/hbfwUdIds.H:plugins/ \
    src/include/usr/hbotcompid.H \
    src/include/usr/hwas/common/hwasCallout.H:hwas/ \
    src/include/usr/devicefw/driverif.H:devicefw/ \
    src/include/usr/devicefw/userif.H:devicefw/ \
    obj/genfiles/plugins/errludattributeP_gen.H:plugins/ \
    src/usr/errl/plugins/errludattributeP.H:plugins/ \
    obj/genfiles/plugins/errludtarget.H:plugins/ \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/hbfwSrcParse*.C)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,obj/genfiles/plugins/prdf/*)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,src/usr/*/plugins/*)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,src/usr/secureboot/common/plugins/*)) \
    $(addsuffix :plugins/,\
        $(call ROOTPATH_WILDCARD,src/usr/isteps/nvdimm/plugins/*)) \
    src/build/debug/hb-memdump.sh:src/build/debug/ \
    src/build/debug/ffdcExpander:src/build/debug/ \
    obj/genfiles/hbfw_term_rc.H \
    obj/genfiles/srcListing \
    obj/genfiles/attrInfo.csv \
    obj/genfiles/attrEnumInfo.csv \
    obj/genfiles/targAttrInfo.csv\
    obj/genfiles/plugins/hbfwPlatHwpErrParser.H:plugins/ \
    obj/genfiles/plugins/hbfwPlatHwpErrParserFFDC.H:plugins \
    src/include/runtime/generic_hbrt_fsp_message.H \
    obj/genfiles/fapi2AttrOverrideEnums.H \
    obj/genfiles/fapi2AttrOverrideData.H \
    src/usr/pnor/ecc.C \
    src/include/usr/pnor/ecc.H:pnor/ \
    src/import/hwpf/fapi2/include/target_types.H \
    src/include/usr/fapi2/plat_target_filter.H \
    src/usr/targeting/attroverride/attrTextToBinaryBlob.C \
    src/usr/targeting/attroverride/attrTextToBinaryBlob.H \
    src/include/usr/sbe/sbe_common.H \
    src/include/util/memoize.H


include dist.rules.mk
