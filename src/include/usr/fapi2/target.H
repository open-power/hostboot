/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/target.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file target.H
///
/// @brief Defines the platform target functions that needs to be
/// specialized for platform implementation.
///
/**
 * @file target.H
 * @brief platform specializations for fapi2 targets
 */

#ifndef __FAPI2_TARGET__
#define __FAPI2_TARGET__

#include <plat_target.H>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <target_types.H>
#include <return_code_defs.H>
#include <fapi2_target.H>

#include <hwpf_fapi2_reasoncodes.H>


// HB platform support
#include <fapiPlatTrace.H>
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicateisfunctional.H>

//@TODO RTC:150675 get error info from getOtherEnd fails
//#include <errl/errlentry.H>
//#include <errl/errlmanager.H>



namespace PLAT_TARGET
{
///
/// @brief         Helper function for specialized system target allows
///                for the constructor to call targetservice::getTopLevel
/// @param[in/out] io_handle Reference to TARGETING::Target to assign
///                iv_handle to.
/// @return void
///
void systemTargCtorHelperFunc(fapi2::plat_target_handle_t& io_handle);
}

namespace fapi2
{


///
/// @brief         Specialization for TARGET_TYPE_SYSTEM targets
///                for the constructor to call targetservice::getTopLevel
/// @param[in/out] io_handle Reference to TARGETING::Target to assign
///                iv_handle to.
/// @return void
///
/// @note          the default templated constructor is delagated to constructors
///                take take in a plat_target_handle_t
///
template<>
inline Target<TARGET_TYPE_SYSTEM, plat_target_handle_t>
::Target(const plat_target_handle_t& v)
{
    PLAT_TARGET::systemTargCtorHelperFunc(iv_handle);
}

///
/// @brief Assignment Operator.
/// @tparam K The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to assign from.
/// @return Reference to 'this' Target
///
template<TargetType K, typename V>
Target<K, V>& Target<K, V>::operator=(const Target& i_right)
{ iv_handle = i_right.iv_handle; return *this; }

///
/// @brief Equality Comparison Operator
/// @tparam K The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if equal.
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, typename V>
bool Target<K, V>::operator==(const Target& i_right) const
{ return i_right.iv_handle == iv_handle; }

///
/// @brief Inquality Comparison Operator
/// @tparam K The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if not equal.
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, typename V>
bool Target<K, V>::operator!=(const Target& i_right) const
{ return i_right.iv_handle != iv_handle; }

///
/// @brief Less Than Comparison Operator
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if less than i_right
/// @note This platform uses handles for comparison as
/// target handles are statically defined so the order
/// is consistent.
///
template<TargetType K, typename V>
bool Target<K, V>::operator<(const Target& i_right) const
{
    return  iv_handle < i_right.iv_handle;
}

///
/// @brief This function takes in a FAPI2 Type and returns the corresponding
///         TARGETING::Target type
///
/// @param[in] i_fapi2Type
///
/// @returns TARGETTING::Type equivelent to fapi2 type
inline TARGETING::TYPE convertFapi2TypeToTargeting(fapi2::TargetType i_T)
{
    TARGETING::TYPE o_targetingType = TARGETING::TYPE_NA;

   switch (i_T)
    {
        case fapi2::TARGET_TYPE_NONE:
            o_targetingType = TARGETING::TYPE_NA;
            break;
        case fapi2::TARGET_TYPE_SYSTEM:
            o_targetingType = TARGETING::TYPE_SYS;
            break;
        case fapi2::TARGET_TYPE_DIMM:
            o_targetingType = TARGETING::TYPE_DIMM;
            break;
        case fapi2::TARGET_TYPE_PROC_CHIP:
            o_targetingType = TARGETING::TYPE_PROC;
            break;
        case fapi2::TARGET_TYPE_MEMBUF_CHIP:
            o_targetingType = TARGETING::TYPE_MEMBUF;
            break;
        case fapi2::TARGET_TYPE_EX:
            o_targetingType = TARGETING::TYPE_EX;
            break;
        case fapi2::TARGET_TYPE_MBA:
            o_targetingType = TARGETING::TYPE_MBA;
            break;
        case fapi2::TARGET_TYPE_MCS:
            o_targetingType = TARGETING::TYPE_MCS;
            break;
        case fapi2::TARGET_TYPE_XBUS:
            o_targetingType = TARGETING::TYPE_XBUS;
            break;
        case fapi2::TARGET_TYPE_ABUS:
            o_targetingType = TARGETING::TYPE_ABUS;
            break;
        case fapi2::TARGET_TYPE_L4:
            o_targetingType = TARGETING::TYPE_L4;
            break;
        case fapi2::TARGET_TYPE_CORE:
            o_targetingType = TARGETING::TYPE_CORE;
            break;
        case fapi2::TARGET_TYPE_EQ:
            o_targetingType = TARGETING::TYPE_EQ;
            break;
        case fapi2::TARGET_TYPE_MCA:
            o_targetingType = TARGETING::TYPE_MCA;
            break;
        case fapi2::TARGET_TYPE_MCBIST:
            o_targetingType = TARGETING::TYPE_MCBIST;
            break;
        case fapi2::TARGET_TYPE_MI:
            o_targetingType = TARGETING::TYPE_MI;
            break;
        case fapi2::TARGET_TYPE_CAPP:
            o_targetingType = TARGETING::TYPE_CAPP;
            break;
        case fapi2::TARGET_TYPE_DMI:
            o_targetingType = TARGETING::TYPE_DMI;
            break;
        case fapi2::TARGET_TYPE_OBUS:
            o_targetingType = TARGETING::TYPE_OBUS;
            break;
        case fapi2::TARGET_TYPE_OBUS_BRICK:
            o_targetingType = TARGETING::TYPE_OBUS_BRICK;
            break;
        case fapi2::TARGET_TYPE_SBE:
            o_targetingType = TARGETING::TYPE_SBE;
            break;
        case fapi2::TARGET_TYPE_PPE:
            o_targetingType = TARGETING::TYPE_PPE;
            break;
        case fapi2::TARGET_TYPE_PERV:
            o_targetingType = TARGETING::TYPE_PERV;
            break;
        case fapi2::TARGET_TYPE_PEC:
            o_targetingType = TARGETING::TYPE_PEC;
            break;
        case fapi2::TARGET_TYPE_PHB:
            o_targetingType = TARGETING::TYPE_PHB;
            break;
        case fapi2::TARGET_TYPE_MC:
            o_targetingType = TARGETING::TYPE_MC;
            break;
        default:
            FAPI_ERR("convertFapi2TypeToTargeting:: Chiplet type not supported 0x%.8X!", i_T);
            assert(false);
            break;
    }

    return o_targetingType;
}

///
/// @brief This function takes in a TARGETING Type and returns the corresponding
///         FAPI::Target type
///
/// @param[in] i_fapi2Type
///
/// @returns TARGETTING::Type equivelent to fapi2 type
inline fapi2::TargetType  convertTargetingTypeToFapi2(TARGETING::TYPE i_T)
{
    fapi2::TargetType o_targetingType = fapi2::TARGET_TYPE_NONE;

   switch (i_T)
    {
        case TARGETING::TYPE_NA:
            o_targetingType = fapi2::TARGET_TYPE_NONE;
            break;
        case TARGETING::TYPE_SYS:
            o_targetingType = fapi2::TARGET_TYPE_SYSTEM;
            break;
        case TARGETING::TYPE_DIMM:
            o_targetingType = fapi2::TARGET_TYPE_DIMM;
            break;
        case TARGETING::TYPE_PROC:
            o_targetingType = fapi2::TARGET_TYPE_PROC_CHIP;
            break;
        case TARGETING::TYPE_MEMBUF:
            o_targetingType = fapi2::TARGET_TYPE_MEMBUF_CHIP;
            break;
        case TARGETING::TYPE_EX:
            o_targetingType = fapi2::TARGET_TYPE_EX;
            break;
        case TARGETING::TYPE_MBA:
            o_targetingType = fapi2::TARGET_TYPE_MBA;
            break;
        case TARGETING::TYPE_MCS:
            o_targetingType = fapi2::TARGET_TYPE_MCS;
            break;
        case TARGETING::TYPE_XBUS:
            o_targetingType = fapi2::TARGET_TYPE_XBUS;
            break;
        case TARGETING::TYPE_ABUS:
            o_targetingType = fapi2::TARGET_TYPE_ABUS;
            break;
        case TARGETING::TYPE_L4:
            o_targetingType = fapi2::TARGET_TYPE_L4;
            break;
        case TARGETING::TYPE_CORE:
            o_targetingType = fapi2::TARGET_TYPE_CORE;
            break;
        case TARGETING::TYPE_EQ:
            o_targetingType = fapi2::TARGET_TYPE_EQ;
            break;
        case TARGETING::TYPE_MCA:
            o_targetingType = fapi2::TARGET_TYPE_MCA;
            break;
        case TARGETING::TYPE_MCBIST:
            o_targetingType = fapi2::TARGET_TYPE_MCBIST;
            break;
        case TARGETING::TYPE_MI:
            o_targetingType = fapi2::TARGET_TYPE_MI;
            break;
        case TARGETING::TYPE_CAPP:
            o_targetingType = fapi2::TARGET_TYPE_CAPP;
            break;
        case TARGETING::TYPE_DMI:
            o_targetingType = fapi2::TARGET_TYPE_DMI;
            break;
        case TARGETING::TYPE_OBUS:
            o_targetingType = fapi2::TARGET_TYPE_OBUS;
            break;
        case TARGETING::TYPE_OBUS_BRICK:
            o_targetingType = fapi2::TARGET_TYPE_OBUS_BRICK;
            break;
        case TARGETING::TYPE_SBE:
            o_targetingType = fapi2::TARGET_TYPE_SBE;
            break;
        case TARGETING::TYPE_PPE:
            o_targetingType = fapi2::TARGET_TYPE_PPE;
            break;
        case TARGETING::TYPE_PERV:
            o_targetingType = fapi2::TARGET_TYPE_PERV;
            break;
        case TARGETING::TYPE_PEC:
            o_targetingType = fapi2::TARGET_TYPE_PEC;
            break;
        case TARGETING::TYPE_PHB:
            o_targetingType = fapi2::TARGET_TYPE_PHB;
            break;
        case TARGETING::TYPE_MC:
            o_targetingType = fapi2::TARGET_TYPE_MC;
            break;
        default:
            o_targetingType = fapi2::TARGET_TYPE_NONE;
            break;
    }

    return o_targetingType;
}


///
/// @brief Get this target's immediate parent
/// @tparam T_SELF The type of target on which this is called
/// @tparam K_PARENT The desired type of the parent target
/// @tparam V the type of the target's Value
/// @return Target<T> a target representing the parent
///
template<TargetType T_SELF, typename V>
template<TargetType K_PARENT>
inline Target<K_PARENT, V> Target<T_SELF, V>::getParent(void) const
{

    FAPI_DBG(ENTER_MRK "getParent. Type of parent 0x%08x", K_PARENT);

    // General compound chiplet check for proc parent

    const fapi2::TargetType TARGET_TYPE_PROC_CHIPLETS = fapi2::TARGET_TYPE_EX |
            fapi2::TARGET_TYPE_MCS |
            fapi2::TARGET_TYPE_XBUS |
            fapi2::TARGET_TYPE_CORE |
            fapi2::TARGET_TYPE_EQ |
            fapi2::TARGET_TYPE_MCA |
            fapi2::TARGET_TYPE_MCBIST |
            fapi2::TARGET_TYPE_MC |
            fapi2::TARGET_TYPE_MI |
            fapi2::TARGET_TYPE_CAPP |
            fapi2::TARGET_TYPE_DMI |
            fapi2::TARGET_TYPE_OBUS |
            fapi2::TARGET_TYPE_OBUS_BRICK |
            fapi2::TARGET_TYPE_SBE |
            fapi2::TARGET_TYPE_PPE |
            fapi2::TARGET_TYPE_PERV |
            fapi2::TARGET_TYPE_PEC |
            fapi2::TARGET_TYPE_PHB;

    static_assert( !((K_PARENT == fapi2::TARGET_TYPE_PROC_CHIP) &&
        ((T_SELF & TARGET_TYPE_PROC_CHIPLETS) == fapi2::TARGET_TYPE_NONE)),
                   "fapi2::TARGET_TYPE_PROC_CHIP is not a valid parent" );

    const fapi2::TargetType TARGET_TYPE_PERV_CHIPLETS = fapi2::TARGET_TYPE_EQ |
            fapi2::TARGET_TYPE_CORE |
            fapi2::TARGET_TYPE_XBUS |
            fapi2::TARGET_TYPE_OBUS |
            fapi2::TARGET_TYPE_CAPP |
            fapi2::TARGET_TYPE_OBUS_BRICK |
            fapi2::TARGET_TYPE_MCBIST |
            fapi2::TARGET_TYPE_MCS |
            fapi2::TARGET_TYPE_MCA |
            fapi2::TARGET_TYPE_MI |
            fapi2::TARGET_TYPE_MC |
            fapi2::TARGET_TYPE_DMI |
            fapi2::TARGET_TYPE_PEC |
            fapi2::TARGET_TYPE_PHB;

    static_assert( !((K_PARENT == fapi2::TARGET_TYPE_PERV) &&
       ((T_SELF & TARGET_TYPE_PERV_CHIPLETS) == fapi2::TARGET_TYPE_NONE)),
                   "fapi2::TARGET_TYPE_PERV is not a valid parent" );

    // Specific parent checks for each TargetType

    // valid parents for DIMM
    // DIMM -> MCA
    // DIMM -> MBA
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_DIMM) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MCA) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MBA)),
                  "improper parent of fapi2::TARGET_TYPE_DIMM");

    // valid parents for PROC
    // PROC -> SYSTEM
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PROC_CHIP) &&
                    (K_PARENT != fapi2::TARGET_TYPE_SYSTEM)),
                  "improper parent of fapi2::TARGET_TYPE_PROC_CHIP");

    // valid parents for MEMBUF
    // MEMBUF -> SYSTEM
    // MEMBUF -> DMI
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MEMBUF_CHIP) &&
                    (K_PARENT != fapi2::TARGET_TYPE_SYSTEM) &&
                    (K_PARENT != fapi2::TARGET_TYPE_DMI)),
                  "improper parent of fapi2::TARGET_TYPE_MEMBUF_CHIP");

    // valid parents for EX
    // EX -> EQ
    // EX -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_EX) &&
                    (K_PARENT != fapi2::TARGET_TYPE_EQ) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_EX");

    // valid parents for MBA
    // MBA -> MEMBUF
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MBA) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MBA");

    // valid parents for MCS
    // MCS -> MCBIST
    // MCS -> PERV
    // MCS -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCS) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MCBIST) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCS");

    // valid parents for L4
    // L4 -> MEMBUF
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_L4) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_L4");

    // valid parents for CORE
    // CORE -> EX
    // CORE -> EQ
    // CORE -> PERV
    // CORE -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_CORE) &&
                    (K_PARENT != fapi2::TARGET_TYPE_EX) &&
                    (K_PARENT != fapi2::TARGET_TYPE_EQ) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_CORE");

    // valid parents for EQ
    // EQ -> PROC
    // EQ -> PERV
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_EQ) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_EQ");

    // valid parents for MCA
    // MCA -> MCS
    // MCA -> MCBIST
    // MCA -> PERV
    // MCA -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCA) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MCS) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MCBIST) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCA");

    // valid parents for MCBIST
    // MCBIST -> PERV
    // MCBIST -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCBIST) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCBIST");

    // valid parents for MC
    // MC -> PERV
    // MC -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MC) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MC");

    // valid parents for MI
    // MI -> MC
    // MI -> PERV
    // MI -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MI) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MC) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MI");

    // valid parents for DMI
    // DMI -> MI
    // DMI -> MC
    // DMI -> PERV
    // DMI -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_DMI) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MI) &&
                    (K_PARENT != fapi2::TARGET_TYPE_MC) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_DMI");

    // valid parents for SBE
    // SBE -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_SBE) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_SBE");

    // valid parents for PPE
    // PPE -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PPE) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PPE");

    // valid parents for PERV
    // PERV -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PERV");

    // valid parents for PEC
    // PEC -> PERV
    // PEC -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PEC) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PEC");

    // valid parents for PHB
    // PHB -> PERV
    // PHB -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PHB) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PHB");

    // valid parents for XBUS
    // XBUS -> PERV
    // XBUS -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_XBUS) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_XBUS");

    // valid parents for OBUS
    // OBUS -> PERV
    // OBUS -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_OBUS) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_OBUS");

    // valid parents for OBUS_BRICK
    // OBUS_BRICK -> PERV
    // OBUS_BRICK -> OBUS
    // OBUS_BRICK -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_OBUS_BRICK) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_OBUS) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_OBUS_BRICK");

    // valid parents for CAPP
    // CAPP -> PERV
    // CAPP -> PROC
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_CAPP) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PERV) &&
                    (K_PARENT != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_CAPP");



    TARGETING::TargetHandleList l_parentList;

    TARGETING::TYPE requiredPType =
      fapi2::convertFapi2TypeToTargeting(K_PARENT);

    if(K_PARENT == fapi2::TARGET_TYPE_PERV)
    {
        TARGETING::getParentPervasiveTargetsByState(
            l_parentList,
            static_cast<TARGETING::Target*>(this->get()),
            TARGETING::CLASS_NA,
            requiredPType,
            TARGETING::UTIL_FILTER_ALL);
    }
    else
    {
        TARGETING::getParentAffinityTargetsByState(
            l_parentList,
            static_cast<TARGETING::Target*>(this->get()),
            TARGETING::CLASS_NA,
            requiredPType,
            TARGETING::UTIL_FILTER_ALL);
    }

    assert(l_parentList.size() == 1, "Found %d parents of the same type. Target HUID %x ,\
          looking for parents of type %x", l_parentList.size(), TARGETING::get_huid(this->get()) , requiredPType);

    TARGETING::Target * l_parentTarget = l_parentList[0];

    assert(l_parentTarget != NULL,
           "No parent of type %x was found for the target of type %x, Found required parent plat type to be %x",
           K_PARENT, T_SELF, requiredPType)


    Target<K_PARENT> outTarget(l_parentTarget);
    FAPI_DBG(EXIT_MRK "getParent");
    return outTarget;
}

