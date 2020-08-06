/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_lib.H $         */
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
/// @brief Determines the thread number for the given iohs target
/// @param[in] i_iohs_target    IOHS target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    int& o_thread)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    o_thread = l_iohs_num % P10_IO_LIB_NUMBER_OF_IOHS_THREADS;

    if (l_iohs_num >= 2)
    {
        //AX0/1 are swapped for ioo1..3
        o_thread = (P10_IO_LIB_NUMBER_OF_IOHS_THREADS - 1) - o_thread;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines the thread number for the given omic target
/// @param[in] i_omic_target    OMIC target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    int& o_thread)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_omic_target, l_omic_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    o_thread = l_omic_num % P10_IO_LIB_NUMBER_OF_OMIC_THREADS;
    //omic threads start after iohc threads
    o_thread += P10_IO_LIB_NUMBER_OF_IOHS_THREADS;
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an IOHS target
/// @param[in] i_iohs_target    IOHS target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    std::vector<int>& o_lanes)
{
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
    fapi2::ATTR_LINK_SPEED_Type l_link_speed;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_iohs_target, l_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_SPEED, i_iohs_target, l_link_speed),
             "Error from FAPI_ATTR_GET (ATTR_LINK_SPEED)");

    if (l_link_speed == fapi2::ENUM_ATTR_LINK_SPEED_50G)
    {
        for (size_t l_lane = 0; l_lane < ARRAY_SIZE(P10_IO_LIB_50G_IOHS_LANES); l_lane++)
        {
            o_lanes.push_back(P10_IO_LIB_50G_IOHS_LANES[l_lane]);
        }
    }
    else
    {
        int l_start_bit = 0;
        int l_end_bit = 0;

        if (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY)
        {
            l_start_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES / 2;
            l_end_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
        }
        else if (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
        {
            l_end_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES / 2;
        }
        else if (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
        {
            l_end_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
        }

        for (int l_lane = l_start_bit; l_lane < l_end_bit; l_lane++)
        {
            o_lanes.push_back(l_lane);
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an OMIC target
/// @param[in] i_omic_target    OMIC target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    std::vector<int>& o_lanes)
{
    auto l_omi_targets = i_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    for (auto l_omi_target : l_omi_targets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_num;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi_target, l_omi_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        l_omi_num = l_omi_num % 2;

        for (int l_lane = l_omi_num * 8; l_lane < (l_omi_num + 1) * 8; l_lane++)
        {
            o_lanes.push_back(l_lane);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

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
        const uint64_t i_fld_data)
{
    const uint64_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    for (uint64_t l_lane = 0; l_lane < i_num_lanes; ++l_lane)
    {
        l_addr = i_reg_base_addr | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
        FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));
        l_data.insertFromRight(i_fld_data, i_reg_start, i_reg_len);
        FAPI_TRY(fapi2::putScom(i_target, l_addr, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

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
        const uint64_t i_fld_data)
{
    const uint32_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    for (uint64_t l_lane = 0; l_lane < i_num_lanes; ++l_lane)
    {
        l_addr = i_reg_base_addr | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
        FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));
        l_data.insertFromRight(i_fld_data, i_reg_start, i_reg_len);
        FAPI_TRY(fapi2::putScom(i_target, l_addr, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

#endif
