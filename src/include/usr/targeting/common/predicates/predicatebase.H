/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatebase.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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

#ifndef __TARGETING_COMMON_PREDICATEBASE_H
#define __TARGETING_COMMON_PREDICATEBASE_H

/**
 *  @file targeting/common/predicates/predicatebase.H
 *
 *  @brief Interface for an abstract targeting predicate which filters a set of
 *      targets based on the programmed criteria.  Concrete predicates must
 *      provide the interface specified here.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component

//******************************************************************************
// Macros 
//******************************************************************************

/**
 *  @brief Disable copy constructor / assignment operators
 */
#undef TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS
#define TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(Type) \
    Type(const Type& i_other); \
    Type& operator=(const Type& i_other)

/**
 *  @brief Ensure trace macros are undefined
 */
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

class Target;

/**
 *  @brief Abstract predicate class which specifies an interface for all
 *      concrete predicates.  A predicate acts as a filter on a set of targets.
 */
class PredicateBase
{
    public:

        /**
         *  @brief Destroys the predicate base class (nothing to do)
         */
        virtual ~PredicateBase();

        /**
         *  @brief Predicate function call interface
         *
         *  @par Detailed Description:
         *      This abstract interface must be declared/implemented by all
         *      derived predicates.  A concrete version of this function accepts
         *      a target, applies the associated predicate logic, and returns
         *      whether the target met the predicate criteria or not.  Caller
         *      must always supply a valid Target*, or routine will assert.
         *      
         *  @param[in] i_pTarget Pointer to target to apply predicate to
         *
         *  @return Boolean indicating whether target matches criteria specified
         *      by the concrete predicate
         *
         *  @retval true Target matches the predicate criteria
         *  @retval false Target does not match the predicate criteria
         */
        virtual bool operator()(
            const Target* i_pTarget) const = 0;

    protected:

        /**
         *  @brief Create the predicate base class (nothing to do)
         *
         *  @note Constructor protected to allow access from the derived class
         */
        PredicateBase()
        {
            #define TARG_FN "PredicateBase()"
            #undef TARG_FN
        }

    private:

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateBase);
};

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEBASE_H
