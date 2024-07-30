/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/pagemgr.C $                                        */
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
 * @file pagemgr.C
 *
 * @brief Implementations of PageManagerCore class and functions;
 *        PageManagerCore manipulates memory pages.
 */

#include <limits.h>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <arch/magic.H>
#include <util/locked/pqueue.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/vmmmgr.H>
#include <sys/task.h>
#include <kernel/misc.H>
#include <sys/syscall.h>
#include <assert.h>
#include <kernel/memstate.H>
#include <kernel/bltohbdatamgr.H>
#include <kernel/misc.H>
#include <usr/debugpointers.H>
#include <kernel/cpumgr.H>
#include <usr/vmmconst.h>
#include <kernel/spte.H>
#include <kernel/timemgr.H>
#include <kernel/simpletrace.H>

extern int g_istep;   // used in STRC_KALLOC
extern int g_substep; // used in STRC_KALLOC

void PageManager::get_stats(struct kmem_trc_data &o_stats)
{
    PageManager& pmgr = Singleton<PageManager>::instance();

    o_stats.cv_pagesTotal          = pmgr.cv_pagesTotal;
    o_stats.cv_pagesAvail_heap     = pmgr.iv_heap.cv_free_pages;
    o_stats.cv_low_page_count_heap = pmgr.iv_heap.cv_low_page_count;
    o_stats.cv_coalesce_state      = pmgr.iv_heap.cv_coalesce_state;
    o_stats.cv_coalesce_attempts   = pmgr.iv_heap.cv_coalesce_attempts;
    o_stats.cv_coalesce_count      = pmgr.iv_heap.cv_coalesce_count;
    for (int i=0; i<PageManagerCore::BUCKETS; i++)
    {
        o_stats.cv_free_bucket_count_heap[i] =
                    static_cast<uint32_t>(pmgr.iv_heap.cv_free_bucket_count[i]);
    }

    o_stats.cv_allocatePage_coalesce_wait = pmgr.cv_allocatePage_coalesce_wait;

    o_stats.cv_pagesAvail_res     = pmgr.iv_reserved.cv_free_pages;
    o_stats.cv_low_page_count_res = pmgr.iv_reserved.cv_low_page_count;
    for (int i=0; i<8; i++)
    {
        o_stats.cv_free_bucket_count_res[i] =
                static_cast<uint32_t>(pmgr.iv_reserved.cv_free_bucket_count[i]);
    }
}

void PageManagerCore::addMemory( size_t i_addr, size_t i_pageCount )
{
    size_t length = i_pageCount;
    size_t align  = ALIGN_PAGE(i_addr);
    page_t* page  = reinterpret_cast<page_t *>(align);

    KTRC1("PageManagerCore::addMemory: i_addr:%lx i_pageCount:%ld\n",
            i_addr, i_pageCount);

    // Allocate pages to buckets.
    size_t page_length = BUCKETS-1;
    while(length > 0)
    {
        while (length < (size_t)(1 << page_length))
        {
            page_length--;
        }

        __sync_add_and_fetch(&cv_free_bucket_count[page_length],1);

        iv_heap[page_length].push(page);
        page = (page_t*)((uint64_t)page + (1 << page_length)*PAGESIZE);
        length -= (1 << page_length);
    }

    // Only check range if coalesce is allowed
    if (iv_supports_coalesce)
    {
        // Update set of registered heap memory ranges to support heap coalescing.
        // It is a critical error for the last range to already be registered when
        // this API is invoked.
        kassert(!iv_ranges.back().first);
        for(auto& range : iv_ranges)
        {
            // Range value of 0 indicates a free range to use, since Hostboot cannot
            // ever start the heap at an address of 0.
            if(!range.first)
            {
                range.first=align;
                range.second=i_pageCount*PAGE_SIZE;
                break;
            }

            // Can't ever start a range at/below that of an existing range.
            if (align <= range.first)
            {
                KTRC0("page <= range.first 0x%lx <= 0x%lx\n", align, (size_t)range.first);
            }
            kassert(align > range.first);
        }
    }
    __sync_add_and_fetch(&cv_free_pages, i_pageCount);
    return;
}



