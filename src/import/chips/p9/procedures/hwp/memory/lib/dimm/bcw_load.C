/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/bcw_load.C $ */
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
/// @file rcd_load.C
/// @brief Run and manage the RCD_LOAD engine
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/bcw_load.H>
#include <lib/dimm/bcw_load_ddr4.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief Perform the bcw_load operations - TARGET_TYPE_MCBIST specialization
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode bcw_load<TARGET_TYPE_MCBIST>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    // A vector of CCS instructions. We'll ask the targets to fill it, and then we'll execute it
    ccs::program<TARGET_TYPE_MCBIST> l_program;

    // Clear the initial delays. This will force the CCS engine to recompute the delay based on the
    // instructions in the CCS instruction vector
    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        for (const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(p))
        {
            FAPI_DBG("bcw load for %s", mss::c_str(d));
            FAPI_TRY( perform_bcw_load(d, l_program.iv_instructions), "Failed BCW load %s", mss::c_str(d) );
        }

        // We have to configure the CCS engine to let it know which port these instructions are
        // going out (or whether it's broadcast ...) so lets execute the instructions we presently
        // have so that we kind of do this by port
        FAPI_TRY( ccs::execute(i_target, l_program, p), "Failed executing ccs engine load %s", mss::c_str(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the bcw_load operations - unknown DIMM case
/// @param[in] i_target the DIMM target
/// @param[in] io_inst a vector of CCS instructions we should add to (unused)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<DEFAULT_KIND>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type), "Error in perform_bcw_load" );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen), "Error in perform_bcw_load" );

    // If we're here, we have a problem. The DIMM kind (type and/or generation) wasn't known
    // to our dispatcher. We have a DIMM plugged in we don't know how to deal with.
    FAPI_ASSERT(false,
                fapi2::MSS_UNKNOWN_DIMM()
                .set_DIMM_TYPE(l_type)
                .set_DRAM_GEN(l_gen)
                .set_DIMM_IN_ERROR(i_target),
                "Unable to perform bcw load on %s: unknown type (%d) or generation (%d)",
                mss::c_str(i_target), l_type, l_gen);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the bcw_load operations - LRDIMM DDR4
/// @param[in] i_target the DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<KIND_LRDIMM_DDR4>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_DBG("perform bcw_load for %s [expecting lrdimm (ddr4)]", mss::c_str(i_target));
    FAPI_TRY( bcw_load_ddr4(i_target, io_inst), "Failed bcw load for lrdimm %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the bcw_load operations - RDIMM DDR4
/// @param[in] i_target the DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<KIND_RDIMM_DDR4>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("Skipping BCW loading for %s since this is valid only for LRDIMMs", mss::c_str(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Perform the bcw_load operations - start the dispatcher
/// @param[in] i_target the DIMM target
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<FORCE_DISPATCH>( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type), "Error in perform_bcw_load" );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen), "Error in perform_bcw_load" );

    return perform_bcw_load_dispatch<FORCE_DISPATCH>(dimm_kind( l_type, l_gen ), i_target, io_inst);

fapi_try_exit:
    FAPI_ERR("Couldn't get DIMM type, DRAM gen: %s", mss::c_str(i_target));
    return fapi2::current_err;
}

} // namespace
