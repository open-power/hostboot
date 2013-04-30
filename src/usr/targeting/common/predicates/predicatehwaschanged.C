/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/predicates/predicatehwaschanged.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
 *  @file targeting/common/predicates/predicatehwaschanged.C
 *
 *  @brief Implementation for a predicate which fiters a target based on its
 *      HWAS state
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <string.h>

// Other Host Boot Components

// Targeting Component
#include <targeting/common/attributes.H>
#include <targeting/common/target.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/adapters/assertadapter.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FN

//******************************************************************************
// Interface
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "PredicateHwasChanged::"

//******************************************************************************
// PredicateHwasChanged::~PredicateHwasChanged()
//******************************************************************************

PredicateHwasChanged::~PredicateHwasChanged()
{
    #define TARG_FUNC "~PredicateHwasChanged()"
    #undef TARG_FUNC
}

//******************************************************************************
// PredicateHwasChanged::reset
//******************************************************************************

PredicateHwasChanged& PredicateHwasChanged::reset()
{
    memset(&iv_valid,0x00,sizeof(iv_valid));
    memset(&iv_desired,0x00,sizeof(iv_desired));
    return *this;
}

//******************************************************************************
// PredicateHwasChanged::operator()
//******************************************************************************

bool PredicateHwasChanged::operator()(
    const Target* const i_pTarget) const
{
    #define TARG_FUNC "operator()(...)"

    hwasStateChangedFlag actual = { rawValue: 0};
    CPPASSERT(sizeof(actual.attribute) <=
                sizeof(actual.rawValue));
    actual.attribute =
            i_pTarget->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();
    ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK_type subscriptionMask =
            i_pTarget->getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>();

    return ((actual.rawValue & (iv_valid.rawValue & subscriptionMask)) ==
            (iv_desired.rawValue & (iv_valid.rawValue & subscriptionMask)));

    #undef TARG_FUNC
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

