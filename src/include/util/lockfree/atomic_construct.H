//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/lockfree/atomic_construct.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
