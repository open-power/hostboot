/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_train.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_train.C
/// @brief Start OMI training
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

#include <ody_omi_train.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>

SCOMT_OMI_USE_D_REG_DL0_CONFIG0

///
/// @brief Start OMI training
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_train(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_train");

    using namespace scomt::omi;

    D_REG_DL0_CONFIG0_t l_dl0_config0;

    FAPI_TRY(l_dl0_config0.getScom(i_target));
    l_dl0_config0.set_CFG_TL_CREDITS(0x12);
    l_dl0_config0.set_TL_EVENT_ACTIONS(0);
    l_dl0_config0.set_TL_ERROR_ACTIONS(0);
    l_dl0_config0.set_DEBUG_SELECT(0);
    l_dl0_config0.set_DEBUG_ENABLE(0);
    l_dl0_config0.set_TX_LN_REV_ENA(1);
    l_dl0_config0.set_PWRMGT_ENABLE(0);
    l_dl0_config0.set_TRAIN_MODE(8);
    l_dl0_config0.set_VERSION(9);
    FAPI_TRY(l_dl0_config0.putScom(i_target));

fapi_try_exit:
    FAPI_DBG("End ody_omi_train");
    return fapi2::current_err;
}
