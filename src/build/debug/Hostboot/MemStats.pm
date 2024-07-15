# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/MemStats.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2024
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

# Functions to read and display Hostboot Kernel Memory Statistics
#  There are three ways to invoke.
#  1. MemStats         : Show the live Statistics
#  2. MemStats summary : Show a summary of the Memory trace entries
#  3. MemStats trace   : Show the full details of the Memory trace entries

use strict;
use Switch;

package Hostboot::MemStats;
use Exporter;
use Hostboot::SimpleTraceCommon;
our @EXPORT_OK = ('main');

use constant PAGEMGR_NUMBER_OF_BUCKETS => 16;
use constant HEAPMGR_NUMBER_OF_BUCKETS => 12;

################################################################################
sub helpInfo
{
    my %info = (
        name    => "MemStats",
        intro   => ["Displays Hostboot kernel memory statistics"],
        options => {"summary" => ["A shortened list of the available trace entries"],
                    "trace"   => ["The full details of all the trace entries"]
                   },
               );
}

################################################################################
# read and dump bytes from the addr passed in, for debug
sub dump_bytes
{
    my $addr = shift @_;
    my $d;
    my $str;
    for (my $i=0; $i<24; $i++)
    {
        $d = ::read32 ($addr);
        $str = sprintf("%08x %08x\n", $addr, $d);
        ::userDisplay "$str";
        $addr += 4;
    }
}

################################################################################
# print the header, if passed in
sub display_header
{
    my ($hdr) = (@_);
    $hdr or return;
    ::userDisplay "$hdr\n";
}
################################################################################
# print the istep/substep, if passed in
sub display_istep
{
    my ($istep, $substep) = (@_);
    $istep or return;
    ::userDisplay "  IStep: $istep.$substep\n";
}

################################################################################
# print a msg for the tag passed in
sub display_tag
{
    my $tag = shift || 0;
    switch ($tag)
    {
        case 0x1001 {::userDisplay "KMEM_STATS_SYSCALL";}
        case 0x1002 {::userDisplay "KMEM_ALLOC_PAGE_OOM";}
        case 0x1003 {::userDisplay "KMEM_ALLOC_PAGE_OOM_COALESCE";}
        case 0x1004 {::userDisplay "KMEM_ALLOC_PAGE_OOM_DEFRAG";}
        case 0x1005 {::userDisplay "KMEM_ALLOC_PAGE_OOM_TIMEOUT";}
        case 0x1006 {::userDisplay "KMEM_ALLOC_PAGE_OOM_FIRST_FAIL";}
        case 0x1007 {::userDisplay "KMEM_ALLOC_PAGE_OOM_SECOND_FAIL";}
        case 0x1008 {::userDisplay "KMEM_ALLOC_PAGE_OOM_KASSERT";}
    }
}

################################################################################
# print a msg for the data, if passed in
sub display_req_pages
{
    my $pages = shift || 0;
    $pages or return;
    ::userDisplay "  Pages: $pages\n";
}

