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
#include <util/locked/pqueue.H>
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
            BUCKETS = 12,
        };

        /**
         * @brief Used as an addr to memory the size of 1 or more 4k pages
         *        Used to manage free pages in the bucket lists and for coalescing
         */
        struct page_t
        {
            page_t  *next;       //!< Next block of pages
            page_t  *prev;       //!< Prev block of pages
            uint64_t key;        //!< Key  (set to size_t in buckets, page_t in coalesce)
            size_t   size;       //!< size (set to num pages of memory, used in coalesce)
            void set_key(size_t  i_key) {key = i_key;}
            void set_key(page_t *i_key) {key = reinterpret_cast<uint64_t>(i_key);}
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
         */
        void freePage(void*  i_page,
                      size_t i_pageCount);

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

        uint64_t cv_free_bucket_count[BUCKETS]={};//!< number of elements in each bucket
        uint64_t cv_alloc_sizes      [BUCKETS]={};//!< number of allocates to each bucket
        uint64_t cv_free_pages{0};                //!< sum of pages in free buckets
        uint64_t cv_low_page_count{UINT64_MAX};   //!< lowest page count
        uint64_t cv_coalesce_state{0};            //!< 1 if coalesce is running, else 0
        uint64_t cv_coalesce_attempts{0};         //!< num times a coalesce has run
        uint64_t cv_coalesce_count{0};            //!< num times pages were merged

    private:

        static constexpr size_t BUCKETS_LOWER = 2;
        static constexpr size_t BUCKETS_UPPER = BUCKETS; // 0,1 in upper are not used

        // The lower buckets use atomics to be lockless and are all the same
        //   size (bucket 0 memory are all one page, bucket 1 are all two pages)
        Util::Lockfree::Stack<page_t> iv_heap_lower[BUCKETS_LOWER];       //!< buckets 0..1

        // The upper buckets are protected by iv_spinlock, where PQueue sorts
        //   the list of memory by their size. A PQueue remove() returns memory
        //   from the smallest size to the largest.
        Util::Locked::PQueue<page_t,size_t> iv_heap_upper[BUCKETS_UPPER]; //!< buckets 2..11

        bool     iv_supports_coalesce;   //!< true if coalesce is supported
        uint32_t iv_pad1{0xF11DF11D};    //!< compiler adds this anyway for iv_spinlock
                                         //   so put it here to help the debug scripts

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
        //
        // This lock protects the data integrity of the buckets in iv_heap_upper.
        // The buckets in iv_heap_lower are protected using atomics.
        // This lock also protects against fragmentation which can happen during
        // multi-thread bucket access during allocate, free, and coalesce.
        Spinlock iv_spinlock; //!< protects iv_heap_upper and reduces fragmentation

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
         * @brief Find a page of proper size
         * @param[in] the Size
         * @return a page ptr to a page of size pages
         */
        page_t* pop_bucket(size_t);

        /**
         * @brief Add memory into a page manager bucket
         * @param[in] ptr to the allocation
         * @param[in] The number of pages
         */
        void push_bucket(page_t*, size_t);

        /**
         * @brief  Add any extra pages from an allocatePage back into a bucket.
         *         Subtract the size of i_page from i_pageCount and return the
         *           extra memory back into a free bucket.
         * @param[in] Ptr to the allocation
         * @param[in] The number of pages requested
         */
        void check_remain(page_t *i_page, size_t i_pageCount);

        /**
         * @brief     Look in bucket 0 or 1 to find a page of proper size
         * @param[in] The number of pages requested
         * @return    Page ptr to a page of i_pageCount pages
         */
        page_t* pop_bucket_lower(size_t i_pageCount);

        /**
         * @brief     Look in buckets 0..11 to find a page of proper size
         * @param[in] The number of pages requested
         * @return    Page ptr to a page of i_pageCount pages
         */
        page_t* pop_bucket_upper(size_t i_pageCount);

        /**
         * @brief Merge the memory in q
         * @param[in] Queue of memory to merge
         */
        void do_coalesce(Util::Locked::Queue<page_t> q);
};

