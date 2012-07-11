#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/PageMgr.pm $
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

package Hostboot::PageMgr;
use Exporter;
our @EXPORT_OK = ('main');

use constant PAGEMGR_INSTANCE_NAME =>
                "Singleton<PageManager>::instance()::instance";
use constant PAGEMGR_CORE_OFFSET => 3 * 8;
use constant PAGEMGR_PAGES_AVAIL_OFFSET => 0;
use constant PAGEMGR_BUCKETS_OFFSET => 8;
use constant PAGEMGR_NUMBER_OF_BUCKETS => 16;


sub main
{
    my ($packName, $args) = @_;

    # Parse 'debug' option.
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    # Find the PageManager
    my ($symAddr, $symSize) = ::findSymbolAddress(PAGEMGR_INSTANCE_NAME);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find ".PAGEMGR_INSTANCE_NAME;
        die;
    }
    # Increment to the PageManagerCore for the general heap.
    $symAddr = $symAddr + PAGEMGR_CORE_OFFSET;

    # Read pages available.
    my $pagesAvail = ::read64($symAddr + PAGEMGR_PAGES_AVAIL_OFFSET);
    ::userDisplay "Pages available: ".$pagesAvail."\n";

    # Parse through buckets and count pages in buckets.
    my $pagesInBuckets = 0;

    for (my $bucket = 0; $bucket <  PAGEMGR_NUMBER_OF_BUCKETS; $bucket++)
    {
        my $stackAddr = ::read32($symAddr + PAGEMGR_BUCKETS_OFFSET +
                                 (8 * $bucket) + 4);

        my $stackCount = countItemsInStack($stackAddr);
        my $size = (1 << $bucket) * $stackCount;

        $pagesInBuckets = $pagesInBuckets + $size;

        ::userDisplay "Bucket $bucket has $stackCount blocks for ".
                      "$size pages.\n" if $debug;
    }

    ::userDisplay "Pages in buckets: ".$pagesInBuckets."\n";

    # Compare if they match.  Hopefully they do.
    if ($pagesAvail != $pagesInBuckets)
    {
        my $difference = abs ($pagesAvail - $pagesInBuckets);
        ::userDisplay "WARNING: Values differ by $difference!!\n";
    }
}

sub countItemsInStack
{
    my $stack = shift;

    return 0 if (0 == $stack);

    return 1 + countItemsInStack(::read64($stack));
}

sub helpInfo
{
    my %info = (
        name => "PageMgr",
        intro => ["Calculates free pages in Kernel PageManager."],
        options => { "debug" => ["Turn on additional debug messages"], },
    );
}
