/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/iterator.h $                            */
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
         *  Uses the existence of a += operator on the iterator to determine
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
         *  Uses the existence of a - operator on the iterator to determine
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
