#!/usr/local/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/eecache_editor.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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
use File::Copy;
use File::Basename;


binmode STDOUT, ':bytes';

my $pnorBinaryPath = "";
my $eecacheBinaryPath = "";
my $newImagePath = "";
my $outFilePath = "./eecache_editor_output.dat";
my $masterHuid = 0;
my $port = 0;
my $engine = 0;
my $devAddr = 0;
my $muxHuid = 0;
my $muxSelect = 0xFF;
my $eepromSize = 0;
my $usage = 0;
my $uniqueId = "";
my $verbose = 0;
my $onlyValid = 0;
my $clearEepromData = 0;
my $overwrite = 0;
my $summary = 0;
my $devOffsetKB = 0xFFFF; # initialized to invalid offset
my $appendSpiEntry = 0;   # Flag passed in CLI argument to specify that a new SPI
                          # bus type cache entry will be appended to EECACHE
my $appendI2cEntry = 0;   # Flag passed in CLI argument to specify that a new I2C
                          # bus type cache entry will be appended to EECACHE
my $cacheIsValid = 0;     # Passed as an argument only when cache entry in
                          # $newImagePath is considred valid
my $masterInEeprom = 0;   # Passed as an argument only when cache entry in
                          # $newImagePath is master in EEPROM it comes from
my $cacheSizeKB = 0;      # Expected size of cache in EECACHE

# Goals of this tool:
#
# ** Handle both entire PNOR image as well as single EECACHE section as input **
#
# 1) Given masterHuid, port, engine, devAddr, muxSelect lookup cached EEPROM value and replace
#    it with a given binary file. (File size must be <= allocated space)
#
# 2) Given a binary pnor/eecache. Print summary of cached eeproms
#
# 3) Zero out a given cached eeprom
#
# 4) Extract the contents for a given masterHuid, port, engine, devAddr, muxSelect
#
# 5) Replace cache data for a given entry
#
# 6) Append new cache data entries

# Note: *_NUM_ENTRIES count comes from src/include/usr/eeprom/eeprom_const.H
use constant VERSION_1_TOC_ENTRY_SIZE_BYTES => 17;
use constant VERSION_1_TOC_ENTRY_SIZE_BITS => (VERSION_1_TOC_ENTRY_SIZE_BYTES * 8) ;
use constant VERSION_1_NUM_ENTRIES => 50;
use constant VERSION_1_TOC_SIZE => (VERSION_1_TOC_ENTRY_SIZE_BYTES * VERSION_1_NUM_ENTRIES) + 5;

use constant VERSION_2_TOC_ENTRY_SIZE_BYTES => 18;
use constant VERSION_2_TOC_ENTRY_SIZE_BITS => (VERSION_2_TOC_ENTRY_SIZE_BYTES * 8) ;
use constant VERSION_2_NUM_ENTRIES => 100;
use constant VERSION_2_TOC_SIZE => (VERSION_2_TOC_ENTRY_SIZE_BYTES * VERSION_2_NUM_ENTRIES) + 5;

use constant VERSION_LATEST => 2;

use constant EEPROM_ACCESS_I2C => 1;
use constant EEPROM_ACCESS_SPI => 2;



my $eecacheVersion = VERSION_LATEST;

GetOptions("pnor:s"         => \$pnorBinaryPath,
           "eecache:s"      => \$eecacheBinaryPath,
           "newImage:s"     => \$newImagePath,
           "newFile:s"      => \$newImagePath,
           "out:s"          => \$outFilePath,
           "of:s"           => \$outFilePath,
           "masterHuid:o"   => \$masterHuid,
           "port:o"         => \$port,
           "engine:o"       => \$engine,
           "devAddr:o"      => \$devAddr,
           "muxSelect:o"    => \$muxSelect,
           "eepromSize:o"   => \$eepromSize,
           "uniqueId:s"     => \$uniqueId,
           "devOffsetKB:o"  => \$devOffsetKB,
           "version:o"      => \$eecacheVersion,
           "onlyValid"      => \$onlyValid,
           "overwrite"      => \$overwrite,
           "clear"          => \$clearEepromData,
           "verbose"        => \$verbose,
           "usage"          => \$usage,
           "help"           => \$usage,
           "appendSpiEntry" => \$appendSpiEntry,
           "appendI2cEntry" => \$appendI2cEntry,
           "cacheIsValid"   => \$cacheIsValid,
           "masterInEeprom" => \$masterInEeprom,
           "cacheSizeKB:o"  => \$cacheSizeKB,
           "h"              => \$usage);

sub print_help()
{
    print "--------- EECACHE Editor Tool V 2.0 ---------\n";
    print "\n";
    print "Mandatory:\n\n";

    print "   --eecache     Path to ECC-less eeprom cache section of PNOR  (IE : EECACHE.bin )\n\n";

    print "Optional:\n\n";

    print "   --clear       If a matching eeprom is found, clear out its contents\n";
    print "   --devAddr     Device address of desired EEPROM\n";
    print "   --devOffsetKB Offset (KB) of where record begins in eeprom for SPI access\n";
    print "   --engine      Engine of I2C/SPI Master desired EEPROM exists on\n";
    print "   --masterHuid  HUID of the I2C/SPI Master Target\n";
    print "   --muxSelect   Mux Select (if needed) defaults to 0xFF \n";
    print "   --onlyValid   If printing summary, only print valid eeprom caches\n";
    print "   --out         Full path to desired out file, if not provided defaults to ./eecache_editor_output.dat\n";
    print "   --port        Port of I2C Master desired EEPROM exists on\n";
    print "   --uniqueId    Combination of unique I2C Slave information, alternative to passing\n";
    print "                 information in 1 thing at a time\n";
    print "   --version     Version of eecache (default to latest if this isn't provided)\n";
    print "   --verbose     Print extra information \n";
    print "   --help        Print this information  \n";
    print "\n ";
    print "Examples: \n\n";
    print "  # prints out info about all eeproms in EECACHE.bin\n";
    print "  eecache_editor.pl --eecache EECACHE.bin\n";
    print "\n";
    print "  # To replace a section using --uniqueId, you can first look at your cache \"eecache_editor.pl --eecache EECACHE.bin\"\n";
    print "  # and find the section that you want to replace, you'll use \"unique ID\" entry\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --uniqueId 0x020005000003010000 --newImage newSPD.dat\n";
    print "\n";
    print "  # (I2C) lookup eeprom matching input params and write contents of that EEPROM's cached data to outfile \n";
    print "  eecache_editor.pl --eecache EECACHE.bin --version 1 --port 0 --engine 3 --muxSelect 8 --devAddr 0xa0 --masterHuid 0x50000\n";
    print "\n";
    print "  # (I2C) lookup eeprom matching input params and clear the contents ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --port 0 --engine 3 --muxSelect 8 --devAddr 0xa0 --masterHuid 0x50000 --clear\n";
    print "\n";
    print "  # (I2C) lookup eeprom matching input params and write new image's contents to offset in EECACHE where matching eeprom data exists ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --port 0 --engine 3 --muxSelect 8 --devAddr 0xa0 --masterHuid 0x50000 --newImage newSPD.dat\n";
    print "\n";
    print "  # (SPI) lookup eeprom matching input params and write contents of that EEPROM's cached data to outfile \n";
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffsetKB 0xc0 --masterHuid 0x50000\n";
    print "\n";
    print "  # (SPI) lookup eeprom matching input params and clear the contents ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffsetKB 0xc0 --masterHuid 0x50000 --clear\n";
    print "\n";
    print "  # (SPI) lookup eeprom matching input params and write new image's contents to offset in EECACHE where matching eeprom data exists ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffsetKB 0xc0 --masterHuid 0x50000 --newImage newSPD.dat\n";
    print "\n";
    print "  # Append new Cache entries:\n";
    print "\n";
    print "  # (SPI) Append cache entry into EECACHE.bin\n";
    print "  eecache_editor.pl --appendSpiEntry --eecache EECACHE.bin --engine 3 --devOffsetKB 0xc0 --masterHuid 0x50000 --cacheSizeKB 0x0a0 --newImage newSPD.dat\n";
    print "  # (I2C) Append cache entry into EECACHE.bin\n";
    print "  eecache_editor.pl --appendI2cEntry --eecache EECACHE.bin --masterHuid 0x50000 --port 0 --engine 3 --devAddr 0xa0 --muxSelect 8 --cacheSizeKB 0x0a0 --newImage newSPD.dat\n";
    print "  # If the cache being appended is considered valid and/or the master one, you'll need to also include --cacheIsValid and/or --masterInEeprom, e.g.:\n";
    print "  eecache_editor.pl --appendSpiEntry --eecache EECACHE.bin --engine 3 --devOffsetKB 0xc0 --masterHuid 0x50000 --cacheSizeKB 0xa0 --newImage newSPD.dat --cacheIsValid --masterInEeprom\n";
    print "\n";
    print "---------------------------------------------\n";
}

