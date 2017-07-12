/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/io/p9_io_cen_dccal.C $ */
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
/// @file p9_io_cen_dccal.C
/// @brief Train the Link.
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
/// Run Dccal
///
/// Dccal is completed on all thin/thick PHYs:
///     - cen(EDI)
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
#include <p9_io_cen_dccal.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//#include <p9_io_common.H>

const uint8_t GRP0 = 0;
const uint8_t LN0  = 0;

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------


/**
 * @brief Tx Impedance Calibration
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);

/**
 * @brief Rx Dc Calibration
 * @retval ReturnCode
 */
fapi2::ReturnCode rxDccal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------

/**
 * @brief A I/O EDI Procedure that runs Rx Dccal and Tx Z Impedance calibration
 * on every instance of the Centaur on a per group level.
 * @param[in] i_target_chip p9 chip target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_cen_dccal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_IMP("p9_io_cen_dccal: I/O EDI Cen Entering");

    FAPI_DBG("I/O EDI Cen Dccal");

    // Runs Tx Zcal on a per bus basis
    FAPI_TRY(txZcal(i_target_chip), "I/O Edi Cen Tx Z-Cal Failed");

    // Starts Rx Dccal on a per group basis
    FAPI_TRY(rxDccal(i_target_chip), "I/O Edi Cen Rx DC Cal Failed");

fapi_try_exit:
    FAPI_IMP("p9_io_cen_dccal: I/O EDI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Convert a 4R decimal value to a 2R binary code
 * @param[in] i_4r_val 4R Value
 * @retval Converted 1R Value
 */
uint32_t roundTo2r(const uint32_t i_4rVal)
{
    return (i_4rVal & 0x1) ? ((i_4rVal >> 1) + 1) : (i_4rVal >> 1);
}

