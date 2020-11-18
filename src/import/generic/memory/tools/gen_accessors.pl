#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/generic/memory/tools/gen_accessors.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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

# @file shmoo_2d_plot.pl
# @brief Calls the 2D plotting information
#
# *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
# *HWP HWP Backup : Stephen Glancy <sglancy@us.ibm.com>

# *HWP Team: Memory
# *HWP Level: 2
# *HWP Consumed by: Memory

use strict;
use warnings;

# Gets the directory where the perl script is stored
# This allows the user to use a relative instead of a direct path for the include
my $pwd;

BEGIN
{
    # Some scripts needs the directory the script was called from, save that here
    #This keeps the directory intact.
    my $callingPwd = "";
    chomp( $callingPwd = `cd .;pwd` );

    # Now do the rest
    my @tempArr = split( /\/+/, $0 );
    pop(@tempArr);    # The script name
    my $LIST_SEPARATOR = "/";    # Make it so the array below separates on / instead of space
                                 #If it starts with a ., it's being called with relative path
    if ( substr( $0, 0, 1 ) ne "/" )
    {
        $pwd = $callingPwd;                # Get where I got called from
        $pwd = $pwd . "/" . "@tempArr";    # Now use the relative to find out where the script is
    }
    else
    {                                      # Absolute path
        $pwd = "@tempArr";
    }
    $LIST_SEPARATOR = " ";                 # Reset
    chomp( $pwd = `cd $pwd;pwd` );         # Get to where this script resides
}

use lib "$pwd";
use lib $ENV{PROJECT_ROOT} . "/generic/memory/tools";               # EKB Path
use lib $ENV{PROJECT_ROOT} . "/src/import/generic/memory/tools";    # Hostboot Path

use English;
use Carp qw( croak );
use Getopt::Long;
use gen_accessors qw( get_array_dimensions format_attr_description generate_accessor_methods );

#
# @brief Print help text
#
sub print_help
{
    print(
        "Usage: gen_acessors.pl --system=<system> --output-dir=<output dir> --output-file-prefix=<prefix> <attr-xml-file1> [<attr-xml-file2> ...]\n"
    );
    print("  This perl script will parse attribute XML files and create the following files:\n");
    print("  - <prefix>_attribute_getters.H.       Contains the attribute getters, based on the xml\n");
    print("  - <prefix>_attribute_setters.H.       Contains the attribute setters, based on the xml\n");
    print("  Note that the system argument must be one of the following: NIMBUS, P10\n");
    exit(1);
}

# Print out where we got the plotter module from (useful for debugging)
#print "Using module gen_accessors from: " . $INC{"gen_accessors.pm"} . "\n";

#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $arg_output_dir         = undef;
my $arg_system             = undef;
my $arg_output_file_prefix = undef;

# Get the options from the command line - the rest of @ARGV will
# be filenames
GetOptions(
    "output-dir=s"         => \$arg_output_dir,
    "output-file-prefix=s" => \$arg_output_file_prefix,
    "system=s"             => \$arg_system
);

if (   ( scalar(@ARGV) < 1 )
    || !defined($arg_output_dir)
    || !defined($arg_output_file_prefix)
    || !defined($arg_system) )
{
    print_help();
}

my $system = uc($arg_system);
if ( !grep( /^$system$/, keys( %{ +TARGET_TYPES } ) ) )
{
    print("ERROR: unrecognized --system option: $arg_system\n");
    print_help();
}

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use XML::Simple;
my $xml = new XML::Simple( KeyAttr => [] );

# Uncomment to enable debug output
use Data::Dumper;

#------------------------------------------------------------------------------
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
#------------------------------------------------------------------------------
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $getters_string = "";
my $setters_string = "";

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $infile (@ARGV)
{
    # Hashes to keep track of the methods for the classes
    my %getter_methods = ();
    my %setter_methods = ();

    # read XML file. The ForceArray option ensures that there is an array of
    # elements even if there is only one such element in the file
    my $attributes =
        $xml->XMLin( $infile, ForceArray => [ 'attribute', 'chip' ], SuppressEmpty => undef, NormaliseSpace => 2 );

    #--------------------------------------------------------------------------
    # For each Attribute
    #--------------------------------------------------------------------------

    foreach my $attr ( @{ $attributes->{attribute} } )
    {
        my $arrayDimensions = "";
        my @arrayDims       = ();

        # Only create functions for attributes that have an accessor name
        # This avoids creating functions for attributes we don't use
        if ( !$attr->{mssAccessorName} )
        {
            next;
        }

        # If we have an array, lets do a little up front work to disect it
        my $array_dimensions = get_array_dimensions( $attr, \@arrayDims );

        # Make the description something nice we can use.
        format_attr_description($attr);

        # Write accessors for things which are tied to the MEM_PORT or the OCMB_CHIP
        generate_accessor_methods( $system, $attr, \@arrayDims, $array_dimensions, \%getter_methods, \%setter_methods );
    }    #end foreach attr

    foreach my $method ( sort keys %getter_methods )
    {
        $getters_string .= "$getter_methods{$method}\n";
    }

    foreach my $method ( sort keys %setter_methods )
    {
        $setters_string .= "$setter_methods{$method}\n";
    }

}    #end foreach xml

# Finally, print out the header file(s)
if ( $getters_string ne "" )
{
    my $file_string      = generate_header_file( GETTERS, $arg_output_dir, $arg_output_file_prefix, $getters_string );
    my $header_file_name = $arg_output_file_prefix . "_attribute_getters.H";
    my $header_file      = $arg_output_dir . "/" . $header_file_name;

    open( my $fh, ">", $header_file ) || croak "Could not open attribute getter header file for writing: $header_file";
    print {$fh} $file_string;
    close($fh);
}

if ( $setters_string ne "" )
{
    my $file_string      = generate_header_file( SETTERS, $arg_output_dir, $arg_output_file_prefix, $setters_string );
    my $header_file_name = $arg_output_file_prefix . "_attribute_setters.H";
    my $header_file      = $arg_output_dir . "/" . $header_file_name;

    open( my $fh, ">", $header_file ) || croak "Could not open attribute setter header file for writing: $header_file";
    print {$fh} $file_string;
    close($fh);
}
