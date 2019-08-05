/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9a_io_omi_dccal.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p9a_io_omi_dccal.C
/// @brief Train the Link.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Run Dccal
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9a_io_omi_dccal.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------

namespace P9A_IO_OMI_DCCAL
{

/**
 * @brief Converts a decimal value to a thermometer code
 * @param[in] i_dec Decimal Value
 * @retval    Thermometer Value
 */
uint32_t toTherm(const uint32_t i_dec)
{
    return ((0x1 << i_dec) - 1 );
}

/**
 * @brief Converts a decimal value to a thermometer code with a MSB 1/2 strength bit
 * @param[in] i_dec   Decimal Value
 * @param[in] i_width Width of Register
 * @retval Thermometer Value
 */
uint32_t toThermWithHalf(const uint32_t i_dec, const uint8_t i_width)
{
    // If the LSB of the 2r equivalent is on, then we need to set the 2r bit (MSB)
    uint32_t halfOn = (i_dec & 0x1) << (i_width - 1);

    // Shift the 2r equivalent to a 1r value and convert to a thermometer code.
    uint32_t x1Equivalent ((0x1 << (i_dec >> 0x1)) - 1);

    // combine 1r equivalent thermometer code + the 2r MSB value.
    return halfOn | x1Equivalent ;
}

/**
 * @brief Tx Z Impedance Calibration Get Results
 * @param[in] io_pvalx4  Tx Zcal P-value X4
 * @param[in] io_nvalx4  Tx Zcal N-value X4
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_verify_results(uint32_t& io_pvalx4, uint32_t& io_nvalx4)
{
    // l_zcal_p and l_zcal_n are 9 bit registers
    // These are also 4x of a 1R segment
    const uint32_t X4_MIN = 16 * 4; // 16 segments * 4 = 64 (0x40)
    const uint32_t X4_MAX = 33 * 4; // 33 segments * 4 = 132(0x84)
    FAPI_IMP("tx_zcal_verify_results: I/O OMI Entering");

    FAPI_INF("Min/Max Allowed(0x%X,0x%X) Read Pval/Nval(0x%X,0x%X)",
             X4_MIN, X4_MAX, io_pvalx4, io_nvalx4);

    if(io_pvalx4 > X4_MAX)
    {
        FAPI_ERR("I/O OMI Tx Zcal Pval(0x%X) > Max Allowed(0x%X); Code will override with 0x%X and continue.",
                 io_pvalx4, X4_MAX, X4_MAX);
        io_pvalx4 = X4_MAX;
    }

    if(io_nvalx4 > X4_MAX)
    {
        FAPI_ERR("I/O OMI Tx Zcal Nval(0x%X) > Max Allowed(0x%X); Code will override with 0x%X and continue.",
                 io_nvalx4, X4_MAX, X4_MAX);
        io_nvalx4 = X4_MAX;
    }

    if(io_pvalx4 < X4_MIN)
    {
        FAPI_ERR("I/O OMI Tx Zcal Pval(0x%X) < Min Allowed(0x%X); Code will override with 0x%X and continue.",
                 io_pvalx4, X4_MIN, X4_MIN);
        io_pvalx4 = X4_MIN;
    }

    if(io_nvalx4 < X4_MIN)
    {
        FAPI_ERR("I/O OMI Tx Zcal Nval(0x%X) < Min Allowed(0x%X); Code will override with 0x%X and continue.",
                 io_nvalx4, X4_MIN, X4_MIN);
        io_nvalx4 = X4_MIN;
    }

    FAPI_IMP("tx_zcal_verify_results: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_run_zcal(const OMIC_TGT i_tgt)
{
    const uint64_t DLY_20MS         = 20000000;
    const uint64_t DLY_10US         = 10000;
    const uint64_t DLY_10MIL_CYCLES = 10000000;
    const uint64_t DLY_1MIL_CYCLES  = 1000000;
    const uint32_t TIMEOUT          = 200;
    const uint8_t GRP0              = 0;
    const uint8_t LN0               = 0;
    uint32_t l_count                = 0;
    uint64_t l_data                 = 0;
    uint8_t  l_is_sim               = 0;

    FAPI_IMP("tx_run_zcal: I/O OMI Entering");

    ///////////////////////////////////////////////////////////////////////////
    /// Simulation Speed Up
    ///////////////////////////////////////////////////////////////////////////
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

    if(l_is_sim)
    {
        // To speed up simulation, xbus_unit model + pie driver
        //   without these settings: 50 million cycles
        //   with these settings: 13 million cycles
        io::set(OPT_TX_ZCAL_SM_MIN_VAL, 50, l_data);
        io::set(OPT_TX_ZCAL_SM_MAX_VAL, 52, l_data);
        FAPI_TRY(io::write(OPT_TX_IMPCAL_SWO2_PB, i_tgt, GRP0, LN0, l_data));
    }

    // Request to start Tx Impedance Calibration
    // The Done bit is read only pulse, must use pie driver or system model in sim
    FAPI_TRY(io::rmw(OPT_TX_ZCAL_REQ, i_tgt, GRP0, LN0, 1));

    // Delay before we start polling.  20ms was use from past p8 learning
    FAPI_TRY(fapi2::delay(DLY_20MS, DLY_10MIL_CYCLES));

    // Poll Until Tx Impedance Calibration is done or errors out
    FAPI_TRY(io::read(OPT_TX_IMPCAL_PB, i_tgt, GRP0, LN0, l_data));

    while((++l_count < TIMEOUT) &&
          !(io::get(OPT_TX_ZCAL_DONE, l_data) || io::get(EDIP_TX_ZCAL_ERROR, l_data)))
    {
        FAPI_DBG("tx_run_zcal: I/O OMI Tx Zcal Poll, Count(%d/%d).", l_count, TIMEOUT);

        // Delay for 10us between polls for a total of 22ms.
        FAPI_TRY(fapi2::delay(DLY_10US, DLY_1MIL_CYCLES));

        FAPI_TRY(io::read(OPT_TX_IMPCAL_PB, i_tgt, GRP0, LN0, l_data));
    }

    // Check for Zcal Done
    if(io::get(OPT_TX_ZCAL_DONE, l_data) == 1)
    {
        FAPI_DBG("I/O OMI Tx Zcal Poll Completed(%d/%d).", l_count, TIMEOUT);
    }

    // Check for Zcal Error
    if(io::get(OPT_TX_ZCAL_ERROR, l_data) == 1)
    {
        FAPI_ERR("I/O OMI Tx Z Calibration Error");
    }

    // Check for Zcal Timeout
    if(l_count >= TIMEOUT)
    {
        FAPI_ERR("I/O OMI Tx Z Calibration Timeout: Loops(%d)", l_count);
    }

fapi_try_exit:
    FAPI_IMP("tx_run_zcal: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration Apply Segments.  The results of the Tx Impedance
 *   calibration are applied with accounting for margining ,FFE Precursor, and FFE Postcursor.
 * @param[in] i_tgt      FAPI2 Target
 * @param[in] i_pvalx4   Tx Zcal P-value X4
 * @param[in] i_nvalx4   Tx Zcal N-value X4
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_apply(const OMIC_TGT i_tgt, const uint32_t i_pvalx4, const uint32_t i_nvalx4)
{
    FAPI_IMP("tx_zcal_apply: I/O OPT OMI Entering");
    const uint8_t  GRP0              = 0;
    const uint8_t  LN0               = 0;
    const uint8_t  PRE_WIDTH         = 5;
    const uint8_t  POST_WIDTH        = 7;
    const uint8_t  MAIN_WIDTH        = 7;
    const uint32_t PRECURSOR_X2_MAX  = ( 4 * 2) + (1); // 18
    const uint32_t POSTCURSOR_X2_MAX = ( 6 * 2) + (1); // 26
    const uint32_t MARGIN_X2_MAX     = ( 8 * 2) + (0); // 32
    const uint32_t MAIN_X2_MAX       = ( 6 * 2) + (1); // 26
    const uint32_t TOTAL_X2_MAX      = PRECURSOR_X2_MAX +
                                       POSTCURSOR_X2_MAX +
                                       (MARGIN_X2_MAX * 2) +
                                       MAIN_X2_MAX;

    uint8_t  margin_ratio      = 0;
    uint8_t  ffe_pre_coef      = 0;
    uint8_t  ffe_post_coef     = 0;
    uint32_t margin_sel        = 0;
    uint32_t p_pre_sel_x2      = 0;
    uint32_t n_pre_sel_x2      = 0;
    uint32_t p_post_sel_x2     = 0;
    uint32_t n_post_sel_x2     = 0;
    uint32_t margin_pu_sel_x2  = 0;
    uint32_t margin_pd_sel_x2  = 0;

    uint32_t pvalx2            = i_pvalx4 / 2;
    uint32_t nvalx2            = i_nvalx4 / 2;

    uint32_t p_pre_en_x2       = PRECURSOR_X2_MAX;
    uint32_t p_post_en_x2      = POSTCURSOR_X2_MAX;
    uint32_t p_margin_pu_en_x2 = MARGIN_X2_MAX;
    uint32_t p_margin_pd_en_x2 = MARGIN_X2_MAX;
    uint32_t p_main_en_x2      = MAIN_X2_MAX;
    int      pvalx2_int        = (int)pvalx2 - (int)TOTAL_X2_MAX;

    uint32_t n_pre_en_x2       = PRECURSOR_X2_MAX;
    uint32_t n_post_en_x2      = POSTCURSOR_X2_MAX;
    uint32_t n_margin_pu_en_x2 = MARGIN_X2_MAX;
    uint32_t n_margin_pd_en_x2 = MARGIN_X2_MAX;
    uint32_t n_main_en_x2      = MAIN_X2_MAX;
    int      nvalx2_int        = (int)nvalx2 - (int)TOTAL_X2_MAX;

    // During normal operation we will not use margining :: min(0, 0%) max(0.5, 50%)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_TX_MARGIN_RATIO, i_tgt, margin_ratio));

    //   FFE Precursor Tap Weight :: min(0.0, 0%) max(0.115, 11.5%)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_TX_FFE_PRECURSOR, i_tgt, ffe_pre_coef));

    //   FFE Postcursor Tap Weight :: min(0.0, 0%) max(0.2578, 25.8%)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OMI_TX_FFE_POSTCURSOR, i_tgt, ffe_post_coef));


    // We use the X2 here, since the LSB bit is a 1/2
    p_pre_sel_x2 = (pvalx2 * ffe_pre_coef) / 128;
    n_pre_sel_x2 = (nvalx2 * ffe_pre_coef) / 128;

    // We use the X2 here, since the LSB bit is a 1/2
    p_post_sel_x2 = (pvalx2 * ffe_post_coef) / 128;
    n_post_sel_x2 = (nvalx2 * ffe_post_coef) / 128;

    margin_pu_sel_x2 = (pvalx2 * margin_ratio) / (128 * 2);
    margin_pd_sel_x2 = (nvalx2 * margin_ratio) / (128 * 2);

    // Work on Pvalue
    if(pvalx2_int % 2) // Check if we need to add a half segment (2R)
    {
        --p_main_en_x2;
        ++pvalx2_int;
    }

    while(pvalx2_int < 0)
    {
        if(p_main_en_x2 > 1)
        {
            p_main_en_x2 -= 2;
        }
        else if((p_margin_pu_en_x2 + p_margin_pd_en_x2) > 0)
        {
            if(p_margin_pu_en_x2 == p_margin_pd_en_x2)
            {
                p_margin_pd_en_x2 -= 2;
            }
            else
            {
                p_margin_pu_en_x2 -= 2;
            }

        }

        pvalx2_int += 2; // Add a full segment
    }

    // Work on Nvalue
    if(nvalx2_int % 2) // Check if we need to add a half segment (2R)
    {
        --n_main_en_x2;
        ++nvalx2_int;
    }

    while(nvalx2_int < 0)
    {
        if(n_main_en_x2 > 1)
        {
            n_main_en_x2 -= 2;
        }
        else if((n_margin_pu_en_x2 + n_margin_pd_en_x2) > 0)
        {
            if(n_margin_pu_en_x2 == n_margin_pd_en_x2)
            {
                n_margin_pd_en_x2 -= 2;
            }
            else
            {
                n_margin_pu_en_x2 -= 2;
            }
        }

        nvalx2_int += 2; // Add a full segment
    }

    margin_sel =
        toTherm((margin_pu_sel_x2 + 1) / 2) & toTherm((margin_pd_sel_x2 + 1) / 2) &
        toTherm((p_margin_pu_en_x2 + 1) / 2) & toTherm((n_margin_pu_en_x2 + 1) / 2) &
        toTherm((p_margin_pd_en_x2 + 1) / 2) & toTherm((n_margin_pd_en_x2 + 1) / 2);


    // Setting Pre Cursor Values
    FAPI_TRY(io::rmw(OPT_TX_PSEG_PRE_EN , i_tgt, GRP0, LN0, toThermWithHalf(p_pre_en_x2 , PRE_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_PSEG_PRE_SEL, i_tgt, GRP0, LN0, toThermWithHalf(p_pre_sel_x2, PRE_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_PRE_EN , i_tgt, GRP0, LN0, toThermWithHalf(n_pre_en_x2 , PRE_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_PRE_SEL, i_tgt, GRP0, LN0, toThermWithHalf(n_pre_sel_x2, PRE_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_PSEG_POST_EN , i_tgt, GRP0, LN0, toThermWithHalf(p_post_en_x2 , POST_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_PSEG_POST_SEL, i_tgt, GRP0, LN0, toThermWithHalf(p_post_sel_x2, POST_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_POST_EN , i_tgt, GRP0, LN0, toThermWithHalf(n_post_en_x2 , POST_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_POST_SEL, i_tgt, GRP0, LN0, toThermWithHalf(n_post_sel_x2, POST_WIDTH)));

    // Setting Post Cursor Values
    FAPI_TRY(io::rmw(OPT_TX_PSEG_MARGINPD_EN, i_tgt, GRP0, LN0, toTherm((p_margin_pd_en_x2 + 1) / 2)));
    FAPI_TRY(io::rmw(OPT_TX_PSEG_MARGINPU_EN, i_tgt, GRP0, LN0, toTherm((p_margin_pu_en_x2 + 1) / 2)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_MARGINPD_EN, i_tgt, GRP0, LN0, toTherm((n_margin_pd_en_x2 + 1) / 2)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_MARGINPU_EN, i_tgt, GRP0, LN0, toTherm((n_margin_pu_en_x2 + 1) / 2)));
    FAPI_TRY(io::rmw(OPT_TX_MARGINPD_SEL, i_tgt, GRP0, LN0, margin_sel));
    FAPI_TRY(io::rmw(OPT_TX_MARGINPU_SEL, i_tgt, GRP0, LN0, margin_sel));

    // Setting Main Values
    FAPI_TRY(io::rmw(OPT_TX_PSEG_MAIN_EN, i_tgt, GRP0, LN0, toThermWithHalf(p_main_en_x2, MAIN_WIDTH)));
    FAPI_TRY(io::rmw(OPT_TX_NSEG_MAIN_EN, i_tgt, GRP0, LN0, toThermWithHalf(n_main_en_x2, MAIN_WIDTH)));

fapi_try_exit:
    FAPI_IMP("tx_zcal_apply: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_set_zcal_ffe(const OMIC_TGT i_tgt)
{
    FAPI_IMP("tx_set_zcal_ffe: I/O OMI Entering");

    const uint8_t  GRP0             = 0;
    const uint8_t  LN0              = 0;
    const uint32_t DEFAULT_SEGMENTS = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
    uint32_t       pvalx4           = DEFAULT_SEGMENTS;
    uint32_t       nvalx4           = DEFAULT_SEGMENTS;
    uint64_t       data             = 0;


    FAPI_TRY(io::read(OPT_TX_IMPCAL_PB, i_tgt, GRP0, LN0, data));

    if(io::get(OPT_TX_ZCAL_DONE, data) == 1)
    {
        FAPI_DBG("Using zCal Results.");

        FAPI_TRY(io::read(OPT_TX_ZCAL_P, i_tgt, GRP0, LN0, data));

        // We need to convert the 8R value to a 4R equivalent
        pvalx4 = io::get(OPT_TX_ZCAL_P, data) / 2;

        FAPI_TRY(io::read(OPT_TX_ZCAL_N, i_tgt, GRP0, LN0, data));

        // We need to convert the 8R value to a 4R equivalent
        nvalx4 = io::get(OPT_TX_ZCAL_N, data) / 2;


        FAPI_TRY(tx_zcal_verify_results(pvalx4, nvalx4), "Tx Z Cal Verify Results Failed");
    }
    else
    {
        FAPI_INF("Warning: P9 IO OMI Using Default Tx Zcal Segments.");
    }

    // Convert the results of the zCal to actual segments.
    FAPI_TRY(tx_zcal_apply(i_tgt, pvalx4, nvalx4), "Tx Zcal Apply Segments Failed");

fapi_try_exit:
    FAPI_IMP("tx_set_zcal_ffe: I/O Obus Exiting");
    return fapi2::current_err;
}


/**
 * @brief Rx Dc Calibration
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lane_vector Lane Vector
 * @param[in] i_data        Data to be set to rx_run_dccal
 * @retval ReturnCode
 */
fapi2::ReturnCode set_rx_run_dccal(const OMIC_TGT i_tgt, const uint32_t i_lane_vector, const uint8_t i_data)
{
    FAPI_IMP("set_rx_run_dccal: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Start DC Calibrate, this iniates the rx dccal state machine
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_RUN_DCCAL, i_tgt, GRP0, lane, i_data));
        }
    }

    FAPI_DBG("I/O OMI Set Rx Run Dccal Complete.");