/**
 * @brief Tx Z Impedance Calibration Get Results
 * @param[in] io_pval  Tx Zcal P-value
 * @param[in] io_nval  Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcalVerifyResults(uint32_t& io_pvalx4, uint32_t& io_nvalx4)
{
    // l_zcal_p and l_zcal_n are 9 bit registers
    // These are also 4x of a 1R segment
    const uint32_t X4_MIN = 16 * 4; // 16 segments * 4 = 64 (0x40)
    const uint32_t X4_MAX = 33 * 4; // 33 segments * 4 = 132(0x84)
    FAPI_IMP("tx_zcal_verify_results: I/O EDI Cen Entering");

    FAPI_DBG("Cen Tx Zcal Min/Max Allowed(0x%X,0x%X) Read Pval/Nval(0x%X,0x%X)",
             X4_MIN, X4_MAX, io_pvalx4, io_nvalx4);

    if(io_pvalx4 > X4_MAX)
    {
        FAPI_INF("Warning: Cen Tx Zcal Pval(0x%X) > Max Allowed(0x%X): Code will override with 0x%X and continue",
                 io_pvalx4, X4_MAX, X4_MAX);
        io_pvalx4 = X4_MAX;
    }

    if(io_nvalx4 > X4_MAX)
    {
        FAPI_INF("Warning: Cen Tx Zcal Nval(0x%X) > Max Allowed(0x%X): Code will override with 0x%X and continue.",
                 io_nvalx4, X4_MAX, X4_MAX);
        io_nvalx4 = X4_MAX;
    }

    if(io_pvalx4 < X4_MIN)
    {
        FAPI_INF("Warning: Cen Tx Zcal Pval(0x%X) < Min Allowed(0x%X): Code will override with 0x%X and continue.",
                 io_pvalx4, X4_MIN, X4_MIN);
        io_pvalx4 = X4_MIN;
    }

    if(io_nvalx4 < X4_MIN)
    {
        FAPI_INF("Warning: Cen Tx Zcal Nval(0x%X) < Min Allowed(0x%X): Code will override with 0x%X and continue.",
                 io_nvalx4, X4_MIN, X4_MIN);
        io_nvalx4 = X4_MIN;
    }

    FAPI_IMP("tx_zcal_verify_results: I/O EDI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcalRunStateMachine(const CEN_TGT& i_tgt)
{
    FAPI_IMP("tx_zcal_run_sm: I/O EDI cen Entering");

    // Request to start Tx Impedance Calibration
    // The Done bit is read only pulse, must use pie driver or system model in sim
    FAPI_TRY(io::rmw(EDI_TX_ZCAL_REQ, i_tgt, GRP0, LN0, 0));
    FAPI_TRY(io::rmw(EDI_TX_ZCAL_REQ, i_tgt, GRP0, LN0, 1));

fapi_try_exit:

    FAPI_IMP("tx_zcal_run_sm: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcalRunStateMachinePoll(const CEN_TGT& i_tgt)
{
    const uint64_t DLY_10US         = 10000;
    const uint64_t DLY_1MIL_CYCLES  = 1000000;
    const uint32_t TIMEOUT          = 200;
    uint32_t count                  = 0;
    uint64_t regData                = 0;

    FAPI_IMP("tx_zcal_run_sm: I/O EDI cen Entering");


    // Poll Until Tx Impedance Calibration is done or errors out
    FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, regData));

    while((++count < TIMEOUT) &&
          !(io::get(EDI_TX_ZCAL_DONE, regData) || io::get(EDI_TX_ZCAL_ERROR, regData)))
    {
        FAPI_DBG("tx_zcal_run_sm: I/O EDI cen Tx Zcal Poll, Count(%d/%d).", count, TIMEOUT);

        // Delay for 10us between polls for a total of 22ms.
        FAPI_TRY(fapi2::delay(DLY_10US, DLY_1MIL_CYCLES));

        FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, regData));
    }


    if(io::get(EDI_TX_ZCAL_DONE, regData) == 1)
    {
        FAPI_DBG("tx_zcal_run_sm: I/O EDI cen Tx Zcal Poll Completed(%d/%d).", count, TIMEOUT);
    }
    else if(io::get(EDI_TX_ZCAL_ERROR, regData) == 1)
    {
        FAPI_ERR("tx_zcal_run_sm: WARNING: Tx Z Calibration Error");
    }
    else
    {
        FAPI_ERR("tx_zcal_run_sm: WARNING: Tx Z Calibration Timeout: Loops(%d)", count);
    }

fapi_try_exit:

    FAPI_IMP("tx_zcal_run_sm: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration Apply Segments.  The results of the Tx Impedance
 *   calibrationMargining and FFE Precursor
 * @param[in] i_tgt FAPI2 Target
 * @param[in] i_pval   Tx Zcal P-value
 * @param[in] i_nval   Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcalApply(const CEN_TGT& i_tgt, const uint32_t i_pvalx4, const uint32_t i_nvalx4)
{
    FAPI_IMP("txZcalApply: I/O EDI Cen Entering");

    uint32_t pMarginx4   = 0;
    uint32_t nMarginx4   = 0;
    uint32_t pPostx4     = 0;
    uint32_t nPostx4     = 0;
    uint32_t pMainx4     = 0;
    uint32_t nMainx4     = 0;
    uint8_t  marginRatio = 0;
    uint8_t  preRatio    = 0;

    // Encoding of Margin Ratio and Tx FFE Precursor
    // 100.00% = 128(0x80) / 128
    //  75.00% =  96(0x60) / 128
    //  50.00% =  64(0x40) / 128
    //  25.00% =  32(0x20) / 128
    //   4.67% =   6(0x06) / 128
    //   0.00% =   0(0x00) / 128

    // During normal operation we will not use margining :: min(0, 0%) max(0.5, 50%)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_DMI_CEN_TX_MARGIN_RATIO, i_tgt, marginRatio));

    // FFE Precursor Tap Weight :: min(0.0, 0%) max(0.115, 11.5%)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_DMI_CEN_TX_FFE_POSTCURSOR, i_tgt, preRatio));

    // Margin Should always be zero for normal operation.
    // margin = (1-m)*zcal/2
    pMarginx4 = (marginRatio / 128) * (i_pvalx4 / 2);
    nMarginx4 = (marginRatio / 128) * (i_nvalx4 / 2);
    // Post-cursor was never intended to be used on Centaur
    // postcursor = (zcal - (2*margin))*k2
    pPostx4  = (preRatio / 128) * (i_pvalx4 - (2 * pMarginx4));
    nPostx4  = (preRatio / 128) * (i_nvalx4 - (2 * nMarginx4));
    pMainx4  = i_pvalx4 - (2 * pMarginx4) - pPostx4;
    nMainx4  = i_nvalx4 - (2 * nMarginx4) - nPostx4;

    // We can write these registers without reading, since we are writing
    //   the entire register.  To convert the 4R values to needed register values,
    FAPI_TRY(io::rmw(EDI_TX_FFE_POST_P_ENC  , i_tgt, GRP0, LN0, roundTo2r(pPostx4)));
    FAPI_TRY(io::rmw(EDI_TX_FFE_POST_N_ENC  , i_tgt, GRP0, LN0, roundTo2r(nPostx4)));
    FAPI_TRY(io::rmw(EDI_TX_FFE_MARGIN_P_ENC, i_tgt, GRP0, LN0, roundTo2r(pMarginx4)));
    FAPI_TRY(io::rmw(EDI_TX_FFE_MARGIN_N_ENC, i_tgt, GRP0, LN0, roundTo2r(nMarginx4)));
    FAPI_TRY(io::rmw(EDI_TX_FFE_MAIN_P_ENC  , i_tgt, GRP0, LN0, roundTo2r(pMainx4)));
    FAPI_TRY(io::rmw(EDI_TX_FFE_MAIN_N_ENC  , i_tgt, GRP0, LN0, roundTo2r(nMainx4)));
fapi_try_exit:

    FAPI_IMP("txZcalApply: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcalSetResults(const CEN_TGT& i_tgt)
{
    FAPI_IMP("txZcalSetResults: I/O EDI cen Entering");

    const uint8_t  GRP0             = 0;
    const uint8_t  LN0              = 0;
    const uint32_t DEFAULT_SEGMENTS = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
    uint32_t       pvalx4           = DEFAULT_SEGMENTS;
    uint32_t       nvalx4           = DEFAULT_SEGMENTS;
    uint64_t       data             = 0;


    FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, data));

    if(io::get(EDI_TX_ZCAL_DONE, data) == 1)
    {
        FAPI_DBG("Using zCal Results.");

        FAPI_TRY(io::read(EDI_TX_ZCAL_P, i_tgt, GRP0, LN0, data));

        // We need to convert the 8R value to a 4R equivalent
        pvalx4 = io::get(EDI_TX_ZCAL_P, data) / 2;

        FAPI_TRY(io::read(EDI_TX_ZCAL_N, i_tgt, GRP0, LN0, data));

        // We need to convert the 8R value to a 4R equivalent
        nvalx4 = io::get(EDI_TX_ZCAL_N, data) / 2;

        FAPI_TRY(txZcalVerifyResults(pvalx4, nvalx4), "Tx Z Cal Verify Results Failed");
    }
    else
    {
        FAPI_ERR("WARNING: Using Default Tx Zcal Segments.");
    }

    // Convert the results of the zCal to actual segments.
    FAPI_TRY(txZcalApply(i_tgt, pvalx4, nvalx4), "Tx Zcal Apply Segments Failed");
fapi_try_exit:
    FAPI_IMP("txZcalSetResults: I/O EDI cen Exiting");
    return fapi2::current_err;
}



/**
 * @brief A I/O EDI Procedure that runs Tx Z Impedance calibration
 * @param[in] i_target_chip p9 chip target
 * @retval ReturnCode
 */
