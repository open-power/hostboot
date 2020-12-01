/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/fir/p10_fir.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#ifndef _P10_FIR_H_
#define _P10_FIR_H_

#include <fapi2.H>
#include <p10_scom_mcc.H>
#include <p10_scom_omi.H>
#include <lib/fir/p10_fir_traits.H>
#include <lib/mc/host_mc_traits.H>
#include <lib/workarounds/p10_fir_workarounds.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/mss_p10_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

namespace scomt
{
namespace mcc
{

// fld_fixes for USTLFAILMASK
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_0             = 0;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_1             = 1;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_2             = 2;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_3             = 3;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_4             = 4;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_5             = 5;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_6             = 6;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_7             = 7;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_8             = 8;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_9             = 9;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_10            = 10;
static constexpr uint8_t USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_11            = 11;

static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_16          = 16;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_17          = 17;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_18          = 18;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_19          = 19;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_20          = 20;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_21          = 21;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_22          = 22;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_23          = 23;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_24          = 24;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_25          = 25;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_26          = 26;
static constexpr uint8_t USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_27          = 27;

static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_32          = 32;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_33          = 33;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_34          = 34;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_35          = 35;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_36          = 36;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_37          = 37;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_38          = 38;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_39          = 39;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_40          = 40;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_41          = 41;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_42          = 42;
static constexpr uint8_t USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_43          = 43;

static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_48      = 48;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_49      = 49;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_50      = 50;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_51      = 51;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_52      = 52;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_53      = 53;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_54      = 54;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_55      = 55;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_56      = 56;
static constexpr uint8_t USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_57      = 57;

// fld_fixes for DSTLFIR
static constexpr uint8_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_SCOM_PER              = 24;
static constexpr uint8_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_KEY_LOCKED            = 25;
static constexpr uint8_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_ADDR_PIPE_PER         = 26;
static constexpr uint8_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_CL_PERR_ON_VALID_TAG  = 27;
static constexpr uint8_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_USTL_DMX_PERR         = 28;
static constexpr uint8_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_SCOM_PER              = 29;
static constexpr uint8_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_KEY_LOCKED            = 30;
static constexpr uint8_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_ADDR_ENCRYPT_PERR     = 31;
static constexpr uint8_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_DATA_ENCRYPT_PERR     = 32;

} // mcc
} // scomt

namespace mss
{
namespace unmask
{

///
/// @brief Helper function to check which OMI subchannels are configured
/// @tparam T The TARGET_TYPE of i_target
/// @param[in] i_target MCC target
/// @param[out] o_subchannel_a_config true if subchannel A OMI target is configured
/// @param[out] o_subchannel_b_config true if subchannel B OMI target is configured
///
template< fapi2::TargetType T >
void subchannel_config(const fapi2::Target<T>& i_target,
                       bool& o_subchannel_a_config,
                       bool& o_subchannel_b_config)
{
    o_subchannel_a_config = false;
    o_subchannel_b_config = false;

    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        const auto l_omi_pos = mss::relative_pos<fapi2::TARGET_TYPE_OMIC>(l_omi);

        if (l_omi_pos == 0)
        {
            o_subchannel_a_config = true;
        }
        else if (l_omi_pos == 1)
        {
            o_subchannel_b_config = true;
        }
    }
}

///
/// @brief Helper function to perform p10 MCC DSTLFIR unmasks
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p10_omi_init_dstlfir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;
    const bool l_hostboot_mode = fapi2::is_platform<fapi2::PLAT_HOSTBOOT>();
    fapi2::ATTR_OMI_CHANNEL_FAIL_ACTION_Type l_omi_fail_action = 0;
    bool l_subchannel_a_config = false;
    bool l_subchannel_b_config = false;

    mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW> l_p10_mcc_dstlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target),
             scomt::mcc::DSTL_DSTLFIR_RW);

    FAPI_TRY(mss::attr::get_omi_channel_fail_action(l_omi_fail_action));

    l_p10_mcc_dstlfir_reg.local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>()
    .host_attention<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>()
    .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>()
    .host_attention<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>()
    .checkstop<scomt::mcc::DSTL_DSTLFIR_DECRYPT_ERR_INFO_SCOM_PER>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_DECRYPT_ERR_INFO_KEY_LOCKED>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_DECRYPT_ERR_INFO_ADDR_PIPE_PER>()
    .checkstop<scomt::mcc::DSTL_DSTLFIR_DECRYPT_ERR_INFO_CL_PERR_ON_VALID_TAG>()
    .checkstop<scomt::mcc::DSTL_DSTLFIR_DECRYPT_ERR_INFO_USTL_DMX_PERR>()
    .checkstop<scomt::mcc::DSTL_DSTLFIR_ENCRYPT_ERR_INFO_SCOM_PER>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_ENCRYPT_ERR_INFO_KEY_LOCKED>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_ENCRYPT_ERR_INFO_ADDR_ENCRYPT_PERR>()
    .recoverable_error<scomt::mcc::DSTL_DSTLFIR_ENCRYPT_ERR_INFO_DATA_ENCRYPT_PERR>();

    // Need to mask the SPECIAL_ATTENTION FIRs in Cronus mode because they get lit during memdiags and are causing lab issues
    mss::workarounds::fir::dstl_cronus_settings(i_target, l_hostboot_mode, l_p10_mcc_dstlfir_reg);

    // Set up subchannel FIR attribute overrides
    mss::workarounds::fir::override_dstl_subchannel_firs_after_omi_init(i_target, l_omi_fail_action, l_p10_mcc_dstlfir_reg);

    // Re-mask any subchannel FIRs that are on non-configured OMI channels
    subchannel_config(i_target, l_subchannel_a_config, l_subchannel_b_config);

    if (!l_subchannel_a_config)
    {
        l_p10_mcc_dstlfir_reg.remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>();
    }

    if (!l_subchannel_b_config)
    {
        l_p10_mcc_dstlfir_reg.remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>()
        .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>();
    }

    FAPI_TRY(l_p10_mcc_dstlfir_reg.write(), "Error setting up fir reg 0x%016x for target %s",
             scomt::mcc::DSTL_DSTLFIR_RW,
             mss::c_str(i_target));

    using MCCT = mss::mccTraits<mss::proc_type::PROC_P10>;

    // Set bits of DSTLCFG2 for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, MCCT::DSTL_CFG2, l_reg_data));

    l_reg_data.clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_COUNTER_ERR>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_COUNTER_ERR>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE>()
    .setBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT>()
    .setBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LOCAL_PARITY>()
    .clearBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LOCAL_PARITY>();

    FAPI_TRY(fapi2::putScom(i_target, MCCT::DSTL_CFG2, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Helper function to perform p10 MCC USTLFIR unmasks
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p10_omi_init_ustlfir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ATTR_OMI_CHANNEL_FAIL_ACTION_Type l_omi_fail_action = 0;
    bool l_subchannel_a_config = false;
    bool l_subchannel_b_config = false;

    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<scomt::mcc::USTL_USTLFIR_RW> l_p10_mcc_ustlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target),
             scomt::mcc::USTL_USTLFIR_RW);

    FAPI_TRY(mss::attr::get_omi_channel_fail_action(l_omi_fail_action));

    // Perform all USTLFIR unmasks per RAS unmask spec
    l_p10_mcc_ustlfir_reg.local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_CE>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_UE>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_OVERRUN>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_TAG_PARITY_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_CL_POP_PARITY_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WDF_CMT_PARITY_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_WRT_BUFFER_CE>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_WRT_BUFFER_UE>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_WRT_DATA_SYNDROME_NE0>()
    .checkstop<scomt::mcc::USTL_USTLFIR_WRT_BUFF_ERR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>()
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
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
    .checkstop<scomt::mcc::USTL_USTLFIR_FATAL_REG_PARITY_ERROR>()
    .recoverable_error<scomt::mcc::USTL_USTLFIR_RECOV_REG_PARITY_ERROR>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
    .local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>()
    .checkstop<scomt::mcc::USTL_USTLFIR_SPARE_61>(); // USTLFIR_MIRROR_CHANFAIL_RELATED_PARITY_ERROR

    // Set up subchannel FIR attribute overrides
    mss::workarounds::fir::override_ustl_subchannel_firs_after_omi_init(i_target, l_omi_fail_action, l_p10_mcc_ustlfir_reg);

    // Re-mask any subchannel FIRs that are on non-configured OMI channels
    subchannel_config(i_target, l_subchannel_a_config, l_subchannel_b_config);

    if (!l_subchannel_a_config)
    {
        l_p10_mcc_ustlfir_reg.remask<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>();
    }

    if (!l_subchannel_b_config)
    {
        l_p10_mcc_ustlfir_reg.remask<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
        .remask<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>();
    }

    FAPI_TRY(l_p10_mcc_ustlfir_reg.write(), "Error setting up fir reg 0x%016x for target %s",
             scomt::mcc::USTL_USTLFIR_RW,
             mss::c_str(i_target));

    using MCCT = mss::mccTraits<mss::proc_type::PROC_P10>;

    // Set bits of USTLFIRMASK for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, MCCT::USTL_FAILMASK, l_reg_data));

    l_reg_data.clearBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_0>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_1>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_2>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_3>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_4>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_5>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_6>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_7>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_8>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_9>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_10>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_RECOVER_ENABLE_MASK_11>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_16>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_17>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_18>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_19>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_20>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_21>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_22>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_23>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_24>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_25>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_26>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_27>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_32>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_33>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_34>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_35>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_36>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_37>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_38>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_39>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_40>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_41>()
    .setBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_42>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_43>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_48>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_49>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_50>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_51>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_52>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_53>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_54>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_55>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_56>()
    .clearBit<scomt::mcc::USTL_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_57>();

    FAPI_TRY(fapi2::putScom(i_target, MCCT::USTL_FAILMASK, l_reg_data));

    // Configures the USTLCNFG register
    // NOTE: These are outside of standard FIR procedure and are being configured due to p10 HW bugs
    FAPI_TRY(fapi2::getScom(i_target, scomt::mcc::USTL_USTLCFG, l_reg_data));

    // TODO:ZEN695 USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE for p10 DD2

    l_reg_data.setBit<scomt::mcc::USTL_USTLCFG_DATE_ERROR_RETRY_ENABLE>()
    .insertFromRight<scomt::mcc::USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE, scomt::mcc::USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE_LEN>
    (0b11)
    .setBit<scomt::mcc::USTL_USTLCFG_DL_WIDTH_X4_LOL_ENABLE>()
    .setBit<scomt::mcc::USTL_USTLCFG_DL_WIDTH_X2_LOL_ENABLE>()
    .insertFromRight<scomt::mcc::USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE, scomt::mcc::USTL_USTLCFG_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN>
    (0x7f)
    .insertFromRight<scomt::mcc::USTL_USTLCFG_LOL_CAPTURE_CONFIG, scomt::mcc::USTL_USTLCFG_LOL_CAPTURE_CONFIG_LEN>(0b11)
    .setBit<scomt::mcc::USTL_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>()
    .setBit<scomt::mcc::USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>()
    .insertFromRight<scomt::mcc::USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT, scomt::mcc::USTL_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN>
    (0b111);

    // TODO:ZEN690 Update after_p10_omi_init_ustlfir_helper for DD2
    // Set new DD2 new USTLCFG bit: USTLCFG_wrstuck_mitigation_en_p10d20 -> 1

    FAPI_TRY(fapi2::putScom(i_target, scomt::mcc::USTL_USTLCFG, l_reg_data));

    // Configures the USTLLOLMASK register
    // NOTE: These are outside of standard FIR procedure and are being configured due to p10 HW bugs
    FAPI_TRY(fapi2::getScom(i_target, scomt::mcc::USTL_USTLLOLMASK, l_reg_data));

    l_reg_data.insertFromRight<scomt::mcc::USTL_USTLLOLMASK_RECOVER_ENABLE_MASK, scomt::mcc::USTL_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>
    (0x22D860);

    FAPI_TRY(fapi2::putScom(i_target, scomt::mcc::USTL_USTLLOLMASK, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Clear error bits P10_MC_DLn_ERROR_MASK registers n[0:1] since they are now "active"
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode setup_reg_dl_after_omi_init_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(scomt::omi::GET_ERROR_MASK(i_target, l_reg_data));

    scomt::omi::CLEAR_ERROR_MASK_34(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_33(l_reg_data);

    FAPI_TRY(scomt::omi::PUT_ERROR_MASK(i_target, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up error bits in ERROR_MASK register, after chiplet_scominit
/// @param[in] i_target OMI target to find targets to initialize
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode setup_reg_dl_after_chiplet_scominit_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(scomt::omi::GET_ERROR_MASK(i_target, l_reg_data));

    scomt::omi::SET_ERROR_MASK_47(l_reg_data);
    scomt::omi::SET_ERROR_MASK_46(l_reg_data);
    scomt::omi::SET_ERROR_MASK_45(l_reg_data);
    scomt::omi::SET_ERROR_MASK_44(l_reg_data);
    scomt::omi::SET_ERROR_MASK_43(l_reg_data);
    scomt::omi::SET_ERROR_MASK_42(l_reg_data);
    scomt::omi::SET_ERROR_MASK_41(l_reg_data);
    scomt::omi::SET_ERROR_MASK_40(l_reg_data);
    scomt::omi::SET_ERROR_MASK_38(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_37(l_reg_data);
    scomt::omi::SET_ERROR_MASK_36(l_reg_data);
    scomt::omi::SET_ERROR_MASK_34(l_reg_data);
    scomt::omi::SET_ERROR_MASK_33(l_reg_data);
    scomt::omi::SET_ERROR_MASK_32(l_reg_data);
    scomt::omi::SET_ERROR_MASK_18(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_17(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_16(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_15(l_reg_data);
    scomt::omi::CLEAR_ERROR_MASK_14(l_reg_data);
    scomt::omi::SET_ERROR_MASK_05(l_reg_data);

    FAPI_TRY(scomt::omi::PUT_ERROR_MASK(i_target, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask FIR registers after p10_chiplet_scominit procedure
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS iff success
///
inline fapi2::ReturnCode after_p10_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ATTR_OMI_CHANNEL_FAIL_ACTION_Type l_omi_fail_action = 0;
    fapi2::ATTR_OMI_X4_DEGRADE_ACTION_Type l_degrade_fail_action = 0;
    fapi2::ATTR_OMI_CRC_DEBUG_Type l_omi_crc_debug = 0;
    bool l_subchannel_a_config = false;
    bool l_subchannel_b_config = false;

    mss::fir::reg<scomt::mc::MBA_SCOMFIR_MISCFIRQ_RW> l_mc_miscfir_reg(i_target, l_rc);

    FAPI_TRY(l_rc, "unable to create fir::reg for MBA_SCOMFIR_MISCFIRQ_RW 0x%08X", scomt::mc::MBA_SCOMFIR_MISCFIRQ_RW);

    FAPI_TRY(mss::attr::get_omi_channel_fail_action(l_omi_fail_action));
    FAPI_TRY(mss::attr::get_omi_x4_degrade_action(l_degrade_fail_action));
    FAPI_TRY(mss::attr::get_omi_crc_debug(l_omi_crc_debug));

    // Set up MISCFIRQ
    l_rc = l_mc_miscfir_reg.recoverable_error<scomt::mc::MBA_SCOMFIR_MISCFIRQ_SCOM_RECOVERABLE_REG_PE>()
           .recoverable_error<scomt::mc::MBA_SCOMFIR_MISCFIRQ_MCEBUSEN_REGS_PE>()
           .write();
    FAPI_TRY(l_rc, "Error setting up fir reg 0x%016x for target %s",
             scomt::mc::MBA_SCOMFIR_MISCFIRQ_RW,
             mss::c_str(i_target));

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        // Create register and check success
        mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW> l_mc_omi_fir_reg(l_omic, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for MC_OMI_FIR_REG_RW 0x%08X", scomt::omic::MC_OMI_FIR_REG_RW);

        l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_DATA_UE>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_TIMEOUT>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_DATA_UE>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_TIMEOUT>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();

        // Set up OMI CRC debug mode if requested
        mss::workarounds::fir::override_omi_crc_firs(l_omic, l_omi_crc_debug, l_mc_omi_fir_reg);

        // Set up x4 degrade FIR attribute overrides
        mss::workarounds::fir::override_x4_degrade_firs(l_omic, l_degrade_fail_action, l_mc_omi_fir_reg);

        // Re-mask any subchannel FIRs that are on non-configured OMI channels
        subchannel_config(l_omic, l_subchannel_a_config, l_subchannel_b_config);

        if (!l_subchannel_a_config)
        {
            FAPI_INF("No subchannel A, remasking FIRs");
            l_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL0_DATA_UE>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL0_TIMEOUT>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
        }

        if (!l_subchannel_b_config)
        {
            FAPI_INF("No subchannel A, remasking FIRs");
            l_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL1_DATA_UE>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL1_TIMEOUT>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
            .remask<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
        }

        // Write MC_OMI_FIR register
        FAPI_TRY(l_mc_omi_fir_reg.write());

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper(l_omi));
        }
    }

    for (const auto& l_mcc : mss::find_targets<fapi2::TARGET_TYPE_MCC>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // Create FIR reg
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW> l_mcc_dstlfir_reg(l_mcc, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for DSTL_DSTLFIR_RW 0x%08X", scomt::mcc::DSTL_DSTLFIR_RW);

        // Write DSTLFIR register per axone spec
        l_mcc_dstlfir_reg.checkstop<scomt::mcc::DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR>()
        .checkstop<scomt::mcc::DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO>()
        .recoverable_error<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>()
        .checkstop<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
        .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();

        // Re-mask any subchannel FIRs that are on non-configured OMI channels
        subchannel_config(l_mcc, l_subchannel_a_config, l_subchannel_b_config);

        if (!l_subchannel_a_config)
        {
            l_mcc_dstlfir_reg.remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>();
        }

        if (!l_subchannel_b_config)
        {
            l_mcc_dstlfir_reg.remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .remask<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
        }

        // Set up subchannel FIR attribute overrides
        mss::workarounds::fir::override_subchannel_firs_after_chiplet_scominit(l_mcc, l_omi_fail_action, l_mcc_dstlfir_reg);

        FAPI_TRY(l_mcc_dstlfir_reg.write(), "Error setting up fir reg 0x%016x for target %s",
                 scomt::mcc::DSTL_DSTLFIR_RW,
                 mss::c_str(i_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Helper function to perform p10 OMI FIR unmasks
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p10_omi_init_omi_fir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_subchannel_a_config = false;
    bool l_subchannel_b_config = false;

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW> l_mc_omi_fir_reg(l_omic, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for MC_OMI_FIR_REG_RW 0x%08X", scomt::omic::MC_OMI_FIR_REG_RW);

        l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FLIT_CE>()
        .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FLIT_CE>();

        // Re-mask any subchannel FIRs that are on non-configured OMI channels
        subchannel_config(l_omic, l_subchannel_a_config, l_subchannel_b_config);

        if (!l_subchannel_a_config)
        {
            l_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL0_FLIT_CE>();
        }

        if (!l_subchannel_b_config)
        {
            l_mc_omi_fir_reg.remask<scomt::omic::MC_OMI_FIR_REG_DL1_FLIT_CE>();
        }

        // Write MC_OMI_FIR registers now that they've been set up in the loop above
        FAPI_TRY(l_mc_omi_fir_reg.write());

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            // Clear ERROR_MASK on REGm_DLn 0:2 registers because they are now considered valid
            FAPI_TRY(setup_reg_dl_after_omi_init_helper(l_omi));
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns
#endif
