/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_fir_workarounds.C $ */
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
/// @file p10_fir_workarounds.C
/// @brief Workarounds for p10 fir workaround
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <cstdarg>
#include <fapi2.H>
#include <p10_scom_mcc.H>
#include <lib/shared/p10_consts.H>
#include <lib/fir/p10_fir_traits.H>
#include <lib/workarounds/p10_fir_workarounds.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/mss_p10_attribute_setters.H>

namespace mss
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the chip_ec dependent setting of USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE
/// @param[in] i_doubledead_support value of ATTR_CHIP_EC_FEATURE_USTLCFG_LOL_DOUBLEDEAD_SUPPORT
/// @param[in,out] io_ustlcfg_data buffer for USTLCFG data
///
void set_lol_doubledead_support( const bool i_doubledead_support,
                                 fapi2::buffer<uint64_t>& io_ustlcfg_data )
{
    const uint8_t l_setting = i_doubledead_support ? 0b10 : 0b11;
    io_ustlcfg_data.insertFromRight<scomt::mcc::USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE,
                                    scomt::mcc::USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN>
                                    (l_setting);
}

///
/// @brief Function handling the chip_ec dependent setting of P10_20_USTL_USTLCFG_WRSTUCK_MITIGATION_EN_P10D20
/// @param[in] i_wrstuck_support value of ATTR_CHIP_EC_FEATURE_USTLCFG_WRSTUCK_MITIGATION
/// @param[in,out] io_ustlcfg_data buffer for USTLCFG data
///
void set_wrstuck_mitigation( const bool i_wrstuck_support,
                             fapi2::buffer<uint64_t>& io_ustlcfg_data )
{
    if (i_wrstuck_support)
    {
        io_ustlcfg_data.setBit<scomt::mcc::P10_20_USTL_USTLCFG_WRSTUCK_MITIGATION_EN_P10D20>();
    }
}

///
/// @brief Function handling the chip_ec dependent setting of USTL_USTLLOLMASK
/// @param[in] i_loldrop_support value of ATTR_CHIP_EC_FEATURE_HW555009_LOLDROP
/// @param[in,out] io_ustllolmask_data buffer for USTLLOLMASK data
///
void setup_loldrop_masks( const bool i_loldrop_support,
                          fapi2::buffer<uint64_t>& io_ustllolmask_data )
{
    constexpr uint8_t HW555009_LOLDROP_MASK_BIT = 10;

    if (!i_loldrop_support)
    {
        io_ustllolmask_data.setBit<HW555009_LOLDROP_MASK_BIT>();
    }
}

