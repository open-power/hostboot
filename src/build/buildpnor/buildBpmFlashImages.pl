#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildBpmFlashImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2023
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
use warnings;
use File::Basename;
use Getopt::Long;
use Pod::Usage;

my $progName = File::Basename::basename $0;
my $outputDir=".";
my $bpmUtilScript="./bpm-utils/insertBpmFwCrc.py";
my $bpmCrcProgram="./bpm-utils/imageCrc";
my @files;
my $cfgHelp=0;
my $cfgMan=0;
my $verbose=0;

GetOptions("output-dir=s" => \$outputDir,
           "bpm-util-script=s" => \$bpmUtilScript,
           "bpm-crc-program=s" => \$bpmCrcProgram,
           "image=s" => \@files,
           "help" => \$cfgHelp,
           "verbose" => \$verbose,
           "man" => \$cfgMan ) || pod2usage(-verbose => 0);

pod2usage(-verbose => 1) if $cfgHelp;
pod2usage(-verbose => 2) if $cfgMan;

# Verify that there aren't any duplicate files in the array of input file names.
# This is done by creating an anonymous hash of all the file names and comparing
# the number of keys in the hash to the number of files in @files. If they are
# not equal then there is a duplicate file of the same name in the input file
# array.
if (keys %{{ map {$_, 1} @files }} != @files)
{
    die "One or more non-unique --image arguments supplied";
}

# Verify that there are no duplicate image files of different versions in the
# input --image arguments. This is done by creating an anonymous hash of all the
# output file names that would be generated based on the images given and then
# comparing the number of keys in that hash to the number of original file
# names. If the number keys and elements of @files aren't equal then there are
# two images for the same NVDIMM type of different versions present in the
# input and this is not allowed.
if (keys %{{map { (generateOutputNameAndVersion($_))[0], 1} @files}} != @files)
{
    die "One or more --image arguments are different versions of the same ".
        "image. Please remove the unused versions.";
}

if($verbose)
{
    print "Output dir = $outputDir\n";
    print "Input images:\n";
}

for my $file (@files)
{
    if ($verbose)
    {
        print "    $file\n";
    }

    generateConfigImage($file,$outputDir);
    generateFirmwareImage($file,$outputDir);
}

