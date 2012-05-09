#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/vpo-debug-framework.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
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
# @file vpo-debug-framework.pl
# @brief Implementation of the common debug framework for running in vpo.
#

use strict;
use warnings;

use POSIX;
use Getopt::Long;
use Pod::Usage;
use File::Temp ('tempfile');
use File::Basename;
use lib dirname (__FILE__);
#print __FILE__."\n";

use Hostboot::_DebugFramework;

#-----------
# Constants
#-----------
use constant CACHELINESIZE => 128;
use constant CACHELINEMASK => 0xFFFFFF80;
use constant NUMTHREADS => 8;

#------------------------------------------------------------
# Common options for the different tools in VPO environment
#------------------------------------------------------------
my %optionInfo = (
    "--test" => ["Use the hbicore_test.syms file instead of the default."],
    "--img-path=<path>" => ["The path to the \"img\" directory where the syms file, etc is located.",
                            "User can also set the env variable HB_IMGDIR to the path of  the \"img\"",
                            "directory instead of using this option."],
    "--out-path=<path>" => ["The path to the directory where the output will be saved."],
    "--debug" => ["Enable debug tracing."],
    "--mute" => ["Don't output the 'Data saved ...' message"],
    "--no-save-states" => ["Don't save thread states..."],
    "-k#" => ["The cage to act on."],
    "-n#" => ["The node to act on."],
    "-s#" => ["The slot to act on."],
    "-p#" => ["The chip position to act on."],
    "-c#" => ["The core/chipUnit to act on."],
);

#--------------------------------------------------------------------------------
# MAIN
#--------------------------------------------------------------------------------
my $name = "vpo-debug-framework.pl";
my $self = ($0 =~ m/$name/);   #flag showing whether script invoked using a different name; i.e symlink
my $tool = "";
my $testImage = 0;
my $outPath = "";
my $outFile = "";
my $toolOptions = "";
my $cfgHelp = 0;
my $cfgMan = 0;
my $toolHelp = 0;
my $debug = 0;
my $mute = 0;
my $nosavestates = 0;
my @ecmdOpt = ("-c3");
my @threadState = ();
my $l2Flushed = 0;
my $fh;

# Use HB_VBUTOOLS env if specified
my $vbuToolDir = $ENV{'HB_VBUTOOLS'};
if (defined ($vbuToolDir))
{
    unless ($vbuToolDir ne "")
    {
        $vbuToolDir = "/gsa/ausgsa/projects/h/hostboot/vbutools/latest";
    }
}

my $imgPath = "";
my $hbDir = $ENV{'HB_IMGDIR'};
if (defined ($hbDir))
{
    if ($hbDir ne "")
    {
        $imgPath = "$hbDir/";
    }
}

Getopt::Long::Configure ("bundling");

if ($self)
{
    GetOptions("tool:s" => \$tool,
               "tool-options:s" => \$toolOptions,
               "test" => \$testImage,
               "img-path:s" => \$imgPath,
               "out-path:s" => \$outPath,
               "debug" => \$debug,
               "mute" => \$mute,
               "no-save-states" => \$nosavestates,
               "help" => \$cfgHelp,
               "toolhelp" => \$toolHelp,
               "man" => \$cfgMan,
               "k=i" => \&processEcmdOpts,
               "n=i" => \&processEcmdOpts,
               "s=i" => \&processEcmdOpts,
               "p=i" => \&processEcmdOpts,
               "c=i" => \&processEcmdOpts) || pod2usage(-verbose => 0);
               
    pod2usage(-verbose => 1) if ($cfgHelp && $self);
    pod2usage(-verbose => 2) if ($cfgMan && $self);
    pod2usage(-verbose => 0) if (($tool eq "") && $self);

    if ($toolHelp)
    {
        callToolModuleHelp($tool);
        exit;
    }
}
else
{
    Getopt::Long::Configure ("pass_through");

    GetOptions("test" => \$testImage,
               "img-path:s" => \$imgPath,
               "out-path:s" => \$outPath,
               "debug" => \$debug,
               "mute" => \$mute,
               "no-save-states" => \$nosavestates,
               "help" => \$cfgHelp,
               "man" => \$cfgMan,
               "k=i" => \&processEcmdOpts,
               "n=i" => \&processEcmdOpts,
               "s=i" => \&processEcmdOpts,
               "p=i" => \&processEcmdOpts,
               "c=i" => \&processEcmdOpts);

    #Determine the tool module.
    determineToolModule();

    if ($cfgHelp || $cfgMan)
    {
        displayToolModuleHelp();
        exit;
    }

    # Determine the options for the tool module
    determineToolModuleOpts();
}

