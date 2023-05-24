# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/genxml/create_odyperv.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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

###
# Generate the Odyssey Pervasive targets for the P10 standalone configuration
#
# Hints for xml modifications
#  Find the range in the xml : grep -n "Odyssey PERV Units" simics_P10.system.xml
#  Delete lines 123-234 : sed -i '123,234d' simics_P10.system.xml
#  Insert result into xml at line 123 : sed -i '123 r operv.txt' simics_P10.system.xml

$max_proc=2;
$max_mc=4;
$max_mi=1;
$max_mcc=2;
$max_omi=2;

for( $proc = 0; $proc < $max_proc; $proc++ )
{
    for( $mc = 0; $mc < $max_mc; $mc++ )
    {
        $mi = 0; # only 1 MI
        for( $mcc = 0; $mcc < $max_mcc; $mcc++ )
        {
            for( $omi = 0; $omi < $max_omi; $omi++ )
            {
                # The ddimm/ocmb connection
                $ddimm = $proc*$max_mc*$max_mi*$max_mcc*$max_omi
                         + $mc*$max_mi*$max_mcc*$max_omi
                         + $mi*$max_mcc*$max_omi
                         + $mcc*$max_omi
                         + $omi;
                # 2 Pervasive targets for each Odyssey
                foreach( 1, 8 )
                {
                    $perv = $_;

                    # Leave space in all numbering for 9 PERV targets

                    # Agreement with Cronus to add arbitrary 0x8000
                    $fapipos = (($ddimm * 9) + $perv) | 0x8000;

                    # SSSSNNNNTTTTTTTTCCiiiiiiiiiiiiii
                    #  CC=01 for Odyssey
                    $huid = (($ddimm * 9) + $perv) | 0x002C4000;

                    # Arbitrary jump to handle largest system
                    $ordinalid = (($ddimm * 9) + $perv) | 0x400;

printf "\n";
printf "<targetInstance>\n";
printf "  <id>sys0node0ocmb%dperv%d</id>\n", $ddimm, $perv;
printf "  <type>unit-perv</type>\n";
printf "  <attribute>\n";
printf "    <id>AFFINITY_PATH</id>\n";
printf "    <default>affinity:sys-0/node-0/proc-%d/mc-%d/mi-%d/mcc-%d/omi-%d/ocmb_chip-0/perv-%d</default>\n", $proc, $mc, $mi, $mcc, $omi, $perv;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>CHIP_UNIT</id>\n";
printf "    <default>%d</default>\n", $perv;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>CHIPLET_ID</id>\n";
printf "    <default>%d</default>\n", $perv;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>REL_POS</id>\n";
printf "    <default>%d</default>\n", $perv;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>FAPI_NAME</id>\n";
printf "    <default>ocmb.perv:k0:n0:s0:p%.2d:c%.2d</default>\n", $ddimm, $perv;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>FAPI_POS</id>\n";
printf "    <default>%d</default>\n", $fapipos;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>HUID</id>\n";
printf "    <default>0x%.8X</default>\n", $huid;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>ORDINAL_ID</id>\n";
printf "    <default>%d</default>\n", $ordinalid;
printf "  </attribute>\n";
printf "  <attribute>\n";
printf "    <id>PHYS_PATH</id>\n";
printf "    <default>physical:sys-0/node-0/ocmb_chip-%d/perv-%d</default>\n", $ddimm, $perv;
printf "  </attribute>\n";
printf "</targetInstance>\n";

                }
            }
        }
    }
}
printf "\n";

