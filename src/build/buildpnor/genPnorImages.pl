#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/genPnorImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2025
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
use Data::Dumper;
use File::Basename;
use Cwd qw(abs_path cwd);
use lib dirname abs_path($0);
use PnorUtils qw(loadPnorLayout getNumber traceErr trace run_command PAGE_SIZE
                 loadBinFiles findLayoutKeyByEyeCatch checkSpaceConstraints
                 getSwSignatures getBinDataFromFile getV1PayloadHash);
use Getopt::Long qw(:config pass_through);

# Hostboot base image constants for the hardware header portion of the
# secureboot header

# Note: base_image_target_hrmor is not being filled out because
# the value is not used. We want the hostboot codebase to be able
# to dynamically handle being loaded at any HRMOR. We will use a
# value of zero to comply with legacy code that validates the
# field as an aligned value.
use constant BASE_IMAGE_TARGET_HRMOR => 0x0000000000000000;
use constant BASE_IMAGE_INSTRUCTION_START_STACK_POINTER => 0x0000000008280000;

use constant MAX_COMP_ID_LEN => 8;

# @HBBL_SIZE_SYNC@
# Max logical HBBL content size including securerom is 94KB
# this includes the securerom, but not any security headers
my $MAX_HBBL_SIZE = 96256;

# Jail command for yocto froot
my $jailcmd = "";
if ($ENV{JAILCMD}) {
   $jailcmd = $ENV{JAILCMD};
}

print ("jailcmd = $jailcmd\n");

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
use Digest::SHA qw(sha512);
use Crypt::Digest::SHA3_512 qw(sha3_512);

my $programName = File::Basename::basename $0;
my @systemBinFiles =  ();
my %pnorLayout = ();
my %PhysicalOffsets = ();
my %partitionUtilHash;

# percentage utilization threshold, if crossed display warning message
# that partition is almost full
use constant CRITICAL_THRESHOLD => 85.00;

# Truncate SHA to n bytes
use constant SHA_TRUNCATE_SIZE => 32;
# Defined in src/include/sys/vfs.h
use constant VFS_EXTENDED_MODULE_MAX => 192;
# VfsSystemModule struct size
use constant VFS_MODULE_TABLE_ENTRY_SIZE => 112;
# VFS Module table max size
use constant VFS_MODULE_TABLE_MAX_SIZE => VFS_EXTENDED_MODULE_MAX
                                          * VFS_MODULE_TABLE_ENTRY_SIZE;
# Flag parameter string passed into signing tools
# Note spaces before/after are critical.
use constant OP_SIGNING_FLAG => " --flags ";
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

# Default to signing with enterprise signing keys
my $buildFlag = ENTERPRISE_KEYS_FLAG;

# Corrupt parameter strings
my $CORRUPT_PROTECTED = "pro";
my $CORRUPT_UNPROTECTED = "unpro";
use constant MAX_PAGES_TO_CORRUPT => 10;
# rand file prefix string. Note hbDistribute cleans up files with this prefix
use constant RAND_PREFIX => "rand-";

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
my $testRun = 0;
my $pnorLayoutFile = "";
my $system_target = "";
my $build_all = 0;
my $emitEccless = 0;
my $emitIplLids = 0;
my $install_all = 0;
my $key_transition = "";
my $help = 0;
my %partitionsToCorrupt = ();
my $sign_mode = $DEVELOPMENT;
my $hwKeyHashFile = "";
my $hb_standalone="";
my $buildType="";
my $editedLayoutLocation="";
my $secureVersionStr="";
my $secureVersionHbbl = 0xFF; # default - invalid value

# @TODO RTC 170650: Set default to 0 after all environments provide external
# control over this policy, plus remove '!' from 'lab-security-override'
# command line option as well as documentation for
# '--no-lab-security-override'
my $labSecurityOverride = 1;

GetOptions("binDir:s" => \$bin_dir,
           "secureboot" => \$secureboot,
           "test" => \$testRun,
           "pnorLayout:s" => \$pnorLayoutFile,
           "systemBinFiles:s" => \@systemBinFiles,
           "build-all" => \$build_all,
           "install-all" => \$install_all,
           "key-transition:s" => \$key_transition,
           "corrupt:s" => \%partitionsToCorrupt,
           "sign-mode:s" => \$sign_mode,
           "hwKeyHashFile:s" => \$hwKeyHashFile,
           "hb-standalone" => \$hb_standalone,
           "lab-security-override!" => \$labSecurityOverride,
           "emit-eccless" => \$emitEccless,
           "emit-ipl-lids" => \$emitIplLids,
           "build-type:s" => \$buildType,
           "editedLayoutLocation:s" => \$editedLayoutLocation,
           "secure-version:s" => \$secureVersionStr,
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

# Put key transition input into a hash and ensure a valid key transition mode
my %keyTransition = ( enabled => 0,
                      $DEVELOPMENT => 0,
                      $PRODUCTION => 0,
                      $PRODTOPROD => 0,
                      $V1 => 0,
                      $V3 => 0);

if ($key_transition =~ m/^$DEVELOPMENT/i)
{
    $keyTransition{$DEVELOPMENT} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition =~ m/^$PRODUCTION/i)
{
    $keyTransition{$PRODUCTION} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition =~ m/^$PRODTOPROD/i)
{
    $keyTransition{$PRODTOPROD} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition ne "")
{
    die "Invalid key transition mode = $key_transition";
}

# Put security version transition input into a hash and ensure a valid security version transition mode
if ($key_transition =~ m/.*-$V1/i)
{
    $keyTransition{$V1} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition =~ m/.*-$V3/i)
{
    $keyTransition{$V3} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition ne "")
{
    die "Invalid key transition mode, sign security version incorrectly specified = $key_transition";
}

my $labSecurityOverrideFlag = 0;
my $ktSecurityOverrideFlag = 0;
if($labSecurityOverride)
{
    if($signMode{$DEVELOPMENT})
    {
        $labSecurityOverrideFlag = LAB_SECURITY_OVERRIDE_FLAG;
        if($keyTransition{$DEVELOPMENT})
        {
            $ktSecurityOverrideFlag = LAB_SECURITY_OVERRIDE_FLAG;
        }
        elsif($keyTransition{$PRODUCTION})
        {
            # Key Transition flag will take precedence over the
            # lab override flag.
            $ktSecurityOverrideFlag = 0;
            $labSecurityOverride = 0;
        }
    }
    else
    {
        $labSecurityOverride = 0;
        print "WARNING! Lab security override only valid in development-"
            . "signed mode or during a key transition that installs development"
            . " keys. Continuing with lab security override disabled.\n";
    }
}

if ($secureboot)
{
    # Ensure all values of partitionsToCorrupt hash are valid.
    # Allow some flexibility for the user and do a regex, case insensitive check
    # to properly clean up the corrupt partition hash.
    foreach my $key (keys %partitionsToCorrupt)
    {
        my $value = $partitionsToCorrupt{$key};
        if ($value eq "" || $value =~ m/^$CORRUPT_PROTECTED/i)
        {
            $partitionsToCorrupt{uc($key)} = $CORRUPT_PROTECTED
        }
        elsif ($value =~ m/^$CORRUPT_UNPROTECTED/i)
        {
            $partitionsToCorrupt{uc($key)} = $CORRUPT_UNPROTECTED;
        }
        else
        {
            die "Error> Unsupported option for --corrupt, value \"$key=$value\"";
        }
    }
}

print "Check Signing and Dev key directory location set via env vars\n";

# Signing and Dev key directory location set via env vars
# NOTE: Currently signing directories are the same
my $SIGNING_DIR_V1 = $ENV{'SIGNING_DIR'};
my $SIGNING_DIR_V3 = $ENV{'SIGNING_DIR'};

# Add relative path to the dev key directory
my $DEV_KEY_DIR = $ENV{'DEV_KEY_DIR'};

# For FSP builds must add "/test" at the end to line up
# with the new V1 and V3 sub-directories
if ($buildType eq "fspbuild")
{
    $DEV_KEY_DIR = "$DEV_KEY_DIR/test";
}
# temporary workaround for open-power builds to find the right directory
# will remove once https://github.ibm.com/open-power/pnor/pull/51 gets merged
else
{
    if (!-d "${DEV_KEY_DIR}/v3_keys")
    {
        $DEV_KEY_DIR = "$DEV_KEY_DIR/..";
    }
}

my $DEV_KEY_DIR_V1 = "$DEV_KEY_DIR/keys";
my $DEV_KEY_DIR_V3 = "$DEV_KEY_DIR/v3_keys";

# Create V3 sub-directory for the output files if it's not already there
run_command("mkdir -p $bin_dir/V3");


if ($secureboot)
{
    # Check all components needed for developer signing
    print "...input parameter Bin Dir: $bin_dir\n";
    print "...env variable DEV_KEY_DIR: $DEV_KEY_DIR\n";
    # V1
    print "...Check developer signing dir V1: $SIGNING_DIR_V1\n";
    die "Signing Dir = $SIGNING_DIR_V1 DNE" if(! -d $SIGNING_DIR_V1);
    print "...Check developer signing key dir V1: $DEV_KEY_DIR_V1\n";
    die "Dev Key Dir = $DEV_KEY_DIR_V1 DNE" if(! -d $DEV_KEY_DIR_V1);
    die "hw_key_a DNE in $DEV_KEY_DIR_V1" if(!glob("$DEV_KEY_DIR_V1/hw_key_a*"));
    die "hw_key_b DNE in $DEV_KEY_DIR_V1" if(!glob("$DEV_KEY_DIR_V1/hw_key_b*"));
    die "hw_key_c DNE in $DEV_KEY_DIR_V1" if(!glob("$DEV_KEY_DIR_V1/hw_key_c*"));
    die "sw_key_a DNE in $DEV_KEY_DIR_V1" if(!glob("$DEV_KEY_DIR_V1/sw_key_a*"));
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

my $OPEN_SIGN_REQUEST_V1=
    "$SIGNING_DIR_V1/crtSignedContainer.sh --scratchDir $bin_dir -V 1";

my $OPEN_SIGN_REQUEST_V3=
    "$SIGNING_DIR_V3/crtSignedContainer.sh --scratchDir $bin_dir/V3/ -V 3 ";

# Check if secure version parameter was passed in and add it to the signing command, if necessary
if ($secureVersionStr eq "")
{
    # Without input still write Secure Version 0 to HBBL,
    # but dont pass in "--security version" to signing tool
    $secureVersionStr = "0";
    $secureVersionHbbl = sprintf("%02X",$secureVersionStr);
}
else
{
    $secureVersionHbbl = sprintf("%02X",$secureVersionStr);

    # Pass this parameter to the signing tool
    $OPEN_SIGN_REQUEST_V1 .= " --security-version $secureVersionStr ";
    $OPEN_SIGN_REQUEST_V3 .= " --security-version $secureVersionStr ";
}


# Production signing parameters
my $OPEN_PRD_SIGN_PARAMS_V1 = "--mode production "
    . "--hwKeyA __get "
    . "--hwKeyB __get "
    . "--hwKeyC __get "
    . "--swKeyP __get ";

my $OPEN_PRD_SIGN_PARAMS_V3 = "--mode production "
    . "--hwKeyA __get "
    . "--hwKeyD __get "
    . "--swKeyP __get "
    . "--swKeyS __get ";

# Development key signing parameters.  In a non-secure compile, omit the keys to
# generate a secure header without signatures
my $OPEN_DEV_SIGN_PARAMS_V1 = "";
my $OPEN_DEV_SIGN_PARAMS_V3 = "";
if($secureboot)
{
    $OPEN_DEV_SIGN_PARAMS_V1 = "--mode development "
    . "--hwKeyA $DEV_KEY_DIR_V1/hw_key_a.key "
    . "--hwKeyB $DEV_KEY_DIR_V1/hw_key_b.key "
    . "--hwKeyC $DEV_KEY_DIR_V1/hw_key_c.key "
    . "--swKeyP $DEV_KEY_DIR_V1/sw_key_a.key ";

    $OPEN_DEV_SIGN_PARAMS_V3 = "--mode development "
    . "--hwKeyA $DEV_KEY_DIR_V3/runtime_hw_key_a.key "
    . "--hwKeyD $DEV_KEY_DIR_V3/runtime_hw_key_d.key "
    . "--swKeyP $DEV_KEY_DIR_V3/runtime_sw_key_p.key "
    . "--swKeyS $DEV_KEY_DIR_V3/runtime_sw_key_s.key ";
}

# By default key transition container is unused
my $OPEN_SIGN_KEY_TRANS_NEW = "";
my $OPEN_SIGN_KEY_TRANS_OLD = "";

# Handle key transition and production signing logic
if ($keyTransition{enabled})
{
    # Allowed transition drivers:
    # 1. V3 dev to V3 dev
    # 2. V3 dev to V3 prod
    # 3. V1 prod to V3 prod - Not currently supperted @TODO JIRA: PFHB-923

    if ($signMode{$DEVELOPMENT} && $keyTransition{$V3} && $keyTransition{$DEVELOPMENT})
    {
        $OPEN_SIGN_KEY_TRANS_OLD = "$OPEN_SIGN_REQUEST_V3 $OPEN_DEV_SIGN_PARAMS_V3";
        $OPEN_SIGN_KEY_TRANS_NEW = "$OPEN_SIGN_REQUEST_V3 $OPEN_DEV_SIGN_PARAMS_V3";
    }
    elsif ($signMode{$DEVELOPMENT} && $keyTransition{$V3} && $keyTransition{$PRODUCTION})
    {
        $OPEN_SIGN_KEY_TRANS_OLD = "$OPEN_SIGN_REQUEST_V3 $OPEN_DEV_SIGN_PARAMS_V3";
        $OPEN_SIGN_KEY_TRANS_NEW = "$OPEN_SIGN_REQUEST_V3 $OPEN_PRD_SIGN_PARAMS_V3";
    }
    elsif ($signMode{$PRODUCTION} && $keyTransition{$V3} && $keyTransition{$PRODTOPROD})
    {
        $OPEN_SIGN_KEY_TRANS_OLD = "$OPEN_SIGN_REQUEST_V1 $OPEN_PRD_SIGN_PARAMS_V1";
        $OPEN_SIGN_KEY_TRANS_NEW = "$OPEN_SIGN_REQUEST_V3 $OPEN_PRD_SIGN_PARAMS_V3";
        # currently not supported
        die "Prod v1 - prod v3 not currently supported\n";
    }
    else
    {
        die "Attempted to create image for illegal transition ($sign_mode -> $key_transition)\n";
    }
    # Since this request signs 4k of random data for SBKT, but is not a named
    # section, we'll make up a component ID of "SBKTRAND"
    $OPEN_SIGN_KEY_TRANS_NEW .=  "--sign-project-FW-token SBKTRAND ";

    print "Creating transition image ($sign_mode -> $key_transition)\n";
    print "New security settings: $OPEN_SIGN_KEY_TRANS_NEW\n";
    print "Old security settings: $OPEN_SIGN_KEY_TRANS_OLD\n";
}

if ($signMode{$PRODUCTION})
{
    # for p11 we dont support V1 prod signing
    # use prod for V3 and dev for V1
    $OPEN_SIGN_REQUEST_V1 .= $OPEN_DEV_SIGN_PARAMS_V1;
    $OPEN_SIGN_REQUEST_V3 .= $OPEN_PRD_SIGN_PARAMS_V3;
}
else
{
    $OPEN_SIGN_REQUEST_V1 .= $OPEN_DEV_SIGN_PARAMS_V1;
    $OPEN_SIGN_REQUEST_V3 .= $OPEN_DEV_SIGN_PARAMS_V3;
}

### Secureboot headers
# Contains the appropriate flags, prefix, and file names.
my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
my %sb_hdrs = (
    DEFAULT => {
        flags =>  sprintf("0x%08X",$buildFlag),
        file => "$bin_dir/$randPrefix.default.secureboot.hdr.bin"
    },
    SBE => {
        flags =>  sprintf("0x%08X",($buildFlag | $labSecurityOverrideFlag)),
        file => "$bin_dir/$randPrefix.sbe.default.secureboot.hdr.bin"
    },
    SBKT => {
        outer => {
            flags => sprintf("0x%08X", $buildFlag | KEY_TRANSITION_FLAG),
            file => "$bin_dir/$randPrefix.sbkt.outer.secureboot.hdr.bin"
        },
        inner => {
            flags => sprintf("0x%08X", $buildFlag | $ktSecurityOverrideFlag),
            file => "$bin_dir/$randPrefix.sbkt.inner.secureboot.hdr.bin"
        }
    }
);


# This is the max number of parallel subprocesses we should use to sign the
# PNOR images.
# Allow the environment variable HB_PRIME_MAX_PARALLEL_PROCESSES
# to override the max number of processes, default to the number
# of processors on the machine.
my $max_processes = $ENV{HB_GEN_PNOR_IMAGES_MAX_PARALLEL_PROCESSES} || `nproc`;

if ($signMode{$PRODUCTION} || $keyTransition{$PRODUCTION})
{
    # In production mode, allow at most 1 signing process to run
    # at once. If we run more, it could cause file name collisions.
    # This also applies for dev-to-prod key transition drivers
    $max_processes = 1;
}

if ($max_processes < 1)
{
    # We can't do with anything less than one process.
    $max_processes = 1;
}

################################################################################
# main
################################################################################

# Print all settings in one print statement to avoid parallel build to mess
# up output.
my $SETTINGS = "\n//============= Generate PNOR Image Settings ===========//\n";
$SETTINGS .= "PNOR Layout = ".$pnorLayoutFile."\n";
$SETTINGS .= $build_all ? "Build Phase = build_all\n" : "";
$SETTINGS .= "Emit ECC-less versions of output files, when possible = ";
$SETTINGS .= $emitEccless ? "Yes\n" : "No\n";
$SETTINGS .= "Emit IPL-time lids, when possible = ";
$SETTINGS .= $emitIplLids ? "Yes\n" : "No\n";
$SETTINGS .= $install_all ? "Build Phase = install_all\n" : "";
$SETTINGS .= $testRun ? "Test Mode = Yes\n" : "Test Mode = No\n";
$SETTINGS .= $secureboot ? "Secureboot = Enabled\n" : "Secureboot = Disabled\n";
$SETTINGS .= %partitionsToCorrupt && $secureboot ? "Corrupt Partitions: ".Dumper \%partitionsToCorrupt : "";
$SETTINGS .= $secureboot ? "Sign Mode = $sign_mode\n" : "Sign Mode = NA\n";
$SETTINGS .= $secureVersionStr ? "Secure Version = $secureVersionStr\n" : "Secure Version was NA, so will use 0\n";
$SETTINGS .= $key_transition && $secureboot ? "Key Transition Mode = $key_transition\n" : "Key Transition Mode = NA\n";
$SETTINGS .= "Lab security override (valid for SBE partition only) = ";
$SETTINGS .= $labSecurityOverride ? "Yes\n" : "No\n";
$SETTINGS .= "Max number of parallel subprocesses: $max_processes\n";
$SETTINGS .= "//======================================================//\n\n";
print $SETTINGS;

if ($build_all && $secureboot)
{
    gen_test_containers();
}

#Load PNOR Layout XML file
loadPnorLayout($pnorLayoutFile, \%pnorLayout, \%PhysicalOffsets, $testRun,
    $editedLayoutLocation);

# Generate final images for each system's bin files.
foreach my $binFilesCSV (@systemBinFiles)
{
    my %binFiles = ();
    my $system_target = "";

    # Check if format includes a system target 'TARGET:<csv of bin files>'
    if ($binFilesCSV =~ m/:/)
    {
        my @arr = split(':', $binFilesCSV);
        $system_target = $arr[0];
        $binFilesCSV = $arr[1];
    }

    # Load bin files into hash to know what to generate
    loadBinFiles($binFilesCSV, \%binFiles);

    #Perform any data integrity manipulation (ECC, sha-hash, etc)
    manipulateImages(\%pnorLayout, \%binFiles, $system_target);
}

# display percentage utilization data for each eyecatch
foreach my $key (keys %partitionUtilHash) {

    print "$key is $partitionUtilHash{$key}{pctUtilized} utilized ($partitionUtilHash{$key}{freeBytes} of $partitionUtilHash{$key}{physicalRegionSize} bytes free)\n";

    # if percentage is greater than critical threshold, surface warning
    if ($partitionUtilHash{$key}{pctUtilized} > CRITICAL_THRESHOLD) {
        print "Warning: Percent utilization for $key shows that partition is almost full.\n";
    }
}

################################################################################
# Subroutines
################################################################################

################################################################################
# partitionDepSort
# Custom sort to ensure images are handled in the correct dependency order.
# If a dependency is not specified in the hash used, use default behavior.
################################################################################

sub partitionDepSort
{
    # Hardcoded defined order that binfiles should be handled. Fails to work
    # properly unless declared inside the sort routine under some platforms/perl
    # versions
    my %partitionDeps = ( HBBL => 0,
                          HBB => 1,
                          HBI => 2);

    # If $a exists but $b does not, set $a < $b
    if (exists $partitionDeps{$a} && !exists $partitionDeps{$b})
    {
        -1
    }
    # If $a does not exists but $b does, set $a > $b
    elsif (!exists $partitionDeps{$a} && exists $partitionDeps{$b})
    {
        1
    }
    # If both $a and $b exist, actually compare values.
    elsif (exists $partitionDeps{$a} && exists $partitionDeps{$b})
    {
        if ($partitionDeps{$a} < $partitionDeps{$b}) {-1}
        elsif ($partitionDeps{$a} > $partitionDeps{$b}) {1}
        else {0}
    }
    # If neither $a or $b have a dependency, order doesn't matter
    else {0}
}

################################################################################
# manipulateImage
# Perform any ECC/padding/sha/signing manipulations on a single image
################################################################################

sub manipulateImage
{
    my ($key, $i_pnorLayoutRef, $i_binFilesRef, $parallelPrefix, $preReqImages, $system_target) = @_;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    # Used for calling setCallerHwHdrFields for V1 Headers
    my %callerHwHdrFields = (
        configure => 0,
        totalContainerSize => 0,
        targetHrmor => 0,
        instructionStartStackPointer => 0);

    # Because totalContainerSize can be different for V3, need a separate one
    # Used for calling setV3HdrCntrSize for V3 Headers
    my %callerHwHdrFields_V3 = (
        configure => 0,
        totalContainerSize => 0);

    my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayoutRef);

    # Skip if binary file isn't included in the PNOR layout file
    if ($layoutKey eq -1)
    {
        print "Warning: skipping $key since it is NOT in the PNOR layout file\n";
        return;
    }

    my $eyeCatch = $sectionHash{$layoutKey}{eyeCatch};
    my $physicalRegionSize = $sectionHash{$layoutKey}{physicalRegionSize};
    my %tempImages = (
        HDR_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.hdr.bin",
        TEMP_SHA_IMG => "$bin_dir/$parallelPrefix.$eyeCatch.temp.sha.bin",
        PAD_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.pad.bin",
        ECC_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.bin.ecc",
        VFS_MODULE_TABLE => => "$bin_dir/$parallelPrefix.$eyeCatch.vfs_module_table.bin",
        TEMP_BIN => "$bin_dir/$parallelPrefix.$eyeCatch.temp.bin",
        PAYLOAD_TEXT => "$bin_dir/$parallelPrefix.$eyeCatch.payload_text.bin",
        PROTECTED_PAYLOAD => "$bin_dir/$parallelPrefix.$eyeCatch.protected_payload.bin",
        # duplicate for V3
        HDR_PHASE_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.temp.hdr.bin",
        TEMP_SHA_IMG_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.temp.sha.bin",
        PAD_PHASE_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.temp.pad.bin",
        ECC_PHASE_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.temp.bin.ecc",
        VFS_MODULE_TABLE_V3 => => "$bin_dir/V3/$parallelPrefix.$eyeCatch.vfs_module_table.bin",
        TEMP_BIN_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.temp.bin",
        PAYLOAD_TEXT_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.payload_text.bin",
        PROTECTED_PAYLOAD_V3 => "$bin_dir/V3/$parallelPrefix.$eyeCatch.protected_payload.bin"
        );

    my $size = $sectionHash{$layoutKey}{physicalRegionSize};

    # Get size of partition without ecc
    if ($sectionHash{$layoutKey}{ecc} eq "yes")
    {
        $size = page_aligned_size_wo_ecc($size);
    }

    # Sections that have secureboot support. Secureboot still must be
    # enabled for secureboot actions on these partitions to occur.
    my $isNormalSecure ||= ($eyeCatch eq "PAYLOAD");
    $isNormalSecure ||= ($eyeCatch eq "OCC");
    $isNormalSecure ||= ($eyeCatch eq "CAPP");
    $isNormalSecure ||= ($eyeCatch eq "BOOTKERNEL");
    $isNormalSecure ||= ($eyeCatch eq "IMA_CATALOG");
    $isNormalSecure ||= ($eyeCatch eq "TESTRO");
    $isNormalSecure ||= ($eyeCatch eq "TESTLOAD");
    $isNormalSecure ||= ($eyeCatch eq "VERSION");
    $isNormalSecure ||= ($eyeCatch eq "CENHWIMG");
    $isNormalSecure ||= ($eyeCatch eq "HCODE_LID");
    $isNormalSecure ||= ($eyeCatch eq "PSPD");

    my $isSpecialSecure = ($eyeCatch eq "HBB");
    $isSpecialSecure ||= ($eyeCatch eq "HBD");
    $isSpecialSecure ||= ($eyeCatch eq "HBI");
    $isSpecialSecure ||= ($eyeCatch eq "WOFDATA");
    $isSpecialSecure ||= ($eyeCatch eq "SBE");
    $isSpecialSecure ||= ($eyeCatch eq "HCODE");
    $isSpecialSecure ||= ($eyeCatch eq "MEMD");
    $isSpecialSecure ||= ($eyeCatch eq "OCMBFW");
    $isSpecialSecure ||= ($eyeCatch eq "HBBL");

    if($ENV{'HOSTBOOT_PROFILE'})
    {
        $isSpecialSecure ||= ($eyeCatch eq "HBRT");
    }
    else
    {
        $isNormalSecure ||= ($eyeCatch eq "HBRT");
    }

    # Used to indicate security is supported in firmware
    my $secureSupported = $isNormalSecure || $isSpecialSecure;

    # If there is a non-default header for this section, use it instead
    my $header = $sb_hdrs{DEFAULT};
    if(exists $sb_hdrs{$eyeCatch})
    {
        $header = $sb_hdrs{$eyeCatch};
    }

    my $openSigningFlags = OP_SIGNING_FLAG.$header->{flags};

    my $CUR_OPEN_SIGN_REQUEST_V1 = "$OPEN_SIGN_REQUEST_V1 $openSigningFlags";
    my $CUR_OPEN_SIGN_REQUEST_V3 = "$OPEN_SIGN_REQUEST_V3 $openSigningFlags";

    my $componentId = convertEyecatchToCompId($eyeCatch);
    $CUR_OPEN_SIGN_REQUEST_V1 .= " --sign-project-FW-token $componentId ";
    $CUR_OPEN_SIGN_REQUEST_V3 .= " --sign-project-FW-token $componentId ";

    # Used for corrupting partitions. By default all protected offsets start
    # immediately after the container header which is size = PAGE_SIZE.
    # *Note: this is before ECC.
    my $protectedOffset = PAGE_SIZE;
    my $protectedOffset_V3 = PAGE_SIZE;

    # Get bin file(s) associated with PNOR section
    my $bin_files = $$i_binFilesRef{$eyeCatch};
    # Check if bin file entry has multiple files (multi node)
    my @binFilesArray = split /,/, $bin_files;

    my $node_id = 0;
    my $nodeIDstr = "";

    # Partitions that have a hash page table at the beginning of the section
    # for secureboot purposes.
    my %hashPageTablePartitions = (HBI      => 1,
                                   WOFDATA  => 1,
                                   SBE      => 1,
                                   HCODE    => 1,
                                   OCMBFW   => 1,
                                   MEMD     => 1);

    if($ENV{'HOSTBOOT_PROFILE'})
    {
        $hashPageTablePartitions{HBRT}=1;
    }

    if($ENV{'RM_HASH_PAGE_TABLE'})
    {
        undef %hashPageTablePartitions;
    }

    foreach my $section (keys %sectionHash)
    {
        my $eyeCatch = $sectionHash{$section}{eyeCatch};
        # If the HBD_RW eye catch exists in PNOR Layout XML, then the
        # HBD will be treated as RO and we can add the HPT to it
        if ($eyeCatch eq "HBD_RW")
        {
            $hashPageTablePartitions{"HBD"} = 1;
            last;
        }
    }

    foreach my $bin_file (@binFilesArray)
    {
        # @TODO RTC 182358
        # This is a tactical workaround for the signing tooling not being
        # able to handle muliple different platform binary (or multiple
        # node) contents for the same component ID.  The signing tooling
        # should be modified to tolerate this scenario, at which point the
        # workaround can be removed.
        if ($buildType eq "fspbuild")
        {
            my @signatureFiles=
                glob("$bin_dir/SIGNTOOL_*/$componentId/SW*.sig "
                     . "$bin_dir/V3/SIGNTOOL_*/$componentId/SW*.sig "
                     . "$bin_dir/SIGNTOOL_*/$componentId/*sig_p.raw "
                     . "$bin_dir/SIGNTOOL_*/$componentId/*key_p.sig");
            print "Deleting @signatureFiles\n";
            unlink @signatureFiles;
        }

        # If there are more than 1 bin files per section, final name should
        # have a node ID included.
        if (scalar @binFilesArray > 1)
        {
            $nodeIDstr = "_NODE_$node_id";
        }

        # Check if bin file is system specific and prefix target to the front
        # V1:
        my $final_bin_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.bin":
            "$bin_dir/$system_target.$eyeCatch$nodeIDstr.bin";
        # V3:
        my $final_bin_file_V3 = ($system_target eq "")? "$bin_dir/V3/$eyeCatch$nodeIDstr.bin":
            "$bin_dir/V3/$system_target.$eyeCatch$nodeIDstr.bin";

        # Check if bin file is system specific and prefix target to the front
        # V1:
        my $final_header_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.header":
            "$bin_dir/$system_target.$eyeCatch$nodeIDstr.header";

        # V3
        my $final_header_file_V3 = ($system_target eq "")? "$bin_dir/V3/$eyeCatch$nodeIDstr.header":
            "$bin_dir/V3/$system_target.$eyeCatch$nodeIDstr.header";


        # Handle partitions that have an input binary.
        if (-e $bin_file)
        {
            # Track original name and whether file has a header or not in order
            # to emit eccless outputs, if requested
            my $eccless_file = $bin_file;
            my $eccless_prefix = "";
            my $eccless_file_V3 = $bin_file;

            # HBBL + ROM combination
            if ($eyeCatch eq "HBBL")
            {
                # Ensure the HBBL data section (ie, not including headers)
                # isn't too large
                my $hbblRawSize = (-s $bin_file or die "Cannot get size of file $bin_file");
                print "HBBL raw size ($bin_file) (no padding/ecc) = $hbblRawSize/$MAX_HBBL_SIZE\n";
                if ($hbblRawSize > $MAX_HBBL_SIZE)
                {
                    die "HBBL raw size is too large";
                }
            }

            # Header Phase
            if($sectionHash{$layoutKey}{sha512Version} eq "yes")
            {
                $eccless_prefix.=".header";
                # Add secure container header
                if ($secureboot && $isSpecialSecure)
                {
                    $callerHwHdrFields{configure} = 1;
                    $callerHwHdrFields_V3{configure} = 1;
                    if (exists $hashPageTablePartitions{$eyeCatch})
                    {
                        if ($eyeCatch eq "HBI")
                        {
                            # Pass HBB sw signatures as the salt entry.
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch,$bin_dir,
                                                                          getBinDataFromFile($preReqImages->{HBB_PAYLOAD_HASH_FILE}));
                            $tempImages{hashPageTable_V3} = genHashPageTable($bin_file, $eyeCatch,"$bin_dir/V3/",
                                                                          getBinDataFromFile($preReqImages->{HBB_PAYLOAD_HASH_FILE_V3}));
                        }
                        else
                        {
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch,$bin_dir);
                            $tempImages{hashPageTable_V3} = genHashPageTable($bin_file, $eyeCatch,"$bin_dir/V3/");
                        }
                    }
                    # Add hash page table
                    if ($tempImages{hashPageTable} ne "" && -e $tempImages{hashPageTable})
                    {
                        trace(1,"Adding hash page table for $eyeCatch");
                        my $hashPageTableSize = -s $tempImages{hashPageTable};
                        die "hashPageTable size undefined: errno = $!" unless(defined $hashPageTableSize);

                        my $hashPageTableSize_V3 = -s $tempImages{hashPageTable_V3};
                        die "hashPageTable size undefined: errno = $!" unless(defined $hashPageTableSize_V3);

                        # Move protected offset after hash page table.
                        $protectedOffset += $hashPageTableSize;
                        $protectedOffset_V3 += $hashPageTableSize_V3;


                        if ($eyeCatch eq "HBI")
                        {
                            # Add the VFS module table to the payload text section.
                            run_command("dd if=$bin_file of=$tempImages{VFS_MODULE_TABLE} count=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            # Same VFS module table for V3
                            run_command("cp $tempImages{VFS_MODULE_TABLE} $tempImages{VFS_MODULE_TABLE_V3}");

                            # Remove VFS module table from bin file
                            run_command("dd if=$bin_file of=$tempImages{TEMP_BIN} skip=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            run_command("cp $tempImages{TEMP_BIN} $bin_file");
                            # no need to sync $tempImages{TEMP_BIN} to $tempImages{TEMP_BIN_V3}
                            # here as $tempImages{TEMP_BIN} was just used to add and remove the
                            # VFS table in the above commands.  $tempImages{TEMP_BIN} will get
                            # reset/reused later in this function for a different purpose

                            # Pad after hash page table to have the VFS module table end at a 4K boundary
                            my $padSize = PAGE_SIZE - (($hashPageTableSize + VFS_MODULE_TABLE_MAX_SIZE) % PAGE_SIZE);
                            run_command("dd if=/dev/zero bs=$padSize count=1 | tr \"\\000\" \"\\377\" >> $tempImages{hashPageTable} ");

                            my $padSize_V3 = PAGE_SIZE - (($hashPageTableSize_V3 + VFS_MODULE_TABLE_MAX_SIZE) % PAGE_SIZE);
                            run_command("dd if=/dev/zero bs=$padSize_V3 count=1 | tr \"\\000\" \"\\377\" >> $tempImages{hashPageTable_V3} ");


                            # Move protected offset after padding of hash page table.
                            $protectedOffset += $padSize;
                            $protectedOffset_V3 += $padSize_V3;

                            # Payload text section
                            run_command("cat $tempImages{hashPageTable} $tempImages{VFS_MODULE_TABLE} > $tempImages{PAYLOAD_TEXT} ");
                            run_command("cat $tempImages{hashPageTablei_V3} $tempImages{VFS_MODULE_TABLE_V3} > $tempImages{PAYLOAD_TEXT_V3} ");

                        }
                        else
                        {
                            run_command("cp $tempImages{hashPageTable} $tempImages{PAYLOAD_TEXT}");
                            run_command("cp $tempImages{hashPageTable_V3} $tempImages{PAYLOAD_TEXT_V3}");

                            # Hash table generated so need to set sw-flags
                            my $hex_sw_flag = sprintf("0x%08X", SW_FLAG_HAS_A_HPT);
                            $CUR_OPEN_SIGN_REQUEST_V1 .= " --sw-flags $hex_sw_flag ";
                            $CUR_OPEN_SIGN_REQUEST_V3 .= " --sw-flags $hex_sw_flag ";
                        }

                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $tempImages{PAYLOAD_TEXT} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");
                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file > $tempImages{HDR_PHASE}");

                        # While we have had separate default (V1) and V3 files so far,
                        # for the actual signing we need to target the same default/V1
                        # PAYLOAD_TEXT to ensure that the V3 header is signing the
                        # EXACT same data
                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $tempImages{PAYLOAD_TEXT} "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PROTECTED_PAYLOAD_V3}");
                        run_command("cat $tempImages{PROTECTED_PAYLOAD_V3} $bin_file > $tempImages{HDR_PHASE_V3}");

                    }
                    # Handle COMBO RO and RW payload
                    elsif ($eyeCatch eq "HBD")
                    {
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $bin_file.protected "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");

                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file.unprotected > $tempImages{HDR_PHASE}");

                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $bin_file.protected "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PROTECTED_PAYLOAD_V3}");

                        run_command("cat $tempImages{PROTECTED_PAYLOAD_V3} $bin_file.unprotected > $tempImages{HDR_PHASE_V3}");
                    }
                    # Handle HBBL payload
                    elsif ($eyeCatch eq "HBBL")
                    {
                        # The HBBL does not have a Hash Page Table, but needs to
                        # have the V3 Header added as an "unprotected" section
                        # to the final V1 image:
                        # [V1 Header][HBBL data + pad to page boundary][V3 Header]

                        # First pad HBBL data such that the V1 and V3 headers
                        # can be processed on the page-aligned HBBL data
                        # Also, overwrite the original input file $bin_file
                        # (likely hbbl.bin) since it gets picked up in sim
                        # environments and SBE code expects it to be on a
                        # page/cacheline boundary
                        run_command("cp $bin_file $tempImages{TEMP_BIN}");
                        run_command("dd if=$tempImages{TEMP_BIN} of=$bin_file ibs=4k conv=sync");

                        # Create V1 Header for HBBL data + pad
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $bin_file "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");

                        # Create the V3 Header for the HBBL data + pad
                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $bin_file "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PROTECTED_PAYLOAD_V3}");

                        # Now append the V3 header to the V1 PROTECTED_PAYLOD image
                        # It will show up as "unprotected" data in the PNOR code
                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $final_header_file_V3 > $tempImages{HDR_PHASE}");

                        # Nothing unique for V3 HDR_PHASE_V3 image
                        run_command("cp $tempImages{PROTECTED_PAYLOAD_V3} $tempImages{HDR_PHASE_V3}");
                    }
                    elsif ($eyeCatch eq "HBB")
                    {
                        # HBB needs this offset set
                        my $codeStartOffset = "--code-start-offset 0x00000180";

                        # Like the HBBL above, the HBB does not have a Hash Page
                        # Table, but needs to have the V3 Header added as an
                        # "unprotected" section to the final V1 image:
                        # [V1 Header][HBB data + pad to page boundary][V3 Header]

                        # Appending the V3 header here allows for the HBBL to
                        # verify the HBB data when it loads it and the system is
                        # in V3 mode

                        # First pad HBB data such that the V1 and V3 headers
                        # can be processed on the page-aligned HBB data
                        run_command("dd if=$bin_file of=$tempImages{TEMP_BIN} ibs=4k conv=sync");

                        # Create V1 Header for HBB data + pad
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "$codeStartOffset "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");

                        # Create the V3 Header for the HBB data + pad
                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "$codeStartOffset "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PROTECTED_PAYLOAD_V3}");

                        # Now append the V3 header to the V1 PROTECTED_PAYLOAD image
                        # It will show up as "unprotected" data in the PNOR code
                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $final_header_file_V3 > $tempImages{HDR_PHASE}");

                        # Nothing unique for V3 HDR_PHASE_V3 image
                        run_command("cp $tempImages{PROTECTED_PAYLOAD_V3} $tempImages{HDR_PHASE_V3}");
                    }
                    else
                    {
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $bin_file "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{HDR_PHASE}");

                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $bin_file "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{HDR_PHASE_V3}");
                    }

                    # Customize secureboot prefix header with container size,
                    # target HRMOR, and stack address (8 bytes each), in that
                    # order. Customization begins at offset 6 into the container
                    # header.
                    if($eyeCatch eq "HBB")
                    {
                        $callerHwHdrFields{targetHrmor}
                        = BASE_IMAGE_TARGET_HRMOR;
                        $callerHwHdrFields{instructionStartStackPointer}
                        = BASE_IMAGE_INSTRUCTION_START_STACK_POINTER;
                        $callerHwHdrFields_V3{targetHrmor}
                        = BASE_IMAGE_TARGET_HRMOR;
                        $callerHwHdrFields_V3{instructionStartStackPointer}
                        = BASE_IMAGE_INSTRUCTION_START_STACK_POINTER;

                        # Save off HBB V1 Payload Hash for use by HBI to "salt" its hash page table
                        open (HBB_PAYLOAD_HASH_FILE, ">",
                              $preReqImages->{HBB_PAYLOAD_HASH_FILE}) or die "Error opening file $preReqImages->{HBB_SW_SIG_FILE}: $!\n";
                        binmode HBB_PAYLOAD_HASH_FILE;
                        print HBB_PAYLOAD_HASH_FILE getV1PayloadHash($tempImages{HDR_PHASE});
                        die "Error writing to $preReqImages->{HBB_PAYLOAD_HASH_FILE} failed" if $!;
                        close HBB_PAYLOAD_HASH_FILE;
                        die "Error closing of $preReqImages->{HBB_PAYLOAD_HASH_FILE} failed" if $!;

                        # V3: So that the hash page table is built exactly the same, use the
                        #     same payload hash from V1 for V3
                        run_command("cp $preReqImages->{HBB_PAYLOAD_HASH_FILE} $preReqImages->{HBB_PAYLOAD_HASH_FILE_V3}");
                    }
                }
                elsif($secureboot && $isNormalSecure)
                {
                    $callerHwHdrFields{configure} = 1;
                    $callerHwHdrFields_V3{configure} = 1;
                    run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file "
                                . "--out $tempImages{HDR_PHASE}");

                    run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file_V3 "
                                . "--out $tempImages{HDR_PHASE_V3}");
                }
                # Add non-secure version header
                else
                {
                    # Attach signature-less secure header for OpenPOWER builds
                    run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file "
                                . "--out $tempImages{HDR_PHASE}");

                    run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file_V3 "
                                . "--out $tempImages{HDR_PHASE_V3}");
                }
            }
            else
            {
                run_command("cp $bin_file $tempImages{HDR_PHASE}");
                run_command("cp $bin_file $tempImages{HDR_PHASE_V3}");
            } # end of Header Phase

            setCallerHwHdrFields(\%callerHwHdrFields, $tempImages{HDR_PHASE});
            setV3HdrCntrSize(\%callerHwHdrFields_V3, $tempImages{HDR_PHASE_V3});

            # If so instructed, take the ecc-less, unpadded file, make it
            # 4KB byte aligned in size and emit it as EYE_CATCH.ipllid
            # This will be used in op-build as the ipl time lids for PLDM
            # file io.
            if ($emitIplLids)
            {
                # Get the files size and round it up to the next multiple of 4096
                my $file_size = -s $tempImages{HDR_PHASE};
                if(($file_size % 4096) ne 0)
                {
                    $file_size += (4096 - ($file_size % 4096));
                }

                my $file_size_V3 = -s $tempImages{HDR_PHASE_V3};
                if(($file_size_V3 % 4096) ne 0)
                {
                    $file_size_V3 += (4096 - ($file_size_V3 % 4096));
                }

                # Create an empty file of all 0xFF's of $file_size
                run_command("dd if=/dev/zero bs=$file_size count=1 | tr \"\\000\" \"\\377\" > $bin_dir/$eyeCatch.ipllid");
                run_command("dd if=/dev/zero bs=$file_size_V3 count=1 | tr \"\\000\" \"\\377\" > $bin_dir/V3/$eyeCatch.ipllid");

                # Write the contents of tempImages[HDR_PHASE} to the begining of the file we just made
                run_command("dd if=$tempImages{HDR_PHASE} conv=notrunc of=$bin_dir/$eyeCatch.ipllid");
                run_command("dd if=$tempImages{HDR_PHASE_V3} conv=notrunc of=$bin_dir/V3/$eyeCatch.ipllid");
            }

            # store binary file size + header size in hash

            # If section will passed through ecc, include this in size calculation
            if( ($sectionHash{$layoutKey}{ecc} eq "yes") )
            {
                $partitionUtilHash{$eyeCatch}{logicalFileSize} = $callerHwHdrFields{totalContainerSize} * (9/8);
                $partitionUtilHash{$eyeCatch}{logicalFileSize_V3} = $callerHwHdrFields_V3{totalContainerSize} * (9/8);
            }
            else
            {
                $partitionUtilHash{$eyeCatch}{logicalFileSize} = $callerHwHdrFields{totalContainerSize};
                $partitionUtilHash{$eyeCatch}{logicalFileSize_V3} = $callerHwHdrFields_V3{totalContainerSize};
            }
            # V1:
            $partitionUtilHash{$eyeCatch}{pctUtilized} = sprintf("%.2f", $partitionUtilHash{$eyeCatch}{logicalFileSize} / $physicalRegionSize * 100);
            $partitionUtilHash{$eyeCatch}{freeBytes} = $physicalRegionSize - $partitionUtilHash{$eyeCatch}{logicalFileSize};
            $partitionUtilHash{$eyeCatch}{physicalRegionSize} = $physicalRegionSize;
            # V3:
            $partitionUtilHash{$eyeCatch}{pctUtilized_V3} = sprintf("%.2f", $partitionUtilHash{$eyeCatch}{logicalFileSize_V3} / $physicalRegionSize * 100);
            $partitionUtilHash{$eyeCatch}{freeBytes_V3} = $physicalRegionSize - $partitionUtilHash{$eyeCatch}{logicalFileSize_v3};
            $partitionUtilHash{$eyeCatch}{physicalRegionSize_V3} = $physicalRegionSize;

            # Padding Phase
            if ($eyeCatch eq "HBI" && $testRun)
            {
                # If "--test" flag set do not pad as the test HBI images is
                # possibly larger than partition size and does not need to be
                # fully padded. Size adjustments made in checkSpaceConstraints
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=4k conv=sync");
                run_command("dd if=$tempImages{HDR_PHASE_V3} of=$tempImages{PAD_PHASE_V3} ibs=4k conv=sync");
            }
            else
            {
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
                run_command("dd if=$tempImages{HDR_PHASE_V3} of=$tempImages{PAD_PHASE_V3} ibs=$size conv=sync");
            }

            # If so instructed, retain pre-ECC versions of the output files
            # using the appropriate naming convention
            if ($emitEccless)
            {
                my($file,$dirs,$suffix) = fileparse($eccless_file);
                $file =~ s/(\.\w+)$/$eccless_prefix$1/;
                run_command("cp $tempImages{PAD_PHASE} $bin_dir/$file");

                my($file,$dirs,$suffix) = fileparse($eccless_file_V3);
                $file =~ s/(\.\w+)$/$eccless_prefix$1/;
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/V3/$file");
            }

            # Corrupt section if user specified to do so, before ECC injection.
            if ($secureboot && exists $partitionsToCorrupt{$eyeCatch})
            {
                # If no protected file ($tempImages{PAYLOAD_TEXT}) exists
                # for this partition, then that means there is no unprotected
                # section. A protected file is only created when there's a need
                # to split up the partition for signing purposes.
                corrupt_partition($eyeCatch, $protectedOffset,
                                  $tempImages{PAYLOAD_TEXT},
                                  $tempImages{PAD_PHASE});

                corrupt_partition($eyeCatch, $protectedOffset,
                                  $tempImages{PAYLOAD_TEXT_V3},
                                  $tempImages{PAD_PHASE_V3});
            }
        }
        # Handle partitions that have no input binary. Simply zero or random
        # fill the partition.
        elsif (!-e $bin_file)
        {
            if ($eyeCatch eq "HB_HLL")
            {
                # Create HB_HLL container with header and padding
                # - only need to create for V3.
                create_hb_hll($tempImages{HDR_PHASE_V3},$CUR_OPEN_SIGN_REQUEST_V3);

                # Update header fields (basically total container size)
                $callerHwHdrFields_V3{configure} = 1;
                setV3HdrCntrSize(\%callerHwHdrFields_V3, $tempImages{HDR_PHASE_V3});

                # Copy V3 file over to V1 file, as some shared logic below
                # might look for the V1 file
                run_command("cp $tempImages{HDR_PHASE_V3} $tempImages{HDR_PHASE}");

                # Pad the images ($size has previously been page aligned)
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
                run_command("dd if=$tempImages{HDR_PHASE_V3} of=$tempImages{PAD_PHASE_V3} ibs=$size conv=sync");

                # The PAD_PHASE_V3 has had its total container size updated and is
                # page aligned.  Copy out this padded, non-ecc file to be picked up in FSP builds
                # The FSP builds definitely need the file without ECC as they add it themselves
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/hb_hll.bin");
            }
            elsif ($eyeCatch eq "SBKT" && $secureboot && $keyTransition{enabled})
            {
                # Create SBKT container with header (no padding)
                # - only need to create for V3.
                create_sb_key_transition_container($tempImages{HDR_PHASE_V3});

                # Update header fields (basically total container size)
                $callerHwHdrFields_V3{configure} = 1;
                setV3HdrCntrSize(\%callerHwHdrFields_V3, $tempImages{HDR_PHASE_V3});

                # Copy V3 file over to V1 file, as some shared logic below
                # might look for the V1 file
                run_command("cp $tempImages{HDR_PHASE_V3} $tempImages{HDR_PHASE}");

                # Pad the images ($size has previously been page aligned)
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
                run_command("dd if=$tempImages{HDR_PHASE_V3} of=$tempImages{PAD_PHASE_V3} ibs=$size conv=sync");
            }
            else
            {
                # Test partitions have random data
                if ($eyeCatch eq "TEST" || $eyeCatch eq "TESTRO")
                {
                    run_command("dd if=/dev/urandom of=$tempImages{PAD_PHASE} count=1 bs=$size");
                    run_command("dd if=/dev/urandom of=$tempImages{PAD_PHASE_V3} count=1 bs=$size");

                }
                # Other partitions fill with FF's if no empty bin file provided
                else
                {
                    run_command("dd if=/dev/zero bs=$size count=1 | tr \"\\000\" \"\\377\" > $tempImages{PAD_PHASE}");
                    run_command("dd if=/dev/zero bs=$size count=1 | tr \"\\000\" \"\\377\" > $tempImages{PAD_PHASE_V3}");
                }

                # Add secure container header
                # Force TESTRO section to have a header
                if( ($eyeCatch eq "TESTRO") ||
                    (($sectionHash{$layoutKey}{sha512Version} eq "yes")
                     && ($eyeCatch ne "SBKT")))
                {
                    # Remove PAGE_SIZE bytes from generated dummy content of
                    # file to make room for the secure header
                    my $fileSize = (-s $tempImages{PAD_PHASE}) - PAGE_SIZE;
                    die "fileSize undefined: errno = $!"
                        unless(defined $fileSize);
                    run_command("dd if=$tempImages{PAD_PHASE} of=$tempImages{TEMP_BIN} count=1 bs=$fileSize");

                    my $fileSize_V3 = (-s $tempImages{PAD_PHASE_V3}) - PAGE_SIZE;
                    die "fileSize_V3 undefined: errno = $!"
                        unless(defined $fileSize_V3);
                    run_command("dd if=$tempImages{PAD_PHASE_V3} of=$tempImages{TEMP_BIN_V3} count=1 bs=$fileSize_V3");

                    if ($secureboot && $secureSupported)
                    {
                        $callerHwHdrFields{configure} = 1;
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PAD_PHASE}");
                        setCallerHwHdrFields(\%callerHwHdrFields,
                                             $tempImages{PAD_PHASE});

                        $callerHwHdrFields_V3{configure} = 1;
                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $tempImages{TEMP_BIN_V3} "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PAD_PHASE_V3}");
                        setV3HdrCntrSize(\%callerHwHdrFields_V3,
                                             $tempImages{PAD_PHASE_V3});

                    }
                    # Add non-secure version header
                    else
                    {
                        # Attach signature-less secure header for OpenPOWER builds
                        run_command("$CUR_OPEN_SIGN_REQUEST_V1 "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PAD_PHASE}");

                        run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                                    . "--protectedPayload $tempImages{TEMP_BIN_V3} "
                                    . "--contrHdrOut $final_header_file_V3 "
                                    . "--out $tempImages{PAD_PHASE_V3}");
                    }

                    # Save a copy of the original binary to package later,
                    #  only need this for sections that are temporarily zeros but eventually
                    #  will have real content
                    my $staged_bin_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.staged":
                        "$bin_dir/$system_target.$eyeCatch$nodeIDstr.staged";
                    run_command("cp -n $tempImages{TEMP_BIN} $staged_bin_file");

                    my $staged_bin_file_V3 = ($system_target eq "")? "$bin_dir/V3/$eyeCatch$nodeIDstr.staged":
                        "$bin_dir/V3/$system_target.$eyeCatch$nodeIDstr.staged";
                    run_command("cp -n $tempImages{TEMP_BIN_V3} $staged_bin_file_V3");

                }

                # Corrupt section if user specified to do so, before ECC injection.
                if ($secureboot && exists $partitionsToCorrupt{$eyeCatch})
                {
                    # If no protected file ($tempImages{PAYLOAD_TEXT}) exists
                    # for this partition, then that means there is no unprotected
                    # section. A protected file is only created when there's a need
                    # to split up the partition for signing purposes.
                    corrupt_partition($eyeCatch, $protectedOffset,
                                      $tempImages{PAYLOAD_TEXT},
                                      $tempImages{PAD_PHASE});

                    corrupt_partition($eyeCatch, $protectedOffset,
                                      $tempImages{PAYLOAD_TEXT_V3},
                                      $tempImages{PAD_PHASE_V3});
                }
            }

            # if we are requested to emit ipl lid artifacts ensure that the generated binary
            # from above is 4KB byte aligned and write a copy to the $bin_dir
            if ($eyeCatch eq "HB_HLL" && $emitIplLids)
            {
                # Since HB_HLL has already been padded to a boundary, just copy that out for ipllid
                # For HB_HLL, use V3 version for both sub-dirs
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/$eyeCatch.ipllid");
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/V3/$eyeCatch.ipllid");
            }
            elsif ($eyeCatch eq "SBKT" && $emitIplLids)
            {
                # Since SBKT has already been padded to a boundary, just copy that out for ipllid
                # For SBKT, use V3 version for both sub-dirs
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/$eyeCatch.ipllid");
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/V3/$eyeCatch.ipllid");
            }
            elsif ($emitIplLids)
            {
                # Get the files size and round it up to the next multiple of 4096
                my $file_size = -s $tempImages{PAD_PHASE};
                if(($file_size % 4096) ne 0)
                {
                    $file_size += (4096 - ($file_size % 4096));
                }
                # Create an empty file of all 0xFF's of $file_size
                run_command("dd if=/dev/zero bs=$file_size count=1 | tr \"\\000\" \"\\377\" > $bin_dir/$eyeCatch.ipllid");
                # Write the contents of tempImages[PAD_PHASE} to the begining of the file we just made
                run_command("dd if=$tempImages{PAD_PHASE} conv=notrunc of=$bin_dir/$eyeCatch.ipllid");

                # Do the same for V3
                my $file_size_V3 = -s $tempImages{PAD_PHASE_V3};
                if(($file_size_V3 % 4096) ne 0)
                {
                    $file_size_V3 += (4096 - ($file_size_V3 % 4096));
                }
                # Create an empty file of all 0xFF's of $file_size
                run_command("dd if=/dev/zero bs=$file_size_V3 count=1 | tr \"\\000\" \"\\377\" > $bin_dir/V3/$eyeCatch.ipllid");

                # Write the contents of tempImages[PAD_PHASE_V3} to the begining of the file we just made
                run_command("dd if=$tempImages{PAD_PHASE_V3} conv=notrunc of=$bin_dir/V3/$eyeCatch.ipllid");
            }

            if ($eyeCatch eq "SBKT" && $emitEccless)
            {
                # The PAD_PHASE_V3 has had its total container size updated and is
                # page aligned.  Copy out this padded, non-ecc file to be picked up in FSP builds
                # The FSP builds definitely need the file without ECC as they add it themselves
                # Copy to both directories just to be safe, even though the first (non-V3) one
                # should be used
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/sbkt.bin");
                run_command("cp $tempImages{PAD_PHASE_V3} $bin_dir/V3/sbkt.bin");
            }
        }

        # ECC Phase
        if( ($sectionHash{$layoutKey}{ecc} eq "yes") )
        {
            run_command("$jailcmd ecc --inject $tempImages{PAD_PHASE} --output $tempImages{ECC_PHASE} --p8");
            run_command("$jailcmd ecc --inject $tempImages{PAD_PHASE_V3} --output $tempImages{ECC_PHASE_V3} --p8");
        }
        else
        {
            run_command("cp $tempImages{PAD_PHASE} $tempImages{ECC_PHASE}");
            run_command("cp $tempImages{PAD_PHASE_V3} $tempImages{ECC_PHASE_V3}");
        }

        # Compression phase
        if( ($sectionHash{$layoutKey}{compressed}{algorithm} eq "xz"))
        {
            # Placeholder for compression partitions
        }

        # Move content to final bin filename
        if ($eyeCatch eq "HB_HLL")
        {
            # No need for V1 HB_HLL, so overwrite it with V3 HB_HLL
            # This will also put the V3 HB_HLL in the base $bin_dir
            # so it can be more easily found by some build tools.
            # In other words, by doing this, build tools won't have to
            # be updated to look for the HB_HLL in the different V3/
            # sub-directory versus where it picks up all of the other binaries
            run_command("cp $tempImages{ECC_PHASE_V3} $final_bin_file");
            run_command("cp $tempImages{ECC_PHASE_V3} $final_bin_file_V3");
        }
        elsif ($eyeCatch eq "SBKT")
        {
            # No need for V1 SBKT, so overwrite it with V3 SBKT
            # This will also put the V3 SBKT in the base $bin_dir
            # so it can be more easily found by some build tools.
            # In other words, by doing this, build tools won't have to
            # be updated to look for the SBKT in the different V3/
            # sub-directory versus where it picks up all of the other binaries
            run_command("cp $tempImages{ECC_PHASE_V3} $final_bin_file");
            run_command("cp $tempImages{ECC_PHASE_V3} $final_bin_file_V3");
        }
        else
        {
            run_command("cp $tempImages{ECC_PHASE} $final_bin_file");
            run_command("cp $tempImages{ECC_PHASE_V3} $final_bin_file_V3");
        }

        # Clean up temp images

        foreach my $image (keys %tempImages)
        {
            system("rm -f $tempImages{$image}");
            die "Failed deleting $tempImages{$image}" if ($?);
        }

        $node_id++;
    }
}

