/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/nimbus_kind.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file nimbus_kind.C
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Amita Banchhor <Amita.Banchhor@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <lib/shared/nimbus_defaults.H>
#include <lib/utils/nimbus_find.H>
#include <lib/workarounds/mcbist_workarounds.H>
#include <lib/dimm/nimbus_kind.H>

namespace mss
{

namespace dimm
{

///
/// @brief Check if any dimms exist that have RCD enabled - nimbus/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    uint8_t l_dimm_type = 0;

    FAPI_TRY(mss::eff_dimm_type(i_target, l_dimm_type));

    // Set RCD if we have an RDIMM or LRDIMM type
    o_has_rcd = ((l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM) ||
                 (l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM));

fapi_try_exit:

    return fapi2::current_err;
}

}// end dimm ns
}// end mss ns
