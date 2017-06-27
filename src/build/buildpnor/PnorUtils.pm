#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/PnorUtils.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

package PnorUtils;

use File::Basename;
use Exporter 'import';
@EXPORT_OK = qw(loadPnorLayout getNumber traceErr trace run_command PAGE_SIZE
                loadBinFiles findLayoutKeyByEyeCatch checkSpaceConstraints
                getSwSignatures getBinDataFromFile checkFile displayPnorLayout);
use strict;
use Data::Dumper;

my $TRAC_ERR = 0;
# 0=errors, >0 for more traces, leaving at 1 to keep key milestone traces.
my $g_trace = 1;

use XML::Simple;
################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

use constant PAGE_SIZE => 4096;

################################################################################
# loadPnorLayout
################################################################################
sub loadPnorLayout
{
    my ($i_pnorFile, $i_pnorLayoutRef, $i_physicalOffsets, $i_testRun) = @_;
    my $this_func = (caller(0))[3];

    unless(-e $i_pnorFile)
    {
        traceErr("$this_func: File not found: $i_pnorFile");
        return -1;
    }

    #parse the input XML file
    my $xs = new XML::Simple(keyattr=>[], forcearray => 1);
    my $xml = $xs->XMLin($i_pnorFile);
    my $imageSize = 0;
    my $chipSize = 0;

    # Save the metadata - imageSize, blockSize, toc Information etc.
    foreach my $metadataEl (@{$xml->{metadata}})
    {
        # Get meta data
        $imageSize   = $metadataEl->{imageSize}[0];
        $chipSize    = $metadataEl->{chipSize}[0];
        my $blockSize   = $metadataEl->{blockSize}[0];
        my $tocSize     = $metadataEl->{tocSize}[0];
        my $arrangement = $metadataEl->{arrangement}[0];
        $imageSize      = getNumber($imageSize);
        $chipSize       = getNumber($chipSize);
        $blockSize      = getNumber($blockSize);
        $tocSize        = getNumber($tocSize);
        $$i_pnorLayoutRef{metadata}{imageSize}   = $imageSize;
        $$i_pnorLayoutRef{metadata}{chipSize}    = $chipSize;
        $$i_pnorLayoutRef{metadata}{blockSize}   = $blockSize;
        $$i_pnorLayoutRef{metadata}{tocSize}     = $tocSize;
        $$i_pnorLayoutRef{metadata}{arrangement} = $arrangement;

        my $numOfSides  = scalar (@{$metadataEl->{side}});
        my $sideSize = ($imageSize)/($numOfSides);

        trace(2, " $this_func: metadata: imageSize = $imageSize, blockSize=$blockSize, arrangement = $arrangement, numOfSides: $numOfSides, sideSize: $sideSize, tocSize: $tocSize");

        #determine the TOC offsets from the arrangement and side Information
        #stored in the layout xml
        #
        #Arrangement A-B-D means that the layout had Primary TOC (A), then backup TOC (B), then Data (pnor section information).
        #Similaryly, arrangement A-D-B means that primary toc is followed by the data (section information) and then
        #the backup TOC. In order for the parsing tools to find the TOC, the TOCs must be at TOP_OF_FLASH-(2) * TOC_SIZE
        # and the other at 0x0 of flash memory.
        if ($arrangement eq "A-B-D")
        {
            my $count = 0;
            foreach my $side (@{$metadataEl->{side}})
            {
                my $golden     = (exists $side->{golden} ? "yes" : "no");
                my $sideId     = $side->{id}[0];
                my $primaryTOC = ($sideSize)*($count);
                my $backupTOC  = ($primaryTOC)+($tocSize);

                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{primary} = $primaryTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{backup}  = $backupTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{golden}       = $golden;

                $count = $count + 1;
                trace(2, "A-B-D: side:$sideId primaryTOC:$primaryTOC, backupTOC:$backupTOC, golden: $golden");
            }
        }
        elsif ($arrangement eq "A-D-B")
        {
            my $count = 0;
            foreach my $side (@{$metadataEl->{side}})
            {
                my $golden     = (exists $side->{golden} ? "yes" : "no");
                my $sideId     = $side->{id}[0];
                #Leave 1 block sized pad because the top addr of flash special
                # and simics broke we had the toc touching it
                my $primaryTOC = ($sideSize)*($count + 1) - ($tocSize + $blockSize) ;
                my $backupTOC  = ($sideSize)*($count);

                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{primary} = $primaryTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{toc}{backup}  = $backupTOC;
                $$i_pnorLayoutRef{metadata}{sides}{$sideId}{golden}       = $golden;
                $count = $count + 1;
                trace(2, "A-D-B: side:$sideId, primaryTOC:$primaryTOC, backupTOC:$backupTOC, golden: $golden");
            }
        }
        else
        {
            trace(0, "Arrangement:$arrangement is not supported");
            exit(1);
        }

        #Iterate over the <section> elements.
        foreach my $sectionEl (@{$xml->{section}})
        {
            my $description = $sectionEl->{description}[0];
            my $eyeCatch = $sectionEl->{eyeCatch}[0];
            my $physicalOffset = $sectionEl->{physicalOffset}[0];
            my $physicalRegionSize = $sectionEl->{physicalRegionSize}[0];
            my $side = $sectionEl->{side}[0];
            my $testonly = $sectionEl->{testonly}[0];
            my $ecc = (exists $sectionEl->{ecc} ? "yes" : "no");
            my $sha512Version = (exists $sectionEl->{sha512Version} ? "yes" : "no");
            my $sha512perEC = (exists $sectionEl->{sha512perEC} ? "yes" : "no");
            my $preserved = (exists $sectionEl->{preserved} ? "yes" : "no");
            my $reprovision = (exists $sectionEl->{reprovision} ? "yes" : "no");
            my $readOnly = (exists $sectionEl->{readOnly} ? "yes" : "no");
            if (($i_testRun == 0) && ($sectionEl->{testonly}[0] eq "yes"))
            {
                next;
            }

            trace(3, "$this_func: description = $description, eyeCatch=$eyeCatch, physicalOffset = $physicalOffset, physicalRegionSize=$physicalRegionSize, side=$side");

            $physicalOffset = getNumber($physicalOffset);
            $physicalRegionSize = getNumber($physicalRegionSize);

            if($physicalRegionSize  + $physicalOffset > $imageSize)
            {
                die "ERROR: $this_func: Image size ($imageSize) smaller than $eyeCatch's offset + $eyeCatch's size (".($physicalOffset + $physicalRegionSize)."). Aborting! ";
            }

            $$i_pnorLayoutRef{sections}{$physicalOffset}{description} = $description;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{eyeCatch} = $eyeCatch;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalOffset} = $physicalOffset;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{physicalRegionSize} = $physicalRegionSize;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{side} = $side;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{ecc} = $ecc;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{sha512Version} = $sha512Version;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{sha512perEC} = $sha512perEC;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{preserved} = $preserved;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{reprovision} = $reprovision;
            $$i_pnorLayoutRef{sections}{$physicalOffset}{readOnly} = $readOnly;

            #store the physical offsets of each section in a hash, so, it is easy
            #to search physicalOffsets based on the name of the section (eyecatch)
            if ($side eq "sideless")
            {
                foreach my $metadata (@{$xml->{metadata}})
                {
                    foreach my $sides (@{$metadata->{side}})
                    {
                        $$i_physicalOffsets{side}{$sides->{id}[0]}{eyecatch}{$eyeCatch} = $physicalOffset;
                    }
                }
            }
            else
            {
                $$i_physicalOffsets{side}{$side}{eyecatch}{$eyeCatch} = $physicalOffset;
            }
        }
    }
    return 0;
}

