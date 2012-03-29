#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/tools/cpfiles.pl $
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
# Purpose:  This perl script needs to be executed from the
# git repository.  It will copy all relevant files, including
# scripts, hbotStringFile, .list, .syms and .bin files needed for debug
# or to release Hostboot code to the user specified directory.
#
# Author: CamVan Nguyen 07/07/2011
#

#
# Usage:
# cpfiles.pl <path> [--test] [--release | --vpo | --simics]


#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use warnings;
use Cwd;
use File::Basename;
use File::Spec;

#------------------------------------------------------------------------------
# Forward Declaration
#------------------------------------------------------------------------------
sub printUsage;

#------------------------------------------------------------------------------
# Global arrays
#------------------------------------------------------------------------------

#List of files to copy.  Path is relative to git repository.
# r = copy to Hostboot release dir
# s = copy to simics sandbox
# v = copy to vpo/vbu dir
my %files = ("src/build/tools/hb-parsedump.pl" => "rsv",
             "src/build/simics/hb-simdebug.py" => "s",
             "src/build/simics/post_model_hook.simics" => "s",
             "src/build/debug/Hostboot" => "rsv",
             "src/build/debug/simics-debug-framework.pl" => "s",
             "src/build/debug/simics-debug-framework.py" => "s",
             "src/build/debug/vpo-debug-framework.pl" => "rv",
             "src/build/debug/hb-dump-debug" => "rsv",
             "src/build/vpo/hb-dump" => "rv",
             "src/build/vpo/hb-istep" => "rv",
             "src/build/vpo/hb-virtdebug.pl" => "rv",
             "src/build/vpo/VBU_Cacheline.pm" => "rv",
             "src/build/hwpf/prcd_compile.tcl" => "r",
             "img/errlparser" => "rsv",
             "img/hbotStringFile" => "rsv",
             "img/hbicore.syms" => "rsv",
             "img/hbicore_test.syms" => "rsv",
             "img/hbicore.bin" => "rsv",
             "img/hbicore_test.bin" => "rsv",
             "img/hbicore.list" => "rsv",
             "img/hbicore_test.list" => "rsv",
             "img/hbicore.bin.modinfo" => "rsv",
             "img/hbicore_test.bin.modinfo" => "rsv",
             "img/simics_MURANO.pnor" => "rs",
             "img/simics_MURANO_test.pnor" => "rs",
             "img/simics_VENICE.pnor" => "rs",
             "img/simics_VENICE_test.pnor" => "rs",
             "img/TULETA.pnor" => "r",
             "img/TULETA_test.pnor" => "r",
             "img/vbu.pnor" => "rv",
             "img/vbu_test.pnor" => "rv",
             "img/isteplist.csv" => "rsv",
             "img/dimmspd.dat" => "sv",
             "img/procmvpd.dat" => "sv",
             "src/build/simics/hb-pnor-mvpd-preload.py" => "sv",
             "src/build/simics/hb-pnor-mvpd-preload.pl" => "sv",
             "src/usr/hwpf/hwp/fapiTestHwp.C" => "r",
             "src/include/usr/hwpf/hwp/fapiTestHwp.H" => "r",
             "src/usr/hwpf/hwp/initfiles/sample.initfile" => "r",
             );

#Directories in base git repository
my @gitRepoDirs = ("img",
                    "obj",
                    "src");


#==============================================================================
# MAIN
#==============================================================================

#------------------------------------------------------------------------------
# Parse optional input argument
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
#print "num args = $numArgs\n";

my $test = 0;   #Flag to overwrite hbicore.<syms|bin|list> with the test versions
my $inDir = ""; #User specified directory to copy files to
my $env = "s";  #Flag to indicate which environment; simics by default

if ($numArgs > 3)
{
    #Print command line help
    print ("ERROR: Too many arguments entered.\n");
    printUsage();
    exit (1);
}
else
{
    foreach (@ARGV)
    {
        if (($_ eq "--help") || ($_ eq "-h"))
        {
            #Print command line help
            printUsage();
            exit (0);
        }
        elsif ($_ eq "--test")
        {
            #Set flag to copy hbicore_test.<syms|bin> to hbcore_test.<syms|bin>
            $test = 1;
        }
        elsif ($_ eq "--release")
        {
            #Set flag to indicate environment
            $env = "r";
        }
        elsif ($_ eq "--vpo")
        {
            #Set flag to indicate environment
            $env = "v";
        }
        elsif ($_ eq "--simics")
        {
            #Set flag to indicate environment
            $env = "s";
        }
        else
        {
            #Save user specified directory
            $inDir = $_;
        }
    }
}