PageManagerCore::page_t * PageManagerCore::allocatePage( size_t i_pageCount )
{
    page_t *page{nullptr};
    size_t which_bucket = ((sizeof(size_t)*8 - 1) -
                                __builtin_clzl(i_pageCount));
    size_t bucket_size = ((size_t)1) << which_bucket;

    if (bucket_size != i_pageCount)
    {
        ++which_bucket;
        bucket_size <<= 1;
    }

    if (which_bucket < 2)
    {
        // requests here are for bucket 0 or 1, so do it lockless,
        // because it wont interfere with dividing larger pages from higher buckets
        page = iv_heap[which_bucket].pop();
        if (page)
        {
            __sync_add_and_fetch(&cv_alloc_sizes[which_bucket], 1);
            __sync_sub_and_fetch(&cv_free_bucket_count[which_bucket], 1);
            __sync_sub_and_fetch(&cv_free_pages, bucket_size);
            if (cv_free_pages < cv_low_page_count)
            {
                cv_low_page_count = cv_free_pages;
            }
            return page;
        }
    }

    // Either no page exists for i_pageCount in bucket 0 or 1,
    // or i_pageCount is larger than 2,
    // Go search the buckets under a lock
    // Use a lock to prevent fragmentation, caused when multiple threads
    //  simultaneously pull memory from the upper buckets and split it
    //  into smaller pieces.

    iv_spinlock.lock();
    page = pop_bucket(which_bucket);
    if (page)
    {
        __sync_add_and_fetch(&cv_alloc_sizes[which_bucket], 1);
        __sync_sub_and_fetch(&cv_free_pages, bucket_size);
        if (cv_free_pages < cv_low_page_count)
        {
            cv_low_page_count = cv_free_pages;
        }
        // Buckets are 2^k in size so if i_pageCount is not 2^k we have some
        // extra pages allocated.  ie. the non-2^k portion of i_pageCount.
        // Return that portion by freeing.
        if (bucket_size != i_pageCount)
        {
            freePage(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(page) +
                                            (i_pageCount*PAGESIZE)),
                     bucket_size - i_pageCount,
                     true);
        }
    }
    iv_spinlock.unlock();

    return page;
}

void PageManagerCore::freePage(void*  i_page,
                               size_t i_pageCount,
                               bool   i_overAllocated)
{
    if ((NULL == i_page) || (0 == i_pageCount)) return;

    size_t which_bucket = ((sizeof(size_t)*8 - 1) - __builtin_clzl(i_pageCount));
    size_t bucket_size  = ((size_t)1) << which_bucket;

    push_bucket(
           (page_t*)(reinterpret_cast<uintptr_t>(i_page)
         + (i_overAllocated ? ((i_pageCount-bucket_size)*PAGESIZE) : 0)),
         which_bucket);

    __sync_add_and_fetch(&cv_free_pages, bucket_size);

    // Buckets are 2^k in size so if i_pageCount is not 2^k we have some
    // spare pages to free.  ie. the non-2^k portion of i_pageCount.
    if (bucket_size != i_pageCount)
    {
        freePage(
            reinterpret_cast<void*>(
                  reinterpret_cast<uintptr_t>(i_page)
                + (i_overAllocated ? 0 : (bucket_size*PAGESIZE))),
            i_pageCount - bucket_size, i_overAllocated);
    }
    return;
}

void PageManager::init()
{
    Singleton<PageManager>::instance();

    STRC_KMEM_INIT   (KMEMSTATS_SIZE, BASE_FORMAT);
    STRC_KALLOC_INIT (KALLOC_SIZE,    BASE_FORMAT);
}

