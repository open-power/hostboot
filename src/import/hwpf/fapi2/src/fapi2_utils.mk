# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/src/fapi2_utils.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG
MODULE=fapi2_utils
$(call ADD_MODULE_INCDIR,$(MODULE),$(FAPI2_PLAT_INCLUDE))
OBJS+=fapi2_utils.o
$(call BUILD_MODULE)
