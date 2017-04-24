#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/eSEL.pl $
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
use strict;
use Cwd;
use POSIX;
use Switch;
use Getopt::Long;
use File::Basename;
use Data::Dumper;
use File::Copy qw(copy);
use Fcntl qw(:seek);

use constant ESEL_HEADER_LENGTH   => 16;
use constant PNOR_ERROR_LENGTH    => 4096;
use constant WORD_5_OFFSET        => 100;
use constant ACK_MASK             => 0x00200000;
use constant EMPTY_ERRLOG_IN_PNOR => "ffffffff";

# options and usage
my $target = '';                        # Target BMC name / IP  (convert to IP)
my $userid = 'ADMIN';                   # BMC user id to use for the ipmitool cmd
my $passwd = 'admin';                   # BMC password to use for the ipmitool cmd
my $dirname = dirname(__FILE__);
my $errl_path = $dirname;
my $fspt_path = $dirname;
my $img_path = $dirname;
my $output_path = cwd();
my $debug = 0;
my $usage = 0;
my $option = "";
my $esel_file = "";
my $bad_option = 0;
my $removeEcc = 0;
my $filterAcked = 0;
my $keepTempFiles = 0;
my @filesToDelete = ();
my $ecc_executable  = "";

my %options_table = (
    get_ami_data => 0,
    decode_ami_data => 0,
    get_and_decode_ami => 0,
    decode_obmc_data => 0,
    decode_hbel_data => 0
);

sub printUsage
{
    print "All directory paths passed as arguments to the tool MUST be Fully qualified path names.\n";
    print "Usage:  eSEL_ami.pl [-h] -t <BMC Name / IP> [-U <userid>] [-P <password>]\n";
    print "                    [-o <output dir>] # default: $output_path\n";
    print "                    [-e <errl dir>] # default: $errl_path(*) \n";
    print "                    [-f <fsp-trace dir>] # default $fspt_path(*)\n";
    print "                    [-i <img dir (for hbotStringFile & hbicore.syms>] # default $img_path(*)\n";
    print "                    [-l <eSEL file>]\n";
    print "                    [-c] # remove ECC before processing the HBEL partition\n";
    print "                    [-r] # filter out ACKed logs from HBEL\n";
    print "                    [-k] # keep the temp files created by the script\n";
    print "                    [--ecc <path>] # path to the ECC executable\n";
    print "                    [-p <option>]\n";
    print "                       where <option> can be one of:\n";
    print "                       get_ami_data (use IPMI to fetch eSEL data into binaries, no decode)\n";
    print "                       decode_ami_data (decode AMI binary eSEL file)\n";
    print "                       get_and_decode_ami (fetch and decode the AMI eSEL data)\n";
    print "                       decode_obmc_data (decode OpenBMC eSEL file)\n";
    print "                       decode_hbel_data (decode HBEL PNOR file).\n";
    print " (*): Alternative to providing the paths to each of the files required, you may set the\n";
    print "      ESEL_PATH environment variable to point to the folder where all of the required\n";
    print "      files are. The script will automatically use that env variable's path.\n";
    print "\n";
    print "This tool will ONLY process hostboot eSEL entries that contain PEL data.\n";
    exit;
}

if (defined $ENV{"ESEL_PATH"})
{
    $errl_path = $fspt_path = $img_path = $ENV{"ESEL_PATH"};
}

GetOptions(
    "t:s" => \$target,
    "U:s" => \$userid,
    "P:s" => \$passwd,
    "e:s" => \$errl_path,
    "f:s" => \$fspt_path,
    "i:s" => \$img_path,
    "o:s" => \$output_path,
    "l:s" => \$esel_file,
    "p:s" => \&HandleOption,
    "c+"  => \$removeEcc,
    "r+"  => \$filterAcked,
    "k+"  => \$keepTempFiles,
    "ecc:s" => \$ecc_executable,
    "v+" => \$debug,
    "h" => \$usage,
    ) || printUsage();

if ($usage)
{
    printUsage();
    exit;
}

if ($bad_option)
{
    print "***ERROR: Incorrect option provided.\n";
    print "Specify an option with -p <option>.\n\n";
    printUsage();
    exit -1;
}

