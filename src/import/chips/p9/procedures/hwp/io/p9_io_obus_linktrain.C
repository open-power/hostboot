/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_linktrain.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// *HWP Level            : 3
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

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_obus_linktrain.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9_io_common.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>

//-----------------------------------------------------------------------------
//  Constant Definitions
//-----------------------------------------------------------------------------

enum p9_io_obus_linktrain_pattern_t
{
    PATTERN_A,
    PATTERN_TS1,
    PATTERN_NONE
};

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------


/**
 * @brief Init PHY TX FIFO logic
 * @param[in] i_tgt  Reference to OBUS endpoint target
 * @param[in] i_even Process even half link?
 * @param[in] i_odd  Process odd half link?
 * @retval    ReturnCode
 */
fapi2::ReturnCode
init_tx_fifo(const OBUS_TGT& i_tgt,
             bool i_even,
             bool i_odd)
{
    const uint32_t MAX_LANES = 24;
    const uint8_t GRP0 = 0;
    fapi2::buffer<uint64_t> l_data = 0;

    for (uint8_t l_lane = 0; l_lane < MAX_LANES; l_lane++)
    {
        if ((i_even && (l_lane  < (MAX_LANES / 2))) ||
            (i_odd  && (l_lane >= (MAX_LANES / 2))))
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
    return fapi2::current_err;
}


/**
 * @brief Force DL to send specified repeating pattern
 * @param[in] i_tgt  OBUS endpoint target
 * @param[in] i_even Send on even half link?
 * @param[in] i_odd  Send on odd half link?
 * @param[in] i_pat  Pattern type to send
 * @retval    ReturnCode
 */
fapi2::ReturnCode
force_dl_pattern_send(
    const OBUS_TGT& i_tgt,
    const bool i_even,
    const bool i_odd,
    const p9_io_obus_linktrain_pattern_t i_pat)
{
    fapi2::buffer<uint64_t> l_data = 0;

    if (i_pat == PATTERN_A)
    {
        l_data = 0x4444444444400000ULL;
    }
    else if (i_pat == PATTERN_TS1)
    {
        l_data = 0x1111111111100000ULL;
    }
    else if (i_pat == PATTERN_NONE)
    {
        l_data = 0x0ULL;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::IO_OBUS_INVALID_PATTERN()
                    .set_TARGET(i_tgt)
                    .set_PATTERN(i_pat),
                    "Invalid/unsupported pattern requested");
    }

    if (i_even)
    {
        FAPI_TRY(fapi2::putScom(i_tgt,
                                OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL,
                                l_data),
                 "Error from putScom (OBUS_LL0_IOOL_LINK0_TX_LANE_CONTROL)");
    }

    if (i_odd)
    {
        FAPI_TRY(fapi2::putScom(i_tgt,
                                OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL,
                                l_data),
                 "Error from putScom (OBUS_LL0_IOOL_LINK1_TX_LANE_CONTROL)");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Lock CDR in cable
 * @param[in] i_tgt  OBUS endpoint target
 * @param[in] i_even Send on even half link?
 * @param[in] i_odd  Send on odd half link?
 * @retval    ReturnCode
 */
fapi2::ReturnCode
lock_cable_cdr(
    const OBUS_TGT& i_tgt,
    const bool i_even,
    const bool i_odd)
{
    // set TX lane control to force send of TS1 pattern
    FAPI_TRY(force_dl_pattern_send(i_tgt,
                                   i_even,
                                   i_odd,
                                   PATTERN_TS1),
             "Error from force_dl_pattern_send (TS1)");

    // Delay to compensate for active links
    FAPI_TRY(fapi2::delay(100000000, 1000000),
             "Error from A-link retimer delay");

    // resset TX lane control
    FAPI_TRY(force_dl_pattern_send(i_tgt,
                                   i_even,
                                   i_odd,
                                   PATTERN_NONE),
             "Error from force_dl_pattern_send (reset)");

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief If lane is bad based on pattern A comparisons, power it down to
 *        permit downstream DL training code to recognize error
 * @param[in] i_tgt   Reference to OBUS endpoint target
 * @param[in] i_group Group to power down
 * @param[in] i_lane  Lane to power down
 * @retval    ReturnCode
 */
fapi2::ReturnCode
pdwn_bad_lane(
    const OBUS_TGT& i_tgt,
    const uint8_t i_group,
    const uint8_t i_lane)
{
    fapi2::buffer<uint64_t> l_rx_dac_cntl2_eo_pl;
    fapi2::buffer<uint64_t> l_offset_data;
    uint64_t l_data = 0;
    uint32_t l_lane_pdwn = 0;

    const uint8_t  TIMEOUT           = 200;
    const uint64_t DLY_1MS           = 1000000;
    const uint64_t DLY_1MIL_CYCLES   = 1000000;

    FAPI_DBG("Start, lane=%d", i_lane);

    // skip if already powered down
    FAPI_TRY(io::read(OPT_RX_LANE_ANA_PDWN, i_tgt, i_group, i_lane, l_data),
             "Error reading OPT_RX_LANE_ANA_PDWN");

    if (io::get(OPT_RX_LANE_ANA_PDWN, l_data) == 1)
    {
        FAPI_DBG("Skipping this lane, already powered down");
        goto fapi_try_exit;
    }

    FAPI_DBG("Marking powerdown");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OBUS_LANE_PDWN,
                           i_tgt,
                           l_lane_pdwn),
             "Error from FAPI_ATTR_GET (ATTR_IO_OBUS_LANE_PDWN)");
    l_lane_pdwn |= (0x80000000 >> i_lane);
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OBUS_LANE_PDWN,
                           i_tgt,
                           l_lane_pdwn),
             "Error from FAPI_ATTR_SET (ATTR_IO_OBUS_LANE_PDWN)");

    // set rx_recal_abort = 1
    FAPI_TRY(io::rmw(OPT_RX_RECAL_ABORT, i_tgt, i_group, i_lane, 0x1),
             "Error setting OPT_RX_RECAL_ABORT");

    // poll for rx_lane_busy = 0
    for (uint8_t l_count = 0; l_count < TIMEOUT; ++l_count)
    {
        FAPI_TRY(io::read(OPT_RX_LANE_BUSY, i_tgt, i_group, i_lane, l_data),
                 "Error reading OPT_RX_LANE_BUSY");

        if (io::get(OPT_RX_LANE_BUSY, l_data) == 0)
        {
            break;
        }

        FAPI_TRY(fapi2::delay(DLY_1MS, DLY_1MIL_CYCLES));
    }

    FAPI_ASSERT((io::get(OPT_RX_LANE_BUSY, l_data) == 0),
                fapi2::IO_OBUS_PDWN_BAD_LANE_TIMEOUT()
                .set_TARGET(i_tgt)
                .set_GROUP(i_group)
                .set_LANE(i_lane),
                "Timeout waiting for RX lane busy status");

    // set rx_amp_val = max
    FAPI_TRY(io::rmw(OPT_RX_AMP_VAL, i_tgt, i_group, i_lane, 0x7F),
             "Error setting OPT_RX_AMP_VAL");
    // rx_a_controls (bit 3) = 1
    FAPI_TRY(io::read(OPT_RX_A_CONTROLS, i_tgt, i_group, i_lane, l_rx_dac_cntl2_eo_pl),
             "Error reading OPT_RX_A_CONTROLS");
    l_rx_dac_cntl2_eo_pl.setBit < OBUS_RX0_RXPACKS0_SLICE0_RX_DAC_CNTL2_EO_PL_A_CONTROLS + 3 > ();
    FAPI_TRY(io::write(OPT_RX_A_CONTROLS, i_tgt, i_group, i_lane, l_rx_dac_cntl2_eo_pl),
             "Error writing OPT_RX_A_CONTROLS");
    // rx_bank_sel_a = 1
    FAPI_TRY(io::rmw(OPT_RX_BANK_SEL_A, i_tgt, i_group, i_lane, 0x1),
             "Error setting OPT_RX_BANK_SEL_A");
    // power down lane
    FAPI_TRY(io::rmw(OPT_RX_LANE_ANA_PDWN, i_tgt, i_group, i_lane, 0x01),
             "Error setting OPT_RX_LANE_ANA_PDWN");
    FAPI_TRY(io::rmw(OPT_RX_LANE_DIG_PDWN, i_tgt, i_group, i_lane, 0x01),
             "Error setting OPT_RX_LANE_DIG_PDWN");
    FAPI_TRY(io::rmw(OPT_RX_LANE_DISABLED, i_tgt, i_group, i_lane, 0x01),
             "Error setting OPT_RX_LANE_DISABLED");
    FAPI_TRY(io::rmw(OPT_RX_FORCE_INIT_DONE, i_tgt, i_group, i_lane, 0x01),
             "Error setting OPT_RX_FORCE_INIT_DONE");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::FAPI2_RC_SUCCESS;
}


