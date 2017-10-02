/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
// *HWP Level : 3
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_chiplet_scominit.H>
#include <p9_xbus_fir_utils.H>
#include <p9_fbc_ioo_tl_scom.H>
#include <p9_fbc_ioo_dl_scom.H>
#include <p9n_mcs_scom.H>
#include <p9c_dmi_scom.H>
#include <p9c_mi_scom.H>
#include <p9c_mc_scom.H>
#include <p9_cxa_scom.H>
#include <p9_nx_scom.H>
#include <p9_int_scom.H>
#include <p9_vas_scom.H>
#include <p9_fbc_smp_utils.H>
#include <p9_mc_scom_addresses.H>
#include <p9_xbus_scom_addresses.H>
#include <p9_xbus_scom_addresses_fld.H>
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_perv_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t FBC_IOO_TL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_ACTION1 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_TL_FIR_MASK    = 0xFF6DB0000FFFFFFFULL;

const uint64_t FBC_IOO_DL_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t FBC_IOO_DL_FIR_ACTION1 = 0x0303C0000300FF0CULL;
const uint64_t FBC_IOO_DL_FIR_MASK    = 0xFCFC3FFFFCFF00F3ULL;

// link 0,1 internal errors are a simulation artifact in dd1 so they need to be masked
const uint64_t FBC_IOO_DL_FIR_MASK_SIM = 0xFCFC3FFFFCFF00FFULL;

static const uint8_t N3_PG_NPU_REGION_BIT = 7;

