/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_dmi_linktrain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_io_dmi_linktrain.C
/// @brief I/O Link Training on the Dmi Links.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Train the link through several steps (WDERF).
///     - (W) Wiretest
///     - (D) Deskew
///     - (E) Eye Optimization
///     - (R) Repair/Recal
///     - (F) Functional
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///     - Dccal Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Defines
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_dmi_linktrain.H>

#include <p9_io_dmi_clear_firs.H>

#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9_io_common.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

/**
 * @brief I/O EDI+ Training Substeps
 */
enum class State
{
    NONE       = 0x00000000,
    WIRETEST   = 0x00000010,
    DESKEW     = 0x00000008,
    EYEOPT     = 0x00000004,
    REPAIR     = 0x00000002,
    FUNCTIONAL = 0x00000001,
    WDERF      = 0x0000001F
};
inline State operator& (const State& a, const State& b)
{
    return static_cast<State>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}
inline State operator| (const State& a, const State& b)
{
    return static_cast<State>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}
/**
 * @brief Adds I/O FFDC Link data to the Error
 * @param[in]  i_mtgt   Master Target
 * @param[in]  i_stgt   Slave Target
 * @param[in]  GRP0    Clock Group
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_ffdc(
    const DMI_TGT& i_mtgt,
    const CN_TGT& i_stgt,
    const bool i_timeout)
{

    const uint8_t  GRP3         = 3;
    const uint8_t  GRP0         = 0;
    const uint8_t  LN0          = 0;
    const uint32_t INVALID_FFDC = 0xFFFFFFFF;
    uint64_t       l_data       = 0;

    // Return Codes:
    //  l_ffdc_rc -- Passed by reference and is used to create the ffdc.  This return code
    //               will be returned at the end of the function
    fapi2::ReturnCode l_ffdc_rc    = 0;

    //  l_rc      -- Used during the data collection and will not cause the function to fail,
    //               only will cause invalid data if the scoms fail.
    fapi2::ReturnCode l_rc         = 0;

    // Create the FFDC Error
    fapi2::IO_DMI_LINKTRAIN_ERROR ffdc(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_ffdc_rc);

    ffdc.set_M_TARGET(i_mtgt);
    ffdc.set_S_TARGET(i_stgt);
    ffdc.set_M_GROUP (GRP3);
    ffdc.set_M_GROUP (GRP0);
    ffdc.set_TIMEOUT (i_timeout);

    ///////////////////////////////////////////////////////////////////////////
    // Master Common
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDIP_RX_CTL_CNTL1_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_WDERF_START (io::get(EDIP_RX_START_WDERF_ALIAS,  l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_WDERF_START (INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_STAT1_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_WDERF_DONE  (io::get(EDIP_RX_WDERF_DONE_ALIAS,   l_data));
    ffdc.set_M_WDERF_FAILED(io::get(EDIP_RX_WDERF_FAILED_ALIAS, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_WDERF_DONE  (INVALID_FFDC);
        ffdc.set_M_WDERF_FAILED(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_STAT2_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_LANE_BAD_0_15(io::get(EDIP_RX_LANE_BAD_VEC_0_15, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_LANE_BAD_0_15(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read(EDIP_RX_CTL_STAT4_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_LANE_BAD_16_23(io::get(EDIP_RX_LANE_BAD_VEC_16_23, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_LANE_BAD_16_23(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_MODE11_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_LANE_DISABLED_VEC_0_15(io::get(EDIP_RX_LANE_DISABLED_VEC_0_15, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_LANE_DISABLED_VEC_0_15(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_MODE12_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_LANE_DISABLED_VEC_16_23(io::get(EDIP_RX_LANE_DISABLED_VEC_16_23, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_LANE_DISABLED_VEC_16_23(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_MAIN_INIT_STATE(io::get(EDIP_RX_MAIN_INIT_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_MAIN_INIT_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Master Wiretest
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_WIRETEST_WTM_STATE(io::get(EDIP_RX_WTM_STATE, l_data));
    ffdc.set_M_WIRETEST_WTR_STATE(io::get(EDIP_RX_WTR_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_WIRETEST_WTM_STATE(INVALID_FFDC);
        ffdc.set_M_WIRETEST_WTR_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_STAT3_EO_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_WIRETEST_WTL_SM_STATUS(io::get(EDIP_RX_WTL_SM_STATUS, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_WIRETEST_WTL_SM_STATUS(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_GLBSM_STAT2_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_WTR_BAD_LANE_COUNT(io::get(EDIP_RX_WTR_BAD_LANE_COUNT, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_WTR_BAD_LANE_COUNT(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read(EDIP_RX_CTL_STAT5_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_CLK_LANE_BAD_CODE   (io::get(EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data));
    ffdc.set_M_WT_CLK_LANE_INVERTED(io::get(EDIP_RX_WT_CLK_LANE_INVERTED, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_CLK_LANE_BAD_CODE   (INVALID_FFDC);
        ffdc.set_M_WT_CLK_LANE_INVERTED(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Master Deskew
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Master Eye Optimization
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDIP_RX_GLBSM_STAT1_EO_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_EYE_OPT_STATE(io::get(EDIP_RX_EYE_OPT_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_EYE_OPT_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_CTL_CNTL13_EO_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_HIST_MIN_EYE_WIDTH(      io::get(EDIP_RX_HIST_MIN_EYE_WIDTH, l_data));
    ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE( io::get(EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data));
    ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID(io::get(EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_HIST_MIN_EYE_WIDTH      (INVALID_FFDC);
        ffdc.set_M_HIST_MIN_EYE_WIDTH_LANE (INVALID_FFDC);
        ffdc.set_M_HIST_MIN_EYE_WIDTH_VALID(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Master Repair
    ///////////////////////////////////////////////////////////////////////////
    l_rc =  io::read(EDIP_RX_GLBSM_STAT4_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_RPR_STATE(io::get(EDIP_RX_RPR_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_RPR_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDIP_RX_GLBSM_STAT9_E_PG, i_mtgt, GRP3, LN0, l_data);
    ffdc.set_M_BAD_LANE1    (io::get(EDIP_RX_BAD_LANE1,     l_data));
    ffdc.set_M_BAD_LANE2    (io::get(EDIP_RX_BAD_LANE2,     l_data));
    ffdc.set_M_BAD_LANE_CODE(io::get(EDIP_RX_BAD_LANE_CODE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_M_BAD_LANE1    (INVALID_FFDC);
        ffdc.set_M_BAD_LANE2    (INVALID_FFDC);
        ffdc.set_M_BAD_LANE_CODE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Master Functional Mode
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Slave Common
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDI_RX_TRAINING_START_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_WDERF_START (io::get(EDI_RX_START_WDERF_ALIAS,  l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_WDERF_START (INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_TRAINING_STATUS_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_WDERF_DONE  (io::get(EDI_RX_WDERF_DONE_ALIAS,   l_data));
    ffdc.set_S_WDERF_FAILED(io::get(EDI_RX_WDERF_FAILED_ALIAS, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_WDERF_DONE  (INVALID_FFDC);
        ffdc.set_S_WDERF_FAILED(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_LANE_BAD_VEC_0_15_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_LANE_BAD_0_15(io::get(EDI_RX_LANE_BAD_VEC_0_15, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_LANE_BAD_0_15(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }


    l_rc = io::read(EDI_RX_LANE_BAD_VEC_16_31_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_LANE_BAD_16_23(io::get(EDI_RX_LANE_BAD_VEC_16_31, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_LANE_BAD_16_23(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_LANE_DISABLED_VEC_0_15_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_LANE_DISABLED_VEC_0_15(io::get(EDI_RX_LANE_DISABLED_VEC_0_15, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_LANE_DISABLED_VEC_0_15(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_LANE_DISABLED_VEC_16_31_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_LANE_DISABLED_VEC_16_23(io::get(EDI_RX_LANE_DISABLED_VEC_16_31, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_LANE_DISABLED_VEC_16_23(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ffdc.set_S_MAIN_INIT_STATE(INVALID_FFDC);

    ///////////////////////////////////////////////////////////////////////////
    // Slave Wiretest
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDI_RX_WIRETEST_STATE_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_WIRETEST_WTM_STATE(io::get(EDI_RX_WTM_STATE, l_data));
    ffdc.set_S_WIRETEST_WTR_STATE(io::get(EDI_RX_WTR_STATE, l_data));
    ffdc.set_S_WIRETEST_WTL_SM_STATUS(io::get(EDI_RX_WTL_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_WIRETEST_WTM_STATE(INVALID_FFDC);
        ffdc.set_S_WIRETEST_WTR_STATE(INVALID_FFDC);
        ffdc.set_S_WIRETEST_WTL_SM_STATUS(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_WIRETEST_LANEINFO_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_WTR_BAD_LANE_COUNT(io::get(EDI_RX_WTR_BAD_LANE_COUNT, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_WTR_BAD_LANE_COUNT(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc =  io::read(EDI_RX_WT_CLK_STATUS_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_CLK_LANE_BAD_CODE   (io::get(EDI_RX_WT_CLK_LANE_BAD_CODE, l_data));
    ffdc.set_S_WT_CLK_LANE_INVERTED(io::get(EDI_RX_WT_CLK_LANE_INVERTED, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_CLK_LANE_BAD_CODE   (INVALID_FFDC);
        ffdc.set_S_WT_CLK_LANE_INVERTED(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Slave Deskew
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Slave Eye Optimization
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDI_RX_EO_RECAL_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_EYE_OPT_STATE(io::get(EDI_RX_EYE_OPT_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_EYE_OPT_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ffdc.set_S_HIST_MIN_EYE_WIDTH      (INVALID_FFDC);
    ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE (INVALID_FFDC);
    ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID(INVALID_FFDC);

    ///////////////////////////////////////////////////////////////////////////
    // Slave Repair
    ///////////////////////////////////////////////////////////////////////////
    l_rc = io::read(EDI_RX_STATIC_REPAIR_STATE_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_RPR_STATE(io::get(EDI_RX_RPR_STATE, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_RPR_STATE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    l_rc = io::read(EDI_RX_BAD_LANE_ENC_GCRMSG_PG, i_stgt, GRP0, LN0, l_data);
    ffdc.set_S_BAD_LANE1    (io::get(EDI_RX_BAD_LANE1_GCRMSG,     l_data));
    ffdc.set_S_BAD_LANE2    (io::get(EDI_RX_BAD_LANE2_GCRMSG,     l_data));
    ffdc.set_S_BAD_LANE_CODE(io::get(EDI_RX_BAD_LANE_CODE_GCRMSG, l_data));

    if(l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ffdc.set_S_BAD_LANE1    (INVALID_FFDC);
        ffdc.set_S_BAD_LANE2    (INVALID_FFDC);
        ffdc.set_S_BAD_LANE_CODE(INVALID_FFDC);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Slave Functional Mode
    ///////////////////////////////////////////////////////////////////////////

    // Log FFDC
    ffdc.execute();

    return l_ffdc_rc;

    return fapi2::FAPI2_RC_SUCCESS;
}

/**
 * @brief Starts I/O Training on Centuar (EDI).  The slave target must start
 *   training before the master.  This function also assumes that dccal(tx
 *   impedance calibration and rx offset calibration) are complete.
 * @param[in]  i_tgt    Fapi2 Target
 * @param[in]  i_wderf  Represents which training substeps are run.
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_dmi_cn_start(const CN_TGT& i_tgt, const State i_wderf)
{
    const uint8_t GRP0 = 0;
    const uint8_t LN0  = 0;
    return io::rmw(EDI_RX_START_WDERF_ALIAS, i_tgt, GRP0, LN0, static_cast<uint64_t>(i_wderf));
}


/**
 * @brief Starts I/O Training on DMI (EDI Plus).  The slave target must start
 *   training before the master.  This function also assumes that dccal(tx
 *   impedance calibration and rx offset calibration) are complete.
 * @param[in]  i_tgt    Fapi2 Target
 * @param[in]  i_wderf  Represents which training substeps are run.
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_dmi_proc_start(const DMI_TGT& i_tgt, const State i_wderf)
{
    const uint8_t GRP3 = 3;
    const uint8_t LN0  = 0;
    return io::rmw(EDIP_RX_START_WDERF_ALIAS, i_tgt, GRP3, LN0, static_cast<uint64_t>(i_wderf));
}

/**
 * @brief This function polls the EDI Plus training logic until the training
 *   is complete.  During the case of an error/timeout, the code will log
 *   FFDC data, which is added to the original error.
 * @param[in]  i_mtgt     Master Target
 * @param[in]  i_stgt     Slave Target
 * @param[in]  i_started  The started EDI/EDI Plus training substeps
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_poll(const DMI_TGT& i_mtgt, const CN_TGT& i_stgt, const State i_started)
{
    FAPI_IMP("linktrain_poll: P9 I/O EDI+/EDI DMI Entering");

    const uint8_t  MAXLOOPS         = 100;
    const uint64_t DELAY_1MS        = 1000000;
    const uint64_t DELAY_SIM_CYCLES = 20000000;  // Set lower due to sim speed up
    const uint8_t  GRP3             = 3;
    const uint8_t  LN0              = 0;
    uint8_t        l_loops          = 0;
    uint64_t       l_reg_data       = 0;
    State          l_done_state     = State::NONE;
    State          l_failed_state   = State::NONE;

    // In the P9 EDI+ Xbus unit model, polling finishes in
    //   17 loops @ 20 million cycles = 340 million cycles
    // For hardware timeout, we used what was used in p8, 1ms @ 100 cycles for
    //   a max of 100ms to complete training.
    while(++l_loops < MAXLOOPS)
    {
        // Get Done/Failed WDERF Status
        FAPI_TRY(io::read(EDIP_RX_CTL_STAT1_E_PG, i_mtgt, GRP3, LN0, l_reg_data));
        l_done_state   = static_cast<State>(io::get(EDIP_RX_WDERF_DONE_ALIAS,   l_reg_data));
        l_failed_state = static_cast<State>(io::get(EDIP_RX_WDERF_FAILED_ALIAS, l_reg_data));

        // Check if all substeps are complete
        if(i_started == (i_started & l_done_state))
        {
            break;
        }

        // Check if any substeps have failed.
        if(l_failed_state != State::NONE)
        {
            break;
        }

        FAPI_TRY(fapi2::delay(DELAY_1MS, DELAY_SIM_CYCLES));
    }

    // Check the error conditions.
    if(l_failed_state != State::NONE)
    {
        FAPI_ERR("I/O EDI+ DMI Link Training Failed.");
        FAPI_TRY(add_linktrain_ffdc(i_mtgt, i_stgt, false));
    }
    else if(i_started != (i_started & l_done_state))
    {
        FAPI_ERR("I/O EDI+ DMI Link Training Timeout.");
        FAPI_TRY(add_linktrain_ffdc(i_mtgt, i_stgt, true));
    }
    else
    {
        FAPI_INF("linktrain_poll: P9 I/O EDI+/EDI DMI Training Successful in %d loops.", l_loops);
    }

fapi_try_exit:
    FAPI_IMP("linktrain_poll: P9 I/O EDI+/EDI DMI Exiting");
    return fapi2::current_err;
}


/**
 * @brief Enables the Tx Serializer Sync on DMI (EDI Plus).
 * @param[in]  i_mtgt   Master Fapi2 Target
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_on(const DMI_TGT& i_mtgt)
{
    FAPI_IMP("tx_serializer_sync_power_on: I/O EDI+ DMI Proc Entering");
    const uint8_t DMI_TX_LANES = 17;
    const uint8_t GRP3         = 3;
    const uint8_t LN0          = 0;

    FAPI_TRY(io::rmw(EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_mtgt, GRP3, LN0, 0));
    FAPI_TRY(io::rmw(EDIP_TX_CLK_RUN_COUNT         , i_mtgt, GRP3, LN0, 0));
    FAPI_TRY(io::rmw(EDIP_TX_CLK_RUN_COUNT         , i_mtgt, GRP3, LN0, 1));
    FAPI_TRY(io::rmw(EDIP_TX_CLK_UNLOAD_CLK_DISABLE, i_mtgt, GRP3, LN0, 1));

    for(uint8_t lane = 0; lane < DMI_TX_LANES; ++lane)
    {
        FAPI_TRY(io::rmw(EDIP_TX_UNLOAD_CLK_DISABLE, i_mtgt, GRP3, lane, 0x0));
    }

fapi_try_exit:
    FAPI_IMP("tx_serializer_sync_power_on: I/O EDI+ DMI Proc Exiting");
    return fapi2::current_err;
}

/**
 * @brief Disables the Tx Serializer Sync on DMI (EDI Plus).
 * @param[in]  i_mtgt   Master Fapi2 Target
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode tx_serializer_sync_power_off(const DMI_TGT& i_mtgt)
{
    FAPI_IMP("tx_serializer_sync_power_off: I/O EDI+ DMI Proc Entering");
    const uint8_t DMI_TX_LANES = 17;
    const uint8_t GRP3         = 3;

    for(uint8_t lane = 0; lane < DMI_TX_LANES; ++lane)
    {
        FAPI_TRY(io::rmw(EDIP_TX_UNLOAD_CLK_DISABLE, i_mtgt, GRP3, lane, 0x1));
    }

fapi_try_exit:
    FAPI_IMP("tx_serializer_sync_power_off: I/O EDI+ DMI Proc Exiting");
    return fapi2::current_err;
}

/**
 * @brief Reads bad lane vector data from the
 *   passed target and stores the data in the vector.
 * @param[in]  i_target     CN Fapi2 Target
 * @param[out] o_data       Data of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode get_dmi_cn_bad_lane_data(const CN_TGT& i_tgt, uint32_t& o_data)
{
    FAPI_IMP("P9 I/O EDI DMI Centaur Entering");
    const uint8_t GRP0   = 0;
    const uint8_t LN0    = 0;
    uint64_t      l_data = 0;

    FAPI_TRY(io::read(EDI_RX_LANE_BAD_VEC_0_15, i_tgt, GRP0, LN0, l_data));
    o_data = (io::get(EDI_RX_LANE_BAD_VEC_0_15, l_data) << 16) & 0xFFFF0000;

    FAPI_TRY(io::read(EDI_RX_LANE_BAD_VEC_16_31, i_tgt, GRP0, LN0, l_data));
    o_data |= (io::get(EDI_RX_LANE_BAD_VEC_16_31, l_data) & 0x0000FFFF);

fapi_try_exit:
    FAPI_IMP("P9 I/O EDI DMI Centaur Exiting");
    return fapi2::current_err;
}

/**
 * @brief Reads bad lane vector data from the
 *   passed target and stores the data in the vector.
 * @param[in]  i_target     Fapi2 Target
 * @param[out] o_data       Data of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode get_dmi_proc_bad_lane_data(const DMI_TGT& i_tgt, uint32_t& o_data)
{
    FAPI_IMP("P9 I/O EDI+ DMI Proc Entering");
    const uint8_t GRP3   = 3;
    const uint8_t LN0    = 0;
    uint64_t      l_data = 0;

    FAPI_TRY(io::read(EDIP_RX_LANE_BAD_VEC_0_15, i_tgt, GRP3, LN0, l_data));
    o_data = (io::get(EDIP_RX_LANE_BAD_VEC_0_15, l_data) << 8) & 0x00FFFF00;

    FAPI_TRY(io::read(EDIP_RX_LANE_BAD_VEC_16_23, i_tgt, GRP3, LN0, l_data));
    o_data |= (io::get(EDIP_RX_LANE_BAD_VEC_16_23, l_data) & 0x000000FF);

fapi_try_exit:
    FAPI_IMP("P9 I/O EDI+ DMI Proc Exiting");
    return fapi2::current_err;
}

/**
 * @brief Copmares the bad lane vector pre and post training.  If the data is
 *   the same, then we will want to clear the firs, since the firs have already
 *   been recorded.
 * @param[in]  i_tgt     CN Fapi2 Target
 * @param[out] o_data    Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode check_dmi_cn_bad_lane_data(
    const CN_TGT&  i_tgt,
    uint32_t       i_pre_bad_lane_data,
    uint32_t       i_post_bad_lane_data)
{
    FAPI_IMP("P9 I/O EDI DMI Centaur Entering");
    const uint8_t GRP0   = 0;
    const uint8_t LN0    = 0;
    uint64_t      l_data = 0;

    // If the bad lane vector matches pre to post training, then the same bad
    //   lanes that were previously found, were found again.  These bad lanes have
    //   already been reported.  So we will clear the first related to these bad
    //   lanes
    if(i_pre_bad_lane_data == i_post_bad_lane_data)
    {
        FAPI_DBG("I/O EDI DMI Centaur Pre/Post Bad Lane Data Match");

        // If the entire bad lane vector equals 0, then we don't need to clear
        //   any firs.
        if(i_pre_bad_lane_data != 0)
        {
            FAPI_DBG("I/O EDI DMI Centaur Clearing Firs");

            FAPI_TRY(p9_io_dmi_cn_clear_firs(i_tgt));

            // Clear BUS0_SPARE_DEPLOYED (Bit 9).
            FAPI_TRY(io::read(EDI_SCOM_FIR_PB, i_tgt, GRP0, LN0, l_data));
            l_data &= 0xFF7FFFFFFFFFFFFFull;
            FAPI_TRY(io::write(EDI_SCOM_FIR_PB, i_tgt, GRP0, LN0, l_data));
        }
    }

fapi_try_exit:
    FAPI_IMP("P9 I/O EDI DMI Centaur Exiting");
    return fapi2::current_err;
}


/**
 * @brief Copmares the bad lane vector pre and post training.  If the data is
 *   the same, then we will want to clear the firs, since the firs have already
 *   been recorded.
 * @param[in]  i_tgt     Fapi2 Target
 * @param[out] o_data    Data Vector of bad lane vector data
 * @retval     ReturnCode
 */
