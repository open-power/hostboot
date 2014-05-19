#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildSbePart.pl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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

#Builds an SBE partition for PNOR based on user-provided SBE images
#It works for both Processor SBE-IPL images and Centaur SBE images

use strict;
use File::Basename;
use File::Temp qw/ tempfile tempdir /;

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_trace = 1;

my $progName = File::Basename::basename $0;
my $outBin = "";
my %ecImgs;
my $injectVerHdrs = undef;
my $tocVersion = 1;  #Only version 1 currently defined

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
    elsif($ARGV[$i] =~ /--injectVersionHeaders/) {
        $injectVerHdrs = 1;
        trace(2, "injectVersionHeaders flag specified");
    }
    elsif($ARGV[$i] =~ /--sbeOutBin/) {
        $outBin = $ARGV[++$i];
        trace(2, "SBE output Binary File=$outBin");
    }
    elsif($ARGV[$i] =~ /--ecImg/) {
        my $argName = $ARGV[$i];
        my $argVal = $ARGV[++$i];
        saveInputFile("--ecImg", $argName, $argVal, \%ecImgs);
    }
    else {
        traceErr("Unrecognized Input: $ARGV[$i]");
        exit 1;
    }
}


#Verify all the SBE images exist
my $rc = verifyFilesExist(\%ecImgs);
if($rc != 0)
{
    trace(0, "$progName: Error detected from call to verifyFilesExist().  Exiting");
    exit 1;
}

#Generate the output image
my $rc = genOutputImage($injectVerHdrs, $tocVersion, $outBin, \%ecImgs);
if($rc != 0)
{
    trace(0, "$progName: Error detected from call to genOutputImage().  Exiting");
    exit 1;
}


################################################################################
# saveInputFile - save inputfile name into ecImgss array
################################################################################
sub saveInputFile
{
    my ($i_argPrefix, $i_argName, $i_argVal, $i_ecImgs) = @_;
    my $this_func = (caller(0))[3];

    #$i_argName will be something like --ecIMG_10
    #This substr command should return just the 10, which is the image EC Level
    my $ecLevel = substr($i_argName,
                         length($i_argPrefix)+1,
                         length($i_argName)-length($i_argPrefix));

    trace(10, "$this_func: $ecLevel=$i_argVal");

    $$i_ecImgs{$ecLevel} = $i_argVal;

    trace(10, "$this_func:           $$i_ecImgs{$ecLevel}");

    #no return code expected
}

################################################################################
# verifyFilesExist - Verify all the input files exist
################################################################################
sub verifyFilesExist
{
    my ($i_ecImgs) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %$i_ecImgs)
    {
        unless(-e $$i_ecImgs{$key})
        {
            my $inputFile = $$i_ecImgs{$key};
            trace(0, "$this_func: Specified input file ($inputFile) for key ($key) does not exist.  Aborting!");
            $rc = 1;
            last;
        }
        else
        {
            trace(10, "$this_func: $$i_ecImgs{$key} exists");
        }
    }

    return $rc;
}

################################################################################
# genOutputImage - Generate output image
#          -Build SBE TOC in first 128 bytes
#          -Insert 4K header in front of each image with SHA512 as version
#          -Insert each SBE image after corresponding header
################################################################################
#Output image layout (Defined in Hostboot SBE Layout document)
#word 0: 'SBE\0' eyecatcher
#word 1: SBE TOC Layout version - currently only 1 is defined
#word 2: SBE image EC
#word 3: Sbe image offset in partition
#word 4: SBE image size
#Repeat words 2-4 for each supported EC

