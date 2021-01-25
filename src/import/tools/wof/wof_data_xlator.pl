#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/tools/wof/wof_data_xlator.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2021
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
################################################################################
#
# Purpose
# -------
# This script creates a WOF Tables Image File based on one or more input CSV
# files.  Each CSV file contains all the VRTs for one SPWBF (Socket Power and
# WOF Base Frequency) combination.
#
# The script also provides the following utility functions:
#   * List contents of a WOF Tables Image File (top level headers)
#   * View contents of one VRT within a WOF Tables Image File
#   * Extract one set of WOF Tables from an Image File
#
# Related Documentation
# ---------------------
# * "WOF Tables Image Tool":  Defines the command line interface, CSV file
#   format, and several binary data structures such as the Image Header.
#
# * "POWER Energy Management Hcode/HWP Specification":  Defines the format of
#   the VRT as well as most of the binary data structures such as the
#   WOF Tables Header.
#
# Implementation Notes
# --------------------
# * Object-oriented PERL features are used to simplify the implementation.
#   Major elements of the domain, such as a CSV file or WOF Tables Image File,
#   are represented as classes with data members and methods.
#
# * Class data members SHOULD NOT be directly accessed (as hash elements) by
#   code OUTSIDE of the class implementation.  Direct access breaks
#   encapsulation, complicates interfaces, and can lead to quality issues.
#
# * Class data members SHOULD be directly accessed (as hash elements) by code
#   INSIDE the class implementation.  Performance is 5-10 times better.
#
# * The OO PERL convention of naming 'private' class methods with a leading
#   underscore is used (e.g. _foo_bar).  'Private' class methods are those that
#   should not be called outside the class implementation.
#
# * The OO PERL convention of combining get/set methods is used for writable
#   data members.  The methods provide an optional parameter that, when
#   specified, provides the new value for the data member.
#
################################################################################
################################################################################
# Imports
################################################################################
use strict;    # Enable strict error checking
################################################################################
#
# Global Variables and Subroutines
#
################################################################################
# variables below used for both ImageFile and Options Packages
my $G_ATTR_vcs_ceff_index   = 'vcs_ceff_index';
my $G_ATTR_vdd_ceff_index   = 'vdd_ceff_index';
my $G_ATTR_io_power_index   = 'io_power_index';
my $G_ATTR_amb_cond_index   = 'amb_cond_index';
my $G_ATTR_vratio_index     = 'vratio_index';
my $G_ATTR_disp_axis_vcs    = 'vcs';
my $G_ATTR_disp_axis_vdd    = 'vdd';
my $G_ATTR_disp_axis_amb    = 'amb';
my $G_ATTR_disp_axis_io     = 'io';
my $G_ATTR_disp_axis_vratio = 'vratio';

my $G_DEF_IO_POWER_SIZE = 6;
my $G_DEF_VCS_CEFF_SIZE = 4;
my $G_DEF_VDD_CEFF_SIZE = 26;
my $G_DEF_AMB_COND_SIZE = 4;

my $g_io_power_size;
my $g_vcs_ceff_size;
my $g_vdd_ceff_size;
my $g_amb_cond_size;

my $G_MIN_FREQ_ENCODE = 108;
my $G_MAX_FREQ_ENCODE = 255;
my $G_MIN_OVRG_ENCODE = 1;
my $G_MAX_OVRG_ENCODE = 107;    # This value is: $G_MIN_FREQ_ENCODE - 1;

my $G_MAX_READ_SIZE = 4096;
################################################################################
#
# Internal global variables
# Variables used across different functions. The user should not modify these variable values.
# These Internal global veriables similar to static variables in C language.
#
################################################################################
# Log Package
#
# This package contains utility subroutines for logging.
# these are global subroutines. As a resultthere is no need to use
# the domain name.
################################################################################
package Log;

# constants for logging levels.
my $LOG_LVL_0 = 0;    # info.
my $LOG_LVL_1 = 1;    # debugging.
my $LOG_LVL_2 = 2;    # warning.
my $LOG_LVL_3 = 3;    # error.
my $LOG_LVL_4 = 4;    # critical.
my $LOG_LVL_5 = 5;    # no print.

# It defines the the level above (or equal to) which can be printed.
# The user can change this level.
# If you don't want to print anything, change it to  $LOG_LVL_5,
my $g_log_lvl_target = $LOG_LVL_1;

# Global Logging level compared to logging level in package scope.
my $g_log_lvl = $LOG_LVL_0;

# switch to use scopes of logging:
#   1 - to use global logging level.
#   0 - to use logging level in package scope.
my $g_use_global_log_lvl = 0;
#
# Subroutine section
#
#
# log_print() subroutine
# prints on display with debug level.
#
sub log_print
{
    my $argc = scalar @_;
    if ( $argc < 2 )
    {
        return;
    }
    my $log_lvl = $_[0];

    # print out logging message to debug this subroutine. comment out when not debugging
    #    print "log_lvl: $log_lvl.\n";
    #    print "g_log_lvl: $g_log_lvl_target.\n";
    # also check if it is required to print.
    if ( ( $log_lvl < $g_log_lvl_target ) or ( $log_lvl >= $LOG_LVL_5 ) )
    {
        return;
    }
    my @array = @_;
    shift @array;
    if ( $argc == 2 )
    {
        print(@array);
    }
    else
    {
        printf(@array);
    }
}
#
# log_fprint() subroutine
# write to file with debug level.
#
sub log_fprint
{
    my $argc = scalar @_;
    if ( $argc < 3 )
    {
        return;
    }
    my $log_lvl = $_[0];

    # print out logging message to debug this subroutine. comment out when not debugging
    #    print "log_lvl: $log_lvl.\n";
    #    print "g_log_lvl: $g_log_lvl_target.\n";
    # also check if it is required to print.
    if ( ( $log_lvl < $g_log_lvl_target ) || ( $log_lvl >= $LOG_LVL_5 ) )
    {
        return;
    }
    my $fh    = $_[1];
    my @array = @_;
    shift @array;
    shift @array;
    if ( $argc == 3 )
    {
        print( $fh, @array );
    }
    else
    {
        printf( $fh, @array );
    }
}
################################################################################
# Util Package
#
# This package contains utility subroutines used by one or more classes.
################################################################################
package Util;

sub round
{
    my ($value)        = @_;
    my $integer_value  = int($value);
    my $fraction_value = $value - $integer_value;
    my $rounded_value  = $integer_value;
    if ( $fraction_value >= 0.5 )
    {
        $rounded_value++;
    }
    return $rounded_value;
}

sub ceil
{
    my ($value)        = @_;
    my $integer_value  = int($value);
    my $fraction_value = $value - $integer_value;
    my $ceiled_value   = $integer_value;
    if ( $fraction_value > 0.0 )
    {
        $ceiled_value++;
    }
    return $ceiled_value;
}
################################################################################
# VRT Class
#
# This class represents one VRT within a CSV file.
################################################################################
package VRT;
our $p_log_lvl = $LOG_LVL_0;

# Number of columns in a VRT
our $VRT_COLUMN_COUNT = 12;

# Attribute names in this class
our $VRT_ATTR_vcs_ceff_index         = 'vcs_ceff_index';
our $VRT_ATTR_vdd_ceff_index         = 'vdd_ceff_index';
our $VRT_ATTR_io_power_index         = 'io_power_index';
our $VRT_ATTR_amb_cond_index         = 'amb_cond_index';
our $VRT_ATTR_wof_freqs              = 'wof_freqs';
our $VRT_ATTR_wof_ceff_ratio_overage = 'wof_ceff_overage';

sub new
{
    my ( $class, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index ) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $VRT_ATTR_vcs_ceff_index         => $vcs_ceff_index,
        $VRT_ATTR_vdd_ceff_index         => $vdd_ceff_index,
        $VRT_ATTR_io_power_index         => $io_power_index,
        $VRT_ATTR_amb_cond_index         => $amb_cond_index,
        $VRT_ATTR_wof_freqs              => [],
        $VRT_ATTR_wof_ceff_ratio_overage => [],
    };

    # Build one-dimensional array to hold WOF frequency values.
    for ( my $col_index = 0; $col_index < $VRT_COLUMN_COUNT; $col_index++ )
    {
        $self->{$VRT_ATTR_wof_freqs}[$col_index] = undef;
    }

    # Build one-dimensional array to hold WOF ceff ratio overage.
    for ( my $col_index = 0; $col_index < $VRT_COLUMN_COUNT; $col_index++ )
    {
        $self->{$VRT_ATTR_wof_ceff_ratio_overage}[$col_index] = undef;
    }
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub wof_freq
{
    my ( $self, $vratio_index, $new_value ) = @_;
    if ( defined($new_value) )
    {
        $self->{$VRT_ATTR_wof_freqs}[$vratio_index] = $new_value;
    }
    return $self->{$VRT_ATTR_wof_freqs}[$vratio_index];
}

sub wof_ceff_ratio_overage
{
    my ( $self, $vratio_index, $new_value ) = @_;
    if ( defined($new_value) )
    {
        $self->{$VRT_ATTR_wof_ceff_ratio_overage}[$vratio_index] = $new_value;
    }
    return $self->{$VRT_ATTR_wof_ceff_ratio_overage}[$vratio_index];
}

sub is_complete
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "is_complete():\n";

    # Check whether all WOF frequency values have been defined
    for ( my $col_index = 0; $col_index < $VRT_COLUMN_COUNT; $col_index++ )
    {
        if ( !defined( $self->{$VRT_ATTR_wof_freqs}[$col_index] ) )
        {
            return 0;
        }
        if ( !defined( $self->{$VRT_ATTR_wof_ceff_ratio_overage}[$col_index] ) )
        {
            return 0;
        }
    }
    return 1;
}

################################################################################
# CSVFile Class
#
# This class represents one CSV file containing all the VRTs for one
# SPWBF (Socket Power and WOF Base Frequency) combination.
#
# The CSV file format is described in detail by the documentation referenced at
# the beginning of this script.
#
# The first row of the CSV file must contain the list of column names.  The
# columns must appear in the specified order within the CSV file.  The column
# names are not case-sensitive.
#
# Each row following the first contains one entry (WOF frequency) in one VRT.
# There is no requirement on the order of the rows in the CSV file.  For
# example, the rows representing one VRT are not required to be adjacent.
#
# This class is very performance-sensitive.  Most of the execution time of this
# script is spent within this class.  Small changes to this class can have large
# performance impacts.  This is due to the large amount of data it parses.  One
# CSV file contains over a 120,000 rows.
################################################################################
package CSVFile;
use IO::File;
our $p_log_lvl = $LOG_LVL_0;

# Number of vcs_ceff_index values
our $csv_vcs_ceff_index_count;

# Number of vdd_ceff_index values
our $csv_vdd_ceff_index_count;

# Number of amb_cond_index values
our $csv_io_power_index_count;

# Number of amb_cond_index values
our $csv_amb_cond_index_count;

# Number ofvratio_index values
our $csv_vratio_index_count = 12;

# Number of columns in the CSV file
our $CSV_COLUMN_COUNT;

# Columns we want to store that have file scope (all rows have same value)
our @CSV_FILE_SCOPE_COLUMN_INDEXES;

# Columns in the CSV file.  Index value is important, but case is not.
# This contains the latest CSV version of columns
my %CSV_COLUMN_NAME_TO_INDEX;

# Look up column name via index number
# will be set to reverse %CSV_COLUMN_NAME_TO_INDEX;
our %CSV_COLUMN_INDEX_TO_NAME;

# Attribute names in this class
our $CSV_ATTR_file_name                 = 'file_name';
our $CSV_ATTR_sort                      = 'sort';
our $CSV_ATTR_vrts                      = 'vrts';
our $CSV_ATTR_package                   = 'package';
our $CSV_ATTR_table_version             = 'table_version';
our $CSV_ATTR_table_date                = 'table_date';
our $CSV_ATTR_PN                        = 'PN';
our $CSV_ATTR_ocs_mode                  = 'ocs_mode';
our $CSV_ATTR_socket_power              = 'socket_power';
our $CSV_ATTR_rdp_current               = 'rdp_current';
our $CSV_ATTR_boost_current             = 'boost_current';
our $CSV_ATTR_tdp_vcs_ceff_index        = 'tdp_vcs_ceff_index';
our $CSV_ATTR_tdp_vdd_ceff_index        = 'tdp_vdd_ceff_index';
our $CSV_ATTR_tdp_io_power_index        = 'tdp_io_power_index';
our $CSV_ATTR_tdp_amb_cond_index        = 'tdp_amb_cond_index';
our $CSV_ATTR_io_full_power             = 'io_full_power';
our $CSV_ATTR_io_disabled_power         = 'io_disabled_power';
our $CSV_ATTR_core_count                = 'core_count';
our $CSV_ATTR_pdv_sort_power_save_freq  = 'pdv_sort_power_save_freq';
our $CSV_ATTR_pdv_sort_wof_base_freq    = 'pdv_sort_wof_base_freq';
our $CSV_ATTR_pdv_sort_ultra_turbo_freq = 'pdv_sort_ultra_turbo_freq';
our $CSV_ATTR_pdv_sort_throttle_freq    = 'pdv_sort_throttle_freq';
our $CSV_ATTR_vdd_ceff_start            = 'vdd_ceff_start';
our $CSV_ATTR_vdd_ceff_step             = 'vdd_ceff_step';
our $CSV_ATTR_vcs_ceff_start            = 'vcs_ceff_start';
our $CSV_ATTR_vcs_ceff_step             = 'vcs_ceff_step';
our $CSV_ATTR_io_power_start            = 'io_power_start';
our $CSV_ATTR_io_power_step             = 'io_power_step';
our $CSV_ATTR_amb_cond_start            = 'amb_cond_start';
our $CSV_ATTR_amb_cond_step             = 'amb_cond_step';
our $CSV_ATTR_vratio_start              = 'vratio_start';
our $CSV_ATTR_vratio_step               = 'vratio_step';
our $CSV_ATTR_vdd_ceff                  = 'vdd_ceff';
our $CSV_ATTR_vdd_ceff_index            = 'vdd_ceff_index';
our $CSV_ATTR_vcs_ceff                  = 'vcs_ceff';
our $CSV_ATTR_vcs_ceff_index            = 'vcs_ceff_index';
our $CSV_ATTR_io_power                  = 'io_power';
our $CSV_ATTR_io_power_index            = 'io_power_index';
our $CSV_ATTR_amb_cond                  = 'amb_cond';
our $CSV_ATTR_amb_cond_index            = 'amb_cond_index';
our $CSV_ATTR_vratio                    = 'vratio';
our $CSV_ATTR_vratio_index              = 'vratio_index';
our $CSV_ATTR_wof_freq                  = 'wof_freq';
our $CSV_ATTR_wof_ceff_ratio_overage    = 'wof_ceff_ratio_overage';
our $CSV_ATTR_override_match_freq       = 'override_match_freq';
our $CSV_ATTR_override_match_power      = 'override_match_power';
our $CSV_ATTR_pdv_sort_fixed_freq       = 'pdv_sort_fixed_freq';

# columns of csv file scope in csv files.
our @CSV_FILE_SCOPE_COLUMN_NAMES = (
    $CSV_ATTR_sort,                     $CSV_ATTR_package,                   $CSV_ATTR_table_version,
    $CSV_ATTR_table_date,               $CSV_ATTR_PN,                        $CSV_ATTR_ocs_mode,
    $CSV_ATTR_socket_power,             $CSV_ATTR_rdp_current,               $CSV_ATTR_boost_current,
    $CSV_ATTR_tdp_vcs_ceff_index,       $CSV_ATTR_tdp_vdd_ceff_index,        $CSV_ATTR_tdp_io_power_index,
    $CSV_ATTR_tdp_amb_cond_index,       $CSV_ATTR_io_full_power,             $CSV_ATTR_io_disabled_power,
    $CSV_ATTR_core_count,               $CSV_ATTR_pdv_sort_ultra_turbo_freq, $CSV_ATTR_pdv_sort_throttle_freq,
    $CSV_ATTR_pdv_sort_power_save_freq, $CSV_ATTR_pdv_sort_wof_base_freq,    $CSV_ATTR_vdd_ceff_start,
    $CSV_ATTR_vdd_ceff_step,            $CSV_ATTR_vcs_ceff_start,            $CSV_ATTR_vcs_ceff_step,
    $CSV_ATTR_io_power_start,           $CSV_ATTR_io_power_step,             $CSV_ATTR_amb_cond_start,
    $CSV_ATTR_amb_cond_step,            $CSV_ATTR_vratio_start,              $CSV_ATTR_vratio_step,
    $CSV_ATTR_override_match_freq,      $CSV_ATTR_override_match_power,      $CSV_ATTR_pdv_sort_fixed_freq,
);

# columns of csv vrt scope in csv files.
# accourding the requirement doc, the followings are for debug purpose and not processed
# by this program:
# CSV_ATTR_vdd_ceff
# CSV_ATTR_vcs_ceff
# CSV_ATTR_io_power
# CSV_ATTR_amb_cond
# CSV_ATTR_vratio
our @CSV_VRT_SCOPE_COLUMN_NAMES = (
    $CSV_ATTR_vdd_ceff, $CSV_ATTR_vdd_ceff_index, $CSV_ATTR_vcs_ceff, $CSV_ATTR_vcs_ceff_index,
    $CSV_ATTR_io_power, $CSV_ATTR_io_power_index, $CSV_ATTR_amb_cond, $CSV_ATTR_amb_cond_index,
    $CSV_ATTR_vratio,   $CSV_ATTR_vratio_index,   $CSV_ATTR_wof_freq, $CSV_ATTR_wof_ceff_ratio_overage,
);

# Columns in csv file that will be processed in this tool
our @CSV_COLUMN_NAMES = ( @CSV_FILE_SCOPE_COLUMN_NAMES, @CSV_VRT_SCOPE_COLUMN_NAMES );

# Columns in csv file that could be skipped in the file.
# If the columns can be skipped, they must be included in the table here.
my %CSV_FILE_SCOPE_COLUMN_NOT_FOUND_DEFAULT_VALUES = (
    $CSV_ATTR_override_match_freq  => 0,
    $CSV_ATTR_override_match_power => 0,
    $CSV_ATTR_pdv_sort_fixed_freq  => 0,
);

# If the column is really skipped in CSV file, but in teh table above, added to this array.
our @CSV_FILE_SCOPE_COLUMN_NOT_FOUND;

sub new
{
    my ( $class, $file_name ) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $CSV_ATTR_file_name => $file_name,
        $CSV_ATTR_vrts      => [],
    };

    # Set hash %self of remaining columns with undef value.
    foreach my $column (@CSV_COLUMN_NAMES)
    {
        $self->{$column} = undef;
    }

    # set index counts from global variable read from command options
    # || from default values.
    $csv_vcs_ceff_index_count = $g_vcs_ceff_size;
    $csv_vdd_ceff_index_count = $g_vdd_ceff_size;
    $csv_io_power_index_count = $g_io_power_size;
    $csv_amb_cond_index_count = $g_amb_cond_size;

    # Build four-dimensional array to hold VRTs. The dimensions include
    # vcs_ceff_index, vdd_ceff_index, io_power_index, and amb_cond_index.
    for ( my $vcs_idx = 0; $vcs_idx < $csv_vcs_ceff_index_count; $vcs_idx++ )
    {
        $self->{$CSV_ATTR_vrts}[$vcs_idx] = [];
        for ( my $vdd_idx = 0; $vdd_idx < $csv_vdd_ceff_index_count; $vdd_idx++ )
        {
            $self->{$CSV_ATTR_vrts}[$vcs_idx][$vdd_idx] = [];
            for ( my $io_power_idx = 0; $io_power_idx < $csv_io_power_index_count; $io_power_idx++ )
            {
                $self->{$CSV_ATTR_vrts}[$vcs_idx][$vdd_idx][$io_power_idx] = [];
                for ( my $amb_cond_idx = 0; $amb_cond_idx < $csv_amb_cond_index_count; $amb_cond_idx++ )
                {
                    $self->{$CSV_ATTR_vrts}[$vcs_idx][$vdd_idx][$io_power_idx][$amb_cond_idx] = undef;
                }
            }
        }
    }
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
    }
    return $self->{$attr_name};
}

sub vrt
{
    my ( $self, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index ) = @_;
    return $self->{$CSV_ATTR_vrts}[$vcs_ceff_index][$vdd_ceff_index][$io_power_index][$amb_cond_index];
}

sub parse
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "parse():\n";

    # Open the CSV file
    my $csv_file = IO::File->new();
    Log::log_print $LOG_LVL_3, "  Processing, " . $self->access($CSV_ATTR_file_name) . ".\n";
    if ( !( $csv_file->open( $self->access($CSV_ATTR_file_name), 'r' ) ) )
    {
        die "Error: Unable to open file " . $self->access($CSV_ATTR_file_name) . ": $!.\n";
    }

    # Clear the column not found array for the new file
    @CSV_FILE_SCOPE_COLUMN_NOT_FOUND = ();

    # Parse rows in the CSV file
    my $row;
    my $row_number = 1;    # starting row index is 1.
    my @columns;
    while ( defined( $row = $csv_file->getline() ) )
    {
        #    Log::log_print $p_log_lvl, "row: $row.\n";
        Log::log_print $p_log_lvl, "row_number: $row_number.\n";

        # Parse the row, resulting in an array of column values
        $self->_parse_row( $row, $row_number, \@columns );
        if ( $row_number == 1 )
        {
            # Row#1 only contains column names.
            # Column header row. Extract values and indexes of columns in the row.
            $self->_extract_column_names_indexes( \@columns );
        }
        elsif ( $row_number == 2 )
        {
            # From Row#2, contains column values. But for file scope columns, all values are the same.
            # But
            # Data row.  Store the column values in our data structure.

            # Verify and store column values that have file scope
            $self->_store_file_scope_columns( $row_number, \@columns );

            # Save VRT scope values.
            # Verify and store column values that are scoped to a specific VRT entry
            $self->_store_vrt_scope_columns( $row_number, \@columns );
        }
        else
        {
            # Save VRT scope values.
            # Verify and store column values that are scoped to a specific VRT entry
            $self->_store_vrt_scope_columns( $row_number, \@columns );
        }
        $row_number++;
    }

    # Verify the data we stored in our data structure
    $self->_verify_stored_vrt_data();

    # Close the CSV file
    if ( !( $csv_file->close() ) )
    {
        die "Error: Unable to close file " . $self->access($CSV_ATTR_file_name) . ": $!.\n";
    }
}

#------------------------------------------------------------------------------
# Private methods
#------------------------------------------------------------------------------
sub _parse_row
{
    my ( $self, $row, $row_number, $columns ) = @_;
    Log::log_print $p_log_lvl, "_parse_row():\n";

    #  Log::log_print $p_log_lvl, "  row: $row.\n";
    Log::log_print $p_log_lvl, "  row_number: $row_number.\n";

    #  Log::log_print $p_log_lvl, "  columns: $columns.\n";
    # Clear columns array
    @$columns = ();

    # While row has more columns
    while ( $row !~ /^\s*$/ )
    {
        # If row starts with a simple column without double quotes
        if ( $row =~ /^(([^,"\v]*)(?:,|\v|$))/ )
        {
            # Match #1 contains column value with comma.  Delete it from row.
            $row = substr( $row, length($1) );

            # Match #2 contains column value without the comma.  Add to column array.
            push( @$columns, $2 );
        }
        elsif ( $row =~ /^("((?:[^"]|"")*)"(?:,|\v|$))/ )
        {
            # Complex column found with double quotes.  May contain commas or nested
            # double quotes.
            # Match #1 contains column value with outer comma and outer double quotes.
            # Delete it from row.
            $row = substr( $row, length($1) );

            # Match #2 has column value without outer comma or outer double quotes.
            # However it may contain nested commas and double quotes.  Nested double
            # quotes are represented as two consecutive double quotes.  Convert them
            # to one double quote.  Then add column value to array.
            my $column_value = $2;
            $column_value =~ s/""/"/g;
            push( @$columns, $column_value );
        }
        else
        {
            die "Error: Unable to parse row $row_number of file " . $self->access($CSV_ATTR_file_name) . ".\n";
        }
    }
}

sub _extract_column_names_indexes
{
    my ( $self, $columns ) = @_;
    Log::log_print $p_log_lvl, "_extract_column_names():\n";

    #  Log::log_print $p_log_lvl, "  columns: $columns.\n";
    if ( scalar @$columns == 0 )
    {
        die "Error: the array lenth of columns is zero.";
    }
    $CSV_COLUMN_COUNT = scalar @CSV_COLUMN_NAMES;

    # populate the $CSV_COLUMN_NAME_TO_INDEX table.
    # outer loop, iterate through array @CSV_COLUMN_NAMES.
    foreach my $column_name (@CSV_COLUMN_NAMES)
    {
        # inner loop, iterate through array @$columns.
        for ( my $indx = 0; $indx < scalar @$columns; ++$indx )
        {
            if ( uc( @$columns[$indx] ) eq uc($column_name) )
            {
                # Found it! will exit from the inner loop.
                Log::log_print $LOG_LVL_0, "  $column_name: $column_name.\n";
                $CSV_COLUMN_NAME_TO_INDEX{$column_name} = $indx;
                last;
            }
        }
    }

    # populate the @CSV_FILE_SCOPE_COLUMN_NOT_FOUND table.
    # outer loop, iterate through array @CSV_COLUMN_NAMES.
    foreach my $column_name (@CSV_COLUMN_NAMES)
    {
        # Check if the column is in csv column default value table.
        if ( !exists( $CSV_COLUMN_NAME_TO_INDEX{$column_name} ) )
        {
            Log::log_print $LOG_LVL_0, "  Not exist column_name: $column_name.\n";

            # the column in @CSV_COLUMN_NAMES table, but the column not exist in the CSV file.
            # check if it is in not found table.
            if ( exists( $CSV_FILE_SCOPE_COLUMN_NOT_FOUND_DEFAULT_VALUES{$column_name} ) )
            {
                # it is in the not found table, so it is expected.
                push( @CSV_FILE_SCOPE_COLUMN_NOT_FOUND, $column_name );
            }
            else
            {
                # it is not in the not found table. so it is not expected.
                die "Error: CSV file "
                    . $self->access($CSV_ATTR_file_name)
                    . " columns do not include column: "
                    . $column_name;
            }
        }
    }

    if (scalar @CSV_COLUMN_NAMES != ( ( keys %CSV_COLUMN_NAME_TO_INDEX ) + ( keys @CSV_FILE_SCOPE_COLUMN_NOT_FOUND ) ) )
    {
        my $output =
              "Error: the number of required columns in CSV file "
            . $self->access($CSV_ATTR_file_name)
            . " is different from the number set in the program. ";
        $output = $output . " number of columns: " . scalar @CSV_COLUMN_NAMES;
        $output = $output . " keys CSV_COLUMN_NAME_TO_INDEX: " . keys %CSV_COLUMN_NAME_TO_INDEX;
        $output = $output . " keys CSV_FILE_SCOPE_COLUMN_NOT_FOUND: " . keys @CSV_FILE_SCOPE_COLUMN_NOT_FOUND;
        print "$output\n";
        die $output;
    }

    # populate the CSV_COLUMN_INDEX_TO_NAME hash table with reverse.
    %CSV_COLUMN_INDEX_TO_NAME = reverse %CSV_COLUMN_NAME_TO_INDEX;

    #    Log::log_print $p_log_lvl, "  key: $_ and value: $CSV_COLUMN_NAME_TO_INDEX{$_}.\n";

    # verify that @CSV_FILE_SCOPE_COLUMN_NAMES is subset of @CSV_COLUMN_NAMES.
    # use a temp hash as storage, and compare two arrays.
    my %temp_hash;

    # add a hash key for each element of @CSV_FILE_SCOPE_COLUMN_NAMES
    undef @temp_hash{@CSV_FILE_SCOPE_COLUMN_NAMES};

    # remove all keys for elements of @CSV_COLUMN_NAMES
    delete @temp_hash{@CSV_COLUMN_NAMES};

    # check if the hash is empty.
    # if not empty, print error and exit.
    if (%temp_hash)
    {
        die "Error: @CSV_FILE_SCOPE_COLUMN_NAMES is not " . "subset of @CSV_COLUMN_NAMES.\n";
    }

    # populate @CSV_FILE_SCOPE_COLUMN_INDEXES array with column's index.
    foreach my $column (@CSV_FILE_SCOPE_COLUMN_NAMES)
    {
        push @CSV_FILE_SCOPE_COLUMN_INDEXES, $CSV_COLUMN_NAME_TO_INDEX{$column};
    }
}

sub _store_file_scope_columns
{
    my ( $self, $row_number, $columns ) = @_;
    Log::log_print $p_log_lvl, "_store_file_scope_columns():\n";

    # Store value of all file scope columns.  Values should be same for all rows.
    my ( $column_index, $column_name, $column_value, $stored_value );
    for ( my $i = 0; $i < scalar(@CSV_FILE_SCOPE_COLUMN_INDEXES); $i++ )
    {
        $column_index = $CSV_FILE_SCOPE_COLUMN_INDEXES[$i];
        $column_name  = $CSV_COLUMN_INDEX_TO_NAME{$column_index};

        # Get column value from current row
        $column_value = $columns->[$column_index];

        # Get column value currently stored in this object from a previous row
        $stored_value = $self->access($column_name);
        Log::log_print $p_log_lvl, "  column_index: $column_index.\n";
        Log::log_print $p_log_lvl, "  column_name: $column_name.\n";
        Log::log_print $p_log_lvl, "  column_value: $column_value.\n";

        if ( !defined($stored_value) )
        {
            # We do not have a stored value yet for this column; store it
            $self->access( $column_name, $column_value );
        }
        elsif ( $column_value ne $stored_value )
        {
            # Column value in current row doesn't match stored value from previous row.
            # file scope column, all values of the same column in a single csv file should be same.
            die "Error: Unexpected column value in "
                . $self->access($CSV_ATTR_file_name) . ".\n"
                . "Row $row_number contains the value $column_value for column "
                . "$column_name, but the previous row contains the value $stored_value.\n";
        }
    }

    # for columns that not found in CSV file, but in not found table,
    # assign default values from not found value table.
    foreach my $column_no_found (@CSV_FILE_SCOPE_COLUMN_NOT_FOUND)
    {
        $column_value = $CSV_FILE_SCOPE_COLUMN_NOT_FOUND_DEFAULT_VALUES{$column_no_found};
        Log::log_print $p_log_lvl, "  column not found value: $column_value.\n";

        # Get column value currently stored in this object from a previous row
        $stored_value = $self->access($column_no_found);

        if ( !defined($stored_value) )
        {
            # We do not have a stored value yet for this column; store it
            $self->access( $column_no_found, $column_value );
        }
    }
}

sub _store_vrt_scope_columns
{
    my ( $self, $row_number, $columns ) = @_;
    Log::log_print $p_log_lvl, "_store_vrt_scope_columns():\n";

    # values of VRT scope columns are not saved to new hash.

    # Get VRT that corresponds to column values from CSV row
    my $vrt = $self->_get_vrt( $row_number, $columns );

    # Get vratio_index value and verify it is valid.  This is the VRT column index.
    my $vratio_index = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_vratio_index} ];
    Log::log_print $p_log_lvl, "  vratio_index: $vratio_index.\n";
    if ( ( $vratio_index < 0 ) || ( $vratio_index >= $VRT_COLUMN_COUNT ) )
    {
        die "Error: Invalid vratio_index value $vratio_index in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Get wof_freq value and verify it is valid
    my $wof_freq = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_wof_freq} ];
    Log::log_print $p_log_lvl, "  wof_freq: $wof_freq.\n";
    if ( $wof_freq < 0 )
    {
        die "Error: Invalid wof_freq value $wof_freq in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Get wof_ceff_ratio_overage value and verify it is valid
    my $wof_ceff_ratio_overage = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_wof_ceff_ratio_overage} ];
    Log::log_print $p_log_lvl, "  wof_ceff_ratio_overage: $wof_ceff_ratio_overage.\n";
    if ( $wof_ceff_ratio_overage < 0 )
    {
        die "Error: Invalid wof_freq value wof_ceff_ratio_overage in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Set wof_freq value in VRT
    $vrt->wof_freq( $vratio_index, $wof_freq );

    # Set wof_ceff_ratio_overage value in VRT
    $vrt->wof_ceff_ratio_overage( $vratio_index, $wof_ceff_ratio_overage );
}