if( $usage )
{
    print_help();
    exit 0;
}

# Info
# Structs Used for Different Header Versions

# Struct for Header Version 1
#
# p9 support, in src/include/usr/i2c/eeprom_const.H
#
# struct completeRecord
# {
#     uint32_t i2c_master_huid;   // HUID of i2c Master
#     uint8_t  port;              // I2C Port
#     uint8_t  engine;            // I2C Engine
#     uint8_t  devAddr;           // I2C Device Address
#     uint8_t  mux_select;        // Some I2C devices are behind a mux, this says
#                                 // what setting on the mux is required
#     uint32_t cache_copy_size;   // Size of data saved in cache (in KB)
#     uint32_t internal_offset;   // offset from start of EECACHE section where cached
#                                 // data exists
#     uint8_t  cached_copy_valid : 1,   // This bit is set when we think the contents of the
#                                       // cache is valid.
#              unused            : 7;
#
# } PACKED completeRecord;
#
# struct uniqueRecord
# {
#     uint8_t uniqueID [NUM_BYTE_UNIQUE_ID];
#     uint8_t metaData [sizeof(completeRecord) - NUM_BYTE_UNIQUE_ID];
# } PACKED uniqueRecord;

# Struct for Header Version 2
#
# master-p10 src/include/usr/eeprom/eeprom_const.H
#
# struct completeRecord
# {
#    EepromHwAccessMethodType accessType;  // how to access record
#    union eepromAccess_t
#    {
#        struct i2cAccess_t
#        {
#            uint32_t i2c_master_huid;   // HUID of i2c Master
#            uint8_t  port;              // I2C Port
#            uint8_t  engine;            // I2C Engine
#            uint8_t  devAddr;           // I2C Device Address
#            uint8_t  mux_select;        // Some I2C devices are behind a mux, this says
#                                        // what setting on the mux is required
#        } PACKED i2cAccess;
#        struct spiAccess_t
#        {
#            uint32_t spi_master_huid;  // HUID of SPI master
#            uint8_t  engine;           // engine specific to eeprom
#            uint16_t offset_KB;        // offset in KB of where record begins in eeprom
#        } PACKED spiAccess;
#    } PACKED eepromAccess;
#    uint32_t cache_copy_size;   // Size of data saved in cache (in KB)
#    uint32_t internal_offset;   // offset from start of EECACHE section where cached
#                                // data exists
#    uint8_t  cached_copy_valid : 1,   // This bit is set when we think the contents of the
#                                      // cache is valid.
#    master_eeprom              : 1,   // This bit marks this record as the master one (i.e. look at this one for change)
#    unused                     : 6;

# } PACKED completeRecord;

# struct uniqueRecord
# {
#    uint8_t uniqueID [NUM_BYTE_UNIQUE_ID];
#    uint8_t metaData [sizeof(completeRecord) - NUM_BYTE_UNIQUE_ID];
# } PACKED uniqueRecord;



if( ($pnorBinaryPath eq "") &&
    ($eecacheBinaryPath eq ""))
{
    # Print error saying we need one of these filled in
    print "ERROR: Neither PNOR binary nor EECACHE section binary passed in. Cannot continue.\n\n";
    print_help();
    exit 0;
}

# if PNOR is not empty, ignore eecacheBinary , we will
# output a full updated pnor since we were provided a pnor.
# but if no pnor is provided , we will just return and EECACHE sections
my $inputIsEntirePnor = 0;
if( $pnorBinaryPath ne "")
{
    $inputIsEntirePnor = 1;
}

if ($eecacheVersion > VERSION_LATEST)
{
    print "ERROR: --version $eecacheVersion is greater than max ".VERSION_LATEST."\n\n";
    print_help();
    exit 0;
}

if ($uniqueId eq "")
{
    if ($eecacheVersion == VERSION_LATEST)
    {
        # devOffsetKB is specific to SPI access so check to see if it is valid
        if ($devOffsetKB != 0xFFFF)
        {
            $uniqueId  = sprintf ("%.02X", EEPROM_ACCESS_SPI);
            $uniqueId .= sprintf ("%.08X", $masterHuid);
            $uniqueId .= sprintf ("%.02X", $engine);
            $uniqueId .= sprintf ("%.04X", $devOffsetKB);
            $uniqueId .= "00"; # blank byte
        }
        else
        {
            $uniqueId  = sprintf ("%.02X", EEPROM_ACCESS_I2C);
            $uniqueId .= sprintf ("%.08X", $masterHuid);
            $uniqueId .= sprintf ("%.02X", $port);
            $uniqueId .= sprintf ("%.02X", $engine);
            $uniqueId .= sprintf ("%.02X", $devAddr);
            $uniqueId .= sprintf ("%.02X", $muxSelect);
        }
    }
    elsif ($eecacheVersion == 1)
    {
        $uniqueId .= sprintf ("%.08X", $masterHuid);
        $uniqueId .= sprintf ("%.02X", $port);
        $uniqueId .= sprintf ("%.02X", $engine);
        $uniqueId .= sprintf ("%.02X", $devAddr);
        $uniqueId .= sprintf ("%.02X", $muxSelect);
    }
}

