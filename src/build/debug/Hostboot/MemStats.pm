# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/MemStats.pm $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
use strict;

package Hostboot::MemStats;
use Exporter;
our @EXPORT_OK = ('main');

use constant HEAPMGR_INSTANCE_NAME =>
                "Singleton<HeapManager>::instance()::instance";
use constant HEAPMGR_CHUNK_OFFSET => 0;
#use constant HEAPMGR_BIGCHUNK_OFFSET => 0;
use constant HEAPMGR_NUMBER_OF_BUCKETS => 12;
use constant MIN_BUCKET_SIZE => 16;
use constant FIB_START_INCR => 16;

sub main
{
    my ($packName, $args) = @_;

    my $countchunks = 0;
    if (defined $args->{"count"})
    {
        ::userDisplay "counting chunks";
        $countchunks = 1;
    }
    my $showchunks = 0;
    if (defined $args->{"show"})
    {
        ::userDisplay "showing chunks";
        $showchunks = 1;
    }

    my ($heap_manager_addr, $symSize) =
        ::findSymbolAddress(HEAPMGR_INSTANCE_NAME);

    my @page_manager_addr =
        ::findSymbolAddress("Singleton<PageManager>::instance()::instance");

    my $free_pages =
        ::read64 @page_manager_addr;

    my $total_pages =
        ::read64 ($page_manager_addr[0] + 8, 8);

    my $free_min =
        ::read64 ::findSymbolAddress("PageManager::cv_low_page_count");

    my $page_coal =
        ::read64 ::findSymbolAddress("PageManager::cv_coalesce_count");

    my $big_heap_pages_used =
        ::read32 ::findSymbolAddress("HeapManager::cv_largeheap_page_count");

    my $big_heap_max =
        ::read32 ::findSymbolAddress("HeapManager::cv_largeheap_page_max");

    my $small_heap_pages_used =
        ::read32 ::findSymbolAddress("HeapManager::cv_smallheap_page_count");

    my $heap_coal =
        ::read32 ::findSymbolAddress("HeapManager::cv_coalesce_count");

    my $heap_free =
        ::read32 ::findSymbolAddress("HeapManager::cv_free_bytes");

    my $heap_free_chunks =
        ::read32 ::findSymbolAddress("HeapManager::cv_free_chunks");

    my $heap_total = $big_heap_pages_used + $small_heap_pages_used;
    my $heap_max = $big_heap_max + $small_heap_pages_used;


    my $castout_ro =
        ::read32 ::findSymbolAddress("Block::cv_ro_evict_req");

    my $castout_rw =
        ::read32 ::findSymbolAddress("Block::cv_rw_evict_req");


    ::userDisplay "===================================================\n";
    ::userDisplay "MemStats:\n";
    ::userDisplay "    Total pages available:   $total_pages\n";
    ::userDisplay "    Free pages:              $free_pages\n";
    ::userDisplay "    Free pages Low mark:     $free_min\n";
    ::userDisplay "    Page chunks coalesced:   $page_coal\n";
    ::userDisplay "\nHeap:\n";
    ::userDisplay "    Pages used by heap:      $heap_total  ".
                  "(B:$big_heap_pages_used,S:$small_heap_pages_used)\n";
    ::userDisplay "    Max. Pages used by heap: $heap_max\n";
    ::userDisplay "    heap free bytes/chunks   $heap_free/$heap_free_chunks (valid only after a coalescing)\n";
    ::userDisplay "    Heap chunks coalesced:   $heap_coal\n";
    ::userDisplay "\nVirtual Memory Manager page eviction requests:\n";
    ::userDisplay "    RO page requests:        $castout_ro\n";
    ::userDisplay "    RW page requests:        $castout_rw\n";
    ::userDisplay "===================================================\n";

    if( $showchunks )
    {
        ::userDisplay "Show Buckets - ";
        #Show the entire heap
        ::userDisplay(sprintf("HeapManager at 0x%X\n",$heap_manager_addr));
        my $bucketsize = MIN_BUCKET_SIZE;
        my $oldbucketsize = MIN_BUCKET_SIZE;
        for (my $bucket = 0; $bucket <  HEAPMGR_NUMBER_OF_BUCKETS; $bucket++)
        {
                my $stackAddr =
                    ::read32($heap_manager_addr + HEAPMGR_CHUNK_OFFSET +
                             (8 * $bucket) + 4);
                ::userDisplay(sprintf("%d : stackaddr=0x%.8X\n",
                                      $bucket,$stackAddr) );

                showPagesInStack($stackAddr,$bucket,$bucketsize);

                my $tmpsize = $bucketsize;
                $bucketsize = $bucketsize + $oldbucketsize;
                $oldbucketsize = $tmpsize;
        }
    }

    if( $countchunks )
    {
        ::userDisplay "Show Buckets - ";
        #Show the entire heap
        ::userDisplay( sprintf("HeapManager at 0x%X\n",$heap_manager_addr) );
        my $bucketsize = MIN_BUCKET_SIZE;
        my $oldbucketsize = MIN_BUCKET_SIZE;
        for (my $bucket = 0; $bucket < HEAPMGR_NUMBER_OF_BUCKETS; $bucket++)
        {
                my $stackAddr =
                    ::read32($heap_manager_addr + HEAPMGR_CHUNK_OFFSET +
                             (8 * $bucket) + 4);

                my $numchunks = countChunks($stackAddr);

                ::userDisplay(
                    sprintf("Bucket %d(=%d) has %d chunks = %d bytes\n",
                            $bucket,$bucketsize,$numchunks,
                            $bucketsize*$numchunks));

                my $tmpsize = $bucketsize;
                $bucketsize = $bucketsize + $oldbucketsize;
                $oldbucketsize = $tmpsize;
        }
    }
}

sub helpInfo
{
    my %info = (
        name => "MemStats",
        intro => ["Displays Hostboot memory usage information."],
    );
}

sub showPagesInStack
{
    my $stack = shift;
    my $bucket = shift;
    my $bucketsize = shift;
    ::userDisplay(sprintf "..stack=0x%.8X-0x%.8X : %d=%d bytes\n",
                  $stack,$stack+$bucketsize,$bucket,$bucketsize);

    return 0 if (0 == $stack);

    return 1 + showPagesInStack(::read64($stack+8),$bucket,$bucketsize);
}

sub countChunks
{
    my $stack = shift;

    return 0 if (0 == $stack);

    return 1 + countChunks(::read64($stack+8));
}
