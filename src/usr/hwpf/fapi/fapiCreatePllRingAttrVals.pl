#!/usr/bin/perl -w
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/fapi/fapiCreatePllRingAttrVals.pl $
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
# $Id: fapiCreatePllRingAttrVals.pl,v 1.4 2014/01/13 15:49:47 dedahle Exp $
#
# Purpose:  This perl script will parse HWP Attribute XML files
# and add attribute information to a file called fapiAttributeIds.H
#
# Author: Kahn Evans
# Last Updated: 09/16/2013
#
# Version: 1.0
#
# Change Log **********************************************************
#
#  Flag  Track#    Userid    Date      Description
#  ----  --------  --------  --------  -----------
#                  dpeterso  09/16/13  Modified Kahn Evans/John Farrugia script to gen .H
#
#
# End Change Log ******************************************************

use strict;
use Cwd 'chdir';
use Env;

sub help;

my $ProgName            = "fapicreatePllRingAttrVals.pl";
my @args                = @ARGV;
my $Arg                 = "";
#my $ekbPathHead = "/cronus/ekb";
my $ekbPathHead = ".";
my $kbPath = "$ekbPathHead/eclipz/chips/";
#my $kbPath = "/cronus/ekb/eclipz/chips/";
my $pllFile;
my $callingPwd;
my $DEBUG = 0;
my $VERBOSE = 0;
my $chip = "";
my $capChip = "";
my $ec = "";
my  $fileName = "fapiPllRingAttr.H";

my %cronusNameToFapi = (
                        ATTR_MSS_FREQ                => "MEMB_MEM_FREQ",
                        ATTR_FREQ_X_mem                => "MEMB_NEST_FREQ",
                        ATTR_FREQ_A                => "PU_ABUS_FREQ",
                        ATTR_FREQ_PB                => "PU_DMI_FREQ",
                        ATTR_NEST_FREQ_MHZ        => "PU_NEST_FREQ",
                        ATTR_FREQ_PCIE                => "PU_PCIE_FREQ",
                        ATTR_NO_FAPI_ATTR_ALWAYS_100 => "PU_PCIE_REF_CLOCK",
                        ATTR_FREQ_PROC_REFCLOCK        => "PU_REF_CLOCK",
                        ATTR_FREQ_X                => "PU_XBUS_FREQ",
                        );

# Frequencies to query for each attribute type
# NOTE: For each attribute the frequencies must be listed in alphabetical order
my %attrToFreqs = (
                   ATTR_PROC_AB_BNDY_PLL                => [ "ATTR_FREQ_A" ],
                   ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL      => [ "ATTR_FREQ_A" ],
                   ATTR_PROC_AB_BNDY_PLL_FOR_RUNTIME    => [ "ATTR_FREQ_A" ],
                   ATTR_PROC_PB_BNDY_DMIPLL             => [ "ATTR_FREQ_PB" ],
                   ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL   => [ "ATTR_FREQ_PB" ],
                   ATTR_PROC_PB_BNDY_DMIPLL_FOR_RUNTIME => [ "ATTR_FREQ_PB" ],
                   ATTR_PROC_PCI_BNDY_PLL               => [ "ATTR_FREQ_PCIE" ],
                   ATTR_PROC_PERV_BNDY_PLL              => [ "ATTR_NEST_FREQ_MHZ", "ATTR_NO_FAPI_ATTR_ALWAYS_100", "ATTR_FREQ_PROC_REFCLOCK", "ATTR_FREQ_X" ],
                   ATTR_MEMB_TP_BNDY_PLL                    => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL          => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_FOR_RUNTIME        => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866   => [ "ATTR_MSS_FREQ", "ATTR_FREQ_X_mem" ],
                   );

# Get the path the script was called from so we can get back to it later
$callingPwd = $ARGV[0];
$callingPwd .= "/";

my  $fileString = "";
#Pull out the args passed in
&parseArgs;

#Full path of the file
$pllFile = "$kbPath" . "$chip\/" . "working\/ec_" . "$ec\/" . "$chip" . "_" . "$ec" . "_pll_ring.attributes";

