#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/buildpnor/buildpnor.pl $
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

#Builds a PNOR image based on pnorLayout XML file.
#See usage function at bottom of file for details on how to use this script

#Limitations to address later
# number fields must be 4 or 8 bytes
# numbers cannot be over 32 bits


use strict;
use XML::Simple;
use Data::Dumper;
use File::Basename;

################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_trace = 1; 

my $programName = File::Basename::basename $0;
my %tocLayout;
my %pnorLayout;
my %binFiles;


my $pnorLayoutFile;
my $pnorBinName = "";
my $tocVersion = 0x12345;
my $genTocFlag = 0;


if ($#ARGV < 0) {
    usage();
    exit;
}

#Parse the commandline args
for (my $i=0; $i < $#ARGV + 1; $i++)
{
    if ($ARGV[$i] =~ /-h/) {
        usage();
        exit 0;
    }
    elsif($ARGV[$i] =~ /--tocVersion/) {
        $tocVersion = getNumber($ARGV[++$i]);
        trace(2, "TOC Version to use=".sprintf("0x%x", $tocVersion));
    }
    elsif($ARGV[$i] =~ /--pnorLayout/) {
        $pnorLayoutFile = $ARGV[++$i];
        trace(2, "PNOR Layout XML File=$pnorLayoutFile");
    }
    elsif($ARGV[$i] =~ /--pnorOutBin/) {
        $pnorBinName = $ARGV[++$i];
        trace(2, "PNOR Binary File=$pnorBinName");
    }
    elsif($ARGV[$i] =~ /--genToc/) {
        $genTocFlag = 1;
        trace(2, "genTocFlag Set");
    }
    elsif($ARGV[$i] =~ /--binFile/) {
        my $argName = $ARGV[$i];
        my $argVal = $ARGV[++$i];
        saveInputFile("--binFile", $argName, $argVal, \%binFiles);
    }
    else {
        traceErr("Unrecognized Input: $ARGV[$i]");
        exit 1;
	#Error!!
    }
}


#Load PNOR Layout XML file
my $rc = loadPnorLayout($pnorLayoutFile, \%pnorLayout);
if($rc != 0)
{
    exit 1;
}

#trace(1, Dumper(%pnorLayout->{1576960}));
#trace(1, Dumper(%binFiles));

#Verify all the section files exist
my $rc = verifyFilesExist($genTocFlag, \%pnorLayout, \%binFiles);
if($rc != 0)
{
    exit 1;
}

#Perform any data integrity manipulation (ECC, shaw-hash, etc)
$rc = robustifyImgs(\%pnorLayout, \%binFiles);
if($rc != 0)
{
    exit 1;
}

#collect Actual image sizes
$rc = collectActSizes(\%pnorLayout, \%binFiles);
if($rc != 0)
{
    exit 1;
}

#Generate TOC if requested.
if ($genTocFlag != 0)
{
    $rc = fillTocActSize($tocVersion, \%pnorLayout);
    if($rc != 0)
    {
        exit 1;
    }

    if(exists($binFiles{TOC}))
    {
        $rc = genToc($tocVersion, $binFiles{TOC}, \%pnorLayout);
        if($rc != 0)
        {
            exit 1;
        }
    }
    else
    {
        trace(0, "No TOC Binary file name provided.  Aborting!");
        exit 1;
    }
}


$rc = checkSpaceConstraints(\%pnorLayout, \%binFiles);
if($rc != 0)
{
    exit 1;
}

$rc = assemblePnorImage($pnorBinName, \%pnorLayout, \%binFiles);
if($rc != 0)
{
    exit 1;
}

exit 0;

################################################################################
# loadPnorLayout
################################################################################
sub loadPnorLayout
{
    my ($i_pnorFile, $i_pnorLayoutRef) = @_;
    my $this_func = (caller(0))[3];

    unless(-e $i_pnorFile)
    {
        traceErr("$this_func: File not found: $i_pnorFile");
        return -1;
    }    

    #parse the input XML file
    my $xs = new XML::Simple(keyattr=>[], forcearray => 1);
    my $xml = $xs->XMLin($i_pnorFile);

    #trace(1, "pnorLayoutXML \n ".Dumper($xml));

    #Iterate over the <section> elements.
    foreach my $sectionEl (@{$xml->{section}})
    {
        #trace(1, "current Element: \n ".Dumper($sectionEl));
        my $description = $sectionEl->{description}[0];
        my $eyeCatch = $sectionEl->{eyeCatch}[0];
        my $physicalOffset = $sectionEl->{physicalOffset}[0];
        my $physicalRegionSize = $sectionEl->{physicalRegionSize}[0];
        my $ecc = $sectionEl->{ecc}[0];
        my $source = $sectionEl->{source}[0];

        my $actualRegionSize = 0;
        if(exists($sectionEl->{actualRegionSize}[0]))
        {
            $actualRegionSize = $sectionEl->{actualRegionSize}[0];
            $actualRegionSize = getNumber($actualRegionSize);
        }

        trace(3, "$this_func: description = $description, eyeCatch=$eyeCatch, physicalOffset = $physicalOffset, physicalRegionSize=$physicalRegionSize, ecc=$ecc, source=$source, actualRegionSize=$actualRegionSize");

        $physicalOffset = getNumber($physicalOffset);
        $physicalRegionSize = getNumber($physicalRegionSize);

        # trace(4, "$this_func: physicalOffset=$physicalOffset, physicalRegionSize=$physicalRegionSize");

        %{$i_pnorLayoutRef}->{$physicalOffset}{description}=$description;
        %{$i_pnorLayoutRef}->{$physicalOffset}{eyeCatch}=$eyeCatch;
        %{$i_pnorLayoutRef}->{$physicalOffset}{physicalOffset}=$physicalOffset;
        %{$i_pnorLayoutRef}->{$physicalOffset}{physicalRegionSize}=$physicalRegionSize;
        %{$i_pnorLayoutRef}->{$physicalOffset}{actualRegionSize}=$actualRegionSize;
        %{$i_pnorLayoutRef}->{$physicalOffset}{ecc}=$ecc;
        %{$i_pnorLayoutRef}->{$physicalOffset}{source}=$source;

    }

    return 0;
}

################################################################################
# genToc - generate Table of Contents image based on input data.
################################################################################
sub genToc
{
    my ($i_tocVersion, $i_tocBinName, $i_pnorLayoutRef) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $FILEHANDLE;
    trace(4, "$this_func: >>Enter");

    #open output file
    open( $FILEHANDLE, ">:raw", $i_tocBinName) or die "Can't open $i_tocBinName file for writing";

    #Write version to toc Binary
    print $FILEHANDLE pack('N', 0);
    print $FILEHANDLE pack('N', $i_tocVersion);

    #key is the physical offset of section.  Need to sort the keys
    #so we put things in the correct order in toc.
    #This is important so pnorrp can easily find the length of the TOC section.
    #Generally speaking, this loop is populating the TOC with records based on the
    #section data specified in the XML + actual sizes of the input binary files.
    for $key ( sort {$a<=> $b} keys %{$i_pnorLayoutRef})
    {
        #trace(1, Dumper(%{$i_pnorLayoutRef}->{$key}));
        # print eyecatcher
        if(exists(%{$i_pnorLayoutRef}->{$key}{eyeCatch}))
        {
            my $char;
            my @charArray = unpack("C*", %{$i_pnorLayoutRef}->{$key}{eyeCatch});
            foreach $char (@charArray)
            {
                print $FILEHANDLE pack('C', $char);
            }
            #pad out to get 8 bytes
            my $zeroPad = 8-length(%{$i_pnorLayoutRef}->{$key}{eyeCatch});
            insertPadBytes($FILEHANDLE, $zeroPad);
        }
        else
        {
            insertPadBytes($FILEHANDLE, 8);
        }

        #print physical offset
        if(exists(%{$i_pnorLayoutRef}->{$key}{physicalOffset}))
        {
            my $val = %{$i_pnorLayoutRef}->{$key}{physicalOffset};
            #pad first 32 bits
	    print $FILEHANDLE pack('N', 0);
            #verify number consumes less than 32 bits
            if($val > 0xFFFFFFFF)
            {
                trace(0, "value=".$val.".  This is greater than 32 bits in hex and not currently supported!. \n Aborting program");
                exit 1;
            }

            print $FILEHANDLE pack('N', $val);

        }
        else
        {
            insertPadBytes($FILEHANDLE, 8);
        }

        #print physical size
        if(exists(%{$i_pnorLayoutRef}->{$key}{physicalRegionSize}))
        {
            my $val = %{$i_pnorLayoutRef}->{$key}{physicalRegionSize};
            #pad first 32 bits
	    print $FILEHANDLE pack('N', 0);
            #verify number consumes less than 32 bits
            if($val > 0xFFFFFFFF)
            {
                trace(0, "value=".$val.".  This is greater than 32 bits in hex and not currently supported!. \n Aborting program");
                exit 1;
            }

            print $FILEHANDLE pack('N', $val);

        }
        else
        {
            insertPadBytes($FILEHANDLE, 8);
        }

        #print actual size
        if(exists(%{$i_pnorLayoutRef}->{$key}{actualRegionSize}))
        {
            my $val = %{$i_pnorLayoutRef}->{$key}{actualRegionSize};
            #pad first 32 bits
            print $FILEHANDLE pack('N', 0);
            #verify number consumes less than 32 bits
            if($val > 0xFFFFFFFF)
            {
                trace(0, "value=".$val.".  This is greater than 32 bits in hex and not currently supported!. \n Aborting program");
                exit 1;
            }

            print $FILEHANDLE pack('N', $val);
        }
        else
        {
            insertPadBytes($FILEHANDLE, 8);
        }

        #pad Miscellaneous information (8 bytes)
        insertPadBytes($FILEHANDLE, 8);

        #Pad Free space in TOC entry
        insertPadBytes($FILEHANDLE, 88);
    }
    return 0;
}

################################################################################
# fillTocActSize - Fill in the toc actual size record based on number of PNOR records
################################################################################
sub fillTocActSize
{
    #Note: tocVersion is passed in because the toc Layout version could influence the
    #rules regarding how the size is calculated.
    my($i_tocVersion, $i_pnorLayoutRef) = @_;
    my $this_func = (caller(0))[3];
    my $rc = 0;
    my $tocRecordSize = 128;

    my $recordCount = scalar keys %{$i_pnorLayoutRef};
    my $size = ($recordCount*$tocRecordSize);

    if(%{$i_pnorLayoutRef}->{0}{ecc} =~ "yes")
    {
        $size=$size*(9/8);
    }
    
    trace(2, "$this_func: PNOR TOC Size=$size");

    #Assume TOC is always at address zero for now since it's currently true by design
    %{$i_pnorLayoutRef}->{0}{actualRegionSize}=$size;


    return $rc;
}

################################################################################
# robustifyImgs - Perform any ECC or ShawHash manipulations
################################################################################
sub robustifyImgs
{
    my ($i_pnorLayout, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];

    #@TODO: ECC Correction
    #@TODO: maybe a little SHA hashing?

    return 0;
}

################################################################################
# collectActSizes - walk through all the images and set their actual sizes in the layout
################################################################################
sub collectActSizes
{
    my ($i_pnorLayout, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %{$i_binFiles})
    {
        my $filesize = -s $$i_binFiles{$key};
        trace(10, "$this_func: $$i_binFiles{$key} size = $filesize");

        my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayout);
        if( $layoutKey == -1)
        {
            $rc = 1;
            last;
        }

        $$i_pnorLayout{$layoutKey}{actualRegionSize} = $filesize;

       trace(2, "$this_func: $$i_binFiles{$key} size = $$i_pnorLayout{$layoutKey}{actualRegionSize}");

    }

    return $rc;
}