sub _verify_stored_vrt_data
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_stored_vrt_data():\n";

    # Verify all VRTs were found
    for ( my $vcs_ceff_index = 0; $vcs_ceff_index < $csv_vcs_ceff_index_count; $vcs_ceff_index++ )
    {
        for ( my $vdd_ceff_index = 0; $vdd_ceff_index < $csv_vdd_ceff_index_count; $vdd_ceff_index++ )
        {
            for ( my $io_power_index = 0; $io_power_index < $csv_io_power_index_count; $io_power_index++ )
            {
                for ( my $amb_cond_index = 0; $amb_cond_index < $csv_amb_cond_index_count; $amb_cond_index++ )
                {
                    my $vrt =
                        $self->{$CSV_ATTR_vrts}[$vcs_ceff_index][$vdd_ceff_index][$io_power_index][$amb_cond_index];
                    Log::log_print $p_log_lvl, "  vcs_ceff_index: $vcs_ceff_index,\n";
                    Log::log_print $p_log_lvl, "  vdd_ceff_index: $vdd_ceff_index,\n";
                    Log::log_print $p_log_lvl, "  io_power_index: $io_power_index.\n";
                    Log::log_print $p_log_lvl, "  amb_cond_index: $amb_cond_index.\n";
                    if ( !defined($vrt) )
                    {
                        die "Error: No VRT found in "
                            . $self->access($CSV_ATTR_file_name)
                            . " for\n"
                            . "  vcs_ceff_index    = $vcs_ceff_index\n"
                            . "  vdd_ceff_index    = $vdd_ceff_index\n"
                            . "  io_power_index    = $io_power_index\n"
                            . "  amb_cond_index = $amb_cond_index\n";
                    }

                    # Verify VRT is complete; all WOF frequencies were found
                    if ( !( $vrt->is_complete() ) )
                    {
                        die "Error: Incomplete VRT in "
                            . $self->access($CSV_ATTR_file_name)
                            . " for\n"
                            . "  vcs_ceff_index    = $vcs_ceff_index\n"
                            . "  vdd_ceff_index    = $vdd_ceff_index\n"
                            . "  io_power_index    = $io_power_index\n"
                            . "  amb_cond_index = $amb_cond_index\n";
                    }
                }
            }
        }
    }

    # Verify vratio_start and vratio_step values result in a valid vratio value in
    # the last column of the VRT.  Verify the following equation is true:
    #   vratio_start + (vratio_step * (VRT_COLUMN_COUNT - 1)) <= 1.1
    # The last vratio value should be <= 1.0 (100%) since it is an ascending
    # decimal percentage.  However, we use 1.1 to allow for imprecision due to
    # floating point math, rounding during CSV data generation, etc.
    my $last_vratio =
        $self->access($CSV_ATTR_vratio_start) + ( $self->access($CSV_ATTR_vratio_step) * ( $VRT_COLUMN_COUNT - 1 ) );
    Log::log_print $p_log_lvl, "  last_vratio: $last_vratio.\n";
    if ( $last_vratio > 1.1 )
    {
        die "Error: Invalid vratio_start and vratio_step values in "
            . $self->access($CSV_ATTR_file_name)
            . "\nResults in vratio value of $last_vratio.\n";
    }
}

sub _get_vrt
{
    my ( $self, $row_number, $columns ) = @_;
    Log::log_print $p_log_lvl, "_get_vrt():\n";

    # Get vcs_ceff_index value and verify it is valid.
    my $vcs_ceff_index = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_vcs_ceff_index} ];
    Log::log_print $p_log_lvl, "  vcs_ceff_index: $vcs_ceff_index.\n";
    if ( !defined($vcs_ceff_index) )
    {
        die "Error: vcs_ceff_index not defined in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }
    if (   ( $vcs_ceff_index < 0 )
        || ( $vcs_ceff_index >= $csv_vcs_ceff_index_count ) )
    {
        die "Error: Invalid vcs_ceff_index value $vcs_ceff_index in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Get vdd_ceff_index value and verify it matches expected value
    my $vdd_ceff_index = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_vdd_ceff_index} ];
    Log::log_print $p_log_lvl, "  vdd_ceff_index: $vdd_ceff_index.\n";
    if ( !defined($vdd_ceff_index) )
    {
        die "Error: vdd_ceff_index not defined in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }
    if (   ( $vdd_ceff_index < 0 )
        || ( $vdd_ceff_index >= $csv_vdd_ceff_index_count ) )
    {
        die "Error: Invalid vdd_ceff_index value $vdd_ceff_index in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Find io_power_index value via map.
    my $io_power_index = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_io_power_index} ];
    Log::log_print $p_log_lvl, "  io_power_index: $io_power_index.\n";
    if ( !defined($io_power_index) )
    {
        die "Error: io_power_index not defined in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }
    if (   ( $io_power_index < 0 )
        || ( $io_power_index >= $csv_io_power_index_count ) )
    {
        die "Error: Invalid io_power_index value $io_power_index in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Find amb_cond_index value via map.  Add 0 to amb_cond value to
    # ensure numerical comparison used when finding matching map key.
    my $amb_cond_index = $columns->[ $CSV_COLUMN_NAME_TO_INDEX{$CSV_ATTR_amb_cond_index} ];
    Log::log_print $p_log_lvl, "  amb_cond_index: $amb_cond_index.\n";
    if ( !defined($amb_cond_index) )
    {
        die "Error: amb_cond_index not defined in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }
    if (   ( $amb_cond_index < 0 )
        || ( $amb_cond_index >= $csv_amb_cond_index_count ) )
    {
        die "Error: Invalid amb_cond_index value $amb_cond_index in row "
            . "$row_number of file "
            . $self->access($CSV_ATTR_file_name) . ".\n";
    }

    # Get VRT at the specified vcs_ceff_index, vdd_ceff_index, and
    # io_power_index, $amb_cond_index in our three-dimensional array
    my $vrt = $self->{$CSV_ATTR_vrts}[$vcs_ceff_index][$vdd_ceff_index][$io_power_index][$amb_cond_index];
    if ( $p_log_lvl >= $g_log_lvl_target )
    {
        if ( !defined($vrt) )
        {
            Log::log_print $p_log_lvl, "  vrt not defined.\n";
        }
        else
        {
            Log::log_print $p_log_lvl, "  vrt: $vrt.\n";
        }
    }
    Log::log_print $p_log_lvl,
          "  vcs_ceff_index    = $vcs_ceff_index\n"
        . "  vdd_ceff_index    = $vdd_ceff_index\n"
        . "  io_power_index    = $io_power_index\n"
        . "  amb_cond_index = $amb_cond_index\n";

    # If VRT does not yet exist, create it
    # VREs in same VRT block will share the same VRT header.
    # It is possible that the VRT already exist if VRE in the same
    # VRT block already created it.
    if ( !defined($vrt) )
    {
        $vrt = VRT->new( $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index );
        $self->{$CSV_ATTR_vrts}[$vcs_ceff_index][$vdd_ceff_index][$io_power_index][$amb_cond_index] = $vrt;
    }
    return $vrt;
}
################################################################################
#  BinaryFileIO Class
#
# This class represents a binary file.  It is a wrapper around an IO::File
# object.  BinaryFileIO provides methods that make it easier to read and write
# binary data.  The data is written in big-endian format.  This class does not
# enforce any alignment/padding requirements.
################################################################################
package BinaryFileIO;
use IO::File;
use Fcntl qw(SEEK_SET SEEK_CUR);    # Import constants for seek()
our $p_log_lvl = $LOG_LVL_0;

# Attribute names in this class
our $BFIO_ATTR_file_name = 'file_name';
our $BFIO_ATTR_file      = 'file';

sub new
{
    my ( $class, $file_name ) = @_;

    # check to use global logging level.
    # $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $BFIO_ATTR_file_name => $file_name,
        $BFIO_ATTR_file      => IO::File->new(),
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name ) = @_;
    return $self->{$attr_name};
}

sub file_name
{
    my ($self) = @_;
    return $self->{$BFIO_ATTR_file_name};
}

sub open
{
    my ( $self, $mode ) = @_;
    Log::log_print $p_log_lvl, "open():\n";
    Log::log_print $p_log_lvl, "  mode: $mode.\n";

    # Open image file
    if ( !( $self->{$BFIO_ATTR_file}->open( $self->{$BFIO_ATTR_file_name}, $mode ) ) )
    {
        die "Error: Unable to open file " . $self->{$BFIO_ATTR_file_name} . ": $!.\n";
    }

    # Set file to binary mode
    if ( !( $self->{$BFIO_ATTR_file}->binmode() ) )
    {
        die "Error: Unable to open file " . $self->{$BFIO_ATTR_file_name} . " in binary mode: $!.\n";
    }
}

sub close
{
    my ($self) = @_;
    if ( !( $self->{$BFIO_ATTR_file}->close() ) )
    {
        die "Error: Unable to close file " . $self->{$BFIO_ATTR_file_name} . ": $!.\n";
    }
}

sub get_pos
{
    my ($self) = @_;
    my $pos = $self->{$BFIO_ATTR_file}->tell();
    if ( $pos == -1 )
    {
        die "Error: Unable to obtain current position in file " . $self->{$BFIO_ATTR_file_name} . ".\n";
    }
    return $pos;
}

sub set_pos
{
    my ( $self, $pos ) = @_;
    if ( !( $self->{$BFIO_ATTR_file}->seek( $pos, SEEK_SET ) ) )
    {
        die "Error: Unable to move to byte $pos in file " . $self->{$BFIO_ATTR_file_name} . ".\n";
    }
}

sub read
{
    my ( $self, $length ) = @_;
    my $buffer;
    if ( $length > 0 )
    {
        my $bytes_read = $self->{$BFIO_ATTR_file}->read( $buffer, $length );
        if ( $bytes_read != $length )
        {
            my $error_description;
            if ( !defined($bytes_read) )
            {
                $error_description = $!;
            }
            elsif ( $bytes_read == 0 )
            {
                $error_description = "End of file";
            }
            else
            {
                $error_description = "Only read $bytes_read bytes";
            }

            #      my $pos =  $self->get_pos();
            #      Log::log_print $LOG_LVL_1, "  pos: $pos.\n";
            die "Error: Unable to read $length bytes from file "
                . $self->{$BFIO_ATTR_file_name}
                . ": $error_description.\n";
        }
    }
    return $buffer;
}

sub read_to_buffer
{
    my ( $self, $length ) = @_;
    my $buffer     = undef;
    my $bytes_read = 0;

    if ( $length <= 0 )
    {
        die "Error: Invalid length passed in: $length\n";
    }
    $bytes_read = $self->{$BFIO_ATTR_file}->read( $buffer, $length );
    my $error_description;
    if ( !defined($bytes_read) )
    {
        $error_description = $!;
        die "Error: Unable to read $length bytes from file "
            . $self->{$BFIO_ATTR_file_name}
            . ": $error_description.\n";
    }
    return ( $buffer, $bytes_read );
}

sub write
{
    my ( $self, $buffer ) = @_;
    if ( !( $self->{$BFIO_ATTR_file}->print($buffer) ) )
    {
        die "Error: Unable to write to file " . $self->{$BFIO_ATTR_file_name} . ": $!.\n";
    }
}

sub read_uint8
{
    my ($self) = @_;
    my $buffer = $self->read(1);
    return unpack( 'C', $buffer );
}

sub write_uint8
{
    my ( $self, $uint8_value ) = @_;
    $self->write( pack( 'C', $uint8_value ) );
}

sub read_uint16
{
    my ($self) = @_;
    my $buffer = $self->read(2);
    return unpack( 'S>', $buffer );
}

sub write_uint16
{
    my ( $self, $uint16_value ) = @_;
    $self->write( pack( 'S>', $uint16_value ) );
}

sub read_uint32
{
    my ($self) = @_;
    my $buffer = $self->read(4);
    return unpack( 'L>', $buffer );
}

sub write_uint32
{
    my ( $self, $uint32_value ) = @_;
    $self->write( pack( 'L>', $uint32_value ) );
}

sub read_ascii_text
{
    my ( $self, $field_length ) = @_;
    my $buffer = $self->read($field_length);
    return unpack( 'A' . $field_length, $buffer );
}

sub write_ascii_text
{
    my ( $self, $ascii_text, $field_length ) = @_;
    $self->write( pack( 'A' . $field_length, $ascii_text ) );
}

sub skip_bytes
{
    my ( $self, $byte_count ) = @_;
    if ( !( $self->{$BFIO_ATTR_file}->seek( $byte_count, SEEK_CUR ) ) )
    {
        die "Error: Unable to move forward $byte_count bytes in file " . $self->{$BFIO_ATTR_file_name} . ".\n";
    }
}

sub fill_bytes
{
    my ( $self, $byte_count, $byte_value ) = @_;
    while ( $byte_count > 0 )
    {
        $self->write_uint8($byte_value);
        $byte_count--;
    }
}
################################################################################
# ImageHeader Class
#
# This class represents the Image Header within a WOF Tables Image File.
################################################################################
package ImageHeader;
our $p_log_lvl = $LOG_LVL_0;

# Constants representing expected field values
our $IMAGE_HEADER_MAGIC_NUMBER = 'WTIH';
our $IMAGE_HEADER_VERSION      = 1;

# Header size in bytes
our $IMAGE_HEADER_SIZE = 32;

# Attribute names in this class
our $IMH_ATTR_magic_number              = 'magic_number';
our $IMH_ATTR_version                   = 'version';
our $IMH_ATTR_section_table_entry_count = 'section_table_entry_count';
our $IMH_ATTR_section_table_offset      = 'section_table_offset';
our $IMH_ATTR_table_set_id              = 'table_set_id';

# dd_level is for all WOF tables.
our $IMH_ATTR_major_dd_level = 'major_dd_level';
our $IMH_ATTR_minor_dd_level = 'minor_dd_level';

sub new
{
    my ($class) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $IMH_ATTR_magic_number              => $IMAGE_HEADER_MAGIC_NUMBER,
        $IMH_ATTR_version                   => $IMAGE_HEADER_VERSION,
        $IMH_ATTR_section_table_entry_count => 0,
        $IMH_ATTR_section_table_offset      => 0,
        $IMH_ATTR_table_set_id              => undef,
        $IMH_ATTR_major_dd_level            => undef,
        $IMH_ATTR_minor_dd_level            => undef,
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;

    # Read field values from binary file
    $self->access( $IMH_ATTR_magic_number,              $file->read_ascii_text(4) );
    $self->access( $IMH_ATTR_version,                   $file->read_uint8() );
    $self->access( $IMH_ATTR_section_table_entry_count, $file->read_uint8() );
    $self->access( $IMH_ATTR_section_table_offset,      $file->read_uint32() );
    $self->access( $IMH_ATTR_table_set_id,              $file->read_ascii_text(16) );
    $file->skip_bytes(6);    # skip padding 6 bytes for reserved.

    # Verify field values
    if ( $self->access($IMH_ATTR_magic_number) ne $IMAGE_HEADER_MAGIC_NUMBER )
    {
        die "Error: Unexpected value in Magic Number field of Image Header: "
            . $self->access($IMH_ATTR_magic_number) . "\n";
    }
    if ( $self->access($IMH_ATTR_version) != $IMAGE_HEADER_VERSION )
    {
        die "Error: Unexpected value in Version field of Image Header: "
            . sprintf( "0x%02X", $self->access($IMH_ATTR_version) ) . "\n";
    }
}

sub write
{
    my ( $self, $file ) = @_;

    # Write field values to binary file
    $file->write_ascii_text( $self->access($IMH_ATTR_magic_number), 4 );
    $file->write_uint8( $self->access($IMH_ATTR_version) );
    $file->write_uint8( $self->access($IMH_ATTR_section_table_entry_count) );
    $file->write_uint32( $self->access($IMH_ATTR_section_table_offset) );
    $file->write_ascii_text( $self->access($IMH_ATTR_table_set_id), 16 );
    $file->fill_bytes( 6, 0x00 );    # padding 6 bytes for reserved.
                                     # align
}

sub print
{
    my ($self) = @_;

    # Print header fields to stdout
    printf("Image Header:\n");
    printf( "  Magic Number             : %s\n",     $self->access($IMH_ATTR_magic_number) );
    printf( "  Version                  : %u\n",     $self->access($IMH_ATTR_version) );
    printf( "  Section Table Entry Count: %u\n",     $self->access($IMH_ATTR_section_table_entry_count) );
    printf( "  Section Table Offset     : 0x%08X\n", $self->access($IMH_ATTR_section_table_offset) );
    printf( "  Section Table Set ID     : %s\n",     $self->access($IMH_ATTR_table_set_id) );
    printf("\n");
}
################################################################################
# SectionTableEntry Class
#
# This class represents a Section Table Entry within a WOF Tables Image File.
################################################################################
package SectionTableEntry;

# Attribute names in this class
our $STE_ATTR_section_offset = 'section_offset';
our $STE_ATTR_section_size   = 'section_size';

sub new
{
    my ($class) = @_;
    my $self = {
        $STE_ATTR_section_offset => 0,
        $STE_ATTR_section_size   => 0
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;

    # Read field values from binary file
    $self->access( $STE_ATTR_section_offset, $file->read_uint32() );
    $self->access( $STE_ATTR_section_size,   $file->read_uint32() );
}

sub write
{
    my ( $self, $file ) = @_;

    # Write field values to binary file
    $file->write_uint32( $self->access($STE_ATTR_section_offset) );
    $file->write_uint32( $self->access($STE_ATTR_section_size) );
}

################################################################################
# SectionTable Class
#
# This class represents the Section Table within a WOF Tables Image File.
################################################################################
package SectionTable;
our $p_log_lvl = $LOG_LVL_0;

sub new
{
    my ($class) = @_;
    my $self = [];    # anonymous array
    bless($self);
    return $self;
}

sub entry_count
{
    my ($self) = @_;
    return scalar(@$self);
}

sub clear
{
    my ($self) = @_;
    @$self = ();
}

sub add_entry
{
    my ( $self, $entry ) = @_;
    push( @$self, $entry );
}

sub get_entry
{
    my ( $self, $index ) = @_;
    return $self->[$index];
}

sub read
{
    my ( $self, $file, $entry_count ) = @_;

    # Clear out any current entries in table
    $self->clear();

    # Read entries from binary file
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = SectionTableEntry->new();

        # read entry info of Section Table Entry from file.
        $entry->read($file);

        # and save the entry to array of Section Table
        $self->add_entry($entry);
    }
}

sub write
{
    my ( $self, $file ) = @_;

    # Write entries to binary file
    my $entry_count = $self->entry_count();
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = $self->get_entry($i);
        $entry->write($file);
    }
}

sub print
{
    my ($self) = @_;

    # Print section table to stdout
    printf("Section Table:\n");
    printf("  Entry  Section Offset  Section Size\n");
    printf("  -----  --------------  ------------\n");
    my $entry_count = $self->entry_count();
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        # Print section table entry fields to stdout
        my $entry = $self->get_entry($i);
        printf(
            "     %2u      0x%08X    0x%08X\n",
            $i,
            $entry->access($STE_ATTR_section_offset),
            $entry->access($STE_ATTR_section_size)
        );
    }
    printf("\n");
}
################################################################################
# WOFTablesHeader Class
#
# This class represents a WOF Tables Header within a WOF Tables Image File.
################################################################################
package WOFTablesHeader;
our $p_log_lvl = $LOG_LVL_0;

# Constants representing expected field values
our $WOF_TABLES_HEADER_MAGIC_VALUE           = 'WFTH';
our $WOF_TABLES_HEADER_HEADER_VERSION        = 1;
our $WOF_TABLES_HEADER_VRT_BLOCK_SIZE        = 16;
our $WOF_TABLES_HEADER_VRT_BLOCK_HEADER_SIZE = 4;
our $WOF_TABLES_HEADER_VRT_DATA_SIZE         = 1;
our $WOF_TABLES_HEADER_OCS_MODE              = 1;
our $WOF_TABLES_HEADER_VRATIO_SIZE           = $VRT_COLUMN_COUNT;
our $WOF_TABLES_HEADER_SIZE                  = 128;
our $CSV_WOF_CONV_MULTIPLIER_PERCENT         = 10000;
our $CSV_WOF_CONV_MULTIPLIER_VALUE           = 1;

# Attribute names in this class
our $WOF_ATTR_magic_value               = 'magic_value';
our $WOF_ATTR_major_dd_level            = 'major_dd_level';
our $WOF_ATTR_minor_dd_level            = 'minor_dd_level';
our $WOF_ATTR_header_version            = 'header_version';
our $WOF_ATTR_vrt_block_size            = 'vrt_block_size';
our $WOF_ATTR_vrt_block_header_size     = 'vrt_block_header_size';
our $WOF_ATTR_vrt_data_size             = 'vrt_data_size';
our $WOF_ATTR_ocs_mode                  = 'ocs_mode';
our $WOF_ATTR_core_count                = 'core_count';
our $WOF_ATTR_vcs_start                 = 'vcs_start';
our $WOF_ATTR_vcs_step                  = 'vcs_step';
our $WOF_ATTR_vcs_size                  = 'vcs_size';
our $WOF_ATTR_vdd_start                 = 'vdd_start';
our $WOF_ATTR_vdd_step                  = 'vdd_step';
our $WOF_ATTR_vdd_size                  = 'vdd_size';
our $WOF_ATTR_vratio_start              = 'vratio_start';
our $WOF_ATTR_vratio_step               = 'vratio_step';
our $WOF_ATTR_vratio_size               = 'vratio_size';
our $WOF_ATTR_io_power_start            = 'io_power_start';
our $WOF_ATTR_io_power_step             = 'io_power_step';
our $WOF_ATTR_io_power_size             = 'io_power_size';
our $WOF_ATTR_amb_cond_start            = 'amb_cond_start';
our $WOF_ATTR_amb_cond_step             = 'amb_cond_step';
our $WOF_ATTR_amb_cond_size             = 'amb_cond_size';
our $WOF_ATTR_sort_throttl_freq_mhz     = 'sort_pwr_throttl_freq_mhz';
our $WOF_ATTR_socket_power_w            = 'socket_power_w';
our $WOF_ATTR_sort_pwr_tgt_freq_mhz     = 'sort_pwr_tgt_freq_mhz';
our $WOF_ATTR_rdp_current               = 'rdp_current';
our $WOF_ATTR_boost_current             = 'boost_current';
our $WOF_ATTR_tdp_vcs_ceff_index        = 'tdp_vcs_ceff_index';
our $WOF_ATTR_tdp_vdd_ceff_index        = 'tdp_vdd_ceff_index';
our $WOF_ATTR_tdp_io_power_index        = 'tdp_io_power_index';
our $WOF_ATTR_tdp_amb_cond_index        = 'tdp_amb_cond_index';
our $WOF_ATTR_io_full_power             = 'io_full_power';
our $WOF_ATTR_io_disabled_power         = 'io_diabled_power';
our $WOF_ATTR_sort_ultra_turbo_freq_mhz = 'sort_ultra_turbo_tgt_freq_mhz';
our $WOF_ATTR_table_date_timestamp      = 'table_date_timestamp';
our $WOF_ATTR_override_match_freq       = 'override_match_freq';
our $WOF_ATTR_override_match_power      = 'override_match_power';
our $WOF_ATTR_table_version             = 'table_version';
our $WOF_ATTR_package_name              = 'package_name';
our $WOF_ATTR_sort_power_save_freq_mhz  = 'sort_power_save_freq_mhz';
our $WOF_ATTR_sort_fixed_freq_mhz       = 'sort_fixed_freq_mhz';

