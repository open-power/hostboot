/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_fir.C $ */
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

///
/// @file exp_fir.C
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/fir/exp_fir_traits.H>

namespace mss
{

namespace check
{

// Declares FIR registers that are re-used between multiple functions
// Vectors of FIR and mask registers to read through
// As check_fir can be called in multiple places, we don't know what the mask may hold
// In order to tell if a FIR is legit or not, we read the FIR and check it against the mask reg
// Note: using a vector here in case we need to expand
static const std::vector<std::pair<uint64_t, uint64_t>> EXPLORER_FIR_REGS =
{
    // Explorer LOCAL_FIR
    {EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR, EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK},

    // Explorer MC_OMI_FIR_REG
    {EXPLR_DLX_MC_OMI_FIR_REG, EXPLR_DLX_MC_OMI_FIR_MASK_REG},
};

static const std::vector<std::pair<uint64_t, uint64_t>> MC_FIR_REGS =
{
    // Axone MC_OMI_FIR_REG
    {P9A_MC_REG0_OMI_FIR, P9A_MC_REG0_OMI_FIR_MASK},
};

static const std::vector<std::pair<uint64_t, uint64_t>> MCC_FIR_REGS =
{
    // Axone DSTLFIR
    {P9A_MCC_DSTLFIR, P9A_MCC_DSTLFIRMASK},
};

///
/// @brief Checks whether any FIRs have lit up on a target
/// @param[in] i_target - the target on which to operate
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode bad_fir_bits<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::ReturnCode& io_rc,
        bool& o_fir_error )
{
    const auto& l_mcc = mss::find_target<fapi2::TARGET_TYPE_MCC>(i_target);
    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(l_mcc);

    // Start by assuming we do not have a FIR
    o_fir_error = false;

    // Loop, check the scoms, and check the FIR
    // Note: we return out if any FIR is bad
    for(const auto& l_fir_reg : EXPLORER_FIR_REGS)
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

    for(const auto& l_fir_reg : MC_FIR_REGS)
    {
        FAPI_TRY(fir_with_mask<mss::mc_type::EXPLORER>(l_mc, l_fir_reg, o_fir_error));

        // Log the error if need be
        log_fir_helper(l_mc, o_fir_error, io_rc);

        // Exit if we have found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    for(const auto& l_fir_reg : MCC_FIR_REGS)
    {
        FAPI_TRY(fir_with_mask<mss::mc_type::EXPLORER>(l_mcc, l_fir_reg, o_fir_error));

        // Log the error if need be
        log_fir_helper(l_mcc, o_fir_error, io_rc);

        // Exit if we have found a FIR
        if(o_fir_error)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end check ns
} // end mss ns
