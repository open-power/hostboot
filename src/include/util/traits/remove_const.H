//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/traits/remove_const.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

#ifndef __UTIL_TRAITS_REMOVE_CONST
#define __UTIL_TRAITS_REMOVE_CONST

/** @file remove_const.H
 *  Creates a template class remove_const who's type typedef will strip the
 *  "const" from another type.
 *
 *  Example:
 *      remove_const<const int>::type == int
 *      remove_const<int>::type == int
 *      remove_const<const int*>::type == int*
 *
 */

namespace Util
{
    namespace Traits
    {
        template <typename T> struct remove_const;

        template <typename T>
        struct remove_const<const T>
        {
            typedef T type;
        };

        template <typename T>
        struct remove_const<const T*>
        {
            typedef T* type;
        };

        template <typename T>
        struct remove_const<const T&>
        {
            typedef T& type;
        };

        template <typename T>
        struct remove_const
        {
            typedef T type;
        };

    };
};

#endif
