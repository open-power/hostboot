/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/simpletrace.H $                            */
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
 * @file simpletrace.H
 * @brief Define class SimpleTrace, which is a ring trace buffer of a fixed
 *        size, where each trace element is a struct of data.
 */

#ifndef __KERNEL_SIMPLETRACE_H
#define __KERNEL_SIMPLETRACE_H

#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <kernel/types.h>
#include <kernel/console.H>

////////////////////////////////////////////////////////////////////////////////
// Definitions for g_kalloc_trace
////////////////////////////////////////////////////////////////////////////////

/**
 *******************************************************************************
 *  @brief Define the trace tags for each kalloc entry
 */
enum kalloc_trc_tag_t : uint16_t
{
    K_ALLOC_USR_FIRST      = 0x1001,  // usr thread first failure in allocatePage,
                                      // so log it and retry until timeout
    K_ALLOC_USR_PERIODIC   = 0x1002,  // usr thread is in the failure loop in allocatePage,
                                      // and runs forceMemoryPeriodic
    K_ALLOC_USR_GET_RES    = 0x1003,  // usr thread multiple fails at allocatePage,
                                      // so get memory from iv_reserve
    K_ALLOC_KERNEL_GET_RES = 0x1004,  // kernel thread fails at allocatePage,
                                      // so get memory from iv_reserve
};

/**
 *******************************************************************************
 *  @brief Define the data in each kalloc entry. This trace provides general
 *         information for page allocation problems in the PageManager.
 */
typedef struct kalloc_trc_data
{
    // Do not change the order of these variables,
    //  the perl debug scripts depend upon the order when reading the memory
    uint16_t istep;
    uint16_t substep;
    tid_t    tid;
    uint16_t requested_pages;
}  __attribute__((packed)) kalloc_trc_data_t;

////////////////////////////////////////////////////////////////////////////////
// Definitions for g_kmemstats_trace
////////////////////////////////////////////////////////////////////////////////

/**
 *******************************************************************************
 *  @brief Define the trace tags for each kmemstats entry
 */
enum kmem_trc_tag_t : uint16_t
{
    KMEM_STATS_SYSCALL                            = 0x1001, // each istep logs a trace
    KMEM_STATS_ALLOC_PAGE_OOM_USR_GET_RES_FAIL    = 0x1002, // usr thread get iv_reserved fails
    KMEM_STATS_ALLOC_PAGE_OOM_USR_TIMEOUT_ASSERT  = 0x1003, // usr thread times out with OOM
    KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_GET_RES_FAIL = 0x1004, // kernel thread get iv_reserved fails
    KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_KASSERT      = 0x1005, // kernel thread hits OOM kassert
};

/**
 *******************************************************************************
 *  @brief Define the data in each kmemstats entry. This trace shows the entire
 *         hostboot memory state for PageManager, HeapManager, and Block.
 */
typedef struct kmem_trc_data
{
    // Do not change the order of the variables in this struct,
    //  the perl debug scripts depend upon the order when reading the memory
    uint16_t istep;
    uint16_t substep;
    tid_t    tid;
    uint16_t requested_pages;

    // The following vars are named to match the actual class variables, to
    // enable easier lookup from stat to class.

    // pagemgr
    uint32_t cv_pagesTotal;
    uint32_t cv_pagesAvail_heap;
    uint32_t cv_low_page_count_heap;
    uint32_t cv_coalesce_state;
    uint32_t cv_coalesce_attempts;
    uint32_t cv_coalesce_count;
    uint32_t cv_free_bucket_count_heap[16];
    uint32_t cv_allocatePage_coalesce_wait;
    uint32_t cv_pagesAvail_res;
    uint32_t cv_low_page_count_res;
    uint32_t cv_free_bucket_count_res[8];

    // block
    uint32_t cv_pages_allocated;
    uint32_t cv_pages_allocated_peak;
    uint32_t cv_pages_allocated_count;
    uint32_t cv_ro_evict_req;
    uint32_t cv_rw_evict_req;

    // heapmgr
    uint32_t cv_free_chunks;
    uint32_t cv_free_bytes;
    uint32_t cv_inuse_chunks;
    uint32_t cv_inuse_bytes;
    uint32_t cv_smallheap_coalesce_attempts;
    uint32_t cv_smallheap_coalesce_count;
    uint32_t cv_smallheap_coalesce_page;
    uint32_t cv_smallheap_page_count;
    uint32_t cv_largeheap_page_count;
    uint32_t cv_largeheap_page_max;
    uint32_t iv_hugeblock_allocated;
    uint32_t cv_hugeblock_page_count;
    uint32_t cv_hugeblock_page_max;
    uint32_t cv_smallheap_user_allocated;
    uint32_t cv_smallheap_allocated;
    uint32_t cv_smallheap_alloc_hw;
    uint32_t cv_free_bucket_counts[12];

}  __attribute__((packed)) kmem_trc_data_t;

