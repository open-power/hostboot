# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Gcov.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2019
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
#!/usr/bin/perl
use strict;
use warnings;
use File::Path;
use File::Basename;
use IO::Handle;

package Hostboot::Gcov;
use Hostboot::_DebugFrameworkVMM qw(NotFound NotPresent getPhysicalAddr);

use Exporter;
our @EXPORT_OK = ('init', 'main', 'parseGcovInfo');

# NOTE:
#
# Neither the in-memory structures or the resulting file format is well
# documented for GCOV.  I was able to piece together enough of this to
# make it work for our purposes by looking at gcov-io.h and libgcov.c
# from the gcc source and gcov/gcc_3_4.c from the linux source.
#
# Since this is a Perl script only used internally for debug, I do not see
# any risk for contamination.  If we decided to give Hostboot to external
# vendors than this Perl script would be distributed as source which should
# not lead us into any issues.
#
# If you are personally concerned about contamination by reading this
# code you are hereby warned of the potential.  Proceed at your own choice.

use constant GCOV_EXTENDED_IMAGE_ADDRESS => (1024 * 1024 * 1024);
use constant GCOV_INFO_HEAD_SYMBOLNAME => "_gcov_info_head";
use constant GCOV_INFO_MAGIC_SYMBOLNAME => "_gcov_info_magic";
use constant GCOV_MAGIC_IDENTIFIER => 0xbeefb055;

use constant GCOV_COUNTERS_492 => 9;
use constant SIZEOF_PTR => 8;
use constant SIZEOF_UINT64 => 8;

use constant GCOV_FUNCTION_TAG => 0x01000000;
use constant GCOV_COUNTERS_TAG => 0x01a10000;
use constant GCOV_PROGRAM_SUMMARY_TAG => 0xa3000000;

use constant GCOV_GCDA_MAGIC_VALUE => 0x67636461;

# See gcov.h for the structs (gcov_info, gcov_fn_info) from which
# these offsets derive

use constant GCOV_INFO_VERSION_OFFSET_492 => 0;
use constant GCOV_INFO_NEXT_OFFSET_492 => 8;
use constant GCOV_INFO_TIMESTAMP_OFFSET_492 => 16;
use constant GCOV_INFO_FILENAME_OFFSET_492 => 24;
use constant GCOV_INFO_MERGE_OFFSET_492 => 32;
use constant GCOV_INFO_N_FUNCTIONS_OFFSET_492 => 32 + (9 * 8);
use constant GCOV_INFO_FUNCTIONS_OFFSET_492 => GCOV_INFO_N_FUNCTIONS_OFFSET_492 + 8;

use constant GCOV_FN_INFO_IDENT_OFFSET_492 => 8;
use constant GCOV_FN_INFO_LINENO_CHECKSUM_OFFSET_492 => 12;
use constant GCOV_FN_INFO_CFG_CHECKSUM_OFFSET_492 => 16;
use constant GCOV_FN_INFO_CTR_INFO_OFFSET_492 => 24;

use constant GCOV_CTR_INFO_NUM_OFFSET_492 => 0;
use constant GCOV_CTR_INFO_VALUES_OFFSET_492 => 8;

