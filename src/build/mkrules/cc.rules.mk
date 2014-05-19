# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cc.rules.mk $
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
	            -o $@.trace $(INCFLAGS) -iquote .
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@rm $@.trace

# Compiling *.cc files
$(OBJDIR)/%.o : %.cc
	@mkdir -p $(OBJDIR)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(CXXFLAGS) $< -o $@.trace $(INCFLAGS) -iquote .
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@rm $@.trace


$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
# Override to use C++ compiler in place of C compiler
# CC_OVERRIDE is set in the makefile of the component
ifndef CC_OVERRIDE
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(call FLAGS_FILTER, $(CFLAGS), $<) $< \
	           -o $@.trace $(INCFLAGS) -iquote .
else
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CXX) -c $(call FLAGS_FILTER, $(CXXFLAGS), $<) $< \
	            -o $@.trace $(INCFLAGS) -iquote .
endif
	$(C1)$(TRACE_HASHER) $@ $(TRACE_FLAGS)
	@rm $@.trace

$(OBJDIR)/%.o : %.S
	@mkdir -p $(OBJDIR)
	$(C2) "    CC         $(notdir $<)"
	$(C1)$(CC) -c $(ASMFLAGS) $< -o $@ $(ASMINCFLAGS) $(INCFLAGS) -iquote .

ifdef MODULE
$(IMGDIR)/lib$(MODULE).so : $(OBJECTS) $(ROOTPATH)/src/module.ld $(MODULE_INIT)
	$(C2) "    LD         $(notdir $@)"
	$(C1)$(LD) -shared -z now -x $(LDFLAGS) \
		   $(OBJECTS) $(MODULE_INIT) \
	           -T $(ROOTPATH)/src/module.ld -o $@
endif
