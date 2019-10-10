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
my $devOffset = 0xFFFF;  # initialized to invalid offset

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

use constant VERSION_1_TOC_ENTRY_SIZE_BYTES => 17;
use constant VERSION_1_TOC_ENTRY_SIZE_BITS => (VERSION_1_TOC_ENTRY_SIZE_BYTES * 8) ;
use constant VERSION_1_NUM_ENTRIES => 50;
use constant VERSION_1_TOC_SIZE => (VERSION_1_TOC_ENTRY_SIZE_BYTES * VERSION_1_NUM_ENTRIES) + 5;

use constant VERSION_2_TOC_ENTRY_SIZE_BYTES => 18;
use constant VERSION_2_TOC_ENTRY_SIZE_BITS => (VERSION_2_TOC_ENTRY_SIZE_BYTES * 8) ;
use constant VERSION_2_NUM_ENTRIES => 50;
use constant VERSION_2_TOC_SIZE => (VERSION_2_TOC_ENTRY_SIZE_BYTES * VERSION_2_NUM_ENTRIES) + 5;

use constant VERSION_LATEST => 2;

use constant EEPROM_ACCESS_I2C => 1;
use constant EEPROM_ACCESS_SPI => 2;



my $eecacheVersion = VERSION_LATEST;

GetOptions("pnor:s"        => \$pnorBinaryPath,
           "eecache:s"     => \$eecacheBinaryPath,
           "newImage:s"    => \$newImagePath,
           "newFile:s"     => \$newImagePath,
           "out:s"         => \$outFilePath,
           "of:s"          => \$outFilePath,
           "masterHuid:o"  => \$masterHuid,
           "port:o"        => \$port,
           "engine:o"      => \$engine,
           "devAddr:o"     => \$devAddr,
           "muxSelect:o"   => \$muxSelect,
           "eepromSize:o"  => \$eepromSize,
           "uniqueId:s"    => \$uniqueId,
           "devOffset:o"   => \$devOffset,
           "version:o"     => \$eecacheVersion,
           "onlyValid"     => \$onlyValid,
           "overwrite"     => \$overwrite,
           "clear"         => \$clearEepromData,
           "verbose"       => \$verbose,
           "usage"         => \$usage,
           "help"          => \$usage,
           "h"             => \$usage);

sub print_help()
{
    print "--------- EECACHE Editor Tool V 2.0 ---------\n";
    print "\n";
    print "Mandatory:\n\n";

    print "   --eecache     Path to ECC-less eeprom cache section of PNOR  (IE : EECACHE.bin )\n\n";

    print "Optional:\n\n";

    print "   --clear       If a matching eeprom is found, clear out its contents\n";
    print "   --devAddr     Device address of desired EEPROM\n";
    print "   --devOffset   Offset (KB) of where record begins in eeprom for SPI access\n";
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
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffset 0xc0 --masterHuid 0x50000\n";
    print "\n";
    print "  # (SPI) lookup eeprom matching input params and clear the contents ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffset 0xc0 --masterHuid 0x50000 --clear\n";
    print "\n";
    print "  # (SPI) lookup eeprom matching input params and write new image's contents to offset in EECACHE where matching eeprom data exists ( manipulate input binary )\n";
    print "  eecache_editor.pl --eecache EECACHE.bin --engine 3 --devOffset 0xc0 --masterHuid 0x50000 --newImage newSPD.dat\n";
    print "---------------------------------------------\n";
}

if( $usage )
{
    print_help();
    exit 0;
}

