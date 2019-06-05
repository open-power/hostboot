#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/buildBpmFlashImages.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019
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
my @files;
my $cfgHelp=0;
my $cfgMan=0;
my $verbose=0;

GetOptions("output-dir=s" => \$outputDir,
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

    generateFirmwareImage($file,$outputDir);
}

################################################################################
# @brief Processes an input file to pull information from its name and content
#        to be used when preparing the output file's binary image. This function
#        will only emit the binaries for the firmware portion of the BPM update.
#        The final binary will be organized in the following way:
#        Byte 1:     Major version number (MM)
#        Byte 2:     Minor version number (mm)
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
# @param[in] i_outputDir   Dir to emit intermediate file to
#
# @return N/A
################################################################################

sub generateFirmwareImage
{
    my ($i_fileName, $i_outputDir) = @_;
    my $this_func = (caller(0))[3];

    open my $inputFileHandle, '<:encoding(UTF-8)', $i_fileName
        or die "Failed to open $i_fileName";

    my ($name, @version) = generateOutputNameAndVersion($i_fileName);

    my $imageFile = $i_outputDir . "/" . $name . ".bin";

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

    # Each line is plain text where each byte is separated by spaces.
    # To determine how many bytes are on the line divide by characters per byte
    # and number of spaces between bytes. 2 characters per byte + 1 space = 3
    use constant BYTES_PER_LINE_EXCLUDING_SPACES => 3;

    # Spec for BPM updates says that the maximum size for the data portion of
    # the payload is 16 bytes
    use constant MAXIMUM_DATA_BYTES_FOR_PAYLOAD => 16;

    # images use carriage return which by default chomp doesn't remove so update
    # local $/ to remove that character.
    local $/ = "\r\n";

    my $blocks = undef;
    while (my $line = <$inputFileHandle>)
    {
        chomp($line);

        # The end of the firmware data section is marked by a 'q'
        if (substr($line, 0, 1) eq "q")
        {
            last;
        }

        # Ignore data from addresses below @8000 because the firmware data
        # only begins from @8000 onward.
        if (substr($line, 0, 1) eq ADDRESS_LINE)
        {
            $currentAddress = hex substr($line, 1, 4);
            if ($verbose)
            {
                printf("Found address offset: 0x%04x\n", $currentAddress);
            }

            if ($line eq "\@8000")
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
        my $dataLength = length($line) / BYTES_PER_LINE_EXCLUDING_SPACES;

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

    close $inputFileHandle or die "Failed to close input file: $i_fileName";
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
    # 1: Number of NVDIMM interfaces (1 = 36GB, 2 = 16GB)
    # _FULL_: The image contains the firmware and configuration data.
    # Rev1.03: Version of this image file
    my @fileNameComponents = split(/_/, $name);

    # The NVDIMM interface types supported
    my %nvdimmTypes = ( 1 => "36GB",
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

    # Extract the version from the filename and convert it to a hex string.
    my @version = map { sprintf("%.2X", $_) }
        $fileNameComponents[3] =~ /([0-9]+)/g;

    if ($verbose)
    {
        print "\tNVDIMM Type -> ". $nvdimmType ."\n";
        print "\tVersion Info -> Major: " . $version[0] .
                               " Minor: " . $version[1] . "\n";
    }

    return ($nvdimmType."-NVDIMM-BPM-FW", @version);

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
