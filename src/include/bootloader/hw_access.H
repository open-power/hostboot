/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/hw_access.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file hw_access.H
///
/// @brief Hardware access functions that needs to be specialized for
/// platform implementation.
///

#ifndef _FAPI2_HWACCESS_H_
#define _FAPI2_HWACCESS_H_

#include <plat_hw_access.H>
#include <fapi2_hw_access.H>

namespace fapi2
{
//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

//The operational mode, or opMode is a thread local variable that allows the
//fapi2 interface to call getScom or putScom with special settings. Examples
//of their use cases are disabling the abiility for a scom to wakeup or core
//or ignore hardware errors. The opMode is reset on every FAPI_INVOKE call
//and is therefore reset each HWP.

/// @brief Sets the operational mode
/// @param[in]  i_mode     The new mode
// note: this can be moved  to a C file if desired
inline void setOpMode(const OpModes i_mode)
{
    return platSetOpMode(i_mode);
}

/// @brief Gets the operational mode
/// @return the operational mode
// note: this can be moved  to a C file if desired
inline OpModes getOpMode(void)
{
    return platGetOpMode();
}

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

///
/// @brief Platform-level implementation of getScom()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  SCOM register address to read from.
/// @param[out] o_data     Buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getScom(const Target<K, M, V>& i_target,
                          const uint64_t i_address,
                          buffer<uint64_t>& o_data)
{
    return platGetScom(i_target, i_address, o_data);
}

/// @brief Platform-level implementation of putScom()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScom(const Target<K, M, V>& i_target,
                          const uint64_t i_address,
                          const buffer<uint64_t> i_data)
{
    return platPutScom(i_target, i_address, i_data);
}

/// @brief Platform-level implementation of putScomUnderMask()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScomUnderMask(const Target<K, M, V>& i_target,
                                   const uint64_t i_address,
                                   const buffer<uint64_t> i_data,
                                   const buffer<uint64_t> i_mask)
{
    return platPutScomUnderMask(i_target, i_address, i_data, i_mask);
}

// -------------------------------------------------------------------------
// NOTE:
// No spy access in Hostboot Bootloader
// -------------------------------------------------------------------------

};

#endif // _FAPI2_HWACCESS_H_
