/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_setup.C
/// @brief Setup OMI DL
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------
#include <ody_omi_setup.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>

SCOMT_OMI_USE_D_REG_DL0_ERROR_MASK
SCOMT_OMI_USE_D_REG_CMN_CONFIG
SCOMT_OMI_USE_D_REG_DL0_CONFIG1
SCOMT_OMI_USE_D_REG_DL0_CYA_BITS

///
/// @brief Checks the ATTR_MFG_FLAGS for manufacturing mode
///
/// @param[out] o_mfg_mode Indicates if the manufacturing mode flag is set
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_setup_get_mfg_mode(bool& o_mfg_mode)
{
    constexpr uint32_t MFG_FLAG = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;
    constexpr size_t CELL_SIZE = 32;
    const size_t l_index = MFG_FLAG / CELL_SIZE;
    const size_t l_flag_pos = MFG_FLAG % CELL_SIZE;

    uint32_t l_mfg_flags[4] = {};
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags));

    o_mfg_mode = (l_mfg_flags[l_index] & l_flag_pos) ? true : false;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Setup OMI DL
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_setup(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_setup");

    using namespace scomt::omi;

    D_REG_DL0_ERROR_MASK_t l_dl0_error_mask;
    D_REG_CMN_CONFIG_t l_cmn_config;
    D_REG_DL0_CONFIG1_t l_dl0_config1;
    D_REG_DL0_CYA_BITS_t l_dl0_cya;

    bool l_mfg_mode = false;

    FAPI_TRY(ody_omi_setup_get_mfg_mode(l_mfg_mode));

    //Clear mask to all training done FIR
    FAPI_TRY(l_dl0_error_mask.getScom(i_target));
    l_dl0_error_mask.set_39(0);
    FAPI_TRY(l_dl0_error_mask.putScom(i_target));

    FAPI_TRY(l_cmn_config.getScom(i_target));
    l_cmn_config.set_SPARE(0);
    l_cmn_config.set_RX_EDGE_ENA(1);
    l_cmn_config.set_RX_EDGE_MARGIN(1);
    l_cmn_config.set_DISABLE_XSTOPIN(0);
    l_cmn_config.set_RECAL_TIMER(7);
    l_cmn_config.set_DBG_EN(0);
    l_cmn_config.set_DBG_SEL(0);
    FAPI_TRY(l_cmn_config.putScom(i_target));

    FAPI_TRY(l_dl0_config1.getScom(i_target));
    l_dl0_config1.set_PREIPL_PRBS_TIME(1);

    if (l_mfg_mode)
    {
        l_dl0_config1.set_EDPL_TIME(10); // 10: 512s
        l_dl0_config1.set_EDPL_THRESHOLD(3); // 3: 8 Errors
    }
    else
    {
        l_dl0_config1.set_EDPL_TIME(6); // 6: 128mS
        l_dl0_config1.set_EDPL_THRESHOLD(7); // 7: 128 Errors
    }

    l_dl0_config1.set_EDPL_ENA(1);
    FAPI_TRY(l_dl0_config1.putScom(i_target));

    FAPI_TRY(l_dl0_cya.getScom(i_target));
    l_dl0_cya.set_FRBUF_FULL(1);
    FAPI_TRY(l_dl0_cya.putScom(i_target));

fapi_try_exit:
    FAPI_DBG("End ody_omi_setup");
    return fapi2::current_err;
}
