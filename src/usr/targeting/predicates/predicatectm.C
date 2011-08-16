
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
#include <targeting/attributeenums.H>
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

