#ifndef __UTIL_LOCKED_PQUEUE_H
#define __UTIL_LOCKED_PQUEUE_H

#include <util/locked/queue.H>

namespace Util
{
    namespace Locked
    {
	template <typename _T, typename _K,
		  bool locked = false, typename _S = int>
	class PQueue : public Queue<_T, locked, _S>
	{
	    public:
		void insert(_T*);
		_T* remove_if(_K&);

	    private:
		void bubbleUp(_T*);
	};

	template <typename _T, typename _K, bool locked, typename _S>
	void PQueue<_T,_K,locked,_S>::insert(_T* item)
	{
	    this->__lock();
	    
	    if (this->head == NULL)
	    {
		item->next = item->prev = NULL;
		this->head = this->tail = item;
	    }
	    else
	    {
		item->prev = NULL;
		item->next = this->head;
		this->head = this->head->prev = item;

		bubbleUp(item);
	    }
	    
	    this->__unlock();
	}

	template <typename _T, typename _K, bool locked, typename _S>
	_T* PQueue<_T,_K,locked,_S>::remove_if(_K& key)
	{
	    _T* item = NULL;

	    this->__lock();
	    
	    if ((this->tail != NULL) && (this->tail->key <= key))
	    {
		item = this->tail;
		if (this->head == this->tail)
		    this->head = this->tail = NULL;
		else
		    this->tail = item->prev;
	    }

	    this->__unlock();
	    
	    return item;
	}


	template <typename _T, typename _K, bool locked, typename _S>
	void PQueue<_T,_K,locked,_S>::bubbleUp(_T* item)
	{
	    if (!item->next)
		return;
	    
	    if (item->next->key <= item->key)
		return;

	    if (this->head == item)
		this->head = item->next;
	    if (this->tail == item->next)
		this->tail = item;
	    
	    _T* temp = item->next;

	    if (temp->next)
	    {
		temp->next->prev = item;
		item->next = item->next->next;
	    }
	    else
	    {
		item->next = NULL;
	    }

	    if (item->prev)
	    {
		item->prev->next = temp;
		temp->prev = item->prev;
	    }
	    else
	    {
		temp->prev = NULL;
	    }

	    temp->next = item;
	    item->prev = temp;

	    bubbleUp(item);
	}


    };
};

#endif
