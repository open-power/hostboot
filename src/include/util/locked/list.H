#ifndef __UTIL_LOCKED_LIST_H
#define __UTIL_LOCKED_LIST_H

#include <stddef.h>
#include <util/locked/lock.H>

namespace Util
{
    namespace Locked
    {
	template <typename _T, typename _K,
		  bool locked = false, typename _S = int>
	class List 
	{
	    public:
	    	List() : head(NULL), tail(NULL), lock() {};
		~List() {};

		_T* remove();
		void insert(_T*);

		void erase(_T* node);
		void erase(_K& key);

		_T* find(_K& key);

	    protected:
		_T* head;
		_T* tail;

		_S lock;

		void __lock();
		void __unlock();
	};

	template <typename _T, typename _K, bool locked, typename _S>
	_T* List<_T,_K,locked,_S>::remove()
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
	    }

	    __unlock();
	    
	    return item;
	}

	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::insert(_T* item)
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
	    
	    __unlock();
	}

	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::__lock()
	{
	    Util::Locked::LockHelper<locked,_S>(lock).lock();
	}
	
	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::__unlock()
	{
	    Util::Locked::LockHelper<locked,_S>(lock).unlock();
	}

	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::erase(_T* node)
	{
	    __lock();

	    if (node == head)
		head = node->next;
	    else
		node->prev->next = node->next;

	    if (node == tail)
		tail = node->prev;
	    else
		node->next->prev = node->prev; 

	    __unlock();
	}

	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::erase(_K& key)
	{
	    __lock();
	    
	    _T* node = head;

	    while((node != NULL) && (node->key != key))
		node = node->next;

	    if (node != NULL)
	    {
		if (node == head)
		    head = node->next;
		else
		    node->prev->next = node->next;

		if (node == tail)
		    tail = node->prev;
		else
		    node->next->prev = node->prev; 
	    }

	    __unlock();

	    return node;
	}

	template <typename _T, typename _K, bool locked, typename _S>
	_T* List<_T,_K,locked,_S>::find(_K& key)
	{
	    __lock();

	    _T* node = head;

	    while((node != NULL) && (node->key != key))
		node = node->next;

	    __unlock();
	    
	    return node;
	}
    }
}


#endif