if( ($pnorBinaryPath eq "") &&
    ($eecacheBinaryPath eq ""))
{
    # Print error saying we need one of these filled in
    print "ERROR Neither PNOR binary nor EECACHE section binary passed in. Cannot continue.\n\n";
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

if($newImagePath ne "")
{
    $overwrite = 1;
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
        # devOffset is specific to SPI access so check to see if it is valid
        if ($devOffset != 0xFFFF)
        {
            $uniqueId  = sprintf ("%.02X", EEPROM_ACCESS_SPI);
            $uniqueId .= sprintf ("%.08X", $masterHuid);
            $uniqueId .= sprintf ("%.02X", $engine);
            $uniqueId .= sprintf ("%.04X", $devOffset);
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

# setup input and output files
my $input_fh;
my $output_fh;

my $new_fh;

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
        $output_fh = $input_fh;
    }
    else
    {
        open $output_fh, '+>:raw', $outFilePath or die "failed to open $outFilePath: $!\n";
        copy($eecacheBinaryPath, $outFilePath) ;
    }
}

if($newImagePath ne "")
{
    open $new_fh, '<', $newImagePath or die "failed to open $newImagePath: $!\n";
}



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
        # If the offset is 0, then no match was found
        if($hashRef->{'entry_offset'} != 0)
        {
            if($newImagePath ne "") # if a new image is available try to load it in
            {
                my $new_file_size = -s $newImagePath ;
                my $new_file_data;
                read($new_fh, $new_file_data, $new_file_size );

                # Verify the new image is the correct size
                if( $new_file_size != $hashRef->{'entry_size'})
                {
                    print "ERROR incorrect size, EECACHE is reporting size to be".$hashRef->{'entry_size'}."bytes but file proved is only".$new_file_size." bytes\n";
                    exit 0;
                }

                # seek to the offset inside EEACHE where this eeprom's cache lives
                # and write the new file contents
                seek($output_fh, $hashRef->{'entry_offset'} , 0);
                print $output_fh $new_file_data;
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


# Start Subroutines

sub readEecacheToc {
    my $eecache_fh = shift;

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
            ###### VERSION 1 ########
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

            # unpack according to src/include/usr/i2c/eeprom_const.H ( pasted above)
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
            ###### VERSION 2 ########
            #    struct completeRecord
            #    {
            #        EepromHwAccessMethodType accessType;  // how to access record
            #        union eepromAccess_t
            #        {
            #            struct i2cAccess_t
            #            {
            #                uint32_t i2c_master_huid;   // HUID of i2c Master
            #                uint8_t  port;              // I2C Port
            #                uint8_t  engine;            // I2C Engine
            #                uint8_t  devAddr;           // I2C Device Address
            #                uint8_t  mux_select;        // Some I2C devices are behind a mux, this says
            #                                            // what setting on the mux is required
            #            } PACKED i2cAccess;
            #            struct spiAccess_t
            #            {
            #                uint32_t spi_master_huid;  // HUID of SPI master
            #                uint8_t  engine;           // engine specific to eeprom
            #                uint16_t offset_KB;        // offset in KB of where record begins in eeprom
            #            } PACKED spiAccess;
            #        } PACKED eepromAccess;
            #        uint32_t cache_copy_size;   // Size of data saved in cache (in KB)
            #        uint32_t internal_offset;   // offset from start of EECACHE section where cached
            #                                    // data exists
            #        uint8_t  cached_copy_valid : 1,   // This bit is set when we think the contents of the
            #                                          // cache is valid.
            #        master_eeprom              : 1,   // This bit marks this record as the master one (i.e. look at this one for change)
            #        unused                     : 6;
            #
            #    } PACKED completeRecord;
            #
            #    struct uniqueRecord
            #    {
            #        uint8_t uniqueID [NUM_BYTE_UNIQUE_ID];
            #        uint8_t metaData [sizeof(completeRecord) - NUM_BYTE_UNIQUE_ID];
            #    } PACKED uniqueRecord;

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

        if(uc $entryUniqueID eq uc $idToMatch)
        {
            $entryInfo{entry_offset} = $internal_offset;
            $entryInfo{entry_size}   = $cached_copy_size * 1024; # KB to Bytes
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


sub findEepromRecordOffset {



}

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