################################################################################
# manipulateImages - Perform any ECC/padding/sha/signing manipulations on one or more images
################################################################################

sub manipulateImages
{
    my ($i_pnorLayoutRef, $i_binFilesRef, $system_target) = @_;
    my $this_func = (caller(0))[3];

    trace(1, "manipulateImages");

    # Prefix for temporary files for parallel builds
    my $parallelPrefix = RAND_PREFIX.POSIX::ceil(rand(0xFFFFFFFF)).$system_target;

    my %preReqImages = (
        HBB_PAYLOAD_HASH_FILE => "$bin_dir/$parallelPrefix.hbb_payload_hash.bin",
        HBB_PAYLOAD_HASH_FILE_V3 => "$bin_dir/V3/$parallelPrefix.hbb_payload_hash.bin"
        );

    my @todo = keys %{$i_binFilesRef};
    my %done;

    # This hash table contains pairs in the form of "partition => dependency"
    my %deps =
    (
        'HBI' => 'HBB', # HBI depends on HBB being built first
        'HBB' => 'HBBL' # HBB depends on HBBL being built first
    );

    # Start off with our @todo list containing all the partitions, and
    # %done contains nothing. We loop through everything in the @todo
    # list, and as long as the partition doesn't have a dependency
    # that hasn't been processed, we process it and add it to the
    # %done list. This way we process things in batches grouped by the
    # criteria of "all dependencies satisfied."
    # Repeat this process until the @todo list contains the same
    # number of elements as the %done list.
    # NOTE: HB_HLL must be processed last since it requires all of the other
    #       images to have already been processed such that the HB_HLL can
    #       incorporate the other images' V3 security headers.  Therefore,
    #       HB_HLL will be skipped in this loop and processed after the loop
    #       is done with the other images (aka keys).
    my $key_hb_hll = "HB_HLL";
    while (scalar(@todo) != scalar(keys %done))
    {
        my @pids = ();

        # Create a new process for each partition that we can operate
        # on now
        foreach my $key (@todo)
        {
            if ($key eq $key_hb_hll)
            {
                # Since HB_HLL must be processed last, put it on the done list
                # It will be processed after the outer while() loop is completed
                $done{$key} = 1;
                next;
            }

            if (exists($done{$key}))
            {
                next;
            }

            if (exists($deps{$key}) && !exists($done{$deps{$key}}))
            {
                next;
            }

            my $pid;

            if(!defined($pid = fork())) {
                die "fork() failed with code $!";
            } elsif ($pid == 0) {
                manipulateImage($key, $i_pnorLayoutRef, $i_binFilesRef, $parallelPrefix, \%preReqImages, $system_target);
                exit 0;
            } else {
                my @info = ($pid, $key);
                push(@pids, \@info);
            }

            if (scalar(@pids) >= $max_processes)
            {
                last;
            }
        }

        # Wait for all the processes to finish
        foreach my $info (@pids)
        {
            my ($pid, $key) = @{$info};

            waitpid($pid, 0);

            if ($? != 0)
            {
                die "Child failed with exit code $?\n";
            }

            $done{$key} = 1;
        }
    }

    # Process HB_HLL last here since it requires all of the other images to
    # have already been processed such that the HB_HLL can incorporate the
    # other images' V3 security headers
    manipulateImage($key_hb_hll, $i_pnorLayoutRef, $i_binFilesRef, $parallelPrefix, \%preReqImages, $system_target);


    # Clean up prerequisite images
    foreach my $image (keys %preReqImages)
    {
        system("rm -f $preReqImages{$image}");
        die "Failed deleting $preReqImages{$image}" if ($?);
    }

    return 0;
}

################################################################################
# corrupt_partition : Corrupts a single byte of a section's bin file.
#                     The input $protected_file is used to determine the
#                     unprotected offset. Some partitions have no unprotected
#                     section, so the file DNE.
#                     *Note: this should be run before ECC is injected.
################################################################################
sub corrupt_partition
{
    my ($eyeCatch, $protected_offset, $protected_file, $bin_file) = @_;

    die "Error> Missing bin file to corrupt $bin_file" if (!-f $bin_file);

    my $section = $partitionsToCorrupt{$eyeCatch};
    my $offset = 0;
    my $bin_file_size = -s $bin_file;
    die "size of $bin_file undef" unless(defined $bin_file_size);

    if ($section eq $CORRUPT_PROTECTED)
    {
        $offset = $protected_offset;
    }
    elsif ($section eq $CORRUPT_UNPROTECTED)
    {
        # If no protected_file file exists for this partition, then that means
        # there is no unprotected section. A protected_file is only created
        # when there's a need to split up the partition for signing purposes.
        # *Note: Must add PAGE_SIZE to protected size as it does not include
        #        the secure container header.
        $offset = (-f $protected_file) ? (-s $protected_file)+PAGE_SIZE : 0;
        die "offset undef" unless(defined $offset);
        if ($offset == 0)
        {
            die "Error> Section $eyeCatch does not have an unprotected section to corrupt";
        }
        elsif ($offset <= $protected_offset)
        {
            die "Error> Unprotected offset($offset) <= Protected offset($protected_offset)";
        }
    }
    else
    {
        die "Error> Unsupported --corrupt value \"$section\"";
    }

    # Error checking
    die "Error> corrupt offset not set" if ($offset == 0);
    die "Error> Offset=$offset is past the size of the bin file to corrupt size=$bin_file_size" if ($offset >= $bin_file_size);

    # Corrupt partition
    my $num_pages_to_corrupt = 1;
    # If corrupting the unprotected HBI section, corrupt multiple pages in
    # attempt to corrupt a page that is actually used to result in a VFS
    # verify page failure.
    if (($eyeCatch eq "HBI") && ($section eq $CORRUPT_UNPROTECTED))
    {
        $num_pages_to_corrupt = MAX_PAGES_TO_CORRUPT;
    }
    for (my $i = 0; $i < $num_pages_to_corrupt; $i++)
    {
        my $page_offset = $i*PAGE_SIZE;
        my $hex_offset = sprintf("0x%X", $offset + $page_offset);
        trace(1,"Corrupting $eyeCatch $section section offset=$hex_offset");
        # dd used with seek to manipulate a bin file in-place at a specific location.
        run_command("printf \'\\xaf\' | dd conv=notrunc of=$bin_file bs=1 seek=\$(($hex_offset))");
    }
}

