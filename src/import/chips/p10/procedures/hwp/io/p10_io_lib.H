/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_lib.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_io_lib.H
/// @brief Common IO functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>
#include <vector>
#include <utils.H>

#ifndef _P10_IO_LIB__
#define _P10_IO_LIB__

//------------------------------------------------------------------------------
// Consts
//------------------------------------------------------------------------------
static const int P10_IO_LIB_NUMBER_OF_IOHS_LANES = 18;
static const int P10_IO_LIB_50G_IOHS_LANES[] = { 0, 2, 4, 6, 8, 9, 11, 15, 17 };

static const int P10_IO_LIB_NUMBER_OF_OMI_LANES = 8;
static const int P10_IO_LIB_NUMBER_OF_OMIC_LANES = 2 * P10_IO_LIB_NUMBER_OF_OMI_LANES;

static const int P10_IO_LIB_NUMBER_OF_IOHS_THREADS = 2;
static const int P10_IO_LIB_NUMBER_OF_OMIC_THREADS = 2;
static const int P10_IO_LIB_NUMBER_OF_THREADS = P10_IO_LIB_NUMBER_OF_IOHS_THREADS + P10_IO_LIB_NUMBER_OF_OMIC_THREADS;

static const uint64_t P10_IO_LIB_FREQ_ADJUST_LT_25G = 0x01;
static const uint64_t P10_IO_LIB_FREQ_ADJUST_GE_25G = 0x0D;
//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

///// @brief Drive PRBS from PHY
///// @param[in] i_iohs_target   OMI target to get thread id for
///// @param[in] i_on            Enable/Disable PRBS
///// @return FAPI_RC_SUCCESS if arguments are valid
//fapi2::ReturnCode p10_io_omi_drive_prbs(
//    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
//    const bool& i_on);

/// @brief Determines the thread number for the given iohs target
/// @param[in] i_iohs_target    IOHS target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    int& o_thread);

/// @brief Determines the thread number for the given omic target
/// @param[in] i_omic_target    OMIC target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    int& o_thread);

/// @brief Determines which lanes are enabled for an IOHS target
/// @param[in] i_iolink_target  IOLINK target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iolink_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
    std::vector<int>& o_lanes);

/// @brief Determines which lanes are enabled for an IOHS target
/// @param[in] i_iohs_target    IOHS target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    std::vector<int>& o_lanes);

/// @brief Determines which lanes are enabled for an OMIC target
/// @param[in] i_omic_target    OMIC target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    std::vector<int>& o_lanes);

///
/// @brief Write IOHS Per-Lane Hardware Data
///
/// @param[in] i_target IOHS target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_put_pl_regs(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint32_t i_num_lanes,
        const uint64_t i_fld_data);

///
/// @brief Write IOHS Per-Lane Hardware Data, only writes 1 lane, not multiple lanes
///
/// @param[in] i_target IOHS target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_put_pl_regs_single(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint64_t i_lane,
        const uint64_t i_fld_data);

///
/// @brief Write OMI Per-Lane Hardware Data
///
/// @param[in] i_target OMI target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_omi_put_pl_regs(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint32_t i_num_lanes,
        const uint64_t i_fld_data);

///
/// @brief Check OMI init dones
///
/// @param[in] i_target IOHS target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_omi_poll_init_done(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target);

#endif
