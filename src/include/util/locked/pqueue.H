/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/locked/pqueue.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
                    _T* front();

                private:
                    void bubbleUp(_T*);
            };

        // SFINAE template to ensure compile fails if functions which are not
        // SMP-safe are used on a 'locked' instance.
        template<bool locked>
            class __verify_pqueue_is_smp_safe
            {
                public:
                    __verify_pqueue_is_smp_safe()
                    {
                        class __util_locked_pqueue_is_not_smp_safe;
                        __util_locked_pqueue_is_not_smp_safe();
                    }
            };

        // SFINAE template implementation to allow certain functions when the
        // instance is not 'locked', assuming that caller is ensuring safety
        // in some other way.
        template<>
            class __verify_pqueue_is_smp_safe<false>
            {
                public:
                    __verify_pqueue_is_smp_safe()
                    {
                    }
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

                    if (item->prev)
                        item->prev->next = NULL;
                }

                this->__unlock();

                return item;
            }


        template <typename _T, typename _K, bool locked, typename _S>
            void PQueue<_T,_K,locked,_S>::bubbleUp(_T* item)
            {
                while(1)
                {

                    if (!item->next)
                        break;

                    if (item->next->key <= item->key)
                        break;

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
                }
            }


        template <typename _T, typename _K, bool locked, typename _S>
        _T* PQueue<_T, _K,locked,_S>::front()
        {
            // Entirely not SMP-safe to return a pointer to a node if
            // we are a locking instance.  If we aren't locking we
            // have to assume that the caller is ensuring SMP-safety
            // globally in some other way.  Use SFINAE technique to
            // ensure front() fails on locked lists.
            __verify_pqueue_is_smp_safe<locked>();
            return this->tail;
        }
    };
};

#endif