fapi_try_exit:
    FAPI_IMP("set_rx_run_dccal: I/O OMI Exiting");
    return fapi2::current_err;
}





/**
 * @brief Rx Dc Calibration
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lane_vector Lane Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_poll_dccal_done(const OMIC_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("rx_poll_dccal_done: I/O OMI Entering");
    const uint8_t  TIMEOUT           = 200;
    const uint64_t DLY_1MS           = 1000000;
    const uint64_t DLY_1MIL_CYCLES   = 1000000;
    const uint32_t MAX_LANES         = 24;
    const uint8_t  GRP0              = 0;
    uint8_t        poll_count      = 0;
    uint64_t       data            = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// Poll Rx Dccal
    ////////////////////////////////////////////////////////////////////////////

    FAPI_TRY(fapi2::delay(DLY_1MS, DLY_1MIL_CYCLES));


    for(uint32_t lane = 0; lane < MAX_LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) == 0)
        {
            continue;
        }

        for(poll_count = 0; poll_count < TIMEOUT; ++poll_count)
        {
            FAPI_TRY(io::read(OPT_RX_DCCAL_DONE, i_tgt, GRP0, lane, data));

            if(io::get(OPT_RX_DCCAL_DONE, data) == 1)
            {
                FAPI_DBG("I/O OMI Rx Dccal Complete: Lane(%d) Polling(%d/%d) ",
                         lane, poll_count, TIMEOUT);
                break;
            }

            FAPI_TRY(fapi2::delay(DLY_1MS, DLY_1MIL_CYCLES));
        }

        FAPI_ASSERT((io::get(OPT_RX_DCCAL_DONE, data) == 1),
                    fapi2::IO_OMI_RX_DCCAL_TIMEOUT().set_TARGET(i_tgt),
                    "Rx Dccal Timeout: Loops(%d) delay(%d ns, %d cycles)",
                    poll_count, DLY_1MS, DLY_1MIL_CYCLES);

    }

    FAPI_DBG("I/O OPT OMI Rx Poll Dccal Successful.");

fapi_try_exit:
    FAPI_IMP("rx_poll_dccal_done: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief Set Rx B Bank Controls
 * @param[in] i_tgt          FAPI2 Target
 * @param[in] i_lane_vector  Lane Vector
 * @param[in] i_data         Data
 * @retval ReturnCode
 */
