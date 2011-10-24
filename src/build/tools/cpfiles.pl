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
# to the user specified directory.
#
# Author: CamVan Nguyen 07/07/2011
#

#
# Usage:
# cpfiles.pl <path>


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
my @files = ("src/build/tools/hb-parsedump.pl",
             "src/build/simics/hb-simdebug.py",
             "src/build/simics/post_model_hook.simics",
             "img/errlparser", 
             "img/hbotStringFile",
             "img/hbicore.syms",
             "img/hbicore_test.syms",
             "img/hbicore.bin",
             "img/hbicore_test.bin",
             "img/hbicore.list",
             "img/hbicore_test.list",
             "img/hbicore_extended.bin",
             "img/hbicore_test_extended.bin",
             "img/pnor.toc",
             "img/simics_SALERNO_targeting.bin",
             "img/simics_VENICE_targeting.bin",
             "img/vbu_targeting.bin",
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

if ($numArgs > 2)
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

foreach (@files)
{
    $command = "";

    my($filename, $directories, $suffix) = fileparse($_, qr{\..*});
    #print "$filename, $directories, $suffix\n";

    #Copy .bin to the img dir
    if (($suffix eq ".bin") ||
	($suffix eq ".toc"))
    {
        $copyDir = $imgDir;
    }
    else
    {
        $copyDir = $simicsDir;
    }

    #Delete the old file first (handles copying over symlinks)
    $command = sprintf("rm -f %s/%s%s", $copyDir, $filename, $suffix);
    if ($command ne "")
    {
        print "$command\n";
        `$command`;
    }
    $command = "";


    #Check if user wants to copy test versions to hbicore.<syms|bin|list>
    if ($test == 1)
    {
        #Copy test versions to hbicore.<syms|bin|list>
        if ($filename eq "hbicore_test")
        {
            $command = sprintf("cp %s %s", $_, $copyDir."/hbicore".$suffix);
        }
        elsif ($filename eq "hbicore_test_extended")
        {
            $command = sprintf("cp %s %s", $_, $copyDir."/hbicore_extended".$suffix);
        }
        elsif ($filename ne "hbicore" and $filename ne "hbicore_extended")
        {
            $command = sprintf("cp %s %s", $_, $copyDir);
        }
    }
    else
    {
        $command = sprintf("cp %s %s", $_, $copyDir);
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

# create a sym-link to the appropriate targeting binary
print "Linking in simics_".$machine.".targeting.bin\n";
$command = sprintf("ln -sf %s/simics_%s_targeting.bin %s/targeting.bin", $imgDir, $machine, $imgDir );
print "$command\n";
`$command`;
if( $? != 0 )
{
    print "ERROR : exiting\n";
    exit(-1);
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
    print ("\nUsage: cpfiles.pl [--help] | [<path>] [--test]\n\n");
    print ("  This program needs to be executed from the git repository.\n");
    print ("  It will copy all relevant files, scripts, hbotStringFile,\n");
    print ("  .list, .syms and .bin files needed for debug to one of two\n");
    print ("  locations:\n");
    print ("      1.  <path> if one is specified by the user\n");
    print ("      2.  if <path> is not specified, then the files will be\n");
    print ('          copied to the path specified by env variable $SANDBOXBASE'."\n");
    print ("          if it is defined.\n\n");
    print ("  --help: prints usage information\n");
    print ("  --test: Copy hbicore_test.<syms|bin|list> to hbicore.<syms|bin|list>\n");
}

