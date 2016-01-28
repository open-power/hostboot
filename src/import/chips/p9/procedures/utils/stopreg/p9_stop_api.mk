# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/utils/stopreg/p9_stop_api.mk $
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
PROCEDURE=p9_stop_api
STOP_UTIL=$(ROOTPATH)/chips/p9/procedures/utils/stopreg/
STOP_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/lib
libp9_stop_util_DEPLIBS += p9_stop_util
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(STOP_UTIL))
$(call BUILD_PROCEDURE)