#output file path and name
if ($chip ne ""){
    $capChip = ucfirst($chip);
    $fileName = $capChip . "Ec" . "$ec" . "Pll.H";
}

my  $outputFile = "$callingPwd" . "$fileName";
my  $line = "";

# Start to generate header file.

open (OUTFILE, ">$outputFile") or die "Couldn't open $outputFile for output. \n";

#Initial data types and definitions here

print OUTFILE "// fapiPllRingAttr.H\n";
print OUTFILE "// This file is generated by perl script fapiCreatePllRingAttrVals.pl\n";
print OUTFILE "\n";
print OUTFILE "#ifndef FAPIPLLRINGATTR_H_\n";
print OUTFILE "#define FAPIPLLRINGATTR_H_\n";
print OUTFILE "//----------------------------------------------------------------------\n";
print OUTFILE "//  Includes\n";
print OUTFILE "//----------------------------------------------------------------------\n";
print OUTFILE "#include <stdlib.h>\n";
print OUTFILE "\n";
print OUTFILE "#include <fapiAttributeIds.H>\n";
print OUTFILE "\n";
print OUTFILE "using namespace fapi;\n";
print OUTFILE "\n";
print OUTFILE "#define MAX_PLL_RING_SIZE_BYTES 256\n";
print OUTFILE "\n";


# Create array structures for PLL attributes based on the number of keys
my %freqCountHash = ();
foreach my $val (sort (values %attrToFreqs)) {
    my $numKeys = scalar @$val;
    if (!$freqCountHash{$numKeys}) {
        $freqCountHash{$numKeys} = 1;
        print OUTFILE "struct PLL_RING_ATTR_WITH_" . $numKeys . "_KEYS {\n";
        for (my $i=1; $i <= $numKeys; $i++) {
            print OUTFILE "    uint32_t l_freq_" . $i . ";\n";
        }
        print OUTFILE "    uint16_t l_ATTR_PLL_RING_BIT_LENGTH;\n";
        print OUTFILE "    uint8_t l_ATTR_PLL_RING_BYTE_LENGTH;\n";
        print OUTFILE "    uint8_t l_ATTR_PLL_RING_DATA [MAX_PLL_RING_SIZE_BYTES];\n";
        print OUTFILE "    uint8_t l_ATTR_PLL_RING_FLUSH [MAX_PLL_RING_SIZE_BYTES];\n";
        print OUTFILE "};\n";
        print OUTFILE "\n";
    }
}

print OUTFILE "\n";

$fileString = "ls -1 $fileString |";

open(ALLFILES, "$fileString") or die die "$ProgName ERROR : Couldn't open list of files $fileString\n";

