#include <kernel/heapmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>

void* HeapManager::allocate(size_t n)
{
    HeapManager& hmgr = Singleton<HeapManager>::instance();
    return hmgr._allocate(n);
}

void HeapManager::free(void* p)
{
    HeapManager& hmgr = Singleton<HeapManager>::instance();
    return hmgr._free(p);
}

void* HeapManager::_allocate(size_t n)
{
    int which_bucket = 0;
    while (n > ((1 << (which_bucket + 4)) - 8)) which_bucket++;

    chunk_t* chunk = (chunk_t*)NULL;
    chunk = pop_bucket(which_bucket);
    if (NULL == chunk)
    {
	newPage();
	return _allocate(n);
    }
    else
    {
	return &chunk->next;
    }
}

void HeapManager::_free(void* p)
{
    if (NULL == p) return;

    chunk_t* chunk = (chunk_t*)((size_t*)p)-1;
    push_bucket(chunk, chunk->len);
}

HeapManager::chunk_t* HeapManager::pop_bucket(size_t n)
{
    if (n >= BUCKETS) return NULL;

    chunk_t* c = first_chunk[n].pop();

    if (NULL == c)
    {
	// Couldn't allocate from the correct size bucket, so split up an
	// item from the next sized bucket.
	c = pop_bucket(n+1);
	if (NULL != c)
	{
	    chunk_t* c1 = (chunk_t*)(((uint8_t*)c) + (1 << (n + 4)));
	    c->len = n;
	    c1->len = n;
	    push_bucket(c1, n);
	}
    }

    return c;
}

void HeapManager::push_bucket(chunk_t* c, size_t n)
{
    if (n >= BUCKETS) return;
    first_chunk[n].push(c);
}

void HeapManager::newPage()
{
    void* page = PageManager::allocatePage();
    chunk_t * c = (chunk_t*)page;
    for (int i = 0; i < (PageManager::PAGESIZE / (1 << (BUCKETS + 3))); i++)
    {
	c->len = BUCKETS-1;
	push_bucket(c, BUCKETS-1);
	c = (chunk_t*)(((uint8_t*)c) + (1 << (BUCKETS + 3)));
    }
}
