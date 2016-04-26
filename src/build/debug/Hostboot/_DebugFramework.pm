#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/_DebugFramework.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2016
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
# _DebugFramework.pm
#
# This module is a set of utility functions for the debug framework, which
# should be common across all debug framework environments.
#
# The module provides the functions listed below in @EXPORT.
#
# A debug framework environment is expected to implement the following
# functions:
#     * getIsTest() - Is the image loaded a test image or normal?
#     * getImgPath() - Path to the .../img/ directory containing debug files.
#     * readData(addr,size) - Read a blob of memory.
#     * userDisplay(varargs-of-mixed) - Display things to the user.
#

use strict;

package Hostboot::_DebugFramework;
use Exporter 'import';

our @EXPORT = ( 'setBootloader', 'clearBootloader', 'callToolModule',
                'callToolModuleHelp', 'callToolModuleHelpInfo',
                'parseToolOpts', 'determineImagePath',
                'findSymbolAddress', 'findSymbolTOCAddress',
                'findSymbolByAddress',
                'findModuleByAddress', 'listModules',
                'littleendian',
                'read64', 'read32', 'read16', 'read8', 'readStr',
                'write64', 'write32', 'write16', 'write8',
                'translateHRMOR',
                'getIstepList',
                'findSymbolWithinAddrRange',
              );

our ($parsedSymbolFile, %symbolAddress, %symbolTOC,
     %addressSymbol, %symbolSize, %addrRangeHash);
our ($parsedModuleFile, %moduleAddress);
our (%toolOpts);
our ($bootloaderDebug);

BEGIN
{
    $parsedSymbolFile = 0;
    %symbolAddress = ();
    %symbolTOC = ();
    %addressSymbol = ();
    %addrRangeHash = ();

    %symbolSize = ();

    $parsedModuleFile = 0;
    %moduleAddress = ();

    %toolOpts = ();

    $bootloaderDebug = 0;
}
return 1;

# @sub setBootloader
#
# Sets flag for running Bootloader tool.
#
sub setBootloader
{
    $bootloaderDebug = 1;

    return;
}

# @sub clearBootloader
#
# Clears flag for running Bootloader tool.
#
sub clearBootloader
{
    $bootloaderDebug = 0;

    return;
}

# @sub callToolModule
#
# Executes the 'main' function of the requested tool module.
#
# @param string - Tool to call.
#
# @pre Must have previously called parseToolOpts.
#
sub callToolModule
{
    my $tool = shift;
    my $package = "Hostboot::$tool";

    my $tool_loc = ".";
    if (exists &::getToolOverride)
    {
        $tool_loc = ::getToolOverride();
    }

    eval("use lib '$tool_loc'; use $package; return 1;") or
            die "Couldn't load tool \"$tool\":\n\t$@";
    eval("$package->main(\\%toolOpts);");
    die $@ if $@;
}

