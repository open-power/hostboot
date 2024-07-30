/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/pagemgr.H $                                */
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
#ifndef __KERNEL_PAGEMGR_H
#define __KERNEL_PAGEMGR_H

#include <stdint.h>
#include <limits.h>
#include <util/lockfree/stack.H>
#include <kernel/vmmmgr.H>
#include <builtins.h>
#include <kernel/console.H>
#include <util/align.H>
#include <sys/vfs.h>
#include <utility>
#include <array>

/** @class PageManagerCore
 * @brief Manages the allocation of memory pages
 */
class PageManagerCore
{
    public:
        enum
        {
            BUCKETS = 16,
        };

        struct page_t
        {
            page_t* next;       //!< Next block of pages
            page_t* prev;       //!< Prev block of pages
            page_t* key;        //!< Key for pqueue
        };

        /**
         * Constructor
         * @param[in] i_supports_coalesce, Does this instance support coalesce
         */
        PageManagerCore(bool i_supports_coalesce)
            : iv_supports_coalesce(i_supports_coalesce), iv_spinlock() {}

        /**
         * Add memory to the page manager
         * @param[in] i_addr, The start address of the memory to add
         * @param[in] i_pageCount, The number of pages to add
         * @note i_addr must be on a page boundary
         */
        void addMemory( size_t i_addr, size_t i_pageCount );

        /**
         * Destructor
         */
        ~PageManagerCore( void ) {}

        /**
         * Request page allocations
         * @param[in] i_pageCount, The number of pages requested
         * @return a pointer to the requested allocation | NULL
         * if the request could not be satisfied.
         */
        page_t * allocatePage( size_t i_pageCount );

        /**
         * Return page allocations to the page manager
         * @param[in] i_page, pointer to the allocation
         * @param[in] i_pageCount, the number of pages in the allocation
         * @param[in] i_overAllocated, whether pages to free are the being
         *     returned because the intial allocation was larger than needed
         */
        void freePage(
            void*  i_page,
            size_t i_pageCount,
            bool   i_overAllocated = false );

        /**
         * Coalesce pages in the page manager (defrag)
         */
        void coalesce( void );

        /**
         * Get the start of memory after the code
         */
        ALWAYS_INLINE uint64_t firstPageAddr( void ) const
        {
            return ALIGN_PAGE(VFS_LAST_ADDRESS);
        }

        uint64_t cv_free_bucket_count[BUCKETS] = {};
        uint64_t cv_alloc_sizes      [BUCKETS] = {};
        uint64_t cv_free_pages{0};         //!< sum of pages in free buckets
        uint64_t cv_low_page_count{999999};//!< lowest page count
        uint64_t cv_coalesce_state{0};     //!< 1 if coalesce is running, else 0
        uint64_t cv_coalesce_attempts{0};  //!< num times a coalesce has run
        uint64_t cv_coalesce_count{0};     //!< num times pages were merged

    private:

        Util::Lockfree::Stack<page_t> iv_heap[BUCKETS]; //!< The free heap memory

        bool     iv_supports_coalesce;   //!< true if coalesce is supported
        uint32_t iv_pad1{0xF11DF11D};    // compiler adds this anyway, so put it here

        // The allocator was designed to be lockless. We have ran into a problem
        // in Brazos where all threads (over 256) were trying to allocate a page
        // at the same time.  This resulted in many of them trying to break a large
        // page chunk into smaller fragments.  The later threads ended up seeing
        // no chunks available and claimed we were out of memory.
        //
        // All calls to the functions using iv_spinlock must be running
        // in kernel space so we dont run into any deadlock situations
        //
        // RTC: 98271
        Spinlock iv_spinlock; //!< lock for the iv_heap buckets
                              //     used in allocatePage and coalesce

        //!< Starting address of a heap memory range
        using rangeAddr_t = uint64_t;

        //!< Size of a heap memory range
        using rangeSizeBytes_t = uint64_t;

        //!< Heap memory range tracking element
        using range_t = std::pair<rangeAddr_t,rangeSizeBytes_t>;

        //!< Max number of heap memory ranges tracked by the kernel
        static constexpr size_t MAX_HEAP_RANGES = 4;

        //!< Heap memory range tracker
        std::array<range_t,MAX_HEAP_RANGES> iv_ranges;

        /**
         * Find a page of proper size
         * @param[in] the Size
         * @return a page ptr to a page of size pages
         */
        page_t* pop_bucket(size_t);

