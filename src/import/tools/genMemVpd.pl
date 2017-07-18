#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/tools/genMemVpd.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2019
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

################################################################################
# This script creates binary vpd files to be used to build the direct memory
# eeprom image. There are two 'types', MR and MT. MR is for the 'memory rotator'
# direct memory attributes and MT is for the 'memory terminator' direct memory
# attributes.
#
# For MR and MT, there can be unique attribute values based on the
# MCS position, the data rate of the system, and the rank count of the dimms
# plugged in.
#
# There are 16 possible MCS positions (4 possible procs x 4 MCS
# positions). MRW attribute ATTR_MEMVPD_POS, similiar to ATTR_FAPI_POS,
# but will differ on multiple node systems, goes from 0 to 15. For a
# 2 proc system, there will only be 8 MCSs, but up to 16 is supported by the
# script for the general case.
#
# Each dimm can have rank count 0 (not there), 1, 2, or 4 ranks. Each
# 'pair' combination (dimm0 rank count by dimm1 rank count), may need
# unique vpd attribute values. There are 16 combinations of dimm0 rank count by
# dimm1 rank count. For MR, the rank count is summarized into drop 1 for
# those combinations with only one dimm (a 0 in the pair) and  drop 2 for
# those combinations with two dimms (does not have a 0 in the pair).
#
# There are 1024 (16 MCS positions x 4 freqencies x 16 dimm rank pairs)
# configurations. In a particular system, some may not be supported and
# many commbinations will use the same attribute values. It was 'decided'
# to support up to 36 unique sets of values. For MR, they are stored in
# vpd keywords J0..J9,JA..JZ and for MT in vpd keywords X0..X9,XA..XZ.
# In practice, the eeprom will likely not be big enough for this many
# keywords (each is 255 bytes), so the actual number will be less.
#
# The 'values' for the attributes in a vpd keyword are provided in files
# with a '.vpd' extension and is in the format of an attribute override file,
# but only has direct values (no enumerations) so that this script does not
# have to be built to a particular build, like the attribute override tool.
#
# The vpd text file (.vpd extension) also has a header to specify the data
# rate frequencies and rank count pairs supported by the file. The 'target'
# line specifies the MCS positions supported. There can be multiple target
# lines, similiar to an attribute override file, but only one header which
# must preceed the first target line.
#
# example partial file: template_mr_00_freq_2400_2133_drop_2_1.vpd
#
# #DATA_RATE = 2400, 2133
# #NUM_DROPS = 2, 1
# target = k0:n0:s0:p9.mcs:p0,1:call
# #MSS:description:MR Keyword Layout Version Number.  Increases when attributes
# # are added, removed, or redefined.  Does not reset.
# #MSS:mssUnit:num
# ATTR_MSS_VPD_MR_0_VERSION_LAYOUT                      u8      0x00
# #MSS:description:MR Keyword Data Version Number.  Increases when data changes
# # with the above layout version.  Resets when layout version number
# # increments.
# #MSS:mssUnit:num
# ATTR_MSS_VPD_MR_1_VERSION_DATA                        u8      0x00
# #MSS:description:Hash Signature for the MT Keyword. The hash signature is
# # 32bits for 256 bytes of data.
# #MSS:mssUnit:hash
# ATTR_MSS_VPD_MR_2_SIGNATURE_HASH                      u32     0x00000000
# #MSS:description:Phase rotator delay value of command/address of A## in
# # ticks. Ticks are 1/128 of one cycle of clock.
# #MSS:mssUnit:tick
# ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00[0]              u8[2]   0x03
# ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00[1]              u8[2]   0x08
#
# example partial file: template_mt_00_dimm0dimm1_10_20_11_22.vpd
#
# #RANK_CONFIG = 0x10, 0x20, 0x11, 0x22
# target = k0:n0:s0:p9.mcs:p0,1:call
# #MSS:description:MT Keyword Layout Version Number.  Increases when attributes
# # are added, removed, or redefined.  Does not reset.
# #MSS:mssUnit:num
# ATTR_MSS_VPD_MT_0_VERSION_LAYOUT                        u8          0x00
# #MSS:description:MT Keyword Data Version Number.  Increases when data changes
# # with the above layout version.  Resets when layout version number increments
# #MSS:mssUnit:num
# ATTR_MSS_VPD_MT_1_VERSION_DATA                          u8          0x00
# #MSS:description:Hash Signature for the MT Keyword. The hash signature is
# # 32bits for 256 bytes of data.
# #MSS:mssUnit:encode
# ATTR_MSS_VPD_MT_2_SIGNATURE_HASH                        u32         0x00000000
# #MSS:description:Memory Controller side Read Vref setting. Dividing by 1000
# # gives you percentage of Vdd
# #MSS:enum:VDD40375 = 40375, ...
# #MSS:mssUnit:percent of Vdd
# ATTR_MSS_VPD_MT_VREF_MC_RD[0]                           u32[2]      0x000131AA
# ATTR_MSS_VPD_MT_VREF_MC_RD[1]                           u32[2]      0x000131AA
#
# The script parses the ATTR_ lines for values to build the binary file,
# but does not care about the specifics, other then data type (u8, u16,..)
# and value.
#
# The script also builds a "mapping" from the configurations in the vpd
# text files to the generated keyword files. The mapping is provided in
# a binary MR and MT keyword file. At run time, the getVPD call is passed
# a VPDInfo structure with frequency and dimm counts. The target's MEMVPD_POS,
# frequency, and dimm rank count pair is used with the MR or MT keyword
# mapping to select a vpd keyword (X0..XZ or J0..JZ), returning the values.
#
# More details...
#
# The format of the file name of the vpd text files is:
# $SystemName_$KeyWordType_$DecoderVersion_$KeyWordDependentInfo.vpd
# $KeyWordType is expected to be MR or MT (case insensitive)
# The script picks the files with the highest $DecoderVersion and
# replaces the output files.
# $SystemName_$KeyWordType is a required parameter, called the 'prefix'.
#
# The input and output directories can be optionally specified as parameters.
# The same directory can be used for both. The default is to use the
# directory where the script is (./).
#
# The script also creates 3 information files.
# $SystemName_$KeyWordType_mapping.csv has a text version of the mapping
# keyword for human readable convenience.
# $SystemName_$KeyWordType_trace.txt has a detailed execution trace for
# debuging.
# $SystemName_$KeyWordType_report.csv shows the mapped to keyword
# for each of the 1024 possible configurations along with the vpd text
# file it came from. There should not be any "duplicates", meaning there
# was a overlap in the vpd text file specifications. Either the vpd text
# files need to be fixed, or there is a bug in the script. The report
# can also be used to debug if at run time the wrong vpd is thought to have
# been returned.

#TODO RTC:154580 support split eeproms

use strict;

################################################################################
# Use of the following packages
################################################################################

use Getopt::Long;

################################################################################
# define constants and data type conventions
################################################################################

