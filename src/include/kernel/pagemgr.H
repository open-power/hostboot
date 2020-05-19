/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/pagemgr.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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
         * Default Constructor
         */
        PageManagerCore()
            : iv_available(0) {}

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
         * Query the the current number of pages in the page manager
         */
        ALWAYS_INLINE
        size_t getFreePageCount() const { return iv_available; }

        /**
         * Get the start of memory after the code
         */
        ALWAYS_INLINE uint64_t firstPageAddr( void ) const
        {
            return ALIGN_PAGE(VFS_LAST_ADDRESS);
        }

    private:

        size_t iv_available;            //!< free pages
        Util::Lockfree::Stack<page_t> iv_heap[BUCKETS]; //!< The heap

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
         * @return pointer to requested memory
         */
        static void* allocatePage(size_t n = 1, bool userspace = false);

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

        enum
        {
            // Always keep this many free pages for the kernel to use
            KERNEL_HEAP_RESERVED_PAGES = 10,

            // Triggers a NORMAL page castout
#ifdef CONFIG_P9_VPO_COMPILE // VPO has constrained mem env -> higher threshold
            LOWMEM_NORM_LIMIT = 32,
#else
            LOWMEM_NORM_LIMIT = 16,
#endif

            // Triggers CRITICAL page castout
            LOWMEM_CRIT_LIMIT = KERNEL_HEAP_RESERVED_PAGES+1,
        };

        static size_t cv_coalesce_count;        //!< running coalesced counter
        static size_t cv_low_page_count;        //!< lowest page count
        static size_t cv_alloc_coalesce_count;  //!< number of repeat allocs

    protected:

        PageManager();
        ~PageManager() {};

    private:
        void _initialize();

        void* _allocatePage(size_t,bool);   //!< see allocatePage()
        void _freePage(void*, size_t);       //!< see freePage()
        void _coalesce( void );              //!< see coalesce()
        void _addMemory(size_t, size_t);     //!< see addMemory()
        void _addDebugPointers();           //!< see addDebugPointers()

        /** see queryAvail() */
        ALWAYS_INLINE uint64_t _queryAvail() const
        {
            return (100*iv_pagesAvail)/iv_pagesTotal;
        }

        ALWAYS_INLINE uint64_t firstPageAddr( void ) const
        {
            return iv_heap.firstPageAddr();
        }

        /** see availPages() */
        ALWAYS_INLINE uint64_t _availPages() const
        {
            return iv_pagesAvail;
        }

        // Private data

        uint64_t iv_pagesAvail;         //!< free pages (for debug)
        uint64_t iv_pagesTotal;         //!< Total number o fpages
        Spinlock iv_lock;               //!< lock for allocating

        PageManagerCore iv_heap;        //!< Main heap
        PageManagerCore iv_heapKernel;  //!< kernel heap for out-of-mem
};

#endif
