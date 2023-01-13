/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_setup.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file p10_omi_setup.C
/// @brief Setup the OMI
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_omi_setup.H>
#include <lib/omi/p10_omi_utils.H>
#include <lib/fir/p10_fir.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <p10_io_omi_prbs.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <explorer_scom_addresses.H>
#include <p10_scom_omi.H>

///
/// @brief Setup OMI for P10
/// @param[in] i_target the OMIC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_omi_setup_explorer( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target )
{
    uint8_t l_sim = 0;
    uint8_t l_is_apollo = 0;

    mss::display_git_commit_info("p10_omi_setup");
    FAPI_INF("%s Start p10_omi_setup_explorer", mss::c_str(i_target));

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    // No-op in sim, we will just perform auto training in p10_omi_train.C
    if (l_sim)
    {
        FAPI_INF("Sim, exiting p10_omi_setup %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(mss::unmask::before_p10_omi_setup(mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target)));

    FAPI_TRY(mss::attr::get_is_apollo(l_is_apollo));


    FAPI_TRY(mss::omi::setup_mc_cmn_config(i_target));

    // Add 120ms delay before PRBS
    FAPI_TRY( fapi2::delay( 120 * mss::DELAY_1MS, 200) );

    // Terminate downstream PRBS23 pattern
    if (l_is_apollo == fapi2::ENUM_ATTR_MSS_IS_APOLLO_FALSE)
    {
        for (const auto& l_omi_target : i_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            FAPI_TRY(p10_io_omi_prbs(mss::find_target<fapi2::TARGET_TYPE_OMI>(l_omi_target), false));
        }
    }

    // Two OMI per OMIC
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        // One OCMB per OMI
        // We only need to set up host side registers if there is an OCMB on the other side,
        // otherwise, there's no need to train the link. So with no OCMB, we just skip
        // the below steps
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            FAPI_TRY(mss::omi::setup_mc_config1(l_omi));
            FAPI_TRY(mss::omi::setup_mc_cya_bits(l_omi));
            FAPI_TRY(mss::omi::setup_mc_error_action(l_omi));
            // No setup needed for rc_rmt_config, as we leave at default (0) value

            // Perform PRBS workarounds if needed
            FAPI_TRY(mss::omi::p10_omi_setup_prbs_helper(i_target, l_omi, l_ocmb));
        }
    }


fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Checks the ATTR_MFG_FLAGS for manufacturing mode
///
/// @param[out] o_mfg_mode Indicates if the manufacturing mode flag is set
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_omi_setup_get_mfg_mode(bool& o_mfg_mode)
{
    constexpr uint32_t MFG_FLAG = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;
    constexpr size_t CELL_SIZE = 32;
    const size_t l_index = MFG_FLAG / CELL_SIZE;
    const size_t l_flag_pos = MFG_FLAG % CELL_SIZE;

    uint32_t l_mfg_flags[4] = {};
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags));

    o_mfg_mode = (l_mfg_flags[l_index] & l_flag_pos) ? true : false;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup OMI for P10
