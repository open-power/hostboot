#!/usr/bin/perl

#
# Purpose:  This perl script will parse a hostboot dump file and extract
# the code version, kernel printk buffer and components traces.
#
# Author: CamVan Nguyen
# Last Updated: 07/06/2011
#

#
# Usage:
# exthbdump.pl <path/hbDumpFile> <path/symsFile>


#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use warnings;
use Cwd;
use File::Basename;
use File::Copy;

#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------
use constant MAX_NUM_TRACE_BUFFERS => 24;
use constant DESC_ARRAY_ENTRY_ADDR_SIZE => 8;
use constant DESC_ARRAY_ENTRY_COMP_NAME_SIZE => 16;
use constant TRAC_DEFAULT_BUFFER_SIZE => 0x0800;


#------------------------------------------------------------------------------
# Forward Declaration
#------------------------------------------------------------------------------
sub getAddrNSize;
sub readBinFile;
sub readStringBinFile;
sub writeBinFile;
sub appendBinFile;


#==============================================================================
# MAIN
#==============================================================================


#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
if ($numArgs < 1)
{
    print ("\nUsage: exthbdump.pl <dumpfile> [--test] [--dir <path to .syms file & hbotStringFile>]\n\n");
    print ("  This program will parse the hostboot dump file specified\n");
    print ("  and extract the code version, kernel printk buffer and traces\n");
    print ("  to the current directory.\n\n");
    print ("  User should copy the relevant .syms file and hbotStringFile\n");
    print ("  to the current directory or set the env variable HBDIR to the path\n");
    print ("  of the hbicore.syms/hbicore_test.syms files & hbotStringFile.\n\n");
    print ("  User should also copy the fsp-trace program to the current directory\n");
    print ("  or set the env variable PATH to include the path to the program.\n\n");
    print ("  --dir:  Override the automatically detected .syms and hbotStringFile\n");
    print ("       in HBDIR or the current directory.  This program will search\n");
    print ("       for the files in the following order:\n");
    print ("       1.  from the path specified by user\n");
    print ("       2.  from HBDIR if it is defined\n");
    print ("       3.  from the current directory\n");
    print ("  --test:  Use the hbicore_test.syms file vs the hbicore.syms file\n");
    print ("\nNOTE: User can run cpfiles.pl from the git repository to\n");
    print ("  copy all files needed to parse the hostboot dump to the current\n");
    print ("  directory prior to running this program.\n");
    exit(1);
}

#------------------------------------------------------------------------------
# Parse the input argument(s)
#------------------------------------------------------------------------------

#Initialize default settings
my $hbSymsFile = "hbicore.syms";
my $hbStringFile = "hbotStringFile";

my $hbDir = $ENV{'HBDIR'};
if (defined ($hbDir))
{
    unless ($hbDir ne "")
    {
        $hbDir = '.';             #Set to current directory
    }
}
else
{
    $hbDir = '.';                 #Set to current directory
}

# Save the user specifed dump file
my $hbDumpFile = $ARGV[0];
my $hbDumpFileBase = basename($hbDumpFile);

# Save the optional user specified arguments
for (my $i=1; $i<$numArgs; $i++)
{
    if ($ARGV[$i] eq "--dir")
    {
        if (($i + 1) >= $numArgs)
        {
            die "No value given for --dir parameter.\n";
        }
        $i++;
        $hbDir = $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "--test")
    {
        #Use hbicore_test.syms
        $hbSymsFile = 'hbicore_test.syms';
    }
    else
    {
        print "Invalid argument entered:  $ARGV[$i]\n";
        exit(1);
    }
}

#Check for existence of .syms file and hbotStringFile
if (!(-e "$hbDir/$hbSymsFile"))
{
      die "Cannot find $hbDir/$hbSymsFile\n";
}

if (!(-e "$hbDir/$hbStringFile"))
{
      die "Cannot find $hbDir/$hbStringFile\n";
}