my $displayOnly = 0;

unless (isUniqueIdValid($uniqueId))
{
    if( $clearEepromData )
    {
        print_help();
        print "\n ERROR: Detecting that user is trying to --clear data without providing what info on what eeprom to clear. Exiting. \n\n";
        exit 0;
    }
    $displayOnly = 1;
    $verbose = 1;
}
else
{
    print "\nUnique ID we are looking up: 0x$uniqueId \n\n" ;
}

# setup input and output file handles
my $input_fh;
my $output_fh;

if($inputIsEntirePnor)
{
    open $input_fh, '<', $pnorBinaryPath or die "failed to open $pnorBinaryPath: $!\n";
    if($overwrite)
    {
        open $output_fh, '>', $pnorBinaryPath or die "failed to open $pnorBinaryPath: $!\n";
    }
    else
    {
        open $output_fh, '>', $outFilePath or die "failed to open $outFilePath: $!\n";
    }
}
else
{
    open $input_fh, '+<:raw', $eecacheBinaryPath or die "failed to open $eecacheBinaryPath: $!\n";
    if($overwrite)
    {
        open $output_fh, '+<:raw', $eecacheBinaryPath or die "failed to open $eecacheBinaryPath: $!\n";
    }
    else
    {
        open $output_fh, '+>:raw', $outFilePath or die "failed to open $outFilePath: $!\n";
        copy($eecacheBinaryPath, $outFilePath) ;
    }
}


# When not appending a new cache entry by using $appendSpiEntry or $appendI2cEntry, then
# at this point we should know what we are trying to accomplish :
#
# IF ($displayOnly != 0) THEN we will only print a summary
#
# ELSE IF ($newImagePath != "") THEN we will write new contents if matching section found
#
# ELSE IF ($clear != 0) THEN clear the contents if matching section found
#
# ELSE if matching section found, then write contents to outfile



# TODO handle entire PNOR
if($inputIsEntirePnor)
{
    #find EECACHE offset , seek to there
}
else
{
    # Parse the larger binary blob to get just the Table of Contents
    my $eecacheTOC = readEecacheToc($input_fh);

    # The hashRef you key back has members: offset and size
    # This represents offset and size of eeprom data in given
    # binary.
    my $hashRef = parseEecacheToc($eecacheTOC, $uniqueId);

    # if we are doing displayOnly then we are done, we can skip the following logic
    if(!$displayOnly)
    {

        # Append new cache entry to EECACHE
        if ($appendSpiEntry || $appendI2cEntry)
        {
            appendNewEntryWithData();
        }
        # If the offset is 0, then no match was found
        elsif($hashRef->{'entry_offset'} != 0)
        {
            if($newImagePath ne "") # if a new image is available try to load it in
            {
                # Pad new cache file if needed
                my $inputImgPath = padFileIfNeeded($newImagePath, $hashRef->{'entry_size'});

                # Open and read input img file to work with
                my $inputImgSize = -s $inputImgPath;
                my $imgOffset = hex $hashRef->{'entry_offset'};

                my $inputImgHandle;
                open $inputImgHandle, '<', $inputImgPath or die "failed to open $inputImgPath: $!\n";

                my $newFileData;
                read($inputImgHandle, $newFileData, $inputImgSize);

                print("Inserting img: $inputImgPath\n");
                print("Of size: $inputImgSize\n");
                print("At entry offset: $imgOffset\n");

                # seek to the offset inside EEACHE where this eeprom's cache
                # lives and write the new file contents
                seek($output_fh, $imgOffset , 0);
                print $output_fh $newFileData;

                close $inputImgHandle;
            }
            elsif($clearEepromData) # if we are told to clear the data do that
            {
                print "Attempting Clearing starting at $hashRef->{'entry_offset'} $hashRef->{'header_offset'}!!!!!!!!\n";
                my $byteOfOnes = pack("H2", "FF") ;
                my $byteOfZeroes = pack("H2", "00") ;
                seek($output_fh, $hashRef->{'entry_offset'} , 0);
                for(my $i = 0; $i < $hashRef->{'entry_size'}; $i++)
                {
                    print $output_fh $byteOfOnes;
                }

        #       seek($output_fh, $hashRef->{'header_offset'} + 16, 0);
        #       print $output_fh  $byteOfZeroes;
            }
            else
            {
                seek($input_fh, $hashRef->{'entry_offset'} , 0);
                my $cur_pos = tell $input_fh;
                print "reading $hashRef->{'entry_size'} from $cur_pos\n ";
                my $cachedData;
                read($input_fh, $cachedData, $hashRef->{'entry_size'});
                print $output_fh $cachedData;
            }
        }
    }
}

close $input_fh;
close $output_fh;

# End of Main
exit 0;



# Subroutines

sub readEecacheToc {
    my $eecache_fh = shift;

    # Get starting position of read pointer before reading
    my $start_location = tell $eecache_fh;

    my $eecache_toc_version = 0;

    read($eecache_fh, $eecache_toc_version, 1) == 1 or die "failed to read single byte from eecache file handle";
    $eecache_toc_version = unpack 'C', $eecache_toc_version;

    my $eecache_toc;

    if( $eecache_toc_version == 1 )
    {
        seek($eecache_fh, $start_location, 0);
        read($eecache_fh, $eecache_toc, VERSION_1_TOC_SIZE) or die "failed to read ".VERSION_1_TOC_SIZE." bytes from eecache file handle"; ;
    }
    elsif ( $eecache_toc_version == 2)
    {
        seek($eecache_fh, $start_location, 0);
        read($eecache_fh, $eecache_toc, VERSION_2_TOC_SIZE) or die "failed to read ".VERSION_2_TOC_SIZE." bytes from eecache file handle"; ;
    }
    else
    {
        die "Failed to find valid TOC, version found = $eecache_toc_version. Latest version this tool supports is ".VERSION_LATEST;
    }

    return $eecache_toc;
}



