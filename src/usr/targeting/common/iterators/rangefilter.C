/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/iterators/rangefilter.C $            */
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

/**
 *  @file common/targeting/iterators/rangefilter.C
 *
 *  @brief Implementation of an object which takes an iterator range and
 *      allows caller to iterate through the elements which match a supplied
 *      predicate (filter)
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/common/iterators/iterators.H>
#include <targeting/common/trace.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Implementation
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS "RangeFilter<IteratorType>::"

//******************************************************************************
// RangeFilter<IteratorType>::advance
//******************************************************************************

template<typename IteratorType>
void RangeFilter<IteratorType>::advance()
{
    #define TARG_FN "RangeFilter<IteratorType>::advance()"

    if(iv_current != iv_end)
    {
        while( (++iv_current) != iv_end )
        {
            if(   (!iv_pPredicate)
               || ((*iv_pPredicate)(*iv_current)))
            {
                break;
            }
        }
    }

    #undef TARG_FN
}

//******************************************************************************
// RangeFilter<IteratorType>::advanceIfNoMatch
//******************************************************************************

template<typename IteratorType>
void RangeFilter<IteratorType>::advanceIfNoMatch()
{
    if(   (iv_current != iv_end)
       && (   (iv_pPredicate)
           && (!((*iv_pPredicate)(*iv_current)))))
    {
        advance();
    }
}

//******************************************************************************
// RangeFilter<IteratorType>::operator fake_bool
//******************************************************************************

template<typename IteratorType>
RangeFilter<IteratorType>::operator fake_bool() const
{
    return (iv_current != iv_end)
        ? &RangeFilter::notComparable : NULL;
}

//******************************************************************************
// Explicit template class member function instantiations
//******************************************************************************

template void RangeFilter<TargetIterator>::advance();
template void RangeFilter<ConstTargetIterator>::advance();

template void RangeFilter<TargetIterator>::advanceIfNoMatch();
template void RangeFilter<ConstTargetIterator>::advanceIfNoMatch();

template RangeFilter<TargetIterator>::operator fake_bool() const;
template RangeFilter<ConstTargetIterator>::operator fake_bool() const;

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

