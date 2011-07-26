#!/usr/bin/perl

#
# Purpose:  This perl script works on VBU and will dump either the entire L3 or
# relevant data such as the code version, kernel printk buffer & component traces.
#
# Author: CamVan Nguyen
# Last Updated: 07/19/2011
#

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use warnings;
use POSIX;


#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------
use constant MAX_NUM_TRACE_BUFFERS => 24;
use constant DESC_ARRAY_ENTRY_ADDR_SIZE => 8;
use constant DESC_ARRAY_ENTRY_COMP_NAME_SIZE => 16;
use constant TRAC_DEFAULT_BUFFER_SIZE => 0x0800;
use constant CACHE_LINE_SIZE => 128;


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
# Parse optional input arguments
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
#print "num args = $numArgs\n";

#Initialize default settings
my $hbSymsFile = "hbicore.syms";  #Use hbicore.syms
my $hbStringFile = "hbotStringFile";
my $dumpPrintk = 0;               #Flag to dump printk
my $dumpTrace = 0;                #Flag to dump trace buffers
my $dumpAll = 1;                  #Flag to dump everything
my @comp;                         #Array of component trace buffers to dump
my @symsLines;                    #Array to store the .syms file data

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

for (my $i=0; $i<$numArgs; $i++)
{
    if (($ARGV[$i] eq "--help") || ($ARGV[$i] eq "-h"))
    {
        #Print command line help
        printUsage();
        exit (0);
    }
    elsif ($ARGV[$i] eq "--dir")
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
    elsif ($ARGV[$i] eq "--printk")
    {
        #Set flag to dump printk
        $dumpPrintk = 1;
        $dumpAll = 0;
    }
    elsif ($ARGV[$i] eq "--trace")
    {
        #Set flag to dump component trace buffers
        $dumpTrace = 1;
        $dumpAll = 0;

        for ( $i += 1; $i < $numArgs; $i++)
        {
            if (substr($ARGV[$i], 0, 1) eq '-')
            {
                $i -=1;
                last;
            }

            push (@comp, $ARGV[$i]);
        }
    }
    else
    {
        print "Invalid argument entered:  $ARGV[$i]\n";
        printUsage();
        exit(1);
    }
}

#------------------------------------------------------------------------------
# Check for files needed to dump printk and component traces
#------------------------------------------------------------------------------
if (!$dumpAll)
{
    #Need .syms file for both printk and traces
    if (!(-e "$hbDir/$hbSymsFile"))
    {
      die "Cannot find $hbDir/$hbSymsFile\n";
    }

    #Need string file for traces
    if (!(-e "$hbDir/$hbStringFile") && $dumpTrace)
    {
      die "Cannot find $hbDir/$hbStringFile\n";
    }

    #Print the files that will be used
    print "hostboot syms file: $hbDir/$hbSymsFile\n";

    if ($dumpTrace)
    {
        print "hostboot string file: $hbDir/$hbStringFile\n";
    }

    #------------------------------------------------------------------------------
    # Open and read the .syms file
    #------------------------------------------------------------------------------
    open SYMSFILE, "$hbDir/$hbSymsFile" or
        die "ERROR: $hbDir/$hbSymsFile not found : $!";
    @symsLines = <SYMSFILE>;        # Read it into an array
    close(SYMSFILE);                   # Close the file

    unless (@symsLines)
    {
        print "ERROR: $hbDir/$hbSymsFile is empty\n";
        exit (1);
    }
}

#------------------------------------------------------------------------------
#Flush L2 - this step is needed in order to dump L3 quickly
#------------------------------------------------------------------------------
my $command = "";
$command = "/afs/awd.austin.ibm.com/projects/eclipz/lab/p8/gsiexe/p8_runso.x86 ";
$command .= "/afs/awd.austin.ibm.com/projects/eclipz/lab/p8/gsiexe/p8_l2_flush_x86.so ";
$command .= "-c3 -debug5.6";
#print "$command\n";
system("$command");


