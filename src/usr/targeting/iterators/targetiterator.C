
/**
 *  @file targetiterator.C
 *
 *  @brief Implementation of iterator/const iterator used to iterate through
 *      target service targets 
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/iterators/targetiterator.H>
#include <targeting/targetservice.H>

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

#define TARG_CLASS "_TargetIterator<T>::"

//******************************************************************************
// TargetIterator::advance
//******************************************************************************

template<typename T>
void _TargetIterator<T>::advance()
{
    TargetService& l_targetService = targetService();

    // If cursor points to end()/NULL, do nothing.  Otherwise, check to see if 
    // it should advance (possibly to NULL)
    if(iv_pCurrent != NULL)
    {
        // Advance to end() if no targets available.  Otherwise, check to see if
        // it should advance (possibly to NULL)
        if (l_targetService.iv_maxTargets > 0)
        {
            // If at or past last element, advance to end() else advance
            if(iv_pCurrent >=  
               &(*l_targetService.iv_targets)[l_targetService.iv_maxTargets-1])
            {
               iv_pCurrent = NULL;
            }
            else
            {
                iv_pCurrent++;
            }
        }
        else
        {
            iv_pCurrent = NULL;
        }
    }
}

//******************************************************************************
// Explicit template class member function instantiations
//******************************************************************************

template void _TargetIterator<Target*>::advance();
template void _TargetIterator<const Target*>::advance();

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING



