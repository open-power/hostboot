/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/target.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <fapi2_target.H>
#include <target_types.H>


// HB platform support
#include <fapiPlatTrace.H>
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

namespace fapi2
{

///
/// @brief Assignment Operator.
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to assign from.
/// @return Reference to 'this' Target
///
template<TargetType K, typename V>
Target<K, V>& Target<K, V>::operator=(const Target& i_right)
{ iv_handle = i_right.iv_handle; return *this; }

///
/// @brief Equality Comparison Operator
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if equal.
/// @note Platforms need to define this so that the physical
/// targets are determined to be equivilent rather than just the handles
///
template<TargetType K, typename V>
bool Target<K, V>::operator==(const Target& i_right) const
{ return i_right.iv_handle == iv_handle; }

///
/// @brief Inquality Comparison Operator
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to compare.
/// @return bool. True if not equal.
/// @note Platforms need to define this so that the physical
/// targets are determined to be equivilent rather than just the handles
///
template<TargetType K, typename V>
bool Target<K, V>::operator!=(const Target& i_right) const
{ return i_right.iv_handle != iv_handle; }


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
        case fapi2::TARGET_TYPE_NV:
            o_targetingType = TARGETING::TYPE_NVBUS;
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
        default:
            FAPI_ERR("convertFapi2TypeToTargeting:: Chiplet type not supported 0x%.8X!", i_T);
            assert(false);
            break;
    }

    return o_targetingType;
}


