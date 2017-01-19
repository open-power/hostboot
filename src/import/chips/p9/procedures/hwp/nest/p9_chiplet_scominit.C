/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_chiplet_scominit.C
///
/// @brief SCOM inits to all chiplets (sans Quad)
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
#include <p9_chiplet_scominit.H>
#include <p9_fbc_no_hp_scom.H>
#include <p9_fbc_ioe_tl_scom.H>
#include <p9_fbc_ioe_dl_scom.H>
#include <p9_fbc_ioo_tl_scom.H>
#include <p9_fbc_ioo_dl_scom.H>
#include <p9_mcs_scom.H>
#include <p9_cxa_scom.H>
#include <p9_nx_scom.H>
#include <p9_int_scom.H>
#include <p9_vas_scom.H>

#include <p9_xbus_scom_addresses.H>
#include <p9_xbus_scom_addresses_fld.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t FBC_IOE_TL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOE_TL_FIR_ACTION1 = 0x004B000000000000ULL;
const uint64_t FBC_IOE_TL_FIR_MASK    = 0xFF24F0303FFFFFFFULL;

const uint64_t FBC_IOO_TL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_ACTION1 = 0x0002400000000000ULL;
const uint64_t FBC_IOO_TL_FIR_MASK    = 0xFF6DB0000FFFFFFFULL;

const uint64_t FBC_IOE_DL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOE_DL_FIR_ACTION1 = 0x0303C00000001FFCULL;
const uint64_t FBC_IOE_DL_FIR_MASK    = 0xFCFC3FFFFFFFE003ULL;

const uint64_t FBC_IOO_DL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_DL_FIR_ACTION1 = 0x0303C0000300FFFCULL;
const uint64_t FBC_IOO_DL_FIR_MASK    = 0xFCFC3FFFFCFF000CULL;

