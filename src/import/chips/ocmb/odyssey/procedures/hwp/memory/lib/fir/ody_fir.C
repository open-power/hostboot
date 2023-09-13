/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file ody_fir.C
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/fir/ody_fir.H>
#include <ody_scom_ody_odc.H>
#include <ody_scom_mp_odp.H>
#include <ody_scom_perv_tcmc.H>
#include <ody_scom_perv_tpchip.H>
#include <ody_scom_omi.H>
#include <ody_scom_perv.H>
#include <p10_scom_omic.H>
#include <p10_scom_mcc.H>

namespace mss
{

namespace check
{

namespace ody
{

///
/// @brief Helper to check port-specific FIR bits after draminit
/// @param[in] i_target - the MEM_PORT target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[in,out] io_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode bad_fir_bits_draminit_internal(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& io_fir_error)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    const auto l_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Check SRQFIR[4] or [33], [30] or [34], and [44] based on the port position
    if (io_fir_error != true)
    {
        // Unmask bit 4 or 33 depending on which port we're on
        constexpr uint32_t SRQ0_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_IN04;
        constexpr uint32_t SRQ1_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_IN33;
        // Unmask bit 30 or 34 depending on which port we're on
        constexpr uint32_t SRQ0_DFI_ERROR = scomt::ody::ODC_SRQ_LFIR_IN30;
        constexpr uint32_t SRQ1_DFI_ERROR = scomt::ody::ODC_SRQ_LFIR_IN34;

        if (l_pos == 0)
        {
            l_check_mask.clearBit<SRQ0_RCD_PARITY_ERROR>()
            .clearBit<SRQ0_DFI_ERROR>();
        }
        else
        {
            l_check_mask.clearBit<SRQ1_RCD_PARITY_ERROR>()
            .clearBit<SRQ1_DFI_ERROR>();
        }

        l_check_mask.clearBit<scomt::ody::ODC_SRQ_LFIR_IN44>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(l_ocmb,
                                               scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR,
                                               scomt::ody::ODC_SRQ_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               io_fir_error));
    }

