/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train.C $  */
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
/// @file p10_omi_train.C
/// @brief Setup OMI training on P10
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_omi_train.H>
#include <p10_scom_omi.H>
#include <p10_scom_omic.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
///
/// @brief putScom for a specific OMI lane
///
/// @param[in] i_target    Reference to OMI endpoint target
/// @param[in] i_scom      0th lane scom address
/// @param[in] i_data      Data to write
/// @param[in] i_lane      The lane to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_dl_setup_putScomLane(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    uint64_t i_scom, const fapi2::buffer<uint64_t>& i_data, uint64_t i_lane)
{
    FAPI_DBG("Start");

    i_lane <<= 32;
    i_scom |= i_lane;
    FAPI_TRY(putScom(i_target, i_scom, i_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup the OMIC fir mask
///
/// @param[in] i_target    Reference to OMIC endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_firs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    FAPI_DBG("Start");
    using namespace scomt::omic;
    //TODO: FIXME!!
    fapi2::buffer<uint64_t> l_data = 0xFFFFFFFFFFFFFFFFull;

    FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_RW(i_target));
    FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_RW(i_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup CMN_CONFIG register
///
/// @param[in] i_target Reference to OMIC endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_cmn_config(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    using namespace scomt::omic;
    fapi2::buffer<uint64_t> l_val = 0;

    FAPI_TRY(PREP_CMN_CONFIG(i_target));

    SET_CMN_CONFIG_CFG_CMN_SPARE(0, l_val);
    // FIXME: SET_CMN_CONFIG_CFG_CMN_PM_CDR_TIMER(CDR_TIMER_250NS, l_val);
    // FIXME: SET_CMN_CONFIG_CFG_CMN_PM_DIDT_TIMER(DIDT_TIMER_10NS, l_val);
    SET_CMN_CONFIG_CFG_CMN_PSAV_STS_ENABLE(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_RECAL_TIMER(RECAL_TIMER_100MS, l_val);
    SET_CMN_CONFIG_CFG_CMN_1US_TMR(1600, l_val);
    SET_CMN_CONFIG_CFG_CMN_DBG_EN(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_DBG_SEL(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_RD_RST(1, l_val);
    SET_CMN_CONFIG_CFG_CMN_PRE_SCALAR(PRESCALAR_16BIT, l_val);
    SET_CMN_CONFIG_CFG_CMN_FREEZE(1, l_val);
    SET_CMN_CONFIG_CFG_CMN_PORT_SEL(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR3_PS(SEL_EVEN, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR3_ES(SIG_1_0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR2_PS(SEL_EVEN, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR2_ES(SIG_7_6, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR1_PS(SEL_EVEN, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR1_ES(SIG_3_2, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR0_PS(SEL_ODD, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR0_ES(SIG_1_0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR3_PE(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR2_PE(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR1_PE(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR0_PE(0, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR3_EN(1, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR2_EN(1, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR1_EN(1, l_val);
    SET_CMN_CONFIG_CFG_CMN_CNTR0_EN(1, l_val);

    FAPI_TRY(PUT_CMN_CONFIG(i_target, l_val));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup CONFIG1 register
///
/// @param[in] i_target Reference to OMI endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_config1(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    using namespace scomt::omi;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    fapi2::buffer<uint64_t> l_val = 0;

    uint8_t l_edpl_disable = 0;

    uint8_t l_sim;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, l_sys, l_sim));

    FAPI_TRY(PREP_CONFIG1(i_target));


    SET_CONFIG1_PREIPL_PRBS_TIME(l_sim ? PREIPL_PRBS_1US : PREIPL_PRBS_256MS, l_val);

    // FIXME: PRE-IPL PRBS Timing is not functional in Axone, so set to disable
    SET_CONFIG1_PREIPL_PRBS_ENA(0, l_val); // Disable

    SET_CONFIG1_LANE_WIDTH(TL_CTR_BY_SIDEBAND, l_val);
    SET_CONFIG1_B_HYSTERESIS(B_HYSTERESIS_16, l_val);
    SET_CONFIG1_A_HYSTERESIS(A_HYSTERESIS_16, l_val);
    SET_CONFIG1_B_PATTERN_LENGTH(0, l_val);
    SET_CONFIG1_A_PATTERN_LENGTH(0, l_val);
    SET_CONFIG1_TX_PERF_DEGRADED(1, l_val);
    SET_CONFIG1_RX_PERF_DEGRADED(1, l_val);
    SET_CONFIG1_TX_LANES_DISABLE(LANE_DISABLED_NONE, l_val);
    SET_CONFIG1_RX_LANES_DISABLE(LANE_DISABLED_NONE, l_val);
    SET_CONFIG1_RESET_ERR_HLD(0, l_val);
    SET_CONFIG1_RESET_ERR_CAP(0, l_val);
    SET_CONFIG1_RESET_TSHD_REG(0, l_val);
    SET_CONFIG1_RESET_RMT_MSG(0, l_val);
    SET_CONFIG1_INJECT_CRC_DIRECTION(CRC_DIR_RX, l_val);
    SET_CONFIG1_INJECT_CRC_RATE(CRC_INJ_RATE_1US, l_val);
    SET_CONFIG1_INJECT_CRC_LANE(0, l_val);
    SET_CONFIG1_INJECT_CRC_ERROR(0, l_val);
    SET_CONFIG1_EDPL_TIME(EDPL_TIME_WIN_16MS, l_val);
    SET_CONFIG1_EDPL_THRESHOLD(EDPL_ERR_THRES_16, l_val);
    SET_CONFIG1_EDPL_ENA(l_edpl_disable ? 0 : 1, l_val);

    FAPI_TRY(PUT_CONFIG1(i_target, l_val));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup CYA_BITS register
///
/// @param[in] i_target Reference to OMI endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_cya_bits(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    using namespace scomt::omi;
    fapi2::buffer<uint64_t> l_val = 0;

    FAPI_TRY(GET_CYA_BITS(i_target, l_val));

    SET_CYA_BITS_FRBUF_FULL0(1, l_val);

    FAPI_TRY(PUT_CYA_BITS(i_target, l_val));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup error_action register
///
/// @param[in] i_target Reference to OMI endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_error_action(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    using namespace scomt::omi;
    fapi2::buffer<uint64_t> l_val = 0;

    FAPI_TRY(PREP_ERROR_ACTION(i_target));

    SET_ERROR_ACTION_0_ACTION(1, l_val);

    FAPI_TRY(PUT_ERROR_ACTION(i_target, l_val));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Setup config0 register
///
/// @param[in] i_target Reference to OMI endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    using namespace scomt::omi;
    fapi2::buffer<uint64_t> l_val = 0;
    uint8_t l_dl_tx_ln_rev_en = 1;

    FAPI_TRY(PREP_CONFIG0(i_target));

    SET_CONFIG0_ENABLE(1, l_val);
    SET_CONFIG0_CFG_SPARE(0, l_val);
    SET_CONFIG0_CFG_TL_CREDITS(32, l_val);
    SET_CONFIG0_TL_EVENT_ACTIONS(0, l_val);
    SET_CONFIG0_TL_ERROR_ACTIONS(0, l_val);
    SET_CONFIG0_FWD_PROGRESS_TIMER(NO_FORWARD_TIMER_16US, l_val);
    SET_CONFIG0_REPLAY_RSVD_ENTRIES(0, l_val);
    SET_CONFIG0_DEBUG_SELECT(0, l_val);
    SET_CONFIG0_DEBUG_ENABLE(0, l_val);
    SET_CONFIG0_DL2TL_DATA_PARITY_INJECT(0, l_val);
    SET_CONFIG0_DL2TL_CONTROL_PARITY_INJECT(0, l_val);
    SET_CONFIG0_ECC_UE_INJECTION(0, l_val);
    SET_CONFIG0_ECC_CE_INJECTION(0, l_val);
    SET_CONFIG0_FP_DISABLE(0, l_val);
    SET_CONFIG0_TX_LN_REV_ENA(l_dl_tx_ln_rev_en, l_val);
    SET_CONFIG0_128_130_ENCODING_ENABLED(0, l_val);
    SET_CONFIG0_PHY_CNTR_LIMIT(PHY_CTR_MODE_50US, l_val);
    SET_CONFIG0_RUNLANE_OVRD_ENABLE(0, l_val);
    SET_CONFIG0_PWRMGT_ENABLE(1, l_val);
    SET_CONFIG0_QUARTER_WIDTH_BACKOFF_ENABLE(0, l_val);
    SET_CONFIG0_HALF_WIDTH_BACKOFF_ENABLE(1, l_val);
    SET_CONFIG0_SUPPORTED_MODES(LINK_WIDTHS_X8, l_val);
    SET_CONFIG0_TRAIN_MODE(ENABLE_AUTO_TRAINING, l_val);
    SET_CONFIG0_VERSION(9, l_val);
    SET_CONFIG0_RETRAIN(0, l_val);
    SET_CONFIG0_RESET(0, l_val);

    FAPI_TRY(PUT_CONFIG0(i_target, l_val));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Start DL link training on the selected OMIC
///
/// @param[in] i_target Reference to OMIC endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_omi_train(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    FAPI_DBG("Start");
    auto l_omi_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    FAPI_TRY(p10_omi_train_firs(i_target));

    FAPI_TRY(p10_omi_train_cmn_config(i_target));

    for (auto l_omi_target : l_omi_targets)
    {
        FAPI_TRY(p10_omi_train_config1(l_omi_target));
        FAPI_TRY(p10_omi_train_cya_bits(l_omi_target));
        FAPI_TRY(p10_omi_train_error_action(l_omi_target));
        FAPI_TRY(p10_omi_train_config0(l_omi_target));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
