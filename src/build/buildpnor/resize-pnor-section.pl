#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/resize-pnor-section.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017
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
use Getopt::Long qw(:config pass_through);
use Pod::Usage;
use Data::Dumper;
use PnorUtils qw(loadPnorLayout findLayoutKeyByEyeCatch checkFile displayPnorLayout);

my $help = 0;
my $man = 0;
my %globals = ();

## HANDLE INPUTS

GetOptions(
    "pnor-layout=s" => \$globals{pnorLayoutFile},
    "section=s" => \$globals{modifySection},
    "size=s" => \$globals{modifySectionSize},
    "help" => \$help,
    "man" => \$man) || pod2usage(-verbose=>0);

pod2usage(-verbose => 1) if $help;
pod2usage(-verbose => 2) if $man;

## MAIN

verify_inputs();
modify_xml();

## FUNCTIONS

sub modify_xml
{
    my %pnorLayout = ();
    my %PhysicalOffsets = ();

    my $rc = loadPnorLayout($globals{pnorLayoutFile}, \%pnorLayout, \%PhysicalOffsets);
    die "Error detected from call to loadPnorLayout()" if($rc);

    my $section_phys_offset = findLayoutKeyByEyeCatch($globals{modifySection},
                                                      \%pnorLayout);

    my $size_diff = $globals{modifySectionSize} - $pnorLayout{sections}{$section_phys_offset}{physicalRegionSize};
    if ($size_diff <= 0)
    {
        print "Size the same or smaller than current size, no action needed\n";
        exit;
    }

    print "Before Modification:\n";
    displayPnorLayout(\%pnorLayout);

    my $endOffset = 0;
    # Iterate through all sections of PNOR, including TOC's
    foreach my $section (sort {$a <=> $b} keys %{$pnorLayout{sections}})
    {
        my $secOffset = $pnorLayout{sections}{$section}{physicalOffset};
        my $secSize = $pnorLayout{sections}{$section}{physicalRegionSize};

        # Skip sections unaffected by size change
        if ( $secOffset < $section_phys_offset )
        {
            next;
        }

        # Enter modified size for specified section
        if ( $secOffset == $section_phys_offset )
        {
            $secSize = $globals{modifySectionSize};
        }
        # Shift physical offset of following sections in pnor layout if the size
        # diff affects the offset
        elsif ($secOffset < $endOffset)
        {
            $secOffset += $size_diff;
        }


         $pnorLayout{sections}{$section}{physicalRegionSize} = $secSize;
         $pnorLayout{sections}{$section}{physicalOffset} = $secOffset;
         $endOffset = $secOffset + $secSize;
    }

    if ($endOffset > $pnorLayout{metadata}{imageSize})
    {
        print STDERR "\nModification does not fit in current PNOR size of $pnorLayout{metadata}{imageSize}\n";
        die;
    }

    print "\n========================================================\n\n";
    print "After Modification:\n";
    displayPnorLayout(\%pnorLayout);

}

sub verify_inputs
{
    if( checkFile($globals{pnorLayoutFile}) )
    {
        print STDERR "Pnor layout file DNE or not XML=> $globals{pnorLayoutFile}\n\n";
        pod2usage(-verbose=>1);
    }

    if( $globals{modifySection} eq "" )
    {
        print STDERR "Pnor section not specified\n\n";
        pod2usage(-verbose=>1);
    }

    if( $globals{modifySectionSize} !~ /^0x[0-9a-fA-F]+$/ )
    {
        print STDERR "New pnor section size not a hex number\n\n";
        pod2usage(-verbose=>1);
    }
    # Convert hex string to decimal number
    $globals{modifySectionSize} = hex($globals{modifySectionSize});
}

__END__

=head1 NAME

resize-pnor-section.pl

=head1 SYNOPSIS

resize-pnor-section.pl
    --pnor-layout=PNOR_XML_FILE
    --section=PNOR_SECTION_TO_MODIFY
    --size=NEW_PNOR_SECTION_SIZE[0x HEX prefix]

=head1 OPTIONS

=over 8

=item B<--help>

Prints a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=back

=head1 DESCRIPTION

B<resize-pnor-section> will determine if a modification to a pnor section's size
is feasible and prints the resulting offsets and sizes of all sections

=cut
