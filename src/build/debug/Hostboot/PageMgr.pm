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
use constant BUCKETS => 12;
use constant BUCKETS_LOWER => 2;

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
# find PageManager addr
# print PAGEMGR_INSTANCE data
# print iv_heap data
# print iv_reserved data
# Usage: PageMgr             print summary of buckets
#                [debug]     print how many blocks in each bucket
#                [showpages] print buckets and all page addrs in each bucket
################################################################################
sub main
{
    my ($packName, $args) = @_;

    ###################
    # setup debug flags
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

    ######################
    # get PageManager addr
    my ($symAddr, $symSize) = ::findPointer("PAGEMINS", PAGEMGR_INSTANCE);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find".PAGEMGR_INSTANCE."\n";
        die;
    }

    ###############################
    # collect PAGEMGR_INSTANCE data

    my $pagesTotal = ::read64($symAddr);

    if ($pagesTotal == 0)
    {
        ::userDisplay "data is unavailable at this time\n";
        return;
    }

    $symAddr += 8;      # cv_pagesTotal
    $symAddr += 8;      # cv_allocatePage_coalesce_wait

    ######################
    # collect iv_heap data

    $symAddr += (BUCKETS*8); # cv_free_bucket_count
    $symAddr += (BUCKETS*8); # cv_alloc_sizes

    my $cv_free_pages_heap = ::read64($symAddr);

    $symAddr += 8;      # cv_free_pages
    $symAddr += 8;      # cv_low_page_count
    $symAddr += 8;      # cv_coalesce_state
    $symAddr += 8;      # cv_coalesce_attempts
    $symAddr += 8;      # cv_coalesce_count

    ::userDisplay "pagesTotal: $pagesTotal\n";
    ::userDisplay " Heap\n";

    my $pagesInBuckets_heap = 0;

    $pagesInBuckets_heap += countLowerBuckets($symAddr,
                                              $debug,
                                              $showpages);

    $symAddr += 2*8; # iv_heap_lower (num:2 * size:8)

    $pagesInBuckets_heap += countUpperBuckets($symAddr,
                                              $debug,
                                              $showpages);

    ::userDisplay "   cv_free_pages:           $cv_free_pages_heap\n";
    ::userDisplay "   actual pages in buckets: $pagesInBuckets_heap\n";
    if ($cv_free_pages_heap != $pagesInBuckets_heap)
    {
        my $difference = abs ($cv_free_pages_heap - $pagesInBuckets_heap);
        ::userDisplay "WARNING: Values differ by $difference!!\n";
    }

    $symAddr += BUCKETS*32; # iv_heap_upper (num:BUCKETS * size:32)
    $symAddr += 4;          # iv_supports_coalesce
    $symAddr += 4;          # pad1
    $symAddr += 24;         # iv_spinlock
    $symAddr += (4*16);     # iv_ranges (num:4 * size:16)

    ##########################
    # collect iv_reserved data

    $symAddr += (BUCKETS*8); # cv_free_bucket_count
    $symAddr += (BUCKETS*8); # cv_alloc_sizes

    my $cv_free_pages_reserved = ::read64($symAddr);

    $symAddr += 8;      # cv_free_pages
    $symAddr += 8;      # cv_low_page_count
    $symAddr += 8;      # cv_coalesce_state
    $symAddr += 8;      # cv_coalesce_attempts
    $symAddr += 8;      # cv_coalesce_count

    ::userDisplay " Reserved\n";

    my $pagesInBuckets_reserved = 0;

    $pagesInBuckets_reserved += countLowerBuckets($symAddr,
                                                  $debug,
                                                  $showpages);

    $symAddr += 2*8; # iv_heap_lower (num:2 * size:8)

    $pagesInBuckets_reserved += countUpperBuckets($symAddr,
                                                  $debug,
                                                  $showpages);


    ::userDisplay "   cv_free_pages:           $cv_free_pages_reserved\n";
    ::userDisplay "   actual pages in buckets: $pagesInBuckets_reserved\n";
    if ($cv_free_pages_reserved != $pagesInBuckets_reserved)
    {
        my $difference = abs ($cv_free_pages_reserved - $pagesInBuckets_reserved);
        ::userDisplay "WARNING: Values differ by $difference!!\n";
    }
}

################################################################################
# foreach Stack in the lower buckets
#   call countItemsInStack to traverse and count the elements
#   if showpages then call showPagesInStack to traverse and print each element
sub countLowerBuckets
{
    my ($symAddr, $debug, $showpages) = (@_);

    my $pagesInBuckets = 0;

    for (my $bucket = 0; $bucket < BUCKETS_LOWER; $bucket++)
    {
        my $stackAddr = ::read32($symAddr + (8 * $bucket) + 4);

        my $stackCount = countItemsInStack($stackAddr);
        my $count = (1 << $bucket) * $stackCount;

        $pagesInBuckets += $count;
        my $size         = 1<<$bucket;

        if ($count && ($debug || $showpages))
        {
            my $str = sprintf "      Bucket %2d has %3d blocks with a total of %5d pages\n",
                              $bucket, $stackCount, $count;
            ::userDisplay $str;
        }
        if ($showpages)
        {
            showPagesInStack($stackAddr,(1 << $bucket));
        }
    }
    return $pagesInBuckets;
}

################################################################################
# follow (page_t*)->next through the Stack
sub countItemsInStack
{
    my $stack = shift;

    return 0 if (0 == $stack);

    #only read bottom 32 bits of ptr to handle AbaPtr
    return 1 + countItemsInStack(::read32($stack + 4));
}

################################################################################
# follow (page_t*)->next through the Stack
sub showPagesInStack
{
    my $stack      = shift;
    my $bucketsize = shift;

    return 0 if (0 == $stack);

    ::userDisplay(sprintf "            0x%.16X..0x%.16X : size:%d\n",
                  $stack, $stack+4096*$bucketsize, $bucketsize);

    #only read bottom 32 bits of ptr to handle AbaPtr
    return 1 + showPagesInStack(::read32($stack+4),$bucketsize);
}

################################################################################
# foreach PQueue in the upper buckets
#   call traversePQueue to traverse and count the elements
#   if showpages then call traversePQueue to traverse and print each element
sub countUpperBuckets
{
    my ($symAddr, $debug, $showpages) = (@_);

    my $pagesInBuckets = 0;

    for (my $bucket = 2; $bucket < BUCKETS; $bucket++)
    {
        my $pqAddr = ::read64($symAddr + (32 * $bucket));

        my ($numElements, $numPages) = traversePQueue($pqAddr,0);

        $pagesInBuckets += $numPages;

        if ($numElements && ($debug || $showpages))
        {
            my $str = sprintf "      Bucket %2d has %3d blocks with a total of %5d pages\n",
                              $bucket, $numElements, $numPages;
            ::userDisplay $str;
        }
        $showpages and traversePQueue($pqAddr, 1);
    }
    return $pagesInBuckets;
}

################################################################################
# follow (page_t*)->next through the PQueue and add in the size (page_t*)->key
sub traversePQueue
{
    my ($symAddr, $showpages) = (@_);
    my $numElements=0;
    my $numPages=0;
    my $size;

    while ($symAddr)
    {
        $numElements += 1;
        $size         = ::read64($symAddr+16); # read (page_t*)->key
        if ($showpages)
        {
            ::userDisplay(sprintf "            0x%.16X..0x%.16X : size:%d\n",
                     $symAddr, $symAddr+4096*$size, $size);
        }
        $symAddr   = ::read64($symAddr); # read (page_t*)->next
        $numPages += $size;
    }
    return ($numElements, $numPages);
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
