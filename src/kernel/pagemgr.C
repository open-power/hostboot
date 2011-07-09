#include <limits.h>
#include <kernel/pagemgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <sys/vfs.h>
#include <arch/ppc.H>

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

PageManager::PageManager()
{
    // Determine first page of un-allocated memory.
    uint64_t addr = (uint64_t) VFS_LAST_ADDRESS;
    if (0 != (addr % PAGESIZE))
	addr = (addr - (addr % PAGESIZE)) + PAGESIZE;
    
    // Determine number of pages available.
    page_t* page = (page_t*)((void*) addr);
    size_t length = (MEMLEN - addr) / PAGESIZE;
    
    // Display.
    printk("Initializing PageManager with %zd pages starting at %lx...",
	   length,
	   (uint64_t)page);
    
    // Populate L3 cache lines.
    uint64_t* cache_line = (uint64_t*) addr;
    uint64_t* end_cache_line = (uint64_t*) VmmManager::FULL_MEM_SIZE;
    while (cache_line != end_cache_line)
    {
        dcbz(cache_line);
        cache_line++;
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

    printk("done\n");
}

void* PageManager::_allocatePage(size_t n)
{
    size_t which_bucket = 0;
    while (n > (size_t)(1 << which_bucket)) which_bucket++;
    
    int retries = 0;
    page_t* page = (page_t*)NULL;
    while ((page == NULL) && (retries < 3))
    {
	page = pop_bucket(which_bucket);
	retries++;
    }

    if (NULL == page)
    {
	// TODO: Add abort instead.
	printk("Insufficient memory for allocation of size %zd!\n", n);
	while(1);
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    if ((NULL == p) || (0 == n)) return;

    size_t which_bucket = 0;
    while (n > (size_t)(1 << which_bucket)) which_bucket++;

    push_bucket((page_t*)p, which_bucket);
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