#------------------------------------------------------------------------------
# Dump the kernel printk buffer
#------------------------------------------------------------------------------
my $buffer = 0;
my $offset = 0;
my $cacheLines = 0;
my $string = "";
my $addr = 0;
my $size = 0;

if ($dumpPrintk)
{
    #Find address and size of the kernel_printk_buffer from the .syms file
    $string = 'kernel_printk_buffer';
    ($addr, $size) = getAddrNSize($string, \@symsLines);

    if ((0 != $addr) && (0 != $size))
    {
        print "Reading the kernel printk buffer...\n\n";

        $offset = $addr % CACHE_LINE_SIZE;
        $cacheLines = ceil($size / CACHE_LINE_SIZE);
        if ($offset != 0)
        {
            $cacheLines += 1;
        }
        #print "addr $addr, offset $offset, size $size, cacheLines $cacheLines\n";

        #Read the kernel printk buffer from L3 and save to file
        $command = sprintf ("time p8_dump_l3 %x $cacheLines -f $string -b -c3",
                            $addr);
        #print "$command\n";
        system("$command");

        #Extract and save just the kernel printk buffer
        $buffer = readStringBinFile($string, $offset);
        writeBinFile($string, $buffer);

        #Output to screen
        print "\nKernel printk buffer:";
        print "\n=====================\n\n$buffer\n";
        print "\n=====================\n\n";
        print "Data saved to file $string\n\n";
    }
}


#------------------------------------------------------------------------------
# Extract the component traces
#------------------------------------------------------------------------------
if ($dumpTrace)
{
    #Find address and size of the g_desc_array from the .syms file
    $string = 'g_desc_array';
    ($addr, $size) = getAddrNSize($string, \@symsLines);

    if ((0 != $addr) && (0 != $size))
    {
        print "Reading the component trace buffer(s)...\n\n";

        #Read the g_desc_array from L3 and save to file
        $offset = $addr % CACHE_LINE_SIZE;
        $cacheLines = ceil($size / CACHE_LINE_SIZE);
        if ($offset != 0)
        {
            $cacheLines += 1;
        }
        #print "addr $addr, offset $offset, size $size, cacheLines $cacheLines\n";

        $command = sprintf ("time p8_dump_l3 %x $cacheLines -f $string -b -c3",
                            $addr);
        #print "$command\n";
        system("$command");

        #Save the trace buffers
        $addr = $offset;
        for (my $i = 0; $i < MAX_NUM_TRACE_BUFFERS; $i++)
        {
            #Get the component name
            my $compName = readStringBinFile($string, $addr);
            chomp $compName;
            last if ($compName eq "");

            #Get the component trace buffer address
            $addr += DESC_ARRAY_ENTRY_COMP_NAME_SIZE;
            $buffer = readBinFile($string, $addr, DESC_ARRAY_ENTRY_ADDR_SIZE);
            my $compBufAddr= unpack('H*',$buffer);
            $compBufAddr = hex $compBufAddr;
            $addr += DESC_ARRAY_ENTRY_ADDR_SIZE;

            if ((grep $_ eq $compName, @comp) || (@comp == 0))
            {
                #Read the component trace buffer and save to file
                $offset = $compBufAddr % CACHE_LINE_SIZE;
                $cacheLines = ceil(TRAC_DEFAULT_BUFFER_SIZE / CACHE_LINE_SIZE);
                if ($offset != 0)
                {
                    $cacheLines += 1;
                }
                #print "$compName, addr $compBufAddr, offset $offset, cacheLines $cacheLines\n";

                $command = sprintf ("time p8_dump_l3 %x $cacheLines -f trace.out -b -c3",
                                   $compBufAddr);
                #print "$command\n";
                system("$command");

                #Extract just the component trace
                $buffer = readBinFile("trace.out", $offset, TRAC_DEFAULT_BUFFER_SIZE);

                #Append to tracBIN
                appendBinFile('tracBIN', $buffer);
                unlink "trace.out";
            }
        }

        #Check if file exists and is not empty
        if (-s "tracBIN")
        {
            print "\n";

            #create tracMERG file
            `fsp-trace -s $hbDir/$hbStringFile tracBIN | tee tracMERG`;

            #Check if file exists and is not empty
            #This will be false if the fsp-trace tool cannot be found
            if (-s "tracMERG")
            {
                open FILE, "tracMERG" or die "ERROR: $!";
                my @lines = <FILE>;        # Read it into an array
                close(FILE);               # Close the file
                print "\nComponent trace buffer(s):";
                print "\n==========================\n\n";
                print "@lines\n";        # Output to screen
                print "\n==========================\n\n";
                print "Data saved to file tracMERG\n\n";

                #delete tracBIN file
                unlink "tracBIN";
            }
            else
            {
                print "\nData saved to file tracBIN\n\n";
            }
        }
        else
        {
            print "\nComponent trace buffer(s) not found\n\n";
        }

        #Delete g_desc_array file
        unlink "$string";
    }
}


