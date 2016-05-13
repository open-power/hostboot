#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildpnor.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
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
#Builds a PNOR image based on pnorLayout XML file.
#See usage function at bottom of file for details on how to use this script

#Limitations to address later
# number fields must be 4 or 8 bytes
# numbers cannot be over 32 bits


use strict;
use XML::Simple;
use Data::Dumper;
use File::Basename;

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

################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_trace = 1;

my $programName = File::Basename::basename $0;
my %pnorLayout;
my %PhysicalOffsets;
my %binFiles;
my %finalBinFiles=();
my $pnorLayoutFile;
my $pnorBinName = "";
my $tocVersion = 0x1;
my $g_TOCEyeCatch = "part";
my $testRun = 0;
# @TODO RTC:155374 remove refactor supported
my $refactor_supported = 0;
my $g_fpartCmd = "";
my $g_fcpCmd = "";
my %sidelessSecFilled = ();
my %SideOptions = (
        A => "A",
        B => "B",
        sideless => "sideless",
    );
my $bin_dir;
my $secureboot;
use constant PAGE_SIZE => 4096;
# Truncate SHA to n bytes
use constant SHA_TRUNCATE_SIZE => 32;
# Defined in src/include/sys/vfs.h
use constant VFS_EXTENDED_MODULE_MAX => 128;
# VfsSystemModule struct size
use constant VFS_MODULE_TABLE_ENTRY_SIZE => 112;

if ($#ARGV < 0) {
    usage();
    exit;
}

#Parse the commandline args
for (my $i=0; $i < $#ARGV + 1; $i++)
{
    if ($ARGV[$i] =~ /-h/) {
        usage();
        exit 0;
    }
    elsif($ARGV[$i] =~ /--tocVersion/) {
        $tocVersion = getNumber($ARGV[++$i]);
        trace(2, "TOC Version to use=".sprintf("0x%x", $tocVersion));
    }
    elsif($ARGV[$i] =~ /--pnorLayout/) {
        $pnorLayoutFile = $ARGV[++$i];
        trace(2, "PNOR Layout XML File=$pnorLayoutFile");
    }
    elsif($ARGV[$i] =~ /--pnorOutBin/) {
        $pnorBinName = $ARGV[++$i];
        trace(2, "PNOR Binary File=$pnorBinName");
    }
    elsif($ARGV[$i] =~ /--binFile/) {
        my $argName = $ARGV[$i];
        my $argVal = $ARGV[++$i];
        saveInputFile("--binFile", $argName, $argVal, \%binFiles);
    }
    elsif($ARGV[$i] =~ /--fpartCmd/) {
        $g_fpartCmd = $ARGV[++$i];
    }
    elsif($ARGV[$i] =~ /--fcpCmd/) {
        $g_fcpCmd = $ARGV[++$i];
    }
    elsif($ARGV[$i] =~ /--test/) {
        $testRun = 1;
    }
    elsif($ARGV[$i] =~ /--binDir/) {
        $bin_dir = $ARGV[++$i];
    }
    # @TODO RTC:155374 remove refactor supported
    elsif($ARGV[$i] =~ /--refactor-supported/) {
        $refactor_supported = 1;
    }
    elsif($ARGV[$i] =~ /--secureboot/) {
        $secureboot = 1;
        print "Building Secure PNOR image\n";
    }
    else {
        traceErr("Unrecognized Input: $ARGV[$i]");
        exit 1;
	#Error!!
    }
}

############################## Begin Actions ##################################

#Delete File (pnorBinName) if exists to prevent errors when making layout
#changes
if (-e $pnorBinName)
{
    unlink $pnorBinName or warn "Could not unlink $pnorBinName: $!";
}

my $image_target = basename($pnorBinName);
$image_target =~ s/.pnor//;

# @TODO RTC: 155374 add official signing support including up to 3 sw keys
# Signing and Dev key directory location set via env vars
my $SIGNING_DIR = $ENV{'SIGNING_DIR'};
my $DEV_KEY_DIR = $ENV{'DEV_KEY_DIR'};
# Secureboot command strings
# Requires naming convention of hw/sw keys in DEV_KEY_DIR
my $SIGN_PREFIX_PARAMS = "-flag 0x80000000 -hka ${DEV_KEY_DIR}/hw_key_a -hkb ${DEV_KEY_DIR}/hw_key_b -hkc ${DEV_KEY_DIR}/hw_key_c -skp ${DEV_KEY_DIR}/sw_key_a";
my $SIGN_BUILD_PARAMS = "-skp ${DEV_KEY_DIR}/sw_key_a";
# Secureboot header file
my $SECUREBOOT_HDR = "$bin_dir/$image_target.secureboot.hdr.bin";

if ($secureboot)
{
    # Check all components needed for developer signing
    die "Signing Dir = $SIGNING_DIR DNE" if(! -d $SIGNING_DIR);
    die "Dev Key Dir = $DEV_KEY_DIR DNE" if(! -d $DEV_KEY_DIR);
    die "hw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_a*"));
    die "hw_key_b DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_b*"));
    die "hw_key_c DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/hw_key_c*"));
    die "sw_key_a DNE in $DEV_KEY_DIR" if(!glob("$DEV_KEY_DIR/sw_key_a*"));

    # Key prefix used for all partitions
    run_command("$SIGNING_DIR/prefix -good -of $SECUREBOOT_HDR $SIGN_PREFIX_PARAMS");
    gen_test_containers();
}

#Load PNOR Layout XML file
loadPnorLayout($pnorLayoutFile, \%pnorLayout, \%PhysicalOffsets);

#Verify all the section files exist
verifyFilesExist(\%pnorLayout, \%binFiles);