    // Check ODP FIR [1,2,3,4,6,9,10,11,12,13]
    if (io_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::mp::S_LFIR_FSMPERR>()
        .clearBit<scomt::mp::S_LFIR_WPERR>()
        .clearBit<scomt::mp::S_LFIR_PSLVPERR>()
        .clearBit<scomt::mp::S_LFIR_ODPCTRLPERR>()
        .clearBit<scomt::mp::S_LFIR_PHYSTICKYUNLOCKERR>()
        .clearBit<scomt::mp::S_LFIR_PHYD5ACSM1PARITYERR>()
        .clearBit<scomt::mp::S_LFIR_PHYD5ACSM0PARITYERR>()
        .clearBit<scomt::mp::S_LFIR_PHYRXFIFOCHECKERR>()
        .clearBit<scomt::mp::S_LFIR_PHYRXTXPPTERR>()
        .clearBit<scomt::mp::S_LFIR_PHYECCERR>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               scomt::mp::S_LFIR_RW_WCLEAR,
                                               scomt::mp::S_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               io_fir_error));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to check chip level FIR bits after draminit
/// @param[in] i_target - the OCMB_CHIP target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[in,out] io_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode bad_fir_bits_draminit_internal(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& io_fir_error)
{
    // Note: these addresses don't have the leading '8' or '1' in the reg headers, so define them here
    constexpr uint64_t TCMC_LFIR_RW_WCLEAR = 0x8040100ull;
    constexpr uint64_t TCMC_EPS_MASK_RW_WCLEAR = 0x8040102ull;
    constexpr uint64_t TPCHIP_TPC_LFIR_RW_WCLEAR = 0x1040100ull;
    constexpr uint64_t TPCHIP_TPC_EPS_MASK_RW_WCLEAR = 0x1040102ull;

    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Check TCMC LFIR [3]
    if (io_fir_error != true)
    {
        l_check_mask.clearBit<scomt::perv::TCMC_LFIR_CC_OTHERS>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               TCMC_LFIR_RW_WCLEAR,
                                               TCMC_EPS_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               io_fir_error));
    }

    // Check TPC LFIR [3,18]
    if (io_fir_error != true)
    {
        l_check_mask.flush<1>()
        .clearBit<scomt::perv::TPCHIP_TPC_LFIR_CC_OTHERS>()
        .clearBit<scomt::perv::TPCHIP_TPC_LFIR_IN18>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               TPCHIP_TPC_LFIR_RW_WCLEAR,
                                               TPCHIP_TPC_EPS_MASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               io_fir_error));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace ody

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the MEM_PORT target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY MEM_PORT and fir checklist for DRAMINIT regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::DRAMINIT>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Check port-specific FIRs first
    FAPI_TRY(ody::bad_fir_bits_draminit_internal(i_target, io_rc, o_fir_error));

    // Check chip level FIRs
    FAPI_TRY(ody::bad_fir_bits_draminit_internal(l_ocmb, io_rc, o_fir_error));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the OCMB_CHIP target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY OCMB_CHIP and fir checklist for DRAMINIT regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::DRAMINIT>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Check port-specific FIRs first
    for (const auto& l_port :  mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(ody::bad_fir_bits_draminit_internal(l_port, io_rc, o_fir_error));
    }

    // Check chip level FIRs
    FAPI_TRY(ody::bad_fir_bits_draminit_internal(i_target, io_rc, o_fir_error));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the OCMB_CHIP target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY and fir checklist for CCS regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::CCS>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    // For draminit_mc case, we want to check SRQFIR[4,33] and MCBISTFIR[3,4] only, so unmask checkbits
    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Check MCBISTFIR bits [3,4]
    {
        l_check_mask.flush<1>().clearBit<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
        .clearBit<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR,
                                               scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
    }

    // Now check all the FIR bits in the DRAMINIT checklist
    if (o_fir_error != true)
    {
        bool l_fir_error = false;
        FAPI_TRY( (bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::DRAMINIT>(i_target, io_rc, l_fir_error)) );
        o_fir_error |= l_fir_error;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the MEM_PORT target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for ODYSSEY and fir checklist for GENERIC case
/// Redirects the GENERIC case to the DRAMINIT checks because no FIR checklist is defined for GENERIC.
/// GENERIC case required for bad_fir_bits call in mss_bad_bits.H -- update if GENERIC check needed
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::GENERIC>( const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        fapi2::ReturnCode& io_rc,
        bool& o_fir_error)
{
    // NOTE: Redirecting the GENERIC case to the DRAMINIT checks because no FIR checklist is defined for GENERIC.
    //       GENERIC case required for bad_fir_bits call in mss_bad_bits.H -- update if GENERIC check needed
    return bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::DRAMINIT>(i_target, io_rc, o_fir_error);
}

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
                                               scomt::perv::TPCHIP_TPC_LFIR_RW_WCLEAR,
                                               scomt::perv::TPCHIP_TPC_EPS_MASK_RW_WCLEAR,
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
                                               scomt::perv::TCMC_LFIR_RW_WCLEAR,
                                               scomt::perv::TCMC_EPS_MASK_RW_WCLEAR,
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
    //const auto c_omic_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<faip2::TARGET_TYPE_OMIC>();
    //const auto c_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<faip2::TARGET_TYPE_MCC>();
    const auto c_omic_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_OMIC>();
    const auto c_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_MCC>();
    //const auto c_omic_target = i_target.getParent<faip2::TARGET_TYPE_OMIC>();
    //const auto c_mcc_target = i_target.getParent<faip2::TARGET_TYPE_MCC>();

    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

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
        l_check_mask.flush<1>()
        .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
        .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_DATA_UE>()
        .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_X4_MODE>()
        .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_TIMEOUT>()
        .clearBit<scomt::omic::MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(c_omic_target,
                                               scomt::omic::MC_OMI_FIR_REG_WO_AND,
                                               scomt::omic::MC_OMI_FIR_MASK_REG_WO_AND,
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
            .clearBit<scomt::mcc::DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR>()
            .clearBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR>();

            FAPI_TRY(bad_fir_bits_helper_with_mask(c_mcc_target,
                                                   scomt::mcc::DSTL_DSTLFIR_WO_AND,
                                                   scomt::mcc::DSTL_DSTLFIRMASK_WO_AND,
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