################################################################################
# @brief Processes an input file to pull information from its name and content
#        to be used when preparing the output file's binary image. This function
#        will only emit the binaries for the firmware portion of the BPM update.
#        The final binary will be organized in the following way:
#        Byte 1:     Major version number (MM), in hex representation of decimal
#        Byte 2:     Minor version number (mm), in hex representation of decimal
#        Byte 3-4:   N number of blocks in the file (NN NN)
#        Byte 5-EOF: Blocks of the form:
#                  BLOCK_SIZE      Byte 1: X number of bytes in block excluding
#                                          this byte. (XX)
#                  ADDRESS_OFFSET  Byte 2-3: Original address offset of the
#                                            first data byte. (AD DR)
#                  DATA_BYTES      Byte 4-X: Firmware data bytes (DD)
#
#        Example file output:
#           01 03 00 01 06 80 00 6a 14 31 80
#           MM mm NN NN XX AD DR DD DD DD DD
#
# @param[in] i_fileName    Name of file
# @param[in] i_outputDir   Dir to emit binary to
#
# @return N/A
################################################################################
sub generateFirmwareImage
{
    my ($i_fileName, $i_outputDir) = @_;
    my $this_func = (caller(0))[3];

    my $intermediateFileName = generateIntermediateImage($i_fileName,$i_outputDir);

    open my $inputFileHandle, '<:encoding(UTF-8)', $intermediateFileName
        or die "Failed to open $intermediateFileName";

    my ($name, @version) = generateOutputNameAndVersion($i_fileName);

    my $imageFile = $i_outputDir . "/" . $name . "FW.bin";

    open my $outputFileHandle, '>:raw', $imageFile
        or die "Failed to open $imageFile";

    # Indicates whether or not we're in the firmware section of the image file.
    my $inFirmwareSection = undef;

    # Keep track of the number of blocks we'll be writing to the output file.
    my $numberOfBlocks = 0;

    # This is the starting address of the first byte of the payload data.
    my $currentAddress = 0;

    # The address offsets in the file are prefixed with the @ symbol.
    use constant ADDRESS_LINE => "\@";
    use constant FW_START_ADDRESS_8000 => "\@8000";
    use constant FW_START_ADDRESS_A000 => "\@A000";

    # Spec for BPM updates says that the maximum size for the data portion of
    # the payload is 16 bytes
    use constant MAXIMUM_DATA_BYTES_FOR_PAYLOAD => 16;

    # Ensure that the diamond operator ( <> ) is searching for \n to determine
    # where the end of a line is in the image file.
    local $/ = "\n";

    my $blocks = undef;
    while (my $line = <$inputFileHandle>)
    {
        # Strip off the end-of-line character \n and optionally \r if it exists.
        # Since the image files were created on a windows OS and this script
        # runs on linux this will not be handled properly by chomp.
        $line =~ s/\r?\n$//;

        # The end of the firmware data section is marked by a 'q'
        if (substr($line, 0, 1) eq "q")
        {
            last;
        }

        # There are two possible addresses where the firmware data section can
        # start: @8000 or @A000. Ignore all data until we reach either of those
        # addresses since it's only after that, that the firmware data begins.
        if (substr($line, 0, 1) eq ADDRESS_LINE)
        {
            $currentAddress = hex substr($line, 1, 4);
            if ($verbose)
            {
                printf("Found address offset: 0x%04x\n", $currentAddress);
            }

            if (  ($line eq FW_START_ADDRESS_8000)
               || ($line eq FW_START_ADDRESS_A000))
            {
                $inFirmwareSection = 1;
            }
            next;
        }

        # Don't process lines that aren't firmware data.
        if (not $inFirmwareSection)
        {
            next;
        }

        # Process the line into blocks of the form: size, address offset, bytes
        # Size: The size of the block.
        #  Note: The size here is only the size of the block itself. It does not
        #  have any correspondence to the final payload size which will be
        #  calculated during payload construction in hostboot code.
        # Address offset: The address offset of the first byte of payload data.
        #                 This will be reused during payload construction in
        #                 hostboot code.
        # Bytes: The payload data. This is the firmware data to be written to
        #        the BPM.

        # The length of the payload data. The maximum size of payload data is 16
        # bytes which is conveniently the maximum size of any line in the file
        # minus spaces and carriage return/line feeds.
        my $dataLength = calculateDataLength($line);

        if ($dataLength > MAXIMUM_DATA_BYTES_FOR_PAYLOAD)
        {
            die "$dataLength exceeds the maximum size for the data portion of" .
                "the payload (". MAXIMUM_DATA_BYTES_FOR_PAYLOAD .")";
        }

        # total size of the block is the number of bytes from the dataLength
        # plus two more for the address size.
        my $blockSize = $dataLength + 2;

        # Pack the block size
        # uint8_t
        $blocks .= pack("C", $blockSize);

        # Pack the starting address offset of the firmware data bytes
        # uint16_t
        $blocks .= pack("n",  $currentAddress);

        # Pack the payload data.
        # Since the line is a string where each byte is an ASCII representation
        # of the hex data separated by spaces, we must split the line by the
        # space character and then write each byte string one at a time. Hence,
        # the template "(H2)*". Each element is processed with the H2 part and
        # the * just says to do this for all elements in the array emitted by
        # split.
        $blocks .= pack("(H2)*", split(/ /, $line));

        # Increment the address offset by the number of firmware data
        # bytes processed.
        $currentAddress += $dataLength;

        ++$numberOfBlocks;
    }

    if ($verbose)
    {
        print "number of blocks: $numberOfBlocks\n";
    }

    if (!defined($blocks))
    {
        die "Unable to process image file: $intermediateFileName";
    }

    # Write the version information to the file.
    print $outputFileHandle pack("(H2)*", @version)
        or die "Failed to write to output file: $imageFile";

    # Write the number of blocks in the file.
    # uint16_t
    print $outputFileHandle pack("n", $numberOfBlocks)
        or die "Failed to write to output file: $imageFile";

    # Write the blocks to the file
    print $outputFileHandle $blocks
        or die "Failed to write to output file: $imageFile";

    close $inputFileHandle
        or die "Failed to close input file: $intermediateFileName";
    unlink $intermediateFileName
        or die "Failed to remove temporary file $intermediateFileName";
    close $outputFileHandle
        or die "Failed to close output file: $imageFile";
}

