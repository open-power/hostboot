#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/plugins/plugins.mk $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

# This is a FipS makefile. It will be copied to the directory above
# the directories for Hostboot components that build an errl plugin.

# Hostboot plugin makefiles should include this makefile with 
#          .include "../plugins.mk" 
# in order to set CFLAGS. Eventually, there may be other global 
# settings common to all Hostboot makefiles.  This makefile 
# provides a common place for such changes.


CFLAGS += -DERRL_TOOLS -DPARSER  -I${HOSTBOOTROOT}/obj/genfiles  -I${HOSTBOOTROOT}/src/include/usr

