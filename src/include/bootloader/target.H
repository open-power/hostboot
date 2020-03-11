/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/target.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#ifndef __FAPI2_TARGET_BOOTLOADER__
#define __FAPI2_TARGET_BOOTLOADER__

#include <plat_target.H>
#include <fapi2_target.H>

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
/// @note          the default templated constructor is delegated to
///                constructors take in a plat_target_handle_t
///
template<>
inline Target<TARGET_TYPE_SYSTEM, MULTICAST_OR, plat_target_handle_t>
::Target(const plat_target_handle_t& v)
{
    PLAT_TARGET::systemTargCtorHelperFunc(iv_handle);
}

///
/// @brief Apply any platform specific static assertions to target construction
/// @tparam K the type of target to be constructed
/// @tparam M the multicast type of the target to be constructed
/// @tparam V the value type of the target to be constructed
///
template<TargetType K, MulticastType M, typename V>
static constexpr void plat_apply_target_limits(void)
{
}

///
/// @brief Assignment Operator.
/// @tparam K The type of target on which this is called
/// @tparam M The multicast type of target on which this is called
/// @tparam V the type of the target's Value
/// @param[in] i_right Reference to Target to assign from.
/// @return Reference to 'this' Target
///
template<TargetType K, MulticastType M, typename V>
Target<K, M, V>& Target<K, M, V>::operator=(const Target& i_right)
{ iv_handle = i_right.iv_handle; return *this; }

} // End namespace fapi2


#endif // End __FAPI2_TARGET_BOOTLOADER__
