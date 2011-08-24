//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/predicates/predicatectm.H $
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

#ifndef TARG_PREDICATECTM_H
#define TARG_PREDICATECTM_H

/**
 *  @file predicatectm.H
 *
 *  @brief Interface for a predicate which fiters a target based on its class,
 *      type, and model.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/target.H>
#include <targeting/attributeenums.H>
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
#define TARG_CLASS "PredicateCTM::"

class Target;

/**
 *  @brief Predicate class which filters a target based on its class, type,
 *      and model
 */
class PredicateCTM : public PredicateBase
{
    public:

        /**
         *  @brief Create a target class, type, model predicate
         *
         *  @param[in] i_class Class of matching target, default NA (any)
         *  @param[in] i_type Type of matching target, default NA (any)
         *  @param[in] i_model Model of matching target, default NA (any)
         */
        PredicateCTM(
            CLASS i_class = CLASS_NA,
            TYPE  i_type  = TYPE_NA,
            MODEL i_model = MODEL_NA);

        /**
         *  @brief Destroy a class, type, model predicate 
         */
        virtual ~PredicateCTM() 
        {
            #define TARG_FUNC "~PredicateCTM()"
            #undef TARG_FUNC
        }
    
        /**
         *  @brief Returns whether target matches the specified class, type,
         *      model
         * 
         *  @par Detailed Description:
         *      Returns whether target matches the specified class, type, model.
         *      Note that all three fields are always compared, so wildcards
         *      (CLASS_NA, TYPE_NA, MODEL_NA) must be used for any fields that
         *      do not matter.  See PredicateBase class for parameter/return 
         *      description.
         */
        virtual bool operator()(
            const Target* i_pTarget) const;

    private:
    
        CLASS iv_class; ///< Class to compare with that of target
        TYPE  iv_type;  ///< Type to compare with that of target
        MODEL iv_model; ///< Model to compare with that of target

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateCTM);
};

//******************************************************************************
// PredicateCTM::PredicateCTM
//******************************************************************************

inline PredicateCTM::PredicateCTM(
    const CLASS i_class,
    const TYPE  i_type,
    const MODEL i_model) 
: iv_class(i_class), 
  iv_type(i_type), 
  iv_model(i_model) 
{
    #define TARG_FUNC "PredicateCTM(...)"
    #undef TARG_FUNC
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // TARG_PREDICATECTM_H
