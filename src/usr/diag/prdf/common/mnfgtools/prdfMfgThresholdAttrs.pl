#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholdAttrs.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2015
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

use strict;

if (0 != $#ARGV)
{
    print "prdfMfgThresholdAttrs.pl <threshold list>\n";
    exit;
}

unless (-e $ARGV[0])
{
    die "Couldn't find ".$ARGV[0];
}

print "#ifndef __PRDF_PRDFMFGTHRESHOLDATTRS_H\n";
print "#define __PRDF_PRDFMFGTHRESHOLDATTRS_H\n";
print "#ifndef PRDF_MFGTHRESHOLD_ENTRY\n";
print "#define PRDF_MFGTHRESHOLD_TABLE_BEGIN \\\n";
print "\tenum PrdfMfgThresholdAttrs {\n";
print "#define PRDF_MFGTHRESHOLD_TABLE_END \\\n";
print "\t};\n";
print "#define PRDF_MFGTHRESHOLD_ENTRY(a,b) \\\n";
print "\ta = b,\n";
print "#endif\n";
print "\n";
print "PRDF_MFGTHRESHOLD_TABLE_BEGIN\n";

open(THRESHOLDS, $ARGV[0]);
while (my $line = <THRESHOLDS>)
{
    chomp $line;
    $line =~ s/#.*//;

    if ("" eq $line)
    {
        next;
    }

    if (($line !~ "ATTR_MNFG_TH_") and ($line !~ "ATTR_FIELD_TH_"))
    {
        next;
    }

    # Remove the blank spaces
    $line =~ s/ //g;

    # Remove the token ","
    $line =~ s/,//g;

    my ($name, $value) = split '=',$line;

    print "\tPRDF_MFGTHRESHOLD_ENTRY($name, $value)\n";
}
close(THRESHOLDS);

print "PRDF_MFGTHRESHOLD_TABLE_END\n";
print "\n";
print "#endif\n";

