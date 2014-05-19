/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatectm.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

#ifndef __TARGETING_COMMON_PREDICATECTM_H
#define __TARGETING_COMMON_PREDICATECTM_H

/**
 *  @file targeting/common/predicates/predicatectm.H
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
#include <targeting/common/target.H>
#include <targeting/common/attributes.H>
#include <targeting/common/predicates/predicatebase.H>

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
        virtual ~PredicateCTM();

        /**
         *  @brief Set the class
         *
         *  @param[in] i_class Class of matching target
         */
        void setClass(CLASS i_class);

        /**
         *  @brief Set the type
         *
         *  @param[in] i_type Type of matching target
         */
        void setType(TYPE i_type);

        /**
         *  @brief Set the model
         *
         *  @param[in] i_model Model of matching target
         */
        void setModel(MODEL i_model);

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
         *
         *  @param[in] i_pTarget
         *      Target handle pointing to the target to compare to
         *
         *  @return bool indicating whether the target matches or not
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

//******************************************************************************
// PredicateCTM::setClass
//******************************************************************************

inline void PredicateCTM::setClass(CLASS i_class)
{
    iv_class = i_class;
}

//******************************************************************************
// PredicateCTM::setType
//******************************************************************************

inline void PredicateCTM::setType(TYPE i_type)
{
    iv_type = i_type;
}

//******************************************************************************
// PredicateCTM::setModel
//******************************************************************************

inline void PredicateCTM::setModel(MODEL i_model)
{
    iv_model = i_model;
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATECTM_H
