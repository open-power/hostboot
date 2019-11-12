/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/mrs_load_nimbus.C $ */
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
/// @file mrs_load_nimbus.C
/// @brief Run and manage the MRS_LOAD engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/workarounds/ccs_workarounds.H>

namespace mss
{
///
/// @brief Perform the mrs_load operations - fapi2::TARGET_TYPE_MCA specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_MCA>
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const bool i_nvdimm_workaround )
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // A vector of CCS instructions. We'll ask the targets to fill it, and then we'll execute it
    ccs::program l_program;

    // Clear the initial delays. This will force the CCS engine to recompute the delay based on the
    // instructions in the CCS instruction vector
    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    for ( const auto& d : find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_DBG("mrs load for %s", mss::c_str(d));

        // TK - break out the nvdimm stuff into function
        if (i_nvdimm_workaround)
        {
            FAPI_DBG("nvdimm workaround detected. loading mrs for restore sequence");
            FAPI_TRY( ddr4::mrs_load_nvdimm(d, l_program.iv_instructions) );
        }
        else
        {
            FAPI_TRY( perform_mrs_load(d, l_program.iv_instructions) );
        }
    }

    // We have to configure the CCS engine to let it know which port these instructions are
    // going out (or whether it's broadcast ...) so lets execute the instructions we presently
    // have so that we kind of do this by port
    // Run the NVDIMM-specific execute procedure if this is for nvdimm workaround.
    // Otherwise, execute as usual.
    if (i_nvdimm_workaround)
    {
        FAPI_TRY( mss::ccs::workarounds::nvdimm::execute(l_mcbist, l_program, i_target), "Failed ccs execute %s",
                  mss::c_str(i_target) );
    }
    else
    {
        FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target), "Failed ccs execute %s", mss::c_str(i_target) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the mrs_load operations - fapi2::TARGET_TYPE_MCBIST specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_MCBIST>
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                            const bool i_nvdimm_workaround )
{
    for ( const auto& p : find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        FAPI_TRY( mrs_load(p) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the mrs_load operations - unknown DIMM case
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to (unused)
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_mrs_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type) );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen) );

    // If we're here, we have a problem. The DIMM kind (type and/or generation) wasn't know
    // to our dispatcher. We have a DIMM plugged in we don't know how to deal with.
    FAPI_ASSERT(false,
                fapi2::MSS_UNKNOWN_DIMM()
                .set_DIMM_TYPE(l_type)
                .set_DRAM_GEN(l_gen)
                .set_DIMM_IN_ERROR(i_target),
                "Unable to perform mrs load on %s: unknown type (%d) or generation (%d)",
                mss::c_str(i_target), l_type, l_gen);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the mrs_load operations - RDIMM DDR4
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_mrs_load<KIND_RDIMM_DDR4>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    FAPI_DBG("perform mrs_load for %s [expecting rdimm (ddr4)]", mss::c_str(i_target));
    FAPI_TRY( ddr4::mrs_load(i_target, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the mrs_load operations - LRDIMM DDR4
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_mrs_load<KIND_LRDIMM_DDR4>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    FAPI_DBG("perform mrs_load for %s [expecting lrdimm (ddr4)]", mss::c_str(i_target));
    FAPI_TRY( ddr4::mrs_load(i_target, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform the mrs_load operations - start the dispatcher
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return fapi2::FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_mrs_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    FAPI_TRY( mss::eff_dimm_type(i_target, l_type) );
    FAPI_TRY( mss::eff_dram_gen(i_target, l_gen) );

    return perform_mrs_load_dispatch<FORCE_DISPATCH>(dimm_kind( l_type, l_gen ), i_target, io_inst);

fapi_try_exit:
    FAPI_ERR("couldn't get dimm type, dram gen: %s", mss::c_str(i_target));
    return fapi2::current_err;
}

} // namespace
