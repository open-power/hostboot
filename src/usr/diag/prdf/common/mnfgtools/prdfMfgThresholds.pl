#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholds.pl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2009,2014
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

sub adler32_sum
{
    my $a = 1;
    my $b = 0;
    foreach (split //, shift)
    {
        $a = $a + ord($_);
        $b = $a + $b;

        $a = $a % 65521;
        $b = $b % 65521;
    }

    return (($b << 16) | $a) & 0x7FFFFFFF;
}

if (0 != $#ARGV)
{
    print "prdfMfgThresholds.pl <threshold list>\n";
    exit;
}

if (not -e $ARGV[0])
{
    die "Couldn't find ".$ARGV[0];
}

print "#ifndef __PRDF_PRDFMFGTHRESHOLDS_H\n";
print "#define __PRDF_PRDFMFGTHRESHOLDS_H\n";
print "#ifndef PRDF_MFGTHRESHOLD_ENTRY\n";
print "#define PRDF_MFGTHRESHOLD_TABLE_BEGIN \\\n";
print "\tenum PrdfMfgThresholds {\n";
print "#define PRDF_MFGTHRESHOLD_TABLE_END \\\n";
print "\t};\n";
print "#define PRDF_MFGTHRESHOLD_ENTRY(a,b,c) \\\n";
print "\tPRDF_##a = b,\n";
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
    my ($name, $value) = split ' ',$line;
    $value =~ s/unlimited/0/i;

    my $hash_value = adler32_sum($name);

    print "\tPRDF_MFGTHRESHOLD_ENTRY($name, $hash_value, $value)\n";
}
close(THRESHOLDS);

print "PRDF_MFGTHRESHOLD_TABLE_END\n";
print "\n";
print "#endif\n";

