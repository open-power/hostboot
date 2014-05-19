/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/predicates/predicateisnonfunctional.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
 *  @file targeting/common/predicates/predicateisnonfunctional.C
 *
 *  @brief Implement predicate defined in
 *      src/usr/include/targeting/predicate/predicateisnonfunctional.H
 *
 */

//  targeting support.
#include    <targeting/common/commontargeting.H>

namespace   TARGETING
{

//******************************************************************************
//  PredicateIsNonFunctional::PredicateIsNonFunctional()
//******************************************************************************
PredicateIsNonFunctional::PredicateIsNonFunctional(bool i_requirePresent)
    :iv_requirePresent(i_requirePresent)
{

}

//******************************************************************************
//  PredicateIsNonFunctional::~PredicateIsNonFunctional()
//******************************************************************************
PredicateIsNonFunctional::~PredicateIsNonFunctional()
{

}

//******************************************************************************
//  PredicateIsNonFunctional::operator()
//******************************************************************************
bool PredicateIsNonFunctional::operator()(
        const TARGETING::Target* i_pTarget) const
{
    bool l_rc = false;

    if (iv_requirePresent)
    {
        l_rc = ((!i_pTarget->getAttr<ATTR_HWAS_STATE>().functional) &&
                (i_pTarget->getAttr<ATTR_HWAS_STATE>().present));
    }
    else
    {
        l_rc = !i_pTarget->getAttr<ATTR_HWAS_STATE>().functional;
    }

    return l_rc;
};

}   // namespace