#Perform any data integrity manipulation (ECC, shaw-hash, etc)
# @TODO RTC:155374 remove this check
if ($refactor_supported)
{
    manipulateImages(\%pnorLayout, \%binFiles, \%finalBinFiles);
    checkSpaceConstraints(\%pnorLayout, \%finalBinFiles);
}
else
{
    checkSpaceConstraints(\%pnorLayout, \%binFiles);
}
trace(1, "Done checkSpaceConstraints");

# Create all Partition Tables at each TOC offset
# Each side has 2 TOC's created at different offsets for backup purposes.
# Loop all side sections
foreach my $sideId ( keys %{$pnorLayout{metadata}{sides}} )
{
    # Loop all tocs (primary and backup)
    foreach my $toc ( keys %{$pnorLayout{metadata}{sides}{$sideId}{toc}})
    {
        my $tocOffset = $pnorLayout{metadata}{sides}{$sideId}{toc}{$toc};
        createPnorPartition($tocVersion, $pnorBinName, \%pnorLayout,
                                  $sideId, $tocOffset);

        #Add the golden side tag to the "part" partition of PNOR`
        my $userflags1 = ($pnorLayout{metadata}{sides}{$sideId}{golden} eq "yes") ?
                            0x01 : 0x00;

        #add a golden bit to the misc flags in userflag1
        $userflags1 = $userflags1 << 16;
        trace(2, "$g_fpartCmd --target $pnorBinName --partition-offset $tocOffset --user 1 --name part --value $userflags1 --force");
        system("$g_fpartCmd --target $pnorBinName --partition-offset $tocOffset --user 1 --name part --value $userflags1 --force");
        die "ERROR: Call to add golden flag to PART failed. Aborting!" if($?);
    }
}

#add backup TOC and other side's toc information to each TOC
addTOCInfo(\%pnorLayout, $pnorBinName);

# Fill all sides
foreach my $sideId ( keys %{$pnorLayout{metadata}{sides}} )
{
    my $tocOffset = $pnorLayout{metadata}{sides}{$sideId}{toc}{primary};

    # @TODO RTC:155374 remove this check
    if ($refactor_supported)
    {
        fillPnorImage($pnorBinName, \%pnorLayout, \%finalBinFiles, $sideId,
                            $tocOffset);
    }
    else
    {
        fillPnorImage($pnorBinName, \%pnorLayout, \%binFiles, $sideId,
                            $tocOffset);
    }
}

system("rm -f $SECUREBOOT_HDR");
die "Could not delete $SECUREBOOT_HDR" if $?;

exit 0;

#########################  Begin Utility Subroutines ###########################

################################################################################
# loadPnorLayout
################################################################################
sub loadPnorLayout
{
    my ($i_pnorFile, $i_pnorLayoutRef, $i_physicalOffsets) = @_;
    my $this_func = (caller(0))[3];

    unless(-e $i_pnorFile)
    {
        traceErr("$this_func: File not found: $i_pnorFile");
        return -1;
    }

    #parse the input XML file
    my $xs = new XML::Simple(keyattr=>[], forcearray => 1);
    my $xml = $xs->XMLin($i_pnorFile);

    #Iterate over the <section> elements.
    foreach my $sectionEl (@{$xml->{section}})
    {
        my $description = $sectionEl->{description}[0];
        my $eyeCatch = $sectionEl->{eyeCatch}[0];
        my $physicalOffset = $sectionEl->{physicalOffset}[0];
        my $physicalRegionSize = $sectionEl->{physicalRegionSize}[0];
        my $side = $sectionEl->{side}[0];
        my $testonly = $sectionEl->{testonly}[0];
        my $ecc = (exists $sectionEl->{ecc} ? "yes" : "no");
        my $sha512Version = (exists $sectionEl->{sha512Version} ? "yes" : "no");
        my $sha512perEC = (exists $sectionEl->{sha512perEC} ? "yes" : "no");
        my $preserved = (exists $sectionEl->{preserved} ? "yes" : "no");
        my $reprovision = (exists $sectionEl->{reprovision} ? "yes" : "no");
        my $readOnly = (exists $sectionEl->{readOnly} ? "yes" : "no");
        if (($testRun == 0) && ($sectionEl->{testonly}[0] eq "yes"))
        {
            next;
        }

        trace(3, "$this_func: description = $description, eyeCatch=$eyeCatch, physicalOffset = $physicalOffset, physicalRegionSize=$physicalRegionSize, side=$side");

        $physicalOffset = getNumber($physicalOffset);
        $physicalRegionSize = getNumber($physicalRegionSize);

        $$i_pnorLayoutRef{sections}{$physicalOffset}{description} = $description;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{eyeCatch} = $eyeCatch;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalOffset} = $physicalOffset;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalRegionSize} = $physicalRegionSize;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{side} = $side;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{ecc} = $ecc;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{sha512Version} = $sha512Version;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{sha512perEC} = $sha512perEC;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{preserved} = $preserved;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{reprovision} = $reprovision;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{readOnly} = $readOnly;

        #store the physical offsets of each section in a hash, so, it is easy
        #to search physicalOffsets based on the name of the section (eyecatch)
        if ($side eq "sideless")
        {
            foreach my $metadata (@{$xml->{metadata}})
            {
                foreach my $sides (@{$metadata->{side}})
                {
                    $$i_physicalOffsets{side}{$sides->{id}[0]}{eyecatch}{$eyeCatch} = $physicalOffset;
                }
            }
        }
        else
        {
            $$i_physicalOffsets{side}{$side}{eyecatch}{$eyeCatch} = $physicalOffset;
        }
    }
    # Save the metadata - imageSize, blockSize, toc Information etc.
    foreach my $metadataEl (@{$xml->{metadata}})
    {
        # Get meta data
        my $imageSize   = $metadataEl->{imageSize}[0];
        my $blockSize   = $metadataEl->{blockSize}[0];
        my $tocSize     = $metadataEl->{tocSize}[0];
        my $arrangement = $metadataEl->{arrangement}[0];
        $imageSize      = getNumber($imageSize);
        $blockSize      = getNumber($blockSize);
        $tocSize        = getNumber($tocSize);
        $$i_pnorLayoutRef{metadata}{imageSize}   = $imageSize;
        $$i_pnorLayoutRef{metadata}{blockSize}   = $blockSize;
        $$i_pnorLayoutRef{metadata}{tocSize}     = $tocSize;
        $$i_pnorLayoutRef{metadata}{arrangement} = $arrangement;

        my $numOfSides  = scalar (@{$metadataEl->{side}});
        my $sideSize = ($imageSize)/($numOfSides);

        trace(1, " $this_func: metadata: imageSize = $imageSize, blockSize=$blockSize, arrangement = $arrangement, numOfSides: $numOfSides, sideSize: $sideSize, tocSize: $tocSize");

        #determine the TOC offsets from the arrangement and side Information
        #stored in the layout xml
        #
        #Arrangement A-B-D means that the layout had Primary TOC (A), then backup TOC (B), then Data (pnor section information).
        #Similaryly, arrangement A-D-B means that primary toc is followed by the data (section information) and then
        #the backup TOC.
        if ($arrangement eq "A-B-D")
        {
            my $count = 0;
            foreach my $side (@{$metadataEl->{side}})
            {
                my $golden     = (exists $side->{golden} ? "yes" : "no");
                my $sideId     = $side->{id}[0];
                my $primaryTOC = ($sideSize)*($count);
                my $backupTOC  = ($primaryTOC)+($tocSize);

                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{primary} = $primaryTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{backup}  = $backupTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{golden}       = $golden;

                $count = $count + 1;
                trace(1, "A-B-D: side:$sideId primaryTOC:$primaryTOC, backupTOC:$backupTOC, golden: $golden");
            }
        }
        elsif ($arrangement eq "A-D-B")
        {
            foreach my $side (@{$metadataEl->{side}})
            {
                my $golden     = (exists $side->{golden} ? "yes" : "no");
                my $sideId     = $side->{id}[0];
                my $hbbAddr    = $$i_physicalOffsets{side}{$sideId}{eyecatch}{"HBB"};
                my $primaryTOC = align_down($hbbAddr, $sideSize);
                my $backupTOC  = align_up($hbbAddr, $sideSize) - $tocSize;

                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{primary} = $primaryTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{backup}  = $backupTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{golden}       = $golden;
                trace(1, "A-D-B: side:$sideId HBB:$hbbAddr, primaryTOC:$primaryTOC, backupTOC:$backupTOC, golden: $golden");
            }
        }
        else
        {
            trace(0, "Arrangement:$arrangement is not supported");
            exit(1);
        }
    }
    return 0;
}