#------------------------------------------------------------------------------
# Initialize the paths to copy files to
#------------------------------------------------------------------------------
my $simicsDir = "";
my $imgDir = "";

my $sandbox = $ENV{'SANDBOXBASE'};
my $machine = $ENV{'MACHINE'};
#print "machine = $machine\n";

if ($inDir ne "")
{
    $simicsDir = $inDir;
    $imgDir = $inDir;
    print "input dir = $inDir\n";


    #If at src dir in sandbox
    if (basename($inDir) eq "src")
    {
        #Check if img dir exists else will copy .bin files to simics dir
        $imgDir = File::Spec->catdir($inDir, "../img");
        $simicsDir = File::Spec->catdir($inDir, "../simics");
        unless (-d ($inDir."/../img"))
        {
            $imgDir = $simicsDir;
            print "No img directory found in sandbox.  Copying .bin files";
            print " to simics directory\n";
        }
    }
}
elsif (defined ($sandbox))
{
    unless ($sandbox ne "")
    {
        die ('ERROR: No path specified and env $SANDBOXBASE = NULL'."\n");
    }

    print "sandbox = $sandbox\n";

    #Check if simics and img dirs exist, else exit
    $simicsDir = File::Spec->catdir($sandbox, "simics");
    $imgDir = File::Spec->catdir($sandbox, "img");
    print "simics dir = $simicsDir\n   img dir = $imgDir\n";

    unless ((-d $simicsDir) && (-d $imgDir))
    {
        die ("ERROR: simics and/or img directories not found in sandbox\n");
    }
}
else
{
    print 'ERROR: No path specified and env $SANDBBOXBASE not set.'."\n";
    printUsage();
    exit(1);
}

#------------------------------------------------------------------------------
# Get the base dir of the git repository
#------------------------------------------------------------------------------
my $cwd = getcwd();
my @paths = File::Spec->splitdir($cwd);
#print "@paths\n";

my @list;
my $data;
foreach $data (@paths)
{
    last if grep { $_ eq $data } @gitRepoDirs;
    push @list, $data;
}
#print "@list\n";

my $gitRepo = File::Spec->catdir(@list);
#print "$gitRepo\n";

#------------------------------------------------------------------------------
# Copy files to user specified directory or to sandbox
# Use unix command vs perl's File::Copy to preserve file attributes
#------------------------------------------------------------------------------
my $command = "";
my $copyDir = "";

chdir $gitRepo;
#print "cwd: ", getcwd()."\n";

# There is no guarantee of the order of the elements of a hash (%files), so
# delete the files first so we don't accidentally delete them after copying when
# the --test option is used.
while ( my ($key, $value) = each(%files) )
{
    #Skip file if not correct env
    next if (!($value =~ m/$env/));

    my($filename, $directories, $suffix) = fileparse($key, qr{\..*});
    my $recursive = (-d $key) ? "-r" : "";

    #Is file in img dir?
    if (($suffix eq ".bin") ||
	($suffix eq ".toc") ||
	($suffix eq ".pnor"))
    {
        $copyDir = $imgDir;
    }
    else
    {
        $copyDir = $simicsDir;
    }

    #Delete the old file first (handles copying over symlinks)
    $command = sprintf("rm -f %s %s/%s%s", $recursive,
                                           $copyDir, $filename, $suffix);
    print "$command\n";
    die if (system("$command") != 0);
}

