#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Printk.pm $
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

package Hostboot::Printk;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
    ::userDisplay "------------Kernel Printk Parser------------\n";
    my ($symAddr, $symSize) = ::findSymbolAddress("kernel_printk_buffer");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }
    ::userDisplay ::readData($symAddr,$symSize);
    ::userDisplay "--------------------------------------------\n";
}

sub help
{
    ::userDisplay "Tool: Printk\n";
    ::userDisplay "\tDisplays the printk buffer.\n";
}
