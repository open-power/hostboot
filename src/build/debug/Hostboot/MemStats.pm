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

use constant PAGEMGR_INSTANCE => "Singleton<PageManager>::instance()::instance";
use constant HEAPMGR_INSTANCE => "Singleton<HeapManager>::instance()::instance";
use constant BUCKETS       => 12;
use constant BUCKETS_RES   => 9;
use constant HEAP_RESERVED => 256;

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
# print the header, if passed in
sub display_header
{
    my ($hdr) = (@_);
    $hdr or return;
    ::userDisplay "$hdr\n";
}

################################################################################
# print a msg for the tag passed in (defined in simpletrace.H)
sub display_tag
{
    my $tag = shift || 0;
    switch ($tag)
    {
        case 0x1001 {::userDisplay "KMEM_STATS_SYSCALL                     ";}
        case 0x1002 {::userDisplay "KMEM_STATS_ALLOC_PG_USR_GET_RES_FAIL   ";}
        case 0x1003 {::userDisplay "KMEM_STATS_ALLOC_PG_USR_TIMEOUT_ASSERT ";}
        case 0x1004 {::userDisplay "KMEM_STATS_ALLOC_PG_KER_GET_RES_FAIL   ";}
        case 0x1005 {::userDisplay "KMEM_STATS_ALLOC_PG_KER_KASSERT        ";}
        case 0x1006 {::userDisplay "KMEM_STATS_FORCE_MEMORY_PERIODIC       ";}
        case 0x1007 {::userDisplay "KMEM_STATS_ALLOC_BIG_KASSERT_1         ";}
        case 0x1008 {::userDisplay "KMEM_STATS_ALLOC_BIG_KASSERT_2         ";}
        else
        {
            my $str = sprintf("0x%04x                                 ", $tag);
            ::userDisplay "$str";
        }
    }
}