///
/// @brief Get this target's children
/// @tparam T_SELF The type of target on which this is called
/// @tparam K_CHILD The desired type of child target
/// @tparam V the type of the target's Value
/// @param[in] i_state The desired TargetState of the children
/// @return std::vector<Target<T> > a vector of present/functional
/// children
/// @warning The children of EX's (cores) are expected to be returned
/// in order. That is, core 0 is std::vector[0].
///
template<TargetType T_SELF, typename V>
template< TargetType K_CHILD>
inline std::vector<Target<K_CHILD, V> >
    Target<T_SELF, V>::getChildren(const TargetState i_state) const
{
    FAPI_DBG(ENTER_MRK "getChildren. Type 0x%08x State:0x%08x", K_CHILD, i_state);
#define INVALID_CHILD(_PARENT, _CHILD) \
    static_assert(!((T_SELF == _PARENT) && (K_CHILD == _CHILD)), \
                  #_CHILD " is not a child of " #_PARENT );

    // invalid children for proc
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_NONE)
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_SYSTEM)
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_DIMM)
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_PROC_CHIP)
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_MEMBUF_CHIP)
    INVALID_CHILD(fapi2::TARGET_TYPE_PROC_CHIP, fapi2::TARGET_TYPE_MBA)
#undef INVALID_CHILD

    // valid children for PERV
    // PERV -> EQ
    // PERV -> CORE
    // PERV -> XBUS
    // PERV -> OBUS
    // PERV -> CAPP
    // PERV -> NV
    // PERV -> MCBIST
    // PERV -> MCS
    // PERV -> MCA
    // PERV -> PEC
    // PERV -> PHB
    // PERV -> MC
    // PERV -> MI
    // PERV -> DMI
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_PERV) &&
                    (K_CHILD != fapi2::TARGET_TYPE_EQ) &&
                    (K_CHILD != fapi2::TARGET_TYPE_CORE) &&
                    (K_CHILD != fapi2::TARGET_TYPE_XBUS) &&
                    (K_CHILD != fapi2::TARGET_TYPE_OBUS) &&
                    (K_CHILD != fapi2::TARGET_TYPE_CAPP) &&
                    (K_CHILD != fapi2::TARGET_TYPE_OBUS_BRICK) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCBIST) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCS) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCA) &&
                    (K_CHILD != fapi2::TARGET_TYPE_PEC) &&
                    (K_CHILD != fapi2::TARGET_TYPE_PHB) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MC) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MI) &&
                    (K_CHILD != fapi2::TARGET_TYPE_DMI)),
                  "improper child of fapi2::TARGET_TYPE_PERV");

    // valid children for MEMBUF
    // MEMBUF -> L4
    // MEMBUF -> MBA
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MEMBUF_CHIP) &&
                    (K_CHILD != fapi2::TARGET_TYPE_L4) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MBA)),
                  "improper child of fapi2::TARGET_TYPE_MEMBUF_CHIP");

    // valid children for system
    // SYSTEM -> PROC
    // SYSTEM -> MEMBUF
    // SYSTEM -> DIMM ??? disabled for now
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_SYSTEM) &&
                    (K_CHILD != fapi2::TARGET_TYPE_PROC_CHIP) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper child of fapi2::TARGET_TYPE_SYSTEM");

    // valid children for EQ
    // EQ -> CORE
    // EQ -> EX
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_EQ) &&
                    (K_CHILD != fapi2::TARGET_TYPE_CORE) &&
                    (K_CHILD != fapi2::TARGET_TYPE_EX)),
                  "improper child of fapi2::TARGET_TYPE_EQ");

    // valid children for EX
    // EX -> CORE
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_EX) &&
                    (K_CHILD != fapi2::TARGET_TYPE_CORE)),
                  "improper child of fapi2::TARGET_TYPE_EX");

    // Nimbus Memory
    // valid children for MCS
    // MCS -> MCA
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCS) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCA)),
                  "improper child of fapi2::TARGET_TYPE_MCS");

    // valid children for MCA
    // MCA -> DIMM
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCA) &&
                    (K_CHILD != fapi2::TARGET_TYPE_DIMM)),
                  "improper child of fapi2::TARGET_TYPE_MCA");

    // valid children for MCBIST
    // MCBIST -> MCA
    // MCBIST -> MCS
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MCBIST) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCA) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MCS)),
                  "improper child of fapi2::TARGET_TYPE_MCBIST");

    // Cumulus Memory
    // valid children for MC
    // MC -> MI
    // MC -> DMI
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MC) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MI) &&
                    (K_CHILD != fapi2::TARGET_TYPE_DMI)),
                  "improper child of fapi2::TARGET_TYPE_MC");

    // valid children for MI
    // MI -> DMI
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MI) &&
                    (K_CHILD != fapi2::TARGET_TYPE_DMI)),
                  "improper child of fapi2::TARGET_TYPE_MI");

    // valid children for DMI
    // DMI -> MEMBUF
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_DMI) &&
                    (K_CHILD != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper child of fapi2::TARGET_TYPE_DMI");

    // valid children for MBA
    // MBA -> DIMM
    static_assert(!((T_SELF == fapi2::TARGET_TYPE_MBA) &&
                    (K_CHILD != fapi2::TARGET_TYPE_DIMM)),
                  "improper child of fapi2::TARGET_TYPE_MBA");

    //Check that we are not calling this on a target with no children
    static_assert((T_SELF != fapi2::TARGET_TYPE_NONE),
                  "fapi2::TARGET_TYPE_NONE has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_XBUS),
                  "fapi2::TARGET_TYPE_XBUS has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_ABUS),
                  "fapi2::TARGET_TYPE_ABUS has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_L4),
                  "fapi2::TARGET_TYPE_L4 has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_CORE),
                  "fapi2::TARGET_TYPE_CORE has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_CAPP),
                  "fapi2::TARGET_TYPE_CAPP has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_OBUS_BRICK),
                  "fapi2::TARGET_TYPE_OBUS_BRICK has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_SBE),
                  "fapi2::TARGET_TYPE_SBE has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_PPE),
                  "fapi2::TARGET_TYPE_PPE has no children");
    static_assert((T_SELF != fapi2::TARGET_TYPE_PHB),
                  "fapi2::TARGET_TYPE_PHB has no children");


    std::vector<Target<K_CHILD>> l_children;
    //Get the platform target type of the current fapi2::target
    TARGETING::TYPE l_type = fapi2::convertFapi2TypeToTargeting(K_CHILD);
    TARGETING::TargetHandleList l_childList;
    bool l_functional = (i_state & fapi2::TARGET_STATE_FUNCTIONAL)? true:false;

    if(!l_functional)
    {
        // PERV targets use a special interface
        if(T_SELF == fapi2::TARGET_TYPE_PERV)
        {
            TARGETING::getPervasiveChildTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_ALL);
        }
        // DIMMs need to use PRESENT so that we don't report things
        //  that aren't installed
        else if(K_CHILD == fapi2::TARGET_TYPE_DIMM)
        {
            TARGETING::getChildAffinityTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_PRESENT);
        }
        // All chiplets need to use ALL so that we report the architectural
        //  limits, versus what PG might say
        else
        {
            TARGETING::getChildAffinityTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_ALL);
        }
    }
    else
    {
        if(T_SELF == fapi2::TARGET_TYPE_PERV)
        {
            TARGETING::getPervasiveChildTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_FUNCTIONAL);
        }
        else
        {
             TARGETING::getChildAffinityTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_FUNCTIONAL);
        }
    }

    FAPI_DBG("getChildren: l_functional 0x%.8X, l_type = 0x%.8X, ChipUnitId 0x%.8X",
                l_functional, l_type, TARGETING::get_huid(this->get()));
    FAPI_DBG("getChildren: l_childList size %d", l_childList.size());

    // Return fapi2::Targets to the caller
    for (TARGETING::TargetHandleList::const_iterator
            chipletIter = l_childList.begin();
            chipletIter != l_childList.end();
            ++chipletIter)
    {
        fapi2::Target<K_CHILD> l_target(*chipletIter);
        l_children.push_back(l_target);
    }
    FAPI_DBG(EXIT_MRK "getChildren. %d results", l_children.size());

    return l_children;
}


