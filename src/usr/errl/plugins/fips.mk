#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/plugins/fips.mk $
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

# This is a FipS makefile. The 'hb errlparser' step will copy it
# to a FipS build tree and assign a value for HBCOMPS as it is copied.


.if ( $(CONTEXT) == "x86.nfp" || $(CONTEXT) == "ppc" )

EXPINC_SUBDIRS = $(HBCOMPS)
EXPLIB_SUBDIRS = $(HBCOMPS) 
OBJECTS_SUBDIRS = $(HBCOMPS)
SUBDIRS = $(HBCOMPS)
EXPSHLIB_SUBDIRS = $(HBCOMPS)

.elif ( $(CONTEXT) == "aix.nfp" )

EXPINC_SUBDIRS =
EXPLIB_SUBDIRS =
OBJECTS_SUBDIRS =
SUBDIRS =
EXPSHLIB_SUBDIRS =
.endif

.include <${RULES_MK}>