################################################################################
# align_down: Align the input to the lower end of the PNOR side
################################################################################
sub align_down
{
    my ($addr,$n) = @_;
    return (($addr) - ($addr)%($n));
}

################################################################################
# align_up: Align the input address to the higher end of the PNOR side
################################################################################
sub align_up
{
    my ($addr,$n) = @_;
    return ((($addr) + ($n-1)) & ~($n-1));
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
# run_command - First print, and then run a system command, erroring out if the
#               command does not complete successfully
################################################################################
sub run_command
{
    my $command = shift;
    trace(1, "$command");
    my $rc = system($command);
    die "Error running command: $command. Nonzero return code of ($rc) returned.\n" if ($rc !=0);
}

################################################################################
# loadBinFiles - Load bin file CSV into hash
################################################################################
sub loadBinFiles
{
    my ($i_binFilesCSV, $i_binFilesRef) = @_;

    print "Loading bin files...\n";

    foreach my $binFile (split(',',$i_binFilesCSV))
    {
        # Format is 'BIN_NAME=FILENAME'
        my @arr = split('=', $binFile);

        $$i_binFilesRef{$arr[0]} = $arr[1];
    }
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
        if($sectionHash{$key}{eyeCatch} eq $eyeCatch)
        {
            $layoutKey = $key;
            last;
        }
    }

    return $layoutKey;
}

