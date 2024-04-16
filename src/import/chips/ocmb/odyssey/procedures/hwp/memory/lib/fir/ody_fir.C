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
// *HWP Level: 3
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

} // end check ns
} // end mss ns
