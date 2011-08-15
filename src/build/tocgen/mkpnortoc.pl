#!/usr/bin/perl
# File mkPnorTOC.pl created by ADAM R. MUHLE at 14:39:27 on Mon Aug  1 2011.

#Limitations to address later
# number fields must be 4 or 8 bytes
# numbers cannot be over 32 bits

#@TODO - enable "use strict"
#@TODO - standardize variable names, i_blah for input, etc.

use XML::LibXML;
#use Data::Dumper;
use File::Basename;

my $programName = File::Basename::basename $0;
my $g_trace = 0; # >0 enable traces
$tocDataFile = "";
$tocOutFile = "";

if ($#ARGV < 0) {
    usage();
    exit;
}


#Parse the commandline args
for ($i=0; $i < $#ARGV + 1; $i++)
{
    if ($ARGV[$i] =~ /-h/) {
    usage();
    exit 0;
    }
    elsif($ARGV[$i] =~ /-v/) {
	$verbose = 1;
    }
    elsif($ARGV[$i] =~ /-i/) {
	$tocDataFile = $ARGV[++$i];
	trace(1, "Input Data File=$tocDataFile");
    }
    elsif($ARGV[$i] =~ /-o/) {
	$tocOutFile = $ARGV[++$i];
	trace(1, "Output Binary File=$tocOutFile");
    }
    else {
	#Error!!
    }
}


#open output file
open( BIN_TOC_FILE, ">:raw", $tocOutFile) or die "Can't open $tocOutFile file for writing";

#parse the input XML file
$parser = XML::LibXML->new();
$doc = $parser->parse_file($tocDataFile);

#add the SBE field to the TOC
$sbeNodes = $doc->getElementsByTagName("sbeLoc");
$onlySbeNode = $sbeNodes->pop();
writeElementToBinFile(BIN_TOC_FILE, $onlySbeNode);

#Add TOC version field to TOC
$tocVerNodes = $doc->getElementsByTagName("tocVersion");
$onlytocVerNode = $tocVerNodes->pop();
writeElementToBinFile(BIN_TOC_FILE, $onlytocVerNode);


#Add the individual TOC entries
$root = $doc->firstChild;
$curSibling = $root->firstChild;

do {
    #just in case the first childe is bad
    if(!$curSibling)
    {
	last;
    }
    elsif($curSibling->nodeName eq "tocEntry")
    {
	parseTocEntry(BIN_TOC_FILE, $curSibling);
    }
    elsif(($curSibling->nodeName eq "sbeLoc") ||
	  ($curSibling->nodeName eq "tocVersion"))
    {
	#skip these, already inserted above
    }

}while($curSibling = $curSibling->nextSibling);


close(BIN_TOC_FILE);
exit;

#################################################
# Get Length of a field
#  Searches XML element for sub-element called
#    length
#################################################
sub getLength
{
    $element = @_[0];

    $lenElements = $element->getElementsByLocalName("length");
    $lenEl = $lenElements->pop();

    $len = $lenEl->firstChild->data;
    chomp $len;
    return $len;

}

#################################################
# Get format of a field
#  Searches XML element for sub-element called
#    format
#################################################
sub getFormat
{
    $element = @_[0];

    $formatElements = $element->getElementsByLocalName("format");
    $formatEl = $formatElements->pop();

    $format = $formatEl->firstChild->data;
    chomp $format;
    return $format;

}


#################################################
# Get data value from provided XML element
#  
#################################################
sub getValue
{
    $i_element = @_[0];

    $value = $i_element->firstChild->data;

    $value =~s/\s+$//;
    chomp $value;

    return $value;
}
    
#################################################
# parse <tocEntry> node, write bin data to file
#  
#################################################
sub parseTocEntry
{
    ($i_FILEHANDLE, $i_element) = @_;
    $entryLength = 0;
    $sumFieldLen = 0;
    local $curSibling;
    

    $curSibling = $i_element->firstChild;
    do {
	#just in case the first childe is bad
	if(!$curSibling)
	{
	    last;
	}
	elsif(($curSibling->nodeName eq "text") ||
	      ($curSibling->nodeName eq "#text"))
	{
	    trace(1, "ignoring ".$curSibling->nodeName);
	}
	elsif($curSibling->nodeName eq "length")
	{
	    $entryLength = $curSibling->firstChild->data;

	}
	else
	{
	    trace(1, "Parsing ".$curSibling->nodeName);
	    $fieldLen = writeElementToBinFile($i_FILEHANDLE, $curSibling);
	    $sumFieldLen = $sumFieldLen + $fieldLen;

	}
#       ($nextSibling = $curSibling->nextSibling)

    }while($curSibling = $curSibling->nextSibling);

    if($sumFieldLen > $entryLength)
    {
	trace(0, "Fields in TOC Entry consumed more space (".$sumFieldLen.") then they were supposed to (".$entryLength.")\n Aborting");
	exit 1;
    }
    elsif($sumFieldLen < $entryLength)
    {
	trace(1, "Need to insert padding to fill up TOC entry space");
	$padBytes = $entryLength - $sumFieldLen;
	insertPadBytes($i_FILEHANDLE, $padBytes);
    }
    

}
#################################################
# write provided element to binary file
#  
#################################################
sub writeElementToBinFile
{
    ($i_FILEHANDLE, $i_element) = @_;

    $elValue = getValue($i_element);
    $len = getLength($i_element);
    $format = getFormat($i_element);

    trace(1, "Value=".$elValue." Length=".$len." Format=".$format);


    if($format =~ "string")
    {
	#print in ascii
	#pad on right side
	@charArray = unpack("C*", $elValue);
	foreach $char (@charArray)
	{
	    print $i_FILEHANDLE pack('C', $char);
	}

	$zeroPad = $len-length($elValue);
	insertPadBytes($i_FILEHANDLE, $zeroPad);
    }
    elsif ($format =~ "number")
    {
	if(($len != 4) &&
	   ($len != 8))
	{
	    trace(0, "field <length>=".$len.".  Currently only lengths of 4 or 8 are supported. \n Aborting program");
	    exit 1;
	}

	if($len == 8)
	{
	    print $i_FILEHANDLE pack('N', 0);
	}

	#check if we have a hex number
	if($elValue =~ "0x")
	{
	    $num = oct($elValue);
	}
	else
	{
	    $num = $elValue;
	}

	#verify number consumes less than 32 bits
	if($num > 0xFFFFFFFF)
	{
	    trace(0, "number=".$num.".  This is greater than 32 bits in hex and not currently supported!. \n Aborting program");
	    exit 1;
	}

	print $i_FILEHANDLE pack('N', $num);

    }
    else
    {
	print "ERROR: Unrecognized <format> type: ".$format."  Exiting!\n";
	exit 1;
    }

    return $len

}

#################################################
# Insert specifed number of pad bytes into file
#  
#################################################
sub insertPadBytes
{
    ($i_FILEHANDLE, $i_padBytes) = @_;
    for($i=0; $i<$i_padBytes; $i++)
    {
	print $i_FILEHANDLE pack('C', 0);
    }
}




################################################################################
# trace
################################################################################
sub trace
{
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
  $programName = Creates the PNOR Table of Contents (TOC) based on input XML file.

  Usage:
      $programName -i <XML File> -o <binary Output File>

  Current Limitations:
      --Hex/number fields must be 4 or 8 bytes in length
      --Numbers cannot be over 32 bits (in hex)
     The script will print and error and exit with a non-zero return code if these
     conditions are encountered.

ENDUSAGE
}