################################################################################
# createPnorImg - Create PNOR image based on input data.
################################################################################
sub createPnorImg
{
    my ($i_tocVersion, $i_pnorBinName, $i_pnorLayoutRef, $i_offset) = @_;
    my $this_func = (caller(0))[3];
    trace(4, "$this_func: >>Enter");

    trace(1, "createPnorImg:: $i_offset");

    #get Block size
    my $blockSize = $$i_pnorLayoutRef{metadata}{blockSize};

    #Get size of image in blocks
    my $imageSize = $$i_pnorLayoutRef{metadata}{imageSize};
    my $blockCount = $imageSize/$blockSize;
    if ($blockCount != int($blockCount))
    {
        die "ERROR: $this_func: Image size ($imageSize) is not an even multiple of erase blocks ($blockSize).  This is not supported.  Aborting!";

    }
    #f{fs,part} --create tuleta.pnor --partition-offset 0 --size 8MiB --block 4KiB --force
    trace(2, "$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --create --size $imageSize --block $blockSize --force");
    system("$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --create --size $imageSize --block $blockSize --force");
    die "ERROR: $this_func: Call to creating image failed. Aborting!" if($?);
}

################################################################################
# addUserData - Add partition user data.
################################################################################
sub addUserData
{
    my $i_pnorBinName = shift;
    my $i_offset = shift;
    my $i_key = shift;
    my %i_sectionHash = @_;

    my $this_func = (caller(0))[3];
    trace(4, "$this_func: >>Enter");

    my $eyeCatch = $i_sectionHash{$i_key}{eyeCatch};

    # User data Flags based on FFS entry user data (ffs_hb_user_t)
    my $chip = 0;
    my $compressType = 0;
    my $dataInteg = 0;
    my $verCheck = 0;
    my $miscFlags = 0;

    # DataInteg flag
    if( ($i_sectionHash{$i_key}{ecc} eq "yes") )
    {
        $dataInteg = 0x8000;
    }

    # VerCheck Flag
    if( ($i_sectionHash{$i_key}{sha512Version} eq "yes") )
    {
        $verCheck = 0x80;
    }
    elsif( ($i_sectionHash{$i_key}{sha512perEC} eq "yes") )
    {
        $verCheck = 0x40;
    }

    # Misc Flags
    if( ($i_sectionHash{$i_key}{preserved} eq "yes") )
    {
        $miscFlags |= 0x80;
    }
    if( ($i_sectionHash{$i_key}{readOnly} eq "yes") )
    {
        $miscFlags |= 0x40;
    }
    if( ($i_sectionHash{$i_key}{reprovision} eq "yes") )
    {
        $miscFlags |= 0x10;
    }

    #First User Data Word
    #[1:chip][1:compressType][2:dataInteg]
    my $userflags0 = ($chip << 24)
      | ($compressType << 16)
      | $dataInteg;

    #Second User Data Word
    #[1:sha512Version/sha512perEC][1:miscFlags]
    my $userflags1 = ($verCheck << 24)
        | ($miscFlags << 16);


    trace(2, "$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --user 0 --name $eyeCatch --value userflags0=$userflags0");
    system("$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --user 0 --name $eyeCatch --value $userflags0");
    die "ERROR: $this_func: Call to add userdata to $eyeCatch failed. Aborting!" if($?);

    trace(2, "$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --user 1 --name $eyeCatch --value userflags1=$userflags1");
    system("$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --user 1 --name $eyeCatch --value $userflags1");
    die "ERROR: $this_func: Call to add userdata to $eyeCatch failed. Aborting!" if($?);

}