/**
 * @brief Detect if pattern A was received in RX data pipe latches
 * @param[in] i_data_pipe 22 bits of sampled data, left aligned
 * @retval    bool (true = pattern A detected, false = pattern A not detected)
 */
bool
check_pattern_A(const uint32_t i_data_pipe)
{
    // Maximum and minimum run length of bits.  This correponds to the number of X's
    // e.g.  Pattern A is 1111111100000000.... (8 up 8 down)
    //       and can be received as 1111000000000000....  (4 up 12 down)
    //       or 1111111111110000.... (12 up 4 down)
    const uint8_t MAX_RUN = 12;
    const uint8_t MIN_RUN = 4;
    const uint8_t NUM_DATA_BITS = 22;

    std::vector<bool> l_data_pipe;
    std::vector<bool> l_values;
    std::vector<uint8_t> l_switches;

    // create vector from input data (entry per bit)
    for (uint8_t ii = 0; ii < NUM_DATA_BITS; ii++)
    {
        uint32_t l_bit_val = ((i_data_pipe >> (31 - ii)) & 1);
        l_data_pipe.push_back(l_bit_val == 1);
    }

    // create value history/switch index vectors
    for (uint8_t ii = 0; ii < NUM_DATA_BITS; ii++)
    {
        if (ii == 0)
        {
            l_values.push_back(l_data_pipe[ii]);
        }
        else if (l_data_pipe[ii] != l_data_pipe[ii - 1])
        {
            l_values.push_back(l_data_pipe[ii]);
            l_switches.push_back(ii);
        }
    }

    FAPI_DBG("Value history:");

    for (auto l_value : l_values)
    {
        FAPI_DBG("  %d", (l_value) ? (1) : (0));
    }

    FAPI_DBG("Switch indexes:");

    for (auto l_switch : l_switches)
    {
        FAPI_DBG("  %d", l_switch);
    }

    // determine if switching history is viable given runs in transmitted pattern
    for (uint8_t ii = 0; ii < l_switches.size(); ii++)
    {
        // first run of bits
        if (ii == 0)
        {
            // first run of bits is too long
            if (l_switches[ii] > MAX_RUN)
            {
                return false;
            }
        }
        // middle or last run of bits
        else
        {
            if (((l_switches[ii] - l_switches[ii - 1]) < MIN_RUN) || // middle run is too short
                ((l_switches[ii] - l_switches[ii - 1]) > MAX_RUN) || // middle run is too long
                ((ii == (l_switches.size() - 1)) &&
                 ((NUM_DATA_BITS - l_switches[ii]) > MAX_RUN)))    // last run is too long
            {
                return false;
            }
        }
    }

    // ensure that we switched 2 or 3 times
    if ((l_switches.size() != 2) &&
        (l_switches.size() != 3))
    {
        return false;
    }

    // all checks passed
    return true;
}


