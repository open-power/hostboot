/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicatehwas.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#ifndef __TARGETING_COMMON_PREDICATEHWAS_H
#define __TARGETING_COMMON_PREDICATEHWAS_H

/**
 *  @file targeting/common/predicates/predicatehwas.H
 *
 *  @brief Interface for a predicate which fiters a target based on its HWAS
 *      state
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
#define TARG_CLASS "PredicateHWAS::"

class Target;

/**
 *  @brief Predicate class which filters a target based on its HWAS state
 */
class PredicateHwas : public PredicateBase
{
    public:

        /**
         *  @brief Create an HWAS state predicate
         */
        PredicateHwas();

        /**
         *  @brief Destroy an HWAS state predicate
         */
        virtual ~PredicateHwas();

        /**
         *  @brief Reset the predicate to match everything
         *
         *  @return Reference to the predicate, for chaining
         */
        PredicateHwas& reset();

        /**
         *  @brief Configure predicate to look for the given powered on state
         *
         *  @param[in] i_poweredOn Desired powered on state
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwas& poweredOn(bool i_poweredOn);

        /**
         *  @brief Configure predicate to look for the given present state
         *
         *  @param[in] i_present Desired present state
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwas& present(bool i_present);

        /**
         *  @brief Configure predicate to look for the given functional state
         *
         *  @param[in] i_functional Desired functional state
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwas& functional(bool i_functional);

        /**
         *  @brief Configure predicate to look for the given functional
         *         override state
         *
         *  @param[in] i_functionalOverride Desired functional override state
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwas& functionalOverride(bool i_functionalOverride);

        /**
         *  @brief Configure predicate to look for the given dump functional
         *         state
         *
         *  @param[in] i_dumpFunctional Desired dump functional state
         *
         *  @return Reference to the predicate, for chaining
         */
         PredicateHwas& dumpFunctional(bool i_dumpFunctional);

         /**
          *  @brief Configure predicate to look for the given speculative
          *         deconfig state
          *
          *  @param[in] i_specdeconfig Desired speculative deconfig state
          *
          *  @return Reference to the predicate, for chaining
          */
         PredicateHwas& specdeconfig(bool i_specdeconfig);

         /**
          *  @brief Configure predicate to look for the given deconfig by
          *         error log id or enum value
          *
          *  @param[in] i_eid Desired value of deconfig by EID
          *
          *  @return Reference to the predicate, for chaining
          */
         PredicateHwas& deconfiguredByEid(uint32_t i_eid);

        /**
         *  @brief Returns whether target matches the desired HWAS state
         *
         *  @par Detailed Description:
         *      Returns whether target matches the desired HWAS state.  Current
         *      HWAS sub-fields compared include poweredOn, present, functional
         *      and dumpFunctional.  On construction, the
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
         *  @brief Union that exposes raw value of an HWAS state attribute
         *      for purposes of bitwise comparison
         *
         *  @warning ATTR_HWAS_STATE size must be <= uint64_t in size, otherwise
         *      code cannot guarantee that the required bitfields fit.  This
         *      requirement is enforced by a compile-time assert
         */
        union hwasState
        {
            ATTR_HWAS_STATE_type attribute; // Attribute
            uint64_t             rawValue;  // Flattened representation

        };

        hwasState iv_desired; ///< Desired states
        hwasState iv_valid;   ///< Validity of each field

        TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateHwas);
};

//******************************************************************************
// PredicateHwas::PredicateHwas
//******************************************************************************

inline PredicateHwas::PredicateHwas()
{
    // Ignore reference
    reset();
}

//******************************************************************************
// PredicateHwas::poweredOn
//******************************************************************************

inline PredicateHwas& PredicateHwas::poweredOn(
    const bool i_poweredOn)
{
    iv_desired.attribute.poweredOn = i_poweredOn;
    iv_valid.attribute.poweredOn = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::present
//******************************************************************************

inline PredicateHwas& PredicateHwas::present(
    const bool i_present)
{
    iv_desired.attribute.present = i_present;
    iv_valid.attribute.present = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::functional
//******************************************************************************

inline PredicateHwas& PredicateHwas::functional(
    const bool i_functional)
{
    iv_desired.attribute.functional = i_functional;
    iv_valid.attribute.functional = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::functionalOverride
//******************************************************************************

inline PredicateHwas& PredicateHwas::functionalOverride(
    const bool i_functionalOverride)
{
    iv_desired.attribute.functionalOverride = i_functionalOverride;
    iv_valid.attribute.functionalOverride = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::dumpFunctional
//******************************************************************************

inline PredicateHwas& PredicateHwas::dumpFunctional(
    const bool i_dumpFunctional)
{
    iv_desired.attribute.dumpfunctional = i_dumpFunctional;
    iv_valid.attribute.dumpfunctional = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::specdeconfig
//******************************************************************************
inline PredicateHwas& PredicateHwas::specdeconfig(
    const bool i_specdeconfig)
{
    iv_desired.attribute.specdeconfig = i_specdeconfig;
    iv_valid.attribute.specdeconfig = true;
    return *this;
}

//******************************************************************************
// PredicateHwas::deconfiguredByEid
//******************************************************************************
inline PredicateHwas& PredicateHwas::deconfiguredByEid(
    const uint32_t i_eid)
{
    iv_desired.attribute.deconfiguredByEid = i_eid;
    iv_valid.attribute.deconfiguredByEid = 0xFFFFFFFF;
    return *this;
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_PREDICATEHWAS_H

