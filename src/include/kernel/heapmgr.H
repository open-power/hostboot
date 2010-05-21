#ifndef __KERNEL_HEAPMGR_H
#define __KERNEL_HEAPMGR_H

#include <stdint.h>
#include <util/lockfree/stack.H>

class HeapManager
{
    public:
	static void init();

	static void* allocate(size_t n);
	static void  free(void *);

	enum
	{
	    BUCKETS = 8,

	    MAX_ALLOC_SIZE = (1 << (BUCKETS + 4)) - 8,
	};

    protected:
	HeapManager() {};
	~HeapManager() {};

    private:
	void* _allocate(size_t);
	void _free(void*);

	struct chunk_t
	{
	    size_t len;
	    chunk_t* next;
	};
	Util::Lockfree::Stack<chunk_t> first_chunk[BUCKETS];

	chunk_t* pop_bucket(size_t);
	void push_bucket(chunk_t*, size_t);

	void newPage();
};

#endif
