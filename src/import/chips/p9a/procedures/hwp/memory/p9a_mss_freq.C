/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_mss_freq.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9a_mss_freq.C
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <p9a_mss_freq.H>
#include <generic/memory/lib/data_engine/p9a/p9a_data_init_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/spd_facade.H>

///
/// @brief Calculate and save off DIMM frequencies
/// @param[in] i_target port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_mss_freq( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    // We will first set pre-eff_config attribes
    for(const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        std::vector<uint8_t> l_raw_spd;
        FAPI_TRY(mss::spd::get_raw_data(d, l_raw_spd));
        {
            // Gets the SPD facade
            fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
            mss::spd::facade l_spd_decoder(d, l_raw_spd, l_rc);

            // Checks that the facade was setup correctly
            FAPI_TRY( l_rc, "Failed to initialize SPD facade for %s", mss::spd::c_str(d) );

            FAPI_TRY( mss::attr_eff_engine<mss::pre_data_init_fields>::set(l_spd_decoder) );
        }

        // TK - Remove hard-code FREQ -- Should we have enums? Louis problem now
        uint64_t HARDCODE_FREQ_LOUIS_REMOVE = 25600;
        FAPI_TRY( mss::attr::set_freq(i_target, HARDCODE_FREQ_LOUIS_REMOVE) );
    }// dimm

fapi_try_exit:
    return fapi2::current_err;
}
