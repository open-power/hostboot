/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/lockfree/abaptr.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __UTIL_LOCKFREE_ABAPTR_H
#define __UTIL_LOCKFREE_ABAPTR_H

#include <stdint.h>
#include <assert.h>

namespace Util
{
    namespace Lockfree
    {
        /** ABA-safe smart pointer class.
         *
         *  Lockfree algorithms often utilize atomic operations like
         *  'compare-and-swap' to identify conditions when another thread
         *  has caused contention and already modified the same data this
         *  thread is attempting to modify.  The 'ABA' problem, or 'A-B-A',
         *  is a common problem class in lockfree algorithms.
         *
         *  The desired behavior between two threads is a sequence such as:
         *     1) 'A' reads a value and begins some calculation.
         *     2) 'B' updates the value read by 'A'.
         *     3) 'A' attempts to atomically update the value but fails
         *        because 'B' has already modified the value in step 2.
         *
         *  The typical solution to this program sequence is an atomic update,
         *  like compare-and-swap, that fails when the value is different
         *  between steps 1 and 3.
         *
         *  When operating with pointers, it is quite possible for a pointer
         *  to be reused.  Due to pointer reuse, the step 2 update could
         *  write the same value back as what was read in step 1.  If this
         *  happens, step 3 will appear to succeed even though it should not.
         *  This is the ABA problem.  (ABA affects any atomic algorithm where
         *  values can be reused, but especially impacts pointers)
         *
         *  A common 'trick' to solve the ABA problem with pointers, and the
         *  one implemented here, is to use a rolling value in the upper
         *  part of a pointer.  The upper N bits are reserved for this rolling
         *  value and the bottom 64-N bits can be masked off to obtain the
         *  real pointer value.  N-bits of rolling value results in a
         *  (1 / 2^N) probability of an incorrectly-successful step 3 when
         *  there is pointer reuse.
         *
         *  Since Hostboot heap memory addresses are all well below 4GB, we
         *  can use the upper 32 bits as the rolling value.  This yields us
         *  probability sufficiently close to zero of a pointer reuse at the
         *  same time as a value reuse.
         *
         *  This class acts as a smart-pointer specifically for maintaining
         *  the ABA-solution properties.
         */
        template <typename _T>
            class AbaPtr
            {
                public:
                    /** Default constructor - set everything to NULL. */
                    AbaPtr() : original(NULL), ptr(NULL), counter(0) {};

                    /** Construct from existing pointer value. */
                    explicit AbaPtr(_T* i_ptr) : original(i_ptr),
                            ptr(_getPtr(i_ptr)),
                            counter(_getCounter(i_ptr))
                    {
                    }

                    /** Assignment operator */
                    AbaPtr& operator=(_T* i_ptr)
                    {
                        original = i_ptr;
                        ptr = _getPtr(i_ptr);
                        counter = _getCounter(i_ptr);
                        return *this;
                    }

                    /** Set pointer portion.  Update count. */
                    AbaPtr& set(_T* i_ptr)
                    {
                        ptr = _getPtr(i_ptr);
                        counter++;

                        return *this;
                    }

                    /** Get pointer. */
                    _T* get() const
                    {
                        return ptr;
                    }

                    /** Dereference operator. */
                    _T& operator*() const
                    {
                        return *ptr;
                    }

                    /** Dereference operator. */
                    _T* operator->() const
                    {
                        return ptr;
                    }

                    /** Perform atomic update of pointer, with ABA properties.
                     *
                     *  @param[in] o_ptr - Pointer location to be updated.
                     *
                     *  Updates o_ptr with the ABA pointer value from this
                     *  object if the o_ptr still contains the 'original'
                     *  value from time of construction or assignment.
                     */
                    bool update(_T** o_ptr)
                    {
                        return __sync_bool_compare_and_swap(o_ptr,
                                                            original,
                                                            _getVal());
                    }

                    bool update(_T* volatile* o_ptr)
                    {
                        return __sync_bool_compare_and_swap(o_ptr,
                                                            original,
                                                            _getVal());
                    }


                    /** Get count */
                    uint32_t count() const
                    {
                        return counter;
                    }

                    /** Set count */
                    void setCount(uint32_t i_count)
                    {
                        counter = i_count;
                    }

                    /** Get full value */
                    _T* value() const { return _getVal(); }

                protected:

                    /** Utility function to get 'pointer' part of ABA value. */
                    static _T* _getPtr(_T* i_ptr)
                    {
                        CPPASSERT(sizeof(_T*) == sizeof(uint64_t));
                        return reinterpret_cast<_T*>(
                            reinterpret_cast<uint64_t>(i_ptr) & 0x0FFFFFFFFull
                        );
                    }

                    /** Utility function to get 'counter' part of ABA value. */
                    static uint32_t _getCounter(_T* i_ptr)
                    {
                        CPPASSERT(sizeof(_T*) == sizeof(uint64_t));
                        return (reinterpret_cast<uint64_t>(i_ptr) >> 32) &
                            0x0FFFFFFFFull;
                    }

                    /** Reconstruct ABA poitner value from components. */
                    _T* _getVal() const
                    {
                        CPPASSERT(sizeof(_T*) == sizeof(uint64_t));
                        return reinterpret_cast<_T*>(
                            (static_cast<uint64_t>(counter) << 32) |
                            (reinterpret_cast<uint64_t>(ptr))
                        );
                    }

                private:
                    /** Prevent operator== because it isn't intuitive for this
                     *  object. */
                    bool operator==(const AbaPtr<_T>& i) const;

                    _T* original;
                    _T* ptr;
                    uint32_t counter;
            };
    }
}

#endif
