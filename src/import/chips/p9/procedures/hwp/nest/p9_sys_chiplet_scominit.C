/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_sys_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP Level : 3
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_sys_chiplet_scominit.H"
#include "p9_fbc_ioo_tl_scom.H"
#include "p9_fbc_ioo_dl_scom.H"
#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"
#include "p9_fbc_smp_utils.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_sys_chiplet_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_en;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_en;
    FAPI_DBG("Start");

    // Invoke IOO (OBUS FBC IO) SCOM initfiles
    FAPI_DBG("Invoking p9.fbc.ioo_tl.scom.initfile...");
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_tl_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioo_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

    for (auto l_iter = l_obus_chiplets.begin();
         l_iter != l_obus_chiplets.end();
         l_iter++)
    {
        FAPI_DBG("Invoking p9.fbc.ioo_dl.scom.initfile...");
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_dl_scom, *l_iter, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioo_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    // mask EXTFIR associated with unused inter-drawer links
    FAPI_DBG("Masking OBUS FIR resources for unused inter-drawer links");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");

    for (uint8_t l_obus = 0;
         l_obus < P9_FBC_UTILS_MAX_A_LINKS;
         l_obus++)
    {
        if (!l_x_en[3 + l_obus] && !l_a_en[l_obus])
        {
            fapi2::buffer<uint64_t> l_extfir_mask = 0;
            fapi2::buffer<uint64_t> l_extfir_action1 = 0;

            FAPI_TRY(l_extfir_mask.setBit(PU_PB_CENT_SM1_EXTFIR_REG_PB_X3_FIR_ERR +
                                          l_obus),
                     "Error forming EXTFIR mask register content");
            FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR, l_extfir_mask),
                     "Error from putScom (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR)");

            FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action1),
                     "Error from getScom (PU_PB_CENT_SM1_EXTFIR_ACTION1_REG)");
            FAPI_TRY(l_extfir_action1.setBit(PU_PB_CENT_SM1_EXTFIR_REG_PB_X3_FIR_ERR +
                                             l_obus),
                     "Error forming EXTFIR action1 register content");
            FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action1),
                     "Error from putScom (PU_PB_CENT_SM1_EXTFIR_ACTION1_REG)");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return l_rc;
}
