#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/make_hb_hll.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2025
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
# This make_hb_hll.pl script only runs in FSP builds.  It creates unique
# HB_HLL files based on the different system and node configurations that
# require unique HBD (Hostboot Data, aka targeting and attributes) and
# WOFDATA content.
# The V3/*.entry files from an earlier pass of genPnorImages.pl are passed into
# this script such that a unuqie HB_HLL can be created and signed:
# [V3 Header of HB_HLL][HB_HLL TOC][List of HB_HLL entries]
################################################################################

use strict;
use Data::Dumper;
use File::Basename;
use Cwd qw(abs_path cwd);
use lib dirname abs_path($0);
use PnorUtils qw(run_command PAGE_SIZE);
use Getopt::Long qw(:config pass_through);
use constant MAX_COMP_ID_LEN => 8;

################################################################################
# Be explicit with POSIX
# Everything is exported by default (with a handful of exceptions). This is an
# unfortunate backwards compatibility feature and its use is strongly discouraged.
# You should either prevent the exporting (by saying use POSIX (); , as usual)
# and then use fully qualified names (e.g. POSIX::SEEK_END ), or give an explicit
# import list. If you do neither and opt for the default (as in use POSIX; ),
# you will import hundreds and hundreds of symbols into your namespace.
################################################################################
use POSIX ();

# Jail command for yocto froot
my $jailcmd = "";
if ($ENV{JAILCMD}) {
   $jailcmd = $ENV{JAILCMD};
}
print ("jailcmd = $jailcmd\n");

my $programName = File::Basename::basename $0;

# Flag parameter string passed into signing tools
# Note spaces before/after are critical.
use constant SIGNING_FLAG => " --flags ";
use constant SW_FLAG_HAS_A_HPT => 0x80000000;
# Security bits HW flag strings
use constant OPENPOWER_KEYS_FLAG  => 0x80000000;
use constant ENTERPRISE_KEYS_FLAG => 0x40000000;
# Applies to SBE image only
use constant LAB_SECURITY_OVERRIDE_FLAG => 0x00080000;
use constant KEY_TRANSITION_FLAG => 0x00000001;
# Size of HW keys' Hash and Secure Version
# NOTE: HW_KEYS_HASH_SIZE and SECURE_VERSION_SIZE have the same values
#       for V1 and V3 headers
use constant HW_KEYS_HASH_SIZE => 64;
use constant SECURE_VERSION_SIZE => 1;

# rand file prefix string. Note hbDistribute cleans up files with this prefix
use constant RAND_PREFIX => "rand-";


# Default to signing with enterprise signing keys
my $buildFlag = ENTERPRISE_KEYS_FLAG;

# Only building HB_HLL in this file, so use set the $eyeCatch here
my $eyeCatch = "HB_HLL";
my $componentId = convertEyecatchToCompId($eyeCatch);

# Signing modes
my $DEVELOPMENT = "development";
my $PRODUCTION = "production";
my $INDEPENDENT = "independent";
my $V1 = "V1";
my $V3 = "V3";
my $PRODTOPROD = "prod-prod";

################################################################################
# I/O parsing
################################################################################

my %globals = ();
my $bin_dir = cwd();
my $secureboot = 0;
my $system_target = "";
my $help = 0;
my $sign_mode = $DEVELOPMENT;
my $buildType="";
my $secureVersionStr="";
my $prefix="";
my $outFile="";
# Array of inputEntryFiles
my @inputEntryFiles =  ();
# Main array of entry files passed in; HB_HLL will be created from these files
my @entryFiles = ();

GetOptions("binDir:s" => \$bin_dir,
           "secureboot" => \$secureboot,
           "entryFiles:s" => \@inputEntryFiles,
           "sign-mode:s" => \$sign_mode,
           "build-type:s" => \$buildType,
           "secure-version:s" => \$secureVersionStr,
           "prefix:s" => \$prefix,
           "out-file:s" => \$outFile,
           "help" => \$help);

if ($help)
{
    usage();
    exit 0;
}

################################################################################
# Environment Setup, Checking, and Variable Initialization
################################################################################

# Put any future support for dynamically choosing between enterprise or
# OpenPOWER signing keys here

# Put mode transition input into a hash and ensure a valid signing mode
my %signMode = ( $DEVELOPMENT => 1,
                 $PRODUCTION => 0,
                 $INDEPENDENT => 0);

