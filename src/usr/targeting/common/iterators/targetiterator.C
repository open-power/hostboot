/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/iterators/targetiterator.C $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 *  @file targeting/common/iterators/targetiterator.C
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
#include <targeting/common/iterators/iterators.H>
#include <targeting/common/targetservice.H>

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
    static TargetService& l_targetService = targetService();

    // If cursor points to end()/NULL, do nothing.  Otherwise, check to see if
    // it should advance (possibly to NULL)
    if(likely (iv_pCurrent != NULL) )
    {
        // In HB the first block will always compile to run and take the optimal
        // iterator performance path that assumes only one node's worth of data
        if(!PLAT::PROPERTIES::MULTINODE_AWARE)
        {
            if (   likely( (!l_targetService.iv_nodeInfo.empty()) )
                && likely( (l_targetService.iv_nodeInfo[0].maxTargets > 0)  ) )
            {
                // If at or past last element, advance to end() else advance
                if(unlikely (
                       iv_pCurrent >=
                           &(*(l_targetService.iv_nodeInfo[0]).targets)
                               [l_targetService.iv_nodeInfo[0].maxTargets-1]
                   ))
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
        else
        {
            iv_pCurrent = l_targetService.getNextTarget(iv_pCurrent);
            if(likely(iv_pCurrent != NULL))
            {
                // Targeting XML and compiler ensure that there are no back to
                // back hidden system targets; therefore, if the current one is
                // a hidden system target, skip it and the next one will either
                // be valid or NULL (i.e. end())
                if(unlikely(
                      l_targetService.isNonMasterNodeSystemTarget(iv_pCurrent)))
                {
                    iv_pCurrent = l_targetService.getNextTarget(iv_pCurrent);
                }
            }

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



