#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/genPnorImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2021
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
                 getSwSignatures getBinDataFromFile);
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
# Max logical HBBL content size is 32K
my $MAX_HBBL_SIZE = 32768;

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
use constant OP_BUILD_FLAG => 0x80000000;
use constant FIPS_BUILD_FLAG => 0x40000000;
# Applies to SBE image only
use constant LAB_SECURITY_OVERRIDE_FLAG => 0x00080000;
use constant KEY_TRANSITION_FLAG => 0x00000001;
# Size of HW keys' Hash and Secure Version
use constant HW_KEYS_HASH_SIZE => 64;
use constant SECURE_VERSION_SIZE => 1;

# Dynamic support for choosing FSP or op-build flag type.
# Default to OP build
my $buildFlag = OP_BUILD_FLAG;

# Corrupt parameter strings
my $CORRUPT_PROTECTED = "pro";
my $CORRUPT_UNPROTECTED = "unpro";
use constant MAX_PAGES_TO_CORRUPT => 10;
# rand file prefix string. Note hbDistribute cleans up files with this prefix
use constant RAND_PREFIX => "rand-";

# Signing modes
my $DEVELOPMENT = "development";
my $IMPRINT = "imprint";
my $PRODUCTION = "production";
my $INDEPENDENT = "independent";

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

# Get the build type
if ($buildType eq "fspbuild")
{
    $buildFlag = FIPS_BUILD_FLAG;
}

# Put mode transition input into a hash and ensure a valid signing mode
my %signMode = ( $DEVELOPMENT => 1,
                 $PRODUCTION => 0,
                 $INDEPENDENT => 0 );
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
                      $IMPRINT => 0,
                      $PRODUCTION => 0 );
if ($key_transition =~ m/^$IMPRINT/i)
{
    $keyTransition{$IMPRINT} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition =~ m/^$PRODUCTION/i)
{
    $keyTransition{$PRODUCTION} = 1;
    $keyTransition{enabled} = 1;
}
elsif ($key_transition ne "")
{
    die "Invalid key transition mode = $key_transition";
}

my $labSecurityOverrideFlag = 0;
my $ktSecurityOverrideFlag = 0;
if($labSecurityOverride)
{
    if($signMode{$DEVELOPMENT})
    {
        $labSecurityOverrideFlag = LAB_SECURITY_OVERRIDE_FLAG;
        if($keyTransition{$IMPRINT})
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

# Signing and Dev key directory location set via env vars
my $SIGNING_DIR = $ENV{'SIGNING_DIR'};
my $DEV_KEY_DIR = $ENV{'DEV_KEY_DIR'};

if ($secureboot)
{
    # Check all components needed for developer signing
    die "Signing Dir = $SIGNING_DIR DNE" if(! -d $SIGNING_DIR);
    die "Dev Key Dir = $DEV_KEY_DIR DNE" if(! -d $DEV_KEY_DIR);
    die "hw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_a*"));
    die "hw_key_b DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_b*"));
    die "hw_key_c DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_c*"));
    die "sw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/sw_key_a*"));
}

### Open POWER signing
# In most cases this is desired, but do not override a value set by user
if(!$ENV{'SB_KEEP_CACHE'})
{
    $ENV{'SB_KEEP_CACHE'} = "true";
}

my $OPEN_SIGN_REQUEST=
    "$SIGNING_DIR/crtSignedContainer.sh --scratchDir $bin_dir ";
# By default key transition container is unused
my $OPEN_SIGN_KEY_TRANS_REQUEST = $OPEN_SIGN_REQUEST;

# Production signing parameters
my $OPEN_PRD_SIGN_PARAMS = "--mode production "
    . "--hwKeyA __get "
    . "--hwKeyB __get "
    . "--hwKeyC __get "
    . "--swKeyP __get ";

# Imprint key signing parameters.  In a non-secure compile, omit the keys to
# generate a secure header without signatures
my $OPEN_DEV_SIGN_PARAMS = "";
if($secureboot)
{
    $OPEN_DEV_SIGN_PARAMS = "--mode $sign_mode "
    . "--hwKeyA $DEV_KEY_DIR/hw_key_a.key "
    . "--hwKeyB $DEV_KEY_DIR/hw_key_b.key "
    . "--hwKeyC $DEV_KEY_DIR/hw_key_c.key "
    . "--swKeyP $DEV_KEY_DIR/sw_key_a.key";
}

