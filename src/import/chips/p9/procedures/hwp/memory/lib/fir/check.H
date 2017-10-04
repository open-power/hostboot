/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/check.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file check.H
/// @brief Subroutines for checking MSS FIR
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_CHECK_FIR_H_
#define _MSS_CHECK_FIR_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>

namespace mss
{

namespace check
{

///
/// @brief Check FIR bits during PHY reset
/// @note For DDRPHYFIR and some MBACALFIR errors, up to and including phy reset, need to
/// handle within the phy reset procedure, since we may get errors from a 'non-functional'
/// magic port, which PRD can't analyze.
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode during_phy_reset( const fapi2::Target<T>& i_target );

///
/// @brief Check FIR bits during draminit training
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the dimm that was trained
/// @note We check for fir errors after training each rank
/// to see if there was a problem with the engine
/// FFDC errors return from this will be handle similar to other training errors
/// Logged if it affects less than a nibble and a bit.
/// Reported if it affects more than that
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode during_draminit_training( const fapi2::Target<T>& i_target );

///
/// @brief Checks whether any of the PLL unlock values are set
/// @param[in] i_local_fir - the overall FIR register
/// @param[in] i_perv_fir - the pervasive PLL FIR
/// @param[in] i_mc_fir - the memory controller FIR
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
bool pll_unlock( const fapi2::buffer<uint64_t>& i_local_fir,
                 const fapi2::buffer<uint64_t>& i_perv_fir,
                 const fapi2::buffer<uint64_t>& i_mc_fir );

///
/// @brief Checks whether any PLL FIRs have been set on a target
/// @param[in] i_target - the target on which to operate
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pll_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, bool& o_fir_error );

///
/// @brief Checks whether any FIRs have lit up on a target
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target - the target on which to operate
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode bad_fir_bits( const fapi2::Target<T>& i_target, bool& o_fir_error );

///
/// @brief Checks whether the passed in FIRs have any un-masked errors set
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target - the target on which to operate
/// @param[in] i_fir_regs - FIR register and mask register
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode fir_with_mask( const fapi2::Target<T>& i_target,
                                        const std::pair<uint64_t, uint64_t>& i_fir_regs,
                                        bool& o_fir_error )
{
    // Temporary variables to make the code a bit more readable
    const auto FIR_REG = i_fir_regs.first;
    const auto FIR_MASK = i_fir_regs.second;

    fapi2::buffer<uint64_t> l_fir;
    fapi2::buffer<uint64_t> l_fir_mask;

    // Read the registers
    FAPI_TRY(mss::getScom(i_target, FIR_REG, l_fir));
    FAPI_TRY(mss::getScom(i_target, FIR_MASK, l_fir_mask));


    // The mask register will need to be inverted as a 0 in the mask register means the FIR is legit
    // A bitwise and works the opposite way
    l_fir_mask.invert();

    // If we have any unmasked bit, set that we have a FIR error and exit out with success
    // Note: we want to set success here as PRD will find the FIR as "new" and retrigger the procedure this way
    o_fir_error = ((l_fir & l_fir_mask) != 0);

    // And print the information for debuggability
    FAPI_INF("%s %s on reg 0x%016lx value 0x%016lx and mask 0x%016lx value 0x%016lx", mss::c_str(i_target),
             o_fir_error ? "has FIR's set" : "has no FIR's set", FIR_REG, l_fir, FIR_MASK, l_fir_mask.invert());

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks whether a FIR or unlocked PLL could be the root cause of another failure
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target - the target on which to operate
/// @param[in] i_rc - the return code for the function - cannot be const due to a HB compile issue
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note This is a helper function to enable unit testing
///
template< fapi2::TargetType T >
fapi2::ReturnCode hostboot_fir_or_pll_fail( const fapi2::Target<T>& i_target, fapi2::ReturnCode& i_rc)
{
    // We didn't have an error, so return success
    if(i_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF("%s has a good return code, returning success", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    fapi2::ReturnCode l_fircheck_scom_err(fapi2::FAPI2_RC_SUCCESS);
    bool l_fir_error = false;

    FAPI_ERR("%s has a bad return code, time to check some firs!", mss::c_str(i_target));

    l_fircheck_scom_err = bad_fir_bits(i_target, l_fir_error);

    FAPI_ERR("%s took a fail. FIR was %s", mss::c_str(i_target),
             l_fir_error ? "set - returning FIR RC" : "unset - returning inputted RC");

    // If we had a FIR error, log the original error and return success
    // PRD will handle the original error
    if(l_fir_error)
    {
        fapi2::log_related_error(i_target, i_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        fapi2::current_err = i_rc;
    }

    return fapi2::current_err;
}

///
/// @brief Checks whether a FIR or unlocked PLL could be the root cause of another failure, if a check fir boolean is passed in
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target - the target on which to operate
/// @param[in] i_rc - the return code for the function - cannot be const due to a HB compile issue
/// @param[in] i_check_fir - true IFF the FIR needs to be checked - defaults to true
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode fir_or_pll_fail( const fapi2::Target<T>& i_target, fapi2::ReturnCode& i_rc,
                                   const bool i_check_fir = true)
{
#ifdef __HOSTBOOT_MODULE

    fapi2::ReturnCode l_rc(i_rc);

    // If need be, check the FIR below
    if(i_check_fir)
    {
        // Handle any issues according to PRD FIR scheme, as a FIR could have caused this issue
        l_rc = hostboot_fir_or_pll_fail(i_target, l_rc);
    }

    return l_rc;

#else
    return i_rc;
#endif
}

}
}
#endif