# In memory format:
#       GCC creates a 'gcov_info' structure for each .o file.  The info
#       structure has a next pointer to form a chain.  In Hostboot we have
#       organized the chains so that the pointer to the first entry is
#       stored at [modulename]_gcov_info_head (where modulename = "core" for
#       kernel and basic system libraries).
#
#       The gcov_info has a version id (for the gcc compiled with), a
#       compile timestamp, c-string with the name of the .gcda file to be
#       generated, a count of the number of functions in the object, a
#       pointer to a set of function descriptors, a "counter mask" and a
#       set of counter descriptors.
#
#       GCOV supports multiple types of counters.  The only one we are
#       interested in is the "ARCS" counter, which describes the number of
#       times a particular branch is executed.  The other counters are for,
#       for instance, profiling the value of a particular variable.  The
#       "counter mask" specifies which counters are instrumented, which
#       determines the size of some of the array structures, but we only
#       parse the ARCS-counter type (we do properly calculate sizes if
#       needed).
#
#       Each function descriptor contains an identity number and checksum
#       pair so the processing tools can match data to code information.
#       Also the function descriptor has an "n_counters" array which
#       determines for each counter type how many counters are instrumented.
#       Again, we are only concerned with the ARCS counter type.
#
#       The counter descriptor is a size and pointer to array of counter
#       values.  If there were 3 functions in the object each with n_counter
#       values of [3, 5, 2], then the size of the counter descriptor would be
#       3+5+2 = 10.  The values are arranged such that the first function has
#       the first 3 values, second one has the next 5, etc.  The relationship
#       between function descriptor / "n_counters" and counter descriptor
#       values was not obvious from reading the gcov-io.h.
#
#       For more details on these structures search the internet for gcov-io.h
#       or ask the building block team for the source code to the compiler we
#       are currently using.  The offsets of all of these structures are all
#       documented in Perl constants above so you should only need this if
#       something breaks.
#
# .gcda file format:
#       The gcov tools expect a .gcda (gcov data) file as input, containing the
#       instrumented counter values, to go along with the .gcno (gcov note)
#       file created by the compiler.  The format is documented in gcov-io.h
#       as well but was again not obvious to decipher.
#
#       Here is a distilled file format description.  Each entity is an u32.
#
#       file : magic version stamp {function counts}*
#       function: f_header ident checksum
#       counts: c_header count*
#       count: lo hi
#       f_header: F_TAG(=0x01000000) F_LENGTH(=2)
#       c_header: C_TAG(=0x01a10000) C_LENGTH(=count_length*2)
#
#       The file has three u32 of header followed by any number of function
#       descriptor and count set pairs.  The function descriptor is the
#       identity and checksum of the function.  The count set is an array of
#       uint64_ts, containing instrumented counts, for the preceeding function.

# Global of where we want the output to go.
our $debug_mode;
our $hbicore_extended_bin_file;
our $hbicore_extended_bin_file_size;
BEGIN
{
    $debug_mode = 0;
}

sub init
{
    # TODO: We need to figure out how to handle reading data from
    # HBB/HBRT for when those are instrumented. One hurdle is being
    # able to determine from an address what module it belongs to,
    # because HBB/HBI/HBRT are not necessarily laid out in memory as
    # they are in PNOR or anywhere else.

    my $hbicore_extended_bin_fname = "$ENV{SANDBOXROOT}/$ENV{SANDBOXNAME}/src/hbfw/img/hostboot_extended.bin";

    userDebug("Opening " . $hbicore_extended_bin_fname . " for HBI\n");

    unless (open($hbicore_extended_bin_file, "< $hbicore_extended_bin_fname")) {
        ::userDisplay "Failed to open $hbicore_extended_bin_fname, exiting\n";
        return 0;
    }

    binmode($hbicore_extended_bin_file);

    $hbicore_extended_bin_file_size = -s $hbicore_extended_bin_fname;

    return 1;
}

sub main
{
    if (!init()) {
        return;
    }

    # Find all the hostboot modules.
    my @modules = getModules();

    # Search for the gcov_info object for each module and parse.
    foreach my $module (@modules)
    {
        parseModuleGcov($module);
    }

    my $pwd = `pwd`;
    chomp $pwd;

    close $hbicore_extended_bin_file or die;

    ::userDisplay("GCOV info extraction complete.\n");
}

