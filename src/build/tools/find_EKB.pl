#!/usr/local/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/find_EKB.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
##
##  @file   find_EKB.pl
##  find HostBoot files in $HBDIR (assume: $HB = src/usr/hwpf/hwp )
##  and compare "$Id $" version numbers against the like-named HWP files
##  in $topdir ( assume: $EKB = /afs/awd/projects/eclipz/KnowledgeBase/eclipz/chips/p8/working/procedures ).
##
##  Discussion of selected Options:
##      --verbose :  If the script cannot find a file in HB or a search directory,
##          and --verbose is enabled, it will generate a warning message.
##      --justdiffs:    print only  the files that have differing versions
##      --long: If you are trying to find files that need to be updated in HB,
##          use this option to print out the entire pathname of the HWP version.
##          This makes it easy to copy to the local HB dir or gitrepo.
##
##
##
##  Default is to take base filenames from the command line.
##  Example 1, compare the versions of 2 files in HB vs the ones in the EKB dir:
##      $ src/build/tools/find_EKB.pl proc_stop_deadman_timer.C proc_stop_deadman_timer.H
##      Processing files...   |
##      2 files processed.
##      Output file table...
##      ---------------------------------------------------------------
##      HB Version from src/usr/hwpf/hwp
##      HWP Version from /afs/awd/projects/eclipz/KnowledgeBase/eclipz/chips/p8/working/procedures
##      differing versions are marked with '*' .
##      ---------------------------------------------------------------
##      File                            HB Version      HWP Version
##      * proc_stop_deadman_timer.C     1.4             1.6
##       proc_stop_deadman_timer.H      1.2             1.2
##  In this case, the C file in HB is downlevel from the one in EKB
##
##
##  Example 2:  EKB tends to be a bit stale, compare the same files against
##  my local cvs repository:
##      $ src/build/tools/find_EKB.pl --topdir ../cvs_hwp proc_stop_deadman_timer.C proc_stop_deadman_timer.H
##      Processing files...   |
##      2 files processed.
##      Output file table...
##      ---------------------------------------------------------------
##      HB Version from src/usr/hwpf/hwp
##      HWP Version from ../cvs_hwp
##      differing versions are marked with '*' .
##      ---------------------------------------------------------------
##      File                            HB Version      HWP Version
##      * proc_stop_deadman_timer.C     1.4             1.6
##       proc_stop_deadman_timer.H      1.2             1.2
##
##  In this case, they give the same results.
##
##  Example 3:  Print the full pathname of the new HWP version, so you can copy
##  it to your local dir for testing.
##      $ src/build/tools/find_EKB.pl --justdiffs --long --topdir ../cvs_hwp proc_stop_deadman_timer.C proc_stop_deadman_timer.H
##      Processing files...   |
##      2 files processed.
##      Output file table...
##      ---------------------------------------------------------------
##      HB Version from src/usr/hwpf/hwp
##      HWP Version from ../cvs_hwp
##      differing versions are marked with '*' .
##      ---------------------------------------------------------------
##      File                            HB Version      HWP Version     HWP path
##      * proc_stop_deadman_timer.C     1.4             1.6             ../cvs_hwp/eclipz/chips/p8/working/procedures/ipl/fapi/proc_stop_deadman_timer.C
##
##  Example 4:  Run "hwp_id -s -m" to dump all the files in HB to a file, then
##  use that file to compare against my local cvs repository:
##  Note, the script will accept a vanilla file (generated, say with "dir"), or
##  any reasonable csv file of the format "File,Version" (say, the ProcRevisionList
##  file used in the Cronus archives.)
##  Currently it throws the Version field away and gets a fresh one from the file
##  it finds in --topdir , so direct your --topdir correctly.
##
##      $ src/build/tools/hwp_id.pl -s -m > hb.files
##      $ src/build/tools/find_EKB.pl --topdir ../cvs_hwp --infiles hb.files
##      Reading files from hb.files...
##      Processing files...   -
##
##      ...
##
##      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
##      ERROR: dmi_io_run_training.C was not found under ../cvs_hwp!!!
##      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
##
##      ...
##
##      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
##      ERROR: Found multiple versions 1 of proc_fab_smp.C under src/usr/hwpf/hwp!!!
##      src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/proc_fab_smp.C  1.4
##      src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_smp.C
##      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
##
##      ...
##
##      \
##      137 files processed.
##      Output file table...
##      ---------------------------------------------------------------
##      HB Version from src/usr/hwpf/hwp
##      HWP Version from ../cvs_hwp
##      differing versions are marked with '*' .
##      ---------------------------------------------------------------
##      File                            HB Version      HWP Version
##       fapiHwpExecInitFile.C
##       gcr_funcs.C
##       gcr_funcs.H
##       io_funcs.C
##       io_funcs.H
##       io_run_training.C
##       io_run_training.H
##       dimmBadDqBitmapAccessHwp.C
##       dimmBadDqBitmapFuncs.C
##       HvPlicModule.H
##      * p8_pore_table_gen_api.H                       1.13
##       proc_pba_slave_config.H
##      * p8_delta_scan_rw.h                            1.23
##      * p8_image_help.C                               1.28
##       pore_bitmanip.H
##      * mss_setup_bars.C                              1.22
##
##      ...
##
##      proc_stop_deadman_timer.H      1.2             1.2
##     * sbe_xip_image.c               1.20            1.21
##  Notes:
##  1. The output of hwp_id.pl produces more files than we are interested in,
##  (or they have been renamed in one place or the other, or...).
##  If you wish to investigate these, enable --verbose.
##  2. The script also prints an ERROR if it finds duplicate filenames in the
##  HB tree.  These cannot be suppressed and should be investigated.
##  3. You can see that some files have no $Id tags in neither HB or HWP.
##  This may be OK, or not.
##
##  Example Last: compare files in HB against EKB, using the 12.10.01
##  ProcRevisionList as a source of filenames.  Suppress all the files that
##  aren't there for one reason or another.
##      $ src/build/tools/find_EKB.pl   --infile /afs/awd/projects/eclipz/lab/p8/compiled_procs/archives/.locker1/12.10.01/procs/ProcRevisionList
##      Reading files from /afs/awd/projects/eclipz/lab/p8/compiled_procs/archives/.locker1/12.10.01/procs/ProcRevisionList...
##      Processing files...   -
##      240 files processed.
##      Output file table...
##      ---------------------------------------------------------------
##      HB Version from src/usr/hwpf/hwp
##      HWP Version from /afs/awd/projects/eclipz/KnowledgeBase/eclipz/chips/p8/working/procedures
##      differing versions are marked with '*' .
##      ---------------------------------------------------------------
##      File                                    HB Version      HWP Version
##       io_run_training.C
##       proc_a_x_pci_dmi_pll_initf.C           1.4             1.4
##       proc_a_x_pci_dmi_pll_setup.C           1.7             1.7
##       proc_cen_framelock.C                   1.7             1.7
##       proc_chiplet_scominit.C                1.5             1.5
##       proc_fab_iovalid.C                     1.8             1.8
##      * proc_prep_master_winkle.C             1.7             1.9
##       proc_revert_sbe_mcs_setup.C            1.3             1.3
##       proc_sbe_ffdc.C                        1.4             1.4
##       proc_setup_bars.C                      1.5             1.5
##       proc_start_clocks_chiplets.C           1.5             1.5
##      * proc_stop_deadman_timer.C             1.4             1.6
##


