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
#include <p10_scom_mcc_2.H>
#include <p10_scom_mcc_4.H>
#include <p10_scom_mcc_b.H>
#include <p10_scom_mcc_d.H>
#include <p10_scom_omi_7.H>
#include <lib/fir/p10_fir_traits.H>
#include <lib/mc/host_mc_traits.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

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

} // mcc
} // scomt

namespace mss
{
namespace unmask
{

///
/// @brief Helper function to perform p10 MCC DSTLFIR unmasks
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p10_omi_init_dstlfir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_setup_dstlfir_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW> l_p10_mcc_dstlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target),
             scomt::mcc::DSTL_DSTLFIR_RW);

    l_setup_dstlfir_rc = l_p10_mcc_dstlfir_reg
                         .template local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
                         .template recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>()
                         .template attention<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>()
                         .template local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>()
                         .template recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>()
                         .template attention<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>()
                         .template recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>()
                         .template recoverable_error<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>()
                         .write();

    FAPI_TRY(l_setup_dstlfir_rc, "Error setting up fir reg 0x%016x for target %s",
             scomt::mcc::DSTL_DSTLFIR_RW,
             mss::c_str(i_target));

    using MCCT = mss::mccTraits<mss::proc_type::PROC_P10>;

    // Set bits of DSTLCFG2 for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, scomt::mcc::DSTL_DSTLCFG2, l_reg_data));

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
    .setBit<scomt::mcc::DSTL_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>();

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
    fapi2::ReturnCode l_setup_ustlfir_rc = fapi2::FAPI2_RC_SUCCESS;

    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<scomt::mcc::USTL_USTLFIR_RW> l_p10_mcc_ustlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target),
             scomt::mcc::USTL_USTLFIR_RW);

    // Perform all USTLFIR unmasks per RAS unmask spec
    l_setup_ustlfir_rc = l_p10_mcc_ustlfir_reg
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_UNEXP_DATA_ERR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_UNEXP_DATA_ERR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_CE>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_UE>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_BUFFER_OVERRUN>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_TAG_PARITY_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_SCOM_SEQ_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WDF_CMT_PARITY_ERROR>() /* P9A uses WDF_CMD_PARITY */
                         .template checkstop<scomt::mcc::USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_WRT_BUFFER_CE>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_WRT_BUFFER_UE>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WRT_SCOM_SEQ_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_LOL_DROP_RECOVER>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_LOL_DROP_RECOVER>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_CMD_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_CMD_ERROR>()
                         .template checkstop<scomt::mcc::USTL_USTLFIR_FATAL_REG_PARITY_ERROR>()
                         .template recoverable_error<scomt::mcc::USTL_USTLFIR_RECOV_REG_PARITY_ERROR>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
                         .template local_checkstop<scomt::mcc::USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO>()
                         .write();

    FAPI_TRY(l_setup_ustlfir_rc, "Error setting up fir reg 0x%016x for target %s",
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

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        // Create register and check success
        mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW> l_mc_omi_fir_reg(l_omic, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for MC_OMI_FIR_REG_RW 0x%08X", scomt::omic::MC_OMI_FIR_REG_RW);

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            // Note that there are child-target-specific FIR bits in these regs, so we need to check
            // what's configured and unmask the corresponding group of FIRs in the right reg
            // OMI relative pos ==> DL0/1
            uint8_t l_omi_pos = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_OMI_DL_GROUP_POS, l_omi, l_omi_pos) );

            switch(l_omi_pos)
            {
                case 0:
                    l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_DATA_UE>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_TIMEOUT>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
                    break;

                case 1:
                    l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_DATA_UE>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_TIMEOUT>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
                    .recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_OMI_POSITION().
                                set_POSITION(l_omi_pos).
                                set_OMI_TARGET(l_omi),
                                "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                    break;
            }

            FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper(l_omi));
        }

        // Write MC_OMI_FIR register
        FAPI_TRY(l_mc_omi_fir_reg.write());
    }

    for (const auto& l_mcc : mss::find_targets<fapi2::TARGET_TYPE_MCC>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::ReturnCode l_setup_dstlfir_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW> l_mcc_dstlfir_reg(l_mcc, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for DSTL_DSTLFIR_RW 0x%08X", scomt::mcc::DSTL_DSTLFIR_RW);

        // Write DSTLFIR register per axone spec, TK, potential changes in P10
        l_setup_dstlfir_rc = l_mcc_dstlfir_reg
                             .recoverable_error<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>()
                             .checkstop<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
                             .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
                             .write();

        FAPI_TRY(l_setup_dstlfir_rc, "Error setting up fir reg 0x%016x for target %s",
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

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW> l_mc_omi_fir_reg(l_omic, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for MC_OMI_FIR_REG_RW 0x%08X", scomt::omic::MC_OMI_FIR_REG_RW);

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            // Note that there are child-target-specific FIR bits in these regs, so we need to check
            // what's configured and unmask the corresponding group of FIRs in the right reg
            // OMI relative pos ==> DL0/1
            uint8_t l_omi_pos = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_OMI_DL_GROUP_POS, l_omi, l_omi_pos) );

            switch(l_omi_pos)
            {
                case 0:
                    l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL0_FLIT_CE>();
                    break;

                case 1:
                    l_mc_omi_fir_reg.recoverable_error<scomt::omic::MC_OMI_FIR_REG_DL1_FLIT_CE>();
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_OMI_POSITION().
                                set_POSITION(l_omi_pos).
                                set_OMI_TARGET(l_omi),
                                "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                    break;
            }

            // Clear ERROR_MASK on REGm_DLn 0:2 registers because they are now considered valid
            FAPI_TRY(setup_reg_dl_after_omi_init_helper(l_omi));
        }

        // Write MC_OMI_FIR registers now that they've been set up in the loop above
        FAPI_TRY(l_mc_omi_fir_reg.write());
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns
#endif
