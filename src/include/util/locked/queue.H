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
