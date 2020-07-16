/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_fir_workarounds.C $ */
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
/// @file p10_fir_workarounds.C
/// @brief Workarounds for p10 fir workaround
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <cstdarg>
#include <fapi2.H>
#include <p10_scom_mcc_b.H>
#include <lib/shared/p10_consts.H>
#include <lib/fir/p10_fir_traits.H>
#include <lib/workarounds/p10_fir_workarounds.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the DD1 workaround for HW511630 and HW520480
/// @param[in] i_target the MCC target of the DSTL fir
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dstl_dd1_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target )
{
    fapi2::buffer<uint64_t> l_mask_or = 0;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW> l_mcc_dstlfir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "unable to create fir::reg for DSTL_DSTLFIR_RW 0x%08X", scomt::mcc::DSTL_DSTLFIR_RW);

    // Write DSTLFIR register per defect workaround
    l_rc = l_mcc_dstlfir_reg
           .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
           .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
           .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
           .masked<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
           .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION>()
           .local_checkstop<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION>()
           .write();

    FAPI_TRY(l_rc, "unable to write to dstlfir for target %s", mss::c_str(i_target));

    // Set the mask_or reg to remask firs
    l_mask_or.setBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>();
    l_mask_or.setBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>();
    l_mask_or.setBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>();
    l_mask_or.setBit<scomt::mcc::DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>();
    FAPI_TRY( mss::putScom(i_target, scomt::mcc::DSTL_DSTLFIRMASK_WO_OR, l_mask_or) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace fir
} // namespace workarounds
} // namespace mss
