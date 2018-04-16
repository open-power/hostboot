#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/genIstepWaitOverride.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018
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
use Getopt::Long;
use POSIX;
use Env;
use XML::LibXML;
use File::Temp qw(tempfile);

my $seconds          = "";
my $stepMajor        = "";
my $stepMinor        = "";
my $fullStopEnabled  = 0;
my $makeValuesConst  = 0;
my $disableSecurity  = 0;
my $outFile          = "FspOverrideAttrs.txt";
my $usage            = 0;
my $verbose          = 0;


GetOptions("sec:i"           => \$seconds,
           "major:i"         => \$stepMajor,
           "minor:i"         => \$stepMinor,
           "out:s"           => \$outFile,
           "fullStop"        => \$fullStopEnabled,
           "disableSecurity" => \$disableSecurity,
           "const"           => \$makeValuesConst,
           "verbose"         => \$verbose,
           "debug"           => \$verbose,
           "help"            => \$usage);

if($usage)
{
    display_help();
    exit 1;
}
elsif ($stepMajor eq "" ||
    $stepMinor eq "" ||
    $seconds   eq "" )
{
    print "\n\nERROR !! Expected inputs for --major, --minor, and --sec\n\n";
    display_help();
    exit 1;
}


# Make sure seconds is a valid value
if( $seconds >= 255 )
{
    print "\nWait time entered was $seconds, which is greater than 254. Setting value to 255, which will cause the wait to be indefinite\n\n";
    $seconds = 255;
}
elsif( $seconds <= 0 )
{
    print "\nWait time must be greater than 0, exiting program\n\n";
    exit 1;
}

# Istep values are harder to verify, they will change over time so
# we are not going to verify the values

if($verbose)
{
    print "***Inputs***\n\n";
    print "Istep Major       = $stepMajor\n";
    print "Istep Minor       = $stepMinor\n";
    print "Wait time         = $seconds seconds\n";
    print "Full Stop Enabled = ";
    print $fullStopEnabled ? "True\n" : "False\n";
    print "Out File          = $outFile\n\n"
}


# Convert values to hex strings
my $stepMajorHex = sprintf("%.2X",$stepMajor);
my $stepMinorHex = sprintf("%.2X",$stepMinor);
my $secondsHex = sprintf("%.2X",$seconds);
my $fullStopHex = $fullStopEnabled ? "01" : "00";

if($verbose)
{
    print "***Hex Conversions***\n\n";
    print "Istep Major (hex)       = 0x$stepMajorHex\n";
    print "Istep Minor (hex)       = 0x$stepMinorHex\n";
    print "Wait time   (hex)       = 0x$secondsHex seconds\n";
    print "Full Stop Enabled (hex) = 0x$fullStopHex\n\n";
}

# typedef struct
#    {
#        uint8_t majorStep; // Target istep where pause will be applied
#        uint8_t minorStep;
#        uint8_t pauseLen;  // The number of seconds before IPL resumes from
#                           // pause state
#        uint8_t fullStopEn; // Enable full stop. When set to 0x01 the IPL stops
#                            // indefinitely until resumed using an outside
#                            // command
#        uint32_t bpTagInfo; // Tag value passed to the iStepBreakPoint
#                            // function
#    } istepPauseConfig_t;

# value to write to ATTR_ISTEP_PAUSE_CONFIG , note that we are always setting bpTagInfo to 0
my $istepPauseConfigValue = $stepMajorHex.$stepMinorHex.$secondsHex.$fullStopHex."00000000";

# Open File writer
open(my $fh , ">", $outFile)
      or croak ("Attribute Override File file: FspOverrideAttrs.txt could not be opened.");
my $attrOverrideFile = *$fh;

my $attrLineEnd = "\n";
if($makeValuesConst)
{
    $attrLineEnd = "CONST\n";
}

# Write contents of file
print $attrOverrideFile "CLEAR\n";
print $attrOverrideFile "target = k0:n0:s0:\n";
if($disableSecurity)
{
    print $attrOverrideFile "ATTR_BOOT_FLAGS 0x16000000 $attrLineEnd";
}
print $attrOverrideFile "ATTR_ISTEP_PAUSE_ENABLE 0x1 $attrLineEnd";
print $attrOverrideFile "ATTR_ISTEP_PAUSE_CONFIG 0x$istepPauseConfigValue $attrLineEnd";

# Close file writer
close $attrOverrideFile;

if($verbose)
{
    print "***Written to $outFile***\n\n";
    system("cat FspOverrideAttrs.txt");
    print "\n";
}


sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

    This perl script is a utility tool to generate an FspOverrideAttrs.txt file that will insert
    a wait loop after a specified istep. Sometimes it is useful to add in an extra wait so that
    a user can manually insert a command to the system via the FSP command line or Cronus in order
    to test failure paths or do other debugging techniques.

    NOTE: This script does not currently support break point tag information , which is the last
          32 bits of the ISTEP_PAUSE_CONFIG attribute.

Usage:

    $scriptname --help
            Dump this help text to the screen.

    $scriptname --sec=numSecondsToWait          [ Required ]
            Decimal representation of the number of seconds we would like to wait after
            the istep. Note the max value for this is 254 seconds. If this is set to be
            255 or greater the wait will be indefinite.

    $scriptname --major=majorIstepNumber        [ Required ]
            Decimal representation of the major istep number we want to wait after. See IPL flow
            documentation for valid major istep numbers.

    $scriptname --minor=minorIstepNumber        [ Required ]
            Decimal representation of the minor istep number we want to wait after. See IPL flow
            documentation for valid minor istep numbers for each major step.

    $scriptname --fullStop                      [ Optional ]
            If this flag is passed the wait will be indefinite

    $scriptname --disableSecurity                [ Optional ]
            Adding this flag will add the ATTR_BOOT_FLAGS override into the final output which
            will disable security on the system allowing for more scom access

    $scriptname --const                          [ Optional ]
            Adding this flag will make the attribute overrides CONST which will make the overrides
            persist through reboots. The overrides will live in the ATTR_PERM section if this flag
            is set.

    $scriptname --verbose | -v | --debug | -d   [ Optional ]
            Print extra debug information while script is running

    $scriptname --out=nameOfOutputFile          [ Optional ]
            This is automatically defaulted to be FspOverrideAttrs.txt which is what the file
            needs to be named to be consumed by attributeOverride tooling. You can change it to
            be whatever you want though.
\n\n";
}