void* PageManager::allocatePage(size_t n, bool userspace, bool kAllowOom)
{
    void* page = NULL;

    // In non-kernel mode, make a system-call to allocate in kernel-mode.
    if (!KernelMisc::in_kernel_mode())
    {
        page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                         reinterpret_cast<void*>(n));
        if (NULL == page)
        {
            // The alloc pages syscall failed, so loop and retry the syscall
            //  until success or until timeoutSecs.
            // At firstSecs,          run forceMemoryPeriodic,     do not run again
            // At reserveSecs,        get memory from iv_reserved, do not run again
            // At every periodicSecs, run forceMemoryPeriodic

            // forceMemoryPeriodic
            //   -does flushPageTable, castOutPages, evict, and PageMgr/HeapMgr coalesce

            const uint64_t firstSecs     = 5;   // secs to wait until first forceMemoryPeriodic
            const uint64_t reserveSecs   = 10;  // secs to wait until using iv_reserved
            const uint64_t periodicSecs  = 30;  // interval to invoke a forceMemoryPeriodic
            const uint64_t timeoutSecs   = 180; // total seconds to retry

            uint64_t curTicks      = 0;   // ticks taken at every loop iteration
            uint64_t firstTicks    = 0;   // tick count when the timeout hits
            uint64_t reserveTicks  = 0;   // tick count when the iv_reserved is used
            uint64_t periodicTicks = 0;   // tick count when forceMemoryPeriodic is invoked
            uint64_t timeoutTicks  = 0;   // tick count when the timeout hits

            PageManager      &l_pmgr = Singleton<PageManager>::instance();
            kmem_trc_data_t   l_kmem_data{0};
            kalloc_trc_data_t l_kalloc_data{0};
            l_kalloc_data.requested_pages = n;

            curTicks      = getTB();
            timeoutTicks  = curTicks + TimeManager::convertSecToTicks(timeoutSecs,0);
            firstTicks    = curTicks + TimeManager::convertSecToTicks(firstSecs,0);
            reserveTicks  = curTicks + TimeManager::convertSecToTicks(reserveSecs,0);
            periodicTicks = curTicks + TimeManager::convertSecToTicks(periodicSecs,0);

            while (NULL == page)
            {
                // Didn't successfully allocate, so yield in hopes that memory
                // will eventually free up (ex. VMM flushes).
                task_yield();

                curTicks = getTB();

                // TIMEOUT
                // Check the maximum time allowed for retry
                if (curTicks > timeoutTicks)
                {
                    KTRC0("KMEM_STATS_ALLOC_PAGE_OOM_USR_TIMEOUT_ASSERT size: %ld tid:%d\n",
                            n, task_gettid());
                    l_kmem_data.istep   = g_istep;
                    l_kmem_data.substep = g_substep;
                    STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_USR_TIMEOUT_ASSERT, l_kmem_data);
                    MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
                    KernelMisc::printkBacktrace(nullptr);
                    crit_assert(0);
                }
                // FIRST
                // Run forceMemoryPeriodic early in the loop
                if (curTicks > firstTicks)
                {
                    KTRC1("K_ALLOC_USR_FIRST size:%ld tid:%d\n", n, task_gettid());
                    __sync_add_and_fetch(&l_pmgr.cv_allocatePage_coalesce_wait, 1);
                    l_kalloc_data.istep   = g_istep;
                    l_kalloc_data.substep = g_substep;
                    STRC_KALLOC(STRC_L0, K_ALLOC_USR_FIRST, l_kalloc_data);
                    CpuManager::forceMemoryPeriodic();
                    // ensure this FIRST section does not run again in the loop
                    firstTicks += TimeManager::convertSecToTicks(timeoutSecs,0);
                }
                // RESERVE
                // Use a reserved page if available
                if (curTicks > reserveTicks)
                {
                    page = l_pmgr.iv_reserved.allocatePage(n);
                    if (page)
                    {
                        KTRC0("K_ALLOC_USR_GET_RES size: %ld tid:%d\n", n, task_gettid());
                        l_kalloc_data.istep   = g_istep;
                        l_kalloc_data.substep = g_substep;
                        STRC_KALLOC(STRC_L0, K_ALLOC_USR_GET_RES, l_kalloc_data);
                        return page;
                    }
                    KTRC0( "KMEM_STATS_ALLOC_PAGE_OOM_USR_GET_RES_FAIL size:%ld tid:%d\n",
                            n, task_gettid());
                    l_kmem_data.istep           = g_istep;
                    l_kmem_data.substep         = g_substep;
                    l_kmem_data.requested_pages = n;
                    STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_USR_GET_RES_FAIL, l_kmem_data);
                    // ensure this RESERVE section does not run again in the loop
                    reserveTicks += TimeManager::convertSecToTicks(timeoutSecs,0);
                }
                // PERIODIC
                // runs forceMemoryPeriodic
                if (curTicks > periodicTicks)
                {
                    l_kalloc_data.istep   = g_istep;
                    l_kalloc_data.substep = g_substep;
                    STRC_KALLOC(STRC_L0, K_ALLOC_USR_PERIODIC, l_kalloc_data);
                    CpuManager::forceMemoryPeriodic();
                    periodicTicks += TimeManager::convertSecToTicks(periodicSecs,0);
                }

                // try to get memory from iv_heap again
                page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                                 reinterpret_cast<void*>(n));
            }
        }
    }
    else
    {
        // In kernel mode.  Do a normal call to the PageManager.
        PageManager& l_pmgr = Singleton<PageManager>::instance();
        page = l_pmgr._allocatePage(n, userspace, kAllowOom);
    }

    return page;
}

