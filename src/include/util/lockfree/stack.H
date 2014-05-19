/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/lockfree/stack.H $                           */
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
#ifndef __UTIL_LOCKFREE_STACK_H
#define __UTIL_LOCKFREE_STACK_H

#include <stddef.h>
#include <assert.h>

namespace Util
{
    namespace Lockfree
    {
        template <typename _T>
            class Stack
            {
                public:
                    Stack() : head(NULL) {};

                    _T* pop();
                    void push(_T*);

                    /**
                     * Get a pointer to the first element in the stack
                     * @return the pointer to the first element
                     * @Note:  SMP safety of this pointer is not guaranteed.
                     */
                    _T* first();

                private:
                    _T* head;
            };

        template <typename _T>
            _T* Stack<_T>::first()
            {
                _T * _head = head;
                return (_T*) (((uint64_t)_head) & 0x00000000FFFFFFFF);
            }

        template <typename _T>
            _T* Stack<_T>::pop()
            {
                _T * _head = head;
                _T * h = (_T*) (((uint64_t)_head) & 0x00000000FFFFFFFF);
                if (NULL == h) return h;
                uint64_t token = ((uint64_t)_head) >> 32;
                token++;
                uint64_t h_next_v = (uint64_t)(h->next);
                _T * h_next = (_T*) ((h_next_v & 0x00000000FFFFFFFF) |
                                     (token << 32));
                if (!__sync_bool_compare_and_swap(&head,
                                                  _head,
                                                  h_next))
                    return pop();

                crit_assert((h_next_v >> 32) == 0x5354414B);
                return h;
            }

        template <typename _T>
            void Stack<_T>::push(_T* p)
            {
                _T* _head = head;
                p->next = (_T*) ((((uint64_t)_head) & 0x00000000FFFFFFFF) |
                          0x5354414B00000000);
                uint64_t token = ((uint64_t)_head) >> 32;
                token++;

                _T* _p = (_T*) (((uint64_t)p) | (token << 32));

                if (!__sync_bool_compare_and_swap(&head,
                                                  _head,
                                                  _p))
                    push(p);
            }
    }
}

#endif
