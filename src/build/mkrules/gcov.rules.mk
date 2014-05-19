# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/gcov.rules.mk $
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
