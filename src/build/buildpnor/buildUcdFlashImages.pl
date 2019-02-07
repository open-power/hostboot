#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildUcdFlashImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2019
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
use File::Basename;
use Getopt::Long;
use Pod::Usage;

# These must be kept in sync with Hostboot source code
use constant IMG_TYPE_DATA_FLASH => 0;
use constant MAX_DEVICE_ID_ASCII => 31;
use constant NULL_SIZE => 1;
use constant EYECATCH_SIZE => 8;
use constant EYECATCH => "UCDFLSH";

# These can be arbitrarily changed if needed
use constant TOC_ALIGNMENT => 0x80;
use constant TOC_ENTRY_SIZE => 0x40;
use constant FLASH_IMAGES_OFFSET => 0x1000;
use constant FLASH_IMAGE_ALIGNMENT => 0x1000;
use constant TOC_MAJOR => 0x00000001;
use constant TOC_MINOR => 0x00000000;

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key traces.
my $g_trace = 1;

my $progName = File::Basename::basename $0;
my $outputFile="ucd-flash.bin";
my $outputDir=".";
my @files;
my $cfgHelp=0;
my $cfgMan=0;
my $verbose=0;

GetOptions("output-file=s" => \$outputFile,
           "output-dir=s" => \$outputDir,
           "image=s" => \@files,
           "help" => \$cfgHelp,
           "verbose" => \$verbose,
           "man" => \$cfgMan ) || pod2usage(-verbose => 0);

pod2usage(-verbose => 1) if $cfgHelp;
pod2usage(-verbose => 2) if $cfgMan;

if (keys %{{ map {$_, 1} @files }} != @files)
{
    die "One or more non-unique --image arguments supplied";
}

if($verbose)
{
    print "Output file = $outputFile\n";
    print "Output dir = $outputDir\n";
    print "Input images:\n";
    for my $file (@files)
    {
        print "    $file\n";
    }
}

my %flashImages;
for my $file (@files)
{
    processInputFile($file,$outputDir,\%flashImages);
}

my $rc = genOutputImage($outputDir,$outputFile,\%flashImages);
if($rc != 0)
{
    trace(0, "$progName: Error detected from call to genOutputImage(). "
        . " Exiting");
    exit $rc;
}

################################################################################
# @brief Upward aligns the input value to the requested boundary
#
# @param[in] i_value The value to align
# @param[in] i_boundary The boundary to align to
#
# @return The input value, aligned to the requested boundary
################################################################################

sub alignto
{
    my $i_value = shift;
    my $i_boundary = shift;

    return  ((($i_value) + (($i_boundary)-1)) & ~(($i_boundary)-1));
}

################################################################################
# @brief Processes an input file to pull information from its name and content
#     to be used when preparing the output file's TOC.  Also strips out
#     unneeded content  (like comments) and writes the remainder to an
#     intermediate file with .stripped extension, which will be fed into
#     the data portion of the final output file.
#
# @param[in] i_fileName Name of file
# @param[in] i_outputDir Dir to emit intermediate file to
# @param[in] i_flashImages Hash where TOC information will be recorded
#
# @return N/A
################################################################################

