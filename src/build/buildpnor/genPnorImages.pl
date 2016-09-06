#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/genPnorImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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

use constant COMMUNITY => "community";

# Hostboot base image constants for the hardware header portion of the
# secureboot header
use constant BASE_IMAGE_TOTAL_CONTAINER_SIZE => 0x000000000007EF80;
use constant BASE_IMAGE_TARGET_HRMOR => 0x0000000008000000;
use constant BASE_IMAGE_INSTRUCTION_START_STACK_POINTER => 0x0000000008280000;

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

# Truncate SHA to n bytes
use constant SHA_TRUNCATE_SIZE => 32;
# Defined in src/include/sys/vfs.h
use constant VFS_EXTENDED_MODULE_MAX => 128;
# VfsSystemModule struct size
use constant VFS_MODULE_TABLE_ENTRY_SIZE => 112;
# VFS Module table max size
use constant VFS_MODULE_TABLE_MAX_SIZE => VFS_EXTENDED_MODULE_MAX
                                          * VFS_MODULE_TABLE_ENTRY_SIZE;
# Flag parameter string passed into signing tools
# Note spaces before/after are critical.
use constant LOCAL_SIGNING_FLAG => " -flag ";
use constant OP_SIGNING_FLAG => " -flags ";
# Security bits HW flag strings
use constant HB_FW_FLAG => "0x80000000";
use constant OPAL_FLAG => "0x40000000";
use constant PHYP_FLAG => "0x20000000";

################################################################################
# I/O parsing
################################################################################

my $bin_dir = cwd();
my $secureboot = 0;
my $testRun = 0;
my $pnorLayoutFile = "";
my $system_target = "";
my $build_all = 0;
my $install_all = 0;
my $help = 0;

GetOptions("binDir:s" => \$bin_dir,
           "secureboot" => \$secureboot,
           "test" => \$testRun,
           "pnorLayout:s" => \$pnorLayoutFile,
           "systemBinFiles:s" => \@systemBinFiles,
           "build-all" => \$build_all,
           "install-all" => \$install_all,
           "help" => \$help);

if ($help)
{
    usage();
    exit 0;
}

# Hardcoded defined order that binfiles should be handled.
my %partitionDeps = ( HBB => 0,
                      HBI => 1);

# Custom sort to ensure images are handled in the correct dependency order.
# If a dependency is not specified in the hash used, use default behavior.
sub partitionDepSort
{
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
# main
################################################################################

# @TODO RTC: 155374 add official signing support including up to 3 sw keys
# Signing and Dev key directory location set via env vars
my $SIGNING_DIR = $ENV{'SIGNING_DIR'};
my $DEV_KEY_DIR = $ENV{'DEV_KEY_DIR'};

my $openSigningTool = 0;
my $SIGNING_TOOL_EDITION = $ENV{'SIGNING_TOOL_EDITION'};
if($SIGNING_TOOL_EDITION eq COMMUNITY)
{
    $openSigningTool = 1;
}

# Secureboot command strings
# Requires naming convention of hw/sw keys in DEV_KEY_DIR

my $SIGN_BUILD_PARAMS = "-skp ${DEV_KEY_DIR}/sw_key_a";
# Secureboot header file
my $randPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF));
my $HB_FW_SECUREBOOT_HDR = "$bin_dir/$randPrefix.hb.fw.secureboot.hdr.bin";
my $OPAL_SECUREBOOT_HDR = "$bin_dir/$randPrefix.opal.secureboot.hdr.bin";
my $PHYP_SECUREBOOT_HDR = "$bin_dir/$randPrefix.phyp.secureboot.hdr.bin";

my $OPEN_SIGN_REQUEST="$SIGNING_DIR/crtSignedContainer.pl -v "
    . "-hwPrivKeyA $DEV_KEY_DIR/hw_key_a.key "
    . "-hwPrivKeyB $DEV_KEY_DIR/hw_key_b.key "
    . "-hwPrivKeyC $DEV_KEY_DIR/hw_key_c.key "
    . "-swPrivKeyP $DEV_KEY_DIR/sw_key_a.key ";

