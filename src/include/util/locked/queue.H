/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/locked/queue.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