# Handle key transition and production signing logic
# If in production mode, key transition is not supported yet
# If in developement mode, key transition can move to either imprint or
#   production keys
if ($signMode{$PRODUCTION})
{
    # Production to Production key transition not supported yet
    $OPEN_SIGN_REQUEST .= $OPEN_PRD_SIGN_PARAMS;
    $OPEN_SIGN_KEY_TRANS_REQUEST = "";
}
elsif ($keyTransition{enabled} && $signMode{$DEVELOPMENT})
{
    $OPEN_SIGN_REQUEST .= $OPEN_DEV_SIGN_PARAMS;

    # Since this request signs 4k of random data for SBKT, but is not a named
    # section, we'll make up a component ID of "SBKTRAND"
    my $sbktDataComponentIdArg = "--sign-project-FW-token SBKTRAND";
    if ($keyTransition{$IMPRINT})
    {
        $OPEN_SIGN_KEY_TRANS_REQUEST .=
            "$OPEN_DEV_SIGN_PARAMS $sbktDataComponentIdArg";
    }
    elsif ($keyTransition{$PRODUCTION})
    {
        $OPEN_SIGN_KEY_TRANS_REQUEST .=
            "$OPEN_PRD_SIGN_PARAMS $sbktDataComponentIdArg";
    }
}
else
{
    $OPEN_SIGN_REQUEST .= $OPEN_DEV_SIGN_PARAMS;
    $OPEN_SIGN_KEY_TRANS_REQUEST = "";
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

if ($signMode{$PRODUCTION})
{
    # In production mode, allow at most 1 signing process to run
    # at once. If we run more, it could cause file name collisions.
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
    $OPEN_SIGN_REQUEST .= " --security-version $secureVersionStr ";
}

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

    my %callerHwHdrFields = (
        configure => 0,
        totalContainerSize => 0,
        targetHrmor => 0,
        instructionStartStackPointer => 0);

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
        PROTECTED_PAYLOAD => "$bin_dir/$parallelPrefix.$eyeCatch.protected_payload.bin"
        );

    my $size = $sectionHash{$layoutKey}{physicalRegionSize};

    # Get size of partition without ecc
    if ($sectionHash{$layoutKey}{ecc} eq "yes")
    {
        $size = page_aligned_size_wo_ecc($size);
    }

    # Sections that have secureboot support. Secureboot still must be
    # enabled for secureboot actions on these partitions to occur.
    my $isNormalSecure = ($eyeCatch eq "HBBL");
    $isNormalSecure ||= ($eyeCatch eq "PAYLOAD");
    $isNormalSecure ||= ($eyeCatch eq "OCC");
    $isNormalSecure ||= ($eyeCatch eq "CAPP");
    $isNormalSecure ||= ($eyeCatch eq "BOOTKERNEL");
    $isNormalSecure ||= ($eyeCatch eq "IMA_CATALOG");
    $isNormalSecure ||= ($eyeCatch eq "TESTRO");
    $isNormalSecure ||= ($eyeCatch eq "TESTLOAD");
    $isNormalSecure ||= ($eyeCatch eq "VERSION");
    $isNormalSecure ||= ($eyeCatch eq "CENHWIMG");
    $isNormalSecure ||= ($eyeCatch eq "HCODE_LID");

    my $isSpecialSecure = ($eyeCatch eq "HBB");
    $isSpecialSecure ||= ($eyeCatch eq "HBD");
    $isSpecialSecure ||= ($eyeCatch eq "HBI");
    $isSpecialSecure ||= ($eyeCatch eq "WOFDATA");
    $isSpecialSecure ||= ($eyeCatch eq "SBE");
    $isSpecialSecure ||= ($eyeCatch eq "HCODE");
    $isSpecialSecure ||= ($eyeCatch eq "MEMD");
    $isSpecialSecure ||= ($eyeCatch eq "OCMBFW");

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

    my $CUR_OPEN_SIGN_REQUEST = "$OPEN_SIGN_REQUEST $openSigningFlags";
    my $componentId = convertEyecatchToCompId($eyeCatch);
    $CUR_OPEN_SIGN_REQUEST .= " --sign-project-FW-token $componentId ";

    # Used for corrupting partitions. By default all protected offsets start
    # immediately after the container header which is size = PAGE_SIZE.
    # *Note: this is before ECC.
    my $protectedOffset = PAGE_SIZE;

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
                glob("$bin_dir/SIGNTOOL_*/$componentId/*sig_p.raw $bin_dir/SIGNTOOL_*/$componentId/*key_p.sig");
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
        my $final_bin_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.bin":
            "$bin_dir/$system_target.$eyeCatch$nodeIDstr.bin";

        # Check if bin file is system specific and prefix target to the front
        my $final_header_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.header":
            "$bin_dir/$system_target.$eyeCatch$nodeIDstr.header";

        # Handle partitions that have an input binary.
        if (-e $bin_file)
        {
            # Track original name and whether file has a header or not in order
            # to emit eccless outputs, if requested
            my $eccless_file = $bin_file;
            my $eccless_prefix = "";

            # HBBL + ROM combination
            if ($eyeCatch eq "HBBL")
            {
                # Ensure the HBBL partition isn't too large
                my $hbblRawSize = (-s $bin_file or die "Cannot get size of file $bin_file");
                print "HBBL raw size ($bin_file) (no padding/ecc) = $hbblRawSize/$MAX_HBBL_SIZE\n";
                if ($hbblRawSize > $MAX_HBBL_SIZE)
                {
                    die "HBBL raw size is too large";
                }

                # Pad HBBL to max size before Header Phase
                run_command("cp $bin_file $tempImages{TEMP_BIN}");
                run_command("dd if=$tempImages{TEMP_BIN} of=$bin_file ibs=$MAX_HBBL_SIZE conv=sync");

            }

            # Header Phase
            if($sectionHash{$layoutKey}{sha512Version} eq "yes")
            {
                $eccless_prefix.=".header";
                # Add secure container header
                if ($secureboot && $isSpecialSecure)
                {
                    $callerHwHdrFields{configure} = 1;
                    if (exists $hashPageTablePartitions{$eyeCatch})
                    {
                        if ($eyeCatch eq "HBI")
                        {
                            # Pass HBB sw signatures as the salt entry.
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch,
                                                                          getBinDataFromFile($preReqImages->{HBB_SW_SIG_FILE}));
                        }
                        else
                        {
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch);
                        }
                    }
                    # Add hash page table
                    if ($tempImages{hashPageTable} ne "" && -e $tempImages{hashPageTable})
                    {
                        trace(1,"Adding hash page table for $eyeCatch");
                        my $hashPageTableSize = -s $tempImages{hashPageTable};
                        die "hashPageTable size undefined: errno = $!" unless(defined $hashPageTableSize);
                        # Move protected offset after hash page table.
                        $protectedOffset += $hashPageTableSize;
                        if ($eyeCatch eq "HBI")
                        {
                            # Add the VFS module table to the payload text section.
                            run_command("dd if=$bin_file of=$tempImages{VFS_MODULE_TABLE} count=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            # Remove VFS module table from bin file
                            run_command("dd if=$bin_file of=$tempImages{TEMP_BIN} skip=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            run_command("cp $tempImages{TEMP_BIN} $bin_file");
                            # Pad after hash page table to have the VFS module table end at a 4K boundary
                            my $padSize = PAGE_SIZE - (($hashPageTableSize + VFS_MODULE_TABLE_MAX_SIZE) % PAGE_SIZE);
                            run_command("dd if=/dev/zero bs=$padSize count=1 | tr \"\\000\" \"\\377\" >> $tempImages{hashPageTable} ");

                            # Move protected offset after padding of hash page table.
                            $protectedOffset += $padSize;

                            # Payload text section
                            run_command("cat $tempImages{hashPageTable} $tempImages{VFS_MODULE_TABLE} > $tempImages{PAYLOAD_TEXT} ");
                        }
                        else
                        {
                            run_command("cp $tempImages{hashPageTable} $tempImages{PAYLOAD_TEXT}");
                            # Hash table generated so need to set sw-flags
                            my $hex_sw_flag = sprintf("0x%08X", SW_FLAG_HAS_A_HPT);
                            $CUR_OPEN_SIGN_REQUEST .= " --sw-flags $hex_sw_flag ";
                        }

                        run_command("$CUR_OPEN_SIGN_REQUEST "
                                    . "--protectedPayload $tempImages{PAYLOAD_TEXT} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");

                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file > $tempImages{HDR_PHASE}");
                    }
                    # Handle read-only protected payload
                    elsif ($eyeCatch eq "HBD")
                    {
                        run_command("$CUR_OPEN_SIGN_REQUEST "
                                    . "--protectedPayload $bin_file.protected "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PROTECTED_PAYLOAD}");

                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file.unprotected > $tempImages{HDR_PHASE}");
                    }
                    else
                    {
                        my $codeStartOffset = ($eyeCatch eq "HBB") ?
                            "--code-start-offset 0x00000180" : "";
                        run_command("$CUR_OPEN_SIGN_REQUEST "
                                    . "$codeStartOffset "
                                    . "--protectedPayload $bin_file "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{HDR_PHASE}");
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
                        # Save off HBB sw signatures for use by HBI
                        open (HBB_SW_SIG_FILE, ">",
                              $preReqImages->{HBB_SW_SIG_FILE}) or die "Error opening file $preReqImages->{HBB_SW_SIG_FILE}: $!\n";
                        binmode HBB_SW_SIG_FILE;
                        print HBB_SW_SIG_FILE getSwSignatures($tempImages{HDR_PHASE});
                        die "Error writing to $preReqImages->{HBB_SW_SIG_FILE} failed" if $!;
                        close HBB_SW_SIG_FILE;
                        die "Error closing of $preReqImages->{HBB_SW_SIG_FILE} failed" if $!;
                    }
                }
                elsif($secureboot && $isNormalSecure)
                {
                    $callerHwHdrFields{configure} = 1;
                    run_command("$CUR_OPEN_SIGN_REQUEST "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file "
                                . "--out $tempImages{HDR_PHASE}");
                }
                # Add non-secure version header
                else
                {
                    # Attach signature-less secure header for OpenPOWER builds
                    run_command("$CUR_OPEN_SIGN_REQUEST "
                                . "--protectedPayload $bin_file "
                                . "--contrHdrOut $final_header_file "
                                . "--out $tempImages{HDR_PHASE}");
                }
            }
            else
            {
                run_command("cp $bin_file $tempImages{HDR_PHASE}");
            }

            setCallerHwHdrFields(\%callerHwHdrFields, $tempImages{HDR_PHASE});
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
                # Create an empty file of all 0xFF's of $file_size
                run_command("dd if=/dev/zero bs=$file_size count=1 | tr \"\\000\" \"\\377\" > $bin_dir/$eyeCatch.ipllid");
                # Write the contents of tempImages[HDR_PHASE} to the begining of the file we just made
                run_command("dd if=$tempImages{HDR_PHASE} conv=notrunc of=$bin_dir/$eyeCatch.ipllid");
            }

            # store binary file size + header size in hash

            # If section will passed through ecc, include this in size calculation
            if( ($sectionHash{$layoutKey}{ecc} eq "yes") )
            {
                $partitionUtilHash{$eyeCatch}{logicalFileSize} = $callerHwHdrFields{totalContainerSize} * (9/8);
            }
            else
            {
                $partitionUtilHash{$eyeCatch}{logicalFileSize} = $callerHwHdrFields{totalContainerSize};
            }
            $partitionUtilHash{$eyeCatch}{pctUtilized} = sprintf("%.2f", $partitionUtilHash{$eyeCatch}{logicalFileSize} / $physicalRegionSize * 100);
            $partitionUtilHash{$eyeCatch}{freeBytes} = $physicalRegionSize - $partitionUtilHash{$eyeCatch}{logicalFileSize};
            $partitionUtilHash{$eyeCatch}{physicalRegionSize} = $physicalRegionSize;

            # Padding Phase
            if ($eyeCatch eq "HBI" && $testRun)
            {
                # If "--test" flag set do not pad as the test HBI images is
                # possibly larger than partition size and does not need to be
                # fully padded. Size adjustments made in checkSpaceConstraints
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=4k conv=sync");
            }
            # HBBL was already padded
            elsif ($eyeCatch eq "HBBL")
            {
                run_command("cp $tempImages{HDR_PHASE} $tempImages{PAD_PHASE}");
            }
            else
            {
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
            }

            # If so instructed, retain pre-ECC versions of the output files
            # using the appropriate naming convention
            if ($emitEccless)
            {
                my($file,$dirs,$suffix) = fileparse($eccless_file);
                $file =~ s/(\.\w+)$/$eccless_prefix$1/;
                run_command("cp $tempImages{PAD_PHASE} $bin_dir/$file");
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
            }
        }
        # Handle partitions that have no input binary. Simply zero or random
        # fill the partition.
        elsif (!-e $bin_file)
        {

            if ($eyeCatch eq "SBKT" && $secureboot && $keyTransition{enabled})
            {
                $callerHwHdrFields{configure} = 1;
                create_sb_key_transition_container($tempImages{PAD_PHASE});
                setCallerHwHdrFields(\%callerHwHdrFields, $tempImages{PAD_PHASE});
            }
            else
            {
                # Test partitions have random data
                if ($eyeCatch eq "TEST" || $eyeCatch eq "TESTRO")
                {
                    run_command("dd if=/dev/urandom of=$tempImages{PAD_PHASE} count=1 bs=$size");
                }
                # Other partitions fill with FF's if no empty bin file provided
                else
                {
                    run_command("dd if=/dev/zero bs=$size count=1 | tr \"\\000\" \"\\377\" > $tempImages{PAD_PHASE}");
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

                    if ($secureboot && $secureSupported)
                    {
                        $callerHwHdrFields{configure} = 1;
                        run_command("$CUR_OPEN_SIGN_REQUEST "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PAD_PHASE}");
                        setCallerHwHdrFields(\%callerHwHdrFields,
                                             $tempImages{PAD_PHASE});
                    }
                    # Add non-secure version header
                    else
                    {
                        # Attach signature-less secure header for OpenPOWER builds
                        run_command("$CUR_OPEN_SIGN_REQUEST "
                                    . "--protectedPayload $tempImages{TEMP_BIN} "
                                    . "--contrHdrOut $final_header_file "
                                    . "--out $tempImages{PAD_PHASE}");
                    }

                    # Save a copy of the original binary to package later,
                    #  only need this for sections that are temporarily zeros but eventually
                    #  will have real content
                    my $staged_bin_file = ($system_target eq "")? "$bin_dir/$eyeCatch$nodeIDstr.staged":
                        "$bin_dir/$system_target.$eyeCatch$nodeIDstr.staged";
                    run_command("cp -n $tempImages{TEMP_BIN} $staged_bin_file");
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
                }
            }
            # if we are requested to emit ipl lid artifacts ensure that the generated binary
            # from above is 4KB byte aligned and write a copy to the $bin_dir
            if ($emitIplLids)
            {
                # Get the files size and round it up to the next multiple of 4096
                my $file_size = -s $tempImages{PAD_PHASE};
                if(($file_size % 4096) ne 0)
                {
                    $file_size += (4096 - ($file_size % 4096));
                }
                # Create an empty file of all 0xFF's of $file_size
                run_command("dd if=/dev/zero bs=$file_size count=1 | tr \"\\000\" \"\\377\" > $bin_dir/$eyeCatch.ipllid");
                # Write the contents of tempImages[HDR_PHASE} to the begining of the file we just made
                run_command("dd if=$tempImages{PAD_PHASE} conv=notrunc of=$bin_dir/$eyeCatch.ipllid");
            }
            if ($eyeCatch eq "SBKT" && $emitEccless)
            {
                run_command("cp $tempImages{PAD_PHASE} $bin_dir/sbkt.bin");
            }
        }

        # ECC Phase
        if( ($sectionHash{$layoutKey}{ecc} eq "yes") )
        {
            run_command("$jailcmd ecc --inject $tempImages{PAD_PHASE} --output $tempImages{ECC_PHASE} --p8");
        }
        else
        {
            run_command("cp $tempImages{PAD_PHASE} $tempImages{ECC_PHASE}");
        }

        # Compression phase
        if( ($sectionHash{$layoutKey}{compressed}{algorithm} eq "xz"))
        {
            # Placeholder for compression partitions
        }

        # Move content to final bin filename
        run_command("cp $tempImages{ECC_PHASE} $final_bin_file");

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
        HBB_SW_SIG_FILE => "$bin_dir/$parallelPrefix.hbb_sw_sig.bin"
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
    while (scalar(@todo) != scalar(keys %done))
    {
        my @pids = ();

        # Create a new process for each partition that we can operate
        # on now
        foreach my $key (@todo)
        {
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
    my ($bin_file, $eyeCatch, $saltData) = @_;

    # Open the file
    my $hashPageTableFile = "$bin_dir/$eyeCatch.page_hash_table";
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
        $salt_entry = truncate_sha(sha512($saltData));
    }
    else
    {
        # Generate random salt data
        for (my $i = 0; $i < SHA_TRUNCATE_SIZE; $i++)
        {
            $salt_entry .= sha512(rand(0x7FFFFFFFFFFFFFFF));
        }
        $salt_entry = truncate_sha(sha512($salt_entry));
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
        my $hash_entry = truncate_sha(sha512($hashes[$index-1].$data));
        push @hashes, $hash_entry;
        $index++;
        print OUTBINFILE $hash_entry;
    }

    close INBINFILE or die "Error closing $bin_file: $!\n";
    close OUTBINFILE or die "Error closing $hashPageTableFile: $!\n";

    # Pad hash page table to a multiple of page size (4K)
    my $temp_file = "$bin_dir/$eyeCatch.page_hash_table.temp";
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

    my $CUR_OPEN_SIGN_REQUEST = "$OPEN_SIGN_REQUEST $openSigningFlags";
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
    $tempImages{hashPageTable} = genHashPageTable($tempImages{TEST_CONTAINER_DATA}, "secureboot_test");
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
#       Generate sb key transition container used for transitioning from an
#       imprint to production key.
#       Format:
#           SB_HDR_IMPRINT_KEY[SB_HDR_PRD_KEY[4K rand blob]]
#       Steps:
#           1. Generate 4K blob of random data
#           2. Sign #1 with production keys
#           3. Sign #2 with the imprint keys
################################################################################
sub create_sb_key_transition_container
{
    my ($o_file) = @_;

    my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
    my %tempImages = (
        RAND_BLOB => "$bin_dir/$randPrefix.rand_blob.bin",
        PRD_KEY_FILE => "$bin_dir/$randPrefix.sbkt_prod_key.bin"
    );

    # Gen 4K blob of random data
    run_command("dd if=/dev/urandom of=$tempImages{RAND_BLOB} count=1 bs=4k");

    die "Key transition not allowed in $sign_mode mode" if ($OPEN_SIGN_KEY_TRANS_REQUEST eq "");

    # Create a signed container with new production keys
    run_command("$OPEN_SIGN_KEY_TRANS_REQUEST".OP_SIGNING_FLAG
        . "$sb_hdrs{SBKT}{inner}{flags} --protectedPayload $tempImages{RAND_BLOB} "
        . "--out $tempImages{PRD_KEY_FILE}");
    # Sign new production key container with imprint keys
    my $sbktComponentIdArg = "--sign-project-FW-token SBKT ";
    run_command("$OPEN_SIGN_REQUEST ".$sbktComponentIdArg.OP_SIGNING_FLAG
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
# setCallerHwHdrFields
#       Sets the caller hardware header fields in the passed in file based on
#       the input hash passed in.
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
    --corrupt           <Partition name>[= pro|unpro] (Note: requires '--secureboot')
                        Partition 'eyeCatch' name to corrupt a byte of.
                        Optional '= pro|unpro' to indicate which section of the secure container to corrupt.
                            Default (empty string '') is protected section.
                            [Note: Some sections only have a protected section so not relevant for all.]
                        Multiple '--corrupt' options are allowed, but note the system will checkstop on the
                            first bad partition so multiple may not be that useful.
                        Example: --corrupt HBI --corrupt HBD=unpro
    --sign-mode <development|production>   Indicates how to sign partitions with either development keys or production keys
    --key-transition <imprint|production>   Indicates a key transition is needed and creates a secureboot key transition container.
                                            Note: "--sign-mode production" is not allowed with "--key-transition imprint"
                                            With [--test] will transition to test dev keys, which are a fixed permutation of imprint keys.
    --lab-security-override       If signing SBE image, set bit in signing
                                      header which turns on security override
                                      checking in the SBE the next time it is
                                      updated and invoked.  When security
                                      override checking is enabled, SBE will
                                      check mailbox scratch register 3 bit 6 and
                                      if set, disable security.  Otherwise, it
                                      will retain the existing security
                                      settings.  NOTE: Only allowed for
                                      development/imprint signed images.
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