# a number is a hash with these members
use constant NUM_VALUE => "num_value";    #numeric value
use constant NUM_SIZE  => "num_size";     #number of bytes

# a fileInfo is a hash with these members
use constant FILE_NAME => "file_name";    #name of the binary file to write
use constant FILE_SIZE => "file_size";    #final size to create
use constant FILE_DATA => "file_data";    #array to hold data until written
use constant FILE_PTR  => "file_ptr";     #current end of data pointer

# a configuration is a hash with these members
use constant CONF_MCS           => "config_mcs_mask";
use constant CONF_FREQ          => "config_freq_mask";
use constant CONF_RANK          => "config_rank_mask";
use constant CONF_KEY_CHAR      => "config_keyword_character";
use constant CONF_VPD_TEXT_FILE => "config_vpd_text_file";
use constant CONF_BIN_FILE      => "config_bin_file";

# global constants
use constant VPD_BIN_FILE_SIZE     => 255;    #all vpd binary key word file size
use constant DQ_VPD_BIN_FILE_SIZE  => 160;    # DQ vpd binary key word file size
use constant DQ_Q0_BIN_FILE_SIZE   => 36;     # DQ map file size (Q0)
use constant CKE_VPD_BIN_DATA_SIZE => 16;     # CKE "blob" size per MCS
use constant CKE_BIN_FILE_SIZE     => 136;    # CKE full binary file size
use constant VM_BIN_FILE_SIZE      => 4;      # VM (4-byte timestamp) binary file size

################################################################################
# configuration structures.
# These masks (and the version) are written to the binary mapping vpd keyword
# and used by the decode hwp.
################################################################################
use constant MAPPING_LAYOUT_VERSION => 1;    #version of decode algorithm

my %g_freqMask = (                           #frequency index to mask
    1866 => 0x80,                            #1866
    2133 => 0x40,                            #2133
    2400 => 0x20,                            #2400
    2666 => 0x10
);                                           #2666
use constant FREQ_ALL => 0xf0;

my %g_rankMask = (                           #dimm rank count pair to mask
    0x00 => 0x8000,
    0x01 => 0x4000,                          #dimm0 rank count=0 dimm1 rank count=1
    0x02 => 0x2000,
    0x04 => 0x1000,
    0x10 => 0x0800,
    0x11 => 0x0400,
    0x12 => 0x0200,                          #dimm0 rank count=1 dimm1 rank count=2
    0x14 => 0x0100,
    0x20 => 0x0080,
    0x21 => 0x0040,
    0x22 => 0x0020,
    0x24 => 0x0010,
    0x40 => 0x0008,
    0x41 => 0x0004,
    0x42 => 0x0002,                          #dimm0 rank count=4 dimm1 rank count=2
    0x44 => 0x0001
);

use constant RANK_DROP1 => 0x7888;           #pairs with just one dimm
use constant RANK_DROP2 => 0x0777;           #pairs with two dimms

my %g_mcsMask = (                            #MCS MEMVPD_POS to mask
    0  => 0x8000,                            #proc=0 mcs position=0 memvpd_pos=0
    1  => 0x4000,
    2  => 0x2000,
    3  => 0x1000,
    4  => 0x0800,                            #proc=1 mcs position=0 memvpd_pos=4
    5  => 0x0400,
    6  => 0x0200,
    7  => 0x0100,
    8  => 0x0080,                            #proc=2 mcs position=0 memvpd_pos=8
    9  => 0x0040,
    10 => 0x0020,
    11 => 0x0010,
    12 => 0x0008,                            #proc=3 mcs position=0 memvpd_pos=12
    13 => 0x0004,
    14 => 0x0002,
    15 => 0x0001
);
my $g_mcs_added_to_cfg = 0;

use constant MCS_ALL       => 0xffff;
use constant MAX_NUM_PROCS => 4;
use constant MAX_POSITION  => 3;

################################################################################
# Global data
################################################################################
my %g_configs = ();    #hash of configuration hashes (a list of all configs)
my $g_tarType = "";    #supported target types (MR, MT, Q#, CK)

################################################################################
# Main flow:
# - get parameters and validate
# - get list of vpd text files to process
# - process each vpd text file
# - construct mapping and keyword binary file
# - construct report
################################################################################

sub main { }
my $cfgPrefix          = undef;
my $cfgInputVpdTextDir = ".";
my $cfgOutputVpdBinDir = ".";
my $cfgHelp            = 0;
my $cfgVerbose         = 0;
my $cfgVersion         = undef;
my %ckeKeywordData;    # CKE hash table (mcsMask -> hash ref with blob data for those masked mcs's)

# Process command line parameters, issue help text if needed
GetOptions(
    "prefix=s"             => \$cfgPrefix,
    "version:s"            => \$cfgVersion,
    "input-vpd-text-dir:s" => \$cfgInputVpdTextDir,
    "output-vpd-bin-dir:s" => \$cfgOutputVpdBinDir,
    "help"                 => \$cfgHelp,
    "verbose"              => \$cfgVerbose
);

if ($cfgHelp)
{
    display_help();
    exit(0);
}

# Check mandatory parameters
if ( $cfgPrefix eq undef )
{
    print STDERR "\n==>prefix is a required parameter\n";
}

if ( $cfgPrefix eq undef )
{
    display_help();
    exit(1);
}

# Validate vpd type
{
    ( my $system, $g_tarType ) = $cfgPrefix =~ m/^(.*?)_(\S+)/;
    $g_tarType = uc $g_tarType;
    if (   ( "MR" ne $g_tarType )
        && ( "MT" ne $g_tarType )
        && ( "CKE_MAP" ne $g_tarType )
        && ( "DQ_MAP" ne $g_tarType )
        && ( "VM" ne $g_tarType ) )
    {
        fatal( "error in --prefix parameter: $cfgPrefix" . " unsupported target type = $g_tarType" );
    }
}

# Ensure directories consistently end with a /
{
    local $/ = '/';    #use temporary version of $/ for the chomp
    chomp($cfgInputVpdTextDir);
    $cfgInputVpdTextDir .= "/";

    chomp($cfgOutputVpdBinDir);
    $cfgOutputVpdBinDir .= "/";
}

# Show parameters
{
    verbose("Parameters=");
    verbose("    Prefix = $cfgPrefix");
    verbose("    Input vpd text file directory = $cfgInputVpdTextDir");
    verbose("    Ouput vpd bin file directory =  $cfgOutputVpdBinDir");
}

# skip vpd input files for VM type
if ( "VM" ne $g_tarType )
{
    # Get the list of input vpd text files from the input directory
    my @vpdTextFiles = getVpdTextFileList( $cfgInputVpdTextDir, $cfgPrefix );
    {
        my $numVpdTextFiles = scalar(@vpdTextFiles);
        if ( $numVpdTextFiles == 0 )
        {
            fatal("No input vpd text files");
        }
        verbose("Input Vpd Text Files ($numVpdTextFiles)=");
        foreach my $file (@vpdTextFiles)
        {
            verbose("    $file");
        }
    }

    # Process vpd text files
    foreach my $file (@vpdTextFiles)
    {
        if ( "CKE_MAP" eq $g_tarType )
        {
            processCkeVpdTextFile( $file, \%ckeKeywordData );
        }
        else
        {
            processVpdTextFile($file);
        }
    }
}

