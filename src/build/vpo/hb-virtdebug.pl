#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/vpo/hb-virtdebug.pl $
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
use Cwd;


#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------
use constant MAX_NUM_TRACE_BUFFERS => 48;
use constant DESC_ARRAY_ENTRY_ADDR_SIZE => 8;
use constant DESC_ARRAY_ENTRY_COMP_NAME_SIZE => 16;
use constant TRAC_DEFAULT_BUFFER_SIZE => 0x0800;
use constant CACHE_LINE_SIZE => 128;
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
# Parse optional input arguments
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
#print "num args = $numArgs\n";
#print "arg list: @ARGV\n";

#Initialize default settings
my $hbSymsFile = "hbicore.syms";  #Use hbicore.syms
my $hbStringFile = "hbotStringFile";
my $hbErrlParser = "errlparser";
my $dumpPrintk = 0;               #Flag to dump printk
my $dumpTrace = 0;                #Flag to dump trace buffers
my $dumpErrl = 0;                 #Flag to dump error logs
my $dumpErrlList = 1;             #Flag to dump a listing of all error logs
my $dumpErrlDtl = 0;              #Flag to dump error log detail data
my $errLogId = "all";             #Error log id; default = all
my $dumpAll = 1;                  #Flag to dump everything
my @comp;                         #Array of component trace buffers to dump
my @symsLines;                    #Array to store the .syms file data
my $outDir = getcwd();            #Default = current working directory
my @ecmdOpt;                      #Array of ecmd options
my $core = "3";                   #Default is core 3

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
    elsif ($ARGV[$i] eq "--in")
    {
        if (($i + 1) >= $numArgs)
        {
            die "No value given for --in parameter.\n";
        }
        $i++;
        $hbDir = $ARGV[$i];
    }
    elsif ($ARGV[$i] eq "--out")
    {
        if (($i + 1) >= $numArgs)
        {
            die "No value given for --out parameter.\n";
        }
        $i++;
        $outDir = $ARGV[$i];
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
    elsif ($ARGV[$i] eq "--errl")
    {
        #Set flag to dump the error logs
        $dumpErrl = 1;
        $dumpAll = 0;

        last if (($i + 1) >= $numArgs);
        $i++;

        if ($ARGV[$i] eq "-d")
        {
            $dumpErrlList = 0;
            $dumpErrlDtl = 1;

            last if (($i + 1) >= $numArgs);
            $i++;

            if (substr($ARGV[$i], 0, 1) eq '-')
            {
                $i--;
            }
            else
            {
                if (isdigit($ARGV[$i]))
                {
                    $errLogId = $ARGV[$i];
                }
                else
                {
                    die "ERROR:  Enter logid or 'all'"
                        unless ($ARGV[$i] =~ /all/i);
                }
            }
        }
        elsif ($ARGV[$i] ne "-l")
        {
            $i--;
        }
    }
    elsif ($ARGV[$i] =~ m/^-[c](\d+)/)
    {
        $core = $1;
    }
    elsif ($ARGV[$i] =~ m/^-[knsp]\d+/)
    {
        push(@ecmdOpt, $ARGV[$i]);
    }
    else
    {
        print "Invalid argument entered:  $ARGV[$i]\n";
        printUsage();
        exit(1);
    }
}

push(@ecmdOpt, "-c$core");
#print "ecmd options = @ecmdOpt\n";