#------------------------------------------------------------------------------
#Print the files used
#------------------------------------------------------------------------------
print "hostboot dump file: $hbDumpFile\n";
print "hostboot syms file: $hbDir/$hbSymsFile\n";
print "hostboot string file: $hbDir/$hbStringFile\n";


#------------------------------------------------------------------------------
# Create dumpout subdir for extracted dump
#------------------------------------------------------------------------------
#print getcwd()."\n";
my $extDir = "dumpout.$hbDumpFileBase";
if (-d $extDir)
{
    print "ERROR: directory $extDir exists.\n";
    exit (1);
}

mkdir $extDir;


#------------------------------------------------------------------------------
# Open and read the .syms file
#------------------------------------------------------------------------------
open SYMSFILE, "$hbDir/$hbSymsFile" or
    die "ERROR: $hbDir/$hbSymsFile not found : $!";
my @symslines = <SYMSFILE>;        # Read it into an array
close(SYMSFILE);                   # Close the file

unless (@symslines)
{
    print "ERROR: $hbDir/$hbSymsFile is empty\n";
    exit (1);
}


#------------------------------------------------------------------------------
# Extract the code version / image id
#------------------------------------------------------------------------------
#Find address and size of the hbi_ImageId from the .syms file
my $string = 'hbi_ImageId';
my $buffer = 0;
my ($addr, $size) = getAddrNSize($string, \@symslines);

if (0 != $addr)
{
    #Read the hbi_ImageId from dump file and save to file
    $buffer = readStringBinFile($hbDumpFile, $addr);

    chdir "$extDir";
    writeBinFile($string, $buffer);
    chdir "../";
}


#------------------------------------------------------------------------------
# Extract the kernel printk buffer
#------------------------------------------------------------------------------
#Find address and size of the kernel_printk_buffer from the .syms file
$string = 'kernel_printk_buffer';
($addr, $size) = getAddrNSize($string, \@symslines);

if ((0 != $addr) && (0 != $size))
{
    #Read the kernel printk buffer from dump file and save to file
    #$buffer = readBinFile($hbDumpFile, $addr, $size);
    $buffer = readStringBinFile($hbDumpFile, $addr);
    chdir "$extDir";
    writeBinFile($string, $buffer);
    chdir "../";
}


#------------------------------------------------------------------------------
# Extract the component traces
#------------------------------------------------------------------------------
#Find address and size of the g_desc_array from the .syms file
$string = 'g_desc_array';
($addr, $size) = getAddrNSize($string, \@symslines);

if ((0 != $addr) && (0 != $size))
{
    #make subdir component_traces to store all traces
    my $traceDir = $extDir.'/component_traces';
    mkdir $traceDir;

    #Read the g_desc_array from dump file and save the trace buffers
    for (my $i = 0; $i < MAX_NUM_TRACE_BUFFERS; $i++)
    {
        #get the component name
        my $compName = readStringBinFile($hbDumpFile, $addr);
        chomp $compName;
        last if ($compName eq "");

        #get the component trace buffer address
        $addr += DESC_ARRAY_ENTRY_COMP_NAME_SIZE;
        $buffer = readBinFile($hbDumpFile, $addr, DESC_ARRAY_ENTRY_ADDR_SIZE);
        my $compBufAddr= unpack('H*',$buffer);
        $compBufAddr = hex $compBufAddr;
        #print "Component: $compName, $buffer, $compBufAddr\n";
        $addr += DESC_ARRAY_ENTRY_ADDR_SIZE;

        #read the component trace buffer and save to file
        $buffer = readBinFile($hbDumpFile, $compBufAddr, TRAC_DEFAULT_BUFFER_SIZE);

        chdir "$traceDir";

        writeBinFile($compName, $buffer);

        #also append to tracBIN
        appendBinFile('tracBIN', $buffer);

        chdir "../../";
    }

    #check if file exists and is not empty
    if (-s $traceDir.'/tracBIN')
    {
        #create tracMERG file
        $string = sprintf ("fsp-trace -s %s/%s %s/tracBIN > %s/tracMERG",
                           $hbDir, $hbStringFile, $traceDir, $traceDir);
        #print "$string\n";
        `$string`;

        if (-s "$traceDir/tracMERG")
        {
            #delete tracBIN file
            unlink $traceDir.'/tracBIN';
        }
    }
}

