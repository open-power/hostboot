#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/ecmd-debug-framework.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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

use Getopt::Long;
use Pod::Usage;
use IO::Seekable;
use File::Temp ( 'tempfile' );
use File::Basename;
use lib dirname (__FILE__);

use Hostboot::_DebugFramework;

use constant DEFAULT_HRMOR => 128*1024*1024; # 128 MB.
use constant PER_NODE_OFFSET => 32*1024*1024*1024*1024; # 32 TB.

my $filename = basename (__FILE__);
my $self = ($0 =~ m/$filename/);

my $tool = "";
my $testImage = 0;
my $toolOptions = "";
my $cfgHelp = 0;
my $cfgMan = 0;
my $toolHelp = 0;
my $forceHRMOR = DEFAULT_HRMOR;
my $node = 0;  # -nX parm to ecmd
my $proc = 0;  # -pX parm to ecmd

my $imgPath = "";
my $hbDir = $ENV{'HB_IMGDIR'};
if (defined ($hbDir))
{
    if ($hbDir ne "")
    {
        $imgPath = "$hbDir/";
    }
}

if (not $self)
{
    $tool = basename $0;
}

GetOptions("tool:s" => \$tool,
           "tool-options:s" => \$toolOptions,
           "test" => \$testImage,
           "img-path:s" => \$imgPath,
           "help" => \$cfgHelp,
           "toolhelp" => \$toolHelp,
           "force-hrmor:o" => \$forceHRMOR,
           "node:i" => \$node,
           "proc:i" => \$proc,
           "man" => \$cfgMan) || pod2usage(-verbose => 0);
pod2usage(-verbose => 1) if $cfgHelp;
pod2usage(-verbose => 2) if $cfgMan;
pod2usage(-verbose => 0) if ($tool eq "");

if ($toolHelp)
{
    callToolModuleHelp($tool);
}
else
{
    # Determine the full image path.
    $imgPath = determineImagePath($imgPath);

    # Parse tool options and call module.
    parseToolOpts($toolOptions);
    callToolModule($tool);
}

exit 0;

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
    }
}


# @sub getImgPath
#
# Return file-system path to .../img/ subdirectory containin debug files.
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

# @sub getEnv
#
# Return the environment that we are running in.
#
sub getEnv
{
    return "hw";
}

# @sub getHRMOR
#
# Returns the HRMOR (128MB for a real system).
#
sub getHRMOR
{
    return $forceHRMOR + ($node * PER_NODE_OFFSET);
}

# @sub readData
#
# Reads a data blob from the system.
#
# @param addr - Address to read at.
# @param size - Size (in bytes) to read.
#
# @return The blob of data requested.
#
sub readData
{
    my $addr = shift;
    my $size = shift;

    $addr = translateHRMOR($addr);

    my (undef, $debugfile) = tempfile(OPEN => 0);
    my (undef, $filename) = tempfile(OPEN => 0);
    my $command = sprintf("cipgetmempba -n%d -p%d -fb %s %x %d -quiet > %s",
                          $node,
                          $proc,
                          $filename,
                          $addr,
                          $size,
                          $debugfile);
    if (system($command) != 0)
    {
        system("cat $debugfile");
    }
    unlink $debugfile;

    my $result;
    open FILE, $filename or die
        "ERROR: $filename not found attempting getmempba";
    binmode FILE;
    read FILE, $result, $size;
    close FILE;
    unlink $filename;

    return $result;
}

# @sub writeData
#
# Write a data blob to the system.
#
# @param addr - Address to read at.
# @param size - Size (in bytes) to read.
# @param value - Value to write.
#
sub writeData
{
    my $addr = shift;
    my $size = shift;
    my $value = shift;

    $addr = translateHRMOR($addr);

    my (undef, $debugfile) = tempfile(OPEN => 0);
    my ($file, $filename) = tempfile();
    binmode $file;
    print $file $value;
    close $file;

    my $command = sprintf("cipputmempba -n%d -p%d -cft -fb %s %x -quiet -mode inj > %s",
                          $node,
                          $proc,
                          $filename,
                          $addr,
                          $debugfile);
    ::userDisplay($command);
    if (system($command) != 0)
    {
        system("cat $debugfile");
    }
    unlink $debugfile;

    unlink $filename;

    return;
}

# @sub readScom
#
# Perform a getscom operation.
#
# @param addr - Address to read at.
# @param size - Size (in bytes) to read.
#
# @return Data from scom.
#
sub readScom
{
    my $addr = shift;
    my $size = shift;

    my $command = sprintf("getscom pu -n%d -p%d %x -quiet -ox",
                          $node, $proc, $addr);
    open OUTPUT, "$command |";
    my $result = <OUTPUT>;
    close OUTPUT;

    $result =~ s/.*0x//;
    $result = hex $result;

    return $result;
}

# @sub writeScom
#
# Perform a putscom operation.
#
# @param addr - Address to write at.
# @param size - Size (in bytes) to write.
# @param data - Data to write.
#
sub writeScom
{
    my $addr = shift;
    my $size = shift;
    my $data = shift;

    my $command = sprintf("putscom pu -n%d -p%d %x %x -quiet > /dev/null",
                          $node, $proc, $addr, $data);

    system($command);

    return;
}

# @sub executeInstrCycles
#
# Execute a number of cycles.
#
# @param cycles - Number of cycles to execute.
#
sub executeInstrCycles
{
    my $cycles = shift;

    #No op on real HW
}

# @sub readyForInstructions
#
# Determines if system can execute cycles.
#
sub readyForInstructions
{
    return 1;
}

# @sub readExtImage
#
# Reads from the extended image file.
#
# @param addr - Address to read.
# @param size - Size to read.
sub readExtImage
{
    my $addr = shift;
    my $size = shift;

    my $extImage = extImageFile();

    seek $extImage, $addr, SEEK_SET;

    my $result = "";
    read $extImage, $result, $size;

    return $result;
}

# @sub extImageFile
#
# Returns a file descriptor to the extended image file.
#
my $extImage = 0;
sub extImageFile
{
    if ($extImage == 0)
    {
        my $path = determineImagePath(getImgPath());

        if (getIsTest())
        {
            $path = $path . "hbicore_test_extended.bin";
        }
        else
        {
            $path = $path . "hbicore_extended.bin";
        }

        print $path."\n";

        open($extImage, "< $path") or die "Cannot find extended image";
        binmode($extImage);
    }

    return $extImage;
}

##
##  Dummy function to match continuous trace call in VPO
##
sub checkContTrace
{

}


__END__

=head1 NAME

ecmd-debug-framework.pl

=head1 SYNOPSIS

ecmd-debug-framework.pl [options] --tool=<module>

=head1 OPTIONS

=over 8

=item B<--tool>=MODULE

Identify the tool module to execute.

=item B<--tool-options>="OPTIONS"

List of arguments to pass to the tool as options.

=item B<--force-hrmor>=value

Set the HRMOR to be a non-default value.  The default is 128MB.

=item B<--toolhelp>

Displays the help message for a specific debug tool.

=item B<--test>

Use the hbicore_test.syms file instead of the default.

=item B<--img-path>=PATH

The path to the "img" directory where the syms file, etc is located.
User can also set the env variable HBDIR to the path of the "img"
directory instead of using this option.

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=back

=head1 DESCRIPTION

Executes a debug tool module against an ecmd target.

=cut
