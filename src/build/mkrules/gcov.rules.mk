# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/gcov.rules.mk $
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

# File: gcov.rules.mk
# Description:
#     Rules for analyzing coverage data.  This is handled by a special GCOV
#     pass.

GCOV_PASS_PRE += make_gcovdir
GCOV_PASS_BODY += make_gcovdata

.PHONY: make_gcovdir
make_gcovdir:
	@mkdir -p $(GCOVDIR)

.PHONY: make_gcovdata
make_gcovdata:
ifdef OBJS
	$(C2)"    LCOV       $(GCOVNAME)"
	$(C1)cp $(OBJECTS:.o=.gcno) $(OBJECTS:.o=.gcda) .
	$(C1)lcov --directory . -c -o $(GCOVDIR)/$(GCOVNAME) \
	          --gcov-tool $(GCOV) --ignore-errors source
	$(C1)rm $(OBJS:.o=.gcno) $(OBJS:.o=.gcda) -f
endif

CLEAN_TARGETS += $(OBJECTS:.o=.gcno) $(OBJECTS:.o=.gcda)
