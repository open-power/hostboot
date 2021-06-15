/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicateattrval.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#ifndef __TARGETING_COMMON_PREDICATEATTRVAL_H
#define __TARGETING_COMMON_PREDICATEATTRVAL_H

/**
 *  @file targeting/common/predicates/predicateattrval.H
 *
 *  @brief Interface and implementation for a predicate which filters a target
 *      based on whether it possesses a given attribute, and if so, the 
 *      attribute's value
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <string.h>

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
#define TARG_CLASS "PredicateAttrVal::"

class Target;

/**
 *  @brief Templated predicate class which filters a target based on whether it
 *      possesses a given attribute, and if so, the attribute's value
 */
template<const ATTRIBUTE_ID A>
class PredicateAttrVal : public PredicateBase
{
    public:

        /**
         *  @brief Constructor which configures the predicate to filter targets
         *      based on the existence of the attribute type given by the "A"
         *      template parameter, and the input criteria
         *
         *  @param[in] i_value
         *      Assuming the target being filtered has the attribute given by
         *      the "A" template parameter, the value of that attribute
         *      that will cause the predicate to register a match.  If the
         *      i_invertSearch parameter is the non-default value of true,
         *      the predicate registers a match when the value of the
         *      attribute != i_value
         *  @param[in] i_invertSearch
         *      Assuming the attribute is present, this determines what check
         *      needs to be performed on i_value.
         *      If false (default), the predicate registers a match when the
         *      attribute's value is i_value; If true, the predicate registers
         *      a match when the attribute's value is != i_value
         */
        PredicateAttrVal(
            const typename AttributeTraits<A>::Type& i_value,
            const bool i_invertSearch = false)
            : iv_invertSearch(i_invertSearch)
        {
            memcpy(&iv_value,&i_value,sizeof(iv_value));
        }

        /**
         *  @brief Destroys the attribute value predicate
         */
        virtual ~PredicateAttrVal()
        {
        }

        /**
         *  @brief Returns whether target has an attribute, given by template
         *      parameter "A", whose value matches the filter's configured
         *      criteria
         *
         *  @par Detailed Description:
         *      Returns whether target has an attribute, given by template
         *      parameter "A", whose value matches the filter's configured
         *      value.  Note that the target must have the "A" attribute,
         *      otherwise the predicate will always return false.
         *      Assuming the target has the "A" attribute, if the attribute's
         *      value matches and the search is not inverted, the predicate
         *      returns true.  If the attribute's value does not match but the
         *      search is inverted, the predicate also returns true.
         *      Otherwise, the predicate returns false.  See
         *      PredicateBase class for parameter/return description.
         *
         *  @param[in] i_pTarget
         *      Target handle pointing to the target to compare to.  Must
         *      not be NULL.
         *
         *  @return bool indicating whether the target matches or not
         */
        virtual bool operator()(
            const Target* i_pTarget) const
        {
            typename AttributeTraits<A>::Type actual; // not set intentionally
            bool l_match = i_pTarget->tryGetAttr<A>(actual);
            if(iv_invertSearch == true)
            {
                l_match = (l_match && !(iv_value == actual));
            }
            else
            {
                l_match = (l_match && (iv_value == actual));
            }
            return l_match;
        }

        /*
         * @brief Sets the attribute value contained in this class to the one passed in.
         *
         * @param[in]  i_value      The desired attribute value for this class to have.
         *
         * @return                  Reference to this predicate for chaining with other predicates.
         */
        inline PredicateAttrVal& value(const typename AttributeTraits<A>::Type& i_value)
        {
            memcpy(&iv_value,&i_value,sizeof(iv_value));
            return *this;
        }

    private:

        /**
         *  @brief Value of attribute to compare for each target filter is
         *      applied to
         */
        typename AttributeTraits<A>::Type iv_value;

        // Whether to look for attribute whose value matches iv_value (false) or
        // an attribute whose value does not match iv_value (true) for target
        // being filtered
        bool iv_invertSearch;

        /**
         *  @brief Disable copy/assignment operators
         */
        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateAttrVal);
};

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEATTRVAL_H
