# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/customize/p9_xip_customize.mk $
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
PROCEDURE = p9_xip_customize
lib$(PROCEDURE)_DEPLIBS+=p9_xip_image
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p9/xip)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/tools/imageProcs)
$(call BUILD_PROCEDURE)
