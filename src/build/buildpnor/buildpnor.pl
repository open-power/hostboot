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
#  IBM_PROLOG_END_TAG
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
my $tocVersion = 0x1;
my $genTocFlag = 0;
my $g_TOCEyeCatch = "part";

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
    trace(0, "Error detected from call to loadPnorLayout().  Exiting");
    exit 1;
}

#trace(1, Dumper(%pnorLayout->{1576960}));
#trace(1, Dumper(%binFiles));

#Verify all the section files exist
my $rc = verifyFilesExist($genTocFlag, \%pnorLayout, \%binFiles);
if($rc != 0)
{
    trace(0, "Error detected from call to verifyFilesExist().  Exiting");
    exit 1;
}

#Perform any data integrity manipulation (ECC, shaw-hash, etc)
$rc = robustifyImgs(\%pnorLayout, \%binFiles);
if($rc != 0)
{
    trace(0, "Error detected from call to robustifyImgs().  Exiting");
    exit 1;
}

#collect Actual image sizes
$rc = collectActSizes(\%pnorLayout, \%binFiles);
if($rc != 0)
{
    trace(0, "Error detected from call to collectActSizes().  Exiting");
    exit 1;
}

#Generate TOC if requested.
if ($genTocFlag != 0)
{
    $rc = fillTocActSize($tocVersion, \%pnorLayout);
    if($rc != 0)
    {
        trace(0, "Error detected from call to fillTocActSize().  Exiting");
        exit 1;
    }

    if(exists($binFiles{$g_TOCEyeCatch}))
    {
        $rc = genToc($tocVersion, $binFiles{$g_TOCEyeCatch}, \%pnorLayout);
        if($rc != 0)
        {
            trace(0, "Error detected from call to genToc().  Exiting");
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
    trace(0, "Error detected from call to checkSpaceConstraints().  Exiting");
    exit 1;
}

$rc = assemblePnorImage($pnorBinName, \%pnorLayout, \%binFiles);
if($rc != 0)
{
    trace(0, "Error detected from call to assemblePnorImage().  Exiting");
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

    #Save the meatadata - imageSize, blockSize, etc.
    foreach my $metadataEl (@{$xml->{metadata}})
    {
        my $imageSize = $metadataEl->{imageSize}[0];
        my $blockSize = $metadataEl->{blockSize}[0];
        my $partTableSize = $metadataEl->{partTableSize}[0];

        trace(3, "$this_func: metadata: imageSize = $imageSize, blockSize=$blockSize, partTableSize=$partTableSize");

        $imageSize = getNumber($imageSize);
        $blockSize = getNumber($blockSize);

        $$i_pnorLayoutRef{metadata}{imageSize} = $imageSize;
        $$i_pnorLayoutRef{metadata}{blockSize} = $blockSize;
        $$i_pnorLayoutRef{metadata}{partTableSize} = $partTableSize;
    }

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

        $$i_pnorLayoutRef{sections}{$physicalOffset}{description} = $description;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{eyeCatch} = $eyeCatch;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalOffset} = $physicalOffset;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalRegionSize} = $physicalRegionSize;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{actualRegionSize} = $actualRegionSize;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{ecc} = $ecc;
        $$i_pnorLayoutRef{sections}{$physicalOffset}{source} = $source;

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
    my $partIdCount = 1;
    my $FILEHANDLE;
    trace(4, "$this_func: >>Enter");

    #open output file
    open( $FILEHANDLE, ">:raw", $i_tocBinName) or die "Can't open $i_tocBinName file for writing";

    #Insert FFS Header data
    #HEADER WORD 1: Magic Number - "PART" in ASCII
    my @charArray = split //, 'PART';  
    my $curChar;                      
    foreach $curChar (@charArray)
    {
        print $FILEHANDLE pack('C', ord($curChar));
    }

    #HEADER WORD 2: FFS version to Binary
    print $FILEHANDLE pack('N', $i_tocVersion);

    #HEADER WORD 3: Size of Partition table in blocks - 4 bytes of space
    if(exists($$i_pnorLayoutRef{metadata}{partTableSize}))
    {
        my $val = $$i_pnorLayoutRef{metadata}{partTableSize};
        #verify number consumes less than 32 bits
        if($val > 0xFFFFFFFF)
        {
            trace(0, "$this_func: value=".$val.".  This is greater than 32 bits in hex and not currently supported!. \n Aborting program");
            exit 1;
        }
        print $FILEHANDLE pack('N', $val);
    }
    else
    {
        insertPadBytes($FILEHANDLE, 4);
    }

    #HEADER WORD 4: Size of Partition entry in bytes
    print $FILEHANDLE pack('N', getFFSEntrySize($i_tocVersion, $i_pnorLayoutRef));

    #HEADER WORD 5: Number of Partition Entries
    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    my $partitionCount = scalar keys %sectionHash;
    print $FILEHANDLE pack('N', $partitionCount);

    #HEADER WORD 6: block size
    my $blockSize = $$i_pnorLayoutRef{metadata}{blockSize};
    print $FILEHANDLE pack('N', $blockSize);

    #HEADER WORD 7: block count (size of flash in blocks)
    my $imageSize = $$i_pnorLayoutRef{metadata}{imageSize};
    my $blockCount = $imageSize/$blockSize;
    if ($blockCount != int($blockCount))
    {
        trace(0, "$this_func: Image size ($imageSize) is not an even multiple of erase blocks ($blockSize).  This is not supported.  Aborting!");
        exit 1;
    }
    print $FILEHANDLE pack('N', $blockCount);

    #HEADER WORD 8-11: Reserved
    #insert 16 pad bytes for 4 reserved words
    insertPadBytes($FILEHANDLE, 16);

    #HEADER WORD 12: checksum
    #insert 4 pad bytes for now.
    insertPadBytes($FILEHANDLE, 4);

    #key into hash data is the physical offset of section.  Need to sort the keys
    #so we put things in the correct order in toc.
    #Generally speaking, this loop is populating the FFS Header with records based on the
    #section data specified in the XML + actual sizes of the input binary files.
    for $key ( sort {$a<=> $b} keys %sectionHash)
    {

        # FFS Entry Word 1-4: eyecatcher
        if(exists($sectionHash{$key}{eyeCatch}))
        {
            my $char;
            my @charArray = unpack("C*", $sectionHash{$key}{eyeCatch});
            foreach $char (@charArray)
            {
                print $FILEHANDLE pack('C', $char);
            }
            #pad out to get 16 bytes
            my $zeroPad = 16-length($sectionHash{$key}{eyeCatch});
            insertPadBytes($FILEHANDLE, $zeroPad);
        }
        else
        {
            insertPadBytes($FILEHANDLE, 16);
        }

        #FFS Entry Word 5: base/physical offset in blocks
        if(exists($sectionHash{$key}{physicalOffset}))
        {
            my $val = $sectionHash{$key}{physicalOffset};
            $val = $val/$blockSize;
            if ($val != int($val))
            {
                trace(0, "$this_func: Partition offset ($val) is does not fall on an erase block ($blockSize) boundary.  This is not supported.  Aborting!");
                exit 1;
            }

            print $FILEHANDLE pack('N', $val);

        }
        else
        {
            insertPadBytes($FILEHANDLE, 4);
        }

        #FFS Entry Word 6: physical size in blocks
        if(exists($sectionHash{$key}{physicalRegionSize}))
        {
            my $val = $sectionHash{$key}{physicalRegionSize};
            $val = $val/$blockSize;
            if($val != int($val))
            {
                trace(0, "$this_func: Partition size ($val) is not an even multiple of erase blocks ($blockSize).  This is not supported.  Aborting!");
                exit 1;
            }

            print $FILEHANDLE pack('N', $val);

        }
        else
        {
            insertPadBytes($FILEHANDLE, 4);
        }

        #FFS Entry Word 7: PID (Parent ID) - always 0xFFFFFFFF for hostboot.
        print $FILEHANDLE pack('N', 0xFFFFFFFF);

        #FFS Entry Word 8: ID (Partition ID) - Incremented number for each partition.
        print $FILEHANDLE pack('N', $partIdCount++);

        #FFS Entry Word 9: type - usually 1, except TOC is 3
        if( $sectionHash{$key}{eyeCatch} =~ $g_TOCEyeCatch )
        {
            print $FILEHANDLE pack('N', 3);
        }
        else
        {
            print $FILEHANDLE pack('N', 1);
        }

        #FFS Entry Word 10: flags - always zero
        insertPadBytes($FILEHANDLE, 4);

        #FFS Entry Word 11-15: 5 Reserved words
        insertPadBytes($FILEHANDLE, 20);

        #FFS Entry Words 16-31: 16 User Words
        #FFS User Word 1 - Actual size actual size
        if(exists($sectionHash{$key}{actualRegionSize}))
        {
            my $val = $sectionHash{$key}{actualRegionSize};
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
            insertPadBytes($FILEHANDLE, 4);
        }
    
        #FFS User Word 2-3: Miscellaneous information.  Not currently implemented
        insertPadBytes($FILEHANDLE, 8);


        #FFS User Word 4-16: Free space User Data
        insertPadBytes($FILEHANDLE, 52);


        #FFS Entry Word 31: Checksum - not currently implemented
        insertPadBytes($FILEHANDLE, 4);
        

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
    my $ffsHeaderSize = 9*4;
    my $ffsEntrySize = getFFSEntrySize($i_tocVersion, $i_pnorLayoutRef);

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    my $recordCount = scalar keys %sectionHash;
    my $size = ($recordCount*$ffsEntrySize)+$ffsHeaderSize;

    my $tocLayoutKey = findLayoutKeyByEyeCatch($g_TOCEyeCatch, \%$i_pnorLayoutRef);
    if( $tocLayoutKey == -1)
    {
        trace(0, "$this_func: Unable to find EyeCatcher=$g_TOCEyeCatch in PNOR layout for TOC entry. ");
        $rc = 1;
        last;
    }

    if($$i_pnorLayoutRef{sections}{$tocLayoutKey}{ecc} =~ "yes")
    {
        $size=$size*(9/8);
    }
    
    trace(2, "$this_func: PNOR FFS contains $recordCount records, total Size=$size");
    $$i_pnorLayoutRef{sections}{$tocLayoutKey}{actualRegionSize}=$size;


    return $rc;
}

################################################################################
# robustifyImgs - Perform any ECC or ShawHash manipulations
################################################################################
sub robustifyImgs
{
    my ($i_pnorLayoutRef, $i_binFiles) = @_;
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
    my ($i_pnorLayoutRef, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %{$i_binFiles})
    {
        my $filesize = -s $$i_binFiles{$key};

        my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayoutRef);
        if( $layoutKey == -1)
        {
            trace(0, "$this_func: entry not found in PNOR layout for file $$i_binFiles{$key}, under eyecatcher $key");
            $rc = 1;
            last;
        }

        $$i_pnorLayoutRef{sections}{$layoutKey}{actualRegionSize} = $filesize;

        trace(2, "$this_func: $$i_binFiles{$key} size = $$i_pnorLayoutRef{sections}{$layoutKey}{actualRegionSize}");

    }

    return $rc;
}

