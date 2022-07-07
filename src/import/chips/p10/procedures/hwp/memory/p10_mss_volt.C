/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_volt.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_mss_volt.C
/// @brief Calculate and save off rail voltages
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <p10_mss_volt.H>

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/voltage/gen_mss_volt.H>
#include <generic/memory/mss_git_data_helper.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <lib/eff_config/p10_common_engine.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/count_dimm.H>
///
/// @brief Calculate and save off rail voltages
/// @param[in] i_targets vector of ports (e.g., MEM_PORT)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_mss_volt( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_targets )
{
    mss::display_git_commit_info("p10_mss_volt");

    for (const auto& l_port : i_targets)
    {
        const auto& l_dimm_count = mss::count_dimm(l_port);

        if(!l_dimm_count)
        {
            FAPI_INF("p10_mss_volt: No valid dimm found for target: %s", mss::c_str(l_port));
            continue;
        }

        // setup_voltage_rail_values called based on DRAM generation.
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
        {
            std::vector<uint8_t> l_spd;
            uint8_t l_dram_gen;
            FAPI_TRY(mss::spd_common_process(l_dimm, l_spd));
            FAPI_TRY(mss::attr::get_dram_gen(l_dimm, l_dram_gen));

            switch(l_dram_gen)
            {
                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4:
                    FAPI_TRY( (mss::setup_voltage_rail_values<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4>(l_dimm, l_spd)),
                              "%s Failed setup_voltage_rail_values", mss::c_str(l_port) );
                    break;

                case fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5:
                    FAPI_TRY( (mss::setup_voltage_rail_values<mss::mc_type::ODYSSEY, mss::spd::device_type::DDR5>(l_dimm, l_spd)),
                              "%s Failed setup_voltage_rail_values", mss::c_str(l_port) );
                    break;

                default :
                    FAPI_ASSERT(false,
                                fapi2::MSS_VOLT_INVALID_DRAM_GEN().
                                set_DRAM_GEN(l_dram_gen).
                                set_PORT_TARGET(l_port),
                                "Invalid DRAM generation (%d) in p10_mss_volt. target: %s",
                                l_dram_gen,
                                mss::c_str(l_port));
            }
        }
    } // port

    FAPI_INF("End mss volt");

fapi_try_exit:
    return fapi2::current_err;
} // p10_mss_volt