////////////////////////////////////////////////////////////////////////////////
// Definitions for class SimpleTrace
////////////////////////////////////////////////////////////////////////////////

/**
 *******************************************************************************
 *  @brief Define the trace levels for a SimpleTrace
 */
enum simple_trace_level_t
{
    STRC_L0  = 0,
    STRC_L1  = 1,
    STRC_L2  = 2,
    STRC_L3  = 3,
    STRC_L4  = 4
};

/**
 *******************************************************************************
 *  @brief Define the type of format of any SimpleTrace entry
 */
enum simple_trace_format_t : uint16_t
{
    BASE_FORMAT  = 0x0001,
    TIMED_FORMAT = 0x0002
};

/**
 *******************************************************************************
 *  @brief Define the BASE_FORMAT entry
 */
typedef struct simple_trace_entry
{
    uint16_t iv_tag;
    void set(uint16_t i_tag) {iv_tag = i_tag;}
} __attribute__((packed)) simple_trace_base_entry_t;

/**
 *******************************************************************************
 *  @brief Define the TIMED_FORMAT entry
 */
typedef struct simple_trace_timed_entry
{
    uint16_t iv_tag;
    uint32_t iv_tbu;
    uint32_t iv_tbl;
    void set(uint16_t i_tag)
    {
        iv_tag = i_tag;
        // TO DO - get time base
    }
} __attribute__((packed)) simple_trace_timed_entry_t;

/**
 *******************************************************************************
 *  @brief Define the template class SimpleTrace
 *         BASE_DATA is a simple_trace base format of data to store in each trace entry
 *         USER_DATA is the user-defined data to store in each trace entry
 */
template <typename BASE_DATA, typename USER_DATA>
class SimpleTrace
{
    static constexpr uint32_t EMPTY_TAG = 0xDEAD;

    /**
     ***************************************************************************
     *  @brief Define SimpleTrace versions to allow future changes
     */
    enum simple_trace_version_t : uint16_t
    {
        SIMPLE_TRACE_VERSION_1 = 0xBEA1,
        SIMPLE_TRACE_VERSION_2 = 0xBEA2
    };

    /**
     ***************************************************************************
     *  @brief Define the header for each SimpleTrace array
     */
    struct simple_trace_hdr_t
    {
        // Do not change the order of these variables,
        //  the perl debug scripts depend upon the order when reading the memory
        simple_trace_version_t iv_version;   //!< version of this SimpleTrace
        uint16_t               iv_format;    //!< specifies the format of each entry
        uint32_t               iv_level;     //!< trace level
        uint32_t               iv_e_size;    //!< byte size of a trace entry
        uint32_t               iv_size;      //!< byte size of the entire memory buffer
        uint32_t               iv_max;       //!< number of traces which fit in this buffer
        uint32_t               iv_pad;
        volatile uint64_t      iv_idx;       //!< count used for the next entry
        uint8_t                iv_data[];    //!< the array of trace entries
    };

    /**
     ***************************************************************************
     *  @brief Define a single trace entry
     */
    typedef struct simple_trace_entry
    {
        BASE_DATA iv_base;
        USER_DATA iv_data;
    } __attribute__((packed)) simple_trace_entry_t;

    /**
     ***************************************************************************
     *  @brief  Select an element in the trace array and return a pointer to it
     *  @return  pointer to the trace entry
     */
    simple_trace_entry_t* add()
    {
        simple_trace_entry_t *l_entry;
        uint64_t              l_idx{0};
        uint64_t              l_off{0};

        l_idx   = __sync_fetch_and_add(&iv_hdr->iv_idx, 1);
        l_idx  %= iv_hdr->iv_max;
        l_off   = l_idx * iv_hdr->iv_e_size;
        l_entry = (simple_trace_entry_t*)(iv_hdr->iv_data+l_off);
        return l_entry;
    }

    simple_trace_hdr_t *iv_hdr{nullptr}; //!< The trace array memory allocated in init

