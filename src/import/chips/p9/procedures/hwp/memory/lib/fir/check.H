/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/check.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#include <generic/memory/lib/utils/mss_generic_check.H>

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
/// @param[in,out] io_rc - the return code for the function
/// @param[out] o_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pll_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                           fapi2::ReturnCode& io_rc,
                           bool& o_fir_error );

}
}
#endif