# Create VPD mapping binary file
if ( "DQ_MAP" eq $g_tarType )
{
    createDqMappingFile();
}
elsif ( "CKE_MAP" eq $g_tarType )
{
    createCkBinaryFile( \%ckeKeywordData );
    verbose("Output binary Vpd File=");
    verbose( "    $cfgPrefix" . "_CKE.bin" );

    verbose("Support files created(1)=");
    verbose( "    $cfgPrefix" . "_trace.csv" );
}
elsif ( "VM" eq $g_tarType )
{
    unless (defined ($cfgVersion))
    {
        fatal( "Need to supply a version (0-F) for VM keyword" );
    }
    unless ($cfgVersion =~ m/^(0x)?[[:xdigit:]]$/)
    {
        fatal( "Invalid VM version ($cfgVersion), must be a single character (0-F)" );
    }

    createVMFile();
    # createVMFile already reported created file
    verbose("Support file created:");
    verbose( "   $cfgPrefix" . "_trace.txt" );
}
else
{
    createMappingFile();
}

# Create report
if ( ("CKE_MAP" ne $g_tarType) &&
     ("VM" ne $g_tarType) )
{
    createReport();

    # Show what files have been created
    {
        my @keys = sort { $a <=> $b } keys %g_configs;
        my $numBinVpdFiles = ( scalar @keys ) + 1;
        verbose("Output binary Vpd Files ($numBinVpdFiles)=");
        if ( $g_tarType eq "DQ_MAP" )
        {
            verbose( "    $cfgPrefix" . "_Q0.bin" );
        }
        else
        {
            verbose( "    $cfgPrefix" . "_" . $g_tarType . ".bin" );
        }
        foreach my $key (@keys)
        {
            my $ref_config = $g_configs{$key};
            verbose("    $ref_config->{CONF_BIN_FILE}");
        }
        verbose("Support files created(3)=");
        verbose( "    $cfgPrefix" . "_map.csv" );
        verbose( "    $cfgPrefix" . "_report.csv" );
        verbose( "    $cfgPrefix" . "_trace.csv" );
    }

}

verbose("Successful completion");
exit(0);

################################################################################
# Get the list of input vpd text files from input directory
#
# file name format =
#      $SystemName_$KeyWordType_$DecoderVersion_$KeyWordDependentInfo.vpd
# Return the files of the highest $DecoderVersion. This is the mem
# team decode version of the vpd data, not the decode of the selection
# criteria done by p9_get_mem_vpd_keyword.C
################################################################################
sub getVpdTextFileList
{
    my ( $inputVpdTextDir, $prefix ) = @_;

    opendir( FILEDIR, $inputVpdTextDir )
        || fatal("Couldn't open input vpd text file dir $inputVpdTextDir: $!");

    # get ALL the vpd files to find the largest vpd decode version
    my @allVpdTextFiles    = grep {/^$prefix.*vpd/} readdir(FILEDIR);
    my $largestDecode      = "";
    my $largestDecodeValue = -1;
    foreach my $vpdFile (@allVpdTextFiles)
    {
        my ( $system, $tarType ) = $prefix =~ m/^(.*?)_(\S+)/;
        my ( $decode, $rest )    = $vpdFile =~ m/^${prefix}_(.*?)_(\S+)/;

        my $decodeValue = eval($decode);
        if ( undef eq $decodeValue )
        {
            warning("decode $decode is not a number: $vpdFile SKIPPED");
        }
        if ( $decodeValue > $largestDecodeValue )
        {
            $largestDecodeValue = $decodeValue;
            $largestDecode      = $decode;
        }
    }

    # only get files for the largest attribute decode version
    rewinddir(FILEDIR);
    my $prefixDecode = $prefix . "_" . $largestDecode;
    my @vpdTextFiles = grep {/^$prefixDecode.*vpd/} readdir(FILEDIR);

    closedir FILEDIR;

    return @vpdTextFiles;
}