if (($options_table{"decode_ami_data"} or $options_table{"decode_obmc_data"})
      and $esel_file eq "")
{
    print "***ERROR: No input file provided for decode mode.\n";
    print "Please specify an input file with eSEL data.\n\n";
    printUsage();
    exit -1;
}

if($ecc_executable eq "")
{
    $ecc_executable = "/afs/awd.austin.ibm.com/projects/eclipz/lab/p8/gsiexe/ecc";
}

#################################
# Variables used for the script #
#################################
my $cmd = '';                           # Used to store the ipmitool commands
my $string_file = '';
my $cd_syms_dir = '';
my $log_file = '';
my @eSEL_lengths;                   # size of each eSEL
my $esel_file_name = basename($esel_file);
###############################################################
# Add code to check that we have the needed fields filled in. #
# Not applicable if the eSEL file is provided.                #
###############################################################
if($options_table{"get_ami_data"} or $options_table{"get_and_decode_ami"})
{
    ($target)     || die "Missing BMC target name / IP\n";
    ($userid)     || die "Missing BMC user id\n";
    ($passwd)     || die "Missing BMC password\n";
}

# We don't need the following files in get_ami mode.
if (!$options_table{"get_ami_data"})
{
    # check if we can find the fsp-trace program
    if (-e "$fspt_path/fsp-trace")
    {
        # it's good, build PATH so errl can find it.
        $fspt_path = "PATH=$fspt_path:\$PATH";
    }
    else
    {
        print "can't find fsp-trace in \"$fspt_path\"; no fsp-traces\n";
        $fspt_path = "";
    }

    $img_path = glob($img_path);
    # check if we can get to the string file
    if (-e "$img_path/hbotStringFile")
    {
        # it's good, build errl option
        $string_file = "-t $img_path/hbotStringFile";
    }
    else
    {
        print "can't find hbotStringFile in \"$img_path\"; incomplete fsp-traces\n";
        $string_file = "";
    }

    # check if we can find a syms file (for backtrace decoding)
    if (-e "$img_path/hbicore.syms")
    {
        # it's good, build cd option
        $cd_syms_dir = "cd $img_path &&";
    }
    else
    {
        print "can't find hbicore.syms in \"$img_path\"; no backtrace resolution\n";
        $cd_syms_dir = "";
    }
}

if ($debug > 0)
{
    print "target: \"$target\"\n";
    print "userid: \"$userid\"\n";
    print "passwd: \"$passwd\"\n";
    print "errl_path: \"$errl_path\"\n";
    print "fspt_path: \"$fspt_path\"\n";
    print "img_path: \"$img_path\"\n";
    print "output_path: \"$output_path\"\n";
    print "debug: $debug\n";
    print "string_file: $string_file\n";
    print "cd_syms_dir: $cd_syms_dir\n";
    print "eSEL file: $esel_file\n";
    print "ECC executable: $ecc_executable\n";
    print "options:\n";
    print Dumper \%options_table;
    print "\n";
}

#########################################################################################
#                                     Main body                                         #
#########################################################################################

# get_and_decode_ami and decode_obmc_data need to create binary files of format
# $log_file.binary.
if ($options_table{"get_ami_data"})
{
    GetAmiEselData(); #makes log_file
}
elsif ($options_table{"decode_ami_data"})
{
    DecodeBinarySelData();
}
elsif ($options_table{"get_and_decode_ami"})
{
    GetAmiEselData();
    DecodeBinarySelData();
}
elsif ($options_table{"decode_obmc_data"})
{
    DecodeObmcEselData();
    DecodeBinarySelData();
}
elsif ($options_table{"decode_hbel_data"})
{
    if($removeEcc)
    {
        RemoveEccFromFile();
    }
    else
    {
        print "Remove ECC option was not given. ECC will not be removed.\n";
    }

    if($filterAcked)
    {
        FilterACKedLogs();
    }

    DecodeBinarySelData();
}
else
{
    print "***ERROR: No option (-p) specified.\n";
    printUsage();
    exit -1;
}

if(not $keepTempFiles)
{
    if(@filesToDelete)
    {
        unlink @filesToDelete or warn "Unable to remove temp files: $!\n";
    }
}

# all done
exit;

#########################################################################################
#                                   Functions                                           #
#########################################################################################
sub HandleOption
{
    my ($opt, $key) = @_;
    ($debug) && print "OPTION: $opt KEY: $key\n";
    if(!exists $options_table{$key})
    {
        $bad_option = 1;
    }
    else
    {
        $options_table{$key} = 1;
    }
    ($debug) && print Dumper \%options_table;
}