/** @class PageManager
 *  @brief Manages the allocation of memory pages.
 */
class PageManager
{
    public:

        friend class CpuManager;

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
         * @brief Allocate pages, called from syscall
         * @param[in] n, Requested allocation in pages
         * @return pointer to requested memory
         */
        static void* allocatePage_syscall(size_t n);

        /**
         * @brief Allocate reserved pages, called from syscall
         * @param[in] n, Requested allocation in pages
         * @return pointer to requested memory
         */
        static void* allocateReservedPage_syscall(size_t n);

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
         * @brief Coalesce the memory in the free buckets
         */
        static void coalesce( void );

        /**
         * Retrieve the number of available pages
         * @returns Number of free pages
         */
        static uint64_t availPages();

        /**
         * Retrieve the number of available reserved pages
         * @returns Number of free reserved pages
         */
        static uint64_t availPagesRes();

        /**
         * Retrieve the low page count
         * @returns Low page cound
         */
        static uint64_t lowPageCount();

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
         * Reset statistics used to analyze each IStep
         */
        static void resetIStepStats();

        /**
         * @brief      Copy statistics data from memory to o_stats
         * @param[out] The memory block to copy statistics data into
         */
        static void get_stats(struct kmem_trc_data &o_stats);

        /**
         * @brief  The reserved pages serve three purposes
         *         1. Provide pages for a PTE miss from the kernel. These are
         *            nearly always one or two pages.
         *         2. Provide larger blocks, in case the normal free buckets
         *            become so fragmented that there are no large blocks
         *         3. Throttle allocatePage when the free buckets are empty
         *            -Every iv_reserved page allocate has a delay of at least .5 second.
         *             This allows other threads time to free memory.
         */
        enum
        {
            HEAP_RESERVED          = 256,             //!< number of free pages reserved
            HEAP_RESERVED_MIN_SIZE = 16,              //!< smallest size to re-fill iv_reserved
            HEAP_RESERVED_LOW_MARK = HEAP_RESERVED/4, //!< low mark to re-fill iv_reserved
                                                      //   with any size
        };

        static constexpr size_t KER_ALLOC_WAIT_RESERVED  = 1;  //!> delay before using iv_reserved
        static constexpr size_t USR_ALLOC_WAIT_RESERVED  = 2;  //!> delay before using iv_reserved
        static constexpr size_t USR_ALLOC_CRIT_PERIODIC  = 10; //!> delay for critical periodic
        static constexpr size_t USR_ALLOC_WAIT_TIMEOUT   = 180;//!> time until crit_assert
        static constexpr size_t CASTOUT_NORMAL_DELAY     = 1;  //!> min delay for normal castout
        static constexpr size_t CASTOUT_CRITICAL_DELAY   = 3;  //!> min delay for critical castout

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

        /** see availPagesRes() */
        ALWAYS_INLINE uint64_t _availPagesRes() const
        {
            return iv_reserved.cv_free_pages;
        }

        /** see lowPageCount() */
        ALWAYS_INLINE uint64_t _lowPageCount() const
        {
            return iv_heap.cv_low_page_count;
        }

        /** see isSmallMemEnv() */
        ALWAYS_INLINE bool _isSmallMemEnv() const
        {
            return (cv_pagesTotal < 0xE00 /*14MB*/);
        }

        uint64_t cv_pagesTotal{0};            //!< Total iv_heap pages + iv_reserved pages
        uint64_t cv_allocatePage_usr_wait{0}; //!< num times a usr-mode allocatePage had to wait

        PageManagerCore iv_heap    { true };  //!< Main heap, allow coalesce
        PageManagerCore iv_reserved{ false }; //!< Reserved heap, no coalesce
};

#endif
