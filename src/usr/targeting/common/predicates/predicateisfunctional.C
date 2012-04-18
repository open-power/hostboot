//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/predicates/predicateisfunctional.C $
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
/**
 *  @file targeting/common/predicates/predicateisfunctional.C
 *
 *  @brief Implement predicate defined in
 *      src/usr/include/targeting/predicate/predicateisfunctional.H
 *
 */

//  targeting support.
#include    <targeting/common/commontargeting.H>

namespace   TARGETING
{

//******************************************************************************
//  PredicateIsFunctional::PredicateIsFunctional()
//******************************************************************************
PredicateIsFunctional::PredicateIsFunctional()
{

}

//******************************************************************************
//  PredicateIsFunctional::~PredicateIsFunctional()
//******************************************************************************
PredicateIsFunctional::~PredicateIsFunctional()
{

}

//******************************************************************************
//  PredicateIsFunctional::operator()
//******************************************************************************
bool PredicateIsFunctional::operator()(
        const TARGETING::Target* i_pTarget) const
{
    bool    l_rc    =   false;

    if ( i_pTarget->getAttr<ATTR_HWAS_STATE>().functional )
    {
        l_rc    =   true;
    }

    return  l_rc;
};

}   // namespace