################################################################################
# checkSpaceConstraints - Make sure provided files will fit in their sections
################################################################################
sub checkSpaceConstraints
{
    my ($i_pnorLayoutRef, $i_binFiles, $testRun) = @_;
    my $this_func = (caller(0))[3];
    my $key;

    my %sectionHash = %{$$i_pnorLayoutRef{sections}};

    for $key ( keys %{$i_binFiles})
    {
        my $filesize = -s $$i_binFiles{$key};

        my $layoutKey = findLayoutKeyByEyeCatch($key, \%$i_pnorLayoutRef);
        if( $layoutKey == -1)
        {
            die "ERROR: $this_func: entry not found in PNOR layout for file $$i_binFiles{$key}, under eyecatcher $key";
        }

        my $eyeCatch = $sectionHash{$layoutKey}{eyeCatch};
        my $physicalRegionSize = $sectionHash{$layoutKey}{physicalRegionSize};

        if($filesize > $physicalRegionSize)
        {
            # If this is a test run increase HBI size by PAGE_SIZE until all test
            # cases fit
            if ($testRun && $eyeCatch eq "HBI")
            {
                print "Adjusting HBI size - ran out of space for test cases\n";
                my $hbbKey = findLayoutKeyByEyeCatch("HBB", \%$i_pnorLayoutRef);
                adjustHbiPhysSize(\%sectionHash, $layoutKey, $filesize, $hbbKey);
            }
            else
            {
                die "ERROR: $this_func: Image provided ($$i_binFiles{$eyeCatch}) has size ($filesize) which is greater than allocated space ($physicalRegionSize) for section=$eyeCatch.  Aborting!";
            }
        }
    }
    trace(1, "Done checkSpaceConstraints");
}


###############################################################################
# adjustHbiPhysSize - Adjust HBI physical size when running test cases and fix
#                     up physical offsets of partitions between HBI and HBB
################################################################################
sub adjustHbiPhysSize
{
    my ($i_sectionHashRef, $i_hbiKey, $i_filesize, $i_hbbKey) = @_;

    my %sectionHash = %$i_sectionHashRef;

    # Increment HBI physical size by PAGE_SIZE until the HBI file can fit
    my $hbi_old = $sectionHash{$i_hbiKey}{physicalRegionSize};
    while ($i_filesize > $sectionHash{$i_hbiKey}{physicalRegionSize})
    {
        $sectionHash{$i_hbiKey}{physicalRegionSize} += PAGE_SIZE;
    }
    my $hbi_move = $sectionHash{$i_hbiKey}{physicalRegionSize} - $hbi_old;
    my $hbi_end = $sectionHash{$i_hbiKey}{physicalRegionSize} + $hbi_move;

    # Fix up physical offset affected by HBI size change
    foreach my $section (keys %sectionHash)
    {
        # Only fix partitions after HBI and before HBB
        if ( ( $sectionHash{$section}{physicalOffset} >
               $sectionHash{$i_hbiKey}{physicalOffset} ) &&
             ( $sectionHash{$section}{physicalOffset} <
               $sectionHash{$i_hbbKey}{physicalOffset} )
            )
        {
            $sectionHash{$section}{physicalOffset} += $hbi_move;
            # Ensure section adjustment does not cause an overlap with HBB
            if ($sectionHash{$section}{physicalOffset} >
                $sectionHash{$i_hbbKey}{physicalOffset})
            {
                die "Error detected $sectionHash{$section}{eyeCatch}'s adjusted size overlaps HBB";
            }
        }
    }
}

###############################################################################
# getSwSignatures -   Extracts concatenation of sw signatures from secure
#                     container header. Simplified to skip around to the data
#                     needed.
################################################################################
sub getSwSignatures
{
    my ($i_file) = @_;

    # Constants defined in ROM code.
    use constant ecid_size => 16; #bytes
    use constant sw_key_size => 132; #bytes

    # Offsets defined in secure boot PLDD.
    # Relative offset are based on the previous constant
    use constant sw_key_count_offset => 450; #bytes
    use constant relative_offset_to_hw_ecid_count => 73; #bytes
    # Offset assuming Default of ECID count = 0 and SW count = 1
    use constant relative_offset_to_sw_ecid_count => 626; #bytes
    # Offset assuming Default of ECID count = 0
    use constant relative_offset_to_sw_signatures => 1; #bytes

    # Header info
    my $sw_key_count = 0;
    my $hw_ecid_count = 0;
    my $sw_ecid_count = 0;
    my $sw_signatures = 0;

    # Get header data from file
    my $header_data = getBinDataFromFile($i_file);

    # get sw key count
    my $cur_offset = sw_key_count_offset;
    $sw_key_count  = unpack("x$cur_offset C", $header_data);

    # get hw ecid counts
    $cur_offset += relative_offset_to_hw_ecid_count;
    $hw_ecid_count = unpack("x$cur_offset C", $header_data);

    # Variable size elements of a secure header
    # Note 1 sw_key is already considered in above constants
    my $num_optional_keys = ($sw_key_count > 1) ?
                             ($sw_key_count - 1) : 0;
    my $variable_size_offset = ($num_optional_keys * sw_key_size)
                                + ($hw_ecid_count * ecid_size);

    # get sw ecid count
    $cur_offset +=  relative_offset_to_sw_ecid_count + $variable_size_offset;
    $sw_ecid_count = unpack("x$cur_offset C", $header_data);

    # Variable size elements of a secure header
    $variable_size_offset = ($sw_ecid_count * ecid_size);

    # get sw signatures
    $cur_offset +=  relative_offset_to_sw_signatures + $variable_size_offset;
    # Get concatenation of all possible sw signatures
    $sw_signatures = substr($header_data, $cur_offset,
                            $sw_key_count*sw_key_size);

    return $sw_signatures;
}

