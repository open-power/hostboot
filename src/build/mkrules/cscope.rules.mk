# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cscope.rules.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2018
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

# File: cscope.rules.mk
# Description:
#     Rules for running Cscope and Ctags against the codebase.

.PHONY: cscope
cscope:
	@mkdir -p $(ROOTPATH)/obj/cscope
	$(C2) "    CSCOPE"
	$(C1)(cd $(ROOTPATH)/obj/cscope ; rm -f cscope.* ; \
	      find ../../ -name '*.[CHchS]' -type f -fprint cscope.files; \
	      cscope -bk)
# removed -q as it caused a segfault in obj/modules/testfapi2/testfapi2.C

.PHONY: ctags
ctags:
	@mkdir -p $(ROOTPATH)/obj/cscope
	$(C2) "    CTAGS"
	$(C1)(cd $(ROOTPATH)/obj/cscope ; rm -f tags ; \
	      ctags --recurse=yes --fields=+S ../../src)