if ($sign_mode =~ m/^$DEVELOPMENT/i)
{}
elsif ($sign_mode =~ m/^$PRODUCTION/i)
{
    $signMode{$PRODUCTION} = 1;
    $signMode{$DEVELOPMENT} = 0;
    $signMode{$INDEPENDENT} = 0;
}
elsif ($sign_mode =~ m/^$INDEPENDENT/i)
{
    $signMode{$PRODUCTION} = 0;
    $signMode{$DEVELOPMENT} = 0;
    $signMode{$INDEPENDENT} = 1;
}
else
{
    die "Invalid signing mode = $sign_mode";
}

print "Check Signing and Dev key directory location set via env vars\n";

# Signing and Dev key directory location set via env vars
my $SIGNING_DIR_V3 = $ENV{'SIGNING_DIR'};

# Add relative path to the dev key directory
my $DEV_KEY_DIR = $ENV{'DEV_KEY_DIR'};

# For FSP builds must add "/test" at the end to line up
# with the new V1 and V3 sub-directories
if ($buildType eq "fspbuild")
{
    $DEV_KEY_DIR = "$DEV_KEY_DIR/test";
}
else
{
    die "Invalid buildType = $buildType (only 'fspbuild' is supported";
}
my $DEV_KEY_DIR_V3 = "$DEV_KEY_DIR/v3_keys";

# Create V3 sub-directory for the output files if it's not already there
run_command("mkdir -p $bin_dir/V3");

if ($secureboot)
{
    # Check all components needed for developer signing
    print "...input parameter Bin Dir: $bin_dir\n";
    print "...env variable DEV_KEY_DIR: $DEV_KEY_DIR\n";
    # V3
    print "...Check developer signing dir V3: $SIGNING_DIR_V3\n";
    die "Signing Dir = $SIGNING_DIR_V3 DNE" if(! -d $SIGNING_DIR_V3);
    print "...Check developer signing key dir V3: $DEV_KEY_DIR_V3\n";
    die "Dev Key Dir = $DEV_KEY_DIR_V3 DNE" if(! -d $DEV_KEY_DIR_V3);
    die "runtime_hw_key_a DNE in $DEV_KEY_DIR_V3" if(!glob("$DEV_KEY_DIR_V3/runtime_hw_key_a*"));
    die "runtime_hw_key_d DNE in $DEV_KEY_DIR_V3" if(!glob("$DEV_KEY_DIR_V3/runtime_hw_key_d*"));
    die "runtime_sw_key_p DNE in $DEV_KEY_DIR_V3" if(!glob("$DEV_KEY_DIR_V3/runtime_sw_key_p*"));
    die "runtime_sw_key_s DNE in $DEV_KEY_DIR_V3" if(!glob("$DEV_KEY_DIR_V3/runtime_sw_key_s*"));
}

### Open POWER signing
# In most cases this is desired, but do not override a value set by user
if(!$ENV{'SB_KEEP_CACHE'})
{
    $ENV{'SB_KEEP_CACHE'} = "true";
}


my $SIGN_REQUEST_V3=
    "$SIGNING_DIR_V3/crtSignedContainer.sh --scratchDir $bin_dir/V3/ -V 3 ";

# Check if secure version parameter was passed in and add it to the signing command, if necessary
if ($secureVersionStr eq "")
{
    # Without input set Secure Version 0
    $secureVersionStr = "0";
}
# Pass this parameter to the signing tool
$SIGN_REQUEST_V3 .= " --security-version $secureVersionStr ";


# Production signing parameters
my $PRD_SIGN_PARAMS_V3 = "--mode production "
    . "--hwKeyA __get "
    . "--hwKeyD __get "
    . "--swKeyP __get "
    . "--swKeyS __get ";

# Development key signing parameters.  In a non-secure compile, omit the keys to
# generate a secure header without signatures
my $DEV_SIGN_PARAMS_V3 = "";
if($secureboot)
{
    $DEV_SIGN_PARAMS_V3 = "--mode development "
    . "--hwKeyA $DEV_KEY_DIR_V3/runtime_hw_key_a.key "
    . "--hwKeyD $DEV_KEY_DIR_V3/runtime_hw_key_d.key "
    . "--swKeyP $DEV_KEY_DIR_V3/runtime_sw_key_p.key "
    . "--swKeyS $DEV_KEY_DIR_V3/runtime_sw_key_s.key ";
}

if ($signMode{$PRODUCTION})
{
    $SIGN_REQUEST_V3 .= $PRD_SIGN_PARAMS_V3;
}
else
{
    $SIGN_REQUEST_V3 .= $DEV_SIGN_PARAMS_V3;
}


