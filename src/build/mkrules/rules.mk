# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/rules.mk $
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

# File: rules.mk
# Description:
#     Root of the rules (ie. recipes) for the build system.

include $(MKRULESDIR)/verbose.rules.mk
include $(MKRULESDIR)/dep.rules.mk
include $(MKRULESDIR)/cxxtest.rules.mk
include $(MKRULESDIR)/cc.rules.mk
include $(MKRULESDIR)/binfile.rules.mk
include $(MKRULESDIR)/beam.rules.mk
include $(MKRULESDIR)/gcov.rules.mk
include $(MKRULESDIR)/images.rules.mk
include $(MKRULESDIR)/cscope.rules.mk