fapi2::ReturnCode txZcal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_IMP("txZcal: I/O EDI Cen Entering");
    const uint64_t DLY_10MIL_CYCLES = 10000000;
    const uint64_t DLY_20MS         = 20000000;

    for (auto l_dmi : i_target_chip.getChildren<fapi2::TARGET_TYPE_DMI>())
    {
        //There should only be one centaur child
        for (auto l_tgt : l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>())
        {
            FAPI_DBG("Running on centaur..");

            // Runs Tx Zcal on a per bus basis
            FAPI_TRY(txZcalRunStateMachine(l_tgt), "I/O Edi Cen Tx Z-Cal Run State Machine Failed");
        }
    }

    // Delay before we start polling.  20ms was use from past p8 learning
    FAPI_TRY(fapi2::delay(DLY_20MS, DLY_10MIL_CYCLES));

    for (auto l_dmi : i_target_chip.getChildren<fapi2::TARGET_TYPE_DMI>())
    {
        //There should only be one centaur child
        for (auto l_tgt : l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>())
        {
            FAPI_TRY(txZcalRunStateMachinePoll(l_tgt), "I/O Edi Cen Tx Z-Cal Run State Machine Failed");
        }
    }

    for (auto l_dmi : i_target_chip.getChildren<fapi2::TARGET_TYPE_DMI>())
    {
        //There should only be one centaur child
        for (auto l_tgt : l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>())
        {
            // Sets Tx Zcal Group Settings based on the bus results
            FAPI_TRY(txZcalSetResults(l_tgt), "I/O Edi Cen Tx Z-Cal Set Results Failed");
        }
    }

