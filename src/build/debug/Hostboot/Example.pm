#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Example.pm $
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

use strict;

package Hostboot::Example;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
    ::userDisplay "Welcome to the example module.\n";
    ::userDisplay "Calling 'usage', which will exit...\n";
    ::usage();
    ::userDisplay "Should never get here.\n";

    return 0;
}

sub help
{
    ::userDisplay "Tool: Example\n";
    ::userDisplay "\tDoesn't really do anything special.\n";
}