### Secureboot headers
# Contains the appropriate flags, prefix, and file names.
my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
my %sb_hdrs = (
    DEFAULT => {
        flags =>  sprintf("0x%08X",$buildFlag),
        file => "$bin_dir/$randPrefix.default.secureboot.hdr.bin"
    },
);

################################################################################
# main
################################################################################

# Print all settings in one print statement to avoid parallel build to mess
# up output.
my $SETTINGS = "\n//============= Generate PNOR Image Settings ===========//\n";
$SETTINGS .= $secureboot ? "Secureboot = Enabled\n" : "Secureboot = Disabled\n";
$SETTINGS .= $secureboot ? "Sign Mode = $sign_mode\n" : "Sign Mode = NA\n";
$SETTINGS .= "Secure Version = $secureVersionStr\n";
$SETTINGS .= "//======================================================//\n\n";
print $SETTINGS;

my %tempImages = (
    PAD_PHASE_V3 => "$bin_dir/V3/$prefix.$eyeCatch.temp.pad.bin",
    HB_HLL_ENTRIES => "$bin_dir/V3/$prefix.$eyeCatch.temp.entries.bin",
    HB_HLL_TOC => "$bin_dir/V3/$prefix.$eyeCatch.temp.toc.bin",
    HB_HLL_TOC_PLUS_ENTRIES => "$bin_dir/V3/$prefix.$eyeCatch.temp.toc_plus_entries.bin",
    HB_HLL_SIGNED => "$bin_dir/V3/$prefix.$eyeCatch.temp.signed.bin",
    HB_HLL_JUST_HEADER => "$bin_dir/V3/$prefix.$eyeCatch.temp.just_hdr.bin",
    );


# Keep track of the number of entry files processed
my $entry_file_count = 0;
foreach my $entryFilesList (@inputEntryFiles)
{
    # Each element in the array @inputEntryFiles is a comma-separated list
    # of entry files
    my @localEntryFiles = split /,/, $entryFilesList;

    # Append each entry file to one stack of entry files
    foreach my $entryFile (@localEntryFiles)
    {
        # Check if the entry file exists and has some data in it
        # Needed check because for non-transition builds SBKT.entry might still
        # get passed in by the caller
        if (-s $entryFile)
        {
            $entry_file_count++;
            #debug: print "$entry_file_count:\tentryFile = $entryFile\n";

            # for the first entry file, create a new $tempImages{ENTRY_FILE_STACK_V3}
            if ($entry_file_count == 1)
            {
                # create a new file with the first entry file
                run_command("cat $entryFile > $tempImages{HB_HLL_ENTRIES}");
            }
            else
            {
                # append the entry file
                run_command("cat $entryFile >> $tempImages{HB_HLL_ENTRIES}");
            }
        }
        else
        {
            print "$programName: $entryFile does not exist. Not including it in HB_HLL\n";
        }
    }

}

# Used for calling setV3HdrCntrSize for V3 Headers
my %callerHwHdrFields_V3 = (
    configure => 0,
    totalContainerSize => 0);


# Use defailt header and flags
my $header = $sb_hdrs{DEFAULT};
my $signingFlags = SIGNING_FLAG.$header->{flags};
my $SIGN_REQUEST_V3 = "$SIGN_REQUEST_V3 $signingFlags";
$SIGN_REQUEST_V3 .= " --sign-project-FW-token $componentId ";


