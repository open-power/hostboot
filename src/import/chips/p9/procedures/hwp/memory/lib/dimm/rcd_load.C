/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/rcd_load.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file rcd_load.C
/// @brief Run and manage the RCD_LOAD engine
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/rcd_load.H>
#include <lib/dimm/rcd_load_ddr4.H>
#include <lib/utils/nimbus_find.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{
///
/// @brief Perform the rcd_load operations - TARGET_TYPE_MCA specialization
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rcd_load<TARGET_TYPE_MCA>( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    const auto& l_mcbist = mss::find_target<TARGET_TYPE_MCBIST>(i_target);

    // A vector of CCS instructions. We'll ask the targets to fill it, and then we'll execute it
    ccs::program l_program;

    uint8_t l_sim = 0;
    // Clear the initial delays. This will force the CCS engine to recompute the delay based on the
    // instructions in the CCS instruction vector
    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    FAPI_TRY(mss::is_simulation(l_sim));

    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        // CKE needs to be LOW before running the RCW sequence
        // So we use the power down entry command to achieve this
        if(!l_sim)
        {
            l_program.iv_instructions.push_back( ccs::pde_command() );
        }

        FAPI_DBG("rcd load for %s", mss::c_str(d));
        FAPI_TRY( perform_rcd_load(d, l_program.iv_instructions),
                  "Failed perform_rcd_load() for %s", mss::c_str(d) );
    }// dimms

    // We have to configure the CCS engine to let it know which port these instructions are
    // going out (or whether it's broadcast ...) so lets execute the instructions we presently
    // have so that we kind of do this by port
    FAPI_TRY( ccs::execute(l_mcbist, l_program, i_target),
              "Failed to execute ccs for %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the rcd_load operations - TARGET_TYPE_MCBIST specialization
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCBIST>
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rcd_load<TARGET_TYPE_MCBIST>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    for ( const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target) )
    {
        FAPI_TRY( rcd_load(p) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the rcd_load operations - unknown DIMM case
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to (unused)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_rcd_load<DEFAULT_KIND>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& i_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type) );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen) );

    // If we're here, we have a problem. The DIMM kind (type and/or generation) wasn't known
    // to our dispatcher. We have a DIMM plugged in we don't know how to deal with.
    FAPI_ASSERT(false,
                fapi2::MSS_UNKNOWN_DIMM()
                .set_DIMM_TYPE(l_type)
                .set_DRAM_GEN(l_gen)
                .set_DIMM_IN_ERROR(i_target),
                "Unable to perform rcd load on %s: unknown type (%d) or generation (%d)",
                mss::c_str(i_target), l_type, l_gen);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the rcd_load operations - RDIMM DDR4
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_rcd_load<KIND_RDIMM_DDR4>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& i_inst)
{
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    FAPI_DBG("perform rcd_load for %s [expecting rdimm (ddr4)]", mss::c_str(i_target));
    FAPI_TRY( rcd_load_ddr4(i_target, l_sim, i_inst),
              "Failed rcd_load_ddr4() for %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the rcd_load operations - LRDIMM DDR4
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_rcd_load<KIND_LRDIMM_DDR4>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& i_inst)
{
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    FAPI_DBG("perform rcd_load for %s [expecting lrdimm (ddr4)]", mss::c_str(i_target));
    FAPI_TRY( rcd_load_ddr4(i_target, l_sim, i_inst) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform the rcd_load operations - start the dispatcher
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_rcd_load<FORCE_DISPATCH>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& i_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type) );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen) );

    return perform_rcd_load_dispatch<FORCE_DISPATCH>(dimm_kind( l_type, l_gen ), i_target, i_inst);

fapi_try_exit:
    FAPI_ERR("couldn't get dimm type, dram gen: %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Helper function to bring CKE high and hold for 400 cycles
/// @param[in] i_target MCA target on which to operate
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode draminit_cke_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{

    auto l_des = mss::ccs::des_command();
    mss::ccs::program l_program;

    // Also a Deselect command must be registered as required from the Spec.
    // Register DES instruction, which pulls CKE high. Idle 400 cycles, and then begin RCD loading
    // Note: This only is sent to one of the MCA as we still have the mux_addr_sel bit set, meaning
    // we'll PDE/DES all DIMM at the same time.
    l_des.arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(400);
    l_program.iv_instructions.push_back(l_des);

    FAPI_TRY( mss::ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                                l_program,
                                i_target),
              "%s Failed execute in p9_mss_draminit",
              mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