################################################################################
# page_aligned_size_wo_ecc : Size of partition without ECC, rounded down to
#                            nearest multiple of PAGE_SIZE.
################################################################################
sub page_aligned_size_wo_ecc
{
    my ($size) = @_;

    die "Size must be at least (9/8)*PAGE_SIZE" if ($size < ((9/8)*PAGE_SIZE));
    return POSIX::floor((($size * 8) / 9) / PAGE_SIZE) * PAGE_SIZE;
}

################################################################################
# truncate_sha - Truncates sha hash
#   @return sha hash if already less than truncate size
#           otherwise truncated sha hash
################################################################################
sub truncate_sha
{
    my ($sha) = @_;
    # Switch Perl to byte mode vs char mode. Only lasts in scope.
    use bytes;
    (length($sha) < SHA_TRUNCATE_SIZE)? return $sha :
            return substr ($sha, 0, SHA_TRUNCATE_SIZE);
}

################################################################################
# genHashPageTable - Generates hash page table for PNOR partitions
#   @return filename of binary hash page table content
################################################################################
sub genHashPageTable
{
    my ($bin_file, $eyeCatch, $hashPageTableDir, $saltData) = @_;

    # Open the file
    my $hashPageTableFile = "$hashPageTableDir/$eyeCatch.page_hash_table";
    open (INBINFILE, "<", $bin_file) or die "Error opening file $bin_file: $!\n";
    open (OUTBINFILE, ">", $hashPageTableFile) or die "Error opening file $hashPageTableFile: $!\n";
    # set stream to binary mode
    binmode INBINFILE;
    binmode OUTBINFILE;

    # Enter Salt as first entry
    my $salt_entry = 0;
    if (defined $saltData)
    {
        # Use input salt data
        $salt_entry = truncate_sha(sha3_512($saltData));
    }
    else
    {
        # Use the same salt data for all builds.
        # For now use zero
        # @TODO JIRA PFHB-932 will implement the use of a build-wide "salt"
        # file created via a random number
        $saltData=0;
        $salt_entry = truncate_sha(sha3_512($saltData));
    }
    my @hashes = ($salt_entry);
    print OUTBINFILE $salt_entry;

    # boundary
    my $total_pages = POSIX::ceil((-s INBINFILE)/PAGE_SIZE);
    # read buffer
    my $data;
    # Read data in chunks of PAGE_SIZE bytes
    my $index = 1;
    while ($index <= $total_pages)
    {
        read(INBINFILE,$data,PAGE_SIZE);
        die "genHashPageTable reading of $bin_file failed" if $!;
        # Add trailing zeros back in to pages at the end of the bin file.
        if(length($data) < PAGE_SIZE)
        {
            my $pads = PAGE_SIZE - length($data);
            $data .= pack ("@".$pads);
        }

        # hash(salt + data)
        #   salt = previous entry
        #   data = current page
        my $hash_entry = truncate_sha(sha3_512($hashes[$index-1].$data));
        push @hashes, $hash_entry;
        $index++;
        print OUTBINFILE $hash_entry;
    }

    close INBINFILE or die "Error closing $bin_file: $!\n";
    close OUTBINFILE or die "Error closing $hashPageTableFile: $!\n";

    # Pad hash page table to a multiple of page size (4K)
    my $temp_file = "$hashPageTableDir/$eyeCatch.page_hash_table.temp";
    run_command("cp $hashPageTableFile $temp_file");
    run_command("dd if=$temp_file of=$hashPageTableFile ibs=4k conv=sync");
    run_command("rm $temp_file");

    return $hashPageTableFile;
}

