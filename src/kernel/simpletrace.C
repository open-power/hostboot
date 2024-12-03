/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/simpletrace.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2024                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 * @file simpletrace.C
 * @brief Implementation of class SimpleTrace
 */

#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <kernel/simpletrace.H>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
#include <kernel/block.H>
#include <usr/debugpointers.H>
#include <sys/task.h>

SimpleTrace<simple_trace_timed_entry_t, kdebug_trc_data_t> g_kshort_trace;
SimpleTrace<simple_trace_timed_entry_t, kdebug_trc_data_t> g_klong_trace;
SimpleTrace<simple_trace_timed_entry_t, kmem_trc_data_t>   g_kmemstats_trace;
SimpleTrace<simple_trace_timed_entry_t, kalloc_trc_data_t> g_kalloc_trace;

////////////////////////////////////////////////////////////////////////////////
template <typename BASE_DATA, typename USER_DATA>
void SimpleTrace<BASE_DATA, USER_DATA>::init(uint32_t i_size,
                                simple_trace_format_t i_format)
{
    iv_hdr = (simple_trace_hdr_t*) new uint8_t[i_size];
    if (!iv_hdr) {return;}

    iv_hdr->iv_eyecatcher = EYECATCHER;
    iv_hdr->iv_version    = SIMPLE_TRACE_VERSION_1;
    iv_hdr->iv_format     = i_format;
    iv_hdr->iv_level      = STRC_L1;
    iv_hdr->iv_size       = i_size;
    iv_hdr->iv_e_size     = sizeof(simple_trace_entry_t);
    iv_hdr->iv_idx        = 0;
    iv_hdr->iv_max        = (i_size - sizeof(simple_trace_hdr_t)) / iv_hdr->iv_e_size;

    if (iv_hdr->iv_max == 0)
    {
        KTRC4("simpletrace::ctor: i_size:%d e_size:%d iv_max:%d\n",
                i_size, iv_hdr->iv_e_size, iv_hdr->iv_max);
        return;
    }

    simple_trace_entry_t *e = (simple_trace_entry_t*)iv_hdr->iv_data;

    for (uint32_t i=0; i<iv_hdr->iv_max; i++)
    {
        e->iv_base.set(EMPTY_TAG);
        e++;
    }
}

////////////////////////////////////////////////////////////////////////////////
void SimpleTrace_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::KSHORTTRACE,
                             &g_kshort_trace,
                             sizeof(g_kshort_trace));
    DEBUG::add_debug_pointer(DEBUG::KLONGTRACE,
                             &g_klong_trace,
                             sizeof(g_klong_trace));
    DEBUG::add_debug_pointer(DEBUG::KMEMTRACE,
                             &g_kmemstats_trace,
                             sizeof(g_kmemstats_trace));
    DEBUG::add_debug_pointer(DEBUG::KALLOCTRACE,
                             &g_kalloc_trace,
                             sizeof(g_kalloc_trace));
}

