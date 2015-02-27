/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/lockfree/stack.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2015                        */
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
#ifndef __UTIL_LOCKFREE_STACK_H
#define __UTIL_LOCKFREE_STACK_H

#include <stddef.h>
#include <assert.h>
#include <util/lockfree/abaptr.H>

namespace Util
{
    namespace Lockfree
    {
        /** This is a lockfree stack implementation.
         *
         *  This is an intrusive container design, meaning elements being
         *  added to the stack must have a 'next' member of _T* type.
         *
         *  Using the ABAPtr, performs a lockfree implementation of a stack.
         *  The stack also protects against minor corruption by ensuring that
         *  the 'next' pointer inside each stored element maintains a magic
         *  token.
         *
         *  Note: Since this uses the ABAPtr pattern, all pointers must be
         *  only 32-bits in length.
         */
        template <typename _T>
            class Stack
            {
                public:
                    Stack() : head(NULL) {};

                    /** Pop an element from the stack. */
                    _T* pop();
                    /** Push an element to the stack. */
                    void push(_T*);

                    /**
                     * Get a pointer to the first element in the stack
                     * @return the pointer to the first element
                     * @Note:  SMP safety of this pointer is not guaranteed.
                     */
                    _T* first();

                private:
                    _T* head;

                    enum { TOKEN = 0x5354414B };
            };

        template <typename _T>
            _T* Stack<_T>::first()
            {
                // Use AbaPtr to extract just the pointer part.
                return AbaPtr<_T>(head).get();
            }

        template <typename _T>
            _T* Stack<_T>::pop()
            {
                // Save the original head as an AbaPtr.
                AbaPtr<_T> _head = AbaPtr<_T>(head);

                // Extract the pointer part and check for empty stack.
                _T* original = _head.get();
                if (unlikely(NULL == original)) return NULL;

                // Set the head pointer to match the current 'next'.
                AbaPtr<_T> _next = AbaPtr<_T>(original->next);
                _head.set(_next.get());

                // Attempt atomic update.  On fail, rerun function and try
                // again.
                if (unlikely(!_head.update(&head)))
                {
                    return this->pop();
                }

                // Verify the element wasn't corrupted.
                // Note: we can't do this until after the atomic has been
                // successful because otherwise it is possible another thread
                // has already taken the original head element and so we can't
                // trust the original->next value.
                crit_assert(_next.count() == TOKEN);

                // Return the element we popped.
                return original;
            }

        template <typename _T>
            void Stack<_T>::push(_T* p)
            {
                // Save the original head as an AbaPtr.
                AbaPtr<_T> _head = AbaPtr<_T>(head);


                // Create a 'p->next' AbaPtr and set it to head.
                AbaPtr<_T> _next = AbaPtr<_T>(p->next);
                _next.set(_head.get());
                _next.setCount(TOKEN); // p->next token for corruption detect.

                // Update 'p->next'.
                // If this fails we have a memory corruption because someone
                // modified a pointer inside the struct we control.
                crit_assert(_next.update(&p->next));

                // Atomically update head to point at the new element.
                // On fail, rerun function and try again.
                _head.set(p);
                if (!_head.update(&head))
                {
                    return push(p);
                }
            }
    }
}

#endif
