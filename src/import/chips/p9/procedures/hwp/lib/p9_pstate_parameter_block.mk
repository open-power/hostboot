# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/lib/p9_pstate_parameter_block.mk $
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
PROCEDURE=p9_pstate_parameter_block
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p9/procedures/hwp/pm/include/registers)
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p9/procedures/hwp/lib)
#p9_pstate_parameter_block_PATH+=$(PROJECT_ROOT)/chips/p9/procedures/hwp/lib
$(call BUILD_PROCEDURE)