///
/// @brief Function handling the chip_ec default for ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in] i_target the MC target of the OMI channel FIRs in question
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode setup_attr_omi_channel_fail_action( const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target )
{
    fapi2::ATTR_CHIP_EC_FEATURE_OMI_CH_FIRS_XSTOP_Type l_override = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_CH_FIRS_XSTOP,
                           mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target), l_override));

    if (l_override)
    {
        FAPI_TRY(mss::attr::set_omi_channel_fail_action(fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_XSTOP));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function handling the subchannel FIR settings after chiplet_scominit
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void override_subchannel_firs_after_chiplet_scominit( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg )
{
    // Write DSTLFIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_XSTOP:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_MASKED:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to masked per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_RECOVERABLE:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
            break;

        default:
            // By default just leave it local_checkstop
            FAPI_DBG("%s Leaving DSTLFIR subchannel FIRs as local_checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
            break;
    }
}

///
/// @brief Function handling the DSTLFIR subchannel FIR settings after omi_init
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void override_dstl_subchannel_firs_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg )
{
    // Write DSTLFIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_XSTOP:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
            .checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_MASKED:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to masked per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
            .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_RECOVERABLE:
            FAPI_DBG("%s Setting DSTLFIR subchannel FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
            .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
            break;

        default:
            // By default just leave it local_checkstop
            FAPI_DBG("%s Leaving DSTLFIR subchannel FIRs as local_checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_dstlfir_reg.local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
            .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>();
            break;
    }
}

///
/// @brief Function handling the USTLFIR subchannel FIR settings after omi_init
/// @param[in] i_target the MCC target of the USTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_ustlfir_reg the USTLFIR FIR register instance
///
void override_ustl_subchannel_firs_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::USTL_USTLFIR_RW>& io_mcc_ustlfir_reg )
{
    // Write USTLFIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_XSTOP:
            FAPI_DBG("%s Setting USTLFIR subchannel FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_ustlfir_reg.checkstop<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
            .checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_MASKED:
            FAPI_DBG("%s Setting USTLFIR subchannel FIRs to masked per attribute setting", mss::c_str(i_target));
            io_mcc_ustlfir_reg.masked<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
            .masked<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_RECOVERABLE:
            FAPI_DBG("%s Setting USTLFIR subchannel FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_mcc_ustlfir_reg.recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
            .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
            break;

        default:
            // By default just leave it local_checkstop
            FAPI_DBG("%s Leaving USTLFIR subchannel FIRs as local_checkstop per attribute setting", mss::c_str(i_target));
            io_mcc_ustlfir_reg.local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
            .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
            break;
    }
}

///
/// @brief Function handling the Cronus mode settings for DSTLFIR
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_hostboot_mode true if our platform is hostboot, false if cronus
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void dstl_cronus_settings( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
                           const bool i_hostboot_mode,
                           mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg )
{
    // Need to mask the SPECIAL_ATTENTION FIRs in Cronus mode because they get lit during memdiags and are causing lab issues
    if (!i_hostboot_mode)
    {
        FAPI_DBG("%s Setting DSTLFIR to Cronus mode settings", mss::c_str(i_target));
        io_mcc_dstlfir_reg.masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>()
        .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>();
    }
}

///
/// @brief Function handling the OMI FIR settings after chiplet_scominit
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mc_omi_fir_reg the OMI FIR register instance
///
void override_dl_fir_actions( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                              const uint8_t i_omi_fail_action,
                              mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg )
{
    // Write OMI_FIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_XSTOP:
            FAPI_DBG("%s Setting OMI_DL FATAL_ERROR FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_MASKED:
            FAPI_DBG("%s Setting OMI_DL FATAL_ERROR FIRs to masked per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.masked<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .masked<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
            break;

        case fapi2::ENUM_ATTR_OMI_CHANNEL_FAIL_ACTION_RECOVERABLE:
            FAPI_DBG("%s Setting OMI_DL FATAL_ERROR FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
            break;

        default:
            // By default just leave it recoverable (local_checkstop is not an option for these FIRs)
            FAPI_DBG("%s Leaving OMI_DL FATAL_ERROR FIRs as recoverable per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>();
            break;
    }
}

///
/// @brief Function handling the MC_OMI_FIR x4 degrade FIR settings
/// @param[in] i_target the OMIC target of the MC_OMI fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_X4_DEGRADE_ACTION
/// @param[in,out] io_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_x4_degrade_firs( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                               const uint8_t i_omi_fail_action,
                               mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg )
{
    // Write MC_OMI_FIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_MASKED:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIRs to masked per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.masked<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .masked<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_LOCAL_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIRs to local_checkstop per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>();
            break;

        default:
            // By default just leave them recoverable
            FAPI_DBG("%s Leaving MC_OMI_FIR degrade FIRs as recoverable per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>();
            break;
    }
}

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OMIC target of the MC_OMI fir
/// @param[in] i_omi_crc_debug value from ATTR_OMI_CRC_DEBUG
/// @param[in,out] io_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_omi_crc_firs( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                            const uint8_t i_omi_crc_debug,
                            mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg )
{
    // Write MC_OMI_FIR register per attr setting
    switch(i_omi_crc_debug)
    {
        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to checkstop per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_CRC_ERROR>()
            .checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_NACK>()
            .checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_NACK>();
            break;

        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_RECOVERABLE:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to recoverable per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_CRC_ERROR>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_NACK>()
            .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_NACK>();
            break;

        case fapi2::ENUM_ATTR_OMI_CRC_DEBUG_LOCAL_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR CRC FIRs to local_checkstop per attribute setting", mss::c_str(i_target));
            io_mc_omi_fir_reg.local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_CRC_ERROR>()
            .local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_CRC_ERROR>()
            .local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL0_NACK>()
            .local_checkstop<scomt::omic::MC_OMI_FIR_REG_DL1_NACK>();
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
/// @param[in] i_omi_mfg_screen_test value of MNFG_OMI_CRC_EDPL_SCREEN
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_crc_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                             const bool i_omi_crc_dd1_wkrnd,
                             const bool i_omi_mfg_screen_test,
                             mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg )
{
    // Set up MNFG OMI screen settings
    if (i_omi_mfg_screen_test)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR CRC FIR to masked for MFG test", mss::c_str(i_target));
        io_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL0_CRC_ERROR>()
        .remask<scomt::omic::MC_OMI_FIR_REG_DL1_CRC_ERROR>();
    }
    // Or unmask to recoverable if we're on DD2.0+
    else if (!i_omi_crc_dd1_wkrnd)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR CRC FIR to recoverable for DD2.0+", mss::c_str(i_target));
        io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_CRC_ERROR>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_CRC_ERROR>();
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
/// @param[in] i_omi_mfg_screen_test value of MNFG_OMI_CRC_EDPL_SCREEN
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_edpl_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                              const bool i_omi_edpl_dd1_wkrnd,
                              const bool i_omi_mfg_screen_test,
                              mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg )
{
    // Set up MNFG OMI screen settings
    if (i_omi_mfg_screen_test)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR EDPL FIR to masked for MFG test", mss::c_str(i_target));
        io_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL>()
        .remask<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL>();
    }
    // Or unmask to recoverable if we're on DD2.0+
    else if (!i_omi_edpl_dd1_wkrnd)
    {
        FAPI_DBG("%s Setting MC_OMI_FIR EDPL FIR to recoverable for DD2.0+", mss::c_str(i_target));
        io_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL>();
    }
    // Or leave it as-is (masked or lab override setting) for DD1.0
    else
    {
        FAPI_DBG("%s Leaving MC_OMI_FIR EDPL FIR as-is for DD1.0", mss::c_str(i_target));
    }
}

} // namespace fir
} // namespace workarounds
} // namespace mss