# Determine the full image path.
$imgPath = determineImagePath($imgPath);

# Determine the output file
$outFile = determineOutputFile();

if ($outFile ne "")
{
    unlink $outFile if (-e $outFile);
    open $fh, ">>$outFile" or die "ERROR: cannot open $outFile";
    binmode $fh;
}

my $flag = "-quiet";
if ($debug)
{
    $flag = "";
}

# Save original thread states
if (!$nosavestates)
{
   saveThreadStates();
}

# Parse tool options and call module.
parseToolOpts($toolOptions);
callToolModule($tool);

# Restore thread states
if (!$nosavestates)
{
   restoreThreadStates();
}        

if (!$mute)
{
    print "\n\nData saved to $outFile\n\n";
}

# Close the output file
close $fh if ($outFile ne "");


#--------------------------------------------------------------------------------
# SUBROUTINES
#--------------------------------------------------------------------------------

sub usage
{
    pod2usage(-verbose => 2);
}

sub processEcmdOpts
{
    my ($opt, $value) = @_;

    if ($opt eq "c")
    {
        #remove default value
        shift(@ecmdOpt);
    }

    push(@ecmdOpt, "-$opt$value");
}

# @sub determineOutputFile
#
# Determine the file to save the output to.
#
sub determineOutputFile
{
    if ($outPath eq "")
    {
        $outPath = ".";
    }

    return "$outPath/hb-$tool.output";
}

# @sub userDisplay
#
# Display parameters to the user.
#
# @param varargs - Items to display to the user.
#
sub userDisplay
{
    foreach my $value (@_)
    {
        print $value;
        print $fh $value if ($outFile ne "");
    }
}

# Flush the L2 cache
# This is needed in order to dump L3 quickly
#
sub flushL2
{
    if (0 == $l2Flushed)
    {
        #stop instructions
        stopInstructions("all");

        my $command = "$vbuToolDir/proc_l2_flush_wrap.x86 @ecmdOpt $flag";
        die "ERROR: cannot flush L2" if (system("$command") != 0);

        $l2Flushed = 1;
    }
}


# @return The blob of data requested.
# @sub readData
#
# Reads a data blob from L3
#
# @param integer - Address to read at.
# @param size - Size (in bytes) to read.
#
# @return The blob of data requested.
#
sub readData
{
    my $addr = shift;
    my $size = shift;

    #flushL2
    flushL2();

    #Compute the # of cache lines
    my $offset = $addr % CACHELINESIZE;
    my $numCacheLines = ceil($size / CACHELINESIZE);
    if (($offset + $size) > ($numCacheLines * CACHELINESIZE))
    {
        $numCacheLines += 1;
    }

    #Read the cache lines from L3 and save to temp file
    my (undef, $fname) = tempfile("tmpXXXXX");
    my $command = sprintf ("$vbuToolDir/p8_dump_l3 %x $numCacheLines -f $fname -b @ecmdOpt",
                            $addr);

    if ($debug)
    {
        print "addr $addr, size $size, offset $offset\n";
        print "$command\n";
    }
    die "ERROR: cannot read L3" if (system("$command") != 0);

    #Extract just the data requested from the cache lines read
    open FILE, $fname or die "ERROR: $fname not found : $!";
    binmode FILE;
    my $result = "";
    seek FILE, $offset, SEEK_SET or die "ERROR: Couldn't seek to $offset in $fname: $!\n";
    read FILE, $result, $size;
    close (FILE);
    unlink($fname);

    return $result;
}

# @sub writeData
# @brief write a blob of data to L3
sub writeData
{
    my $addr = shift;
    my $size = shift;
    my $value = shift;

    #Compute the # of cache lines
    my $base = $addr & CACHELINEMASK;
    my $offset = $addr % CACHELINESIZE;
    my $numCacheLines = ceil($size / CACHELINESIZE);
    if (($offset + $size) > ($numCacheLines * CACHELINESIZE))
    {
        $numCacheLines += 1;
    }

    if ($debug)
    {
        my $value2 = unpack("H*", $value);
        print "addr $addr, size $size, value $value2\n";
        print "base $base, offset $offset, numCacheLines $numCacheLines\n";
    }

    #read the cachelines from L3 & save to temp file
    my ($fh, $fname) = tempfile("tmpXXXXX");
    binmode $fh;
    print $fh (readData($base, $numCacheLines * CACHELINESIZE));
    if ($debug)
    {
        print "data read\n";
        system("xxd $fname");
    }

    #modify the cachelines
    seek $fh, $offset, SEEK_SET or die "ERROR: Couldn't seek to $offset in $fname: $!\n";
    print $fh $value;
    close ($fh);
    if ($debug)
    {
        print "data modify\n";
        system("xxd $fname");
    }

    #write the cachelines
    my $command = sprintf("$vbuToolDir/p8_load_l3 -f $fname -o 0x%x -b @ecmdOpt", $base);
    die "ERROR: cannot write L3" if (system("$command") != 0);

    unlink($fname);

    if ($debug)
    {
        ($fh, $fname) = tempfile("tmpXXXXX");
        binmode $fh;
        print $fh (readData($base, $numCacheLines * CACHELINESIZE));
        print "data written\n";
        system("xxd $fname");
        close ($fh);
        unlink($fname);
    }

    return;
}

