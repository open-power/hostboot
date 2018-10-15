/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/predicates/predicatehwaschanged.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#include <targeting/adapters/types.H>
#include <targeting/common/trace.H>
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
extern TARG_TD_t g_trac_targeting;

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
    // resets to an invalid cleared state,
    // user needs to identify a bit to check after this reset
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

    TRACDCOMP(g_trac_targeting,
       TARG_FUNC "actual: 0x%.8X, subscription: 0x%.8X, iv_valid: 0x%.8X, iv_desired: 0x%.8X",
       actual.rawValue, subscriptionMask, iv_valid.rawValue, iv_desired.rawValue);

    // Catch a coding error where nothing is being setup to check
    TARG_ASSERT(iv_valid.rawValue != 0, "PredicateHwasChanged::operator() - "
        "No valid bits being checked for change");

    // Only check for change on the bits subscribed to.
    // Skip if not monitoring any of those subscribed bits.
    // Then verify the bits we want to compare are a match to their
    // desired changed state
    return (((iv_valid.rawValue & subscriptionMask) != 0) &&
            (actual.rawValue & (iv_valid.rawValue & subscriptionMask)) ==
            (iv_desired.rawValue & (iv_valid.rawValue & subscriptionMask)));

    #undef TARG_FUNC
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

