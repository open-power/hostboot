#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/pkgOcmbFw.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019
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

###############################################################################
#
# Tool for adding a new OCMB firmware header to an unpackaged OCMB firmware
# image or for verifying an existing OCMB firmware header of a pre-packaged
# OCMB firmware image.
#
# OCMB Firmware Header Format:
#    1. Magic number .. indicating this is OCMB firmware ('OCMBHDR'<null>).
#       Can't ever change in presence or size.  8 bytes.
#    2. Version # .. indicating major/minor version of header.
#       Version 1.0 to start.    Can't ever change in presence or size.
#       4 bytes major, 4 bytes minor
#    3. Size of header, relative to start of header (jump that many bytes
#       from start to get to Explorer image content).   4 bytes.
#       Max allowed value = 4k.
#    4. Number of tagged data triplets to follow.  4 bytes.
#    5. Remaining values are tagged data  triplets (in any order) consisting
#       of  4 byte tag id, 4 byte size, content defined by tag ID.
#       Tag ID=1 must be found, others optional.
#        a. [tag ID=1][size=64][ 64 byte SHA-2 512 hash value over Explorer
#           FW content following the header]
#        b. [tag ID=2][size=strlen+1][csv formatted list of key value pairs
#           (see below); null terminated.
#           values cannot have any character of the set {=,} in them].
#           Format:
#               version=<vendor version id>,timestamp=<timestamp>,url=<url>
#                   key/value pairs can be in any order, and can be altered
#                   over time as needed.
#        c. Currently, the header is not designed to support different types
#           of OCMB firmware (just explorer for now), nor different ECs.
#           This can be expanded over time.
#    6. Padding to end of header; size of Explorer binary is protected payload
#       size given by secure header, minus reported header size.
#    7. Content is 8 byte aligned
#
# Header should look like this:
#
#                      0x4               0x8              0xC
#     +----------------+----------------+----------------+----------------+
#  0x0| magic number = "OCMBHDR/0"      | hdr major ver  | hdr minor ver  |
#     +----------------+----------------+----------------+----------------+
# 0x10| header size    | # of triplets  |    tagId = 1   | num bytes = 64 |
#     +----------------+----------------+----------------+----------------+
# 0x20|                                                                   |
#     +                                                                   +
# 0x30|                        64 byte SHA512 hash                        |
#     +                                                                   +
# 0x40|                                                                   |
#     +                                                                   +
# 0x50|                                                                   |
#     +----------------+----------------+----------------+----------------+
# 0x60| tagId = 2      | num bytes      |                                 |
#     +----------------+----------------+                                 +
# 0x80|                                                                   |
#     +          -unordered, comma delimited key/value strings            +
# 0x90|          -variable sized and null terminated                      |
#     +          -padded with zeroes at end for 8 byte alignment          +
# 0xA0|                                                                   |
#     +----------------+----------------+----------------+----------------+
#
#     NOTE: tagged triplet order may vary
#
#
###############################################################################

use strict;
use File::Basename;
use Digest::SHA qw(sha512);
use Getopt::Long qw(:config pass_through);

#Error trace level set to 0 (always printed)
use constant TRAC_ERR => 0;


# Header must start with this magic number
use constant MAGIC_NUMBER => "OCMBHDR";

# version of the header info
use constant HEADER_VER_MAJOR => 1;
use constant HEADER_VER_MINOR => 0;

# Miscellaneous header size values
use constant HEADER_MAX_SIZE => 4096;
use constant HEADER_MIN_SIZE => 96;
use constant HEADER_BYTES_FOR_LENGTH_FIELD => 24;
use constant HEADER_SHA512_SIZE => 64;

# supported tag values for tagged triplets
use constant TAG_SHA512 => 1;
use constant TAG_KEY_VALUE_PAIRS => 2;

# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_traceLevel = 1;
my $g_progName = File::Basename::basename $0;

# globals populated from command line args
my $g_verify = 0;
my $g_unpackagedBin = "";
my $g_packagedBin = "";
my $g_vendorVersion = "";
my $g_vendorUrl = "";
my $g_timestamp = "";
my $g_verbose = 0;
my $g_help = 0;

# Holds a variable number of tagged triplets <tagId><size><data>
my @g_taggedTriplets;

# Holds a variable number of key/value pairs: "<key string>=<value string>"
my @g_keyValuePairs;

################################################################################
# align(i_alignment, i_number)
################################################################################
sub align
{
    my $i_alignment;
    my $i_number;

    ($i_alignment, $i_number) = @_;
    return(($i_number + ($i_alignment - 1)) & (~($i_alignment - 1)));
}

