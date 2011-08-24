//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/heapmgr.H $
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

	    MAX_ALLOC_SIZE = (1 << (BUCKETS + 3)) - 8,
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