################################################################################
# Process CKE vpd text file
#
# Parsing logic:
# - keep reading lines as long as $stateKeepReading
# - first target line marks the end of the header
# - there can be multiple target lines
################################################################################
sub processCkeVpdTextFile
{
    my ( $vpdFile, $io_cke_entries ) = @_;  # vpd text file, %hash ref to be appended (mscMask, hash ref with blob data)

    trace( "Process cke vpd text file = " . $vpdFile );

    my %config   = ();                      # configuration for current section
    my %fileInfo = ();                      # fileInfo for current section
    my $mcsMask  = 0;                       # MCS mask for this target
    my $row      = 0;                       # row count for error message

    # Open vpd text file to parse
    open( VPDINPUTTEXT, "<$cfgInputVpdTextDir$vpdFile" )
        or fatal("open failed for $cfgInputVpdTextDir$vpdFile: $!");

    # State variables to control parsing the vpd text file
    my $stateKeepReading = 1;               #keep reading lines until EOF
    my $stateProcHeader  = 1;               #process header lines until first target line
    my $stateProcSection = 0;               #working on the attributes for a target line

    while ($stateKeepReading)
    {
        # Actions to be be performed based on this line of text
        my $actionTarget    = 0;
        my $actionAttr      = 0;
        my $actionWriteFile = 0;

        my $line = <VPDINPUTTEXT>;
        $line =~ s/(\r|\n)//g;

        $row++;
        if ($line)    #determine all actions based on text line
        {
            if ( $line =~ /ATTR_/ )    #first since will be the most of these
            {
                if ($stateProcHeader)
                {
                    fatal( "ATTR before header complete:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                $actionAttr = 1;
            }
            elsif ( $line =~ /target/ )
            {
                $stateProcHeader = 0;
                $actionTarget    = 1;

                if ($stateProcSection)
                {
                    $actionWriteFile = 1;    #process previous section before next
                }
            }

            # At this point, everything of interest has been processed.
            # The only lines not processed above should be comment lines,
            # which can be ignored (skipped).
        }
        else    # determine actions based on hitting end of the text file
        {
            $stateKeepReading = 0;
            if ($stateProcSection)
            {
                $actionWriteFile = 1;
            }
        }

        # Process all actions needed based on text line

        # needs to be before target in case there is a previous target to
        # finish out before starting the next section.
        if ($actionWriteFile)
        {
            $io_cke_entries->{$mcsMask} = {%fileInfo};
            trace(    "Adding CKE entry "
                    . sprintf( "0x%02X", $mcsMask )
                    . " -> name: "
                    . $fileInfo{FILE_NAME}
                    . ", size: "
                    . $fileInfo{FILE_SIZE}
                    . ", ptr: "
                    . $fileInfo{FILE_PTR} );
        }
        if ($actionTarget)
        {
            $mcsMask          = procTarget( $line, $vpdFile, $row );
            $stateProcSection = 1;
            %fileInfo         = newFileInfo( $vpdFile, CKE_VPD_BIN_DATA_SIZE );
        }
        if ($actionAttr)
        {
            my ( $attr, $type, $value ) = split( /\s+/, $line );
            my %num = newNum( $value, $type );
            trace("   $attr $type $value bytes=$num{NUM_SIZE}");
            filePushNum( \%fileInfo, \%num );
        }
    }
}

################################################################################
# Process vpd text file
#
# Parsing logic: (example of vpd text file in initial prologue)
# - keep reading lines as long as $stateKeepReading
# - process the header, which has the frequrency and rank pair/drop
#   configuration lines
# - the first target line marks the end of the header.
# - there can be multiple target lines
################################################################################

sub processVpdTextFile
{
    my ($vpdFile) = @_;

    trace( "Process file = " . $vpdFile );

    my %config   = ();    # configuration for current section
    my %fileInfo = ();    # fileInfo for current section
    my $freqMask = 0;     # frequenices (data rates) for this vpd file
    my $rankMask = 0;     # dimm rank count pairs for this vpd file
    my $mcsMask  = 0;     # MCS mask for this target
    my $row      = 0;     # row count for error message

    # Open vpd text file to parse
    open( VPDINPUTTEXT, "<$cfgInputVpdTextDir$vpdFile" )
        or fatal("open failed for $cfgInputVpdTextDir$vpdFile: $!");

    # State variables to control parsing the vpd text file
    my $stateKeepReading   = 1;    #keep reading lines until EOF
    my $stateProcHeader    = 1;    #process header lines until first target line
    my $stateProcSection   = 0;    #working on the attributes for a target line
    my $stateDataRateSet   = 0;    #Data Rate (frequency) as been found or default
    my $stateRankConfigSet = 0;    #Rank Count (drop) has been found

    while ($stateKeepReading)
    {
        # Actions to be be performed based on this line of text
        my $actionDataRate   = 0;
        my $actionRankConfig = 0;
        my $actionDropConfig = 0;
        my $actionTarget     = 0;
        my $actionAttr       = 0;
        my $actionWriteFile  = 0;

        my $line = <VPDINPUTTEXT>;
        $line =~ s/(\r|\n)//g;

        $row++;
        if ($line)    #determine all actions based on text line
        {
            if ( $line =~ /ATTR_/ )    #first since will be the most of these
            {
                if ($stateProcHeader)
                {
                    fatal( "ATTR before header complete:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                $actionAttr = 1;
            }
            elsif ( $line =~ /DATA_RATE/ )
            {
                if ( !$stateProcHeader )
                {
                    fatal( "DATA_RATE outside of header:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                $actionDataRate = 1;
            }
            elsif ( $line =~ /RANK_CONFIG/ )
            {
                if ( !$stateProcHeader )
                {
                    fatal( "RANK_CONFIG outside of header:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                $actionRankConfig = 1;
            }
            elsif ( $line =~ /NUM_DROPS/ )
            {
                if ( !$stateProcHeader )
                {
                    fatal( "NUM_DROPS outside of header:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                $actionDropConfig = 1;
            }
            elsif ( $line =~ /target/ )
            {
                # MT files can default to all frequencies if not specified
                if (   ( !$stateDataRateSet )
                    && ( "MT" eq $g_tarType ) )
                {
                    $freqMask = FREQ_ALL;
                    trace( "Freq Mask = 0x" .
                           sprintf( "%02X", $freqMask ) . " - DEFAULT VALUE" );
                    $stateDataRateSet = 1;
                }
                if (   ( $stateDataRateSet and $stateRankConfigSet )
                    || ( "DQ_MAP" eq $g_tarType ) )
                {
                    $stateProcHeader = 0;
                    $actionTarget    = 1;
                }
                else
                {
                    fatal( "target before header is complete:\n" .
                           "    $vpdFile\n" . "    row $row:$line" );
                }
                if ($stateProcSection)
                {
                    $actionWriteFile = 1;    #process previous section before next
                }
            }

            # At this point, everthing of interest has been processed.
            # The only lines not processed above should be comment lines,
            # which can be ignored (skipped).
        }
        else    # determine actions based on hitting end of the text file
        {
            $stateKeepReading = 0;
            if ($stateProcSection)
            {
                $actionWriteFile = 1;
            }
        }

        # Process all actions needed based on text line
        if ($actionDataRate)
        {
            $freqMask = procDataRate( $line, $vpdFile, $row );
            $stateDataRateSet = 1;
        }
        if ($actionRankConfig)
        {
            $rankMask = procRankConfig( $line, $vpdFile, $row );
            $stateRankConfigSet = 1;
        }
        if ($actionDropConfig)
        {
            $rankMask = procDropConfig( $line, $vpdFile, $row );
            $stateRankConfigSet = 1;
        }

        # needs to be before target in case there is a previous target to
        # finish out before starting the next section.
        if ($actionWriteFile)
        {
            trace( "addConfiguration for " . $vpdFile . " -> " . $config{CONF_BIN_FILE} );
            addConfiguration( \%config );    #capture final configuration
            fileWrite( \%fileInfo );
        }
        if ($actionTarget)
        {
            $mcsMask = procTarget( $line, $vpdFile, $row );
            $g_mcs_added_to_cfg |= $mcsMask;
            $stateProcSection = 1;
            %config           = ();
            %config           = newConfiguration( $mcsMask, $freqMask, $rankMask, $vpdFile );
            %fileInfo         = ();
            if ( "DQ_MAP" eq $g_tarType )
            {
                %fileInfo = newFileInfo( $config{CONF_BIN_FILE}, DQ_VPD_BIN_FILE_SIZE );
            }
            else
            {
                %fileInfo = newFileInfo( $config{CONF_BIN_FILE}, VPD_BIN_FILE_SIZE );
            }

            traceConfig( "createConfig:", \%config );
        }
        if ($actionAttr)
        {
            my ( $attr, $type, $value ) = split( /\s+/, $line );
            my %num = newNum( $value, $type );
            trace("   $attr $type $value bytes=$num{NUM_SIZE}");
            filePushNum( \%fileInfo, \%num );
        }
    }
}

# process the DATA_RATE line
#
# Must be in the 'header' before the first 'target' line
# # DATA_RATE = XXXX[,XXXX,XXXX,XXXX]
# at least one frequency, up to 4 frequencies
sub procDataRate
{
    my ( $line, $file, $row ) = @_;

    my $freqMask = 0;

    ( undef, my $rest ) = split( /\=/, $line );

    my @freqs = split( /\,/, $rest );
    foreach my $freqText (@freqs)
    {
        my $freq = eval($freqText);
        if ( undef eq $freq )
        {
            fatal( "Invalid freq value = $freqText\n" .
                   "   $file\n" . "   row $row: $line" );
        }

        if ( undef eq $g_freqMask{$freq} )
        {
            fatal( "$freq not a supported value\n" .
                   "   $file\n" . "   row $row: $line" );
        }
        else
        {
            $freqMask |= $g_freqMask{$freq};
        }
    }
    trace( "Freq Mask = 0x" . sprintf( "%02X", $freqMask ) );
    return $freqMask;
}

# process the RANK_CONFIG line
#
# Must be in the 'header' before the first 'target' line
# # RANK_CONFIG = 0xXX[,0xXX,...,0xXX]
# X = 0,1,2, or 4
# at least one dimm count pair, up to 16 pairs
# the 0xXX format is for reability, its just a number (0x10 same as 16).
# The first X is dimm0 rank count. Second is dimm1 rank count.
sub procRankConfig
{
    my ( $line, $file, $row ) = @_;

    my $rankMask = 0;

    ( undef, my $rest ) = split( /\=/, $line );

    my @ranks = split( /\,/, $rest );
    foreach my $rankText (@ranks)
    {
        my $rank = eval($rankText);
        if ( undef eq $rank )
        {
            fatal( "Invalid rank value = $rankText\n" .
                   "   $file\n" . "   row $row: $line" );
        }
        my $mask = $g_rankMask{$rank};
        if ( undef == $mask )
        {
            fatal(    "Unsupported rank configuration = 0x"
                    . sprintf( "%02X", $rank ) . "\n"
                    . "   $file\n"
                    . "   row $row: $line" );
        }
        $rankMask |= $mask;
    }
    trace( "Rank Config = 0x" . sprintf( "%04X", $rankMask ) );
    return $rankMask;
}

# process the NUM_DROPS line
#
# Must be in the 'header' before the first 'target' line
# # NUM_DROPS = X[,X]
# X = 0 or 1
sub procDropConfig
{
    my ( $line, $file, $row ) = @_;

    my $dropMask = 0;

    ( undef, my $rest ) = split( /\=/, $line );

    my @drops = split( /\,/, $rest );
    foreach my $dropText (@drops)
    {
        my $drop = eval($dropText);
        if ( undef eq $drop )
        {
            fatal( "Invalid drop value = $dropText\n" .
                   "   $file\n" . "   row $row: $line" );
        }
        if ( 1 == $drop )
        {
            $dropMask |= RANK_DROP1;
        }
        elsif ( 2 == $drop )
        {
            $dropMask |= RANK_DROP2;
        }
        else
        {
            fatal( "Unsupported drop configuration = $drop\n" .
                   "   $file\n" . "   row $row: $line" );
        }
    }
    trace( "Num Drops Config = 0x" . sprintf( "%04X", $dropMask ) );
    return $dropMask;
}

# process the target line
#
# Concludes the 'header'.
# target = k0:n0:s0:p9.mcs:pXXX:cXXX
# XXX = all or a list of comma separated positions (0,1,2 or 3).
sub procTarget
{
    my ( $line, $file, $row ) = @_;

    my $mcsMask = 0;

    ( undef, my $rest ) = split( /\=/, $line );
    ( undef, undef, undef, my $p9mcs, my $proc, my $chip ) = split( /\:/, $line );

    if (   ( "p9.mcs" ne $p9mcs )
        && ( "pu.mcs" ne $p9mcs )
        && ( "p9n.mcs" ne $p9mcs ) )
    {
        fatal(    "Invalid target value = $p9mcs, "
                . "p9.mcs, pu.mcs or p9n.mcs expected\n"
                . "   $file\n"
                . "   row $row: $line" );
    }

    my @plist = procPositions( $line, $file, $row, $proc, "p" );
    my @clist = procPositions( $line, $file, $row, $chip, "c" );

    #The MCS bit mask (g_mscMask) is based on the ATTR_MEMVPD_POS of the MCS.
    #The MEMVPD_POS is the hash key to find the mask value in g_mscMask.
    #Proc 0 MCS 0 is bit 0x8000. MEMVPD_POS = 0
    #Proc 0 MCS 1 is bit 0x4000. MEMVPD_POS = 1, ... etc.
    #MEMVPD_POS can be calculated by proc num * 4 + mcs position within the proc
    foreach my $ppos (@plist)
    {
        foreach my $cpos (@clist)
        {
            my $memVpdPos = ( $ppos * 4 ) + $cpos;
            $mcsMask |= $g_mcsMask{$memVpdPos};
        }
    }

    trace( "Target Mask = 0x" . sprintf( "%04X", $mcsMask ) );
    return $mcsMask;
}

# helper to get list of MemPos in mcsMask;
sub convertMcsMaskToMemPosArray
{
    my ($mcsMask) = @_;

    #printf("Target Mask = 0x".sprintf("%04X",$mcsMask)."\n");

    my @aMemPos;

    my %bitToPos = reverse %g_mcsMask;

    foreach my $bitPos ( keys %bitToPos )
    {
        if ( ( $bitPos & $mcsMask ) == $bitPos )
        {
            push( @aMemPos, $bitToPos{$bitPos} );
        }
    }
    return @aMemPos;
}

# helper to process positions
# pXXX or cXXX
# where XXX is "all" or a comma separated list of digits 0,1,2,3
sub procPositions
{
    my ( $line, $file, $row, $position, $expected ) = @_;

    my @list = ();

    my $type = substr( $position, 0, 1 );
    my $rest = substr( $position, 1 );
    if ( $type ne $expected )
    {
        fatal( "Invalid target specification $type, $expected expected\n" .
               "   $file\n" . "   row $row: $line" );
    }

    if ( "ALL" eq uc($rest) )
    {
        for ( my $i = 0; $i < MAX_NUM_PROCS; $i++ )
        {
            $list[$i] = $i;
        }
    }
    else
    {
        my $i = 0;
        my @positions = split( /\,/, $rest );
        foreach my $posText (@positions)
        {
            my $pos = eval($posText);
            if ( undef eq $pos )
            {
                fatal( "Invalid position value = $posText\n" .
                       "   $file\n" . "   row $row: $line" );
            }
            if ( MAX_POSITION < $pos )
            {
                fatal(    "Position out of 0 to "
                        . MAX_POSITION
                        . " range  = $posText\n"
                        . "   $file\n"
                        . "   row $row: $line" );
            }
            $list[ $i++ ] = $pos;
        }
    }
    return @list;
}

################################################################################
# File functions
################################################################################

# create a new file info
sub newFileInfo
{
    my ( $fileName, $fileSize ) = @_;

    my %fileInfo = ();
    $fileInfo{FILE_NAME} = $fileName;
    $fileInfo{FILE_SIZE} = $fileSize;
    $fileInfo{FILE_PTR}  = 0;

    return %fileInfo;
}

# append "number" to the end of data to be written
sub filePushNum
{
    my $ref_fileInfo = shift;
    my $ref_num      = shift;

    my $newPtr = $ref_fileInfo->{FILE_PTR} + $ref_num->{NUM_SIZE};
    if ( $newPtr > $ref_fileInfo->{FILE_SIZE} )
    {
        fatal(    "bin file size exceeded\n"
                . "    file=$ref_fileInfo->{FILE_NAME}\n"
                . "    limit=$ref_fileInfo->{FILE_SIZE}" );
    }
    $ref_fileInfo->{FILE_PTR} = $newPtr;

    my $fullValue = $ref_num->{NUM_VALUE};
    my $byteValue = $fullValue % 256;
    for ( my $i = 0; $i < $ref_num->{NUM_SIZE}; $i++ )
    {
        $newPtr--;
        $ref_fileInfo->{FILE_DATA}[$newPtr] = $byteValue;    #big endian order
        $fullValue -= $byteValue;
        $fullValue /= 256;
        $byteValue = $fullValue % 256;
    }
}

# Write the data to the file
sub fileWrite
{
    my $ref_fileInfo = shift;

    my $outBinFile = $cfgOutputVpdBinDir . $ref_fileInfo->{FILE_NAME};
    open( BIN_FILE, ">:raw", $outBinFile )
        || fatal("couldn't open $outBinFile: $!");

    for ( my $i = 0; $i < $ref_fileInfo->{FILE_PTR}; $i++ )
    {
        print BIN_FILE pack( 'C', $ref_fileInfo->{FILE_DATA}[$i] );
    }
    for ( my $i = $ref_fileInfo->{FILE_PTR}; $i < $ref_fileInfo->{FILE_SIZE}; $i++ )
    {
        print BIN_FILE pack( 'C', 0 );
    }
    close(BIN_FILE);
    my $pad = $ref_fileInfo->{FILE_SIZE} - $ref_fileInfo->{FILE_PTR};

    trace( "create bin file = $ref_fileInfo->{FILE_NAME} " .
           "data=$ref_fileInfo->{FILE_PTR} pad = $pad" );
}

################################################################################
# Configuration helpers
################################################################################

# create a configuration
my $static_keyChar = undef;

sub newConfiguration
{
    my ( $mcsMask, $freqMask, $rankMask, $vpdFile ) = @_;

    my %config = ();
    $config{CONF_MCS}           = $mcsMask;
    $config{CONF_FREQ}          = $freqMask;
    $config{CONF_RANK}          = $rankMask;
    $config{CONF_VPD_TEXT_FILE} = $vpdFile;

    if ( undef eq $static_keyChar )
    {
        $static_keyChar = '0';
        if ( "DQ_MAP" eq $g_tarType )
        {
            # Q0 is reserved for mapping
            $static_keyChar = '1';
        }
    }
    elsif ( '9' eq $static_keyChar )
    {
        $static_keyChar = 'A';
    }
    elsif ( 'Z' eq $static_keyChar )
    {
        fatal("Ran out of keyword characters");
    }
    else
    {
        $static_keyChar++;
    }
    $config{CONF_KEY_CHAR} = ord($static_keyChar);

    my $binFileName = "";
    if ( "MR" eq uc $g_tarType )
    {
        $binFileName = $cfgPrefix . '_J' . $static_keyChar . ".bin";
    }
    elsif ( "MT" eq uc $g_tarType )
    {
        $binFileName = $cfgPrefix . '_X' . $static_keyChar . ".bin";
    }
    elsif ( "DQ_MAP" eq uc $g_tarType )
    {
        $binFileName = $cfgPrefix . '_Q' . $static_keyChar . ".bin";
    }
    else
    {
        fatal("unsupported target type = $g_tarType");
    }
    $config{CONF_BIN_FILE} = $binFileName;

    return %config;
}

# capture a copy of a configuration and add to global list
sub addConfiguration
{
    my $ref_config = shift;

    my %config = %{$ref_config};    #create a copy

    $g_configs{ $config{CONF_KEY_CHAR} } = \%config;
}

sub createCkBinaryFile
{
    my ($rCkeKeywordData) = @_;

    # open file for binary version of mapping data
    my %fileInfo = newFileInfo( $cfgPrefix . "_CK.bin", CKE_BIN_FILE_SIZE );
    trace( "Create output binary file: " . $fileInfo{FILE_NAME} );

    # start with header
    #   - version
    #   - number of entries
    #   - size of data entries (blob size)
    #   - reserved
    my %num = newNum( MAPPING_LAYOUT_VERSION, "u8" );
    filePushNum( \%fileInfo, \%num );
    str2num( \%num, 8, "u8" );
    filePushNum( \%fileInfo, \%num );

    # bytes per data entry
    str2num( \%num, 16, "u8" );
    filePushNum( \%fileInfo, \%num );
    str2num( \%num, 0, "u8" );
    filePushNum( \%fileInfo, \%num );

    for ( my $i = 0; $i < 8; $i++ )    # only room for 2 processors (4 pos per processor)
    {
        my $mcsMaskBit  = $g_mcsMask{$i};
        my $added_entry = 0;

        foreach my $key ( keys %$rCkeKeywordData )
        {
            if ( ( $key & $mcsMaskBit ) == $mcsMaskBit )
            {
                my $newDataPtr = $fileInfo{FILE_PTR};
                my $rblobData  = $rCkeKeywordData->{$key};

                trace("$i -- Found CKE entry:");
                trace(    "Key "
                        . sprintf( "0x%02X", $key )
                        . " -> name: "
                        . $rblobData->{FILE_NAME}
                        . ", size: "
                        . $rblobData->{FILE_SIZE}
                        . ", ptr: "
                        . $rblobData->{FILE_PTR} );

                # add one glob of data for the section
                for ( my $i = 0; $i < $rblobData->{FILE_PTR}; $i++ )
                {
                    trace( "Adding " . sprintf( "0x%02X", $rblobData->{FILE_DATA}[$i] ) .
                           " to index " . $newDataPtr );
                    $fileInfo{FILE_DATA}[ $newDataPtr++ ] = $rblobData->{FILE_DATA}[$i];
                }
                trace( "File_ptr = " . $newDataPtr . ", previously " . $fileInfo{FILE_PTR} );
                $fileInfo{FILE_PTR} = $newDataPtr;

                str2num( \%num, 0, "u8" );
                for ( my $i = $rblobData->{FILE_PTR}; $i < $rblobData->{FILE_SIZE}; $i++ )
                {
                    filePushNum( \%fileInfo, \%num );
                }
                $added_entry = 1;
            }
        }
        if ( $added_entry == 0 )
        {
            trace( "No entry found for $i " . sprintf( "(0x%02X)", $mcsMaskBit ) );

            # add a blank entry for missing vpd
            str2num( \%num, 0, "u8" );
            for ( my $i = 0; $i < CKE_VPD_BIN_DATA_SIZE; $i++ )
            {
                filePushNum( \%fileInfo, \%num );
            }
        }
    }
    fileWrite( \%fileInfo );
}

sub createDqMappingFile
{
    # open file for human readable csv version of mapping data
    ( my $system, my $tarType ) = $cfgPrefix =~ m/^(.*?)_(\S+)/;
    my $outCsvFile = $cfgOutputVpdBinDir . $cfgPrefix . "_map.csv";
    trace("createDqMappingFile: $outCsvFile");
    open( CSV_FILE, ">$outCsvFile" )
        || fatal("Couldn't open $outCsvFile: $!");
    print CSV_FILE "MCS,KEYCHAR,VPDFILE\n";

    # open file for binary version of mapping data
    my %fileInfo = newFileInfo( $cfgPrefix . "_Q0.bin", DQ_Q0_BIN_FILE_SIZE );

    # start with header
    #   - version
    #   - number of mapped entries
    #   - size of data entries
    #   - reserved
    my %num = newNum( MAPPING_LAYOUT_VERSION, "u8" );
    filePushNum( \%fileInfo, \%num );

    # Number of map entries
    # i.e. count the number of bits set in $g_mcs_added_to_cfg (uint16 = 0..15)
    my $totalMappedEntries = grep $g_mcs_added_to_cfg & 1 << $_, 0 .. 15;
    trace("Adding $totalMappedEntries entries into map file");
    str2num( \%num, $totalMappedEntries, "u8" );
    filePushNum( \%fileInfo, \%num );

    # bytes per data entry
    str2num( \%num, 0, "u8" );
    filePushNum( \%fileInfo, \%num );
    str2num( \%num, 0, "u8" );
    filePushNum( \%fileInfo, \%num );

    my @keys = sort { $a <=> $b } keys %g_configs;
    foreach my $key (@keys)
    {
        my $ref_config = $g_configs{$key};
        my $mcsMask    = $ref_config->{CONF_MCS};
        my $keyChar    = $ref_config->{CONF_KEY_CHAR};
        my $vpdFile    = $ref_config->{CONF_VPD_TEXT_FILE};
        my $binFile    = $ref_config->{CONF_BIN_FILE};

        print CSV_FILE "0x"
            . sprintf( "%04X", $mcsMask ) . "," . "0x"
            . sprintf( "%02X", $keyChar ) . ","
            . chr($keyChar)
            . "-$vpdFile\n";

        my @memPositions = convertMcsMaskToMemPosArray($mcsMask);
        foreach my $mempos (@memPositions)
        {
            print CSV_FILE $mempos . ", " . chr($keyChar) . "\n";

            str2num( \%num, $mempos, "u8" );
            filePushNum( \%fileInfo, \%num );
            str2num( \%num, $keyChar, "u8" );
            filePushNum( \%fileInfo, \%num );
        }
    }

    fileWrite( \%fileInfo );
    close(CSV_FILE);
}

# create mapping bin file and csv
sub createMappingFile
{
    # open file for human readable csv version of mapping data
    ( my $system, my $tarType ) = split( /\_/, $cfgPrefix );
    my $outCsvFile = $cfgOutputVpdBinDir . $cfgPrefix . "_map.csv";
    trace("createMappingFile: $outCsvFile");
    open( CSV_FILE, ">$outCsvFile" )
        || fatal("Couldn't open $outCsvFile: $!");
    print CSV_FILE "MCS,RANK,FREQ,KEYCHAR,VPDFILE\n";

    # open file for binary version of mapping data
    my %fileInfo = newFileInfo( $cfgPrefix . "_" . uc($tarType) . ".bin", VPD_BIN_FILE_SIZE );

    # start with header
    #   - version
    #   - number of entries
    #   - reserved
    my %num = newNum( MAPPING_LAYOUT_VERSION, "u8" );
    filePushNum( \%fileInfo, \%num );
    str2num( \%num, scalar keys %g_configs, "u8" );
    filePushNum( \%fileInfo, \%num );
    str2num( \%num, 0, "u8" );
    filePushNum( \%fileInfo, \%num );

    my @keys = sort { $a <=> $b } keys %g_configs;
    foreach my $key (@keys)
    {
        my $ref_config = $g_configs{$key};

        my $mcsMask  = $ref_config->{CONF_MCS};
        my $freqMask = $ref_config->{CONF_FREQ};
        my $rankMask = $ref_config->{CONF_RANK};
        my $keyChar  = $ref_config->{CONF_KEY_CHAR};
        my $vpdFile  = $ref_config->{CONF_VPD_TEXT_FILE};
        my $binFile  = $ref_config->{CONF_BIN_FILE};

        print CSV_FILE "0x"
            . sprintf( "%04X", $mcsMask ) . "," . "0x"
            . sprintf( "%04X", $rankMask ) . "," . "0x"
            . sprintf( "%02X", $freqMask ) . "," . "0x"
            . sprintf( "%02X", $keyChar ) . ","
            . chr($keyChar)
            . "-$vpdFile\n";

        #write bin config line
        #  - MCS mask
        #  - Rank mask
        #  - Frequency mask
        #  - keyword character
        str2num( \%num, $mcsMask, "u16" );
        filePushNum( \%fileInfo, \%num );
        str2num( \%num, $rankMask, "u16" );
        filePushNum( \%fileInfo, \%num );
        str2num( \%num, $freqMask, "u8" );
        filePushNum( \%fileInfo, \%num );
        str2num( \%num, $keyChar, "u8" );
        filePushNum( \%fileInfo, \%num );
    }
    fileWrite( \%fileInfo );
    close(CSV_FILE);
}

# create a file and add a 4-byte binary timestamp
sub createVMFile
{
    # open file for binary version of mapping data
    my %fileInfo = newFileInfo( $cfgPrefix . "_VM.bin", VM_BIN_FILE_SIZE );
    trace( "Create output binary file: " . $fileInfo{FILE_NAME} );

    my $time = time;
    $time = $time & 0xfffffff0;
    $time = $time | hex($cfgVersion);
    my %num = newNum( $time, "u32" );
    filePushNum( \%fileInfo, \%num );
    fileWrite( \%fileInfo );
    verbose( "\nTranslated VM timestamp in file: ".
             scalar localtime($num{NUM_VALUE}) );
    verbose( "Created " . $cfgOutputVpdBinDir . $fileInfo{FILE_NAME} );
}

# create report
sub createReport
{
    my $numUnf = 0;
    my $numOK  = 0;
    my $numDup = 0;

    # open file for report. Report can be used to validate mapping.
    my $outCsvFile = $cfgOutputVpdBinDir . $cfgPrefix . "_report.csv";
    open( CSV_FILE, ">$outCsvFile" )
        || fatal("Couldn't open $outCsvFile: $!");
    trace("createReport: $outCsvFile");
    print CSV_FILE "CHK,MCS,FREQ,RANK,BINFILE,VPDFILE\n";

    my $numMCS  = scalar keys %g_mcsMask;
    my $numFreq = scalar keys %g_freqMask;
    my $numRank = scalar keys %g_rankMask;

    for ( my $i = 0; $i < $numMCS; $i++ )
    {
        my @freqs = sort { $a <=> $b } keys %g_freqMask;
        foreach my $freq (@freqs)
        {
            my @keys = sort { $a <=> $b } keys %g_rankMask;
            foreach my $key (@keys)
            {
                my @configList = checkConfig( $g_mcsMask{$i}, $g_freqMask{$freq}, $g_rankMask{$key} );
                my $numHits    = scalar @configList;
                my $status     = "";
                if ( 0 == $numHits )
                {
                    $status = "UNF";
                    print CSV_FILE "$status,$i,$freq," . "0x" . sprintf( "%02X", $key ) . ',"",""' . "\n";
                    $numUnf++;
                }
                else
                {
                    if ( 1 == $numHits )
                    {
                        $status = "OK ";
                        $numOK++;
                    }
                    else
                    {
                        $status = "DUP";
                        $numDup++;
                    }
                    for ( my $m = 0; $m < $numHits; $m++ )
                    {
                        print CSV_FILE "$status,$i,$freq," . "0x"
                            . sprintf( "%02X", $key ) . ","
                            . "$configList[$m]->{CONF_BIN_FILE},"
                            . "$configList[$m]->{CONF_VPD_TEXT_FILE}\n";
                    }
                }
            }
        }
    }
    verbose( "Of the " . $numMCS * $numFreq * $numRank . " combinations:" );
    verbose( "    " . sprintf( "%4D", $numOK ) . " are mapped to vpd data" );
    verbose( "    " . sprintf( "%4D", $numUnf ) . " are undefined" );
    verbose( "    " . sprintf( "%4D", $numDup ) . " are duplicated (should be 0)" );
    if ($numDup)
    {
        warning(  "There are $numDup duplicate mappings, there should be none.\n"
                . "   Review $cfgPrefix"
                . "_report.txt and correct the vpd files" );

    }
    close(CSV_FILE);
}

# Return list of configs that this configuration "hits"
# Ideally, it is just one or none. A dup means there is a overlap problem
# in the vpd text files
sub checkConfig
{
    my ( $mcsMask, $freqMask, $rankMask ) = @_;

    my @configList = ();
    trace(    "checkConfig:"
            . " mcsMask="
            . sprintf( "%04X", $mcsMask )
            . " freqMask="
            . sprintf( "%02X", $freqMask )
            . " rankMask="
            . sprintf( "%04X", $rankMask ) );

    my @keys = sort { $a <=> $b } keys %g_configs;
    foreach my $key (@keys)
    {
        my $ref_config = $g_configs{$key};
        my $status     = "UNF";

        my $mcsHit  = $mcsMask & $ref_config->{CONF_MCS};
        my $freqHit = $freqMask & $ref_config->{CONF_FREQ};
        my $rankHit = $rankMask & $ref_config->{CONF_RANK};
        if (   ( $mcsHit && $freqHit && $rankHit )
            || ( ( "DQ_MAP" eq $g_tarType ) && $mcsHit ) )
        {
            push @configList, $ref_config;
            $status = "HIT";
        }
        trace( "    $status==> " . $ref_config->{CONF_BIN_FILE} );
        trace( "        mscHit=0x" . sprintf( "%04X", $mcsHit ) .
               " 0x" . sprintf( "%04X", $ref_config->{CONF_MCS} ) );
        trace( "        freqHit=" . sprintf( "%02X", $freqHit ) .
               " 0x" . sprintf( "%02X", $ref_config->{CONF_FREQ} ) );
        trace( "        rankHit=" . sprintf( "%04X", $rankHit ) .
               " 0x" . sprintf( "%04X", $ref_config->{CONF_RANK} ) );
    }

    return @configList;
}

################################################################################
# Number helpers
################################################################################

# create a "number" hash
sub newNum
{
    my ( $value, $type ) = @_;

    my ($decSize) = $type =~ /u(\d+)/;
    my $byteSize = $decSize / 8;

    my %number = ();
    $number{NUM_VALUE} = str2value($value);
    $number{NUM_SIZE}  = $byteSize;

    return %number;
}

# update a "number" hash
sub str2num
{
    my $ref_num = shift;
    my $value   = shift;
    my $type    = shift;

    my ($decSize) = $type =~ /u(\d+)/;
    my $byteSize = $decSize / 8;

    $ref_num->{NUM_VALUE} = str2value($value);
    $ref_num->{NUM_SIZE}  = $byteSize;
}

# Convert a string into a numeric value scalar
sub str2value
{
    my ($text) = @_;

    my $value = eval($text);
    if ( $value eq undef )
    {
        fatal("str2value: $text is not a number");
    }

    return $value;
}

################################################################################
# trace and related helpers
################################################################################

# verbose to STDOUT and trace
sub verbose
{
    my ($text) = @_;

    if ($cfgVerbose)
    {
        print STDOUT $text . "\n";
    }
    trace($text);
}

# trace
my $static_traceInit = 0;

sub trace
{
    my ($text) = @_;

    if ( 0 == $static_traceInit )
    {
        my $outTextFile = $cfgOutputVpdBinDir . $cfgPrefix . "_trace.txt";
        open( TRACE_FILE, ">$outTextFile" )
            || fatal("couldn't open $outTextFile: $!");
        $static_traceInit = 1;
    }
    print TRACE_FILE $text . "\n";
}

# add a configuration to the trace
sub traceConfig
{
    my ( $tag, $ref_config ) = @_;

    my $mcsMask  = $ref_config->{CONF_MCS};
    my $freqMask = $ref_config->{CONF_FREQ};
    my $rankMask = $ref_config->{CONF_RANK};
    my $keyChar  = chr( $ref_config->{CONF_KEY_CHAR} );
    my $vpdFile  = $ref_config->{CONF_VPD_TEXT_FILE};
    my $binFile  = $ref_config->{CONF_BIN_FILE};

    trace("$tag $binFile");
    trace(    "   key=$keyChar mcsMask="
            . sprintf( "%04X", $mcsMask )
            . " freqMask="
            . sprintf( "%02X", $freqMask )
            . " rankMask="
            . sprintf( "%04X", $rankMask ) );
    trace("   from= $vpdFile");
}

#warning error
sub warning
{
    my ($text) = @_;

    trace("[WARNING!] $text");
    print STDERR "[WARNING!] $text\n";
}

#fatal error
sub fatal
{
    my ($text) = @_;

    trace("[FATAL!] $text");
    print STDERR "[FATAL!] $text\n";

    exit(1);
}

# Display the parameters
sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);

    print STDERR "
usage:
    $scriptname --help
    $scriptname --prefix <system_kw>
                [--version <single hex character>]
                [--input-vpd-text-dir=./] [--output-vpd-bin-dir=./]
                [--verbose]
        --prefix
             Prefix of vpd input files to process (template_MR or template_MT)
             Available kw = MR, MT, CKE_MAP, DQ_MAP and VM
        --version
             Hex character used in the last nibble of the VM keyword
        --input-vpd-text-dir
             Optional path to directory with input vpd files.
             Defaults to current directory (./)
        --output-vpd-bin-dir
             Optional path to directory for output binary and support files.
             Defaults to current directory (./)
        --verbose
             Optional additional execution information.
             Defaults to not verbose.
\n";
}