    /**
     ***************************************************************************
     *  @brief Add a trace entry to g_kmem_trace
     *  @param[in]  i_tag   tag for the new trace entry
     *  @param[in]  i_data  data for the new trace entry
     */
    void STRC_KMEM(kmem_trc_tag_t i_tag, kmem_trc_data_t &i_data);

  public:
    /**
     ***************************************************************************
     *  @brief Free the trace array which was allocated in init()
     */
    ~SimpleTrace()
    {
        if (iv_hdr)
        {
            delete [] iv_hdr;
        }
    }

    /**
     ***************************************************************************
     *  @brief Allocate the buffer and initialize it
     *  @param[in]  i_size    number of bytes to allocate
     *  @param[in]  i_format  format of each trace entry
     */
    void init(uint32_t i_size, simple_trace_format_t i_format)
    {
        iv_hdr = (simple_trace_hdr_t*) new uint8_t[i_size];
        if (!iv_hdr) {return;}

        iv_hdr->iv_version = SIMPLE_TRACE_VERSION_1;
        iv_hdr->iv_format  = i_format;
        iv_hdr->iv_level   = 0;
        iv_hdr->iv_size    = i_size;
        iv_hdr->iv_e_size  = sizeof(simple_trace_entry_t);
        iv_hdr->iv_idx     = 0;
        iv_hdr->iv_max     = (i_size - sizeof(simple_trace_hdr_t)) / iv_hdr->iv_e_size;

        if (iv_hdr->iv_max == 0)
        {
            printkd("simpletrace::ctor: i_size:%d e_size:%d iv_max:%d\n",
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

    /**
     ***************************************************************************
     *  @brief  Set the trace level
     *  @param[in]  i_lvl   trace level to set
     */
    void set_trace_level(uint32_t &i_lvl)
    {
        if (!iv_hdr) {return;}
        iv_hdr->iv_level = i_lvl;
    }

    /**
     ***************************************************************************
     *  @brief  Get the trace level
     *  @return  the trace level for this SimpleTrace
     */
    uint32_t get_trace_level()
    {
        if (!iv_hdr) {return 0;}
        return iv_hdr->iv_level;
    }

    /**
     ***************************************************************************
     *  @brief  Add a trace entry to the array
     *  @param[in]  i_tag   tag for the new trace entry
     */
    void add(uint16_t i_tag)
    {
        if (!iv_hdr) {return;}
        simple_trace_entry_t *l_entry = add();
        l_entry->iv_base.set(i_tag);
        l_entry->iv_data.set();
    }

    /**
     ***************************************************************************
     *  @brief  Add a trace entry to the array
     *  @param[in]  i_tag   tag for the new trace entry
     *  @param[in]  i_data  data for the new trace entry
     */
    void add(uint16_t i_tag, USER_DATA &i_data)
    {
        if (!iv_hdr) {return;}
        simple_trace_entry_t *l_entry = add();
        l_entry->iv_base.set(i_tag);
        l_entry->iv_data = i_data;
    }
};

/**
 *******************************************************************************
 *  @brief Save pointers to SimpleTrace structs for later debug
 */
void SimpleTrace_addDebugPointers();

/**
 *******************************************************************************
 *  @brief Initialize the SimpleTrace named g_kalloc_trace
 *  @param[in]  i_size    number of bytes to allocate
 *  @param[in]  i_format  format for each entry in this trace
 */
void STRC_KALLOC_INIT(uint32_t i_size, simple_trace_format_t i_format);

/**
 *******************************************************************************
 *  @brief Add a trace entry to g_kalloc_trace
 *  @param[in]  i_lvl   trace level
 *  @param[in]  i_tag   tag for the new trace entry
 *  @param[in]  i_data  data for the new trace entry
 */
void STRC_KALLOC(simple_trace_level_t i_lvl,
                     kalloc_trc_tag_t i_tag,
                   kalloc_trc_data_t &i_data);

/**
 *******************************************************************************
 *  @brief Initialize the SimpleTrace named g_kmem_trace
 *  @param[in]  i_size    number of bytes to allocate
 *  @param[in]  i_format  format for each entry in this trace
 */
void STRC_KMEM_INIT(uint32_t i_size, simple_trace_format_t i_format);

/**
 *******************************************************************************
 *  @brief Add a trace entry to g_kmem_trace
 *  @param[in]  i_lvl   trace level
 *  @param[in]  i_tag   tag for the new trace entry
 *  @param[in]  i_data  struct to add into the trace
 */
void STRC_KMEM(simple_trace_level_t i_lvl,
                     kmem_trc_tag_t i_tag,
                   kmem_trc_data_t &i_data);

#endif
