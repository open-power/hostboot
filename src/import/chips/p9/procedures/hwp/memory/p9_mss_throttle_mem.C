/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_throttle_mem.C $ */
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
/// @file p9_mss_throttle_mem.C
/// @brief Write the runtime memory throttle settings from attributes to scom registers
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Cronus

#include <fapi2.H>
#include <p9_mss_throttle_mem.H>
#include <mss.H>
using fapi2::TARGET_TYPE_MCS;

extern "C"
{

///
/// @brief Write the runtime memory throttle settings from attributes to scom registers
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS iff ok
/// @note overwriting the safemem_throttle values
///
    fapi2::ReturnCode p9_mss_throttle_mem( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        FAPI_INF("Start throttle mem");

        for (const auto& l_mca : mss::find_targets<fapi2::TARGET_TYPE_MCA> (i_target))
        {
            uint32_t l_runtime_port = 0;
            uint32_t l_runtime_slot = 0;
            uint32_t l_throttle_denominator = 0;

            FAPI_TRY( mss::mem_m_dram_clocks( l_mca, l_throttle_denominator) );
            FAPI_TRY( mss::runtime_mem_throttled_n_commands_per_port(l_mca, l_runtime_port));
            FAPI_TRY( mss::runtime_mem_throttled_n_commands_per_slot(l_mca, l_runtime_slot));

            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY(mss::getScom(l_mca, MCA_MBA_FARB3Q, l_data));

            l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT, MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN>(l_runtime_slot);
            l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT, MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN>(l_runtime_port);

            FAPI_TRY( mss::putScom(l_mca, MCA_MBA_FARB3Q, l_data) );

        }

        FAPI_INF("End throttle mem");
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        FAPI_ERR("Couldn't finish mss_throttle_mem");
        return fapi2::current_err;
    }
} // extern "C"