################################################################################
# findLayoutKeyByEyeCatch - Figure out hash key based on eyeCatcher
################################################################################
sub findLayoutKeyByEyeCatch
{
    my $layoutKey = -1;
    my($eyeCatch, $i_pnorLayout) = @_;
    my $key;

    for $key (keys  %{$i_pnorLayout})
    {
        if($$i_pnorLayout{$key}{eyeCatch} =~ $eyeCatch)
        {
            $layoutKey = $key;
            last;
        }

    }
    
    return $layoutKey;
}

################################################################################
# verifyFilesExist - Verify all the input files exist, and there are files
#        provided for each PNOR section
################################################################################
sub verifyFilesExist
{
    my ($i_genToc, $i_pnorLayout, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %$i_binFiles)
    {

        #Don't check if toc file exists if we're going to generate it
        if(($key =~ "TOC") && ($i_genToc != 0))
        {
            next;
        }
        unless(-e $$i_binFiles{$key})
        {
            my $inputFile = $$i_binFiles{$key};
            trace(0, "Specified input file ($inputFile) for key ($key) does not exist.  Aborting!");
            $rc = 1;
        }
        else
        {
            trace(10, "$this_func: $$i_binFiles{$key} exists");
        }
    }

    #Verify there is an input file for each section of PNOR
    for $key ( keys %$i_pnorLayout)
    {
        my $eyeCatch = $$i_pnorLayout{$key}{eyeCatch};

        #Don't check if toc file exists if we're going to generate it
        if(($eyeCatch =~ "TOC") && ($i_genToc != 0))
        {
            next;
        }
        #Ignore sections that are marked as blank
        elsif($$i_pnorLayout{$key}{source} =~ "Blank")
        {
            next;
        }
        #check if binFiles list has a file for eyeCatcher
        unless(exists($$i_binFiles{$eyeCatch}))
        {
            my $inputFile = $$i_binFiles{$eyeCatch};
            trace(0, "Input file not provided for PNOR section with eyeCatcher=$eyeCatch.  Aborting!");
            $rc = 1;
        }
        else
        {
            trace(10, "$this_func: $$i_binFiles{$key} exists");
        }
    }

    return $rc;
}

