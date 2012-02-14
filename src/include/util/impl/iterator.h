//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/util/impl/iterator.h $
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

#ifndef __UTIL_IMPL_ITERATOR_H
#define __UTIL_IMPL_ITERATOR_H

/** @file iterator.h
 *
 *  Contains the internal implementation details of the stl <iterator> header.
 */

#include <util/traits/has_plusequals.H>
#include <util/traits/has_minus.H>

namespace Util
{
    namespace __Util_Iterator_Impl
    {

        /**
         *  Template definition of an iterator advance functor.
         */
        template <typename InputIterator, typename Distance,
                  bool HasPlusEquals> struct AdvanceImpl;

        /**
         *  Template specialization of the advance functor for iterators
         *  which do not support random access.
         */
        template <typename InputIterator, typename Distance>
        struct AdvanceImpl<InputIterator, Distance, false>
        {
            static void advance(InputIterator& i, Distance n)
            {
                while(n--)
                    ++i;
            }
        };

        /**
         *  Template specialization of the advance functor for iterators
         *  which do support random access.
         */
        template <typename RandomIterator, typename Distance>
        struct AdvanceImpl<RandomIterator, Distance, true>
        {
            static void advance(RandomIterator& i, Distance n)
            {
                i += n;
            }
        };

        /**
         *  Template wrapper function for the iterator advance.
         *
         *  Uses the existance of a += operator on the iterator to determine
         *  if the random-access or non-random-access version should be used.
         */
        template <typename InputIterator, typename Distance>
        void advance(InputIterator& i, Distance n)
        {
            AdvanceImpl<InputIterator, Distance,
                    Util::Traits::has_plusequals<InputIterator,Distance,
                                                 InputIterator>::value
                >::advance(i,n);
        }

        /**
         *  Template definition of an iterator distance functor.
         */
        template <typename InputIterator, typename Distance,
                  bool HasMinus> struct DistanceImpl;

        /**
         *  Template specialization of the distance functor for iterators
         *  which do not support random access.
         */
        template <typename InputIterator, typename Distance>
        struct DistanceImpl<InputIterator, Distance, false>
        {
            static Distance distance(InputIterator& first,
                                     InputIterator& last)
            {
                Distance i = 0;
                while (first != last)
                {
                    ++i;
                    ++first;
                }
                return i;
            }
        };

        /**
         *  Template specialization of the distance functor for iterators
         *  which do support random access.
         */
        template <typename RandomIterator, typename Distance>
        struct DistanceImpl<RandomIterator, Distance, true>
        {
            static Distance distance(RandomIterator& first,
                                     RandomIterator& last)
            {
                return last - first;
            }
        };

        /**
         *  Template wrapper function for the iterator distance.
         *
         *  Uses the existance of a - operator on the iterator to determine
         *  if the random-access or non-random-access version should be used.
         */
        template <typename InputIterator, typename Distance>
        Distance distance(InputIterator& first,
                          InputIterator& last)
        {
            return DistanceImpl<InputIterator, Distance,
                        Util::Traits::has_minus<InputIterator, InputIterator,
                                                Distance>::value
                    >::distance(first,last);
        }

    };
};

#endif
