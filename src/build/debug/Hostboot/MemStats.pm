use strict;

package Hostboot::MemStats;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
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
    ::userDisplay "    Pages used by heap:      $heap_total\n";
    ::userDisplay "    Max. Pages used by heap: $heap_max\n";
    ::userDisplay "    heap free bytes/chunks   $heap_free/$heap_free_chunks (valid only after a coalescing)\n";
    ::userDisplay "    Heap chunks coalesced:   $heap_coal\n";
    ::userDisplay "\nVirtual Memory Manager page eviction requests:\n";
    ::userDisplay "    RO page requests:        $castout_ro\n";
    ::userDisplay "    RW page requests:        $castout_rw\n";
    ::userDisplay "===================================================\n";

}

sub help
{
    ::userDisplay "Tool: MemStats\n";
    ::userDisplay "\tDisplays Hostboot memory usage information\n";
}
