# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/TiParser.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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
use strict;

package Hostboot::TiParser;
use Exporter qw(import);
our @EXPORT_OK = qw(main parseTiData formatDataForPrinting formatData shiftMultiple mapSafe);

# The TI pointer is located at 0x2008 offset from HRMOR
use constant TI_AREA_PTR => 0x2008;
# The size of the TI area
# refer to bootloader_data.H @sync_ti_area_size for the Ti area size
use constant TI_AREA_SIZE_BYTES => 128;
# The offset of the HBBL from HRMOR
use constant BL_HRMOR_OFFSET => 0x200000;
# Flag to not overlay HRMOR on top of the address
use constant IGNORE_HRMOR => 0x8000000000000000;
# Hostboot lives within first 64MB after HMOR
use constant HB_SPACE => 0x3FFFFFF;

# @sub formatData formats the input stream of bytes into a format acceptable
# by the parsing logic in this script.
# @param[in] data the binary representation of the TI data
# @return Formatted data
sub formatData
{
    my $data = shift;
    my $dataRaw = "";

    for (my $i = 0; $i < length($data); $i++)
    {
        my $dataHexStr = sprintf("%02X", ord(substr($data, $i, 1)));
        $dataRaw .= $dataHexStr;
        $dataRaw .= " ";
    }

    return $dataRaw."\n";
}

# @sub formatDataForPrinting formats the input binary data into readable
#        format for printing.
# @param[in] data unformatted binary data
# @return Formatted data
sub formatDataForPrinting
{
    my $data = shift;
    my $dataRaw = "";

    for (my $i = 0; $i < length($data); $i++)
    {
        my $dataHexStr = sprintf("%02X", ord(substr($data, $i, 1)));
        $dataRaw .= $dataHexStr;

        if ($i % 16 == 15)
        {
            $dataRaw .= "\n";
        }
        elsif ($i % 4 == 3)
        {
            $dataRaw .= "   ";
        }
    }

    return $dataRaw."\n";
}

# @sub getTiAreaData returns formatted and parsed TI Area data
# @param[in] override_hrmor a value to use instead of deduced HRMOR (optional)
sub getTiAreaData
{
    my $override_hrmor = shift;
    my $tiAddress = findTiAreaAddress($override_hrmor);
    if($tiAddress eq 0)
    {
         die "The TI Area Address is 0!\n";
    }

    ::userDisplay(sprintf "TiParser: The TI Area Address is 0x%08x\n", $tiAddress);
    my $tiData = ::readData($tiAddress, TI_AREA_SIZE_BYTES);
    my $tiDataFormatted = formatDataForPrinting($tiData);
    ::userDisplay("Unparsed binary HB TI Data:\n");
    ::userDisplay $tiDataFormatted;
    $tiDataFormatted = formatData($tiData);
    parseTiData($tiDataFormatted);
}

# @sub findTiAreaAddress finds the address of the TI Area
# @param[in] override_hrmor a value to use instead of deduced HRMOR (optional)
# @return The address of the TI Area
sub findTiAreaAddress
{
    my $override_hrmor = shift;
    my $hrmor = ::getHRMOR();
    ::userDisplay(sprintf "TiParser: HRMOR is 0x%08x\n", $hrmor);
    my $is_dump = ($hrmor eq 0); # HRMOR is 0 in dump parser

    if($override_hrmor ne 0)
    {
        $hrmor = $override_hrmor;
    }

    my $tiPtr = 0;
    if($is_dump)
    {
        # We are parsing the HB dump directly; the TI area is 0x2008 offset into
        # the file; we don't need to append the HRMOR to the address
        $tiPtr = ::read64(TI_AREA_PTR);
        if(($tiPtr & HB_SPACE) ne $tiPtr)
        {
            # This is a bootloader TI; need to strip the HRMOR offset from the address
            $tiPtr = $tiPtr & HB_SPACE;
        }
        else
        {
            # Regular HB TI; there is a level of indirection where the TI area is at
            # the offset pointed to by an offset at the TI_AREA_PTR, so we need to
            # make another read to get to the actual TI area.
            $tiPtr = ::read64($tiPtr);
        }
    }
    else
    {
        if($hrmor & BL_HRMOR_OFFSET)
        {
            # We're still in bootloader, so we need to subtract the bootloader offset
            # from HRMOR to arrive at the correct TI area
            $tiPtr = ::read64(IGNORE_HRMOR | $hrmor - BL_HRMOR_OFFSET | TI_AREA_PTR, 8);
        }
        else
        {
            $tiPtr = ::read64(IGNORE_HRMOR | $hrmor | TI_AREA_PTR, 8);
        }

        # Bootloader TI area is located at the pointer at TI_AREA_PTR; however, HB
        # TI area is located at an offset that lives at TI_AREA_PTR (there is another
        # level of indirection).
        if(not ($tiPtr > $hrmor))
        {
            # HB TI - there is a level of indirection
            $tiPtr = ::read64($tiPtr);
        }
    }

    if($tiPtr eq 0)
    {
        ::userDisplay(sprintf "TiParser: No TI pointer found at location 0x%08x\n", TI_AREA_PTR);
        return 0;
    }

    ::userDisplay(sprintf "TiParser: TI pointer is 0x%08x\n", $tiPtr);

    return $tiPtr;
}