if ($secureboot)
{
    # Check all components needed for developer signing
    die "Signing Dir = $SIGNING_DIR DNE" if(! -d $SIGNING_DIR);
    die "Dev Key Dir = $DEV_KEY_DIR DNE" if(! -d $DEV_KEY_DIR);
    die "hw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_a*"));
    die "hw_key_b DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_b*"));
    die "hw_key_c DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_c*"));
    die "sw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/sw_key_a*"));

    if(!$openSigningTool)
    {
        # Key prefix used for all partitions (N/A for open edition)
        my $SIGN_PREFIX_PARAMS = "-hka ${DEV_KEY_DIR}/hw_key_a -hkb "
                    . "${DEV_KEY_DIR}/hw_key_b -hkc ${DEV_KEY_DIR}/hw_key_c "
                    . "-skp ${DEV_KEY_DIR}/sw_key_a";
        run_command("$SIGNING_DIR/prefix -good -of $HB_FW_SECUREBOOT_HDR".
                    LOCAL_SIGNING_FLAG.HB_FW_FLAG." $SIGN_PREFIX_PARAMS");
        run_command("$SIGNING_DIR/prefix -good -of $OPAL_SECUREBOOT_HDR ".
                    LOCAL_SIGNING_FLAG.OPAL_FLAG." $SIGN_PREFIX_PARAMS");
        run_command("$SIGNING_DIR/prefix -good -of $PHYP_SECUREBOOT_HDR ".
                    LOCAL_SIGNING_FLAG.PHYP_FLAG." $SIGN_PREFIX_PARAMS");
        if ($build_all)
        {
            gen_test_containers();
        }
    }
}

#Load PNOR Layout XML file
loadPnorLayout($pnorLayoutFile, \%pnorLayout, \%PhysicalOffsets, $testRun);

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

    # Make sure provided files will fit in their sections
    checkSpaceConstraints(\%pnorLayout, \%binFiles, $testRun);
}

system("rm -f $HB_FW_SECUREBOOT_HDR");
die "Could not delete $HB_FW_SECUREBOOT_HDR" if $?;
system("rm -f $OPAL_SECUREBOOT_HDR");
die "Could not delete $OPAL_SECUREBOOT_HDR" if $?;
system("rm -f $PHYP_SECUREBOOT_HDR");
die "Could not delete $PHYP_SECUREBOOT_HDR" if $?;