fapi2::ReturnCode set_rx_b_bank_controls(const OMIC_TGT i_tgt, const uint32_t i_lane_vector, const uint8_t i_data)
{
    FAPI_IMP("set_rx_b_bank_controls: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Start DC Calibrate, this iniates the rx dccal state machine
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_B_BANK_CONTROLS, i_tgt, GRP0, lane, i_data));
        }
    }

    FAPI_DBG("I/O OMI Rx Dccal Complete.");
fapi_try_exit:
    FAPI_IMP("set_rx_b_bank_controls: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief A I/O Obus Procedure that powers up the unit
 * on every instance of the OMI.
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode omi_powerup(const OMIC_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("omi_powerup: I/O OMI Entering");

    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Power up Per-Group Registers
    FAPI_TRY(io::rmw(OPT_RX_CLKDIST_PDWN, i_tgt, GRP0, 0, 0));
    FAPI_TRY(io::rmw(OPT_TX_CLKDIST_PDWN, i_tgt, GRP0, 0, 0));
    FAPI_TRY(io::rmw(OPT_RX_IREF_PDWN_B, i_tgt, GRP0, 0, 1));
    FAPI_TRY(io::rmw(OPT_RX_CTL_DATASM_CLKDIST_PDWN, i_tgt, GRP0, 0, 0));

    // Power up Per-Lane Registers
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_LANE_ANA_PDWN, i_tgt, GRP0, lane, 0));
            FAPI_TRY(io::rmw(OPT_RX_LANE_DIG_PDWN, i_tgt, GRP0, lane, 0));
            FAPI_TRY(io::rmw(OPT_TX_LANE_PDWN    , i_tgt, GRP0, lane, 0));
        }
    }