sub new
{
    my ($class) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $WOF_ATTR_magic_value               => $WOF_TABLES_HEADER_MAGIC_VALUE,
        $WOF_ATTR_major_dd_level            => undef,
        $WOF_ATTR_minor_dd_level            => undef,
        $WOF_ATTR_header_version            => $WOF_TABLES_HEADER_HEADER_VERSION,
        $WOF_ATTR_vrt_block_size            => $WOF_TABLES_HEADER_VRT_BLOCK_SIZE,
        $WOF_ATTR_vrt_block_header_size     => $WOF_TABLES_HEADER_VRT_BLOCK_HEADER_SIZE,
        $WOF_ATTR_vrt_data_size             => $WOF_TABLES_HEADER_VRT_DATA_SIZE,
        $WOF_ATTR_ocs_mode                  => $WOF_TABLES_HEADER_OCS_MODE,
        $WOF_ATTR_core_count                => undef,
        $WOF_ATTR_vcs_start                 => undef,
        $WOF_ATTR_vcs_step                  => undef,
        $WOF_ATTR_vcs_size                  => undef,
        $WOF_ATTR_vdd_start                 => undef,
        $WOF_ATTR_vdd_step                  => undef,
        $WOF_ATTR_vdd_size                  => undef,
        $WOF_ATTR_vratio_start              => undef,
        $WOF_ATTR_vratio_step               => undef,
        $WOF_ATTR_vratio_size               => $WOF_TABLES_HEADER_VRATIO_SIZE,
        $WOF_ATTR_io_power_start            => undef,
        $WOF_ATTR_io_power_step             => undef,
        $WOF_ATTR_io_power_size             => undef,
        $WOF_ATTR_amb_cond_start            => undef,
        $WOF_ATTR_amb_cond_step             => undef,
        $WOF_ATTR_amb_cond_size             => undef,
        $WOF_ATTR_sort_throttl_freq_mhz     => undef,
        $WOF_ATTR_socket_power_w            => undef,
        $WOF_ATTR_sort_pwr_tgt_freq_mhz     => undef,
        $WOF_ATTR_rdp_current               => undef,
        $WOF_ATTR_boost_current             => undef,
        $WOF_ATTR_tdp_vcs_ceff_index        => undef,
        $WOF_ATTR_tdp_vdd_ceff_index        => undef,
        $WOF_ATTR_tdp_io_power_index        => undef,
        $WOF_ATTR_tdp_amb_cond_index        => undef,
        $WOF_ATTR_io_full_power             => undef,
        $WOF_ATTR_io_disabled_power         => undef,
        $WOF_ATTR_sort_ultra_turbo_freq_mhz => undef,
        $WOF_ATTR_table_date_timestamp      => undef,
        $WOF_ATTR_override_match_freq       => undef,
        $WOF_ATTR_override_match_power      => undef,
        $WOF_ATTR_table_version             => undef,
        $WOF_ATTR_package_name              => undef,
        $WOF_ATTR_sort_power_save_freq_mhz  => undef,
        $WOF_ATTR_sort_fixed_freq_mhz       => undef,

    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;

    # comment out lines below to reduce logging messages.
    # Log::log_print $LOG_LVL_0, "access():\n";
    # Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;
    Log::log_print $p_log_lvl, "read():\n";

    # before calling this function, the file pointer should already set to the start
    # of the wof table header.
    my $pos = $file->get_pos();

    # Read field values from binary file
    $self->access( $WOF_ATTR_magic_value,    $file->read_ascii_text(4) );
    $self->access( $WOF_ATTR_major_dd_level, $file->read_uint8() );
    $self->access( $WOF_ATTR_minor_dd_level, $file->read_uint8() );
    $file->skip_bytes(1);    # Reserved 1 bytes
    $self->access( $WOF_ATTR_header_version,            $file->read_uint8() );
    $self->access( $WOF_ATTR_vrt_block_size,            $file->read_uint16() );
    $self->access( $WOF_ATTR_vrt_block_header_size,     $file->read_uint16() );
    $self->access( $WOF_ATTR_vrt_data_size,             $file->read_uint16() );
    $self->access( $WOF_ATTR_ocs_mode,                  $file->read_uint8() );
    $self->access( $WOF_ATTR_core_count,                $file->read_uint8() );
    $self->access( $WOF_ATTR_vcs_start,                 $file->read_uint16() );
    $self->access( $WOF_ATTR_vcs_step,                  $file->read_uint16() );
    $self->access( $WOF_ATTR_vcs_size,                  $file->read_uint16() );
    $self->access( $WOF_ATTR_vdd_start,                 $file->read_uint16() );
    $self->access( $WOF_ATTR_vdd_step,                  $file->read_uint16() );
    $self->access( $WOF_ATTR_vdd_size,                  $file->read_uint16() );
    $self->access( $WOF_ATTR_vratio_start,              $file->read_uint16() );
    $self->access( $WOF_ATTR_vratio_step,               $file->read_uint16() );
    $self->access( $WOF_ATTR_vratio_size,               $file->read_uint16() );
    $self->access( $WOF_ATTR_io_power_start,            $file->read_uint16() );
    $self->access( $WOF_ATTR_io_power_step,             $file->read_uint16() );
    $self->access( $WOF_ATTR_io_power_size,             $file->read_uint16() );
    $self->access( $WOF_ATTR_amb_cond_start,            $file->read_uint16() );
    $self->access( $WOF_ATTR_amb_cond_step,             $file->read_uint16() );
    $self->access( $WOF_ATTR_amb_cond_size,             $file->read_uint16() );
    $self->access( $WOF_ATTR_sort_throttl_freq_mhz,     $file->read_uint16() );
    $self->access( $WOF_ATTR_socket_power_w,            $file->read_uint16() );
    $self->access( $WOF_ATTR_sort_pwr_tgt_freq_mhz,     $file->read_uint16() );
    $self->access( $WOF_ATTR_rdp_current,               $file->read_uint16() );
    $self->access( $WOF_ATTR_boost_current,             $file->read_uint16() );
    $self->access( $WOF_ATTR_tdp_vcs_ceff_index,        $file->read_uint8() );
    $self->access( $WOF_ATTR_tdp_vdd_ceff_index,        $file->read_uint8() );
    $self->access( $WOF_ATTR_tdp_io_power_index,        $file->read_uint8() );
    $self->access( $WOF_ATTR_tdp_amb_cond_index,        $file->read_uint8() );
    $self->access( $WOF_ATTR_io_full_power,             $file->read_uint8() );
    $self->access( $WOF_ATTR_io_disabled_power,         $file->read_uint8() );
    $self->access( $WOF_ATTR_sort_ultra_turbo_freq_mhz, $file->read_uint16() );
    $self->access( $WOF_ATTR_table_date_timestamp,      $file->read_uint32() );
    $self->access( $WOF_ATTR_override_match_freq,       $file->read_uint16() );
    $self->access( $WOF_ATTR_override_match_power,      $file->read_uint16() );
    $self->access( $WOF_ATTR_table_version,             $file->read_ascii_text(16) );
    $self->access( $WOF_ATTR_package_name,              $file->read_ascii_text(16) );
    $self->access( $WOF_ATTR_sort_power_save_freq_mhz,  $file->read_uint16() );
    $self->access( $WOF_ATTR_sort_fixed_freq_mhz,       $file->read_uint16() );
    $file->skip_bytes(20);    # Reserved 20 bytes

    my $actual_data_size = $file->get_pos() - $pos;
    Log::log_print $p_log_lvl, "actual_data_size: $actual_data_size.\n";

    if ( $actual_data_size > $WOF_TABLES_HEADER_SIZE )
    {
        # if the program comes to here. The something is not correct.
        # check the writing statements against the definition of WOF Table Header.
        Log::log_print $LOG_LVL_3, "Actual size of WOF Table Header: $actual_data_size.\n";
        Log::log_print $LOG_LVL_3, "Defined size of WOF Table Header: $WOF_TABLES_HEADER_SIZE.\n";
        die "Error: acutual WOF table header data size is larger than header size.";
    }
    elsif ( $actual_data_size < $WOF_TABLES_HEADER_SIZE )
    {
        # if the program comes to here. The something seems not correct.
        # check the writing statements against the definition of WOF Table Header.
        Log::log_print $LOG_LVL_2, "Actual size of WOF Table Header: $actual_data_size.\n";
        Log::log_print $LOG_LVL_2, "Defined size of WOF Table Header: $WOF_TABLES_HEADER_SIZE.\n";
        my $padding_size = $WOF_TABLES_HEADER_SIZE - $actual_data_size;
        Log::log_print $LOG_LVL_2, "The size of extra reserved bytes: $padding_size.\n";
        $file->skip_bytes($padding_size);    # Reserved bytes
    }

    # Verify field values
    if ( $self->access($WOF_ATTR_magic_value) ne $WOF_TABLES_HEADER_MAGIC_VALUE )
    {
        die "Error: Unexpected value in Magic Value field of WOF Tables Header: "
            . $self->access($WOF_ATTR_magic_value) . "\n";
    }
    if ( $self->access($WOF_ATTR_header_version) ne $WOF_TABLES_HEADER_HEADER_VERSION )
    {
        die "Error: Unexpected value in Version field of WOF Tables Header: "
            . sprintf( "0x%02X", $self->access($WOF_ATTR_header_version) ) . "\n";
    }
}

sub write
{
    my ( $self, $file ) = @_;
    Log::log_print $p_log_lvl, "write():\n";

    # before calling this function, the file pointer should already set to the start
    # of the wof table header.
    my $pos = $file->get_pos();

    # Write field values to binary file
    $file->write_ascii_text( $self->access($WOF_ATTR_magic_value), 4 );
    $file->write_uint8( $self->access($WOF_ATTR_major_dd_level) );
    $file->write_uint8( $self->access($WOF_ATTR_minor_dd_level) );
    $file->fill_bytes( 1, 0x00 );    # Reserved 1 bytes
    $file->write_uint8( $self->access($WOF_ATTR_header_version) );
    $file->write_uint16( $self->access($WOF_ATTR_vrt_block_size) );
    $file->write_uint16( $self->access($WOF_ATTR_vrt_block_header_size) );
    $file->write_uint16( $self->access($WOF_ATTR_vrt_data_size) );
    $file->write_uint8( $self->access($WOF_ATTR_ocs_mode) );
    $file->write_uint8( $self->access($WOF_ATTR_core_count) );
    $file->write_uint16( $self->access($WOF_ATTR_vcs_start) );
    $file->write_uint16( $self->access($WOF_ATTR_vcs_step) );
    $file->write_uint16( $self->access($WOF_ATTR_vcs_size) );
    $file->write_uint16( $self->access($WOF_ATTR_vdd_start) );
    $file->write_uint16( $self->access($WOF_ATTR_vdd_step) );
    $file->write_uint16( $self->access($WOF_ATTR_vdd_size) );
    $file->write_uint16( $self->access($WOF_ATTR_vratio_start) );
    $file->write_uint16( $self->access($WOF_ATTR_vratio_step) );
    $file->write_uint16( $self->access($WOF_ATTR_vratio_size) );
    $file->write_uint16( $self->access($WOF_ATTR_io_power_start) );
    $file->write_uint16( $self->access($WOF_ATTR_io_power_step) );
    $file->write_uint16( $self->access($WOF_ATTR_io_power_size) );
    $file->write_uint16( $self->access($WOF_ATTR_amb_cond_start) );
    $file->write_uint16( $self->access($WOF_ATTR_amb_cond_step) );
    $file->write_uint16( $self->access($WOF_ATTR_amb_cond_size) );
    $file->write_uint16( $self->access($WOF_ATTR_sort_throttl_freq_mhz) );
    $file->write_uint16( $self->access($WOF_ATTR_socket_power_w) );
    $file->write_uint16( $self->access($WOF_ATTR_sort_pwr_tgt_freq_mhz) );
    $file->write_uint16( $self->access($WOF_ATTR_rdp_current) );
    $file->write_uint16( $self->access($WOF_ATTR_boost_current) );
    $file->write_uint8( $self->access($WOF_ATTR_tdp_vcs_ceff_index) );
    $file->write_uint8( $self->access($WOF_ATTR_tdp_vdd_ceff_index) );
    $file->write_uint8( $self->access($WOF_ATTR_tdp_io_power_index) );
    $file->write_uint8( $self->access($WOF_ATTR_tdp_amb_cond_index) );
    $file->write_uint8( $self->access($WOF_ATTR_io_full_power) );
    $file->write_uint8( $self->access($WOF_ATTR_io_disabled_power) );
    $file->write_uint16( $self->access($WOF_ATTR_sort_ultra_turbo_freq_mhz) );
    $file->write_uint32( $self->access($WOF_ATTR_table_date_timestamp) );
    $file->write_uint16( $self->access($WOF_ATTR_override_match_freq) );
    $file->write_uint16( $self->access($WOF_ATTR_override_match_power) );
    $file->write_ascii_text( $self->access($WOF_ATTR_table_version), 16 );
    $file->write_ascii_text( $self->access($WOF_ATTR_package_name),  16 );
    $file->write_uint16( $self->access($WOF_ATTR_sort_power_save_freq_mhz) );
    $file->write_uint16( $self->access($WOF_ATTR_sort_fixed_freq_mhz) );
    $file->fill_bytes( 20, 0x00 );    # Reserved 20 bytes

    my $actual_data_size = $file->get_pos() - $pos;
    Log::log_print $p_log_lvl, "actual_data_size: $actual_data_size.\n";

    if ( $actual_data_size > $WOF_TABLES_HEADER_SIZE )
    {
        # if the program comes to here. The something is not correct.
        # check the writing statements against the definition of WOF Table Header.
        Log::log_print $LOG_LVL_3, "Actual size of WOF Table Header: $actual_data_size.\n";
        Log::log_print $LOG_LVL_3, "Defined size of WOF Table Header: $WOF_TABLES_HEADER_SIZE.\n";
        die "Error: acutual WOF table header data size is larger than header size.";
    }
    elsif ( $actual_data_size < $WOF_TABLES_HEADER_SIZE )
    {
        # if the program comes to here. The something seems not correct.
        # check the writing statements against the definition of WOF Table Header.
        Log::log_print $LOG_LVL_2, "Actual size of WOF Table Header: $actual_data_size.\n";
        Log::log_print $LOG_LVL_2, "Defined size of WOF Table Header: $WOF_TABLES_HEADER_SIZE.\n";
        my $padding_size = $WOF_TABLES_HEADER_SIZE - $actual_data_size;
        Log::log_print $LOG_LVL_2, "The size of extra reserved bytes: $padding_size.\n";
        $file->fill_bytes( $padding_size, 0x00 );    # Reserved bytes.
    }
}

sub print
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "print():\n";

    # Print header fields to stdout
    printf("WOF Tables Header:\n");
    printf( "  Magic Value                    : %s\n", $self->access($WOF_ATTR_magic_value) );
    printf( "  Major DD Level                 : %s\n", $self->access($WOF_ATTR_major_dd_level) );
    printf( "  Minor DD Level                 : %s\n", $self->access($WOF_ATTR_minor_dd_level) );
    printf( "  Header Version                 : %u\n", $self->access($WOF_ATTR_header_version) );
    printf( "  VRT Block Size                 : %u\n", $self->access($WOF_ATTR_vrt_block_size) );
    printf( "  VRT Block Header Size          : %u\n", $self->access($WOF_ATTR_vrt_block_header_size) );
    printf( "  VRT Data Size                  : %u\n", $self->access($WOF_ATTR_vrt_data_size) );
    printf( "  Ocs Mode                       : %u\n", $self->access($WOF_ATTR_ocs_mode) );
    printf( "  Core Count                     : %u\n", $self->access($WOF_ATTR_core_count) );
    printf( "  Vcs Start                      : %u\n", $self->access($WOF_ATTR_vcs_start) );
    printf( "  Vcs Step                       : %u\n", $self->access($WOF_ATTR_vcs_step) );
    printf( "  Vcs Size                       : %u\n", $self->access($WOF_ATTR_vcs_size) );
    printf( "  Vdd Start                      : %u\n", $self->access($WOF_ATTR_vdd_start) );
    printf( "  Vdd Step                       : %u\n", $self->access($WOF_ATTR_vdd_step) );
    printf( "  Vdd Size                       : %u\n", $self->access($WOF_ATTR_vdd_size) );
    printf( "  Vratio Start                   : %u\n", $self->access($WOF_ATTR_vratio_start) );
    printf( "  Vratio Step                    : %u\n", $self->access($WOF_ATTR_vratio_step) );
    printf( "  Vratio Size                    : %u\n", $self->access($WOF_ATTR_vratio_size) );
    printf( "  Io Power Start                 : %u\n", $self->access($WOF_ATTR_io_power_start) );
    printf( "  Io Power Step                  : %u\n", $self->access($WOF_ATTR_io_power_step) );
    printf( "  Io Power Size                  : %u\n", $self->access($WOF_ATTR_io_power_size) );
    printf( "  Amb Cond Start                 : %u\n", $self->access($WOF_ATTR_amb_cond_start) );
    printf( "  Amb Cond Step                  : %u\n", $self->access($WOF_ATTR_amb_cond_step) );
    printf( "  Amb Cond Size                  : %u\n", $self->access($WOF_ATTR_amb_cond_size) );
    printf( "  Sort Throttle Frequency MHz    : %u\n", $self->access($WOF_ATTR_sort_throttl_freq_mhz) );
    printf( "  Socket Power W                 : %u\n", $self->access($WOF_ATTR_socket_power_w) );
    printf( "  Sort Power Target Frequency MHz: %u\n", $self->access($WOF_ATTR_sort_pwr_tgt_freq_mhz) );
    printf( "  RDP Current                    : %u\n", $self->access($WOF_ATTR_rdp_current) );
    printf( "  Boost Current                  : %u\n", $self->access($WOF_ATTR_boost_current) );
    printf( "  Tdp Vcs Ceff Index             : %u\n", $self->access($WOF_ATTR_tdp_vcs_ceff_index) );
    printf( "  Tdp Vdd Ceff Index             : %u\n", $self->access($WOF_ATTR_tdp_vdd_ceff_index) );
    printf( "  Tdp Io Power Index             : %u\n", $self->access($WOF_ATTR_tdp_io_power_index) );
    printf( "  Tdp Amb Cond Index             : %u\n", $self->access($WOF_ATTR_tdp_amb_cond_index) );
    printf( "  Io Full Power                  : %u\n", $self->access($WOF_ATTR_io_full_power) );
    printf( "  Io Disabled Power              : %u\n", $self->access($WOF_ATTR_io_disabled_power) );
    printf( "  Sort Ultra Turbo Frequency MHz : %u\n", $self->access($WOF_ATTR_sort_ultra_turbo_freq_mhz) );
    printf( "  Table Date Timestamp           : %u\n", $self->access($WOF_ATTR_table_date_timestamp) );
    printf( "  Override Match Freq MHz        : %s\n", $self->access($WOF_ATTR_override_match_freq) );
    printf( "  Override Match Power           : %s\n", $self->access($WOF_ATTR_override_match_power) );
    printf( "  Table Version                  : %s\n", $self->access($WOF_ATTR_table_version) );
    printf( "  Package Name                   : %s\n", $self->access($WOF_ATTR_package_name) );
    printf( "  Sort Power Save Frequency MHz  : %s\n", $self->access($WOF_ATTR_sort_power_save_freq_mhz) );
    printf( "  Sort Fixed Frequency MHz       : %s\n", $self->access($WOF_ATTR_sort_fixed_freq_mhz) );
    printf("\n");
}
################################################################################
# VRTHeader Class
#
# This class represents a VRT Header within a WOF Tables Image File.
################################################################################
package VRTHeader;
our $p_log_lvl = $LOG_LVL_0;

# Constants representing expected field values
our $VRT_HEADER_MAGIC_VALUE = 'V';
our $VRT_HEADER_TYPE        = 0;
our $VRT_HEADER_CONTENT     = 0;
our $VRT_HEADER_VERSION     = 0;

# in big endian notation
our $VRTH_BITMASK_TYPE            = 0x80;    # bit 0 of the byte
our $VRTH_BITMASK_CONTENT         = 0x40;    # bit 1 of the byte
our $VRTH_BITMASK_VERSION         = 0x30;    # bits 2:3 of the byte
our $VRTH_BITMASK_IO_IDX_IN_VAL1  = 0x0F;
our $VRTH_BITMASK_IO_IDX_IN_VAL2  = 0x80;
our $VRTH_BITMASK_AC_IDX_IN_VAL2  = 0x7C;
our $VRTH_BITMASK_VCS_IDX_IN_VAL2 = 0x03;
our $VRTH_BITMASK_VCS_IDX_IN_VAL3 = 0xE0;
our $VRTH_BITMASK_VDD_IDX_IN_VAL3 = 0x1F;

# Starting positions of bit masks for VRT Header
our $VRTH_BIT_POS_TYPE            = 7;
our $VRTH_BIT_POS_CONTENT         = 6;
our $VRTH_BIT_POS_VERSION         = 4;
our $VRTH_BIT_POS_IO_IDX_IN_VAL1  = -1;
our $VRTH_BIT_POS_IO_IDX_IN_VAL2  = 7;
our $VRTH_BIT_POS_AC_IDX_IN_VAL2  = 2;
our $VRTH_BIT_POS_VCS_IDX_IN_VAL2 = -3;
our $VRTH_BIT_POS_VCS_IDX_IN_VAL3 = 5;
our $VRTH_BIT_POS_VDD_IDX_IN_VAL3 = 0;

# Attribute names in the class
our $VRTH_ATTR_magic_value = 'magic_value';
our $VRTH_ATTR_type        = 'type';
our $VRTH_ATTR_content     = 'content';
our $VRTH_ATTR_version     = 'version';
our $VRTH_ATTR_io_index    = 'io_index';
our $VRTH_ATTR_ac_index    = 'ac_index';
our $VRTH_ATTR_vcs_index   = 'vcs_index';
our $VRTH_ATTR_vdd_index   = 'vdd_index';

