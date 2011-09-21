//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/iterators/rangefilter.C $
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

/**
 *  @file rangefilter.C
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
#include <targeting/iterators/rangefilter.H>

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

