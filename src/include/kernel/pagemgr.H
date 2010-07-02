#ifndef __KERNEL_PAGEMGR_H
#define __KERNEL_PAGEMGR_H

#include <stdint.h>
#include <util/lockfree/stack.H>
#include <kernel/vmmmgr.H>

/** @class PageManager
 *  @brief Manages the allocation of memory pages.
 */

class PageManager
{
    public:
	static void init();

	static void* allocatePage(size_t n = 1);
	static void freePage(void*, size_t n = 1);

	enum 
	{ 
	    PAGESIZE = VmmManager::PAGESIZE,
	    MEMLEN = VmmManager::HTABORG,

	    BUCKETS = 16,
	};

    protected:
	PageManager();
	~PageManager() {};

    private:
	void* _allocatePage(size_t);
	void _freePage(void*, size_t);
	
	struct page_t
	{
	    page_t* next;
	};
	Util::Lockfree::Stack<page_t> first_page[BUCKETS];

	page_t* pop_bucket(size_t);
	void push_bucket(page_t*, size_t);
};

#endif
