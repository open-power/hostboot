/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_link_layer.C $ */
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
/// @file p10_fabric_link_layer.C
/// @brief Start SMP link layer (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fabric_link_layer.H>
#include <p10_scom_iohs.H>
#include <p10_io_power.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Engage DLL/TL training for a single fabric link (X/A)
///
/// @param[in] i_target         Reference to IOHS link to train
/// @param[in] i_en             Defines sublinks to enable
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_link_layer_train_link(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const fapi2::ATTR_IOHS_LINK_TRAIN_Type i_en)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    const uint8_t l_bitmap_rev[]   = { 7, 6, 5, 4, 8, 3, 2, 1, 0 };
    const uint8_t l_bitmap_norev[] = { 0, 1, 2, 3, 8, 4, 5, 6, 7 };
    fapi2::buffer<uint64_t> l_dlp_control_data;
    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_lane_vec_valid = fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_FALSE;
    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_Type l_bad_lane_vec = 0;
    fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL_Type l_iohs_fabric_lane_reversal = 0;

    bool l_even = (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH) ||
                  (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY);

    bool l_odd  = (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH) ||
                  (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, i_target, l_bad_lane_vec_valid));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC, i_target, l_bad_lane_vec));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_FABRIC_LANE_REVERSAL, i_target, l_iohs_fabric_lane_reversal));

    FAPI_TRY(GET_DLP_CONTROL(i_target, l_dlp_control_data),
             "Error from getScom (DLP_CONTROL)");

    if (l_even)
    {
        if (l_bad_lane_vec_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_TRUE)
        {
            fapi2::buffer<uint64_t> l_dlp_link_rx_lane_control = 0;
            fapi2::buffer<uint64_t> l_dlp_link_rx_lane_control_copy = 0;
            const uint8_t* l_bitmap;
            FAPI_TRY(GET_DLP_LINK0_RX_LANE_CONTROL(i_target, l_dlp_link_rx_lane_control));
            l_dlp_link_rx_lane_control_copy.insert<0, 9, 0>(l_bad_lane_vec);

            if (l_iohs_fabric_lane_reversal & 0x40) // rx lane reversal
            {
                l_bitmap = l_bitmap_rev;
            }
            else
            {
                l_bitmap = l_bitmap_norev;
            }

            for (uint8_t x = 0; x < 9; x++)
            {
                FAPI_DBG("Even, bit pos: %d (mapped to bit pos: %d)", x, l_bitmap[x]);
                bool l_bit;
                l_bit = l_dlp_link_rx_lane_control_copy.getBit(x);
                FAPI_TRY(l_dlp_link_rx_lane_control.writeBit(l_bit, l_bitmap[x]));
            }

            FAPI_TRY(PUT_DLP_LINK0_RX_LANE_CONTROL(i_target, l_dlp_link_rx_lane_control));
        }

        FAPI_TRY(PREP_DLP_CONTROL(i_target));
        SET_DLP_CONTROL_0_PHY_TRAINING(l_dlp_control_data);
        SET_DLP_CONTROL_0_STARTUP(l_dlp_control_data);
    }

    if (l_odd)
    {
        if (l_bad_lane_vec_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_TRUE)
        {
            fapi2::buffer<uint64_t> l_dlp_link_rx_lane_control = 0;
            fapi2::buffer<uint64_t> l_dlp_link_rx_lane_control_copy = 0;
            const uint8_t* l_bitmap;
            FAPI_TRY(GET_DLP_LINK1_RX_LANE_CONTROL(i_target, l_dlp_link_rx_lane_control));
            l_dlp_link_rx_lane_control_copy.insert<0, 9, 9>(l_bad_lane_vec);

            if (l_iohs_fabric_lane_reversal & 0x10) // rx lane reversal
            {
                l_bitmap = l_bitmap_rev;
            }
            else
            {
                l_bitmap = l_bitmap_norev;
            }

            for (uint8_t x = 0; x < 9; x++)
            {
                FAPI_DBG("Odd, bit pos: %d (mapped to bit pos: %d)", x, l_bitmap[x]);
                bool l_bit;
                l_bit = l_dlp_link_rx_lane_control_copy.getBit(x);
                FAPI_TRY(l_dlp_link_rx_lane_control.writeBit(l_bit, l_bitmap[x]));
            }

            FAPI_TRY(PUT_DLP_LINK1_RX_LANE_CONTROL(i_target, l_dlp_link_rx_lane_control));
        }

        FAPI_TRY(PREP_DLP_CONTROL(i_target));
        SET_DLP_CONTROL_1_PHY_TRAINING(l_dlp_control_data);
        SET_DLP_CONTROL_1_STARTUP(l_dlp_control_data);
    }

    FAPI_TRY(PUT_DLP_CONTROL(i_target, l_dlp_control_data),
             "Error from putScom (DLP_CONTROL)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fabric_link_layer(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_train_intranode,
    const bool i_train_internode)
{
    FAPI_DBG("Start, i_train_intranode = %d, i_train_internode = %d",
             i_train_intranode, i_train_internode);

    for (const auto l_iohs : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
        fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;
        fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fabric_link_active;
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_iohs, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs, l_drawer_interconnect),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs, l_fabric_link_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

        if ((l_link_train != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE) &&
            (l_fabric_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE) &&
            ((i_train_intranode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE)) ||
             (i_train_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE))))
        {

            FAPI_DBG("Training link %s", l_targetStr);

            if (i_train_internode)   // Abus
            {
                FAPI_TRY(p10_io_iohs_power(l_iohs, true),
                         "Error from p10_io_iohs_power");
            }

            FAPI_TRY(p10_fabric_link_layer_train_link(
                         l_iohs,
                         l_link_train),
                     "Error from p10_fabric_link_layer_train_link");
        }
        else
        {
            FAPI_DBG("Skipping link training for %s", l_targetStr);
            FAPI_DBG("  l_link_train:           %d", l_link_train);
            FAPI_DBG("  l_fabric_link_active:   %d", l_fabric_link_active);
            FAPI_DBG("  i_train_intranode:      %d", i_train_intranode);
            FAPI_DBG("  i_train_internode:      %d", i_train_internode);
            FAPI_DBG("  l_drawer_interconnect:  %d", l_drawer_interconnect);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
