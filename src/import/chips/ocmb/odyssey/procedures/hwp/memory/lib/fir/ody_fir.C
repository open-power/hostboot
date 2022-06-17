/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/fir/ody_fir.H>
#include <ody_scom_ody_odc.H>

namespace mss
{

namespace check
{

///
/// @brief Helper for bad_fir_bits to check a fir register/mask pair against a desired mask value
/// @param[in] i_target - the target on which to operate
/// @param[in] i_fir_addr - address of the FIR register to compare against mask
/// @param[in] i_mask_addr - address of the mask register for i_fir_addr
/// @param[in] i_mask - the 64-bit mask that we want to compare the reg against
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode bad_fir_bits_helper_with_mask(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_fir_addr,
        const uint64_t i_mask_addr,
        const fapi2::buffer<uint64_t>& i_mask,
        fapi2::ReturnCode& io_rc,
        bool& o_fir_error)
{
    fapi2::buffer<uint64_t> l_mask_data;
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(fapi2::getScom(i_target, i_fir_addr, l_reg_data));
    FAPI_TRY(fapi2::getScom(i_target, i_mask_addr, l_mask_data));

    // OR together the input mask with the mask register value so we aren't checking any FIRs
    // that are currently masked in hardware
    o_fir_error = fir_with_mask_helper(l_reg_data, (i_mask | l_mask_data));

#ifndef __PPE__
    FAPI_INF(TARGTIDFORMAT " %s on reg 0x%016lx value 0x%016lx and mask value 0x%016lx", TARGTID,
             o_fir_error ? "has FIR's set" : "has no FIR's set",
             i_fir_addr, l_reg_data, (i_mask | l_mask_data));
#endif

    // Log the error if need be
    log_fir_helper(i_target, o_fir_error, io_rc);

    // Exit if we have found a FIR
    if(o_fir_error)
    {
        return fapi2::FAPI2_RC_SUCCESS;
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
/// @note specialization for ODYSSEY and fir checklist for DRAMINIT regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::ODYSSEY, firChecklist::DRAMINIT>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    const auto l_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // For draminit case, we want to check SRQFIR[4] or [33] only based on the port position, so unmask checkbits
    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Unmask bit 4 or 33 depending on which port we're on
    constexpr uint32_t SRQ0_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_04;
    constexpr uint32_t SRQ1_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_33;

    if (l_pos == 0)
    {
        l_check_mask.clearBit<SRQ0_RCD_PARITY_ERROR>();
    }
    else
    {
        l_check_mask.clearBit<SRQ1_RCD_PARITY_ERROR>();
    }

    FAPI_TRY(bad_fir_bits_helper_with_mask(l_ocmb,
                                           scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR,
                                           scomt::ody::ODC_SRQ_MASK_RW_WCLEAR,
                                           l_check_mask,
                                           io_rc,
                                           o_fir_error));

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

    // Unmask bits 4 and 33
    constexpr uint32_t SRQ0_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_04;
    constexpr uint32_t SRQ1_RCD_PARITY_ERROR = scomt::ody::ODC_SRQ_LFIR_33;
    l_check_mask.clearBit<SRQ0_RCD_PARITY_ERROR>()
    .clearBit<SRQ1_RCD_PARITY_ERROR>();

    FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                           scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR,
                                           scomt::ody::ODC_SRQ_MASK_RW_WCLEAR,
                                           l_check_mask,
                                           io_rc,
                                           o_fir_error));

    // Mask all, then unmask bits 3,4
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>().clearBit<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_INTERNAL_FSM_ERROR>()
        .clearBit<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target,
                                               scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR,
                                               scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR,
                                               l_check_mask,
                                               io_rc,
                                               o_fir_error));
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
