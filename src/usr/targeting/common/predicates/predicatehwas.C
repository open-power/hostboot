/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/targeting/common/predicates/predicatehwas.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */

/**
 *  @file targeting/common/predicates/predicatehwas.C
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
#define TARG_CLASS "PredicateHwas::"

//******************************************************************************
// PredicateHwas::~PredicateHwas()
//******************************************************************************

PredicateHwas::~PredicateHwas() 
{
    #define TARG_FUNC "~PredicateHwas()"
    #undef TARG_FUNC
}

//******************************************************************************
// PredicateHwas::reset
//******************************************************************************

PredicateHwas& PredicateHwas::reset()
{
    memset(&iv_valid,0x00,sizeof(iv_valid));
    memset(&iv_desired,0x00,sizeof(iv_desired));
    return *this;
}

//******************************************************************************
// PredicateHwas::operator()
//******************************************************************************

bool PredicateHwas::operator()(
    const Target* const i_pTarget) const
{
    #define TARG_FUNC "operator()(...)" 
 
    hwasState actual = { rawValue: 0};
    CPPASSERT(sizeof(actual.attribute) <= sizeof(actual.rawValue));
    actual.attribute = i_pTarget->getAttr<ATTR_HWAS_STATE>();
    
    return (   (actual.rawValue & iv_valid.rawValue) 
            == (iv_desired.rawValue & iv_valid.rawValue));
    
    #undef TARG_FUNC
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

