# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cxxtest.rules.mk $
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