# Brief : Takes in binary blob representing EECACHE table of contents, as well as
#         a uniqueID to match against, returns hash that contains size and offset of
#         cached eeprom data inside EEACHE section
#
#  If verbose is set,
sub parseEecacheToc {
    my $eecacheTOC = shift;
    my $idToMatch = shift;

    # figure out what version of EECACHE header exists
    my $headerVersion = 0;
    my $tocEntrySizeBytes = 0;
    my $tocEntries = 0;

    my ($version) = unpack('H2', "$eecacheTOC");
    if ($version == 0x01)
    {
        $headerVersion = 1;
        $tocEntrySizeBytes = VERSION_1_TOC_ENTRY_SIZE_BYTES;
        $tocEntries = VERSION_1_NUM_ENTRIES;
    }
    elsif ($version == 0x02)
    {
        $headerVersion = 2;
        $tocEntrySizeBytes = VERSION_2_TOC_ENTRY_SIZE_BYTES;
        $tocEntries = VERSION_2_NUM_ENTRIES;
    }
    else
    {
        die "Unsupported PNOR EECACHE level $version";
    }

    # verify uniqueId was built against same version as PNOR's EECACHE
    if (isUniqueIdValid($uniqueId))
    {
        unless (($headerVersion == $eecacheVersion))
        {
            die "PNOR EECACHE version $headerVersion is not same as expected EECACHE version $eecacheVersion!" .
                "Maybe changed expected with --version option";
        }
    }

    # header entries start after on 6th byte
    my $headerEntryOffset = 5;

    # this will end up being the return value
    my %entryInfo;
    $entryInfo{entry_offset}  = 0;
    $entryInfo{entry_size}    = 0;
    $entryInfo{header_offset} = 0;

    my $totalEntryCount = 0;
    my $validEntryCount = 0;

    my $matchSummaryString = "";

    # Some common variables between header versions
    my $internal_offset = 0xFFFF;
    my $cached_copy_valid = 0;
    my $cached_copy_size = 0;
    my $entry_size = 0;
    my $entry_offset = 0;
    my $bitFieldByte = 0; # last byte of header
    my $entryUniqueID = "FFFFFFFFFFFFFFFF";

    use Class::Struct;

    struct I2C_Entry_t => {
        i2c_master_huid => '$',
        port            => '$',
        engine          => '$',
        devAddr         => '$',
        mux_select      => '$',
    };

    struct SPI_Entry_t => {
        spi_master_huid => '$',
        engine          => '$',
        offset_KB       => '$',
    };

    for(my $i = 0; $i < $tocEntries; $i++)
    {
        my $eepromAccess = EEPROM_ACCESS_I2C;
        my $master_eeprom = 0xFF; # default to invalid master eeprom

        my $entry = substr $eecacheTOC, $headerEntryOffset, $tocEntrySizeBytes;

        # update offset right away so we dont forget
        $headerEntryOffset += $tocEntrySizeBytes;
        my $entry_data;

        if ($headerVersion == 1)
        {
            # see "Struct for Header Version 1" in top of file

            my @entryFields = unpack('H8 H2 H2 H2 H2 H8 H8 H2', "$entry");

            $entryUniqueID = "@entryFields[0]@entryFields[1]@entryFields[2]@entryFields[3]@entryFields[4]";
            $eepromAccess = EEPROM_ACCESS_I2C;
            $entry_data = I2C_Entry_t->new();
            $entry_data->i2c_master_huid( @entryFields[0] );
            $entry_data->port ( @entryFields[1] );
            $entry_data->engine ( @entryFields[2] );
            $entry_data->devAddr ( @entryFields[3] );
            $entry_data->mux_select ( @entryFields[4] );
            $bitFieldByte = @entryFields[7];
            $cached_copy_valid = (hex( "0x".@entryFields[7]) & 0x80) >> 7;


            # if the entry ID is FFFFFFFFFFFFFFFF this indicates
            # that the entry is not filled out
            if($entryUniqueID == "FFFFFFFFFFFFFFFF")
            {
                next;
            }
            $cached_copy_size = @entryFields[5];
            $internal_offset = @entryFields[6];
        }
        elsif ($headerVersion == 2)
        {
            # see "Struct for Header Version 2" in top of file

            ($eepromAccess) = unpack('H2', "$entry");
            if ($eepromAccess == EEPROM_ACCESS_I2C)
            {
                # unpack according to src/include/usr/i2c/eeprom_const.H ( pasted above)
                my @entryFields = unpack('H2 H8 H2 H2 H2 H2 H8 H8 H2', "$entry");

                $entryUniqueID = "@entryFields[0]@entryFields[1]@entryFields[2]@entryFields[3]@entryFields[4]@entryFields[5]";

                $entry_data = I2C_Entry_t->new();
                $entry_data->i2c_master_huid( @entryFields[1] );
                $entry_data->port( @entryFields[2] );
                $entry_data->engine( @entryFields[3] );
                $entry_data->devAddr( @entryFields[4] );
                $entry_data->mux_select( @entryFields[5] );

                $cached_copy_size = @entryFields[6];
                $internal_offset  = @entryFields[7];

                $bitFieldByte = @entryFields[8];
                $cached_copy_valid = (hex("0x".@entryFields[8]) & 0x80) >> 7;
                $master_eeprom     = (hex("0x".@entryFields[8]) & 0x40) >> 6;
            }
            elsif ($eepromAccess == EEPROM_ACCESS_SPI)
            {
                # unpack according to src/include/usr/i2c/eeprom_const.H ( pasted above)
                my @entryFields = unpack('H2 H8 H2 H4 H2 H8 H8 H2', "$entry");

                $entryUniqueID = "@entryFields[0]@entryFields[1]@entryFields[2]@entryFields[3]00";

                $entry_data =  SPI_Entry_t->new();
                $entry_data->spi_master_huid( @entryFields[1] );
                $entry_data->engine( @entryFields[2] );
                $entry_data->offset_KB( @entryFields[3] );

                # @entryField[4] is just filler

                $cached_copy_size = @entryFields[5];
                $internal_offset  = @entryFields[6];

                $bitFieldByte = @entryFields[7];
                $cached_copy_valid = (hex("0x".@entryFields[7]) & 0x80) >> 7;
                $master_eeprom     = (hex("0x".@entryFields[7]) & 0x40) >> 6;
            }
            else
            {
                # entry is not filled out if eepromAccess is not I2C or SPI
                next;
            }
        }

        $totalEntryCount++;

        if(hexStrsEqual($entryUniqueID, $idToMatch))
        {
            $entryInfo{entry_offset} = $internal_offset;

            # Converting hex string to int and multiplying by 1024
            # KB to Bytes
            $entryInfo{entry_size}   = (hex $cached_copy_size) * 1024;
            $entryInfo{header_offset} = $headerEntryOffset - $tocEntrySizeBytes;

            $matchSummaryString =  "ENTRY FOUND ...\n";
            if ($eepromAccess == EEPROM_ACCESS_I2C)
            {
                if ($headerVersion >= 2)
                {
                    $matchSummaryString .=
                      "accessType               = 0x".$eepromAccess." I2C ACCESS\n";
                }
                $matchSummaryString .=
                "Master I2C Huid          = 0x". $entry_data->i2c_master_huid ."\n".
                "Port                     = 0x". $entry_data->port ."\n".
                "Engine                   = 0x". $entry_data->engine ."\n".
                "Device Address           = 0x". $entry_data->devAddr ."\n".
                "Mux Select               = 0x". $entry_data->mux_select ."\n".
                "Size of Cached Copy (KB) = 0x$cached_copy_size\n".
                "Offset within EECACHE    = 0x$internal_offset\n".
                "Cached copy valid ?      = 0x$cached_copy_valid (1st bit of 0x$bitFieldByte)\n";
            }
            else # EEPROM_ACCESS_SPI
            {
                if ($headerVersion >= 2)
                {
                    $matchSummaryString .=
                      "accessType               = 0x".$eepromAccess." SPI ACCESS\n";
                }
                $matchSummaryString .=
                "Master SPI Huid          = 0x". $entry_data->spi_master_huid ."\n".
                "Engine                   = 0x". $entry_data->engine ."\n".
                "Offset in EEPROM         = 0x". $entry_data->offset_KB ."\n".
                "Size of Cached Copy (KB) = 0x$cached_copy_size\n".
                "Offset within EECACHE    = 0x$internal_offset\n".
                "Cached copy valid ?      = $cached_copy_valid (1st bit of 0x$bitFieldByte)\n";
            }
            if ($master_eeprom != 0xFF)
            {
                $matchSummaryString .=
                "EEPROM master ?          = $master_eeprom (2nd bit of 0x$bitFieldByte)\n";
            }
            $matchSummaryString .=
                "unique ID                = 0x$entryUniqueID \n\n";

            if(!$verbose)
            {
                last;
            }
        }

        if( !$cached_copy_valid )
        {
            # skip if this entry is not valid and told to just
            # print valid only entries
            if($onlyValid)
            {
                next;
            }
        }
        else
        {
            $validEntryCount++;
        }

        my $entryString = "";
        if ($eepromAccess == EEPROM_ACCESS_I2C)
        {
            if ($headerVersion >= 2)
            {
                $entryString .=
                  "accessType               = 0x".$eepromAccess." I2C ACCESS\n";
            }
            $entryString .=
            "Master I2C Huid          = 0x". $entry_data->i2c_master_huid ."\n".
            "Port                     = 0x". $entry_data->port ."\n".
            "Engine                   = 0x". $entry_data->engine ."\n".
            "Device Address           = 0x". $entry_data->devAddr ."\n".
            "Mux Select               = 0x". $entry_data->mux_select ."\n".
            "Size of Cached Copy (KB) = 0x$cached_copy_size\n".
            "Offset within EECACHE    = 0x$internal_offset\n".
            "Cached copy valid ?      = $cached_copy_valid (1st bit of 0x$bitFieldByte)\n";
        }
        else
        {
            if ($headerVersion >= 2)
            {
                $entryString .=
                  "accessType               = 0x".$eepromAccess." SPI ACCESS\n";
            }
            $entryString .=
            "Master SPI Huid          = 0x". $entry_data->spi_master_huid ."\n".
            "Engine                   = 0x". $entry_data->engine ."\n".
            "Offset in EEPROM         = 0x". $entry_data->offset_KB ."\n".
            "Size of Cached Copy (KB) = 0x$cached_copy_size\n".
            "Offset within EECACHE    = 0x$internal_offset\n".
            "Cached copy valid ?      = $cached_copy_valid (1st bit of 0x$bitFieldByte)\n";
        }

        if ($master_eeprom != 0xFF)
        {
            $entryString .=
            "EEPROM master ?          = $master_eeprom (2nd bit of 0x$bitFieldByte)\n";
        }
        $entryString .=
            "unique ID                = 0x$entryUniqueID \n\n";

        printVerbose($entryString);
    }

    printVerbose(
        "Summary :\n".
        "  Total Entry Count    : $totalEntryCount \n".
        "  Valid Entry Count    : $validEntryCount \n".
        "  Max Possible Entries : $tocEntries\n\n");

    print "\nmatchSummaryString: $matchSummaryString\n";

    if($matchSummaryString ne "")
    {
        print $matchSummaryString;
    }
    else
    {
        # Skip failure message if not looking for a unique id match
        if (isUniqueIdValid($uniqueId))
        {
            print "No Match Found! \n\n";
        }
    }

    return \%entryInfo;
}