################################################################################
# @brief Processes an input file to pull information from its name and content
#        to be used when preparing the output file's binary image. This function
#        will only emit the binaries for the configuration data portion of the
#        BPM update.
#        The final binary will be organized in the following way:
#        Byte 1:     Major version number (MM), in hex representation of decimal
#        Byte 2:     Minor version number (mm), in hex representation of decimal
#        Byte 3:     N number of fragments in the file (NN)
#        Byte 4-EOF: Fragments of the form:
#                  FRAGMENT_SIZE   Byte 1:   X number of bytes in fragment data
#                                            section. (XX)
#                  INDEX_OFFSET    Byte 2-3: Each BPM's config section is unique
#                                            to itself. So, during update the
#                                            contents of a BPM's config data
#                                            will be dumped into a buffer.
#                                            These bytes will be used as an
#                                            offset into that buffer from which
#                                            overwritting will take place.
#                                            (IN DX)
#                  DATA_BYTES      Byte 4-X: Configuration data bytes (DD)
#
#        Example file output:
#           01 05 01 04 01 28 6a 14 31 80
#           MM mm NN XX IN DX DD DD DD DD
#
# @algorithm    Each BPM has a config data section unique to itself so the data
#               on each BPM must be dumped into a buffer and then "merged" with
#               the config data from the update. The config data section is
#               divided into 4 segments. A, B, C, and D. These segments appear
#               in reverse order. Since it is known which "fragments" of each
#               segment has to be updated this function will extract those
#               fragments from the update file and organize them as described
#               above so that hostboot can handle the rest.
#
# SegmentDataFromBPM:     Copy of the segment data taken from the BPM (dump)
#
# SegmentDataFromFWImage: Copy of the segment data from the firmware image file.
#                         This could be the firmware image to be upgraded to or
#                         to be downgraded to. These are what will become
#                         fragments.
#
# Segment  Address         Data Source
# =====================================
# D        1800 - 187F     <---- [SegmentDataFromFWImage: 1800 - 187F]
#
# C        1880 - 18FF     <---- [SegmentDataFromBPM: 1880 - 18FF]
#
# B        1900 - 197F     <---- [SegmentDataFromBPM:     1900 - 1927]
#                                [SegmentDataFromFWImage: 1928 - 1979]
#                                [SegmentDataFromBPM:     197A - 197D]
#                                [SegmentDataFromFWImage: 197E - 197F]
#
# A        1980 - 19FF     <---- [SegmentDataFromBPM: 1980 - 19FF]
#
# @param[in] i_fileName    Name of file
# @param[in] i_outputDir   Dir to emit binary to
#
# @return N/A
################################################################################
sub generateConfigImage
{
    my ($i_fileName, $i_outputDir) = @_;
    my $this_func = (caller(0))[3];

    open my $inputFileHandle, '<:encoding(UTF-8)', $i_fileName
        or die "Failed to open $i_fileName";

    my ($name, @version) = generateOutputNameAndVersion($i_fileName);

    my $imageFile = $i_outputDir . "/" . $name . "CONFIG.bin";

    open my $outputFileHandle, '>:raw', $imageFile
        or die "Failed to open $imageFile";

    # Indicates whether or not we're in the config section of the image file.
    my $inConfigSection = undef;

    # Keep track of the number of fragments we'll be writing to the output file.
    my $numberOfFragments = 0;

    # Used to keep track of which byte is the current byte being looked at in
    # the file.
    my $currentAddress = 0;

    # The address offsets in the file are prefixed with the @ symbol.
    use constant ADDRESS_LINE => "\@";
    use constant CONFIG_START_ADDRESS_MARKER => "\@1800";
    use constant CONFIG_START_ADDRESS => 0x1800;

    # Segment data start addresses relative to config data start address.
    use constant SEGMENT_D_START_ADDRESS => 0x000;
    use constant SEGMENT_C_START_ADDRESS => 0x080;
    use constant SEGMENT_B_START_ADDRESS => 0x100;
    use constant SEGMENT_A_START_ADDRESS => 0x180;

    # Spec for BPM updates says that the maximum size for the data portion of
    # the payload is 16 bytes
    use constant MAXIMUM_DATA_BYTES_FOR_PAYLOAD => 16;

    my $fragments = undef;
    my $fragmentData = undef;
    my $fragmentSize = 0;

    # The offset into the segment data where the fragment data will be written.
    # In hostboot code, this will be a 512 byte buffer that holds a dump of the
    # BPM's unique segment data.
    my $fragmentOffset = SEGMENT_D_START_ADDRESS;

    # Ensure that the diamond operator ( <> ) is searching for \n to determine
    # where the end of a line is in the image file.
    local $/ = "\n";

    while (my $line = <$inputFileHandle>)
    {
        # Strip off the end-of-line character \n and optionally \r if it exists.
        # Since the image files were created on a windows OS and this script
        # runs on linux this will not be handled properly by chomp.
        $line =~ s/\r?\n$//;

        # Look for @1800 starting address marker.
        #
        # If found, start reading the data from the file until the next "@"
        # marker or "q" starting markers are found.
        #
        # It is possible that the input file might not have the distinct @1800
        # marker. In that case, the [currentAddress] variable is used to track
        # the 0x1800 address in the input file.
        if (substr($line, 0, 1) eq "q")
        {
            last;
        }

        if (substr($line, 0, 1) eq ADDRESS_LINE)
        {
            $currentAddress = hex substr($line, 1);
            if ($verbose)
            {
                printf("Found address offset: 0x%04x\n", $currentAddress);
            }

            if ($line eq CONFIG_START_ADDRESS_MARKER)
            {
                $inConfigSection = 1;
            }
            next;
        }

        # Process the line into fragments of the form: size, address offset,
        # and bytes.
        #
        # Size: The size of the fragment data.
        #       Note: The size only corresponds to the size of the fragment data
        #       itself. In hostboot code, this size will indicate how much of
        #       the BPM's segment data will be overwritten for the given
        #       fragment.
        # Address offset: The address offset of the start byte of segment data.
        #                 This will be used to determine where to start
        #                 overwritting segment data from the BPM config dump.
        # Bytes: The bytes to write to the BPM config data dump buffer.

        # The length of the line. The maximum size of any line is 16 bytes.
        my $dataLength = calculateDataLength($line);

        if ($dataLength > MAXIMUM_DATA_BYTES_FOR_PAYLOAD)
        {
            die "$dataLength exceeds the maximum size for the data portion of" .
                "the payload (". MAXIMUM_DATA_BYTES_FOR_PAYLOAD .")";
        }

        # If the CONFIG_START_ADDRESS_MARKER is missing from the file then this
        # will serve as the backup method to locating the config data within the
        # image file. Otherwise, this will always evaluate to false.
        if (($currentAddress + $dataLength) == CONFIG_START_ADDRESS)
        {
            # The next line is the start of the config data section of the
            # image. So, skip the current line and move into the config section.
            $inConfigSection = 1;
            $currentAddress += $dataLength;
            next;
        }

        # Don't process lines that aren't config data.
        if (not $inConfigSection)
        {
            next;
        }

        # Create Segment D fragment. For Segment D, the entire segment is
        # required to be updated during the firmware update. So, create a
        # fragment that encompasses the whole segment.
        if ($currentAddress < CONFIG_START_ADDRESS + SEGMENT_C_START_ADDRESS)
        {
            # Increase the fragmentSize by the amount being appended to the
            # fragment.
            $fragmentSize += $dataLength;

            # Pack the fragment data.
            # Since the line is a string where each byte is an ASCII
            # representation of the hex data separated by spaces, we
            # must split the line by the space character and then write
            # each byte string one at a time. Hence, the template
            # "(H2)*". Each element is processed with the H2 part and
            # the * just says to do this for all elements in the array
            # emitted by split.
            $fragmentData .= pack("(H2)*", split(/ /, $line));

            if($currentAddress ==
                (CONFIG_START_ADDRESS + SEGMENT_C_START_ADDRESS - 0x10))
            {
                $fragments .= createFragment($fragmentSize,
                                             $fragmentOffset,
                                             $fragmentData,
                                             $numberOfFragments);
            }
        }
        # Segment C is skipped over implicitly since there is no segment data in
        # segment C that needs to be applied to the BPM.
        elsif (   ($currentAddress >=
                  (CONFIG_START_ADDRESS + SEGMENT_B_START_ADDRESS))
               && ($currentAddress <
                  (CONFIG_START_ADDRESS + SEGMENT_A_START_ADDRESS)))
        {
            # Work on Segment B data. There will be two fragments created for
            # this segment.
            # Fragment 1: [0x1928 - 0x1979]
            # Fragment 2: [0x197E - 0x197F]
            my $createFragment = 0;

            # According to SMART's documentation, each segment must be 8 lines
            # of 16 byte rows. Since we are searching for a specific region in
            # segment B to create a fragment from we bound the fragment packing
            # code by the borders of that region.
            if (   ($currentAddress >=
                    (CONFIG_START_ADDRESS + SEGMENT_B_START_ADDRESS + 0x20))
                && ($currentAddress <
                    (CONFIG_START_ADDRESS + SEGMENT_B_START_ADDRESS + 0x80)))
            {
                # Only need bytes from [0x1928 to 0x1979] to form Fragment 1.
                # If we are not on the bounds of the fragment then we can simply
                # pack the data and update the size.
                # Otherwise, we must do some extra trimming.
                if ($currentAddress ==
                    (CONFIG_START_ADDRESS + SEGMENT_B_START_ADDRESS + 0x20))
                {
                    # This is the begining of Fragment 1's range. Trim off the
                    # bytes with offsets less than 0x1928.

                    # Set the fragmentOffset to the start of the range
                    $fragmentOffset = SEGMENT_B_START_ADDRESS
                                    + 0x28;

                    # Split the line into individual bytes and only pack
                    # required bytes.
                    my @bytes = split(/ /, $line);

                    # Drop the first eight bytes since they aren't in the range.
                    splice @bytes, 0, 8;

                    $fragmentSize += scalar @bytes;

                    $fragmentData .= pack("(H2)*", @bytes);

                    # Since this is the begining of Fragment 1, there is still
                    # data left to be appended to this fragment. So don't call
                    # createFragment().
                }
                elsif ($currentAddress ==
                        (CONFIG_START_ADDRESS + SEGMENT_B_START_ADDRESS + 0x70))
                {
                    # This is the last line in the range of Fragment 1 and the
                    # only line where Fragment 2 data is. So, trimming is
                    # required to finalize Fragment 1 and create Fragment 2.

                    # Start by finishing off Fragment 1.
                    # Split the line into individual bytes and only pack
                    # required bytes.
                    my @bytes = split(/ /, $line);

                    # Drop the last six bytes since they aren't
                    # in range [0x1928-0x1979]
                    splice @bytes, 10, 6;

                    $fragmentSize += scalar @bytes;

                    $fragmentData .= pack("(H2)*", @bytes);

                    # Now that Fragment 1 is completed, create the fragment and
                    # append it to the list of fragments.
                    $fragments .= createFragment($fragmentSize,
                                                 $fragmentOffset,
                                                 $fragmentData,
                                                 $numberOfFragments);

                    # Now work on Fragment 2.
                    # Only need bytes from [0x197E to 0x197F] to form Fragment 2

                    # Set the fragmentOffset
                    $fragmentOffset = SEGMENT_B_START_ADDRESS
                                    + 0x7E;

                    # Split the line into individual bytes and only pack
                    # required bytes.
                    @bytes = split(/ /, $line);

                    # Drop the first 14 bytes since they aren't in
                    # range [0x197E to 0x197F]
                    splice @bytes, 0, 14;

                    $fragmentSize += scalar @bytes;

                    $fragmentData .= pack("(H2)*", @bytes);

                    # Fragment 2 is complete. Create the fragment and append to
                    # list of fragments.
                    $fragments .= createFragment($fragmentSize,
                                                 $fragmentOffset,
                                                 $fragmentData,
                                                 $numberOfFragments);

                }
                else
                {
                    # We are not on a fragment boundary, so append the full line
                    # of data to Fragment 1.

                    # Increase the fragmentSize by the amount being appended to
                    # the fragment.
                    $fragmentSize += $dataLength;

                    # Pack the fragment data.
                    # Since the line is a string where each byte is an ASCII
                    # representation of the hex data separated by spaces, we
                    # must split the line by the space character and then write
                    # each byte string one at a time. Hence, the template
                    # "(H2)*". Each element is processed with the H2 part and
                    # the * just says to do this for all elements in the array
                    # emitted by split.
                    $fragmentData .= pack("(H2)*", split(/ /, $line));
                }
            }
        }
        elsif ($currentAddress >=
                  (CONFIG_START_ADDRESS + SEGMENT_A_START_ADDRESS))
        {
            # Don't need to create fragments in Segment A.
            last;
        }

        # Increment the address offset by the number of firmware data
        # bytes processed.
        $currentAddress += $dataLength;
    }

    if ($verbose)
    {
        print "number of fragments: $numberOfFragments\n";
    }

    if (!defined($fragments))
    {
        die "Unable to process image file: $i_fileName";
    }

    # Write the version information to the file.
    print $outputFileHandle pack("(H2)*", @version)
        or die "Failed to write to output file: $imageFile";

    # Write the number of fragments in the file.
    # uint16_t
    print $outputFileHandle pack("n", $numberOfFragments)
        or die "Failed to write to output file: $imageFile";

    # Write the fragments to the file
    print $outputFileHandle $fragments
        or die "Failed to write to output file: $imageFile";

    close $inputFileHandle
        or die "Failed to close input file: $i_fileName";
    close $outputFileHandle
        or die "Failed to close output file: $imageFile";
}