///
/// @brief Get this target's immediate parent
/// @tparam T The desired type of the parent target
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @return Target<T> a target representing the parent
///
template<TargetType K, typename V>
template<TargetType T>
inline Target<T> Target<K, V>::getParent(void) const
{

    FAPI_DBG(ENTER_MRK "getParent. Type of parent 0x%08x", T);

    // General compound chiplet check for proc parent

    const fapi2::TargetType TARGET_TYPE_PROC_CHIPLETS = fapi2::TARGET_TYPE_EX |
            fapi2::TARGET_TYPE_MCS |
            fapi2::TARGET_TYPE_XBUS |
            fapi2::TARGET_TYPE_CORE |
            fapi2::TARGET_TYPE_EQ |
            fapi2::TARGET_TYPE_MCA |
            fapi2::TARGET_TYPE_MCBIST |
            fapi2::TARGET_TYPE_MI |
            fapi2::TARGET_TYPE_CAPP |
            fapi2::TARGET_TYPE_DMI |
            fapi2::TARGET_TYPE_OBUS |
            fapi2::TARGET_TYPE_NV |
            fapi2::TARGET_TYPE_SBE |
            fapi2::TARGET_TYPE_PPE |
            fapi2::TARGET_TYPE_PERV |
            fapi2::TARGET_TYPE_PEC |
            fapi2::TARGET_TYPE_PHB;

    static_assert( !((T == fapi2::TARGET_TYPE_PROC_CHIP) &&
                     ((K & TARGET_TYPE_PROC_CHIPLETS) == fapi2::TARGET_TYPE_NONE)),
                   "fapi2::TARGET_TYPE_PROC_CHIP is not a valid parent" );

    const fapi2::TargetType TARGET_TYPE_PERV_CHIPLETS = fapi2::TARGET_TYPE_EQ |
            fapi2::TARGET_TYPE_CORE |
            fapi2::TARGET_TYPE_XBUS |
            fapi2::TARGET_TYPE_OBUS |
            fapi2::TARGET_TYPE_CAPP |
            fapi2::TARGET_TYPE_NV |
            fapi2::TARGET_TYPE_MCBIST |
            fapi2::TARGET_TYPE_MCS |
            fapi2::TARGET_TYPE_MCA |
            fapi2::TARGET_TYPE_MI |
            fapi2::TARGET_TYPE_DMI |
            fapi2::TARGET_TYPE_PEC |
            fapi2::TARGET_TYPE_PHB;

    static_assert( !((T == fapi2::TARGET_TYPE_PERV) &&
                     ((K & TARGET_TYPE_PERV_CHIPLETS) == fapi2::TARGET_TYPE_NONE)),
                   "fapi2::TARGET_TYPE_PERV is not a valid parent" );

    // Specific parent checks for each TargetType

    // valid parents for DIMM
    // DIMM -> MCA
    // DIMM -> MBA
    static_assert(!((K == fapi2::TARGET_TYPE_DIMM) &&
                    (T != fapi2::TARGET_TYPE_MCA) &&
                    (T != fapi2::TARGET_TYPE_MBA)),
                  "improper parent of fapi2::TARGET_TYPE_DIMM");

    // valid parents for PROC
    // PROC -> SYSTEM
    static_assert(!((K == fapi2::TARGET_TYPE_PROC_CHIP) &&
                    (T != fapi2::TARGET_TYPE_SYSTEM)),
                  "improper parent of fapi2::TARGET_TYPE_PROC_CHIP");

    // valid parents for MEMBUF
    // MEMBUF -> SYSTEM
    // MEMBUF -> DMI
    static_assert(!((K == fapi2::TARGET_TYPE_MEMBUF_CHIP) &&
                    (T != fapi2::TARGET_TYPE_SYSTEM) &&
                    (T != fapi2::TARGET_TYPE_DMI)),
                  "improper parent of fapi2::TARGET_TYPE_MEMBUF_CHIP");

    // valid parents for EX
    // EX -> EQ
    // EX -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_EX) &&
                    (T != fapi2::TARGET_TYPE_EQ) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_EX");

    // valid parents for MBA
    // MBA -> MEMBUF
    static_assert(!((K == fapi2::TARGET_TYPE_MBA) &&
                    (T != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MBA");

    // valid parents for MCS
    // MCS -> MCBIST
    // MCS -> PERV
    // MCS -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_MCS) &&
                    (T != fapi2::TARGET_TYPE_MCBIST) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCS");

    // valid parents for L4
    // L4 -> MEMBUF
    static_assert(!((K == fapi2::TARGET_TYPE_L4) &&
                    (T != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_L4");

    // valid parents for CORE
    // CORE -> EX
    // CORE -> EQ
    // CORE -> PERV
    // CORE -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_CORE) &&
                    (T != fapi2::TARGET_TYPE_EX) &&
                    (T != fapi2::TARGET_TYPE_EQ) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_CORE");

    // valid parents for EQ
    // EQ -> PROC
    // EQ -> PERV
    static_assert(!((K == fapi2::TARGET_TYPE_EQ) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_EQ");

    // valid parents for MCA
    // MCA -> MCS
    // MCA -> MCBIST
    // MCA -> PERV
    // MCA -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_MCA) &&
                    (T != fapi2::TARGET_TYPE_MCS) &&
                    (T != fapi2::TARGET_TYPE_MCBIST) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCA");

    // valid parents for MCBIST
    // MCBIST -> PERV
    // MCBIST -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_MCBIST) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MCBIST");

    // valid parents for MI
    // MI -> PERV
    // MI -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_MI) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_MI");

    // valid parents for DMI
    // DMI -> MI
    // DMI -> PERV
    // DMI -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_DMI) &&
                    (T != fapi2::TARGET_TYPE_MI) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_DMI");

    // valid parents for SBE
    // SBE -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_SBE) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_SBE");

    // valid parents for PPE
    // PPE -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_PPE) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PPE");

    // valid parents for PERV
    // PERV -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PERV");

    // valid parents for PEC
    // PEC -> PERV
    // PEC -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_PEC) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PEC");

    // valid parents for PHB
    // PHB -> PERV
    // PHB -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_PHB) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_PHB");

    // valid parents for XBUS
    // XBUS -> PERV
    // XBUS -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_XBUS) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_XBUS");

    // valid parents for OBUS
    // OBUS -> PERV
    // OBUS -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_OBUS) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_OBUS");

    // valid parents for NV
    // NV -> PERV
    // NV -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_NV) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_NV");

    // valid parents for CAPP
    // CAPP -> PERV
    // CAPP -> PROC
    static_assert(!((K == fapi2::TARGET_TYPE_CAPP) &&
                    (T != fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP)),
                  "improper parent of fapi2::TARGET_TYPE_CAPP");



    TARGETING::TargetHandleList l_parentList;

    TARGETING::TYPE requiredPType = fapi2::convertFapi2TypeToTargeting(T);

    TARGETING::getParentAffinityTargetsByState(l_parentList,
                                    static_cast<TARGETING::Target*>(this->get()),
                                    TARGETING::CLASS_NA,
                                    requiredPType,
                                    TARGETING::UTIL_FILTER_ALL);

    assert(l_parentList.size() == 1, "Found %d parents of the same type. Target HUID %x , \
          looking for parents of type %x", l_parentList.size(), TARGETING::get_huid(this->get()) , requiredPType);

    TARGETING::Target * l_parentTarget = l_parentList[0];

    assert(l_parentTarget != NULL,
                "No parent of type %x was found for the target of type %x \
                Found required parent plat type to be %x", T, K, requiredPType)


    Target<T> outTarget(l_parentTarget);
    FAPI_DBG(EXIT_MRK "getParent");
    return outTarget;
}

///
/// @brief Get this target's children
/// @tparam T The desired type of child target
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_state The desired TargetState of the children
/// @return std::vector<Target<T> > a vector of present/functional
/// children
/// @warning The children of EX's (cores) are expected to be returned
/// in order. That is, core 0 is std::vector[0].
///
template<TargetType K, typename V>
template< TargetType T>
inline std::vector<Target<T> >
    Target<K, V>::getChildren(const TargetState i_state) const
{

FAPI_DBG(ENTER_MRK "getChildren. Type 0x%08x State:0x%08x", T, i_state);
#define INVALID_CHILD(PARENT, CHILD) \
    static_assert(!((K == PARENT) && (T == CHILD)), \
                  #CHILD " is not a child of " #PARENT );

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
    // PERV -> MI
    // PERV -> DMI
    static_assert(!((K == fapi2::TARGET_TYPE_PERV) &&
                    (T != fapi2::TARGET_TYPE_EQ) &&
                    (T != fapi2::TARGET_TYPE_CORE) &&
                    (T != fapi2::TARGET_TYPE_XBUS) &&
                    (T != fapi2::TARGET_TYPE_OBUS) &&
                    (T != fapi2::TARGET_TYPE_CAPP) &&
                    (T != fapi2::TARGET_TYPE_NV) &&
                    (T != fapi2::TARGET_TYPE_MCBIST) &&
                    (T != fapi2::TARGET_TYPE_MCS) &&
                    (T != fapi2::TARGET_TYPE_MCA) &&
                    (T != fapi2::TARGET_TYPE_PEC) &&
                    (T != fapi2::TARGET_TYPE_PHB) &&
                    (T != fapi2::TARGET_TYPE_MI) &&
                    (T != fapi2::TARGET_TYPE_DMI)),
                  "improper child of fapi2::TARGET_TYPE_PERV");

    // valid children for MEMBUF
    // MEMBUF -> L4
    // MEMBUF -> MBA
    static_assert(!((K == fapi2::TARGET_TYPE_MEMBUF_CHIP) &&
                    (T != fapi2::TARGET_TYPE_L4) &&
                    (T != fapi2::TARGET_TYPE_MBA)),
                  "improper child of fapi2::TARGET_TYPE_MEMBUF_CHIP");

    // valid children for system
    // SYSTEM -> PROC
    // SYSTEM -> MEMBUF
    // SYSTEM -> DIMM ??? disabled for now
    static_assert(!((K == fapi2::TARGET_TYPE_SYSTEM) &&
                    (T != fapi2::TARGET_TYPE_PROC_CHIP) &&
                    (T != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper child of fapi2::TARGET_TYPE_SYSTEM");

    // valid children for EQ
    // EQ -> CORE
    // EQ -> EX
    static_assert(!((K == fapi2::TARGET_TYPE_EQ) &&
                    (T != fapi2::TARGET_TYPE_CORE) &&
                    (T != fapi2::TARGET_TYPE_EX)),
                  "improper child of fapi2::TARGET_TYPE_EQ");

    // valid children for EX
    // EX -> CORE
    static_assert(!((K == fapi2::TARGET_TYPE_EX) &&
                    (T != fapi2::TARGET_TYPE_CORE)),
                  "improper child of fapi2::TARGET_TYPE_EX");

    // Nimbus Memory
    // valid children for MCS
    // MCS -> MCA
    static_assert(!((K == fapi2::TARGET_TYPE_MCS) &&
                    (T != fapi2::TARGET_TYPE_MCA)),
                  "improper child of fapi2::TARGET_TYPE_MCS");

    // valid children for MCA
    // MCA -> DIMM
    static_assert(!((K == fapi2::TARGET_TYPE_MCA) &&
                    (T != fapi2::TARGET_TYPE_DIMM)),
                  "improper child of fapi2::TARGET_TYPE_MCA");

    // valid children for MCBIST
    // MCBIST -> MCA
    // MCBIST -> MCS
    static_assert(!((K == fapi2::TARGET_TYPE_MCBIST) &&
                    (T != fapi2::TARGET_TYPE_MCA) &&
                    (T != fapi2::TARGET_TYPE_MCS)),
                  "improper child of fapi2::TARGET_TYPE_MCBIST");

    // Cumulus Memory
    // valid children for MI
    // MI -> DMI
    static_assert(!((K == fapi2::TARGET_TYPE_MI) &&
                    (T != fapi2::TARGET_TYPE_DMI)),
                  "improper child of fapi2::TARGET_TYPE_MI");

    // valid children for DMI
    // DMI -> MEMBUF
    static_assert(!((K == fapi2::TARGET_TYPE_DMI) &&
                    (T != fapi2::TARGET_TYPE_MEMBUF_CHIP)),
                  "improper child of fapi2::TARGET_TYPE_DMI");

    // valid children for MBA
    // MBA -> DIMM
    static_assert(!((K == fapi2::TARGET_TYPE_MBA) &&
                    (T != fapi2::TARGET_TYPE_DIMM)),
                  "improper child of fapi2::TARGET_TYPE_MBA");

    //Check that we are not calling this on a target with no children
    static_assert((K != fapi2::TARGET_TYPE_NONE),
                  "fapi2::TARGET_TYPE_NONE has no children");
    static_assert((K != fapi2::TARGET_TYPE_XBUS),
                  "fapi2::TARGET_TYPE_XBUS has no children");
    static_assert((K != fapi2::TARGET_TYPE_ABUS),
                  "fapi2::TARGET_TYPE_ABUS has no children");
    static_assert((K != fapi2::TARGET_TYPE_L4),
                  "fapi2::TARGET_TYPE_L4 has no children");
    static_assert((K != fapi2::TARGET_TYPE_CORE),
                  "fapi2::TARGET_TYPE_CORE has no children");
    static_assert((K != fapi2::TARGET_TYPE_CAPP),
                  "fapi2::TARGET_TYPE_CAPP has no children");
    static_assert((K != fapi2::TARGET_TYPE_OBUS),
                  "fapi2::TARGET_TYPE_OBUS has no children");
    static_assert((K != fapi2::TARGET_TYPE_NV),
                  "fapi2::TARGET_TYPE_NV has no children");
    static_assert((K != fapi2::TARGET_TYPE_SBE),
                  "fapi2::TARGET_TYPE_SBE has no children");
    static_assert((K != fapi2::TARGET_TYPE_PPE),
                  "fapi2::TARGET_TYPE_PPE has no children");
    static_assert((K != fapi2::TARGET_TYPE_PEC),
                  "fapi2::TARGET_TYPE_PEC has no children");
    static_assert((K != fapi2::TARGET_TYPE_PHB),
                  "fapi2::TARGET_TYPE_PHB has no children");


    std::vector<Target<T>> l_children;
    //Get the platform target type of the current fapi2::target
    TARGETING::TYPE l_type = fapi2::convertFapi2TypeToTargeting(T);
    TARGETING::TargetHandleList l_childList;
    bool l_functional = (i_state & fapi2::TARGET_STATE_FUNCTIONAL)? true:false;


    if(!l_functional)
    {
        TARGETING::getChildAffinityTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_ALL);
    }
    else
    {
        TARGETING::getChildAffinityTargetsByState(l_childList,
                          static_cast<TARGETING::Target*>(this->get()),
                          TARGETING::CLASS_NA,
                          l_type,
                          TARGETING::UTIL_FILTER_FUNCTIONAL);
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
        fapi2::Target<T> l_target(*chipletIter);
        l_children.push_back(l_target);
    }
    FAPI_DBG(EXIT_MRK "getChildren. %d results", l_children.size());

    return l_children;
}



///
/// @brief Get the target at the other end of a bus - dimm included
/// @tparam T The type of the parent
/// @tparam K The type of target of which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_state The desired TargetState of the children
/// @return Target<T> a target representing the thing on the other end
/// @note Can be easily changed to a vector if needed
///
template<TargetType K, typename V>
template<TargetType T>
inline Target<T>
Target<K, V>::getOtherEnd(const TargetState i_state) const
{
    //@TODO RTC:129517
    // Implementation note: cast to a composite of
    // bus types and the compiler will check if this is
    // a good function at compile time
    return Target<T>();
}


///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] i_target Target<T>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T >
inline void toString(const Target<T>& i_target, char* i_buffer, size_t i_bsize)
{
    snprintf(i_buffer, i_bsize, "Target 0x%lx/0x%x", i_target.get(), T);
}

///
/// @brief Return the string interpretation of this target
/// @tparam T The type of the target
/// @param[in] A pointer to the Target<T>
/// @param[in] i_buffer buffer to write in to
/// @param[in] i_bsize size of the buffer
/// @return void
/// @post The contents of the buffer is replaced with the string
/// representation of the target
///
template< TargetType T >
inline void toString(const Target<T>* i_target, char* i_buffer, size_t i_bsize)
{
    snprintf(i_buffer, i_bsize, "Target 0x%lx/0x%x", i_target->get(), T);
}

///
/// @brief Get an enumerated target of a specific type
/// @tparam T The type of the target
/// @param[in] Ordinal representing the ordinal number of
/// the desired target
/// @return Target<T> the target requested
///
template<TargetType T>
inline Target<T> getTarget(uint64_t Ordinal)
{
  //@TODO RTC:129517
    // For testing
    return Target<T>(Ordinal);
}

} // End namespace fapi2

#endif // End __FAPI2_TARGET__