################################################################################
# checkSpaceConstraints - Make sure provided files will fit in their sections
################################################################################
sub checkSpaceConstraints
{
    my ($i_pnorLayout, $i_binFiles) = @_;
    my $rc = 0;
    my $this_func = (caller(0))[3];
    my $key;

    #Verify there is an input file for each section of PNOR
    for $key ( keys %$i_pnorLayout)
    {
        my $eyeCatch = $$i_pnorLayout{$key}{eyeCatch};
        my $physicalRegionSize = $$i_pnorLayout{$key}{physicalRegionSize};
        my $actualRegionSize = $$i_pnorLayout{$key}{actualRegionSize};

        if($actualRegionSize > $physicalRegionSize)
        {
            trace(0, "$this_func: Image provided ($$i_binFiles{$eyeCatch}) has size ($actualRegionSize) which is greater than allocated space ($physicalRegionSize) for section=$eyeCatch.  Aborting!");
            $rc = 1;
        }

    }


    return $rc;
}

################################################################################
# assemblePnorImage - Assemble actual PNOR image using the provided input data
################################################################################
sub assemblePnorImage
{
    my ($i_pnorBinName, $i_pnorLayout, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $rc = 0;
    my $key;

    #key is the physical offset into the file, however don't need to sort
    #as long as I tell dd not to truncate the file.
    for $key ( keys %{$i_pnorLayout})
    {
        my $eyeCatch = $$i_pnorLayout{$key}{eyeCatch};
        my $physicalOffset = $$i_pnorLayout{$key}{physicalOffset};
        my $if = $$i_binFiles{$eyeCatch};

        #Ignore sections that are marked as blank
        if($$i_pnorLayout{$key}{source} =~ "Blank")
        {
            next;
        }

        #telling dd to read write 512 characters (1b) at a time, so need to seek
        #<bytes>/512 blocks.  This will work because PNOR offests will always be
        # on a page boundary
        my $blockSeek = $physicalOffset/512;

        trace(1, "$this_func: populating section $eyeCatch, filename=$if");
#        my $ddCmd = `dd if=$if ibs=8c of=$i_pnorBinName obs=8c seek=$physicalOffset`;
        my $ddCmd = `dd if=$if ibs=1b of=$i_pnorBinName obs=1b seek=$blockSeek conv=notrunc`;
        
        

    }

    return $rc;
}

################################################################################
# saveInputFile - save inputfile name into binFiles array
################################################################################
sub saveInputFile
{
    my ($i_argPrefix, $i_argName, $i_argVal, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];

    #$i_argName will be something like --binFile_HBB
    #This substr command should return just the HBB, which should match an eyeCather
    my $eyeCatcher = substr($i_argName, length($i_argPrefix)+1, length($i_argName)-length($i_argPrefix));

    trace(10, "$this_func: $eyeCatcher=$i_argVal");

    $$i_binFiles{$eyeCatcher} = $i_argVal;

    trace(10, "$this_func:           $$i_binFiles{$eyeCatcher}");

    #no return code expected
}
    


#################################################
# Insert specifed number of pad bytes into file
#  
#################################################
sub insertPadBytes
{
    my ($i_FILEHANDLE, $i_padBytes) = @_;
    my $i;
    print $i_FILEHANDLE pack("C[$i_padBytes]", map { 0 } 1..$i_padBytes);

}

################################################################################
# getNumber - handle hex or decimal input string
################################################################################
sub getNumber
{
    my $inVal = shift;
    if($inVal =~ "0x")
    {
	return oct($inVal);
    }
    else
    {
	return $inVal;
    }
}

################################################################################
# trace
################################################################################
sub traceErr
{
    my $i_string = shift;
    trace($TRAC_ERR, $i_string);
}

################################################################################
# trace
################################################################################
sub trace
{
    my $i_traceLevel;
    my $i_string;

    ($i_traceLevel, $i_string) = @_;

    #traceLevel 0 is for errors
    if($i_traceLevel == 0)
    {
	print "ERROR: ".$i_string."\n";
    }
    elsif ($g_trace >= $i_traceLevel)
    {
	print "TRACE: ".$i_string."\n";
    }
}



################################################################################
# print usage instructions
################################################################################
sub usage
{
print <<"ENDUSAGE";
  $programName = Creates the PNOR IMAGE and with TOC based on input data.

  Usage:
    $programName --pnorlayout <layout xml file> --genToc --tocVersion <TOC layout version
                 --pnorOutBin  <complete PNOR image>
                 --binFile_HBB <hostboot base image> --binFile_HBI <hostboot extended image>

  Parms:
    -h                  Print this help text
    --pnorlayout <file> PNOR Layout XML file
    --pnorOutBin <file> Name of output file for PNOR Binary
    --genToc            Indicates you wish to generate a table of contents.  It will 
                        write the file indicated by --binFile_TOC.

    --binFile_<Section> <file>  This is a special paramater.  It is used to specify
                        input files to use for populating the various sections of
                        PNOR.
                            Examples:  --binFile_HBB hostboot.bin
                                       --binFile_HBI hostboot_extended.bin
                                       --binFile_TOC murano.toc
                         A section declared as Blank in the XML does not need to have a
                         binFile specified

  Current Limitations:
      --TOC Records must be 4 or 8 bytes in length
      --Regions and offsets cannot be over 32 bits (in hex), not an issue with current PNOR size
     The script will print and error and exit with a non-zero return code if these
     conditions are encountered.

ENDUSAGE
}
