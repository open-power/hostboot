#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/genStandaloneMrw.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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

# This script generates a hostboot-compatible file from a machine-specific MRW.
# The generated file can be used in place of the simics system XML to 
# create patches for eBMC machines from a standalone Hostboot environment. 

set -x
set -e

MRW_HB_TOOLS=$PROJECT_ROOT/src/usr/targeting/common
MACHINE_XML_TARGET_TYPES_OPENPOWER_XML=$MRW_HB_TOOLS/xmltohb/target_types_openpower.xml

XML="$1"
TMPOUT="$XML.mrw.tmp"

perl -I $MRW_HB_TOOLS $MRW_HB_TOOLS/processMrw.pl -x "$XML" -o "$TMPOUT"

perl $MRW_HB_TOOLS/filter_out_unwanted_attributes.pl \
            --tgt-xml $PROJECT_ROOT/obj/genfiles/target_types_full.xml \
            --tgt-xml $MRW_HB_TOOLS/xmltohb/target_types_hb.xml \
            --tgt-xml $MRW_HB_TOOLS/xmltohb/target_types_oppowervm.xml \
            --tgt-xml $MRW_HB_TOOLS/xmltohb/target_types_openpower.xml \
            --mrw-xml "$TMPOUT"

echo Copy "$TMPOUT".updated to $PROJECT_ROOT/src/usr/targeting/common/xmltohb/simics_P10.system.xml