///
/// @brief Get this target's children, filtered
/// @tparam T The type of the parent
/// @tparam T_SELF The type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_filter The desired chiplet filter
/// @param[in] i_state The desired TargetState of the children
/// @return std::vector<Target<T> > a vector of present/functional
/// children
///
template<TargetType T_SELF, typename V>
template< TargetType T>
inline std::vector<Target<T, V> >
    Target<T_SELF, V>::getChildren(const TargetFilter i_filter,
                              const TargetState i_state) const
{
    std::vector<Target<T>> l_children;

    l_children = this->getChildren<T>(i_state);

    FAPI_DBG("getChildrenFilter: Tgt=0x%.8X, i_filter=0x%.16X,"
             "T_SELF-Type=0x%.8X, T-Type=0x%.8X, sizeA=%d",
             TARGETING::get_huid(this->get()), i_filter,
             T_SELF, T, l_children.size());

    // Limit to getting Pervasive children from proc_chip parent for now
    //@TODO RTC:155755 to track possible additional support
    static_assert(((T == fapi2::TARGET_TYPE_PERV) &&
                   (T_SELF == fapi2::TARGET_TYPE_PROC_CHIP)),
                   "fapi2::getChildren-Filter only supports getting fapi2::TARGET_TYPE_PERV children on a fapi2::TARGET_TYPE_PROC_CHIP");

    for ( auto childIter =  l_children.begin();
               childIter != l_children.end();
               // ++childIter incremented below
        )
    {
        const TARGETING::Target * l_platTarget =
                         static_cast<const TARGETING::Target*>(childIter->get());
        uint8_t  l_chiplet_num = 0;
        uint32_t l_fapi2_type = childIter->getType();
        uint64_t l_bitMask = 0x0;

        // ATTR_CHIP_UNIT represents the Pervasive Chiplet numbering and is
        // needed to create the l_bitMask to use against i_filter
        if(!l_platTarget->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_chiplet_num))
        {
            FAPI_ERR("ERROR: getChildrenFilter: Can not read CHIP_UNIT attribute"
                     "Keeping Target 0x%lx for 0x%x", l_platTarget, T);
            l_bitMask = 0xFFFFFFFFFFFFFFFF;
        }
        else
        {
            l_bitMask = 0x8000000000000000 >> l_chiplet_num;
        }

        if (i_filter & l_bitMask) // keep child
        {
          FAPI_DBG("getChildrenFilter: keep child=0x%.8X, type=0x%.8X, l_bitMask=0x%.16X, num=0x%.2X",
                   TARGETING::get_huid(l_platTarget), l_fapi2_type, l_bitMask, l_chiplet_num );

          ++childIter;
        }
        else // remove child
        {
          childIter = l_children.erase(childIter); // this increments childIter

          FAPI_DBG("getChildrenFilter: removed child=0x%.8X, type=0x%.8X, l_bitMask=0x%.16X, num=0x%.2X",
                   TARGETING::get_huid(l_platTarget), l_fapi2_type, l_bitMask, l_chiplet_num );
        }
    }

    // Return filtered fapi2::Targets to the caller
    return l_children;
}

