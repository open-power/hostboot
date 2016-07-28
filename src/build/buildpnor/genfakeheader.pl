#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/genfakeheader.pl $
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
use Getopt::Long;
use Pod::Usage;
use 5.010;
use constant HEADER_SIZE => 4096;

my $outputFile = "";
my $payloadTextHash = "";
my $payloadTextSize=0;
my $payloadDataSize=0;
my $help=0;
my $man=0;

GetOptions(
    "output-file=s" => \$outputFile,
    "payload-text-hash=s" => \$payloadTextHash,
    "payload-text-size=s" => \$payloadTextSize,
    "payload-data-size=s" => \$payloadDataSize,
    "help" => \$help,
    "man" => \$man) || pod2usage(-verbose=>0);

pod2usage(-verbose => 1) if $help;
pod2usage(-verbose => 2) if $man;

if(   (length($payloadTextHash) != 128)
   || ($payloadTextHash =~ /[^a-fA-F0-9]/ ))
{
    print STDERR "\nERROR: --payload-text-hash must "
        . "be 64 ASCII hex bytes.  Example: --payload-text-hash="
        . "e41110deec6c3bd7914bf792a2e51b0c8eaebe8d30f9360324598"
        . "1b32106a13beafb6cdddd36e48947d35723d166ac08f0be93d2c6"
        . "8e2640b539952e6fe819c6\n\n";
    pod2usage(-verbose=>1);
}

if($payloadTextSize == 0)
{
    print STDERR "\nERROR: --payload-text-size must be non-zero\n";
    pod2usage(-verbose=>1);
}

if($outputFile eq "")
{
    print STDERR "\nERROR: --output-file must not be empty\n";
    pod2usage(-verbose=>1);
}

sub pack8byte {
    my($value) = @_;
    return pack("NN" , (($value >> 32) & 0xFFFFFFFF),
                               ($value & 0xFFFFFFFF));
}

sub pack4byte {
    my($value) = @_;
    return pack("N",$value);
}

sub pack2byte {
    my($value) = @_;
    return pack("n",$value);
}

sub pack1byte {
    my($value) = @_;
    return pack("C",$value);
}

sub createFakeHeader {

    my ($containerSize,$hrmor,
        $stack,$textSize,$textHash) = @_;

    # Array of [ field size (bytes), field value ] pairs
    my @sizeValAoA = (
        [4,0x17082011],     # Magic number
        [2,1],              # Container version
        [8,$containerSize], # Container size
        [8,$hrmor],         # HRMOR
        [8,$stack],         # Stack address
        [132*3,0],          # 3xHW public keys
        [2,1],              # Header version
        [1,1],              # Hash algo
        [1,1],              # Sign algo
        [8,0],              # Unused
        [8,0],              # Reserved
        [4,0],              # Flags
        [1,1],              # SW key count
        [8,132],            # Size of SW key payload
        [64,0],             # Hash of SW key payload
        [1,0],              # ECID count
                            # ECID array (empty)
        [132*3,0],          # 3xHW signatures
        [132,0],            # SW key payload
        [2,1],              # SW header version
        [1,1],              # Hash algo version
        [1,0],              # Unused
        [8,0],              # Code start offset
        [8,0],              # Reserved
        [4,0],              # Flags
        [1,0],              # Reserved
        [8,$textSize],      # Size of protected payload
        [64,$textHash],     # Hash of protected payload
        [1,0]               # ECID count
                            # ECID array (empty)
                            # Padding to 4k boundary
        );

    my %types;
    $types{1} = \&pack1byte;
    $types{2} = \&pack2byte;
    $types{4} = \&pack4byte;
    $types{8} = \&pack8byte;

    my $data;
    foreach my $i (0 .. $#sizeValAoA)
    {
        my $size = $sizeValAoA[$i][0];
        my $val = $sizeValAoA[$i][1];
        if(exists $types{$size})
        {
            $data .= $types{$size}->($val);
        }
        elsif($val eq "0")
        {
            $data .= pack ("@".$size);
        }
        else
        {
            $data .= pack ("H*",$val);
        }
    }
    my $len = length($data);
    my $pads = HEADER_SIZE-$len;
    $data .= pack ("@".$pads);
    return $data;
}

open(OUTFILE, "> $outputFile")
    or die "Can't open > $outputFile for writing: $!";

my $containerSize=  HEADER_SIZE
                  + $payloadTextSize + $payloadDataSize;
my $data = createFakeHeader (
    $containerSize,0,0,$payloadTextSize, $payloadTextHash ) ;

print OUTFILE $data;

close(OUTFILE)
    or die "Can't close $outputFile: $!";

__END__

=head1 NAME

genfakeheader.pl

=head1 SYNOPSIS

genfakeheader.pl
    --output-file=HEADER_FILE
    --payload-text-hash=TEXT_HASH
    --payload-text-size=TEXT_SIZE
    [--payload-data-size=DATA_SIZE]

=head1 OPTIONS

=over 8

=item B<--help>

Prints a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--payload-text-hash>=HASH

sha512 hash of the protected payload.  Must be 64 ASCII hex bytes.

=item B<--payload-text-size>=SIZE

Size of protected payload, in bytes.

=item B<--payload-data-size>=SIZE

Size of the unprotected payload, in bytes.

=back

=head1 DESCRIPTION

B<genfakeheader.pl> will generate a fake secureboot header
in order to allow unsigned code to work when security is disabled.

=cut
