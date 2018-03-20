#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/scom/genCentaurScomCacheRegDefs.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2018
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

################################################################################
# Imported packages
################################################################################

use Carp;
use Getopt::Long;
use Pod::Usage;

################################################################################
# Initialize some globals
################################################################################

use constant OUT_FILE_BASE=>"centaurScomCacheRegDefs";
use constant OUT_C_FILE=>OUT_FILE_BASE.".C";

################################################################################
# Process command line parameters, issue help text if needed.
################################################################################

my $cfgCsvFile ="Centaur_Register_List.csv";
my $cfgOutputDir = ".";
my $cfgHelp=0;
my $cfgMan=0;
my $cfgVerbose=0;

GetOptions("csv:s" => \$cfgCsvFile,
           "output-dir:s" =>  \$cfgOutputDir,
           "help" => \$cfgHelp,
           "man" => \$cfgMan,
           "verbose" => \$cfgVerbose ) || pod2usage(-verbose => 0);

pod2usage(-verbose => 1) if $cfgHelp;
pod2usage(-verbose => 2) if $cfgMan;

# Remove extraneous '/' from end of path names; use temporary version of $/ for
# the chomp
{
    local $/ = '/';
    chomp($cfgOutputDir);
    $cfgOutputDir .= "/";
}

if($cfgVerbose)
{
    print STDOUT "CSV file = $cfgCsvFile\n";
    print STDOUT "Output dir = $cfgOutputDir\n";
    print STDOUT "Output file name = " . OUT_C_FILE . "\n";
}

################################################################################
# Main logic
################################################################################

open(CSV_FILE,"<$cfgCsvFile")
    or croak("Failed to open CSV file of $cfgCsvFile.");
my $csvFile = *CSV_FILE;

my $outSrcFile="$cfgOutputDir".OUT_C_FILE;
open(OUT_SRC_FILE,">$outSrcFile")
    or croak("Failed to open output source file of "
        . "$outSrcFile");
my $sourceFile = *OUT_SRC_FILE;

writeScomRegDefSourceHeader($sourceFile);
writeScomRegDefSourceContent($csvFile,$sourceFile);
writeScomRegDefSourceFooter($sourceFile);

close CSV_FILE or croak("Failed to close CSV file of $cfgCsvFile");

close OUT_SRC_FILE or
    croak("Failed to close output source file of $outSrcFile");

################################################################################
#  @brief: Strips off leading and trailing whitespace from an input line
#      and returns it
#  @param[in] $line Line of input file
#  @return Line without leading and trailing whitespace
################################################################################

sub stripLeadingAndTrailingWhitespace {
    my($line) = @_;

    $line =~ s/^\s+|\s+$//g;

    return $line;
}

################################################################################
#  @brief: Verifies an input line ends with a comma
#  @param[in] $line Line of input file
################################################################################

sub verifyEndsWithComma
{
    my $line = shift;

    if ($line !~ m/,$/)
    {
         croak "BUG! CSV file doesn't end with comma\n\t$line";
    }
}

################################################################################
#  @brief: Verifies an input line has no starting comma
#  @param[in] $line Line of input file
################################################################################

sub verifyNoStartingComma
{
    my $line = shift;

    if ($line =~ m/^,/)
    {
         croak "BUG! CSV file should not start with comma\n\t$line";
    }
}

################################################################################
#  @brief: Returns whether number is a hex number without leading 0x
#  @param[in] $number Number to verify
#  @retval 0 if not a 0x-less hex number
#  @retval 1 if a 0x-less hex number
################################################################################

sub isValidNumber
{
    my $number=shift;
    my $valid=0;

    my $maxLength = 16;

    if ($number =~ m/^[0-9a-fA-F]{1,$maxLength}$/)
    {
        $valid=1;
    }

    return $valid;
}

################################################################################
#  @brief: Scrubs required register address and returns a sanitized copy
#  @param[in] $addr The register address
#  @param[in] $line Line of the input file to display on error conditions
#  @return A normalized register address
################################################################################

sub normalizeRequiredAddr
{
    my $addr=shift;
    my $line=shift;

    if(!defined $addr
       || $addr eq "")
    {
        croak "BUG! CSV file record had undefined register "
            . "address [$addr]\n\t$line";
    }

    if(!isValidNumber($addr))
    {
        croak "BUG! CSV file record has invalid address [$addr]\n\t$line";
    }

    $addr="0x".$addr."ULL";
    return $addr;
}

