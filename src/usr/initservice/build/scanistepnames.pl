#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/initservice/build/scanistepnames.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

# 
#   scan files in the src/include/usr/isteps dir for ISTEPSNAME macro.  This 
#   calls out ISTeps that are executed by the IStep Dispatcher.  
#   This perl script will create an img/istepnames.csv file that contains a
#   list of Comma-Separated-Values of the istep, substep, and istep names 
#   that the user console should support.  For example:
#   4,0,init_target_states
#   4,1,init_fsi
#   4,2,apply_fsi_info
#   4,3,apply_dd_presence
#   4,4,apply_pr_keyword_data
#   4,5,apply_partial_bad
#   4,6,apply_gard
#   4,7,testHWP

use strict;
use File::Find ();
use Time::localtime;
use File::Path;

# Variables
my $DEBUG = 0;
my $sandBase = $ENV{HOSTBOOTROOT};

my $arg;
my $argOutput = "";
my $output = "";

# Arrays
my  @fileList;

while( $ARGV = shift )
{
    if( $ARGV =~ m/-b/ )
    {
        # set base input dir
        $sandBase = shift;
    }
    elsif( $ARGV =~ m/-o/i )
    {
        # set output filename
        $argOutput = shift;
    }
    elsif( $ARGV =~ m/-h/i )
    {
        # help
        usage();
    }
    elsif( $ARGV =~ m/-d/i )
    {
        # debug flag
        $DEBUG = 1;
    }
    else
    {
        usage();
    }
}

# Variables depending on input parameters
if( $argOutput eq "" )
{
    $output = "$sandBase/img/istepnames.csv";
}
else
{
    $output = $argOutput; 
}

print   "base input dir:    $sandBase\n";
print   "output file name:  $argOutput\n";
print   "debug flag:        $DEBUG\n";

#debugMsg( "Source Base Path: $sourcebasePath" );
#debugMsg( "Sandbox Base Dir: $sandBase" );
#debugMsg( "Output Dir: $output" );

@fileList = getFiles( $sandBase );

open( OUTFILE, "> $argOutput" ) or die( "Cannot open: $argOutput: $!" );

my  $infile;
my  $csv;
my  $junk;
my  $junk2;

foreach $infile ( @fileList )
{
    print "Scanning file $sandBase/$infile...\n"; 
    open(INFILE,  "< $sandBase/$infile") or die("Cannot open: $infile: $!");

    while( <INFILE> )
    {
        if ( m/^ *ISTEPNAME/ )
        {
            ( $junk, $csv, $junk2 ) = split /[\(\)]/ ;
            $csv    =~  s/[" ]//g;
            print $csv, "\n";
            print OUTFILE $csv, "\n";
        }
    }
    
}

close (INFILE);
close (OUTFILE);


##  Subroutines ################################################################

##
##  Print the Usage message
##
sub usage
{
    print "Usage: $0 < -b base > <-d> < -o output file >\"\n";
    print "\n";
    print "-b:     base directory ( default is pwd )\n";
    print "-o:     Output file path for  csv file\n";
    print "-d      Enable Debug messages.\n";
    print "-h      Display usage message.\n";
    print "\n\n";
    exit 1;
}


#
# Print debug messages if $DEBUG is enabled.
#
sub debugMsg
{
    my ($msg) = @_;
    if( $DEBUG )
    {
        print "DEBUG: $msg\n";
    }
}


#
# getFiles - find *.H or *.C files
# This recursively searches the input directory passed in for all C/H files.
#
sub getFiles
{
    my ($l_input_dir) = @_;
    my @dir_entry;
    my $basefilename;
    local *DH;

    debugMsg( "Getting Files for dir: $l_input_dir" );

    # Open the directory and read all entry names.
    opendir(DH, $l_input_dir) or die("Cannot open $l_input_dir: $!");
    # skip the dots
    ## @dir_entry  =  grep { !/^\./ } readdir(DH);
    @dir_entry  =   grep { /^*.[CH]/ } readdir(DH);
    closedir(DH);
    
    return( @dir_entry );
}