#------------------------------------------------------------------------------
# Check for files needed to dump printk and component traces
#------------------------------------------------------------------------------
if (!$dumpAll)
{
    #Need .syms file for error logs, printk and traces
    if (!(-e "$hbDir/$hbSymsFile"))
    {
      die "Cannot find $hbDir/$hbSymsFile\n";
    }

    #Need string file for traces
    if (!(-e "$hbDir/$hbStringFile") && $dumpTrace)
    {
      die "Cannot find $hbDir/$hbStringFile\n";
    }

    #Need errlparser for error logs
    if (!(-e "$hbDir/$hbErrlParser") && $dumpErrl)
    {
      die "Cannot find $hbDir/$hbErrlParser\n";
    }

    #Print the files that will be used
    print "hostboot syms file: $hbDir/$hbSymsFile\n";

    if ($dumpTrace)
    {
        print "hostboot string file: $hbDir/$hbStringFile\n";
    }

    if ($dumpErrl)
    {
        print "hostboot error log parser: $hbDir/$hbErrlParser\n";
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
# Output reminder to stop instructions
#------------------------------------------------------------------------------
print "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
print "\nREMINDER:  User need to stop instructions prior to running this program.\n";
print "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

#------------------------------------------------------------------------------
#Flush L2 - this step is needed in order to dump L3 quickly
#------------------------------------------------------------------------------
my $command = "";
$command = "/afs/awd.austin.ibm.com/projects/eclipz/lab/p8/gsiexe/p8_l2_flush.x86 ";
$command .= "@ecmdOpt -loop ex -debug5.6";
print "$command\n";
die if (system("$command") != 0);


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
        print "\nReading the kernel printk buffer...\n\n";

        $string = "$outDir/$string";

        $offset = $addr % CACHE_LINE_SIZE;
        $cacheLines = ceil($size / CACHE_LINE_SIZE);
        if ($offset != 0)
        {
            $cacheLines += 1;
        }
        #print "addr $addr, offset $offset, size $size, cacheLines $cacheLines\n";

        #Read the kernel printk buffer from L3 and save to file
        $command = sprintf ("p8_dump_l3 %x $cacheLines -f $string -b @ecmdOpt",
                            $addr);
        print "$command\n";
        die if (system("$command") != 0);

        if (-s $string)
        {
	    #Extract and save just the kernel printk buffer
	    $buffer = readStringBinFile($string, $offset);

	    writeBinFile($string, $buffer);

	    #Output to screen
	    print "\nKernel printk buffer:";
	    print "\n=====================\n\n$buffer\n";
	    print "\n=====================\n\n";
	    print "Data saved to file $string\n\n";
        }
        else
        {
            print "\nWARNING: Cannot read the kernel printk buffer.\n";
        }
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
        print "\nReading the component trace buffer(s)...\n\n";

        $string = "$outDir/$string";

        #Read the g_desc_array from L3 and save to file
        $offset = $addr % CACHE_LINE_SIZE;
        $cacheLines = ceil($size / CACHE_LINE_SIZE);
        if ($offset != 0)
        {
            $cacheLines += 1;
        }
        #print "addr $addr, offset $offset, size $size, cacheLines $cacheLines\n";

        $command = sprintf ("p8_dump_l3 %x $cacheLines -f $string -b @ecmdOpt",
                            $addr);
        print "$command\n";
        die if (system("$command") != 0);

        #Save the trace buffers
        $addr = $offset;
        for (my $i = 0; ($i < MAX_NUM_TRACE_BUFFERS) && (-s $string); $i++)
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

                $command = sprintf ("p8_dump_l3 %x $cacheLines -f $outDir/trace.out -b @ecmdOpt",
                                   $compBufAddr);
                print "$command\n";
                die if (system("$command") != 0);

                # Get the length of the buffer from the component trace header 
                $buffer = readBinFile( "$outDir/trace.out", 
                                       $offset+TRAC_BUFFER_SIZE_OFFSET, 
                                       TRAC_BUFFER_SIZE_SIZE );

                my $compBufferSize=unpack('H*',$buffer);
                $compBufferSize = hex $compBufferSize;

                # Re-read trace buffer using correct buffer size 
                $offset = $compBufAddr % CACHE_LINE_SIZE;
                $cacheLines = ceil( $compBufferSize / CACHE_LINE_SIZE);
                if ($offset != 0)
                {
                    $cacheLines += 1;
                }
                #print "$compName, addr $compBufAddr, offset $offset, cacheLines $cacheLines\n";
                $command = sprintf ("p8_dump_l3 %x $cacheLines -f $outDir/trace.out -b @ecmdOpt",
                                   $compBufAddr);
                print "$command\n";
                die if (system("$command") != 0);

                #Extract just the component trace
                $buffer = readBinFile("$outDir/trace.out", $offset, $compBufferSize);

                #Append to tracBIN
                appendBinFile("$outDir/tracBIN", $buffer);
                unlink "$outDir/trace.out";
            }
        }

        #Check if file exists and is not empty
        if (-z $string)
        {
            print "\nWARNING: Cannot read the component trace buffers.\n";
        }
        elsif (-s "$outDir/tracBIN")
        {
            print "\n";

            #create tracMERG file
            `fsp-trace -s $hbDir/$hbStringFile $outDir/tracBIN | tee $outDir/tracMERG`;

            #Check if file exists and is not empty
            #This will be false if the fsp-trace tool cannot be found
            if (-s "$outDir/tracMERG")
            {
                open FILE, "$outDir/tracMERG" or die "ERROR: $!";
                my @lines = <FILE>;        # Read it into an array
                close(FILE);               # Close the file
                print "\nComponent trace buffer(s):";
                print "\n==========================\n\n";
                print "@lines\n";        # Output to screen
                print "\n==========================\n\n";
                print "Data saved to $outDir/tracMERG\n\n";

                #delete tracBIN file
                unlink "$outDir/tracBIN";
            }
            else
            {
                print "\nData saved to $outDir/tracBIN\n\n";
            }
        }
        else
        {
            print "\nComponent trace buffer(s) not found.\n\n";
        }

        #Delete g_desc_array file
        unlink "$string";
    }
}


