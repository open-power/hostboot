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

SimpleTrace<simple_trace_base_entry_t, kmem_trc_data_t>   g_kmemstats_trace;
SimpleTrace<simple_trace_base_entry_t, kalloc_trc_data_t> g_kalloc_trace;

////////////////////////////////////////////////////////////////////////////////
void SimpleTrace_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::KMEMTRACE,
                             &g_kmemstats_trace,
                             sizeof(g_kmemstats_trace));
    DEBUG::add_debug_pointer(DEBUG::KALLOCTRACE,
                             &g_kalloc_trace,
                             sizeof(g_kalloc_trace));
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KALLOC_INIT(uint32_t i_size, simple_trace_format_t i_format)
{
    g_kalloc_trace.init(i_size, i_format);
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KALLOC(kalloc_trc_tag_t i_tag, kalloc_trc_data_t &i_data)
{
    i_data.tid = task_gettid();
    g_kalloc_trace.add(i_tag, i_data);
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
                           uint16_t i_requested_pages)
{
    if (g_kmemstats_trace.get_trace_level() >= i_lvl)
    {
        kmem_trc_data_t l_data{0};
        l_data.requested_pages = i_requested_pages;
        l_data.tid             = task_gettid();
        STRC_KMEM(i_tag, l_data);
    }
}

////////////////////////////////////////////////////////////////////////////////
void STRC_KMEM(simple_trace_level_t i_lvl,
                     kmem_trc_tag_t i_tag,
                           uint16_t i_istep,
                           uint16_t i_substep)
{
    if (g_kmemstats_trace.get_trace_level() >= i_lvl)
    {
        kmem_trc_data_t l_data{0};
        l_data.istep    = i_istep;
        l_data.substep  = i_substep;
        STRC_KMEM(i_tag, l_data);
    }
}