# Loop over all attribute files found
while (defined($line = <ALLFILES>))
{
    $pllFile = $line;
    if ($pllFile =~ m"\S+/(\S+?)_(\d+?)_pll_ring.attributes")
    {
        $chip = $1;
        $capChip = ucfirst($chip);
        $ec = $2;
    } else {
        die "$ProgName ERROR : Couldn't parse chip type and ec from file $pllFile \n\n";
    }

    my $count = 0;
    my @envType ;
    my @freqVals;
    my @freqType;
    my @uniqFreqType;
    my $uniqFreqTypeCount = 0;
    my @pllDataName;
    my @pllFlushName;
    my @pllDataArrayNames;
    my @pllDataArrayVals;
    my @pllFlushArrayNames;
    my @pllFlushArrayVals;
    my @pllRingLength;
    my @pllDataSize;
    my @pllFlushSize;
    my @freqValSize;
    my @uniqAttrs;
    my @uniqAttrSize;
    my @uniqFlushAttrs;
    my @uniqFlushAttrSize;
    my $uniqAttrCount = 0;
    my $uniqFlushAttrCount = 0;
    my $freqCount = 0;
    my $dataCount = 0;
    my $flushCount = 0;
    my $haveHwVals = 0;

    # open the pll attribute file
    open (FILE, "$pllFile") or die "Couldn't open $pllFile for input.\n";


    if (($DEBUG) || ($VERBOSE))
    {
        print "Chip: $chip \n";
        print "EC: $ec \n";
        print "File: $pllFile \n";
        print "Output File: $outputFile\n";
    }

    while (<FILE>)
    {
        # Each section we are interested in begins with ===BEGIN and ends with ===END
        if (/\===BEGIN/../\===END/)
        {
            # Keep track of how many instances we have in the file and reset some sub-counters.
            if (/\===BEGIN/)
            {
                $count++;
                $freqCount = 0;
                $dataCount = 0;
                $flushCount = 0;
            }
            # Determine if we are dealing with SIM or HW and store it in an array
            if (m/\#ENV\=/)
            {
                my $env = $_;
                chomp $env;
                $env =~ tr/\#ENV\=//d ;
                push(@envType,$env);
                if ($env eq "HW") {
                    $haveHwVals = 1;
                }
            }

            # Determine any frequency dependent values and store them in arrays
            # Also keep track of the size.
            if ((m/\#PU_/) || (m/\#MEMB_/))
            {
                $freqCount++;
                my $freq = $_;
                chomp $freq;
                ($freqType[$count - 1][$freqCount - 1], $freqVals[$count - 1][$freqCount - 1]) = split " = ",$freq;
                # Strip the # off the name and convert to lower case
                $freqType[$count - 1][$freqCount - 1] =~ tr/\#//d ;
                $freqValSize[$count - 1] = $freqCount;

                # Determine if this is the first instance of a particular name
                # If it is, then store it away in the uniq array.
                if ($uniqFreqTypeCount == 0)
                {
                    $uniqFreqType[$uniqFreqTypeCount] = $freqType[$count - 1][$freqCount - 1];
                    $uniqFreqTypeCount++;
                }
                else
                {
                    my $uniqFreq = 1;
                    for (my $i=0; $i < $uniqFreqTypeCount; $i++)
                    {
                        if ($freqType[$count - 1][$freqCount - 1] eq $uniqFreqType[$i])
                        {
                            $uniqFreq = 0;
                        }
                    }
                    if ($uniqFreq == 1)
                    {
                        $uniqFreqType[$uniqFreqTypeCount] = $freqType[$count - 1][$freqCount - 1];
                        $uniqFreqTypeCount++;
                    }
                }

            }

            # Determine the PLL_DATA name and store in an array
            if ((m/_DATA/) && (m/\#/))
            {
                my ($pllName, $garbage) = split " = ",$_;
                #Remove the leading #
                $pllName =~ tr/\#//d;
                #Remove whitespace at the end.
                $pllName =~ s/\s+$//;
                push(@pllDataName,$pllName);

                # Determine if this is the first instance of a particular name
                # If it is, then store it away in the uniq array.
                if ($count == 1)
                {
                    $uniqAttrs[$count - 1] = $pllName;
                    $uniqAttrCount++;
                }
                else
                {
                    my $uniq = 1;
                    for (my $i=0; $i < $uniqAttrCount; $i++)
                    {
                        if ($pllName eq $uniqAttrs[$i])
                        {
                            $uniq = 0;
                        }
                    }
                    if ($uniq == 1)
                    {
                        $uniqAttrs[$uniqAttrCount] = $pllName;
                        $uniqAttrCount++;
                    }
                }

            }


            # Determine the PLL_FLUSH name and store in an array
            if ((m/_FLUSH/) && (m/\#/) && !(m/GEN_FLUSH/))
            {
                my ($pllFlush, $garbage) = split " = ",$_;
                #Remove # at the beginning
                $pllFlush =~ tr/\#//d;
                #Remove whitespace at the end.
                $pllFlush =~ s/\s+$//;
                push(@pllFlushName,$pllFlush);

                # Determine if this is the first instance of a particular name
                # If it is, then store it away in the uniq array.
                if ($count == 1)
                {
                    $uniqFlushAttrs[$count - 1] = $pllFlush;
                    $uniqFlushAttrCount++;
                }
                else
                {
                    my $uniqFlush = 1;
                    for (my $i=0; $i < $uniqFlushAttrCount; $i++)
                    {
                        if ($pllFlush eq $uniqFlushAttrs[$i])
                        {
                            $uniqFlush = 0;
                        }
                    }
                    if ($uniqFlush == 1)
                    {
                        $uniqFlushAttrs[$uniqFlushAttrCount] = $pllFlush;
                        $uniqFlushAttrCount++;
                    }
                }


            }
            # No flush values exist.  Create a blank entry to prevent errors during flush looping output.
            elsif (m/GEN_FLUSH\=NO/) {
                my $pllFlush = "";
                push(@pllFlushName,$pllFlush);

            }

            #Store bit length in an array..
            if ($_ =~ m/_LENGTH\s+u\d+\s+(\d+)/)
            {
                $pllRingLength[$count - 1] = $1;
            }

            #Determine the actual data names and values and store them in arrays.
            #Also keep track of the size.
            if ((m/_DATA/) && (m/\[/))
            {
                my $garbage;
                $dataCount++;
                chomp $_;
                ($pllDataArrayNames[$count - 1][$dataCount - 1], $garbage, $pllDataArrayVals[$count - 1][$dataCount - 1]) = split " ",$_;
                $pllDataSize[$count - 1] = $dataCount;
            }

            #Determine the actual flush names and values and store them in arrays.
            #Also keep track of the size.
            if ((m/_FLUSH/) && (m/\[/))
            {
                my $garbage;
                $flushCount++;
                chomp $_;
                ($pllFlushArrayNames[$count - 1][$flushCount - 1], $garbage, $pllFlushArrayVals[$count - 1][$flushCount - 1]) = split " ",$_;
                $pllFlushSize[$count - 1] = $flushCount;
            }

        }

    }
    close (FILE);

    #Fill in some other values now that we need
    for (my $q=0; $q < $uniqAttrCount; $q++)
    {
        for (my $r=0; $r < $count; $r++)
        {
            if ($uniqAttrs[$q] eq $pllDataName[$r])
            {
                $uniqAttrSize[$q] = $pllDataSize[$r];
                last;
            }
        }
    }

    for (my $q=0; $q < $uniqFlushAttrCount; $q++)
    {
        for (my $r=0; $r < $count; $r++)
        {
            if ($uniqFlushAttrs[$q] eq $pllFlushName[$r])
            {
                $uniqFlushAttrSize[$q] = $pllFlushSize[$r];
                last;
            }
        }
    }


    #Embed some version info
    print OUTFILE "/**\n";
    print OUTFILE " \@kdbfile $pllFile\n";
    print OUTFILE " \@chip $chip\n";
    print OUTFILE " \@ec $ec\n";
    print OUTFILE "*/\n";
    print OUTFILE "\n";


    #################################################################################
    # First loop over all instances of each uniq attribute within the pll data
    # Then loop over all HW and SIM instances
    # Then check the frequency dependencies
    # Output the attr values
    # Repeat all of the above for pll flush values.
    #################################################################################


    #First display the HW attr values
    ### PLL_DATA VALUES ###
    for (my $x = 0; $x < $uniqAttrCount; $x++)
    {
        my %freqHash = ();
        my $firstAttr = 1;
        my $simString = "\n";
        my $freqString = "";
        my $isDefHw = 0;
        my $isDefSim = 0;
        my $arrayIndex = 0;
        my @freqList = ();
        my $attr_prefix = "";
        my $y = 0;

        if ($uniqAttrs[$x] =~ m"(\S+)_DATA")
        {
            $attr_prefix = $1;
            $y = scalar @{$attrToFreqs{$attr_prefix}};
        }
        print OUTFILE "\n" . "const PLL_RING_ATTR_WITH_" . $y . "_KEYS $capChip" . "_" . $ec . "_" . "$uniqAttrs[$x]_array [] = {\n";

        for (my $y=0 ; $y < $count; $y++) {
            if ($pllDataName[$y] eq $uniqAttrs[$x])
            {
                if ($envType[$y] eq "HW")
                {
                    #This attribute has HW values.
                    $isDefHw = 1;
                    if ($firstAttr == 1)
                    {
                        print OUTFILE "#ifdef HW\n";
                        $firstAttr = 0;
                        $arrayIndex = 0;
                    } else
                    {
                        $arrayIndex++;
                    }
                    print OUTFILE "            {        // Entry $arrayIndex\n";
                    %freqHash = ();
                    for (my $q=0; $q < $uniqFreqTypeCount; $q++)
                    {
                        $freqHash{$uniqFreqType[$q]} = 0;
                    }
                    for (my $z=0; $z < $freqValSize[$y]; $z++) {
                        $freqHash{$freqType[$y][$z]} = $freqVals[$y][$z];
                    }
                    #                    foreach my $freq (sort keys %freqHash) {
                    if ($uniqAttrs[$x] =~ m"(\S+)_DATA")
                    {
                        my $attr_prefix = $1;
                        for (my $freqIdx = 0; $freqIdx <= $#{$attrToFreqs{$attr_prefix}}; $freqIdx++)
                        {
                            # Frequency is supported for this attribute
                            print OUTFILE "            $freqHash{$cronusNameToFapi{$attrToFreqs{$attr_prefix}[$freqIdx]}},   \t// $attrToFreqs{$attr_prefix}[$freqIdx] = $cronusNameToFapi{$attrToFreqs{$attr_prefix}[$freqIdx]} \n";
                        }
                    }
                    print OUTFILE "            $pllRingLength[$y], \t// $pllDataName[$y] ring length\n";
                    print OUTFILE "            $pllDataSize[$y], \t// $pllDataName[$y] array length\n";
                    # Add attr values here
                    print OUTFILE "            { ";
                    for (my $attr_num = 0; $attr_num < $pllDataSize[$y]-1; $attr_num++)
                    {
                        print OUTFILE "$pllDataArrayVals[$y][$attr_num], ";
                    }
                    print OUTFILE " }, \t// $pllDataName[$y]\n";

                    if (defined $pllFlushSize[$y])
                    {
                        print OUTFILE "            { ";
                        for (my $attr_num = 0; $attr_num < $pllFlushSize[$y]-1; $attr_num++)
                        {
                            print OUTFILE "$pllFlushArrayVals[$y][$attr_num], ";
                        }
                        print OUTFILE " }, \t// $pllFlushName[$y]\n";
                    }

                    print OUTFILE "            },\n";

                } # end envType condition

                # For SIM values, there are a couple of assumptions:
                # 1.  No frequency values
                # 2.  Only one set of values per attribute
                elsif ($envType[$y] eq "SIM")
                {
                    $isDefSim = 1;
                    $simString = "            \{        // Entry 0\n";
                    %freqHash = ();
                    for (my $q=0; $q < $uniqFreqTypeCount; $q++)
                    {
                        $freqHash{$uniqFreqType[$q]} = 0;
                    }
                    #                    foreach my $freq (sort keys %freqHash) {
                    if ($uniqAttrs[$x] =~ m"(\S+)_DATA")
                    {
                        my $attr_prefix = $1;
                        for (my $freqIdx = 0; $freqIdx <= $#{$attrToFreqs{$attr_prefix}}; $freqIdx++)
                        {
                            # Frequency is supported for this attribute
                            #                                if ($attrToFreqs{$attr_prefix}[$freqIdx] eq $cronusNameToFapi{$freq}) {
                            $simString = $simString . "            $freqHash{$cronusNameToFapi{$attrToFreqs{$attr_prefix}[$freqIdx]}},   \t// $attrToFreqs{$attr_prefix}[$freqIdx] = $cronusNameToFapi{$attrToFreqs{$attr_prefix}[$freqIdx]} \n";
                        }
                    }
                    $simString = $simString . "            $pllRingLength[$y], \t\t// $pllDataName[$y] ring length\n";
                    $simString = $simString . "            $pllDataSize[$y], \t\t// $pllDataName[$y] array length\n";
                    $simString = $simString . "            { ";
                    for (my $attr_num = 0; $attr_num < $pllDataSize[$y]-1; $attr_num++)
                    {
                        $simString = $simString . "$pllDataArrayVals[$y][$attr_num], ";
                    }
                    # Print final byte
                    $simString = $simString . " }, \t// $pllDataName[$y]\n";
                    if (defined $pllFlushSize[$y])
                    {
                        #                        $simString = $simString . "            $pllFlushSize[$y], \t\t// $pllFlushName[$y]_LENGTH\n";
                        $simString = $simString . "            { ";
                        if ( $pllDataName[$y] =~ m"ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL")
                        {
                            print " pllFlushSize[y] = $pllFlushSize[$y]   y = $y  array size = $#pllFlushSize \n";
                        }
                        for (my $attr_num = 0; $attr_num < $pllFlushSize[$y]-1; $attr_num++)
                        {
                            if ( $pllDataName[$y] =~ m"ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL")
                            {
                                print " pllFlushSize[y] = $pllFlushSize[$y]   y = $y \n";
                            }
                            $simString = $simString . "$pllFlushArrayVals[$y][$attr_num], ";
                        }
                        # Print final byte
                        $simString = $simString . " }, \t// $pllFlushName[$y]\n";
                    }
                    $simString = $simString . "            },\n";

                } # end sim condition
                else
                {
                    # We shouldn't be here
                    print "fapicreatePllRingAttrVals.pl:ERROR: Unexpected environment type.  Should only be HW or SIM. \n";
                    exit(1);
                }

            } # end pllDataName condition

        } # end for loop over all attributes


        #This is where we insert the SIM values.
        if (($isDefHw == 1) && ($isDefSim == 1))
        {
            $simString = "#else\n" . $simString;
        }

        print OUTFILE "$simString\n";

        #Only display this if we had HW values.
        if ($isDefHw == 1)
        {
            print OUTFILE "#endif\n";
        }

        print OUTFILE "        };\n";

    } # end for loop over uniq attributes

    if ($VERBOSE)
    {
        print "Number of sections in file: $count \n";
        print "Number of Freqs: @freqValSize \n";
        print "Number of Data Vals: @pllDataSize \n";
        print "Number of Flush Vals: @pllFlushSize \n";
        print "Uniq Freq Types: @uniqFreqType \n";
        print "Number of Uniq Freq Types: $uniqFreqTypeCount \n";
        print "Uniq Attrs: @uniqAttrs \n";
        print "Uniq Attr Size: @uniqAttrSize \n";
        print "Uniq Flush Attrs: @uniqFlushAttrs \n";
        print "Uniq Flush Attr Size: @uniqFlushAttrSize \n";
        print "Number of Uniq Attrs: $uniqAttrCount \n";
        print "Number of Uniq Flush Attrs: $uniqFlushAttrCount \n";

        print "envType: @envType \n \n";
        print "pllDataName: @pllDataName \n \n";
        print "pllFlushName: @pllFlushName \n \n";

        my $item1, my $item2;
        print "\nfreqType: \n";
        foreach $item1 (@freqType)
        {
            foreach $item2 (@{$item1})
            {
                print "$item2 ";
            }
            print "\n";
        }
        print "\nfreqVals: \n";
        foreach $item1 (@freqVals)
        {
            foreach $item2 (@{$item1})
            {
                print "$item2 ";
            }
            print "\n";
        }

    }

}

print OUTFILE "#endif  // FAPIPLLRINGATTR_H_\n";
close (OUTFILE);



sub help {
    printf("Usage:  fapicreatePllRingAttrVals.pl <output directory> [<attributes-file1> [<attributes-file2> ...] [-help|-h]\n");
    printf("Generates C header file from KB pll_ring.attributes file(s).  \n");
    printf("          fapicreatePllRingAttrVals.pl -v\n");
    exit(0);
}




sub parseArgs {
    #Note that arg 0 MUST be output dir
    foreach my $argnum (1 .. $#ARGV)
    {
        my $infile = $ARGV[$argnum];

        if ($Arg =~ m"^-debug" || $Arg =~ m"^-d")
        {
            $DEBUG = 1;
        }
        elsif ($Arg =~ m"^-verbose" || $Arg =~ m"^-v")
        {
            $VERBOSE = 1;
        }
        elsif ($Arg =~ m"^-help" || $Arg =~ m"^-h")
        {
            &help;
            exit 1;
        }
        else
        {
            $fileString = "$fileString " . "$infile";
        }
    }
}