################################################################################
# findLayoutKeyByEyeCatch - Figure out hash key based on eyeCatcher
################################################################################
sub findLayoutKeyByEyeCatch
{
    my $layoutKey = -1;
    my($eyeCatch, $i_pnorLayoutRef) = @_;
    my $key;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    for $key ( keys %sectionHash)
    {
        if($sectionHash{$key}{eyeCatch} =~ $eyeCatch)
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
    my ($i_genToc, $i_pnorLayoutRef, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $key;
    my $rc = 0;

    for $key ( keys %$i_binFiles)
    {
        #Don't check if toc file exists if we're going to generate it
        if(($key =~ $g_TOCEyeCatch) && ($i_genToc != 0))
        {
            next;
        }
        unless(-e $$i_binFiles{$key})
        {
            my $inputFile = $$i_binFiles{$key};
            trace(0, "Specified input file ($inputFile) for key ($key) does not exist.  Aborting!");
            $rc = 1;
            last;
        }
        else
        {
            trace(10, "$this_func: $$i_binFiles{$key} exists");
        }
    }

    if($rc != 0)
    {
        return $rc;
    }

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    #Verify there is an input file for each section of PNOR
    for $key ( keys %sectionHash)
    {
        my $eyeCatch = $sectionHash{$key}{eyeCatch};

        #Don't check if toc file exists if we're going to generate it
        if(($eyeCatch =~ $g_TOCEyeCatch) && ($i_genToc != 0))
        {
            next;
        }
        #Ignore sections that are marked as blank
        elsif($sectionHash{$key}{source} =~ "Blank")
        {
            next;
        }
        #check if binFiles list has a file for eyeCatcher
        unless(exists($$i_binFiles{$eyeCatch}))
        {
            my $inputFile = $$i_binFiles{$eyeCatch};
            trace(0, "Input file not provided for PNOR section with eyeCatcher=$eyeCatch.  Aborting!");
            $rc = 1;
            last;
        }
        else
        {
            trace(10, "$this_func: Input file ($$i_binFiles{$eyeCatch}) provided for section $eyeCatch");
        }
    }

    return $rc;
}

################################################################################
# checkSpaceConstraints - Make sure provided files will fit in their sections
################################################################################
sub checkSpaceConstraints
{
    my ($i_pnorLayoutRef, $i_binFiles) = @_;
    my $rc = 0;
    my $this_func = (caller(0))[3];
    my $key;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    #Verify there is an input file for each section of PNOR
    for $key ( keys %sectionHash)
    {
        my $eyeCatch = $sectionHash{$key}{eyeCatch};
        my $physicalRegionSize = $sectionHash{$key}{physicalRegionSize};
        my $actualRegionSize = $sectionHash{$key}{actualRegionSize};

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
    my ($i_pnorBinName, $i_pnorLayoutRef, $i_binFiles) = @_;
    my $this_func = (caller(0))[3];
    my $rc = 0;
    my $key;

    #key is the physical offset into the file, however don't need to sort
    #as long as I tell dd not to truncate the file.
    my %sectionHash = %{$$i_pnorLayoutRef{sections}};
    for $key ( keys %sectionHash)
    {
        trace(3, "$this_func: key=$key");
        my $eyeCatch = $sectionHash{$key}{eyeCatch};
        my $physicalOffset = $sectionHash{$key}{physicalOffset};
        my $if = $$i_binFiles{$eyeCatch};

        #Ignore sections that are marked as blank
        if($sectionHash{$key}{source} =~ "Blank")
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
# getFFSEntrySize: Returns number of bytes in an ffs_entry based on specified version
#################################################
sub getFFSEntrySize
{
    my($i_tocVersion, $i_pnorLayoutRef) = @_;
    my $this_func = (caller(0))[3];
    my $ffsEntrySize = 0;

    if($i_tocVersion == 0x1)
    {
        #16 char name + 12 fixed words + 16 user data words
        $ffsEntrySize = 16+(12*4)+(16*4); 
    }
    else
    {
        trace(0, "$this_func:  Layout Version Unsupported!  i_tocVersion=$i_tocVersion");
        exit 1;
    }
    return $ffsEntrySize;
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
