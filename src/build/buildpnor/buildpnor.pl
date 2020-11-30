#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildpnor.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2020
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
use Data::Dumper;
use File::Basename;
use Cwd qw(abs_path);
use lib dirname abs_path($0);
use PnorUtils qw(loadPnorLayout getNumber traceErr trace run_command
                 findLayoutKeyByEyeCatch checkSpaceConstraints);

# Jail command for yocto froot
my $jailcmd = "";
if ($ENV{JAILCMD}) {
   $jailcmd = $ENV{JAILCMD};
}

print ("jailcmd = $jailcmd\n");

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
my $g_fpartCmd = "";
my $g_fcpCmd = "";
my %sidelessSecFilled = ();
my %SideOptions = (
        A => "A",
        B => "B",
        sideless => "sideless",
    );
my $editedLayoutLocation = "";

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
    elsif($ARGV[$i] =~ /--editedLayoutLocation/) {
        $editedLayoutLocation = $ARGV[++$i];
        trace(2, "Location where the edited layout file will be placed: $editedLayoutLocation");
    }
    else {
        traceErr("Unrecognized Input: $ARGV[$i]");
        exit 1;
	#Error!!
    }
}

# Prepend the jail command to the fpart and fcp commands
$g_fpartCmd = "$jailcmd $g_fpartCmd";
$g_fcpCmd = "$jailcmd $g_fcpCmd";

############################## Begin Actions ##################################

#Delete File (pnorBinName) if exists to prevent errors when making layout
#changes
if (-e $pnorBinName)
{
    unlink $pnorBinName or warn "Could not unlink $pnorBinName: $!";
}

#Load PNOR Layout XML file
loadPnorLayout($pnorLayoutFile, \%pnorLayout, \%PhysicalOffsets, $testRun,
    $editedLayoutLocation);

#Verify all the section files exist
verifyFilesExist(\%pnorLayout, \%binFiles);

# Make sure provided files will fit in their sections
checkSpaceConstraints(\%pnorLayout, \%binFiles, $testRun);

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

        # Make the TOC Read-only
        $userflags1 |= 0x40;

        #add the golden and read-only bits to the misc flags in userflag1
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

    fillPnorImage($pnorBinName, \%pnorLayout, \%binFiles, $sideId, $tocOffset);
}

exit 0;

#########################  Begin Utility Subroutines ###########################

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
    my $chipSize = $$i_pnorLayoutRef{metadata}{chipSize};
    my $imageSize = $$i_pnorLayoutRef{metadata}{imageSize};
    my $blockCount = $imageSize/$blockSize;
    if ($blockCount != int($blockCount))
    {
        die "ERROR: $this_func: Image size ($imageSize) is not an even multiple of erase blocks ($blockSize).  This is not supported.  Aborting!";

    }
    #f{fs,part} --create tuleta.pnor --partition-offset 0 --size 8MiB --block 4KiB --force
    trace(2, "$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --create --size $chipSize --block $blockSize --force");
    system("$g_fpartCmd --target $i_pnorBinName --partition-offset $i_offset --create --size $chipSize --block $blockSize --force");
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

    # VerCheck Flag: sha512Version
    if( ($i_sectionHash{$i_key}{sha512Version} eq "yes") )
    {
        $verCheck |= 0x80;
    }

    # VerCheck Flag: sha512perEC
    if( ($i_sectionHash{$i_key}{sha512perEC} eq "yes") )
    {
        $verCheck |= 0x40;
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
    if( ($i_sectionHash{$i_key}{volatile} eq "yes") )
    {
        $miscFlags |= 0x08;
    }
    if( ($i_sectionHash{$i_key}{clearOnEccErr} eq "yes") )
    {
        $miscFlags |= 0x04;
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

        #Using userflags mark these sections read-only (0x40) and indicate that
        #they are puesdo-partitions that should be skipped on code update (0x20)
        my $userflags1 = 0x40 | 0x20;
        $userflags1 = $userflags1 << 16;

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

            #adding user flags
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

                #adding user flags
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

###############################################################################
# fillPnorImage - Load actual PNOR image with data using the provided input images
################################################################################
sub fillPnorImage
{
    my ($i_pnorBinName, $i_pnorLayoutRef, $i_binFiles, $side, $offset) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $other_side = getOtherSide($side);

    my $imageSize =  $$i_pnorLayoutRef{metadata}{imageSize};

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
            system("$g_fcpCmd $inputFile $i_pnorBinName:$eyeCatch --offset $offset --write --buffer $imageSize");
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
    --editedLayoutLocation <directory>      Location to place edited layout file

  Current Limitations:
      --TOC Records must be 4 or 8 bytes in length
      --Regions and offsets cannot be over 32 bits (in hex), not an issue with current PNOR size
     The script will print and error and exit with a non-zero return code if these
     conditions are encountered.

ENDUSAGE
}
