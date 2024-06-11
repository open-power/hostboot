/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_proc_specific_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_proc_specific_fir.C
/// @brief Memory subsystem FIR support - for this specific processor only. Not to be mirrored
///
// *HWP HWP Owner: Josh Chica <Josh.Chica@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/fir/ody_fir.H>
#include <ody_scom_omi.H>
#include <ody_scom_perv.H>
#include <p10_scom_omic.H>
#include <p10_scom_mcc.H>

namespace mss
{
namespace check
{

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the OCMB_CHIP target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY and fir checklist for IO regs
///
template <>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::IO_GENERAL>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    // Note: these addresses don't have the leading '8' or '1' in the reg headers, so define them here
    constexpr uint64_t TCMC_LFIR_RW_WCLEAR = 0x8040100ull;
    constexpr uint64_t TCMC_EPS_MASK_RW_WCLEAR = 0x8040102ull;
    constexpr uint64_t TPCHIP_TPC_LFIR_RW_WCLEAR = 0x1040100ull;
    constexpr uint64_t TPCHIP_TPC_EPS_MASK_RW_WCLEAR = 0x1040102ull;

    /*
        Check:
            TCP.LFIR: 3,18
            TCMC.LFIR: 3
            IOPPE.FIR: 1,5,13,14,15,16,17,18,20,23,26,27
    */
    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);
    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Check TCP.LFIR bits [3,18]
    if(o_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::perv::TPCHIP_TPC_LFIR_CC_OTHERS>()
        .clearBit<scomt::perv::TPCHIP_TPC_LFIR_IN18>();
        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               TPCHIP_TPC_LFIR_RW_WCLEAR,
                                               TPCHIP_TPC_EPS_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
    }

    // Check TCMC.LFIR: bits [3]
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::perv::TCMC_LFIR_CC_OTHERS>();
        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               TCMC_LFIR_RW_WCLEAR,
                                               TCMC_EPS_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
    }

    // Check IOPPE.FIR: bits [1,5,13,14,15,16,17,18,20,23,26,27]
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_IO0_RX_INVALID_STATE_OR_PARITY_ERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_IO0_TX_INVALID_STATE_OR_PARITY_ERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_INT_HWERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_EXT_HWERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_HALT_DEBUG>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_HALTED>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_WATCHDOG_TIMEOUT>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_CODE_FATAL_ERROR>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_CODE_RECAL_NOT_RUN>()
        .clearBit<scomt::omi::PHY_SCOM_MAC0_LFIR_REG_PPE_CODE_THREAD_LOCKED>();
        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               scomt::omi::PHY_SCOM_MAC0_LFIR_REG_RW_WCLEAR,
                                               scomt::omi::PHY_SCOM_MAC0_LFIR_MASK_REG_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
    }

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the OCMB_CHIP target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY and fir checklist for IO_TRAIN regs
///
template <>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::IO_TRAIN>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    /*
        Check:
            MC.OMI.FIR.REG: 1,2,6,8,10,11,21,22
    */
    const auto c_omic_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_OMIC>();
    const auto c_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_MCC>();

    fapi2::ATTR_FAPI_POS_Type l_ocmb_pos = 0;

    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);
    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_target, l_ocmb_pos));
    l_ocmb_pos = l_ocmb_pos % 2;

    // Check MC.OMI.FIR.REG: bits [1,2,6,8,10,11,21,22]
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_FATAL_ERROR>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_DATA_UE>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_X4_MODE>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_TIMEOUT>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_ERROR_RETRAIN>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_EDPL_RETRAIN>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_SKITTER_ERROR>()
        .clearBit<scomt::omi::D_REG_MC_OMI_FIR_DL0_SKITTER_DRIFT>();
        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               scomt::omi::D_REG_MC_OMI_FIR_RW_WCLEAR,
                                               scomt::omi::D_REG_MC_OMI_FIR_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
    }

    // P10 FIR checks
    if (o_fir_error != true)
    {
        // Check MC.OMI.FIR.REG: bits [0,1,5,7,10]
        if (!l_ocmb_pos)
        {
            l_check_mask.flush<1>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_DATA_UE>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_TIMEOUT>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
        }
        else
        {
            l_check_mask.flush<1>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL1_DATA_UE>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL1_X4_MODE>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL1_TIMEOUT>()
            .clearBit<scomt::omic::MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
        }

        FAPI_TRY(bad_fir_bits_helper_with_mask(c_omic_target,
                                               scomt::omic::MC_OMI_FIR_REG_RW,
                                               scomt::omic::MC_OMI_FIR_MASK_REG_RW,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));

        // Check DSTLFIR.REG: bits [8,9,10,11,12,13,16,17,22,23,35,36]
        if (o_fir_error != true)
        {
            l_check_mask.flush<1>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>();

            // Check if OMI0
            if (!l_ocmb_pos)
            {
                l_check_mask.clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>();
            }
            // OMI1
            else
            {
                l_check_mask.clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
                .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();
            }

            FAPI_TRY(bad_fir_bits_helper_with_mask(c_mcc_target,
                                                   scomt::mcc::DSTL_DSTLFIR_RW,
                                                   scomt::mcc::DSTL_DSTLFIRMASK_RW,
                                                   l_check_mask,
                                                   io_rc,
                                                   o_fir_error));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end check ns
} // end mss ns
