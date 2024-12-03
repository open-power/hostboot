# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Ktrc.pm $
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

# Functions to print the Kernel Short and Long Traces
#  The data is held in the global arrays: g_kshort_trace and g_klong_trace

use strict;
use Switch;

package Hostboot::Ktrc;
use Exporter;
use Hostboot::SimpleTraceCommon;
our @EXPORT_OK = ('main');

################################################################################
sub helpInfo
{
    my %info = (
        name => "Ktrc",
        intro => ["Displays Hostboot kernel trace usage information."],
        options => {"long" => ["Dump the g_klong_trace trace entries"]},
    );
};

use constant
{
    # PageManager
    KDBG_PM_ALLOC_USR_ENTER      => 0x1001,
    KDBG_PM_ALLOC_USR_EXIT       => 0x1002,
    KDBG_PM_FREE_ENTER           => 0x1003,
    KDBG_PM_FREE_EXIT            => 0x1004,
    KDBG_PM_COALESCE_ENTER       => 0x1005,
    KDBG_PM_COALESCE_START       => 0x1006,
    KDBG_PM_COALESCE_EXIT        => 0x1007,
    KDBG_PM_ALLOC_KER_ENTER      => 0x1008,
    KDBG_PM_ALLOC_KER_EXIT       => 0x1009,
    KDBG_PM_ADD_MEMORY           => 0x100A,
    KDBG_PM_USR_GET_RES_FAIL     => 0x100B,
    KDBG_PM_PERIODIC_RES_INTERVAL=> 0x100C,
    KDBG_PM_PERIODIC_KER_MISS    => 0x100D,
    # HeapManager
    KDBG_HM_ALLOC                => 0x2001,
    KDBG_HM_REALLOC              => 0x2002,
    KDBG_HM_FREE                 => 0x2003,
    KDBG_HM_COALESCE             => 0x2004,
    KDBG_HM_NEW_PAGE             => 0x2005,
    KDBG_HM_ALLOC_BIG            => 0x2006,
    KDBG_HM_REALLOC_BIG          => 0x2007,
    KDBG_HM_FREE_BIG             => 0x2008,
    KDBG_HM_ALLOC_HUGE           => 0x2009,
    KDBG_HM_REALLOC_HUGE         => 0x200A,
    KDBG_HM_FREE_HUGE            => 0x200B,
    KDBG_HM_ALLOC_ASSERT_NOT_F   => 0x200C,
    KDBG_HM_FREE_ASSERT_NOT_A    => 0x200D,
    KDBG_HM_FREE_BIG_ASSERT      => 0x200E,
    KDBG_HM_ALLOC_HUGE_NO_CHUNKS => 0x200F,
    KDBG_HM_FREE_CRASH_NOT_V     => 0x2010,
    KDBG_HM_COALESCE_ASSERT_NOT_F=> 0x2011,
    KDBG_HM_COALESCE_ASSERT_NOT_C=> 0x2012,
    KDBG_HM_HUGE_ALLOC_BLOCK_ERROR=>0x2013,
    KDBG_HM_HUGE_SETPERM_ERROR   => 0x2014,
    # Block
    KDBG_BK_SET_PERM_EINVAL        => 0x3000,
    KDBG_BK_SET_PERM_SPTE_EINVAL_1 => 0x3001,
    KDBG_BK_SET_PERM_SPTE_EINVAL_2 => 0x3002,
    KDBG_BK_SET_PERM_SPTE_EINVAL_3 => 0x3003,
    KDBG_BK_SET_PERM_SPTE_EINVAL_4 => 0x3004,
    KDBG_BK_SET_PERM_SPTE_EINVAL_5 => 0x3005,
    KDBG_BK_REMOVE_PAGES_EINVAL    => 0x3006,

    KDBG_SET_FORCE_PERIODIC      => 0xE000,

    KDBG_TEMP_TRACE              => 0xF000,
    KDBG_FREEZE_TRACE            => 0xFFFF,

    # FREEZE Types
    KDBG_PROG_EX            => 0x0001,
    KDBG_DSI                => 0x0002,
    KDBG_DATA_SEGMENT_EX    => 0x0003,
    KDBG_INST_STORAGE_EX    => 0x0004,
    KDBG_INST_SEGMENT_EX    => 0x0005,
    KDBG_ALIGNMENT_EX       => 0x0006,
    KDBG_ILLEGAL_INST       => 0x0007,
    KDBG_FP_UNAVAILABLE     => 0x0008,
    KDBG_SOFTPATCH          => 0x0009,
    KDBG_MACHINE_CHECK      => 0x000A,
    KDBG_USR_MACHNE_CHECK   => 0x000B,
    KDBG_UNHANDLED_EX       => 0x000C,
    KDBG_ASSERT             => 0x000D,
};

