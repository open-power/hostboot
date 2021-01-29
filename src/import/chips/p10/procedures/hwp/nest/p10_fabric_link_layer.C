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
#include <p10_scom_iohs_c.H>

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

    fapi2::buffer<uint64_t> l_dlp_control_data;

    bool l_even = (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH) ||
                  (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY);
    bool l_odd  = (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH) ||
                  (i_en == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY);

    FAPI_TRY(GET_DLP_CONTROL(i_target, l_dlp_control_data),
             "Error from getScom (DLP_CONTROL)");

    if (l_even)
    {
        SET_DLP_CONTROL_0_PHY_TRAINING(l_dlp_control_data);
        SET_DLP_CONTROL_0_STARTUP(l_dlp_control_data);
    }

    if (l_odd)
    {
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
