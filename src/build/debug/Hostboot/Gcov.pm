#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Gcov.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
use strict;
use File::Path;
use File::Basename;

package Hostboot::Gcov;
use Hostboot::_DebugFrameworkVMM qw(NotFound NotPresent getPhysicalAddr);

use Exporter;
our @EXPORT_OK = ('main');

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

use constant GCOV_INFO_VERSION_OFFSET => 0;
use constant GCOV_INFO_NEXT_OFFSET => GCOV_INFO_VERSION_OFFSET + 8;
use constant GCOV_INFO_TIMESTAMP_OFFSET => GCOV_INFO_NEXT_OFFSET + 8;
use constant GCOV_INFO_FILENAME_OFFSET => GCOV_INFO_TIMESTAMP_OFFSET + 8;
use constant GCOV_INFO_NFUNCTIONS_OFFSET => GCOV_INFO_FILENAME_OFFSET + 8;
use constant GCOV_INFO_FUNCTIONS_OFFSET => GCOV_INFO_NFUNCTIONS_OFFSET + 8;
use constant GCOV_INFO_CTRMASK_OFFSET => GCOV_INFO_FUNCTIONS_OFFSET + 8;
use constant GCOV_INFO_COUNTS_OFFSET => GCOV_INFO_CTRMASK_OFFSET + 8;

use constant GCOV_FNINFO_IDENT_OFFSET => 0;
use constant GCOV_FNINFO_CHECKSUM_OFFSET => GCOV_FNINFO_IDENT_OFFSET + 4;
use constant GCOV_FNINFO_NCTRS_OFFSET => GCOV_FNINFO_CHECKSUM_OFFSET + 4;

use constant GCOV_CTRINFO_COUNT_OFFSET => 0;
use constant GCOV_CTRINFO_VALUEPTR_OFFSET => GCOV_CTRINFO_COUNT_OFFSET + 8;

use constant GCOV_GCDA_MAGIC_VALUE => 0x67636461;
use constant GCOV_FUNCTION_TAG => 0x01000000;
use constant GCOV_COUNTERS_TAG => 0x01a10000;

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
our $output_dir;
our $debug_mode;
BEGIN
{
    $debug_mode = 0;
    $output_dir = "";
}
return 1;

sub main
{
    # Pick a new output directory based on the time.
    $output_dir = sprintf "gcov.output.%d/", time;
    File::Path::mkpath($output_dir);

    # Find all the hostboot modules.
    my @modules = getModules();

    # Search for the gcov_info object for each module and parse.
    foreach my $module (@modules)
    {
        parseModuleGcov($module);
    }

    my $pwd = `pwd`;
    chomp $pwd;
    ::userDisplay "GCOV output written to: $pwd/$output_dir\n";
}

sub parseModuleGcov
{
    my $module = shift;
    ::userDisplay "Extracting GCOV info for ".$module."\n";

    # Search for gcov_info chain symbol.
    my ($gcov_info, $unused) =
        ::findSymbolAddress($module.GCOV_INFO_HEAD_SYMBOLNAME);

    userDebug("\tFound info at 0x" . (sprintf "%x", $gcov_info) . "\n");

    # Translate gcov_info chain to a physical address if in a module.
    if (isVirtualAddress($gcov_info))
    {
        $gcov_info = getPhysicalAddr($gcov_info);

        if (($gcov_info eq NotFound) || ($gcov_info eq NotPresent))
        {
            ::userDisplay "\tModule data is not present.\n";
            return;
        }
    }

    # Check that we found the gcov_info chain.
    if ($gcov_info == 0)
    {
        ::userDisplay "\tUnable to find gcov_info chain.  Skipped.\n";
        return;
    }

    # Parse info chain.
    parseGcovInfo(read64($gcov_info));
}

sub parseGcovInfo
{
    my $info_ptr = shift;
    return if (0 eq $info_ptr);

    my $filename = readStr(read64($info_ptr + GCOV_INFO_FILENAME_OFFSET));
    userDebug("\tFile = ".$filename."\n");

    my $version = read32($info_ptr + GCOV_INFO_VERSION_OFFSET);
    my $stamp = read32($info_ptr + GCOV_INFO_TIMESTAMP_OFFSET);

    my $func_count = read32($info_ptr + GCOV_INFO_NFUNCTIONS_OFFSET);
    userDebug("\tFunction Count = ".$func_count."\n");

    my $funcs = read64($info_ptr + GCOV_INFO_FUNCTIONS_OFFSET);
    userDebug("\tFunc Address = ".(sprintf "%x", $funcs)."\n");

    my $ctrmask = read32($info_ptr + GCOV_INFO_CTRMASK_OFFSET);
    if ($ctrmask % 2) # Check that COUNTER_ARCS is turned on.
    {
        # COUNTER_ARCS is on.  Create file, find arc-values array,
        # parse functions.

        my $fd = createGcovFile($filename, $version, $stamp);

        my $arcs_ptr = read64($info_ptr + GCOV_INFO_COUNTS_OFFSET +
                                GCOV_CTRINFO_VALUEPTR_OFFSET);
        parseGcovFuncs($fd, $funcs, $func_count, $ctrmask, $arcs_ptr);

        close $fd;
    }
    else
    {
        userDebug("COUNTER_ARCS is missing!\n");
    }

    # Look for next .o in gcov_info chain, parse.
    my $next = read64($info_ptr + GCOV_INFO_NEXT_OFFSET);
    parseGcovInfo($next);
}

