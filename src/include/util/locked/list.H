//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/locked/list.H $
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

		_T* find(_K& key) const;

	    protected:
		_T* head;
		_T* tail;

		mutable _S lock;

		void __lock() const;
		void __unlock() const;
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
	void List<_T,_K,locked,_S>::__lock() const
	{
	    Util::Locked::LockHelper<locked,_S>(lock).lock();
	}

	template <typename _T, typename _K, bool locked, typename _S>
	void List<_T,_K,locked,_S>::__unlock() const
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
	_T* List<_T,_K,locked,_S>::find(_K& key) const
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
