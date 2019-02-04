/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/nolockfree/stack.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2019                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef __UTIL_NOLOCKFREE_STACK_H
#define __UTIL_NOLOCKFREE_STACK_H

#include <stddef.h>
#include <assert.h>

namespace Util
{
    namespace NoLockFree
    {

    /**
     *  @brief Non-lockfree stack implementation
     *
     *  This is an intrusive container design, meaning elements being
     *  added to the stack must have a 'next' member of _T* type.  This
     *  container is not threadsafe.
     *
     *  @note: For a lockfree stack implementation, see Util::LockFree::Stack
     */
    template <typename _T>
        class Stack
        {
            public:

                /**
                 *  @brief Constructor
                 */
                Stack()
                  : head(nullptr)
                {
                }

                /**
                 *  @brief Pop an element from the stack.
                 *
                 *  @return _T* The pointer to the element popped from the stack
                 */
                _T* pop();

                /**
                 *  @brief Push an element to the stack.
                 *
                 *  @param[in] p Pointer to the element to add to the stack.
                 */
                void push(_T* p);

                /**
                 *  @brief Get a pointer to the first element in the stack
                 *
                 *  @return _T* The pointer to the first element
                 *  @Note: SMP safety of this pointer is not guaranteed.
                 */
                _T* first();

            private:
                _T* head;
        };

    template <typename _T>
        _T* Stack<_T>::first()
        {
            return head;
        }

    template <typename _T>
        _T* Stack<_T>::pop()
        {
            auto original = head;
            if (unlikely(nullptr == original))
            {
                return nullptr;
            }
            head = original->next;
            return original;
        }

    template <typename _T>
        void Stack<_T>::push(_T* p)
        {
            p->next = head;
            head = p;
        }

    } // End NoLockFree namespace

} // End Util namespace

#endif // __UTIL_NOLOCKFREE_STACK_H

