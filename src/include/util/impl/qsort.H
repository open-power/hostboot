/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/qsort.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef __UTIL_IMPL_QSORT_H
#define __UTIL_IMPL_QSORT_H

/** @file qsort.H
 *
 *  Contains the internal implementation details of std::sort implemented as
 *  quick-sort.
 */

#include <iterator>

// Forward declaration due to 'swap' being defined in <algorithm> which is
// including this file itself.
namespace std
{
    template <typename T> void swap(T& a, T& b);
};

namespace Util
{
    namespace __Util_QSort_Impl
    {
        template <typename RandomAccessIterator>
        void sort(RandomAccessIterator first, RandomAccessIterator last)
        {
            size_t length = std::distance(first, last);

            // A range of length 0 or 1 is already sort.
            if ((length == 0) || (length == 1))
            {
                return;
            }

            // A range of length 2 has a trivial sort.
            if (length == 2)
            {
                RandomAccessIterator next = first;
                std::advance(next, 1);

                if (*next < *first)
                {
                    std::swap(*first, *next);
                }
                return;
            }

            // Choose pivot as middle and move pivot to end.
            //     This is done to eliminate the O(n^2) behavior when the
            //     range is already sorted.
            RandomAccessIterator pivot = first;
            std::advance(pivot,length - 1);
            RandomAccessIterator middle = first;
            std::advance(middle, length / 2);
            std::swap(*pivot, *middle);

            // Perform partitioning...

            // Division points to the first element greater than the pivot or
            // else the farthest point partitioned if no elements greater than
            // the pivot have been found yet.
            RandomAccessIterator division = first;
            RandomAccessIterator pos = first;
            while(pos != pivot)
            {
                // Element less than the pivot is found, so move it to the
                // "less than" side of the division line.
                if (*pos < *pivot)
                {
                    if (pos != division)
                    {
                        std::swap(*pos, *division);
                    }
                    ++division;
                }

                ++pos;
            }

            // Move the pivot down to the division line, which is its sorted
            // position in the range.
            if (pivot != division)
            {
                std::swap(*pivot,*division);
            }

            // Sort each partition
            __Util_QSort_Impl::sort(first,division);
            std::advance(division, 1);
            __Util_QSort_Impl::sort(division, last);
        };


        template <typename RandomAccessIterator, typename StrictWeakOrdering>
        void sort(RandomAccessIterator first, RandomAccessIterator last,
                  StrictWeakOrdering pred)
        {
            size_t length = std::distance(first, last);

            // A range of length 0 or 1 is already sort.
            if ((length == 0) || (length == 1))
            {
                return;
            }

            // A range of length 2 has a trivial sort.
            if (length == 2)
            {
                RandomAccessIterator next = first;
                std::advance(next, 1);

                if (pred(*next,*first))
                {
                    std::swap(*first, *next);
                }
                return;
            }

            // Choose pivot as middle and move pivot to end.
            //     This is done to eliminate the O(n^2) behavior when the
            //     range is already sorted.
            RandomAccessIterator pivot = first;
            std::advance(pivot,length - 1);
            RandomAccessIterator middle = first;
            std::advance(middle, length / 2);
            std::swap(*pivot, *middle);

            // Perform partitioning...

            // Division points to the first element greater than the pivot or
            // else the farthest point partitioned if no elements greater than
            // the pivot have been found yet.
            RandomAccessIterator division = first;
            RandomAccessIterator pos = first;
            while(pos != pivot)
            {
                // Element less than the pivot is found, so move it to the
                // "less than" side of the division line.
                if (pred(*pos,*pivot))
                {
                    if (pos != division)
                    {
                        std::swap(*pos, *division);
                    }
                    ++division;
                }

                ++pos;
            }

            // Move the pivot down to the division line, which is its sorted
            // position in the range.
            if (pivot != division)
            {
                std::swap(*pivot,*division);
            }

            // Sort each partition.
             __Util_QSort_Impl::sort(first,division,pred);
            std::advance(division, 1);
             __Util_QSort_Impl::sort(division, last,pred);
        };

    };
};

#endif
