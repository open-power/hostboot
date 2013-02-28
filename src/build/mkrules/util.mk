# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/util.mk $
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

# File: util.mk
# Description:
#    Make utility functions that can be used in generating other variables
#    or rules.

__internal__comma= ,
__internal__empty=
__internal__space=$(__internal__empty) $(__internal__empty)

# Convert a comma separated list to a space separated list.
MAKE_SPACE_LIST = $(subst $(__internal__comma),$(__internal__space),$(1))


