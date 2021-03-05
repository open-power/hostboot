/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_fir.C $ */
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
/// @file exp_fir.C
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
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/fir/exp_fir_traits.H>
#include <p10_scom_mcc_9.H>
#include <p10_scom_mcc_b.H>
#include <p10_scom_omic_3.H>
#include <p10_scom_omic_f.H>

namespace mss
{

namespace check
{

///
/// Declares FIR registers that are re-used between multiple functions
/// Vectors of FIR and mask registers to read through
/// As check_fir can be called in multiple places, we don't know what the mask may hold
/// In order to tell if a FIR is legit or not, we read the FIR and check it against the mask reg
/// Note: using a vector here in case we need to expand
/// Note: the format for these vectors is [TARGET_TYPE]_[PROCEDURE]_FIR_REGS
/// Note: if you change the order of the regs, update indicies in bad_fir_bits below
///
static const std::vector<std::pair<uint64_t, uint64_t>> EXPLORER_OMI_INIT_FIR_REGS =
{
    // Explorer LOCAL_FIR
    {EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR, EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK},

    // Explorer MC_OMI_FIR_REG
    {EXPLR_DLX_MC_OMI_FIR_REG, EXPLR_DLX_MC_OMI_FIR_MASK_REG},

    // Explorer SRQFIR
    {EXPLR_SRQ_SRQFIRQ, EXPLR_SRQ_SRQFIR_MASK},
};

static const std::vector<std::pair<uint64_t, uint64_t>> EXPLORER_DRAMINIT_FIR_REGS =
{
    // Explorer SRQFIR
    {EXPLR_SRQ_SRQFIRQ, EXPLR_SRQ_SRQFIR_MASK},

    // Explorer LOCAL_FIR
    {EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR, EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK},
};

static const std::vector<std::pair<uint64_t, uint64_t>> EXPLORER_CCS_FIR_REGS =
{
    // Explorer SRQFIR
    {EXPLR_SRQ_SRQFIRQ, EXPLR_SRQ_SRQFIR_MASK},

    // Explorer MCBISTFIR
    {EXPLR_MCBIST_MCBISTFIRQ, EXPLR_MCBIST_MCBISTFIRMASK},

};

static const std::vector<std::pair<uint64_t, uint64_t>> MC_OMI_INIT_FIR_REGS =
{
    // P10 MC_OMI_FIR_REG
    {scomt::omic::MC_OMI_FIR_REG_RW, scomt::omic::MC_OMI_FIR_MASK_REG_RW},
};

static const std::vector<std::pair<uint64_t, uint64_t>> MCC_OMI_INIT_FIR_REGS =
{
    // P10 DSTLFIR
    {scomt::mcc::DSTL_DSTLFIR_RW, scomt::mcc::DSTL_DSTLFIRMASK_RW},
};

///
/// @brief Helper for bad_fir_bits to loop through reg/mask pairs for FIRs
/// @tparam T the fapi2::TargetType that we are targeting for fir reg checking, inherited
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @param[in] i_checklist - the list of vector reg/mask pairs to search
/// @note i_checklist is last since optional parameter w/ default needs to be end of list
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode bad_fir_bits_helper(const fapi2::Target<T>& i_target,
                                      fapi2::ReturnCode& io_rc,
                                      bool& o_fir_error,
                                      const std::vector<std::pair<uint64_t, uint64_t>>& i_checklist)
{
    // Loop, check the scoms, and check the FIR
    // Note: we return out if any FIR is bad
    for(const auto& l_fir_reg : i_checklist)
    {
        FAPI_TRY(fir_with_mask<mss::mc_type::EXPLORER>(i_target, l_fir_reg, o_fir_error));

        // Log the error if need be
        log_fir_helper(i_target, o_fir_error, io_rc);

        // Exit if we have found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper for bad_fir_bits to check a fir register/mask pair against a desired mask value
/// @param[in] i_target - the target on which to operate
/// @param[in] i_fir_reg - the register/mask pair to compare against mask
/// @param[in] i_mask - the 64-bit mask that we want to compare the reg against
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode bad_fir_bits_helper_with_mask(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::pair<uint64_t, uint64_t>& i_fir_reg,
        const fapi2::buffer<uint64_t>& i_mask,
        fapi2::ReturnCode& io_rc,
        bool& o_fir_error)
{
    fapi2::buffer<uint64_t> l_mask_data;
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(fapi2::getScom(i_target, i_fir_reg.first, l_reg_data));
    FAPI_TRY(fapi2::getScom(i_target, i_fir_reg.second, l_mask_data));

    // AND together the input mask with the mask register value so we aren't checking any FIRs
    // that are currently masked in hardware
    o_fir_error = fir_with_mask_helper(l_reg_data, (i_mask & l_mask_data));

    FAPI_INF("%s %s on reg 0x%016lx value 0x%016lx and mask value 0x%016lx", mss::c_str(i_target),
             o_fir_error ? "has FIR's set" : "has no FIR's set",
             i_fir_reg.first, l_reg_data, (i_mask & l_mask_data));

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
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for EXPLORER and fir checklist for OMI regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::OMI>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    const auto& l_mcc = mss::find_target<fapi2::TARGET_TYPE_MCC>(i_target);
    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(i_target);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // For OMI case, we want to check all bits on fir registers (no custom mask)
    FAPI_TRY(bad_fir_bits_helper(i_target, io_rc, o_fir_error, EXPLORER_OMI_INIT_FIR_REGS));

    if (o_fir_error != true)
    {
        FAPI_TRY(bad_fir_bits_helper(l_omic, io_rc, o_fir_error, MC_OMI_INIT_FIR_REGS));
    }

    if (o_fir_error != true)
    {
        FAPI_TRY(bad_fir_bits_helper(l_mcc, io_rc, o_fir_error, MCC_OMI_INIT_FIR_REGS));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Specialization for EXPLORER, fir checklist for OMI regs, TARGET_TYPE_OMI
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::OMI>(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error )
{
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target))
    {
        FAPI_TRY( (bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::OMI>(l_ocmb, io_rc, o_fir_error)) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for EXPLORER and fir checklist for DRAMINIT regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::DRAMINIT>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    // For draminit case, we want to check SRQFIR[4] and LOCAL_FIR[20,36] only, so unmask checkbits
    // NOTE: if you change DRAMINIT_FIR_REGS, you need to update these indices
    const auto l_srqfir = EXPLORER_DRAMINIT_FIR_REGS.at(0);
    const auto l_localfir = EXPLORER_DRAMINIT_FIR_REGS.at(1);
    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Unmask bit 4
    l_check_mask.clearBit<EXPLR_SRQ_SRQFIRQ_RCD_PARITY_ERROR>();
    FAPI_TRY(bad_fir_bits_helper_with_mask(i_target, l_srqfir, l_check_mask, io_rc, o_fir_error));

    // Mask all, then unmask bits 20,36
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>().clearBit<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_106>()
        .clearBit<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_DDR4_PHY__FATAL>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target, l_localfir, l_check_mask, io_rc, o_fir_error));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for EXPLORER and fir checklist for CCS regs
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::CCS>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ReturnCode& io_rc,
    bool& o_fir_error)
{
    // For draminit_mc case, we want to check SRQFIR[4] and MBISTFIR[2,3] only, so unmask checkbits
    // NOTE: if you change DRAMINIT_MC_FIR_REGS, you need to update these indices
    const auto l_srqfir = EXPLORER_CCS_FIR_REGS.at(0);
    const auto l_mcbistfir = EXPLORER_CCS_FIR_REGS.at(1);
    fapi2::buffer<uint64_t> l_check_mask(0xFFFFFFFFFFFFFFFF);

    // Start by assuming we do not have a FIR; if true at any point, skip other checks to preserve error
    o_fir_error = false;

    // Unmask bit 4
    l_check_mask.clearBit<EXPLR_SRQ_SRQFIRQ_RCD_PARITY_ERROR>();
    FAPI_TRY(bad_fir_bits_helper_with_mask(i_target, l_srqfir, l_check_mask, io_rc, o_fir_error));

    // Mask all, then unmask bits 2,3
    if (o_fir_error != true)
    {
        l_check_mask.flush<1>().clearBit<EXPLR_MCBIST_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
        .clearBit<EXPLR_MCBIST_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>();

        FAPI_TRY(bad_fir_bits_helper_with_mask(i_target, l_mcbistfir, l_check_mask, io_rc, o_fir_error));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note specialization for EXPLORER and fir checklist for GENERIC case
/// Redirects the GENERIC case to the DRAMINIT checks because no FIR checklist is defined for GENERIC.
/// GENERIC case required for bad_fir_bits call in mss_bad_bits.H -- update if GENERIC check needed
///
template<>
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::GENERIC>( const
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::ReturnCode& io_rc,
        bool& o_fir_error)
{
    // NOTE: Redirecting the GENERIC case to the DRAMINIT checks because no FIR checklist is defined for GENERIC.
    //       GENERIC case required for bad_fir_bits call in mss_bad_bits.H -- update if GENERIC check needed
    return bad_fir_bits<mss::mc_type::EXPLORER, firChecklist::DRAMINIT>(i_target, io_rc, o_fir_error);
}

} // end check ns
} // end mss ns
