/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_volt.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <p9_mss_volt.H>

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/spd/spd_factory.H>
#include <lib/spd/common/spd_decoder.H>
#include <lib/eff_config/attr_setters.H>
#include <c_str.H>
#include <lib/utils/pos.H>
#include <lib/utils/find.H>
#include <lib/utils/checker.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{

    ///
    /// @brief Calculate and save off rail voltages
    /// @param[in] i_targets vector of controllers (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_volt( const std::vector< fapi2::Target<TARGET_TYPE_MCS> >& i_targets )
    {
        // Loop through MCS
        for (const auto& l_mcs : i_targets)
        {
            FAPI_INF("Populating decoder cache for %s", mss::c_str(l_mcs));

            //Factory cache is per MCS
            std::vector< std::shared_ptr<mss::spd::decoder> > l_factory_caches;
            FAPI_TRY( mss::spd::populate_decoder_caches(l_mcs, l_factory_caches),
                      "Failed to populate decoder cache for %s", l_mcs);

            // Get dimms for each MCS
            for ( const auto& l_cache : l_factory_caches )
            {
                uint8_t l_dimm_nominal = 0;
                uint8_t l_dimm_endurant = 0;

                // Read nominal and endurant bits from SPD, 0 = 1.2V is not operable and endurant, 1 = 1.2 is valid
                FAPI_TRY( l_cache->operable_nominal_voltage(l_dimm_nominal) );
                FAPI_TRY( l_cache->endurant_nominal_voltage(l_dimm_endurant) );

                //Check to make sure 1.2 V is both operable and endurant, fail if it is not
                FAPI_ASSERT ( (l_dimm_nominal == mss::spd::OPERABLE) && (l_dimm_endurant == mss::spd::ENDURANT),
                              fapi2::MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                              set_OPERABLE(l_dimm_nominal).
                              set_ENDURANT(l_dimm_endurant).
                              set_DIMM_TARGET(l_cache->iv_target),
                              "%s: DIMM is not operable (%d)"
                              " and/or endurant (%d) at 1.2V",
                              mss::c_str(l_cache->iv_target),
                              l_dimm_nominal,
                              l_dimm_endurant);
            } // l_dimm

            // Set the attributes for this MCS, values are in mss_const.H
            // TK : will need to change attribute target according to voltage rails in the future
            FAPI_TRY (mss::set_voltage_attributes (l_mcs,
                                                   mss::DDR4_NOMINAL_VOLTAGE,
                                                   mss::DDR4_VPP_VOLTAGE),
                      "Failed to set volt attributes");
        } // mcs

        FAPI_INF("End mss volt");
        return FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    } // p9_mss_volt
} //extern "C"