################################################################################
# createTaggedTriplet(i_tagId, i_data)
################################################################################
sub createTaggedTriplet
{
    my $i_tagId;
    my $i_data;
    my $dataSize;

    ($i_tagId, $i_data) = @_;

    #determine size and align to 8 bytes
    $dataSize = align(8, byteLength($i_data));

    #Output the triplet as <4 byte tag id><4 byte size><zero padded data>
    return (pack("NNa$dataSize", $i_tagId, $dataSize, $i_data));
}

################################################################################
# createKeyValuePair(i_key, i_value)
################################################################################
sub createKeyValuePair
{
    my $i_key;
    my $i_value;
    ($i_key, $i_value) = @_;

    #check for ',' or '=' in the value
    if($i_value =~ m/=|,/)
    {
        traceErr("',' and '=' are not allowed in $i_key string: $i_value");
        exit 1;
    }
    return ("$i_key=$i_value");
}

################################################################################
# byteLength(i_scalar)
################################################################################
sub byteLength
{
    my ($i_scalar) = @_;

    # Switch Perl to byte mode vs char mode.  Only lasts in scope.
    use bytes;
    return (length $i_scalar);
}

################################################################################
# readBytes(i_fileHandle, i_numBytes)
################################################################################
sub readBytes
{
    local $/; #unset the field separator special variable

    my $buffer;
    my $bytesRead;
    my $i_fileHandle;
    my $i_numBytes;
    ($i_fileHandle, $i_numBytes) = @_;

    local $/; #unset the field separator special variable

    #Read i_numBytes
    $bytesRead = read($i_fileHandle, $buffer, $i_numBytes);
    unless($bytesRead && ($bytesRead == $i_numBytes))
    {
        traceErr("Failed to read $i_numBytes. $!");
        exit 1;
    }
    return ($buffer);
}

################################################################################
# dumpTripletData($i_tagId, $i_tripletSize, $i_data)
################################################################################
sub dumpTripletData
{
    my $i_tagId;
    my $i_tripletSize;
    my $i_data;
    ($i_tagId, $i_tripletSize, $i_data) = @_;

    if($i_tagId == TAG_SHA512)
    {
        #convert to a hex string
        my $hexData = unpack("H*", $i_data);
        trace(1, "\nSHA512 hash from header: $hexData");
    }
    elsif($i_tagId == TAG_KEY_VALUE_PAIRS)
    {
        trace(1, "\nKey value pairs from header:");
        my @keyValuePairs = split(",", unpack("Z$i_tripletSize", $i_data));
        foreach (@keyValuePairs)
        {
            trace(1, $_);
        }
    }
    else
    {
        traceErr("Invalid Header: tag id $i_tagId is not supported.");
        exit 1;
    }
}