#------------------------------------------------------------------------------
# Dump the error logs 
#------------------------------------------------------------------------------
if ($dumpErrl)
{
    #Find address and size of the g_ErrlStorage from the .syms file
    $string = 'g_ErrlStorage';
    ($addr, $size) = getAddrNSize($string, \@symsLines);

    if ((0 != $addr) && (0 != $size))
    {
        print "\nReading the error log(s)...\n\n";

        $string = "$outDir/$string";

        #Read the binary error log buffer from L3 and save to file
        $offset = $addr % CACHE_LINE_SIZE;
        $cacheLines = ceil($size / CACHE_LINE_SIZE);
        if ($offset != 0)
        {
            $cacheLines += 1;
        }
        #print "addr $addr, offset $offset, size $size, cacheLines $cacheLines\n";

        $command = sprintf ("p8_dump_l3 %x $cacheLines -f $string -b @ecmdOpt",
                            $addr);
        print "$command\n";
        die if (system("$command") != 0);

        if (-s $string)
        {
            #Extract and save just the error log buffer
            $buffer = readBinFile($string, $offset, $size);
            writeBinFile($string, $buffer);

            #Parse error log buffer and save to file
            my $hbErrlFile = "$outDir/Errorlogs";
            if ($dumpErrlList)
            {
                $command = sprintf("$hbDir/$hbErrlParser $string|tee $hbErrlFile");
            }
            else
            {
                $command = sprintf("$hbDir/$hbErrlParser $string -d $errLogId |tee $hbErrlFile");
            }
            die if (system("$command") != 0);

            if (-s $hbErrlFile)
            {
                print "\n\nData saved to file $hbErrlFile\n\n";
                unlink "$string";
            }
        }
        else
        {
	    print "\nWARNING: Cannot read the error logs.\n";
        }
    }
}


#------------------------------------------------------------------------------
#Dump the entire L3 to a file
#------------------------------------------------------------------------------
if ($dumpAll)
{
    print "\nDumping L3...\n\n";

    #Get current timestamp
    my $timeStamp = strftime "%Y%m%d%H%M\n", localtime;
    chomp $timeStamp;
    #print "timestamp: $timeStamp\n";

    #Dump L3 to file
    my $hbDumpFile = "$outDir/hbdump.$timeStamp";
    $command = "p8_dump_l3 0 65536 -f $hbDumpFile -b @ecmdOpt";
    print "$command\n";
    die if (system("$command") != 0);

    #Check if hbDumpFile exists and is not empty
    if (-s "$hbDumpFile")
    {
        print "\nHostBoot dump saved to $hbDumpFile.\n";
        print "Use hb-parsedump.pl program to parse the dump.\n";
    }
    else
    {
        print "\nWARNING: Cannot dump L3.  Did you stop instructions?\n\n";
	unlink $hbDumpFile;
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
    print ("\nUsage: hb-virtdebug.pl [--help] | [--in <path to .syms file, hbotStringFile & errlparser>]\n");
    print ("                  [--out <path to save output data>]\n");
    print ("                  [--test] [--errl [-l | -d [<logid>|all]] [--printk]\n");
    print ("                  [--trace [<compName1 compName2 compName3 ...>]]\n");
    print ("                  [-k#] [-n#] [-s#] [-p#] [-c#]\n\n");
    print ("  This program retrieves the user requested data from L3.\n");
    print ("  If no options are specified, this program will dump the entire L3 to a file.\n");
    print ("  Use the hb-parsedump.pl program to expand and view data in the file.\n\n");
    print ("  User should copy the relevant .syms file, hbotStringFile & errlparser\n");
    print ("  to the current directory or set the env variable HBDIR to the path\n");
    print ("  of the files.\n\n");
    print ("  User should also set the env variable PATH to include the path to the fsp-trace program.\n\n");
    print ("  --help            Prints usage information\n");
    print ("  --in              Overrides the automatically detected .syms file,\n");
    print ("                    hbotStringFile & errlparser in HBDIR or the current\n");
    print ("                    directory.  This program will search for the files in\n");
    print ("                    the following order:\n");
    print ("                        1.  from the path specified by user\n");
    print ("                        2.  from HBDIR if it is defined\n");
    print ("                        3.  from the current directory\n");
    print ("  --out             Directory where the output data will be saved\n");
    print ("                    Default path is the current directory\n");
    print ("  --test            Use the hbicore_test.syms file vs the hbicore.syms file\n");
    print ("  --errl            Dumps the error logs\n");
    print ("      -l            Dumps a listing of all the error logs\n");
    print ("      -d <logid>    Dumps detailed data of the specified error log\n");
    print ("      -d [all]      Dumps detailed data of all error logs\n");
    print ("  --printk          Dumps the kernel printk buffer only\n");
    print ("  --trace           Dumps all or just the user specified component trace buffer(s)\n");
    print ("  -k#               Specify which cage to act on (default = 0)\n");
    print ("  -n#               Specify which node to act on (default = 0)\n");
    print ("  -s#               Specify which slot to act on (default = 0)\n");
    print ("  -p#               Specify which chip position to act on (default = 0)\n");
    print ("  -c#               Specify which core/chipUnit to act on (default = 3)\n");
    print ("\n  NOTE:  This program will not work if user has not stopped instructions\n");
    print ("         prior to running this program.\n");
}

