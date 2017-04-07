/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_revert_sbe_mcs_setup.C $ */
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
/// @file p9_revert_sbe_mcs_setup.C
/// @brief Revert MC configuration applied by SBE (FAPI2)

///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_revert_sbe_mcs_setup.H>
#include <p9_perv_scom_addresses.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// MCS target type constants
const uint8_t NUM_MCS_TARGETS = 4;

const uint64_t MCS_CPLT_CTRL1_ARR[NUM_MCS_TARGETS] =
{
    PERV_N3_CPLT_CTRL1,
    PERV_N3_CPLT_CTRL1,
    PERV_N1_CPLT_CTRL1,
    PERV_N1_CPLT_CTRL1
};

const uint64_t MCS_CPLT_CTRL1_BIT_ARR[NUM_MCS_TARGETS] =
{
    10,
    10,
    9,
    9
};

const uint64_t MCS_MCFGP_ARR[NUM_MCS_TARGETS] =
{
    MCS_0_MCFGP,
    MCS_1_MCFGP,
    MCS_2_MCFGP,
    MCS_3_MCFGP
};
const uint64_t MCS_MCMODE1_ARR[NUM_MCS_TARGETS] =
{
    MCS_0_MCMODE1,
    MCS_1_MCMODE1,
    MCS_2_MCMODE1,
    MCS_3_MCMODE1
};
const uint64_t MCS_MCPERF1_ARR[NUM_MCS_TARGETS] =
{
    MCS_0_MCPERF1,
    MCS_1_MCPERF1,
    MCS_2_MCPERF1,
    MCS_3_MCPERF1
};
const uint64_t MCS_MCFIRMASK_OR_ARR[NUM_MCS_TARGETS] =
{
    MCS_0_MCFIRMASK_OR,
    MCS_1_MCFIRMASK_OR,
    MCS_2_MCFIRMASK_OR,
    MCS_3_MCFIRMASK_OR
};


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// helper function for MCS target type
fapi2::ReturnCode
revert_mcs_hb_dcbz_config(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                          const uint8_t i_mcs)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_cplt_ctrl1;
    fapi2::buffer<uint64_t> l_mcfgp;
    fapi2::buffer<uint64_t> l_mcmode1;
    fapi2::buffer<uint64_t> l_mcperf1;
    fapi2::buffer<uint64_t> l_mcfirmask;

    FAPI_TRY(fapi2::getScom(i_target, MCS_CPLT_CTRL1_ARR[i_mcs], l_cplt_ctrl1),
             "Error from getscom (CPLT_CTRL1)");

    if (!l_cplt_ctrl1.getBit(MCS_CPLT_CTRL1_BIT_ARR[i_mcs]))
    {
        // MCFGP -- mark BAR invalid & reset grouping configuration fields
        FAPI_TRY(fapi2::getScom(i_target, MCS_MCFGP_ARR[i_mcs], l_mcfgp),
                 "Error from getScom (MCS%d_MCFGP)", i_mcs);
        l_mcfgp.clearBit<MCS_MCFGP_VALID>();
        l_mcfgp.clearBit<MCS_MCFGP_MC_CHANNELS_PER_GROUP,
                         MCS_MCFGP_MC_CHANNELS_PER_GROUP_LEN>();
        l_mcfgp.clearBit<MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION,
                         MCS_MCFGP_CHANNEL_0_GROUP_MEMBER_IDENTIFICATION_LEN>();
        l_mcfgp.clearBit<MCS_MCFGP_GROUP_SIZE, MCS_MCFGP_GROUP_SIZE_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, MCS_MCFGP_ARR[i_mcs], l_mcfgp),
                 "Error from putScom (MCS%d_MCFGP)", i_mcs);

        // MCMODE1 -- enable speculation, cmd bypass, fp command bypass
        FAPI_TRY(fapi2::getScom(i_target, MCS_MCMODE1_ARR[i_mcs], l_mcmode1),
                 "Error from getScom (MCS%d_MCMODE1)", i_mcs);
        l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_ALL_SPEC_OPS>();
        l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_SPEC_OP,
                           MCS_MCMODE1_DISABLE_SPEC_OP_LEN>();
        l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_COMMAND_BYPASS,
                           MCS_MCMODE1_DISABLE_COMMAND_BYPASS_LEN>();
        l_mcmode1.clearBit<MCS_MCMODE1_DISABLE_FP_COMMAND_BYPASS>();
        FAPI_TRY(fapi2::putScom(i_target, MCS_MCMODE1_ARR[i_mcs], l_mcmode1),
                 "Error from putScom (MCS%d_MCMODE1)", i_mcs);

        // MCS_MCPERF1 -- enable fast path
        FAPI_TRY(fapi2::getScom(i_target, MCS_MCPERF1_ARR[i_mcs], l_mcperf1),
                 "Error from getScom (MCS%d_MCPERF1)", i_mcs);
        l_mcperf1.clearBit<MCS_MCPERF1_DISABLE_FASTPATH>();
        FAPI_TRY(fapi2::putScom(i_target, MCS_MCPERF1, l_mcperf1),
                 "Error from putScom (MCS%d_MCPERF1)", i_mcs);

        // Re-mask MCFIR. We want to ensure all MCSs are masked
        // until the BARs are opened later during IPL.
        l_mcfirmask.flush<1>();
        FAPI_TRY(fapi2::putScom(i_target, MCS_MCFIRMASK_OR_ARR[i_mcs], l_mcfirmask),
                 "Error from putScom (MCS % d_MCFIRMASK_OR)", i_mcs);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// helper function for MI target type
fapi2::ReturnCode
revert_mi_hb_dcbz_config(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // TODO: implement for Cumulus/MI target type
    (void) i_target;
    goto fapi_try_exit;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// HWP entry point
fapi2::ReturnCode
p9_revert_sbe_mcs_setup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_IPL_PHASE_Type l_ipl_phase;
    auto l_mcs_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>(fapi2::TARGET_STATE_PRESENT);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE, FAPI_SYSTEM, l_ipl_phase),
             "Error from FAPI_ATTR_GET (ATTR_SYSTEM_IPL_PHASE)");

    if (l_ipl_phase == fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_CHIP_CONTAINED)
    {

        FAPI_INF("Leaving MC BAR configured for chip contained execution");
        goto fapi_try_exit;
    }

    if (l_mcs_chiplets.size())
    {
        for (uint8_t l_mcs = 0; l_mcs < NUM_MCS_TARGETS; l_mcs++)
        {
            FAPI_TRY(revert_mcs_hb_dcbz_config(i_target, l_mcs),
                     "Error from revert_mcs_hb_dcbz_config");
        }
    }
    else
    {
        FAPI_TRY(revert_mi_hb_dcbz_config(i_target),
                 "Error from revert_mi_hb_dcbz_config");
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