################################################################################
# print the data from the hash passed in
sub display_mem_stats
{
    my %data = %{$_[0]};
    my $str;

    if ($data{cv_pagesTotal} == 0)
    {
        ::userDisplay "data is unavailabe at this time\n";
        return;
    }

    $data{summary} or ::userDisplay "=========================================================\n";
    display_header($data{header});
    display_tag($data{tag});
    $data{summary} or ::userDisplay "\n";
    display_istep($data{istep}, $data{substep});
    Hostboot::SimpleTraceCommon::st_display_tid($data{tid});
    display_req_pages($data{requested_pages});

    $data{summary} and return;

    ::userDisplay "\n";

    # pagemgr
    ::userDisplay "Page Memory Stats:\n";
    $str = sprintf("  %6d Total Pages\n", $data{cv_pagesTotal});
    ::userDisplay "$str";
    $str = sprintf("  %6d Available Pages\n", $data{cv_pagesAvail});
    ::userDisplay "$str";
    $str = sprintf("  %6d Low Page Count\n", $data{cv_low_page_count});
    ::userDisplay "$str";
    $str = sprintf("  %6d Kernel reserved pages available\n", $data{cv_reserved_pages_available});
    ::userDisplay "$str";
    if ($data{cv_coalesce_state})
    {
        $str = sprintf("  %8d Coalesce is running\n");
    }
    if ($data{cv_coalesce_attempts})
    {
        $str = sprintf("  %6d Coalesced Attempts\n", $data{cv_coalesce_attempts});
        ::userDisplay "$str";
    }
    if ($data{cv_coalesce_count})
    {
        $str = sprintf("  %6d Coalesced Pages\n", $data{cv_coalesce_count});
        ::userDisplay "$str";
    }
    if ($data{cv_allocatePage_coalesce_wait})
    {
        $str = sprintf("  %6d Alloc Page Wait For Coalesce\n", $data{cv_allocatePage_coalesce_wait});
        ::userDisplay "$str";
    }
    ::userDisplay "free:";
    for (my $i=0; $i<PAGEMGR_NUMBER_OF_BUCKETS; $i++)
    {
        if ($data{cv_free_bucket_count}{$i})
        {
            my $field = sprintf("%ld/%ld", $i, $data{cv_free_bucket_count}{$i}*(1<<$i));
            $str = sprintf("%8s", $field);
            ::userDisplay "$str";
        }
    }
    ::userDisplay "\n     ";
    for (my $i=0; $i<PAGEMGR_NUMBER_OF_BUCKETS; $i++)
    {
        if ($data{cv_free_bucket_count}{$i})
        {
            $str = sprintf("%8ld", $data{cv_free_bucket_count}{$i});
            ::userDisplay "$str";
        }
    }
    ::userDisplay "\n";

    # block
    ::userDisplay "\nBlock Stats:\n";
    $str = sprintf("  %6d Pages allocated\n", $data{cv_pages_allocated});
    ::userDisplay "$str";
    $str = sprintf("  %6d Max pages allocated\n", $data{cv_pages_allocated_peak});
    ::userDisplay "$str";
    $str = sprintf("  %6d Total pages allocated\n", $data{cv_pages_allocated_count});
    ::userDisplay "$str";
    $str = sprintf("  %6d RO page requests\n", $data{cv_ro_evict_req});
    ::userDisplay "$str";
    $str = sprintf("  %6d RW page requests\n", $data{cv_rw_evict_req});
    ::userDisplay "$str";
    ::userDisplay "\n";

    # heapmgr
    ::userDisplay "Heap Memory Stats:\n";
    $str = sprintf("  %8d Huge block pages allocated\n", $data{cv_hugeblock_page_count});
    ::userDisplay "$str";
    $str = sprintf("  %8d Huge block max allocated\n", $data{cv_hugeblock_page_max});
    ::userDisplay "$str";
    $str = sprintf("  %8d Huge block alloc state\n", $data{iv_hugeblock_allocated});
    ::userDisplay "$str";
    $str = sprintf("  %8d Big heap pages allocated\n", $data{cv_largeheap_page_count});
    ::userDisplay "$str";
    $str = sprintf("  %8d Big heap max allocated\n", $data{cv_largeheap_page_max});
    ::userDisplay "$str";
    $str = sprintf("  %8d Small heap pages\n", $data{cv_smallheap_page_count});
    ::userDisplay "$str";
    $str = sprintf("  %8d Small heap peak bytes allocated\n", $data{cv_smallheap_alloc_hw});
    ::userDisplay "$str";
    $str = sprintf("  %8d Small heap allocated bytes in %d chunks\n",
                         $data{cv_smallheap_allocated}, $data{cv_inuse_chunks});
    ::userDisplay "$str";
    $str = sprintf("  %8d Small heap user bytes allocated in %d chunks\n",
                         $data{cv_smallheap_user_allocated}, $data{cv_inuse_chunks});
    ::userDisplay "$str";
    $str = sprintf("  %8d Small heap free bytes in %d chunks\n",
                                     $data{cv_free_bytes}, $data{cv_free_chunks});
    ::userDisplay "$str";
    my $percent_waste = 0;
    if ($data{cv_smallheap_allocated})
    {
        $percent_waste = ((($data{cv_smallheap_allocated}-$data{cv_smallheap_user_allocated})*100) /
                            $data{cv_smallheap_allocated});
    }
    $str = sprintf("  %8d Percent waste in the allocated chunks\n", $percent_waste);
    ::userDisplay "$str";
    if ($data{cv_smallheap_coalesce_state})
    {
        $str = sprintf("  %8d Coalesce is running\n");
        ::userDisplay "$str";
    }
    if ($data{cv_smallheap_coalesce_attempts})
    {
        $str = sprintf("  %8d Coalesced Attempts\n", $data{cv_smallheap_coalesce_attempts});
        ::userDisplay "$str";
    }
    if ($data{cv_smallheap_coalesce_count})
    {
        $str = sprintf("  %8d Small heap total chunks coalesced\n", $data{cv_smallheap_coalesce_count});
        ::userDisplay "$str";
    }
    if ($data{cv_smallheap_coalesce_page})
    {
        $str = sprintf("  %8d Small heap total pages  coalesced\n", $data{cv_smallheap_coalesce_page});
        ::userDisplay "$str";
    }
    ::userDisplay "           0/16    1/32    2/48    3/80   4/128   5/208   6/336";
    ::userDisplay "   7/544   8/880  9/1424 10/2304 11/3728\n";
    ::userDisplay "free:  ";
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $str = sprintf("%8ld", $data{cv_free_bucket_counts}{$i});
        ::userDisplay "$str";
    }
    ::userDisplay "\n";
    if ($data{INUSE_BUCKET_COUNTS})
    {
        ::userDisplay "inuse: ";
        for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
        {
            $str = sprintf("%8ld", $data{cv_inuse_bucket_counts}{$i});
            ::userDisplay "$str";
        }
        ::userDisplay "\n";
    }
    if ($data{ALLOC_BUCKET_COUNTS})
    {
        ::userDisplay "alloc: ";
        for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
        {
            $str = sprintf("%8ld", $data{cv_alloc_sizes}{$i});
            ::userDisplay "$str";
        }
        ::userDisplay "\n";
    }
}