################################################################################
# Now create the HB_HLL - Adapted from genPnorImages.pl's create_hb_hll subroutine:
#       Generate the HB_HLL lid based on all of the other sections/keys having
#       already been processed. This function finds the existing V3 *.header
#       files, pulls out the vital information, and builds up the HB_HLL lid.
#
#       HB HLL Format:
#           Must be synced with definitions in src/usr/pnor/hb_hll.H
#
#       struct HB_HLL_Header
#       {
#           uint64_t EyeCatcher; <-- "HB_HLL" <-- 8 bytes
#           uint16_t version; <-- start at 1
#           uint16_t CompatibleVersion; <-- start at 1
#           uint16_t NumberOfEntries; // Count of the SectionEntry
#           uint16_t hashSignMode; // SHA3_512 <-- 0x0001
#           uint16_t HashEntryStructSize; <-- 96 bytes for version 1
#           uint16_t OffsetToHashListEntries; <-- 128 bytes
#           uint8_t  reserved[108];
#       } __attribute__ ((packed));
#
#      Entry file structure in hb_hll.H and genPnorImages.pl's create_hb_hll subroutine;
#      no need to copy that here
#
################################################################################

    # @HB_HLL_SYNC@ These contants need to be kept in sync with the constants
    #               in src/usr/pnor/spnorrp.H
    # NOTE: Did not make these constants as that would still require creating a
    #       variable to use them below. So just directly created the variables here
    my $HB_HLL_SIZE_OF_METADATA = 128, #128 bytes
    my $HB_HLL_EYE_CATCHER = "HB_HLL",
    my $HB_HLL_VERSION = 1,
    my $HB_HLL_COMPATIBLE_VERSION = 1,
    my $HB_HLL_HASH_SIGN_MODE = 1, # SHA3_512
    my $HB_HLL_HASH_ENTRY_STRUCT_SIZE = 96, # 96 bytes
    my $HB_HLL_OFFSET_TO_LIST_ENTRIES = 128, #128 bytes
    my $HB_HLL_PART_NAME_SIZE = 16, #16 bytes - PART_NAME_MAX+1


    # Create HB_HLL Header Section (aka TOC)
    my $FILEHANDLE;
    open( $FILEHANDLE, ">:raw", $tempImages{HB_HLL_TOC})
        or die "Error opening file $tempImages{HB_HLL_TOC}: $!\n";

    # - set EyeCatcher - "HB_HLL\0\0" in ASCII - 8 bytes
    my @charArray = split //, $HB_HLL_EYE_CATCHER;
    my $curChar;
    foreach $curChar (@charArray)
    {
        print $FILEHANDLE pack('C', ord($curChar));
    }

    # - pad 2 null characters after HB_HLL (8 bytes were reserved for
    print $FILEHANDLE pack("C[2]", map { 0 } 1..2);

    # - set version (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_VERSION);

    # - set compatible version (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_COMPATIBLE_VERSION);

    # - set number of entries (uint16_t)
    print $FILEHANDLE pack("n", $entry_file_count);

    # - set hashSignMode (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_HASH_SIGN_MODE);

    # - set hash entry struct size (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_HASH_ENTRY_STRUCT_SIZE);

    # - set offset to list entries (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_OFFSET_TO_LIST_ENTRIES);

    # - pad the remaining "reserved" 108 bytes with null characters
    print $FILEHANDLE pack("C[108]", map { 0 } 1..108);

    close $FILEHANDLE or die "Error closing $tempImages{HB_HLL_TOC}: $!\n";

    # next line for debug; can comment out in the future
    run_command("hexdump -C $tempImages{HB_HLL_TOC}");

    # Combine (cat) the two files (TOC and Entries file)
    run_command("cat $tempImages{HB_HLL_TOC} $tempImages{HB_HLL_ENTRIES} > $tempImages{HB_HLL_TOC_PLUS_ENTRIES}");

    # next line for debug; can comment out in the future
    run_command("hexdump -C $tempImages{HB_HLL_TOC_PLUS_ENTRIES}");

    # Sign the binary to create the .header file
    run_command("$SIGN_REQUEST_V3 "
                . "--protectedPayload $tempImages{HB_HLL_TOC_PLUS_ENTRIES} "
                . "--contrHdrOut $tempImages{HB_HLL_JUST_HEADER} "
                . "--out $tempImages{HB_HLL_SIGNED} ");


################################################################################
# End of code block borrowed from genPnorImages.pl's create_hb_hll subroutine
################################################################################

# Check the size - use value from PNOR layout files
# NOTE: To simplfy this script we are not passing in the PNOR layout file
#       to just get the HB_HLL size.
# @HB_HLL_SIZE@ - need to keep in sync with pnorLayoutFSP.xml
#        <description>HB_HLL (24K)</description>
#        <!-- Purposely skipping <sha512Version/> as this section will just
#             be a V3 Header + less than 4KB of data (+ECC) -->
#        <eyeCatch>HB_HLL</eyeCatch>
#        <physicalRegionSize>0x6000</physicalRegionSize>
# MAX HB_HLL size
my $hb_hll_physicalRegionSize =  24576; # 0x6000

# get and use size without ECC
my $size_wo_ecc = page_aligned_size_wo_ecc($hb_hll_physicalRegionSize);
# get current signed, non padded size
my $hb_hll_size = -s $tempImages{HB_HLL_SIGNED};

# Do a quick size check
if ($hb_hll_size > $size_wo_ecc)
{
    die "$programName: HB_HLL size of $hb_hll_size is larger than size_wo_ecc=$size_wo_ecc (hb_hll_physicalRegionSize = $hb_hll_physicalRegionSize)";
}

