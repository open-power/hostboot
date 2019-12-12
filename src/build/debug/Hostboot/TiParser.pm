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
use Exporter;
our @EXPORT_OK = ('main');

# The TI pointer is located at 0x2008 offset from HRMOR
use constant TI_AREA_PTR => 0x2008;
# The size of the TI area
use constant TI_AREA_SIZE_BYTES => 48;
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

# @sub parseTiData parses the input TI data; the TI data gets printed to screen
# @param[in] tiAreaStr formatted binary TI data
sub parseTiData
{
    my $tiAreaStr = shift;

    # Create an array of bytes
    my @bytes = split(/ /, $tiAreaStr);


    ##############################################################################
    # Parse out the HB_TI_DataArea Struct and print.
    # See src/include/kernel/hbterminatetypes.H for the format of HB_TI_DataArea.
    ##############################################################################
    ::userDisplay("\nHB_TI_DataArea\n");

    # Type
    my $type = shiftMultiple(\@bytes, 2);

    my %HB_TERMINATE_TYPE = ( "0001" => "TI_WITH_PLID",
    "0002" => "TI_WITH_SRC", );

    my $terminateTypeString = "";
    if(!exists $HB_TERMINATE_TYPE{$type})
    {
        $terminateTypeString = "UNDEFINED";
    }
    else
    {
        $terminateTypeString = $HB_TERMINATE_TYPE{$type};
    }


    ::userDisplay("Terminate Type: " . $terminateTypeString . " (0x" . $type . ")\n");

    # Source
    my $source = shiftMultiple(\@bytes, 2);

    my %HB_TERMINATE_SOURCE = ( "0000" => "NO_TI_ERROR",
    "0001" => "TI_KERNEL_ASSERT",
    "0002" => "TI_CRIT_ASSERT",
    "0003" => "TI_SHUTDOWN",
    "0004" => "TI_UNHANDLED_EX",
    "0005" => "TI_BOOTLOADER", );

    my $sourceString = "";
    if(!exists $HB_TERMINATE_SOURCE{$source})
    {
        $sourceString = "UNDEFINED";
    }
    else
    {
        $sourceString = $HB_TERMINATE_SOURCE{$source};
    }

    ::userDisplay("Terminate Source: " . $sourceString." (0x" . $source
          . ")\n");

    # Hostboot Dump Flag
    my $hbDumpFlag = substr(@bytes[0], 0, 1);

    ::userDisplay("Hostboot Dump Flag: 0x" . $hbDumpFlag . "\n");

    # Reserved 2
    my $reserved2 = shiftMultiple(\@bytes, 2);

    ::userDisplay("Reserved2: 0x" . $reserved2 . "\n");

    # Reserved 3
    my $reserved3 = shiftMultiple(\@bytes, 2);

    ::userDisplay("Reserved3: 0x" . $reserved3 . "\n");

    # Error Data or Reserved 0
    my $ErrorData = shiftMultiple(\@bytes, 4);

    ::userDisplay("Error Data/Reserved0: 0x" . $ErrorData . "\n");

    # PLID
    my $plid = shiftMultiple(\@bytes, 4);

    ::userDisplay("PLID: 0x" . $plid . "\n");

    ############################################################################
    # Parse out the HB_T_SRC_DataArea Struct and print
    ############################################################################
    ::userDisplay "\t\nHB_T_SRC_DataArea\n";
    # First SRC Word often referred to as the SRC
    # Format: Bsxxyyyy
    ::userDisplay "SRC Word 0\n";

    # ID = Bs
    # s = Code Subsystem (1=FSP, C=HB, 7=PHYP)
    my $id = shift @bytes;
    my %CODE_SUBSYSTEM = ( "1" => "FSP",
                           "C" => "Hostboot",
                           "7" => "PHYP", );

    ::userDisplay("\tID: " . $CODE_SUBSYSTEM{substr($id, 1, 1)} ." (0x" . $id . ")\n");

    # Subsystem ID of Callout = xx
    my $subsystemId = shift @bytes;

    # Reason Code = yyyy
    my $reasonCode = shiftMultiple(\@bytes, 2);

    ::userDisplay("\tReason Code: 0x". $reasonCode ."\n");

    # Attempt to decode the reason code and the module id if supported
    ::decodeRc($reasonCode, $bytes[2]);

    # SRC Word 1 is reserved by FSP SRCI comp, so nothing to parse.

    # Third SRC word
    # Format: ssssmmrr
    # System Backplane CCIN = ssss
    ::userDisplay("\t\nSRC Word 2\n");

    my $sysBackPlaneCCIN = shiftMultiple(\@bytes, 2);

    ::userDisplay("\tSystem Backplane CCIN: 0x". $sysBackPlaneCCIN ."\n");

    # Module ID = mm
    # Hostboot usually has this value define a file or a function
    # The combination of Module ID + Reason Code *must* be completely unique
    # across the entire subsystem's codebase
    my $modId = shift @bytes;

    ::userDisplay("\tModule Id: " . " (0x". $modId .")\n");

    # FSP Subsystem = rr
    # 10 if FSP A, 20 if FSP B originated SRC (FSP subsystem only)
    my $fspSubSys = shift @bytes;

    my %FSP_SUBSYSTEM = ( "10" => "FSP A",
    "20" => "FSP B", );

    ::userDisplay("\tFSP Subsystem: ". $FSP_SUBSYSTEM{$fspSubSys} ." (0x". $fspSubSys
          .")\n");

    # SRC Word 3
    # Hex value of last Progess Code (FSP subsystem only)
    ::userDisplay("\t\nSRC Word 3\n");
    my $fullWord3 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\tLast Progress Code (FSP Only): 0x". $fullWord3."\n");

    # SRC Word 4
    # Error Status Flags
    ::userDisplay("\t\nSRC Word 4\n");
    my $fullWord4 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\tError Status Flags: 0x". $fullWord4."\n");

    # The Termination Type and Source should be the same as above, but for consistency,
    # we process them again here.

    # Remaining SRC Words are user data
    # SRC Word 5
    ::userDisplay("\t\nSRC Word 5\n");
    # iType: SRC or PLID Failure
    my $iType = shiftMultiple(\@bytes, 2);
    my $typeString = "";
    if(!exists $HB_TERMINATE_TYPE{$iType})
    {
        $typeString = "UNDEFINED";
    }
    else
    {
        $typeString = $HB_TERMINATE_TYPE{$iType};
    }

    ::userDisplay("\tSRC or PLID Failure: " . $typeString
          ." (0x" . $iType . ")\n");

    # iSource: Source of the SRC
    my $iSource = shiftMultiple(\@bytes, 2);
    my $srcString = "";
    if(!exists $HB_TERMINATE_SOURCE{$iSource})
    {
        $srcString = "UNDEFINED";
    }
    else
    {
        $srcString = $HB_TERMINATE_SOURCE{$iSource};
    }
    ::userDisplay("\tSource of the SRC: " . $srcString
          ." (0x" . $iSource . ")\n");

    # SRC Word 6
    my $fullWord6 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\t\nSRC Word 6: 0x". $fullWord6."\n");

    # SRC Word 7
    my $fullWord7 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\t\nSRC Word 7: 0x". $fullWord7."\n");

    # SRC Word 8
    my $fullWord8 = shiftMultiple(\@bytes, 4);

    ::userDisplay("\t\nSRC Word 8: 0x". $fullWord8."\n");

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
        notes => ["Usage examples:",
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
