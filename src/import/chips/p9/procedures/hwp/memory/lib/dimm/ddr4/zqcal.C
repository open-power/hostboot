/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/zqcal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file zqcal.C
/// @brief Subroutines to send ZQCL commands
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <vector>
#include <fapi2.H>

#include <lib/dimm/ddr4/zqcal.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/ccs/ccs.H>
#include <lib/eff_config/timing.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

///
/// @brief Setup DRAM ZQCL
/// Specializaton for TARGET_TYPE_DIMM
/// @param[in] i_target the target associated with this cal
/// @param[in] i_rank the current rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode setup_dram_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_rank,
                                    std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    ccs::instruction_t<TARGET_TYPE_MCBIST> l_inst;

    uint64_t tDLLK = 0;
    FAPI_TRY( mss::tdllk(i_target, tDLLK) );

    // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
    l_inst = ccs::zqcl_command<TARGET_TYPE_MCBIST>(i_target, i_rank);

    l_inst.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(tDLLK + mss::tzqinit());

    // There's nothing to decode here.
    FAPI_INF("ZQCL 0x%016llx:0x%016llx %s:rank %d",
             l_inst.arr0, l_inst.arr1, mss::c_str(i_target), i_rank);

    // Add both to the CCS program
    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup LRDIMM data buffer ZQCL
/// Specializaton for TARGET_TYPE_DIMM
/// @param[in] i_target the target associated with this cal
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode setup_data_buffer_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // For LRDIMMs, program BCW to send ZQCal Long command to all data buffers
    // in broadcast mode
    uint8_t l_dimm_type = 0;
    FAPI_TRY( eff_dimm_type(i_target, l_dimm_type) );

    if( l_dimm_type != fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM )
    {
        FAPI_INF("%s Skipping LRDIMM data buffer ZQCL, only done on LRDIMMs", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( ddr4::set_command_space(i_target, ddr4::command::ZQCL, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup and execute DRAM ZQCL
/// Specializaton for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this cal
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode setup_and_execute_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled)
{
    mss::ccs::program<TARGET_TYPE_MCBIST> l_program;

    for ( const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        // If this bit isn't set, nothing to do here...
        if ( i_cal_steps_enabled.getBit<DRAM_ZQCAL>() )
        {
            std::vector<uint64_t> l_ranks;
            FAPI_TRY( mss::rank::ranks(d, l_ranks) );

            for( const auto& r : l_ranks)
            {
                FAPI_TRY( mss::setup_dram_zqcal(d, r, l_program.iv_instructions) );
            }// ranks
        }

        // If this bit isn't set, nothing to do here...
        if ( i_cal_steps_enabled.getBit<DB_ZQCAL>() )
        {
            FAPI_TRY( mss::setup_data_buffer_zqcal(d, l_program.iv_instructions) );
        }
    }// dimm

    // execute ZQCAL instructions
    FAPI_TRY( mss::ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_program, i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