# @sub shiftMultiple shifts in multiple bytes from the input array
# @param[in] Byte array to shift from
# @param[in] Number of bytes to shift in
# @return The shifted bytes
sub shiftMultiple
{
    # Note: Don't need to get the first arg since we're modifing by reference
    # Amount to shift off the array.
    my $i_length = $_[1];

    my $data = "";
    for (my $i=0; $i < $i_length; $i++)
    {
        # Shift off the first byte. Do this by reference so that the string is
        # modified outside the function.
        $data .= shift @{$_[0]};
    }

    return uc $data;
}

# @sub mapSafe maps the input key to the hash value of the input hash or to
#      unknown value
# @param[in] map the given hash
# @param[in] key the key to find in the hash
# @return String "UNDEFINED" if the key is not in the hash table or the value
#         associated with the key if it's present.
sub mapSafe
{
    my $map = shift;
    my $key = shift;

    my $string = "UNDEFINED";

    if(exists $map->{$key})
    {
        $string = $map->{$key};
    }

    return $string;
}

# @sub parseTiData parses the input TI data; the TI data gets printed to screen
# @param[in] tiAreaStr formatted binary TI data
sub parseTiData
{
    my $tiAreaStr = shift;

    # Create an array of bytes
    my @bytes = split(/ /, $tiAreaStr);

    ############################################################################
    # Parse out the HB_TI_DataArea Struct and print. See hbterminatetypes.H for
    # current format.
    ############################################################################
    ::userDisplay("\nHB_TI_DataArea\n");

    #==========================================================================
    #                                Word 0
    #==========================================================================

    # TI Area Valid
    my $tiAreaValid = shift @bytes;
    ::userDisplay("TI Area Valid?: 0x" . $tiAreaValid . "\n");

    # Command Type
    my $commandType = shift @bytes;
    ::userDisplay("Command Type: 0x" . $commandType . "\n");

    # Number Of Data Bytes - unused by Hostboot
    my $numberOfDataBytes = shiftMultiple(\@bytes, 2);
    ::userDisplay("Number of Data Bytes: 0x$numberOfDataBytes (unused by HB)\n");

    #==========================================================================
    #                                Word 1
    #==========================================================================

    # Reserved 0 - unused
    my $reserved0 = shift @bytes;
    ::userDisplay("(Reserved: 0x" . $reserved0 . " (unused by HB))\n");

    # HB Terminate Type
    my $terminateType = shift @bytes;

    my %HB_TERMINATE_TYPE = ( "01" => "TI_WITH_PLID",
                              "02" => "TI_WITH_SRC", );

    ::userDisplay("Terminate Type: " . mapSafe(\%HB_TERMINATE_TYPE, $terminateType) . " (0x" . $terminateType . ")\n");

    # Dump Type
    my $dumpType = shiftMultiple(\@bytes, 2);
    my %DUMP_TYPE_MAP = ( "0000" => "SW_DUMP",
                          "0001" => "SW_DUMP", # 0 and 1 are SW_DUMP
                          "0002" => "HW_DUMP",);

    ::userDisplay("Dump Type: " . mapSafe(\%DUMP_TYPE_MAP, $dumpType) . " (0x" . $dumpType . ")\n");

    #==========================================================================
    #                                Word 2
    #==========================================================================

    # At this time, this is a PHYP-only word
    # SRC Format - unused by Hostboot
    my $srcFormat = shift @bytes;
    # SRC Flags - unused by Hostboot
    my $srcFlags = shift @bytes;
    # Num Ascii Words - unused by Hostboot
    my $numAsciiWords = shift @bytes;
    # Num Hex Words - unused by Hostboot
    my $numHexWords = shift @bytes;

    my $word2 = $srcFormat.$srcFlags.$numAsciiWords.$numHexWords;
    ::userDisplay("PHYP-specific data: 0x" . $word2 . " (unused by HB)\n");

    #==========================================================================
    #                                Hostboot Flags
    #==========================================================================
    # Hostboot Dump Flag - 1 bit
    my $hbDumpFlag = 0;
    $hbDumpFlag = substr(@bytes[0], 0, 1);

    ::userDisplay(sprintf "Hostboot Dump Flag: 0x%02X\n", $hbDumpFlag);

    # 7 reserved bits
    my $reserved1 = shift @bytes;

    # HB Terminate Source
    my $terminateSource = shift @bytes;

    my %HB_TERMINATE_SOURCE = ( "00" => "NO_TI_ERROR",
                                "01" => "TI_KERNEL_ASSERT",
                                "02" => "TI_CRIT_ASSERT",
                                "03" => "TI_SHUTDOWN",
                                "04" => "TI_UNHANDLED_EX",
                                "05" => "TI_BOOTLOADER", );

    ::userDisplay("Terminate Source: " . mapSafe(\%HB_TERMINATE_SOURCE, $terminateSource) ." (0x" . $terminateSource . ")\n");

    # Length of SRC - unused by Hostboot
    my $lenfthOfSrc = shiftMultiple(\@bytes, 2);

    ############################################################################
    # Parse out the HB_T_SRC_DataArea Struct and print
    ############################################################################
    ::userDisplay("\nHB_T_SRC_DataArea\n");
    # Zeroth SRC Word often referred to as the SRC
    # Format: Bsxxyyyy
    ::userDisplay("SRC Word 0\n");

    # ID = Bs
    # s = Code Subsystem (1=FSP, C=HB, 7=PHYP)
    my $id = shift @bytes;
    my %CODE_SUBSYSTEM = ( "1" => "FSP",
                           "C" => "Hostboot",
                           "7" => "PHYP", );

    ::userDisplay("\tID: " . mapSafe(\%CODE_SUBSYSTEM, substr($id, 1, 1)) ." (0x" . $id . ")\n");

    # Subsystem ID of Callout = xx
    my $subsystemId = shift @bytes;
    ::userDisplay("\tSubsystem ID: (0x" . $subsystemId . ")\n");

    # Reason Code = yyyy
    my $reasonCode = shiftMultiple(\@bytes, 2);

    ::userDisplay("\tReason Code: 0x" . $reasonCode . "\n");

    # Attempt to decode the reason code
    ::userDisplay("Decoded Reason Code: \n");

    my $decodeMsg = ::decodeRc($reasonCode);
    $decodeMsg =~ s/\n/\n\t/g;
    ::userDisplay("\t$decodeMsg");

    # First SRC Word is reserved by FSP SRCI comp, so nothing to parse.

    # Second SRC word
    # Format: ssssmmrr
    # System Backplane CCIN = ssss
    ::userDisplay("\nSRC Word 2\n");

    my $sysBackPlaneCCIN = shiftMultiple(\@bytes, 2);

    ::userDisplay("\tSystem Backplane CCIN: 0x" . $sysBackPlaneCCIN . "\n");

    # Module ID = mm
    # Hostboot usually has this value define a file or a function
    # The combination of Module ID + Reason Code *must* be completely unique
    # across the entire subsystem's codebase
    my $modId = shift @bytes;

    ::userDisplay("\tModule ID: (0x" . $modId . ")\n");

    # FSP Subsystem = rr
    # 10 if FSP A, 20 if FSP B originated SRC (FSP subsystem only)
    my $fspSubSys = shift @bytes;

    my %FSP_SUBSYSTEM = ( "10" => "FSP A",
                          "20" => "FSP B", );

    ::userDisplay("\tFSP Subsystem: ". mapSafe(\%FSP_SUBSYSTEM, $fspSubSys) ." (0x" . $fspSubSys . ")\n");

    # Third SRC Word
    # Hex value of last Progess Code (FSP subsystem only)
    ::userDisplay("\nSRC Word 3\n");
    my $fullWord3 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\tLast Progress Code (FSP Only): 0x" . $fullWord3 . "\n");

    # Fourth SRC Word
    # Error Status Flags
    ::userDisplay("\nSRC Word 4\n");
    my $fullWord4 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\tError Status Flags: 0x" . $fullWord4 . "\n");

    ::userDisplay("SRC Word 5\n");

    # Remaining SRC Words are user data
    # SRC Word 5
    # iType: SRC of the PLID Failure
    my $iType = shiftMultiple(\@bytes, 2);
    # Word 5 defines the size of the TI type to be 16 bits as opposed to 8
    # bits earlier.
    my %HB_TERMINATE_TYPE_16_BITS = ( "0001" => "TI_WITH_PLID",
                                      "0002" => "TI_WITH_SRC", );
    ::userDisplay("\tSRC or the PLID Failure: " . mapSafe(\%HB_TERMINATE_TYPE_16_BITS, $iType) ." (0x" . $iType . ")\n");

    # iSource: Source of the SRC (16 bits in Word 5)
    my $iSource = shiftMultiple(\@bytes, 2);

    my %HB_TERMINATE_SOURCE_16_BITS = ( "0000" => "NO_TI_ERROR",
                                        "0001" => "TI_KERNEL_ASSERT",
                                        "0002" => "TI_CRIT_ASSERT",
                                        "0003" => "TI_SHUTDOWN",
                                        "0004" => "TI_UNHANDLED_EX",
                                        "0005" => "TI_BOOTLOADER", );
    ::userDisplay("\tSource of the SRC: " . mapSafe(\%HB_TERMINATE_SOURCE_16_BITS, $iSource) ." (0x" . $iSource . ")\n");

    # SRC Word 6
    my $fullWord6 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\nSRC Word 6: 0x" . $fullWord6 . "\n");

    # SRC Word 7
    my $fullWord7 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\nSRC Word 7: 0x" . $fullWord7 . "\n");

    # SRC Word 8
    my $fullWord8 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\nSRC Word 8: 0x" . $fullWord8 . "\n");

    ############################################################################
    # End HB_T_SRC_DataArea
    ############################################################################

    # Error data
    my $errorData = shiftMultiple(\@bytes, 4);
    ::userDisplay("Error Data: 0x" . $errorData . "\n");

    # EID
    my $eid = shiftMultiple(\@bytes, 4);
    ::userDisplay("EID: 0x" . $eid . "\n");
}

# @sub helpInfo prints the usage info
sub helpInfo
{
    my %info = (
        name => "TiParser",
        intro => ["Fetches and parses the HB/HBBL TI Area."],
        options => {
                   "hrmor" => ["The HRMOR value to overwrite the default HRMOR with."],
                   },
        notes => ["Made during HB Hackathon 2019 by ismirno and matthew.raybuck.",
                  "Usage examples:",
                  "For HB dump: hb-dump-debug --file=<dump file> --tool=TiParser",
                  "In Cronus: ecmd-debug-framework.pl --Tool=TiParser",
                  "In simics: hb-TiParser"
                 ],
    );
}

# @sub main script's main entry
sub main
{
    my ($unused, $args) = @_;
    my $override_hrmor = 0;

    if(defined $args->{"hrmor"})
    {
        $override_hrmor = hex($args->{"hrmor"});
    }
    elsif(defined $args->{"--hrmor"})
    {
        $override_hrmor = hex($args->{"--hrmor"});
    }

    getTiAreaData($override_hrmor);
}
