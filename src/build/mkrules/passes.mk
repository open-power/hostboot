# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/passes.mk $
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

# File: passes.mk
# Description:
#     Root of the passes for the build system.
#
# These are handled at the end (after the other env/rules files) because there
# are many variables defined in earlier makefiles that are needed to properly
# create the passes.

include $(MKRULESDIR)/passes.env.mk
include $(MKRULESDIR)/passes.rules.mk