################################################################################
# createPnorPartition - Create PNOR partitions based on input data.
################################################################################
sub createPnorPartition
{
    my ($i_tocVersion, $i_pnorBinName, $i_pnorLayoutRef, $side, $offset) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $other_side = getOtherSide($side);

    trace(4, "$this_func: >>Enter");

    trace(1, "createPnorPartition:: $offset");

    # Create pnor image at partition offset
    createPnorImg($i_tocVersion, $i_pnorBinName, $i_pnorLayoutRef, $offset);

    #get Block size
    my $blockSize = $$i_pnorLayoutRef{metadata}{blockSize};

    # key into hash data is the physical offset of section.  Need to sort the
    # keys so we put things in the correct order in toc. Generally speaking,
    # this loop is populating the FFS Header with records based on the section
    # data specified in the XML + actual sizes of the input binary files.
    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    for $key ( sort {$a<=> $b} keys %sectionHash)
    {
        my $eyeCatch = "UNDEF";
        my $physicalOffset = 0xFFFFFFFF;
        my $physicalRegionSize = 0xFFFFFFFF;

        # eyecatcher
        my $eyeCatch = $sectionHash{$key}{eyeCatch};

        my $sideInfo = getSideInfo($key, %sectionHash);

        #don't try to add the TOC, but need to update all other paritions
        #Add if side matches (or not set) -- so if it isn't equal to other side
        #Also add if sideless
        if( ($eyeCatch ne $g_TOCEyeCatch ) &&
            ($sideInfo ne $other_side ))
        {
            # base/physical offset
            my $physicalOffset = $sectionHash{$key}{physicalOffset};
            #make sure offset is on a block boundary
            my $val = $physicalOffset/$blockSize;
            if ($val != int($val))
            {
                die "ERROR: this_func: Partition offset ($val) does not fall on an erase block ($blockSize) boundary.  This is not supported.  Aborting!";
            }

            #physical size
            my $physicalRegionSize = $sectionHash{$key}{physicalRegionSize};
            $val = $physicalRegionSize/$blockSize;
            if($val != int($val))
            {
                die "ERROR: $this_func: Partition size ($val) is not an even multiple of erase blocks ($blockSize).  This is not supported.  Aborting!";
            }

            #Add Partition
            #f{fs,part} --add --target tuleta.pnor --partition-offset 0 --offset 0x1000   --size 0x280000 --name HBI --flags 0x0
            trace(2, "$this_func: $g_fpartCmd --target $i_pnorBinName --partition-offset $offset --add --offset $physicalOffset --size $physicalRegionSize --name $eyeCatch --flags 0x0");
            system("$g_fpartCmd --target $i_pnorBinName --partition-offset $offset --add --offset $physicalOffset --size $physicalRegionSize --name $eyeCatch --flags 0x0");
            die "ERROR: $this_func: Call to add partition $eyeCatch failed. Aborting!" if($?);

            # Add User Partition data
            addUserData($i_pnorBinName, $offset, $key, %sectionHash);

            #Trunc Partition
            #f{fs,part} --target tuleta.pnor --partition-offset 0 --name HBI --trunc
            system("$g_fpartCmd --target $i_pnorBinName --partition-offset $offset --trunc --name $eyeCatch");
            die "ERROR: $this_func: Call to trunc partition $eyeCatch failed. Aborting!" if ($?);
        }
    }
}

