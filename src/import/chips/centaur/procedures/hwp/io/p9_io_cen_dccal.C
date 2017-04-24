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
/// *HWP Level            : 1
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
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_run_bus(const CEN_TGT i_tgt);

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_set_grp(const CEN_TGT i_tgt);

/**
 * @brief Rx Dc Calibration Poll
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dccal_poll_grp(const CEN_TGT i_tgt);

/**
 * @brief Rx Dc Calibration Start
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dccal_start_grp(const CEN_TGT i_tgt);

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------

/**
 * @brief A I/O EDI Procedure that runs Rx Dccal and Tx Z Impedance calibration
 * on every instance of the Centaur on a per group level.
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_cen_dccal(const CEN_TGT& i_tgt)
{
    FAPI_IMP("p9_io_cen_dccal: I/O EDI Cen Entering");
    /*
        char l_tgtStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(i_tgt, l_tgtStr, fapi2::MAX_ECMD_STRING_LEN);
        FAPI_DBG("I/O EDI Cen Dccal %s", l_tgtStr);

        // Runs Tx Zcal on a per bus basis
        FAPI_TRY(tx_zcal_run_bus(i_tgt), "I/O Edi Cen Tx Z-Cal Run Bus Failed");

        // Sets Tx Zcal Group Settings based on the bus results
        FAPI_TRY(tx_zcal_set_grp(i_tgt), "I/O Edi Cen Tx Z-Cal Set Grp Failed");

        // Starts Rx Dccal on a per group basis
        FAPI_TRY(rx_dccal_start_grp(i_tgt), "I/O Edi Cen Rx DC Cal Start Failed");

        // Checks/polls Rx Dccal on a per group basis
        FAPI_TRY(rx_dccal_poll_grp(i_tgt), "I/O Edi Cen Rx DC Cal Poll Failed");

    fapi_try_exit:
    */
    FAPI_IMP("p9_io_cen_dccal: I/O EDI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Convert a 4R decimal value to a 1R thermometer code
 * @param[in] i_4r_val 4R Value
 * @retval Converted 1R Value
 */
uint32_t convert_4r(const uint32_t i_4r_val)
{
    // 1. Add 2 for averaging since we will truncate the last 2 bits
    // 2. Divide by 4 to bring back to a 1r value
    // 2. Convert the decimal number to number of bits set by shifting
    //    a 0x1 over by the amount and subtracting 1
    return ((0x1 << ((i_4r_val + 2) / 4)) - 1 );
}

uint32_t convert_4r_with_2r(const uint32_t i_4r_val, const uint8_t i_width)
{
    // Add 1 for rounding, then shift the 4r bit off.  We now have a 2r equivalent
    uint32_t l_2r_equivalent = (i_4r_val + 1) >> 0x1;

    // If the LSB of the 2r equivalent is on, then we need to set the 2r bit (MSB)
    uint32_t l_2r_on = (l_2r_equivalent & 0x1);

    // Shift the 2r equivalent to a 1r value and convert to a thermometer code.
    uint32_t l_1r_equivalent ((0x1 << (l_2r_equivalent >> 0x1)) - 1);

    // combine 1r equivalent thermometer code + the 2r MSB value.
    return (l_2r_on << (i_width - 1)) | l_1r_equivalent ;
}

/**
 * @brief Tx Z Impedance Calibration Get Results
 * @param[in] io_pval  Tx Zcal P-value
 * @param[in] io_nval  Tx Zcal N-value
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_verify_results(uint32_t& io_pval, uint32_t& io_nval)
{
    // l_zcal_p and l_zcal_n are 9 bit registers
    // These are also 4x of a 1R segment
    const uint32_t ZCAL_MIN = 16 * 4; // 16 segments * 4 = 64 (0x40)
    const uint32_t ZCAL_MAX = 33 * 4; // 33 segments * 4 = 132(0x84)
    FAPI_IMP("tx_zcal_verify_results: I/O EDI Cen Entering");

    FAPI_DBG("Cen Tx Zcal Min/Max Allowed(0x%X,0x%X) Read Pval/Nval(0x%X,0x%X)",
             ZCAL_MIN, ZCAL_MAX,
             io_pval, io_nval);

    if(io_pval > ZCAL_MAX)
    {
        io_pval = ZCAL_MAX;
        FAPI_ERR("Cen Tx Zcal Pval(0x%X) > Max Allowed(0x%X)", io_pval, ZCAL_MAX);
    }

    if(io_nval > ZCAL_MAX)
    {
        io_nval = ZCAL_MAX;
        FAPI_ERR("Cen Tx Zcal Nval(0x%X) > Max Allowed(0x%X)", io_nval, ZCAL_MAX);
    }

    if(io_pval < ZCAL_MIN)
    {
        io_pval = ZCAL_MIN;
        FAPI_ERR("Cen Tx Zcal Pval(0x%X) < Min Allowed(0x%X)", io_pval, ZCAL_MIN);
    }

    if(io_nval < ZCAL_MIN)
    {
        io_nval = ZCAL_MIN;
        FAPI_ERR("Cen Tx Zcal Nval(0x%X) < Min Allowed(0x%X)", io_nval, ZCAL_MIN);
    }

    FAPI_IMP("tx_zcal_verify_results: I/O EDI Cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration State Machine
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_run_bus(const CEN_TGT i_tgt)
{
    /*
      const uint64_t DLY_20MS         = 20000000;
      const uint64_t DLY_10US         = 10000;
      const uint64_t DLY_10MIL_CYCLES = 10000000;
      const uint64_t DLY_1MIL_CYCLES  = 1000000;
      const uint32_t TIMEOUT          = 200;
      uint32_t l_count                = 0;
      uint64_t l_data                 = 0;
      uint8_t       l_is_sim = 0;

      FAPI_IMP("tx_zcal_run_sm: I/O EDI cen Entering");

      ///////////////////////////////////////////////////////////////////////////
      /// Simulation Speed Up
      ///////////////////////////////////////////////////////////////////////////
      FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

      if(l_is_sim)
      {
          // To speed up simulation, xbus_unit model + pie driver
          //   without these settings: 50 million cycles
          //   with these settings: 13 million cycles
          io::set(EDI_TX_ZCAL_SM_MIN_VAL, 50, l_data);
          io::set(EDI_TX_ZCAL_SM_MAX_VAL, 52, l_data);
          FAPI_TRY(io::write(EDI_TX_IMPCAL_SWO2_PB, i_tgt, GRP0, LN0, l_data));
      }

      // Request to start Tx Impedance Calibration
      // The Done bit is read only pulse, must use pie driver or system model in sim
      FAPI_TRY(io::rmw(EDI_TX_ZCAL_REQ, i_tgt, GRP0, LN0, 1));

      // Delay before we start polling.  20ms was use from past p8 learning
      FAPI_TRY(fapi2::delay(DLY_20MS, DLY_10MIL_CYCLES));

      // Poll Until Tx Impedance Calibration is done or errors out
      FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, l_data));

      while((++l_count < TIMEOUT) &&
             !(io::get(EDI_TX_ZCAL_DONE, l_data) || io::get(EDI_TX_ZCAL_ERROR, l_data)))
      {
          FAPI_DBG("tx_zcal_run_sm: I/O EDI cen Tx Zcal Poll, Count(%d/%d).", l_count, TIMEOUT);

          // Delay for 10us between polls for a total of 22ms.
          FAPI_TRY(fapi2::delay(DLY_10US, DLY_1MIL_CYCLES));

          FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, l_data));
      }


      if(io::get(EDI_TX_ZCAL_DONE, l_data) == 1)
      {
          FAPI_DBG("tx_zcal_run_sm: I/O EDI cen Tx Zcal Poll Completed(%d/%d).", l_count, TIMEOUT);
      }
      else if(io::get(EDI_TX_ZCAL_ERROR, l_data) == 1)
      {
          FAPI_ERR("tx_zcal_run_sm: WARNING: Tx Z Calibration Error");
      }
      else
      {
          FAPI_ERR("tx_zcal_run_sm: WARNING: Tx Z Calibration Timeout: Loops(%d)", l_count);
      }
    fapi_try_exit:
    */
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
fapi2::ReturnCode tx_zcal_apply(const CEN_TGT i_tgt, const uint32_t i_pval, const uint32_t i_nval)
{
    FAPI_IMP("tx_zcal_apply: I/O EDI Cen Entering");
    /*
        const uint8_t POST_WIDTH   = 5;
        const uint8_t MARGIN_WIDTH = 5;
        const uint8_t MAIN_WIDTH   = 13;

        uint32_t margin_p = 0;
        uint32_t margin_n = 0;
        uint32_t post_p = 0;
        uint32_t post_n = 0;
        uint32_t main_p = 0;
        uint32_t main_n = 0;

        // Encoding of Margin Ratio and Tx FFE Precursor
        // 100.00% = 128(0x80) / 128
        //  75.00% =  96(0x60) / 128
        //  50.00% =  64(0x40) / 128
        //  25.00% =  32(0x20) / 128
        //   4.67% =   6(0x06) / 128
        //   0.00% =   0(0x00) / 128

        // During normal operation we will not use margining :: min(0, 0%) max(0.5, 50%)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_CN_TX_MARGIN_RATIO, i_tgt, l_margin_ratio));

        // FFE Precursor Tap Weight :: min(0.0, 0%) max(0.115, 11.5%)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_CN_TX_FFE_POSTCURSOR, i_tgt, l_ffe_pre_coef));

        margin_p = (l_margin_ratio / 128) * i_pval;
        margin_n = (l_margin_ratio / 128) * i_nval;
        post_p   = (l_ffe_pre_coef / 128) * (i_pval - margin_p);
        post_n   = (l_ffe_pre_coef / 128) * (i_nval - margin_n);
        main_p   = i_pval - margin_p - post_p;
        main_n   = i_nval - margin_n - post_n;

        // We can write these registers without reading, since we are writing
        //   the entire register.  To convert the 4R values to needed register values,
        FAPI_TRY(io::rmw(EDI_TX_FFE_POST_P_ENC  , i_tgt, GRP0, LN0, convert_4r(p_post  , PRE_WIDTH   )));
        FAPI_TRY(io::rmw(EDI_TX_FFE_POST_N_ENC  , i_tgt, GRP0, LN0, convert_4r(n_post  , PRE_WIDTH   )));
        FAPI_TRY(io::rmw(EDI_TX_FFE_MARGIN_P_ENC, i_tgt, GRP0, LN0, convert_4r(p_margin, MARGIN_WIDTH)));
        FAPI_TRY(io::rmw(EDI_TX_FFE_MARGIN_N_ENC, i_tgt, GRP0, LN0, convert_4r(n_margin, MARGIN_WIDTH)));
        FAPI_TRY(io::rmw(EDI_TX_FFE_MAIN_P_ENC  , i_tgt, GRP0, LN0, convert_4r(p_main  , MAIN_WIDTH  )));
        FAPI_TRY(io::rmw(EDI_TX_FFE_MAIN_N_ENC  , i_tgt, GRP0, LN0, convert_4r(n_main  , MAIN_WIDTH  )));

    fapi_try_exit:
    */
    FAPI_IMP("tx_zcal_apply: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Tx Z Impedance Calibration
 * @param[in] i_tgt  FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_zcal_set_grp(const CEN_TGT i_tgt)
{
    FAPI_IMP("tx_zcal_set_grp: I/O EDI cen Entering");
    /*
        const uint8_t  GRP0             = 0;
        const uint8_t  LN0              = 0;
        const uint32_t DEFAULT_SEGMENTS = 25 * 4; // Nominal 25 Segments 1R * 4 = 4R
        uint32_t       l_pval           = DEFAULT_SEGMENTS;
        uint32_t       l_nval           = DEFAULT_SEGMENTS;
        uint64_t       l_data           = 0;


        FAPI_TRY(io::read(EDI_TX_IMPCAL_PB, i_tgt, GRP0, LN0, l_data),
                  "tx_zcal_run_sm: Reading Tx Impcal Pb Failed");

        if(io::get(EDI_TX_ZCAL_DONE, l_data) == 1)
        {
            FAPI_DBG("Using zCal Results.");

            FAPI_TRY(io::read(EDI_TX_ZCAL_P, i_tgt, GRP0, LN0, l_data));

            // We need to convert the 8R value to a 4R equivalent
            l_pval = io::get(EDI_TX_ZCAL_P, l_data) / 2;

            FAPI_TRY(io::read(EDI_TX_ZCAL_N, i_tgt, GRP0, LN0, l_data));

            // We need to convert the 8R value to a 4R equivalent
            l_nval = io::get(EDI_TX_ZCAL_N, l_data) / 2;


            FAPI_TRY(tx_zcal_verify_results(l_pval, l_nval), "Tx Z Cal Verify Results Failed");
        }
        else
        {
            FAPI_ERR("WARNING: Using Default Tx Zcal Segments.");
        }

        // Convert the results of the zCal to actual segments.
        FAPI_TRY(tx_zcal_apply(i_tgt, l_pval, l_nval), "Tx Zcal Apply Segments Failed");
    fapi_try_exit:
    */
    FAPI_IMP("tx_zcal_set_grp: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Rx Dc Calibration Set Lanes Invalid
 * @param[in] i_tgt    FAPI2 Target
 * @param[in] i_data   Data to Set Lanes Invalid
 * @retval ReturnCode
 */
fapi2::ReturnCode set_lanes_invalid(const CEN_TGT i_tgt, const uint8_t i_data)
{
    /*
        const uint8_t CN_LANES = 17;

        FAPI_IMP("set_lanes_invalid: I/O EDI cen Entering");

        for(uint8_t lane = 0; lane < CN_LANES; ++lane)
        {
            FAPI_TRY(io::rmw(EDI_RX_LANE_INVALID, i_tgt, GRP0, lane, i_data));
        }
    fapi_try_exit:
    */
    FAPI_IMP("set_lanes_invalid: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Start Cleanup Pll
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode start_cleanup_pll(const CEN_TGT i_tgt)
{
    FAPI_IMP("start_cleanup_pll: I/O EDI cen Entering");
    /*
        const uint8_t LN0  = 0;
        const uint8_t GRP0 = 0;
        uint64_t reg_data  = 0;

        FAPI_TRY(io::read(EDI_RX_CTL_CNTL4_E_PG, i_tgt, GRP0, LN0, reg_data),
                  "read edip_rx_ctl_cntl4_e_pg failed");

        io::set(EDI_RX_WT_PLL_REFCLKSEL, 0x1, reg_data);
        io::set(EDI_RX_PLL_REFCLKSEL_SCOM_EN, 0x1, reg_data);

        FAPI_TRY(io::write(EDI_RX_CTL_CNTL4_E_PG, i_tgt, GRP0, LN0, reg_data),
                  "write edip_rx_ctl_cntl4_e_pg failed");

        FAPI_TRY(fapi2::delay(150000, 0), " Fapi Delay Failed.");

        FAPI_TRY(io::rmw(EDI_RX_WT_CU_PLL_PGOOD, i_tgt, GRP0, LN0, 0x1),
                  "rmw edip_rx_wt_cu_pll_pgood failed");

        FAPI_TRY(fapi2::delay(5000, 0), " Fapi Delay Failed.");


    // The PLL Lock bit is not getting updated.  According to AET it is locked.
    #if 0
        FAPI_TRY(io::read(EDI_RX_WT_CU_BYP_PLL_LOCK, i_tgt, i_group, LANE_00, reg_data),
                  "read edip_rx_wt_cu_byp_pll_lock failed");0

        FAPI_ASSERT((io::get(EDI_RX_WT_CU_BYP_PLL_LOCK, reg_data) == 1),
                     fapi2::IO_XBUS_RX_CLEANUP_PLL_NOT_LOCKED().set_TARGET(i_tgt).set_GROUP(i_group),
                     "start_cleanup_pll: Cleanup Pll Not Locking");
    #endif

    fapi_try_exit:
    */
    FAPI_IMP("start_cleanup_pll: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Stop Cleanup Pll
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode stop_cleanup_pll(const CEN_TGT i_tgt)
{
    FAPI_IMP("stop_cleanup_pll: I/O EDI cen Entering");
    /*
        const uint8_t GRP0 = 0;
        const uint8_t LN0  = 0;
        uint64_t reg_data  = 0;

        FAPI_TRY(io::read(EDI_RX_CTL_CNTL4_E_PG, i_tgt, GRP0, LN0, reg_data));

        io::set(EDI_RX_WT_PLL_REFCLKSEL,      0, reg_data);
        io::set(EDI_RX_PLL_REFCLKSEL_SCOM_EN, 0, reg_data);
        io::set(EDI_RX_WT_CU_PLL_PGOOD,       0, reg_data);

        FAPI_TRY(io::write(EDI_RX_CTL_CNTL4_E_PG, i_tgt, GRP0, LN0, reg_data));

        FAPI_TRY(fapi2::delay(110500, 0), " Fapi Delay Failed.");
    fapi_try_exit:
    */
    FAPI_IMP("stop_cleanup_pll: I/O EDI cen Exiting");
    return fapi2::current_err;
}

/**
 * @brief Rx Dc Calibration
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dccal_start_grp(const CEN_TGT i_tgt)
{
    FAPI_IMP("rx_dccal_start_grp: I/O EDI cen Entering");
    /*

        const uint8_t GRP0 = 0;
        const uint8_t LN0  = 0;

        ///////////////////////////////////////////////////////////////////////////
        /// Simulation Speed Up
        ///////////////////////////////////////////////////////////////////////////
        FAPI_TRY(p9_io_cen_shorten_timers(i_tgt), "Shorten Timers Failed.");

        ////////////////////////////////////////////////////////////////////////////
        /// Start Rx Dccal
        ////////////////////////////////////////////////////////////////////////////

        // Must set lane invalid bit to 0 to run rx dccal, this enables us to run
        //   dccal on the specified lane.  These bits are normally set by wiretest
        //   although we are not running that now.
        FAPI_TRY(set_lanes_invalid(i_tgt, 0), "Error Setting Lane Invalid to 0");

        // We must start the cleanup pll to have a clock that clocks the
        //  dccal logic.  This function locks the rx cleanup pll to the internal
        //  grid clock reference.
        FAPI_TRY(start_cleanup_pll(i_tgt), "rx_dc_cal: Starting Cleanup Pll");

        // Clear the rx dccal done bit in case rx dccal was previously run.
        FAPI_TRY(io::rmw(EDI_RX_DC_CALIBRATE_DONE, i_tgt, GRP0, LN0, 0));

        // Start DC Calibrate, this iniates the rx dccal state machine
        FAPI_TRY(io::rmw(EDI_RX_START_DC_CALIBRATE, i_tgt, GRP0, LN0, 1));

        FAPI_DBG("I/O EDI cen Rx Dccal Complete");

    fapi_try_exit:
    */
    FAPI_IMP("rx_dccal_start_grp: I/O EDI cen Exiting");
    return fapi2::current_err;
}





/**
 * @brief Rx Dc Calibration
 * @param[in] i_tgt FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_dccal_poll_grp(const CEN_TGT i_tgt)
{
    FAPI_IMP("rx_dccal_poll_grp: I/O EDI cen Entering");
    /*

        const uint8_t  TIMEOUT           = 200;
        const uint64_t DLY_100MS         = 100000000;
        const uint64_t DLY_10MS          = 10000000;
        const uint64_t DLY_1MIL_CYCLES   = 1000000;
        const uint8_t  GRP0              = 0;
        const uint8_t  LN0               = 0;
        uint8_t        l_poll_count      = 0;
        uint64_t       l_data            = 0;

        ////////////////////////////////////////////////////////////////////////////
        /// Poll Rx Dccal
        ////////////////////////////////////////////////////////////////////////////
        // In the pervasive unit model, this takes 750,000,000 sim cycles to finish
        //   on a group.  This equates to 30 loops with 25,000,000 delay each.

        // Delay before we start polling.  100ms was use from past p8 learning
        FAPI_TRY(fapi2::delay(DLY_100MS, DLY_1MIL_CYCLES),
                  "rx_dc_cal_poll: Fapi Delay Failed.");

        do
        {
            FAPI_DBG("I/O EDI cen Rx Dccal Polling Count(%d/%d).", l_poll_count, TIMEOUT);

            FAPI_TRY(fapi2::delay(DLY_10MS, DLY_1MIL_CYCLES), "Fapi Delay Failed.");

            FAPI_TRY(io::read(EDI_RX_DC_CALIBRATE_DONE, i_tgt, GRP0, LN0, l_data));
        }
        while((++l_poll_count < TIMEOUT) && !io::get(EDI_RX_DC_CALIBRATE_DONE, l_data));

        FAPI_ASSERT((io::get(EDI_RX_DC_CALIBRATE_DONE, l_data) == 1),
                     fapi2::IO_XBUS_RX_DCCAL_TIMEOUT().set_TARGET(i_tgt).set_GROUP(i_grp),
                     "Rx Dccal Timeout: Loops(%d) delay(%d ns, %d cycles)",
                     l_poll_count, DLY_10MS, DLY_1MIL_CYCLES);

        FAPI_DBG("I/O EDI cen Rx Dccal Successful.");

        ////////////////////////////////////////////////////////////////////////////
        /// Cleanup Rx Dccal
        ////////////////////////////////////////////////////////////////////////////

        // Stop DC Calibrate
        FAPI_TRY(io::rmw(EDI_RX_START_DC_CALIBRATE, i_tgt, GRP0, LN0, 0));

        // We must stop the cleanup pll to cleanup after ourselves.  Wiretest will
        //  turn this back on.  This function will turn off the cleanup pll and
        //   switch it back to bus clock reference.
        FAPI_TRY(stop_cleanup_pll(i_tgt), "rx_dc_cal: Stopping Cleanup Pll");

        // Restore the invalid bits, Wiretest will modify these as training is run.
        FAPI_TRY(set_lanes_invalid(i_tgt, 1), "Error Setting Lane Invalid to 1");

        FAPI_DBG("I/O EDI cen Rx Dccal Complete");

    fapi_try_exit:
    */
    FAPI_IMP("rx_dccal_poll_grp: I/O EDI Centaur Exiting");
    return fapi2::current_err;
}