use strict;
use warnings;
use POSIX;
use Getopt::Long;
use File::Basename;
use lib dirname (__FILE__);
## not available ... use Text::Table;

#----------------------------------------------------------------------
#   Globals
#----------------------------------------------------------------------
my  @SearchDirs     =   (   "/afs/awd/projects/eclipz/KnowledgeBase/eclipz/chips/p8/working/procedures",
                            "/afs/awd/projects/eclipz/KnowledgeBase/eclipz/chips/centaur/working/procedures",
                        );

my  $HBDIR          =   "src/usr/hwpf/hwp";

my  $opt_help       =   0;
my  $opt_debug      =   0;
my  $opt_justdiffs  =   0;
my  $opt_topdir     =   "";
my  $opt_infiles    =   "";
my  $opt_long       =   0;
my  $opt_verbose      =   0;


##  input filenames, just the base name
my  @InFiles    =   ();

##  use "find" to get the pathnames of the InFiles in HB and store here.
my  @HBFiles    =   ();

##  use "find" to get the pathnames of the InFiles (in EKB or whatever) and store here
my  @HWPFiles   =   ();

##  output lines to print, columns separated by '|'
my  @OutLines   =   ();

my  $fileCount =   0;

#------------------------------------------------------------------------------
#   Forward Declaration
#------------------------------------------------------------------------------
sub usage();
sub findId( $ );
sub findFile( $$ );
sub printSpinny();

#######################################################################
# Main
#######################################################################
if (scalar(@ARGV) < 1)
{
    ## needs at least one filename as a parameter
    print   "Need at least one filename.   Usage:\n";
    usage();
    exit    -1;
}


