/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_scominit.C $ */
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
///
/// @file p10_chiplet_scominit.C
///
/// @brief SCOM inits to all chiplets (sans Quad/fabric)
///

// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: HB

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_chiplet_scominit.H>
#include <p10_mi_omi_scom.H>
#include <p10_mcc_omi_scom.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OMI>> l_omi_targets;

    FAPI_DBG("Start");

    auto l_mi_targets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

    for (const auto& l_mi_target : l_mi_targets)
    {
        auto l_mcc_targets = l_mi_target.getChildren<fapi2::TARGET_TYPE_MCC>();

        for (const auto& l_mcc_target : l_mcc_targets)
        {
            FAPI_EXEC_HWP(l_rc, p10_mcc_omi_scom, l_mcc_target, FAPI_SYSTEM, i_target);

            if (l_rc)
            {
                FAPI_ERR("Error from p10.mcc.omi.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            l_omi_targets = l_mcc_target.getChildren<fapi2::TARGET_TYPE_OMI>();

            for (auto l_omi_target : l_omi_targets)
            {
                FAPI_EXEC_HWP(l_rc, p10_mi_omi_scom, l_mi_target, l_omi_target, l_mcc_target);

                if (l_rc)
                {
                    FAPI_ERR("Error from p10.mi.omi.scom.initfile");
                    fapi2::current_err = l_rc;
                    goto fapi_try_exit;
                }

            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