# Stop instructions
sub stopInstructions
{
    my $thread = shift;

    #Stopping all threads
    my $command = "$vbuToolDir/proc_thread_control_wrap.x86 @ecmdOpt -stop -t$thread $flag";

    if ($debug)
    {
        print "$command\n";
    }

    die "ERROR: cannot stop instructions" if (system("$command") != 0);
}

# Start instructions
sub startInstructions
{
    my $thread = shift;

    #Starting all threads
    my $command = "$vbuToolDir/proc_thread_control_wrap.x86 @ecmdOpt -start -t$thread $flag";

    if ($debug)
    {
        print "$command\n";
    }

    if (system("$command") != 0)
    {
        if (0 == getShutdownRequestStatus())
        {
            die "ERROR: cannot start instructions";
        }
        else
        {
            if ($debug)
            { 
                print "Cannot start instructions since Hostboot has shutdown";
            }
        }
    }

    #Need to flush L2 the next time we read data from L3
    $l2Flushed = 0;
}

# Query thread state
# @brief query whether thread state is quiesced or running
sub queryThreadState
{
    my $thread = shift;

    my $command = "$vbuToolDir/proc_thread_control_wrap.x86 @ecmdOpt -query -t$thread";
    my $result = `$command`;

    if ($debug)
    {
        print"query result:\n $result\n";
    }

    if ($result =~ m/Quiesced/)
    {
        return "Quiesced";
    }
    return "Running";
}

# Save thread states
# @brief Save the thread states
sub saveThreadStates
{
    for (my $i = 0; $i < NUMTHREADS; $i++)
    {
        push (@threadState, queryThreadState($i));
    }
}

# Restore thread states
# @brief Restore the thread states
sub restoreThreadStates
{
    for (my $i = 0; $i < NUMTHREADS; $i++)
    {
        my $curState = queryThreadState($i);
        if ($threadState[$i] ne $curState)
        {
            if ("Quiesced" eq $curState)
            {
                startInstructions($i);
            }
            else
            {
                stoptInstructions($i);
            }
        }
    }
}

# @sub CheckXstopAttn
# @brief Check for a checkstop/special attn
#        return 1 if checkstop/attn occurs
sub CheckXstopAttn
{
    my $result = `getscom pu 000f001a @ecmdOpt -quiet`;
    my $chkstop = 0;
    if ($result !~ m/0x[04]000000000000000/)
    {
        $chkstop = 1;
    }
    return $chkstop;
}

# @sub FirCheck
# @brief Check for FIR
sub FirCheck
{
    my $result = `fircheck @ecmdOpt -quiet 2>&1 | head -30`;
    $result =~ s/error/ERR*R/gi;
    $result =~ s/FAIL/F*IL/g;
    $result =~ s/.*00 SIMDISP.*\n//g;
    $result =~ s/.*CNFG FILE GLOBAL_DEBUG.*\n//g;
    print "$result\n";
}

# @sub getCIA
# @brief return CIA
sub getCIA
{
    my $cia = `getspy pu EX03.EC.IFU.I.T0_CIA -quiet | paste - -`;
    return $cia;
}

# @sub executeInstrCycles
# @brief Tell the simulator to run for so many clock cycles
sub executeInstrCycles
{
    my $flag = "-quiet";
    if ($debug)
    {
        $flag = "";
    }

    #start instructions
    startInstructions("all");

    # run clock cycles
    my $cycles = shift;
    $cycles = $cycles * 100;   #increase cycles since VBU takes longer
    my $command = "simclock $cycles $flag";
    my $noshow = shift;
    if (!$noshow)
    {
        print "$command\n";
    }
    die "ERROR: cannot run clock cycles" if (system("$command") != 0);
}