################################################################################
# verifySHA512()
################################################################################
sub verifySHA512
{
    my $magicNumber;
    my $headerMajor;
    my $headerMinor;
    my $headerSize;
    my $numTriplets;
    my $packagedDataFH;

    trace(1, "\nVerifying SHA512 hash of file \"$g_packagedBin\".");
    unless (-e $g_packagedBin)
    {
        traceErr("File, \"$g_packagedBin\", does not exist.");
        exit 1;
    }

    # open the file as read only, set to binary mode and read in the whole file
    open($packagedDataFH, "<$g_packagedBin")
        or die "Couldn't open file \"$g_packagedBin\", $!";

    #switch to binary mode for this file handle
    binmode $packagedDataFH;
    my $headerData;
    my $bytesRead;
    {
        local $/; #unset the field separator special variable
        $bytesRead = read($packagedDataFH, $headerData,
                          HEADER_BYTES_FOR_LENGTH_FIELD);
    }

    # check that we were able to read something
    unless($bytesRead)
    {
        die "Couldn't read file \"$g_packagedBin\", $!";
    }

    # check that file is large enough to read header size
    if($bytesRead < HEADER_BYTES_FOR_LENGTH_FIELD)
    {
        traceErr("File too small to hold header (size = $bytesRead bytes).");
        exit 1;
    }

    # unpack the data into our scalars
    ($magicNumber,
     $headerMajor,
     $headerMinor,
     $headerSize,
     $numTriplets) = unpack("Z8NNNNN", $headerData);

    # verify the magic number is correct
    unless($magicNumber eq MAGIC_NUMBER)
    {
        traceErr("Invalid Header.  Incorrect magic number: $magicNumber");
        exit 1;
    }

    # check for supported header version
    unless( ($headerMajor == HEADER_VER_MAJOR) &&
            ($headerMinor == HEADER_VER_MINOR))
    {
        traceErr("Header version $headerMajor.$headerMinor not supported.");
        exit 1;
    }

    # check that header size is large enough for at least the SHA512 hash
    # and less than the maximum header size.
    if(($headerSize < HEADER_MIN_SIZE) ||
       ($headerSize > HEADER_MAX_SIZE))
    {
        traceErr("Invalid header size: $headerSize bytes. MIN[".HEADER_MIN_SIZE.") MAX[".HEADER_MAX_SIZE."]");
        exit 1;
    }

    # check that we have at least one triplet
    if($numTriplets < 1)
    {
        traceErr("Invalid header: At least one tagged triplet is required.");
        exit 1;
    }

    # Looks good so far.  Now, read in tagged triplets one at a time.
    my $curTriplet = 0;
    my $headerSHA512 = "";
    while(($curTriplet < $numTriplets) && ($bytesRead < $headerSize))
    {
        my $tagId;
        my $tripletSize;
        my $dataBuffer;

        local $/; #unset the field separator special variable

        #Read in the tagId and data size fields (2 x 4-byte unsigned integers)
        $dataBuffer = readBytes($packagedDataFH, 8);
        $bytesRead += 8;

        ($tagId, $tripletSize) = unpack("NN", $dataBuffer);

        if($tagId == TAG_SHA512)
        {
            # check that we don't already have a SHA512 triplet
            unless($headerSHA512 eq "")
            {
                traceErr("Invalid header: multiple SHA512 hash triplets exist (only one allowed).");
                exit 1;
            }

            # check that data is HEADER_SHA512_SIZE bytes long
            unless($tripletSize == HEADER_SHA512_SIZE)
            {
                traceErr("Invalid header: SHA512 hash only $tripletSize bytes (triplet $curTriplet).");
                exit 1;
            }

            # found the SHA512 data. keep for later comparison.
            $headerSHA512 = readBytes($packagedDataFH, $tripletSize);

            dumpTripletData($tagId, $tripletSize, $headerSHA512);
        }
        else
        {
            # just dump all other triplet data to stdout
            $dataBuffer = readBytes($packagedDataFH, $tripletSize);
            dumpTripletData($tagId, $tripletSize, $dataBuffer);
        }
        $bytesRead += $tripletSize;
        $curTriplet++;
    }

    #advance to end of header and beginning of firmware image
    if($bytesRead < $headerSize)
    {
        readBytes($packagedDataFH, $headerSize - $bytesRead);
    }

    my $firmwareImage;
    #read in the rest of the file for the firmware image contents
    {
        local $/; #unset the field separator special variable
        $firmwareImage = <$packagedDataFH>;
    }

    my $imageSHA512 = sha512($firmwareImage);

    trace(1, "\nSHA512 hash from firmware image: ".unpack("H*", $imageSHA512));

    #Now, compare the two hash values
    if($imageSHA512 eq $headerSHA512)
    {
        trace(1, "\nHeader successfully validated against firmware image.");
    }
    else
    {
        traceErr("Header SHA512 hash does not match firmware image!");
        exit 1;
    }

    exit 0;
}



################################################################################
# traceErr
################################################################################
sub traceErr
{
    my $i_string = shift;
    trace(TRAC_ERR, $i_string);
}

################################################################################
# trace
################################################################################
sub trace
{
    my $i_traceLevel;
    my $i_string;

    ($i_traceLevel, $i_string) = @_;

    #Add error string to error traces
    if($i_traceLevel == TRAC_ERR)
    {
        print "ERROR: ".$i_string."\n";
    }
    elsif ($g_traceLevel >= $i_traceLevel)
    {
        print $i_string."\n";
    }
}

################################################################################
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $g_progName = Add or verify OCMB Firmware Header

  Usage:
    $g_progName --verify
                  --packagedBin <packaged binary file name>
                  [--verbose]
    $g_progName --packagedBin <packaged binary file name>
                  --unpackagedBin <unpackaged binary file name>
                  [--vendorVersion <string>]
                  [--vendorUrl <string>]
                  [--timestamp <string>]
                  [--verbose]

  Parms:
    -h                        Print this help text
    --verify                  Verify the SHA512 hash of a packaged binary file
    --packagedBin <file>      Name of packaged binary file
    --unpackagedBin <file>    Name of unpackaged binary file
    --vendorVersion <string>  Quoted vendor version string
    --vendorUrl <string>      Quoted vendor URL string
    --timestamp <string>      Quoted timestamp string
    --verbose                 Display debug information

ENDUSAGE
}

################################################################################
# main
################################################################################

# check for no parms passed in
if ($#ARGV < 0) {
    usage();
    exit 0;
}

