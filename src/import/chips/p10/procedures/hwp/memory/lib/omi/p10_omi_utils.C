/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/omi/p10_omi_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_omi_utils.C
/// @brief OMI utils for P10
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <p10_omi_utils.H>
#include <p10_scom_omi.H>
#include <p10_scom_omic.H>
#include <lib/shared/p10_consts.H>
#include <lib/workarounds/p10_omi_workarounds.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_log_utils.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <mss_p10_attribute_getters.H>
#include <explorer_scom_addresses.H>

namespace mss
{
namespace omi
{

/// @brief Function to setup the CMN_CONFIG
/// @param[in] i_target the TARGET_TYPE_OMIC to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_cmn_config(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    // Expected resulting register value: 0x921564008874630F
    fapi2::buffer<uint64_t> l_val;
    fapi2::ATTR_CHIP_EC_FEATURE_OMI_DD1_RECAL_TIMER_Type l_recal_timer_override = false;

    // Number of cycles in 1us. Number correct for 25.6, but will also be valid for 21.3
    constexpr uint64_t CFG_CMN_MESO_BUFFER_START_VAL = 1;
    constexpr uint64_t CFG_CMN_RX_EDGE_MARGIN_VAL = 1;
    constexpr uint64_t CFG_CMN_1US_TMR = 1600;
    constexpr uint8_t CFG_CMN_PORT_SEL = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DD1_RECAL_TIMER,
                           mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target),
                           l_recal_timer_override),
             "Failed reading ATTR_CHIP_EC_FEATURE_OMI_DD1_RECAL_TIMER");

    FAPI_TRY(scomt::omic::PREP_CMN_CONFIG(i_target));
    // MESO_BUFFER
    scomt::omic::SET_CMN_CONFIG_MESO_BUFFER_ENABLE(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_MESO_BUFFER_START(CFG_CMN_MESO_BUFFER_START_VAL, l_val);

    // CFG_CMN_RX_EDGE
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RX_EDGE_ENA(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RX_EDGE_MARGIN(CFG_CMN_RX_EDGE_MARGIN_VAL, l_val);


    // CFG_CMN_SPARE: Spare
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_SPARE(mss::states::OFF, l_val);

    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PSAV_STS_ENABLE(mss::states::OFF, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RECAL_TIMER(mss::omi::recal_timer::RECAL_TIMER_400MS, l_val);
    // Override to DD1 setting if needed
    mss::workarounds::omi::override_recal_timer(i_target, l_recal_timer_override, l_val);

    // CFG_CMN_1US_TMR: Number of cycles in 1us.
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_1US_TMR(CFG_CMN_1US_TMR, l_val);

    // CFG_CMN_DBG_EN: Enable the debug logic
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_DBG_EN(mss::states::OFF, l_val);

    // CFG_CMN_DBG_SEL: Debug select
    // 000 - zeros
    // 001 - DL0 trace information
    // 010 - DL1 trace information
    // 011 - DL2 trace information
    // 100 - trace information common macro 0
    // 101 - trace information common macro 2
    // 110 - 22 bits from common 0 plus
    // 11 bits from all 3 DLs plus
    // 33 bits from common macro 2
    // 111 - zeros
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_DBG_SEL(mss::omi::cfg_cmn_debug_select::CFG_CMN_DEBUG_NONE, l_val);

    // CFG_CMN_RD_RST: Reset the PMU counters when the PMU counters are read
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_RD_RST(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PRE_SCALAR(mss::omi::pmu_prescalar::PRESCALAR_16BIT, l_val);

    // CFG_CMN_FREEZE: PMU freeze mode - when set, the PMU will stop all counters when 1 of the counters wraps.
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_FREEZE(mss::states::ON, l_val);

    // CFG_CMN_PORT_SEL: PMU port select - select which of the 8 groups of inputs will be used by the PMU.
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_PORT_SEL(CFG_CMN_PORT_SEL, l_val);

    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_PS(mss::omi::cntrl_pair_selector::SEL_ODD, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_ES(mss::omi::cntrl_event_selector::SIG_6_7, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_PS(mss::omi::cntrl_pair_selector::SEL_ODD, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_ES(mss::omi::cntrl_event_selector::SIG_0_1, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_PS(mss::omi::cntrl_pair_selector::SEL_ODD, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_ES(mss::omi::cntrl_event_selector::SIG_4_5, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_PS(mss::omi::cntrl_pair_selector::SEL_EVEN, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_ES(mss::omi::cntrl_event_selector::SIG_6_7, l_val);

    // CFG_CMN_CNTRx_PE: PMU cntrx positive edge select
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_PE(mss::states::OFF, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_PE(mss::states::OFF, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_PE(mss::states::OFF, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_PE(mss::states::OFF, l_val);

    // CFG_CMN_CNTRx_EN: PMU cntrx enable
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR3_EN(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR2_EN(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR1_EN(mss::states::ON, l_val);
    scomt::omic::SET_CMN_CONFIG_CFG_CMN_CNTR0_EN(mss::states::ON, l_val);

    FAPI_TRY(scomt::omic::PUT_CMN_CONFIG(i_target, l_val));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the CONFIG0 for the given train mode and backoff_en bit
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_train_mode training step to enable
/// @param[in] i_dl_x4_backoff_en backoff enable mode
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en)
{
    uint8_t l_sim = 0;

    // Expected resulting register value: 0x8200040000152824
    fapi2::buffer<uint64_t> l_val;

    // Maximum number of credits that can be sent to the TL
    constexpr uint64_t CFG0_CFG_TL_CREDITS = 18;
    constexpr uint64_t CONFIG0_VERSION = 9;
    constexpr uint64_t REPLAY_RSVD_ENTRIES = 0;

    // Certain values needed for VBU, key off sim
    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    FAPI_TRY(scomt::omi::PREP_CONFIG0(i_target));

    // CFG_DL0_ENABLE: dl0 enabled
    scomt::omi::SET_CONFIG0_ENABLE(mss::states::ON, l_val);

    // CFG_DL0_CFG_SPARE: dl0 Spare
    scomt::omi::SET_CONFIG0_CFG_SPARE(mss::states::OFF, l_val);

    // CFG_DL0_CFG_TL_CREDITS: dl0 TL credits - Maximum number of credits that can be sent to the TL
    scomt::omi::SET_CONFIG0_CFG_TL_CREDITS(CFG0_CFG_TL_CREDITS, l_val);

    // CFG_DL0_TL_EVENT_ACTIONS: dl0 TL event actions
    // Bit 0 = Freeze all
    // Bit 1 = Freeze afu, leave TL and DL running
    // Bit 2 = Trigger Internal Logic Analyzers
    // Bit 3 = Bring down the link
    scomt::omi::SET_CONFIG0_TL_EVENT_ACTIONS(mss::omi::tl_error_event_actions::ERROR_EVENT_NONE, l_val);

    // CFG_DL0_TL_ERROR_ACTIONS: dl0 TL error actions
    // Bit 0 = Freeze all
    // Bit 1 = Freeze afu, leave TL and DL running
    // Bit 2 = Trigger Internal Logic Analyzers
    // Bit 3 = Bring down the link
    scomt::omi::SET_CONFIG0_TL_ERROR_ACTIONS(mss::omi::tl_error_event_actions::ERROR_EVENT_NONE, l_val);

    scomt::omi::SET_CONFIG0_FWD_PROGRESS_TIMER(mss::omi::no_forward_progress_timer::NO_FORWARD_TIMER_16US, l_val);

    // CFG_DL0_REPLAY_RSVD_ENTRIES: dl0 replay buffers reserved - times 16 is the number of replay buffers reserved
    scomt::omi::SET_CONFIG0_REPLAY_RSVD_ENTRIES(REPLAY_RSVD_ENTRIES, l_val);

    // CFG_DL0_DEBUG_SELECT: dl0 trace mux select
    // "000" = zeros
    // "001" = RX information
    // "010" = TX flit information
    // "011" = Tx training information
    // "100" = 11 bits of RX information
    // "101" = 11 bits of TX flit information
    // "110" = 11 bits of Tx training information
    scomt::omi::SET_CONFIG0_DEBUG_SELECT(mss::omi::config0_debug_select::CFG0_DEBUG_NONE, l_val);

    // CFG_DL0_DEBUG_ENABLE: dl0 trace enable
    scomt::omi::SET_CONFIG0_DEBUG_ENABLE(mss::states::OFF, l_val);

    // CFG_DL0_DL2TL_DATA_PARITY_INJECT: dl0 inject a data parity error
    scomt::omi::SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(mss::states::OFF, l_val);

    // CFG_DL0_DL2TL_CONTROL_PARITY_INJECT: dl0 inject a control parity error
    scomt::omi::SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(mss::states::OFF, l_val);

    // CFG_DL0_ECC_UE_INJECTION: dl0 inject a ECC UE error
    scomt::omi::SET_CONFIG0_ECC_UE_INJECTION(mss::states::OFF, l_val);

    // CFG_DL0_ECC_CE_INJECTION: dl0 inject a ECC CE erro
    scomt::omi::SET_CONFIG0_ECC_CE_INJECTION(mss::states::OFF, l_val);

    // CFG_DL0_FP_DISABLE: dl0 fastpath disabled
    scomt::omi::SET_CONFIG0_FP_DISABLE(mss::states::OFF, l_val);

    // CFG_DL0_TX_LN_REV_ENA: When set will allow dl0 to perform tx lane reversals.
    scomt::omi::SET_CONFIG0_TX_LN_REV_ENA(mss::states::ON, l_val);

    // CFG_DL0_128_130_ENCODING_ENABLED: dl0 128/130 encoding enabled
    scomt::omi::SET_CONFIG0_128_130_ENCODING_ENABLED(mss::states::OFF, l_val);

    // Should "ideally" be 5us, but real-world tests lead us to 60ms in P10
    // P10 is expected to operate the same, so this value should be ok
    scomt::omi::SET_CONFIG0_PHY_CNTR_LIMIT(
        l_sim ? mss::omi::phy_ctr_mode::PHY_CTR_MODE_50US :
        mss::omi::phy_ctr_mode::PHY_CTR_MODE_60MS,
        l_val);

    // CFG_DL0_RUNLANE_OVRD_ENABLE: When enabled, the dl0 will drive run lane to the PHY for all training states.
    scomt::omi::SET_CONFIG0_RUNLANE_OVRD_ENABLE(mss::states::OFF, l_val);

    // CFG_DL0_PWRMGT_ENABLE: dl0 power management enabled
    scomt::omi::SET_CONFIG0_PWRMGT_ENABLE(mss::states::OFF, l_val);

    // CFG_DL0_QUARTER_WIDTH_BACKOFF_ENABLE: dl0 x1 backoff enabled
    scomt::omi::SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(mss::states::OFF, l_val);

    // CFG_DL0_HALF_WIDTH_BACKOFF_ENABLE: dl0 x4 backoff enabled
    scomt::omi::SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(i_dl_x4_backoff_en, l_val);

    // CFG_DL0_SUPPORTED_MODES x8 and X4
    scomt::omi::SET_CONFIG0_SUPPORTED_MODES(mss::omi::link_widths::LINK_WIDTHS_X8X4, l_val);

    // CFG_DL0_TRAIN_MODE: dl0 train mode
    scomt::omi::SET_CONFIG0_TRAIN_MODE(i_train_mode, l_val);

    // CFG_DL0_VERSION: dl0 version number
    scomt::omi::SET_CONFIG0_VERSION(CONFIG0_VERSION, l_val);

    // CFG_DL0_RETRAIN: dl0 retrain - Reset dl0 back to training state 4
    scomt::omi::SET_CONFIG0_RETRAIN(mss::states::OFF, l_val);

    // CFG_DL0_RESET: dl0 reset - Reset dl0 back to traning state 0
    scomt::omi::SET_CONFIG0_RESET(mss::states::OFF, l_val);

    FAPI_DBG("Writing CONFIG0 0x%016llx", l_val());
    FAPI_TRY(scomt::omi::PUT_CONFIG0(i_target, l_val));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to setup the CONFIG1
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_config1(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    // Expected resulting register value: 0x0C00050000000059
    fapi2::buffer<uint64_t> l_val;

    constexpr uint64_t INJECT_CRC_LANE = 0;

    uint8_t l_sim = 0;
    uint8_t l_edpl_disable = 0;
    bool l_mnfg_screen_test = false;
    fapi2::ATTR_MSS_MNFG_EDPL_TIME_Type l_mnfg_edpl_time = 0;
    fapi2::ATTR_MSS_MNFG_EDPL_THRESHOLD_Type l_mnfg_edpl_threshold = 0;

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));
    FAPI_TRY(mss::attr::get_mss_omi_edpl_disable(l_edpl_disable));
    FAPI_TRY(mss::check_mfg_flag(mss::p10::MNFG_OMI_CRC_EDPL_SCREEN, l_mnfg_screen_test));
    FAPI_TRY(mss::attr::get_mnfg_edpl_time(l_mnfg_edpl_time));
    FAPI_TRY(mss::attr::get_mnfg_edpl_threshold(l_mnfg_edpl_threshold));

    FAPI_TRY(scomt::omi::PREP_CONFIG1(i_target));

    // CFG_DL0_CFG1_PREIPL_PRBS
    scomt::omi::SET_CONFIG1_PREIPL_PRBS_TIME(
        l_sim ? mss::omi::preipl_prbs_time::PREIPL_PRBS_1US : mss::omi::preipl_prbs_time::PREIPL_PRBS_256MS, l_val);

    // PRE-IPL PRBS Timing is not functional in P10, so set to disable
    scomt::omi::SET_CONFIG1_PREIPL_PRBS_ENA(mss::states::OFF, l_val); // Disable

    scomt::omi::SET_CONFIG1_LANE_WIDTH(mss::omi::lan_width_override::TL_CTR_BY_SIDEBAND, l_val);
    scomt::omi::SET_CONFIG1_B_HYSTERESIS(mss::omi::b_hysteresis::B_HYSTERESIS_16, l_val);
    scomt::omi::SET_CONFIG1_A_HYSTERESIS(mss::omi::a_hysteresis::A_HYSTERESIS_16, l_val);

    // CFG_DL0_B_PATTERN_LENGTH: Number of consecutive 1s and 0s needed to represent training Pattern
    // B=> "11111111111111110000000000000000"
    // "00" = two Xs => "11111111111111XX00000000000000XX"
    // "10" = four Xs => "111111111111XXXX000000000000XXXX"
    // "01" = one Xs => "111111111111111X000000000000000X"
    // "11" = same as "10"
    scomt::omi::SET_CONFIG1_B_PATTERN_LENGTH(mss::omi::pattern_length::TWO_Xs, l_val);

    // CFG_DL0_A_PATTERN_LENGTH: Number of consecutive 1s and 0s needed to represent training Pattern
    // A => "1111111100000000"
    // "00" = two Xs => "111111XX000000XX"
    // "10" = four Xs => "1111XXXX0000XXXX"
    // "01" = one Xs => "1111111X0000000X"
    // "11" = same as "10"
    scomt::omi::SET_CONFIG1_A_PATTERN_LENGTH(mss::omi::pattern_length::TWO_Xs, l_val);

    // CFG_DL0_TX_PERF_DEGRADED: "00" = if tx perf is degraded by 1% set error bit 25
    // "01" = if tx perf is degraded by 2% set error bit 25
    // "10" = if tx perf is degraded by 3% set error bit 25
    // "11" = if tx perf is degraded by 4% set error bit 25
    scomt::omi::SET_CONFIG1_TX_PERF_DEGRADED(mss::omi::perf_degraded::TWO_PERCENT, l_val);

    // CFG_DL0_RX_PERF_DEGRADED: "00" = if rx performance is degraded by 1% set error bit 26
    // "01" = if rx perf is degraded by 2% set error bit 26
    // "10" = if rx perf is degraded by 3% set error bit 26
    // "11" = if rx perf is degraded by 4% set error bit 26
    scomt::omi::SET_CONFIG1_RX_PERF_DEGRADED(mss::omi::perf_degraded::TWO_PERCENT, l_val);

    scomt::omi::SET_CONFIG1_TX_LANES_DISABLE(mss::omi::LANE_DISABLED_NONE, l_val);
    scomt::omi::SET_CONFIG1_RX_LANES_DISABLE(mss::omi::LANE_DISABLED_NONE, l_val);

    // CFG_DL0_RESET_ERR_HLD: dl0 reset the error hold register when it is read
    scomt::omi::SET_CONFIG1_RESET_ERR_HLD(mss::states::OFF, l_val);

    // CFG_DL0_RESET_ERR_CAP: dl0 reset the error capture register when it is read
    scomt::omi::SET_CONFIG1_RESET_ERR_CAP(mss::states::OFF, l_val);

    // CFG_DL0_RESET_TSHD_REG: dl0 reset the edpl threshold register when it is read
    scomt::omi::SET_CONFIG1_RESET_TSHD_REG(mss::states::OFF, l_val);

    // CFG_DL0_RESET_RMT_MSG: dl0 reset the remote register when it is read
    scomt::omi::SET_CONFIG1_RESET_RMT_MSG(mss::states::OFF, l_val);

    // CFG_DL0_INJECT_CRC_DIRECTION: dl0 inject crc direction

    scomt::omi::SET_CONFIG1_INJECT_CRC_DIRECTION(mss::omi::crc_inject_dir::CRC_DIR_RX, l_val);
    scomt::omi::SET_CONFIG1_INJECT_CRC_RATE(mss::omi::crc_inject_rate::CRC_INJ_RATE_1US, l_val);

    // CFG_DL0_INJECT_CRC_LANE: dl0 inject crc error on lane number
    scomt::omi::SET_CONFIG1_INJECT_CRC_LANE(INJECT_CRC_LANE, l_val);

    // CFG_DL0_INJECT_CRC_ERROR: dl0 inject crc error enable
    scomt::omi::SET_CONFIG1_INJECT_CRC_ERROR(mss::states::OFF, l_val);

    // CFG_DL0_EDPL_TIME: dl0 edpl time window
    scomt::omi::SET_CONFIG1_EDPL_TIME(mss::omi::edpl_time_win::EDPL_TIME_WIN_128MS, l_val);
    setup_mfg_test_edpl_time(i_target, l_edpl_disable, l_mnfg_screen_test, l_mnfg_edpl_time, l_val);

    scomt::omi::SET_CONFIG1_EDPL_THRESHOLD(mss::omi::edpl_err_thres::EDPL_ERR_THRES_128, l_val);
    setup_mfg_test_edpl_threshold(i_target, l_edpl_disable, l_mnfg_screen_test, l_mnfg_edpl_threshold, l_val);

    // CFG_DL0_EDPL_ENA: dl0 error detection per lane "edpl" enable
    scomt::omi::SET_CONFIG1_EDPL_ENA(!l_edpl_disable, l_val);

    FAPI_DBG("Writing CONFIG1 0x%016llx", l_val());
    FAPI_TRY(scomt::omi::PUT_CONFIG1(i_target, l_val));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the DL0_CYA_BITS
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_cya_bits(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    fapi2::buffer<uint64_t> l_val;

    FAPI_TRY(scomt::omi::GET_CYA_BITS(i_target, l_val));

    scomt::omi::SET_CYA_BITS_FRBUF_FULL0(mss::states::ON, l_val);

    FAPI_TRY(scomt::omi::PUT_CYA_BITS(i_target, l_val));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the DL0_ERROR_ACTION
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_error_action(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    fapi2::buffer<uint64_t> l_val;

    // Expected resulting register value: 0x000000000001 (16:63)
    FAPI_TRY(scomt::omi::PREP_ERROR_ACTION(i_target));

    scomt::omi::SET_ERROR_ACTION_0_ACTION(mss::states::ON, l_val);

    FAPI_TRY(scomt::omi::PUT_ERROR_ACTION(i_target, l_val));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to setup CONFIG1_EDPL_TIME for MFG screen test
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_edpl_disable value from ATTR_MSS_OMI_EDPL_DISABLE
/// @param[in] i_mnfg_screen_test true if OMI mfg screen is enabled
/// @param[in] i_mnfg_edpl_time value of ATTR_MSS_MNFG_EDPL_TIME
/// @param[in,out] io_data the register data to work on
/// @return FAPI2_RC_SUCCESS iff ok
///
void setup_mfg_test_edpl_time(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
                              const uint8_t i_edpl_disable,
                              const bool i_mnfg_screen_test,
                              const uint8_t i_mnfg_edpl_time,
                              fapi2::buffer<uint64_t>& io_data)
{
    if (!i_edpl_disable && i_mnfg_screen_test)
    {
        FAPI_DBG("%s Setting CONFIG1_EDPL_TIME to 0x%02X for MFG test", mss::c_str(i_target), i_mnfg_edpl_time);
        scomt::omi::SET_CONFIG1_EDPL_TIME(i_mnfg_edpl_time, io_data);
    }
}

///
/// @brief Function to setup CONFIG1_EDPL_THRESHOLD for MFG screen test
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_edpl_disable value from ATTR_MSS_OMI_EDPL_DISABLE
/// @param[in] i_mnfg_screen_test true if OMI mfg screen is enabled
/// @param[in] i_mnfg_edpl_threshold value of ATTR_MSS_MNFG_EDPL_THRESHOLD
/// @param[in,out] io_data the register data to work on
/// @return FAPI2_RC_SUCCESS iff ok
///
void setup_mfg_test_edpl_threshold(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
                                   const uint8_t i_edpl_disable,
                                   const bool i_mnfg_screen_test,
                                   const uint8_t i_mnfg_edpl_threshold,
                                   fapi2::buffer<uint64_t>& io_data)
{
    if (!i_edpl_disable && i_mnfg_screen_test)
    {
        FAPI_DBG("%s Setting CONFIG1_EDPL_THRESHOLD to 0x%02X for MFG test", mss::c_str(i_target), i_mnfg_edpl_threshold);
        scomt::omi::SET_CONFIG1_EDPL_THRESHOLD(i_mnfg_edpl_threshold, io_data);
    }
}

///
/// @brief P10 OMI setup helper function, to perform PRBS workarounds if needed
/// @param[in] i_omic OMIC target
/// @param[in] i_omi OMI target
/// @param[in] i_ocmb OCMB on the other side of the link
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode p10_omi_setup_prbs_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic,
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_omic);
    uint8_t l_dl_x4_backoff_en = 0;
    bool l_prbs_workaround_required = false;
    uint8_t l_proc_type = 0;
    uint8_t l_ocmb_type = 0;

    // Get BACKOFF_ENABLE CHIP_EC attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, i_ocmb, l_dl_x4_backoff_en),
             "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

    // Determine if workaround will be performed, if so, perform it
    FAPI_TRY(mss::workarounds::omi::get_ocmb_proc_types(i_ocmb, l_proc, l_ocmb_type, l_proc_type));
    l_prbs_workaround_required = mss::workarounds::omi::is_p10_prbs_required(l_ocmb_type, l_proc_type);

    if (l_prbs_workaround_required)
    {
        // TX_TRAINING_STATE1
        FAPI_TRY(mss::workarounds::omi::pre_training_prbs(i_omi, l_dl_x4_backoff_en));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief P10 OMI train helper function, to perform PRBS workarounds if needed
/// @param[in] i_omi OMI target
/// @param[in] i_ocmb OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode p10_omi_train_prbs_helper1(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    uint8_t l_dl_x4_backoff_en = 0;
    bool l_gem_or_apollo_workaround_req = false;
    bool l_p10_workaround_req = false;
    uint8_t l_proc_type = 0;
    uint8_t l_ocmb_type = 0;

    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_ocmb);

    // Get BACKOFF_ENABLE CHIP_EC attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, i_ocmb, l_dl_x4_backoff_en),
             "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

    // Determine if workarounds will be performed, if so, perform them
    FAPI_TRY(mss::workarounds::omi::get_ocmb_proc_types(i_ocmb, l_proc, l_ocmb_type, l_proc_type));
    l_gem_or_apollo_workaround_req = mss::workarounds::omi::is_gemini_apollo_prbs_required(l_ocmb_type, l_proc_type);
    l_p10_workaround_req = mss::workarounds::omi::is_p10_prbs_required(l_ocmb_type, l_proc_type);

    if (l_p10_workaround_req)
    {
        // TX_PATTERN_A
        FAPI_TRY(mss::workarounds::omi::training_prbs(i_omi, l_dl_x4_backoff_en));
    }
    else if (l_gem_or_apollo_workaround_req)
    {
        // TX_TRAINING_STATE_3, TX_PATTERN_A
        FAPI_TRY(mss::workarounds::omi::training_prbs_gem(i_omi, l_dl_x4_backoff_en));

        // 2 second delay for gemini
        FAPI_TRY(fapi2::delay(2 * mss::common_timings::DELAY_1S, mss::common_timings::DELAY_1MS));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief P10 OMI train helper function, to perform PRBS workarounds if needed
/// @param[in] i_omi OMI target
/// @param[in] i_ocmb OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode p10_omi_train_prbs_helper2(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    uint8_t l_dl_x4_backoff_en = 0;

    // Get BACKOFF_ENABLE CHIP_EC attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, i_ocmb, l_dl_x4_backoff_en),
             "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

    {
        fapi2::buffer<uint64_t> l_data;
        uint64_t l_pattern_a = 0;
        uint64_t l_pattern_b = 0;
        int i = 0;

        for (; i < 400; i++)
        {
            FAPI_TRY(fapi2::delay(mss::common_timings::DELAY_1MS, 10));

            FAPI_TRY(scomt::omi::GET_TRAINING_STATUS(i_omi, l_data));
            scomt::omi::GET_TRAINING_STATUS_RX_PATTERN_A(l_data, l_pattern_a);
            scomt::omi::GET_TRAINING_STATUS_RX_PATTERN_B(l_data, l_pattern_b);

            if (l_pattern_a > 0 || l_pattern_b)
            {
                break;
            }
        }

        FAPI_DBG("%s Found Pattern A|B(0x%08X%08X) after %dms...", mss::c_str(i_omi), l_data >> 32, l_data, i);
    }

    // Enable auto training
    FAPI_TRY(mss::omi::setup_mc_config0(i_omi, mss::omi::train_mode::ENABLE_AUTO_TRAINING, l_dl_x4_backoff_en));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief P10 omi train procedure for simulation
///
/// @param[in] i_omic OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode p10_omi_train_sim(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic)
{
    // Sim value
    const uint8_t l_dl_x4_backoff_en = 1;

    FAPI_TRY(setup_mc_cmn_config(i_omic));

    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_omic))
    {
        FAPI_TRY(setup_mc_config1(l_omi));
        FAPI_TRY(setup_mc_cya_bits(l_omi));
        FAPI_TRY(setup_mc_error_action(l_omi));

        FAPI_TRY(mss::omi::setup_mc_config0(
                     l_omi,
                     mss::omi::train_mode::ENABLE_AUTO_TRAINING,
                     l_dl_x4_backoff_en));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the OMI training status and state machine state
/// @param[in] i_omi OMI target
/// @param[out] o_state_machine_state state machine state
/// @param[out] o_omi_status omi status register buffer
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode omi_train_status(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    uint64_t& o_state_machine_state,
    fapi2::buffer<uint64_t>& o_omi_status)
{
    fapi2::buffer<uint64_t> l_omi_status;
    FAPI_TRY(scomt::omi::GET_STATUS(i_omi, l_omi_status));
    scomt::omi::GET_STATUS_TRAINING_STATE_MACHINE(l_omi_status, o_state_machine_state);

    o_omi_status = l_omi_status;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the OMI CRC counters for MFG screen test
/// @param[in] i_target OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_omi_mfg_screen_crc_counts(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_pmu_data;
    uint64_t l_crc_count = 0;
    uint64_t l_total_crc_count = 0;
    fapi2::ATTR_MFG_SCREEN_OMI_CRC_ALLOWED_Type l_crc_allowed = 0;

    FAPI_TRY(mss::attr::get_mfg_screen_omi_crc_allowed(l_crc_allowed));

    FAPI_TRY(scomt::omic::GET_PMU_CNTR(i_target, l_pmu_data));

    // Check upstream CRC count
    scomt::omic::GET_PMU_CNTR_2(l_pmu_data, l_crc_count);
    FAPI_INF("%s Upstream CRC count from PMU2: %d", mss::c_str(i_target), l_crc_count);
    l_total_crc_count += l_crc_count;

    scomt::omic::GET_PMU_CNTR_0(l_pmu_data, l_crc_count);
    FAPI_INF("%s Upstream CRC count from PMU0: %d", mss::c_str(i_target), l_crc_count);
    l_total_crc_count += l_crc_count;

    // Using NOEXIT here so we capture all fails, and not only the first one
    FAPI_ASSERT_NOEXIT((l_total_crc_count <= l_crc_allowed),
                       fapi2::P10_MFG_OMI_SCREEN_UPSTREAM_CRC()
                       .set_OMIC_TARGET(i_target)
                       .set_THRESHHOLD(l_crc_allowed)
                       .set_CRC_COUNT(l_total_crc_count),
                       "%s MFG OMI screen upstream CRC count (%d) exceeded threshhold (%d)",
                       mss::c_str(i_target),
                       l_total_crc_count,
                       l_crc_allowed );

    // Capture and log the error if the above assert failed
    mss::log_and_capture_error(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_rc);

    // Check downstream CRC count
    l_total_crc_count = 0;
    scomt::omic::GET_PMU_CNTR_3(l_pmu_data, l_crc_count);
    FAPI_INF("%s Downstream CRC count from PMU3: %d", mss::c_str(i_target), l_crc_count);
    l_total_crc_count += l_crc_count;

    scomt::omic::GET_PMU_CNTR_1(l_pmu_data, l_crc_count);
    FAPI_INF("%s Downstream CRC count from PMU1: %d", mss::c_str(i_target), l_crc_count);
    l_total_crc_count += l_crc_count;

    FAPI_ASSERT_NOEXIT((l_total_crc_count <= l_crc_allowed),
                       fapi2::P10_MFG_OMI_SCREEN_DOWNSTREAM_CRC()
                       .set_OMIC_TARGET(i_target)
                       .set_THRESHHOLD(l_crc_allowed)
                       .set_CRC_COUNT(l_total_crc_count),
                       "%s MFG OMI screen downstream CRC (NACK) count (%d) exceeded threshhold (%d)",
                       mss::c_str(i_target),
                       l_total_crc_count,
                       l_crc_allowed );

    // Capture and log the error if the above assert failed
    mss::log_and_capture_error(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_rc);

    // l_rc holds any error from the ASSERT_NOEXITs above
    // it will get thrown out by the caller, but is used in the unit tests
    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the OMI EDPL counters for MFG screen test
/// @param[in] i_target OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_omi_mfg_screen_edpl_counts(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ATTR_MFG_SCREEN_OMI_EDPL_ALLOWED_Type l_edpl_allowed = 0;

    FAPI_TRY(mss::attr::get_mfg_screen_omi_edpl_allowed(l_edpl_allowed));

    // Check upstream EDPL count (downstream is checked in Explorer library)
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        fapi2::buffer<uint64_t> l_pmu_data;
        uint64_t l_edpl_count = 0;
        uint64_t l_total_edpl_count = 0;

        FAPI_TRY(scomt::omi::GET_EDPL_MAX_COUNT(l_omi, l_pmu_data));

        scomt::omi::GET_EDPL_MAX_COUNT_0_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_0: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_1_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_1: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_2_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_2: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_3_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_3: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_4_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_4: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_5_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_5: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_6_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_6: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        scomt::omi::GET_EDPL_MAX_COUNT_7_MAX_COUNT(l_pmu_data, l_edpl_count);
        FAPI_INF("%s Upstream EDPL count from EDPL_MAX_COUNT_7: %d", mss::c_str(l_omi), l_edpl_count);
        l_total_edpl_count += l_edpl_count;

        // Using NOEXIT here so we capture all fails, and not only the first one
        FAPI_ASSERT_NOEXIT((l_total_edpl_count <= l_edpl_allowed),
                           fapi2::P10_MFG_OMI_SCREEN_UPSTREAM_EDPL()
                           .set_OMI_TARGET(l_omi)
                           .set_THRESHHOLD(l_edpl_allowed)
                           .set_EDPL_COUNT(l_total_edpl_count),
                           "%s MFG OMI screen upstream EDPL count (%d) exceeded threshhold (%d)",
                           mss::c_str(l_omi),
                           l_total_edpl_count,
                           l_edpl_allowed );

        // Capture and log the error if the above assert failed
        mss::log_and_capture_error(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_rc);
    }

    // l_rc holds any error from the ASSERT_NOEXITs above
    // it will get thrown out by the caller, but is used in the unit tests
    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}

} // omi
} // mss
