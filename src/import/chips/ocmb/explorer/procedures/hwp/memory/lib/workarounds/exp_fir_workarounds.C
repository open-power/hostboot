/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_fir_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_fir_workarounds.C
/// @brief Workarounds for Explorer FIR settings
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/exp_fir_workarounds.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the MC_OMI_FIR x4 degrade FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_X4_DEGRADE_ACTION
/// @param[in,out] io_exp_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_x4_degrade_fir( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint8_t i_omi_fail_action,
                              mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_mc_omi_fir_reg )
{
    // Write MC_OMI_FIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_MASKED:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to masked per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.masked<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_LOCAL_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to local_checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.local_checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        default:
            // By default just leave it recoverable
            FAPI_DBG("%s Leaving MC_OMI_FIR degrade FIR as recoverable per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;
    }
}

///
/// @brief Function handling the MC_OMI_FIR CRC FIR lab overrides
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_crc_debug value from ATTR_OMI_CRC_DEBUG
/// @param[in,out] io_exp_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_omi_crc_firs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                            const uint8_t i_omi_crc_debug,
                            mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_mc_omi_fir_reg )
{
    // Write MC_OMI_FIR register per attr setting
    switch(i_omi_crc_debug)
    {
        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_NACK>();
            break;

        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_RECOVERABLE:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_NACK>();
            break;

        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_LOCAL_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to local_checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.local_checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .local_checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_NACK>();
            break;

        default:
            // By default just leave it
            FAPI_DBG("%s Leaving MC_OMI_FIR CRC FIRs as masked per attribute setting", mss::c_str(i_target));
            break;
    }
}

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_crc_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS
/// @param[in] i_omi_mfg_screen_crc value from check_omi_mfg_screen_crc_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_crc_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const bool i_omi_crc_dd1_wkrnd,
                             const bool i_omi_mfg_screen_crc,
                             mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_dlx_omi_fir_reg )
{
    // Set up MNFG OMI screen settings
    if (i_omi_mfg_screen_crc)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR CRC FIR to masked for MFG test", mss::c_str(i_target));
        io_exp_dlx_omi_fir_reg.remask<EXPLR_DLX_MC_OMI_FIR_REG_DL0_CRC_ERROR>();
    }
    // Or unmask to recoverable if we're on DD2.0+
    else if (!i_omi_crc_dd1_wkrnd)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR CRC FIR to recoverable for DD2.0+", mss::c_str(i_target));
        io_exp_dlx_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_CRC_ERROR>();
    }
    // Or leave it as-is (masked or lab override setting) for DD1.0
    else
    {
        FAPI_DBG("%s Leaving MC_OMI_FIR CRC FIR as-is for DD1.0", mss::c_str(i_target));
    }
}

///
/// @brief Function handling the MC_OMI_FIR EDPL FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_edpl_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS
/// @param[in] i_omi_mfg_screen_edpl value from check_omi_mfg_screen_edpl_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_edpl_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const bool i_omi_edpl_dd1_wkrnd,
                              const bool i_omi_mfg_screen_edpl,
                              mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_dlx_omi_fir_reg )
{
    // Set up MNFG OMI screen settings
    if (i_omi_mfg_screen_edpl)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR EDPL FIR to masked for MFG test", mss::c_str(i_target));
        io_exp_dlx_omi_fir_reg.remask<EXPLR_DLX_MC_OMI_FIR_REG_DL0_EDPL>();
    }
    // Or unmask to recoverable if we're on DD2.0+
    else if (!i_omi_edpl_dd1_wkrnd)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR EDPL FIR to recoverable for DD2.0+", mss::c_str(i_target));
        io_exp_dlx_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_EDPL>();
    }
    // Or leave it as-is (masked or lab override setting) for DD1.0
    else
    {
        FAPI_DBG("%s Leaving MC_OMI_FIR EDPL FIR as-is for DD1.0", mss::c_str(i_target));
    }
}

} // fir
} // workarounds
} // exp
} // mss
