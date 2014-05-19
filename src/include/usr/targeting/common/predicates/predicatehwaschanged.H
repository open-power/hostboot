/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatehwaschanged.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __TARGETING_COMMON_PREDICATEHWASCHANGED_H
#define __TARGETING_COMMON_PREDICATEHWASCHANGED_H

/**
 *  @file targeting/common/predicates/predicatehwaschanged.H
 *
 *  @brief Interface for a predicate which fiters a target based on its HWAS
 *      changed flag
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
#define TARG_CLASS "PredicateHWASChanged::"

class Target;

/**
 *  @brief Predicate class which filters a target based on HWAS changed flag
 */
class PredicateHwasChanged : public PredicateBase
{
    public:

        /**
         *  @brief Create an HWAS changed flag predicate
         */
        PredicateHwasChanged();

        /**
         *  @brief Destroy an HWAS changed flag predicate
         */
        virtual ~PredicateHwasChanged();

        /**
         *  @brief Reset the predicate to match everything
         *
         *  @return Reference to the predicate, for chaining
         */
        PredicateHwasChanged& reset();

        /**
         *  @brief Configure predicate to look for the setting of a particular
         *      bit in the HWAS_CHANGED_STATE_FLAG
         *
         *  @param[in] i_bit        HWAS_CHANGED_BIT
         *  @param[in] i_changed    Desired changed setting of that bit
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwasChanged& changedBit(
                const HWAS_CHANGED_BIT i_bit, const bool i_changed);

        /**
         *  @brief Configure predicate to look for the particular state of
         *      bits in the HWAS_CHANGED_STATE_FLAG
         *
         *  @param[in] i_changed    Desired changed setting of all bits
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwasChanged& allChangesApplied(
                const bool i_changed);

        /**
         *  @brief Returns whether target matches the desired HWAS state
         *
         *  @par Detailed Description:
         *      Returns whether target matches the desired HWAS state.  Current
         *      HWAS sub-fields compared include poweredOn, present, functional,
         *      changedSinceLastIpl, and dumpFunctional.  On construction, the
         *      predicate matches any state of those fields.  To make the
         *      filter more restrictive, call any combination of the state
         *      configuration functions with the desired values.  The filter
         *      will make sure all the desired fields have requested values
         *      before returning a match.  To reset the filter to match all
         *      targets, call reset().  See PredicateBase class for
         *      parameter/return description.
         *
         *  @param[in] i_pTarget
         *      Target handle pointing to the target to compare to
         *
         *  @return bool indicating whether the target matches or not
         */
        virtual bool operator()(
            const Target* i_pTarget) const;

    private:

        /**
         *  @brief Union that exposes raw value of an HWAS changed flag
         *      for purposes of bitwise comparison
         *
         *  @warning ATTR_HWAS_STATE size must be <= uint64_t in size, otherwise
         *      code cannot guarantee that the required bitfields fit.  This
         *      requirement is enforced by a compile-time assert
         */
        union hwasStateChangedFlag
        {
            ATTR_HWAS_STATE_CHANGED_FLAG_type attribute; // Attribute
            uint64_t             rawValue;  // Flattened representation
        };

        hwasStateChangedFlag iv_desired; ///< Desired bits
        hwasStateChangedFlag iv_valid;   ///< mask of bits to check

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateHwasChanged);
};

//******************************************************************************
// PredicateHwasChanged::PredicateHwasChanged
//******************************************************************************

inline PredicateHwasChanged::PredicateHwasChanged()
{
    // Ignore reference
    reset();
}

//******************************************************************************
// PredicateHwasChanged::changedBit
//******************************************************************************

inline PredicateHwasChanged& PredicateHwasChanged::changedBit(
    const HWAS_CHANGED_BIT i_bit, const bool i_changed)
{
    if (i_changed)
    {
        iv_desired.rawValue |= i_bit; // turn bit on
    }
    else
    {
        iv_desired.rawValue &= ~i_bit; // turn bit off
    }
    iv_valid.rawValue  |= i_bit; // turn this bit on to check
    return *this;
}

//******************************************************************************
// PredicateHwasChanged::allChangesApplied
//******************************************************************************

inline PredicateHwasChanged& PredicateHwasChanged::allChangesApplied(
    const bool i_changed)
{
    if (i_changed)
    {
        iv_desired.rawValue = 0xFFFFFFFFFFFFFFFFull; // turn all bits on
    }
    else
    {
        iv_desired.rawValue = 0x0ull; // turn all bits off
    }
    iv_valid.rawValue  = 0xFFFFFFFFFFFFFFFFull; // turn all bits on to check
    return *this;
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEHWASCHANGED_H