sub FilterACKedLogs
{
    my $fileSize = -s $esel_file;
    my $numErrors = $fileSize / PNOR_ERROR_LENGTH;
    my $data = "";

    #Create a file where we would put the unacked errors.
    #This way we preserve the original file.
    open(my $tmpFileHandle, '>>', $esel_file.".tmp")
        or die "Unable to create a temp file\n";
    open(my $eselFileHandle, '<', $esel_file)
        or die "Unable to open the eSEL file\n";

    binmode($eselFileHandle);
    binmode($tmpFileHandle);

    ($debug) && print "Input file size: $fileSize\n";
    ($debug) && print "The file contains $numErrors errors\n";

    for(my $i = 0; $i < $numErrors; $i++)
    {
        my $offset = PNOR_ERROR_LENGTH * $i + WORD_5_OFFSET;
        #Get the word 5 from the ith error (it contains the
        #ACKed bit). Get 4 bytes to apply the mask directly
        my $word5 = qx/xxd -p -seek $offset -l 4 $esel_file/;
        if($?)
        {
            print "WARNING: Could not read word5
                             at offset $offset: $!\n.";
            next;
        }
        chomp($word5);

        ($debug) && print "Error $i word5: $word5.\n";

        if($word5 ne EMPTY_ERRLOG_IN_PNOR)
        {
            my $word5val = hex($word5);
            ($debug) && print "ACKed bit: ", ($word5val & ACK_MASK), " \n";

            if(($word5val & ACK_MASK) ne 0) #Error not ACKed
            {
                #Copy the current error to the temp file for further processing
                sysseek($eselFileHandle, PNOR_ERROR_LENGTH * $i, SEEK_SET)
                        or die "Unable to find specified offset\n";
                sysread($eselFileHandle, $data, PNOR_ERROR_LENGTH)
                        or die "Unable to read at specified offset\n";
                ($debug) && print "Error $i: ", ord($data), "\n";
                print $tmpFileHandle $data;
            }
        }
    }

    close $tmpFileHandle;
    close $eselFileHandle;

    #Point the script to the new file we created above.
    $esel_file = $esel_file.".tmp";
    push @filesToDelete, $esel_file;
}

sub RemoveEccFromFile
{
    my $fileExtension = (split(/\./, basename($esel_file)))[-1];
    ($debug) && print "File extension: $fileExtension\n";
    # The ECC script needs file extension to be ".ecc"
    if($fileExtension ne "ecc")
    {
        ($debug) && print "Creating a .ecc file\n";
        copy $esel_file, $output_path."/".$esel_file_name.".ecc"
             or die "Copy failed: $!\n";
        $esel_file = $output_path."/".$esel_file_name.".ecc";
        push @filesToDelete, $esel_file;
    }

    qx/$ecc_executable -R $esel_file -o $output_path"\/"$esel_file_name".noecc" -p/;
    if($?)
    {
        print "***ERROR: Failed to strip ECC from $esel_file\n";
        exit -1;
    }

    $esel_file = $output_path."/".$esel_file_name.".noecc";
    push @filesToDelete, $esel_file;
}

# open and create errorlog text output file, if possible
sub DecodeBinarySelData
{
    my $txt_file_name = "";
    my $bin_file_name = "";
    if (-e "$errl_path/errl")
    {
        if ($options_table{"decode_ami_data"} or
            $options_table{"decode_hbel_data"})
        {
            # These are the only two modes where eSEL file is not generated
            # according to the script's conventions, so we need to
            # strip the actual eSEL file name and make an output file
            # using that name
            $txt_file_name = "$output_path/$esel_file_name.txt";
            $bin_file_name = $esel_file;
            ($debug) && print " esel_file_name = $esel_file_name.\n";
        }
        else
        {
            # In all other modes the binary files are generated
            # according to the following convention:
            $txt_file_name = "$log_file.txt";
            $bin_file_name = "$log_file.binary";
        }
        ($debug) && print " txt_file_name = $txt_file_name.\n";
        ($debug) && print " bin_file_name = $bin_file_name.\n";
        open TXT_FILE, ">", $txt_file_name or die "Unable to open TXT_FILE $txt_file_name\n";
        print "Error log text file: $txt_file_name\n";

        $cmd = "$cd_syms_dir $fspt_path $errl_path/errl --file=$bin_file_name $string_file -d 2>&1";
        $debug && print "$cmd\n";
        my @txt = qx/$cmd/;                # Execute the command
        print TXT_FILE " @txt";
        ($debug > 1) && print " @txt";

        close TXT_FILE;
    }
    else
    {
        print "can't find errl in $errl_path; no formatted PEL data\n";
    }
}

