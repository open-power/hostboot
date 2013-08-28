# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/makefile $
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
# FSP Destination: src/hbfw/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.

# Process the fsp subtree

.if(${CONTEXT:R} == "ppc")

EXPINC_SUBDIRS   += fsp
OBJECTS_SUBDIRS  += 
EXPLIB_SUBDIRS   += fsp
EXPSHLIB_SUBDIRS += fsp
STANDARD_SUBDIRS += fsp img simics
RUNBVT_SUBDIRS   += 

.elseif(${CONTEXT} == "x86.nfp")

EXPINC_SUBDIRS   += fsp
OBJECTS_SUBDIRS  += 
EXPLIB_SUBDIRS   += fsp
EXPSHLIB_SUBDIRS += fsp
STANDARD_SUBDIRS += fsp
RUNBVT_SUBDIRS   +=

.endif

# Directives to expand tar files and ensure expansion before
# subdirectory traversal.
#
# If you add a new tarfile and subdirectory, you must add the 
# corresponding _SUBDIR/BUILD/EXPINC/subdir dependency.

TARFILES = fsp.tar simics.tar

_SUBDIR/BUILD/EXPINC/fsp: expand_tars_fsp.tar
_SUBDIR/BUILD/EXPINC/simics: expand_tars_simics.tar

EXPINC_TARGETS += expand_tars

expand_tars: ${TARFILES:S/^/expand_tars_/g}
expand_tars_%: $${@:S/expand_tars_//}
	@echo Extracting $> to ${*:S/expand_tars_//}
	mkdir -p ${*:S/expand_tars_//}
	${TAR} -x --file $> -C ${*:S/expand_tars_//}

.include <${RULES_MK}>