################################################################################
# gen_test_containers : Generate test containers used in hostboot CXX tests
#       Documents how the original test container files were generated for use
#       by CXX tests. Note these files have been cached via "hb cacheadd". This
#       simply provides transparency on how they were originally generated.
#       They will not match the original file as the executable generates a
#       unique container each time, even if the code is the same.
################################################################################
sub gen_test_containers
{
    my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
    my %tempImages = (
        TEST_CONTAINER_DATA => "$bin_dir/$randPrefix.test.cont.bin",
        PROTECTED_PAYLOAD => "$bin_dir/$randPrefix.test.protected_payload.bin"
    );

    # Setup open signing for test image
    my $header = $sb_hdrs{DEFAULT};

    my $openSigningFlags = OP_SIGNING_FLAG.$header->{flags};

    # At this time this file will only support V3 signed test containers
    my $CUR_OPEN_SIGN_REQUEST = "$OPEN_SIGN_REQUEST_V3 $openSigningFlags";

    my $componentId = "TESTCONT";
    $CUR_OPEN_SIGN_REQUEST .= " --sign-project-FW-token $componentId ";

    # Create a signed test container
    # name = secureboot_signed_container (no prefix in hb cacheadd)
    my $test_container = "$bin_dir/secureboot_signed_container";
    run_command("dd if=/dev/zero count=1 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    run_command("$CUR_OPEN_SIGN_REQUEST --protectedPayload $tempImages{TEST_CONTAINER_DATA} --out $test_container");

    # Create a signed test container with a hash page table
    # name = secureboot_hash_page_table_container (no prefix in hb cacheadd)
    $test_container = "$bin_dir/secureboot_hash_page_table_container";
    run_command("dd if=/dev/urandom count=5 ibs=4096 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    $tempImages{hashPageTable} = genHashPageTable($tempImages{TEST_CONTAINER_DATA}, "secureboot_test", $bin_dir);
    run_command("$CUR_OPEN_SIGN_REQUEST --protectedPayload $tempImages{hashPageTable} --out $tempImages{PROTECTED_PAYLOAD}");
    run_command("cat $tempImages{PROTECTED_PAYLOAD} $tempImages{TEST_CONTAINER_DATA} > $test_container ");

    # Clean up temp images
    foreach my $image (keys %tempImages)
    {
        system("rm -f $tempImages{$image}");
        die "Failed deleting $tempImages{$image}" if ($?);
    }
}

################################################################################
# create_sb_key_transition_container
#       Generate sb key transition container used for transitioning the
#       security keys of a system between development-production and v1-v3
#       Format:
#           SB_HDR_OLD_KEY[SB_HDR_NEW_KEY[4K rand blob]]
#       Steps:
#           1. Generate 4K blob of random data
#           2. Sign #1 with new keys
#           3. Sign combination of #1 and #2 with the old keys
################################################################################
sub create_sb_key_transition_container
{
    my ($o_file) = @_;

    my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
    my %tempImages = (
        RAND_BLOB => "$bin_dir/$randPrefix.rand_blob.bin",
        PRD_KEY_FILE => "$bin_dir/$randPrefix.sbkt_prod_key.bin",
    );

    # Gen 4K blob of random data
    run_command("dd if=/dev/urandom of=$tempImages{RAND_BLOB} count=1 bs=4k");

    die "Key transition not allowed in $sign_mode mode" if ($OPEN_SIGN_KEY_TRANS_NEW eq "");

    # Create a signed container with new keys
    run_command("$OPEN_SIGN_KEY_TRANS_NEW".OP_SIGNING_FLAG
        . "$sb_hdrs{SBKT}{inner}{flags} --protectedPayload $tempImages{RAND_BLOB} "
        . "--out $tempImages{PRD_KEY_FILE}");

    # Sign new production key container with old keys
    my $sbktComponentIdArg = "--sign-project-FW-token SBKT ";
    run_command("$OPEN_SIGN_KEY_TRANS_OLD ".$sbktComponentIdArg.OP_SIGNING_FLAG
        . "$sb_hdrs{SBKT}{outer}{flags} --protectedPayload $tempImages{PRD_KEY_FILE} "
        . "--out $o_file");

    # Clean up temp images
    foreach my $image (keys %tempImages)
    {
        system("rm -f $tempImages{$image}");
        die "Failed deleting $tempImages{$image}" if ($?);
    }
}


################################################################################
# create_hb_hll
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
#       struct HB_HLL_SectionEntry
#       {
#           uint8_t  PartName[16];
#           uint64_t ProtectedSize;
#           uint64_t SectionSize;
#           uint8_t  Hash[64];
#       } __attribute__ ((packed));
#
#       Steps:
#           1. Generate section entries for all *.header files in /V3/ subdir
#              and combine them into one HB_HLL.entries file
#           2. Create HB_HLL Header (aka TOC) based on number of section entries
#           3. Combine (cat) the HB_HLL Header TOC and HB_HLL.entries file
#           4. Sign with V3 algorithm
################################################################################
sub create_hb_hll
{
    my ($o_file, $CUR_OPEN_SIGN_REQUEST_V3) = @_;

    my $v3_dir = "$bin_dir/V3/";
    my %hbHllTempImages = (
        HB_HLL_Entries => "$v3_dir/HB_HLL.entries",
        HB_HLL_TOC => "$v3_dir/HB_HLL.toc",
    );
    # Leave these 2 files in the V3 directory
    my $HB_HLL_BIN = "$v3_dir/HB_HLL.bin";
    my $HB_HLL_HDR = "$v3_dir/HB_HLL.header";

    # this is the file that will be returned
    my $HB_HLL_TEMP_HDR_BIN = "$v3_dir/HB_HLL.temp.hdr.bin";

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


    # Generate section entries from the existing *.header files and then
    # combine them into the single HB_HLL_Entries file

    # This returns the full path and name for the existing .header files
    my @files = glob( $v3_dir . '/*.header' );
    my $num_of_entries = scalar(@files);

    foreach my $v3_header_file (@files)
    {
        my $basename = $v3_header_file;
        # Remove file path and .header extension
        $basename =~ s{^.*/|\.[^.]+$}{}g;
        my $entry_file = "$v3_dir/${basename}.entry";

        # Create and clear new .entry file
        run_command("dd if=/dev/zero bs=96 count=1 > $entry_file");

        # Get and set the partname - string left-justified (ie starts at bit0)
        # NOTE: this comes from Component ID
        run_command("dd if=$v3_header_file bs=1 count=$HB_HLL_PART_NAME_SIZE conv=notrunc seek=0 skip=10347 of=$entry_file");

        # Get and set the ProtectedSize;
        run_command("dd if=$v3_header_file bs=1 count=8 conv=notrunc seek=16 skip=10360 of=$entry_file");

        # Get and set the overall SectionSize
        run_command("dd if=$v3_header_file bs=1 count=8 conv=notrunc seek=24 skip=6 of=$entry_file");

        # Get and set the hash value
        run_command("dd if=$v3_header_file bs=1 count=64 conv=notrunc seek=32 skip=10376 of=$entry_file");

        # Uncomment next line for debug
        #run_command("hexdump -C $entry_file");

        # Append this entry file to the overall HB_HLL entries file
        run_command("cat $entry_file >> $hbHllTempImages{HB_HLL_Entries}");
    }

    # Uncomment next line for debug
    #run_command("hexdump -C $hbHllTempImages{HB_HLL_Entries}");

    # Create HB_HLL Header Section (aka TOC)
    my $FILEHANDLE;
    open( $FILEHANDLE, ">:raw", $hbHllTempImages{HB_HLL_TOC})
        or die "Error opening file $hbHllTempImages{HB_HLL_TOC}: $!\n";

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
    print $FILEHANDLE pack("n", $num_of_entries);

    # - set hashSignMode (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_HASH_SIGN_MODE);

    # - set hash entry struct size (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_HASH_ENTRY_STRUCT_SIZE);

    # - set offset to list entries (uint16_t)
    print $FILEHANDLE pack("n", $HB_HLL_OFFSET_TO_LIST_ENTRIES);

    # - pad the remaining "reserved" 108 bytes with null characters
    print $FILEHANDLE pack("C[108]", map { 0 } 1..108);

    close $FILEHANDLE or die "Error closing $hbHllTempImages{HB_HLL_TOC}: $!\n";

    # Uncomment next line for debug
    #run_command("hexdump -C $hbHllTempImages{HB_HLL_TOC}");

    # Combine (cat) the two files (TOC and Entries file)
    run_command("cat $hbHllTempImages{HB_HLL_TOC} $hbHllTempImages{HB_HLL_Entries} > $HB_HLL_BIN");

    # Uncomment for debug
    #run_command("hexdump -C $HB_HLL_BIN");

    # Sign the binary to create the .header file
    run_command("$CUR_OPEN_SIGN_REQUEST_V3 "
                . "--protectedPayload $HB_HLL_BIN "
                . "--contrHdrOut $HB_HLL_HDR "
                . "--out $o_file ");

    # Clean up temp images
    foreach my $image (keys %hbHllTempImages)
    {
        system("rm -f $hbHllTempImages{$image}");
        die "Failed deleting $hbHllTempImages{$image}" if ($?);
    }
}


################################################################################
# convertEyecatchToCompId
#     Converts eyecatcher to component ID, truncating it to the lesser of its
#     current size or MAX_COMP_ID_LEN bytes, in order to fit within the confines
#     of the component ID field of the firmware header.
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
# setCallerHwHdrFields
#       Sets the caller hardware header fields in the passed in file based on
#       the input hash passed in.
#       NOTE: Only suports V1 headers
################################################################################
sub setCallerHwHdrFields
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
        my $callerHwHdr = sprintf("%016llX%016llX%016llX",
            $i_callerHwHdrFields->{totalContainerSize},
            $i_callerHwHdrFields->{targetHrmor},
            $i_callerHwHdrFields->{instructionStartStackPointer});
        run_command( "echo \"$callerHwHdr\" | xxd -r -ps -seek 6 - $i_file");
    }
}

