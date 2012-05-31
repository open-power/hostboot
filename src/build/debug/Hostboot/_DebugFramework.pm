#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/_DebugFramework.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011-2012
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

our @EXPORT = ( 'callToolModule', 'callToolModuleHelp', 'callToolModuleHelpInfo',
                'parseToolOpts', 'determineImagePath',
                'findSymbolAddress', 'findSymbolTOCAddress',
                'findSymbolByAddress',
                'findModuleByAddress', 'listModules',
                'littleendian',
                'read64', 'read32', 'read16', 'read8', 'readStr',
                'write64', 'write32', 'write16', 'write8',
                'getIstepList'
              );

our ($parsedSymbolFile, %symbolAddress, %symbolTOC,
     %addressSymbol, %symbolSize);
our ($parsedModuleFile, %moduleAddress);
our (%toolOpts);

BEGIN
{
    $parsedSymbolFile = 0;
    %symbolAddress = ();
    %symbolTOC = ();
    %addressSymbol = ();
    %symbolSize = ();

    $parsedModuleFile = 0;
    %moduleAddress = ();

    %toolOpts = ();
}
return 1;

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
            $imgPath = $ENV{"HOSTBOOTROOT"} . "/img/";
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
    if (::getIsTest())
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
