//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/locked/queue.H $
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
#ifndef __UTIL_LOCKED_QUEUE_H
#define __UTIL_LOCKED_QUEUE_H

#include <stddef.h>
#include <util/locked/lock.H>

namespace Util
{
    namespace Locked
    {
	template <typename _T, bool locked = false, typename _S = int>
	class Queue
	{
	    public:
		Queue() : head(NULL), tail(NULL), count(0), lock() {};
		~Queue() {};

		_T* remove();
		void insert(_T*);

		size_t size();

	    protected:
		_T* head;
		_T* tail;

		size_t count;

		_S lock;

		void __lock();
		void __unlock();

	};

	template <typename _T, bool locked, typename _S>
	_T* Queue<_T,locked,_S>::remove()
	{
	    _T* item = NULL;

	    __lock();
	    
	    if (tail != NULL)
	    {
		item = tail;
		if (head == tail)
		    head = tail = NULL;
		else
		    tail = item->prev;
		
		count--;
	    }
	    
	    __unlock();
	    
	    return item;
	}

	template <typename _T, bool locked, typename _S>
	void Queue<_T,locked,_S>::insert(_T* item)
	{
	    __lock();
	    
	    if (head == NULL)
	    {
		item->next = item->prev = NULL;
		head = tail = item;
	    }
	    else
	    {
		item->prev = NULL;
		item->next = head;
		head = head->prev = item;
	    }
	    
	    count++;
	    
	    __unlock();
	}

	template <typename _T, bool locked, typename _S>
	size_t Queue<_T,locked,_S>::size()
	{
	    return count;
	}

	template <typename _T, bool locked, typename _S>
	void Queue<_T,locked,_S>::__lock()
	{
	    Util::Locked::LockHelper<locked,_S>(lock).lock();
	}
	
	template <typename _T, bool locked, typename _S>
	void Queue<_T,locked,_S>::__unlock()
	{
	    Util::Locked::LockHelper<locked,_S>(lock).unlock();
	}


    };
};

#endif
