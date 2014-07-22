# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/images.rules.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2014
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

# File: images.rules.mk
# Description:
#     Rules for linking the Hostboot binary images using the custom linker.

ifdef IMGS
_IMGS = $(addprefix $(IMGDIR)/, $(IMGS))
IMAGES += $(addsuffix .bin, $(_IMGS)) $(addsuffix .elf, $(_IMGS))

IMAGE_PASS_POST += $(addsuffix .list.bz2, $(_IMGS)) $(addsuffix .syms, $(_IMGS))
CLEAN_TARGETS += $(addsuffix .list.bz2, $(_IMGS)) $(addsuffix .syms, $(_IMGS))
CLEAN_TARGETS += $(addsuffix .lnkout.bz2, $(addprefix $(IMGDIR)/., $(IMGS)))

define ELF_template
$$(IMGDIR)/$(1).elf: $$(addprefix $$(OBJDIR)/, $$($(1)_OBJECTS)) \
                     $$(ROOTPATH)/src/kernel.ld
	$$(C2) "    LD         $$(notdir $$@)"
	$$(C1)$$(LD) -static $$(LDFLAGS) $$($$*_LDFLAGS) \
                     $$(addprefix $$(OBJDIR)/, $$($(1)_OBJECTS)) \
                     $$($(1)_LDFLAGS) -T $$(ROOTPATH)/src/kernel.ld -o $$@
endef
$(foreach img,$(IMGS),$(eval $(call ELF_template,$(img))))

$(IMGDIR)/%.bin: $(IMGDIR)/%.elf \
    $(wildcard $(IMGDIR)/*.so) $(addprefix $(IMGDIR)/, $($*_DATA_MODULES)) \
    $(CUSTOM_LINKER_EXE)
	$(C2) "    LINKER     $(notdir $@)"
	$(eval TMPFILE = $(shell mktemp))
	$(C1)$(CUSTOM_LINKER) $@ $< \
              $(addprefix $(IMGDIR)/lib, $(addsuffix .so, $($*_MODULES))) \
	      $(if $($*_EXTENDED_MODULES), \
                  --extended=0x40000 $(IMGDIR)/$*_extended.bin \
                  $(addprefix $(IMGDIR)/lib, \
	              $(addsuffix .so, $($*_EXTENDED_MODULES))) \
	      ) \
              $(addprefix $(IMGDIR)/, $($*_DATA_MODULES)) > $(TMPFILE) && \
              bzip2 -zc > $(IMGDIR)/.$*.lnkout.bz2 < $(TMPFILE)
	rm $(TMPFILE)
	$(C1)$(ROOTPATH)/src/build/tools/addimgid $@ $<

$(IMGDIR)/%.list.bz2 $(IMGDIR)/%.syms: $(IMGDIR)/%.bin
	$(C2) "    GENLIST    $(notdir $*)"
	$(C1)(cd $(ROOTPATH)&& \
              src/build/linker/gensyms $*.bin \
		  $(if $($*_EXTENDED_MODULES), $*_extended.bin 0x40000000) \
                  > ./img/$*.syms && \
              src/build/linker/genlist $*.bin | bzip2 -zc > ./img/$*.list.bz2)

endif
