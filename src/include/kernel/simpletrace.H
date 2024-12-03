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
 *        size, where each trace element is a struct of data. The trace element
 *        is made up of base data + user data.
 *         ie,    element = { simple_trace_base_entry_t,  kmem_trc_data_t   }
 *            or  element = { simple_trace_timed_entry_t, kshort_trc_data_t }
 */

#ifndef __KERNEL_SIMPLETRACE_H
#define __KERNEL_SIMPLETRACE_H

#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <kernel/types.h>
#include <kernel/console.H>
#include <kernel/timemgr.H>
#include <kernel/misc.H>
#include <arch/ppc.H>

static constexpr size_t KSHORT_SIZE    = 81920;//!> size of kshort trace in bytes
static constexpr size_t KLONG_SIZE     = 4096; //!> size of klong  trace in bytes
static constexpr size_t KMEMSTATS_SIZE = 24576;//!> size of kmem   trace in bytes
static constexpr size_t KALLOC_SIZE    = 8192; //!> size of kalloc trace in bytes

enum simple_trc_t      // enums for SET_TRACE_LEVEL
{
    SIMPLE_TRC_KMEM,
    SIMPLE_TRC_KALLOC,
    SIMPLE_TRC_KSHORT,
    SIMPLE_TRC_KLONG
};

// Do not reuse or delete trace enums - always create a new enum for a new trace.
// This ensures backward compatibility.

enum kdebug_trc_tag_t : uint16_t
{
    KDBG_PM_ALLOC_USR_ENTER        = 0x1001,
    KDBG_PM_ALLOC_USR_EXIT         = 0x1002,
    KDBG_PM_FREE_ENTER             = 0x1003,
    KDBG_PM_FREE_EXIT              = 0x1004,
    KDBG_PM_COALESCE_ENTER         = 0x1005,
    KDBG_PM_COALESCE_START         = 0x1006,
    KDBG_PM_COALESCE_EXIT          = 0x1007,
    KDBG_PM_ALLOC_KER_ENTER        = 0x1008,
    KDBG_PM_ALLOC_KER_EXIT         = 0x1009,
    KDBG_PM_ADD_MEMORY             = 0x100A,
    KDBG_PM_USR_GET_RES_FAIL       = 0x100B,
    KDBG_PM_PERIODIC_RES_INTERVAL  = 0x100C,
    KDBG_PM_PERIODIC_KER_MISS      = 0x100D,

    KDBG_HM_ALLOC                  = 0x2001,
    KDBG_HM_REALLOC                = 0x2002,
    KDBG_HM_FREE                   = 0x2003,
    KDBG_HM_COALESCE               = 0x2004,
    KDBG_HM_NEW_PAGE               = 0x2005,
    KDBG_HM_ALLOC_BIG              = 0x2006,
    KDBG_HM_REALLOC_BIG            = 0x2007,
    KDBG_HM_FREE_BIG               = 0x2008,
    KDBG_HM_ALLOC_HUGE             = 0x2009,
    KDBG_HM_REALLOC_HUGE           = 0x200A,
    KDBG_HM_FREE_HUGE              = 0x200B,
    KDBG_HM_ALLOC_ASSERT_NOT_F     = 0x200C,
    KDBG_HM_FREE_ASSERT_NOT_A      = 0x200D,
    KDBG_HM_FREE_BIG_ASSERT        = 0x200E,
    KDBG_HM_ALLOC_HUGE_NO_CHUNKS   = 0x200F,
    KDBG_HM_FREE_CRASH_NOT_V       = 0x2010,
    KDBG_HM_COALESCE_ASSERT_NOT_F  = 0x2011,
    KDBG_HM_COALESCE_ASSERT_NOT_C  = 0x2012,
    KDBG_HM_HUGE_ALLOC_BLOCK_ERROR = 0x2013,
    KDBG_HM_HUGE_SETPERM_ERROR     = 0x2014,