sub new
{
    my ($class) = @_;
    my $self = {
        $VRTH_ATTR_magic_value => $VRT_HEADER_MAGIC_VALUE,
        $VRTH_ATTR_type        => $VRT_HEADER_TYPE,
        $VRTH_ATTR_content     => $VRT_HEADER_CONTENT,
        $VRTH_ATTR_version     => $VRT_HEADER_VERSION,
        $VRTH_ATTR_io_index    => undef,
        $VRTH_ATTR_ac_index    => undef,
        $VRTH_ATTR_vcs_index   => undef,
        $VRTH_ATTR_vdd_index   => undef,
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;
    Log::log_print $p_log_lvl, "read():\n";

    my $uint8_val1;
    my $uint8_val2;
    my $uint8_val3;

    my $io_index;
    my $ac_index;
    my $vcs_index;
    my $vdd_index;

    # Read field values from binary file
    $self->access( $VRTH_ATTR_magic_value, $file->read_ascii_text(1) );
    $uint8_val1 = $file->read_uint8();
    $uint8_val2 = $file->read_uint8();
    $uint8_val3 = $file->read_uint8();

    $self->access( $VRTH_ATTR_type,    ( $uint8_val1 & $VRTH_BITMASK_TYPE ) >> $VRTH_BIT_POS_TYPE );
    $self->access( $VRTH_ATTR_content, ( $uint8_val1 & $VRTH_BITMASK_CONTENT ) >> $VRTH_BIT_POS_CONTENT );
    $self->access( $VRTH_ATTR_version, ( $uint8_val1 & $VRTH_BITMASK_VERSION ) >> $VRTH_BIT_POS_VERSION );

    $io_index =
        ( ( $uint8_val1 & $VRTH_BITMASK_IO_IDX_IN_VAL1 ) << abs($VRTH_BIT_POS_IO_IDX_IN_VAL1) ) |
        ( ( $uint8_val2 & $VRTH_BITMASK_IO_IDX_IN_VAL2 ) >> $VRTH_BIT_POS_IO_IDX_IN_VAL2 );
    $ac_index = ( ( $uint8_val2 & $VRTH_BITMASK_AC_IDX_IN_VAL2 ) >> $VRTH_BIT_POS_AC_IDX_IN_VAL2 );
    $vcs_index =
        ( ( $uint8_val2 & $VRTH_BITMASK_VCS_IDX_IN_VAL2 ) << abs($VRTH_BIT_POS_VCS_IDX_IN_VAL2) ) |
        ( ( $uint8_val3 & $VRTH_BITMASK_VCS_IDX_IN_VAL3 ) >> $VRTH_BIT_POS_VCS_IDX_IN_VAL3 );
    $vdd_index = ( $uint8_val3 & $VRTH_BITMASK_VDD_IDX_IN_VAL3 );

    $self->access( $VRTH_ATTR_io_index,  $io_index );
    $self->access( $VRTH_ATTR_ac_index,  $ac_index );
    $self->access( $VRTH_ATTR_vcs_index, $vcs_index );
    $self->access( $VRTH_ATTR_vdd_index, $vdd_index );

    # Verify field values
    if ( $self->access($VRTH_ATTR_magic_value) ne $VRT_HEADER_MAGIC_VALUE )
    {
        die "Error: Unexpected value in Magic Value field of VRT Header: "
            . $self->access($VRTH_ATTR_magic_value) . "\n";
    }
    if ( $self->access($VRTH_ATTR_type) != $VRT_HEADER_TYPE )
    {
        die "Error: Unexpected value in Type field of VRT Header: "
            . sprintf( "0x%X", $self->access($VRTH_ATTR_type) ) . "\n";
    }
    if ( $self->access($VRTH_ATTR_version) != $VRT_HEADER_VERSION )
    {
        die "Error: Unexpected value in Version field of VRT Header: "
            . sprintf( "0x%X", $self->access($VRTH_ATTR_version) ) . "\n";
    }
}

sub write
{
    my ( $self, $file ) = @_;
    Log::log_print $p_log_lvl, "write():\n";

    my $uint8_val1;
    my $uint8_val2;
    my $uint8_val3;

    # Write field values to binary file
    $file->write_ascii_text( $self->access($VRTH_ATTR_magic_value), 1 );
    $uint8_val1 =
        ( ( $self->access($VRTH_ATTR_type) << $VRTH_BIT_POS_TYPE ) & $VRTH_BITMASK_TYPE ) |
        ( ( $self->access($VRTH_ATTR_content) << $VRTH_BIT_POS_CONTENT ) & $VRTH_BITMASK_CONTENT ) |
        ( ( $self->access($VRTH_ATTR_version) << $VRTH_BIT_POS_VERSION ) & $VRTH_BITMASK_VERSION ) |
        ( ( $self->access($VRTH_ATTR_io_index) >> abs($VRTH_BIT_POS_IO_IDX_IN_VAL1) ) & $VRTH_BITMASK_IO_IDX_IN_VAL1 );
    $uint8_val2 =
        ( ( $self->access($VRTH_ATTR_io_index) << $VRTH_BIT_POS_IO_IDX_IN_VAL2 ) & $VRTH_BITMASK_IO_IDX_IN_VAL2 ) |
        ( ( $self->access($VRTH_ATTR_ac_index) << $VRTH_BIT_POS_AC_IDX_IN_VAL2 ) & $VRTH_BITMASK_AC_IDX_IN_VAL2 ) |
        (
        ( $self->access($VRTH_ATTR_vcs_index) >> abs($VRTH_BIT_POS_VCS_IDX_IN_VAL2) ) & $VRTH_BITMASK_VCS_IDX_IN_VAL2 );
    $uint8_val3 =
        ( ( $self->access($VRTH_ATTR_vcs_index) << $VRTH_BIT_POS_VCS_IDX_IN_VAL3 ) & $VRTH_BITMASK_VCS_IDX_IN_VAL3 ) |
        ( $self->access($VRTH_ATTR_vdd_index) & $VRTH_BITMASK_VDD_IDX_IN_VAL3 );
    $file->write_uint8($uint8_val1);
    $file->write_uint8($uint8_val2);
    $file->write_uint8($uint8_val3);
}

sub print
{
    my ( $self, $file ) = @_;
    Log::log_print $p_log_lvl, "print():\n";

    $self->read($file);

    # Print header fields to stdout
    printf("VRT Header:\n");
    printf( "  Magic Value: %s,",  $self->access($VRTH_ATTR_magic_value) );
    printf( "  Type       : %u",   $self->access($VRTH_ATTR_type) );
    printf( "  Version    : %u\n", $self->access($VRTH_ATTR_version) );
    printf( "  Io_index   : %u,",  $self->access($VRTH_ATTR_io_index) );
    printf( "  Ac_index   : %u,",  $self->access($VRTH_ATTR_ac_index) );
    printf( "  Vcs_index  : %u,",  $self->access($VRTH_ATTR_vcs_index) );
    printf( "  Vdd_index  : %u\n", $self->access($VRTH_ATTR_vdd_index) );
}

################################################################################
# ImageFile Class
#
# This class represents a WOF Tables Image File.
#
# The file format is described in detail by the documents referenced at the
# beginning of this script.
#
# A WOF Tables Image File is a binary file in big-endian format.  Major data
# structures are aligned on 8 byte boundaries.  The file begins with an Image
# File Header, followed by a Section Table, followed by one or more sections.
# Each section contains a WOF Tables Header followed by all of the VRTs for one
# SPWBF (Socket Power and WOF Base Frequency) combination.
################################################################################
package ImageFile;
our $p_log_lvl                 = $LOG_LVL_0;
our $IMAGE_FILE_BYTE_ALIGNMENT = 8;
our $FIELD_LEN1                = 8;
our $FIELD_LEN2                = 6;
our $FIELD_LEN3                = 4;
our $fmt_str                   = "%" . $FIELD_LEN1 . "s" . " ";
our $fmt_str1                  = "%" . $FIELD_LEN3 . "s" . " ";
our $fmt_dec                   = "%" . $FIELD_LEN1 . "d" . " ";
our $fmt_dec1                  = "%" . $FIELD_LEN2 . "d" . " ";
our $fmt_dec2                  = "%" . $FIELD_LEN3 . "d" . " ";
our $fmt_flo                   = "%." . $FIELD_LEN2 . "f" . " ";

# Attribute names in this class
our $IMF_ATTR_binary_file_io = 'file';
our $IMF_ATTR_image_header   = 'image_header';
our $IMF_ATTR_section_table  = 'section_table';

sub new
{
    my ( $class, $file_name ) = @_;

    # check to use global logging level.
    #  $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $IMF_ATTR_binary_file_io => BinaryFileIO->new($file_name),
        $IMF_ATTR_image_header   => ImageHeader->new(),
        $IMF_ATTR_section_table  => SectionTable->new(),
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub create
{
    my ( $self, @csv_file_names ) = @_;
    Log::log_print $p_log_lvl, "create():\n";

    # Open image file for writing
    $self->{$IMF_ATTR_binary_file_io}->open('w');

    # Write image file contents
    $self->_write(@csv_file_names);

    # Close image file
    $self->{$IMF_ATTR_binary_file_io}->close();
}

sub list
{
    my ( $self, $section_number ) = @_;

    Log::log_print $p_log_lvl, "list():\n";

    my $entry;
    my $wof_tables_header;

    # Open image file for reading
    $self->access($IMF_ATTR_binary_file_io)->open('r');

    # Read and print image header
    $self->_read_image_header();
    $self->access($IMF_ATTR_image_header)->print();

    # Read section table Section Table pointed by into Section Table attribute,
    # and file pointer is set file pointer to the end of Section Table.
    $self->_read_section_table();

    # Print section table
    $self->access($IMF_ATTR_section_table)->print();

    # Loop through section table entries
    if ( defined($section_number) )
    {
        if (   ( $section_number < 0 )
            || ( $section_number >= $self->access($IMF_ATTR_section_table)->entry_count() ) )
        {
            die "Error: Option section_number $section_number is invalid.\n";
        }

        $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);

        # Set file offset to the start of the section
        $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

        # Read and print the WOF Tables Header at the start of the section
        $wof_tables_header = $self->_read_wof_tables_header();

        printf("Entry Number: $section_number\n");
        $wof_tables_header->print();
    }
    else
    {
        for ( my $i = 0; $i < $self->access($IMF_ATTR_section_table)->entry_count(); $i++ )
        {
            $entry = $self->access($IMF_ATTR_section_table)->get_entry($i);

            # Set file pointer to the start of the WOF Table Header of the i-th entry,
            # which is stored as offset in the i-th entry in Section Table.
            $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

            # Read and print the WOF Tables Header at the start of the section
            $wof_tables_header = $self->_read_wof_tables_header();

            printf("Entry Number: $i\n");
            $wof_tables_header->print();
        }
    }

    # Close image file
    $self->access($IMF_ATTR_binary_file_io)->close();
}

sub view
{
    my ($self,           $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index,
        $amb_cond_index, $vratio_index,   $outrows,        $outcols,        $convert_to_mhz
    ) = @_;
    Log::log_print $p_log_lvl, "view():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Open image file for reading
    $self->access($IMF_ATTR_binary_file_io)->open('r');

    # Read image header and section table
    $self->_read_image_header();
    $self->_read_section_table();

    # Read and print the matching VRT within this WOF Tables section
    $self->_view_vrt_with_rows_cols(
        $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index,
        $vratio_index,   $outrows,        $outcols,        $convert_to_mhz
    );

    # Close image file
    $self->access($IMF_ATTR_binary_file_io)->close();
}

sub squint
{
    my ( $self, $section_number, $vrt_index ) = @_;

    Log::log_print $p_log_lvl, "squint():\n";

    my $entry;
    my $wof_tables_header;

    # Open image file for reading
    $self->access($IMF_ATTR_binary_file_io)->open('r');

    # Read and print image header
    $self->_read_image_header();
    $self->access($IMF_ATTR_image_header)->print();

    # Read section table Section Table pointed by into Section Table attribute,
    # and file pointer is set file pointer to the end of Section Table.
    $self->_read_section_table();

    # Print section table
    $self->access($IMF_ATTR_section_table)->print();

    # validate $section_number
    if ( !defined($section_number) )
    {
        die "Error: Option section_number $section_number is note defined.\n";
    }
    else
    {
        if (   ( $section_number < 0 )
            || ( $section_number >= $self->access($IMF_ATTR_section_table)->entry_count() ) )
        {
            die "Error: Option section_number $section_number is invalid.\n";
        }
    }

    $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);

    # Set file offset to the start of the section
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read and print the WOF Tables Header at the start of the section
    $wof_tables_header = $self->_read_wof_tables_header();

    printf("Entry Number: $section_number\n");
    $wof_tables_header->print();

    my $io_power_size = $wof_tables_header->access($WOF_ATTR_io_power_size);
    my $vcs_ceff_size = $wof_tables_header->access($WOF_ATTR_vcs_size);
    my $vdd_ceff_size = $wof_tables_header->access($WOF_ATTR_vdd_size);
    my $amb_cond_size = $wof_tables_header->access($WOF_ATTR_amb_cond_size);
    my $max_vrt_index = ( $vcs_ceff_size * $vdd_ceff_size * $io_power_size * $amb_cond_size ) - 1;

    # Nail down to the WOF table and to the VRT or loop through VRT.
    if ( defined($vrt_index) )
    {
        if (   ( $vrt_index < 0 )
            || ( $vrt_index > $max_vrt_index ) )
        {
            die "Error: Option vrt_index $vrt_index is invalid.\n";
        }

        $self->_print_vrt_header_by_index( $section_number, $vrt_index );
    }
    else
    {
        for ( my $i = 0; $i <= $max_vrt_index; $i++ )
        {
            $vrt_index = $i;
            $self->_print_vrt_header_by_index( $section_number, $vrt_index );
        }
    }

    # Close image file
    $self->access($IMF_ATTR_binary_file_io)->close();
}

sub extract
{
    my ( $self, $section_number, $output_file_name ) = @_;
    Log::log_print $p_log_lvl, "extract():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Open image file for reading
    $self->access($IMF_ATTR_binary_file_io)->open('r');

    # Read image header and section table
    $self->_read_image_header();
    $self->_read_section_table();

    # Extract section to the specified output file
    $self->_extract_section( $section_number, $output_file_name );

    # Close image file
    $self->access($IMF_ATTR_binary_file_io)->close();
}

sub retrieve_wof_table_header
{
    my ( $self, $section_number ) = @_;

    Log::log_print $p_log_lvl, "retrieve_wof_table_header():\n";

    my $entry;
    my $wof_tables_header;

    # Open image file for reading
    $self->access($IMF_ATTR_binary_file_io)->open('r');

    # Read image header.
    # this step is required to populate data to objects in this class.
    $self->_read_image_header();

    # Read section table Section Table pointed by into Section Table attribute,
    # and file pointer is set file pointer to the end of Section Table.
    $self->_read_section_table();

    # validate $section_number
    if ( !defined($section_number) )
    {
        die "Error: Option section_number $section_number is note defined.\n";
    }
    else
    {
        if (   ( $section_number < 0 )
            || ( $section_number >= $self->access($IMF_ATTR_section_table)->entry_count() ) )
        {
            die "Error: Option section_number $section_number is invalid.\n";
        }
    }

    $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);

    # Set file offset to the start of the section table.
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read and print the WOF Tables Header at the start of the section
    $wof_tables_header = $self->_read_wof_tables_header();

    Log::log_print $p_log_lvl, "Entry Number: $section_number\n";

    my $major_dd_level          = $wof_tables_header->access($WOF_ATTR_major_dd_level);
    my $minor_dd_level          = $wof_tables_header->access($WOF_ATTR_minor_dd_level);
    my $core_count              = $wof_tables_header->access($WOF_ATTR_core_count);
    my $socket_power_w          = $wof_tables_header->access($WOF_ATTR_socket_power_w);
    my $sort_pwr_tgt_freq_mhz   = $wof_tables_header->access($WOF_ATTR_sort_pwr_tgt_freq_mhz);
    my $override_match_freq_mhz = $wof_tables_header->access($WOF_ATTR_override_match_freq);
    my $override_match_power    = $wof_tables_header->access($WOF_ATTR_override_match_power);
    my $package_name            = $wof_tables_header->access($WOF_ATTR_package_name);

    # Close image file
    $self->access($IMF_ATTR_binary_file_io)->close();

    return ( $major_dd_level, $minor_dd_level, $core_count, $socket_power_w, $sort_pwr_tgt_freq_mhz,
        $override_match_power, $override_match_freq_mhz, $package_name );
}

#------------------------------------------------------------------------------
# Private methods
#------------------------------------------------------------------------------
sub _write
{
    my ( $self, @csv_file_names ) = @_;
    Log::log_print $p_log_lvl, "_write():\n";

    # Write image header to image file.  Pass in number of sections that will
    # exist in file.  There will be one section for each CSV file.
    my $section_count = scalar(@csv_file_names);
    $self->_write_image_header($section_count);

    my $major_dd_level = $self->access($IMF_ATTR_image_header)->access($IMH_ATTR_major_dd_level);
    my $minor_dd_level = $self->access($IMF_ATTR_image_header)->access($IMH_ATTR_minor_dd_level);

    # Write section table to image file with default section offsets/sizes
    $self->_write_section_table();

    # Loop through CSV files
    for ( my $i = 0; $i < $section_count; $i++ )
    {
        # Write section to image file containing the CSV file data
        $self->_write_wof_section( $csv_file_names[$i], $i, $major_dd_level, $minor_dd_level );
    }

    # Update section table in image file with actual section offsets/sizes
    $self->_update_section_table();
}

sub _read_image_header
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_image_header():\n";

    # Read image header from image file
    $self->access($IMF_ATTR_image_header)->read( $self->access($IMF_ATTR_binary_file_io) );

    # Read past any padding
    $self->_read_padding();
}

sub _write_image_header
{
    my ( $self, $section_count ) = @_;
    Log::log_print $p_log_lvl, "_write_image_header():\n";
    Log::log_print $p_log_lvl, "  section_count: $section_count.\n";

    # Set the Section Table Entry Count field
    $self->{$IMF_ATTR_image_header}->access( $IMH_ATTR_section_table_entry_count, $section_count );

    # check table set id.
    my $table_set_id = $self->access($IMF_ATTR_image_header)->access($IMH_ATTR_table_set_id);
    Log::log_print $p_log_lvl, "  table_set_id: $table_set_id.\n";

    # Set the Section Table Offset field.  The image header is at the start of the
    # file (offset 0), and the section table follows the image header.  Offset
    # must take into account any padding added after the image header.
    my $section_table_offset = $IMAGE_HEADER_SIZE;
    $section_table_offset += $self->_get_padding_count($section_table_offset);
    $self->{$IMF_ATTR_image_header}->access( $IMH_ATTR_section_table_offset, $section_table_offset );

    # Write image header to image file
    $self->{$IMF_ATTR_image_header}->write( $self->access($IMF_ATTR_binary_file_io) );

    # Write any necessary padding so header ends on proper byte boundary
    $self->_write_padding();
}

sub _read_section_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_section_table():\n";

    # Get number of section table entries from image header
    my $entry_count = $self->{$IMF_ATTR_image_header}->access($IMH_ATTR_section_table_entry_count);

    # Read section table from image file
    $self->access($IMF_ATTR_section_table)->read( $self->access($IMF_ATTR_binary_file_io), $entry_count );

    # Read past any padding following the section table
    $self->_read_padding();
}

sub _write_section_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_write_section_table():\n";

    # Clear current contents of section table
    $self->access($IMF_ATTR_section_table)->clear();

    # Get number of section table entries from image header
    my $entry_count = $self->{$IMF_ATTR_image_header}->access($IMH_ATTR_section_table_entry_count);

    # Add section table entries with default section offsets/sizes
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = SectionTableEntry->new();
        $self->{$IMF_ATTR_section_table}->add_entry($entry);
    }

    # Write section table to image file
    $self->access($IMF_ATTR_section_table)->write( $self->access($IMF_ATTR_binary_file_io) );

    # Write any necessary padding so table ends on proper byte boundary
    $self->_write_padding();
}

sub _update_section_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_update_section_table():\n";

    # Get offset to the section table from the image header
    my $section_table_offset = $self->access($IMF_ATTR_image_header)->access($IMH_ATTR_section_table_offset);

    # Move to section table offset within image file
    $self->access($IMF_ATTR_binary_file_io)->set_pos($section_table_offset);

    # Update section table in image file.  Write actual section offsets/sizes.
    $self->access($IMF_ATTR_section_table)->write( $self->access($IMF_ATTR_binary_file_io) );
}

sub _write_wof_section
{
    my ( $self, $csv_file_name, $section_number, $major_dd_level, $minor_dd_level ) = @_;
    Log::log_print $p_log_lvl, "_write_wof_section():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Get current file offset.  This is the offset to the start of the section.
    my $section_offset = $self->access($IMF_ATTR_binary_file_io)->get_pos();

    # Create CSVFile object and parse the CSV data
    my $csv_file = CSVFile->new($csv_file_name);
    $csv_file->parse();

    # Write WOF Tables Header to the image file
    my $wof_tables_header = $self->_set_wof_tables_header( $csv_file, $major_dd_level, $minor_dd_level );
    if ( $p_log_lvl >= $LOG_LVL_1 )
    {
        $self->_print_wof_tables_header($wof_tables_header);
    }

    # Write all the VRTs to the image file
    $self->_write_tables_vrts( $csv_file, $wof_tables_header );

    # Get current file offset.  This is one byte past the end of the section.
    # Calculate section size based on offsets.
    my $current_offset = $self->access($IMF_ATTR_binary_file_io)->get_pos();
    my $section_size   = $current_offset - $section_offset;

    # Store section offset and size in section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);
    if ( !defined($entry) )
    {
        die "Error: No Section Table Entry for section number:  $section_number.\n";
    }

    $entry->access( $STE_ATTR_section_offset, $section_offset );
    $entry->access( $STE_ATTR_section_size,   $section_size );

    # Write any necessary padding so section ends on proper byte boundary
    $self->_write_padding();
}

sub _extract_section
{
    my ( $self, $section_number, $output_file_name ) = @_;
    Log::log_print $p_log_lvl, "_extract_section():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Get section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);

    # Set image file offset to the start of the section
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Open output file for writing
    my $output_file = BinaryFileIO->new($output_file_name);
    $output_file->open('w');

    # Copy section bytes from image file to output file
    my $max_read_size = $G_MAX_READ_SIZE;
    my $bytes_left    = $entry->access($STE_ATTR_section_size);
    while ( $bytes_left > 0 )
    {
        my $read_size = ( $bytes_left < $max_read_size ) ? $bytes_left : $max_read_size;
        my $buffer = $self->access($IMF_ATTR_binary_file_io)->read($read_size);
        $output_file->write($buffer);
        $bytes_left -= $read_size;
    }

    # Close output file
    $output_file->close();
}

sub _read_wof_tables_header
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_wof_tables_header():\n";

    # Create WOF Tables header
    my $wof_tables_header = WOFTablesHeader->new();

    # Read header from image file
    $wof_tables_header->read( $self->access($IMF_ATTR_binary_file_io) );

    # Set global size variables with values in WOF Table header,
    # which were read from image file.
    $g_io_power_size = $wof_tables_header->access($WOF_ATTR_io_power_size);
    $g_vcs_ceff_size = $wof_tables_header->access($WOF_ATTR_vcs_size);
    $g_vdd_ceff_size = $wof_tables_header->access($WOF_ATTR_vdd_size);
    $g_amb_cond_size = $wof_tables_header->access($WOF_ATTR_amb_cond_size);

    return $wof_tables_header;
}

