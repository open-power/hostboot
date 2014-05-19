/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/locked/list.H $                              */
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

                bool empty();
                _T* begin();

	    protected:
		_T* head;
		_T* tail;

		mutable _S lock;

		void __lock() const;
		void __unlock() const;
	};

        // SFINAE template to ensure compile fails if functions which are not
        // SMP-safe are used on a 'locked' instance.
        template<bool locked>
        class __verify_list_is_smp_safe
        {
            public:
                __verify_list_is_smp_safe()
                {
                    class __util_locked_list_is_not_smp_safe;
                    __util_locked_list_is_not_smp_safe();
                }
        };

        // SFINAE template implementation to allow certain functions when the
        // instance is not 'locked', assuming that caller is ensuring safety
        // in some other way.
        template<>
        class __verify_list_is_smp_safe<false>
        {
            public:
                __verify_list_is_smp_safe()
                {
                }
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

        template <typename _T, typename _K, bool locked, typename _S>
        bool List<_T, _K,locked,_S>::empty()
        {
            bool isEmpty = false;

            __lock();
            isEmpty = (head == NULL);
            __unlock();

            return isEmpty;
        }

        template <typename _T, typename _K, bool locked, typename _S>
        _T* List<_T, _K,locked,_S>::begin()
        {
            // Entirely not SMP-safe to return a pointer to a node if
            // we are a locking instance.  If we aren't locking we
            // have to assume that the caller is ensuring SMP-safety
            // globally in some other way.  Use SFINAE technique to
            // ensure begin() fails on locked lists.
            __verify_list_is_smp_safe<locked>();
            return head;
        }

    }
}


#endif