################################################################################
# read the data for a kmem trace entry
sub get_trace_data
{
    my ($data, $idx, $addr) = (@_);
    my $str;
    my $EMPTY_TAG = 0xDEAD;

    $data->{tag} = ::read16 ($addr); $addr+=2;
    if ($data->{tag} == $EMPTY_TAG)
    {
        return 0;
    }

    $data->{istep}           = ::read16 ($addr); $addr+=2;
    $data->{substep}         = ::read16 ($addr); $addr+=2;
    $data->{tid}             = ::read16 ($addr); $addr+=2;
    $data->{requested_pages} = ::read16 ($addr); $addr+=2;

    # pagemgr
    $data->{cv_pagesTotal}                 = ::read32 ($addr); $addr+=4;
    $data->{cv_pagesAvail}                 = ::read32 ($addr); $addr+=4;
    $data->{cv_reserved_pages_available}   = ::read32 ($addr); $addr+=4;
    $data->{cv_low_page_count}             = ::read32 ($addr); $addr+=4;
    $data->{cv_coalesce_attempts}          = ::read32 ($addr); $addr+=4;
    $data->{cv_coalesce_count}             = ::read32 ($addr); $addr+=4;
    $data->{cv_allocatePage_coalesce_wait} = ::read32 ($addr); $addr+=4;

    for (my $i=0; $i<16; $i++)
    {
        $data->{cv_free_bucket_count}{$i} = ::read32 ($addr);
        $addr += 4;
    }

    # block
    $data->{cv_pages_allocated}       = ::read32 ($addr); $addr+=4;
    $data->{cv_pages_allocated_peak}  = ::read32 ($addr); $addr+=4;
    $data->{cv_pages_allocated_count} = ::read32 ($addr); $addr+=4;
    $data->{cv_ro_evict_req}          = ::read32 ($addr); $addr+=4;
    $data->{cv_rw_evict_req}          = ::read32 ($addr); $addr+=4;

    # heapmgr
    $data->{cv_free_chunks}                 = ::read32 ($addr); $addr+=4;
    $data->{cv_free_bytes}                  = ::read32 ($addr); $addr+=4;
    $data->{cv_inuse_chunks}                = ::read32 ($addr); $addr+=4;
    $data->{cv_inuse_bytes}                 = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_coalesce_attempts} = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_coalesce_count}    = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_coalesce_page}     = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_page_count}        = ::read32 ($addr); $addr+=4;
    $data->{cv_largeheap_page_count}        = ::read32 ($addr); $addr+=4;
    $data->{cv_largeheap_page_max}          = ::read32 ($addr); $addr+=4;
    $data->{iv_hugeblock_allocated}         = ::read32 ($addr); $addr+=4;
    $data->{cv_hugeblock_page_count}        = ::read32 ($addr); $addr+=4;
    $data->{cv_hugeblock_page_max}          = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_user_allocated}    = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_allocated}         = ::read32 ($addr); $addr+=4;
    $data->{cv_smallheap_alloc_hw}          = ::read32 ($addr); $addr+=4;
    for (my $i=0; $i<12; $i++)
    {
        $data->{cv_free_bucket_counts}{$i} = ::read32 ($addr);
        $addr += 4;
    }
    return 1;
}