sub parseModuleGcov
{
    my $module = shift;
    ::userDisplay "Extracting GCOV info for ".$module."\n";

    # Search for magic symbol.
    my ($gcov_magic, $unused) =
        ::findSymbolAddress($module.GCOV_INFO_MAGIC_SYMBOLNAME);

    if (!defined($gcov_magic))
    {
        $gcov_magic = 0;
    }

    if ($gcov_magic == 0 || read32($gcov_magic, 1) != GCOV_MAGIC_IDENTIFIER)
    {
        ::userDisplay "\tgcov_magic at address " . (sprintf "0x%x", $gcov_magic) . " is incorrect.  Skipped.\n";
        return;
    }

    # Search for gcov_info chain symbol.
    my ($gcov_info, $unused2) =
        ::findSymbolAddress($module.GCOV_INFO_HEAD_SYMBOLNAME);

    userDebug("\tFound info at 0x" . (sprintf "%x", $gcov_info) . "\n");

    # Translate gcov_info chain to a physical address if in a module.
    if (isVirtualAddress($gcov_info))
    {
        $gcov_info = getPhysicalAddr($gcov_info);

        if (($gcov_info eq NotFound) || ($gcov_info eq NotPresent))
        {
            ::userDisplay "\tModule data is not present, module might have been unloaded, skipping.\n";
            return;
        }
    }

    # Check that we found the gcov_info chain.
    if ($gcov_info == 0)
    {
        ::userDisplay "\tUnable to find gcov_info chain, module might hvae been unloaded. Skipping.\n";
        return;
    }

    # Parse info chain.
    parseGcovInfo(read64($gcov_info));
}

sub parseGcovInfo
{
    my $info_ptr = shift;
    return if (0 eq $info_ptr);

    userDebug("\tReading filename pointer from offset " . (sprintf "0x%x", ($info_ptr + GCOV_INFO_FILENAME_OFFSET_492)) . "\n");

    my $filename_addr = read64($info_ptr + GCOV_INFO_FILENAME_OFFSET_492);

    userDebug("\tReading filename from offset " . (sprintf "0x%x", $filename_addr) . "\n");

    my $filename = readStr($filename_addr);

    if ($filename) {
        ::userDisplay("\tFile = ".$filename."\n");

        my $version = read32($info_ptr + GCOV_INFO_VERSION_OFFSET_492);
        my $stamp = read32($info_ptr + GCOV_INFO_TIMESTAMP_OFFSET_492);

        my $func_count = read32($info_ptr + GCOV_INFO_N_FUNCTIONS_OFFSET_492);
        userDebug("\tFunction Count = ".$func_count."\n");

        my $funcs = read64($info_ptr + GCOV_INFO_FUNCTIONS_OFFSET_492, 1);

        if ($funcs ne NotFound && $funcs ne NotPresent) {
            userDebug("\tFunc Address = ".(sprintf "0x%x", $funcs)."\n");

            if ($version ne NotFound && $stamp ne NotFound && $func_count ne NotFound) {
                my $fd = createGcovFile($filename, $version, $stamp);

                parseGcovFuncs($fd, $funcs, $func_count);

                close $fd or die $!;
            }
        } else {
            userDebug("\tFunc Address is NULL, skipping\n");
        }
    } else {
        userDebug("\tCannot read filename, skipping\n");
    }

    # Look for next .o in gcov_info chain, parse.
    my $next = read64($info_ptr + GCOV_INFO_NEXT_OFFSET_492);
    parseGcovInfo($next);
}