################################################################################
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $programName = Manipulates bin files to prepare for building of pnor.

  Usage:
    $programName --pnorlayout <layout xml file>
             --systemBinFiles HBI=hostboot_extended.bin,HBEL=HBEL.bin,GUARD=EMPTY
             --systemBinFiles MURANO:HBD=simics_MURANO_targeting.bin
             --build-all --test --binDir <path> --secureboot --corrupt HBI

  Parms:
    -h|--help           Print this help text
    --pnorlayout <file> PNOR Layout XML file
    --build-all         Indicates script should operate as if in ODE build_all
                        This is used to handle things that should happen once in
                        build_all phase and avoid parallel call issues.
    --systemBinFiles    [SYSTEM:]<NAME=FILE,NAME=FILE> CSV of bin files to format. Multiple '--systemBinFiles' allowed
                            Optional prefix 'SYSTEM:' used to specify with system bin files are being built.
                            If a section has multiple bin files associated with it, just have multiple NAME=FILENAME pairs
                            For sections <NAME> that simply require zero-filling, you can pass in EMPTY or
                                any non-existing file. If a file DNE, the script will handle accordingly.
                            Example: HBI=hostboot_extended.bin,GUARD=EMPTY
                                     MURANO:HBD=simics_MURANO_targeting.bin
    --test              Output test-only sections.
    --secureboot        Indicates a secureboot build.
    --secure-version    Indicates security version value to be built into the partition headers
    --corrupt           <Partition name>[= pro|unpro] (Note: requires '--secureboot')
                        Partition 'eyeCatch' name to corrupt a byte of.
                        Optional '= pro|unpro' to indicate which section of the secure container to corrupt.
                            Default (empty string '') is protected section.
                            [Note: Some sections only have a protected section so not relevant for all.]
                        Multiple '--corrupt' options are allowed, but note the system will checkstop on the
                            first bad partition so multiple may not be that useful.
                        Example: --corrupt HBI --corrupt HBD=unpro
    --sign-mode <development|production>
                                  Indicates how to sign partitions with either development keys or production keys
    --key-transition <development|production|prod-prod>-V3
                                  Indicates a key transition is needed and creates a secureboot key transition container.
                                  Note: Transition images to V1 are not supported, but for clarity "-V3" must be appended to argument
                                  Note: "--sign-mode production" is not allowed with "--key-transition development"
                                  With [--test] will transition to test dev keys, which are a fixed permutation of development keys.
    --lab-security-override       If signing SBE image, set bit in signing
                                      header which turns on security override
                                      checking in the SBE the next time it is
                                      updated and invoked.  When security
                                      override checking is enabled, SBE will
                                      check mailbox scratch register 3 bit 6 and
                                      if set, disable security.  Otherwise, it
                                      will retain the existing security
                                      settings.  NOTE: Only allowed for
                                      development signed images.
    --no-lab-security-override    If signing SBE image, clear bit in signing
                                      header which disables security override
                                      checking in the SBE the next time it is
                                      updated and invoked.  When security
                                      override checking is disabled, the only
                                      way to bypass security is by manipulating
                                      physical jumpers on the system planar.
    --emit-eccless                In addition to typical output, also emit
                                      ECC-less versions of any input binaries
    --emit-ipl-lids               In addition to typical output, also emit
                                      .ipllid files which can be used for IPL
                                      time lids for eBMC systems.
    --build-type                  Specify whether the type of build is FIPS or
                                      OpenPower, indicated by either 'fspbuild'
                                      or 'opbuild' immediately following the
                                      switch (separated with a space and not
                                      including the single quotes). OpenPower is
                                      the default.
    --editedLayoutLocation <directory>      Location to place edited layout file

  Current Limitations:
    - Issues with dependency on ENGD build for certain files such as SBE. This is why [--build-all | --install-all ] are used.
ENDUSAGE
}