sub DecodeObmcEselData
{
    # get the name of the actual sel file to make output file name
    $log_file = basename($esel_file);
    my $out_file_bin = "$output_path/$log_file.binary";
    my $pel_data = "";
    my $line_size = 0;
    my $line = "";

    ($debug) && print "out_file_bin = $out_file_bin.\n";

    open LOG_FILE, $esel_file or die "Unable to open LOG_FILE $esel_file\n";
    open OUT_FILE, ">", $out_file_bin or die "Unable to open OUT_FILE $out_file_bin\n";

    while(<LOG_FILE>)
    {
        $line = $_;
        chomp($line);
        if($line =~ /ESEL=/)
        {
            $line =~ s/ESEL=//g; # strip ESEL=
            ($debug) && print " $line";
        }
        # If the SEL entry contains the "df" key, AND it has '040020' it's our eSEL
        if(!$line =~ /df/ or !$line =~ /20 00 04/)
        {
            ($debug) && print " \'df\' or \'20 00 04\' was not found in $line.\n";
            next;
        }

        my @line_parts = split / /, $line; # get hex byte array
        # Chop off the eSEL header (16 bytes). The rest is PEL data.
        $pel_data = join(' ', @line_parts[ESEL_HEADER_LENGTH..$#line_parts]);
        ($debug) && print " PEL Data: $pel_data\n";
        $line_size = split / /, $pel_data;
        print OUT_FILE HexPack($pel_data, $line_size);
    }
    close OUT_FILE;
    close LOG_FILE;
    # Make sure the file naming is consistent with what parsing function expects
    $log_file = "$output_path/$log_file";
}

sub GetAmiEselData
{
    # Figure out the file name for logging the status.
    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);
    my $nice_timestamp = sprintf ( "%02d%02d%02d.%02d%02d%02d",$year-100,$mon+1,$mday,$hour,$min,$sec);
    chomp($target);
    $log_file = "$output_path/$target.$nice_timestamp.eSel";
    open LOG_FILE, ">$log_file" or die "Unable to open the eSEL text file $log_file\n";

    ################################################################
    ## Run ipmitool setl list to get the list of sels and flag eSEL #
    #################################################################

    my $total_size = 0;                # total errlog buffer size
    my @SEL_list;                      # full SEL list
    my @eSEL_list;                     # entries that have eSEL data

    $cmd = "ipmitool -I lanplus -H $target -U $userid -P $passwd sel list 2>&1";
    $debug && print ">>$cmd\n";
    @SEL_list = qx/$cmd/;                   # Execute the command
    ($debug > 1) && print " @SEL_list";
    if (@SEL_list[0] =~ /RAKP/)    # some sort of error on the ipmi cmd
    {
        print "ERROR: \"$cmd\" failed:\n";
        print " @SEL_list";
        exit 1;
    }

    my $sel_count = @SEL_list;              # Count the number of SELs found
    for(my $i=0; $i<$sel_count; $i++)
    {
        # If the SEL entry contains the "df" key, AND it has '040020' it's our eSEL
        if (($SEL_list[$i] =~ / OEM record df /) && ($SEL_list[$i] =~ /040020/))
        {
            push @eSEL_list, $SEL_list[$i];
        }
    }

    # Check if there's no eSEL
    my $esel_count = @eSEL_list;
    if ($esel_count == 0)
    {
        print "No eSEL records with PEL data found.\n";
        exit 0;
    }
    print "Found $esel_count eSELs with PEL data\n";

    for(my $i=0; $i<$esel_count; $i++)
    {
        my @tmp = split(/\|/, $eSEL_list[$i]);  # Split the entry on the |
        $tmp[0] =~ s/^\s+//;                    # Remove the extra white space
        my $sel_record = hex($tmp[0]);          # Convert the hex value of the record to ascii

        $cmd = "ipmitool -I lanplus -H $target -U $userid -P $passwd sel get $sel_record 2>&1";
        $debug && print ">>$cmd\n";
        print "<";
        print LOG_FILE "\n$cmd\n";
        my @eSEL = qx/$cmd/;                    # Execute the command
        ($debug > 1) && print "@eSEL";
        print LOG_FILE " @eSEL\n";

        # get the eSEL data
        my $eSEL_hex = ConvertToHex($sel_record); # 2 bytes, ie: 0x01 0x02 for record 0x0201
        # raw 0x32 0xf1 is AMI partial_get_esel command. command format is (bytes)
        #   1:2     SEL Record ID (byte reversed)
        #   3:4     Offset within the Record to be fetched. (byte reversed)
        $cmd = "ipmitool -I lan -H $target -U $userid -P $passwd raw 0x32 0xf1 $eSEL_hex 0x00 0x00 2>&1";
        print ">";
        $debug && print ">>$cmd\n";
        print LOG_FILE "$cmd\n";
        @eSEL = qx/$cmd/;                       # Execute the command
        ($debug > 1) && print " @eSEL";
        print LOG_FILE " @eSEL";

        #################################################
        # check to see if there is more data
        #################################################
        # response (bytes) from partial_get_esel is:
        #   1:2   Total Length of the Extended SEL (byte reversed)
        #   3     Progress
        #               1 Last chunk
        #               0 Still there is some record to read
        #   4:5   Remaining Bytes to Read (byte reversed)
        #   6:N   Extended SEL data. [ Max size of 2K]
        my @response = split(' ', "@eSEL[0]");
        if ($response[0] =~ /Unable/)    # some sort of error on the ipmi cmd
        {
            if( "@eSEL[0]" =~ /rsp=0x83/ )
            {
                # Unable to send RAW command (channel=0x0 netfn=0x32 lun=0x0 cmd=0xf1 rsp=0x83): Unknown (0x83)
                print "esel $sel_record has been purged from BMC -- skipping\n";
            }
            else
            {
                print "Error on partial_get_esel of sel $sel_record\n";
                print "@eSEL[0]\n";
            }
            push @eSEL_lengths, 0; # 0 PEL length
            next;
        }

        my $progress = $response[2];
        $debug && print "progress code $progress\n";
        my $tmph = "$response[1]$response[0]";
        my $tmp = hex($tmph);
        my $selSizeHex = $tmph;
        my $selSizeDec = $tmp;
        push @eSEL_lengths, $tmp - 16; # PEL length is SEL size - 16 (SELRecord)
        $total_size += $tmp-16;

        while ($progress == 0)
        {
            $tmph = "$response[4]$response[3]";
            $debug && print "remaining size is 0x$tmph\n";

            my $size_left = $selSizeDec - hex($tmph);  # offset for this next chunk
            my $hex_offset = ConvertToHex($size_left); # 2 bytes, ie: 0x01 0x02 for offset 0x0201

            ################################
            # Run the raw command we built #
            ################################
            $cmd = "ipmitool -I lan -H $target -U $userid -P $passwd raw 0x32 0xf1 $eSEL_hex $hex_offset 2>&1";
            $debug && print ">>$cmd\n";
            print LOG_FILE "$cmd\n";
            @eSEL = qx/$cmd/;                   # Execute the command
            ($debug > 1) && print " @eSEL";
            print LOG_FILE " @eSEL";

            @response = split(' ', "@eSEL[0]");
            if ($response[0] =~ /Unable/)    # some sort of error on the ipmi cmd
            {
                $progress = -1;
                $debug && print "Error on partial_get_esel of sel $eSEL_hex\n";
            }
            else
            {
                $progress = $response[2];
                $debug && print "progress code $progress\n";
            }
        }
        if ($progress == 1)  # successful 'exit'
        {
            $debug && print "eSEL Size = 0x$selSizeHex ($selSizeDec) bytes\n\n";
            print LOG_FILE "eSEL Size = 0x$selSizeHex ($selSizeDec) bytes\n\n";
        }
        else
        {
            # error - ignore this eSEL
        }
    }

    close LOG_FILE;
    print "\neSEL text file: $log_file\n";

    # convert to binary errorlog buffer
    ConvertToErrorlogBuffer($log_file);
}

sub ConvertToHex
{
    my $in = @_[0];
    my $hex = sprintf("%04x",$in);        # Convert the value passed to a 4 digit hex
    $hex = sprintf("%s",$hex);            # Convert the hex value to a string
    my $a = substr $hex, 0, 2;            # Break the string into 2 parts
    my $b = substr $hex, 2, 2;

    my $ret = "0x$b 0x$a";
    ########## Must return in the format 0x00 0x00 ##########
    return $ret;
}
sub ConvertToErrorlogBuffer()
{
    my $file = @_[0];

    # Open input file for reading
    open LOG_FILE, $file or die "Unable to open LOG_FILE $file\n";

    # Open file for binary error log buffer
    my $bin_file_name = "$file.binary";
    print "Error log binary file: $bin_file_name\n";
    open OUT_FILE, ">", $bin_file_name or die "Unable to open OUT_FILE $bin_file_name\n";

    # Read a line, convert to unsigned long, then write to target file
    my $skip = 0;
    my $pel_length = 0;
    my $first_raw = 0;
    my $esel_index = 0;
    while (<LOG_FILE>)
    {
        if($_ =~ /lanplus/)
        {
            $pel_length = $eSEL_lengths[$esel_index];
            $debug && print "eSEL $esel_index has length $pel_length\n";
            $esel_index = $esel_index+1;
            $first_raw = 1; # look for first ipmitool raw command
            $skip = 0;
            next;
        }
        if ($first_raw)
        {
            # skip all lines until we get to the ipmitool raw command
            if (!($_ =~ /raw/))
            {
                next;
            }
        }
        if($_ =~ /raw/)
        {
            #############################################
            # If we are at the raw command, we are at the
            # start of the eSEL data 
            #############################################
            # first raw commands returns
            # >> response header:
            # RECID   00: more  bytes remaining
            # 44  01  00        3a 00
            #                >> SEL data (16 bytes)
            #                00 00 df 00 00 00 00 20 00 04 ff
            # ff 07 aa 00 00
            #                >> PEL
            #                50 48 00 30 01 00 05 00 00 00 00
            # 0d 0d b3 9f e4 00 00 00 0d 0d b4 5f 4a 42 00 00
            # 09 90 00 00 09 55 48 00 18 01 00 05 00 8a 03 40
            #############################################
            # following raw commands return
            # >> response header:
            # RECID   01: done  bytes remaining
            # 44 01   01        00 00
            #                >> rest of PEL
            #                11 00 00 0d 0d b4 5f 4a 42 00 00
            # 09 90 00 00 09 55 48 00 18 01 00 05 00 8a 03 40
            # ...
            #############################################
            if ($first_raw)
            {
                # first raw cmd - skip SEL data
                $first_raw = 0;
                $skip = 1;
            }
            else
            {
                # rest of the raw cmds - no SEL data, all PEL
                $skip = 2;
            }
            next;
        }
        # if it is the first raw command skip first line (SEL data)
        if($skip == 1)
        {
            $skip = 2;
            next;
        }

        my $input = $_;

        # for second line in first raw command and first line of other raw
        # commands skip the response header (5 bytes)
        if($skip == 2)       #  ff 07 aa 00 00 50 48 00 30 01 00 05 00 00 00 00
        {
            $input = substr($input, 17);
            ($debug) && print "s2> :$input:\n";
            $skip = 0;
        }
        if ($pel_length <= 0)
        {
            next;
        }
        chomp($input);
        if($input)
        {
            if ($input eq " ")
            {
                next;
            }
            #remove end of line character
            $input =~ s/^\s+|\s+$//g;
            my $linesize = split(/ /, $input);
            $pel_length -= $linesize;
            ($debug) && print ">$linesize> :$input:\n";
            print OUT_FILE HexPack($input, $linesize);
        }
    }

    # Close files
    close LOG_FILE;
    close OUT_FILE;
}
sub HexPack
{
    my $input = @_[0];
    $input =~ s/^\s+|\s+$//g;
    my @in = split(/ /, $input);             # Hold the split version of the input variable
    my $count = @_[1];                       # Number of hex we want
    my $tmp = '';

    for(my $i=0; $i<$count; $i++)
    {
        $tmp = "$tmp$in[$i]";            # Remove the whitespace
    }
    my $ret = pack('H*', $tmp);
    return $ret;
}
