# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dep.rules.mk $
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

# File: dep.rules.mk
# Description:
#     Rules for creating the header-file dependencies for C/C++/ASM files.

$(OBJDIR)/%.dep : %.C
	@mkdir -p $(OBJDIR)
	$(C2) "    DEP        $(notdir $<)"
	$(C1)rm -f $@; \
	$(CXX_RAW) -M $(call FLAGS_FILTER, $(CXXFLAGS), $<) $< \
                   -o $@.$$$$ $(INCFLAGS) -iquote .; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(OBJDIR)/%.dep : %.cc
	@mkdir -p $(OBJDIR)
	$(C2) "    DEP        $(notdir $<)"
	$(C1)rm -f $@; \
	$(CXX_RAW) -M $(CXXFLAGS) $< -o $@.$$$$ $(INCFLAGS) -iquote .; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(OBJDIR)/%.dep : %.c
	@mkdir -p $(OBJDIR)
	$(C2) "    DEP        $(notdir $<)"
	$(C1)rm -f $@; \
	$(CC_RAW) -M $(call FLAGS_FILTER, $(CFLAGS), $<) $< \
                  -o $@.$$$$ $(INCFLAGS) -iquote .; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(OBJDIR)/%.dep : %.S
	@mkdir -p $(OBJDIR)
	$(C2) "    DEP        $(notdir $<)"
	$(C1)rm -f $@; \
	$(CC_RAW) -M $(ASMFLAGS) $< -o $@.$$$$ $(ASMINCFLAGS) $(INCFLAGS) -iquote .; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