# @brief
# Perform the following operation to the the EECACHE file ($output_fh)
# - Create an SPI or I2C header entry (based on CLI arg $appendSpiEntry or $appendSpiEntry)
# - Append cache data ($newImagePath) at the end of file (note $newImagePath will be padded to be
#   of size $cacheSizeKB)
# - Update "end_of_cache" value in eecache's header
sub appendNewEntryWithData
{
    ### Read TOC of EECACHE

    # Parse the larger binary blob to get just the Table of Contents
    my $eecacheTOC = readEecacheToc($output_fh);

    ### Figure out version and end of cache address of EECACHE,
    ### and TOC layout info

    # Get TOC info
    # struct eecacheSectionHeader
    # {
    #     uint8_t version;         // EECACHE_VERSION
    #     uint32_t end_of_cache;   // End point of the last cache entry
    #     eepromRecordHeader recordHeaders[MAX_EEPROMS_LATEST];
    # } PACKED ;
    my @tocInfo = unpack('H2 H8', "$eecacheTOC");
    my $tocVersion = @tocInfo[0];

    # figure out what version of EECACHE header exists
    my $headerVersion = 0;
    my $tocEntrySizeBytes = 0;
    my $tocEntries = 0;

    if ($tocVersion == 0x01)
    {
        $headerVersion = 1;
        $tocEntrySizeBytes = VERSION_1_TOC_ENTRY_SIZE_BYTES;
        $tocEntries = VERSION_1_NUM_ENTRIES;
    }
    elsif ($tocVersion == 0x02)
    {
        $headerVersion = 2;
        $tocEntrySizeBytes = VERSION_2_TOC_ENTRY_SIZE_BYTES;
        $tocEntries = VERSION_2_NUM_ENTRIES;
    }
    else
    {
        die "Unsupported PNOR EECACHE level $tocVersion";
    }

    ### Find last TOC entry

    my $headerEntryOffset = 5; # header entries start after on 6th byte
    my $lastFilledTocEntryOffset = 0;
    my $lastFilledTocEntry;

    # Loop until last filled-in TOC entry; keep track of last filled in
    # entry offset with $lastFilledTocEntryOffset
    my $i = 1;
    for ($i; $i <= $tocEntries; $i++)
    {
        my $entry = substr $eecacheTOC, $headerEntryOffset, $tocEntrySizeBytes;

        if (!isTocEntryFilledIn($headerVersion, $entry)) {
            # When the first not filled-in entry is found, stop looping through the entries.
            # This empty entry will be used to place the new entry.
            last; # break out of loop
        }

        $lastFilledTocEntry = $entry;
        $lastFilledTocEntryOffset = $headerEntryOffset;
        $headerEntryOffset += $tocEntrySizeBytes; # Update entry offset
    }

    if ($i > $tocEntries)
    {
        die "Error: No empty TOC entries were found where the new cache data could be placed in.";
    }

    ### Calculate offset for new cache entry

    # Get offset in eecache and size of cache of last eecache entry
    my $entryCacheSizeKB;
    my $entryCacheOffset;
    ($entryCacheSizeKB, $entryCacheOffset) = &getCachedCopyOffsetAndSize($headerVersion, $lastFilledTocEntry);

    my $newCacheEntryOffset = (hex $entryCacheOffset) + ((hex $entryCacheSizeKB) * 1024);

    ### Create TOC entry and append to EECACHE

    my $newTocEntry; # TOC entry format depends on Header Version and bus type (I2C or SPI in this case)

    if ($appendSpiEntry)
    {
        if ($headerVersion == 1)
        {
            die "Error: Cannot insert SPI type entry to a Version 1 EECACHE file";
        }
        $newTocEntry = createTocEntrySpiV2($masterHuid, $engine, $devOffsetKB,
            $cacheSizeKB, $newCacheEntryOffset, $cacheIsValid, $masterInEeprom);
    }
    elsif ($appendSpiEntry)
    {
        if ($headerVersion == 1)
        {
            $newTocEntry = createTocEntryI2cV1($masterHuid, $port, $engine,
                $devAddr, $muxSelect, $cacheSizeKB, $newCacheEntryOffset, $cacheIsValid);
        }
        elsif ($headerVersion == 2)
        {
            $newTocEntry = createTocEntryI2cV2($masterHuid, $port, $engine, $devAddr,
                $muxSelect, $cacheSizeKB, $newCacheEntryOffset, $cacheIsValid, $masterInEeprom);
        }
    }

    my $newTocEntryOffset = $lastFilledTocEntryOffset + $tocEntrySizeBytes;

    print("Appending TOC entry for new cache at offset: $newTocEntryOffset\n");

    # Seek to where new TOC entry will be placed and write it
    seek($output_fh, $newTocEntryOffset , 0);
    print $output_fh $newTocEntry;

    ### Append new cache data to EECACHE

    # Pad new cache file if needed
    my $newCacheDataPath = padFileIfNeeded($newImagePath, $cacheSizeKB * 1024);

    # Open and read new cache data to be appended
    my $newCacheDataSize = -s $newCacheDataPath;
    my $newCacheHandle;
    open $newCacheHandle, '<', $newCacheDataPath or die "failed to open $newCacheDataPath: $!\n";
    my $newCacheData;
    read($newCacheHandle, $newCacheData, $newCacheDataSize);
    close $newCacheHandle;

    print("Last cache data entry found at offset ".(hex $entryCacheOffset).
        ", with size ".((hex $entryCacheSizeKB) * 1024)." bytes.\n");
    print("New cache ($newCacheDataPath) data of $newCacheDataSize bytes will be appended at eecache ".
        "offset $newCacheEntryOffset.\n");

    # Seek to where new cache data will be placed and write it
    seek($output_fh, $newCacheEntryOffset , 0);
    print $output_fh $newCacheData;

    ### Edit header's end of cache value

    # Get offset in eecache and size of cache of newly added eecache entry
    my $newEntryCacheSizeKB;
    my $newEntryCacheOffset;
    ($newEntryCacheSizeKB, $newEntryCacheOffset) = &getCachedCopyOffsetAndSize($headerVersion, $newTocEntry);

    my $newEndOfCache = (hex $newEntryCacheOffset) + ((hex $newEntryCacheSizeKB) * 1024);
    my $newEndOfCacheValue = pack('H8', sprintf("%08x", $newEndOfCache));

    # Seek to header end_of_cache value and write new value in
    seek($output_fh, 1 , 0);
    print $output_fh $newEndOfCacheValue;

    print("\n");
    print("EECACHE header \"end_of_cache\" value is being updated from $newCacheEntryOffset bytes to $newEndOfCache bytes.\n");
    print("\n");

}