fapi_try_exit:
    FAPI_IMP("txZcal: I/O EDI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Start Cleanup Pll
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode setCleanupPllWtRefclk(const CEN_TGT& i_tgt)
{
    FAPI_IMP("startCleanupPll: I/O EDI DMI Cen Entering");
    const uint8_t LN0  = 0;
    const uint8_t GRP0 = 0;
    uint64_t regData  = 0;

    FAPI_TRY(io::read(EDI_RX_WIRETEST_PLL_CNTL_PG, i_tgt, GRP0, LN0, regData));

    io::set(EDI_RX_WT_PLL_REFCLKSEL, 0x1, regData);
    io::set(EDI_RX_PLL_REFCLKSEL_SCOM_EN, 0x1, regData);

    FAPI_TRY(io::write(EDI_RX_WIRETEST_PLL_CNTL_PG, i_tgt, GRP0, LN0, regData));

    FAPI_TRY(fapi2::delay(150000, 0));

    FAPI_TRY(io::rmw(EDI_RX_WT_CU_PLL_PGOOD, i_tgt, GRP0, LN0, 0x1));

    FAPI_TRY(fapi2::delay(5000, 0));

fapi_try_exit:
    FAPI_IMP("startCleanupPll: I/O EDI DMI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Stop Cleanup Pll
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode setCleanupPllFunctional(const CEN_TGT& i_tgt)
{
    FAPI_IMP("stopCleanupPll: I/O EDI DMI Cen Entering");
    const uint8_t GRP0 = 0;
    const uint8_t LN0  = 0;
    uint64_t regData  = 0;

    FAPI_TRY(io::read(EDI_RX_WIRETEST_PLL_CNTL_PG, i_tgt, GRP0, LN0, regData));

    io::set(EDI_RX_WT_PLL_REFCLKSEL,      0, regData);
    io::set(EDI_RX_PLL_REFCLKSEL_SCOM_EN, 0, regData);
    io::set(EDI_RX_WT_CU_PLL_PGOOD,       0, regData);

    FAPI_TRY(io::write(EDI_RX_WIRETEST_PLL_CNTL_PG, i_tgt, GRP0, LN0, regData));

    FAPI_TRY(fapi2::delay(110500, 0));

fapi_try_exit:
    FAPI_IMP("stopCleanupPll: I/O EDI DMI Cen Exiting");
    return fapi2::current_err;
}


/**
 * @brief A I/O EDI Procedure that runs Rx Dc Calibration
 * @param[in] i_target_chip p9 chip target
 * @retval ReturnCode
 */
fapi2::ReturnCode rxDccal(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_IMP("rx_dccal: I/O EDI Cen Entering");

    const uint64_t DLY_100MS        = 100000000;
    const uint64_t DLY_10MIL_CYCLES = 10000000;
    const uint8_t  TIMEOUT = 100;

    uint64_t regData = 0;
    uint64_t rxWiretestPllCntlPg = 0;
    uint8_t rxPdwnLite = 0;
    uint8_t rxWtTimeoutSel = 0;
    uint8_t count = 0;

    for (auto l_dmi : i_target_chip.getChildren<fapi2::TARGET_TYPE_DMI>())
    {
        //There should only be one centaur child
        for (auto l_tgt : l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>())
        {
            FAPI_TRY(setCleanupPllWtRefclk(l_tgt));

            // 1.0 Set rx_pdwn_lite_disable = '1'
            //  - Save original setting
            FAPI_TRY(io::read(EDI_RX_PDWN_LITE_DISABLE, l_tgt, GRP0, LN0, regData));
            rxPdwnLite = io::get(EDI_RX_PDWN_LITE_DISABLE, regData);
            FAPI_TRY(io::rmw(EDI_RX_PDWN_LITE_DISABLE, l_tgt, GRP0, LN0, 0x1));

            // 1.1 Set rx_wt_cu_pll_pgooddly = '111'
            //  - Save original wiretest pll control settings
            FAPI_TRY(io::read(EDI_RX_WIRETEST_PLL_CNTL_PG, l_tgt, GRP0, LN0, rxWiretestPllCntlPg));
            FAPI_TRY(io::rmw(EDI_RX_WT_CU_PLL_PGOODDLY, l_tgt, GRP0, LN0, 0x7));

            // 1.2 Set rx_wt_timeout_sel = '111'
            FAPI_TRY(io::read(EDI_RX_WT_TIMEOUT_SEL, l_tgt, GRP0, LN0, regData));
            rxWtTimeoutSel = io::get(EDI_RX_WT_TIMEOUT_SEL, regData);
            FAPI_TRY(io::rmw(EDI_RX_WT_TIMEOUT_SEL, l_tgt, GRP0, LN0, 0x7));

            // 1.3 Set rx_wt_cu_pll_reset = '1'
            FAPI_TRY(io::rmw(EDI_RX_WT_CU_PLL_RESET, l_tgt, GRP0, LN0, 0x1));

            // 1.4 Set rx_wt_cu_pll_pgood = '1'
            FAPI_TRY(io::rmw(EDI_RX_WT_CU_PLL_PGOOD, l_tgt, GRP0, LN0, 0x1));

            // 1.5 Wait 100ms -- From past p8 learning
            FAPI_TRY(fapi2::delay(DLY_100MS, DLY_10MIL_CYCLES));

            // 1.6 Set rx_wt_timeout_sel = '000'
            FAPI_TRY(io::rmw(EDI_RX_WT_TIMEOUT_SEL, l_tgt, GRP0, LN0, 0x0));

            // 2.0 Set rx_start_offset_cal = '1'
            FAPI_TRY(io::rmw(EDI_RX_START_OFFSET_CAL, l_tgt, GRP0, LN0, 0x1));
        }
    }

    for (auto l_dmi : i_target_chip.getChildren<fapi2::TARGET_TYPE_DMI>())
    {
        //There should only be one centaur child
        for (auto l_tgt : l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>())
        {
            // 2.1 Poll for rx_offset_cal done & check for fail
            do
            {
                FAPI_DBG("rx_dccal: I/O EDI Centaur Rx Dccal Poll, Count(%d/%d).", count, TIMEOUT);
                FAPI_TRY(io::read(EDI_RX_TRAINING_STATUS_PG, l_tgt, GRP0, LN0, regData));

                if (io::get(EDI_RX_OFFSET_CAL_DONE, regData) || io::get(EDI_RX_OFFSET_CAL_FAILED, regData))
                {
                    break;
                }

                FAPI_TRY(fapi2::delay(DLY_100MS, DLY_10MIL_CYCLES));

            }
            while((++count < TIMEOUT));

            FAPI_ASSERT(io::get(EDI_RX_OFFSET_CAL_DONE, regData) == 1,
                        fapi2::IO_DMI_CEN_RX_DCCAL_TIMEOUT().set_TARGET(l_tgt),
                        "Rx Dccal Timeout: Loops(%d) Delay(%d ns, %d cycles)",
                        count, DLY_100MS, DLY_10MIL_CYCLES);

            FAPI_ASSERT(io::get(EDI_RX_OFFSET_CAL_FAILED, regData) == 0,
                        fapi2::IO_DMI_CEN_RX_DCCAL_FAILED().set_TARGET(l_tgt),
                        "Rx Dccal Failed: Loops(%d) Delay(%d ns, %d cycles)",
                        count, DLY_100MS, DLY_10MIL_CYCLES);

            FAPI_DBG("rx_dccal: Successful: Loops(%d)", count);


            // 3.0 Clear rx_eo_latch_offset_done = '0'
            FAPI_TRY(io::rmw(EDI_RX_EO_LATCH_OFFSET_DONE, l_tgt, GRP0, LN0, 0x0));

            // 3.1 Clear rx_pdwn_lite_disable = '0'
            FAPI_TRY(io::rmw(EDI_RX_PDWN_LITE_DISABLE, l_tgt, GRP0, LN0, rxPdwnLite));

            // 3.2 Restore rx_wt_timeout_sel to saved values
            FAPI_TRY(io::rmw(EDI_RX_WT_TIMEOUT_SEL, l_tgt, GRP0, LN0, rxWtTimeoutSel));

            // 3.3 Restore rx_wiretest_pll_cntl_pg
            FAPI_TRY(io::write(EDI_RX_WIRETEST_PLL_CNTL_PG, l_tgt, GRP0, LN0, rxWiretestPllCntlPg));

            FAPI_TRY(setCleanupPllFunctional(l_tgt));
        }
    }

fapi_try_exit:
    FAPI_IMP("rx_dccal: I/O EDI Cen Exiting");
    return fapi2::current_err;
}


