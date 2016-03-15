/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_utils_to_throttle.C $ */
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

///
/// @file p9_mss_utils_to_throttle.C
/// @brief Set the N throttle attributes for a given dram data bus utilization.
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>
#include <p9_mss_utils_to_throttle.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

extern "C"
{

///
/// @brief Sets number commands allowed within a given data bus utilization.
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_utils_to_throttle( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        uint8_t l_databus_util[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {0};
        uint32_t l_dram_clocks[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {0};
        uint32_t l_num_commands_allowed[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = 0;

        FAPI_TRY( mss::databus_util(i_target, &l_databus_util[0][0]) );
        FAPI_TRY( mss::mrw_mem_m_dram_clocks(fapi2::Target<TARGET_TYPE_SYSTEM>(), &l_dram_clocks[0][0]) );

        for( const auto& l_mca : i_target.getChildren<TARGET_TYPE_MCA>() )
        {
            l_port_num = mss::index(l_mca);

            for( const auto& l_dimm : i_target.getChildren<TARGET_TYPE_DIMM>() )
            {
                l_dimm_num = mss::index(l_dimm);

                l_num_commands_allowed = mss::commands_allowed_over_clock_window(l_databus_util[l_port_num][l_dimm_num],
                                         l_dram_clocks[l_port_num][l_dimm_num]);
            }
        }

        FAPI_ATTR_SET(fapi2::ATTR_MSS_THROTTLED_N_COMMANDS, i_target, l_num_commands_allowed)

        FAPI_INF("End utils_to_throttle");
    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
