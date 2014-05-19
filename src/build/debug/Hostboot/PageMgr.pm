#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/PageMgr.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
    my $showpages = 0;
    if (defined $args->{"showpages"})
    {
        $showpages = 1;
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

        if( $debug && $showpages ) {
            showPagesInStack($stackAddr,(1 << $bucket));
        }
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

sub showPagesInStack
{
    my $stack = shift;
    my $bucketsize = shift;

    return 0 if (0 == $stack);

    ::userDisplay(sprintf "..mem=0x%.16X..0x%.16X : %d\n",
                  $stack, $stack+4096*$bucketsize, $bucketsize );

    return 1 + showPagesInStack(::read64($stack),$bucketsize);
}

sub helpInfo
{
    my %info = (
        name => "PageMgr",
        intro => ["Calculates free pages in Kernel PageManager."],
        options => { "debug" => ["Turn on additional debug messages"], },
    );
}