# Update header fields (basically total container size)
$callerHwHdrFields_V3{configure} = 1;
setV3HdrCntrSize(\%callerHwHdrFields_V3, $tempImages{HB_HLL_SIGNED});

# Pad the images_wo_ecc ($size has previously been page aligned)
run_command("dd if=$tempImages{HB_HLL_SIGNED} of=$tempImages{PAD_PHASE_V3} ibs=$size_wo_ecc conv=sync");

# The PAD_PHASE_V3 has had its total container size updated and is
# page aligned.  Copy out this padded, non-ecc file to be picked up in FSP builds
# The FSP builds definitely need the file without ECC as they add it themselves
run_command("cp $tempImages{PAD_PHASE_V3} $outFile");


# Clean up temp images
foreach my $image (keys %tempImages)
{
    system("rm -f $tempImages{$image}");
    die "Failed deleting $tempImages{$image}" if ($?);
}

################################################################################
# End of main
################################################################################


################################################################################
# Subroutines
################################################################################

################################################################################
# page_aligned_size_wo_ecc : Size of partition without ECC, rounded down to
#                            nearest multiple of PAGE_SIZE.
# NOTE: direct copy from genPnorImages.pl
################################################################################
sub page_aligned_size_wo_ecc
{
    my ($size) = @_;

    die "Size must be at least (9/8)*PAGE_SIZE" if ($size < ((9/8)*PAGE_SIZE));
    return POSIX::floor((($size * 8) / 9) / PAGE_SIZE) * PAGE_SIZE;
}

################################################################################
# convertEyecatchToCompId
#     Converts eyecatcher to component ID, truncating it to the lesser of its
#     current size or MAX_COMP_ID_LEN bytes, in order to fit within the confines
#     of the component ID field of the firmware header.
# NOTE: direct copy from genPnorImages.pl
################################################################################
sub convertEyecatchToCompId
{
    my ($eyeCatcher) = @_;

    my $maxLen = MAX_COMP_ID_LEN;
    my $len = length($eyeCatcher);
    die "BUG! Empty eyecatcher not allowed.\n" if !$len;
    my $finalLen = ($maxLen > $len) ? $len : $maxLen;
    my $componentId = substr($eyeCatcher,0,$finalLen);

    return $componentId;
}

################################################################################
# setV3HdrCntrSize
#       Sets the caller hardware header total container size field for V3
#       headers
#       NOTE: Only supports V3 headers
# NOTE: direct copy from genPnorImages.pl
################################################################################
sub setV3HdrCntrSize
{
    my ($i_callerHwHdrFields, $i_file) = @_;

    if($i_callerHwHdrFields->{configure})
    {
        # If not already explicitly set, compute total container size
        if(!$i_callerHwHdrFields->{totalContainerSize})
        {
            $i_callerHwHdrFields->{totalContainerSize}
                = -s $i_file;
            die  "Could not determine size of file $i_file; errno = $!" unless
                    defined($i_callerHwHdrFields->{totalContainerSize});
        }
        my $callerContainerSize = sprintf("%016llX",$i_callerHwHdrFields->{totalContainerSize});
        run_command( "echo \"$callerContainerSize\" | xxd -r -ps -seek 6 - $i_file");
    }
}

################################################################################
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $programName = Create custom HB_HLL files in FSP builds for unique system/node configurations

  Usage:
    $programName --entryFiles HBI.entr.HBB.entry
                 --entryFiles WOFDATA.entry,HBD.entry
                 --binDir <path> --secure-version 0 --build-type fspbuild
                 --sign-mode development --secureboot
                 --out-file hb_hll.bin
  Parms:
    -h|--help           Print this help text
    --entryFiles        Comma-separated list of *.entry files to be included as part of the HB_HLL
                            If this parameter is used multiple times, all of the entries listed in
                            each of the calls will be included as part of the HB_HLL.
    --out-file          Full path and name of the HB_HLL that is created
    --secureboot        Indicates a secureboot build.
    --secure-version    Indicates security version value to be built into the partition headers
    --sign-mode <development|production>
                        Indicates how to sign partitions with either development keys or production keys
    --build-type        Specify whether the type of build is FIPS or OpenPower,
                            indicated by either 'fspbuild' or 'opbuild' immediately following the
                            switch (separated with a space and not including the single quotes).
                            Curerntly, only "fspbuild" is supported.
    --bin-dir           Optional parameter to specify where to put any temporary files
    --prefix            Optional parameter to specificy the unique configuration of the HB_HLL
ENDUSAGE
}
