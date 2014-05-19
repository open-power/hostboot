/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/lockfree/atomic_construct.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __UTIL_LOCKFREE_ATOMIC_CONSTRUCT_H
#define __UTIL_LOCKFREE_ATOMIC_CONSTRUCT_H

namespace Util
{
    namespace Lockfree
    {

        /** @brief Atomically construct an object and assign it to a pointer.
         *
         *  This function will check if a pointer is still NULL and
         *  construct an object, atomically, if needed.  If the pointer is
         *  not NULL, the current instance will be left alone.
         *
         *  @param[in] ptr - Pointer-pointer to the object.
         *
         *  Example:
         *      Foo* iv_foo;  //<--- instance variable in class.
         *      atomic_construct(&iv_foo);
         *
         *  @note It is possible for multiple instances to temporarily exist,
         *        if this code is called from multiple CPUs, but only the one
         *        instance will exist outside the lifetime of this function.
         */
        template<typename _T>
            void atomic_construct(_T** ptr)
            {
                if (__sync_bool_compare_and_swap(ptr, NULL, NULL))
                {
                    _T* instance = new _T();
                    if (!__sync_bool_compare_and_swap(ptr, NULL, instance))
                    {
                        delete instance;
                    }
                }
            }
    };
};

#endif