sub processInputFile
{
    my ($i_fileName, $i_outputDir, $i_flashImages) = @_;
    my $this_func = (caller(0))[3];

    my ($name,$path,$suffix) = fileparse($i_fileName);

    # Enforce the input file naming convention
    if($name !~
        /\AUCD[[:alnum:]]+\-data\-pu[0-3]_e[0-3]_p(0?[0-9]|1[0-2])_a[[:xdigit:]]{2}\.csv\Z/)
    {
        die "Unexpected file name ($i_fileName); must be in the format: "
            . "UCDV-data-puW_eX_pY_aZZ.csv, where V is a UCD device ID, "
            . "W=proc position (0-3), "
            . "X=engine # (0-3), Y=port (0-9 or 00-09 or 10-12), "
            . "ZZ=hex address (00->FF)";
    }

    # Break the file name into the device ID. update type, i2c info, and the csv
    # extension.  The extension will be discarded.
    my ($base,$csv) = split(/\./,$name);
    my ($deviceId,$imageType,$i2cInfo) = split (/-/,$base );

    if(length $deviceId > MAX_DEVICE_ID_ASCII )
    {
        die "Device ID of $deviceId was > " . MAX_DEVICE_ID_ASCII
            . " characters";
    }

    if(    $deviceId ne "UCD9090"
       and $deviceId ne "UCD90120A")
    {
        die "Unsupported UCD device $deviceId";
    }

    if($imageType ne "data")
    {
        die "Only data flash images supported (not $imageType type)";
    }

    # Extract the MFR_REVISION out of the file
    my $mfrRevision=undef;
    open my $fh, '<:encoding(UTF-8)', $i_fileName
        or die "Failed to open $i_fileName";
    my $optimizedFile = $i_outputDir . "/" . $name . ".stripped";
    open my $ofh, '>:encoding(UTF-8)', $optimizedFile
        or die "Failed to open $optimizedFile";

    while (my $line = <$fh>)
    {
        # Match below string (but allow any trailing number):
        # Comment,Write MFR_REVISION 02
        if($line =~ /\AComment,Write MFR_REVISION [[:xdigit:]]{2}\s*\Z/)
        {
            if(!defined $mfrRevision)
            {
                $mfrRevision = $line;
                $mfrRevision =~ s/\AComment,Write MFR_REVISION //;
            }
            else
            {
                die "Duplicate MFR_REVISION lines detected in $i_fileName";
            }
        }

        # Copy the input to the output, except for comment lines
        if($line !~ /\AComment/)
        {
            print $ofh $line;
        }
    }
    close $fh or die "Failed to close input file: $i_fileName";
    close $ofh or die "Failed to close optimized ouput file: $optimizedFile";

    if(!defined $mfrRevision)
    {
        die "Could not determine MFR_REVISION from $i_fileName";
    }

    # Strip the prefixing identifiers off the i2c info
    my ($i2cProc,$i2cEngine,$i2cPort,$i2cAddress) = split /_/,$i2cInfo;
    $i2cProc =~s/\Apu//;
    $i2cEngine =~s/\Ae//;
    $i2cPort =~s/\Ap//;
    $i2cAddress =~s/\Aa//;

    $$i_flashImages{$i_fileName}{deviceId}      = $deviceId;
    $$i_flashImages{$i_fileName}{imageType}     = IMG_TYPE_DATA_FLASH;
    $$i_flashImages{$i_fileName}{i2cProc}       = $i2cProc;
    $$i_flashImages{$i_fileName}{i2cEngine}     = $i2cEngine;
    $$i_flashImages{$i_fileName}{i2cPort}       = $i2cPort;
    $$i_flashImages{$i_fileName}{i2cAddress}    = $i2cAddress;
    $$i_flashImages{$i_fileName}{mfrRevision}   = $mfrRevision;
    $$i_flashImages{$i_fileName}{optimizedFile} = $optimizedFile;

    trace(10, "$this_func: File: $i_fileName, Device ID: $deviceId, "
        . "Image type: " . IMG_TYPE_DATA_FLASH
        . " Master proc ID: $i2cProc, I2C engine: $i2cEngine, "
        . "I2C port: $i2cPort, I2C address: $i2cAddress, "
        . "MFR_REVISION: $mfrRevision, Optimized file: $optimizedFile");

    # No return code
}

################################################################################
# @brief Builds the final UCD flash image file
#
# @param[in] i_outputDir   Directory to generate the output in
# @param[in] i_outputFile  Name of file to generate the output in
# @param[in] i_flashImages Reference to hash containing flash image information
#
# @return Return code indicating success or failure
# @retval 0  Successfully generated intended output image
# @retval !0 Failed to generate intended output image
################################################################################