/**
 * @brief Detect pattern A per lane
 * @param[in] i_rx_tgt  Receive side endpoint target
 * @param[in] i_even    Run on even sub link?
 * @param[in] i_odd     Run on odd sub link?
 * @retval    ReturnCode
 */
fapi2::ReturnCode
find_pattern_A(
    const OBUS_TGT& i_rx_tgt,
    const bool i_even,
    const bool i_odd)
{
    const uint32_t MAX_LANES = 24;
    const uint8_t GRP0 = 0;
    fapi2::ATTR_IO_OBUS_PAT_A_CAPTURE_Type l_pat_A_capture;
    // set default
    fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RX_AMP_VALUE_Type l_pat_A_rx_amp_value = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OBUS_PAT_A_CAPTURE,
                           i_rx_tgt,
                           l_pat_A_capture),
             "Error from FAPI_ATTR_GET (ATTR_IO_OBUS_PAT_A_CAPTURE)");

    // read attribute value
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RX_AMP_VALUE,
                           i_rx_tgt,
                           l_pat_A_rx_amp_value),
             "Error from FAPI_ATTR_GET (ATTR_IO_OBUS_PAT_A_DETECT_RX_AMP_VALUE)");

    for (uint8_t l_lane = 0; l_lane < MAX_LANES; l_lane++)
    {
        // capture only if half link containing this lane is active, and should
        // be physically connected
        if ((i_even && (l_lane  < (MAX_LANES / 2) - 1)) ||
            (i_odd  && (l_lane >= (MAX_LANES / 2) + 1)))
        {
            fapi2::buffer<uint64_t> l_data_hi, l_data_lo;
            uint32_t l_sample = 0;
            bool l_pat_A_detected = false;

            // install pre-set values for pattern detection/sampling
            FAPI_TRY(io::rmw(OPT_RX_PIPE_SEL, i_rx_tgt, GRP0, l_lane, 2),
                     "Error setting OPT_RX_PIPE_SEL");
            FAPI_TRY(io::rmw(OPT_RX_BANK_SEL_A, i_rx_tgt, GRP0, l_lane, 1),
                     "Error setting OPT_RX_BANK_SEL_A");
            FAPI_TRY(io::rmw(OPT_RX_A_CONTROLS, i_rx_tgt, GRP0, l_lane, 4),
                     "Error setting OPT_RX_A_CONTROLS");
            FAPI_TRY(io::rmw(OPT_RX_AMP_VAL, i_rx_tgt, GRP0, l_lane, l_pat_A_rx_amp_value),
                     "Error setting OPT_RX_AMP_VAL");
            FAPI_TRY(io::rmw(OPT_RX_CAL_LANE_SEL, i_rx_tgt, GRP0, l_lane, 1),
                     "Error from io::rmw (OPT_RX_CAL_LANE_SEL), set");
            FAPI_TRY(io::rmw(OPT_RX_DATA_PIPE_CAPTURE, i_rx_tgt, GRP0, l_lane, 1),
                     "Error from io::rmw (OPT_RX_DATA_PIPE_CAPTURE)");

            // capture sample
            // concatenate bits 0:10 of rx_data_pipe_0_15 and rx_data_pipe_16_31
            // to get a total of 22 bits, left aligned
            FAPI_TRY(fapi2::delay(10000, 1000),
                     "Error from pipe capture delay");
            FAPI_TRY(io::read(OPT_RX_DATA_PIPE_0_15, i_rx_tgt, GRP0, l_lane, l_data_hi),
                     "Error from io::rmw (OPT_RX_DATA_PIPE_0_15)");
            l_data_hi.extract<48, 11, 0>(l_sample);
            FAPI_TRY(io::read(OPT_RX_DATA_PIPE_16_31, i_rx_tgt, GRP0, l_lane, l_data_lo),
                     "Error from io::rmw (OPT_RX_DATA_PIPE_16_31)");
            l_data_lo.extract<48, 11, 11>(l_sample);
            FAPI_DBG("Data 0_15: 0x%016llX, Data 16_31: 0x%016llX, Sample: 0x%06X",
                     l_data_hi(), l_data_lo(), l_sample);

            // save to attribute
            l_pat_A_capture[l_lane] = l_sample;

            // determine if pattern was received
            FAPI_DBG("Checking pattern A for lane %d", l_lane);
            l_pat_A_detected = check_pattern_A(l_sample);

            // if not, power down this lane
            if (!l_pat_A_detected)
            {
                FAPI_TRY(pdwn_bad_lane(i_rx_tgt,
                                       GRP0,
                                       l_lane),
                         "Error from pdwn_bad_lane");
            }
            else
            {
                // reset lane parameters to default
                FAPI_TRY(io::rmw(OPT_RX_PIPE_SEL, i_rx_tgt, GRP0, l_lane, 1),
                         "Error setting OPT_RX_PIPE_SEL");
                FAPI_TRY(io::rmw(OPT_RX_A_CONTROLS, i_rx_tgt, GRP0, l_lane, 32),
                         "Error setting OPT_RX_A_CONTROLS");
                FAPI_TRY(io::rmw(OPT_RX_AMP_VAL, i_rx_tgt, GRP0, l_lane, 0),
                         "Error setting OPT_RX_AMP_VAL");
            }

            // clear lane select for next iteration
            FAPI_TRY(io::rmw(OPT_RX_CAL_LANE_SEL, i_rx_tgt, GRP0, l_lane, 0),
                     "Error from io::rmw (OPT_RX_CAL_LANE_SEL), clear");
        }
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OBUS_PAT_A_CAPTURE,
                           i_rx_tgt,
                           l_pat_A_capture),
             "Error from FAPI_ATTR_SET (ATTR_IO_OBUS_PAT_A_CAPTURE)");