# @sub readyForInstructions
# @brief Check whether we can run instructions
# @returns 0 - Not ready or 1 - Ready
sub readyForInstructions
{
    # always return Ready
    return 1;
}

# @sub getShutdownRequestStatus
# @brief Check whether shutdown has been requested
# @returns 0 - Shutdown not requested or 1 - Shutdown requested
sub getShutdownRequestStatus
{
    my ($symAddr, $symSize) = findSymbolAddress("CpuManager::cv_shutdown_requested");
    if (not defined $symAddr) { print "Cannot find symbol.\n"; die; }
    my $result = readData($symAddr, $symSize);
    $result= hex (unpack('H*',$result));

    return $result;
}

# @sub getImgPath
#
# Return file-system path to .../img/ subdirectory containing debug files.
#
sub getImgPath
{
    return $imgPath;
}

# @sub getIsTest
#
# Return boolean to determine if tools should look at test debug files or
# normal debug files.
#
sub getIsTest
{
    return $testImage;
}

#--------------------------------------------------------------------------------
# The following routines are used when this script is invoked using a different
# name, i.e. a symlink.
#--------------------------------------------------------------------------------

# @sub determineToolModule
#
# Determine the tool module.
#
sub determineToolModule
{
    if (!$self)
    {
        my ($fname, $dirs, $suffix) = fileparse($0, qr{\..*});
        my @list = split('-', $fname);
        $tool = ucfirst($list[1]);          #Make sure first letter is upper case
    }
    #print "tool $tool\n";
}

# @sub determineToolModuleOpts
#
# Determine the tool module options.
#
sub determineToolModuleOpts
{
    my $numArgs = $#ARGV + 1;

    if (!$self && $numArgs)
    {
        foreach my $arg (@ARGV)
        {
            $arg =~ s/^-+//;
            if (($arg =~ m/=/) && ($arg =~ m/ /))
            {
                #put quotes around it
                my @list = split('=', $arg);
                $list[1] = "'".$list[1]."'";
                $arg = join("=", @list);
            }

            $toolOptions .= " $arg";
        }
    }

    if ($debug)
    {
        print "toolOptions $toolOptions\n";
    }
}

# @sub displayToolModuleHelp
#
# Display usage info for the specific tool plus the common tool options.
#
sub displayToolModuleHelp
{
    if (!$self)
    {
        my %info = callToolModuleHelpInfo($tool);

        print "\nTool: $tool\n";

        for my $i ( 0 .. $#{ $info{intro} } )
        {
            print "\t$info{intro}[$i]\n";
        }

        print "\nOptions:\n";
        if (defined $info{options})
        {
            for my $key ( keys %{$info{options}} )
            {
                print "\t--$key\n";

                for my $i (0 .. $#{ $info{options}{$key} } )
                {
                    print "\t\t$info{options}{$key}[$i]\n";
                }
            }
        }

        for my $key ( keys %optionInfo )
        {
            print "\t$key\n";

            for my $i (0 .. $#{ $optionInfo{$key} } )
            {
                print "\t\t$optionInfo{$key}[$i]\n";
            }
        }

        if (defined $info{notes})
        {
            print "\n";
            for my $i (0 .. $#{ $info{notes} } )
            {
                print "$info{notes}[$i]\n";
            }
        }
    }
}

__END__

=head1 NAME

vpo-debug-framework.pl

=head1 SYNOPSIS

vpo-debug-framework.pl [options] --tool=<module>

=head1 OPTIONS

=over 8

=item B<--tool>=MODULE

Identify the tool module to execute.

=item B<--tool-options>="OPTIONS"

List of arguments to pass to the tool as options.

=item B<--toolhelp>

Displays the help message for a specific debug tool.

=item B<--test>

Use the hbicore_test.syms file instead of the default.

=item B<--img-path>=PATH

The path to the "img" directory where the syms file, etc is located.
User can also set the env variable HB_IMGDIR to the path of the "img"
directory instead of using this option.

=item B<--out-path>=PATH

The path to the directory where the output will be saved.

=item B<--debug>

Enable debug tracing.

=item B<-k>=CAGE #

The cage to act on.

=item B<-n>=NODE #

The node to act on.

=item B<-s>=SLOT #

The slot to act on.

=item B<-p>=CHIP #

The chip position to act on.

=item B<-c>=CORE #

The core/chipUnit to act on.

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=back

=head1 DESCRIPTION

Executes a debug tool module.

=cut
