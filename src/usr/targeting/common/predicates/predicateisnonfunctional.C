/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/predicates/predicateisnonfunctional.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