################################################################################
# read PageManager data from the debug pointer area
sub get_pagemgr_data
{
    my $data = shift @_;

    $data->{cv_reserved_pages_available} = ::read64
      ::findPointer("PAGEMKRA",
                    "PageManager::cv_reserved_pages_available");
    $data->{cv_pagesTotal} = ::read64
      ::findPointer("PAGEMPGT",
                    "PageManager::cv_pagesTotal");
    $data->{cv_pagesAvail} = ::read64
      ::findPointer("PAGEMPGA",
                    "PageManager::cv_pagesAvail");
    $data->{cv_low_page_count} = ::read64
      ::findPointer("PAGEMLPC",
                    "PageManager::cv_low_page_count");
    $data->{cv_coalesce_state} = ::read64
      ::findPointer("PAGEMCST",
                    "PageManager::cv_coalesce_state");
    $data->{cv_coalesce_attempts} = ::read64
      ::findPointer("PAGEMCAT",
                    "PageManager::cv_coalesce_attempts");
    $data->{cv_coalesce_count} = ::read64
      ::findPointer("PAGEMCNT",
                    "PageManager::cv_coalesce_count");
    $data->{cv_allocatePage_coalesce_wait} = ::read64
      ::findPointer("PAGEMACC",
                    "PageManager::cv_allocatePage_coalesce_wait");
    my ($addr,$symsize) = ::findPointer("PAGEMFBK",
                                        "PageManager::cv_free_bucket_count");
    for (my $i=0; $i<PAGEMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_free_bucket_count}{$i} = ::read64($addr); $addr+=8;
    }
}

################################################################################
# read block data from the debug pointer area
sub get_block_data
{
    my $data = shift @_;

    $data->{cv_pages_allocated} = ::read64
      ::findPointer("BLOCKALL",
                    "Block::cv_pages_allocated");
    $data->{cv_pages_allocated_peak} = ::read64
      ::findPointer("BLOCKALP",
                    "Block::cv_pages_allocated_peak");
    $data->{cv_pages_allocated_count} = ::read64
      ::findPointer("BLOCKALC",
                    "Block::cv_pages_allocated_count");
    $data->{cv_ro_evict_req} = ::read64
      ::findPointer("BLOCKROE",
                    "Block::cv_ro_evict_req");
    $data->{cv_rw_evict_req} = ::read64
      ::findPointer("BLOCKRWE",
                    "Block::cv_rw_evict_req");
}

