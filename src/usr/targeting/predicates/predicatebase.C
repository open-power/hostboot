
/**
 *  @file predicatebase.C
 *
 *  @brief Implementation for an abstract targeting predicate which filters a 
 *      set of targets based on the programmed criteria. Only required to 
 *      implement the virtual destrutor which leads to duplicate weak symbols
 *      if it were instead inlined.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/predicates/predicatebase.H>

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
#define TARG_CLASS "PredicateBase::"

//******************************************************************************
// PredicateBase::~PredicateBase 
//******************************************************************************

PredicateBase::~PredicateBase()
{
    #define TARG_FN "~PredicateBase()"
    #undef TARG_FN
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