///
/// @brief Get the target at the other end of a bus
/// @tparam T The type of the target on the other end
/// @param[out] o_target A target representing the thing on the other end
/// @param[in] i_state The desired TargetState of the other end
/// @return FAPI2_RC_SUCCESS if OK, platforms will return a non-success
/// ReturnCode in the event of failure
/// @note o_target is only valid if return is FAPI2_RC_SUCCESS
///
template<TargetType T_SELF, typename V>
template<TargetType T>
inline fapi2::ReturnCodes
Target<T_SELF, V>::getOtherEnd(fapi2::Target<T, V>& o_target,
                          const TargetState i_state) const
{
    ReturnCodes l_rc;
//     errlHndl_t l_errl = NULL;
    TARGETING::TargetHandleList l_peerTargetList;
    TARGETING::CLASS targetClass = TARGETING::CLASS_NA;

    // Only supporting these relationships:
    //  XBUS <-> XBUS
    //  ABUS <-> ABUS
    //  OBUS <-> OBUS

    static_assert( T_SELF==T, "both ends must be of same fapi2::TARGET_TYPE");
    static_assert ( ( (T_SELF==fapi2::TARGET_TYPE_XBUS) ||
                      (T_SELF==fapi2::TARGET_TYPE_ABUS) ||
                      (T_SELF==fapi2::TARGET_TYPE_OBUS) ),
                    "Only types of XBUS, ABUS, and OBUS are supported");

    // for the supported types above, only one option supported
    targetClass = TARGETING::CLASS_UNIT;

    TARGETING::PredicateCTM l_peerFilter(targetClass,
                                         fapi2::convertFapi2TypeToTargeting(T));

    if(i_state == TARGET_STATE_FUNCTIONAL)
    {
        TARGETING::PredicateIsFunctional l_funcFilter;
        TARGETING::PredicatePostfixExpr l_funcAndpeerFilter;
        l_funcAndpeerFilter.push(&l_peerFilter).push(&l_funcFilter).And();
        getPeerTargets( l_peerTargetList,    // list of targets on other end
        static_cast<TARGETING::Target*>(this->get()),//To this target
        NULL/*&l_peerFilter*/, // Don't need to filter peers
        &l_funcAndpeerFilter);//filter results to be the right class & state
    }
    else if(i_state == TARGET_STATE_PRESENT)
    {
        TARGETING::PredicatePostfixExpr l_presAndpeerFilter;
        l_presAndpeerFilter.push(&l_peerFilter);

        getPeerTargets( l_peerTargetList,   // list of targets on other end
        static_cast<TARGETING::Target*>(this->get()), //to this target
        NULL,                               //No need to filter peers
        &l_presAndpeerFilter);//filter results to be the right class & state
    }

    fapi2::Target<T> fapi2_peerTarget = NULL;

    if(l_peerTargetList.size() == 0)
    {
        l_rc = FAPI2_RC_FALSE;
        //@TODO RTC:150675 get error info from getOtherEnd fails
#if 0
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_OTHER_END
        * @reasoncode         fapi2::RC_FOUND_NO_PEERS
        * @userdata1[0:31]    Unused
        * @userdata1[32:63]   Unused
        * @userdata2          Unused
        * @devdesc            Unable to resolve other end of xbus
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_PLAT_GET_OTHER_END,
                                      fapi2::RC_FOUND_NO_PEERS,
                                      NULL,
                                      NULL,
                                      true/*SW Error*/);
        errlCommit(l_errl,FAPI2_COMP_ID);
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
#endif
    }
    else if(l_peerTargetList.size() > 1)
    {
        l_rc = FAPI2_RC_FALSE;
        //@TODO RTC:150675 get error info from getOtherEnd fails
#if 0
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_OTHER_END
        * @reasoncode         fapi2::RC_FOUND_TOO_MANY_PEERS
        * @userdata1[0:31]    Unused
        * @userdata1[32:63]   Unused
        * @userdata2          Unused
        * @devdesc            Unable to resolve other end of xbus
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_PLAT_GET_OTHER_END,
                                      fapi2::RC_FOUND_TOO_MANY_PEERS,
                                      NULL,
                                      NULL,
                                      true/*SW Error*/);
        errlCommit(l_errl,FAPI2_COMP_ID);
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
#endif
    }
    else
    {
        l_rc = FAPI2_RC_SUCCESS;
        fapi2_peerTarget = fapi2::Target<T>(l_peerTargetList[0]);
    }
    o_target = fapi2_peerTarget;

    return l_rc;
}