# @brief Create SPI bus type TOC entry data to be inserted into EECACHE.
# Using Header Version 2 for an SPI entry.
# "Struct for Header Version 2" above shows how data should be packed.
#
# Expected arguments (All values must be hex-string)
# @param[in] $arg1 masterHUID
# @param[in] $arg2 engine, engine number
# @param[in] $arg3 eepromOffsetKB, offset in KB of where record begins in eeprom
# @param[in] $arg4 cachedCopySizeKB, size of data saved in cache (in KB)
# @param[in] $arg5 eecacheOffset, offset from start of EECACHE section where
#                   cached data exists
# @param[in] $arg6 isCachedCopyValid, This bit is set when we think the contents
#                   of the cache is valid, 0: false, 1: true
# @param[in] $arg7 isMasterEeprom, This bit marks this record as the master one,
#                   0: false, 1: true
#
# @return Packed and formatted TOC entry data
sub createTocEntrySpiV2
{
    # Parse function arguments
    my $masterHUID = shift;
    my $engine = shift;
    my $eepromOffsetKB = shift;
    my $cachedCopySizeKB = shift;
    my $eecacheOffset = shift;
    my $isCachedCopyValid = shift;
    my $isMasterEeprom = shift;

    # bitfield to set if the cache is valid and if cache is the master record
    my $endBitfield = 0;
    if ($isMasterEeprom)    { $endBitfield = $endBitfield | 0x40; }
    if ($isCachedCopyValid) { $endBitfield = $endBitfield | 0x80; }

    # Note the '02' refers to the access type, in this case SPI
    # Note the 0 is just empty padding, see "Struct for Header Version 2"
    my $newTocEntry = pack('H2 H8 H2 H4 H2 H8 H8 H2',
        '02',
        sprintf("%08x", $masterHUID),
        sprintf("%02x", $engine),
        sprintf("%04x", $eepromOffsetKB)
        , 0,
        sprintf("%08x", $cachedCopySizeKB),
        sprintf("%08x", $eecacheOffset),
        sprintf("%02x", $endBitfield));

    # Show User content of new TOC created
    my @entryFields = unpack('H2 H8 H2 H4 H2 H8 H8 H2', "$newTocEntry");
    print("\n");
    print("----- New TOC entry content for SPI device -----\n");
    print("entryFields[0] access type:      @entryFields[0]\n");
    print("entryFields[1] master huid:      @entryFields[1]\n");
    print("entryFields[2] engine:           @entryFields[2]\n");
    print("entryFields[3] eepromOffsetKB:   @entryFields[3]\n");
    print("entryFields[4] empty padding:    @entryFields[4]\n");
    print("entryFields[5] cachedCopySizeKB: @entryFields[5]\n");
    print("entryFields[6] eecacheOffset:    @entryFields[6]\n");
    print("entryFields[7] is master/valid:  @entryFields[7]\n");
    print("------------------------------------------------\n");
    print("\n");

    return $newTocEntry;
}



