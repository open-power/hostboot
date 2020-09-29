# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2020
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

#
# FSP Destination: src/hbfw/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.

# Process the fsp subtree

.if (${CONTEXT:R} == "ppc")

SETUP_SUBDIRS    += fsp simics
EXPINC_SUBDIRS   += fsp
OBJECTS_SUBDIRS  += img
EXPLIB_SUBDIRS   += fsp
EXPSHLIB_SUBDIRS += fsp
STANDARD_SUBDIRS += fsp img simics
RUNBVT_SUBDIRS   +=

.elseif (${CONTEXT} == "x86.nfp")

SETUP_SUBDIRS    += fsp simics
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

VPATH += fsp/hwas/common:

_SUBDIR/BUILD/SETUP/fsp: expand_tars_fsp.tar overwrite_xml
_SUBDIR/BUILD/SETUP/simics: expand_tars_simics.tar

SETUP_TARGETS += expand_tars overwrite_xml
EXPLIB_TARGETS += epub_check

expand_tars: ${TARFILES:S/^/expand_tars_/g}
expand_tars_%: $${@:S/expand_tars_//}
	@echo Extracting $> to ${*:S/expand_tars_//}
	mkdir -p ${*:S/expand_tars_//}
	@echo "===== src/hbfw/makefile: START EXTRACT of tarball $> :" `date`
	${TAR} -x --file $> -C ${*:S/expand_tars_//}
	@echo "===== src/hbfw/makefile: END EXTRACT of tarball $> :" `date`


#Overwrites the old xml files with the new generated ones
overwrite_xml: expand_tars_fsp.tar
	@echo "Replacing attribute_types.xml with attribute_types_sp.xml"
	cp fsp/attribute_types_sp.xml fsp/targeting/common/xmltohb/attribute_types.xml
	@echo "Replacing target_types.xml with target_types_sp.xml"
	cp fsp/target_types_sp.xml fsp/targeting/common/xmltohb/target_types.xml

# Note that epub_check depends on expand_tars but it will always
# be run first due to force of it in EXPINC.
epub_check: epubProcedureID_check.pl epub_service_codes.H
	@echo "===== Checking epubProcedureID's Start:" `date`
	${epubProcedureID_check.pl:P} ${epub_service_codes.H:P} ${hwasCallout.H:P}
	@echo "===== Checking epubProcedureID's End:" `date`

.include <${RULES_MK}>