#------------------------------------------------------------------------------
#Dump the entire L3 to a file
#------------------------------------------------------------------------------
if ($dumpAll)
{
    print "Dumping L3...\n\n";

    #Get current timestamp
    my $timeStamp = strftime "%Y%m%d%H%M\n", localtime;
    chomp $timeStamp;
    #print "timestamp: $timeStamp\n";

    #Dump L3 to file
    my $hbDumpFile = "hbdump.$timeStamp";
    $command = "time p8_dump_l3 0 65536 -f $hbDumpFile -b -c3";
    #print "$command\n";
    system("$command");

    print "\nDump saved to $hbDumpFile.\n";

    #Check if we can extract the dump
    if ((-e "$hbDir/exthbdump.pl") &&
        (-e "$hbDir/$hbSymsFile") &&
        (-e "$hbDir/$hbStringFile"))
    {
        if ($hbSymsFile eq "hbicore_test.syms")
        {
            $command = "$hbDir/exthbdump.pl $hbDumpFile --dir $hbDir --test";
        }
        else
        {
            $command = "$hbDir/exthbdump.pl $hbDumpFile --dir $hbDir";
        }

        print "\nExtracting dump...\n";
        #print "$command\n";
        system"$command";

        #print "Dump extracted to dumpout.$hbDumpFile\n\n";
    }
    else
    {
        print "Use exthbdump.pl to extract and view dump.\n\n";
    }
}


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
    print ("\nUsage: hb-dump.pl [--help] | [--dir <path to .syms file & hbotStringFile>]\n");
    print ("                  [--test] [--printk]\n");
    print ("                  [--trace [<compName1 compName2 compName3 ...>]]\n\n");
    print ("  This program dumps the user requested data from L3.\n");
    print ("  If no options are specified, this program will dump the entire L3 to a file.\n");
    print ("  Use the exthbdump.pl program to parse and view data in the file.\n\n");
    print ("  User should copy the relevant .syms file and hbotStringFile\n");
    print ("  to the current directory or set the env variable HBDIR to the path\n");
    print ("  of the hbicore.syms/hbicore_test.syms files & hbotStringFile.\n\n");
    print ("  User should also copy the fsp-trace program to the current directory\n");
    print ("  or set the env variable PATH to include the path to the program.\n\n");
    print ("  --help: Prints usage information\n");
    print ("  --dir:  Override the automatically detected .syms and hbotStringFile\n");
    print ("       in HBDIR or the current directory.  This program will search\n");
    print ("       for the files in the following order:\n");
    print ("       1.  from the path specified by user\n");
    print ("       2.  from HBDIR if it is defined\n");
    print ("       3.  from the current directory\n");
    print ("  --test:  Use the hbicore_test.syms file vs the hbicore.syms file\n");
    print ("  --printk:  Dumps the kernel printk buffer only\n");
    print ("  --trace:  Dumps all or just the user specified component trace buffer(s)\n");
}