void PageManager::freePage(void* p, size_t n)
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    return pmgr._freePage(p, n);
}

uint64_t PageManager::queryAvail()
{
    return Singleton<PageManager>::instance()._queryAvail();
}

uint64_t PageManager::availPages()
{
    return Singleton<PageManager>::instance()._availPages();
}

bool PageManager::isSmallMemEnv()
{
    return Singleton<PageManager>::instance()._isSmallMemEnv();
}

void PageManager::addDebugPointers()
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    pmgr._addDebugPointers();
}

void PageManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERINSTANCE,
                             this,
                             sizeof(PageManager));
}

PageManager::PageManager()
{
    this->_initialize();
}

void PageManager::_initialize()
{
    KTRC0("Hostboot base image ends at 0x%lX...\n", firstPageAddr());

    uint64_t totalPages = 0;
    // Extend memory footprint
    // There is a preserved area after the base image and boot loader to HB
    // communication area. The page table must be 256KB aligned, so it is
    // likely to not be flush against the preserved area end.
    // Example:
    //      [HBB max size][BlToHBData][8 byte aligned]
    //      [128 byte aligned Preserved-area][256K aligned Page Table]
    uint64_t l_endPreservedArea = VmmManager::endPreservedOffset();
    uint64_t l_endInitCache = VmmManager::SINGLE_CACHE_SIZE_BYTES;
    uint64_t l_pageTableOffset = VmmManager::pageTableOffset();
    uint64_t l_endPageTable = l_pageTableOffset + VmmManager::PTSIZE;

    KTRC0("PageManager end of preserved area at 0X%lX\n", l_endPreservedArea);
    KTRC0("PageManager page table offset at 0X%lX\n", l_pageTableOffset);
#ifdef CONFIG_AGGRESSIVE_LRU
    KTRC0("CastOutPages AGGRESSIVE LRU\n");
#else
    KTRC0("CastOutPages NORMAL LRU\n");
#endif

    // Populate half the cache after the preserved area
    KernelMisc::populate_cache_lines(
                                reinterpret_cast<uint64_t*>(l_endPreservedArea),
                                reinterpret_cast<uint64_t*>(l_endInitCache));

    // Allocate heap memory between end of preserved area and start of page
    // table, if necessary
    uint64_t pages = 0;
    if ( (l_pageTableOffset - l_endPreservedArea) > 0 )
    {
        pages = (l_pageTableOffset - l_endPreservedArea) / PAGESIZE;
        iv_heap.addMemory(l_endPreservedArea, pages);
        totalPages += pages;
    }
    // After the Page table
    pages = (l_endInitCache - l_endPageTable) / PAGESIZE;
    iv_heap.addMemory(l_endPageTable, pages);
    totalPages += pages;

#ifndef CONFIG_VPO_COMPILE // In VPO, the size of the cache is 4MB; trying to
                           // execute this code (that attempts to zero out 0
                           // amount of memory) causes crashes
    KernelMisc::populate_cache_lines(
        reinterpret_cast<uint64_t*>(l_endInitCache),
        reinterpret_cast<uint64_t*>(g_BlToHbDataManager.getHbCacheSizeBytes()));

    // Reserve enough memory to fit the OCC BL at 4MB into the cache. For more
    // details, see src/usr/isteps/pm/occCheckstop.C::loadOCCImageDuringIpl()
    l_endInitCache += VMM_OCC_BOOTLOADER_SIZE; // Skip enough to fit OCC BL
    pages = (g_BlToHbDataManager.getHbCacheSizeBytes() - l_endInitCache) /
            PAGESIZE;
    iv_heap.addMemory(l_endInitCache, pages);
    totalPages += pages;
#endif

    // Statistics
    cv_pagesTotal             = totalPages;
    iv_heap.cv_low_page_count = iv_heap.cv_free_pages;

    // allocate pages to iv_reserved
    PageManagerCore::page_t *page = iv_heap.allocatePage(HEAP_RESERVED);
    iv_reserved.freePage(page, HEAP_RESERVED); // add pages into iv_reserved
    iv_reserved.cv_low_page_count = iv_reserved.cv_free_pages;

    KTRC0("Total Pages:       %ld\n"
          "iv_heap Pages:     %ld\n"
          "iv_reserved Pages: %ld\n",
            cv_pagesTotal,
            iv_heap.cv_free_pages,
            iv_reserved.cv_free_pages);

    KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                     g_BlToHbDataManager.getHbCacheSizeMb());
}

