/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_fir.H $ */
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
/// @file ody_fir.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ODY_FIR_H_
#define _MSS_ODY_FIR_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{

namespace check
{

///
/// @brief Helper for bad_fir_bits to check a fir register/mask pair against a desired mask value
/// @tparam T the target type of i_target (derived)
/// @param[in] i_target - the target on which to operate
/// @param[in] i_fir_addr - address of the FIR register to compare against mask
/// @param[in] i_mask_addr - address of the mask register for i_fir_addr
/// @param[in] i_mask - the 64-bit mask that we want to compare the reg against
/// @param[in,out] io_rc - the return code for the function
/// @param[in,out] io_fir_error - true iff a FIR was hit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template <fapi2::TargetType T >
fapi2::ReturnCode bad_fir_bits_helper_with_mask(const fapi2::Target<T>& i_target,
        const uint64_t i_fir_addr,
        const uint64_t i_mask_addr,
        const fapi2::buffer<uint64_t>& i_mask,
        fapi2::ReturnCode& io_rc,
        bool& io_fir_error)
{
    fapi2::buffer<uint64_t> l_mask_data;
    fapi2::buffer<uint64_t> l_reg_data;

    // Don't bother checking any FIRs if we've already found one to blame
    if (io_fir_error)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(fapi2::getScom(i_target, i_fir_addr, l_reg_data));
    FAPI_TRY(fapi2::getScom(i_target, i_mask_addr, l_mask_data));

    // OR together the input mask with the mask register value so we aren't checking any FIRs
    // that are currently masked in hardware
    io_fir_error = fir_with_mask_helper(l_reg_data, (i_mask | l_mask_data));

    FAPI_INF_NO_SBE(TARGTIDFORMAT " %s on reg 0x%016lx value 0x%016lx and mask value 0x%016lx", TARGTID,
                    io_fir_error ? "has FIR's set" : "has no FIR's set",
                    i_fir_addr, l_reg_data, (i_mask | l_mask_data));

    // Exit if we have found a FIR
    if(io_fir_error)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:

    return fapi2::current_err;
}


} // end check ns
} // end mss ns
#endif