///
/// @brief Determine whether the target is functional or not
/// @return true if the target is functional, false otherwise
///
template< TargetType T_SELF, typename V >
inline bool Target< T_SELF, V >::isFunctional(void) const
{
    TARGETING::PredicateIsFunctional l_functional;
    return l_functional(static_cast<TARGETING::Target*>(this->get()));
}


///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] i_target Target<T>
/// @param[in/out] io_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, typename V >
inline void toString(const Target<T, V>& i_target, char* io_buffer, size_t i_bsize)
{
    TARGETING::ATTR_FAPI_NAME_type l_nameString = {0};
    const TARGETING::Target * l_platTarget =
                          static_cast<const TARGETING::Target*>(i_target.get());

    if(!l_platTarget->tryGetAttr<TARGETING::ATTR_FAPI_NAME>(l_nameString))
    {
      FAPI_ERR("ERROR: Can not read FAPI_NAME attribute");
      snprintf(io_buffer, i_bsize, "Target 0x%lx/0x%x", l_platTarget, T);
    }
    else
    {
      size_t needed_buffer_size = strlen((const char*)l_nameString) + 1;

      // Is i_buffer large enough for the entire string + null
      if (i_bsize < needed_buffer_size)
      {
        FAPI_INF("Should use a larger buffer size (%d instead of %d) for %s",
                  needed_buffer_size, i_bsize, l_nameString);
        memcpy(io_buffer, l_nameString, i_bsize);
        if (i_bsize > 0)
        {
          io_buffer[i_bsize-1] = '\0';
        }
      }
      else
      {
        // copy full attribute string + null character
        memcpy(io_buffer, l_nameString, needed_buffer_size);
      }
    }
}

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] A pointer to the Target<T>
/// @param[in/out] io_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T, typename V >
inline void toString(const Target<T, V> *i_target, char* io_buffer, size_t i_bsize)
{
    toString(*i_target, io_buffer, i_bsize);
}
///
/// @brief Get a target from its Type and instance info
/// @tparam T The type of the target to return
/// @tparam V type of the targets value
/// @param[in] i_type   - Type of target to find
/// @param[in] instance - instance of the target to find
///
/// @return Target<T>* pointer to a target of type T
///
/// NOTE: Function caller owns the object returned.
///
#ifdef FAPI2_ENABLE_PLATFORM_GET_TARGET
template<TargetType T, typename V=fapi2::plat_target_handle_t>
inline Target<T,V>* getTarget(TargetType i_type, uint8_t instance)
{

    Target<T,V> * l_target = NULL;

    TARGETING::TYPE l_type = convertFapi2TypeToTargeting(i_type);

    // get a list of all the targets
    TARGETING::TargetService& l_targetService = TARGETING::targetService();
    TARGETING::TargetRangeFilter l_targets(l_targetService.begin(),
                                 l_targetService.end());

    // create a check for the desired target type
    TARGETING::PredicateCTM l_typePredicate;

    l_typePredicate.setType(l_type);

    // create a check for the FAPI_POS of a target
    TARGETING::PredicateAttrVal<TARGETING::ATTR_FAPI_POS>
                               l_fapiPosAttr(instance);

    TARGETING::PredicatePostfixExpr l_Query;

    // look for the type and instance
    l_Query.push(&l_typePredicate).push(&l_fapiPosAttr).And();

    l_targets.setPredicate(&l_Query);

    // reset l_targets to contain only the targets matching our predicates
    l_targets.reset();

    TARGETING::Target * l_t = NULL;

    uint32_t l_count = 0;
    for(; l_targets; ++l_targets, ++l_count)
    {
        l_t = *l_targets;
    }

    // we should not find more than one target
    assert(!(l_count > 1));

    if(l_count == 1)
    {
        l_target = new fapi2::Target<T,V>(l_t);
    }

    return l_target;

}
#endif
/// @tparam T The type of the target
/// @param[in] Ordinal representing the ordinal number of
/// the desired target
/// @return Target<T> the target requested
///
template<TargetType T, typename V>
inline Target<T, V> getTarget(uint64_t i_ordinal_id )
{
    uint16_t  l_fapi_pos = 0;
    TARGETING::Target * l_platTarget = nullptr;

    // get the top-level target
    TARGETING::Target * l_pSys;
    TARGETING::targetService().getTopLevelTarget(l_pSys);
    TARGETING::PredicateCTM l_tPred(TARGETING::CLASS_NA,
           fapi2::convertFapi2TypeToTargeting(T));

    // get a list of all targets of type T
    TARGETING::TargetHandleList l_TargetList;
    TARGETING::targetService().getAssociated( l_TargetList, l_pSys,
           TARGETING::TargetService::CHILD,
           TARGETING::TargetService::ALL,
           &l_tPred);

    if (!l_TargetList.empty())
    {
        FAPI_DBG("getTarget: Ordinal: %.8X", i_ordinal_id );

        // Iterate through all targets and find out matching
        // FAPI_POS target
        for( auto & l_target_elem : l_TargetList)
        {
            l_fapi_pos = l_target_elem->getAttr<TARGETING::ATTR_FAPI_POS>();
            if (l_fapi_pos == i_ordinal_id )
            {
                l_platTarget = l_target_elem;

                FAPI_DBG("getTarget() - FAPI_POS: (%.8X) HUID: (%.8X)",
                      l_fapi_pos,
                      TARGETING::get_huid(l_target_elem));
                break;
            }
        }
    }

    // Target list is empty or Target of Ordinal not Found
    if (l_platTarget == nullptr)
    {
        FAPI_ERR("getTarget(): empty TargetList of T or Target of Ordinal not Found");
        assert(false);
    }

    // Create a fapi2 target & return
    Target<T> l_fapi2_target(l_platTarget);
    return l_fapi2_target;
}

///
/// @brief Returns the chiplet number associated with the Target
/// @return The chiplet number for the Target. 0 is returned if the
/// Target does not have a chiplet number (for ex, the PROC_CHIP Target)
/// @note For logical targets such as the EX, the chiplet number of
/// their immediate parent chiplet is returned
///
template< TargetType T_SELF, typename V >
inline uint8_t Target< T_SELF, V >::getChipletNumber(void) const
{
    const TARGETING::Target * l_pTarget =
        static_cast<TARGETING::Target*>(this->get());
    uint8_t  l_chiplet_id = 0;
    if(!l_pTarget->tryGetAttr<TARGETING::ATTR_CHIPLET_ID>(l_chiplet_id))
    {
        FAPI_ERR("ERROR: getChipletNumber: Can not read CHIPLET_ID attribute");
    }
    return l_chiplet_id;
}

} // End namespace fapi2

#endif // End __FAPI2_TARGET__