void* PageManager::_allocatePage(size_t n, bool userspace, bool allowOom)
{
    PageManagerCore::page_t* page = iv_heap.allocatePage(n);

    if (page)
    {
        return page;
    }

    if (!userspace)
    {
        // the allocation request came from kernel-space and normal allocation failed,
        // so pull a page off the reserve heap
        register task_t* t;
        asm volatile("mr %0, 13" : "=r"(t));

        page = iv_reserved.allocatePage(n);
        if (page)
        {
            KTRC0("K_ALLOC_KERNEL_GET_RES size: %ld tid:%d\n", n, t->tid);
            kalloc_trc_data_t l_kalloc_data{0};
            l_kalloc_data.requested_pages = n;
            l_kalloc_data.istep           = g_istep;
            l_kalloc_data.substep         = g_substep;
            STRC_KALLOC(STRC_L0, K_ALLOC_KERNEL_GET_RES, l_kalloc_data);
            return page;
        }

        // still not successful, we're out of memory.  Assert as long as the
        // caller doesn't want to allow OOM (_pteMiss uses this to avoid deadlocks).
        kmem_trc_data_t l_kmem_data{0};
        l_kmem_data.istep           = g_istep;
        l_kmem_data.substep         = g_substep;
        l_kmem_data.requested_pages = n;
        STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_GET_RES_FAIL, l_kmem_data);
        KTRC0("KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_GET_RES_FAIL size: %ld tid:%d\n", n, t->tid);

        if (!allowOom)
        {
            KTRC0("Insufficient memory for alloc %zd pages on tid=%d!\n", n, t->tid);
            KTRC0("Pages available=%ld\n", iv_heap.cv_free_pages);
            KTRC0("KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_KASSERT size: %ld tid:%d\n", n, t->tid);
            l_kmem_data.istep           = g_istep;
            l_kmem_data.substep         = g_substep;
            l_kmem_data.requested_pages = n;
            STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_KERNEL_KASSERT, l_kmem_data);
            kassert(false);
        }
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    if (iv_reserved.cv_free_pages < HEAP_RESERVED)
    {
        // iv_reserved needs pages, so try to add p
        if (n >= HEAP_RESERVED_MIN_SIZE)
        {
            // if this is the larger size, always put it into iv_reserved
            iv_reserved.freePage(p,n);
            KTRC1("PageManager::_freePage: RES ADD MULTI %ld res_free:%ld\n",
                    n, iv_reserved.cv_free_pages);
            return;
        }
        if (iv_reserved.cv_free_pages < HEAP_RESERVED_LOW_MARK)
        {
            // if iv_reserved is very low on pages, add any sized p
            iv_reserved.freePage(p,n);
            KTRC1("PageManager::_freePage: RES ADD %ld res_free:%ld\n",
                    n, iv_reserved.cv_free_pages);
            return;
        }
    }

    iv_heap.freePage(p,n);

    return;
}

PageManagerCore::page_t* PageManagerCore::pop_bucket(size_t i_n)
{
    if (i_n >= BUCKETS) return NULL;

    page_t* p = iv_heap[i_n].pop();

    if (NULL == p)
    {
        // Couldn't allocate from the correct size bucket, so split up an
        // item from the next sized bucket.
        p = pop_bucket(i_n+1);
        if (NULL != p)
        {
            push_bucket((page_t*) (((uint64_t)p) + (PAGESIZE * (1 << i_n))), i_n);
        }
    }
    else
    {
        __sync_sub_and_fetch(&cv_free_bucket_count[i_n], 1);
    }
    return p;
}

void PageManagerCore::push_bucket(page_t* i_p, size_t i_n)
{
    if (i_n >= BUCKETS) return;
    iv_heap[i_n].push(i_p);
    __sync_add_and_fetch(&cv_free_bucket_count[i_n],1);
}

void PageManager::coalesce( void )
{
    Singleton<PageManager>::instance()._coalesce();
}

void PageManager::_coalesce( void )
{
    iv_heap.coalesce();
}