################################################################################
#  @brief: Scrubs optional input value and returns a sanitized copy
#  @param[in] $value The property value read from the input file
#  @param[in] $default The default value to use if file did not specify
#  @param[in] $name Name of the property to display on error conditions
#  @param[in] $line Line of the input file to display on error conditions
#  @return A normalized value
################################################################################

sub normalizeOptionalValue
{
    my $value=shift;
    my $default=shift;
    my $name=shift;
    my $line=shift;

    if(!defined $value
       || $value eq "")
    {
        $value=$default;
    }

    if(!isValidNumber($value))
    {
        croak "BUG! CSV file record has invalid optional $name "
            . "value [$value]\n"
            . "\tOffending line: $line";
    }

    $value="0x".$value."ULL";
    return $value;
}

################################################################################
#  @brief: Writes the leading mostly non-dynamic content for the output source
#      file
#  @param[in] $outFile Name of the output source file (no path components)
################################################################################

sub writeScomRegDefSourceHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

/**
VERBATIM
print $outFile " *  \@file ".OUT_C_FILE."\n";
print $outFile <<VERBATIM;
 *
 *  \@brief Automatically generated source code to initialize the Centaur
 *      SCOM cache register definition vector
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <scom/centaurScomCache.H>

namespace SECUREBOOT
{

namespace CENTAUR_SECURITY
{

ScomRegDefs* ScomCache::_initScomRegDefs() const
{
    ScomRegDefs* pScomRegDefs = new ScomRegDefs{
VERBATIM
}

################################################################################
#  @brief: Writes the dynamic register definition content to the output file
#
#  @param[in] $csvFile Input CSV file's handle to read from
#  @param[in] $outFile Output file's handle to write to
################################################################################

sub writeScomRegDefSourceContent {
    my($csvFile,$outFile) = @_;

    while( <$csvFile> )
    {
        my $line=stripLeadingAndTrailingWhitespace($_);

        #Ignore comments
        if ($line =~ m/^#/)
        {
            next;
        }

        verifyEndsWithComma($line);

        verifyNoStartingComma($line);

        my ($addr,$wandAddr,$worAddr,$init,$mask) = split(/,/,$line);

        $addr = normalizeRequiredAddr($addr,$line);

        $wandAddr = normalizeOptionalValue($wandAddr,"0","wand address",$line);

        $worAddr = normalizeOptionalValue($worAddr,"0","wor address",$line);

        $init = normalizeOptionalValue($init,"0","init",$line);

        my $defaultMask = "FFFFFFFFFFFFFFFF";

        $mask = normalizeOptionalValue(
            $mask,$defaultMask,"mask",$line);

        # Output columns are:
        # Address,WAND?,WOR?,base address,base index,init,mask

        if($wandAddr ne "0x0ULL")
        {
            print $outFile "        "
            . "{$wandAddr,0b1,0b0,$addr,-1,0x0ULL,0x0ULL},\n";

        }

        if($worAddr ne "0x0ULL")
        {
            print $outFile "        "
            . "{$worAddr,0b0,0b1,$addr,-1,0x0ULL,0x0ULL},\n";

        }

        print $outFile "        "
            . "{$addr,0b0,0b0,0x0ULL,-1,$init,$mask},\n";
    }
}

################################################################################
#  @brief: Writes the trailing non-dynamic content to the output source
#      file
#  @param[in] $outFile Output file handle to write to
################################################################################

sub writeScomRegDefSourceFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;
    };

    return pScomRegDefs;
}

} // End CENTAUR_SECURITY namespace

} // End SECUREBOOT namespace


VERBATIM
}

################################################################################
# Man page
################################################################################

1;

__END__

=head1 NAME

genCentaurScomCacheRegDefs.pl

=head1 SYNOPSIS

genCentaurScomCacheRegDefs.pl --csv=FILE --output-dir=DIR

=head1 OPTIONS

=over 8

=item B<--csv>

Absolute path and file name of CSV file containing register definitions

=item B<--output-dir>

Output dir to write the generated source file

=item B<--verbose>

Prints out some internal workings

=item B<--help>

Print a brief help message and exits

=item B<--man>

Prints the manual page and exits

=back

=head1 DESCRIPTION

B<getCentaurScomCacheRegDefs.pl> will generate a source file, which should be
compiled into Hostboot, that seeds the Secure Boot Centaur SCOM cache sensitive
register definitions

=cut