# print a msg for the tag passed in
sub display_tag
{
    my $tag = shift || 0;
    switch ($tag)
    {
        case 0
             {::userDisplay "NO_TAG                                 ";}
        # PageManager
        case KDBG_PM_ALLOC_USR_ENTER
             {::userDisplay "KDBG_PM_ALLOC_USR_ENTER                ";}
        case KDBG_PM_ALLOC_USR_EXIT
             {::userDisplay "KDBG_PM_ALLOC_USR_EXIT                 ";}
        case KDBG_PM_ALLOC_KER_ENTER
             {::userDisplay "KDBG_PM_ALLOC_KER_ENTER                ";}
        case KDBG_PM_ALLOC_KER_EXIT
             {::userDisplay "KDBG_PM_ALLOC_KER_EXIT                 ";}
        case KDBG_PM_ADD_MEMORY
             {::userDisplay "KDBG_PM_ADD_MEMORY                     ";}
        case KDBG_PM_USR_GET_RES_FAIL
             {::userDisplay "KDBG_PM_USR_GET_RES_FAIL               ";}
        case KDBG_PM_PERIODIC_RES_INTERVAL
             {::userDisplay "KDBG_PM_PERIODIC_RES_INTERVAL          ";}
        case KDBG_PM_PERIODIC_KER_MISS
             {::userDisplay "KDBG_PM_PERIODIC_KER_MISS              ";}
        case KDBG_PM_FREE_ENTER
             {::userDisplay "KDBG_PM_FREE_ENTER                     ";}
        case KDBG_PM_FREE_EXIT
             {::userDisplay "KDBG_PM_FREE_EXIT                      ";}
        case KDBG_PM_COALESCE_ENTER
             {::userDisplay "KDBG_PM_COALESCE_ENTER                 ";}
        case KDBG_PM_COALESCE_START
             {::userDisplay "KDBG_PM_COALESCE_START                 ";}
        case KDBG_PM_COALESCE_EXIT
             {::userDisplay "KDBG_PM_COALESCE_EXIT                  ";}
        # HeapManager
        case KDBG_HM_ALLOC
             {::userDisplay "KDBG_HM_ALLOC                          ";}
        case KDBG_HM_REALLOC
             {::userDisplay "KDBG_HM_REALLOC                        ";}
        case KDBG_HM_FREE
             {::userDisplay "KDBG_HM_FREE                           ";}
        case KDBG_HM_FREE_CRASH_NOT_V
             {::userDisplay "KDBG_HM_FREE_CRASH_NOT_V               ";}
        case KDBG_HM_COALESCE_ASSERT_NOT_F
             {::userDisplay "KDBG_HM_COALESCE_ASSERT_NOT_F          ";}
        case KDBG_HM_COALESCE_ASSERT_NOT_C
             {::userDisplay "KDBG_HM_COALESCE_ASSERT_NOT_C          ";}
        case KDBG_HM_COALESCE
             {::userDisplay "KDBG_HM_COALESCE                       ";}
        case KDBG_HM_NEW_PAGE
             {::userDisplay "KDBG_HM_NEW_PAGE                       ";}
        case KDBG_HM_ALLOC_BIG
             {::userDisplay "KDBG_HM_ALLOC_BIG                      ";}
        case KDBG_HM_REALLOC_BIG
             {::userDisplay "KDBG_HM_REALLOC_BIG                    ";}
        case KDBG_HM_FREE_BIG
             {::userDisplay "KDBG_HM_FREE_BIG                       ";}
        case KDBG_HM_ALLOC_HUGE
             {::userDisplay "KDBG_HM_ALLOC_HUGE                     ";}
        case KDBG_HM_ALLOC_HUGE_NO_CHUNKS
             {::userDisplay "KDBG_HM_ALLOC_HUGE_NO_CHUNKS           ";}
        case KDBG_HM_HUGE_ALLOC_BLOCK_ERROR
             {::userDisplay "KDBG_HM_HUGE_ALLOC_BLOCK_ERROR         ";}
        case KDBG_HM_HUGE_SETPERM_ERROR
             {::userDisplay "KDBG_HM_HUGE_SETPERM_ERROR             ";}
        case KDBG_HM_REALLOC_HUGE
             {::userDisplay "KDBG_HM_REALLOC_HUGE                   ";}
        case KDBG_HM_FREE_HUGE
             {::userDisplay "KDBG_HM_FREE_HUGE                      ";}
        case KDBG_HM_ALLOC_ASSERT_NOT_F
             {::userDisplay "KDBG_HM_ALLOC_ASSERT_NOT_F             ";}
        case KDBG_HM_FREE_ASSERT_NOT_A
             {::userDisplay "KDBG_HM_FREE_ASSERT_NOT_A              ";}

        case KDBG_BK_SET_PERM_EINVAL
             {::userDisplay "BK_SET_PERM_EINVAL                     ";}
        case KDBG_BK_SET_PERM_SPTE_EINVAL_1
             {::userDisplay "BK_SET_PERM_SPTE_EINVAL_1              ";}
        case KDBG_BK_SET_PERM_SPTE_EINVAL_2
             {::userDisplay "BK_SET_PERM_SPTE_EINVAL_2              ";}
        case KDBG_BK_SET_PERM_SPTE_EINVAL_3
             {::userDisplay "KDBG_BK_SET_PERM_SPTE_EINVAL_3         ";}
        case KDBG_BK_SET_PERM_SPTE_EINVAL_4
             {::userDisplay "KDBG_BK_SET_PERM_SPTE_EINVAL_4         ";}
        case KDBG_BK_SET_PERM_SPTE_EINVAL_5
             {::userDisplay "KDBG_BK_SET_PERM_SPTE_EINVAL_5         ";}
        case KDBG_BK_REMOVE_PAGES_EINVAL
             {::userDisplay "BK_REMOVE_PAGES_EINVAL                 ";}

        case KDBG_SET_FORCE_PERIODIC
             {::userDisplay "KDBG_SET_FORCE_PERIODIC                ";}

        case KDBG_TEMP_TRACE
             {::userDisplay "KDBG_TEMP_TRACE                        ";}
        case KDBG_FREEZE_TRACE
             {::userDisplay "KDBG_FREEZE_TRACE                      ";}
        else
        {
            my $str = sprintf("UNKNOWN tag:0x%04x                     ", $tag);
            ::userDisplay "$str";
        }
    }
}

