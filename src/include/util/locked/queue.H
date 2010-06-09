#ifndef __UTIL_LOCKED_QUEUE_H
#define __UTIL_LOCKED_QUEUE_H

namespace Util
{
    namespace Locked
    {
	template <typename _T, bool locked = false, typename _S = int>
	class Queue
	{
	    public:
		Queue() : head(NULL), tail(NULL), lock() {};
		~Queue() {};

		_T* remove();
		void insert(_T*);

	    private:
		_T* head;
		_T* tail;

		_S lock;

	};

	template <typename _T, bool locked, typename _S>
	_T* Queue<_T,locked,_S>::remove()
	{
	    _T* item = NULL;

	    if (locked)
		lock.lock();
	    
	    if (tail != NULL)
	    {
		item = tail;
		if (head == tail)
		    head = tail = NULL;
		else
		    tail = item->prev;
	    }

	    if (locked)
		lock.unlock();

	    return item;
	}

	template <typename _T, bool locked, typename _S>
	void Queue<_T,locked,_S>::insert(_T* item)
	{
	    if (locked)
		lock.lock();
	    
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

	    if (locked)
		lock.unlock();
	}
    };
};

#endif
