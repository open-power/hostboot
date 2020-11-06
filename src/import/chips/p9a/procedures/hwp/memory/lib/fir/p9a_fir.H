/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/fir/p9a_fir.H $ */
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

#ifndef _P9A_FIR_H_
#define _P9A_FIR_H_

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <lib/fir/p9a_fir_traits.H>
#include <lib/mc/host_mc_traits.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

namespace unmask
{

///
/// @brief Helper function to perform p9a MCC DSTLFIR unmasks
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p9a_omi_init_dstlfir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<P9A_MCC_DSTLFIR> l_p9a_mcc_dstlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target), P9A_MCC_DSTLFIR);

    FAPI_TRY(l_p9a_mcc_dstlfir_reg.template local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP>()
             .template recoverable_error<P9A_MCC_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION>()
             .template attention<P9A_MCC_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION>()
             .template local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP>()
             .template recoverable_error<P9A_MCC_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION>()
             .template attention<P9A_MCC_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION>()
             .template recoverable_error<P9A_MCC_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR>()
             .template recoverable_error<P9A_MCC_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR>()
             .write()); // close FAPI_TRY

    using MCCT = mss::mccTraits<mss::proc_type::AXONE>;

    // Set bits of DSTLCFG for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, MCCT::DSTL_CFG, l_reg_data));

    l_reg_data.setBit<P9A_MCC_DSTLCFG_ENABLE_HOST_ATTN>();

    FAPI_TRY(fapi2::putScom(i_target, MCCT::DSTL_CFG, l_reg_data));

    // Set bits of DSTLCFG2 for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, MCCT::DSTL_CFG2, l_reg_data));

    l_reg_data.clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_LINK_DOWN>()
    .clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_LINK_DOWN>()
    .clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_CH_TIMEOUT>()
    .clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_CH_TIMEOUT>()
    .clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_TLX_XSTOP>()
    .clearBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_TLX_XSTOP>()
    .clearBit<P9A_MCC_DSTLCFG2_SUBCH_A_FAIL_DIS_COUNTER_ERR>()
    .clearBit<P9A_MCC_DSTLCFG2_SUBCH_B_FAIL_DIS_COUNTER_ERR>()
    .clearBit<P9A_MCC_DSTLCFG2_SUBCH_A_FAIL_DIS_TLXVC3_OVERUSE>()
    .clearBit<P9A_MCC_DSTLCFG2_SUBCH_B_FAIL_DIS_TLXVC3_OVERUSE>()
    .setBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_A_FAIL_DIS_DSTL_TIMEOUT>()
    .setBit<P9A_MCC_DSTLCFG2_CFG_SUBCH_B_FAIL_DIS_DSTL_TIMEOUT>();

    FAPI_TRY(fapi2::putScom(i_target, MCCT::DSTL_CFG2, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Helper function to perform p9a MCC USTLFIR unmasks
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p9a_omi_init_ustlfir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<P9A_MCC_USTLFIR> l_p9a_mcc_ustlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target), P9A_MCC_USTLFIR);

    // Perform all USTLFIR unmasks per RAS unmask spec
    FAPI_TRY(l_p9a_mcc_ustlfir_reg.template local_checkstop<P9A_MCC_USTLFIR_CHANA_UNEXP_DATA_ERR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_UNEXP_DATA_ERR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR>()
             .template recoverable_error<P9A_MCC_USTLFIR_WDF_BUFFER_CE>()
             .template recoverable_error<P9A_MCC_USTLFIR_WDF_BUFFER_UE>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_BUFFER_OVERRUN>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_TAG_PARITY_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_SCOM_SEQ_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_PWCTL_SEQ_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_MISC_REG_PARITY_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_MCA_ASYNC_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WDF_CMD_PARITY_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_READ_MBS_RDBUF_OVF_ERROR>()
             .template recoverable_error<P9A_MCC_USTLFIR_WRT_BUFFER_CE>()
             .template recoverable_error<P9A_MCC_USTLFIR_WRT_BUFFER_UE>()
             .template checkstop<P9A_MCC_USTLFIR_WRT_SCOM_SEQ_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_WRT_MISC_REG_PARITY_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANA_FAIL_RESP_RECOVER>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANB_FAIL_RESP_RECOVER>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANA_LOL_DROP_RECOVER>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANB_LOL_DROP_RECOVER>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_FLIT_PARITY_ERROR_FIX>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_FLIT_PARITY_ERROR_FIX>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_FATAL_PARITY_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_FATAL_PARITY_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_BAD_RESP_LOG_VAL>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_BAD_RESP_LOG_VAL>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANA_MMIO_IN_LOL_MODE>()
             .template recoverable_error<P9A_MCC_USTLFIR_CHANB_MMIO_IN_LOL_MODE>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_EXCESS_DATA_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_EXCESS_DATA_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_INVALID_CMD_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_INVALID_CMD_ERROR>()
             .template checkstop<P9A_MCC_USTLFIR_FATAL_REG_PARITY_ERROR>()
             .template recoverable_error<P9A_MCC_USTLFIR_RECOV_REG_PARITY_ERROR>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANA_INVALID_DL_DP_COMBO>()
             .template local_checkstop<P9A_MCC_USTLFIR_CHANB_INVALID_DL_DP_COMBO>()
             .write()); // close FAPI_TRY

    using MCCT = mss::mccTraits<mss::proc_type::AXONE>;

    // Set bits of USTLFIRMASK for specific channel fail enables/disables
    // NOTE: These are outside of standard FIR procedure and handle enabling a full OMI channel checkstop
    FAPI_TRY(fapi2::getScom(i_target, MCCT::USTL_FAILMASK, l_reg_data));

    l_reg_data.clearBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_0>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_1>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_2>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_3>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_4>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_5>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_6>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_7>()
    .setBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_8>()
    .clearBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_9>()
    .clearBit<P9A_MCC_USTLFAILMASK_RECOVER_ENABLE_MASK_10>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_16>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_17>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_18>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_19>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_20>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_21>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_22>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_23>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_24>()
    .setBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_25>()
    .setBit<P9A_MCC_USTLFAILMASK_CHECKSTOP_ENABLE_MASK_26>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_32>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_33>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_34>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_35>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_36>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_37>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_38>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_39>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_40>()
    .setBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_41>()
    .setBit<P9A_MCC_USTLFAILMASK_CHAN_FAIL_ENABLE_MASK_42>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_48>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_49>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_50>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_51>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_52>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_53>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_54>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_55>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_56>()
    .clearBit<P9A_MCC_USTLFAILMASK_CHANNEL_FAIL_TYPE_DISABLE_57>();

    FAPI_TRY(fapi2::putScom(i_target, MCCT::USTL_FAILMASK, l_reg_data));

    // Configures the USTLCNFG register
    // NOTE: These are outside of standard FIR procedure and are being configured due to HW bugs
    FAPI_TRY(fapi2::getScom(i_target, P9A_MCC_USTLCFG, l_reg_data));

    l_reg_data.setBit<P9A_MCC_USTLCFG_DATE_ERROR_RETRY_ENABLE>()
    .insertFromRight<P9A_MCC_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE, P9A_MCC_USTLCFG_OPENCAPI_ERROR_LOG_ENABLE_LEN>(0x7f)
    .insertFromRight<P9A_MCC_USTLCFG_LOL_CAPTURE_CONFIG, P9A_MCC_USTLCFG_LOL_CAPTURE_CONFIG_LEN>(0b11)
    .setBit<P9A_MCC_USTLCFG_RETRY_LOL_HOLDOFF_ENABLE>()
    .setBit<P9A_MCC_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_ENABLE>()
    .insertFromRight<P9A_MCC_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT, P9A_MCC_USTLCFG_RETRY_LOL_HOLDOFF_MAX_CMD_COUNT_LEN>
    (0b111);

    FAPI_TRY(fapi2::putScom(i_target, P9A_MCC_USTLCFG, l_reg_data));

    // Configures the USTLLOLMASK register
    // NOTE: These are outside of standard FIR procedure and are being configured due to HW bugs
    FAPI_TRY(fapi2::getScom(i_target, P9A_MCC_USTLLOLMASK, l_reg_data));

    l_reg_data.insertFromRight<P9A_MCC_USTLLOLMASK_RECOVER_ENABLE_MASK, P9A_MCC_USTLLOLMASK_RECOVER_ENABLE_MASK_LEN>
    (0x8B61);

    FAPI_TRY(fapi2::putScom(i_target, P9A_MCC_USTLLOLMASK, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Clear error bits P9A_MC_REGm_DLn_ERROR_MASK registers m[0:2], n[0:2] since they are now "active"
/// @tparam R the REG_DL register we want to write to
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
template<uint64_t R>
inline fapi2::ReturnCode setup_reg_dl_after_omi_init_helper(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(fapi2::getScom(i_target, R, l_reg_data));
    l_reg_data.clearBit<P9A_MC_REG2_DL2_ERROR_MASK_34>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_33>();
    FAPI_TRY(fapi2::putScom(i_target, R, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up error bits P9A_MC_REGm_DLn_ERROR_MASK registers m[0:2], n[0:2] after chiplet_scominit
/// @tparam R the REG_DL register we want to write to
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
template<uint64_t R>
inline fapi2::ReturnCode setup_reg_dl_after_chiplet_scominit_helper(const fapi2::Target<fapi2::TARGET_TYPE_MC>&
        i_target)
{
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(fapi2::getScom(i_target, R, l_reg_data));
    l_reg_data.setBit<P9A_MC_REG2_DL2_ERROR_MASK_47>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_46>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_45>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_44>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_43>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_42>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_41>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_40>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_38>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_37>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_36>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_34>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_33>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_32>()
    .setBit<P9A_MC_REG2_DL2_ERROR_MASK_18>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_17>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_16>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_15>()
    .clearBit<P9A_MC_REG2_DL2_ERROR_MASK_14>();
    FAPI_TRY(fapi2::putScom(i_target, R, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask FIR registers after p9_chiplet_scominit procedure on Axone
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS iff success
///
inline fapi2::ReturnCode after_p9a_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    using MCT = mss::mcTraits<mss::proc_type::AXONE>;

    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc4 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc5 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success
    mss::fir::reg<P9A_MC_LOCAL_FIR> l_mc_local_fir_reg(i_target, l_rc1);
    mss::fir::reg<P9A_MC_MCBISTFIRQ> l_mc_mcbistfirq_reg(i_target, l_rc2);
    mss::fir::reg<P9A_MC_REG0_OMI_FIR> l_mc_reg0_omi_fir_reg(i_target, l_rc3);
    mss::fir::reg<P9A_MC_REG1_OMI_FIR> l_mc_reg1_omi_fir_reg(i_target, l_rc4);
    mss::fir::reg<P9A_MC_REG2_OMI_FIR> l_mc_reg2_omi_fir_reg(i_target, l_rc5);

    FAPI_TRY(l_rc1, "unable to create fir::reg for P9A_MC_LOCAL_FIR 0x%08X", P9A_MC_LOCAL_FIR);
    FAPI_TRY(l_rc2, "unable to create fir::reg for P9A_MC_MCBISTFIRQ 0x%08X", P9A_MC_MCBISTFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for P9A_MC_REG0_OMI_FIR 0x%08X", P9A_MC_REG0_OMI_FIR);
    FAPI_TRY(l_rc4, "unable to create fir::reg for P9A_MC_REG1_OMI_FIR 0x%08X", P9A_MC_REG1_OMI_FIR);
    FAPI_TRY(l_rc5, "unable to create fir::reg for P9A_MC_REG2_OMI_FIR 0x%08X", P9A_MC_REG2_OMI_FIR);

    // Write LOCAL_FIR register per Axone unmask spec
    FAPI_TRY(l_mc_local_fir_reg.recoverable_error<P9A_MC_LOCAL_FIR_IN0>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN1>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN2>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN3>()
             .write());

    // Write MCBISTFIRQ register per Axone unmask spec
    FAPI_TRY(l_mc_mcbistfirq_reg.recoverable_error<P9A_MC_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .write());

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            // Set up MC_OMI_FIR register per Axone unmask spec
            // Note that there are child-target-specific FIR bits in these regs, so we need to check
            // what's configured and unmask the corresponding group of FIRs in the right reg
            // OMIC relative pos ==> REG0/1/2
            // OMI relative pos ==> DL0/1/2
            const auto l_omic_pos = mss::relative_pos<fapi2::TARGET_TYPE_MC>(l_omic);
            uint8_t l_omi_pos = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_OMI_DL_GROUP_POS, l_omi, l_omi_pos) );

            switch(l_omic_pos)
            {
                case 0:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
                            break;

                        case 1:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
                            break;

                        case 2:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_EDPL_RETRAIN>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                case 1:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
                            break;

                        case 1:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
                            break;

                        case 2:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_EDPL_RETRAIN>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                case 2:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
                            break;

                        case 1:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
                            break;

                        case 2:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FATAL_ERROR>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_DATA_UE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_X4_MODE>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_TIMEOUT>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_ERROR_RETRAIN>()
                            .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_EDPL_RETRAIN>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_OMIC_POSITION().
                                set_POSITION(l_omic_pos).
                                set_OMIC_TARGET(l_omic),
                                "Invalid OMIC position (%d) for %s", l_omic_pos, mss::c_str(l_omic));
                    break;
            }
        }

        fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
        fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;

        mss::fir::reg<P9A_OMIC_FIR_REG> l_omic_fir_reg(l_omic, l_rc1);
        mss::fir::reg<P9A_OMIC_PPE_FIR_REG> l_omic_ppe_fir_reg(l_omic, l_rc2);

        FAPI_TRY(l_rc1, "unable to create fir::reg for P9A_OMIC_FIR_REG 0x%08X", P9A_OMIC_FIR_REG);
        FAPI_TRY(l_rc2, "unable to create fir::reg for P9A_OMIC_PPE_FIR_REG 0x%08X", P9A_OMIC_PPE_FIR_REG);

        // Write OMIC FIR register per Axone unmask spec
        FAPI_TRY(l_omic_fir_reg.recoverable_error<P9A_OMIC_FIR_REG_RX_INVALID_STATE_OR_PARITY_ERROR>()
                 .recoverable_error<P9A_OMIC_FIR_REG_TX_INVALID_STATE_OR_PARITY_ERROR>()
                 .recoverable_error<P9A_OMIC_FIR_REG_GCR_HANG_ERROR>()
                 .write());

        // Write OMIC PPE FIR register per Axone unmask spec
        // Note that the spec says this entire reg should be (re)masked just in case
        // so this is intentional
        FAPI_TRY( (l_omic_ppe_fir_reg.masked<P9A_OMIC_PPE_FIR_REG_ERROR, P9A_OMIC_PPE_FIR_REG_ERROR_LEN>()
                   .masked<P9A_OMIC_PPE_FIR_REG_HALTED>()
                   .masked<P9A_OMIC_PPE_FIR_REG_WATCHDOG_TIMEOUT>()
                   .masked<P9A_OMIC_PPE_FIR_REG_MMIO_DATA_IN>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_MISSED_SCRUB_TICK>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_ARY_UE>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_ARY_CE>()
                   .masked<P9A_OMIC_PPE_FIR_REG_RESERVED>()
                   .masked<P9A_OMIC_PPE_FIR_REG_SCOMFIR_ERROR>()
                   .masked<P9A_OMIC_PPE_FIR_REG_SCOMFIR_ERROR_CLONE>()
                   .write()) );
    }

    // Write MC_OMI_FIR registers now that they've been set up in the loop above
    FAPI_TRY(l_mc_reg0_omi_fir_reg.write());
    FAPI_TRY(l_mc_reg1_omi_fir_reg.write());
    FAPI_TRY(l_mc_reg2_omi_fir_reg.write());

    for (const auto& l_mcc : mss::find_targets<fapi2::TARGET_TYPE_MCC>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::fir::reg<P9A_MCC_DSTLFIR> l_mcc_dstlfir_reg(l_mcc, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for P9A_MCC_DSTLFIR 0x%08X", P9A_MCC_DSTLFIR);

        // Write DSTLFIR register per Axone unmask spec
        FAPI_TRY(l_mcc_dstlfir_reg.checkstop<P9A_MCC_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR>()
                 .checkstop<P9A_MCC_DSTLFIR_ASYNC_CROSSING_SEQUENCE_ERROR>()
                 .recoverable_error<P9A_MCC_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>()
                 .checkstop<P9A_MCC_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_CHANNEL_TIMEOUT_SUBCH_A>()
                 .local_checkstop<P9A_MCC_DSTLFIR_CHANNEL_TIMEOUT_SUBCH_B>()
                 .write());
    }

    // Set up ERROR_MASK on REGm_DLn 0:2 registers
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG0_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG0_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG0_DL2_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG1_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG1_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG1_DL2_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG2_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG2_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_chiplet_scominit_helper<MCT::REG2_DL2_ERROR_MASK>(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Helper function to perform p9a OMI FIR unmasks
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
inline fapi2::ReturnCode after_p9a_omi_init_omi_fir_helper(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<P9A_MC_REG0_OMI_FIR> l_mc_reg0_omi_fir_reg(i_target, l_rc);
    mss::fir::reg<P9A_MC_REG1_OMI_FIR> l_mc_reg1_omi_fir_reg(i_target, l_rc2);
    mss::fir::reg<P9A_MC_REG2_OMI_FIR> l_mc_reg2_omi_fir_reg(i_target, l_rc3);

    FAPI_TRY(l_rc, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target), P9A_MC_REG0_OMI_FIR);
    FAPI_TRY(l_rc2, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target), P9A_MC_REG1_OMI_FIR);
    FAPI_TRY(l_rc3, "for target %s unable to create fir::reg for 0x%016x", mss::c_str(i_target), P9A_MC_REG2_OMI_FIR);

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
        {
            // Set up MC_OMI_FIR register per Axone unmask spec
            // Note that there are child-target-specific FIR bits in these regs, so we need to check
            // what's configured and unmask the corresponding group of FIRs in the right reg
            // OMIC relative pos ==> REG0/1/2
            // OMI relative pos ==> DL0/1/2
            const auto l_omic_pos = mss::relative_pos<fapi2::TARGET_TYPE_MC>(l_omic);
            uint8_t l_omi_pos = 0;
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_OMI_DL_GROUP_POS, l_omi, l_omi_pos) );

            switch(l_omic_pos)
            {
                case 0:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FLIT_CE>();
                            break;

                        case 1:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FLIT_CE>();
                            break;

                        case 2:
                            l_mc_reg0_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FLIT_CE>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                case 1:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FLIT_CE>();
                            break;

                        case 1:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FLIT_CE>();
                            break;

                        case 2:
                            l_mc_reg1_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FLIT_CE>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                case 2:
                    switch(l_omi_pos)
                    {
                        case 0:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_FLIT_CE>();
                            break;

                        case 1:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_FLIT_CE>();
                            break;

                        case 2:
                            l_mc_reg2_omi_fir_reg.recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_FLIT_CE>();
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::MSS_INVALID_OMI_POSITION().
                                        set_POSITION(l_omi_pos).
                                        set_OMI_TARGET(l_omi),
                                        "Invalid OMI position (%d) for %s", l_omi_pos, mss::c_str(l_omi));
                            break;
                    }

                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_OMIC_POSITION().
                                set_POSITION(l_omic_pos).
                                set_OMIC_TARGET(l_omic),
                                "Invalid OMIC position (%d) for %s", l_omic_pos, mss::c_str(l_omic));
                    break;
            }
        }
    }

    // Write MC_OMI_FIR registers now that they've been set up in the loop above
    FAPI_TRY(l_mc_reg0_omi_fir_reg.write());
    FAPI_TRY(l_mc_reg1_omi_fir_reg.write());
    FAPI_TRY(l_mc_reg2_omi_fir_reg.write());

    using MCT = mss::mcTraits<mss::proc_type::AXONE>;

    // Clear ERROR_MASK on REGm_DLn 0:2 registers because they are now considered valid
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG0_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG0_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG0_DL2_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG1_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG1_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG1_DL2_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG2_DL0_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG2_DL1_ERROR_MASK>(i_target));
    FAPI_TRY(setup_reg_dl_after_omi_init_helper<MCT::REG2_DL2_ERROR_MASK>(i_target));

fapi_try_exit:

    return fapi2::current_err;
}

} // end unmask ns

} // end mss ns
#endif
