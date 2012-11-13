/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/pagemgr.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
         */
        void freePage( void * i_page, size_t i_pageCount );

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

        enum
        {
            MEMLEN = VmmManager::FIRST_RESERVED_PAGE,
            RESERVED_PAGES = 4,

            LOWMEM_NORM_LIMIT = 16,
            LOWMEM_CRIT_LIMIT = 5,
        };

        static size_t cv_coalesce_count;        //!< running coalesced counter
        static size_t cv_low_page_count;        //!< lowest page count

    protected:

        PageManager();
        ~PageManager() {};

    private:

        void* _allocatePage(size_t,bool);   //!< see allocatePage()
        void _freePage(void*, size_t);       //!< see freePage()
        void _coalesce( void );              //!< see coalesce()
        void _addMemory(size_t, size_t);     //!< see addMemory()

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
        uint64_t iv_lock;               //!< lock for checking low heap

        PageManagerCore iv_heap;        //!< Main heap
        PageManagerCore iv_heapKernel;  //!< kernel heap for out-of-mem
};

#endif