my  @SaveArgV   =   @ARGV;
#------------------------------------------------------------------------------
# Parse optional input arguments
#------------------------------------------------------------------------------
GetOptions( "help|?"                    =>  \$opt_help,
            "topdir=s"                  =>  \$opt_topdir,       ##  top EKB directory to look in
            "justdiffs"                 =>  \$opt_justdiffs,    ## just display different files
            "long"                      =>  \$opt_long,         ## "long" format, prints path to HWP file
            "infiles=s"                 =>  \$opt_infiles,      ##  list of files to look for
            "verbose"                   =>  \$opt_verbose,      ##  print files that can't be found
            "debug"                     =>  \$opt_debug,        ## print debug info

          );

##  scan through remaining args, assume they are files, and store in @InFiles
foreach ( @ARGV )
{
    push    @InFiles, $_ ;
}


if ( $opt_help )
{
    usage();
    exit 0;
}



##  read in a list of files if specified
if ( ($opt_infiles ne "") )
{
    open( INFILE, $opt_infiles )    or die "ERROR: Cannot open --infile $opt_infiles: $!\n";

    print   STDOUT  "Reading files from $opt_infiles...\n";
    while ( <INFILE> )
    {
        ##  clean up input filenames...
        chomp;
        s/^\s+//;
        s/\s+$//;

        ####################################
        ##  Filter junk out of infile
        ####################################
        ##  skip initfiles...
        if ( m/initfile/ )                      {   next;   }
        ##  skip [ ] headers
        if ( m/\[.*\]/ )                        {   next;   }
        ##  skip ProcRevisionList Headers
        if ( m/Procedure,Revision/ )            {   next;   }


        ##  if the input is from "hwp_id.pl -s -m", strip off the versions and paths
        ##  @todo save the versions rather than looking them up again.
        my  ( $fn, $junk )   =   split( /[ ,]/ );
        $fn =   basename($fn);

        push @InFiles, $fn;
    }


    close (INFILE);
}

if ( $opt_debug )
{
    print   STDERR  __LINE__, " : ---- DEBUG -----\n";
    print   STDERR  "help               =   $opt_help\n";
    print   STDERR  "debug              =   $opt_debug\n";
    print   STDERR  "justdiffs          =   $opt_justdiffs\n";
    print   STDERR  "long               =   $opt_long\n";
    print   STDERR  "topdir             =   $opt_topdir\n";
    print   STDERR  "infiles            =   $opt_infiles\n";
    print   STDERR  "verbose            =   $opt_verbose\n";

    ## dump files specified
    print   STDERR  "Files:\n";
    print   STDERR  join( ' ', @InFiles ), "\n";

    print   "\n";
}


if ( $opt_topdir ne "" )
{
    ##  Clear out default search files
    @SearchDirs =   ();

    ##  push the new one on.
    push    @SearchDirs, $opt_topdir;
}






##
##  Loop through all files and extract version info from both dirs
##
print   STDOUT  "Processing files...    ";
my  $maxcol     =   0;
## my  $infile     =   "";
## my  $searchdir  =   "";
foreach my $infile ( @InFiles )
{

    ##  this takes a while, show that we're doing something
    printSpinny();

    ##  get largest column needed for filename
    $maxcol = length($infile) if length($infile) > $maxcol;

    ##  search for the file in HostBoot
    my  $hbfile         =   findFile( $HBDIR, $infile );
    if ( ! -f $hbfile )
    {
        next;
    }

    ##
    my  $hwpfile    =   "";
    foreach my $searchdir ( @SearchDirs )
    {
       $hwpfile =   findFile( $searchdir, $infile );
       if ( $hwpfile ne "" )
       {
           last;
       }
    }
    if ( ! -f $hwpfile )
    {
        next;
    }

    ##  find $Id from HostBoot tree
    my  ( $fn1, $vn1 )   =   findId( $hbfile );

    ##  find $Id from HWP tree
    my  ( $fn2, $vn2 )   =   findId( $hwpfile );

    my  $diff   =   "";
    if ( $vn1 ne $vn2 )
    {
        $diff   =   "*";
    }
    elsif   ( $opt_justdiffs )
    {
        next;
    }

    my $line   =   "$diff $infile|$vn1|$vn2|$hwpfile ";
    push    @OutLines, $line;

    if  ( $opt_debug )  { print STDERR  __LINE__, "\t$line\n";  }

}



##  now print table
print   STDOUT  "\nOutput file table...\n";

