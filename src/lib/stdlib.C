#include <stdlib.h>
#include <kernel/heapmgr.H>
#include <kernel/pagemgr.H>

void* malloc(size_t s)
{
    if (s > HeapManager::MAX_ALLOC_SIZE)
    {
	size_t pages = (s+8) / PageManager::PAGESIZE;
	void* v = PageManager::allocatePage(pages);
	size_t* len = (size_t*)v;
	*len = pages << 8;
	len++;
	return len;
    }
    else
	return HeapManager::allocate(s);
}

void free(void* p)
{
    if (NULL == p) return;

    size_t* len = (size_t*)p;
    len--;

    if ((*len) > 0xff)
    {
	PageManager::freePage(len, (*len) >> 8);
    }
    else
    {
	HeapManager::free(p);
    }
}