################################################################################
# @brief Transforms the input file name into the output file name and extracts
#        the version info from the file name since that info is not present in
#        the image file itself.
#
# @param[in] i_fileName    Name of file
#
# @return                  An array that contains the filename as the first
#                          element and the version info array as the second.
################################################################################
sub generateOutputNameAndVersion
{
    # Input Parameter
    my $i_fileName = shift;

    # Parse the file name into its filename, path, and suffix.
    my ($name, $path, $suffix) = fileparse($i_fileName, ".txt");

    # Split the filename by underscore to access the information contained in
    # the file name.
    # According to the spec an example filename would be of the form:
    # S R C A80 6 2 IBM H 01 1 B _FULL_ FW_Rev1.03_02282019.txt
    #                        ^    ^        ^
    # 1: Number of NVDIMM interfaces (1 = 32GB, 2 = 16GB)
    # _FULL_: The image contains the firmware and configuration data.
    # Rev1.03: Version of this image file
    my @fileNameComponents = split(/_/, $name);

    # The NVDIMM interface types supported
    my %nvdimmTypes = ( 1 => "32GB",
                        2 => "16GB", );

    # Extract the NVDIMM Interface number from filename
    my $nvdimmInterfaceNumber = substr($fileNameComponents[0], -2, 1);

    # Convert interface number to the appropriate human-readable type
    my $nvdimmType = "";
    if (exists($nvdimmTypes{$nvdimmInterfaceNumber}))
    {
        $nvdimmType = $nvdimmTypes{$nvdimmInterfaceNumber};
    }
    else
    {
        die "NVDIMM Interface Type $nvdimmInterfaceNumber Unsupported";
    }

    # Extract the version from the filename and convert each half into
    # a decimal number.  Note that this value will be stored as a hex
    # value in the binary, e.g. v1.11 = 0x0111 not 0x010B
    my @versionComponents = split(/\./, $name);
    my @version =
        sprintf("%.2d", substr($versionComponents[0], -2, 2) =~ /([0-9]+)/g);
    push(@version,
        sprintf("%.2d", substr($versionComponents[1], 0, 2) =~ /([0-9]+)/g));


    if ($verbose)
    {
        print "\tNVDIMM Type -> ". $nvdimmType ."\n";
        print "\tVersion Info -> Major: " . $version[0] .
                               " Minor: " . $version[1] . "\n";
    }

    return ($nvdimmType."-NVDIMM-BPM-", @version);

}

################################################################################
# @brief Processes input image file to generate CRC signature, firmware start
#        address, and calculated CRC bytes at address marker @FF7A. This
#        function simply calls SMART's supplied python script to perform the
#        operations. This intermediate file is only used during the firmware
#        binary generation.
#
# @param[in] i_fileName    Name of file
#
# @return    txt file name The temporary file that has the calculated CRC
################################################################################
sub generateIntermediateImage
{
    my ($i_fileName, $i_outputDir) = @_;

    # Parse the file name into its filename, path, and suffix.
    my ($name, $path, $suffix) = fileparse($i_fileName, ".txt");

    # Parse the file name into its filename, path, and suffix.
    my ($utilName, $utilPath, $utilSuffix) = fileparse($bpmUtilScript, ".txt");

    my $intermediateFileName = $i_outputDir . $name . ".crc";

    # Call the python script which will insert the CRC
    my $pythonReturn = system($bpmUtilScript,
                              $i_fileName,
                              $intermediateFileName,
                              $bpmCrcProgram);

    return $intermediateFileName;

}

################################################################################
# @brief Creates a new fragment by packing the fragment size, offset, and data;
#        then it cleans up the fragment parameters so that the caller doesn't
#        have to.
#
# @param[in] io_fragmentSize        The size of the fragment data section.
# @param[in] i_fragmentOffset       The offset into the BPM config dump buffer
#                                   that this fragment should begin overwritting
#                                   at.
# @param[in] io_fragmentData        The partial config segment data from the
#                                   flash image to be written to the BPM during
#                                   the update procedure.
# @param[in] io_numberOfFragments   This parameter incremented by this function
#                                   so the caller can keep track of how many
#                                   fragments have been created so far. However,
#                                   due to the messiness of perl syntax this
#                                   parameter is created as a visual reference
#                                   only and not used directly.
#
# @return                           The created fragment
################################################################################
sub createFragment
{
    my ($io_fragmentSize,
        $i_fragmentOffset,
        $io_fragmentData,
        $io_numberOfFragments) = @_;

    # Pack the fragment size
    # uint8_t
    my $fragment .= pack("C", $io_fragmentSize);

    # Pack the BPM dump offset.
    # uint16_t
    $fragment .= pack("n", $i_fragmentOffset);

    # Pack the fragment data
    $fragment .= $io_fragmentData;

    # Keep track of number of fragments in output
    $_[3]++;       # $io_numberOfFragments

    # Reset variables
    $_[2] = undef; # $io_fragmentData
    $_[0] = 0;     # $io_fragmentSize

    return $fragment;
}

