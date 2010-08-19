#include <kernel/pagemgr.H>
#include <util/singleton.H>
#include <kernel/console.H>

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
    // NOTE: This will need to change once we support loading modules.

    // Determine first page of un-allocated memory.
    extern void* end_load_address;
    uint64_t addr = (uint64_t)&end_load_address;
    if (0 != (addr % PAGESIZE))
	addr = (addr - (addr % PAGESIZE)) + PAGESIZE;
    
    // Determine number of pages available.
    page_t* page = (page_t*)((void*) addr);
    size_t length = (MEMLEN - addr) / PAGESIZE;
    
    // Display.
    printk("Initializing PageManager with %zd pages starting at %llx...",
	   length,
	   (uint64_t)page);
    
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