// MCBIST FIR (Cumulus)
static const uint64_t MCBIST_FIR_ACTION0 = 0x0000000000000000ULL;
static const uint64_t MCBIST_FIR_ACTION1 = 0x2000000000000000ULL;
static const uint64_t MCBIST_FIR_MASK    = 0xDC00000000000000ULL;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scom_data;
    char l_procTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    char l_chipletTargetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_xbus_present[P9_FBC_UTILS_MAX_ELECTRICAL_LINKS] = {0};
    uint8_t l_xbus_functional[P9_FBC_UTILS_MAX_ELECTRICAL_LINKS] = {0};
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_XBUS>> l_xbus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>> l_obus_chiplets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_mcs_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MI>> l_mi_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MC>> l_mc_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DMI>> l_dmi_targets;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CAPP>> l_capp_targets;
    uint8_t l_is_simulation = 0;
    uint8_t l_nmmu_ndd1 = 0;
    uint32_t l_eps_write_cycles_t1 = 0;
    uint32_t l_eps_write_cycles_t2 = 0;
    uint8_t l_npu_enabled = 0;

    FAPI_DBG("Start");

    // Get simulation indicator attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_is_simulation));

    // Get proc target string
    fapi2::toString(i_target, l_procTargetStr, sizeof(l_procTargetStr));

    // check to see if NPU region in N3 chiplet partial good data is enabled
    // init PG data to disabled
    {
        fapi2::buffer<uint16_t> l_pg_value = 0xFFFF;

        for (auto l_tgt : i_target.getChildren<fapi2::TARGET_TYPE_PERV>
             (fapi2::TARGET_FILTER_NEST_WEST, fapi2::TARGET_STATE_FUNCTIONAL))
        {
            uint8_t l_attr_chip_unit_pos = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_tgt,
                                   l_attr_chip_unit_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            if (l_attr_chip_unit_pos == N3_CHIPLET_ID)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_tgt, l_pg_value));
                break;
            }
        }

        // a bit value of 0 in the PG attribute means the associated region is good
        if (!l_pg_value.getBit<N3_PG_NPU_REGION_BIT>())
        {
            l_npu_enabled = 1;
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_NPU_REGION_ENABLED,
                               i_target,
                               l_npu_enabled),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_NPU_ENABLED)");
    }

    l_xbus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_XBUS>();
    l_obus_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OBUS>();
    l_mcs_targets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();
    l_mi_targets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();
    l_dmi_targets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();
    l_mc_targets = i_target.getChildren<fapi2::TARGET_TYPE_MC>();

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

            FAPI_TRY(fapi2::putScom(l_mc_target, MCBIST_MCBISTFIRACT0, MCBIST_FIR_ACTION0),
                     "Error from putScom (MCBIST_MCBISTFIRACT0)");
            FAPI_TRY(fapi2::putScom(l_mc_target, MCBIST_MCBISTFIRACT1, MCBIST_FIR_ACTION1),
                     "Error from putScom (MCBIST_MCBISTFIRACT1)");
            FAPI_TRY(fapi2::putScom(l_mc_target, MCBIST_MCBISTFIRMASK, MCBIST_FIR_MASK),
                     "Error from putScom (MCBIST_MCBISTFIRMASK)");
        }

        for (auto l_mi_target : l_mi_targets)
        {
            fapi2::toString(l_mi_target, l_chipletTargetStr, sizeof(l_chipletTargetStr));
            FAPI_DBG("Invoking p9c.mi.scom.initfile on target %s...", l_chipletTargetStr);
            FAPI_EXEC_HWP(l_rc, p9c_mi_scom, l_mi_target, FAPI_SYSTEM, i_target);

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
            FAPI_EXEC_HWP(l_rc, p9c_dmi_scom, l_dmi_target, FAPI_SYSTEM, i_target);

            if (l_rc)
            {
                FAPI_ERR("Error from p9c.dmi.scom.initfile");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }
        }
    }
    else
    {
        FAPI_INF("No MCS/MI targets found! Do nothing!");
    }

    // read spare FBC FIR bit -- if set, SBE has configured XBUS FIR resources for all
    // present units, and code here will be run to mask resources associated with
    // non-functional units
    FAPI_TRY(getScom(i_target, PU_PB_CENT_SM0_PB_CENT_FIR_REG, l_scom_data),
             "Error from getScom (PU_PB_CENT_SM0_PB_CENT_FIR_REG)");

    if (l_scom_data.getBit<PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_SPARE_13>())
    {
        FAPI_DBG("Determine set of present XBUS regions on target %s...", l_procTargetStr);
        {
            for (auto& l_cplt_target : i_target.getChildren<fapi2::TARGET_TYPE_PERV>
                 (static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_XBUS),
                  fapi2::TARGET_STATE_FUNCTIONAL))
            {
                fapi2::buffer<uint16_t> l_attr_pg = 0;
                // obtain partial good information to determine viable X links
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_cplt_target, l_attr_pg),
                         "Error from FAPI_ATTR_GET (ATTR_PG)");

                for (uint8_t ii = 0;
                     ii < P9_FBC_UTILS_MAX_ELECTRICAL_LINKS;
                     ii++)
                {
                    l_xbus_present[ii] = !l_attr_pg.getBit(X_PG_IOX0_REGION_BIT + ii) &&
                                         !l_attr_pg.getBit(X_PG_PBIOX0_REGION_BIT + ii);
                }
            }
        }

        FAPI_DBG("Determine set of functional XBUS regions on target %s...", l_procTargetStr);
        {
            for (auto l_iter = l_xbus_chiplets.begin();
                 l_iter != l_xbus_chiplets.end();
                 l_iter++)
            {
                uint8_t l_unit_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_iter, l_unit_pos),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
                l_xbus_functional[l_unit_pos] = 1;
            }
        }

        FAPI_DBG("Masking XBUS FIR resources for unused links on target %s...", l_procTargetStr);
        {
            if (l_xbus_present[0] && !l_xbus_functional[0])
            {
                // XBUS0 FBC DL
                FAPI_TRY(putScom(i_target, XBUS_0_LL0_LL0_LL0_IOEL_FIR_MASK_REG, FBC_IOE_DL_FIR_MASK_NF),
                         "Error from putScom (XBUS_0_LL0_IOEL_FIR_MASK_REG)");
                // XBUS0 PHY
                FAPI_TRY(putScom(i_target, XBUS_FIR_MASK_REG, XBUS_PHY_FIR_MASK_NF),
                         "Error from putScom (XBUS_FIR_MASK_REG)");
            }

            if (!l_xbus_functional[0])
            {
                // XBUS0 FBC TL
                FAPI_TRY(putScom(i_target, PU_PB_IOE_FIR_MASK_REG_OR, FBC_IOE_TL_FIR_MASK_X0_NF),
                         "Error from putScom (PU_PB_IOE_FIR_MASK_REG, X0)");

                // XBUS0 EXTFIR
                FAPI_TRY(putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR, FBC_EXT_FIR_MASK_X0_NF),
                         "Error from putScom (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR)");
            }

            if (l_xbus_present[1] && !l_xbus_functional[1])
            {
                // XBUS1 FBC DL
                FAPI_TRY(putScom(i_target, XBUS_1_LL1_LL1_LL1_IOEL_FIR_MASK_REG, FBC_IOE_DL_FIR_MASK_NF),
                         "Error from putScom (XBUS_1_LL1_IOEL_FIR_MASK_REG)");
                // XBUS1 PHY
                FAPI_TRY(putScom(i_target, XBUS_1_FIR_MASK_REG, XBUS_PHY_FIR_MASK_NF),
                         "Error from putScom (XBUS_1_FIR_MASK_REG)");
            }

            if (!l_xbus_functional[1])
            {
                // XBUS1 FBC TL
                FAPI_TRY(putScom(i_target, PU_PB_IOE_FIR_MASK_REG_OR, FBC_IOE_TL_FIR_MASK_X1_NF),
                         "Error from putScom (PU_PB_IOE_FIR_MASK_REG, X1)");

                // XBUS1 EXTFIR
                FAPI_TRY(putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR, FBC_EXT_FIR_MASK_X1_NF),
                         "Error from putScom (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR)");
            }

            if (l_xbus_present[2] && !l_xbus_functional[2])
            {
                // XBUS2 FBC DL
                FAPI_TRY(putScom(i_target, XBUS_2_LL2_LL2_LL2_IOEL_FIR_MASK_REG, FBC_IOE_DL_FIR_MASK_NF),
                         "Error from putScom (XBUS_2_LL2_IOEL_FIR_MASK_REG)");
                // XBUS2 PHY
                FAPI_TRY(fapi2::putScom(i_target, XBUS_2_FIR_MASK_REG, XBUS_PHY_FIR_MASK_NF),
                         "Error from putScom (XBUS_2_FIR_MASK_REG)");
            }

            if (!l_xbus_functional[2])
            {
                // XBUS2 FBC TL
                FAPI_TRY(putScom(i_target, PU_PB_IOE_FIR_MASK_REG_OR, FBC_IOE_TL_FIR_MASK_X2_NF),
                         "Error from putScom (PU_PB_IOE_FIR_MASK_REG, X2)");

                // XBUS2 EXTFIR
                FAPI_TRY(putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR, FBC_EXT_FIR_MASK_X2_NF),
                         "Error from putScom (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR)");
            }
        }
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

    // Setup NMMU epsilon write cycles
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_NMMU_NDD1, i_target, l_nmmu_ndd1),
             "Error from FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_NMMU_NDD1)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, FAPI_SYSTEM, l_eps_write_cycles_t1),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_WRITE_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, FAPI_SYSTEM, l_eps_write_cycles_t2),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_WRITE_CYCLES_T2)");

    if (!l_nmmu_ndd1)
    {
        FAPI_TRY(fapi2::getScom(i_target, PU_NMMU_MM_EPSILON_COUNTER_VALUE, l_scom_data),
                 "Error from getScom (PU_NMMU_MM_EPSILON_COUNTER_VALUE)");

        l_scom_data.insertFromRight<PU_NMMU_MM_EPSILON_COUNTER_VALUE_WR_TIER_1_CNT_VAL, PU_NMMU_MM_EPSILON_COUNTER_VALUE_WR_TIER_1_CNT_VAL_LEN>
        (l_eps_write_cycles_t1);
        l_scom_data.insertFromRight<PU_NMMU_MM_EPSILON_COUNTER_VALUE_WR_TIER_2_CNT_VAL, PU_NMMU_MM_EPSILON_COUNTER_VALUE_WR_TIER_2_CNT_VAL_LEN>
        (l_eps_write_cycles_t2);

        FAPI_TRY(fapi2::putScom(i_target, PU_NMMU_MM_EPSILON_COUNTER_VALUE, l_scom_data),
                 "Error from putScom (PU_NMMU_MM_EPSILON_COUNTER_VALUE)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
