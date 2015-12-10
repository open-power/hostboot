/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/target.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
/// @param[in] i_right Reference to Target to assign from.
/// @return Reference to 'this' Target
///
template<TargetType K, typename V>
Target<K, V>& Target<K, V>::operator=(const Target& i_right)
{ iv_handle = i_right.iv_handle; return *this; }

///
/// @brief Equality Comparison Operator
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
            FAPI_ERR("Chiplet type not supported 0x%.8X!", i_T);
            break;
    }

    return o_targetingType;
}


///
/// @brief Get this target's immediate parent
/// @tparam T The desired type of the parent target
/// @return Target<T> a target representing the parent
///
template<TargetType K, typename V>
template<TargetType T>
inline Target<T> Target<K, V>::getParent(void) const
{
  //@TODO RTC:129517 fapi2 getParent
    // For testing
    return Target<T>(iv_handle);
}

///
/// @brief Get this target's children
/// @tparam T The desired type of child target
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
    std::vector<Target<T>> l_children;
    TARGETING::TYPE l_type = TARGETING::TYPE_NA;
    TARGETING::TargetHandleList l_chipletList;
    bool l_functional = (i_state & fapi2::TARGET_STATE_FUNCTIONAL)? true:false;

    FAPI_INF(ENTER_MRK "getChildren. Type 0x%08x State:0x%08x", T, i_state);

    switch (T)
    {
      //@TODO RTC:129517 to add the rest of the types
        case TARGET_TYPE_EX_CHIPLET: l_type = TARGETING::TYPE_EX; break;
        case TARGET_TYPE_MBA_CHIPLET: l_type = TARGETING::TYPE_MBA; break;
        case TARGET_TYPE_MCS_CHIPLET: l_type = TARGETING::TYPE_MCS; break;
        case TARGET_TYPE_XBUS_ENDPOINT: l_type = TARGETING::TYPE_XBUS; break;
        case TARGET_TYPE_ABUS_ENDPOINT: l_type = TARGETING::TYPE_ABUS; break;
        case TARGET_TYPE_L4: l_type = TARGETING::TYPE_L4; break;
        default:
             FAPI_ERR("getChildren: Chiplet type 0x%08x not supported 0x%08x",
                       T);
             assert(false);
            break;
    }

    TARGETING::getChildChiplets(l_chipletList,
                       static_cast<TARGETING::Target*>(this->get()),
                       l_type,
                       l_functional);

    FAPI_INF("getChildren: l_functional 0x%.8X, l_type = 0x%.8X, ChipUnitId 0x%.8X",
                l_functional, l_type, TARGETING::get_huid(this->get()));
    FAPI_INF("getChildren: l_chipletList size %d", l_chipletList.size());

    // Return fapi::Targets to the caller
    for (TARGETING::TargetHandleList::const_iterator
            chipletIter = l_chipletList.begin();
            chipletIter != l_chipletList.end();
            ++chipletIter)
    {
        TARGETING::HwasState l_state =
            (*chipletIter)->getAttr<TARGETING::ATTR_HWAS_STATE>();

        // HWPs/FAPI considers partial good chiplets as present, but
        // firmware considers them not-present. Return all chiplets
        // in the model when caller requests PRESENT
        if ((fapi2::TARGET_STATE_FUNCTIONAL == i_state) &&
            !l_state.functional)
        {
            continue;
        }
        fapi2::Target<T> l_target(*chipletIter);
        l_children.push_back(l_target);
    }
    FAPI_INF(EXIT_MRK "getChildren. %d results", l_children.size());

    return l_children;
}

///
/// @brief Get the target at the other end of a bus - dimm included
/// @tparam T The type of the parent
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