fapi2::ReturnCode check_dmi_proc_bad_lane_data(
    const DMI_TGT&  i_tgt,
    uint32_t       i_pre_bad_lane_data,
    uint32_t       i_post_bad_lane_data)
{
    FAPI_IMP("P9 I/O EDI+ DMI Proc Entering");
    const uint8_t GRP3   = 3;
    const uint8_t LN0    = 0;
    uint64_t      l_data = 0;

    // If the bad lane vector matches pre to post training, then the same bad
    //   lanes that were previously found, were found again.  These bad lanes have
    //   already been reported.  So we will clear the first related to these bad
    //   lanes
    if(i_pre_bad_lane_data == i_post_bad_lane_data)
    {
        FAPI_DBG("I/O EDI+ DMI Proc Pre/Post Bad Lane Data Match");

        // If the entire bad lane vector equals 0, then we don't need to clear
        //   any firs.
        if(i_pre_bad_lane_data != 0)
        {
            FAPI_DBG("I/O EDI+ DMI Proc Clearing Firs");

            FAPI_TRY(p9_io_dmi_proc_clear_firs(i_tgt));

            // Clear BUS0_SPARE_DEPLOYED (Bit 9).
            FAPI_TRY(io::read(EDIP_SCOM_FIR_PB, i_tgt, GRP3, LN0, l_data));
            l_data &= 0xFF7FFFFFFFFFFFFFull;
            FAPI_TRY(io::write(EDIP_SCOM_FIR_PB, i_tgt, GRP3, LN0, l_data));
        }
    }

fapi_try_exit:
    FAPI_IMP("P9 I/O EDI+ DMI Proc Exiting");
    return fapi2::current_err;
}


