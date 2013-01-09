# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dist_targets.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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
VALID_TARGETS = fsp vpo tools

#
# Files which are to be directly copied into content targets.
#
# Format is <source file>:<comma separated targets>
#
COPY_FILES = \
    src/build/tools/hb-parsedump.pl:tools,vpo \
    src/build/debug/hb-dump-debug:tools,vpo \
    src/build/debug/vpo-debug-framework.pl:vpo \
    src/build/vpo/hb-dump:vpo \
    src/build/vpo/hb-istep:vpo \
    src/build/vpo/hb-virtdebug.pl:vpo \
    src/build/vpo/VBU_Cacheline.pm:vpo \
    src/build/simics/hb-pnor-vpd-preload.pl:vpo \
    src/build/buildpnor/pnorLayoutVpo.xml:vpo \
    img/errlparser:tools,vpo \
    img/hbotStringFile:tools,vpo \
    img/isteplist.csv:tools,vpo \
    img/dimmspd.dat:vpo \
    img/procmvpd.dat:vpo \
    obj/genfiles/fapiAttributeIds.txt:vpo \
    obj/genfiles/fapiAttributeEnums.txt:vpo \
    src/build/hwpf/prcd_compile.tcl:tools \
    src/usr/hwpf/hwp/initfiles/sample.initfile:tools \
    $(foreach file, $(call ROOTPATH_WILDCARD,releaseNotes.html), $(file):fsp)\

#
# Files which are copied and renamed for targets.
#
# Format is <dest file>:<source file>:<comma separated targets>
#
COPY_RENAME_FILES = \
    makefile:src/build/mkrules/hbfw/makefile:fsp \
    img/makefile:src/build/mkrules/hbfw/img/makefile:fsp \
    hbicore.bin:img/hbicore$(UNDERSCORE_TEST).bin:vpo \
    img/hostboot.bin:img/hbicore$(UNDERSCORE_TEST).bin:fsp \
    img/hostboot_extended.bin:img/hbicore$(UNDERSCORE_TEST)_extended.bin:fsp \
    vbu.pnor:img/vbu$(UNDERSCORE_TEST).pnor:vpo \
    hbicore.syms:img/hbicore$(UNDERSCORE_TEST).syms:tools,vpo \
    hbicore.list:img/hbicore$(UNDERSCORE_TEST).list:tools,vpo \
    hbicore.bin.modinfo:img/hbicore$(UNDERSCORE_TEST).bin.modinfo:tools,vpo \
    $(foreach file, $(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm), \
	Hostboot/$(notdir $(file)):$(file):tools,vpo)

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
    src/build/simics/hb-simdebug.py \
    src/build/debug/simics-debug-framework.py \
    src/build/debug/simics-debug-framework.pl \
    $(addsuffix :Hostboot/, \
	$(call ROOTPATH_WILDCARD,src/build/debug/Hostboot/*.pm)) \
    img/hbicore$(UNDERSCORE_TEST).syms \
    img/hbicore$(UNDERSCORE_TEST).list \
    img/hbicore$(UNDERSCORE_TEST).bin.modinfo \
    img/errlparser \
    img/isteplist.csv \
    img/hbotStringFile \
    src/build/simics/hb-pnor-vpd-preload.py \
    src/build/simics/hb-pnor-vpd-preload.pl \
    img/dimmspd.dat \
    img/procmvpd.dat \
    obj/genfiles/fapiAttributeIds.txt \
    obj/genfiles/fapiAttributeEnums.txt \

#
# Contents for the fsp.tar.
#
# Common code delivered to FSP builds.
#
fsp.tar_CONTENTS = \
    obj/genfiles/hwp_id.html \
    src/build/mkrules/hbfw/fsp/makefile \
    src/build/buildpnor/buildpnor.pl \
    src/build/buildpnor/defaultPnorLayout.xml \
    img/simics_MURANO_targeting.bin \
    img/simics_VENICE_targeting.bin \
    img/TULETA_targeting.bin \
    obj/genfiles/fapiAttributeIds.txt \
    obj/genfiles/fapiAttributeEnums.txt \
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
    src/build/tools/hwp_id.pl

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

include dist_rules.mk