################################################################################
# read HeapManager data from the debug pointer area
sub get_heapmgr_data
{
    my $data = shift @_;

    $data->{iv_hugeblock_allocated} = ::read64
      ::findPointer("HEAPMHPA",
                    "HeapManager::iv_hugeblock_allocated");
    $data->{cv_hugeblock_page_count} = ::read64
      ::findPointer("HEAPMHPC",
                    "HeapManager::cv_hugeblock_page_count");
    $data->{cv_hugeblock_page_max} = ::read64
      ::findPointer("HEAPMHPM",
                    "HeapManager::cv_hugeblock_page_max");
    $data->{cv_largeheap_page_count} = ::read64
      ::findPointer("HEAPMLPC",
                    "HeapManager::cv_largeheap_page_count");
    $data->{cv_largeheap_page_max} = ::read64
      ::findPointer("HEAPMLPM",
                    "HeapManager::cv_largeheap_page_max");
    $data->{cv_smallheap_page_count} = ::read64
      ::findPointer("HEAPMSPC",
                    "HeapManager::cv_smallheap_page_count");
    $data->{cv_smallheap_alloc_hw} = ::read64
      ::findPointer("HEAPMSAH",
                    "HeapManager::cv_smallheap_alloc_hw");
    $data->{cv_smallheap_allocated} = ::read64
      ::findPointer("HEAPMSAL",
                    "HeapManager::cv_smallheap_allocated");
    $data->{cv_smallheap_user_allocated} = ::read64
      ::findPointer("HEAPMSUA",
                    "HeapManager::cv_smallheap_user_allocated");
    $data->{cv_smallheap_coalesce_state} = ::read64
      ::findPointer("HEAPMCST",
                    "HeapManager::cv_smallheap_coalesce_state");
    $data->{cv_smallheap_coalesce_attempts} = ::read64
      ::findPointer("HEAPMCAT",
                    "HeapManager::cv_smallheap_coalesce_attempts");
    $data->{cv_smallheap_coalesce_count} = ::read64
      ::findPointer("HEAPMCNT",
                    "HeapManager::cv_smallheap_coalesce_count");
    $data->{cv_smallheap_coalesce_page} = ::read64
      ::findPointer("HEAPMCPG",
                    "HeapManager::cv_smallheap_coalesce_page");

    my ($addr,$symsize) = ::findPointer("HEAPMFBT",
                                        "HeapManager::cv_free_bucket_counts");
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_free_bucket_counts}{$i} = ::read64($addr); $addr+=8;
    }

    ($addr,$symsize) = ::findPointer("HEAPMIBT",
                                        "HeapManager::cv_inuse_bucket_counts");
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_inuse_bucket_counts}{$i} = ::read64($addr); $addr+=8;
    }
    $data->{INUSE_BUCKET_COUNTS} = 1;

    ($addr,$symsize) = ::findPointer("HEAPASZ",
                                        "HeapManager::cv_alloc_sizes");
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_alloc_sizes}{$i} = ::read64($addr); $addr+=8;
    }
    $data->{ALLOC_BUCKET_COUNTS} = 1;

    ($addr,$symsize) = ::findPointer("HEAPMCSZ",
                                        "HeapManager::iv_chunk_size");
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{iv_chunk_size}{$i} = ::read64($addr); $addr+=8;
    }

    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_free_chunks} += $data->{cv_free_bucket_counts}{$i};
        $data->{cv_free_bytes}  += $data->{cv_free_bucket_counts}{$i} *
                                   $data->{iv_chunk_size}{$i};
    }
    for (my $i=0; $i<HEAPMGR_NUMBER_OF_BUCKETS; $i++)
    {
        $data->{cv_inuse_chunks} += $data->{cv_inuse_bucket_counts}{$i};
        $data->{cv_inuse_bytes}  += $data->{cv_inuse_bucket_counts}{$i} *
                                    $data->{iv_chunk_size}{$i};
    }
}

################################################################################
# get the live data from the debug pointers
# print the formatted output from the perl hash containing all the data
sub print_memory_stats
{
    my $args = shift @_;
    my %data = ();

    # do not print the live stats for these options
    defined $args->{"summary"} and return;
    defined $args->{"trace"}   and return;

    $data{header} = "MEMORY STATS";
    get_pagemgr_data (\%data);
    get_block_data   (\%data);
    get_heapmgr_data (\%data);
    display_mem_stats(\%data);
}

################################################################################
# get the kernel memory trace data from the debug pointer
# print the formatted output from the perl hash containing all the data
sub print_kmem_trace
{
    my $args = shift @_;
    my ($addr, $symSize) = ::findPointer("KMEMTRC",
                                         "g_kmemstats_trace");
    if (not defined $addr)
    {
        ::userDisplay "Couldn't find PageManager::g_kmemstats_trace";
        return;
    }

   # do not print the trace for these options
   (defined $args->{"summary"} || defined $args->{"trace"}) or return;

    my $hdr = ::read64 ($addr);

    # call a common fcn to read and print the SimpleTrace entries
    Hostboot::SimpleTraceCommon::st_print_trace($args,
                                                $hdr,
                                                \&get_trace_data,
                                                \&display_mem_stats);
}

################################################################################
sub main
{
    my ($packName, $args) = @_;

    print_memory_stats($args);
    print_kmem_trace($args);
}