sub _set_wof_tables_header
{
    my ( $self, $csv_file, $major_dd_level, $minor_dd_level ) = @_;
    Log::log_print $p_log_lvl, "_set_wof_tables_header():\n";
    Log::log_print $p_log_lvl, "  csvfile: $csv_file.\n";
    Log::log_print $p_log_lvl, "  $major_dd_level: $major_dd_level.\n";
    Log::log_print $p_log_lvl, "  $minor_dd_level: $minor_dd_level.\n";

    # Create WOF Tables header
    my $wof_tables_header = WOFTablesHeader->new();

    # set dd level to values from input parameter.
    $wof_tables_header->access( $WOF_ATTR_major_dd_level, $major_dd_level );
    $wof_tables_header->access( $WOF_ATTR_minor_dd_level, $minor_dd_level );

    # Set header field values based on columns from CSV file.  CSV columns that
    # contain percentages are expressed as a decimal.  For example, 4.7% is 0.047.
    # Header fields that contain percentages are expressed as integer hundredths
    # of a percent.  For example, 4.7% is 470.  Thus, we need to multiply the CSV
    # percentage values by 10000 to convert to hundredths of a percent.
    # magic_value hardcoded in WOF_HEADER class.
    # version hardcoded in WOF_HEADER class.
    # vrt_block_size hardcoded in WOF_HEADER class.
    # vrt_block_header_size hardcoded in WOF_HEADER class.
    # vrt_data_size hardcoded in WOF_HEADER class.
    # ocs_mode hardcoded in WOF_HEADER class.
    $wof_tables_header->access( $WOF_ATTR_core_count, $csv_file->access($CSV_ATTR_core_count) );
    $wof_tables_header->access( $WOF_ATTR_vcs_start,
        int( $csv_file->access($CSV_ATTR_vcs_ceff_start) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );
    $wof_tables_header->access( $WOF_ATTR_vcs_step,
        int( $csv_file->access($CSV_ATTR_vcs_ceff_step) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );
    $wof_tables_header->access( $WOF_ATTR_vcs_size, $g_vcs_ceff_size );

    $wof_tables_header->access( $WOF_ATTR_vdd_start,
        int( $csv_file->access($CSV_ATTR_vdd_ceff_start) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );
    $wof_tables_header->access( $WOF_ATTR_vdd_step,
        int( $csv_file->access($CSV_ATTR_vdd_ceff_step) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );
    $wof_tables_header->access( $WOF_ATTR_vdd_size, $g_vdd_ceff_size );

    $wof_tables_header->access( $WOF_ATTR_vratio_start,
        int( $csv_file->access($CSV_ATTR_vratio_start) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );
    $wof_tables_header->access( $WOF_ATTR_vratio_step,
        int( $csv_file->access($CSV_ATTR_vratio_step) * $CSV_WOF_CONV_MULTIPLIER_PERCENT ) );

    # vratio_size hardcoded in WOF_HEADER class.

    $wof_tables_header->access( $WOF_ATTR_io_power_start,
        int( $csv_file->access($CSV_ATTR_io_power_start) * $CSV_WOF_CONV_MULTIPLIER_VALUE ) );
    $wof_tables_header->access( $WOF_ATTR_io_power_step,
        int( $csv_file->access($CSV_ATTR_io_power_step) * $CSV_WOF_CONV_MULTIPLIER_VALUE ) );
    $wof_tables_header->access( $WOF_ATTR_io_power_size, $g_io_power_size );

    $wof_tables_header->access( $WOF_ATTR_amb_cond_start,
        int( $csv_file->access($CSV_ATTR_amb_cond_start) * $CSV_WOF_CONV_MULTIPLIER_VALUE ) );
    $wof_tables_header->access( $WOF_ATTR_amb_cond_step,
        int( $csv_file->access($CSV_ATTR_amb_cond_step) * $CSV_WOF_CONV_MULTIPLIER_VALUE ) );
    $wof_tables_header->access( $WOF_ATTR_amb_cond_size, $g_amb_cond_size );

    $wof_tables_header->access( $WOF_ATTR_sort_throttl_freq_mhz, $csv_file->access($CSV_ATTR_pdv_sort_throttle_freq) );
    $wof_tables_header->access( $WOF_ATTR_socket_power_w,        $csv_file->access($CSV_ATTR_socket_power) );
    $wof_tables_header->access( $WOF_ATTR_sort_pwr_tgt_freq_mhz, $csv_file->access($CSV_ATTR_pdv_sort_wof_base_freq) );
    $wof_tables_header->access( $WOF_ATTR_rdp_current,           $csv_file->access($CSV_ATTR_rdp_current) );
    $wof_tables_header->access( $WOF_ATTR_boost_current,         $csv_file->access($CSV_ATTR_boost_current) );
    $wof_tables_header->access( $WOF_ATTR_tdp_vcs_ceff_index,    $csv_file->access($CSV_ATTR_tdp_vcs_ceff_index) );
    $wof_tables_header->access( $WOF_ATTR_tdp_vdd_ceff_index,    $csv_file->access($CSV_ATTR_tdp_vdd_ceff_index) );
    $wof_tables_header->access( $WOF_ATTR_tdp_io_power_index,    $csv_file->access($CSV_ATTR_tdp_io_power_index) );
    $wof_tables_header->access( $WOF_ATTR_tdp_amb_cond_index,    $csv_file->access($CSV_ATTR_tdp_amb_cond_index) );
    $wof_tables_header->access( $WOF_ATTR_io_full_power,         $csv_file->access($CSV_ATTR_io_full_power) );
    $wof_tables_header->access( $WOF_ATTR_io_disabled_power,     $csv_file->access($CSV_ATTR_io_disabled_power) );
    $wof_tables_header->access( $WOF_ATTR_sort_ultra_turbo_freq_mhz,
        $csv_file->access($CSV_ATTR_pdv_sort_ultra_turbo_freq) );
    $wof_tables_header->access( $WOF_ATTR_table_date_timestamp, $csv_file->access($CSV_ATTR_table_date) );
    $wof_tables_header->access( $WOF_ATTR_override_match_freq,  $csv_file->access($CSV_ATTR_override_match_freq) );
    $wof_tables_header->access( $WOF_ATTR_override_match_power, $csv_file->access($CSV_ATTR_override_match_power) );
    $wof_tables_header->access( $WOF_ATTR_table_version,        $csv_file->access($CSV_ATTR_table_version) );
    $wof_tables_header->access( $WOF_ATTR_package_name,         $csv_file->access($CSV_ATTR_package) );
    $wof_tables_header->access( $WOF_ATTR_sort_power_save_freq_mhz,
        $csv_file->access($CSV_ATTR_pdv_sort_power_save_freq) );
    $wof_tables_header->access( $WOF_ATTR_sort_fixed_freq_mhz, $csv_file->access($CSV_ATTR_pdv_sort_fixed_freq) );

    # Write header to image file
    $wof_tables_header->write( $self->access($IMF_ATTR_binary_file_io) );
    return $wof_tables_header;
}

sub _print_wof_tables_header
{
    my ( $self, $wof_tables_header ) = @_;
    Log::log_print $p_log_lvl, "_print_wof_tables_header():\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_core_count:" . $wof_tables_header->access($WOF_ATTR_core_count) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vcs_start:" . $wof_tables_header->access($WOF_ATTR_vcs_start) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vcs_step:" . $wof_tables_header->access($WOF_ATTR_vcs_step) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vcs_size:" . $wof_tables_header->access($WOF_ATTR_vcs_size) . "\n";

    Log::log_print $p_log_lvl, "  WOF_ATTR_vdd_start:" . $wof_tables_header->access($WOF_ATTR_vdd_start) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vdd_step:" . $wof_tables_header->access($WOF_ATTR_vdd_step) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vdd_size:" . $wof_tables_header->access($WOF_ATTR_vdd_size) . "\n";

    Log::log_print $p_log_lvl, "  WOF_ATTR_vratio_start:" . $wof_tables_header->access($WOF_ATTR_vratio_start) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vratio_step:" . $wof_tables_header->access($WOF_ATTR_vratio_step) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_vratio_size:" . $wof_tables_header->access($WOF_ATTR_vratio_size) . "\n";

    Log::log_print $p_log_lvl,
        "  WOF_ATTR_io_power_start:" . $wof_tables_header->access($WOF_ATTR_io_power_start) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_io_power_step:" . $wof_tables_header->access($WOF_ATTR_io_power_step) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_io_power_size:" . $wof_tables_header->access($WOF_ATTR_io_power_size) . "\n";

    Log::log_print $p_log_lvl,
        "  WOF_ATTR_amb_cond_start:" . $wof_tables_header->access($WOF_ATTR_amb_cond_start) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_amb_cond_step:" . $wof_tables_header->access($WOF_ATTR_amb_cond_step) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_amb_cond_size:" . $wof_tables_header->access($WOF_ATTR_amb_cond_size) . "\n";

    Log::log_print $p_log_lvl,
        "  WOF_ATTR_sort_throttl_freq_mhz:" . $wof_tables_header->access($WOF_ATTR_sort_throttl_freq_mhz) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_socket_power_w:" . $wof_tables_header->access($WOF_ATTR_socket_power_w) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_sort_pwr_tgt_freq_mhz:" . $wof_tables_header->access($WOF_ATTR_sort_pwr_tgt_freq_mhz) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_rdp_current:" . $wof_tables_header->access($WOF_ATTR_rdp_current) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_boost_current:" . $wof_tables_header->access($WOF_ATTR_boost_current) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_tdp_vcs_ceff_index:" . $wof_tables_header->access($WOF_ATTR_tdp_vcs_ceff_index) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_tdp_vdd_ceff_index:" . $wof_tables_header->access($WOF_ATTR_tdp_vdd_ceff_index) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_tdp_io_power_index:" . $wof_tables_header->access($WOF_ATTR_tdp_io_power_index) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_tdp_amb_cond_index:" . $wof_tables_header->access($WOF_ATTR_tdp_amb_cond_index) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_io_full_power:" . $wof_tables_header->access($WOF_ATTR_io_full_power) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_io_disabled_power:" . $wof_tables_header->access($WOF_ATTR_io_disabled_power) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_sort_ultra_turbo_freq_mhz:"
        . $wof_tables_header->access($WOF_ATTR_sort_ultra_turbo_freq_mhz) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_table_date_timestamp:" . $wof_tables_header->access($WOF_ATTR_table_date_timestamp) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_override_match_freq:" . $wof_tables_header->access($WOF_ATTR_override_match_freq) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_override_match_power:" . $wof_tables_header->access($WOF_ATTR_override_match_power) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_table_version:" . $wof_tables_header->access($WOF_ATTR_table_version) . "\n";
    Log::log_print $p_log_lvl, "  WOF_ATTR_package_name:" . $wof_tables_header->access($WOF_ATTR_package_name) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_sort_power_save_freq_mhz:" . $wof_tables_header->access($WOF_ATTR_sort_power_save_freq_mhz) . "\n";
    Log::log_print $p_log_lvl,
        "  WOF_ATTR_sort_fixed_freq_mhz:" . $wof_tables_header->access($WOF_ATTR_sort_fixed_freq_mhz) . "\n";
}

sub _write_tables_vrts
{
    my ( $self, $csv_file, $wof_tables_header ) = @_;
    Log::log_print $p_log_lvl, "_write_tables_vrts():\n";

    # Iterate over all the valid values for vcs_ceff_index
    for ( my $vcs_ceff_index = 0; $vcs_ceff_index < $csv_vcs_ceff_index_count; $vcs_ceff_index++ )
    {
        # Iterate over all the valid values for vdd_ceff_index
        for ( my $vdd_ceff_index = 0; $vdd_ceff_index < $csv_vdd_ceff_index_count; $vdd_ceff_index++ )
        {
            # Iterate over all the valid values for io_power_index
            for ( my $io_power_index = 0; $io_power_index < $csv_io_power_index_count; $io_power_index++ )
            {
                # Iterate over all the valid values for amb_cond_index
                for ( my $amb_cond_index = 0; $amb_cond_index < $csv_amb_cond_index_count; $amb_cond_index++ )
                {
                    # Get VRT for current index values
                    my $vrt = $csv_file->vrt( $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index );
                    if ( !defined($vrt) )
                    {
                        die "Error: vrt not defined for indexes, "
                            . " vcs_ceff_index: $vcs_ceff_index,"
                            . " vdd_ceff_index: $vdd_ceff_index,"
                            . " io_power_index: $io_power_index,"
                            . " amb_cond_index: $amb_cond_index.\n";
                    }
                    $vrt->access( $VRT_ATTR_vcs_ceff_index, $vcs_ceff_index );
                    $vrt->access( $VRT_ATTR_vdd_ceff_index, $vdd_ceff_index );
                    $vrt->access( $VRT_ATTR_io_power_index, $io_power_index );
                    $vrt->access( $VRT_ATTR_amb_cond_index, $amb_cond_index );

                    # Write VRT to image file
                    $self->_write_vrt( $vrt, $csv_file, $wof_tables_header );
                }
            }
        }
    }
}

sub _calc_system_vre
{
    my ( $self, $column_index, $vrt, $csv_file, $wof_tables_header ) = @_;
    Log::log_print $p_log_lvl, "_calc_system_vre():\n";
    my $wof_ceff_ratio_overage = $vrt->wof_ceff_ratio_overage($column_index);
    if ( $wof_ceff_ratio_overage == 0 )
    {
        # Get WOF frequency value in MHz.  Verify it is >= 1000.
        my $wof_freq_mhz = $vrt->wof_freq($column_index);
        if ( ( $wof_freq_mhz < 1800 ) || ( $wof_freq_mhz > 4250 ) )
        {
            die "Error: Invalid WOF frequency $wof_freq_mhz in "
                . $csv_file->file_name()
                . ".\nFrequency must be >= 1000.\n";
        }
        Log::log_print $p_log_lvl, "  wof_freq_mhz: $wof_freq_mhz\n";

        # Convert frequency from MHz to one-byte System VRT format using equation
        # System VRT value = Roundup((Freq(MHz) - 1000)/(16.667 (MHz)))+60
        # where 1800MHz <= Freq <= 4250MHz
        my $system_vre_freq_encode = Util::round( ( $wof_freq_mhz - 1000 ) / 16.667 ) + 60;
        Log::log_print $p_log_lvl, "  system_vre_freq_encode: $system_vre_freq_encode\n";

        # Make sure converted value fits in the range.
        if (   ( $system_vre_freq_encode < $G_MIN_FREQ_ENCODE )
            || ( $system_vre_freq_encode > $G_MAX_FREQ_ENCODE ) )
        {
            die "Error: Invalid WOF frequency $wof_freq_mhz in "
                . $csv_file->file_name()
                . ".\nDoes not fit in System VRT format.\n";
        }
        return $system_vre_freq_encode;
    }
    else
    {
        my $system_vre_overage_encode = $wof_ceff_ratio_overage / 0.015625;
        $system_vre_overage_encode = Util::ceil($system_vre_overage_encode);
        Log::log_print $p_log_lvl, "  wof_ceff_ratio_overage: $wof_ceff_ratio_overage\n";
        Log::log_print $p_log_lvl, "  system_vre_overage_encode: $system_vre_overage_encode\n";
        if ( $system_vre_overage_encode == 0.0 )
        {
            $system_vre_overage_encode = 1;
        }
        Log::log_print $p_log_lvl, "  $system_vre_overage_encode: $system_vre_overage_encode\n";

        # Make sure converted value fits in the range.
        if (   ( $system_vre_overage_encode < $G_MIN_OVRG_ENCODE )
            || ( $system_vre_overage_encode > $G_MAX_OVRG_ENCODE ) )
        {
            die "Error: Invalid VRE Overage Encode "
                . "  system_vre_overage_encode: "
                . $system_vre_overage_encode . "\n"
                . "  wof_ceff_ratio_overage: "
                . $wof_ceff_ratio_overage . "\n";
        }
        return $system_vre_overage_encode;
    }
}

sub _write_vrt
{
    my ( $self, $vrt, $csv_file, $wof_tables_header ) = @_;
    Log::log_print $p_log_lvl, "_write_vrt():\n";

    #  Log::log_print $p_log_lvl, "  vrt: $vrt.\n";
    # Write VRT header to image file
    $self->_write_vrt_header( $vrt, $csv_file, $wof_tables_header );

    # Write VRT to image file.
    # Iterate over VRT columns
    for ( my $column_index = 0; $column_index < $VRT_COLUMN_COUNT; $column_index++ )
    {
        # calculate System VRE Overage Encode.
        my $wof_freq_sys = $self->_calc_system_vre( $column_index, $vrt, $csv_file, $wof_tables_header );

        # Write one-byte System VRT frequency value to image file
        $self->access($IMF_ATTR_binary_file_io)->write_uint8($wof_freq_sys);
    }
}

sub _view_vrt_with_rows_cols
{
    my ($self,           $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index,
        $amb_cond_index, $vratio_index,   $outrows,        $outcols,        $convert_to_mhz
    ) = @_;
    Log::log_print $p_log_lvl, "_view_vrt():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    printf("\n");
    printf( "section_number = %s\n", $section_number );
    printf("\n");

    # Make sure understand concept of order and type here.
    # order - the sequence of loop from outermost to innermost for
    #       nested multiple loops 0..4. Normally outrow: 3, outcols: 4.
    # type  - the dimension, such as vcs, vdd, io, amb, vr etc.
    #
    my $MAX_INDEX_COUNT = 5;
    my @DIM_TYPE;
    my @DIM_COUNT;
    my @DIM_INIT;
    my @DIM_INDEX;
    my %DIM_TYPE_ORDER_MAP;
    my %DIM_TYPE_VAL_MAP;
    my %DIM_TYPE_WOF_START_MAP;
    my %DIM_TYPE_WOF_STEP_MAP;
    my %DIM_TYPE_WOF_DIVIDE_VAL_MAP;
    my %DIM_TYPE_LOOP_ORDER_MAP_DEFAULT;

    # default loop order in the nested loops, it is the same as the order
    # in WOF Table Section.
    $DIM_TYPE_LOOP_ORDER_MAP_DEFAULT{$G_ATTR_vcs_ceff_index} = 0;    # most outer loop
    $DIM_TYPE_LOOP_ORDER_MAP_DEFAULT{$G_ATTR_vdd_ceff_index} = 1;    # 2nd most outer loop
    $DIM_TYPE_LOOP_ORDER_MAP_DEFAULT{$G_ATTR_io_power_index} = 2;
    $DIM_TYPE_LOOP_ORDER_MAP_DEFAULT{$G_ATTR_amb_cond_index} = 3;
    $DIM_TYPE_LOOP_ORDER_MAP_DEFAULT{$G_ATTR_vratio_index}   = 4;    # most inner loop

    # save the index and values of inputs to hash table.
    $DIM_TYPE_VAL_MAP{$G_ATTR_vcs_ceff_index} = $vcs_ceff_index;
    $DIM_TYPE_VAL_MAP{$G_ATTR_vdd_ceff_index} = $vdd_ceff_index;
    $DIM_TYPE_VAL_MAP{$G_ATTR_io_power_index} = $io_power_index;
    $DIM_TYPE_VAL_MAP{$G_ATTR_amb_cond_index} = $amb_cond_index;
    $DIM_TYPE_VAL_MAP{$G_ATTR_vratio_index}   = $vratio_index;

    # save the index and start to hash table.
    $DIM_TYPE_WOF_START_MAP{$G_ATTR_vcs_ceff_index} = $WOF_ATTR_vcs_start;
    $DIM_TYPE_WOF_START_MAP{$G_ATTR_vdd_ceff_index} = $WOF_ATTR_vdd_start;
    $DIM_TYPE_WOF_START_MAP{$G_ATTR_io_power_index} = $WOF_ATTR_io_power_start;
    $DIM_TYPE_WOF_START_MAP{$G_ATTR_amb_cond_index} = $WOF_ATTR_amb_cond_start;
    $DIM_TYPE_WOF_START_MAP{$G_ATTR_vratio_index}   = $WOF_ATTR_vratio_start;

    # save the index and step to hash table.
    $DIM_TYPE_WOF_DIVIDE_VAL_MAP{$G_ATTR_vcs_ceff_index} = $CSV_WOF_CONV_MULTIPLIER_PERCENT;
    $DIM_TYPE_WOF_DIVIDE_VAL_MAP{$G_ATTR_vdd_ceff_index} = $CSV_WOF_CONV_MULTIPLIER_PERCENT;
    $DIM_TYPE_WOF_DIVIDE_VAL_MAP{$G_ATTR_io_power_index} = $CSV_WOF_CONV_MULTIPLIER_VALUE;
    $DIM_TYPE_WOF_DIVIDE_VAL_MAP{$G_ATTR_amb_cond_index} = $CSV_WOF_CONV_MULTIPLIER_VALUE;
    $DIM_TYPE_WOF_DIVIDE_VAL_MAP{$G_ATTR_vratio_index}   = $CSV_WOF_CONV_MULTIPLIER_PERCENT;

    # save the index and step to hash table.
    $DIM_TYPE_WOF_STEP_MAP{$G_ATTR_vcs_ceff_index} = $WOF_ATTR_vcs_step;
    $DIM_TYPE_WOF_STEP_MAP{$G_ATTR_vdd_ceff_index} = $WOF_ATTR_vdd_step;
    $DIM_TYPE_WOF_STEP_MAP{$G_ATTR_io_power_index} = $WOF_ATTR_io_power_step;
    $DIM_TYPE_WOF_STEP_MAP{$G_ATTR_amb_cond_index} = $WOF_ATTR_amb_cond_step;
    $DIM_TYPE_WOF_STEP_MAP{$G_ATTR_vratio_index}   = $WOF_ATTR_vratio_step;

    # determine the order of loop. Checking in reverse order in the array.
    my $index_loop_number = $MAX_INDEX_COUNT - 1;

    #  outcols loops 1st innermost. So it is the last index in the array.
    if ( defined($outcols) )
    {
        $DIM_TYPE_ORDER_MAP{$outcols} = $index_loop_number;
        --$index_loop_number;
    }
    else
    {
        die "Error: outcols is not defined.\n";
    }

    #  outrows loops the 2nd innermost. So it is the 2nd last index in the array.
    if ( defined($outrows) )
    {
        $DIM_TYPE_ORDER_MAP{$outrows} = $index_loop_number;
        --$index_loop_number;
    }
    else
    {
        die "Error: outrows is not defined.\n";
    }

    # remaining type of index will loops without
    # any sequence specified.
    foreach my $dim_index (
        $G_ATTR_vcs_ceff_index, $G_ATTR_vdd_ceff_index, $G_ATTR_io_power_index,
        $G_ATTR_amb_cond_index, $G_ATTR_vratio_index,
        )
    {
        if ( !exists $DIM_TYPE_ORDER_MAP{$dim_index} )
        {
            $DIM_TYPE_ORDER_MAP{$dim_index} = $index_loop_number;
            --$index_loop_number;
        }
    }

    # create reverse hash table.
    my %DIM_ORDER_TYPE_MAP = reverse %DIM_TYPE_ORDER_MAP;

    # save the dimension type to array.
    $DIM_TYPE[0] = $DIM_ORDER_TYPE_MAP{0};
    $DIM_TYPE[1] = $DIM_ORDER_TYPE_MAP{1};
    $DIM_TYPE[2] = $DIM_ORDER_TYPE_MAP{2};
    $DIM_TYPE[3] = $DIM_ORDER_TYPE_MAP{3};
    $DIM_TYPE[4] = $DIM_ORDER_TYPE_MAP{4};

    # get the order of rows index. It is the 2nd last one.
    # the order of last index is $MAX_INDEX_COUNT - 1.
    # step up by one:
    my $rows_index_order  = $MAX_INDEX_COUNT - 2;
    my $wof_tables_header = $self->_read_wof_tables_header();

    $csv_io_power_index_count = $wof_tables_header->access($WOF_ATTR_io_power_size);
    $csv_vcs_ceff_index_count = $wof_tables_header->access($WOF_ATTR_vcs_size);
    $csv_vdd_ceff_index_count = $wof_tables_header->access($WOF_ATTR_vdd_size);
    $csv_amb_cond_index_count = $wof_tables_header->access($WOF_ATTR_amb_cond_size);
    $csv_vratio_index_count   = $wof_tables_header->access($WOF_ATTR_vratio_size);

    my %DIM_TYPE_COUNT_MAP;
    $DIM_TYPE_COUNT_MAP{$G_ATTR_vcs_ceff_index} = $csv_vcs_ceff_index_count;
    $DIM_TYPE_COUNT_MAP{$G_ATTR_vdd_ceff_index} = $csv_vdd_ceff_index_count;
    $DIM_TYPE_COUNT_MAP{$G_ATTR_io_power_index} = $csv_io_power_index_count;
    $DIM_TYPE_COUNT_MAP{$G_ATTR_amb_cond_index} = $csv_amb_cond_index_count;
    $DIM_TYPE_COUNT_MAP{$G_ATTR_vratio_index}   = $csv_vratio_index_count;

    my $rows_start =
        $wof_tables_header->access( $DIM_TYPE_WOF_START_MAP{ $DIM_TYPE[$rows_index_order] } ) / 100;
    my $rows_step =
        $wof_tables_header->access( $DIM_TYPE_WOF_STEP_MAP{ $DIM_TYPE[$rows_index_order] } ) / 100;
    for ( my $index = 0; $index < $MAX_INDEX_COUNT; ++$index )
    {
        if ( $DIM_TYPE_VAL_MAP{ $DIM_TYPE[$index] } == -1 )
        {
            $DIM_INIT[$index]  = 0;
            $DIM_COUNT[$index] = $DIM_TYPE_COUNT_MAP{ $DIM_TYPE[$index] };
        }
        else
        {
            $DIM_INIT[$index]  = $DIM_TYPE_VAL_MAP{ $DIM_TYPE[$index] };
            $DIM_COUNT[$index] = 1;
        }
    }

    # temp storage to save and to print out.
    my @rows_cols_array = ();
    for ( my $index_loop0 = $DIM_INIT[0]; $index_loop0 < $DIM_INIT[0] + $DIM_COUNT[0]; $index_loop0++ )
    {
        # outermost loop
        $DIM_INDEX[0] = $index_loop0;
        for ( my $index_loop1 = $DIM_INIT[1]; $index_loop1 < $DIM_INIT[1] + $DIM_COUNT[1]; $index_loop1++ )
        {
            $DIM_INDEX[1] = $index_loop1;
            for ( my $index_loop2 = $DIM_INIT[2]; $index_loop2 < $DIM_INIT[2] + $DIM_COUNT[2]; $index_loop2++ )
            {
                $DIM_INDEX[2] = $index_loop2;
                for ( my $index_loop3 = $DIM_INIT[3]; $index_loop3 < $DIM_INIT[3] + $DIM_COUNT[3]; $index_loop3++ )
                {
                    $DIM_INDEX[3] = $index_loop3;
                    for ( my $index_loop4 = $DIM_INIT[4]; $index_loop4 < $DIM_INIT[4] + $DIM_COUNT[4]; $index_loop4++ )
                    {
                        # innermost loop
                        $DIM_INDEX[4] = $index_loop4;

                        # verify offset.

                        if (!$self->_verify_vrt_offset(
                                $section_number,
                                $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_vcs_ceff_index} ],
                                $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_vdd_ceff_index} ],
                                $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_io_power_index} ],
                                $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_amb_cond_index} ]
                            )
                            )
                        {
                            die "Error: Either Index values and" . " percent values in VRT are invalid.\n";
                        }

                        # get offset.
                        # Go to offset of specified VRE within image file
                        my $offset = $self->_get_vre_offset(
                            $section_number,
                            $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_vcs_ceff_index} ],
                            $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_vdd_ceff_index} ],
                            $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_io_power_index} ],
                            $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_amb_cond_index} ],
                            $DIM_INDEX[ $DIM_TYPE_ORDER_MAP{$G_ATTR_vratio_index} ]
                        );
                        $self->access($IMF_ATTR_binary_file_io)->set_pos($offset);

                        # Print VRT column headings
                        my $column_width = $convert_to_mhz ? 4 : 2;

                        # Read WOF frequency value in one-byte System VRT format from image file
                        my $wof_freq_sys = $self->access($IMF_ATTR_binary_file_io)->read_uint8();
                        $rows_cols_array[$index_loop3][$index_loop4] = $wof_freq_sys;
                    }
                }

                # display index names and values.
                printf("\n");
                printf( "%s = %s\n", $DIM_TYPE[0], $DIM_INDEX[0] );
                printf( "%s = %s\n", $DIM_TYPE[1], $DIM_INDEX[1] );
                printf( "%s = %s\n", $DIM_TYPE[2], $DIM_INDEX[2] );
                printf("\n");

                # display freq values.
                $self->_disp_view_vre_freq(
                    $DIM_TYPE[0],  $DIM_INDEX[0], $DIM_TYPE[1], $DIM_INDEX[1], $DIM_TYPE[2],
                    $DIM_INDEX[2], $rows_start,   $rows_step,   $DIM_TYPE[3],  $DIM_INIT[3],
                    $DIM_COUNT[3], $DIM_TYPE[4],  $DIM_INIT[4], $DIM_COUNT[4], \@rows_cols_array
                );

                # display ceff_ratio_overage values.
                $self->_disp_view_vre_overage(
                    $DIM_TYPE[0],  $DIM_INDEX[0], $DIM_TYPE[1], $DIM_INDEX[1], $DIM_TYPE[2],
                    $DIM_INDEX[2], $rows_start,   $rows_step,   $DIM_TYPE[3],  $DIM_INIT[3],
                    $DIM_COUNT[3], $DIM_TYPE[4],  $DIM_INIT[4], $DIM_COUNT[4], \@rows_cols_array
                );
            }
        }
    }
}

sub _disp_view_vre
{
    my ($self,             $dim0_index_name, $dim0_index_value, $dim1_index_name,
        $dim1_index_value, $dim2_index_name, $dim2_index_value, $rows_start,
        $rows_step,        $outrows_name,    $outrows_init,     $outrows_count,
        $outcols_name,     $outcols_init,    $outcols_count,    $rows_cols_array_ref
    ) = @_;
    Log::log_print $p_log_lvl, "_disp_view_vre():\n";
    Log::log_print $p_log_lvl, "  outrows_name: $outrows_name.\n";
    Log::log_print $p_log_lvl, "  outcols_name: $outcols_name.\n";
    my @rows_cols_array = @$rows_cols_array_ref;
    printf("System VRE\n");
    printf( "Rows: %s\n",    $outrows_name );
    printf( "Columns: %s\n", $outcols_name );

    # header of table to display
    printf( $fmt_str1, "idx" );
    printf( $fmt_str1, "CR" );
    for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_count; $index_outcols++ )
    {
        printf( $fmt_dec, $index_outcols );
    }
    printf("\n");

    # display them.
    for ( my $index_outrows = $outrows_init; $index_outrows < $outrows_count; $index_outrows++ )
    {
        my $cr = $rows_start + $rows_step * $index_outrows;
        printf( $fmt_dec2, $index_outrows );
        printf( $fmt_dec2, $cr );
        for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_count; $index_outcols++ )
        {
            # innermost loop
            printf( $fmt_dec, $rows_cols_array[$index_outrows][$index_outcols] );
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

sub _disp_view_vre_freq
{
    my ($self,             $dim0_index_name, $dim0_index_value, $dim1_index_name,
        $dim1_index_value, $dim2_index_name, $dim2_index_value, $rows_start,
        $rows_step,        $outrows_name,    $outrows_init,     $outrows_count,
        $outcols_name,     $outcols_init,    $outcols_count,    $rows_cols_array_ref
    ) = @_;
    Log::log_print $p_log_lvl, "_disp_view_vre_freq():\n";
    Log::log_print $p_log_lvl, "  outrows_name: $outrows_name.\n";
    Log::log_print $p_log_lvl, "  outcols_name: $outcols_name.\n";
    my @rows_cols_array = @$rows_cols_array_ref;
    printf("Frequqency values only\n");
    printf( "Rows: %s\n",    $outrows_name );
    printf( "Columns: %s\n", $outcols_name );

    # header of table to display
    printf( $fmt_str1, "idx" );
    printf( $fmt_str1, "CR" );
    for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_init + $outcols_count; $index_outcols++ )
    {
        printf( $fmt_dec, $index_outcols );
    }
    printf("\n");

    # display them.
    for ( my $index_outrows = $outrows_init; $index_outrows < $outrows_init + $outrows_count; $index_outrows++ )
    {
        my $cr = $rows_start + $rows_step * $index_outrows;
        printf( $fmt_dec2, $index_outrows );
        printf( $fmt_dec2, $cr );
        for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_init + $outcols_count; $index_outcols++ )
        {
            # innermost loop
            my $vre = $rows_cols_array[$index_outrows][$index_outcols];
            my $freq;
            if ( $vre < 64 )
            {
                $freq = 0;
            }
            else
            {
                $freq = 1000 + 16.667 * ( $vre - 60 );
            }
            printf( $fmt_dec, $freq );
        }
        printf("\n");
    }
    printf("\n");
}

sub _disp_view_vre_overage
{
    my ($self,             $dim0_index_name, $dim0_index_value, $dim1_index_name,
        $dim1_index_value, $dim2_index_name, $dim2_index_value, $rows_start,
        $rows_step,        $outrows_name,    $outrows_init,     $outrows_count,
        $outcols_name,     $outcols_init,    $outcols_count,    $rows_cols_array_ref
    ) = @_;
    Log::log_print $p_log_lvl, "_disp_view_vre_overage():\n";
    Log::log_print $p_log_lvl, "  outrows_name: $outrows_name.\n";
    Log::log_print $p_log_lvl, "  outcols_name: $outcols_name.\n";
    my @rows_cols_array = @$rows_cols_array_ref;
    printf("Overage values only\n");
    printf( "Rows: %s\n",    $outrows_name );
    printf( "Columns: %s\n", $outcols_name );

    # header of table to display
    printf( $fmt_str1, "idx" );
    printf( $fmt_str1, "CR" );
    for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_init + $outcols_count; $index_outcols++ )
    {
        printf( $fmt_dec, $index_outcols );
    }
    printf("\n");

    # display them.
    for ( my $index_outrows = $outrows_init; $index_outrows < $outrows_init + $outrows_count; $index_outrows++ )
    {
        my $cr = $rows_start + $rows_step * $index_outrows;
        printf( $fmt_dec2, $index_outrows );
        printf( $fmt_dec2, $cr );
        for ( my $index_outcols = $outcols_init; $index_outcols < $outcols_init + $outcols_count; $index_outcols++ )
        {
            # innermost loop
            my $vre = $rows_cols_array[$index_outrows][$index_outcols];
            my $ceff_ratio_overage;
            if ( $vre >= 64 )
            {
                $ceff_ratio_overage = 0;
            }
            else
            {
                $ceff_ratio_overage = 0.015625 * $vre;
            }
            Log::log_print $p_log_lvl, "  vre: $vre.\n";
            Log::log_print $p_log_lvl, "  ceff_ratio_overage: $ceff_ratio_overage.\n";
            printf( $fmt_flo, $ceff_ratio_overage );
        }
        printf("\n");
    }
    printf("\n");
}

