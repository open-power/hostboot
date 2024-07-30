#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/PageMgr.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2024
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

use strict;

package Hostboot::PageMgr;
use Exporter;
our @EXPORT_OK = ('main');

use constant PAGEMGR_INSTANCE => "Singleton<PageManager>::instance()::instance";
use constant PAGEMGR_NUMBER_OF_BUCKETS => 16;

################################################################################
# read and dump bytes from the addr passed in, for debug
sub dump_bytes_32
{
    my $addr = shift @_;
    my $num = shift @_;
    my $d;
    my $str;
    ::userDisplay "-----------------------\n";
    for (my $i=0; $i<$num; $i++)
    {
        $d = ::read32 ($addr);
        $str = sprintf("%08x %08x\n", $addr, $d);
        ::userDisplay "$str";
        $addr += 4;
    }
}

################################################################################
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

    # Find the marker for the addr
    my ($symAddr, $symSize) = ::findPointer("PAGEMINS", PAGEMGR_INSTANCE);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find".PAGEMGR_INSTANCE."\n";
        die;
    }

    ##################
    # PAGEMGR_INSTANCE

    my $pagesTotal = ::read64($symAddr);
    ::userDisplay "pagesTotal: $pagesTotal\n";

    $symAddr += 8;      # cv_pagesTotal
    $symAddr += 8;      # cv_allocatePage_coalesce_wait

    ##################
    # iv_heap

    $symAddr += (PAGEMGR_NUMBER_OF_BUCKETS*8); # cv_free_bucket_count
    $symAddr += (PAGEMGR_NUMBER_OF_BUCKETS*8); # cv_alloc_sizes

    my $pagesAvail = ::read64($symAddr);
    ::userDisplay " Heap\n";
    ::userDisplay "   pagesAvail counter: $pagesAvail\n";

    $symAddr += 8;      # cv_free_pages
    $symAddr += 8;      # cv_low_page_count
    $symAddr += 8;      # cv_coalesce_state
    $symAddr += 8;      # cv_coalesce_attempts
    $symAddr += 8;      # cv_coalesce_count

    # Parse through buckets and count pages in buckets.
    my $pagesInBuckets = 0;

    $pagesInBuckets = countBuckets($symAddr,
                                   $debug,
                                   $showpages);

    ::userDisplay "   pages in buckets:   ".$pagesInBuckets."\n";

    # Compare if they match.  Hopefully they do.
    if ($pagesAvail != $pagesInBuckets)
    {
        my $difference = abs ($pagesAvail - $pagesInBuckets);
        ::userDisplay "WARNING: Values differ by $difference!!\n";
    }

    $symAddr += (16*8); # iv_heap[BUCKETS]
    $symAddr += 4;      # iv_supports_coalesce
    $symAddr += 4;      # pad1
    $symAddr += 24;     # iv_spinlock
    $symAddr += (16*4); # iv_ranges

    ##################
    # iv_reserved

    $symAddr += (16*8); # cv_free_bucket_count
    $symAddr += (16*8); # cv_alloc_sizes

    $pagesAvail = ::read64($symAddr);
    ::userDisplay " Reserved\n";
    ::userDisplay "   pagesAvail counter: $pagesAvail\n";

    $symAddr += 8;      # cv_free_pages
    $symAddr += 8;      # cv_low_page_count
    $symAddr += 8;      # cv_coalesce_state
    $symAddr += 8;      # cv_coalesce_attempts
    $symAddr += 8;      # cv_coalesce_count

    $pagesInBuckets = countBuckets($symAddr,
                                   $debug,
                                   $showpages);

    ::userDisplay "   pages in buckets:   ".$pagesInBuckets."\n";

    # Compare if they match.  Hopefully they do.
    if ($pagesAvail != $pagesInBuckets)
    {
        my $difference = abs ($pagesAvail - $pagesInBuckets);
        ::userDisplay "WARNING: Values differ by $difference!!\n";
    }
}

################################################################################
sub countBuckets
{
    my ($symAddr, $debug, $showpages) = (@_);

    my $pagesInBuckets = 0;

    for (my $bucket = 0; $bucket < PAGEMGR_NUMBER_OF_BUCKETS; $bucket++)
    {
        my $stackAddr = ::read32($symAddr + (8 * $bucket) + 4);

        my $stackCount = countItemsInStack($stackAddr);
        my $count = (1 << $bucket) * $stackCount;

        $pagesInBuckets += $count;
        my $size         = 1<<$bucket;

        if ($count)
        {
            ::userDisplay "      Bucket $bucket/$size has $stackCount blocks for ".
                          "$count pages.\n" if $debug;
        }
        if( $debug && $showpages ) {
            showPagesInStack($stackAddr,(1 << $bucket));
        }
    }
    return $pagesInBuckets;
}

################################################################################
sub countItemsInStack
{
    my $stack = shift;

    return 0 if (0 == $stack);

    #only read bottom 32 bits of ptr to handle AbaPtr
    return 1 + countItemsInStack(::read32($stack + 4));
}

################################################################################
sub showPagesInStack
{
    my $stack = shift;
    my $bucketsize = shift;

    return 0 if (0 == $stack);

    ::userDisplay(sprintf "..mem=0x%.16X..0x%.16X : %d\n",
                  $stack, $stack+4096*$bucketsize, $bucketsize );

    #only read bottom 32 bits of ptr to handle AbaPtr
    return 1 + showPagesInStack(::read32($stack+4),$bucketsize);
}

################################################################################
sub helpInfo
{
    my %info = (
        name => "PageMgr",
        intro => ["Calculates free pages in Kernel PageManager."],
        options => { "debug" => ["Turn on additional debug messages"], },
    );
}
