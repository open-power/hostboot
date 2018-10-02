/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_volt.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file p9_mss_volt.C
/// @brief Calculate and save off rail voltages
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin  <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <p9_mss_volt.H>

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/voltage/gen_mss_volt.H>

using fapi2::TARGET_TYPE_MCS;

extern "C"
{

    ///
    /// @brief Calculate and save off rail voltages
    /// @param[in] i_targets vector of controllers (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_volt( const std::vector< fapi2::Target<TARGET_TYPE_MCS> >& i_targets )
    {
        for (const auto& l_mcs : i_targets)
        {
            FAPI_TRY( (mss::setup_voltage_rail_values<mss::mc_type::NIMBUS, mss::spd::device_type::DDR4>(l_mcs)),
                      "Failed setup_voltage_rail_values for %s", mss::c_str(l_mcs) );
        } // mcs

        FAPI_INF("End mss volt");

    fapi_try_exit:
        return fapi2::current_err;
    } // p9_mss_volt
} //extern "C"