/// @param[in] i_target the OMIC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_omi_setup_odyssey( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target )
{
    FAPI_INF("Start p10_omi_setup_odyssey");
    fapi2::buffer<uint64_t> l_val;
    bool l_mfg_mode = false;

    FAPI_TRY(p10_omi_setup_get_mfg_mode(l_mfg_mode));

    FAPI_TRY(scomt::omic::GET_CMN_CONFIG(i_target, l_val));
    scomt::omic::SET_CMN_CONFIG_MESO_BUFFER_ENABLE(1, l_val);
    scomt::omic::SET_CMN_CONFIG_MESO_BUFFER_START(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RX_EDGE_ENA(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RX_EDGE_MARGIN(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_SPARE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PSAV_STS_ENABLE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RECAL_TIMER(7, l_val); // 1600ms
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_1US_TMR(1600, l_val); // Number of cycles in 1us.
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_DBG_EN(0, l_val); // Enable the debug logic = 0
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_DBG_SEL(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RD_RST(1, l_val); // Reset the PMU counters when the PMU counters are read
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PRE_SCALAR(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_FREEZE(1, l_val); // the PMU will stop all counters when 1 of the counters wraps.
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PORT_SEL(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_PS(1, l_val); // ODD
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_ES(3, l_val); // 6_7
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_PS(1, l_val); // ODD
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_ES(0, l_val); // 0_1
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_PS(1, l_val); // ODD
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_ES(2, l_val); // 4_5
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_PS(0, l_val); // EVEN
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_ES(3, l_val); // 6_7
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_PE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_PE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_PE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_PE(0, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_EN(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_EN(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_EN(1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_EN(1, l_val);
    FAPI_TRY(scomt::omic::PUT_CMN_CONFIG(i_target, l_val));

    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        const auto& l_ocmbs = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL);

        if (l_ocmbs.empty())
        {
            continue;
        }

        FAPI_INF("Writing OMI CONFIG1");
        FAPI_TRY(scomt::omi::GET_CONFIG1(l_omi, l_val));
        scomt::omi::SET_CONFIG1_PREIPL_PRBS_TIME(0, l_val);
        scomt::omi::SET_CONFIG1_PREIPL_PRBS_ENA(0, l_val); // Disable
        scomt::omi::SET_CONFIG1_LANE_WIDTH(0, l_val);
        scomt::omi::SET_CONFIG1_B_HYSTERESIS(0, l_val);
        scomt::omi::SET_CONFIG1_A_HYSTERESIS(0, l_val);
        scomt::omi::SET_CONFIG1_B_PATTERN_LENGTH(0, l_val);
        scomt::omi::SET_CONFIG1_A_PATTERN_LENGTH(0, l_val);
        scomt::omi::SET_CONFIG1_TX_PERF_DEGRADED(1, l_val);
        scomt::omi::SET_CONFIG1_RX_PERF_DEGRADED(1, l_val);
        scomt::omi::SET_CONFIG1_TX_LANES_DISABLE(0, l_val);
        scomt::omi::SET_CONFIG1_RX_LANES_DISABLE(0, l_val);
        scomt::omi::SET_CONFIG1_RESET_ERR_HLD(0, l_val);
        scomt::omi::SET_CONFIG1_RESET_ERR_CAP(0, l_val);
        scomt::omi::SET_CONFIG1_RESET_TSHD_REG(0, l_val);
        scomt::omi::SET_CONFIG1_RESET_RMT_MSG(0, l_val);
        scomt::omi::SET_CONFIG1_INJECT_CRC_DIRECTION(0, l_val);
        scomt::omi::SET_CONFIG1_INJECT_CRC_RATE(0, l_val);
        scomt::omi::SET_CONFIG1_INJECT_CRC_LANE(0, l_val);
        scomt::omi::SET_CONFIG1_INJECT_CRC_ERROR(0, l_val);

        if (l_mfg_mode)
        {
            FAPI_INF("Setting OMI Manufacturing mode EDPL settings.");
            scomt::omi::SET_CONFIG1_EDPL_TIME(10, l_val); // 512s
            scomt::omi::SET_CONFIG1_EDPL_THRESHOLD(3, l_val); // 8 Errors
        }
        else
        {
            scomt::omi::SET_CONFIG1_EDPL_TIME(6, l_val); // 128mS
            scomt::omi::SET_CONFIG1_EDPL_THRESHOLD(7, l_val); // 128 Errors
        }

        scomt::omi::SET_CONFIG1_EDPL_ENA(1, l_val);
        FAPI_TRY(scomt::omi::PUT_CONFIG1(l_omi, l_val));


        FAPI_TRY(scomt::omi::GET_CYA_BITS(l_omi, l_val));
        scomt::omi::SET_CYA_BITS_FRBUF_FULL0(1, l_val);
        FAPI_TRY(scomt::omi::PUT_CYA_BITS(l_omi, l_val));

        FAPI_TRY(scomt::omi::PREP_ERROR_ACTION(l_omi));
        scomt::omi::SET_ERROR_ACTION_0_ACTION(1, l_val);
        FAPI_TRY(scomt::omi::PUT_ERROR_ACTION(l_omi, l_val));
    }


fapi_try_exit:
    FAPI_INF("End p10_omi_setup_odyssey");
    return fapi2::current_err;
}


fapi2::ReturnCode p10_omi_setup( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target )
{
    FAPI_INF("Starting p10_omi_setup");
    bool l_any_odyssey = false;
    uint8_t l_ocmb_type = fapi2::ENUM_ATTR_NAME_NONE;

    for (const auto& l_omi : i_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        for (const auto& l_ocmb_chip : l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, l_ocmb_chip, l_ocmb_type));
        }

        if (l_ocmb_type == fapi2::ENUM_ATTR_NAME_ODYSSEY)
        {
            l_any_odyssey = true;
            break;
        }
    }

    if (l_any_odyssey)
    {
        FAPI_TRY(p10_omi_setup_odyssey(i_target));
    }
    else // Explorer, Gemini
    {
        FAPI_TRY(p10_omi_setup_explorer(i_target));
    }

fapi_try_exit:
    FAPI_INF("Exiting p10_omi_setup");
    return fapi2::current_err;
}