    KDBG_BK_SET_PERM_EINVAL        = 0x3000,
    KDBG_BK_SET_PERM_SPTE_EINVAL_1 = 0x3001,
    KDBG_BK_SET_PERM_SPTE_EINVAL_2 = 0x3002,
    KDBG_BK_SET_PERM_SPTE_EINVAL_3 = 0x3003,
    KDBG_BK_SET_PERM_SPTE_EINVAL_4 = 0x3004,
    KDBG_BK_SET_PERM_SPTE_EINVAL_5 = 0x3005,
    KDBG_BK_REMOVE_PAGES_EINVAL    = 0x3006,

    KDBG_SET_FORCE_PERIODIC        = 0xE000,

    KDBG_TEMP_TRACE                = 0xF000, // temp trace used for quick debug

    KDBG_TRACE_FREEZE              = 0xFFFF,
};

enum kdebug_freeze_t
{
    KDBG_PROG_EX            = 0x0001,
    KDBG_DSI                = 0x0002,
    KDBG_DATA_SEGMENT_EX    = 0x0003,
    KDBG_INST_STORAGE_EX    = 0x0004,
    KDBG_INST_SEGMENT_EX    = 0x0005,
    KDBG_ALIGNMENT_EX       = 0x0006,
    KDBG_ILLEGAL_INST       = 0x0007,
    KDBG_FP_UNAVAILABLE     = 0x0008,
    KDBG_SOFTPATCH          = 0x0009,
    KDBG_MACHINE_CHECK      = 0x000A,
    KDBG_USR_MACHNE_CHECK   = 0x000B,
    KDBG_UNHANDLED_EX       = 0x000C,
    KDBG_ASSERT             = 0x000D,
};

typedef struct kdebug_trc_data
{
    tid_t    tid;
    uint32_t u32_1;
    uint32_t u32_2;
}  __attribute__((packed)) kdebug_trc_data_t;

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
    K_ALLOC_KER_GET_RES    = 0x1004,  // kernel thread fails at allocatePage,
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
    uint32_t cv_pagesAvail_heap;
    uint32_t cv_low_page_count_heap;
    uint32_t cv_pagesAvail_res;
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
    KMEM_STATS_SYSCALL                     = 0x1001, // each istep logs a trace
    KMEM_STATS_ALLOC_PG_USR_GET_RES_FAIL   = 0x1002, // usr thread get iv_reserved fails
    KMEM_STATS_ALLOC_PG_USR_TIMEOUT_ASSERT = 0x1003, // usr thread times out with OOM
    KMEM_STATS_ALLOC_PG_KER_GET_RES_FAIL   = 0x1004, // kernel thread get iv_reserved fails
    KMEM_STATS_ALLOC_PG_KER_KASSERT        = 0x1005, // kernel thread hits OOM kassert
    KMEM_STATS_FORCE_MEMORY_PERIODIC       = 0x1006, // force castout and coalesce
    KMEM_STATS_ALLOC_BIG_KASSERT_1         = 0x1007, // allocateBig hits OOM kassert
    KMEM_STATS_ALLOC_BIG_KASSERT_2         = 0x1008, // allocateBig hits OOM kassert
};

constexpr int BUCKETS     = 12;
constexpr int BUCKETS_RES = 9; // max is 256, so only use 9 buckets

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
    uint32_t cv_free_bucket_count_heap[BUCKETS];
    uint32_t cv_allocatePage_usr_wait;
    uint32_t cv_pagesAvail_res;
    uint32_t cv_low_page_count_res;
    uint32_t cv_free_bucket_count_res[BUCKETS_RES];

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
    uint32_t cv_free_bucket_counts[BUCKETS];

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
    STRC_OFF   = 0,
    STRC_FORCE = 0, // force the trace even if it is OFF
    STRC_L1    = 1,
    STRC_L2    = 2,
    STRC_L3    = 3,
    STRC_L4    = 4,
};

/**
 *******************************************************************************
 *  @brief Define the type of format of any SimpleTrace entry
 */