sub _verify_vrt_offset
{
    my ( $self, $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index ) = @_;
    Log::log_print $p_log_lvl, "_verify_vrt_offset():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Get section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);
    if ( !defined($entry) )
    {
        die "Error: No Section Table Entry for section number:  $section_number.\n";
    }

    # Set image file offset to the start of the section
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read the WOF Tables Header at the start of the section
    my $wof_tables_header = $self->_read_wof_tables_header();

    # Get sizes from WOF Header fields used to calculate offset
    my $vrt_block_size = $wof_tables_header->access($WOF_ATTR_vrt_block_size);
    my $vcs_ceff_size  = $wof_tables_header->access($WOF_ATTR_vcs_size);
    my $vdd_ceff_size  = $wof_tables_header->access($WOF_ATTR_vdd_size);
    my $io_power_size  = $wof_tables_header->access($WOF_ATTR_io_power_size);
    my $amb_cond_size  = $wof_tables_header->access($WOF_ATTR_amb_cond_size);

    # Calculate absolute offset to VRT within image file.  We just read the WOF
    # Tables Header, so the current file offset is at the first VRT.  The VRTs
    # are stored in a three-dimensional array within the file, where the first
    # dimension is vcs_ceff_index, and follows with dimensions: vdd_ceff_index,
    # io_power_index, amb_cond_index.
    my $vrt_offset =
        $self->access($IMF_ATTR_binary_file_io)->get_pos() +
        ( $vcs_ceff_index * $vdd_ceff_size * $io_power_size * $amb_cond_size +
            $vdd_ceff_index * $io_power_size * $amb_cond_size +
            $io_power_index * $amb_cond_size +
            $amb_cond_index ) *
        $vrt_block_size;

    $self->access($IMF_ATTR_binary_file_io)->set_pos($vrt_offset);

    # Read VRT Header values VRT format from image file
    my $vrt_header = $self->_read_vrt_header();

    my $vrth_io_id  = $vrt_header->access($VRTH_ATTR_io_index);
    my $vrth_ac_id  = $vrt_header->access($VRTH_ATTR_ac_index);
    my $vrth_vcs_id = $vrt_header->access($VRTH_ATTR_vcs_index);
    my $vrth_vdd_id = $vrt_header->access($VRTH_ATTR_vdd_index);

    if (   ( $io_power_index != $vrth_io_id )
        || ( $amb_cond_index != $vrth_ac_id )
        || ( $vcs_ceff_index != $vrth_vcs_id )
        || ( $vdd_ceff_index != $vrth_vdd_id ) )
    {
        return 0;
    }

    return 1;
}

sub _get_vrt_offset
{
    my ( $self, $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index ) = @_;
    Log::log_print $p_log_lvl, "_get_vrt_offset():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Get section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);
    if ( !defined($entry) )
    {
        die "Error: No Section Table Entry for section number:  $section_number.\n";
    }

    # Set image file offset to the start of the section
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read the WOF Tables Header at the start of the section
    my $wof_tables_header = $self->_read_wof_tables_header();

    # Get sizes from WOF Header fields used to calculate offset
    my $vrt_block_size = $wof_tables_header->access($WOF_ATTR_vrt_block_size);
    my $vcs_ceff_size  = $wof_tables_header->access($WOF_ATTR_vcs_size);
    my $vdd_ceff_size  = $wof_tables_header->access($WOF_ATTR_vdd_size);
    my $io_power_size  = $wof_tables_header->access($WOF_ATTR_io_power_size);
    my $amb_cond_size  = $wof_tables_header->access($WOF_ATTR_amb_cond_size);

    # Calculate absolute offset to VRT within image file.  We just read the WOF
    # Tables Header, so the current file offset is at the first VRT.  The VRTs
    # are stored in a three-dimensional array within the file, where the first
    # dimension is vcs_ceff_index, and follows with dimensions: vdd_ceff_index,
    # io_power_index, amb_cond_index.
    my $vrt_offset =
        $self->access($IMF_ATTR_binary_file_io)->get_pos() +
        ( $vcs_ceff_index * $vdd_ceff_size * $io_power_size * $amb_cond_size +
            $vdd_ceff_index * $io_power_size * $amb_cond_size +
            $io_power_index * $amb_cond_size +
            $amb_cond_index ) *
        $vrt_block_size;

    return $vrt_offset;
}

sub _get_vre_offset
{
    my ( $self, $section_number, $vcs_ceff_index, $vdd_ceff_index, $io_power_index, $amb_cond_index, $vratio_index ) =
        @_;
    Log::log_print $p_log_lvl, "_get_vrt_offset():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";

    # Get section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);
    if ( !defined($entry) )
    {
        die "Error: No Section Table Entry for section number:  $section_number.\n";
    }

    # Set image file offset to the start of the section
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read the WOF Tables Header at the start of the section
    my $wof_tables_header = $self->_read_wof_tables_header();

    # Get sizes from WOF Header fields used to calculate offset
    my $vrt_block_size = $wof_tables_header->access($WOF_ATTR_vrt_block_size);
    my $vcs_ceff_size  = $wof_tables_header->access($WOF_ATTR_vcs_size);
    my $vdd_ceff_size  = $wof_tables_header->access($WOF_ATTR_vdd_size);
    my $io_power_size  = $wof_tables_header->access($WOF_ATTR_io_power_size);
    my $amb_cond_size  = $wof_tables_header->access($WOF_ATTR_amb_cond_size);

    # Calculate absolute offset to VRT within image file.  We just read the WOF
    # Tables Header, so the current file offset is at the first VRT.  The VRTs
    # are stored in a three-dimensional array within the file, where the first
    # dimension is vcs_ceff_index, and follows with dimensions: vdd_ceff_index,
    # io_power_index, amb_cond_index.
    my $vrt_offset =
        $self->access($IMF_ATTR_binary_file_io)->get_pos() +
        ( $vcs_ceff_index * $vdd_ceff_size * $io_power_size * $amb_cond_size +
            $vdd_ceff_index * $io_power_size * $amb_cond_size +
            $io_power_index * $amb_cond_size +
            $amb_cond_index ) *
        $vrt_block_size;

    # to get vre offset, first skip 4 bytes for VRT Header. Then skip the bytes of
    # the number of vre's.
    my $vre_offset = $vrt_offset + 4 + $vratio_index;
    return $vre_offset;
}

#
# before calling this function, the file pointer must be set using
# set_pos() function.
#
sub _print_vrt_header_by_index
{
    my ( $self, $section_number, $vrt_index ) = @_;
    Log::log_print $p_log_lvl, "_print_vrt_header_by_index():\n";

    # Create VRT header
    my $vrt_header = VRTHeader->new();

    my $vrt_offset = $self->_get_vrt_offset_by_index( $section_number, $vrt_index );

    print "VRT index: $vrt_index, ";
    print "VRT offset: $vrt_offset\n";

    # set file pointer to the vrt block again.
    $self->access($IMF_ATTR_binary_file_io)->set_pos($vrt_offset);
    my $uint8_val;
    print "VRT Block: ";
    for ( my $i = 0; $i < 16; ++$i )
    {
        $uint8_val = $self->access($IMF_ATTR_binary_file_io)->read_uint8();
        printf( "%02x", $uint8_val );
        if ( $i != ( 16 - 1 ) )
        {
            print " ";
        }
        else
        {
            print "\n";
        }
    }

    # set file pointer to the vrt block again.
    $self->access($IMF_ATTR_binary_file_io)->set_pos($vrt_offset);

    # print header from image file
    $vrt_header->print( $self->access($IMF_ATTR_binary_file_io) );

}

sub _get_vrt_offset_by_index
{
    my ( $self, $section_number, $vrt_index ) = @_;

    Log::log_print $p_log_lvl, "_get_vrt_offset_by_index():\n";
    Log::log_print $p_log_lvl, "  section_number: $section_number.\n";
    Log::log_print $p_log_lvl, "  vrt_index: $vrt_index.\n";

    # validate $section_number
    if ( !defined($section_number) )
    {
        die "Error: Option section_number $section_number is note defined.\n";
    }
    else
    {
        if (   ( $section_number < 0 )
            || ( $section_number >= $self->access($IMF_ATTR_section_table)->entry_count() ) )
        {
            die "Error: Option section_number $section_number is invalid.\n";
        }
    }

    # Get section table entry
    my $entry = $self->access($IMF_ATTR_section_table)->get_entry($section_number);
    if ( !defined($entry) )
    {
        die "Error: No Section Table Entry for section number:  $section_number.\n";
    }

    # Set image file offset to the start of the section table
    $self->access($IMF_ATTR_binary_file_io)->set_pos( $entry->access($STE_ATTR_section_offset) );

    # Read the WOF Tables Header at the start of the section
    my $wof_tables_header = $self->_read_wof_tables_header();

    # Get sizes from WOF Header fields used to calculate offset
    my $vrt_block_size = $wof_tables_header->access($WOF_ATTR_vrt_block_size);
    my $vcs_ceff_size  = $wof_tables_header->access($WOF_ATTR_vcs_size);
    my $vdd_ceff_size  = $wof_tables_header->access($WOF_ATTR_vdd_size);
    my $io_power_size  = $wof_tables_header->access($WOF_ATTR_io_power_size);
    my $amb_cond_size  = $wof_tables_header->access($WOF_ATTR_amb_cond_size);

    my $max_vrt_index = ( $vcs_ceff_size * $vdd_ceff_size * $io_power_size * $amb_cond_size ) - 1;

    if ( defined($vrt_index) )
    {
        if (   ( $vrt_index < 0 )
            || ( $vrt_index > $max_vrt_index ) )
        {
            die "Error: Option vrt_index $vrt_index is invalid.\n";
        }
    }

    # Calculate absolute offset to VRT within image file.  We have just read the WOF
    # Tables Header, so the current file offset is at the first VRT.  The VRTs
    # are stored in a three-dimensional array within the file, where the first
    # dimension is vcs_ceff_index, and follows with dimensions: vdd_ceff_index,
    # io_power_index, amb_cond_index.
    my $vrt_offset = $self->access($IMF_ATTR_binary_file_io)->get_pos() + $vrt_index * $vrt_block_size;
    return $vrt_offset;
}

#
# before calling this function, the file pointer must be set using
# set_pos() function.
#
sub _read_vrt_header
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_vrt_header():\n";

    # Create VRT header
    my $vrt_header = VRTHeader->new();

    # Read header from image file
    $vrt_header->read( $self->access($IMF_ATTR_binary_file_io) );
    return $vrt_header;
}

sub _write_vrt_header
{
    my ( $self, $vrt, $csv_file, $wof_tables_header ) = @_;
    Log::log_print $p_log_lvl, "_write_vrt_header():\n";

    # Log::log_print $p_log_lvl, "  vrt: $vrt.\n";
    my $vcs_ceff_index = $vrt->access($VRT_ATTR_vcs_ceff_index);
    my $vdd_ceff_index = $vrt->access($VRT_ATTR_vdd_ceff_index);
    my $io_power_index = $vrt->access($VRT_ATTR_io_power_index);
    my $amb_cond_index = $vrt->access($VRT_ATTR_amb_cond_index);

    # Create VRT header
    my $vrt_header = VRTHeader->new();

    # Set header fields based on columns from CSV file.  CSV columns that contain
    # percentages are expressed as a decimal.  For example, 25% is 0.25.  Header
    # fields that contain percentages are expressed as integer percents.  For
    # example, 25% is 25.  Thus, we need to multiply the CSV percentage values by
    # 100 to convert to integer percents.
    $vrt_header->access( $VRTH_ATTR_io_index,  $vrt->access($VRT_ATTR_io_power_index) );
    $vrt_header->access( $VRTH_ATTR_ac_index,  $vrt->access($VRT_ATTR_amb_cond_index) );
    $vrt_header->access( $VRTH_ATTR_vcs_index, $vrt->access($VRT_ATTR_vcs_ceff_index) );
    $vrt_header->access( $VRTH_ATTR_vdd_index, $vrt->access($VRT_ATTR_vdd_ceff_index) );

    # Write header to image file
    $vrt_header->write( $self->access($IMF_ATTR_binary_file_io) );
}

sub _get_padding_count
{
    my ( $self, $file_offset ) = @_;
    Log::log_print $p_log_lvl, "_get_padding_count():\n";

    #  Log::log_print $p_log_lvl, "  file_offset: $file_offset.\n";
    # If a file offset was not specified, get the current file offset
    if ( !defined($file_offset) )
    {
        $file_offset = $self->access($IMF_ATTR_binary_file_io)->get_pos();
    }

    # Return the padding needed to reach the correct alignment boundary
    my $remainder = $file_offset % $IMAGE_FILE_BYTE_ALIGNMENT;
    return ( $remainder == 0 ) ? 0 : ( $IMAGE_FILE_BYTE_ALIGNMENT - $remainder );
}

sub _read_padding
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_padding():\n";
    my $padding_byte_count = $self->_get_padding_count();
    if ( $padding_byte_count > 0 )
    {
        # Skip forward past the padding bytes
        $self->access($IMF_ATTR_binary_file_io)->skip_bytes($padding_byte_count);
    }
}

sub _write_padding
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_write_padding():\n";
    my $padding_byte_count = $self->_get_padding_count();
    if ( $padding_byte_count > 0 )
    {
        # Write 0x00 in the padding bytes
        $self->access($IMF_ATTR_binary_file_io)->fill_bytes( $padding_byte_count, 0x00 );
    }
}

################################################################################
# OverrideHeader Class
#
# This class represents the Override Header within a WOF Tables Override File.
################################################################################
package OverrideHeader;
our $p_log_lvl = $LOG_LVL_0;

# Constants representing expected field values
our $OVERRIDE_HEADER_MAGIC_NUMBER = 'WTSO';
our $OVERRIDE_HEADER_VERSION      = 1;

# Header size in bytes
our $OVERRIDE_HEADER_SIZE = 32;

# Attribute names in this class
our $OVRH_ATTR_magic_number              = 'magic_number';
our $OVRH_ATTR_version                   = 'version';
our $OVRH_ATTR_section_table_entry_count = 'section_table_entry_count';
our $OVRH_ATTR_section_table_offset      = 'section_table_offset';
our $OVRH_ATTR_wof_override_id           = 'wof_override_id';

sub new
{
    my ($class) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $OVRH_ATTR_magic_number              => $OVERRIDE_HEADER_MAGIC_NUMBER,
        $OVRH_ATTR_version                   => $OVERRIDE_HEADER_VERSION,
        $OVRH_ATTR_section_table_entry_count => undef,
        $OVRH_ATTR_section_table_offset      => undef,
        $OVRH_ATTR_wof_override_id           => undef,
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;

    # Read field values from binary file
    my $magic_number              = $file->read_ascii_text(4);
    my $version                   = $file->read_uint8();
    my $section_table_entry_count = $file->read_uint8();
    $file->skip_bytes(2);    # skip padding 2 bytes for reserved.
    my $section_table_offset = $file->read_uint16();
    my $wof_override_id      = $file->read_ascii_text(16);
    $file->skip_bytes(6);    # skip padding 6 bytes for reserved.

    # set values to object's attributes.
    $self->access( $OVRH_ATTR_magic_number,              $magic_number );
    $self->access( $OVRH_ATTR_version,                   $version );
    $self->access( $OVRH_ATTR_section_table_entry_count, $section_table_entry_count );
    $self->access( $OVRH_ATTR_section_table_offset,      $section_table_offset );
    $self->access( $OVRH_ATTR_wof_override_id,           $wof_override_id );

    # Verify field values
    if ( $self->access($OVRH_ATTR_magic_number) ne $OVERRIDE_HEADER_MAGIC_NUMBER )
    {
        die "Error: Unexpected value in Magic Number field of Override Header: "
            . $self->access($OVRH_ATTR_magic_number) . "\n";
    }
    if ( $self->access($OVRH_ATTR_version) != $OVERRIDE_HEADER_VERSION )
    {
        die "Error: Unexpected value in Version field of Override Header: "
            . sprintf( "0x%02X", $self->access($OVRH_ATTR_version) ) . "\n";
    }
}

sub write
{
    my ( $self, $file ) = @_;

    # get values from object's attributes.
    my $magic_number              = $self->access($OVRH_ATTR_magic_number);
    my $version                   = $self->access($OVRH_ATTR_version);
    my $section_table_entry_count = $self->access($OVRH_ATTR_section_table_entry_count);
    my $section_table_offset      = $self->access($OVRH_ATTR_section_table_offset);
    my $wof_override_id           = $self->access($OVRH_ATTR_wof_override_id);

    # Write field values to binary file
    $file->write_ascii_text( $magic_number, 4 );
    $file->write_uint8($version);
    $file->write_uint8($section_table_entry_count);
    $file->fill_bytes( 2, 0x00 );    # padding 2 bytes for reserved.
    $file->write_uint16($section_table_offset);
    $file->write_ascii_text( $wof_override_id, 16 );
    $file->fill_bytes( 6, 0x00 );    # padding 6 bytes for reserved.
}

sub print
{
    my ($self) = @_;

    # Print header fields to stdout
    printf("Override Header:\n");
    printf( "  Magic Number             : %s\n",     $self->access($OVRH_ATTR_magic_number) );
    printf( "  Version                  : %u\n",     $self->access($OVRH_ATTR_version) );
    printf( "  Section Table Entry Count: %u\n",     $self->access($OVRH_ATTR_section_table_entry_count) );
    printf( "  Section Table Offset     : 0x%08X\n", $self->access($OVRH_ATTR_section_table_offset) );
    printf( "  Overrid ID               : %s\n",     $self->access($OVRH_ATTR_wof_override_id) );
    printf("\n");
}

################################################################################
# WTSTableEntry Class
#
# This class represents a WTS Table Entry within a WOF Tables Image File.
################################################################################
package WTSTableEntry;

# Attribute names in this class
our $WTSTE_ATTR_wfs_offset            = 'wfs_offset';
our $WTSTE_ATTR_wfs_size              = 'wfs_size';
our $WTSTE_ATTR_major_dd_level        = 'major_dd_level';
our $WTSTE_ATTR_minor_dd_level        = 'minor_dd_level';
our $WTSTE_ATTR_core_count            = 'core_count';
our $WTSTE_ATTR_socket_power_w        = 'socket_power_w';
our $WTSTE_ATTR_sort_pwr_tgt_freq_mhz = 'sort_pwr_tgt_freq_mhz';
our $WTSTE_ATTR_package_name          = 'package_name';

# Size of WTS Table Entry.
# Please verify this value when the layout of WTS Table Entry is updated.
our $WTS_TABLE_ENTRY_SIZE = 32;

sub new
{
    my ($class) = @_;
    my $self = {
        $WTSTE_ATTR_wfs_offset            => undef,
        $WTSTE_ATTR_wfs_size              => undef,
        $WTSTE_ATTR_major_dd_level        => undef,
        $WTSTE_ATTR_minor_dd_level        => undef,
        $WTSTE_ATTR_core_count            => undef,
        $WTSTE_ATTR_socket_power_w        => undef,
        $WTSTE_ATTR_sort_pwr_tgt_freq_mhz => undef,
        $WTSTE_ATTR_package_name          => undef,
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub read
{
    my ( $self, $file ) = @_;

    # Read field values from binary file
    $self->access( $WTSTE_ATTR_wfs_offset,     $file->read_uint32() );
    $self->access( $WTSTE_ATTR_wfs_size,       $file->read_uint32() );
    $self->access( $WTSTE_ATTR_major_dd_level, $file->read_uint8() );
    $self->access( $WTSTE_ATTR_minor_dd_level, $file->read_uint8() );
    $file->skip_bytes(1);    # skip padding 1 bytes for reserved.
    $self->access( $WTSTE_ATTR_core_count,            $file->read_uint8() );
    $self->access( $WTSTE_ATTR_socket_power_w,        $file->read_uint16() );
    $self->access( $WTSTE_ATTR_sort_pwr_tgt_freq_mhz, $file->read_uint16() );
    $self->access( $WTSTE_ATTR_package_name,          $file->read_ascii_text(16) );
}

sub write
{
    my ( $self, $file ) = @_;

    # Write field values to binary file
    $file->write_uint32( $self->access($WTSTE_ATTR_wfs_offset) );
    $file->write_uint32( $self->access($WTSTE_ATTR_wfs_size) );
    $file->write_uint8( $self->access($WTSTE_ATTR_major_dd_level) );
    $file->write_uint8( $self->access($WTSTE_ATTR_minor_dd_level) );
    $file->fill_bytes( 1, 0x00 );    # padding 1 bytes for reserved.
    $file->write_uint8( $self->access($WTSTE_ATTR_core_count) );
    $file->write_uint16( $self->access($WTSTE_ATTR_socket_power_w) );
    $file->write_uint16( $self->access($WTSTE_ATTR_sort_pwr_tgt_freq_mhz) );
    $file->write_ascii_text( $self->access($WTSTE_ATTR_package_name), 16 );
}

sub print
{
    my ( $self, $file ) = @_;

    print( "   " . "$WTSTE_ATTR_wfs_offset: " . $self->access($WTSTE_ATTR_wfs_offset) . "\n" );
    print( "   " . "$WTSTE_ATTR_wfs_size: " . $self->access($WTSTE_ATTR_wfs_size) . "\n" );
    print( "   " . "$WTSTE_ATTR_major_dd_level: " . $self->access($WTSTE_ATTR_major_dd_level) . "\n" );
    print( "   " . "$WTSTE_ATTR_minor_dd_level: " . $self->access($WTSTE_ATTR_minor_dd_level) . "\n" );
    print( "   " . "$WTSTE_ATTR_core_count: " . $self->access($WTSTE_ATTR_core_count) . "\n" );
    print( "   " . "$WTSTE_ATTR_socket_power_w: " . $self->access($WTSTE_ATTR_socket_power_w) . "\n" );
    print( "   " . "$WTSTE_ATTR_sort_pwr_tgt_freq_mhz: " . $self->access($WTSTE_ATTR_sort_pwr_tgt_freq_mhz) . "\n" );
    print( "   " . "$WTSTE_ATTR_package_name: " . $self->access($WTSTE_ATTR_package_name) . "\n" );
}

################################################################################
# OverrideSectionTable Class
#
# This class represents the Section Table within a WOF Tables Image File.
################################################################################
package OverrideSectionTable;
our $p_log_lvl = $LOG_LVL_0;

sub new
{
    my ($class) = @_;
    my $self = [];    # anonymous array
    bless($self);
    return $self;
}

sub entry_count
{
    my ($self) = @_;
    return scalar(@$self);
}

sub clear
{
    my ($self) = @_;
    @$self = ();
}

sub add_entry
{
    my ( $self, $entry ) = @_;
    push( @$self, $entry );
}

sub get_entry
{
    my ( $self, $index ) = @_;
    return $self->[$index];
}

sub read
{
    my ( $self, $file, $entry_count ) = @_;

    # Clear out any current entries in table
    $self->clear();

    # Read entries from binary file
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = WTSTableEntry->new();

        # read entry info of Section Table Entry from file.
        $entry->read($file);

        # and save the entry to array of Section Table
        $self->add_entry($entry);
    }
}

sub write
{
    my ( $self, $file ) = @_;

    # Write entries to binary file
    my $entry_count = $self->entry_count();
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = $self->get_entry($i);
        $entry->write($file);
    }
}

sub write_empty_entries
{
    my ( $self, $file ) = @_;

    # Write entries to binary file
    my $entry_count = $self->entry_count();
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = $self->get_entry($i);
        $entry->access( $WTSTE_ATTR_wfs_offset,            0xFFFFFFFF );
        $entry->access( $WTSTE_ATTR_wfs_size,              0xFFFFFFFF );
        $entry->access( $WTSTE_ATTR_major_dd_level,        0xFF );
        $entry->access( $WTSTE_ATTR_minor_dd_level,        0xFF );
        $entry->access( $WTSTE_ATTR_core_count,            0xFF );
        $entry->access( $WTSTE_ATTR_socket_power_w,        0xFFFF );
        $entry->access( $WTSTE_ATTR_sort_pwr_tgt_freq_mhz, 0xFFFF );
        $entry->access( $WTSTE_ATTR_package_name,          "0123456789abcdef" );
        $entry->write($file);
    }
}

sub print
{
    my ($self) = @_;

    # Print section table to stdout
    printf("Section Table\n");
    my $entry_count = $self->entry_count();
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        # Print section table entry fields to stdout
        my $entry = $self->get_entry($i);
        printf(" Entry #: $i\n");
        $entry->print();
    }
    printf("\n");
}

################################################################################
# OverrideFile Class
#
# This class represents a WOF Tables Override File.
#
# The file format is described in detail by the documents referenced at the
# beginning of this script.
#
# A WOF Tables Override File is a binary file in big-endian format.  Major data
# structures are aligned on 8 byte boundaries.  The file begins with an Override
# File Header, followed by a Section Table, followed by one or more sections.
# Each section contains a WOF Tables Header followed by all of the VRTs for one
# SPWBF (Socket Power and WOF Base Frequency) combination.
################################################################################
package OverrideFile;
use File::Basename;
our $p_log_lvl                    = $LOG_LVL_0;
our $OVERRIDE_FILE_BYTE_ALIGNMENT = 8;

our $FILE_COPY_BUFFER_SIZE = 1024;

# Attribute names in this class
our $OVRF_ATTR_binary_file_io  = 'file';
our $OVRF_ATTR_override_header = 'override_header';
our $OVRF_ATTR_section_table   = 'section_table';