// link 0,1 internal errors are a simulation artifact in dd1 so they need to be masked
const uint64_t FBC_IOO_DL_FIR_MASK_SIM_DD1 = 0xFCFC3FFFFCFF000FULL;
//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    char l_procTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    char l_chipletTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_XBUS>> l_xbus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_mcs_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CAPP>> l_capp_targets;
    uint8_t l_dd1 = 0;
    uint8_t l_is_simulation = 0;

    fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_fbc_optics_cfg_mode = { fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP };
    FAPI_DBG("Start");

    // Get attribute to check if it is dd1 or dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_P9N_DD1_SPY_NAMES, i_target, l_dd1));
    // Get simulation indicator attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_is_simulation));

    // Get proc target string
    fapi2::toString(i_target, l_procTargetStr, sizeof(l_procTargetStr));

    l_mcs_targets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();

    for (auto l_mcs_target : l_mcs_targets)
    {
        fapi2::toString(l_mcs_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
        FAPI_DBG("Invoking p9.mcs.scom.initfile on target %s...", l_chipletTargetStr);
        FAPI_EXEC_HWP(l_rc, p9_mcs_scom, l_mcs_target, FAPI_SYSTEM, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9.mcs.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

    }

    // apply FBC non-hotplug initfile
    FAPI_DBG("Invoking p9.fbc.no_hp.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_fbc_no_hp_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_no_hp_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // setup IOE (XBUS FBC IO) TL SCOMs
    FAPI_DBG("Invoking p9.fbc.ioe_tl.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioe_tl_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioe_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    l_xbus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_XBUS>();

    if (l_xbus_chiplets.size())
    {
        FAPI_TRY(fapi2::putScom(i_target, PU_PB_IOE_FIR_ACTION0_REG, FBC_IOE_TL_FIR_ACTION0),
                 "Error from putScom (PU_PB_IOE_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_PB_IOE_FIR_ACTION1_REG, FBC_IOE_TL_FIR_ACTION1),
                 "Error from putScom (PU_PB_IOE_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_PB_IOE_FIR_MASK_REG, FBC_IOE_TL_FIR_MASK),
                 "Error from putScom (PU_PB_IOE_FIR_MASK_REG)");
    }

    // setup IOE (XBUS FBC IO) DL SCOMs
    for (auto l_iter = l_xbus_chiplets.begin();
         l_iter != l_xbus_chiplets.end();
         l_iter++)
    {
        fapi2::toString(*l_iter, l_chipletTargetStr, sizeof(l_chipletTargetStr));
        FAPI_DBG("Invoking p9.fbc.ioe_dl.scom.initfile on target %s...", l_chipletTargetStr);
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioe_dl_scom, *l_iter, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioe_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        // configure action registers & unmask
        FAPI_TRY(fapi2::putScom(*l_iter, XBUS_LL0_IOEL_FIR_ACTION0_REG, FBC_IOE_DL_FIR_ACTION0),
                 "Error from putScom (XBUS_LL0_IOEL_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(*l_iter, XBUS_LL0_IOEL_FIR_ACTION1_REG, FBC_IOE_DL_FIR_ACTION1),
                 "Error from putScom (XBUS_LL0_IOEL_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(*l_iter, XBUS_LL0_LL0_LL0_IOEL_FIR_MASK_REG, FBC_IOE_DL_FIR_MASK),
                 "Error from putScom (XBUS_LL0_LL0_LL0_IOEL_FIR_MASK_REG)");
    }

    // set FBC optics config mode attribute
    l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

    for (auto l_iter = l_obus_chiplets.begin();
         l_iter != l_obus_chiplets.end();
         l_iter++)
    {
        uint8_t l_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_iter, l_unit_pos),
                 "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)");
        FAPI_INF("Updating index: %d\n", l_unit_pos);
        FAPI_INF("  before: %d\n", l_fbc_optics_cfg_mode[l_unit_pos]);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, *l_iter, l_fbc_optics_cfg_mode[l_unit_pos]),
                 "Error from FAPI_ATTR_GET(ATTR_OPTICS_CONFIG_MODE)");
        FAPI_INF("  after: %d\n", l_fbc_optics_cfg_mode[l_unit_pos]);
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, i_target, l_fbc_optics_cfg_mode),
             "Error from FAPI_ATTR_SET(ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE)");

    // invoke IOO (OBUS FBC IO) SCOM initfiles
    FAPI_DBG("Invoking p9.fbc.ioo_tl.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_tl_scom, i_target);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioo_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    if (l_obus_chiplets.size())
    {
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_ACTION0_REG, FBC_IOO_TL_FIR_ACTION0),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_ACTION1_REG, FBC_IOO_TL_FIR_ACTION1),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_MASK_REG, FBC_IOO_TL_FIR_MASK),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_MASK_REG)");
    }

    for (auto l_iter = l_obus_chiplets.begin();
         l_iter != l_obus_chiplets.end();
         l_iter++)
    {
        fapi2::toString(*l_iter, l_chipletTargetStr, sizeof(l_chipletTargetStr));
        FAPI_DBG("Invoking p9.fbc.ioo_dl.scom.initfile on target %s...", l_chipletTargetStr);
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_dl_scom, *l_iter);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioo_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        // configure action registers & unmask
        FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_PB_IOOL_FIR_ACTION0_REG, FBC_IOO_DL_FIR_ACTION0),
                 "Error from putScom (OBUS_LL0_PB_IOOL_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_PB_IOOL_FIR_ACTION1_REG, FBC_IOO_DL_FIR_ACTION1),
                 "Error from putScom (OBUS_LL0_PB_IOOL_FIR_ACTION1_REG)");

        if ((l_dd1 != 0) && (l_is_simulation == 1))
        {
            FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG, FBC_IOO_DL_FIR_MASK_SIM_DD1),
                     "Error from putScom (OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_SIM_DD1)");
        }
        else
        {
            FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG, FBC_IOO_DL_FIR_MASK),
                     "Error from putScom (OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG)");
        }
    }

    // Invoke NX SCOM initfile
    FAPI_DBG("Invoking p9.nx.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_nx_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_nx_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // Invoke CXA SCOM initfile
    l_capp_targets = i_target.getChildren<fapi2::TARGET_TYPE_CAPP>();

    for (auto l_capp : l_capp_targets)
    {
        fapi2::toString(l_capp, l_chipletTargetStr, sizeof(l_chipletTargetStr));
        FAPI_DBG("Invoking p9.cxa.scom.initfile on target %s...", l_chipletTargetStr);
        FAPI_EXEC_HWP(l_rc, p9_cxa_scom, l_capp, FAPI_SYSTEM, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_cxa_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    // Invoke INT SCOM initfile
    FAPI_DBG("Invoking p9.int.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_int_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_int_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    // Invoke VAS SCOM initfile
    FAPI_DBG("Invoking p9.vas.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_vas_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_vas_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
