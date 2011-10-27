//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/predicates/predicatectm.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
 *  @file predicatectm.C
 *
 *  @brief Implementation for a predicate which fiters a target based on its 
 *      class, type, and model.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/target.H>
#include <attributeenums.H>
#include <targeting/predicates/predicatectm.H>

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
#define TARG_CLASS "PredicateCTM::"

//******************************************************************************
// PredicateCTM::~PredicateCTM()
//******************************************************************************

PredicateCTM::~PredicateCTM() 
{
    #define TARG_FUNC "~PredicateCTM()"
    #undef TARG_FUNC
}

//******************************************************************************
// PredicateCTM::operator()
//******************************************************************************

bool PredicateCTM::operator()(
    const Target* const i_pTarget) const
{
    #define TARG_FUNC "operator()(...)"

    return (   (   (iv_class == CLASS_NA)
                || (i_pTarget->getAttr<ATTR_CLASS>() == iv_class))
            && (   (iv_type == TYPE_NA)
                || (i_pTarget->getAttr<ATTR_TYPE>() == iv_type))
            && (   (iv_model == MODEL_NA)
                || (i_pTarget->getAttr<ATTR_MODEL>() == iv_model)));
    
    #undef TARG_FUNC
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