enum simple_trace_format_t : uint16_t
{
    BASE_FORMAT  = 0x0001,
    TIME_FORMAT  = 0x0002
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
 *  @brief Define the TIME_FORMAT entry
 */
typedef struct simple_trace_timed_entry
{
    uint16_t iv_tag;
    uint16_t iv_cpuid;
    uint32_t iv_sec;
    uint32_t iv_nsec;
    void set(uint16_t i_tag)
    {
        uint64_t sec{0};
        uint64_t nsec{0};
        TimeManager::convertTicksToSec(getTB(), sec, nsec);
        iv_sec   = static_cast<uint32_t>(sec);
        iv_nsec  = static_cast<uint32_t>(nsec);
        iv_tag   = i_tag;
        if (KernelMisc::in_kernel_mode())
        {
            iv_cpuid = static_cast<uint16_t>(getCpuId());
        }
        else
        {
            iv_cpuid = static_cast<uint16_t>(task_getcpuid());
        }
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
    static constexpr uint32_t EMPTY_TAG  = 0xDEAD;
    static constexpr uint32_t EYECATCHER = 0xABCDDCBA;

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
    typedef struct simple_trace_hdr
    {
        // Do not change the order of these variables,
        //  the perl debug scripts depend upon the order when reading the memory
        uint32_t               iv_eyecatcher;//!< const tag for this struct
        simple_trace_version_t iv_version;   //!< version of this SimpleTrace
        uint16_t               iv_format;    //!< specifies the format of each entry
        uint32_t               iv_level;     //!< trace level
        uint32_t               iv_e_size;    //!< byte size of a trace entry
        uint32_t               iv_size;      //!< byte size of the entire memory buffer
        uint32_t               iv_max;       //!< number of traces which fit in this buffer
        volatile uint64_t      iv_idx;       //!< count used for the next entry
        uint8_t                iv_data[];    //!< the array of trace entries
    } __attribute__((packed)) simple_trace_hdr_t;

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
     *  @brief  Set the trace level
     *  @param[in]  i_lvl   trace level to set
     */
    void set_trace_level(simple_trace_level_t i_lvl)
    {
        if (!iv_hdr) {return;}
        iv_hdr->iv_level = i_lvl;
    }

    /**
     ***************************************************************************
     *  @brief Allocate the buffer and initialize it
     *  @param[in]  i_size    number of bytes to allocate
     *  @param[in]  i_format  format of each trace entry
     */
    void init(uint32_t i_size, simple_trace_format_t i_format);

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
 *  @brief Convert a 64-bit addr to a uint32_t
 */
#define PTR_TO_u32(_p) (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(_p)))

/**
 *******************************************************************************
 *  @brief Initialize the SimpleTrace named g_kshort_trace
 *  @param[in]  i_size    number of bytes to allocate
 *  @param[in]  i_format  format for each entry in this trace
 */
void STRC_KSHORT_INIT(uint32_t i_size, simple_trace_format_t i_format);

/**
 *******************************************************************************
 *  @brief Add a trace entry to g_kshort_trace
 *  @param[in]  i_lvl   trace level
 *  @param[in]  i_tag   tag for the new trace entry
 *  @param[in]  i_d1    data for the new trace entry
 *  @param[in]  i_d2    data for the new trace entry
 */
void STRC_KSHORT(simple_trace_level_t i_lvl,
                     kdebug_trc_tag_t i_tag,
                             uint32_t i_d1,
                             uint32_t i_d2);

#define STRC1_KSHORT(_tag, _d1, _d2) \
         STRC_KSHORT(STRC_L1, _tag, static_cast<uint32_t>(_d1), static_cast<uint32_t>(_d2))
#define STRC2_KSHORT(_tag, _d1, _d2) \
         STRC_KSHORT(STRC_L2, _tag, static_cast<uint32_t>(_d1), static_cast<uint32_t>(_d2))
#define STRC3_KSHORT(_tag, _d1, _d2) \
         STRC_KSHORT(STRC_L3, _tag, static_cast<uint32_t>(_d1), static_cast<uint32_t>(_d2))
#define STRC4_KSHORT(_tag, _d1, _d2) \
         STRC_KSHORT(STRC_L4, _tag, static_cast<uint32_t>(_d1), static_cast<uint32_t>(_d2))

void STRC_KSHORT_SET_LEVEL(simple_trace_level_t i_lvl);

/**
 *******************************************************************************
 *  @brief Initialize the SimpleTrace named g_kslow_trace
 *  @param[in]  i_size    number of bytes to allocate
 *  @param[in]  i_format  format for each entry in this trace
 */
void STRC_KLONG_INIT(uint32_t i_size, simple_trace_format_t i_format);

/**
 *******************************************************************************
 *  @brief Add a trace entry to g_klong_trace
 *  @param[in]  i_lvl   trace level
 *  @param[in]  i_tag   tag for the new trace entry
 *  @param[in]  i_d1    data for the new trace entry
 *  @param[in]  i_d2    data for the new trace entry
 */
void STRC_KLONG(simple_trace_level_t i_lvl,
                    kdebug_trc_tag_t i_tag,
                            uint32_t i_d1,
                            uint32_t i_d2);

#define STRC1_KLONG(_tag, _d1, _d2) \
         STRC_KLONG(STRC_L1, _tag, static_cast<uint32_t>(_d1), static_cast<uint32_t>(_d2))

/**
 *******************************************************************************
 *  @brief Freeze the SimpleTrace. Do not allow any more entries.
 *         Use to ensure FFDC, by stopping a trace at the time a fatal error is detected.
 *         Currently in use for exceptions like DSI, and for assert.
 */
void STRC_FREEZE(uint32_t i_d1=0, uint32_t i_d2=0);

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
 *  @brief Add a trace entry to g_kalloc_trace
 *  @param[in]  trace level
 *  @param[in]  tag for the new trace entry
 *  @param[in]  step
 *  @param[in]  substep
 *  @param[in]  data
 */
void STRC_KALLOC(simple_trace_level_t i_lvl,
                     kalloc_trc_tag_t i_tag,
                     uint16_t         i_step,
                     uint16_t         i_substep,
                     uint16_t         i_data);

#define STRC1_KALLOC(_tag, _step, _substep, _u16)                   \
        STRC_KALLOC(STRC_L1, _tag, static_cast<uint16_t>(_step),    \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC2_KALLOC(_tag, _step, _substep, _u16)                   \
        STRC_KALLOC(STRC_L2, _tag, static_cast<uint16_t>(_step),    \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC3_KALLOC(_tag, _step, _substep, _u16)                   \
        STRC_KALLOC(STRC_L3, _tag, static_cast<uint16_t>(_step),    \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC4_KALLOC(_tag, _step, _substep, _u16)                   \
        STRC_KALLOC(STRC_L4, _tag, static_cast<uint16_t>(_step),    \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))

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

/**
 *******************************************************************************
 *  @brief Add a trace entry to g_kmem_trace
 *  @param[in]  trace level
 *  @param[in]  tag for the new trace entry
 *  @param[in]  step
 *  @param[in]  substep
 *  @param[in]  data
 */
void STRC_KMEM(simple_trace_level_t i_lvl,
                     kmem_trc_tag_t i_tag,
                     uint16_t       i_step,
                     uint16_t       i_substep,
                     uint16_t       i_data);

#define STRC1_KMEM(_tag, _step, _substep, _u16)                     \
        STRC_KMEM(STRC_L1, _tag, static_cast<uint16_t>(_step),      \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC2_KMEM(_tag, _step, _substep, _u16)                     \
        STRC_KMEM(STRC_L2, _tag, static_cast<uint16_t>(_step),      \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC3_KMEM(_tag, _step, _substep, _u16)                     \
        STRC_KMEM(STRC_L3, _tag, static_cast<uint16_t>(_step),      \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))
#define STRC4_KMEM(_tag, _step, _substep, _u16)                     \
        STRC_KMEM(STRC_L4, _tag, static_cast<uint16_t>(_step),      \
                                   static_cast<uint16_t>(_substep), \
                                   static_cast<uint16_t>(_u16))

/**
 *******************************************************************************
 *  @brief Set the trace level for a SimpleTrace
 *  @param[in]  enum designating the trace object to modify
 *  @param[in]  new trace level for the trace object
 */
void SET_TRACE_LEVEL(simple_trc_t i_trc, simple_trace_level_t i_lvl);

#endif