sub genOutputImage
{
    my ($i_outputDir,$i_outputFile,$i_flashImages) = @_;
    my $this_func = (caller(0))[3];
    trace(4, "$this_func: >>Enter");

    my $rc = 0;
    my $curOffset = FLASH_IMAGES_OFFSET;

    # Open output file
    my $outputPath = $i_outputDir . "/" . $i_outputFile;
    my $OFH;
    open( $OFH, ">:raw", $outputPath)
        or die "Can't open $outputPath for writing";

    # Build the header and table of contents (TOC)

    # TOC header format:
    #
    # char[8]   Eyecatcher "UCDFLSH" + NULL
    # uint32_t  TOC major version; Increment if change will break existing code
    # uint32_t  TOC minor version; Increment if change won't break existing code
    # uint32_t  Number of flash image TOC entries
    # uint32_t  Size of each TOC entry
    # uint32_t  Offset to 0th TOC entry from start of file
    # char[X]   Pad to start of N TOC entries
    #
    # TOC entry format:
    #
    # char[32]  Device ID "UCD9090" or "UCD90120A" + NULL.  Max 31 non-null
    #               chars left justified.  Others could be supported in future.
    # uint8_t   Flash image type (0=data flash image, others reserved)
    # uint8_t   Processor position (pu value of ECMD string)
    # uint8_t   I2C engine
    # uint8_t   I2C port
    # uint8_t   I2C address
    # uint8_t   Pad byte
    # uint16_t  MFR_REVISION (2 bytes ASCII, i.e. "02" = 0x30 0x32)
    # uint32_t  Offset to flash image from start of file
    # uint32_t  Flash image size
    # char[16]  Pad to TOC entry size (align next TOC entry @ 16 byte boundary)
    #
    # Flash images start at 4k and are 4k aligned

    my %flashImageOffsets;

    my $header = pack("Z" . EYECATCH_SIZE, EYECATCH);

    # uint32_t: major, uint32_t: minor
    $header .= pack('N', TOC_MAJOR);
    $header .= pack('N', TOC_MINOR);

    # Write # of flash images
    my $flashImages = keys %{$i_flashImages};
    $header .= pack('N', $flashImages);

    # Write size of TOC entry
    $header .= pack('N', TOC_ENTRY_SIZE);

    # Write offset to 0th TOC entry
    my $usedHeaderLength = length($header) + 4;
    my $offsetToToc = alignto($usedHeaderLength,TOC_ALIGNMENT);
    $header .= pack('N', $offsetToToc);

    # Write pads in front of TOC entries
    my $endOfHeaderPads = $offsetToToc - length $header;
    $header .= pack("C$endOfHeaderPads");

    my $contentSansImages = $header;

    #Insert TOC entry for each flash image
    for my $key (keys %{$i_flashImages})
    {
        trace(2, "$this_func: Inserting header for $key");

        # Write device ID
        my $maxSize = MAX_DEVICE_ID_ASCII + NULL_SIZE;
        my $tocEntry .= pack("Z" . $maxSize, $$i_flashImages{$key}{deviceId});

        # Write flash image type
        $tocEntry .= pack('C', $$i_flashImages{$key}{imageType});

        # Write I2C information
        $tocEntry .= pack('C', $$i_flashImages{$key}{i2cProc});
        $tocEntry .= pack('C', $$i_flashImages{$key}{i2cEngine});
        $tocEntry .= pack('C', $$i_flashImages{$key}{i2cPort});
        $tocEntry .= pack('H*', $$i_flashImages{$key}{i2cAddress});

        # Write single pad byte
        $tocEntry .= pack('C1');

        # Write MFR_REVISION
        $tocEntry .= pack('A2', $$i_flashImages{$key}{mfrRevision});

        # Write offset to flash image (from start of file)
        $tocEntry .= pack('N', $curOffset);

        # Write size of flash image
        my $fileSize = -s $$i_flashImages{$key}{optimizedFile};
        if(!defined $fileSize)
        {
            die "Failed reading file size for "
                . "$$i_flashImages{$key}{optimizedFile}  ";
        }
        $tocEntry .= pack('N', $fileSize);

        # Pad remainder of TOC entry to the alignment boundary
        my $endOfTocEntryPads = alignto(length($tocEntry),
                                        TOC_ENTRY_SIZE) - length($tocEntry);
        $tocEntry .= pack("C$endOfTocEntryPads");

        # Verify we didn't exceed the TOC entry size
        my $len = length $tocEntry;
        if($len > TOC_ENTRY_SIZE)
        {
            die "TOC entry size ($len) exceeds max allowable size of "
                . TOC_ENTRY_SIZE;
        }

        # Save the flash image insertion offset
        $flashImageOffsets{$key} = $curOffset;

        # Determine next nearest flash image alignment boundary
        $curOffset += $fileSize;
        $curOffset = alignto($curOffset,FLASH_IMAGE_ALIGNMENT);

        $contentSansImages .= $tocEntry;
    }

    # Make sure we didn't bleed into flash content area
    my $contentSansImagesSize = length $contentSansImages;
    if($contentSansImagesSize > FLASH_IMAGES_OFFSET)
    {
        die   "Header and TOC (length=$contentSansImagesSize) "
            . "overruns flash image content starting at "
            . FLASH_IMAGES_OFFSET;
    }

    # Write the header and TOC
    print $OFH $contentSansImages
        or die "Failed to serialize header and TOC to $outputPath";

    close $OFH or die "Failed to close $outputPath";

    #Insert actual image for each flash image provided
    for my $key (keys %{$i_flashImages})
    {
        trace(2, "$this_func: Inserting flash image $key, "
            . "offset=$flashImageOffsets{$key}");

        my $seekOffset = $flashImageOffsets{$key};
        my $inFile = $$i_flashImages{$key}{optimizedFile};

        my $ddCmd = "dd if=$inFile of=$outputPath bs=1 seek=$seekOffset";
        system ( $ddCmd ) == 0 or die "Couldn't Write $inFile to $outputPath!";
    }

    trace(4, "$this_func: <<Exit");

    return $rc;
}

################################################################################
# traceErr
################################################################################

sub traceErr
{
    my $i_string = shift;
    trace($TRAC_ERR, $i_string);
}

################################################################################
# trace
################################################################################

sub trace
{
    my ($i_traceLevel, $i_string) = @_;

    # traceLevel 0 is for errors
    if($i_traceLevel == 0)
    {
        print "ERROR: ".$i_string."\n";
    }
    elsif ($g_trace >= $i_traceLevel)
    {
        print "TRACE: ".$i_string."\n";
    }
}

__END__

=head1 NAME

buildUcdFlashImage.pl

=head1 SYNOPSIS

buildUcdFlashImage.pl [..]

=head1 OPTIONS

=over 8

=item B<--help>

Prints a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--output-file>

File containing an aggregation of UCD device flash images prefixed by a table
of contents.

=item B<--output-dir>

Path to directory to emit the output files to.

=item B<--image>

File containing a UCD flash update script.  More than one --image
argument can be provided.  If no images are supplied, the output file will
consist of a TOC indicating no valid flash images.

=back

=head1 DESCRIPTION

B<buildUcdFlashImage.pl> will process a set of one or more UCD flash update
scripts in .csv format, strip out the comments, aggregate them together, and
prefix the aggregate with a table of contents.  UCD devices allow flash updates
both data and program flash, however currently firmware only supports updating
UCD data flash.

=cut

