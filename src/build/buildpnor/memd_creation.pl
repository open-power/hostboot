#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/memd_creation.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017
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
use Pod::Usage;
use Getopt::Long qw(:config pass_through);
use strict;
use File::Basename;

### CONSTANTS ###
use constant ROUNDING_DIVISOR => 1000;
use constant HEADER_INPUT_LOCATION => 12;

print "Creating MEMD binary...\n";

# Header format:
#   uint32_t eyecatch        /* Eyecatch to determine validity "OKOK" */
#   uint32_t header_version  /* What version of the header this is in */
#   uint32_t memd_version    /* What version of the MEMD this includes */
#   uint32_t expected_size   /* Size in megabytes of the biggest MEMD section */
#   uint16_t expected_num    /* Number of MEMD instances in this section */

my $memd_dir = "";
my $memd_output = "";
my $help = 0;
my $man = 0;

GetOptions(
    "memd_dir=s" => \$memd_dir,
    "memd_output=s" => \$memd_output,
    "help" => \$help,
    "man" => \$man) || pod2usage(-verbose=>0);

pod2usage(-verbose => 1) if $help;
pod2usage(-verbose => 2) if $man;

# Find files
my @memd_files = glob($memd_dir . '/*');

# Get the max file size - offset for each file binary
my $max_file_size = 0;
foreach my $file (@memd_files)
{
    my $cur_size = (stat $file)[7];
    if($cur_size > $max_file_size)
    {
        $max_file_size = $cur_size;
    }
}
$max_file_size /= ROUNDING_DIVISOR;
$max_file_size = int($max_file_size) + 1;

# Get the number of files - (expected_num)
my $number_of_files = scalar(@memd_files);

# Generate header - add to file
my $header = "OKOK";      # shows that the memd partition is valid
$header .= "01.0";        # current metadata header version
$header .= "01.0";        # current memd version
$header .= "0000";        # expected size of each memd blob (in KB's) placeholder
$header .= "00";          # number of memd instances placeholder
$header .= "00000000";    # padding for the future
$header .= "000000";      # rounding up to 16 bytes

# Create offset
my $offset = length $header;

# Create file
open(my $fh, '>', $memd_output) or die "Could not open file '$memd_output' $!";
print $fh $header;

# Add in the actual size and the number of memd instances
seek($fh, HEADER_INPUT_LOCATION, 0);
my $size_bin = pack('N', $max_file_size);
print $fh $size_bin;
my $num_bin = pack('n', $number_of_files);
print $fh $num_bin;

# Every max file size - rounded to an even number + headersize.
#   Read in the MEMD binary, and concatenate to this file.
foreach my $file (@memd_files)
{
    # Checking that first byte equals "84"
    # The VPD spec has '84' as their first byte for a record, however it is
    # not needed for the hostboot structure to add in into the VPD structure,
    # so we remove it here before creating the MEMD binary
    my $first_byte = `head -c 1 $file`;
    die "System command failed: $?" if $?;

    $first_byte =~ s/(.)/sprintf("%x",ord($1))/eg;
    if(!($first_byte == 84))
    {
        die "Incorrect first byte, MEMD file is invalid";
    }

    # Removing the first byte of the MEMD binary
    my $new_file = "$memd_dir/edited_memd.dat";
    run_command("tail -c +2 $file > $new_file");
    run_command("mv $new_file $file");

    seek($fh, $offset, 0);
    print "Writing the file $file...\n";
    open(my $in_file, '<', $file) or die "Could not open file '$file' $!";

    while ( <$in_file> )
    {
        print $fh $_;
    }
    close $in_file;
    $offset = $offset + ($max_file_size * ROUNDING_DIVISOR);
}


close $fh;
print "Done. Memd binary is $memd_output.\n";

############### HELPER FUNCTIONS ############################
# Function to first print, and then run a system command. Erroring out if the
#  command does not complete successfully
sub run_command {
    my $command = shift;
    print "$command\n";
    my $rc = system($command);
    if ($rc != 0){
        die "Error running command: $command. Nonzero return code of ($rc) returned.\n";
    }
    return $rc;
}

# Function to remove leading and trailing whitespace before returning that string
sub trim_string {
    my $str = shift;
    $str =~ s/^\s+//;
    $str =~ s/\s+$//;
    return $str;
}

__END__

=head1 NAME

memd_creation.pl

=head1 SYNOPSIS

memd_creation.pl
    --memd_dir=DATA_DIRECTORY
    --memd_output=DATA_OUTPUT_NAME

=item B<--help>

Prints a brief help message and exits

=item B<--man>

Prints the manual page and exists

=item B<--memd_dir>=DIRECTORY

Directory of MEMD binary files.

=item B<--memd_output>=FILENAME

Location and name of the resulting output binary.

=head1 DESCRIPTION

B<memd_creation.pl> will generate a binary image for the MEMD
section of the PNOR.  It will generate a header based on the
input binary files and concatenate them together.

=cut

