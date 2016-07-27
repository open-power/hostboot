# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/initfiles/p9_mc_scan.mk $
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
PROCEDURE=p9_mc_scan
lib$(PROCEDURE)_COMMONFLAGS+=-DFAPI_SUPPORT_SPY_AS_STRING=1
$(call BUILD_PROCEDURE)

PROCEDURE=p9_mc_scan_ifCompiler
lib$(PROCEDURE)_COMMONFLAGS+=-DFAPI_SUPPORT_SPY_AS_STRING=1
lib$(PROCEDURE)_COMMONFLAGS+=-DIFCOMPILER_PLAT=1
FAPI=2_IFCOMPILER
OBJS+=p9_mc_scan.o
lib$(PROCEDURE)_LIBPATH=$(LIBPATH)/ifCompiler
lib$(PROCEDURE)_COMMONFLAGS+=-fno-var-tracking-assignments
$(call BUILD_PROCEDURE)