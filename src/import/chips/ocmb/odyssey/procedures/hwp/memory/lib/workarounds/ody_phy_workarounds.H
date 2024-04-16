/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_phy_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_phy_workarounds.H
/// @brief Workarounds for PHY related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ODY_PHY_WORKAROUNDS_H_
#define _MSS_ODY_PHY_WORKAROUNDS_H_

#include <fapi2.H>
#include <lib/shared/ody_consts.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>


namespace mss
{
namespace ody
{
namespace phy
{
namespace workarounds
{

///
/// @brief Clones data between redundant CS for tdqstracking
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_struct the structure to update
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode clone_redundant_cs_data_tdqstracking( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        user_input_advanced& io_struct );

///
/// @brief Clones data between redundant CS
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_array the array on which to operate with ranks indexed in the PHY rank perspective
/// @return FAPI2_RC_SUCCSS iff ok
///
template <typename T>
fapi2::ReturnCode clone_redundant_cs_data( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        T (&io_array)[mss::ody::MAX_RANK_PER_DIMM] )
{
    uint8_t l_redundant_cs[mss::ody::MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(mss::attr::get_ddr5_redundant_cs_en(i_target, l_redundant_cs));

    // If redundant CS is enabled, the PHY needs the same data cloned across two CS
    // CS0/1 need the same data as well as CS2/3 needing the same data
    if(l_redundant_cs[0] == fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE)
    {
        io_array[1] = io_array[0];
        io_array[3] = io_array[2];
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clones data between redundant CS for a multi-dimensional array
/// @tparam N the size of the 2D array on which to operate
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_array the array on which to operate with ranks indexed in the PHY rank perspective
/// @return FAPI2_RC_SUCCSS iff ok
///
template <uint32_t N>
fapi2::ReturnCode clone_redundant_cs_data( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        uint8_t (&io_array)[mss::ody::MAX_RANK_PER_DIMM][N] )
{
    uint8_t l_redundant_cs[mss::ody::MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(mss::attr::get_ddr5_redundant_cs_en(i_target, l_redundant_cs));

    // If redundant CS is enabled, the PHY needs the same data cloned across two CS
    // CS0/1 need the same data as well as CS2/3 needing the same data
    if(l_redundant_cs[0] == fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE)
    {
        for(uint32_t l_index = 0; l_index < N; ++l_index)
        {
            io_array[1][l_index] = io_array[0][l_index];
            io_array[3][l_index] = io_array[2][l_index];
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns phy
} // ns ody
} // ns mss

#endif
