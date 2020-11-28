# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/mkrules/hbfw/fsp/makefile $
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
# FSP Destination: src/hbfw/fsp/makefile
#
# NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
#       repository and will be overwritten.


# Process the targeting subtree

.if (${CONTEXT:R} == "ppc")

SETUP_SUBDIRS    += targeting
EXPINC_SUBDIRS   += targeting hwas pnor plugins
OBJECTS_SUBDIRS  += plugins
EXPLIB_SUBDIRS   += plugins
EXPSHLIB_SUBDIRS += targeting plugins
STANDARD_SUBDIRS += targeting plugins
RUNBVT_SUBDIRS   +=

INCLUDES = hbdescriptor.H \
           hbterminatetypes.H \
           hbotcompid.H \
           hbfw_term_rc.H \
           memoize.H

.elseif (${CONTEXT} == "x86.nfp")

# this file is in src/hbfw/fsp in cmvc
.include "makefile.nfp"

SETUP_SUBDIRS    += targeting
EXPINC_SUBDIRS   += plugins
OBJECTS_SUBDIRS  += plugins
EXPLIB_SUBDIRS   += plugins
EXPSHLIB_SUBDIRS += plugins
STANDARD_SUBDIRS += plugins

INCLUDES = hbotcompid.H

.endif

.include <${RULES_MK}>