#Actual SBE Images start at offset 0x1000 and must always be on a 4k boundary.
################################################################################
sub genOutputImage
{
    my ($i_injectVerHdrs, $i_tocVersion, $i_outBin, $i_ecImgs) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my %ecOffsets;
    my $rc = 0;
    my $FILEHANDLE;
    my $curOffset = 0x1000;  #first offset is at 4k
    trace(4, "$this_func: >>Enter");

#open output file
    open( $FILEHANDLE, ">:raw", $i_outBin)
      or die "Can't open $i_outBin file for writing";

    #Build the TOC
    #WORD 0: EyeCatcher - "SBE\0" in ASCII
    my @charArray = split //, 'SBE';
    my $curChar;
    foreach $curChar (@charArray)
    {
        print $FILEHANDLE pack('C', ord($curChar));
    }

    #Pad byte for null character after SBE
    insertPadBytes($FILEHANDLE, 1);

     #WORD 1: Version = 0x00000001
    print $FILEHANDLE pack('N', 1);

    #Insert header data for each EC provided
    for $key ( keys %{$i_ecImgs})
    {
        trace(2, "$this_func: Inserting header for EC=$key");
        my $filesize = -s $$i_ecImgs{$key};

        if($i_injectVerHdrs)
        {
            $filesize += 0x1000;
        }

        #EC Word
        print $FILEHANDLE pack('N', hex($key));

        #Offset Word
        print $FILEHANDLE pack('N', $curOffset);

        #Size Word
        print $FILEHANDLE pack('N', $filesize);

        #safe offset for inserting images
        $ecOffsets{$key} = $curOffset;

        #generate next to 4k offset
        $curOffset += $filesize;
        if (($curOffset & 0x00000FFF) != 0)
        {
            $curOffset = $curOffset & 0xFFFFF000;
            $curOffset += 0x1000;
        }
    }

    close $FILEHANDLE;

    #Insert actual image for each EC provided
    for $key ( keys %{$i_ecImgs})
    {
        trace(2, "$this_func: Inserting data for EC=$key, offset=$ecOffsets{$key}");

        my $seekOffset = $ecOffsets{$key};
        my $inFile = $$i_ecImgs{$key};

        #Image is prefixed with 4k header containing version
        if($i_injectVerHdrs)
        {
            my $headerOffset = $seekOffset;
            $seekOffset += 0x1000;

            my $headerFh;
            my $headerFile;
            ($headerFh, $headerFile) = tempfile(UNLINK => 1);
            #Disable file handle buffering

            trace(0, "$this_func: headerFile=$headerFile");


            #Insert 'VERSION\0' Eyecatcher
            my @eyeCatchArray = split //, 'VERSION';
            foreach $curChar (@eyeCatchArray)
            {
                print $headerFh pack('C', ord($curChar));
            }
            #Pad byte for null character after VERSION
            insertPadBytes($headerFh, 1);

            #make sure date written to file handle is flushed to disk
            close $headerFh;

            #Create the SHA512 hash
            my $cmd = "sha512sum $inFile \| awk \'\{print $1\}\' \| xxd -ps -r \>> $headerFile";
            system( $cmd ) == 0 or die "Creating $headerFile failed!";

            #Write to output file
            my $hdrdd = "dd if=$headerFile of=$i_outBin bs=1 seek=$headerOffset";
            system ( $hdrdd ) == 0 or die "Couldn't Write $headerFile to $i_outBin!";
        }
        my $ddCmd = "dd if=$inFile of=$i_outBin bs=1 seek=$seekOffset";
        system ( $ddCmd ) == 0 or die "Couldn't Write $inFile to $i_outBin!";

    }

    trace(4, "$this_func: <<Exit");

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
  $progName = Creates SBE partition with SBE TOC based on input data.

  Usage:
    $progName --sbeOutBin  <complete SBE Partition image>
                 [--ecImg_10 <EC 10 SBE image>] [--ecImg_20 <EC_20_SBE_image>]
                 [--injectVersionHeaders]

  Parms:
    -h                  Print this help text
    --sbeOutBin <file> Name of output file for PNOR Binary
    --ecImg_<EC> <file>  This is a special paramater.  It is used to specify
                        input files to use for populating the partition with
                        supported SBE EC specific images
                            Examples:  --binFile_10 s1_10.sbe_seeprom.bin
                                       --binFile_13 s1_13.sbe_seeprom.bin
                                       --binFile_20 s1_20.sbe_seeprom.bin
    --injectVersionHeaders Injects a 4k header at the top of each image
                           containing a SHA512 Hash computed over the image.


ENDUSAGE
}
