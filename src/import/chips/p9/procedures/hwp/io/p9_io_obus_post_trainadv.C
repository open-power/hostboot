/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_post_trainadv.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
/// @file p9_io_obus_post_trainadv.H
/// @brief Post-Training PHY Status Function.
///
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
/// Post-Training PHY Status Function.
///
/// Procedure Prereq:
///   - System clocks are running.
///   - Scominit Procedure is completed.
///   - IO DCCAL Procedure is completed.
///   - IO Run Training Procedure is completed.
/// @endverbatim
///----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include <p9_io_obus_post_trainadv.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------

fapi2::ReturnCode p9_io_obus_mnfg_setup_ecc_crc_masks(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt)
{
    // Setup ECC & CRC Masks
    fapi2::buffer<uint64_t> l_fir_mask;
    l_fir_mask.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE>();
    l_fir_mask.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE>();
    l_fir_mask.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS>();
    l_fir_mask.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS>();
    FAPI_TRY(fapi2::putScom(i_tgt, OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_OR, l_fir_mask));
fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p9_io_obus_mnfg_setup_perf_counters(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt)
{
    // Setup Performance Counters
    fapi2::buffer<uint64_t> l_data;
    // Ex. putscom pu 0901081D 1B1400001B140000 -pall;
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_0,
                           OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_0_LEN>(0x1B);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_1,
                           OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_1_LEN>(0x14);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_4,
                           OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_4_LEN>(0x1B);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_5,
                           OBUS_LL0_IOOL_PERF_SEL_CONFIG_SELECT_5_LEN>(0x14);
    FAPI_TRY(fapi2::putScom(i_tgt, OBUS_LL0_IOOL_PERF_SEL_CONFIG, l_data));

    // Ex. putscom pu 0901081C A050505000000000 -pall;
    l_data.flush<0>();
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_0,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_0_LEN>(0b10);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_1,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_1_LEN>(0b10);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_4,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_4_LEN>(0b01);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_5,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_ENABLE_5_LEN>(0b01);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_0,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_0_LEN>(0b01);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_1,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_1_LEN>(0b01);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_4,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_4_LEN>(0b01);
    l_data.insertFromRight<OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_5,
                           OBUS_LL0_IOOL_PERF_TRACE_CONFIG_SIZE_5_LEN>(0b01);
    FAPI_TRY(fapi2::putScom(i_tgt, OBUS_LL0_IOOL_PERF_TRACE_CONFIG, l_data));
fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p9_io_obus_mnfg_adj_tally_logic(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt,
    const uint64_t i_allowed_errors)
{
    // Adjust Tally Logic to Never Clear ECC & CRC Count
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(fapi2::getScom(i_tgt, OBUS_LL0_IOOL_OPTICAL_CONFIG, l_data));
    l_data.insertFromRight<OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_DURATION,
                           OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_DURATION_LEN>(0xF);
    l_data.insertFromRight<OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_DURATION,
                           OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_DURATION_LEN>(0xF);
    l_data.insertFromRight<OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_MAX,
                           OBUS_LL0_IOOL_OPTICAL_CONFIG_BAD_LANE_MAX_LEN>(i_allowed_errors);
    l_data.insertFromRight<OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_MAX,
                           OBUS_LL0_IOOL_OPTICAL_CONFIG_LINK_FAIL_MAX_LEN>(i_allowed_errors);
    FAPI_TRY(fapi2::putScom(i_tgt, OBUS_LL0_IOOL_OPTICAL_CONFIG, l_data));
fapi_try_exit:
    return fapi2::current_err;
}


/**
 * @brief A simple HWP that runs after io_run_training.
 *  This function is called on every Obus.
 * @param[in] i_target Fapi2 OBUS Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_obus_post_trainadv(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt)
{
    FAPI_IMP("Entering...");

    // Get Sys Target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys_tgt;

    uint64_t l_mfg_flags = 0x0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS, l_sys_tgt, l_mfg_flags));

    if(l_mfg_flags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
    {
        uint8_t l_mfg_error_threshold = 0x0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_O_MNFG_ERROR_THRESHOLD, l_sys_tgt, l_mfg_error_threshold));

        if(l_mfg_error_threshold == fapi2::ENUM_ATTR_IO_O_MNFG_ERROR_THRESHOLD_CORNER_MODE)
        {
            // Setup ECC & CRC Masks
            FAPI_TRY(p9_io_obus_mnfg_setup_ecc_crc_masks(i_tgt),
                     "Error from p9_io_obus_mnfg_setup_ecc_crc_masks()");

            // Setup Performance Counters
            FAPI_TRY(p9_io_obus_mnfg_setup_perf_counters(i_tgt),
                     "error from p9_io_obus_mnfg_setup_perf_counters()");

            // setup performance counters
            //   Make it so there are only 5 ECC errors allowed per lane or 5 CRC errors allowed per link (corner mode)
            //   Ex. putscom pu 0901080F 0F000F00000000000 -bor -pall
            //   Ex. putscom pu 0901080F FF85FF85FFFFFFFF -band -pall
            FAPI_TRY(p9_io_obus_mnfg_adj_tally_logic(i_tgt, 5),
                     "error from p9_io_obus_mnfg_adj_tally_logic()");

        }
        else if(l_mfg_error_threshold == fapi2::ENUM_ATTR_IO_O_MNFG_ERROR_THRESHOLD_RELIABILITY_MODE)
        {
            // Setup ECC & CRC Masks
            FAPI_TRY(p9_io_obus_mnfg_setup_ecc_crc_masks(i_tgt),
                     "Error from p9_io_obus_mnfg_setup_ecc_crc_masks()");

            // Setup Performance Counters
            FAPI_TRY(p9_io_obus_mnfg_setup_perf_counters(i_tgt),
                     "error from p9_io_obus_mnfg_setup_perf_counters()");

            // Setup Performance Counters
            //   Make it so there are only 10 ECC errors allowed per lane or 10 CRC errors allowed
            //   per link (reliability test) --- Have a flag to go between 3.5/3.7 settings
            //   Ex. putscom pu 0901080F 0F000F00000000000 -bor -pall
            //   Ex. putscom pu 0901080F FF8AFF8AFFFFFFFF -band -pall
            FAPI_TRY(p9_io_obus_mnfg_adj_tally_logic(i_tgt, 10),
                     "error from p9_io_obus_mnfg_adj_tally_logic()");

        }
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}
