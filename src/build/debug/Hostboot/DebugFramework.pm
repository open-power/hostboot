#!/usr/bin/perl

# DebugFramework.pm
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

package Hostboot::DebugFramework;
use Exporter 'import';

our @EXPORT = ( 'callToolModule', 'callToolModuleHelp',
                'parseToolOpts', 'determineImagePath',
                'findSymbolAddress', 'findSymbolByAddress',
                'findModuleByAddress',
                'littleendian',
                'read64', 'read32', 'read16', 'read8', 'readStr'
              );

our ($parsedSymbolFile, %symbolAddress, %addressSymbol, %symbolSize);
our ($parsedModuleFile, %moduleAddress);
our (%toolOpts);

BEGIN
{
    $parsedSymbolFile = 0;
    %symbolAddress = ();
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

    eval("use lib '.'; use $package; return 1;") or 
            die "Couldn't load tool \"$tool\"";
    eval("$package->main(\\%toolOpts);");
}

# @sub callToolModuleHelp
#
# Executes the 'help' function of the requested tool module to display 
# tool usage.
#
# @param string - Tool to call.
#
sub callToolModuleHelp
{
    my $tool = shift;
    my $package = "Hostboot::$tool";

    eval("use lib '.'; use $package; return 1;") or 
            die "Couldn't load tool \"$tool\"";
    eval("$package->help(\\%toolOpts);");
}

# @sub parseToolOpts
#
# Parses a space deliminated string of options for use by the tool.
#
# @param string - Tool option list.
#
# Example: "foo bar=/abcd/efg" --> { "foo" => 1 , "bar" => "/abcd/efg" }
#
sub parseToolOpts
{
    my $toolOptions = shift;
    foreach my $opt (split / /, $toolOptions)
    {
        if ($opt =~ m/=/)
        {
            my ($name,$value) = split /=/, $opt;
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
    
    open(FILE, "< $symsFile") or die;
    while (my $line = <FILE>)
    {
        $line =~ m/(.*?),(.*?),(.*?),(.*?),(.*)/;
        my $name = $5;        
        my $addr = hex $2;
        my $tocAddr = hex $3;
        my $size = hex $4;
        
        $symbolAddress{$name} = $addr;
        $symbolSize{$name} = $size;
        $addressSymbol{$addr} = $name;
        $addressSymbol{$tocAddr} = $name;
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

    open(FILE, "< $modFile") or die;
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

__END__