fapi_try_exit:
    FAPI_IMP("omi_powerup: I/O Obus Exiting");
    return fapi2::current_err;
}

/**
 * @brief A I/O Set Obus Flywheel
 * on every instance of the OMI.
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode set_omi_flywheel_off(const OMIC_TGT i_tgt, const uint32_t i_lane_vector, const uint8_t i_data)
{
    FAPI_IMP("set_obus_flywheel_off: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Power up Per-Lane Registers
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_PR_FW_OFF, i_tgt, GRP0, lane, i_data));
        }
    }

fapi_try_exit:
    FAPI_IMP("set_omi_flywheel_off: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief A I/O Set Obus Flywheel
 * on every instance of the OMI.
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode set_omi_pr_edge_track_cntl(const OMIC_TGT i_tgt, const uint32_t i_lane_vector,
        const uint8_t i_data)
{
    FAPI_IMP("set_obus_edge_track_cntl: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Power up Per-Lane Registers
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_PR_EDGE_TRACK_CNTL, i_tgt, GRP0, lane, i_data));
        }
    }

fapi_try_exit:
    FAPI_IMP("set_obus_pr_edge_track_cntl: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief A I/O Set RX AC Coupled
 * @param[in] i_tgt     FAPI2 Target
 * @param[in] i_data    Data to be set
 * @retval ReturnCode
 */
