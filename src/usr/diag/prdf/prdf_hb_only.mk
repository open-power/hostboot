# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: ./prdf_hb_only.mk $
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

################################################################################
# PRD rule plugin object files (Hostboot only).
################################################################################

PRDF_RULE_PLUGINS_PEGASUS_HB = \
	prdfPlatCenPll.o

################################################################################
# PRD object files (Hostboot only).
################################################################################

prd_pegasus_specific_HB = \
    prdfDramRepairs.o \
	prdfPlatCalloutUtil.o

