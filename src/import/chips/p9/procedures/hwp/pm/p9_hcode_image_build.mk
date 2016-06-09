# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/pm/p9_hcode_image_build.mk $
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
PROCEDURE=p9_hcode_image_build
HCODE_UTIL=$(ROOTPATH)/chips/p9/procedures/utils/stopreg/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/xip/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/lib/
HCODE_UTIL+=$(ROOTPATH)/tools/imageProcs/
$(PROCEDURE)_DEPLIBS+=p9_xip_image
$(PROCEDURE)_DEPLIBS+=p9_tor
$(PROCEDURE)_DEPLIBS+=p9_ringId
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(HCODE_UTIL))
$(call BUILD_PROCEDURE)