sub parseGcovFuncs
{
    my $fd = shift;
    my $func_ptr = shift;
    my $func_count = shift;

    my $GCOV_COUNTERS_SUMMABLE_492 = 1;

    print $fd pack('l', GCOV_PROGRAM_SUMMARY_TAG); # data.program.header.tag

    # for each GCOV_COUNTERS_SUMMABLE we have ten int32 (num, runs, and bitvector{8})
    # plus three int64 (sum, max, sum_max) i.e. 10 + 3*2
    # data.unit.header.length is the number of int32's we have following.
    print $fd pack('l', 1 + $GCOV_COUNTERS_SUMMABLE_492 * (10 + 3 * 2)); # data.unit.header.length;

    print $fd pack('l', 0); # data.summary:object.checksum (must be 0 according to docs)

    for (my $i = 0; $i < $GCOV_COUNTERS_SUMMABLE_492;  $i++) {
        print $fd pack('l', 0); # data.summary:object.count-summary.num
        print $fd pack('l', 0); # data.summary:object.count-summary.runs
        print $fd pack('l', 0); # data.summary:object.count-summary.sum@lo
        print $fd pack('l', 0); # data.summary:object.count-summary.sum@hi
        print $fd pack('l', 0); # data.summary:object.count-summary.max@lo
        print $fd pack('l', 0); # data.summary:object.count-summary.max@hi
        print $fd pack('l', 0); # data.summary:object.count-summary.sum_max@lo
        print $fd pack('l', 0); # data.summary:object.count-summary.sum_max@hi

        print $fd pack('l8', (0) x 8);   # data.summary:object.count-summary.histogram.bitvector{8}
    }

    # Iterate through the functions and parse.
    for(my $function = 0; $function < $func_count; $function++)
    {
        userDebug("\tFunction $function of $func_count\n");

        my $fn_info_ptr = read64($func_ptr + SIZEOF_PTR*$function, 1);

        if (($fn_info_ptr eq NotFound) || ($fn_info_ptr eq NotPresent))
        {
            userDebug("\tCannot read function info pointer, skipping\n");
            next;
        }

        userDebug("\tfn_info_ptr = " . (sprintf "%x", $fn_info_ptr) . "\n");

        my $ident = read32($fn_info_ptr + GCOV_FN_INFO_IDENT_OFFSET_492, 1);
        my $lineno_chksum = read32($fn_info_ptr + GCOV_FN_INFO_LINENO_CHECKSUM_OFFSET_492, 1);
        my $cfg_chksum = read32($fn_info_ptr + GCOV_FN_INFO_CFG_CHECKSUM_OFFSET_492, 1);
        my $ctr_info_ptr = $fn_info_ptr + GCOV_FN_INFO_CTR_INFO_OFFSET_492;

        if ($ident eq NotFound
            || $lineno_chksum eq NotFound
            || $cfg_chksum eq NotFound)
        {
            userDebug("Skipping because fn_info structure members are not readable\n");
            next;
        }

        my $num_ctrs = read32($ctr_info_ptr + GCOV_CTR_INFO_NUM_OFFSET_492, 1);
        my $ctrs_ptr = read64($ctr_info_ptr + GCOV_CTR_INFO_VALUES_OFFSET_492, 1);

        if ($ctrs_ptr eq NotFound || $num_ctrs eq NotFound)
        {
            userDebug("Skipping because counters length isn't mapped\n");
            next;
        }

        my $counters = readData($ctrs_ptr, SIZEOF_UINT64 * $num_ctrs);

        userDebug("Ident = ".(sprintf "0x%x", $ident)."\n");
        userDebug("lineno Chksum = ".(sprintf "0x%x", $lineno_chksum)."\n");
        userDebug("cfg Chksum = ".(sprintf "0x%x", $cfg_chksum)."\n");
        userDebug("Num counters = ".(sprintf "%d", $num_ctrs)."\n");
        userDebug("ctrs_ptr = ".(sprintf "0x%x", $ctrs_ptr)."\n");

        if (($counters eq NotFound) || ($counters eq NotPresent))
        {
            userDebug("Skipping because counter data not resident in memory\n");
            next;
        }

        print $fd pack('l', GCOV_FUNCTION_TAG);  # Write function tag.
        print $fd pack('l', 3); # Write size = 3.
        print $fd pack('l', $ident); # Write ident.
        print $fd pack('l', $lineno_chksum); # Write checksum.
        print $fd pack('l', $cfg_chksum); # Write checksum.

        print $fd pack('l', GCOV_COUNTERS_TAG); # Write counter tag.
        print $fd pack('l', $num_ctrs * 2); # Write counter length.

        # Read each counter value, output.
        #       Read as one big block for performance reasons.

        for(my $v_idx = 0; $v_idx < $num_ctrs; $v_idx++)
        {
            my $val = substr $counters, 0, 8;
            $counters = substr $counters, 8;
            if (::littleendian()) { $val = reverse($val); }
            $val = unpack("Q", $val);
            userDebug("\tValue[$v_idx] = ".$val."\n");

            my $preex_read_low = read($fd, my $low_word, 4);
            my $preex_read_high = read($fd, my $high_word, 4);

            if (!defined($preex_read_low) or !(defined($preex_read_high))) {
                die;
            }
            my $preex_read = $preex_read_low + $preex_read_high;

            if ($preex_read == 8)
            {
                my $preex_val = (unpack("l", $high_word) << 32) | unpack("l", $low_word);

                $val += $preex_val;
            }

            if ($preex_read > 0)
            {
                seek $fd, -$preex_read, 1;
            }
            else
            {
                seek $fd, 0, 2;
            }

            print $fd pack('l', $val & 0xFFFFFFFF);  # Write lower word.
            print $fd pack('l', $val >> 32) ; # Write upper word.
        }
    }
}

