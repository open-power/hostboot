//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/algorithm.H $
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
#ifndef __UTIL_ALGORITHM_H
#define __UTIL_ALGORITHM_H

namespace Util
{
    namespace Algorithm
    {

        /** @struct static_min
         *  @brief Template class to perform a compile-time min calculation.
         *
         *  Example:
         *      static_min<size_t, 5, 7>::value == 5
         */
        template <typename T, T a, T b>
        struct static_min
        {
            static const T value = (a < b) ? a : b;
        };

        /** @struct static_max
         *  @brief Template class to perform a compile-time max calculation.
         *
         *  Example:
         *      static_max<size_t, 5, 7>::value == 7
         */
        template <typename T, T a, T b>
        struct static_max
        {
            static const T value = (a > b) ? a : b;
        };

    };
};
#endif
