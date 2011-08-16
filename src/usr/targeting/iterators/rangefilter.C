
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
// Explicit template class member function instantiations
//******************************************************************************

template void RangeFilter<TargetIterator>::advance();
template void RangeFilter<ConstTargetIterator>::advance();

template void RangeFilter<TargetIterator>::advanceIfNoMatch();
template void RangeFilter<ConstTargetIterator>::advanceIfNoMatch();

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