# The *.gcda filename found in the gcov_info struct is an absolute path to
# the corresponding .o file (not the .C file).  This is of the form:
# ${PROJECT_ROOT}/src/usr/module/${ROOTPATH}/obj/${MODULE}/foo.gcda .
# Since we might not even be running this on the same machine, we need to put
# the output into the "output_dir" but we need to strip off a lot of stuff.
# The path is going to have an obj in it somewhere so we key off that
# as the location for where the output file will go.
sub createGcovFile
{
    my $name = shift;
    my $version = shift;
    my $stamp = shift;

    # if the file exists then we update it, if not we create it
    my $GCOVFILE;
    if (-e $name)
    {
        if (!open($GCOVFILE, "+<$name"))
        {
            ::userDisplay("Failed to open $name for reading/writing gcov information\n");
            die;
        }
    }
    else
    {
        if (!open($GCOVFILE, "+>$name"))
        {
            ::userDisplay("Failed to open $name for writing gcov information\n");
            die;
        }
    }

    binmode($GCOVFILE);

    # Write out header.
    print $GCOVFILE pack('l', GCOV_GCDA_MAGIC_VALUE);
    print $GCOVFILE pack('l', $version);
    print $GCOVFILE pack('l', $stamp);

    return $GCOVFILE;
}

# Search the module list for each code module (lib*.so).  Also add "core"
# for the kernel instrumentation.
sub getModules
{
    my @modules = ::listModules();
    my @result = ( "core" );

    foreach my $mod (@modules)
    {
        if ($mod =~ m/lib.*\.so$/)
        {
            $mod =~ s/lib(.*)\.so/$1/;
            push @result, $mod;
        }
    }

    return @result;
}

# Determine if an address is virtual.
sub isVirtualAddress
{
    my $addr = shift;

    return ($addr >= GCOV_EXTENDED_IMAGE_ADDRESS);
}

sub readExtImage
{
    my $addr = shift;
    my $amount = shift;

    if ($addr + $amount >= $hbicore_extended_bin_file_size) {
        return NotFound;
    }

    seek $hbicore_extended_bin_file, $addr, 0;

    read $hbicore_extended_bin_file, my ($contents), $amount;

    return $contents;
}

# Utility to read a block of data from eithr memory or using the extended
# image file as a fallback if not present in memory.
use constant PAGESIZE => 4096;
sub readData
{
    my $addr = shift;
    my $size = shift;

    if (isVirtualAddress($addr))
    {
        my $result = "";

        while($size)
        {
            my $amount = $size;

            if ((($addr % PAGESIZE) + $size) >= PAGESIZE)
            {
                $amount = PAGESIZE - ($addr % PAGESIZE);
            }

            my $paddr = getPhysicalAddr($addr);
            if ((NotFound eq $paddr) || (NotPresent eq $paddr))
            {
                my $tmpdata = readExtImage($addr - GCOV_EXTENDED_IMAGE_ADDRESS, $amount);

                if ($tmpdata eq NotFound) {
                    return NotFound;
                }

                $result = $result . $tmpdata;
            }
            else
            {
                $result = $result.::readData($paddr, $amount);
            }

            $size = $size - $amount;
        }

        return $result;
    }

    return ::readData($addr, $size);
}

