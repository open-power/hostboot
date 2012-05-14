//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/impl/qsort.H $
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

            // Sort each partition.
            sort(first,division);
            std::advance(division, 1);
            sort(division, last);
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
            sort(first,division);
            std::advance(division, 1);
            sort(division, last);
        };

    };
};

#endif
