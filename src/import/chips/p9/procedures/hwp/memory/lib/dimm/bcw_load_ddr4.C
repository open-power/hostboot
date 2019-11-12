/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/bcw_load_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <lib/shared/mss_const.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <lib/eff_config/timing.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/dimm/bcw_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <generic/memory/lib/spd/spd_utils.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// TK:LRDIMM Update and/or verify bcw load

///
/// @brief Perform the bcw_load_ddr4 operations
/// @param[in] i_target a DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode bcw_load_ddr4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t >& io_inst)
{
    FAPI_INF("bcw_load_ddr4 %s", mss::c_str(i_target) );

    uint8_t l_sim = 0;
    uint64_t l_tDLLK = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Per DDR4BC01
    FAPI_TRY( tdllk(i_target, l_tDLLK), "Failed to get tDLLK for %s in bcw_load_ddr4", mss::c_str(i_target) );

    {

        // This initialization may be vendor specific.  We might need a different
        // sequence for Montage vs. IDT for example.
        // We'll know better once we initialize more than one...

        //
        // IDT BCW init
        //

        static const std::vector< cw_info > l_bcw_info =
        {
            // function space #, bcw #, attribute accessor, timing delay
            // We set the 4-bit buffer control words first (they live in function space 0
            // hw is supposed to default to function space 0 but Just.In.Case.
            { FUNC_SPACE_0,  FUNC_SPACE_SELECT_CW,  FUNC_SPACE_0,        mss::tmrd() , CW8_DATA_LEN, cw_info::BCW},

            // 4-bit BCW's from here
            { FUNC_SPACE_0,  DQ_RTT_NOM_CW,         eff_dimm_ddr4_bc00,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  DQ_RTT_WR_CW,          eff_dimm_ddr4_bc01,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  DQ_RTT_PARK_CW,        eff_dimm_ddr4_bc02,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  DQ_DRIVER_CW,          eff_dimm_ddr4_bc03,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  MDQ_RTT_CW,            eff_dimm_ddr4_bc04,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  MDQ_DRIVER_CW,         eff_dimm_ddr4_bc05,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  CMD_SPACE_CW,          eff_dimm_ddr4_bc06,  BCW_SAFE_DELAY , CW4_DATA_LEN, cw_info::BCW}, // using tmrd_l2 causes an error - safe delay works
            { FUNC_SPACE_0,  RANK_PRESENCE_CW,      eff_dimm_ddr4_bc07,  BCW_SAFE_DELAY , CW4_DATA_LEN, cw_info::BCW}, // using tmrd_l2 causes an error - safe delay works
            { FUNC_SPACE_0,  RANK_SELECTION_CW,     eff_dimm_ddr4_bc08,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  POWER_SAVING_CW,       eff_dimm_ddr4_bc09,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  OPERATING_SPEED,       eff_dimm_ddr4_bc0a,  l_tDLLK     , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  VOLT_AND_SLEW_RATE_CW, eff_dimm_ddr4_bc0b,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  BUFF_TRAIN_MODE_CW,    eff_dimm_ddr4_bc0c,  mss::tmrd_l2() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  LDQ_OPERATION_CW,      eff_dimm_ddr4_bc0d,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  PARITY_CW,             eff_dimm_ddr4_bc0e,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0,  ERROR_STATUS_CW,       eff_dimm_ddr4_bc0f,  mss::tmrc() , CW4_DATA_LEN, cw_info::BCW},

            // 8-bit BCW's now
            // Function space 0 - we're already there, so that's nice
            { FUNC_SPACE_0,  BUFF_CONFIG_CW,        eff_dimm_ddr4_f0bc1x, mss::tmrd_l2() , CW8_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_0, LRDIMM_OPERATING_SPEED, eff_dimm_ddr4_f0bc6x, BCW_SAFE_DELAY, CW8_DATA_LEN, cw_info::BCW},

            // Function space 2
            { FUNC_SPACE_2,  FUNC_SPACE_SELECT_CW,  FUNC_SPACE_2,         mss::tmrd(), CW8_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_2, HOST_DFE,               eff_dimm_ddr4_f2bcex, mss::tmrc(), CW8_DATA_LEN, cw_info::BCW},

            // Function space 5
            { FUNC_SPACE_5, FUNC_SPACE_SELECT_CW,   FUNC_SPACE_5,         mss::tmrd(), CW8_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_5, HOST_VREF_CW,           eff_dimm_ddr4_f5bc5x, BCW_SAFE_DELAY, CW8_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_5, DRAM_VREF_CW,           eff_dimm_ddr4_f5bc6x, BCW_SAFE_DELAY, CW8_DATA_LEN, cw_info::BCW},

            // Function space 6
            { FUNC_SPACE_6,  FUNC_SPACE_SELECT_CW,  FUNC_SPACE_6,         mss::tmrd(), CW8_DATA_LEN, cw_info::BCW},
            { FUNC_SPACE_6, BUFF_TRAIN_CONFIG_CW,   eff_dimm_ddr4_f6bc4x, mss::tmrc(), CW8_DATA_LEN, cw_info::BCW},


            // So, we always want to know what function space we're in
            // The way to do that is to always return to one function space
            // The LR spec recommends that we return to the default function space - function space 0
            // If the vector is not at our default function space of function space 0, return to function space 0
            { FUNC_SPACE_0,  FUNC_SPACE_SELECT_CW,  FUNC_SPACE_0,         mss::tmrd(), CW8_DATA_LEN, cw_info::BCW},
        };

        // DES first - make sure those CKE go high and stay there
        io_inst.push_back(mss::ccs::des_command());

        // Issues the CW's
        FAPI_TRY( control_word_engine(i_target, l_bcw_info, l_sim, io_inst),
                  "%s Failed control_word_engine", mss::c_str(i_target) );

        // Now, hold the CKE's high, so we don't power down the RCD and re power it back up
        mss::ccs::workarounds::hold_cke_high(io_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