sub new
{
    my ( $class, $file_name ) = @_;

    # check to use global logging level.
    #  $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $OVRF_ATTR_binary_file_io  => BinaryFileIO->new($file_name),
        $OVRF_ATTR_override_header => OverrideHeader->new(),
        $OVRF_ATTR_section_table   => OverrideSectionTable->new(),
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub combine
{
    my ( $self, $dd_level, $override_id, @combine_file_names ) = @_;
    Log::log_print $p_log_lvl, "combine():\n";

    # Open override file for writing
    $self->access($OVRF_ATTR_binary_file_io)->open('w');

    # Write override file contents
    $self->_write_override_file( $dd_level, $override_id, @combine_file_names );

    # Close override file
    $self->access($OVRF_ATTR_binary_file_io)->close();
}

sub list_ovr
{
    my ( $self, $section_number ) = @_;

    Log::log_print $p_log_lvl, "list_ovr():\n";

    # Open override file for reading
    $self->access($OVRF_ATTR_binary_file_io)->open('r');

    # Read and print override header
    $self->_read_override_header();
    $self->access($OVRF_ATTR_override_header)->print();

    # Read section table Section Table pointed by into Section Table attribute,
    # and file pointer is set file pointer to the end of Section Table.
    $self->_read_override_table();

    # Print section table
    $self->access($OVRF_ATTR_section_table)->print();

    # Close override file
    $self->access($OVRF_ATTR_binary_file_io)->close();
}

sub split_ovr_file
{
    my ($self) = @_;

    Log::log_print $p_log_lvl, "split_ovr_file():\n";

    # Open override file for reading
    $self->access($OVRF_ATTR_binary_file_io)->open('r');

    # Read override header to populate it in object.
    $self->_read_override_header();
    my $entry_count = $self->access($OVRF_ATTR_override_header)->access($OVRH_ATTR_section_table_entry_count);

    # Read section table Section Table pointed by into Section Table attribute,
    # and file pointer is set file pointer to the end of Section Table.
    $self->_split_override_file($entry_count);

    # Close override file
    $self->access($OVRF_ATTR_binary_file_io)->close();
}

#------------------------------------------------------------------------------
# Private methods
#------------------------------------------------------------------------------
sub _write_override_file
{
    my ( $self, $dd_level, $override_id, @combine_file_names ) = @_;
    Log::log_print $p_log_lvl, "_write_override_file():\n";

    my $image_file;
    my $wfs_offset;
    my $wfs_size;
    my $major_dd_level;
    my $minor_dd_level;
    my $core_count;
    my $socket_power_w;
    my $sort_pwr_tgt_freq_mhz;
    my $override_match_power;
    my $override_match_freq_mhz;
    my $package_name;
    my $entry;

    my $major_dd_level_in_option;
    my $minor_dd_level_in_option;
    if ( defined($dd_level) )
    {
        $major_dd_level_in_option = substr( $dd_level, 0, 1 );
        $minor_dd_level_in_option = substr( $dd_level, 1, 1 );
    }

    # Write override header to override file.
    my $section_count = scalar(@combine_file_names);
    $self->_write_override_header( $section_count, $override_id );

    my $override_table_pos = $self->access($OVRF_ATTR_binary_file_io)->get_pos();

    # Write section table for all entries to reserve spaces in the table.
    # It overrides file with default section offsets/sizes.
    $self->_write_override_table();

    # get beginning address of first WTS Table.
    my $next_wts_table_set_pos = $self->access($OVRF_ATTR_binary_file_io)->get_pos();

    # file position is WTS_Table. Set it to Override Table.
    $self->access($OVRF_ATTR_binary_file_io)->set_pos($override_table_pos);

    for ( my $i = 0; $i < $section_count; $i++ )
    {
        if ( !-e $combine_file_names[$i] )
        {
            die "Error - The file, $combine_file_names[$i], not exists.";
        }

        # Get current file offset.  This is the offset to the start of the section.
        $image_file = ImageFile->new( $combine_file_names[$i] );

        # Get WOF table info from the input image file.
        (   $major_dd_level, $minor_dd_level, $core_count, $socket_power_w, $sort_pwr_tgt_freq_mhz,
            $override_match_power, $override_match_freq_mhz, $package_name
        ) = $image_file->retrieve_wof_table_header(0);

        my $filesize = -s $combine_file_names[$i];
        if ( $filesize <= 0 )
        {
            die "Error: file size is not positive, size: $filesize\n";
        }

        # Store section offset and size in section table entry
        # of output file.
        $entry = $self->access($OVRF_ATTR_section_table)->get_entry($i);
        if ( !defined($entry) )
        {
            die "Error: No Section Table Entry for section number:  $i.\n";
        }

        # Update wfs offset and size for current file.
        $wfs_offset = $next_wts_table_set_pos;
        $wfs_size   = $filesize;

        # if dd_level is specified in command option,
        # the values are derived from command opition.
        # if dd_level is not specified in command option,
        # the value from input image file will be used.
        if ( defined($dd_level) )
        {
            $major_dd_level = $major_dd_level_in_option;
            $minor_dd_level = $minor_dd_level_in_option;
        }

        ( $socket_power_w, $sort_pwr_tgt_freq_mhz ) =
            $self->_evaluate_override_match( $socket_power_w, $sort_pwr_tgt_freq_mhz,
            $override_match_power, $override_match_freq_mhz );

        $entry->access( $WTSTE_ATTR_wfs_offset,            $wfs_offset );
        $entry->access( $WTSTE_ATTR_wfs_size,              $wfs_size );
        $entry->access( $WTSTE_ATTR_major_dd_level,        $major_dd_level );
        $entry->access( $WTSTE_ATTR_minor_dd_level,        $minor_dd_level );
        $entry->access( $WTSTE_ATTR_core_count,            $core_count );
        $entry->access( $WTSTE_ATTR_socket_power_w,        $socket_power_w );
        $entry->access( $WTSTE_ATTR_sort_pwr_tgt_freq_mhz, $sort_pwr_tgt_freq_mhz );
        $entry->access( $WTSTE_ATTR_package_name,          $package_name );

        # calculate position of next wfs table entry.
        my $current_wts_table_entry_pos = $override_table_pos + $WTS_TABLE_ENTRY_SIZE * $i;

        # set position of override file to the beginning of wfs table entry.
        $self->access($OVRF_ATTR_binary_file_io)->set_pos($current_wts_table_entry_pos);
        $entry->write( $self->access($OVRF_ATTR_binary_file_io) );

        # set position of override file to next wfs table set.
        $self->access($OVRF_ATTR_binary_file_io)->set_pos($next_wts_table_set_pos);

        # Write section to override file.
        $self->_copy_file_to_binary_wts( $combine_file_names[$i] );

        # make sure the position is set to end of the output file.
        # Then position is the beginning of next write, that is the offset.
        $wfs_offset = $self->access($OVRF_ATTR_binary_file_io)->get_pos();

        # save wts position for next file.
        $next_wts_table_set_pos += $filesize;

        if ( $next_wts_table_set_pos != $wfs_offset )
        {
            die
                "two variable should be same, but not. next_wts_table_set_pos: $next_wts_table_set_pos, wfs_offset: $wfs_offset\n";
        }
    }
}

sub _evaluate_override_match
{
    my ( $self, $socket_power_w, $sort_pwr_tgt_freq_mhz, $override_match_power, $override_match_freq_mhz ) = @_;

    Log::log_print $p_log_lvl, "_evaluate_override_match():\n";

    if ( $override_match_power ne 0 )
    {
        $socket_power_w = $override_match_power;
    }

    if ( $override_match_freq_mhz ne 0 )
    {
        $sort_pwr_tgt_freq_mhz = $override_match_freq_mhz;
    }

    return ( $socket_power_w, $sort_pwr_tgt_freq_mhz );
}

sub _split_override_file
{
    my ( $self, $section_count ) = @_;
    Log::log_print $p_log_lvl, "_write_override_file():\n";

    my $image_file;
    my $wfs_offset;
    my $wfs_size;
    my $entry;

    my $split_tag = "split";

    # set pos to beginning of the file.
    $self->access($OVRF_ATTR_binary_file_io)->set_pos(0);
    $self->_read_override_header($section_count);

    # get the pos of override table for later use.
    my $override_table_pos = $self->access($OVRF_ATTR_binary_file_io)->get_pos();

    # Read override table so that it will populate entry table.
    $self->_read_override_table();

    my $override_file_name = $self->access($OVRF_ATTR_binary_file_io)->file_name();

    # get file's extension.
    my ( $file, $dir, $ext ) = fileparse( $override_file_name, qr/\.\D.*/ );

    # remove the extention from the file path.
    $override_file_name =~ s/$ext$//g;

    for ( my $i = 0; $i < $section_count; $i++ )
    {
        # fabricate the new file path.
        my $split_file_name = $override_file_name . "_" . $split_tag . "_" . $i . $ext;

        # Get current file offset.  This is the offset to the start of the section.
        $image_file = ImageFile->new($split_file_name);

        # Store section offset and size in section table entry
        # of output file.
        $entry = $self->access($OVRF_ATTR_section_table)->get_entry($i);
        if ( !defined($entry) )
        {
            die "Error: No Section Table Entry for section number:  $i.\n";
        }

        $wfs_offset = $entry->access($WTSTE_ATTR_wfs_offset);
        $wfs_size   = $entry->access($WTSTE_ATTR_wfs_size);

        # copy from Image File to external file.

        # calculate position of next wfs table entry.
        my $current_wts_table_entry_pos = $override_table_pos + $WTS_TABLE_ENTRY_SIZE * $i;

        # set position of override file to next wfs table set.
        $self->access($OVRF_ATTR_binary_file_io)->set_pos($wfs_offset);

        # Write section to override file.
        $self->_copy_binary_wts_to_file( $split_file_name, $wfs_size );
    }
}

sub _read_override_header
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_override_header():\n";

    # Read override header from override file
    $self->access($OVRF_ATTR_override_header)->read( $self->access($OVRF_ATTR_binary_file_io) );

    # Read past any padding
    # The data structure is defined so that this is not needed. Comment it out.
    # $self->_read_padding();
}

sub _write_override_header
{
    my ( $self, $section_count, $override_id ) = @_;
    Log::log_print $p_log_lvl, "_write_override_header():\n";
    Log::log_print $p_log_lvl, "  section_count: $section_count.\n";

    # Set the Section Table Entry Count field
    $self->{$OVRF_ATTR_override_header}->access( $OVRH_ATTR_section_table_entry_count, $section_count );

    my $section_table_offset = $OVERRIDE_HEADER_SIZE;
    $self->{$OVRF_ATTR_override_header}->access( $OVRH_ATTR_section_table_offset, $section_table_offset );

    # set overrid id.
    $self->{$OVRF_ATTR_override_header}->access( $OVRH_ATTR_wof_override_id, $override_id );

    # Write override header to override file
    $self->{$OVRF_ATTR_override_header}->write( $self->access($OVRF_ATTR_binary_file_io) );

    # The data structure is defined as 32 bytes, and padding is not needed.
}

sub _read_override_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_override_table():\n";

    # Get number of section table entries from override header
    my $entry_count = $self->{$OVRF_ATTR_override_header}->access($OVRH_ATTR_section_table_entry_count);

    # Read section table from override file
    $self->access($OVRF_ATTR_section_table)->read( $self->access($OVRF_ATTR_binary_file_io), $entry_count );

    # Read past any padding following the section table
    # The data structure is defined so that this is not needed. Comment it out.
    # $self->_read_padding();
}

sub _write_override_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_write_override_table():\n";

    # Clear current contents of section table
    $self->access($OVRF_ATTR_section_table)->clear();

    # Get number of section table entries from override header
    my $entry_count = $self->{$OVRF_ATTR_override_header}->access($OVRH_ATTR_section_table_entry_count);

    # Add section table entries with default section offsets/sizes
    for ( my $i = 0; $i < $entry_count; $i++ )
    {
        my $entry = WTSTableEntry->new();
        $self->access($OVRF_ATTR_section_table)->add_entry($entry);
    }

    # Write section table to override file
    $self->access($OVRF_ATTR_section_table)->write_empty_entries( $self->access($OVRF_ATTR_binary_file_io) );

    # Write any necessary padding so table ends on proper byte boundary
    # The data structure is defined so that this is not needed. Comment it out.
    # $self->_write_padding();
}

sub _update_override_table
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_update_override_table():\n";

    # Get offset to the section table from the override header
    my $section_table_offset = $self->access($OVRF_ATTR_override_header)->access($OVRH_ATTR_section_table_offset);

    # Move to section table offset within override file
    $self->access($OVRF_ATTR_binary_file_io)->set_pos($section_table_offset);

    # Update section table in override file.  Write actual section offsets/sizes.
    $self->access($OVRF_ATTR_section_table)->write( $self->access($OVRF_ATTR_binary_file_io) );
}

#
# _copy_file_to_binary_wts() subroutine
# copy binary data from image file to binary wof table section
# Note: before calling this function, make sure the position of
# override file set to the expected Binarry WOF Table Section.
#
sub _copy_file_to_binary_wts
{
    my ( $self, $combine_file_name ) = @_;
    Log::log_print $p_log_lvl, "_copy_file_to_binary_wts():\n";

    if ( !-e $combine_file_name )
    {
        die "Error - The file, $combine_file_name, not exists.";
    }

    my $filesize = -s $combine_file_name;
    if ( $filesize <= 0 )
    {
        die "Error: file size is not positive, size: $filesize\n";
    }

    # Create combine file IO object
    my $combine_file_io = BinaryFileIO->new($combine_file_name);
    if ( !defined($combine_file_io) )
    {
        die "Error: -- cannot create file object for $combine_file_io.\n";
    }

    # reset file position to the beginning before reading it to copy the image file.
    $combine_file_io->open('r');
    $combine_file_io->set_pos(0);

    my $left_to_copy = $filesize;
    while ( $left_to_copy > 0 )
    {
        my $length_to_copy =
            ( ( $left_to_copy - $FILE_COPY_BUFFER_SIZE ) >= 0 ) ? $FILE_COPY_BUFFER_SIZE : $left_to_copy;
        ( my $buffer, my $read_size ) = $combine_file_io->read_to_buffer($length_to_copy);

        if ( !defined($buffer) )
        {
            last;
        }
        if ( $read_size <= 0 )
        {
            last;
        }
        $left_to_copy -= $length_to_copy;
        $self->access($OVRF_ATTR_binary_file_io)->write($buffer);
    }

    $combine_file_io->close();

    # Write any necessary padding so section ends on proper byte boundary
    # image file is already aligned, so comment this out.
    # $self->_write_padding();
}

#
# _copy_binary_wts_to_file() subroutine
# copy binary data from binary wof table section to file
# Note: before calling this function, make sure the position of
# override file set to the expected Binarry WOF Table Section.
#
sub _copy_binary_wts_to_file
{
    my ( $self, $image_file_name, $filesize ) = @_;
    Log::log_print $p_log_lvl, "_copy_binary_wts_to_file():\n";
    Log::log_print $p_log_lvl, "  filesize: $filesize.\n";

    if ( $filesize <= 0 )
    {
        die "Error: file size is not positive, size: $filesize\n";
    }

    # Create image file IO object
    my $image_file_io = BinaryFileIO->new($image_file_name);
    if ( !defined($image_file_io) )
    {
        die "Error: -- cannot create file object for $image_file_io.\n";
    }

    # reset file position to the beginning before reading it to copy the image file.
    $image_file_io->open('w');
    $image_file_io->set_pos(0);

    my $left_to_copy = $filesize;
    while ( $left_to_copy > 0 )
    {
        my $length_to_copy =
            ( ( $left_to_copy - $FILE_COPY_BUFFER_SIZE ) >= 0 ) ? $FILE_COPY_BUFFER_SIZE : $left_to_copy;
        ( my $buffer, my $read_size ) = $self->access($OVRF_ATTR_binary_file_io)->read_to_buffer($length_to_copy);
        if ( !defined($buffer) )
        {
            last;
        }
        if ( $read_size <= 0 )
        {
            last;
        }
        $left_to_copy -= $length_to_copy;
        $image_file_io->write($buffer);
    }

    $image_file_io->close();

    # Write any necessary padding so section ends on proper byte boundary
    # image file is already aligned, so comment this out.
    # $self->_write_padding();
}

sub _get_padding_count
{
    my ( $self, $file_offset ) = @_;
    Log::log_print $p_log_lvl, "_get_padding_count():\n";

    #  Log::log_print $p_log_lvl, "  file_offset: $file_offset.\n";
    # If a file offset was not specified, get the current file offset
    if ( !defined($file_offset) )
    {
        $file_offset = $self->access($OVRF_ATTR_binary_file_io)->get_pos();
    }

    # Return the padding needed to reach the correct alignment boundary
    my $remainder = $file_offset % $OVERRIDE_FILE_BYTE_ALIGNMENT;
    return ( $remainder == 0 ) ? 0 : ( $OVERRIDE_FILE_BYTE_ALIGNMENT - $remainder );
}

sub _read_padding
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_read_padding():\n";
    my $padding_byte_count = $self->_get_padding_count();
    if ( $padding_byte_count > 0 )
    {
        # Skip forward past the padding bytes
        $self->access($OVRF_ATTR_binary_file_io)->skip_bytes($padding_byte_count);
    }
}

sub _write_padding
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_write_padding():\n";
    my $padding_byte_count = $self->_get_padding_count();
    if ( $padding_byte_count > 0 )
    {
        # Write 0x00 in the padding bytes
        $self->access($OVRF_ATTR_binary_file_io)->fill_bytes( $padding_byte_count, 0x00 );
    }
}

################################################################################
# Options Class
#
# This class represents the command line options for this script.
################################################################################
package Options;
use Getopt::Long;
our $p_log_lvl = $LOG_LVL_0;

# Attribute names in this class
our $OPT_ATTR_create           = 'create';
our $OPT_ATTR_list             = 'list';
our $OPT_ATTR_view             = 'view';
our $OPT_ATTR_squint           = 'squint';
our $OPT_ATTR_extract          = 'extract';
our $OPT_ATTR_combine          = 'combine';
our $OPT_ATTR_list_ovr         = 'list_ovr';
our $OPT_ATTR_split_ovr        = 'split_ovr';
our $OPT_ATTR_help             = 'help';
our $OPT_ATTR_debug            = 'debug';
our $OPT_ATTR_table_set_id     = 'tsi';
our $OPT_ATTR_section_number   = 'section_number';
our $OPT_ATTR_vrt_index        = 'vrt_index';
our $OPT_ATTR_wof_override_id  = 'woi';
our $OPT_ATTR_dd_level         = 'dd';
our $OPT_ATTR_vcs_ceff_index   = $G_ATTR_vcs_ceff_index;
our $OPT_ATTR_vdd_ceff_index   = $G_ATTR_vdd_ceff_index;
our $OPT_ATTR_io_power_index   = $G_ATTR_io_power_index;
our $OPT_ATTR_amb_cond_index   = $G_ATTR_amb_cond_index;
our $OPT_ATTR_vratio_index     = $G_ATTR_vratio_index;
our $OPT_ATTR_outrows          = 'outrows';
our $OPT_ATTR_outcols          = 'outcols';
our $OPT_ATTR_io_power_size    = 'io_power_size';
our $OPT_ATTR_vcs_ceff_size    = 'vcs_ceff_size';
our $OPT_ATTR_vdd_ceff_size    = 'vdd_ceff_size';
our $OPT_ATTR_amb_cond_size    = 'am_cond_size';
our $OPT_ATTR_freq_format      = 'freq_format';
our $OPT_ATTR_csv_files        = 'csv_files';
our $OPT_ATTR_combine_files    = 'combine_files';
our $OPT_ATTR_input_file       = 'input_file';
our $OPT_ATTR_output_file      = 'output_file';
our $OPT_ATTR_disp_axis_vcs    = $G_ATTR_disp_axis_vcs;
our $OPT_ATTR_disp_axis_vdd    = $G_ATTR_disp_axis_vdd;
our $OPT_ATTR_disp_axis_amb    = $G_ATTR_disp_axis_amb;
our $OPT_ATTR_disp_axis_io     = $G_ATTR_disp_axis_io;
our $OPT_ATTR_disp_axis_vratio = $G_ATTR_disp_axis_vratio;

# array for display axis
our @OPT_DISP_AXIS = (
    $OPT_ATTR_disp_axis_vcs, $OPT_ATTR_disp_axis_vdd, $OPT_ATTR_disp_axis_amb,
    $OPT_ATTR_disp_axis_io,  $OPT_ATTR_disp_axis_vratio,
);

# hash table with intial values from array with pair:
# key - axis name from each in array @OPT_DISP_AXIS,
# val - type of index.
our %OPT_DISP_AXIS_TYPE_MAP = (
    $OPT_ATTR_disp_axis_vcs    => $OPT_ATTR_vcs_ceff_index,
    $OPT_ATTR_disp_axis_vdd    => $OPT_ATTR_vdd_ceff_index,
    $OPT_ATTR_disp_axis_io     => $OPT_ATTR_io_power_index,
    $OPT_ATTR_disp_axis_amb    => $OPT_ATTR_amb_cond_index,
    $OPT_ATTR_disp_axis_vratio => $OPT_ATTR_vratio_index,
);

# Possible return values from the action() method
our $OPTIONS_ACTION_CREATE    = $OPT_ATTR_create;
our $OPTIONS_ACTION_LIST      = $OPT_ATTR_list;
our $OPTIONS_ACTION_VIEW      = $OPT_ATTR_view;
our $OPTIONS_ACTION_SQUINT    = $OPT_ATTR_squint;
our $OPTIONS_ACTION_EXTRACT   = $OPT_ATTR_extract;
our $OPTIONS_ACTION_COMBINE   = $OPT_ATTR_combine;
our $OPTIONS_ACTION_LIST_OVR  = $OPT_ATTR_list_ovr;
our $OPTIONS_ACTION_SPLIT_OVR = $OPT_ATTR_split_ovr;
our $OPTIONS_ACTION_HELP      = $OPT_ATTR_help;

# Possible return values from the freq_format() method
our $OPTIONS_FREQ_FORMAT_MHZ    = 'mhz';
our $OPTIONS_FREQ_FORMAT_SYSTEM = 'system';

our $OPT_SECTION_NUMB_DEFAULT = 0;

our @all_options = (
    $OPT_ATTR_create,          $OPT_ATTR_list,           $OPT_ATTR_view,           $OPT_ATTR_squint,
    $OPT_ATTR_extract,         $OPT_ATTR_combine,        $OPT_ATTR_list_ovr,       $OPT_ATTR_split_ovr,
    $OPT_ATTR_help,            $OPT_ATTR_vcs_ceff_index, $OPT_ATTR_vdd_ceff_index, $OPT_ATTR_io_power_index,
    $OPT_ATTR_amb_cond_index,  $OPT_ATTR_vratio_index,   $OPT_ATTR_vrt_index,      $OPT_ATTR_outrows,
    $OPT_ATTR_outcols,         $OPT_ATTR_freq_format,    $OPT_ATTR_section_number, $OPT_ATTR_table_set_id,
    $OPT_ATTR_wof_override_id, $OPT_ATTR_dd_level,       $OPT_ATTR_io_power_size,  $OPT_ATTR_vcs_ceff_size,
    $OPT_ATTR_vdd_ceff_size,   $OPT_ATTR_amb_cond_size,
);

our @action_options = (
    $OPT_ATTR_create,  $OPT_ATTR_list,     $OPT_ATTR_view,      $OPT_ATTR_squint, $OPT_ATTR_extract,
    $OPT_ATTR_combine, $OPT_ATTR_list_ovr, $OPT_ATTR_split_ovr, $OPT_ATTR_help,
);

sub new
{
    my ($class) = @_;

    # check to use global logging level.
    $p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );
    my $self = {
        $OPT_ATTR_create          => undef,
        $OPT_ATTR_list            => undef,
        $OPT_ATTR_view            => undef,
        $OPT_ATTR_extract         => undef,
        $OPT_ATTR_combine         => undef,
        $OPT_ATTR_list_ovr        => undef,
        $OPT_ATTR_split_ovr       => undef,
        $OPT_ATTR_help            => undef,
        $OPT_ATTR_debug           => undef,
        $OPT_ATTR_section_number  => undef,
        $OPT_ATTR_vrt_index       => undef,
        $OPT_ATTR_table_set_id    => undef,
        $OPT_ATTR_wof_override_id => undef,
        $OPT_ATTR_dd_level        => undef,
        $OPT_ATTR_vcs_ceff_index  => undef,
        $OPT_ATTR_vdd_ceff_index  => undef,
        $OPT_ATTR_io_power_index  => undef,
        $OPT_ATTR_amb_cond_index  => undef,
        $OPT_ATTR_freq_format     => undef,
        $OPT_ATTR_vratio_index    => undef,
        $OPT_ATTR_outrows         => undef,
        $OPT_ATTR_outcols         => undef,
        $OPT_ATTR_io_power_size   => undef,
        $OPT_ATTR_vcs_ceff_size   => undef,
        $OPT_ATTR_vdd_ceff_size   => undef,
        $OPT_ATTR_amb_cond_size   => undef,
        $OPT_ATTR_csv_files       => [],
        $OPT_ATTR_combine_files   => [],
        $OPT_ATTR_input_file      => undef,
        $OPT_ATTR_output_file     => undef,
    };
    bless($self);
    return $self;
}

sub access
{
    my ( $self, $attr_name, $attr_value ) = @_;
    Log::log_print $LOG_LVL_0, "access():\n";
    Log::log_print $LOG_LVL_0, "  attr_name: $attr_name.\n";
    if ( defined($attr_value) )
    {
        $self->{$attr_name} = $attr_value;
        Log::log_print $LOG_LVL_0, "  attr_value: $attr_value.\n";
    }
    return $self->{$attr_name};
}

sub action
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "action():\n";

    # Return the action that was specified (if any)
    my $action = undef;

    if ( defined( $self->access($OPT_ATTR_create) ) )
    {
        if ( !defined( $self->access($OPT_ATTR_combine) ) )
        {
            $action = $OPT_ATTR_create;
        }
        else
        {
            $action = $OPT_ATTR_combine;
        }
        return $action;
    }

    foreach my $option (@action_options)
    {
        if ( defined( $self->{$option} ) )
        {
            $action = $option;
            last;
        }
    }
    return $action;
}

sub image_file
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "image_file():\n";

    # Return the image file for the currently specified action (if any)
    my $image_file = undef;
    my $action     = $self->action();
    if ( defined($action) && ( $action ne $OPT_ATTR_help ) )
    {
        $image_file = $self->{$action};
    }
    return $image_file;
}

sub csv_files
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "csv_files():\n";
    return @{ $self->{$OPT_ATTR_csv_files} };
}

sub override_file
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "override_file():\n";

    # Return the override file for the currently specified action (if any)
    my $override_file = undef;
    my $action        = $self->action();
    if ( ( $action eq $OPT_ATTR_create ) || ( $action eq $OPT_ATTR_combine ) )
    {
        $override_file = $self->access($OPT_ATTR_create);
    }
    else
    {
        $override_file = $self->access($action);
    }
    return $override_file;
}

sub combine_files
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "override_file():\n";

    # Return the override file for the currently specified action (if any)
    my $combine_file_list = undef;
    $combine_file_list = $self->access($OPT_ATTR_combine);
    if ( !-e $combine_file_list )
    {
        die "Error - The file, $combine_file_list, not exists.";
    }
    open( FH, '<', $combine_file_list ) or die "Cannot open file: $combine_file_list!";
    while ( my $line = <FH> )
    {
        # remove line feed first.
        $line =~ s/\015?\012?$//;
        push @{ $self->{$OPT_ATTR_combine_files} }, $line;
    }
    close(FH);
    return @{ $self->{$OPT_ATTR_combine_files} };
}

sub parse
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "parse():\n";

    # If no options were specified, default to --help action
    if ( scalar(@ARGV) == 0 )
    {
        push( @ARGV, '--help' );
    }
    if ( $p_log_lvl >= $g_log_lvl_target )
    {
        Log::log_print $LOG_LVL_1, "  printing ARGV content.\n";
        foreach (@ARGV)
        {
            Log::log_print $LOG_LVL_1, "ARGV: $_\n";
        }
    }

    # Parse command line options and store results within this object
    if (!GetOptions(
            $self,
            $OPT_ATTR_create . '=s',
            $OPT_ATTR_list . '=s',
            $OPT_ATTR_view . '=s',
            $OPT_ATTR_squint . '=s',
            $OPT_ATTR_extract . '=s',
            $OPT_ATTR_combine . '=s',
            $OPT_ATTR_list_ovr . '=s',
            $OPT_ATTR_split_ovr . '=s',
            $OPT_ATTR_help,
            $OPT_ATTR_debug,
            $OPT_ATTR_table_set_id . '=s',
            $OPT_ATTR_wof_override_id . '=s',
            $OPT_ATTR_dd_level . '=i',
            $OPT_ATTR_section_number . '=i',
            $OPT_ATTR_vrt_index . '=i',
            $OPT_ATTR_outrows . '=s',
            $OPT_ATTR_outcols . '=s',
            $OPT_ATTR_vcs_ceff_index . '=i',
            $OPT_ATTR_vdd_ceff_index . '=i',
            $OPT_ATTR_io_power_index . '=i',
            $OPT_ATTR_amb_cond_index . '=i',
            $OPT_ATTR_vratio_index . '=i',
            $OPT_ATTR_io_power_size . '=i',
            $OPT_ATTR_vcs_ceff_size . '=i',
            $OPT_ATTR_vdd_ceff_size . '=i',
            $OPT_ATTR_amb_cond_size . '=i',
            $OPT_ATTR_freq_format . '=s'
        )
        )
    {
        die "Error: Invalid command line options specified.\n";
    }

    # Check if debug is enabled in command line option.
    my $debug = $self->access($OPT_ATTR_debug);
    if ( defined($debug) )
    {
        $g_use_global_log_lvl = 1;
        $g_log_lvl            = $LOG_LVL_1;
        $p_log_lvl            = $g_log_lvl;    # set Options pkg log lvl.
    }

    # Verify options specified with action
    my $action = $self->action();
    if ( $action eq $OPT_ATTR_create )
    {
        $self->_verify_create_options();
    }
    elsif ( $action eq $OPT_ATTR_list )
    {
        $self->_verify_list_options();
    }
    elsif ( $action eq $OPT_ATTR_view )
    {
        $self->_verify_view_options();
    }
    elsif ( $action eq $OPT_ATTR_squint )
    {
        $self->_verify_squint_options();
    }
    elsif ( $action eq $OPT_ATTR_extract )
    {
        $self->_verify_extract_options();
    }
    elsif ( $action eq $OPT_ATTR_combine )
    {
        $self->_verify_combine_options();
    }
    elsif ( $action eq $OPT_ATTR_list_ovr )
    {
        $self->_verify_list_ovr_options();
    }
    elsif ( $action eq $OPT_ATTR_split_ovr )
    {
        $self->_verify_split_ovr_options();
    }
    elsif ( $action eq $OPT_ATTR_help )
    {
        $self->_verify_help_options();
    }
    else
    {
        die "Error: Action required: --create, --list," . " --view, --extract, or --help.\n";
    }
}