################################################################################
# print the data from the hash passed in
sub display_trace_data
{
    my %data = %{$_[0]};
    my $str;

    Hostboot::SimpleTraceCommon::st_display_time($data{sec},$data{msec});
    Hostboot::SimpleTraceCommon::st_display_tid_summary($data{tid});
    display_tag($data{tag});
    Hostboot::SimpleTraceCommon::st_display_cpuid_summary($data{cpuid});

    if ($data{tag} == KDBG_PM_ALLOC_USR_ENTER ||
        $data{tag} == KDBG_PM_ALLOC_KER_ENTER)
    {
        $str = sprintf(" sz:%d", $data{first32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_ALLOC_USR_EXIT ||
           $data{tag} == KDBG_PM_ALLOC_KER_EXIT)
    {
        $str = sprintf(" page: %08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_FREE_ENTER)
    {
        $str = sprintf(" chunk:%08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_FREE_EXIT)
    {
        $str = sprintf(" pagesAvail: %d", $data{first32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_COALESCE_ENTER)
    {
        $str = sprintf(" attempts:%d state:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_COALESCE_START ||
           $data{tag} == KDBG_PM_COALESCE_EXIT)
    {
        $str = sprintf(" attempts:%d count:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_ADD_MEMORY)
    {
        $str = sprintf(" addr: %08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_PM_USR_GET_RES_FAIL      ||
           $data{tag} == KDBG_PM_PERIODIC_RES_INTERVAL ||
           $data{tag} == KDBG_PM_PERIODIC_KER_MISS)
    {
        $str = sprintf(" sz: %08x avail:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_ALLOC)
    {
        $str = sprintf(" chunk:%08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_ALLOC_ASSERT_NOT_F)
    {
        $str = sprintf(" chunk:%08x free:%c", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_REALLOC ||
           $data{tag} == KDBG_HM_REALLOC_BIG)
    {
        $str = sprintf(" old:  %08x new:%08x", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_FREE)
    {
        $str = sprintf(" chunk:%08x sz:%d", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_FREE_CRASH_NOT_V      ||
           $data{tag} == KDBG_HM_COALESCE_ASSERT_NOT_F ||
           $data{tag} == KDBG_HM_COALESCE_ASSERT_NOT_C)
    {
        $str = sprintf(" chunk:%08x ascii:0x%x", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_COALESCE)
    {
        $str = sprintf(" attempts:%d", $data{first32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_NEW_PAGE)
    {
        $str = sprintf(" page: %08x cv_smallheap_page_count:%d",
                       $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_ALLOC_BIG)
    {
        $str = sprintf(" chunk:%08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_FREE_BIG)
    {
        $str = sprintf(" chunk:%08x sz:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_ALLOC_HUGE ||
           $data{tag} == KDBG_HM_HUGE_SETPERM_ERROR)
    {
        $str = sprintf(" chunk:%08x pages:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_ALLOC_HUGE_NO_CHUNKS ||
           $data{tag} == KDBG_HM_HUGE_ALLOC_BLOCK_ERROR)
    {
        $str = sprintf(" pages:%d", $data{first32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_REALLOC_HUGE)
    {
        $str = sprintf(" chunk:%08x pages:%d", $data{first32},$data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_FREE_HUGE)
    {
        $str = sprintf(" chunk:%08x", $data{first32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_HM_FREE_ASSERT_NOT_A)
    {
        $str = sprintf(" chunk:%08x free:%c", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }

    elsif ($data{tag} == KDBG_BK_SET_PERM_EINVAL)
    {
        $str = sprintf(" addr: %08x sz:%d", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_BK_SET_PERM_SPTE_EINVAL_1 ||
           $data{tag} == KDBG_BK_SET_PERM_SPTE_EINVAL_2 ||
           $data{tag} == KDBG_BK_SET_PERM_SPTE_EINVAL_3 ||
           $data{tag} == KDBG_BK_SET_PERM_SPTE_EINVAL_4 ||
           $data{tag} == KDBG_BK_SET_PERM_SPTE_EINVAL_5)
    {
        $str = sprintf(" addr: %08x type:%x", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_BK_REMOVE_PAGES_EINVAL)
    {
        $str = sprintf(" max_va:%08x max_base:%08x", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_SET_FORCE_PERIODIC)
    {
        if ($data{first32}) {$str = "CRITICAL";}
        else                {$str = "NORMAL";}
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_TEMP_TRACE)
    {
        $str = sprintf(" %08x %08x", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    elsif ($data{tag} == KDBG_FREEZE_TRACE)
    {
      switch ($data{first32})
      {
        case KDBG_PROG_EX
             {$str = sprintf(" PROG_EX          %08x", $data{second32});}
        case KDBG_DSI
             {$str = sprintf(" DSI              %08x", $data{second32});}
        case KDBG_DATA_SEGMENT_EX
             {$str = sprintf(" DATA_SEGMENT_EX  %08x", $data{second32});}
        case KDBG_INST_STORAGE_EX
             {$str = sprintf(" INST_STORAGE_EX  %08x", $data{second32});}
        case KDBG_INST_SEGMENT_EX
             {$str = sprintf(" INST_SEGMENT_EX  %08x", $data{second32});}
        case KDBG_ALIGNMENT_EX
             {$str = sprintf(" ALIGNMENT_EX     %08x", $data{second32});}
        case KDBG_ILLEGAL_INST
             {$str = sprintf(" ILLEGAL_INST     %08x", $data{second32});}
        case KDBG_FP_UNAVAILABLE
             {$str = sprintf(" FP_UNAVAILABLE   %08x", $data{second32});}
        case KDBG_SOFTPATCH
             {$str = sprintf(" SOFTPATCH        %08x", $data{second32});}
        case KDBG_MACHINE_CHECK
             {$str = sprintf(" MACHINE_CHECK    %08x", $data{second32});}
        case KDBG_USR_MACHNE_CHECK
             {$str = sprintf(" USR_MACHNE_CHECK %08x", $data{second32});}
        case KDBG_UNHANDLED_EX
             {$str = sprintf(" UNHANDLED_EX     %08x", $data{second32});}
        case KDBG_ASSERT
             {$str = sprintf(" ASSERT           %08x", $data{second32});}
        else
        {
             {$str = sprintf("         %08x %08x", $data{first32}, $data{second32});}
        }
      }
      ::userDisplay "$str";
    }
    else
    {
        $str = sprintf(" %08x %08x", $data{first32}, $data{second32});
        ::userDisplay "$str";
    }
    ::userDisplay "\n";
}

################################################################################
# read the data for a trace entry
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
    $data->{cpuid}    = ::read16 ($addr); $addr+=2;
    $data->{sec}      = ::read32 ($addr); $addr+=4;
    $data->{msec}     = ::read32 ($addr); $addr+=4;

    $data->{tid}      = ::read16 ($addr); $addr+=2;
    $data->{first32}  = ::read32 ($addr); $addr+=4;
    $data->{second32} = ::read32 ($addr);

    return 1;
}

################################################################################
sub main
{
    my ($packName, $args) = @_;
    my %data = ();
    my $addr;
    my $symSize;

    if (defined $args->{"long"})
    {
        ($addr, $symSize) = ::findPointer("KLONGTRC",
                                          "g_klong_trace");
    }
    else
    {
        ($addr, $symSize) = ::findPointer("KSHRTTRC",
                                          "g_kshort_trace");
    }
    if (not defined $addr)
    {
        defined $args->{"short"} or  ::userDisplay "Couldn't find g_klong_trace";
        defined $args->{"short"} and ::userDisplay "Couldn't find g_kshort_trace";
        return;
    }

    my $hdr = ::read64 ($addr);
    $data{hdr_addr} = $hdr;

    # call a common fcn to read and print the SimpleTrace entries
    Hostboot::SimpleTraceCommon::st_print_trace($args,
                                                $hdr,
                                                \&get_trace_data,
                                                \&display_trace_data);
}
