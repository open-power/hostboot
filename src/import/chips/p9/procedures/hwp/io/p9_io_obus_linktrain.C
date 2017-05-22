/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_linktrain.C $ */
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
/// @file p9_io_obus_linktrain.C
/// @brief I/O Link Training on the Abus(Obus PHY) Links.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Train the link.
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
#include <p9_io_obus_linktrain.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9_io_common.H>

//-----------------------------------------------------------------------------
//  Definitions
//-----------------------------------------------------------------------------

/**
 * @brief Adds I/O FFDC Link data to the Error
 * @param[in]  i_tgt    Target
 * @param[in]  i_ctgt   Connected Target
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode add_linktrain_ffdc(
    const OBUS_TGT& i_tgt,
    const OBUS_TGT& i_ctgt,
    const bool i_timeout)
{
    /*
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
        fapi2::IO_OBUS_LINKTRAIN_ERROR ffdc(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, l_ffdc_rc);

        ffdc.set_M_TARGET(i_mtgt);
        ffdc.set_S_TARGET(i_stgt);
        ffdc.set_TIMEOUT (i_timeout);

        ///////////////////////////////////////////////////////////////////////////
        // Master Common
        ///////////////////////////////////////////////////////////////////////////
        l_rc = io::read(EDIP_RX_CTL_CNTL1_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_WDERF_START (io::get(EDIP_RX_START_WDERF_ALIAS,  l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_WDERF_START (INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT1_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_WDERF_DONE  (io::get(EDIP_RX_WDERF_DONE_ALIAS,   l_data));
        ffdc.set_M_WDERF_FAILED(io::get(EDIP_RX_WDERF_FAILED_ALIAS, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_WDERF_DONE  (INVALID_FFDC);
            ffdc.set_M_WDERF_FAILED(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT2_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_LANE_BAD_0_15(io::get(EDIP_RX_LANE_BAD_VEC_0_15, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_LANE_BAD_0_15(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }


        l_rc = io::read(EDIP_RX_CTL_STAT4_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_LANE_BAD_16_23(io::get(EDIP_RX_LANE_BAD_VEC_16_23, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_LANE_BAD_16_23(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_MODE11_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_LANE_DISABLED_VEC_0_15(io::get(EDIP_RX_LANE_DISABLED_VEC_0_15, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_LANE_DISABLED_VEC_0_15(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_MODE12_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_LANE_DISABLED_VEC_16_23(io::get(EDIP_RX_LANE_DISABLED_VEC_16_23, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_LANE_DISABLED_VEC_16_23(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_MAIN_INIT_STATE(io::get(EDIP_RX_MAIN_INIT_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_MAIN_INIT_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        ///////////////////////////////////////////////////////////////////////////
        // Master Wiretest
        ///////////////////////////////////////////////////////////////////////////
        l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_WIRETEST_WTM_STATE(io::get(EDIP_RX_WTM_STATE, l_data));
        ffdc.set_M_WIRETEST_WTR_STATE(io::get(EDIP_RX_WTR_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_WIRETEST_WTM_STATE(INVALID_FFDC);
            ffdc.set_M_WIRETEST_WTR_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT3_EO_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_WIRETEST_WTL_SM_STATUS(io::get(EDIP_RX_WTL_SM_STATUS, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_WIRETEST_WTL_SM_STATUS(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT2_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_WTR_BAD_LANE_COUNT(io::get(EDIP_RX_WTR_BAD_LANE_COUNT, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_WTR_BAD_LANE_COUNT(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc =  io::read(EDIP_RX_CTL_STAT5_E_PG, i_mtgt, i_grp, LN0, l_data);
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
        l_rc = io::read(EDIP_RX_GLBSM_STAT1_EO_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_EYE_OPT_STATE(io::get(EDIP_RX_EYE_OPT_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_EYE_OPT_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_CNTL13_EO_PG, i_mtgt, i_grp, LN0, l_data);
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
        l_rc =  io::read(EDIP_RX_GLBSM_STAT4_E_PG, i_mtgt, i_grp, LN0, l_data);
        ffdc.set_M_RPR_STATE(io::get(EDIP_RX_RPR_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_M_RPR_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT9_E_PG, i_mtgt, i_grp, LN0, l_data);
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
        l_rc = io::read(EDIP_RX_CTL_CNTL1_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_WDERF_START (io::get(EDIP_RX_START_WDERF_ALIAS,  l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_WDERF_START (INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT1_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_WDERF_DONE  (io::get(EDIP_RX_WDERF_DONE_ALIAS,   l_data));
        ffdc.set_S_WDERF_FAILED(io::get(EDIP_RX_WDERF_FAILED_ALIAS, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_WDERF_DONE  (INVALID_FFDC);
            ffdc.set_S_WDERF_FAILED(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT2_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_LANE_BAD_0_15(io::get(EDIP_RX_LANE_BAD_VEC_0_15, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_LANE_BAD_0_15(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }


        l_rc = io::read(EDIP_RX_CTL_STAT4_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_LANE_BAD_16_23(io::get(EDIP_RX_LANE_BAD_VEC_16_23, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_LANE_BAD_16_23(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_MODE11_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_LANE_DISABLED_VEC_0_15(io::get(EDIP_RX_LANE_DISABLED_VEC_0_15, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_LANE_DISABLED_VEC_0_15(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_MODE12_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_LANE_DISABLED_VEC_16_23(io::get(EDIP_RX_LANE_DISABLED_VEC_16_23, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_LANE_DISABLED_VEC_16_23(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_MAIN_INIT_STATE(io::get(EDIP_RX_MAIN_INIT_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_MAIN_INIT_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        ///////////////////////////////////////////////////////////////////////////
        // Slave Wiretest
        ///////////////////////////////////////////////////////////////////////////
        l_rc = io::read(EDIP_RX_GLBSM_STAT1_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_WIRETEST_WTM_STATE(io::get(EDIP_RX_WTM_STATE, l_data));
        ffdc.set_S_WIRETEST_WTR_STATE(io::get(EDIP_RX_WTR_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_WIRETEST_WTM_STATE(INVALID_FFDC);
            ffdc.set_S_WIRETEST_WTR_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_STAT3_EO_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_WIRETEST_WTL_SM_STATUS(io::get(EDIP_RX_WTL_SM_STATUS, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_WIRETEST_WTL_SM_STATUS(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT2_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_WTR_BAD_LANE_COUNT(io::get(EDIP_RX_WTR_BAD_LANE_COUNT, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_WTR_BAD_LANE_COUNT(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc =  io::read(EDIP_RX_CTL_STAT5_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_CLK_LANE_BAD_CODE   (io::get(EDIP_RX_WT_CLK_LANE_BAD_CODE, l_data));
        ffdc.set_S_WT_CLK_LANE_INVERTED(io::get(EDIP_RX_WT_CLK_LANE_INVERTED, l_data));

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
        l_rc = io::read(EDIP_RX_GLBSM_STAT1_EO_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_EYE_OPT_STATE(io::get(EDIP_RX_EYE_OPT_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_EYE_OPT_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_CTL_CNTL13_EO_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_HIST_MIN_EYE_WIDTH(      io::get(EDIP_RX_HIST_MIN_EYE_WIDTH, l_data));
        ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE( io::get(EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, l_data));
        ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID(io::get(EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_HIST_MIN_EYE_WIDTH      (INVALID_FFDC);
            ffdc.set_S_HIST_MIN_EYE_WIDTH_LANE (INVALID_FFDC);
            ffdc.set_S_HIST_MIN_EYE_WIDTH_VALID(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        ///////////////////////////////////////////////////////////////////////////
        // Slave Repair
        ///////////////////////////////////////////////////////////////////////////
        l_rc = io::read(EDIP_RX_GLBSM_STAT4_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_RPR_STATE(io::get(EDIP_RX_RPR_STATE, l_data));

        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ffdc.set_S_RPR_STATE(INVALID_FFDC);
            l_rc = fapi2::FAPI2_RC_SUCCESS;
        }

        l_rc = io::read(EDIP_RX_GLBSM_STAT9_E_PG, i_stgt, i_grp, LN0, l_data);
        ffdc.set_S_BAD_LANE1    (io::get(EDIP_RX_BAD_LANE1,     l_data));
        ffdc.set_S_BAD_LANE2    (io::get(EDIP_RX_BAD_LANE2,     l_data));
        ffdc.set_S_BAD_LANE_CODE(io::get(EDIP_RX_BAD_LANE_CODE, l_data));

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

    */
    return fapi2::FAPI2_RC_SUCCESS;
}

