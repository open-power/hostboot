/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicateattr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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

#ifndef __TARGETING_COMMON_PREDICATEATTR_H
#define __TARGETING_COMMON_PREDICATEATTR_H

/**
 *  @file targeting/common/predicates/predicateattr.H
 *
 *  @brief Interface and implementation for a predicate which filters a target
 *      based on whether it possesses a given attribute
 */

//******************************************************************************
// Includes
//******************************************************************************

// Other Host Boot Components

// Targeting Component
#include <targeting/common/target.H>
#include <targeting/common/attributes.H>
#include <targeting/common/predicates/predicatebase.H>

//******************************************************************************
// Interface and implementation
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "PredicateAttr::"

class Target;

/**
 *  @brief Templated predicate class which filters a target based on whether it
 *      possesses a given attribute
 */
template<const ATTRIBUTE_ID A>
class PredicateAttr : public PredicateBase
{
    public:

        /**
         *  @brief Constructor which configures the predicate to filter targets
         *      based on the existence of the attribute type given by the "A"
         *      template parameter, and the input criteria
         *
         *  @param[in] i_invertSearch
         *      Assuming the attribute is present, this determines what check
         *      needs to be performed on i_value.
         *      If false (default), the predicate registers a match when the
         *      target has attribute "A"; If true, the predicate registers
         *      a match when the target does NOT have attribute "A"
         */
        PredicateAttr(
            const bool i_invertSearch = false)
            : iv_invertSearch(i_invertSearch)
        {
        }

        /**
         *  @brief Destroys the attribute value predicate
         */
        virtual ~PredicateAttr()
        {
        }

        /**
         *  @brief Returns whether target has an attribute, given by template
         *      parameter "A"
         *
         *  @param[in] i_pTarget
         *      Target handle pointing to the target to compare to. Must
         *      not be nullptr.
         *
         *  @return bool indicating whether the target matches or not
         *          true if the target has attribute "A", false if not.
         *          Swap true/false if iv_invertSearch = true
         */
        virtual bool operator()(
            const Target* i_pTarget) const
        {
            typename AttributeTraits<A>::Type tmp; // not set intentionally
            bool l_match = i_pTarget->tryGetAttr<A>(tmp);
            return iv_invertSearch ? !l_match : l_match;
        }

    private:

        // Filter on whether the target possesses a given attribute (false)
        // or does not possess a given attribute (true)
        bool iv_invertSearch;

        /**
         *  @brief Disable copy/assignment operators
         */
        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateAttr);
};

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEATTR_H