################################################################################
# manipulateImages - Perform any ECC/padding/sha/signing manipulations
################################################################################
sub manipulateImages
{
    my ($i_pnorLayoutRef, $i_binFilesRef, $system_target) = @_;
    my $this_func = (caller(0))[3];

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    trace(1, "manipulateImages");

    # Prefix for temporary files for parallel builds
    my $parallelPrefix = "rand-".POSIX::ceil(rand(0xFFFFFFFF)).$system_target;

    # Partitions that have a hash page table at the beginning of the section
    # for secureboot purposes.
    my %hashPageTablePartitions = (HBI => 1);

    my %preReqImages = (
        HBB_SW_SIG_FILE => "$bin_dir/$parallelPrefix.hbb_sw_sig.bin"
    );

    foreach my $key (sort partitionDepSort  keys %{$i_binFilesRef})
    {
        my %callerHwHdrFields = (
            configure => 0,
            totalContainerSize => 0,
            targetHrmor => 0,
            instructionStartStackPointer => 0);

        my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayoutRef);
        my $eyeCatch = $sectionHash{$layoutKey}{eyeCatch};
        my %tempImages = (
            HDR_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.hdr.bin",
            PREFIX_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.hdr.prefix.bin",
            TEMP_SHA_IMG => "$bin_dir/$parallelPrefix.$eyeCatch.temp.sha.bin",
            PAD_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.pad.bin",
            ECC_PHASE => "$bin_dir/$parallelPrefix.$eyeCatch.temp.bin.ecc",
            VFS_MODULE_TABLE => => "$bin_dir/$parallelPrefix.$eyeCatch.vfs_module_table.bin",
            TEMP_BIN => "$bin_dir/$parallelPrefix.$eyeCatch.temp.bin",
            PAYLOAD_TEXT => "$bin_dir/$parallelPrefix.$eyeCatch.payload_text.bin",
            PROTECTED_PAYLOAD => "$bin_dir/$parallelPrefix.$eyeCatch.protected_payload.bin"
        );

        my $size = $sectionHash{$layoutKey}{physicalRegionSize};
        my $bin_file = $$i_binFilesRef{$eyeCatch};
        # Check if bin file is system specific and prefix target to the front
        my $final_bin_file = ($system_target eq "")? "$bin_dir/$eyeCatch.bin":
                                        "$bin_dir/$system_target.$eyeCatch.bin";

        # Get size of parition without ecc
        if ($sectionHash{$layoutKey}{ecc} eq "yes")
        {
            $size = page_aligned_size_wo_ecc($size);
        }

        # Sections that have secureboot support. Secureboot still must be
        # enabled for secureboot actions on these partitions to occur.
        my $isNormalSecure =    ($eyeCatch eq "SBE")
                             || ($eyeCatch eq "SBEC")
                             || ($eyeCatch eq "PAYLOAD");

        my $isSpecialSecure =    ($eyeCatch eq "HBB")
                              || ($eyeCatch eq "HBI")
                              || ($eyeCatch eq "HBD");

        my $openSigningFlags = OP_SIGNING_FLAG.HB_FW_FLAG;
        my $secureboot_hdr =  $HB_FW_SECUREBOOT_HDR;
        if ($eyeCatch eq "PAYLOAD")
        {
            $secureboot_hdr = $OPAL_SECUREBOOT_HDR;
            $openSigningFlags = OP_SIGNING_FLAG.OPAL_FLAG;
        }

        # Handle partitions that have an input binary.
        if (-e $bin_file)
        {
            # FSP workaround to keep original bin names
            my $fsp_file = $bin_file;
            my $fsp_prefix = "";

            # Header Phase
            if(   ($sectionHash{$layoutKey}{sha512Version} eq "yes")
               || ($secureboot && $isSpecialSecure) )
            {
                $fsp_prefix.=".header";
                # Add secure container header
                # @TODO RTC:155374 Remove when official signing supported
                if ($secureboot)
                {
                    $callerHwHdrFields{configure} = 1;
                    if (exists $hashPageTablePartitions{$eyeCatch})
                    {
                        if ($eyeCatch eq "HBI")
                        {
                            # Pass HBB sw signatures as the salt entry.
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch,
                                                                    getBinDataFromFile($preReqImages{HBB_SW_SIG_FILE}));
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
                        if ($eyeCatch eq "HBI")
                        {
                            # Add the VFS module table to the payload text section.
                            run_command("dd if=$bin_file of=$tempImages{VFS_MODULE_TABLE} count=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            # Remove VFS module table from bin file
                            run_command("dd if=$bin_file of=$tempImages{TEMP_BIN} skip=".VFS_EXTENDED_MODULE_MAX." ibs=".VFS_MODULE_TABLE_ENTRY_SIZE);
                            run_command("cp $tempImages{TEMP_BIN} $bin_file");
                            # Pad after hash page table to have the VFS module table end at a 4K boundary
                            my $hashPageTableSize = -s $tempImages{hashPageTable};
                            my $padSize = PAGE_SIZE - (($hashPageTableSize + VFS_MODULE_TABLE_MAX_SIZE) % PAGE_SIZE);
                            run_command("dd if=/dev/zero bs=$padSize count=1 | tr \"\\000\" \"\\377\" >> $tempImages{hashPageTable} ");

                            # Payload text section
                            run_command("cat $tempImages{hashPageTable} $tempImages{VFS_MODULE_TABLE} > $tempImages{PAYLOAD_TEXT} ");
                        }
                        else
                        {
                            run_command("cp $tempImages{hashPageTable} $tempImages{PAYLOAD_TEXT}");
                        }

                        if($openSigningTool)
                        {
                            run_command("$OPEN_SIGN_REQUEST "
                                . "$openSigningFlags "
                                . "-protectedPayload $tempImages{PAYLOAD_TEXT} "
                                . "-out $tempImages{PROTECTED_PAYLOAD}");
                        }
                        else
                        {
                            # @TODO RTC:155374 Remove when official signing
                            # supported
                            run_command("$SIGNING_DIR/build -good -if $secureboot_hdr -of $tempImages{PROTECTED_PAYLOAD} -bin $tempImages{PAYLOAD_TEXT} $SIGN_BUILD_PARAMS");
                        }

                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file > $tempImages{HDR_PHASE}");
                    }
                    # Handle read-only protected payload
                    elsif ($eyeCatch eq "HBD")
                    {
                        if($openSigningTool)
                        {
                            run_command("$OPEN_SIGN_REQUEST "
                                . "$openSigningFlags  "
                                . "-protectedPayload $bin_file.protected "
                                . "-out $tempImages{PROTECTED_PAYLOAD}");
                        }
                        else
                        {
                            # @TODO RTC:155374 Remove when official signing
                            # supported
                            run_command("$SIGNING_DIR/build -good -if $secureboot_hdr -of $tempImages{PROTECTED_PAYLOAD} -bin $bin_file.protected $SIGN_BUILD_PARAMS");
                        }

                        run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file.unprotected > $tempImages{HDR_PHASE}");
                    }
                    else
                    {
                        if($openSigningTool)
                        {
                            my $codeStartOffset = ($eyeCatch eq "HBB") ?
                                "-code-start-offset 0x00000180" : "";
                            run_command("$OPEN_SIGN_REQUEST "
                                . "$openSigningFlags $codeStartOffset "
                                . "-protectedPayload $bin_file "
                                . "-out $tempImages{HDR_PHASE}");
                        }
                        else
                        {
                            # @TODO RTC:155374 Remove when official signing
                            # supported
                            run_command("$SIGNING_DIR/build -good -if $secureboot_hdr -of $tempImages{HDR_PHASE} -bin $bin_file $SIGN_BUILD_PARAMS");
                        }
                    }

                    # Customize secureboot prefix header with container size,
                    # target HRMOR, and stack address (8 bytes each), in that
                    # order. Customization begins at offset 6 into the container
                    # header.
                    if($eyeCatch eq "HBB")
                    {
                        $callerHwHdrFields{totalContainerSize}
                            = BASE_IMAGE_TOTAL_CONTAINER_SIZE;
                        $callerHwHdrFields{targetHrmor}
                            = BASE_IMAGE_TARGET_HRMOR;
                        $callerHwHdrFields{instructionStartStackPointer}
                            = BASE_IMAGE_INSTRUCTION_START_STACK_POINTER;
                        # Save off HBB sw signatures for use by HBI
                        open (HBB_SW_SIG_FILE, ">",
                        $preReqImages{HBB_SW_SIG_FILE}) or die "Error opening file $preReqImages{HBB_SW_SIG_FILE}: $!\n";
                        binmode HBB_SW_SIG_FILE;
                        print HBB_SW_SIG_FILE getSwSignatures($tempImages{HDR_PHASE});
                        die "Error reading of $preReqImages{HBB_SW_SIG_FILE} failed" if $!;
                        close HBB_SW_SIG_FILE;
                        die "Error closing of $preReqImages{HBB_SW_SIG_FILE} failed" if $!;
                    }
                }
                # Add simiple version header
                else
                {
                    run_command("env echo -en VERSION\\\\0 > $tempImages{TEMP_SHA_IMG}");
                    run_command("sha512sum $bin_file | awk \'{print \$1}\' | xxd -pr -r >> $tempImages{TEMP_SHA_IMG}");
                    run_command("dd if=$tempImages{TEMP_SHA_IMG} of=$tempImages{HDR_PHASE} ibs=4k conv=sync");
                    run_command("cat $bin_file >> $tempImages{HDR_PHASE}");
                }
            }
            elsif($secureboot
                  &&  (   ($sectionHash{$layoutKey}{sha512perEC} eq "yes")
                       || ($isNormalSecure)))
            {
                $callerHwHdrFields{configure} = 1;
                if($openSigningTool)
                {
                    run_command("$OPEN_SIGN_REQUEST "
                        . "$openSigningFlags "
                        . "-protectedPayload $bin_file "
                        . "-out $tempImages{HDR_PHASE}");
                }
                else
                {
                    # @TODO RTC:155374 Remove when official signing supported
                    run_command("$SIGNING_DIR/build -good -if $secureboot_hdr -of $tempImages{HDR_PHASE} -bin $bin_file $SIGN_BUILD_PARAMS");
                }
            }
            else
            {
                run_command("cp $bin_file $tempImages{HDR_PHASE}");
            }

            if($callerHwHdrFields{configure})
            {
                # If not already explicitly set, compute total container size
                if(!$callerHwHdrFields{totalContainerSize})
                {
                    $callerHwHdrFields{totalContainerSize}
                        = -s $tempImages{HDR_PHASE};
                    die  "Could not determine size of file "
                        ."$tempImages{HDR_PHASE}; errno = $!" unless
                            defined($callerHwHdrFields{totalContainerSize});
                }
                my $callerHwHdr = sprintf("%016llX%016llX%016llX",
                    $callerHwHdrFields{totalContainerSize},
                    $callerHwHdrFields{targetHrmor},
                    $callerHwHdrFields{instructionStartStackPointer});
                run_command( "echo \"$callerHwHdr\" | xxd -r -ps -seek 6 - "
                            ."$tempImages{HDR_PHASE}");
            }

            # Prefix phase
            # Add SBE header to HBB
            if($eyeCatch eq "HBB")
            {
                run_command("echo \"00000000001800000000000008000000000000000007EF80\" | xxd -r -ps - $tempImages{PREFIX_PHASE}");
                run_command("cat $tempImages{HDR_PHASE} >> $tempImages{PREFIX_PHASE}");
            }
            # Otherwise propagate image to next phase
            else
            {
                run_command("mv $tempImages{HDR_PHASE} $tempImages{PREFIX_PHASE}");
            }

            # Padding Phase
            if ($eyeCatch eq "HBI" && $testRun)
            {
                # If "--test" flag set do not pad as the test HBI images is
                # possibly larger than parition size and does not need to be
                # fully padded. Size adjustments made in checkSpaceConstraints
                run_command("dd if=$tempImages{PREFIX_PHASE} of=$tempImages{PAD_PHASE} ibs=4k conv=sync");
            }
            else
            {
                run_command("dd if=$tempImages{PREFIX_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
            }

            # Create .header.bin file for FSP
            if ($build_all)
            {
                $fsp_file =~ s/\.bin/$fsp_prefix.bin/;
                run_command("cp $tempImages{PAD_PHASE} $fsp_file");
            }

            # Leave hacks in here for future testing purposes
            # Hack HBI page to fail verification, Ensure location is past hash page table
            #if ($eyeCatch eq "HBI")
            #{
                # Corrupt a single byte of the HBI partition at a address after
                # the hash page table. Use dd with seek to maniuplate a bin file
                # in-place at a specific location.
                # run_command("printf \'\\xa1\' | dd conv=notrunc of=$tempImages{PAD_PHASE} bs=1 seek=\$((0x00013000))");
            #}

            # Hack HBD page to fail verification
            #if ($eyeCatch eq "HBD")
            #{
                # Corrupt a single byte of HBD's RO section
                # Use dd with seek to maniuplate a bin file in-place at a specific location.
                #run_command("printf \'\\xa1\' | dd conv=notrunc of=$tempImages{PAD_PHASE} bs=1 seek=\$((0x00004000))");

                # Corrupt a single byte of HBD's RW section
                # Use dd with seek to maniuplate a bin file in-place at a specific location.
                # Enusre seek address is after RO section on.
                # run_command("printf \'\\xa1\' | dd conv=notrunc of=$tempImages{PAD_PHASE} bs=1 seek=\$((0x00044000))");
            #}
        }
        # Handle partitions that have no input binary. Simply zero or random
        # fill the partition.
        elsif (!-e $bin_file)
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
            if ($secureboot && $isNormalSecure)
            {
                # Remove PAGE_SIZE bytes from generated dummy content of file
                # to make room for the secure header
                my $fileSize = (-s $tempImages{PAD_PHASE}) - PAGE_SIZE;
                run_command("dd if=$tempImages{PAD_PHASE} of=$tempImages{TEMP_BIN} count=1 bs=$fileSize");
                # @TODO RTC:155374 Remove when official signing supported
                run_command("$SIGNING_DIR/build -good -if $secureboot_hdr -of $tempImages{PAD_PHASE} -bin $tempImages{TEMP_BIN} $SIGN_BUILD_PARAMS");
            }
        }

        # ECC Phase
        if( ($sectionHash{$layoutKey}{ecc} eq "yes") )
        {
            run_command("ecc --inject $tempImages{PAD_PHASE} --output $tempImages{ECC_PHASE} --p8");
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
    my %tempImages = (
        TEST_CONTAINER_DATA => "$bin_dir/test.cont.bin",
        PROTECTED_PAYLOAD => "$bin_dir/test.protected_payload.bin"
    );

    # Create a signed test container
    # name = secureboot_signed_container (no prefix in hb cacheadd)
    my $test_container = "$bin_dir/secureboot_signed_container";
    run_command("dd if=/dev/zero count=1 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    run_command("$SIGNING_DIR/build -good -if $HB_FW_SECUREBOOT_HDR -of $test_container -bin $tempImages{TEST_CONTAINER_DATA} $SIGN_BUILD_PARAMS");

    # Create a signed test container with a hash page table
    # name = secureboot_hash_page_table_container (no prefix in hb cacheadd)
    $test_container = "$bin_dir/secureboot_hash_page_table_container";
    run_command("dd if=/dev/urandom count=5 ibs=4096 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    $tempImages{hashPageTable} = genHashPageTable($tempImages{TEST_CONTAINER_DATA}, "secureboot_test");
    run_command("$SIGNING_DIR/build -good -if $HB_FW_SECUREBOOT_HDR -of $tempImages{PROTECTED_PAYLOAD} -bin $tempImages{hashPageTable} $SIGN_BUILD_PARAMS");
    run_command("cat $tempImages{PROTECTED_PAYLOAD} $tempImages{TEST_CONTAINER_DATA} > $test_container ");

    # Clean up temp images
    foreach my $image (keys %tempImages)
    {
        system("rm -f $tempImages{$image}");
        die "Failed deleting $tempImages{$image}" if ($?);
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
             --build-all --test --binDir <path> --secureboot

  Parms:
    -h|--help           Print this help text
    --pnorlayout <file> PNOR Layout XML file
    --build-all         Indicates script should operate as if in ODE build_all
                        This is used to handle things that should happen once in
                        build_all phase and avoid parallel call issues.
    --systemBinFiles [SYSTEM:]<NAME=FILE,NAME=FILE> CSV of bin files to format. Multiple '--systemBinFiles' allowed
                                    Optional prefix 'SYSTEM:' used to specify with system bin files are being built.
                                    For sections <NAME> that simply require zero-filling, you can pass in EMPTY or
                                        any non-existing file. If a file DNE, the script will handle accordingly.
                                    Example: HBI=hostboot_extended.bin,GUARD=EMPTY
                                             MURANO:HBD=simics_MURANO_targeting.bin
    --test                  Output test-only sections.
    --secureboot            Indicates a secureboot build.

  Current Limitations:
    - Issues with dependency on ENGD build for certain files such as SBE. This
      is why [--build-all | --install-all ] are used.
ENDUSAGE
}