################################################################################
# addTOCInfo -- adds BACKUP_PART and OTHER_SIDE information to all the TOCs
################################################################################
sub addTOCInfo
{
    my ($i_pnorLayout, $i_pnorBinName) = @_;
    my $other_idx = 0;
    my $sideShift = 0;
    my @all_tocs;
    foreach my $sideId (sort keys %{$$i_pnorLayout{metadata}{sides}})
    {
        push @all_tocs, $$i_pnorLayout{metadata}{sides}{$sideId}{toc}{primary};
        push @all_tocs, $$i_pnorLayout{metadata}{sides}{$sideId}{toc}{backup};
    }
    # sort sides so we write A,B not B,A
    foreach my $sideId (sort keys %{$$i_pnorLayout{metadata}{sides}} )
    {
        my $physicalRegionSize = $$i_pnorLayout{metadata}{tocSize};
        my $backup_part = "BACKUP_PART";
        my $other_side  = "OTHER_SIDE";
        my $backup_idx  = 0;
        my $otherSide   = getOtherSide($sideId);
        my $numOfTOCs   =  scalar keys %{$$i_pnorLayout{metadata}{sides}{$sideId}{toc}};

        #Adding an extra entry in the TOC that points to its backup TOC and other side's TOC (if other side exists).
        #This is used to search for all the TOCs in PnorRP code. The idea is to create a link between the tocs such that
        #if we can find one valid TOC, then we can look at its  BACKUP_PART entry or OTHER_SIDE entry in the TOC to
        #determine the location of backup TOC.Each TOC has only one BACKUP_PART entry and one OTHER_SIDE entry.
        #
        # reverse sort is used to sort "primary,backup" rather than "backup,primary"
        foreach my $toc (reverse sort keys %{$$i_pnorLayout{metadata}{sides}{$sideId}{toc}})
        {
            #adding backup_part
            my $toc_offset    = $$i_pnorLayout{metadata}{sides}{$sideId}{toc}{$toc};
            my $backup_offset = $all_tocs[(($backup_idx + 1)% $numOfTOCs) + $sideShift ];
            trace(1, "$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --add --offset $backup_offset --size $physicalRegionSize --name $backup_part --flags 0x0");
            system("$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --add --offset $backup_offset --size $physicalRegionSize --name $backup_part --flags 0x0");
            die "ERROR: Call to add partition $backup_part failed. Aborting!" if ($?);

            #indicate that this is a puesdo-partition and should be skipped on code update
            my $userflags1 = 0x20;
            $userflags1 = $userflags1 << 16;
            trace(1, "$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --user 1 --name $backup_part --value $userflags1 --force");
            system("$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --user 1 --name $backup_part --value $userflags1 --force");
            die "ERROR: Call to set BACKUP_PART as pseudo failed. Aborting!" if ($?);

            #Don't add OTHER_SIDE section if there is only one side in PNOR
            if ((scalar keys % {$$i_pnorLayout{metadata}{sides}}) > 1)
            {
                #adding other_side
                my $otherSide_offset = $all_tocs[(($other_idx + 2)% scalar @all_tocs)];
                trace(1, "$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --add --offset $otherSide_offset --size $physicalRegionSize --name $other_side --flags 0x0");
                system("$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --add --offset $otherSide_offset --size $physicalRegionSize --name $other_side --flags 0x0");
                die "ERROR: Call to add partition $other_side failed. Aborting!" if($?);

                #indicate that this is a puesdo-partition and should be skipped on code update
                trace(1, "$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --user 1 --name $other_side --value $userflags1 --force");
                system("$g_fpartCmd --target $i_pnorBinName --partition-offset $toc_offset --user 1 --name $other_side --value $userflags1 --force");
                die "ERROR: Call to set OTHER_SIDE as pseudo failed. Aborting!" if($?);
            }
            $backup_idx++;
            $other_idx++;
        }
        $sideShift = $sideShift + $numOfTOCs;
    }
}

