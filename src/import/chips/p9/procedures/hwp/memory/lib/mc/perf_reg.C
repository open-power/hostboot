/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/perf_reg.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file perf_reg.C
/// @brief Subroutines to manipulate the memory controller performance registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mss_attribute_accessors.H>

#include <lib/mc/mc.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/dimm/kind.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

namespace mc
{

///
/// @brief Perform initializations of the MC performance registers
/// @note Some of these bits are taken care of in the scom initfiles
/// @param[in] i_target the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_perf2_register(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    // Get the values we need to put in the register
    uint64_t l_value;
    FAPI_TRY( calculate_perf2(i_target, l_value) );

    // Setup the registers
    FAPI_TRY( mss::getScom(i_target, MCS_0_PORT02_MCPERF2, l_data) );

    // Per S. Powell 7/16, setup these registers but don't enable the function yet. So enable bits are
    // intentionally not set
    l_data.insertFromRight<MCS_PORT02_MCPERF2_REFRESH_BLOCK_CONFIG,
                           MCS_PORT02_MCPERF2_REFRESH_BLOCK_CONFIG_LEN>(l_value);

    FAPI_TRY( mss::putScom(i_target, MCS_0_PORT02_MCPERF2, l_data) );

fapi_try_exit:
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculate the value of the MC perf2 register.
/// @param[in] i_target the target which has the MCA to map
/// @param[out] o_value the perf2 value for the MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode calculate_perf2(const fapi2::Target<TARGET_TYPE_MCA>& i_target, uint64_t& o_value)
{
    //
    // From Senor Powell 7/16
    // if (slots=1, masters=1)
    //   MCPERF2_Refresh_Block_Config=0b000
    // if (slots=1, masters=2)
    //   MCPERF2_Refresh_Block_Config=0b001
    // if (slots=1, masters=4)
    //  MCPERF2_Refresh_Block_Config=0b100
    // if (slots=2, masters=1)
    //  MCPERF2_Refresh_Block_Config=0b010
    // if (slots=2, masters=2)
    //  MCPERF2_Refresh_Block_Config=0b011
    // if (slots=2, masters=4)
    //  MCPERF2_Refresh_Block_Config=0b100
    //
    // if slot0 is 2 masters and slot1 is 1 master, just choose the 2 slot, 2 masters setting.
    // (i.e., choose the max(mranks_dimm1, mranks_dimm2)

    constexpr uint64_t l_refresh_values[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] =
    {
        {0b000, 0b001, 0, 0b100}, // Skip the ol' 3 rank DIMM
        {0b010, 0b011, 0, 0b100}
    };

    FAPI_INF("Calculating perf2 register for MCA%d (%d)", mss::pos(i_target), mss::index(i_target));

    // Find the DIMM on this port with the most master ranks.
    // That's how we know which element in the table to use.
    // uint8_t so I can use it to read from an attribute directly

    uint8_t l_mrank_index = 0;
    uint8_t l_master_ranks_zero = 0;
    uint8_t l_master_ranks_one = 0;

    fapi2::buffer<uint64_t> l_data;

    const auto l_dimm = mss::find_targets<TARGET_TYPE_DIMM>(i_target);
    const auto l_slot_index = l_dimm.size() - 1;

    switch(l_dimm.size())
    {
        // No DIMM, nothing to do
        case 0:
            return fapi2::FAPI2_RC_SUCCESS;
            break;

        // One DIMM, we've got the slots of fun
        case 1:
            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(l_dimm[0], l_mrank_index) );
            --l_mrank_index;
            FAPI_INF("1 DIMM mranks: D0[%d] index %d", l_mrank_index + 1, l_mrank_index);
            break;

        // Two DIMM, find the max of the master ranks
        case 2:
            {
                FAPI_TRY( mss::eff_num_master_ranks_per_dimm(l_dimm[0], l_master_ranks_zero) );
                FAPI_TRY( mss::eff_num_master_ranks_per_dimm(l_dimm[1], l_master_ranks_one) );

                l_mrank_index = std::max(l_master_ranks_zero, l_master_ranks_one) - 1;
                FAPI_INF("2 DIMM mranks: D0[%d] D1[%d] index %d", l_master_ranks_zero, l_master_ranks_one, l_mrank_index);
            }
            break;

        default:
            // We have a bug - no way to get more than 2 DIMM in a dual-drop system
            FAPI_ERR("seeing %d DIMM on %s", l_dimm.size(), mss::c_str(i_target));
            fapi2::Assert(false);
            break;
    };

    FAPI_INF("Refresh Block Config: %u ([%d][%d] populated slots: %d, max mranks: %d)",
             l_refresh_values[l_slot_index][l_mrank_index],
             l_slot_index, l_mrank_index,
             l_slot_index + 1, l_mrank_index + 1);

    o_value = l_refresh_values[l_slot_index][l_mrank_index];

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace

} // namespace