sub print_usage
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "print_usage():\n";
    print STDERR "Usage:\n"
        . "  wof_data_xlator.pl --create <image_file> <csv_file>/<csv_dir> [<csv_file> ...]\n"
        . "  wof_data_xlator.pl --create <overrid_image_file> --combine <override_list_file>]\n"
        . "  wof_data_xlator.pl --list <image_file>\n"
        . "  wof_data_xlator.pl --view <image_file> --section_number <number>\n"
        . "                   --vcs_ceff_index <number> --vdd_ceff_index <number>\n"
        . "                   --io_power_index <number> --amb_cond_index <number>\n"
        . "                   --vratio_index <number>\n"
        . "                   [--freq_format mhz|system]\n"
        . "  wof_data_xlator.pl --squint <image_file> --section_number <section_number> --vrt_index <vrt_index>\n"
        . "  wof_data_xlator.pl --extract <image_file> --section_number <number>\n"
        . "  wof_data_xlator.pl --help\n"
        . "Actions:\n"
        . "  --create       Create a WOF Tables image file based on input CSV files or directory,\n"
        . "                 or create a WOF Override image file based on input WOF image files,\n"
        . "                 depending on --combine option.\n"
        . "  --list         List the contents of a WOF Tables image file.\n"
        . "  --view         View one VRT within a WOF Tables image file.\n"
        . "  --squint       Display VRT headers in WOF Table Session.\n"
        . "  --extract      Extract one set of WOF Tables from an image file.\n"
        . "  --combine      Combine files in the list file in this option.\n"
        . "  --list_ovr     List the contents of a WOF override file.\n"
        . "  --split_ovr    Split Override file into files for each Binary WTS.\n"
        . "  --help         Show brief description of command syntax.\n"
        . "Options:\n"
        . "  --tsi                         Image Header Table Set ID (max length: 16).\n"
        . "  --section_number              WOF Tables section_number value.\n"
        . "  --woi                         WOF Override ID (max length: 16).\n"
        . "  --dd                          DD Level for override file.\n"
        . "  --vcs_ceff_index              VRT vcs_ceff_index value.\n"
        . "  --vdd_ceff_index              VRT vdd_ceff_index value.\n"
        . "  --io_power_index              VRT io_power_index value.\n"
        . "  --amb_cond_index              VRT amb_cond_index value.\n"
        . "  --vratio_index                VRT vratio_index value.\n"
        . "  --outrows                     Demention of output row,\n"
        . "                                select from [vdd|vcs|amb|io|vratio],\n"
        . "  --outcols                     Demention of output column.\n"
        . "                                select from [vdd|vcs|amb|io|vratio].\n"
        . "                                If both outrows and outcols are not set,\n"
        . "                                default for outrows set to io and,\n"
        . "                                default for outcols set to vratio.\n"
        . "  --io_power_size               IO Power Size.\n"
        . "  --vcs_ceff_size               VCS Ceff Size.\n"
        . "  --vdd_ceff_size               VDD Ceff Size.\n"
        . "  --amb_cond_size               Amb Cond Size.\n"
        . "  --freq_format                 Frequency display format.  Specify 'mhz' for\n"
        . "                                megahertz format or 'system' for System VRT\n"
        . "                                format.  Default is 'mhz'.\n"
        . "  --debug                       Print debugging messages.\n";
}

#------------------------------------------------------------------------------
# Private methods
#------------------------------------------------------------------------------
sub _verify_create_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_create_options().\n";
    if ( $p_log_lvl >= $g_log_lvl_target )
    {
        use Data::Dumper qw(Dumper);
        print Dumper \@ARGV;
    }
    if ( scalar(@ARGV) == 0 )
    {
        die "Error: --create requires one or more CSV files or one directory.\n";
    }
    Log::log_print $p_log_lvl, "  ARGV: " . join( ", ", @ARGV ) . ".\n";

    # valid options for combine action.
    my @valid_options = (
        $OPT_ATTR_create,        $OPT_ATTR_table_set_id,  $OPT_ATTR_dd_level, $OPT_ATTR_io_power_size,
        $OPT_ATTR_vcs_ceff_size, $OPT_ATTR_vdd_ceff_size, $OPT_ATTR_amb_cond_size,
    );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --create.\n";
        }
    }

    # Verify all required options were specified
    foreach my $option ( $OPT_ATTR_table_set_id, )
    {
        if ( !defined( $self->{$option} ) )
        {
            die "Error: --$option is required with --create.\n";
        }
    }

    if ( defined( $self->{$OPT_ATTR_dd_level} ) )
    {
        if ( !( $self->access($OPT_ATTR_dd_level) =~ /^[0-9][0-9]$/ ) )
        {
            die "Error: --dd option is invalid: $self->access($OPT_ATTR_dd_level).\n";
        }
    }

    # If optional --io_power_size was not specified, set it to the default value
    if ( !defined( $self->access($OPT_ATTR_io_power_size) ) )
    {
        $self->access( $OPT_ATTR_io_power_size, $G_DEF_IO_POWER_SIZE );
    }

    # If optional --vcs_ceff_size was not specified, set it to the default value
    if ( !defined( $self->access($OPT_ATTR_vcs_ceff_size) ) )
    {
        $self->access( $OPT_ATTR_vcs_ceff_size, $G_DEF_VCS_CEFF_SIZE );
    }

    # If optional --vdd_ceff_size was not specified, set it to the default value
    if ( !defined( $self->access($OPT_ATTR_vdd_ceff_size) ) )
    {
        $self->access( $OPT_ATTR_vdd_ceff_size, $G_DEF_VDD_CEFF_SIZE );
    }

    # If optional --am_cond_size was not specified, set it to the default value
    if ( !defined( $self->access($OPT_ATTR_amb_cond_size) ) )
    {
        $self->access( $OPT_ATTR_amb_cond_size, $G_DEF_AMB_COND_SIZE );
    }

    $g_io_power_size = $self->access($OPT_ATTR_io_power_size);
    $g_vcs_ceff_size = $self->access($OPT_ATTR_vcs_ceff_size);
    $g_vdd_ceff_size = $self->access($OPT_ATTR_vdd_ceff_size);
    $g_amb_cond_size = $self->access($OPT_ATTR_amb_cond_size);

    Log::log_print $p_log_lvl, "\$OPT_ATTR_amb_cond_size: $OPT_ATTR_amb_cond_size\n";
    Log::log_print $p_log_lvl, "\$OPT_ATTR_vcs_ceff_size: $OPT_ATTR_vcs_ceff_size\n";
    Log::log_print $p_log_lvl, "\$OPT_ATTR_vdd_ceff_size: $OPT_ATTR_vdd_ceff_size\n";
    Log::log_print $p_log_lvl, "\$OPT_ATTR_amb_cond_size: $OPT_ATTR_amb_cond_size\n";

    # Treat any remaining (unparsed) command line arguments as CSV files or
    # CSV directory that contains the CSV files.
    # Verify that at least one was specified.
    foreach my $filename (@ARGV)
    {
        if ( -f $filename )
        {
            if ( !@ARGV )
            {
                die "Error: --no input files found.\n";
            }
            unless ( -e $filename )
            {
                die "Error: --file not exist: $filename.\n";
            }

            # The CSV files were given as files, return original array
            # $self->access($OPT_ATTR_csv_files, [ @ARGV ]);
            $self->{$OPT_ATTR_csv_files} = [@ARGV];
            Log::log_print $p_log_lvl, "  ARGV: " . join( ", ", @ARGV ) . ".\n";
        }
        elsif ( -d $filename )
        {
            # The CSV files were given in a directory, pull out each filename
            my @file_list = glob("$filename/*");
            @file_list = grep { -f $_ } @file_list;
            if ( !@file_list )
            {
                die "Error: --no input files found.\n";
            }

            # $self->access($OPT_ATTR_csv_files, [ @file_list ]);
            $self->{$OPT_ATTR_csv_files} = [@file_list];
            Log::log_print $p_log_lvl, "  file_list: " . join( ", ", @file_list ) . ".\n";
        }
        else
        {
            unless ( -e $filename )
            {
                Log::log_print $p_log_lvl, "  file or directory does not exist: $filename.\n";
            }
            die "Error: --cannot identify type of file for filename: $filename.\n";
        }
    }
}

sub _verify_list_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_list_options():\n";

    my @valid_options = ( $OPT_ATTR_list, $OPT_ATTR_section_number, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --list.\n";
        }
    }

    # Verify there are no remaining (unparsed) command line arguments
    if ( scalar(@ARGV) > 0 )
    {
        die "Error: Unexpected options specified with --list: @ARGV\n";
    }
}

sub _verify_view_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_view_options():\n";

    # valid options for extract action.
    my @valid_options = (
        $OPT_ATTR_view,           $OPT_ATTR_section_number, $OPT_ATTR_outrows,        $OPT_ATTR_outcols,
        $OPT_ATTR_vcs_ceff_index, $OPT_ATTR_vdd_ceff_index, $OPT_ATTR_io_power_index, $OPT_ATTR_amb_cond_index,
        $OPT_ATTR_vratio_index,   $OPT_ATTR_freq_format,
    );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --view.\n";
        }
    }

    # Verify all required options were specified
    if (( !defined( $self->{$OPT_ATTR_outrows} ) && defined( $self->{$OPT_ATTR_outcols} ) )
        || ( defined( $self->{$OPT_ATTR_outrows} )
            && !defined( $self->{$OPT_ATTR_outcols} ) )
        )
    {
        die "Error: --outraw or outcol were specified incorrectly." . " Please specify both or ignore both.\n";
    }

    if (   !defined( $self->{$OPT_ATTR_outrows} )
        && !defined( $self->{$OPT_ATTR_outcols} ) )
    {
        $self->access( $OPT_ATTR_outrows, $OPT_ATTR_disp_axis_io );
        $self->access( $OPT_ATTR_outcols, $OPT_ATTR_disp_axis_vratio );
    }

    # Verify all required options were specified
    foreach my $option (
        $OPT_ATTR_vcs_ceff_index, $OPT_ATTR_vdd_ceff_index, $OPT_ATTR_io_power_index,
        $OPT_ATTR_amb_cond_index, $OPT_ATTR_vratio_index,
        )
    {
        if ( !defined( $self->{$option} ) )
        {
            $self->{$option} = -1;
        }
    }

    # If optional --freq_format was not specified, set it to the default value
    if ( !defined( $self->access($OPT_ATTR_freq_format) ) )
    {
        $self->access( $OPT_ATTR_freq_format, $OPTIONS_FREQ_FORMAT_MHZ );
    }

    # If optional --section_number not specified, set it to the default value 0
    if ( !defined( $self->access($OPT_ATTR_section_number) ) )
    {
        $self->access( $OPT_ATTR_section_number, $OPT_SECTION_NUMB_DEFAULT );
    }

    # Verify there are no remaining (unparsed) command line arguments
    if ( scalar(@ARGV) > 0 )
    {
        die "Error: Unexpected options specified with --view: @ARGV\n";
    }

    # Verify --vcs_ceff_index value is valid
    if ( $self->access($OPT_ATTR_vcs_ceff_index) != -1 )
    {
        if ( $self->access($OPT_ATTR_vcs_ceff_index) < 0 )
        {
            die "Error: Invalid --vcs_ceff_index value: Must equal or larger than 0.\n";
        }
    }

    # Verify --vdd_ceff_index value is valid
    if ( $self->access($OPT_ATTR_vdd_ceff_index) != -1 )
    {
        if ( $self->access($OPT_ATTR_vdd_ceff_index) < 0 )
        {
            die "Error: Invalid --vdd_ceff_index value: Must equal or larger than 0.\n";
        }
    }

    # Verify --io_power_index value is valid
    if ( $self->access($OPT_ATTR_io_power_index) != -1 )
    {
        if ( $self->access($OPT_ATTR_io_power_index) < 0 )
        {
            die "Error: Invalid --io_power_index value: Must equal or larger than 0.\n";
        }
    }

    # Verify -- amb_cond_index value is valid
    if ( $self->access($OPT_ATTR_amb_cond_index) != -1 )
    {
        if ( $self->access($OPT_ATTR_amb_cond_index) < 0 )
        {
            die "Error: Invalid --amb_cond_index value: Must equal or larger than 0.\n";
        }
    }

    # Verify -- vratio_index value is valid
    if ( $self->access($OPT_ATTR_vratio_index) != -1 )
    {
        if ( $self->access($OPT_ATTR_vratio_index) < 0 )
        {
            die "Error: Invalid --vratio_index value: Must equal or larger than 0.\n";
        }
    }

    # Verify --outrows value is valid
    if ( !exists $OPT_DISP_AXIS_TYPE_MAP{ $self->access($OPT_ATTR_outrows) } )
    {
        die "Error: Invalid --outrows value: Must be one of the following: " . join( ', ', @OPT_DISP_AXIS ) . ".\n";
    }

    # Verify --outcols value is valid
    if ( !exists $OPT_DISP_AXIS_TYPE_MAP{ $self->access($OPT_ATTR_outcols) } )
    {
        die "Error: Invalid --outrows value: Must be one of the following: " . join( ', ', @OPT_DISP_AXIS ) . ".\n";
    }

    if ( $self->access($OPT_ATTR_outrows) eq $self->access($OPT_ATTR_outcols) )
    {
        die "Error: Invalid --outrows and --outcols values cannot be the same.\n";
    }

    if (( !defined( $self->access($OPT_ATTR_outrows) ) && defined( $self->access($OPT_ATTR_outcols) ) )
        or ( defined( $self->access($OPT_ATTR_outrows) )
            && !defined( $self->access($OPT_ATTR_outcols) ) )
        )
    {
        die "Error: Both --outrows and" . " --outcols options should be defined or not defined.\n";
    }

    # Verify --freq_format value is valid
    if (   ( $self->access($OPT_ATTR_freq_format) ne $OPTIONS_FREQ_FORMAT_MHZ )
        && ( $self->access($OPT_ATTR_freq_format) ne $OPTIONS_FREQ_FORMAT_SYSTEM ) )
    {
        die "Error: Invalid --freq_format value: Must be one of the following: "
            . "$OPTIONS_FREQ_FORMAT_MHZ $OPTIONS_FREQ_FORMAT_SYSTEM\n";
    }
}

sub _verify_squint_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_list_options():\n";

    # valid options for extract action.
    my @valid_options = ( $OPT_ATTR_squint, $OPT_ATTR_section_number, $OPT_ATTR_vrt_index, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --squint.\n";
        }
    }

    # Verify all required options were specified
    if ( !defined( $self->{$OPT_ATTR_section_number} ) )
    {
        die "Error: --section_number is not specified..\n";
    }

    # Verify all required options were specified
    if ( !defined( $self->{$OPT_ATTR_vrt_index} ) )
    {
        $OPT_ATTR_vrt_index = undef;
    }
}

sub _verify_extract_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_extract_options():\n";

    # valid options for extract action.
    my @valid_options = ( $OPT_ATTR_extract, $OPT_ATTR_section_number, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --extract.\n";
        }
    }

    # Verify all required options were specified.
    # currently only check one command option.
    # add to the list if need to check more cmd option.
    if ( !defined( $self->{$OPT_ATTR_section_number} ) )
    {
        die "Error: --section_number option is required but missing.\n";
    }

    # Treat any remaining (unparsed) command line arguments as output files.
    # Verify that at exactly one was specified.
    if ( scalar(@ARGV) != 1 )
    {
        die "Error: unrequired command option is specified - " . $ARGV[0] . "\n";
    }
    $self->access( $OPT_ATTR_output_file, $ARGV[0] );
}

sub _verify_combine_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_combine_options():\n";

    # valid options for combine action.
    my @valid_options = ( $OPT_ATTR_create, $OPT_ATTR_combine, $OPT_ATTR_dd_level, $OPT_ATTR_wof_override_id, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --combine.\n";
        }
    }

    # Verify all required options were specified.
    # currently only check one command option.
    # add to the list if need to check more cmd option.
    if ( !defined( $self->{$OPT_ATTR_wof_override_id} ) )
    {
        $self->access( $OPT_ATTR_wof_override_id, "" );
    }

    if ( defined( $self->{$OPT_ATTR_dd_level} ) )
    {
        if ( !( $self->access($OPT_ATTR_dd_level) =~ /^[0-9][0-9]$/ ) )
        {
            die "Error: --dd option is invalid: $self->access($OPT_ATTR_dd_level).\n";
        }
    }
}

sub _verify_list_ovr_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_list_options():\n";

    # valid options for list_ovr action.
    my @valid_options = ( $OPT_ATTR_list_ovr, $OPT_ATTR_section_number, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --list_ovr.\n";
        }
    }

    # Verify there are no remaining (unparsed) command line arguments
    if ( scalar(@ARGV) > 0 )
    {
        die "Error: Unexpected options specified with --list_ovr: @ARGV\n";
    }
}

sub _verify_split_ovr_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_split_ovr_options():\n";

    # valid options for list_ovr action.
    my @valid_options = ( $OPT_ATTR_split_ovr, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --split_ovr.\n";
        }
    }

    # Verify there are no remaining (unparsed) command line arguments
    if ( scalar(@ARGV) > 0 )
    {
        die "Error: Unexpected options specified with --list_ovr: @ARGV\n";
    }
}

sub _verify_help_options
{
    my ($self) = @_;
    Log::log_print $p_log_lvl, "_verify_help_options():\n";

    my @valid_options = ( $OPT_ATTR_help, );

    # Verify no invalid options were specified.
    foreach my $option (@all_options)
    {
        if ( defined( $self->{$option} ) && !grep( /^$option$/, @valid_options ) )
        {
            die "Error: --$option is not valid with --help.\n";
        }
    }

    # Verify there are no remaining (unparsed) command line arguments
    if ( scalar(@ARGV) > 0 )
    {
        die "Error: Unexpected options specified with --help: @ARGV\n";
    }
}

################################################################################
# Main Package
#
# This package contains the code that runs when the script starts.
################################################################################
package Main;
our $p_log_lvl = $LOG_LVL_0;

sub create_image_file
{
    my ($options) = @_;
    Log::log_print $p_log_lvl, "create_image_file():\n";

    # Get relevant command line options
    my $image_file_name = $options->image_file();
    my @csv_file_names  = $options->csv_files();
    my $dd_level        = $options->access($OPT_ATTR_dd_level);

    # get --tsi command option.
    my $table_set_id = $options->access($OPT_ATTR_table_set_id);

    Log::log_print $p_log_lvl, "  image_file_name: $image_file_name.\n";
    Log::log_print $p_log_lvl, "  csv_file_names: " . join( ", ", @csv_file_names ) . ".\n";

    # Create image file
    my $image_file = ImageFile->new($image_file_name);
    if ( !defined($image_file) )
    {
        die "Error: -- cannot create image file object for $image_file_name.\n";
    }

    my $major_dd_level;
    my $minor_dd_level;

    # if dd_level is specified in command option,
    # the values are derived from command opition.
    # if dd_level is not specified in command option,
    # set the values to zero.
    if ( defined($dd_level) )
    {
        $major_dd_level = substr( $dd_level, 0, 1 );
        $minor_dd_level = substr( $dd_level, 1, 1 );
    }
    else
    {
        $major_dd_level = 0;
        $minor_dd_level = 0;
    }

    $image_file->access($IMF_ATTR_image_header)->access( $IMH_ATTR_table_set_id,   $table_set_id );
    $image_file->access($IMF_ATTR_image_header)->access( $IMH_ATTR_major_dd_level, $major_dd_level );
    $image_file->access($IMF_ATTR_image_header)->access( $IMH_ATTR_minor_dd_level, $minor_dd_level );

    $image_file->create(@csv_file_names);
}

sub list_image_file_contents
{
    my ($options) = @_;

    # Get relevant command line options
    my $image_file_name = $options->image_file();

    # List contents of specified image file
    my $image_file     = ImageFile->new($image_file_name);
    my $section_number = $options->access($OPT_ATTR_section_number);

    $image_file->list($section_number);
}

sub view_vrt_in_image_file
{
    my ($options) = @_;

    # Get relevant command line options
    my $image_file_name        = $options->image_file();
    my $section_number         = $options->access($OPT_ATTR_section_number);
    my $vcs_ceff_index         = $options->access($OPT_ATTR_vcs_ceff_index);
    my $vdd_ceff_index         = $options->access($OPT_ATTR_vdd_ceff_index);
    my $io_power_index         = $options->access($OPT_ATTR_io_power_index);
    my $amb_cond_index         = $options->access($OPT_ATTR_amb_cond_index);
    my $vratio_index           = $options->access($OPT_ATTR_vratio_index);
    my $disp_axis_name_outrows = $options->access($OPT_ATTR_outrows);
    my $disp_axis_name_outcols = $options->access($OPT_ATTR_outcols);
    my $index_type_outrows     = $OPT_DISP_AXIS_TYPE_MAP{$disp_axis_name_outrows};
    my $index_type_outcols     = $OPT_DISP_AXIS_TYPE_MAP{$disp_axis_name_outcols};
    my $freq_format            = $options->access($OPT_ATTR_freq_format);

    # View one VRT within specified image file
    my $image_file = ImageFile->new($image_file_name);
    my $convert_to_mhz = ( $freq_format eq $OPTIONS_FREQ_FORMAT_MHZ ) ? 1 : 0;
    $image_file->view(
        $section_number, $vcs_ceff_index,     $vdd_ceff_index,     $io_power_index, $amb_cond_index,
        $vratio_index,   $index_type_outrows, $index_type_outcols, $convert_to_mhz,
    );
}

sub squint_image_file_contents
{
    my ($options) = @_;

    # Get relevant command line options
    my $image_file_name = $options->image_file();

    # List contents of specified image file
    my $image_file     = ImageFile->new($image_file_name);
    my $section_number = $options->access($OPT_ATTR_section_number);
    my $vrt_index      = $options->access($OPT_ATTR_vrt_index);

    $image_file->squint( $section_number, $vrt_index );
}

sub extract_from_image_file
{
    my ($options) = @_;

    # Get relevant command line options
    my $image_file_name  = $options->image_file();
    my $section_number   = $options->access($OPT_ATTR_section_number);
    my $table_set_id     = $options->access($OPT_ATTR_table_set_id);
    my $output_file_name = $options->access($OPT_ATTR_output_file);

    # Extract one set of WOF Tables from the specified image file
    my $image_file = ImageFile->new($image_file_name);
    $image_file->extract( $section_number, $output_file_name );
}

sub combine_to_override_file
{
    my ($options) = @_;
    Log::log_print $p_log_lvl, "combine_to_override_file():\n";

    # Get relevant command line options
    my $override_file_name = $options->override_file();
    my @combine_file_names = $options->combine_files();
    my $dd_level           = $options->access($OPT_ATTR_dd_level);

    # get --woi command option.
    my $wof_override_id = $options->access($OPT_ATTR_wof_override_id);
    Log::log_print $p_log_lvl, "  override_file_name: $override_file_name.\n";
    Log::log_print $p_log_lvl, "  combine_file_names: " . join( ", ", @combine_file_names ) . ".\n";

    # Create override file
    my $override_file = OverrideFile->new($override_file_name);
    if ( !defined($override_file) )
    {
        die "Error: -- cannot create override file object for $override_file_name.\n";
    }
    $override_file->access($OVRF_ATTR_override_header)->access( $OVRH_ATTR_wof_override_id, $wof_override_id );
    $override_file->combine( $dd_level, $wof_override_id, @combine_file_names );
}

sub list_ovr_file_contents
{
    my ($options) = @_;

    # Get relevant command line options
    my $override_file_name = $options->override_file();

    # List contents of specified override file
    my $override_file  = OverrideFile->new($override_file_name);
    my $section_number = $options->access($OPT_ATTR_section_number);

    $override_file->list_ovr($section_number);
}

sub split_ovr_file
{
    my ($options) = @_;

    # Get relevant command line options
    my $override_file_name = $options->override_file();

    # List contents of specified override file
    my $override_file = OverrideFile->new($override_file_name);

    $override_file->split_ovr_file();
}

################################################################################
# Main subroutine
################################################################################
# check to use global logging level.
$p_log_lvl = $g_log_lvl if ( $g_use_global_log_lvl == 1 );

# print out current directory invoking this program.
Log::log_print $LOG_LVL_0, "Starting the program...\n";
use Cwd qw(cwd);
my $dir = cwd;
Log::log_print $LOG_LVL_3, "Current Working Directory: $dir\n";
Log::log_print $LOG_LVL_3, "\n";

# Parse the command line options
my $options = Options->new();
$options->parse();

# check if command line option debug is specificed.
my $debug = $options->access($OPT_ATTR_debug);
if ( defined($debug) )
{
    $p_log_lvl = $g_log_lvl;    # set main pkg log lvl.
}

# Perform the requested action
my $action = $options->action();
Log::log_print $p_log_lvl, "action: $action.\n";
if ( $action eq $OPTIONS_ACTION_CREATE )
{
    Log::log_print $p_log_lvl, "Calling create_image_file().\n";
    create_image_file($options);
}
elsif ( $action eq $OPTIONS_ACTION_LIST )
{
    Log::log_print $p_log_lvl, "Calling list_image_file_contents().\n";
    list_image_file_contents($options);
}
elsif ( $action eq $OPTIONS_ACTION_VIEW )
{
    Log::log_print $p_log_lvl, "Calling view_vrt_in_image_file().\n";
    view_vrt_in_image_file($options);
}
elsif ( $action eq $OPTIONS_ACTION_SQUINT )
{
    Log::log_print $p_log_lvl, "Calling squint_image_file_contents().\n";
    squint_image_file_contents($options);
}
elsif ( $action eq $OPTIONS_ACTION_EXTRACT )
{
    Log::log_print $p_log_lvl, "Calling extract_from_image_file().\n";
    extract_from_image_file($options);
}
elsif ( $action eq $OPTIONS_ACTION_COMBINE )
{
    Log::log_print $p_log_lvl, "Calling combine_to_override_file().\n";
    combine_to_override_file($options);
}
elsif ( $action eq $OPTIONS_ACTION_LIST_OVR )
{
    Log::log_print $p_log_lvl, "Calling list_ovr_file_contents().\n";
    list_ovr_file_contents($options);
}
elsif ( $action eq $OPTIONS_ACTION_SPLIT_OVR )
{
    Log::log_print $p_log_lvl, "Calling split_ovr_file().\n";
    split_ovr_file($options);
}
elsif ( $action eq $OPTIONS_ACTION_HELP )
{
    $options->print_usage();
}

Log::log_print $LOG_LVL_3, "Exiting from the program...\n";

exit(0);
