/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_enable_ecc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_enable_ecc.C
/// @brief Enable ECC checking
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#include <fapi2.H>
#include <ody_enable_ecc.H>
#include <lib/mc/ody_port_traits.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>

extern "C"
{
    ///
    /// @brief Enable ECC checking
    /// @param[in] i_target OCMB chip
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_enable_ecc(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_INF(TARGTIDFORMAT " ody_enable_ecc: Entering...", TARGTID);

        // Enable ecc checking
        FAPI_TRY( mss::enable_read_ecc<mss::mc_type::ODYSSEY>(i_target), TARGTIDFORMAT "Failed enable_read_ecc", TARGTID );

        FAPI_INF(TARGTIDFORMAT " ody_enable_ecc: Exiting...", TARGTID);

    fapi_try_exit:
        return fapi2::current_err;
    }

}
