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
/// @brief SCOM inits to all chiplets (sans Quad/fabric)
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
#include <p9_fbc_ioo_tl_scom.H>
#include <p9_fbc_ioo_dl_scom.H>
#include <p9n_mcs_scom.H>

//TODO: RTC 176054
#ifndef __HOSTBOOT_MODULE
    #include <p9c_dmi_scom.H>
    #include <p9c_mi_scom.H>
    #include <p9c_mc_scom.H>
#endif

#include <p9_cxa_scom.H>
#include <p9_nx_scom.H>
#include <p9_int_scom.H>
#include <p9_vas_scom.H>

#include <p9_xbus_scom_addresses.H>
#include <p9_xbus_scom_addresses_fld.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_perv_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t FBC_IOO_TL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_ACTION1 = 0x0002400000000000ULL;
const uint64_t FBC_IOO_TL_FIR_ACTION1_HW414700 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_MASK    = 0xFF6DB0000FFFFFFFULL;

const uint64_t FBC_IOO_DL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_DL_FIR_ACTION1 = 0x0303C0000300FFFCULL;
const uint64_t FBC_IOO_DL_FIR_MASK    = 0xFCFC3FFFFCFF000CULL;

// link 0,1 internal errors are a simulation artifact in dd1 so they need to be masked
const uint64_t FBC_IOO_DL_FIR_MASK_SIM = 0xFCFC3FFFFCFF000FULL;

static const uint8_t OBRICK0_POS  = 0x0;
static const uint8_t OBRICK1_POS  = 0x1;
static const uint8_t OBRICK2_POS  = 0x2;
static const uint8_t OBRICK9_POS  = 0x9;
static const uint8_t OBRICK10_POS = 0xA;
static const uint8_t OBRICK11_POS = 0xB;

static const uint8_t PERV_OB_CPLT_CONF1_OBRICKA_IOVALID = 0x6;
static const uint8_t PERV_OB_CPLT_CONF1_OBRICKB_IOVALID = 0x7;
static const uint8_t PERV_OB_CPLT_CONF1_OBRICKC_IOVALID = 0x8;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    char l_procTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    char l_chipletTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_mcs_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MI>> l_mi_targets;

//TODO: RTC 176054
#ifndef __HOSTBOOT_MODULE
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MC>> l_mc_targets;
#endif

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DMI>> l_dmi_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CAPP>> l_capp_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS_BRICK>> l_obrick_targets;
    fapi2::buffer<uint64_t> l_ob0data(0x0);
    fapi2::buffer<uint64_t> l_ob3data(0x0);
    uint8_t l_no_ndl_iovalid = 0;
    uint8_t l_is_simulation = 0;

    FAPI_DBG("Start");

    // Get attribute to check if NDL IOValids need to be set (dd2+)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_P9_NO_NDL_IOVALID, i_target, l_no_ndl_iovalid));
    // Get simulation indicator attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_is_simulation));

    // Get proc target string
    fapi2::toString(i_target, l_procTargetStr, sizeof(l_procTargetStr));

    // invoke IOO (OBUS FBC IO) SCOM initfiles
    l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();

    for (auto l_obus_target : l_obus_chiplets)
    {
        uint8_t l_unit_pos;
        uint8_t l_obus_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_obus_target, l_unit_pos),
                 "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, l_obus_target, l_obus_mode),
                 "Error from FAPI_ATTR_GET(ATTR_OPTICS_CONFIG_MODE)");

        //Update NDL IOValid data as needed
        if (!l_no_ndl_iovalid && (l_unit_pos == 0 || l_unit_pos == 3) && //NDL only exists on obus 0 and 3
            l_obus_mode == fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_NV)
        {

            l_obrick_targets = l_obus_target.getChildren<fapi2::TARGET_TYPE_OBUS_BRICK>();

            for (auto l_obrick_target : l_obrick_targets)
            {
                fapi2::toString(l_obrick_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
                FAPI_DBG("Setting NDL IOValid for %s...", l_chipletTargetStr);

                uint8_t l_unit_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_obrick_target, l_unit_pos),
                         "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)");

                //Mapping from John Irish (jdirish@us.ibm.com)
                //OBus   Register bit       NV instance   NV pos
                //OB0    NV0 io_valid(A)    STK0.NTL0..   0
                //OB0    NV1 io_valid(B)    STK0.NTL1..   1
                //OB0    NV2 io_valid(C)    STK1.NTL0..   2
                //OB3    NV2 io_valid(C)    STK1.NTL1..   3
                //OB3    NV1 io_valid(B)    STK2.NTL0..   4
                //OB3    NV0 io_valid(A)    STK2.NTL1..   5
                switch (l_unit_pos)
                {
                    case OBRICK0_POS:
                        l_ob0data.setBit<PERV_OB_CPLT_CONF1_OBRICKA_IOVALID>();
                        break;

                    case OBRICK1_POS:
                        l_ob0data.setBit<PERV_OB_CPLT_CONF1_OBRICKB_IOVALID>();
                        break;

                    case OBRICK2_POS:
                        l_ob0data.setBit<PERV_OB_CPLT_CONF1_OBRICKC_IOVALID>();
                        break;

                    //OBRICK3..8 associated with OBUS 1 & 2 do not have NDL

                    case OBRICK9_POS:
                        l_ob3data.setBit<PERV_OB_CPLT_CONF1_OBRICKC_IOVALID>();
                        break;

                    case OBRICK10_POS:
                        l_ob3data.setBit<PERV_OB_CPLT_CONF1_OBRICKB_IOVALID>();
                        break;

                    case OBRICK11_POS:
                        l_ob3data.setBit<PERV_OB_CPLT_CONF1_OBRICKA_IOVALID>();
                        break;

                    default:
                        FAPI_ASSERT(false, fapi2::P9_CHIPLET_SCOMINIT_UNSUPPORTED_OBRICK_POS_ERR().set_TARGET(l_obrick_target),
                                    "ERROR; Unsupported NV position.");

                }

            }

        }

    }

    //Write the NDL IOValid registers as needed.
    if (l_ob0data != 0)
    {
        FAPI_TRY(putScom(i_target, PERV_OB0_CPLT_CONF1_OR, l_ob0data));
    }

    if (l_ob3data != 0)
    {
        FAPI_TRY(putScom(i_target, PERV_OB3_CPLT_CONF1_OR, l_ob3data));
    }


    l_mcs_targets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();
    l_mi_targets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();
    l_dmi_targets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();