        /**
         * Add a pages to the page manager
         * @param[in] ptr to the allocation
         * @param[in] The number of pages
         */
        void push_bucket(page_t*, size_t);
};

/** @class PageManager
 *  @brief Manages the allocation of memory pages.
 */
class PageManager
{
    public:

        static void init();

        /**
         * Allocate pages
         * @param[in] n, Requested allocation in pages
         * @param[in] userspace - Request to allocate came from userspace
         * @param[in] kAllowOom - Allow out-of-memory in kernel mode
         * @return pointer to requested memory
         *
         * If kAllowOom is true and it is executing in kernel mode, then an OOM
         * condition will cause this function to return a null pointer. If not
         * in kernel mode or allowOom is false, then a kernel assert is
         * triggered.
         */
        static void* allocatePage(size_t n = 1, bool userspace = false,
                                  bool kAllowOom = false);

        /**
         * Return pages to the pagemanager
         * @param[in] ptr to storage to release
         * @param[in] n, size in pages
         */
        static void freePage(void*, size_t n = 1);

        /**
         * Query state for available memory
         * @returns percent of pages available
         */
        static uint64_t queryAvail();

        /**
         * Coalesce adjacent free memory blocks
         * @pre This function can only be called from kernel space and
         * requires that all other processes are quiesced
         */
        static void coalesce( void );

        /**
         * Retrieve the number of available pages
         * @returns Number of free pages
         */
        static uint64_t availPages();

        /**
         * Returns if Hostboot is in a small memory environment
         * @returns True if less than 14MB of memory, else false
         */
        static bool isSmallMemEnv();

        /**
         * Add memory to the page manager
         * @param[in] i_addr, The start address of the memory to add
         * @param[in] i_pageCount, The number of pages to add
         * @note i_addr must be on a page boundary
         */
        static void addMemory(size_t i_addr, size_t i_pageCount);

        /**
         * Add pointers to the global debug area
         */
        static void addDebugPointers();

        /**
         * @brief Copy statistics data from memory to o_stats
         * @param[out] o_stats  The memory block to copy statistics data into
         */
        static void get_stats(struct kmem_trc_data &o_stats);

        enum
        {
            HEAP_RESERVED          = 128,             // free pages reserved
            HEAP_RESERVED_MIN_SIZE = 9,               // smallest size to re-fill iv_reserved
            HEAP_RESERVED_LOW_MARK = HEAP_RESERVED/4, // low mark to re-fill iv_reserved
                                                      // with any size
            // Triggers a NORMAL page castout
#ifdef CONFIG_P9_VPO_COMPILE // VPO has constrained mem env -> higher threshold
            LOWMEM_NORM_LIMIT = 32,
#else
            LOWMEM_NORM_LIMIT = 16,
#endif
            // Triggers CRITICAL page castout
            LOWMEM_CRIT_LIMIT = 8,
        };

        static constexpr size_t KMEMSTATS_SIZE = 4096;
        static constexpr size_t KALLOC_SIZE    = 512;

    protected:

        PageManager();
        ~PageManager() {};

    private:
        void _initialize();

        void* _allocatePage(size_t,bool,bool); //!< see allocatePage()
        void _freePage(void*, size_t);         //!< see freePage()
        void _coalesce( void );                //!< see coalesce()
        void _addMemory(size_t, size_t);       //!< see addMemory()
        void _addDebugPointers();              //!< see addDebugPointers()

        /** see queryAvail() */
        ALWAYS_INLINE uint64_t _queryAvail() const
        {
            return (100*iv_heap.cv_free_pages)/cv_pagesTotal;
        }

        ALWAYS_INLINE uint64_t firstPageAddr( void ) const
        {
            return iv_heap.firstPageAddr();
        }

        /** see availPages() */
        ALWAYS_INLINE uint64_t _availPages() const
        {
            return iv_heap.cv_free_pages;
        }

        /** see isSmallMemEnv() */
        ALWAYS_INLINE bool _isSmallMemEnv() const
        {
            return (cv_pagesTotal < 0xE00 /*14MB*/);
        }

        uint64_t cv_pagesTotal{0};                 //!< Total iv_heap + iv_reserved pages
        uint64_t cv_allocatePage_coalesce_wait{0}; //!< num times a usr alloc had to wait

        PageManagerCore iv_heap    { true };  //!< Main heap, allow coalesce
        PageManagerCore iv_reserved{ false }; //!< reserved heap, no coalesce
};

#endif
