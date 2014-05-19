/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/iterators/rawtargetiterator.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
 *  @file targeting/common/iterators/rawtargetiterator.C
 *
 *  @brief Implementation of raw iterator/const raw iterator used to iterate
 *      through all target service targets
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

#define TARG_CLASS "_TargetRawIterator<T>::"

//******************************************************************************
// TargetIterator::advance
//******************************************************************************

template<typename T>
void _TargetRawIterator<T>::advance()
{
    static TargetService& l_targetService = targetService();

    // If cursor points to end()/NULL, do nothing.  Otherwise, check to see if
    // it should advance (possibly to NULL)
    if(_TargetIterator<T>::iv_pCurrent != NULL)
    {
        _TargetIterator<T>::iv_pCurrent =
            l_targetService.getNextTarget(_TargetIterator<T>::iv_pCurrent);
    }
}

//******************************************************************************
// Explicit template class member function instantiations
//******************************************************************************

template void _TargetRawIterator<Target*>::advance();
template void _TargetRawIterator<const Target*>::advance();

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING

