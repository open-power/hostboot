/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_revert_sbe_mcs_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p10_revert_sbe_mcs_setup.C
/// @brief Revert MC configuration applied by SBE (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_revert_sbe_mcs_setup.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief helper function to revert HB dcbz configuration
///
/// @param[in] i_target Reference to a chip target
/// @param[in] i_target_mc Reference to MC with config'd BAR
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
revert_mc_hb_dcbz_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target_mc)
{
    FAPI_DBG("Start");

    fapi2::ATTR_PROC_SBE_MCS_SETUP_REG_STATES_Type l_reg_states;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MCS_SETUP_REG_STATES,
                           i_target,
                           l_reg_states),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MCS_SETUP_REG_STATES)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCFGP0,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCFGP0]),
             "Error from putScom (MCFGP0)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCMODE0,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCMODE0]),
             "Error from putScom (MCMODE0)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCMODE1,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCMODE1]),
             "Error from putScom (MCMODE1)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCPERF1,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCPERF1]),
             "Error from putScom (MCPERF1)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCFIRMASK_RW,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCFIRMASK]),
             "Error from putScom (MCFIR_WRX)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCFIRACT0,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCFIRACT0]),
             "Error from putScom (MCFIRACT0)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCFIRACT1,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCFIRACT1]),
             "Error from putScom (MCFIRACT1)");

    FAPI_TRY(fapi2::putScom(i_target_mc, scomt::mc::SCOMFIR_MCTO,
                            l_reg_states[fapi2::ENUM_ATTR_PROC_SBE_MCS_SETUP_REG_STATES_MCTO]),
             "Error from putScom (MCTO)");
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// HWP entry point
fapi2::ReturnCode
p10_revert_sbe_mcs_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    auto l_mi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();
    fapi2::ATTR_PROC_SBE_MCS_SETUP_SELECTED_MC_Type l_mc_setup;
    fapi2::ATTR_PROC_SBE_MCS_SETUP_SELECTED_MC_Type l_mc_cplt_id;
    bool l_revert_flag = false;

#ifdef __PPE__

    if (!l_mi_chiplets.size())
    {
        FAPI_ASSERT(false,
                    fapi2::P10_REVERT_SBE_MCS_SETUP_NO_MI_TARGETS_FOUND()
                    .set_CHIP(i_target),
                    "No functional MC unit target found on master chip");
    }

#endif

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MCS_SETUP_SELECTED_MC,
                           i_target,
                           l_mc_setup),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MCS_SETUP_SELECTED_MC)");

    if (l_mi_chiplets.size())
    {
        for (const auto& l_tgt_mi : l_mi_chiplets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_tgt_mi,
                                   l_mc_cplt_id),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            if (l_mc_setup == l_mc_cplt_id)
            {
                l_revert_flag = true;
                FAPI_TRY(revert_mc_hb_dcbz_config(i_target, l_tgt_mi),
                         "Error from revert_mi_hb_dcbz_config (MI)");
                break;
            }
        }

        FAPI_ASSERT(l_revert_flag,
                    fapi2::P10_REVERT_SBE_MCS_SETUP_SELECTED_MC_NOT_FOUND()
                    .set_TARGET(i_target)
                    .set_ATTR_PROC_SBE_MCS_SETUP_SELECTED_MC(l_mc_setup),
                    "Could not find MC that was setup");
    }
    else
    {
        FAPI_INF("No MI targets found! Nothing to do!");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