//TODO: RTC 176054
#ifndef __HOSTBOOT_MODULE
    l_mc_targets = i_target.getChildren<fapi2::TARGET_TYPE_MC>();
#endif

    if (l_mcs_targets.size())
    {
        for (auto l_mcs_target : l_mcs_targets)
        {
            fapi2::toString(l_mcs_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
            FAPI_DBG("Invoking p9n.mcs.scom.initfile on target %s...", l_chipletTargetStr);
            FAPI_EXEC_HWP(l_rc, p9n_mcs_scom, l_mcs_target, FAPI_SYSTEM, i_target,
                          l_mcs_target.getParent<fapi2::TARGET_TYPE_MCBIST>());

            if (l_rc)
            {
                FAPI_ERR("Error from p9.mcs.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }
    }

//TODO: RTC 176054
#ifndef __HOSTBOOT_MODULE

    else if (l_mc_targets.size())
    {
        for (auto l_mc_target : l_mc_targets)
        {
            fapi2::toString(l_mc_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
            FAPI_DBG("Invoking p9c.mc.scom.initfile on target %s...", l_chipletTargetStr);
            FAPI_EXEC_HWP(l_rc, p9c_mc_scom, l_mc_target, FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p9c.mc.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }

        for (auto l_mi_target : l_mi_targets)
        {
            fapi2::toString(l_mi_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
            FAPI_DBG("Invoking p9c.mi.scom.initfile on target %s...", l_chipletTargetStr);
            FAPI_EXEC_HWP(l_rc, p9c_mi_scom, l_mi_target, FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p9c.mi.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }

        for (auto l_dmi_target : l_dmi_targets)
        {
            fapi2::toString(l_dmi_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
            FAPI_DBG("Invoking p9c.dmi.scom.initfile on target %s...", l_chipletTargetStr);
            FAPI_EXEC_HWP(l_rc, p9c_dmi_scom, l_dmi_target, FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p9c.dmi.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }
    }

//TODO: RTC 176054
#endif // __HOSTBOOT_MODULE

    else
    {
        FAPI_INF("No MCS/MI targets found! Do nothing!");
    }


    FAPI_DBG("Invoking p9.fbc.ioo_tl.scom.initfile on target %s...", l_procTargetStr);
    FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_tl_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p9_fbc_ioo_tl_scom");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    if (l_obus_chiplets.size())
    {
        uint8_t l_hw414700;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, i_target, l_hw414700),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW414700)");
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_ACTION0_REG, FBC_IOO_TL_FIR_ACTION0),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_ACTION1_REG,
                                (l_hw414700) ?
                                (FBC_IOO_TL_FIR_ACTION1_HW414700) :
                                (FBC_IOO_TL_FIR_ACTION1)),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_IOO_FIR_MASK_REG, FBC_IOO_TL_FIR_MASK),
                 "Error from putScom (PU_IOE_PB_IOO_FIR_MASK_REG)");
    }

    for (auto l_iter = l_obus_chiplets.begin();
         l_iter != l_obus_chiplets.end();
         l_iter++)
    {
        fapi2::toString(*l_iter, l_chipletTargetStr, sizeof(l_chipletTargetStr));

        // configure action registers & unmask
        FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_PB_IOOL_FIR_ACTION0_REG, FBC_IOO_DL_FIR_ACTION0),
                 "Error from putScom (OBUS_LL0_PB_IOOL_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_PB_IOOL_FIR_ACTION1_REG, FBC_IOO_DL_FIR_ACTION1),
                 "Error from putScom (OBUS_LL0_PB_IOOL_FIR_ACTION1_REG)");

        if (l_is_simulation == 1)
        {
            FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG, FBC_IOO_DL_FIR_MASK_SIM),
                     "Error from putScom (OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG_SIM_DD1)");
        }
        else
        {
            FAPI_TRY(fapi2::putScom(*l_iter, OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG, FBC_IOO_DL_FIR_MASK),
                     "Error from putScom (OBUS_LL0_LL0_LL0_PB_IOOL_FIR_MASK_REG)");
        }

        FAPI_DBG("Invoking p9.fbc.ioo_dl.scom.initfile on target %s...", l_chipletTargetStr);
        FAPI_EXEC_HWP(l_rc, p9_fbc_ioo_dl_scom, *l_iter, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_fbc_ioo_dl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
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