################################################################################
# @brief Calculates the data length of the line by stripping all spaces for it
#        dividing by the number of bytes on the line.
#
# @param[in] i_line        The line to calculate the length on.
#
# @return                  The number of bytes on the line (length).
################################################################################
sub calculateDataLength
{
    my $i_line = shift;

    # Strip all the spaces from the line.
    $i_line =~ s/\s+//g;

    # Each line is plain text where each byte is separated by spaces.
    # To determine how many bytes are on the line, divide by characters per byte
    use constant CHARS_PER_BYTE => 2;
    my $dataLength = length($i_line) / CHARS_PER_BYTE;

    return $dataLength;
}

__END__

=head1 NAME

buildBpmFlashImage.pl

=head1 SYNOPSIS

buildBpmFlashImage.pl [..]

=head1 OPTIONS

=over 8

=item B<--help>

Prints a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--output-dir>

Path to directory to emit the output files to.

=item B<--image>

File containing a BPM flash update script.  More than one --image
argument can be provided.  If no images are supplied, the script will do
nothing.

=back

=head1 DESCRIPTION

B<buildBpmFlashImage.pl> will process a set of one or more BPM flash update
scripts in .txt format by transforming the lines of text into blocks of binary
data of the form BLOCK_SIZE, ADDRESS_OFFSET, PAYLOAD. The final binary output by
this script will have the first 2 bytes be the version info (first byte Major,
second Minor), then followed by two bytes that give the number of blocks in the
file, and the remainder of the file will be blocks organized in the following
way:

BLOCK_SIZE is the number of bytes following the BLOCK_SIZE byte.
ADDRESS_OFFSET is the offset the PAYLOAD data originally came from within the .txt file.
PAYLOAD is the data, along with the ADDRESS_OFFSET, that will be used to construct the payloads to send to the BPM to perform the update.

=cut