////////////////////////////////////////////////////////////////////////////////
void STRC_FREEZE(uint32_t i_d1, uint32_t i_d2)
{
    g_kshort_trace.set_trace_level(STRC_OFF);
    STRC_KSHORT(STRC_FORCE, KDBG_TRACE_FREEZE, i_d1, i_d2);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KSHORT_INIT(uint32_t i_size, simple_trace_format_t i_format)
{
    g_kshort_trace.init(i_size, i_format);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KSHORT(simple_trace_level_t i_lvl,
                     kdebug_trc_tag_t i_tag,
                             uint32_t i_d1,
                             uint32_t i_d2)
{
    if (g_kshort_trace.get_trace_level() >= i_lvl)
    {
        kdebug_trc_data_t l_data = {};
        l_data.tid   = task_gettid();
        l_data.u32_1 = i_d1;
        l_data.u32_2 = i_d2;
        g_kshort_trace.add(i_tag, l_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KSHORT_SET_LEVEL(simple_trace_level_t i_lvl)
{
    g_kshort_trace.set_trace_level(i_lvl);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KLONG_INIT(uint32_t i_size, simple_trace_format_t i_format)
{
    g_klong_trace.init(i_size, i_format);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KLONG(simple_trace_level_t i_lvl,
                    kdebug_trc_tag_t i_tag,
                            uint32_t i_d1,
                            uint32_t i_d2)
{
    if (g_klong_trace.get_trace_level() >= i_lvl)
    {
        kdebug_trc_data_t l_data = {};
        l_data.tid   = task_gettid();
        l_data.u32_1 = i_d1;
        l_data.u32_2 = i_d2;
        g_klong_trace.add(i_tag, l_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KALLOC_INIT(uint32_t i_size, simple_trace_format_t i_format)
{
    g_kalloc_trace.init(i_size, i_format);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KALLOC(simple_trace_level_t i_lvl,
                     kalloc_trc_tag_t i_tag,
                   kalloc_trc_data_t &i_data)
{
    if (g_kalloc_trace.get_trace_level() >= i_lvl)
    {
        i_data.tid = task_gettid();
        g_kalloc_trace.add(i_tag, i_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KALLOC(simple_trace_level_t i_lvl,
                     kalloc_trc_tag_t i_tag,
                     uint16_t         i_step,
                     uint16_t         i_substep,
                     uint16_t         i_data)
{
    if (g_kalloc_trace.get_trace_level() >= i_lvl)
    {
        kalloc_trc_data_t l_data      = {};
        l_data.istep                  = i_step;
        l_data.substep                = i_substep;
        l_data.requested_pages        = i_data;
        l_data.cv_pagesAvail_heap     = PageManager::availPages();
        l_data.cv_low_page_count_heap = PageManager::lowPageCount();
        l_data.cv_pagesAvail_res      = PageManager::availPagesRes();
        g_kalloc_trace.add(i_tag, l_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KMEM_INIT(uint32_t i_size, simple_trace_format_t i_format)
{
    g_kmemstats_trace.init(i_size, i_format);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KMEM(kmem_trc_tag_t i_tag, kmem_trc_data_t &i_data)
{
    PageManager::get_stats(i_data);
    HeapManager::get_stats(i_data);
    Block::get_stats(i_data);
    i_data.tid = task_gettid();
    g_kmemstats_trace.add(i_tag, i_data);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KMEM(simple_trace_level_t i_lvl,
                     kmem_trc_tag_t i_tag,
                   kmem_trc_data_t &i_data)
{
    if (g_kmemstats_trace.get_trace_level() >= i_lvl)
    {
        STRC_KMEM(i_tag, i_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KMEM(simple_trace_level_t i_lvl,
                     kmem_trc_tag_t i_tag,
                     uint16_t       i_step,
                     uint16_t       i_substep,
                     uint16_t       i_data)
{
    if (g_kmemstats_trace.get_trace_level() >= i_lvl)
    {
        kmem_trc_data_t l_data = {};
        l_data.istep           = i_step;
        l_data.substep         = i_substep;
        l_data.requested_pages = i_data;
        STRC_KMEM(i_tag, l_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void SET_TRACE_LEVEL(simple_trc_t i_trc, simple_trace_level_t i_lvl)
{
    if (i_trc == SIMPLE_TRC_KMEM)
    {
        g_kmemstats_trace.set_trace_level(i_lvl);
    }
    else if (i_trc == SIMPLE_TRC_KALLOC)
    {
        g_kalloc_trace.set_trace_level(i_lvl);
    }
    else if (i_trc == SIMPLE_TRC_KSHORT)
    {
        g_kshort_trace.set_trace_level(i_lvl);
    }
    else if (i_trc == SIMPLE_TRC_KLONG)
    {
        g_klong_trace.set_trace_level(i_lvl);
    }
}

