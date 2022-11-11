#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildSPDImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2023
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

#Builds an PSPD partition for PNOR based on user-provided SPD images

use strict;
use File::Basename;
use File::Temp qw/ tempfile tempdir /;

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_trace = 1;

my $progName = File::Basename::basename $0;
my $outBin = "";
my %spdImgs;
my $tocVersion = 1;  #Only version 1 currently defined
my $tocCount = 0;    #Keep track of how many Img's being built
my $rc       = 0;    #rc value

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
    elsif($ARGV[$i] =~ /--spdOutBin/) {
        $outBin = $ARGV[++$i];
    }
    elsif($ARGV[$i] =~ /--spdImg/) {
        my $argName = $ARGV[$i];
        my $argVal = $ARGV[++$i];
        saveInputFile("--spdImg", $argName, $argVal, \%spdImgs);
    }
    else {
        traceErr("Unrecognized Input: $ARGV[$i]");
        usage();
        exit 1;
    }
}


#Verify all the SPD images exist
($rc, $tocCount) = verifyFilesExist(\%spdImgs, $tocCount);
if($rc != 0)
{
    trace(0, "$progName: Error detected from call to verifyFilesExist().  Exiting");
    exit 1;
}

#Generate the output image
trace(1, "$progName tocCount is $tocCount for genOutputImage");
$rc = genOutputImage($tocVersion, $tocCount, $outBin, \%spdImgs);
if($rc != 0)
{
    trace(0, "$progName: Error detected from call to genOutputImage().  Exiting");
    exit 1;
}


################################################################################
# saveInputFile - save inputfile name into spdImgs array
################################################################################
sub saveInputFile
{
    my ($i_argPrefix, $i_argName, $i_argVal, $i_spdImgs) = @_;
    my $this_func = (caller(0))[3];

    #$i_argName will be something like --spdIMG_1
    #This substr command should return just the 1, which is the image identifier
    my $imgIndex = substr($i_argName,
                         length($i_argPrefix)+1,
                         length($i_argName)-length($i_argPrefix));
    $$i_spdImgs{$imgIndex} = $i_argVal;

    #no return code expected
}

################################################################################
# verifyFilesExist - Verify all the input files exist
################################################################################
sub verifyFilesExist
{
    my ($i_spdImgs, $o_tocCount) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %$i_spdImgs)
    {
        unless(-e $$i_spdImgs{$key})
        {
            my $inputFile = $$i_spdImgs{$key};
            trace(0, "$progName:$this_func: Specified input file ($inputFile) for key ($key) does not exist.  Aborting!");
            $rc = 1;
            last;
        }
        else
        {
            trace(1, "$progName:$this_func: Adding inputFile ($$i_spdImgs{$key}) for key=$key o_tocCount=$o_tocCount");
            $o_tocCount++;
        }
    }

    return ($rc, $o_tocCount);
}

################################################################################
# genOutputImage - Generate output image
#          -Build SPD TOC in first 128 bytes
#          -Insert each SPD image
################################################################################
#Output Layout (Defined in Hostboot SectionMapTOC_t ocmb_spd.C)
# word in this context is uint32_t
#word 0: 'SPD\0' eyecatcher
#word 1: SPD TOC Layout version - currently only 1 is defined
#word 2: SPD Count of Images
#  (Defined in Hostboot SPDImages spdEntry ocmb_spd.C)
#word 3: SPD image ID
#word 4: SPD image offset in partition (base is word 0, eyecatcher)
#word 5: SPD image size
#Repeat words 3-5 for each supported Image

#Actual SPD Images start at offset 0x1000 and each SPD image must always be on a 4k boundary.
################################################################################
sub genOutputImage
{
    my ($i_tocVersion, $i_tocCount, $i_outBin, $i_spdImgs) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my %spdOffsets;
    my $rc = 0;
    my $FILEHANDLE;
    my $curOffset = 0x1000;  #first offset is at 4k

    #open output file
    open( $FILEHANDLE, ">:raw", $i_outBin)
      or die "Can't open $i_outBin file for writing";

    #Build the TOC
    #WORD 0: EyeCatcher - "SPD\0" in ASCII
    my @charArray = split //, 'SPD';
    my $curChar;
    foreach $curChar (@charArray)
    {
        print $FILEHANDLE pack('C', ord($curChar));
    }

    #Pad byte for null character after SPD
    insertPadBytes($FILEHANDLE, 1);

    #WORD 1: Version = 0x00000001
    print $FILEHANDLE pack('N', 1);
    #WORD 2: Count of Images
    print $FILEHANDLE pack('N', $i_tocCount);

    #Insert header data for each IMG provided
    for $key (sort { $a <=> $b} keys %{$i_spdImgs})
    {
        my $filesize = -s $$i_spdImgs{$key};

        #IMG Word
        print $FILEHANDLE pack('N', hex($key));

        #Offset Word
        print $FILEHANDLE pack('N', $curOffset);

        #Size Word
        print $FILEHANDLE pack('N', $filesize);

        #safe offset for inserting images
        $spdOffsets{$key} = $curOffset;

        #generate next to 4k offset
        $curOffset += $filesize;
        if (($curOffset & 0x00000FFF) != 0)
        {
            $curOffset = $curOffset & 0xFFFFF000;
            $curOffset += 0x1000;
        }
    }

    close $FILEHANDLE;

    #Insert actual image for each IMG provided
    for $key (sort { $a <=> $b} keys %{$i_spdImgs})
    {
        my $seekOffset = $spdOffsets{$key};
        my $inFile = $$i_spdImgs{$key};

        my $ddCmd = "dd if=$inFile of=$i_outBin bs=1 seek=$seekOffset";
        system ( $ddCmd ) == 0 or die "Couldn't Write $inFile to $i_outBin!";

    }


    return $rc;
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
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $progName = Creates SPD partition with SPD TOC based on input data.

  Usage:
    $progName --spdOutBin  <complete SPD Partition image>
                 [--spdImg_1 <SPD image 1>] [--spdImg_2 <SPD image 2>]
                 [--injectVersionHeaders]

  Parms:
    -h                   Print this help text
    --spdOutBin <file>   Name of output file for PNOR Binary
    --spdImg_1  <file>   This is a special paramater.  It is used to specify
                         input files to use for populating the partition with
                         supported SPD images
                            Example:  --spdImg_1 pspddata.bin
    --injectVersionHeaders Injects a 4k header at the top of each image
                           containing a SHA512 Hash computed over the image.


ENDUSAGE
}