# @sub callToolModuleHelp
#
# Display the tool usage.
#
# @param string - Tool to call.
#
sub callToolModuleHelp
{
    my $tool = shift;
    my %info = callToolModuleHelpInfo($tool);

    ::userDisplay("\nTool: $tool\n");

    for my $i ( 0 .. $#{ $info{intro} } )
    {
        ::userDisplay("\t$info{intro}[$i]\n");
    }

    if (defined $info{options})
    {
        ::userDisplay("\nOptions:\n");

        for my $key ( keys %{$info{options}} )
        {
            ::userDisplay("\t$key\n");

            for my $i (0 .. $#{ $info{options}{$key} } )
            {
                ::userDisplay("\t\t$info{options}{$key}[$i]\n");
            }
        }
    }

    if (defined $info{notes})
    {
        ::userDisplay("\n");
        for my $i (0 .. $#{ $info{notes} } )
        {
            ::userDisplay("$info{notes}[$i]\n");
        }
    }
}

# @sub callToolModuleHelpInfo
#
# Executes the 'helpInfo' function of the requested tool module to get
# the tool usage info.
#
# @param string - Tool to call.
#
sub callToolModuleHelpInfo
{
    my $tool = shift;
    my $package = "Hostboot::$tool";

    my $tool_loc = ".";
    if (exists &::getToolOverride)
    {
        $tool_loc = ::getToolOverride();
    }

    eval("use lib '$tool_loc'; use $package; return 1;") or
            die "Couldn't load tool \"$tool\":\n\t$@";
    my %info = eval("$package->helpInfo(\\%toolOpts);");
    die $@ if $@;
    return %info;
}

# @sub parseToolOpts
#
# Parses a space deliminated string of options for use by the tool.
#
# Allows an option to contain spaces itself by wrapping the value in a
# single quote.
#
# @param string - Tool option list.
#
# Example:
#     "foo bar=/abcd/efg" --> { "foo" => 1 , "bar" => "/abcd/efg" }
#     "foo='bar nil'" --> { "foo" => "bar nil" }
#
sub parseToolOpts
{
    my $toolOptions = shift;
    my $partial = "";
    foreach my $opt (split / /, $toolOptions)
    {
        # Search for a single-quoted word in the option string.
        if (($opt =~ m/'/) and (not ($opt =~ m/'.*'/)))
        {
            # If partial is not empty, this single-quote terminates the string.
            if ($partial ne "")
            {
                $opt = $partial." ".$opt;
                $partial = "";
            }
            # Otherwise, append it to the partial string.
            else
            {
                $partial = $opt;
                next;
            }
        }
        # Append a word to a partially completed string in progress.
        elsif ($partial ne "")
        {
            $partial = $partial." ".$opt;
            next;
        }

        # At this point "opt" is either a free-standing argument set or a
        # fully complete single-quote deliminated string.
        if ($opt =~ m/=/)
        {
            my ($name,$value) = split /=/, $opt;
            $value =~ s/^'([^']*)'$/$1/;        # Trim out the 's.
            $toolOpts{$name} = $value;
        }
        else
        {
            $toolOpts{$opt} = 1;
        }
    }
}

# @sub determineImagePath
#
# Utility function to search for the .../img/ directory from a few well known
# places.
#
# @param string - Path passed by user to the image directory.
#
# @returns Found path to the .../img/ directory.
#
sub determineImagePath
{
    my $imgPath = shift;

    if ($imgPath eq "")
    {
        if ((::getIsTest() and (-e "hbicore_test.syms")) or
            (not ::getIsTest() and (-e "hbicore.syms")))
        {
            $imgPath = "./";
        }
        else
        {
            $imgPath = $ENV{"PROJECT_ROOT"} . "/img/";
        }
    }

    return $imgPath;
}

# @sub parseSymbolFile <INTERNAL ONLY>
#
# Parses through a .syms file and populates a hash.
#
sub parseSymbolFile
{
    if ($parsedSymbolFile) { return; }

    my $symsFile = ::getImgPath();
    if ($bootloaderDebug == 1)
    {
        $symsFile = $symsFile."hbibl.syms";
    }
    elsif (::getIsTest())
    {
        $symsFile = $symsFile."hbicore_test.syms";
    }
    else
    {
        $symsFile = $symsFile."hbicore.syms";
    }

    open(FILE, "< $symsFile") or die "Cannot open symbol file $symsFile";
    while (my $line = <FILE>)
    {
        $line =~ m/(.*?),(.*?),(.*?),(.*?),(.*)/;
        my $name = $5;
        my $addr = hex $2;
        my $tocAddr = hex $3;
        my $size = hex $4;
        my $type = $1;

        $addressSymbol{$addr} = $name;
        $addressSymbol{$tocAddr} = $name;

        $addrRangeHash{$addr}{name} = $name;
        $addrRangeHash{$addr}{size} = $size;

        # Use only the first definition of a symbol.
        #    This is useful for constructors where we only want to call the
        #    'in-charge' version of the constructor.
        if (defined $symbolAddress{$name})
        {
            next;
        }

        $symbolAddress{$name} = $addr;
        if ($type eq "F")
        {
            $symbolTOC{$name} = $tocAddr;
        }
        $symbolSize{$name} = $size;

    }
    close(FILE);

    # Some of the symbols have a size of 0 even though they are obviously
    # bigger than 0 bytes.  As an example any assembly label has a size of 0
    # from the ELF data.  This loop finds all of those 0-sized symbols and
    # fixes their size to be the distance between their address and the
    # address of the next symbol.
    my $prevSymbol = 0;
    foreach my $sym (sort { $a <=> $b } keys %addrRangeHash)
    {
        if (0 != $prevSymbol)
        {
            my $symSize = $sym - $prevSymbol - 4;
            $addrRangeHash{$prevSymbol}{size} = $symSize;
            $symbolSize{$addrRangeHash{$prevSymbol}{name}} = $symSize;
            $prevSymbol = 0;
        }

        if (0 == $addrRangeHash{$sym}{size})
        {
            $prevSymbol = $sym;
        }
    }

    $parsedSymbolFile = 1;
}

# @sub findSymbolAddress
#
# Searchs a syms file for the address of a particular symbol name.
#
# @param string - Symbol to search for.
# @return array of (address, size) or (not-defined, not-defined).
#
sub findSymbolAddress
{
    my $name = shift;

    parseSymbolFile();

    return ($symbolAddress{$name}, $symbolSize{$name} );
}

# @sub findSymbolTOCAddress
# Searches a syms file for the address of the TOC of a symbol.
#
# @param string - Symbol to search for.
# @return TOC address or 'not-defined'.
#
sub findSymbolTOCAddress
{
    my $name = shift;

    parseSymbolFile();

    return $symbolTOC{$name};
}

# @sub findSymbolByAddress
#
# Searchs a syms file for the symbol name at a particular address.
#
# @param integer - Address to search for.
# @return string name of symbol or not-defined.
#
sub findSymbolByAddress
{
    my $addr = shift;

    parseSymbolFile();

    return $addressSymbol{$addr};
}

# @sub findSymbolWithinAddrRange
#
# Searches a syms file for the symbol name for a given address that might not be
# the beginning of the symbol, and returns the symbol name and offset within
# symbol
#
# @param[in] i_addr Address to locate, within some symbol
# @return On success, string name of symbol + offset within symbol.  On failure,
#     UNKNOWN + 0
#
sub findSymbolWithinAddrRange
{
    my $i_addr = shift;

    parseSymbolFile();

    my $found = 0;
    my $symName = undef;
    my $symOff = 0;
    foreach my $sym (sort { $a <=> $b } keys %addrRangeHash)
    {
        if(   ($i_addr >= $sym)
           && ($i_addr <= ($sym+$addrRangeHash{$sym}{size})) )
        {
            $symName = $addrRangeHash{$sym}{name};
            $symOff = ($i_addr - $sym);
            last;
        }

    }

    if(!defined $symName)
    {
        $symName = "UNKNOWN";
        $symOff = 0;
    }

    return ($symName , $symOff) ;
}

# @sub parseModuleFile <INTERNAL ONLY>
#
# Parses through a .modinfo file and populates a hash.
#
sub parseModuleFile
{
    if ($parsedModuleFile) { return; }

    my $modFile = ::getImgPath();
    if (::getIsTest())
    {
        $modFile = $modFile."hbicore_test.bin.modinfo";
    }
    else
    {
        $modFile = $modFile."hbicore.bin.modinfo";
    }

    open(FILE, "< $modFile") or die "Cannot open module-info file $modFile";
    while (my $line = <FILE>)
    {
        $line =~ m/(.*?),(.*)/;
        $moduleAddress{$1} = hex $2;
    }
    close(FILE);

    $parsedModuleFile = 1;
}

# @sub findSymbolByAddress
#
# Searchs a modinfo file for the module owning a particular address.
#
# @param integer - Address to search for.
# @return string name of module or "".
#
sub findModuleByAddress
{
    my $addr = shift;

    parseModuleFile();

    my $addrF = -1;
    my $modName = "";

    foreach my $mod (keys %moduleAddress)
    {
        if (($moduleAddress{$mod} <= $addr) and
            ($moduleAddress{$mod} > $addrF))
        {
            $addrF = $moduleAddress{$mod};
            $modName = $mod;
        }
    }

    return $modName;
}

# @sub listModules
#
# Returns a list of all module names.
#
# @return list of modules found in the modinfo file.
sub listModules
{
    parseModuleFile();

    return keys %moduleAddress;
}

# @sub littleendian
#
# Utility function to determine if the current machine is little or big
# endian.
#
# @return true if machine is little-endian.
#
sub littleendian
{
    return (unpack("L", pack("N", 0xabcd1234)) != 0xabcd1234);
}

# @sub read64
#
# Reads a 64-bit unsigned integer from an address.
#
# @param Address to read from.
# @return Value.
#
sub read64
{
    my $addr = shift;

    my $result = ::readData($addr, 8);
    if (littleendian()) { $result = reverse($result); }

    return unpack("Q", $result);
}

# @sub read32
#
# Reads a 32-bit unsigned integer from an address.
#
# @param Address to read from.
# @return Value.
#
sub read32
{
    my $addr = shift;

    my $result = ::readData($addr, 4);
    if (littleendian()) { $result = reverse($result); }

    return unpack("L", $result);
}

# @sub read16
#
# Reads a 16-bit unsigned integer from an address.
#
# @param Address to read from.
# @return Value.
#
sub read16
{
    my $addr = shift;

    my $result = ::readData($addr, 2);
    if (littleendian()) { $result = reverse($result); }

    return unpack("S", $result);
}

# @sub read8
#
# Reads a 8-bit unsigned integer from an address.
#
# @param Address to read from.
# @return Value.
#
sub read8
{
    my $addr = shift;

    my $result = ::readData($addr, 1);

    return unpack("C", $result);
}

# @sub readStr
#
# Reads a string from an address.
#
# @param Address to read from.
# @return Value.
#
sub readStr
{
    my $addr = shift;

    my $result = "";
    my $byte = 0;

    do
    {
        $byte = read8($addr);
        $addr += 1;

        if ($byte != 0)
        {
            $result = $result.pack("C",$byte);
        }
    } while ($byte != 0);

    return $result;
}

# @sub write64
#
# Write a 64-bit unsigned integer to an address.
#
# @param Address to write to.
# @param Value to write
#
sub write64
{
    my $addr = shift;
    my $value = shift;

    $value = pack("Q", $value);
    if (littleendian()) { $value = reverse($value); }

    my $result = ::writeData($addr, 8, $value);
}

# @sub write32
#
# Write a 32-bit unsigned integer to an address.
#
# @param Address to write to.
# @param Value to write
#
sub write32
{
    my $addr = shift;
    my $value = shift;

    $value = pack("L", $value);
    if (littleendian()) { $value = reverse($value); }

    my $result = ::writeData($addr, 4, $value);
}

# @sub write16
#
# Write a 16-bit unsigned integer to an address.
#
# @param Address to write to.
# @param Value to write
#
sub write16
{
    my $addr = shift;
    my $value = shift;

    $value = pack("S", $value);
    if (littleendian()) { $value = reverse($value); }

    my $result = ::writeData($addr, 2, $value);
}

# @sub write8
#
# Write a 8-bit unsigned integer to an address.
#
# @param Address to write to.
# @param Value to write
#
sub write8
{
    my $addr = shift;
    my $value = shift;

    $value = pack("C", $value);

    my $result = ::writeData($addr, 1, $value);
}

# @sub translateHRMOR
#
# Translate an address with the HRMOR if necessary.
#
# In the event that the most-significant-bit is on, then the HRMOR should be
# bypassed, otherwise the HRMOR is applied.
#
# @param Address to translate.
#
sub translateHRMOR
{
    my $addr = shift;

    if (0 != ($addr & 0x8000000000000000))
    {
        $addr &= 0x7FFFFFFFFFFFFFFF;
    }
    else
    {
        $addr += ::getHRMOR();
    }

    return $addr;
}

# @sub  getIstepList
#
#   get an array of all the supported istep names from the
#   "isteplist.csv" file
#
#   @return   array of lines in the file
#
sub getIstepList
{
    my $isteplistFile = ::getImgPath();

    $isteplistFile = $isteplistFile . "isteplist.csv";

    open(FILE, "< $isteplistFile")
        or die "Cannot open isteplist file $isteplistFile";

    my  @isteplist  =   <FILE>;

    close   FILE    or die "cannot close isteplist file";


    return  @isteplist;
}

__END__