/**
 * @brief A HWP that runs on every link of the DMI(EDI+)
 *
 * @param[in] i_mtgt   Reference to the Master Target
 * @param[in] i_stgt  Reference to the Slave Target
 *
 * @return FAPI2_RC_SUCCESS on success, error otherwise
 */
fapi2::ReturnCode p9_io_dmi_linktrain(const DMI_TGT& i_mtgt, const CN_TGT& i_stgt)
{
    FAPI_IMP("p9_io_dmi_linktrain: P9 I/O EDI+/EDI DMI Entering");


    uint32_t l_m_pre_bad_data  = 0;
    uint32_t l_m_post_bad_data = 0;
    uint32_t l_s_pre_bad_data   = 0;
    uint32_t l_s_post_bad_data  = 0;

    char l_mtgt_str[fapi2::MAX_ECMD_STRING_LEN];
    char l_stgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_mtgt, l_mtgt_str, fapi2::MAX_ECMD_STRING_LEN);
    fapi2::toString(i_stgt, l_stgt_str, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_DBG("I/O DMI Targets: Target(%s) Connected(%s)", l_mtgt_str, l_stgt_str);

    // Shorten timers if we are running in simulation
    FAPI_TRY(p9_io_dmi_proc_shorten_timers(i_mtgt));
    FAPI_TRY(p9_io_dmi_cn_shorten_timers(i_stgt));


    // Record the Bad Lane Vectors Prior to link training.
    FAPI_TRY(get_dmi_proc_bad_lane_data(i_mtgt, l_m_pre_bad_data),
             "Pre Training: Get Bad Lane Vector Failed on Master");
    FAPI_TRY(get_dmi_cn_bad_lane_data(i_stgt, l_s_pre_bad_data),
             "Pre Training: Get Bad Lane Vector Failed on Slave");


    // Clock Serializer Init -- isn't strictly necessary but does line up the
    //   clock serializer counter wit the data slices.
    FAPI_TRY(tx_serializer_sync_power_on(i_mtgt), "tx_serializer_sync_power_on Failed.");

    // TODO : For Centaur Only, Scan in pll settings with PFD360->1

    // Start Slave/Master Target Link Training
    FAPI_TRY(linktrain_dmi_cn_start(i_stgt, State::WIRETEST), "P9 I/O DMI CN Start W Failed.");
    FAPI_TRY(linktrain_dmi_proc_start(i_mtgt, State::WIRETEST), "P9 I/O DMI Proc Start W Failed.");

    // Poll for Training to Complete on Master Target
    FAPI_TRY(linktrain_poll(i_mtgt, i_stgt, State::WIRETEST), "P9 I/O DMI Proc Poll W Failed.");

    // TODO : For Centaur Only, Scan in pll settings with PFD360->0

    FAPI_TRY(linktrain_dmi_cn_start(i_stgt, State::DESKEW | State::EYEOPT), "P9 I/O DMI CN Start DERF Failed.");
    FAPI_TRY(linktrain_dmi_proc_start(i_mtgt, State::DESKEW | State::EYEOPT), "P9 I/O DMI Proc Start DERF Failed.");

    // Poll for Training to Complete on Master Target
    FAPI_TRY(linktrain_poll(i_mtgt, i_stgt, State::DESKEW | State::EYEOPT), "P9 I/O DMI Proc Poll DERF Failed.");

    // DE / RF needs to split up due to HW220654

    FAPI_TRY(linktrain_dmi_cn_start(i_stgt, State::REPAIR | State::FUNCTIONAL), "P9 I/O DMI CN Start DERF Failed.");
    FAPI_TRY(linktrain_dmi_proc_start(i_mtgt, State::REPAIR | State::FUNCTIONAL), "P9 I/O DMI Proc Start DERF Failed.");

    // Poll for Training to Complete on Master Target
    FAPI_TRY(linktrain_poll(i_mtgt, i_stgt, State::REPAIR | State::FUNCTIONAL), "P9 I/O DMI Proc Poll DERF Failed.");


    // >> HW390103 -- Leave Tx Unload Clock Disable Off
    //// Disable the Tx Serializer Sync
    //FAPI_TRY(tx_serializer_sync_power_off(l_mtgt, l_stgt, GRP0),
    //          "tx_serializer_sync_power_off Failed.");
    // << HW390103 -- Leave Tx Unload Clock Disable Off

    // Record the Bad Lane Vectors after link training.
    FAPI_TRY(get_dmi_proc_bad_lane_data(i_mtgt, l_m_post_bad_data),
             "Post Training: Get Bad Lane Vector Failed on Master");
    FAPI_TRY(get_dmi_cn_bad_lane_data(i_stgt, l_s_post_bad_data),
             "Post Training: Get Bad Lane Vector Failed on Master");


    // Check to see if the bad lanes match the bad lanes prior to link training.
    //   If so, then that error has already been logged and we can clear the firs.
    FAPI_TRY(check_dmi_proc_bad_lane_data(i_mtgt, l_m_pre_bad_data, l_m_post_bad_data),
             "Post Training: Evaluate Firs Failed on Master");
    FAPI_TRY(check_dmi_cn_bad_lane_data(i_stgt, l_s_pre_bad_data, l_s_post_bad_data),
             "Post Training: Evaluate Firs Failed on Slave");


fapi_try_exit:

    FAPI_IMP("p9_io_dmi_linktrain: P9 I/O EDI+/EDI DMI Exiting");
    return fapi2::current_err;
}

