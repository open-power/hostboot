#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/tools/hb-parsedump.pl $
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
# Purpose:  This perl script will parse a hostboot dump file and extract
# the code version, kernel printk buffer and components traces.
#
# Author: CamVan Nguyen
# Last Updated: 07/06/2011
#

#
# Usage:
# hb-parsedump.pl <dumpfile> [--test]
#             [--img-path <path to .syms file, hbotStringFile, & errlparser>]
#             [--out-path <path to save output data>]\n");


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
use constant MAX_NUM_TRACE_BUFFERS => 48;
use constant DESC_ARRAY_ENTRY_ADDR_SIZE => 8;
use constant DESC_ARRAY_ENTRY_COMP_NAME_SIZE => 16;
use constant TRAC_DEFAULT_BUFFER_SIZE => 0x0800;
use constant TRAC_BUFFER_SIZE_OFFSET => 20;
use constant TRAC_BUFFER_SIZE_SIZE => 4;


#------------------------------------------------------------------------------
# Forward Declaration
#------------------------------------------------------------------------------
sub getAddrNSize;
sub readBinFile;
sub readStringBinFile;
sub writeBinFile;
sub appendBinFile;
sub printUsage;


#==============================================================================
# MAIN
#==============================================================================


#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
if ($numArgs < 1)
{
    #Print command line help
    print ("ERROR: Enter the hostboot dump file.\n");
    printUsage();
    exit (1);
}
elsif ($numArgs > 6)
{
    #Print command line help
    print ("ERROR: Too many arguments entered.\n");
    printUsage();
    exit (1);
}
elsif (($ARGV[0] eq "--help") || ($ARGV[0] eq "-h"))
{
    #Print command line help
    printUsage();
    exit (0);
}
elsif (substr($ARGV[0], 0, 1) eq '-')
{
    #Print command line help
    print ("ERROR: Enter the hostboot dump file.\n");
    printUsage();
    exit (1);
}

#------------------------------------------------------------------------------
# Parse the input argument(s)
#------------------------------------------------------------------------------

#Initialize default settings
my $hbSymsFile = "hbicore.syms";
my $hbStringFile = "hbotStringFile";
my $hbErrlParser = "errlparser";
my $cwd = getcwd();
my $outDir = $cwd;                #Default = current working directory

my $hbDir = $ENV{'HB_IMGDIR'};
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

#check if file exists and is not empty
if (!(-s $hbDumpFile))
{
    die "$hbDumpFile is not found or is empty.\n";

}

# Save the optional user specified arguments
for (my $i=1; $i<$numArgs; $i++)
{
    if ($ARGV[$i] eq "--img-path")
    {
        if (($i + 1) >= $numArgs)
        {
            die "No value given for --img-path parameter.\n";
        }
        $i++;
        $hbDir = $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "--out-path")
    {
        if (($i + 1) >= $numArgs)
        {
            die "No value given for --out-path parameter.\n";
        }
        $i++;
        $outDir = $ARGV[$i];
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

if (!(-e "$hbDir/$hbErrlParser"))
{
      die "Cannot find $hbDir/$hbErrlParser\n";
}

#------------------------------------------------------------------------------
#Print the files used
#------------------------------------------------------------------------------
print "hostboot dump file: $hbDumpFile\n";
print "hostboot syms file: $hbDir/$hbSymsFile\n";
print "hostboot string file: $hbDir/$hbStringFile\n";
print "hostboot errlog parser: $hbDir/$hbErrlParser\n";


#------------------------------------------------------------------------------
# Create dumpout subdir for extracted dump
#------------------------------------------------------------------------------
#print getcwd()."\n";
my $extDir = "$outDir/dumpout.$hbDumpFileBase";
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
    chdir "$cwd";
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
    chdir "$cwd";
}


#------------------------------------------------------------------------------
# Extract the component traces
#------------------------------------------------------------------------------
#Find address and size of the g_desc_array from the .syms file
$string = 'g_desc_array';
($addr, $size) = getAddrNSize($string, \@symslines);

if ((0 != $addr) && (0 != $size))
{
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

        # read a portion of the buffer header to get its size
        $buffer = readBinFile($hbDumpFile,
                              $compBufAddr+TRAC_BUFFER_SIZE_OFFSET,
                              TRAC_BUFFER_SIZE_SIZE);
        my $compBufferSize = unpack('H*',$buffer);
        $compBufferSize = hex $compBufferSize;


        #read the component trace buffer and save to file
        #read the component trace buffer
        $buffer = readBinFile($hbDumpFile, $compBufAddr, $compBufferSize );

        chdir "$extDir";

        #append to tracBIN
        appendBinFile('tracBIN', $buffer);

        chdir "$cwd";
    }

    #check if file exists and is not empty
    if (-s $extDir.'/tracBIN')
    {
        #create tracMERG file
        $string = sprintf ("fsp-trace -s %s/%s %s/tracBIN > %s/tracMERG",
                           $hbDir, $hbStringFile, $extDir, $extDir);
        #print "$string\n";
        `$string`;

        if (-s "$extDir/tracMERG")
        {
            #delete tracBIN file
            unlink $extDir.'/tracBIN';
        }
    }
}