################################################################################
# manipulateImages - Perform any ECC/padding/sha/signing manipulations
################################################################################
sub manipulateImages
{
    my ($i_pnorLayoutRef, $i_binFiles, $o_finalBinFiles) = @_;
    my $this_func = (caller(0))[3];

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    trace(1, "manipulateImages");

    my %tempImages = (
        HDR_PHASE => "$bin_dir/$image_target.temp.hdr.bin",
        TEMP_SHA_IMG => "$bin_dir/$image_target.temp.sha.bin",
        PAD_PHASE => "$bin_dir/$image_target.temp.pad.bin",
        ECC_PHASE => "$bin_dir/$image_target.temp.bin.ecc",
        VFS_MODULE_TABLE => => "$bin_dir/$image_target.vfs_module_table.bin",
        TEMP_BIN => "$bin_dir/$image_target.temp.bin",
        PAYLOAD_TEXT => "$bin_dir/$image_target.payload_text.bin",
        PROTECTED_PAYLOAD => "$bin_dir/$image_target.protected_payload.bin"
    );

    # @TODO RTC:155374 Remove when all partitions supported by secureboot
    # Partitions that are now handled in this script. Some partitions are still
    # handled in their respective makefiles(FSP) scripts(OP). Eventually this
    # structure should not be needed.
    my %supportedPartitions = (
        HBI => 1,
        GUARD => 1,
        HBEL => 1,
        GLOBAL => 1,
        DJVPD => 1,
        MVPD => 1,
        CVPD => 1,
        PAYLOAD => 1,
        TEST => 1,
        TESTRO => 1
    );

    # @TODO RTC:125298 add HBI to this list, not supported until vfsrp code
    # is modified.
    my %hashPageTablePartitions = ();

    foreach my $key ( keys %sectionHash)
    {
        my $eyeCatch = $sectionHash{$key}{eyeCatch};
        my $size = $sectionHash{$key}{physicalRegionSize};
        my $bin_file = "";
        my $final_bin_file = "$bin_dir/$eyeCatch.$image_target.bin";

        if(exists $$i_binFiles{$eyeCatch})
        {
            $bin_file = $$i_binFiles{$eyeCatch};
        }

        # @TODO RTC:155374 Remove after all partitions supported
        if (exists $supportedPartitions{$eyeCatch})
        {
            # FSP workaround to keep original bin names
            my $fsp_file = $bin_file;
            my $fsp_prefix = "";
            # Header Phase - only necessary if bin file passed in
            if ($bin_file ne "")
            {
                if( ($sectionHash{$key}{sha512Version} eq "yes") )
                {
                    $fsp_prefix.=".header";
                    # Add secure container header
                    # @TODO RTC:155374 Remove when official signing supported
                    if ($secureboot)
                    {
                        if (exists $hashPageTablePartitions{$eyeCatch})
                        {
                            $tempImages{hashPageTable} = genHashPageTable($bin_file, $eyeCatch);
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
                                # Payload text section
                                run_command("cat $tempImages{hashPageTable} $tempImages{VFS_MODULE_TABLE} > $tempImages{PAYLOAD_TEXT} ");
                            }
                            else
                            {
                                run_command("cp $tempImages{hashPageTable} $tempImages{PAYLOAD_TEXT}");
                            }
                            run_command("$SIGNING_DIR/build -good -if $SECUREBOOT_HDR -of $tempImages{PROTECTED_PAYLOAD} -bin $tempImages{PAYLOAD_TEXT} $SIGN_BUILD_PARAMS");
                            run_command("cat $tempImages{PROTECTED_PAYLOAD} $bin_file > $tempImages{HDR_PHASE}");
                        }
                        else
                        {
                            run_command("$SIGNING_DIR/build -good -if $SECUREBOOT_HDR -of $tempImages{HDR_PHASE} -bin $bin_file $SIGN_BUILD_PARAMS");
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
                elsif( ($sectionHash{$key}{sha512perEC} eq "yes") )
                {
                    # Placeholder for sha512perEC partitions
                }
                else
                {
                    run_command("cp $bin_file $tempImages{HDR_PHASE}");
                }
            }

            # Padding Phase
            if ($sectionHash{$key}{ecc} eq "yes")
            {
                $size = page_aligned_size_wo_ecc($size);
            }

            if ($eyeCatch eq "HBI" && $testRun)
            {
                # If "--test" flag set do not pad as the test HBI images is
                # possibly larger than parition size and does not need to be
                # fully padded. Size adjustments made in checkSpaceConstraints
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=4k conv=sync");
            }
            elsif ($bin_file eq "")
            {
                # Test partitions have random data
                if ($eyeCatch eq "TEST" || $eyeCatch eq "TESTRO")
                {
                    run_command("dd if=/dev/urandom of=$tempImages{PAD_PHASE} count=1 bs=$size");
                }
                # Other partitions fill with FF's if no bin file provided
                else
                {
                    run_command("dd if=/dev/zero bs=$size count=1 | tr \"\\000\" \"\\377\" > $tempImages{PAD_PHASE}");
                }
            }
            else
            {
                run_command("dd if=$tempImages{HDR_PHASE} of=$tempImages{PAD_PHASE} ibs=$size conv=sync");
            }

            # Create .header.bin file for FSP
            if ($fsp_file ne "")
            {
                $fsp_file =~ s/.bin/$fsp_prefix.bin/;
                run_command("cp $tempImages{PAD_PHASE} $fsp_file");
            }

            # ECC Phase
            if( ($sectionHash{$key}{ecc} eq "yes") )
            {
                run_command("ecc --inject $tempImages{PAD_PHASE} --output $tempImages{ECC_PHASE} --p8");
                # Create .bin.ecc file for FSP
                if ($fsp_file ne "")
                {
                    run_command("cp $tempImages{ECC_PHASE} $fsp_file.ecc");
                }
            }
            else
            {
                run_command("cp $tempImages{PAD_PHASE} $tempImages{ECC_PHASE}");
            }

            # Compression phase
            if( ($sectionHash{$key}{compressed}{algorithm} eq "xz"))
            {
                # Placeholder for compression partitions
            }

            # Move content to final bin filename
            run_command("cp $tempImages{ECC_PHASE} $final_bin_file");
            $$o_finalBinFiles{$eyeCatch} = $final_bin_file;
        }
        else
        {
            $$o_finalBinFiles{$eyeCatch} = $bin_file;
        }

    }

    # Clean up temp images
    foreach my $image (keys %tempImages)
    {
        system("rm -f $tempImages{$image}");
        die "Failed deleting $tempImages{$image}" if ($?);
    }

    return 0;
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
        TEST_CONTAINER_DATA => "$bin_dir/$image_target.test.cont.bin",
        PROTECTED_PAYLOAD => "$bin_dir/$image_target.test.protected_payload.bin"
    );

    # $image_target prefix is not what's in hb cache, just used for parallel builds
    # Create a signed test container
    # name = secureboot_signed_container (no prefix in hb cacheadd)
    my $test_container = "$bin_dir/$image_target.secureboot_signed_container";
    run_command("dd if=/dev/zero count=1 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    run_command("$SIGNING_DIR/build -good -if $SECUREBOOT_HDR -of $test_container -bin $tempImages{TEST_CONTAINER_DATA} $SIGN_BUILD_PARAMS");

    # Create a signed test container with a hash page table
    # name = secureboot_hash_page_table_container (no prefix in hb cacheadd)
    $test_container = "$bin_dir/$image_target.secureboot_hash_page_table_container";
    run_command("dd if=/dev/urandom count=50 ibs=4096 | tr \"\\000\" \"\\377\" > $tempImages{TEST_CONTAINER_DATA}");
    $tempImages{hashPageTable} = genHashPageTable($tempImages{TEST_CONTAINER_DATA}, "secureboot_test");
    run_command("$SIGNING_DIR/build -good -if $SECUREBOOT_HDR -of $tempImages{PROTECTED_PAYLOAD} -bin $tempImages{hashPageTable} $SIGN_BUILD_PARAMS");
    run_command("cat $tempImages{PROTECTED_PAYLOAD} $tempImages{TEST_CONTAINER_DATA} > $test_container ");

    # Clean up temp images
    foreach my $image (keys %tempImages)
    {
        system("rm -f $tempImages{$image}");
        die "Failed deleting $tempImages{$image}" if ($?);
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
# align_down: Align the input to the lower end of the PNOR side
################################################################################
sub align_down
{
    my ($addr,$n) = @_;
    return (($addr) - ($addr)%($n));
}

################################################################################
# align_up: Align the input address to the higher end of the PNOR side
################################################################################
sub align_up
{
    my ($addr,$n) = @_;
    return ((($addr) + ($n-1)) & ~($n-1));
}

################################################################################
# findLayoutKeyByEyeCatch - Figure out hash key based on eyeCatcher
################################################################################
sub findLayoutKeyByEyeCatch
{
    my $layoutKey = -1;
    my($eyeCatch, $i_pnorLayoutRef) = @_;
    my $key;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    for $key ( keys %sectionHash)
    {
        if($sectionHash{$key}{eyeCatch} =~ $eyeCatch)
        {
            $layoutKey = $key;
            last;
        }
    }

    return $layoutKey;
}

################################################################################
# verifyFilesExist - Verify all the input files exist
################################################################################
sub verifyFilesExist
{
    my ($i_pnorLayoutRef, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;

    for $key ( keys %$i_binFiles)
    {
        unless(-e $$i_binFiles{$key})
        {
            my $inputFile = $$i_binFiles{$key};
            die "ERROR: Specified input file ($inputFile) for key ($key) does not exist.  Aborting!";
        }
        else
        {
            trace(10, "$this_func: $$i_binFiles{$key} exists");
        }
    }

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
}

################################################################################
# checkSpaceConstraints - Make sure provided files will fit in their sections
################################################################################
sub checkSpaceConstraints
{
    my ($i_pnorLayoutRef, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    for $key ( keys %{$i_binFiles})
    {
        my $filesize = -s $$i_binFiles{$key};

        my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayoutRef);
        if( $layoutKey == -1)
        {
            die "ERROR: $this_func: entry not found in PNOR layout for file $$i_binFiles{$key}, under eyecatcher $key";
        }

        my $eyeCatch = $sectionHash{$layoutKey}{eyeCatch};
        my $physicalRegionSize = $sectionHash{$layoutKey}{physicalRegionSize};

        if($filesize > $physicalRegionSize)
        {
            # If this is a test run increase HBI size by PAGE_SIZE until all test
            # cases fit
            if ($testRun && $eyeCatch eq "HBI")
            {
                print "Adjusting HBI size - ran out of space for test cases\n";
                my $hbbKey = findLayoutKeyByEyeCatch("HBB", \%$i_pnorLayoutRef);
                adjustHbiPhysSize(\%sectionHash, $layoutKey, $filesize, $hbbKey);
            }
            else
            {
                die "ERROR: $this_func: Image provided ($$i_binFiles{$eyeCatch}) has size ($filesize) which is greater than allocated space ($physicalRegionSize) for section=$eyeCatch.  Aborting!";
            }
        }
    }
}

###############################################################################
# adjustHbiPhysSize - Adjust HBI physical size when running test cases and fix
#                     up physical offsets of partitions between HBI and HBB
################################################################################
sub adjustHbiPhysSize
{
    my ($i_sectionHashRef, $i_hbiKey, $i_filesize, $i_hbbKey) = @_;

    my %sectionHash = %$i_sectionHashRef;

    # Increment HBI physical size by PAGE_SIZE until the HBI file can fit
    my $hbi_old = $sectionHash{$i_hbiKey}{physicalRegionSize};
    while ($i_filesize > $sectionHash{$i_hbiKey}{physicalRegionSize})
    {
        $sectionHash{$i_hbiKey}{physicalRegionSize} += PAGE_SIZE;
    }
    my $hbi_move = $sectionHash{$i_hbiKey}{physicalRegionSize} - $hbi_old;
    my $hbi_end = $sectionHash{$i_hbiKey}{physicalRegionSize} + $hbi_move;

    # Fix up physical offset affected by HBI size change
    foreach my $section (keys %sectionHash)
    {
        # Only fix partitions after HBI and before HBB
        if ( ( $sectionHash{$section}{physicalOffset} >
               $sectionHash{$i_hbiKey}{physicalOffset} ) &&
             ( $sectionHash{$section}{physicalOffset} <
               $sectionHash{$i_hbbKey}{physicalOffset} )
            )
        {
            $sectionHash{$section}{physicalOffset} += $hbi_move;
            # Ensure section adjustment does not cause an overlap with HBB
            if ($sectionHash{$section}{physicalOffset} >
                $sectionHash{$i_hbbKey}{physicalOffset})
            {
                die "Error detected $sectionHash{$section}{eyeCatch}'s adjusted size overlaps HBB";
            }
        }
    }
}


###############################################################################
# fillPnorImage - Load actual PNOR image with data using the provided input images
################################################################################
sub fillPnorImage
{
    my ($i_pnorBinName, $i_pnorLayoutRef, $i_binFiles, $side, $offset) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $other_side = getOtherSide($side);

    trace(1, "fillPnorImage:: $offset");
    #key is the physical offset into the file, however don't need to sort
    #since FFS allows populating partitions in any order
    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    for $key ( keys %sectionHash)
    {
        trace(3, "$this_func: key=$key");
        my $eyeCatch = $sectionHash{$key}{eyeCatch};
        my $physicalOffset = $sectionHash{$key}{physicalOffset};
        my $inputFile = "";

        #Only populate sections with input files provided
        if(exists $$i_binFiles{$eyeCatch})
        {
            $inputFile = $$i_binFiles{$eyeCatch};
        }
        else
        {
            next;
        }

        my $sideInfo = getSideInfo($key, %sectionHash);

        # Add if side matches (or not set) -- so if it isn't equal to other side
        # Only fill sideless sections once
        if( ($sideInfo ne $other_side) &&
            (!exists($sidelessSecFilled{$eyeCatch})))
        {
            if($sideInfo eq $SideOptions{sideless})
            {
                $sidelessSecFilled{$eyeCatch} = 1;
            }
            trace(5, "$this_func: populating section $sideInfo:$eyeCatch, filename=$inputFile");
            #fcp --target tuleta.pnor --partition-offset 0 --name HBI --write hostboot_extended.bin
            system("$g_fcpCmd $inputFile $i_pnorBinName:$eyeCatch --offset $offset --write --buffer 0x40000000");
            die "ERROR: $this_func: Call to fcp adding data to partition $eyeCatch failed. Aborting!" if($?);
         }
     }
}

################################################################################
# saveInputFile - save inputfile name into binFiles array
################################################################################
sub saveInputFile
{
    my ($i_argPrefix, $i_argName, $i_argVal, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];

    #$i_argName will be something like --binFile_HBB
    #This substr command should return just the HBB, which should match an eyeCather
    my $eyeCatcher = substr($i_argName, length($i_argPrefix)+1, length($i_argName)-length($i_argPrefix));

    trace(10, "$this_func: $eyeCatcher=$i_argVal");

    $$i_binFiles{$eyeCatcher} = $i_argVal;

    trace(10, "$this_func:           $$i_binFiles{$eyeCatcher}");

    #no return code expected
}

#################################################
# Insert specifed number of pad bytes into file
#
#################################################
sub insertPadBytes
{
    my ($i_FILEHANDLE, $i_padBytes) = @_;
    my $i;
    print $i_FILEHANDLE pack("C[$i_padBytes]", map { 0 } 1..$i_padBytes);

}

################################################################################
# getNumber - handle hex or decimal input string
################################################################################
sub getNumber
{
    my $inVal = shift;
    if($inVal =~ "0x")
    {
	return oct($inVal);
    }
    else
    {
	return $inVal;
    }
}

################################################################################
# trace
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
    my $i_traceLevel;
    my $i_string;

    ($i_traceLevel, $i_string) = @_;

    #traceLevel 0 is for errors
    if($i_traceLevel == 0)
    {
	print "ERROR: ".$i_string."\n";
    }
    elsif ($g_trace >= $i_traceLevel)
    {
	print "TRACE: ".$i_string."\n";
    }
}

################################################################################
# getSideInfo - return side info of certain sections and determine if value is
#               a supported value
################################################################################
sub getSideInfo
{
    my $i_key = shift;
    my %i_sectionHash = @_;

    my $side = "";
    my $eyeCatch = $i_sectionHash{$i_key}{eyeCatch};

    $side = $i_sectionHash{$i_key}{side};

    # Error paths
    if ($side eq "")
    {
        trace(0, "Error detected from call to getSideInfo() - $eyeCatch has no side info specified Exiting");
        exit 1;
    }
    elsif (!exists($SideOptions{$side}))
    {
        trace(0, "Error detected from call to getSideInfo() - $eyeCatch has sideInfo = $side which is not supported Exiting");
        exit 1;
    }

    return $side;
}

################################################################################
# getOtherSide - return other side of the given side
#                does not default to main side in case more sides are added
################################################################################
sub getOtherSide
{
    my $i_side = shift;
    my $other_side = "";

    if($i_side eq $SideOptions{A})
    {
        $other_side = $SideOptions{B};
    }
    elsif($i_side eq $SideOptions{B})
    {
        $other_side = $SideOptions{A};
    }

    # Error paths
    if ($other_side eq "")
    {
        trace(0, "Error detected from call to getOtherSide() - Could not get other side of side = $i_side Exiting");
        exit 1;
    }

    return $other_side;
}

################################################################################
# run_command - First print, and then run a system command, erroring out if the
#               command does not complete successfully
################################################################################
sub run_command
{
    my $command = shift;
    trace(1, "$command");
    my $rc = system($command);
    die "Error running command: $command. Nonzero return code of ($rc) returned.\n" if ($rc !=0);
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
    my ($bin_file, $eyeCatch) = @_;

    # Open the file
    my $hashPageTableFile = "$bin_dir/$eyeCatch.$image_target.page_hash_table";
    open (INBINFILE, "<", $bin_file) or die "Error opening file $bin_file: $!\n";
    open (OUTBINFILE, ">", $hashPageTableFile) or die "Error opening file $hashPageTableFile: $!\n";
    # set stream to binary mode
    binmode INBINFILE;
    binmode OUTBINFILE;

    # Enter Salt as first entry
    my $salt_entry = 0;
    for (my $i = 0; $i < SHA_TRUNCATE_SIZE; $i++)
    {
        $salt_entry .= sha512(rand(0x7FFFFFFFFFFFFFFF));
    }
    $salt_entry = truncate_sha(sha512($salt_entry));
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
    my $temp_file = "$bin_dir/$eyeCatch.$image_target.page_hash_table.temp";
    run_command("cp $hashPageTableFile $temp_file");
    run_command("dd if=$temp_file of=$hashPageTableFile ibs=4k conv=sync");
    run_command("rm $temp_file");

    return $hashPageTableFile;
}

################################################################################
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $programName = Creates the PNOR IMAGE and with TOC based on input data.

  Usage:
    $programName --pnorlayout <layout xml file> --genToc --tocVersion <TOC layout version
                 --pnorOutBin  <complete PNOR image>
                 --binFile_HBB <hostboot base image> --binFile_HBI <hostboot extended image>

  Parms:
    -h                  Print this help text
    --pnorlayout <file> PNOR Layout XML file
    --pnorOutBin <file> Name of output file for PNOR Binary
    --genToc            Indicates you wish to generate a table of contents.  It will
                        write the file indicated by --binFile_TOC.

    --binFile_<Section> <file>  This is a special paramater.  It is used to specify
                        input files to use for populating the various sections of
                        PNOR.
                            Examples:  --binFile_HBB hostboot.bin
                                       --binFile_HBI hostboot_extended.bin
                                       --binFile_TOC murano.toc
                         A section declared as Blank in the XML does not need to have a
                         binFile specified
    --ffsCmd            invoke string for executing the ffs tool
    --fpartCmd          invoke string for executing the fpart tool
    --fcpCmd            invoke string for executing the fcp tool
    --test              Output test-only sections.

  Current Limitations:
      --TOC Records must be 4 or 8 bytes in length
      --Regions and offsets cannot be over 32 bits (in hex), not an issue with current PNOR size
     The script will print and error and exit with a non-zero return code if these
     conditions are encountered.

ENDUSAGE
}
