//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/pagemgr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <limits.h>
#include <kernel/pagemgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <util/locked/pqueue.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>

size_t PageManager::cv_coalesce_count = 0;
size_t PageManager::cv_low_page_count = -1;

void PageManager::init()
{
    Singleton<PageManager>::instance();
}

void* PageManager::allocatePage(size_t n)
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    return pmgr._allocatePage(n);
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

PageManager::PageManager() : iv_pagesAvail(0), iv_pagesTotal(0)
{
    // Determine first page of un-allocated memory
    // and number of pages available.
    uint64_t addr = firstPageAddr();
    size_t length = (MEMLEN - addr) / PAGESIZE;
    page_t* page = reinterpret_cast<page_t *>(addr);

    iv_pagesTotal = length;
    // Update statistics.
    __sync_add_and_fetch(&iv_pagesAvail, length);
    cv_low_page_count = iv_pagesAvail;

    // Display.
    printk("Initializing PageManager with %zd pages starting at %lx...",
	   length,
	   (uint64_t)page);

    // Populate L3 cache lines.
    uint64_t* cache_line = reinterpret_cast<uint64_t*>(addr);
    uint64_t* end_cache_line = (uint64_t*) VmmManager::FULL_MEM_SIZE;
    while (cache_line != end_cache_line)
    {
        dcbz(cache_line);
        cache_line += getCacheLineWords();
    }

    // Allocate pages to buckets.
    size_t page_length = BUCKETS-1;
    while(length > 0)
    {
	while (length < (size_t)(1 << page_length))
	    page_length--;

	first_page[page_length].push(page);
	page = (page_t*)((uint64_t)page + (1 << page_length)*PAGESIZE);
	length -= (1 << page_length);
    }

    // @TODO: Venice: Clear 3-8MB region and add to free memory pool.
    //                Can't do this now due to fake-PNOR driver.

    printk("done\n");
}

void* PageManager::_allocatePage(size_t n)
{
    size_t which_bucket = 0;
    while (n > (size_t)(1 << which_bucket)) which_bucket++;

    int retries = 0;
    page_t* page = (page_t*)NULL;
    while ((page == NULL) && (retries < 6))
    {
	page = pop_bucket(which_bucket);
	retries++;
    }

    if (NULL == page)
    {
	// TODO: Add abort instead?
        register task_t* t;
        asm volatile("mr %0, 13" : "=r"(t));
	printk("Insufficient memory for alloc of size %zd page on tid=%d!\n", n, t->tid);
        printk("Pages available=%ld\n",iv_pagesAvail);
	while(1);
    }

    // Update statistics.
    __sync_sub_and_fetch(&iv_pagesAvail, n);
    if(iv_pagesAvail < cv_low_page_count)
    {
        cv_low_page_count = iv_pagesAvail;
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    if ((NULL == p) || (0 == n)) return;

    size_t which_bucket = 0;
    while (n > (size_t)(1 << which_bucket)) which_bucket++;

    push_bucket((page_t*)p, which_bucket);

    // Update statistics.
    __sync_add_and_fetch(&iv_pagesAvail, n);

    return;
}

PageManager::page_t* PageManager::pop_bucket(size_t n)
{
    if (n >= BUCKETS) return NULL;

    page_t* p = first_page[n].pop();

    if (NULL == p)
    {
	// Couldn't allocate from the correct size bucket, so split up an
	// item from the next sized bucket.
	p = pop_bucket(n+1);
	if (NULL != p)
	{
	    push_bucket((page_t*) (((uint64_t)p) + (PAGESIZE * (1 << n))),
			n);
	}
    }
    return p;
}

void PageManager::push_bucket(page_t* p, size_t n)
{
    if (n >= BUCKETS) return;
    first_page[n].push(p);
}

void PageManager::coalesce( void )
{
    Singleton<PageManager>::instance()._coalesce();
}


// Coalsesce adjacent free memory blocks
void PageManager::_coalesce( void )
{
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
        while(NULL != (p = first_page[bucket].pop()))
        {
            p->key = p;
            pq.insert(p);
        }

        while(NULL != (p = pq.remove()))
        {
            // p needs to be the even buddy to prevent merging of wrong block.
            // To determine this, get the index of the block as if the whole
            // page memory space were blocks of this size.
            uint64_t p_idx = (reinterpret_cast<uint64_t>(p) - firstPageAddr())/
                             ((1 << bucket)*PAGESIZE);
            if(0 != (p_idx % 2))  // odd index
            {
                first_page[bucket].push(p);  // can't merge
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
                    push_bucket(p,bucket+1);
                    ++cv_coalesce_count;
                }
                else
                {
                    // Can't merge p
                    first_page[bucket].push(p);

                    if(p_next) // This should be null - if then overlaping mem
                    {
                        first_page[bucket].push(p_next);
                        printk("pagemgr::coalesce Expected %p, got %p\n",
                               p_seek, p_next);
                    }
                }
            }
        }
    }
    printkd("PAGEMGR coalesced total %ld\n", cv_coalesce_count);
    printkd("PAGEMGR low page count %ld\n",cv_low_page_count);
}