# Utility to read 64 bits from either memory or using the extended image file
# as a fallback if not present in memory.
sub read64
{
    my $addr = shift;
    my $fallback = shift;

    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            userDebug((sprintf "0x%x", $old_addr). " not translatable 2\n");

            if (!$fallback) {
                return NotFound;
            }

            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = readExtImage($addr, 8);

            if ($result eq NotFound) {
                return NotFound;
            }

            if (::littleendian()) { $result = reverse($result); }
            return unpack("Q", $result);
        }
    }

    return ::read64($addr);
}

# Utility to read 32 bits from either memory or using the extended image file
# as a fallback if not present in memory.
sub read32
{
    my $addr = shift;
    my $fallback = shift;

    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            userDebug((sprintf "0x%x", $old_addr). "not translatable 3\n");

            if (!$fallback) {
                return NotFound;
            }

            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = readExtImage($addr, 4);
            if ($result eq NotFound) {
                return NotFound;
            }
            if (::littleendian()) { $result = reverse($result); }
            return unpack("L", $result);
        }
    }

    return ::read32($addr);
}

# Utility to read 8 bits from either memory or using the extended image file
# as a fallback if not present in memory.
sub read8
{
    my $addr = shift;
    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            userDebug((sprintf "0x%x", $addr). "not translatable 4\n");

            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = readExtImage($addr, 1);
            return unpack("C", $result);
        }
    }

    return ::read8($addr);
}

# Utility to read a string from either memory or using the extended image file
# as a fallback if not present in memory.
sub readStr
{
    my $addr = shift;
    my $old_addr = $addr;

    if (isVirtualAddress($addr))
    {
        userDebug("it is a virtual address, addr is " . (sprintf "%x", $addr) . "\n");
        my $phys_addr = getPhysicalAddr($addr);

        if ((NotFound eq $phys_addr) || (NotPresent eq $phys_addr))
        {
            userDebug("Translation not found, reading from pnor\n");
            # Virtual address, so need to read 1 byte at a time from the file.
            my $string = "";
            my $byte = 0;

            do
            {
                $byte = readExtImage($addr - GCOV_EXTENDED_IMAGE_ADDRESS, 1);

                if ($byte eq NotFound)
                {
                    return "";
                }

                $addr = $addr + 1;

                if (unpack("C",$byte) eq 0)
                {
                    return $string;
                }

                $string = $string.$byte;
            } while (1);
        }
        else
        {
            my $string = "";
            my $byte = 0;

            do
            {
                if (($addr & 0xfff) == 0)
                {
                    # we have to recalculate the physical address
                    # whenever we cross a page boundary
                    $phys_addr = getPhysicalAddr($addr);

                    if ((NotFound eq $phys_addr) || (NotPresent eq $phys_addr))
                    {
                        userDebug((sprintf "0x%x", $addr). "not translatable 10\n");
                        return "";
                    }
                }

                $byte = read8($phys_addr);

                if ($byte eq NotFound)
                {
                    userDebug("Cannot read byte from physical address\n");
                    return "";
                }

                $addr += 1;
                $phys_addr += 1;

                if ($byte != 0)
                {
                    $string = $string . pack("C", $byte);
                }
            } while ($byte != 0);

            return $string;
        }
    }
    else
    {
        userDebug("it is NOT a virtual address\n");
        return ::readStr($addr);
    }
}


sub userDebug
{
    return if (!$debug_mode);

    my $string = shift;
    ::userDisplay $string;
}

# Debug tool help info.
sub helpInfo
{
    my %info = (
        name => "Gcov",
        intro => [ "Extracts the GCOV information."],
    );
}

1; # Last expression in a perl module must be truthy.
