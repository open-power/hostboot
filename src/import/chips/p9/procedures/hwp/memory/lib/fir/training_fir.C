/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/training_fir.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file training_fir.C
/// @brief Subroutines for training FIR
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>
#include <lib/utils/find.H>
#include <lib/fir/training_fir.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

///
/// @brief Unmask and setup actions for training related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode unmask_training_errors( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    // TK complete with all the actions and other FIR when we get there.
    FAPI_INF("unmask_training_errors");

    // All we presently do here is clear the ALERT_N FIR as it's not
    // reliable until after the RCD has been configured (so before training)

    // Fill our buffer with F's as we're going to clear the bits we want to
    // unmask and then drop the result in to the _AND register.
    fapi2::buffer<uint64_t> l_trainingfir_mask(~0);

    l_trainingfir_mask.clearBit<MCA_MBACALFIRQ_RCD_PARITY_ERROR>();

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        FAPI_TRY( mss::putScom(p, MCA_MBACALFIRQ_AND, l_trainingfir_mask) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
