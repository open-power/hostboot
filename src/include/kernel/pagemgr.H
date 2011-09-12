//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/pagemgr.H $
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
#ifndef __KERNEL_PAGEMGR_H
#define __KERNEL_PAGEMGR_H

#include <stdint.h>
#include <limits.h>
#include <util/lockfree/stack.H>
#include <kernel/vmmmgr.H>
#include <builtins.h>
#include <kernel/console.H>

/** @class PageManager
 *  @brief Manages the allocation of memory pages.
 */

class PageManager
{
    public:
	static void init();

	static void* allocatePage(size_t n = 1);
	static void freePage(void*, size_t n = 1);

        /**
         * Query state for available memory
         * @returns percent of pages available
         */
        static uint64_t queryAvail();

	enum 
	{ 
	    MEMLEN = VmmManager::HTABORG,

	    BUCKETS = 16,
	};

    protected:
	PageManager();
	~PageManager() {};

    private:
	void* _allocatePage(size_t);
	void _freePage(void*, size_t);

        /** see queryAvail() */
        ALWAYS_INLINE
        uint64_t _queryAvail() const 
        {
            return (100*iv_pagesAvail)/iv_pagesTotal;
        }

            /** Statistics on number of free pages (for debug) */
        uint64_t iv_pagesAvail;
            /** Total number of pages */
        uint64_t iv_pagesTotal;

	struct page_t
	{
	    page_t* next;
	};
	Util::Lockfree::Stack<page_t> first_page[BUCKETS];

	page_t* pop_bucket(size_t);
	void push_bucket(page_t*, size_t);
};

#endif
