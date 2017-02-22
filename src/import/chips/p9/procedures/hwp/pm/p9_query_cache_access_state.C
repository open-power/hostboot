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

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

fapi2::ReturnCode
p9_query_cache_access_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    bool& o_l2_is_scomable,
    bool& o_l2_is_scannable,
    bool& o_l3_is_scomable,
    bool& o_l3_is_scannable)
{
    fapi2::buffer<uint64_t> l_qsshsrc;
    uint32_t l_quadStopLevel = 0;
    fapi2::buffer<uint64_t> l_data64;
    bool l_is_scomable = 1;
    uint8_t l_chpltNumber = 0;
    uint32_t l_exPos = 0;
    uint8_t l_execution_platform = 0;
    uint32_t l_stop_state_reg = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_INF("> p9_query_cache_access_state...");

    //Get the stop state from the SSHRC in the EQPPM
    //First figure out whether we should use the C_PPM_SSHFSP (if FSP platform) or C_PPM_SSHHYP (if HOST platform)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXECUTION_PLATFORM, FAPI_SYSTEM, l_execution_platform),
             "Error: Failed to get platform");

    if (l_execution_platform == 0x02)
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

    //Extract the core stop state
    l_qsshsrc.extractToRight<uint32_t>(l_quadStopLevel, SSH_REG_STOP_LEVEL, SSH_REG_STOP_LEVEL_LEN);

    FAPI_DBG("EQ Stop State: EQ(%d)", l_quadStopLevel);

    //Set all attribtes to 1, then clear them based on the stop state
    o_l2_is_scomable = 1;
    o_l2_is_scannable = 1;
    o_l3_is_scomable = 1;
    o_l3_is_scannable = 1;

    // STOP8 - Half Quad Deep Sleep
    //   VSU, ISU are powered off
    //   IFU, LSU are powered off
    //   PC, Core EPS are powered off
    //   L20-EX0 is clocked off if both cores are >= 8
    //   L20-EX1 is clocked off if both cores are >= 8
    if (l_quadStopLevel >= 8)
    {
        o_l2_is_scomable = 0;
    }

    // STOP9 - Fast Winkle (lab use only)
    // Both cores and cache are clocked off
    if (l_quadStopLevel >= 9)
    {
        o_l3_is_scomable = 0;
    }

    // STOP11 - Deep Winkle
    // Both cores and cache are powered off
    if (l_quadStopLevel >= 11)
    {
        o_l2_is_scannable = 0;
        o_l3_is_scannable = 0;
    }

    //Read clock status to confirm stop state history is accurate
    //If we trust the stop state history, this could be removed to save on code size
    //Compare Hardware status vs stop state status. If there is a mismatch the HW value overrides the stop state

    FAPI_TRY(fapi2::getScom(i_target, EQ_CLOCK_STAT_SL, l_data64), "Error reading data from EQ_CLOCK_STAT_SL");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_chpltNumber),
             "Error: Failed to get the position of the EX:0x%08X", i_target);
    l_exPos = l_chpltNumber % 2;

    l_is_scomable = !l_data64.getBit(eq_clk_l2_pos[l_exPos]);

    if (o_l2_is_scomable != l_is_scomable)
    {
        FAPI_INF("Clock status didn't match stop state, overriding is_scomable status");
        o_l2_is_scomable = l_is_scomable;
    }

    l_is_scomable = !l_data64.getBit(eq_clk_l3_pos[l_exPos]);

    if (o_l3_is_scomable != l_is_scomable)
    {
        FAPI_INF("Clock status didn't match stop state, overriding is_scomable status");
        o_l3_is_scomable = l_is_scomable;
    }

fapi_try_exit:
    FAPI_INF("< p9_query_cache_access_state...");
    return fapi2::current_err;
}