# @brief Create I2C bus type TOC entry data to be inserted into EECACHE.
# Using Header Version 2 for an I2C entry.
# "Struct for Header Version 2" above shows how data should be packed.
#
# Expected arguments (All values must be hex-string)
# @param[in] $arg1 $masterHUID
# @param[in] $arg2 $port number
# @param[in] $arg3 $engine, engine number
# @param[in] $arg4 $devAddr, device address
# @param[in] $arg5 $mux_select, Some I2C devices are behind a mux, this says
#                   what setting on the mux is required
# @param[in] $arg6 $cachedCopySizeKB, size of data saved in cache (in KB)
# @param[in] $arg7 $eecacheOffset, offset from start of EECACHE section where
#                   cached data exists
# @param[in] $arg8 $isCachedCopyValid, This bit is set when we think the contents
#                   of the cache is valid, 0: false, 1: true
# @param[in] $arg9 isMasterEeprom, This bit marks this record as the master one,
#                   0: false, 1: true
#
# @return Packed and formatted TOC entry data
sub createTocEntryI2cV2
{
    # Parse function arguments
    my $masterHUID = shift;
    my $port = shift;
    my $engine = shift;
    my $devAddr = shift;
    my $mux_select = shift;
    my $cachedCopySizeKB = shift;
    my $eecacheOffset = shift;
    my $isCachedCopyValid = shift;
    my $isMasterEeprom = shift;

    # bitfield to set if the cache is valid and if cache is the master record
    my $endBitfield = 0;
    if ($isMasterEeprom)    { $endBitfield = $endBitfield | 0x40; }
    if ($isCachedCopyValid) { $endBitfield = $endBitfield | 0x80; }

    # Note the '01' refers to the access type, in this case I2C
    my $newTocEntry = pack('H2 H8 H2 H2 H2 H2 H8 H8 H2',
        '01',
        sprintf("%08x", $masterHUID),
        sprintf("%02x", $port),
        sprintf("%02x", $engine),
        sprintf("%02x", $devAddr),
        sprintf("%02x", $mux_select),
        sprintf("%08x", $cachedCopySizeKB),
        sprintf("%08x", $eecacheOffset),
        sprintf("%02x", $endBitfield));

    # Show User content of new TOC created
    my @entryFields = unpack('H2 H8 H2 H2 H2 H2 H8 H8 H2', "$newTocEntry");
    print("\n");
    print("--- New TOC entry for I2C device, Header V2 ----\n");
    print("entryFields[0] access type:      @entryFields[0]\n");
    print("entryFields[1] master huid:      @entryFields[1]\n");
    print("entryFields[2] port:             @entryFields[2]\n");
    print("entryFields[3] engine:           @entryFields[3]\n");
    print("entryFields[4] devAddr:          @entryFields[4]\n");
    print("entryFields[5] mux_select:       @entryFields[5]\n");
    print("entryFields[6] cachedCopySizeKB: @entryFields[6]\n");
    print("entryFields[7] eecacheOffset:    @entryFields[7]\n");
    print("entryFields[8] is master/valid:  @entryFields[8]\n");
    print("------------------------------------------------\n");
    print("\n");

    return $newTocEntry;
}



# @brief Create I2C bus type TOC entry data to be inserted into EECACHE.
# Using Header Version 1 for an I2C entry.
# "Struct for Header Version 1" above shows how data should be packed.
#
# Expected arguments (All values must be hex-string)
# @param[in] $arg1 $masterHUID
# @param[in] $arg2 $port number
# @param[in] $arg3 $engine, engine number
# @param[in] $arg4 $devAddr, device address
# @param[in] $arg5 $mux_select, Some I2C devices are behind a mux, this says
#                   what setting on the mux is required
# @param[in] $arg6 $cachedCopySizeKB, size of data saved in cache (in KB)
# @param[in] $arg7 $eecacheOffset, offset from start of EECACHE section where
#                   cached data exists
# @param[in] $arg8 $isCachedCopyValid, This bit is set when we think the contents
#                   of the cache is valid, 0: false, 1: true
#
# @return Packed and formatted TOC entry data
sub createTocEntryI2cV1
{
    # Parse function arguments
    my $masterHUID = shift;
    my $port = shift;
    my $engine = shift;
    my $devAddr = shift;
    my $mux_select = shift;
    my $cachedCopySizeKB = shift;
    my $eecacheOffset = shift;
    my $isCachedCopyValid = shift;

    # bitfield to set if the cache is valid
    my $endBitfield = 0;
    if ($isCachedCopyValid) { $endBitfield = $endBitfield | 0x80; }

    my $newTocEntry = pack('H8 H2 H2 H2 H2 H8 H8 H2',
        sprintf("%08x", $masterHUID),
        sprintf("%02x", $port),
        sprintf("%02x", $engine),
        sprintf("%02x", $devAddr),
        sprintf("%02x", $mux_select),
        sprintf("%08x", $cachedCopySizeKB),
        sprintf("%08x", $eecacheOffset),
        sprintf("%02x", $endBitfield));

    # Show User content of new TOC created
    my @entryFields = unpack('H8 H2 H2 H2 H2 H8 H8 H2', "$newTocEntry");
    print("\n");
    print("--- New TOC entry for I2C device, Header V1 ----\n");
    print("entryFields[0] master huid:      @entryFields[0]\n");
    print("entryFields[1] port:             @entryFields[1]\n");
    print("entryFields[2] engine:           @entryFields[2]\n");
    print("entryFields[3] devAddr:          @entryFields[3]\n");
    print("entryFields[4] mux_select:       @entryFields[4]\n");
    print("entryFields[5] cachedCopySizeKB: @entryFields[5]\n");
    print("entryFields[6] eecacheOffset:    @entryFields[6]\n");
    print("entryFields[7] is valid:         @entryFields[7]\n");
    print("------------------------------------------------\n");
    print("\n");

    return $newTocEntry;
}