################################################################################
# print the data from the hash passed in
sub display_mem_stats
{
    my %data = %{$_[0]};
    my $str;

    if ($data{cv_pagesTotal} == 0)
    {
        ::userDisplay "data is unavailable at this time\n";
        return;
    }

    $data{summary} or ::userDisplay "=========================================================\n";
    display_header($data{header});
    $data{summary} and Hostboot::SimpleTraceCommon::st_display_time($data{sec},$data{nsec});
    $data{summary} and Hostboot::SimpleTraceCommon::st_display_tid_summary($data{tid});
    $data{tag}     and display_tag($data{tag});
    $data{summary} and Hostboot::SimpleTraceCommon::st_display_cpuid_summary($data{cpuid});
    $data{summary} or $data{trace} and ::userDisplay "\n";
    Hostboot::SimpleTraceCommon::st_display_istep($data{istep}, $data{substep});
    $data{summary} or $data{trace} and ::userDisplay "\n";
    $data{trace}   and Hostboot::SimpleTraceCommon::st_display_tid($data{tid});
    $data{summary} or $data{trace} and ::userDisplay "\n";
    $data{summary} and Hostboot::SimpleTraceCommon::st_display_pages_summary(\%data);
    $data{summary} and Hostboot::SimpleTraceCommon::st_display_BigHuge_summary(\%data);

    if ($data{tag} == 0x1006) #KMEM_STATS_FORCE_MEMORY_PERIODIC
    {
        # for this tag, requested_pages is actually 0:NORMAL or 1:CRITICAL
        if    ($data{requested_pages} == 0) {::userDisplay " NORMAL";}
        elsif ($data{requested_pages} == 1) {::userDisplay " CRITICAL";}
        else
        {
            $str = sprintf(" 0x%x", $data{requested_pages});
            ::userDisplay "$str";
        }
    }
    else
    {
        Hostboot::SimpleTraceCommon::st_display_req_pages($data{requested_pages});
    }

    $data{summary} or $data{requested_pages} and ::userDisplay "\n";
    ::userDisplay "\n";

    $data{summary} and return;

    # pagemgr
    ::userDisplay "Page Memory Stats:\n";
    $str = sprintf("  %6d Total Pages\n", $data{cv_pagesTotal});
    ::userDisplay "$str";
    $str = sprintf("  %6d Heap Available Pages\n", $data{cv_pagesAvail_heap});
    ::userDisplay "$str";
    $str = sprintf("  %6d Heap Low Page Count\n", $data{cv_low_page_count_heap});
    ::userDisplay "$str";
    if ($data{cv_coalesce_state})
    {
        $str = sprintf("       Heap Coalesce is running\n");
    }
    if ($data{cv_coalesce_attempts})
    {
        $str = sprintf("  %6d Heap Coalesce Attempts\n", $data{cv_coalesce_attempts});
        ::userDisplay "$str";
    }
    if ($data{cv_coalesce_count})
    {
        $str = sprintf("  %6d Heap Coalesce Pages\n", $data{cv_coalesce_count});
        ::userDisplay "$str";
    }
    if ($data{cv_allocatePage_usr_wait})
    {
        $str = sprintf("  %6d Heap allocatePage usr-mode wait\n", $data{cv_allocatePage_usr_wait});
        ::userDisplay "$str";
    }
    ::userDisplay "                    ";
    for (my $i=0; $i<BUCKETS-1; $i++)
    {
        if ($data{cv_free_bucket_count_heap}{$i} ||
            $data{cv_alloc_sizes_heap}{$i})
        {
            my $field = sprintf("%ld/%ld", $i, 1<<$i);
            $str = sprintf("%8s", $field);
            ::userDisplay "$str";
        }
    }
    # print bucket 12 heading
    if ($data{cv_free_bucket_count_heap}{BUCKETS-1} ||
        $data{cv_alloc_sizes_heap}{BUCKETS-1})
    {
       my $field = sprintf("%ld/big", BUCKETS-1);
       $str = sprintf("%8s", $field);
        ::userDisplay "$str";
    }
    ::userDisplay "\n";
    my $heap_nums;
    my $heap_allocs;
    for (my $i=0; $i<BUCKETS; $i++)
    {
        # format these together to use the same heading above
        if ($data{cv_free_bucket_count_heap}{$i} ||
            $data{cv_alloc_sizes_heap}{$i})
        {
            $str = sprintf("%8ld", $data{cv_free_bucket_count_heap}{$i});
            $heap_nums .= $str;
            $str = sprintf("%8ld", $data{cv_alloc_sizes_heap}{$i});
            $heap_allocs .= $str;
        }
    }
    if ($heap_nums) {::userDisplay "         Heap free: $heap_nums\n";}
    my $num_allocs=0;
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $num_allocs += $data{cv_alloc_sizes_heap}{$i};
    }
    if ($num_allocs)
    {
        # trace elements dont have allocs, so dont print a line of zeroes
        ::userDisplay "         Heap Alloc:$heap_allocs\n";
    }

    # iv_reserved
    $str = sprintf("  %6d Reserved Available Pages\n", $data{cv_pagesAvail_res});
    ::userDisplay "$str";
    my $num_res_alloc=0;
    for (my $i=0; $i<BUCKETS_RES; $i++)
    {
        $num_res_alloc += $data{cv_alloc_sizes_res}{$i};
    }
    my $res_nums_str;
    my $res_allocs_str;
    for (my $i=0; $i<BUCKETS_RES; $i++)
    {
        # format these together to use the same heading above
        if ($data{cv_free_bucket_count_res}{$i} ||
            $data{cv_alloc_sizes_res}{$i})
        {
            $str = sprintf("%8ld", $data{cv_free_bucket_count_res}{$i});
            $res_nums_str .= $str;
            $str = sprintf("%8ld", $data{cv_alloc_sizes_res}{$i});
            $res_allocs_str .= $str;
        }
    }
    if ($data{cv_low_page_count_res} != HEAP_RESERVED)
    {
        $str = sprintf("  %6d Reserved Low Page Count\n", $data{cv_low_page_count_res});
        ::userDisplay "$str";
        ::userDisplay "                    ";
        for (my $i=0; $i<BUCKETS_RES; $i++)
        {
            if ($data{cv_free_bucket_count_res}{$i} ||
                $data{cv_alloc_sizes_res}{$i})
            {
                my $field = sprintf("%ld/%ld", $i, (1<<$i));
                $str = sprintf("%8s", $field);
                ::userDisplay "$str";
            }
        }
        ::userDisplay "\n";
        if ($res_nums_str) {::userDisplay "         Res free:  $res_nums_str\n";}
        if ($num_res_alloc)
        {
            ::userDisplay "         Res Alloc: $res_allocs_str\n";
        }
    }

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
        $str = sprintf("  %8d Coalesce Attempts\n", $data{cv_smallheap_coalesce_attempts});
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
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $str = sprintf("%8ld", $data{cv_free_bucket_counts}{$i});
        ::userDisplay "$str";
    }
    ::userDisplay "\n";
    if ($data{INUSE_BUCKET_COUNTS})
    {
        ::userDisplay "inuse: ";
        for (my $i=0; $i<BUCKETS; $i++)
        {
            $str = sprintf("%8ld", $data{cv_inuse_bucket_counts}{$i});
            ::userDisplay "$str";
        }
        ::userDisplay "\n";
    }
    if ($data{ALLOC_BUCKET_COUNTS})
    {
        ::userDisplay "alloc: ";
        for (my $i=0; $i<BUCKETS; $i++)
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
    $data->{cpuid}           = ::read16 ($addr); $addr+=2;
    $data->{sec}             = ::read32 ($addr); $addr+=4;
    $data->{nsec}            = ::read32 ($addr); $addr+=4;

    $data->{istep}           = ::read16 ($addr); $addr+=2;
    $data->{substep}         = ::read16 ($addr); $addr+=2;
    $data->{tid}             = ::read16 ($addr); $addr+=2;
    $data->{requested_pages} = ::read16 ($addr); $addr+=2;

    # pagemgr
    $data->{cv_pagesTotal}                 = ::read32 ($addr); $addr+=4;
    $data->{cv_pagesAvail_heap}            = ::read32 ($addr); $addr+=4;
    $data->{cv_low_page_count_heap}        = ::read32 ($addr); $addr+=4;
    $data->{cv_coalesce_state}             = ::read32 ($addr); $addr+=4;
    $data->{cv_coalesce_attempts}          = ::read32 ($addr); $addr+=4;
    $data->{cv_coalesce_count}             = ::read32 ($addr); $addr+=4;

    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_free_bucket_count_heap}{$i} = ::read32 ($addr);
        $addr += 4;
    }
    $data->{cv_allocatePage_usr_wait} = ::read32 ($addr); $addr+=4;
    $data->{cv_pagesAvail_res}        = ::read32 ($addr); $addr+=4;
    $data->{cv_low_page_count_res}    = ::read32 ($addr); $addr+=4;
    for (my $i=0; $i<BUCKETS_RES; $i++)
    {
        $data->{cv_free_bucket_count_res}{$i} = ::read32 ($addr);
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
    for (my $i=0; $i<BUCKETS; $i++)
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

    my ($symAddr, $symSize) = ::findPointer("PAGEMINS", PAGEMGR_INSTANCE);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find".PAGEMGR_INSTANCE."\n";
        return;
    }

    $data->{cv_pagesTotal}            = ::read64($symAddr); $symAddr += 8;
    $data->{cv_allocatePage_usr_wait} = ::read64($symAddr); $symAddr += 8;

    ### read iv_heap data

    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_free_bucket_count_heap}{$i} = ::read64($symAddr); $symAddr += 8;
    }
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_alloc_sizes_heap}{$i} = ::read64($symAddr); $symAddr += 8;
    }

    $data->{cv_pagesAvail_heap}     = ::read64($symAddr); $symAddr += 8;
    $data->{cv_low_page_count_heap} = ::read64($symAddr); $symAddr += 8;
    $data->{cv_coalesce_state}      = ::read64($symAddr); $symAddr += 8;
    $data->{cv_coalesce_attempts}   = ::read64($symAddr); $symAddr += 8;
    $data->{cv_coalesce_count}      = ::read64($symAddr); $symAddr += 8;

    $symAddr += 2*8;        # iv_heap_lower (num:2 * size:8)
    $symAddr += BUCKETS*32; # iv_heap_upper (num:BUCKETS * size:32)
    $symAddr += 4;          # iv_supports_coalesce
    $symAddr += 4;          # pad1
    $symAddr += 24;         # iv_spinlock
    $symAddr += (4*16);     # iv_ranges (num:4 * size:16)

    ### read iv_reserved data

    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_free_bucket_count_res}{$i} = ::read64($symAddr); $symAddr += 8;
    }
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_alloc_sizes_res}{$i} = ::read64($symAddr); $symAddr += 8;
    }

    $data->{cv_pagesAvail_res}     = ::read64($symAddr); $symAddr += 8;
    $data->{cv_low_page_count_res} = ::read64($symAddr); $symAddr += 8;
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

    my ($symAddr, $symSize) = ::findPointer("HEAPMINS", HEAPMGR_INSTANCE);
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find".HEAPMGR_INSTANCE."\n";
        return;
    }
    $data->{iv_hugeblock_allocated}         = ::read64($symAddr); $symAddr += 8;
    $data->{cv_hugeblock_page_count}        = ::read64($symAddr); $symAddr += 8;
    $data->{cv_hugeblock_page_max}          = ::read64($symAddr); $symAddr += 8;
    $data->{cv_largeheap_page_count}        = ::read64($symAddr); $symAddr += 8;
    $data->{cv_largeheap_page_max}          = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_page_count}        = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_alloc_hw}          = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_allocated}         = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_user_allocated}    = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_coalesce_state}    = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_coalesce_attempts} = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_coalesce_count}    = ::read64($symAddr); $symAddr += 8;
    $data->{cv_smallheap_coalesce_page}     = ::read64($symAddr); $symAddr += 8;

    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_free_bucket_counts}{$i} = ::read64($symAddr); $symAddr+=8;
    }
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_inuse_bucket_counts}{$i} = ::read64($symAddr); $symAddr+=8;
    }
    $data->{INUSE_BUCKET_COUNTS} = 1;
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_alloc_sizes}{$i} = ::read64($symAddr); $symAddr+=8;
    }
    $data->{ALLOC_BUCKET_COUNTS} = 1;
    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{iv_chunk_size}{$i} = ::read64($symAddr); $symAddr+=8;
    }

    for (my $i=0; $i<BUCKETS; $i++)
    {
        $data->{cv_free_chunks} += $data->{cv_free_bucket_counts}{$i};
        $data->{cv_free_bytes}  += $data->{cv_free_bucket_counts}{$i} *
                                   $data->{iv_chunk_size}{$i};
    }
    for (my $i=0; $i<BUCKETS; $i++)
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

   # only print the elements for the trace option
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

