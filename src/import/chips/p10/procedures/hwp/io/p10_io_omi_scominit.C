/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_omi_scominit.C $ */
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
/// @file p10_io_omi_scominit.C
/// @brief Placeholder for OMI PHY SCOM init customization (FAPI2)
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_omi_scominit.H>
#include <p10_omi_scom.H>
#include <p10_omic_scom.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// Main function, see description in header
fapi2::ReturnCode p10_io_omi_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    auto l_omi_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>();
    auto l_omic_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

    for (const auto& l_omic_target : l_omic_targets)
    {
        FAPI_EXEC_HWP(l_rc, p10_omic_scom, l_omic_target, FAPI_SYSTEM, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p10.omic.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    for (auto l_omi_target : l_omi_targets)
    {
        FAPI_EXEC_HWP(l_rc, p10_omi_scom, l_omi_target, FAPI_SYSTEM, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p10.omi.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