# @brief Given a TOC entry and header version of EECACHE, return tuple
# containing the cache copy size in KB and cache copy offset.
#
# @param[in] $headerVersion header version, int
# @param[in] $tocEntry TOC entry data from EECACHE
#
# @return Tuple ($entryCacheSizeKB, $entryCacheOffset)
# $entryCacheSizeKB: Size of cache (KB) TOC describes
# $entryCacheOffset: Offset of cache in EECACHE
sub getCachedCopyOffsetAndSize
{
    # Parse arguments
    my $headerVersion = shift;
    my $tocEntry = shift;

    # Return variables
    my $entryCacheSizeKB;
    my $entryCacheOffset;

    # Parse cache size and cache offset based on header version
    if ($headerVersion == 1)
    {
        # See Header Version 1 structs above
        my @entryFields = unpack('H8 H2 H2 H2 H2 H8 H8 H2', "$tocEntry");
        $entryCacheSizeKB = @entryFields[5];
        $entryCacheOffset = @entryFields[6];
    }
    elsif ($headerVersion == 2)
    {
        # See Header Version 2 structs above
        my $eepromAccess;
        ($eepromAccess) = unpack('H2', "$tocEntry");
        if ($eepromAccess == EEPROM_ACCESS_I2C)
        {
            my @entryFields = unpack('H2 H8 H2 H2 H2 H2 H8 H8 H2', "$tocEntry");
            $entryCacheSizeKB = @entryFields[6];
            $entryCacheOffset  = @entryFields[7];
        }
        elsif ($eepromAccess == EEPROM_ACCESS_SPI)
        {
            my @entryFields = unpack('H2 H8 H2 H4 H2 H8 H8 H2', "$tocEntry");
            $entryCacheSizeKB = @entryFields[5];
            $entryCacheOffset  = @entryFields[6];
        }
        else
        {
            die "Error: getCachedCopyOffsetAndSize() received TOC entry with invalid eeprom access.";
        }
    }
    else
    {
        die "Error: getCachedCopyOffsetAndSize() received invalid Header Version";
    }

    return ($entryCacheSizeKB, $entryCacheOffset);
}



# @brief Given a TOC entry and header version of EECACHE, compute
# if the TOC entry is filled in or not and return answer.
#
# @param[in] $headerVersion header version, int
# @param[in] $tocEntry TOC entry data from EECACHE
#
# @return Bool 1: true, entry is filled in
#              0: false, entry is not filled in
sub isTocEntryFilledIn
{
    # Parse arguments
    my $headerVersion = shift;
    my $tocEntry = shift;

    # Return variable
    my $isEntryFilledIn = 0;

    if ($headerVersion == 1)
    {
        if (!hexStrsEqual(unpack('H8', $tocEntry), "ffffffff"))
        {
            $isEntryFilledIn = 1;
        }
    }
    elsif ($headerVersion == 2)
    {
        my $eepromAccess;
        ($eepromAccess) = unpack('H2', $tocEntry);
        if ($eepromAccess == EEPROM_ACCESS_I2C || $eepromAccess == EEPROM_ACCESS_SPI)
        {
            $isEntryFilledIn = 1;
        }
    }

    return $isEntryFilledIn;
}



## Helper functions

sub printVerbose {

  my $string = shift;

  if($verbose)
  {
    print $string;
  }
}

sub isUniqueIdValid
{
    my ($uniqueId) = @_;

    if( (($eecacheVersion == 1) && ($uniqueId == "00000000000000FF"))   ||
        (($eecacheVersion == 2) && ($uniqueId == "0100000000000000FF")) ||
        (($eecacheVersion == 2) && ($uniqueId == "020000000000000000")) )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



# @brief Take two strings containing hex values and return bool whether the hex
# values are equal
#
# The hex-strings do not have to be of the same format, i.e.:
# - it doesn't matter if the hex string contains "0x"
# - it doesn't matter if letters are capitalized or not
# E.g.: hexStrsEqual("0X123AB", "123ab") will return True
#
# @param[in] $str1 Expected string containing hex value
# @param[in] $str2 Expected string containing hex value
#
# @return
# - Returns True if hex values equal
# - Returns False if hex values are not equal
sub hexStrsEqual
{
    # Input arguments, hex-value strings
    my $str1 = shift;
    my $str2 = shift;

    # Check if any of the hex-strings contains "0x" decorator
    # Note that if hex-string only has one character, then substr(...) will
    # return that one character and not fail
    if (uc substr($str1, 0, 2) eq "0X")
    {
        # If str1 contains "0x", remove it
        $str1 = substr($str1, 2);
    }
    if (uc substr($str2, 0, 2) eq "0X")
    {
        # If str2 contains "0x", remove it
        $str2 = substr($str2, 2);
    }

    return (uc $str1 eq uc $str2);

}



# @brief Add padding at the end of a file if the file is smaller in size than
# what is expected.
#
# @param[in] $pathToNewCacheFile Path to file, string
# @param[in] $expectedSize Expected file size, int, bytes
#
# @return file-path string to new padded file. If file was not padded
# then $pathToNewCacheFile is returned.
sub padFileIfNeeded
{
    my $pathToNewCacheFile = shift; # string
    my $expectedSize = shift; # int, in bytes

    my $new_file_size = -s $pathToNewCacheFile;

    # Var used to keep track of which image to write into EECACHE at
    # the end of this if-statement
    my $inputImgPath = $pathToNewCacheFile;

    # If the size of the new image is larger than the entry size in
    # available in EECACHE, then this image cannot be inserted.
    if ($new_file_size > $expectedSize)
    {
        die "ERROR: incorrect size, EECACHE is reporting the".
        " entry size to be ".$expectedSize." bytes, but".
        " new file to be inserted is larger at a size of "
        .$new_file_size." bytes.\n";
    }

    # If the new file to be loaded-in is smaller in size than the
    # allocated EECACHE entry size, then pad a copy of the
    # file to fit.
    # Note that in the case that the image ($pathToNewCacheFile) to be
    # inserted into the EECACHE is exactly the size of the entry in
    # EECACHE, then padding will be skipped.
    if ($new_file_size < $expectedSize)
    {
        # Make a copy of the input image file and pad it to fit
        # $hashRef->{'entry_size'} size

        # Path of copy of input image which will be padded
        # Note that the padded image will be stored in the
        # current directory
        my $paddedInputImg = basename($pathToNewCacheFile);
        $paddedInputImg .= ".padded";

        $inputImgPath = $paddedInputImg;

        system("\\cp -f $pathToNewCacheFile $paddedInputImg");
        die "ERROR: Failed to create copy of input image to be ".
        "padded $pathToNewCacheFile" if($?);
        system("truncate $paddedInputImg -s $expectedSize");
        die "ERROR: Failed to pad image $pathToNewCacheFile" if($?);

        # Inform User of copied and paddded file
        print("\n");
        print("Provided image ($pathToNewCacheFile) to write into ".
            "EECACHE is smaller than cache entry.\n");
        print("$pathToNewCacheFile size: $new_file_size\n");
        print("expected cache size: $expectedSize\n");
        print("Creating a padded copy of the image ($paddedInputImg)".
            " to be inserted into the cache entry.\n");
        print("$paddedInputImg size: ");
        print(-s $paddedInputImg);
        print("\n\n");

    }

    # Return path of cache image to use
    return $inputImgPath

}


