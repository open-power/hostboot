#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/simics-debug-framework.pl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
#  IBM_PROLOG_END

# @file simics-debug-framework.pl
# @brief Implementation of the common debug framework for running in simics.
#
# Simics uses Python for all debug.  This file is a Perl bridge between Python
# and the framework tool modules.  The Python side will create a sub-process of
# this script using STDIN/STDOUT as an IPC message pipe.  This side will
# execute the Perl module and send data / output across the pipe to the Python
# side.

use strict;
use Hostboot::_DebugFramework;

$| = 1; # Disable buffering on STDIN/STDOUT.

# @sub sendIPCMsg
# @brief Sends a message to the Python side of the framework over STDOUT.
#
# Messages are of the format:
#       [ "type", "data-in-ascii-encoded-hex" ]
# Example:
#    The message...
#       [ "display", "48656c6c6f20576f726c642e0a" ]
#    means 'display "Hello World.\n"'
sub sendIPCMsg
{
    my ($type, $data) = @_;

    print "[ \"$type\", \"".unpack("H*",$data)."\" ]\n";
}

# @sub recvIPCMsg
# @brief Watis for a message from the Python side of the framework from STDIN.
#
# See sendIPCMsg for message format.
sub recvIPCMsg
{
    my $type = "";
    my $data = "";

    if (my $string = <STDIN>)
    {
        if ($string =~ m/\[ \"([^\"]+)\", \"([0-9a-f]*)\" ]\n/)
        {
            $type = $1;
            $data = pack("H*", $2);
        }
    }

    return ($type, $data);
}

# @sub userDisplay
# @brief Send a 'display' type message to Python.
sub userDisplay
{
    my $string = "";

    foreach my $value (@_)
    {
        $string = $string . $value;
    }

    sendIPCMsg("display", $string);
}

# @sub readData
# @brief Send a 'read-data' type message to Python.
sub readData
{
    my $addr = shift;
    my $size = shift;

    sendIPCMsg("read-data", "$addr,$size");

    my ($type, $data) = recvIPCMsg();

    if (length($data) == $size)
    {
        return $data;
    }

    return "";
}

# @sub writeData
# @brief Send a 'write-data' type message to Python.
sub writeData
{
    my $addr = shift;
    my $size = shift;
    my $value = shift;

    my $value = unpack("H*", $value);
    sendIPCMsg("write-data", "$addr,$size,$value");

    return;
}

# @sub executeInstrCycles
# @brief Send a 'execute-instrs' type message to Python.
sub executeInstrCycles
{
    my $cycles = shift;
    sendIPCMsg("execute-instrs", "$cycles");
}

# @sub readyForInstructions
# @brief Send a 'ready-for-instr' type message to Python.
# @returns 0 - Not ready or 1 - Ready
sub readyForInstructions
{
    sendIPCMsg("ready-for-instr", "");

    my ($type, $data) = recvIPCMsg();
    if ("1" eq $data)
    {
        return 1;
    }
    return 0;
}

# Image path global.
my $imgPath = "";
sub getImgPath
{
    return $imgPath;
}

# Simics always uses the non-test named files.
sub getIsTest
{
    return 0;
}


# Get tool name.
sendIPCMsg("get-tool","");
my ($unused, $tool) = recvIPCMsg();

# If we were called with --usage, send tool help instead of executing.
if ((-1 != $#ARGV) && ("--usage" eq $ARGV[0]))
{
    callToolModuleHelp($tool);
    exit;
}

# Get tool options, image path.
sendIPCMsg("get-tool-options","");
my ($unused, $toolOpts) = recvIPCMsg();
sendIPCMsg("get-img-path");
($unused, $imgPath) = recvIPCMsg();

# Update image path, parse options.
$imgPath = determineImagePath();
parseToolOpts($toolOpts);

# Execute module.
callToolModule($tool);