/**
 * @brief Starts I/O Training on Abus (Obus PHY)).  The slave target must start
 *   training before the master.  This function also assumes that dccal(tx
 *   impedance calibration and rx offset calibration) are complete.
 * @param[in]  i_tgt    Fapi2 Target
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_start(const OBUS_TGT& i_tgt)
{
    FAPI_IMP("linktrain_start: P9 I/O OPT Abus Entering");


    FAPI_IMP("linktrain_start: P9 I/O OPT Abus Exiting");
    return fapi2::current_err;
}

/**
 * @brief This function polls the EDI Plus training logic until the training
 *   is complete.  During the case of an error/timeout, the code will log
 *   FFDC data, which is added to the original error.
 * @param[in]  i_mtgt     Master Target
 * @param[in]  i_stgt     Slave Target
 * @retval     fapi2::ReturnCode
 */
fapi2::ReturnCode linktrain_poll(
    const OBUS_TGT& i_mtgt,
    const OBUS_TGT& i_stgt)
{
    FAPI_IMP("linktrain_poll: P9 I/O OPT Abus Entering");

    FAPI_IMP("linktrain_poll: P9 I/O OPT Abus Exiting");
    return fapi2::current_err;
}

/**
 * @brief A HWP that runs on every link of the ABUS(OPT)
 * @param[in] i_mode  Linktraining Mode
 * @param[in] i_tgt   Reference to the Target
 * @param[in] i_ctgt  Reference to the Connected Target
 * @retval    ReturnCode
 */
fapi2::ReturnCode p9_io_obus_linktrain(const OBUS_TGT& i_tgt, const OBUS_TGT& i_ctgt)
{
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Entering");

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    char l_ctgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt,  l_tgt_str,  fapi2::MAX_ECMD_STRING_LEN);
    fapi2::toString(i_ctgt, l_ctgt_str, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_DBG("I/O Abus: Target(%s) Connected(%s)", l_tgt_str, l_ctgt_str);


    // Start Slave/Master Target Link Training
    FAPI_TRY(linktrain_start(i_ctgt), "Connected Training Failed");
    FAPI_TRY(linktrain_start(i_tgt), "Training Failed.");


    // Poll for Training to Complete on Master Target
    FAPI_TRY(linktrain_poll(i_tgt, i_ctgt), "Obus Train Polling Failed");


fapi_try_exit:
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Exiting");
    return fapi2::current_err;
}
