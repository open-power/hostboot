/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_cache_access_state.C $ */
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
/// @file  p9_query_cache_access_state.C
/// @brief Check the stop level for the EX caches and sets boolean scomable parameters
///
// *HWP HWP Owner: Christina Graves <clgraves@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS:SBE
///
///
///
/// @verbatim
/// High-level procedure flow:
///     - For the quad target, read the Stop State History register in the PPM
///       and use the actual stop level to determine if the quad has power and is being
///       clocked.
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_quad_scom_addresses.H>
#include <p9_query_cache_access_state.H>


// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

const uint32_t eq_clk_l2_pos[] = {8, 9};
const uint32_t eq_clk_l3_pos[] = {6, 7};
const uint32_t SSH_REG_STOP_LEVEL = 8;
const uint32_t SSH_REG_STOP_LEVEL_LEN = 4;
const uint32_t SSH_REG_STOP_GATED = 0;

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

fapi2::ReturnCode
p9_query_cache_access_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    bool o_l2_is_scomable[MAX_L2_PER_QUAD],
    bool o_l2_is_scannable[MAX_L2_PER_QUAD],
    bool o_l3_is_scomable[MAX_L3_PER_QUAD],
    bool o_l3_is_scannable[MAX_L3_PER_QUAD])
{
    fapi2::buffer<uint64_t> l_qsshsrc;
    uint32_t l_quadStopLevel = 0;
    fapi2::buffer<uint64_t> l_data64;
    uint8_t l_execution_platform = 0;
    uint32_t l_stop_state_reg = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_INF("> p9_query_cache_access_state...");

    //Get the stop state from the SSHRC in the EQPPM
    //First figure out whether we should use the C_PPM_SSHFSP (if FSP platform) or C_PPM_SSHHYP (if HOST platform)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXECUTION_PLATFORM, FAPI_SYSTEM, l_execution_platform),
             "Error: Failed to get platform");

    if (l_execution_platform == fapi2::ENUM_ATTR_EXECUTION_PLATFORM_FSP)
    {
        l_stop_state_reg =  EQ_PPM_SSHFSP;
    }
    else
    {
        l_stop_state_reg = EQ_PPM_SSHHYP;
    }

    FAPI_TRY(fapi2::getScom(i_target, l_stop_state_reg, l_qsshsrc), "Error reading data from QPPM SSHSRC");

    //A unit is scommable if clocks are running
    //A unit is scannable if the unit is powered up

    //Extract the quad stop state
    if (l_qsshsrc.getBit(SSH_REG_STOP_GATED))
    {
        l_qsshsrc.extractToRight<uint32_t>(l_quadStopLevel, SSH_REG_STOP_LEVEL, SSH_REG_STOP_LEVEL_LEN);
    }

    FAPI_DBG("EQ Stop State: EQ(%d)", l_quadStopLevel);

    //Set all attributes to 1, then clear them based on the clock state
    for (auto cnt = 0; cnt < MAX_L2_PER_QUAD; ++cnt)
    {
        o_l2_is_scomable[cnt] = 1;
        o_l2_is_scannable[cnt] = 1;
    }

    for (auto cnt = 0; cnt < MAX_L3_PER_QUAD; ++cnt)
    {
        o_l3_is_scomable[cnt] = 1;
        o_l3_is_scannable[cnt] = 1;
    }

    //Looking at the stop states is only valid if quad is stop gated -- else it is fully running
    if (l_qsshsrc.getBit(SSH_REG_STOP_GATED))
    {

        // STOP11
        // Both cores and cache are powered off
        if (l_quadStopLevel >= 11)
        {
            //Set all attributes to 0, because in stop 11 nad greater.. can't
            //access any quad chiplet and it's units
            for (auto cnt = 0; cnt < MAX_L2_PER_QUAD; ++cnt)
            {
                o_l2_is_scomable[cnt]  = 0;
                o_l2_is_scannable[cnt] = 0;
            }

            for (auto cnt = 0; cnt < MAX_L3_PER_QUAD; ++cnt)
            {
                o_l3_is_scomable[cnt]  = 0;
                o_l3_is_scannable[cnt] = 0;
            }
        }
        else
        {
            //Read clock status to confirm stop state history is accurate
            //If we trust the stop state history, this could be removed to save on code size
            //Compare Hardware status vs stop state status. If there is a mismatch the HW value overrides the stop state
            FAPI_TRY(p9_query_cache_clock_state(i_target, o_l2_is_scomable, o_l3_is_scomable), "Error querying clock state");
        }
    }
    else
    {
        //Read clock state if stop state history register doesn't have stop
        //gated info
        FAPI_TRY(p9_query_cache_clock_state(i_target, o_l2_is_scomable, o_l3_is_scomable), "Error querying clock state");
    }

fapi_try_exit:
    FAPI_INF("< p9_query_cache_access_state...");
    return fapi2::current_err;
}

fapi2::ReturnCode
p9_query_cache_clock_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    bool o_l2_is_scomable[MAX_L2_PER_QUAD],
    bool o_l3_is_scomable[MAX_L3_PER_QUAD])
{
    FAPI_INF("< p9_query_cache_clock_state...");
    fapi2::buffer<uint64_t> l_data64;
    //Read clock status to confirm stop state history is accurate
    //If we trust the stop state history, this could be removed to save on code size
    //Compare Hardware status vs stop state status. If there is a mismatch the HW value overrides the stop state

    FAPI_TRY(fapi2::getScom(i_target, EQ_CLOCK_STAT_SL, l_data64), "Error reading data from EQ_CLOCK_STAT_SL");

    // Need to look for both l20(ex0),l21(ex1) and l30,l31 bits info
    for (auto l_l2Pos = 0; l_l2Pos < MAX_L2_PER_QUAD; l_l2Pos++)
    {
        o_l2_is_scomable[l_l2Pos] = !l_data64.getBit(eq_clk_l2_pos[l_l2Pos]);
    }

    for (auto l_l3Pos = 0; l_l3Pos < MAX_L3_PER_QUAD; l_l3Pos++)
    {
        o_l3_is_scomable[l_l3Pos] = !l_data64.getBit(eq_clk_l3_pos[l_l3Pos]);
    }

fapi_try_exit:
    FAPI_INF("< p9_query_cache_clock_state...");
    return fapi2::current_err;

}