fapi_try_exit:
    return fapi2::current_err;
}


/**
 * @brief A HWP to perform FIFO init for ABUS(OPT)
 * @param[in] i_mode  Linktraining Mode
 * @param[in] i_tgt   Reference to the Target
 * @retval    ReturnCode
 */
fapi2::ReturnCode p9_io_obus_linktrain(const OBUS_TGT& i_tgt)
{
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Entering");
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt, l_tgt_str, fapi2::MAX_ECMD_STRING_LEN);
    FAPI_DBG("I/O Abus FIFO init: Target(%s)", l_tgt_str);

    const uint32_t MAX_LANES = 24;
    const uint8_t GRP0 = 0;

    OBUS_TGT l_rem_tgt;
    fapi2::buffer<uint64_t> l_dl_control_data;
    fapi2::buffer<uint64_t> l_dl_control_mask;
    fapi2::buffer<uint64_t> l_dl_control_rem;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fbc_active;
    fapi2::ATTR_LINK_TRAIN_Type l_link_train;
    fapi2::ATTR_CHIP_EC_FEATURE_HW419022_Type l_hw419022;
    fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RUN_Type l_pat_a_detect_run;
    fapi2::ATTR_IO_OBUS_TRAIN_FOR_RECOVERY_Type l_train_for_recovery;
    bool l_even = true;
    bool l_odd = true;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE,
                           i_tgt,
                           l_fbc_active),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

    if (!l_fbc_active)
    {
        FAPI_DBG("Skipping link, not active for FBC protocol");
        goto fapi_try_exit;
    }

    // find connected endpoint target
    FAPI_TRY(i_tgt.getOtherEnd(l_rem_tgt),
             "Error from getOtherEnd");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RUN,
                           i_tgt,
                           l_pat_a_detect_run),
             "Error from FAPI_ATTR_GET (ATTR_IO_OBUS_PAT_A_DETECT_RUN)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW419022,
                           i_tgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw419022),
             "Error from FAPI_ATTR_GET (fapi2::ATTR_CHIP_EC_FEATURE_HW419022)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN,
                           i_tgt,
                           l_link_train),
             "Error from FAPI_ATTR_GET (ATTR_LINK_TRAIN)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_OBUS_TRAIN_FOR_RECOVERY,
                           i_tgt,
                           l_train_for_recovery),
             "Error from FAPI_ATTR_GET (ATTR_IO_OBUS_TRAIN_FOR_RECOVERY)");

    // determine link train capabilities (half/full)
    l_even = (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH) ||
             (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY);

    l_odd = (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH) ||
            (l_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_ODD_ONLY);

    // run PHY init sequence + pattern A detection sequence
    // on both connected endpoints if not yet run
    if (l_pat_a_detect_run == fapi2::ENUM_ATTR_IO_OBUS_PAT_A_DETECT_RUN_FALSE)
    {
        FAPI_TRY(init_tx_fifo(i_tgt,
                              l_even,
                              l_odd),
                 "Error from init_tx_fifo, local end");
        FAPI_TRY(init_tx_fifo(l_rem_tgt,
                              l_even,
                              l_odd),
                 "Error from init_tx_fifo, remote end");

        // send  TS1 for Cable CDR lock
        FAPI_TRY(lock_cable_cdr(i_tgt,
                                l_even,
                                l_odd),
                 "Error from lock_cable_cdr, local end, pre pattern A");

        FAPI_TRY(lock_cable_cdr(l_rem_tgt,
                                l_even,
                                l_odd),
                 "Error from lock_cable_cdr, remote end, pre pattern A");

        // execute sequence to send pattern A and check receipt of pattern
        // in PHY RX data pipe logic on connected endpoint -- lanes which
        // do not see expected pattern will be powered down (sparing for
        // single lane faults, or training failure for multi lane faults
        // will be handled in p9_smp_link_layer)
        FAPI_TRY(force_dl_pattern_send(i_tgt,
                                       l_even,
                                       l_odd,
                                       PATTERN_A),
                 "Error from force_dl_pattern_send, pattern A, local end");
        FAPI_TRY(force_dl_pattern_send(l_rem_tgt,
                                       l_even,
                                       l_odd,
                                       PATTERN_A),
                 "Error from force_dl_pattern_send, pattern A, remote end");

        // at IPL time, power down any unneeded lanes (not physically connected or
        // unused half-link)
        if (!l_train_for_recovery)
        {
            for (uint8_t ii = 0; ii < MAX_LANES; ii++)
            {
                if (((ii >= ((MAX_LANES / 2) - 1)) && (ii <= (MAX_LANES / 2))) || // unused lanes, always pdwn
                    (!l_even && (ii <  ((MAX_LANES / 2) - 1))) ||                 // even link is unused
                    (!l_odd  && (ii >= ((MAX_LANES / 2) + 1))))                   // odd link is unused
                {
                    FAPI_TRY(pdwn_bad_lane(i_tgt,
                                           GRP0,
                                           ii),
                             "Error from pdwn_bad_lane, even, local end, lane: %d",
                             ii);
                    FAPI_TRY(pdwn_bad_lane(l_rem_tgt,
                                           GRP0,
                                           ii),
                             "Error from pdwn_bad_lane, even, remote end, lane: %d",
                             ii);
                }
            }
        }

        // Delay to compensate for pattern
        FAPI_TRY(fapi2::delay(100000000, 1000000),
                 "Error from pattern A delay");

        // detect pattern on RX side
        FAPI_TRY(find_pattern_A(l_rem_tgt,
                                l_even,
                                l_odd),
                 "Error from find_pattern_A, local TX, remote RX");

        FAPI_TRY(find_pattern_A(i_tgt,
                                l_even,
                                l_odd),
                 "Error from find_pattern_A, remote TX, local RX");

        // switch off pattern A
        FAPI_TRY(force_dl_pattern_send(i_tgt,
                                       l_even,
                                       l_odd,
                                       PATTERN_NONE),
                 "Error from force_dl_pattern_send, idle, local end");
        FAPI_TRY(force_dl_pattern_send(l_rem_tgt,
                                       l_even,
                                       l_odd,
                                       PATTERN_NONE),
                 "Error from force_dl_pattern_send, idle, remote end");

        // mark both endpoints as run
        l_pat_a_detect_run = fapi2::ENUM_ATTR_IO_OBUS_PAT_A_DETECT_RUN_TRUE;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RUN,
                               i_tgt,
                               l_pat_a_detect_run),
                 "Error from FAPI_ATTR_SET (ATTR_IO_OBUS_PAT_A_DETECT_RUN), local end");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IO_OBUS_PAT_A_DETECT_RUN,
                               l_rem_tgt,
                               l_pat_a_detect_run),
                 "Error from FAPI_ATTR_SET (ATTR_IO_OBUS_PAT_A_DETECT_RUN), remote end");
    }

    // resend TS1 for Cable CDR lock and start phy training
    FAPI_TRY(lock_cable_cdr(i_tgt,
                            l_even,
                            l_odd),
             "Error from lock_cable_cdr, local end, post pattern A");

    // DD1.1+ HW Start training sequence
    if(!l_hw419022)
    {
        if (l_even)
        {
            l_dl_control_data.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_PHY_TRAINING>();
            l_dl_control_mask.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_PHY_TRAINING>();
        }

        if (l_odd)
        {
            l_dl_control_data.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_PHY_TRAINING>();
            l_dl_control_mask.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_PHY_TRAINING>();
        }

        FAPI_TRY(fapi2::putScomUnderMask(i_tgt,
                                         OBUS_LL0_IOOL_CONTROL,
                                         l_dl_control_data,
                                         l_dl_control_mask),
                 "Error writing DLL control register (0x%08X)!",
                 OBUS_LL0_IOOL_CONTROL);

        if (l_even && l_train_for_recovery)
        {
            l_dl_control_data.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_STARTUP>();
            l_dl_control_mask.clearBit<OBUS_LL0_IOOL_CONTROL_LINK0_PHY_TRAINING>();
            l_dl_control_mask.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_STARTUP>();
        }

        if (l_odd && l_train_for_recovery)
        {
            l_dl_control_data.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_STARTUP>();
            l_dl_control_mask.clearBit<OBUS_LL0_IOOL_CONTROL_LINK1_PHY_TRAINING>();
            l_dl_control_mask.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_STARTUP>();
        }

        FAPI_TRY(fapi2::putScomUnderMask(i_tgt,
                                         OBUS_LL0_IOOL_CONTROL,
                                         l_dl_control_data,
                                         l_dl_control_mask),
                 "Error writing DLL control register (0x%08X)!",
                 OBUS_LL0_IOOL_CONTROL);
    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_linktrain: P9 I/O OPT Abus Exiting");
    return fapi2::current_err;
}
