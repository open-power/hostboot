/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_sys_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file p9_sys_chiplet_scominit.C
///
/// @brief SCOM inits to all chiplets required for drawer integration
///

//
// *HWP HW Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 2
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_sys_chiplet_scominit.H"
#include "p9_fbc_ioo_tl_scom.H"
#include "p9_fbc_ioo_dl_scom.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_sys_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    FAPI_DBG("Start");

    do
    {
        // Invoke IOO (OBUS FBC IO) SCOM initfiles
        FAPI_DBG("Invoking p9.fbc.ioo_tl.scom.initfile...");
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_tl_scom, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioo_tl_scom");
            break;
        }

        l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

        for (auto l_iter = l_obus_chiplets.begin();
             l_iter != l_obus_chiplets.end();
             l_iter++)
        {
            FAPI_DBG("Invoking p9.fbc.ioo_dl.scom.initfile...");
            FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_dl_scom, *l_iter);

            if (l_rc)
            {
                FAPI_ERR("Error from p9_fbc_ioo_dl_scom");
                break;
            }
        }
    }
    while(0);

    FAPI_DBG("End");
    return l_rc;
}
