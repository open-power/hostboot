# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/images.rules.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
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

# File: images.rules.mk
# Description:
#     Rules for linking the Hostboot binary images using the custom linker.

ifdef IMGS
_IMGS = $(addprefix $(IMGDIR)/, $(IMGS))
IMAGES += $(addsuffix .bin, $(_IMGS)) $(addsuffix .elf, $(_IMGS))

IMAGE_PASS_BODY += $(addsuffix .list, $(_IMGS)) $(addsuffix .syms, $(_IMGS))
CLEAN_TARGETS += $(addsuffix .list, $(_IMGS)) $(addsuffix .syms, $(_IMGS))

define ELF_template
$$(IMGDIR)/$(1).elf: $$(addprefix $$(OBJDIR)/, $$($(1)_OBJECTS)) \
                     $$(ROOTPATH)/src/kernel.ld
	$$(C2) "    LD         $$(notdir $$@)"
	$$(C1)$$(LD) -static $$(LDFLAGS) \
                     $$(addprefix $$(OBJDIR)/, $$($(1)_OBJECTS)) \
                     $$($(1)_LDFLAGS) -T $$(ROOTPATH)/src/kernel.ld -o $$@
endef
$(foreach img,$(IMGS),$(eval $(call ELF_template,$(img))))

$(IMGDIR)/%.bin: $(IMGDIR)/%.elf \
    $(wildcard $(IMGDIR)/*.so) $(addprefix $(IMGDIR)/, $($*_DATA_MODULES)) \
    $(CUSTOM_LINKER_EXE)
	$(C2) "    LINKER     $(notdir $@)"
	$(C1)$(CUSTOM_LINKER) $@ $< \
              $(addprefix $(IMGDIR)/lib, $(addsuffix .so, $($*_MODULES))) \
                  --extended=0x40000 $(IMGDIR)/$*_extended.bin \
              $(addprefix $(IMGDIR)/lib, $(addsuffix .so, $($*_EXTENDED_MODULES))) \
              $(addprefix $(IMGDIR)/, $($*_DATA_MODULES)) \
              > $(IMGDIR)/.$*.lnkout
	$(C1)$(ROOTPATH)/src/build/tools/addimgid $@ $<

$(IMGDIR)/%.list $(IMGDIR)/%.syms: $(IMGDIR)/%.bin
	$(C2) "    GENLIST    $(notdir $*)"
	$(C1)(cd $(ROOTPATH); \
              src/build/tools/gensyms $*.bin $*_extended.bin 0x40000000 \
                  > ./img/$*.syms ; \
              src/build/tools/genlist $*.bin > ./img/$*.list)

endif
