/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_secure_boot.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

///
/// @file p9c_mss_secure_boot.H
/// @brief  Sets up secure mode boot and checks that it is setup properly
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

#ifndef P9C_MSS_SECURE_BOOT
#define P9C_MSS_SECURE_BOOT

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------


#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_secure_boot_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

extern "C"
{

    ///
    /// @brief Enables secure mode boot
    /// @param[in]  i_target  Reference to target
    /// @return FAPI2_RC_SUCCESS iff successful
    /// @note Calls mss::c_str which is NOT thread safe unless the platform supports thread local storage...
    ///
    fapi2::ReturnCode p9c_mss_secure_boot( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target );

} // extern "C"

namespace mss
{

///
/// @brief Enables secure mode boot
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_secure_mode_boot( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target );

///
/// @brief Verifies secure mode boot is on
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode verify_secure_mode_boot_on( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target );

///
/// @brief Verifies secure mode boot is off
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode verify_secure_mode_boot_off( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target );
}

#endif /* P9C_MSS_SECURE_BOOT */