print   STDOUT  "---------------------------------------------------------------\n";
print   STDOUT  "$fileCount files processed.\n";
print   STDOUT  "HB Version from $HBDIR\n";
print   STDOUT  "HWP Version from dir(s):\n";
foreach my $sd ( @SearchDirs ) {   print   STDOUT  "   $sd\n"; }
print   STDOUT  "differing versions are marked with \'*\' .\n";
print   STDOUT  "---------------------------------------------------------------\n";

my  $col4Hdr    =   "";
if ( $opt_long )
{
    $col4Hdr    =   "HWP path";
}

printf   STDOUT  "%-*s\t%-12s\t%-12s\t%s\n", $maxcol+2,  "File", "HB Version", "HWP Version", $col4Hdr ;

foreach ( @OutLines )
{
    my ( $c1, $c2, $c3, $c4 )    =   split( /\|/ );

    if ( !$opt_long )
    {
        $c4 =   "";
    }

    printf   STDOUT  "%-*s\t%-12s\t%-12s\t%-12s\n", $maxcol, $c1, $c2, $c3, $c4 ;
}


########################################################################
##  Subroutines
########################################################################

##
##  print usage message
##
sub usage()
{

    print   STDOUT  "$0 : Compare HB file versions against HWP file versions\n";
    print   STDOUT  "Usage:\n";
    print   STDOUT  "   $0  \n";
    print   STDOUT  "       [ --topdir    <path> ]  ( top dir to look for HWP files )\n";
    print   STDOUT  "       [ --justdiffs ]         ( just show files that differ )\n";
    print   STDOUT  "       [ --long  ]             ( print path for HWP files )\n";
    print   STDOUT  "       [ --infiles ]           ( file containing filenames to compare )\n";
    print   STDOUT  "       [ --debug ]             ( print debug information )\n";
    print   STDOUT  "       [ --verbose ]           ( print files that can't be found )\n";
    print   STDOUT  "       <files...>\n";
}

##
##  print spinning bar to indicate that program is still working.
##
sub printSpinny()
{
   my @spinState = ("-", "\\", "|", "/");

   $fileCount++;
   print "\b$spinState[($fileCount%4)]";

}

##
##  @param1 -   base dir to look in
##  @param2 -   base filename to look for
##
sub findFile( $$ )
{
    my  $basedir    =   shift;
    my  $basefile   =   shift;

    if ( ( $basedir eq "" )  or ( ! -d $basedir ) )
    {
        print   STDOUT  "ERROR: invalid search dir \"$basedir\" specified\n";
        return  "";
    }

    ##  Read output into array so we can detect multiple hits.
    my  @filepaths   =   `find $basedir -name \'$basefile\' -print`;

    if ( $opt_debug )
    {
        print   STDERR  __LINE__, " findFile: $#filepaths files returned:\n";
        print   STDERR  __LINE__, "\t>", join( ' ', @filepaths ), "<\n";
    }

    if ( (@filepaths == 0) )
    {

        if ( $opt_verbose )
        {
            print   STDOUT  " Warning: $basefile was not found under $basedir.\n";
        }
        return  "";
    }

    if ( @filepaths > 1 )
    {
        print   STDOUT  "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        print   STDOUT  "ERROR: Found multiple versions $#filepaths of $basefile under $basedir!!!\n";

        ##  print the filepaths and the $Ids here so the user can figure out
        ##  which one to get rid of.
        foreach ( @filepaths )
        {
            my  ($fn, $vn ) =   findId( $_ );
            chomp;  chomp   $vn;
            print   STDOUT  " $_  $vn\n";
        }
        print   STDOUT  "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

        return  "";
    }

    my $filepath    =   $filepaths[0];
    chomp   $filepath;

    if ( ! -f $filepath )
    {
        print   STDOUT  "\n";
        print   STDOUT  __LINE__, " ERROR: Cannot find file $basefile under $basedir, \"$filepath\"\n";
        $filepath   =   "";
    }

    return  $filepath;
}

##
##  read in a file and find the id and version (if present)
##
##  @param  $filename   -   name of file
##
##  @return             -   $Id file pathname
##                          $Id version number
##
sub findId( $ )
{
    my $filename  = shift;
    my $data;
    my  $fn =   "";
    my  $vn =   "";

    open( FH, $filename )   or die "cannot open $filename: $!";

    read(FH, $data, -s FH) or die("Error reading $filename: $!");
    close FH;

    ##  extract filename and version from $Id $ string
    if ($data =~ /\$Id: (.*),v ([0-9.]*) .* \$/mgo )
    {
        $fn = $1; # filename
        $vn = $2; # version
    }

    if ( $opt_debug )   {   print   STDERR  __LINE__, " findId: file $filename: fn=$fn, vn=$vn\n";  }

    return  ( $fn, $vn );
}



__END__

