/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_npu_scominit.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_npu_scominit.C
/// @brief Apply SCOM overrides for the NPU unit via an init file
///
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_npu_scominit.H>
#include <p9_npu_scom.H>
#include <p9_nv_ref_clk_enable.H>

///
/// p9_npu_scominit HWP entry point (Defined in .H file)
///
fapi2::ReturnCode p9_npu_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                  & i_target)
{
    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_nv_targets = i_target.getChildren<fapi2::TARGET_TYPE_NV>();

    FAPI_DBG("Entering ...");

    if (l_nv_targets.size())
    {
        FAPI_DBG("Invoking p9.npu.scom.initfile...");
        FAPI_EXEC_HWP(l_rc, p9_npu_scom, i_target, FAPI_SYSTEM);

        if (l_rc)
        {
            FAPI_ERR("Error from p9.npu.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        FAPI_DBG("Invoking p9_nv_ref_clk_enable...");
        FAPI_EXEC_HWP(l_rc, p9_nv_ref_clk_enable, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_nv_ref_clk_enable");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }
    else
    {
        FAPI_DBG("Skipping NPU initialization");
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}

