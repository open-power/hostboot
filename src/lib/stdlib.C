#include <stdlib.h>
#include <string.h>
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

void* realloc(void* p, size_t s)
{
    if (NULL == p) return malloc(s);
    
    size_t* len = (size_t*)p;
    len--;

    size_t cur_size;
    if ((*len) > 0xff)
    {
        cur_size = ((*len) >> 8) * PageManager::PAGESIZE - 8;
    }
    else
    {
        cur_size = (1 << (*len + 4)) - 8;
    }
    
    if (s <= cur_size)
        return p;

    void* new_p = malloc(s);
    memcpy(new_p, p, cur_size);
    free(p);

    return new_p;
}
