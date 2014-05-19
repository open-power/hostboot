# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/dep.rules.mk $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
	$(CXX_RAW) -M $(call FLAGS_FILTER, $(CXXFLAGS), $<) $< \
	           -o $@.$$$$ $(INCFLAGS) -iquote .; \
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
	$(CC_RAW) -M $(ASMFLAGS) $< -o $@.$$$$ $(ASMINCFLAGS) \
	          $(INCFLAGS) -iquote .; \
	sed 's,\($*\)\.o[ :]*,$(OBJDIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

