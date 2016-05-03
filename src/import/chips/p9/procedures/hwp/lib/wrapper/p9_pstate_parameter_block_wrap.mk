# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/lib/wrapper/p9_pstate_parameter_block_wrap.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015,2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG
WRAPPER=p9_pstate_parameter_block_wrap
$(WRAPPER)_USELIBS += p9_pstate_parameter_block
$(call BUILD_WRAPPER)