###############################################################################
# getBinDataFromFile -   Extracts binary data from a given file into a variable
################################################################################
sub getBinDataFromFile
{
    my ($i_file) = @_;

    my $data = 0;
    open (BINFILE, "<", $i_file) or die "Error opening file $i_file: $!\n";
    binmode BINFILE;
    read(BINFILE,$data,PAGE_SIZE);
    die "Error reading of $i_file failed" if $!;
    close(BINFILE);
    die "Error closing $i_file failed" if $!;

    return $data;
}

# sub checkFile
#
# Check if file exists and is of type XML
#
# @param [in] i_layoutFile - PNOR layout file
# @return - N/A Die on failure
#
sub checkFile
{
    my $i_layoutFile = shift;

    my($filename, $dirs, $suffix) = fileparse($i_layoutFile,".xml");

    unless(-e $i_layoutFile)
    {
        die "File not found: $i_layoutFile";
    }
    if ($suffix ne ".xml")
    {
        die "File not type XML: $i_layoutFile";
    }
}

###############################################################################
# Display Pnor Layout -   Display XML pnor layout more simply
################################################################################
sub displayPnorLayout
{
    my ($i_pnorLayoutRef, $i_gaps, $i_verbose) = @_;

    if (!$i_verbose)
    {
        print "-------------------------------------------------------- \n";
        print "Name-physicalOffset-physicalRegionSize-physicalRegionEnd \n";
        print "-------------------------------------------------------- \n";
    }

    my $curOffset = 0;
    my $gapTotal = 0;
    my $prevOffset = 0;
    my $prevSize = 0;
    # Iterate through all sections of PNOR, including TOC's
    foreach my $section (sort {$a <=> $b} keys %{$$i_pnorLayoutRef{sections}})
    {
        # Get hex format for each value
        my $offset = sprintf("0x%X",$$i_pnorLayoutRef{sections}{$section}{physicalOffset});
        my $size = sprintf("0x%X",$$i_pnorLayoutRef{sections}{$section}{physicalRegionSize});
        my $end = sprintf("0x%X",hex($offset)+hex($size));

        if ($prevOffset+$prevSize > hex($offset))
        {
            my $hexEndPrevSection = sprintf("0x%X",$prevOffset+$prevSize);
            print "---- Error: Prevoius Section ends at offset $hexEndPrevSection which is after Current Offset $offset\n";
            print "---- Current Offset Section: ".$$i_pnorLayoutRef{sections}{$section}{eyeCatch}."-$offset-$size-$end\n";
            die ">>Error overlapping section\n";
        }

        # Check if there is a gap between sections
        if ($i_gaps && ($curOffset < hex($offset)))
        {
            print "  > Gap Found: addr = ".sprintf("0x%X",$curOffset);

            # Display address and size of gap
            my $gapSize = hex($offset)-$curOffset;
            print " size = ".sprintf("0x%X",$gapSize)."\n";
            $gapTotal += $gapSize;
            $curOffset = hex($offset) + hex($size);
        }
        else
        {
            $curOffset += hex($size);
        }

        $prevOffset = hex($offset);
        $prevSize = hex($size);

        # Print sections
        if ($i_verbose)
        {
            print $$i_pnorLayoutRef{sections}{$section}{eyeCatch}."\n";
            print Dumper $$i_pnorLayoutRef{sections}{$section};
            print "\n";
        }
        else
        {
            print $$i_pnorLayoutRef{sections}{$section}{eyeCatch}."-$offset-$size-$end\n";
        }
    }

    # Display total free space
    if($i_gaps)
    {
        my $hexVal = sprintf("0x%X",$gapTotal);
        my $kiloBytes = $gapTotal/1024;
        print "\n---Total Gap(s) Free Space = ".$gapTotal." Bytes or ".$kiloBytes." KB";
        print " (".$hexVal.")\n";
    }

    my $endImageFree = $$i_pnorLayoutRef{metadata}{imageSize} - $curOffset;
    $endImageFree = 0 if ($endImageFree < 0 );
    my $totalFree = $endImageFree + $gapTotal;

    my $hexVal = sprintf("0x%X",$totalFree);
    my $kiloBytes = $totalFree/1024;
    print "---Total Free Space = ".$totalFree." Bytes or ".$kiloBytes." KB";
    print " (".$hexVal.")\n";
}
1;
