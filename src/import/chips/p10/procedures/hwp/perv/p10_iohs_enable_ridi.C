/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_iohs_enable_ridi.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
//------------------------------------------------------------------------------
/// @file  p10_iohs_enable_ridi.C
///
/// @brief Enable ridi controls for IOHS logic
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#include <p10_iohs_enable_ridi.H>
#include <p10_scom_iohs.H>
#include <target_filters.H>
#include <p10_enable_ridi.H>

/// @brief Enable Drivers/Receivers of IOHS Chiplet
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_iohs_enable_ridi(const
                                       fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{

    FAPI_INF("p10_iohs_enable_ridi: Entering ...");

    auto l_perv_iohs = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                           static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_ALL_IOHS),
                           fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_DBG("Enabling IOHS drivers and receivers");

    for (auto& targ : l_perv_iohs)
    {
        FAPI_TRY(p10_enable_ridi(targ));
    }

    FAPI_DBG("p10_iohs_enable_ridi: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