#------------------------------------------------------------------------------
# Extract the error logs
#------------------------------------------------------------------------------
#Create error log file and write list header to file
my $errlFile = "$extDir/Errorlogs";
open (ERRLFILE, ">$errlFile") or die "Couldn't open $errlFile!";
print ERRLFILE "Error Log List:\n\n";
close(ERRLFILE);

#Invoke errlparser to parse and save the list of error logs
my $command = sprintf ("$hbDir/$hbErrlParser $hbDumpFile $hbDir/$hbSymsFile >> $errlFile");
#print "$command\n";
`$command`;

#Write error log detail header
open (ERRLFILE, ">>$errlFile") or die "Couldn't open $errlFile!";
print ERRLFILE "\n\nError Log Details:\n\n";
close(ERRLFILE);

#Invoke errlparser to parse and save the individual error log detail data
$command = sprintf ("$hbDir/$hbErrlParser $hbDumpFile $hbDir/$hbSymsFile -d >> $errlFile");
#print "$command\n";
`$command`;

#------------------------------------------------------------------------------
# Print location of dumpout dir
#------------------------------------------------------------------------------
print "\nDump extracted to $extDir\n";


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

#------------------------------------------------------------------------------
# Print command line help
#------------------------------------------------------------------------------
sub printUsage()
{
    print ("\nUsage: hb-parsedump.pl [--help] | <dumpfile> [--test]\n");
    print ("                       [--img-path <path to .syms file, hbotStringFile & errlparser>]\n");
    print ("                       [--out-path <path to save output data>]\n\n");
    print ("  This program will parse the hostboot dump file specified\n");
    print ("  and extract the code version, kernel printk buffer, component\n");
    print ("  traces & error logs.\n\n");
    print ("  User should copy the relevant .syms file, hbotStringFile and errlparser\n");
    print ("  to the current directory or set the env variable HB_IMGDIR to the path\n");
    print ("  of the files.\n\n");
    print ("  User should also set the env variable PATH to include the path to the fsp-trace");
    print (" program.\n\n");
    print ("  --img-path:  Overrides the automatically detected .syms file, hbotStringFile\n");
    print ("               and errlparser in HB_IMGDIR or the current directory.\n");
    print ("               This program will search for the files in the following order:\n");
    print ("               1.  from the path specified by user\n");
    print ("               2.  from HB_IMGDIR if it is defined\n");
    print ("               3.  from the current directory\n");
    print ("  --out-path:  Directory where the output data will be saved.\n");
    print ("               Default path is the current directory.\n");
    print ("  --test:      Use the hbicore_test.syms file vs the hbicore.syms file\n");
}
