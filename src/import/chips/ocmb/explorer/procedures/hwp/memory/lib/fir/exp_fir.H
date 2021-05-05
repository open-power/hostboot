/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_fir.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_fir.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_FIR_H_
#define _MSS_EXP_FIR_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace check
{

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
        bool& o_fir_error);

} // end check ns
} // end mss ns
#endif
