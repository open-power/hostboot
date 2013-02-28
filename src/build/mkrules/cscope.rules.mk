# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/cscope.rules.mk $
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

# File: cscope.rules.mk
# Description:
#     Rules for running Cscope and Ctags against the codebase.

.PHONY: cscope
cscope:
	@mkdir -p $(ROOTPATH)/obj/cscope
	$(C2) "    CSCOPE"
	$(C1)(cd $(ROOTPATH)/obj/cscope ; rm -f cscope.* ; \
	      find ../../ -name '*.[CHchS]' -type f -fprint cscope.files; \
	      cscope -bqk)

.PHONY: ctags
ctags:
	@mkdir -p $(ROOTPATH)/obj/cscope
	$(C2) "    CTAGS"
	$(C1)(cd $(ROOTPATH)/obj/cscope ; rm -f tags ; \
	      ctags --recurse=yes --fields=+S ../../src)

