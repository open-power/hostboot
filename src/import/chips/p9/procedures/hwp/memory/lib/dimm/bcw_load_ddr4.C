/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/bcw_load_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file bcw_load_ddr4.C
/// @brief Run and manage the DDR4 bcw loading
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <lib/utils/c_str.H>
#include <lib/utils/conversions.H>
#include <lib/eff_config/timing.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/bcw_load_ddr4.H>
#include <lib/dimm/bcw_load.H>
#include <lib/mss_attribute_accessors.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief Perform the bcw_load_ddr4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode bcw_load_ddr4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("bcw_load_ddr4 %s", mss::c_str(i_target) );

    // Per DDR4BC01
    uint64_t l_tDLLK = 0;
    FAPI_TRY( tdllk(i_target, l_tDLLK), "Failed to get tdllk for %s", mss::c_str(i_target) );

    {
        static const std::vector< bcw_data > l_bcw_4bit_data =
        {
            // function space #, bcw #, attribute accessor, timing delay
            {  0, 0, eff_dimm_ddr4_bc00, mss::tmrc()   },
            {  0, 1, eff_dimm_ddr4_bc01, mss::tmrc()   },
            {  0, 2, eff_dimm_ddr4_bc02, mss::tmrc()   },
            {  0, 3, eff_dimm_ddr4_bc03, mss::tmrc()   },
            {  0, 4, eff_dimm_ddr4_bc04, mss::tmrc()   },
            {  0, 5, eff_dimm_ddr4_bc05, mss::tmrc()   },
            {  0, 7, eff_dimm_ddr4_bc07, mss::tmrc()   },
            {  0, 9, eff_dimm_ddr4_bc09, mss::tmrc()   },
            {  0, 8, eff_dimm_ddr4_bc08, mss::tmrc()   },
            {  0, 10, eff_dimm_ddr4_bc0a, l_tDLLK      },
            {  0, 11, eff_dimm_ddr4_bc0b, mss::tmrc()  },
            {  0, 12, eff_dimm_ddr4_bc0c, mss::tmrc()  },
            {  0, 13, eff_dimm_ddr4_bc0d, mss::tmrc()  },
            {  0, 14, eff_dimm_ddr4_bc0e, mss::tmrc()  },
            {  0, 15, eff_dimm_ddr4_bc0f, mss::tmrc()  },
        };

        // This initialization may be vendor specific.  We might need a different
        // sequence for Montage vs. IDT for example.
        // We'll know better once we initialize more than one...

        //
        // IDT BCW init
        //

        // We set the 4-bit buffer control words first (they live in function space 0
        // hw is supposed to default to function space 0 but Just.In.Case.
        FAPI_TRY( function_space_select<0>(i_target, io_inst) );
        FAPI_TRY( bcw_engine<BCW_4BIT>(i_target, l_bcw_4bit_data, io_inst) );

        // We set our 8-bit buffer control words but switch function space
        // for control words that live in a different one
        // (feels a little on the light side...)
        FAPI_TRY( function_space_select<6>(i_target, io_inst) );
        FAPI_TRY( bcw_engine<BCW_8BIT>(i_target,
                                       bcw_data(6, 4, eff_dimm_ddr4_f6bc4x, mss::tmrc()),
                                       io_inst) );

        FAPI_TRY( function_space_select<5>(i_target, io_inst) );
        FAPI_TRY( bcw_engine<BCW_8BIT>(i_target,
                                       bcw_data(5, 6, eff_dimm_ddr4_f5bc6x, mss::tmrc()),
                                       io_inst) );

        // Its recommended to always return to the function space
        // "pointer" back to 0 so we always know where we are starting from
        FAPI_TRY( function_space_select<0>(i_target, io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
