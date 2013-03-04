#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/mnfgtools/prdfMfgThresholds.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2009,2013
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