#------------------------------------------------------------------------------
# Save dump file to dumpout dir
#------------------------------------------------------------------------------
copy ($hbDumpFile, $extDir) or die "Copy failed: $!";

#------------------------------------------------------------------------------
# Print location of dumpout dir
#------------------------------------------------------------------------------
print "Dump extracted to ./$extDir\n";


#==============================================================================
# SUBROUTINES
#==============================================================================

#------------------------------------------------------------------------------
# Parse the .syms data to find the relevant address and size for the data
# requested.
#------------------------------------------------------------------------------
sub getAddrNSize($\@)
{
    my $addr = 0;
    my $size = 0;

    my $string = $_[0];
    my (@array) = @{$_[1]};
    #print "$string\n";
    #print "@array\n";

    #search for string in array
    my @line = grep /$string/,@array;
    #print "@line\n";

    #if found string
    if (@line)
    {
        my @list = split(/,+/,$line[0]);
        #print "@list\n";

        $addr = hex $list[1];
        $size = hex $list[3];
        #print "$addr\n";
        #print "$size\n";
    }

    return($addr, $size);
}

#------------------------------------------------------------------------------
# Read a block of data from a binary file.
#------------------------------------------------------------------------------
sub readBinFile($$$)
{
    my ($file, $addr, $size) = @_;
    #print "$file, $addr, $size\n";

    #Open the dump file for reading
    open FILE, $file or die "ERROR: $file not found : $!";
    binmode FILE;

    seek FILE, $addr, 0 or die "Couldn't seek to $addr in $file: $!\n";
    #print tell FILE; print "\n";
    my $bytesRead = read(FILE, my $buffer, $size);
    #print tell FILE; print "\n";
    #print "#bytes read: $bytesRead\n";
    #print "buffer: $buffer\n";

    close (FILE);
    return ($buffer);
}

#------------------------------------------------------------------------------
# Read a NULL terminated string from a binary file.
#------------------------------------------------------------------------------
sub readStringBinFile($$)
{
    my ($file, $addr) = @_;
    #print "$file, $addr\n";

    #Open the dump file for reading
    open FILE, $file or die "ERROR: $file not found : $!";
    binmode FILE;

    local $/ = "\0";       #Set to NULL termination
    #my $tmp = $/;
    #$/ = "\0";            #Set to NULL termination
    seek FILE, $addr, 0 or die "Couldn't seek to $addr in $file: $!\n";
    #print tell FILE; print "\n";
    my $string = <FILE>;
    #print tell FILE; print "\n";
    chomp $string;         #Remove NULL termination
    #print "$string\n";
    #$/ = $tmp;            #Restore $/

    close (FILE);
    return ($string);
}

#------------------------------------------------------------------------------
# Write a block of data to a binary file.
#------------------------------------------------------------------------------
sub writeBinFile($$)
{
    my ($file, $buffer) = @_;
    open (FILE, ">$file") or die "ERROR: $file cannot be opened: $!";
    binmode FILE;
    print FILE $buffer;
    close (FILE);
}

#------------------------------------------------------------------------------
# Append a block of data to a binary file.
#------------------------------------------------------------------------------
sub appendBinFile($$)
{
    my ($file, $buffer) = @_;
    open (FILE, ">>$file") or die "ERROR: $file cannot be opened: $!";
    binmode FILE;
    print FILE $buffer;
    close (FILE);
}
