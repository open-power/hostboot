# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/fsp/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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

#
# FSP Destination: src/hbfw/fsp/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.


# Process the targeting subtree

.if(${CONTEXT:R} == "ppc")

EXPINC_SUBDIRS   += targeting hwas pnor plugins
OBJECTS_SUBDIRS  += plugins
EXPLIB_SUBDIRS   += plugins
EXPSHLIB_SUBDIRS += targeting plugins
STANDARD_SUBDIRS += targeting plugins
RUNBVT_SUBDIRS   +=

INCLUDES = hbdescriptor.H \
           hbterminatetypes.H \

.elseif(${CONTEXT} == "x86.nfp")

# this file is in src/hbfw/fsp in cmvc
.include "makefile.nfp"

EXPINC_SUBDIRS   += plugins
OBJECTS_SUBDIRS  += plugins
EXPLIB_SUBDIRS   += plugins
EXPSHLIB_SUBDIRS += plugins
STANDARD_SUBDIRS += plugins
.endif

.include <${RULES_MK}>
