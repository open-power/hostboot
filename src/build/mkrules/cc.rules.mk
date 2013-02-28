# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cc.rules.mk $
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

# File: cc.rules.mk
# Description:
#     Rules for compiling C/C++/ASM files.

$(OBJDIR)/%.list : $(OBJDIR)/%.o
	$(C2) "    OBJDUMP    $(notdir $<)"
	$(C1)$(OBJDUMP) -rdlCS $< > $@

$(OBJDIR)/%.o : %.C
	@mkdir -p $(OBJDIR)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(call FLAGS_FILTER, $(CXXFLAGS), $<) $< \
	            -o $@ $(INCFLAGS) -iquote .

# Compiling *.cc files
$(OBJDIR)/%.o : %.cc
	@mkdir -p $(OBJDIR)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(CXXFLAGS) $< -o $@ $(INCFLAGS) -iquote .

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
# Override to use C++ compiler in place of C compiler
# CC_OVERRIDE is set in the makefile of the component
ifndef CC_OVERRIDE
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(call FLAGS_FILTER, $(CFLAGS), $<) $< \
	           -o $@ $(INCFLAGS) -iquote .
else
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(call FLAGS_FILTER, $(CXXFLAGS), $<) $< \
	            -o $@ $(INCFLAGS) -iquote .
endif

$(OBJDIR)/%.o : %.S
	@mkdir -p $(OBJDIR)
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(ASMFLAGS) $< -o $@ $(ASMINCFLAGS) $(INCFLAGS) -iquote .

ifdef MODULE
$(IMGDIR)/lib$(MODULE).so : $(OBJECTS) $(ROOTPATH)/src/module.ld $(MODULE_INIT)
	$(C2) "    LD         $(notdir $@)"
	$(C1)$(LD) -shared -z now $(LDFLAGS) \
		   $(OBJECTS) $(MODULE_INIT) \
	           -T $(ROOTPATH)/src/module.ld -o $@
endif
