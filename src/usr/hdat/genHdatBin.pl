#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hdat/genHdatBin.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2018
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
use warnings;
use XML::LibXML;
use feature 'say';
use Class::Struct;
use File::stat;
use File::Copy;

my $cfgBigEndian = 1;

################################################################################
# Pack 2 byte value into a buffer using configured endianness
################################################################################

sub pack4byte {
    my($value) = @_;

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("N",$value);
    }
    else # Little endian
    {
        $binaryData = pack("V",$value);
    }

    return $binaryData;
}

my $layoutFile = 'hdatBinLayout.xml';
my $dom = XML::LibXML->load_xml(location => $layoutFile);

# verify if collective bins size if less than max size

validateMaxSize($dom);
my %toc = createToc($dom);
my $chkSum = createChecksum($dom);
my $ver = '104q';
my $hdatBin = "hdat.bin";
open ( my $hdatBinfh , '>', $hdatBin)
           or die "Can't open > $hdatBin: $!";
binmode($hdatBinfh);
print $hdatBinfh $ver;
print $hdatBinfh $chkSum;
foreach my $my_key ( sort keys %toc )
{
    print $hdatBinfh $my_key;
    print $hdatBinfh $toc{$my_key};
}
seek($hdatBinfh,0x1014,0);

my $tmpFile = "./tempFile";
open my $totbinfh , '<', $tmpFile;
binmode($totbinfh);
local $/;
my $buffer = <$totbinfh>;
print $hdatBinfh $buffer;
close $totbinfh;
close $hdatBinfh;

sub validateMaxSize
{
    my $dom = shift;
    my $totSize = 0;
    my $headerSize = 0x1014; #tocsize + checksum size + version size
    foreach my $binFile ( $dom->findnodes('/hdat/section'))
    {
        if (-e $binFile->findvalue('./fileName'))
        {
            say $binFile->findvalue('./fileName');
            $totSize += (stat($binFile->findvalue('./fileName')))->size;
        }
        else
        {
            say $binFile->findvalue('./fileName'), "doesnt exist";
        }
    }
    my $maxsize = hex($dom->findvalue('/hdat/metadata/maxSize'));
    say $maxsize;
    if($maxsize < ($totSize + $headerSize))
    {
        #say $dom->findvalue('/hdat/metaData/maxSize');
        #say ($totSize + $headerSize);
        die  " collective size of binaries is more than max size , $totSize";
    }

}

sub createToc
{
    my $dom = shift;
    my %toc = ();
    my $offset = 0x1014;
    foreach my $binFile ( $dom->findnodes('/hdat/section')){
        if (-e $binFile->findvalue('./fileName'))
        {
            $toc{pack4byte($offset)} = pack4byte((stat($binFile->findvalue('./fileName')))->size);
            $offset += ((stat($binFile->findvalue('./fileName')))->size);
        }
        else
        {
            $toc{pack4byte($offset)} = pack4byte(0);
            $offset += 4;  #its a hash, so bump up by 4 bytes for uniqueness
        }
    }
    return %toc;
}



sub createChecksum
{
    my $dom = shift;
    my $tmpFile = "./tempFile";
    open my $totbinfh , '>', $tmpFile;
    binmode($totbinfh);
    foreach my $section ( $dom->findnodes('/hdat/section')){
        if (-e $section->findvalue('./fileName'))
        {
            local $/;
            open my $sectBinfh, '<', $section->findvalue('./fileName');
            binmode($sectBinfh);
            my $data = <$sectBinfh>;
            print $totbinfh $data;
            close $sectBinfh;
            say $section->findvalue('./fileName');
        }
        else
        {
            print $totbinfh pack4byte(0);  # if the file doesn't exist,fill 4 byte 0's.
            say $section->findvalue('./fileName'), "is empty";
        }
    }
    my @md5= split / /, `md5sum ./tempFile`;
    close $tmpFile;
    say 'checksum is'.$md5[0];
    return $md5[0];
}

