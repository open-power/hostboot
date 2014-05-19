# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cxxtest.rules.mk $
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

# File: cxxtest.rules.mk
# Description:
#     Rules for creating the CxxTest driver for a testcase module.

ifdef TESTS

TESTGEN = $(ROOTPATH)/src/usr/cxxtest/cxxtestgen.pl

ifdef MODULE
OBJS += $(MODULE).o
CLEAN_TARGETS += $(OBJDIR)/$(MODULE).C
vpath %.C $(OBJDIR) $(shell mkdir -p $(OBJDIR))
else
$(error MODULE must be defined for a testcase.)
endif

$(OBJDIR)/$(MODULE).C: $(TESTS)
	@mkdir -p $(OBJDIR)
	$(C2) "    TESTGEN    $(notdir $@)"
	$(C1)$(TESTGEN) --hostboot -o $@ $(TESTS)

endif