# Parse the commandline arguments
GetOptions("verify" => \$g_verify,
           "packagedBin=s" => \$g_packagedBin,
           "unpackagedBin=s" => \$g_unpackagedBin,
           "vendorVersion=s" => \$g_vendorVersion,
           "vendorUrl=s" => \$g_vendorUrl,
           "timestamp=s" => \$g_timestamp,
           "verbose" => \$g_verbose,
           "help" => \$g_help);

if ($g_verbose)
{
    $g_traceLevel = 10;
}

if ($g_help)
{
    usage();
    exit 0;
}

# Check that --packagedBin option was specified
if ($g_packagedBin eq "")
{
    traceErr("Must specify --packagedBin <file> option.");
    exit 1;
}

# Check if we're just verifying an already packaged binary
if ($g_verify)
{
    #this function does not return
    verifySHA512();
}

# We're not verifying an already packaged binary so we must be packaging a
# new binary.  Check that an unpackaged file name was provided.
if ($g_unpackagedBin eq "")
{
    traceErr("Must specify --unpackagedBin <file> option.");
    exit 1;
}

# Check that the unpackaged file exists
unless (-e $g_unpackagedBin)
{
    traceErr("File \"$g_unpackagedBin\" does not exist.");
    exit 1;
}

# open the file as read only, set to binary mode and read in the whole file
open(UNPACKAGED_DATA, "<$g_unpackagedBin")
    or die "Couldn't open file \"$g_unpackagedBin\", $!";
binmode UNPACKAGED_DATA;
my $unpackagedData;
{
    local $/; #unset the field separator special variable
    $unpackagedData = <UNPACKAGED_DATA>; #reads in entire file
}

# Generate sha512 hash of unpackaged file data
my $sha512_hash = sha512($unpackagedData);

# Generate the sha512 tagged triplet and add it to our list of tagged triplets
push (@g_taggedTriplets, createTaggedTriplet(TAG_SHA512, $sha512_hash));

# Check for the vendorVersion parameter
unless($g_vendorVersion eq "")
{
    #add it to the keyValuePairs list
    push(@g_keyValuePairs, createKeyValuePair("version", $g_vendorVersion));
}

# Check for timestamp parameter
unless($g_timestamp eq "")
{
    #add it to the keyValuePairs list
    push(@g_keyValuePairs, createKeyValuePair("timestamp", $g_timestamp));
}

# Check for the vendorUrl parameter
unless($g_vendorUrl eq "")
{
    #add it to the keyValuePairs list
    push(@g_keyValuePairs, createKeyValuePair("url", $g_vendorUrl));
}

trace(10, "numKeyValuePairs=" . scalar @g_keyValuePairs);

# Check if we have any key/value pairs
if(scalar @g_keyValuePairs > 0)
{
    # Generate key value pair tagged triplet and add it to the list of
    # tagged triplets
    push(@g_taggedTriplets,
         createTaggedTriplet(TAG_KEY_VALUE_PAIRS, join(',', @g_keyValuePairs)));
}

my $numTriplets = scalar @g_taggedTriplets;

trace(10, "numTriplets=$numTriplets");

# join all tagged triplets together in a single string
my $variableHeaderData = join("", @g_taggedTriplets);

# Create header
my $fixedHeaderData = pack("Z8NN", MAGIC_NUMBER,
                                   HEADER_VER_MAJOR,
                                   HEADER_VER_MINOR,
                                   );

trace(10, "variableHeaderSize=".(byteLength($variableHeaderData)));

# determine total size of header (add 8 bytes for numTriplets and
# headerSize fields)
my $headerSize = align(8, (byteLength($variableHeaderData) +
                           byteLength($fixedHeaderData) + 8));

# Make sure we don't go over the max header size limit
if($headerSize > HEADER_MAX_SIZE)
{
    traceErr("Header size of $headerSize bytes is too big.");
    exit 1;
}

# create header
my $headerData = join("", $fixedHeaderData,
                          pack("NN", $headerSize, $numTriplets),
                          $variableHeaderData);


# add null padding to end if needed
my $paddedHeaderData = pack("a$headerSize", $headerData);

# write header data to output file
open(PACKAGED_DATA, ">$g_packagedBin")
    or die "Couldn't open file \"$g_packagedBin\", $!";
binmode PACKAGED_DATA;
print PACKAGED_DATA $paddedHeaderData;

# write image data to output file
print PACKAGED_DATA $unpackagedData;
close PACKAGED_DATA;

trace(1, "\nOCMB firmware header succesfully added to \"$g_packagedBin\".");

exit 0;