fapi2::ReturnCode set_omi_rx_ac_coupled(const OMIC_TGT i_tgt, const uint8_t i_data)
{
    FAPI_IMP("set_omi_rx_ac_coupled: I/O OMI Entering");
    const uint8_t GRP0 = 0;
    const uint8_t LN0  = 0;

    // Per Group Register
    FAPI_TRY(io::rmw(OPT_RX_AC_COUPLED, i_tgt, GRP0, LN0, i_data));

fapi_try_exit:
    FAPI_IMP("set_omi_rx_ac_coupled: I/O OMI Exiting");
    return fapi2::current_err;
}
/**
 * @brief De-assert lane_disable
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_omi_lane_enable(const OMIC_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("p9_omi_lane_enable: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;

    // Power up Per-Lane Registers
    for(uint8_t lane = 0; lane < LANES; ++lane)
    {
        if(((0x1 << lane) & i_lane_vector) != 0)
        {
            FAPI_TRY(io::rmw(OPT_RX_LANE_DISABLED, i_tgt, GRP0, lane, 0x0));
        }
    }

fapi_try_exit:
    FAPI_IMP("p9_omi_lane_enable: I/O OMI Exiting");
    return fapi2::current_err;
}


/**
 * @brief Halt Obus PPE if HW446279 is enabled
 * @param[in] i_tgt         FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_omi_halt_ppe(const OMIC_TGT i_tgt)
{
    FAPI_IMP("p9_omi_halt_ppe: I/O OMI Entering");
    const uint64_t OMI_PPE_XCR_ADDR = 0x0000000007011050ull;
    const uint64_t HALT             = 0x1000000000000000ull; // xcr cmd=001
    fapi2::buffer<uint64_t> l_xcr_data(HALT);

    fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE_Type l_hw446279_use_ppe;

    auto l_chip = i_tgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE,
                           l_chip,
                           l_hw446279_use_ppe));

    if(l_hw446279_use_ppe)
    {
        FAPI_TRY(fapi2::putScom(i_tgt,
                                OMI_PPE_XCR_ADDR,
                                l_xcr_data),
                 "Resume From Halt Failed.");
    }

fapi_try_exit:
    FAPI_IMP("p9_omi_halt_ppe: I/O OMI Exiting");
    return fapi2::current_err;
}

/**
 * @brief Init PHY Tx FIFO Logic
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_omi_tx_fifo_init(const OMIC_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("p9_omi_tx_fifo_init: I/O OMI Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LANES = 24;
    fapi2::buffer<uint64_t> l_data = 0;

    // Power up Per-Lane Registers
    for(uint8_t l_lane = 0; l_lane < LANES; ++l_lane)
    {
        if(((0x1 << l_lane) & i_lane_vector) != 0)
        {
            // - Clear TX_UNLOAD_CLK_DISABLE
            FAPI_TRY(io::read(OPT_TX_MODE2_PL, i_tgt, GRP0, l_lane, l_data));
            io::set(OPT_TX_UNLOAD_CLK_DISABLE, 0, l_data);
            FAPI_TRY(io::write(OPT_TX_MODE2_PL, i_tgt, GRP0, l_lane, l_data));

            // - Set TX_FIFO_INIT
            l_data.flush<0>();
            io::set(OPT_TX_FIFO_INIT, 1, l_data);
            FAPI_TRY(io::write(OPT_TX_CNTL1G_PL, i_tgt, GRP0, l_lane, l_data));

            // - Set TX_UNLOAD_CLK_DISABLE
            FAPI_TRY(io::read(OPT_TX_MODE2_PL, i_tgt, GRP0, l_lane, l_data));
            io::set(OPT_TX_UNLOAD_CLK_DISABLE, 1, l_data );
            FAPI_TRY(io::write(OPT_TX_MODE2_PL, i_tgt, GRP0, l_lane, l_data));
        }
    }

fapi_try_exit:
    FAPI_IMP("p9_omi_tx_fifo_init: I/O OMI Exiting");
    return fapi2::current_err;
}

} // end namespace P9A_IO_OMI_DCCAL

using namespace P9A_IO_OMI_DCCAL;

/**
 * @brief A I/O Obus Procedure that runs Rx Dccal and Tx Z Impedance calibration
 * on every instance of the OMI.
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lave_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode p9a_io_omi_dccal(const OMIC_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("p9a_io_omi_dccal: I/O OMI Entering");
    uint8_t dccal_flags = 0x0;
    char l_tgtStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt, l_tgtStr, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_DBG("I/O OMI Dccal %s, Lane Vector(0x%X)", l_tgtStr, i_lane_vector);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OMI_DCCAL_FLAGS, i_tgt, dccal_flags));

    FAPI_TRY(p9_omi_halt_ppe(i_tgt));

    // Power up Clock Distribution & Lanes
    FAPI_TRY(omi_powerup(i_tgt, i_lane_vector));

    // SW442174 :: Set RX_AC_COUPLED = 1
    // - This must be done before dccal to get accurate dccal values
    FAPI_TRY(set_omi_rx_ac_coupled(i_tgt, 1));

    // Enable Disabled Lanes
    FAPI_TRY(p9_omi_lane_enable(i_tgt, i_lane_vector));

    // Run Tx Zcal State Machine
    FAPI_TRY(tx_run_zcal(i_tgt), "I/O Obus Tx Run Z-Cal Failed");
    FAPI_DBG("I/O Obus Tx Zcal State Machine Successful.");

    // Set that the state machine successfully finished.
    dccal_flags |= fapi2::ENUM_ATTR_IO_OMI_DCCAL_FLAGS_TX;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OMI_DCCAL_FLAGS, i_tgt, dccal_flags));

    // Apply Tx FFE Values
    FAPI_TRY(tx_set_zcal_ffe(i_tgt), "I/O Obus Tx Set Z-Cal FFE Failed");
    FAPI_DBG("I/O Obus Tx Zcal Successful.");

    // Turn Phase Rotator Fly Wheel Off
    FAPI_TRY(set_omi_flywheel_off(i_tgt, i_lane_vector, 1));

    // Run Rx Dc Calibration
    FAPI_TRY(set_rx_run_dccal(i_tgt, i_lane_vector, 1), "Starting Rx Dccal Failed");
    FAPI_TRY(rx_poll_dccal_done(i_tgt, i_lane_vector), "I/O Obus Rx Dccal Poll Failed");
    FAPI_TRY(set_rx_run_dccal(i_tgt, i_lane_vector, 0), "Stopping Rx Dccal Failed");
    FAPI_TRY(set_rx_b_bank_controls(i_tgt, i_lane_vector, 0), "Setting Rx B Bank Controls Failed.");
    dccal_flags |= fapi2::ENUM_ATTR_IO_OMI_DCCAL_FLAGS_RX;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OMI_DCCAL_FLAGS, i_tgt, dccal_flags));
    FAPI_DBG("I/O OMI Rx Dccal Successful.");

    // Turn Phase Rotator Fly Wheel On
    FAPI_TRY(set_omi_flywheel_off(i_tgt, i_lane_vector, 0));
    FAPI_TRY(set_omi_pr_edge_track_cntl(i_tgt, i_lane_vector, 0));

    // Run Tx FIFO Init
    FAPI_TRY(p9_omi_tx_fifo_init(i_tgt, i_lane_vector));

fapi_try_exit:
    FAPI_IMP("p9_io_omi_dccal: I/O OMI Exiting");
    return fapi2::current_err;
}