sub parseGcovFuncs
{
    my $fd = shift;
    my $func_ptr = shift;
    my $func_count = shift;
    my $mask = shift;
    my $val_ptr = shift;

    my $fn_offset = 0;

    # Need to calculate the number of counters based on the bits on in
    # the 'mask'.  This is used to determine the size of the function
    # descriptor object.
    my $counters = 0;
    {
        my $_mask = $mask;

        while (0 != $_mask)
        {
            $counters++;
            $_mask = ($_mask >> 1);
        }
    }

    userDebug("\tCounters = ".$counters."\n");

    # Round up the counter count to the nearest two for alignment of the
    # function descriptor object.
    if ($counters % 2)
    {
        $counters++;
    }
    my $func_size = GCOV_FNINFO_CHECKSUM_OFFSET + 4 * $counters;

    userDebug("\tFunction size = ".$func_size."\n");

    # Iterate through the functions and parse.
    for(my $function = 0; $function < $func_count; $function++)
    {
        my $func_off = ($func_ptr + $func_size * $function);
        my $ident = read32($func_off + GCOV_FNINFO_IDENT_OFFSET);
        my $chksum = read32($func_off + GCOV_FNINFO_CHECKSUM_OFFSET);

        userDebug("Ident = ".(sprintf "%x", $ident)."\n");
        userDebug("Chksum = ".(sprintf "%x", $chksum)."\n");

        print $fd pack('l', GCOV_FUNCTION_TAG);  # Write function tag.
        print $fd pack('l', 2); # Write size = 2.
        print $fd pack('l', $ident); # Write ident.
        print $fd pack('l', $chksum); # Write checksum.

        my $nctr_val = read32($func_off + GCOV_FNINFO_NCTRS_OFFSET);
        userDebug("N-Counters = ".$nctr_val."\n");

        print $fd pack('l', GCOV_COUNTERS_TAG); # Write counter tag.
        print $fd pack('l', $nctr_val * 2); # Write counter length.

        # Read each counter value, output.
        #       Read as one big block for performance reasons.
        my $counters = readData($val_ptr + 8*($fn_offset), 8 * $nctr_val);
        for(my $v_idx = 0; $v_idx < $nctr_val; $v_idx++)
        {
            my $val = substr $counters, 0, 8;
            $counters = substr $counters, 8;
            if (::littleendian()) { $val = reverse($val); }
            $val = unpack("Q", $val);
            userDebug("\tValue[$v_idx] = ".$val."\n");

            print $fd pack('l', $val & 0xFFFFFFFF);  # Write lower word.
            print $fd pack('l', $val >> 32) ; # Write upper word.
        }

        # We used up a number of counters, so move the offset forward for
        # the next function.
        $fn_offset += $nctr_val;
    }

}

# The *.gcda filename found in the gcov_info struct is an absolute path to
# the corresponding .o file (not the .C file).  This is of the form:
# ${HOSTBOOTROOT}/src/usr/module/${ROOTPATH}/obj/${MODULE}/foo.gcda .
# Since we might not even be running this on the same machine, we need to put
# the output into the "output_dir" but we need to strip off a lot of stuff.
# The path is going to have an obj in it somewhere so we key off that
# as the location for where the output file will go.
sub createGcovFile
{
    my $name = shift;
    my $version = shift;
    my $stamp = shift;

    # Change *./../obj/ into obj/, prepend output_dir.
    $name =~ s/.*\/obj\//obj\//;
    $name = $output_dir.$name;

    # Make sure everything after 'obj/' exists (create subdirs).
    my $dir = File::Basename::dirname($name);
    File::Path::mkpath($dir);

    # Create file.
    open(my $GCOVFILE, "> $name");
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
                $paddr = $addr - GCOV_EXTENDED_IMAGE_ADDRESS;
                $result = $result.::readExtImage($paddr, $amount);
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
    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = ::readExtImage($addr, 8);
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
    my $old_addr = $addr;
    if (isVirtualAddress($addr))
    {
        $addr = getPhysicalAddr($addr);
        if ((NotFound eq $addr) || (NotPresent eq $addr))
        {
            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = ::readExtImage($addr, 4);
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
            $addr = $old_addr - GCOV_EXTENDED_IMAGE_ADDRESS;
            my $result = ::readExtImage($addr, 1);
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
        $addr = $addr - GCOV_EXTENDED_IMAGE_ADDRESS;

        # Virtual address, so need to read 1 byte at a time from the file.
        my $string = "";
        my $byte = 0;

        do
        {
            $byte = ::readExtImage($addr,1);
            $addr = $addr + 1;

            if (unpack("C",$byte) eq 0)
            {
                return $string;
            }

            $string = $string.$byte;

        } while (1)
    }
    else
    {
        ::readStr($addr);
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