// Coalsesce adjacent free memory blocks
void PageManagerCore::coalesce( void )
{
    if (!iv_supports_coalesce)
    {
        return;
    }
    if (cv_free_pages <= 1) {return;}

    int l_running = __sync_val_compare_and_swap(&cv_coalesce_state,0,1);
    if (l_running)
    {
        // a coalesce is already running,
        //  so rather than queueing up another thread to run another coalesce
        //  after the one in progress, kick this thread out
        KTRC1("coalesce: SKIP %d\n", task_gettid());
        return;
    }
    iv_spinlock.lock(); // mutex with allocatePage

    __sync_add_and_fetch(&cv_coalesce_attempts, 1);

    // Look at all the "free buckets" and find blocks to merge
    // Since this is binary, all merges will be from the same free bucket
    // Each bucket is a stack of non-allocated memory blocks of the same size
    // Once two blocks are merged they become a single block twice the size.
    // The source blocks must be removed from the current bucket (stack) and
    // the new block needs to be pushed onto the next biggest stack.
    for(size_t bucket = 0; bucket < (BUCKETS-1); ++bucket)
    {
        // Move the this stack bucket into a priority queue
        // sorted by address, highest to lowest
        Util::Locked::PQueue<page_t,page_t*> pq;
        page_t * p = NULL;
        while(NULL != (p = iv_heap[bucket].pop()))
        {
            p->key = p;
            pq.insert(p);

            __sync_sub_and_fetch(&cv_free_bucket_count[bucket],1);
        }

        while(NULL != (p = pq.remove()))
        {
            // p needs to be the even buddy to prevent merging of wrong blocks.
            // To determine this, get the index of the block as if the whole
            // page memory space were blocks of this size.  Note: have to
            // take into account the page manager "hole" in the middle of the
            // initial memory allocation.  Also have to ignore the OCC
            // bootloader page at the start of the third memory range (which
            // accounts for the rest of the initial cache), and the SPTE entries
            // at the start of the 4th memory range (which accounts for the rest
            // of the Hostboot memory footprint).
            uint64_t p_idx = 0;
            const auto addr = reinterpret_cast<uint64_t>(p);
            bool found=false;
            for(const auto& range : iv_ranges)
            {
                if(   (addr >= range.first)
                   && (addr < (range.first + range.second)) )
                {
                    p_idx = (addr - range.first) / ((1 << bucket)*PAGESIZE);
                    found=true;
                    break;
                }
            }
            // Critical error if we didn't map into a known/registered address
            // range.
            kassert(found);

            if(0 != (p_idx % 2))  // odd index
            {
                iv_heap[bucket].push(p);
                __sync_add_and_fetch(&cv_free_bucket_count[bucket],1);
            }
            else // it's even
            {
                // If p can be merged then the next block in pq will be the
                // match.  The address of p also can't be greater than what's
                // in pq or something is really messed up, therefore if
                // pq.remove_if() returns something then it's a match.
                page_t * p_seek = (page_t*)((uint64_t)p +
                                            (1 << bucket)*PAGESIZE);
                page_t * p_next = pq.remove_if(p_seek);
                if(p_next == p_seek)
                {
                    // new block is twice the size and goes into the next
                    // bucket size
                    iv_heap[bucket+1].push(p);
                    __sync_add_and_fetch(&cv_free_bucket_count[bucket+1],1);
                    __sync_add_and_fetch(&cv_coalesce_count, 1);
                }
                else
                {
                    // Can't merge p
                    iv_heap[bucket].push(p);
                    __sync_add_and_fetch(&cv_free_bucket_count[bucket],1);

                    if(p_next) // This should be null - if then overlaping mem
                    {
                        iv_heap[bucket].push(p_next);
                        __sync_add_and_fetch(&cv_free_bucket_count[bucket],1);
                        KTRC0("pagemgr::coalesce Expected %p, got %p\n",
                               p_seek, p_next);
                    }
                }
            }
        }
    }
    iv_spinlock.unlock();
    __sync_sub_and_fetch(&cv_coalesce_state, 1);
}

void PageManager::addMemory(size_t i_addr, size_t i_pageCount)
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    return pmgr._addMemory(i_addr, i_pageCount);
}

// add memory to the heap
void PageManager::_addMemory(size_t i_addr, size_t i_pageCount)
{
    iv_heap.addMemory(i_addr,i_pageCount);

    // Update statistics.
    __sync_add_and_fetch(&cv_pagesTotal, i_pageCount);

    return;
}

