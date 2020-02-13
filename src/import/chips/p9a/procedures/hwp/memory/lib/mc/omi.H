/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/mc/omi.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file omi.H
/// @brief The omi library
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef P9A_OMI_H_
#define P9A_OMI_H_

#include <fapi2.H>

#include <lib/mc/omi_traits.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <mss_p9a_attribute_getters.H>

static constexpr uint8_t OPTIMAL_NUM_TL_CREDITS = 18;

namespace mss
{

namespace mc
{

///
/// @brief Function to setup the CMN_CONFIG
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the PROC target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_mcn_config(const fapi2::Target<T>& i_target)
{
    // The value is 0x042364008874630F
    fapi2::buffer<uint64_t> l_val;

    // CFG_CMN_SPARE: Spare
    l_val.insertFromRight< TT::MC_REG0_CMN_CONFIG_SPARE, TT::MC_REG0_CMN_CONFIG_SPARE_LEN>(0);

    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_PM_CDR_TIMER, TT::MC_REG0_CMN_CONFIG_PM_CDR_TIMER_LEN>
    (mss::omi::rx_cdr_timer::CDR_TIMER_250NS);

    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_PM_DIDT_TIMER, TT::MC_REG0_CMN_CONFIG_PM_DIDT_TIMER_LEN>
    (mss::omi::didt_timer::DIDT_TIMER_10NS);

    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_PSAV_STS_ENABLE>(0);

    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_RECAL_TIMER, TT::MC_REG0_CMN_CONFIG_RECAL_TIMER_LEN>
    (mss::omi::recal_timer::RECAL_TIMER_100MS);

    // CFG_CMN_1US_TMR: Number of cycles in 1us. Needs to be changed based on clock frequency
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CFG_CMN_1US_TMR, TT::MC_REG0_CMN_CONFIG_CFG_CMN_1US_TMR_LEN>
    (1600);

    // CFG_CMN_DBG_EN: Enable the debug logic
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CFG_CMN_DBG_EN>(0);

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
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_DBG_SEL, TT::MC_REG0_CMN_CONFIG_DBG_SEL_LEN>(0);

    // CFG_CMN_RD_RST: Reset the PMU counters when the PMU counters are read
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_RD_RST>(1);

    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_PRE_SCALAR, TT::MC_REG0_CMN_CONFIG_PRE_SCALAR_LEN>
    (mss::omi::pmu_prescalar::PRESCALAR_16BIT);

    // CFG_CMN_FREEZE: PMU freeze mode - when set, the PMU will stop all counters when 1 of the counters wraps.
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CFG_CMN_FREEZE>(1);

    // CFG_CMN_PORT_SEL: PMU port select - select which of the 8 groups of inputs will be used by the PMU.
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_PORT_SEL, TT::MC_REG0_CMN_CONFIG_PORT_SEL_LEN>(0);

    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR3_PS, TT::MC_REG0_CMN_CONFIG_CNTR3_PS_LEN>(
        mss::omi::cntrl_pair_selector::SEL_EVEN);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR3_ES, TT::MC_REG0_CMN_CONFIG_CNTR3_ES_LEN>(
        mss::omi::cntrl_event_selector::SIG_1_0);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR2_PS, TT::MC_REG0_CMN_CONFIG_CNTR2_PS_LEN>(
        mss::omi::cntrl_pair_selector::SEL_EVEN);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR2_ES, TT::MC_REG0_CMN_CONFIG_CNTR2_ES_LEN>(
        mss::omi::cntrl_event_selector::SIG_7_6);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR1_PS, TT::MC_REG0_CMN_CONFIG_CNTR1_PS_LEN>(
        mss::omi::cntrl_pair_selector::SEL_EVEN);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR1_ES, TT::MC_REG0_CMN_CONFIG_CNTR1_ES_LEN>(
        mss::omi::cntrl_event_selector::SIG_3_2);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR0_PS, TT::MC_REG0_CMN_CONFIG_CNTR0_PS_LEN>(
        mss::omi::cntrl_pair_selector::SEL_ODD);
    l_val.insertFromRight<TT::MC_REG0_CMN_CONFIG_CNTR0_ES, TT::MC_REG0_CMN_CONFIG_CNTR0_ES_LEN>(
        mss::omi::cntrl_event_selector::SIG_1_0);

    // CFG_CMN_CNTRx_PE: PMU cntrx positive edge select
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR3_PE>(0);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR2_PE>(0);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR1_PE>(0);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR0_PE>(0);

    // CFG_CMN_CNTRx_EN: PMU cntrx enable
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR3_EN>(1);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR2_EN>(1);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR1_EN>(1);
    l_val.writeBit<TT::MC_REG0_CMN_CONFIG_CNTR0_EN>(1);

    FAPI_TRY( mss::putScom(i_target, TT::MC_REG0_CMN_CONFIG, l_val) );
    FAPI_TRY( mss::putScom(i_target, TT::MC_REG1_CMN_CONFIG, l_val) );
    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_CMN_CONFIG, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the CONFIG0 for the given train mode and backoff_en bit
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @param[in] i_train_mode training step to enable
/// @param[in] i_dl_x4_backoff_en backoff enable mode
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_config0(
    const fapi2::Target<T>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en)
{
    // The value is 0x8200040000152824
    fapi2::buffer<uint64_t> l_val;
    uint8_t l_dl_tx_ln_rev_en = 1;

    // CFG_DL0_ENABLE: dl0 enabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_ENABLE>(1);

    // CFG_DL0_CFG_SPARE: dl0 Spare
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_CFG_SPARE, TT::MC_REG2_DL0_CONFIG0_CFG_CFG_SPARE_LEN>(0);

    // CFG_DL0_CFG_TL_CREDITS: dl0 TL credits - Maximum number of credits that can be sent to the TL
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_CFG_TL_CREDITS, TT::MC_REG2_DL0_CONFIG0_CFG_CFG_TL_CREDITS_LEN>
    (OPTIMAL_NUM_TL_CREDITS);

    // CFG_DL0_TL_EVENT_ACTIONS: dl0 TL event actions
    // Bit 0 = Freeze all
    // Bit 1 = Freeze afu, leave TL and DL running
    // Bit 2 = Trigger Internal Logic Analyzers
    // Bit 3 = Bring down the link
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_TL_EVENT_ACTIONS, TT::MC_REG2_DL0_CONFIG0_CFG_TL_EVENT_ACTIONS_LEN>(0);

    // CFG_DL0_TL_ERROR_ACTIONS: dl0 TL error actions
    // Bit 0 = Freeze all
    // Bit 1 = Freeze afu, leave TL and DL running
    // Bit 2 = Trigger Internal Logic Analyzers
    // Bit 3 = Bring down the link
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_TL_ERROR_ACTIONS, TT::MC_REG2_DL0_CONFIG0_CFG_TL_ERROR_ACTIONS_LEN>(0);

    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_FWD_PROGRESS_TIMER, TT::MC_REG2_DL0_CONFIG0_CFG_FWD_PROGRESS_TIMER_LEN>(
        mss::omi::no_forward_progress_timer::NO_FORWARD_TIMER_16US);

    // CFG_DL0_REPLAY_RSVD_ENTRIES: dl0 replay buffers reserved - times 16 is the number of replay buffers reserved
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_REPLAY_RSVD_ENTRIES, TT::MC_REG2_DL0_CONFIG0_CFG_REPLAY_RSVD_ENTRIES_LEN>
    (0);

    // CFG_DL0_DEBUG_SELECT: dl0 trace mux select
    // "000" = zeros
    // "001" = RX information
    // "010" = TX flit information
    // "011" = Tx training information
    // "100" = 11 bits of RX information
    // "101" = 11 bits of TX flit information
    // "110" = 11 bits of Tx training information
    // "111" = zeros
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_DEBUG_SELECT, TT::MC_REG2_DL0_CONFIG0_CFG_DEBUG_SELECT_LEN>
    (0);

    // CFG_DL0_DEBUG_ENABLE: dl0 trace enable
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_DEBUG_ENABLE>(0);

    // CFG_DL0_DL2TL_DATA_PARITY_INJECT: dl0 inject a data parity error
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_DL2TL_DATA_PARITY_INJECT>(0);

    // CFG_DL0_DL2TL_CONTROL_PARITY_INJECT: dl0 inject a control parity error
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_DL2TL_CONTROL_PARITY_INJECT>(0);

    // CFG_DL0_ECC_UE_INJECTION: dl0 inject a ECC UE error
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_ECC_UE_INJECTION>(0);

    // CFG_DL0_ECC_CE_INJECTION: dl0 inject a ECC CE error
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_ECC_CE_INJECTION>(0);

    // CFG_DL0_FP_DISABLE: dl0 fastpath disabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_FP_DISABLE>(0);

    // CFG_DL0_UNUSED2: dl0 Spare
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_UNUSED2>(0);

    // CFG_DL0_TX_LN_REV_ENA: When set will allow dl0 to perform tx lane reversals.
    FAPI_TRY(mss::attr::get_omi_dl_ln_rev_enable(i_target, l_dl_tx_ln_rev_en),
             "Error from FAPI_ATTR_GET (ATTR_OMI_DL_LN_REV_ENABLE)");
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_TX_LN_REV_ENA>(l_dl_tx_ln_rev_en);

    // CFG_DL0_128_130_ENCODING_ENABLED: dl0 128/130 encoding enabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_128_130_ENCODING_ENABLED>(0);

    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_PHY_CNTR_LIMIT, TT::MC_REG2_DL0_CONFIG0_CFG_PHY_CNTR_LIMIT_LEN>(
        mss::omi::phy_ctr_mode::PHY_CTR_MODE_60MS);

    // CFG_DL0_RUNLANE_OVRD_ENABLE: When enabled, the dl0 will drive run lane to the PHY for all training states.
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_TX_EP_MODE>(0);

    // CFG_DL0_PWRMGT_ENABLE: dl0 power management enabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_PWRMGT_ENABLE>(0);

    // CFG_DL0_QUARTER_WIDTH_BACKOFF_ENABLE: dl0 x1 backoff enabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_X1_BACKOFF_ENABLE>(0);

    // CFG_DL0_HALF_WIDTH_BACKOFF_ENABLE: dl0 x4 backoff enabled
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_X4_BACKOFF_ENABLE>(i_dl_x4_backoff_en);

    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_SUPPORTED_MODES, TT::MC_REG2_DL0_CONFIG0_CFG_SUPPORTED_MODES_LEN>(
        mss::omi::link_widths::LINK_WIDTHS_X8);

    // CFG_DL0_TRAIN_MODE: dl0 train mode
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_TRAIN_MODE, TT::MC_REG2_DL0_CONFIG0_CFG_TRAIN_MODE_LEN>(
        i_train_mode);

    // CFG_DL0_VERSION: dl0 version number
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG0_CFG_VERSION, TT::MC_REG2_DL0_CONFIG0_CFG_VERSION_LEN>(9);

    // CFG_DL0_RETRAIN: dl0 retrain - Reset dl0 back to training state 4
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_RETRAIN>(0);

    // CFG_DL0_RESET: dl0 reset - Reset dl0 back to traning state 0
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG0_CFG_RESET>(0);

    FAPI_DBG("Writing 0x%16llx to MC_REG2_DL0_CONFIG0 (0x%16llx) of %s",
             l_val, TT::MC_REG2_DL0_CONFIG0, mss::c_str(i_target));

    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_DL0_CONFIG0, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to setup the CONFIG1
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_config1(const fapi2::Target<T>& i_target)
{
    // The value is 0x0C00050000000059;
    fapi2::buffer<uint64_t> l_val;

    uint8_t l_sim = 0;
    uint8_t l_edpl_disable = 0;
    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    // CFG_DL0_CFG1_PREIPL_PRBS
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_PREIPL_PRBS_TIME, TT::MC_REG2_DL0_CONFIG1_CFG_PREIPL_PRBS_TIME_LEN>(
        l_sim ? mss::omi::preipl_prbs_time::PREIPL_PRBS_1US : mss::omi::preipl_prbs_time::PREIPL_PRBS_256MS);
    // PRE-IPL PRBS Timing is not functional in Axone, so set to disable
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_PREIPL_PRBS_ENA, 1>(0); // Disable

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_LANE_WIDTH, TT::MC_REG2_DL0_CONFIG1_CFG_LANE_WIDTH_LEN>(
        mss::omi::lan_width_override::TL_CTR_BY_SIDEBAND);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_B_HYSTERESIS, TT::MC_REG2_DL0_CONFIG1_CFG_B_HYSTERESIS_LEN>(
        mss::omi::b_hysteresis::B_HYSTERESIS_16);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_A_HYSTERESIS, TT::MC_REG2_DL0_CONFIG1_CFG_A_HYSTERESIS_LEN>(
        mss::omi::a_hysteresis::A_HYSTERESIS_16);

    // CFG_DL0_B_PATTERN_LENGTH: Number of consecutive 1s and 0s needed to represent training Pattern
    // B=> "11111111111111110000000000000000"
    // "00" = two Xs => "11111111111111XX00000000000000XX"
    // "10" = four Xs => "111111111111XXXX000000000000XXXX"
    // "01" = one Xs => "111111111111111X000000000000000X"
    // "11" = same as "10"
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_B_PATTERN_LENGTH,
                          TT::MC_REG2_DL0_CONFIG1_CFG_B_PATTERN_LENGTH_LEN>(0);

    // CFG_DL0_A_PATTERN_LENGTH: Number of consecutive 1s and 0s needed to represent training Pattern
    // A => "1111111100000000"
    // "00" = two Xs => "111111XX000000XX"
    // "10" = four Xs => "1111XXXX0000XXXX"
    // "01" = one Xs => "1111111X0000000X"
    // "11" = same as "10"
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_A_PATTERN_LENGTH,
                          TT::MC_REG2_DL0_CONFIG1_CFG_A_PATTERN_LENGTH_LEN>(0);

    // CFG_DL0_TX_PERF_DEGRADED: "00" = if tx perf is degraded by 1% set error bit 25
    // "01" = if tx perf is degraded by 2% set error bit 25
    // "10" = if tx perf is degraded by 3% set error bit 25
    // "11" = if tx perf is degraded by 4% set error bit 25
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_TX_PERF_DEGRADED,
                          TT::MC_REG2_DL0_CONFIG1_CFG_TX_PERF_DEGRADED_LEN>(1);

    // CFG_DL0_RX_PERF_DEGRADED: "00" = if rx performance is degraded by 1% set error bit 26
    // "01" = if rx perf is degraded by 2% set error bit 26
    // "10" = if rx perf is degraded by 3% set error bit 26
    // "11" = if rx perf is degraded by 4% set error bit 26
    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_RX_PERF_DEGRADED,
                          TT::MC_REG2_DL0_CONFIG1_CFG_RX_PERF_DEGRADED_LEN>(1);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_TX_LANES_DISABLE,
                          TT::MC_REG2_DL0_CONFIG1_CFG_TX_LANES_DISABLE_LEN>(mss::omi::LANE_DISABLED_NONE);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_RX_LANES_DISABLE,
                          TT::MC_REG2_DL0_CONFIG1_CFG_RX_LANES_DISABLE_LEN>(mss::omi::LANE_DISABLED_NONE);

    // CFG_DL0_RESET_ERR_HLD: dl0 reset the error hold register when it is read
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_RESET_ERR_HLD>(0);

    // CFG_DL0_RESET_ERR_CAP: dl0 reset the error capture register when it is read
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_RESET_ERR_CAP>(0);

    // CFG_DL0_RESET_TSHD_REG: dl0 reset the edpl threshold register when it is read
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_RESET_TSHD_REG>(0);

    // CFG_DL0_RESET_RMT_MSG: dl0 reset the remote register when it is read
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_RESET_RMT_MSG>(0);

    // CFG_DL0_INJECT_CRC_DIRECTION: dl0 inject crc direction
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_DIRECTION>(mss::omi::crc_inject_dir::CRC_DIR_RX);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_RATE,
                          TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_RATE_LEN>(mss::omi::crc_inject_rate::CRC_INJ_RATE_1US);

    // CFG_DL0_INJECT_CRC_LANE: dl0 inject crc error on lane number
    l_val.template
    insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_LANE, TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_LANE_LEN>(0);

    // CFG_DL0_INJECT_CRC_ERROR: dl0 inject crc error enable
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_INJECT_CRC_ERROR>(0);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_EDPL_TIME,
                          TT::MC_REG2_DL0_CONFIG1_CFG_EDPL_TIME_LEN>(mss::omi::edpl_time_win::EDPL_TIME_WIN_16MS);

    l_val.insertFromRight<TT::MC_REG2_DL0_CONFIG1_CFG_EDPL_THRESHOLD,
                          TT::MC_REG2_DL0_CONFIG1_CFG_EDPL_THRESHOLD_LEN>(mss::omi::edpl_err_thres::EDPL_ERR_THRES_16);

    // CFG_DL0_EDPL_ENA: dl0 error detection per lane "edpl" enable
    FAPI_TRY(mss::attr::get_mss_omi_edpl_disable(l_edpl_disable));
    l_val.writeBit<TT::MC_REG2_DL0_CONFIG1_CFG_EDPL_ENA>(l_edpl_disable ? 0 : 1);

    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_DL0_CONFIG1, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the DL0_CYA_BITS
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_cya_bits(const fapi2::Target<T>& i_target)
{
    fapi2::buffer<uint64_t> l_val;

    // The value is 0x00000200 (32:63)
    FAPI_TRY( mss::getScom(i_target, TT::MC_REG2_DL0_CYA_BITS, l_val) );
    // CFG_CYA_BITS0: Chicken switch control bits
    l_val.insertFromRight<TT::MC_REG2_DL0_CYA_BITS_CFG_BITS0, TT::MC_REG2_DL0_CYA_BITS_CFG_BITS0_LEN>(0x00000200);
    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_DL0_CYA_BITS, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to set the DL0_ERROR_ACTION
/// @tparam PROC the memory controller type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_error_action(const fapi2::Target<T>& i_target)
{
    fapi2::buffer<uint64_t> l_val;

    // The value is 0x000000000001 (16:63)
    FAPI_TRY( mss::getScom(i_target, TT::MC_REG2_DL0_ERROR_ACTION, l_val) );
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR11_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR11_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR10_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR10_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR9_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR9_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR8_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR8_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR7_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR7_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR6_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR6_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR5_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR5_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR4_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR4_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR3_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR3_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR2_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR2_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR1_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR1_ACTION_LEN>(0);
    l_val.insertFromRight<TT::MC_REG2_DL0_ERROR_ACTION_FIR0_ACTION, TT::MC_REG2_DL0_ERROR_ACTION_FIR0_ACTION_LEN>(1);
    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_DL0_ERROR_ACTION, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Function to set the DL0_RMT_CONFIG
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode setup_mc_rmt_config(const fapi2::Target<T>& i_target)
{
    fapi2::buffer<uint64_t> l_val;

    // The value is 0x00000000 (32:63)
    FAPI_TRY( mss::getScom(i_target, TT::MC_REG2_DL0_RMT_CONFIG, l_val) );
    // CFG_DLX0
    l_val.insertFromRight<TT::MC_REG2_DL0_RMT_CONFIG_CFG_DLX2, TT::MC_REG2_DL0_RMT_CONFIG_CFG_DLX2_LEN>(0x00000000);
    FAPI_TRY( mss::putScom(i_target, TT::MC_REG2_DL0_RMT_CONFIG, l_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check OMI training status
/// @tparam PROC the proc type
/// @tparam T the fapi2 target type of the target
/// @tparam TT the class traits for the omi
/// @param[in] i_target the OMI target to operate on
/// @param[out] o_state_machine_state training state mahcine
/// @param[out] o_omi_training_status training status
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::proc_type PROC = DEFAULT_PROC_TYPE, fapi2::TargetType T, typename TT = omiTraits<T, PROC>>
fapi2::ReturnCode omi_train_status(const fapi2::Target<T>& i_target,
                                   uint8_t& o_state_machine_state,
                                   fapi2::buffer<uint64_t>& o_omi_training_status)
{
    fapi2::buffer<uint64_t> l_omi_status;

    // Check OMI training status
    FAPI_TRY(mss::getScom(i_target, TT::MC_REG2_DL0_STATUS, l_omi_status));

    o_omi_training_status = l_omi_status;
    o_state_machine_state = 0;
    l_omi_status.extractToRight<TT::MC_REG2_DL0_STATUS_STS_TRAINING_STATE_MACHINE,
                                TT::MC_REG2_DL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN>(o_state_machine_state);

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mc

} // namespace mss


#endif