# Now copy files
while ( my ($key, $value) = each(%files) )
{
    #Skip file if not correct env
    next if (!($value =~ m/$env/));

    $command = "";

    my($filename, $directories, $suffix) = fileparse($key, qr{\..*});
    #print "$filename, $directories, $suffix\n";

    my $recursive = (-d $key) ? "-r" : "";

    #Copy .bin to the img dir
    if (($suffix eq ".bin") ||
	($suffix eq ".toc") ||
	($suffix eq ".pnor"))
    {
        $copyDir = $imgDir;
    }
    else
    {
        $copyDir = $simicsDir;
    }

    #Check if user wants to copy test versions to hbicore.<syms|bin|list>
    if (($test == 1) && ("r" ne $env))
    {
        #Copy test versions to hbicore.<syms|bin|list>
        if ($filename eq "hbicore_test")
        {
            $command = sprintf("cp %s %s %s", $recursive,
                                              $key, $copyDir."/hbicore".$suffix);
        }
        elsif ($filename eq "simics_MURANO_test")
        {
            $command = sprintf("cp %s %s %s", $recursive,
                                              $key, $copyDir."/simics_MURANO".$suffix);
        }
        elsif ($filename eq "simics_VENICE_test")
        {
            $command = sprintf("cp %s %s %s", $recursive,
                                              $key, $copyDir."/simics_VENICE".$suffix);
        }
        elsif ($filename eq "vbu_test")
        {
            $command = sprintf("cp %s %s %s", $recursive,
                                              $key, $copyDir."/vbu".$suffix);
        }
        elsif ($filename ne "hbicore" and $filename ne "simics_MURANO" and $filename ne "simics_VENICE" and $filename ne "vbu")
        {
            $command = sprintf("cp %s %s %s", $recursive,
                                              $key, $copyDir);
        }
    }
    else
    {
        $command = sprintf("cp %s %s %s", $recursive, $key, $copyDir);
    }

    # Copy the file
    if ($command ne "")
    {
        print "$command\n";
        `$command`;
        if( $? != 0 )
        {
            print "ERROR : exiting\n";
            exit(-1);
        }
    }
}

if ("s" eq $env) #simics
{
    # create a sym-link to the appropriate pnor binary
    print "Linking in simics_".$machine.".pnor\n";
    $command = sprintf("ln -sf %s/simics_%s.pnor %s/simics.pnor", $imgDir, $machine, $imgDir );
    print "$command\n";
    `$command`;
    if( $? != 0 )
    {
        print "ERROR : exiting\n";
        exit(-1);
    }

}
else #release or vpo
{
    # create sym-links for vpo-debug-framework.pl for each perl module
    # in the debug framework
    my $debugFrameworkDir = "src/build/debug/Hostboot";
    opendir (my $dh, $debugFrameworkDir) or
        die "Can't open dir '$debugFrameworkDir': $!";
    my @files = readdir $dh;
    closedir $dh;

    #need to create symlinks for old tool names as well
    push(@files, "errl");
    push(@files, "printk");
    push(@files, "trace");

    chdir $inDir;
    foreach (@files)
    {
        # filter out Example.pm  & any file prefixed with '_' or '.'
        next if ( ($_ =~ m/^[._]/) || ($_ =~ m/Example/) );

        my($filename, $directories, $suffix) = fileparse($_, qr{\..*});

        # create sym-link
        $filename = "hb-$filename";
        $command = "ln -sf vpo-debug-framework.pl $filename";
        print "$command\n";
        die if (system("$command") != 0);
    }
}

chdir $cwd;
#print "cwd: ", getcwd()."\n";


#==============================================================================
# SUBROUTINES
#==============================================================================

#------------------------------------------------------------------------------
# Print command line help
#------------------------------------------------------------------------------
sub printUsage()
{
    print ("\nUsage: cpfiles.pl [--help] | [<path>] [--test]\n");
    print ("                   [--release| --vpo| --simics]\n\n");
    print ("  This program needs to be executed from the git repository.\n");
    print ("  It will copy all relevant files, scripts, hbotStringFile,\n");
    print ("  .list, .syms and .bin files needed for debug or release of\n");
    print ("  Hostboot code to one of two locations:\n");
    print ("      1.  <path> if one is specified by the user\n");
    print ("      2.  if <path> is not specified, then the files will be\n");
    print ('          copied to the path specified by env variable $SANDBOXBASE'."\n");
    print ("          if it is defined.\n\n");
    print ("  --help: prints usage information\n");
    print ("  --test: Copy hbicore_test.<syms|bin|list> to hbicore.<syms|bin|list>\n");
    print ("  --release: Copy files needed to release Hostboot code\n");
    print ("  --vpo: Copy files needed to debug in vpo\n");
    print ("  --simics: <default> Copy files needed to debug in simics\n");
}

