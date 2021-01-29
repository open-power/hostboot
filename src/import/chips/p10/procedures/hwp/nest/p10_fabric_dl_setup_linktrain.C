/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_dl_setup_linktrain.C $ */
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
/// @file p10_fabric_dl_setup_linktrain.C
/// @brief Setup DL training
///-----------------------------------------------------------------------------
///
/// *HW HW Maintainer: Ben Gass <bgass@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fabric_dl_setup_linktrain.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Start DL link training on the selected IOHS
///
/// @param[in] i_target Reference to IOHS endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_fabric_dl_setup_linktrain_start(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool l_do_even,
    const bool l_do_odd)
{
    FAPI_DBG("Start");
    using namespace scomt::iohs;
    fapi2::buffer<uint64_t> l_data = 0;

    //## PHY_CONFIG Register: Enable link 0, Config_dl_select = DLP
    //putscom pu.iohs 1801100c 0000000000000081 -all
    //FAPI_TRY(PREP_DLP_PHY_CONFIG(i_target));
    FAPI_TRY(GET_DLP_PHY_CONFIG(i_target, l_data));

    if (l_do_even)
    {
        SET_DLP_PHY_CONFIG_LINK0_SELECT(l_data);
    }

    if (l_do_odd)
    {
        SET_DLP_PHY_CONFIG_LINK1_SELECT(l_data);
    }

    SET_DLP_PHY_CONFIG_DL_SELECT(1, l_data); // DLP
    FAPI_TRY(PUT_DLP_PHY_CONFIG(i_target, l_data));

    //## DLP_CONFIG set paired if links are not split
    if (l_do_even && l_do_odd)
    {
        fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, i_target, l_link_split),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");

        if(l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_FALSE)
        {
            FAPI_TRY(GET_DLP_CONFIG(i_target, l_data))
            SET_DLP_CONFIG_LINK_PAIR(l_data);
            FAPI_TRY(PUT_DLP_CONFIG(i_target, l_data))
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Setup IOHS fir mask and start DL training
///
/// @param[in] i_target Reference to IOHS endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p10_fabric_dl_setup_linktrain(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    FAPI_DBG("Start");

    bool l_do_even = false;
    bool l_do_odd = false;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_active;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN,
                           i_target,
                           l_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE,
                           i_target,
                           l_link_active),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

    l_do_even = l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH ||
                l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY;

    l_do_odd  = l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH ||
                l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY;

    if ((l_link_train != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE) &&
        (l_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE))
    {
        FAPI_TRY(p10_fabric_dl_setup_linktrain_start(i_target, l_do_even, l_do_odd));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
