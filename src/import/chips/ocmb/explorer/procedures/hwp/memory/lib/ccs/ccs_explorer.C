/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/ccs_explorer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file ccs_explorer.C
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/exp_defaults.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/ccs/ccs_explorer.H>
#include <lib/utils/mss_exp_conversions.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>

// Generates linkage
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::EXPLORER>::CS_N[];
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::EXPLORER>::CS_ND[];

namespace mss
{
namespace ccs
{

///
/// @brief Configures the chip to properly execute CCS instructions - EXPLORER specialization
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode setup_to_execute<mss::mc_type::EXPLORER>(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        // Disables low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));

        l_data.setBit<EXPLR_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from a CCS execution - multiple ports - EXPLORER specialization
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode cleanup_from_execute<mss::mc_type::EXPLORER>
(const ccs::program& i_program,
 const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        // Re-enable low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));

        l_data.clearBit<EXPLR_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type
/// @param[in] i_target OCMB target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template<>
fapi2::ReturnCode fail_type( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const uint64_t i_type,
                             const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port )
{
    typedef ccsTraits<mss::mc_type::EXPLORER> TT;

    // Including the PORT_TARGET here and below at CAL_TIMEOUT since these problems likely lie at the MCA level
    // So we disable the PORT and hopefully that's it
    // If the problem lies with the MCBIST, it'll just have to loop
    FAPI_ASSERT(TT::STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_EXP_CCS_READ_MISCOMPARE()
                .set_MC_TARGET(i_target)
                .set_FAIL_TYPE(i_type)
                .set_PORT_TARGET(i_port),
                "%s CCS FAIL Read Miscompare", mss::c_str(i_port));

    // This error is likely due to a bad CCS engine/ MCBIST
    FAPI_ASSERT(TT::STAT_UE_SUE != i_type,
                fapi2::MSS_EXP_CCS_UE_SUE()
                .set_FAIL_TYPE(i_type)
                .set_MC_TARGET(i_target),
                "%s CCS FAIL UE or SUE Error", mss::c_str(i_target));

    // Problem with the CCS engine
    FAPI_ASSERT(TT::STAT_HUNG != i_type,
                fapi2::MSS_EXP_CCS_HUNG().set_MC_TARGET(i_target),
                "%s CCS appears hung", mss::c_str(i_target));
fapi_try_exit:
    // Due to the PRD update, we need to check for FIR's
    // If any FIR's have lit up, this CCS fail could have been caused by the FIR
    // So, let PRD retrigger this step to see if we can resolve the issue
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::CCS>(i_target, fapi2::current_err);
}

///
/// @brief EXP specialization for modeq_copy_cke_to_spare_cke
/// @param[in] fapi2::Target<TARGET_TYPE_OCMB_CHIP>& the target to effect
/// @param[in,out] the buffer representing the mode register
/// @param[in] mss::states - mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
///
template<>
void copy_cke_to_spare_cke<fapi2::TARGET_TYPE_OCMB_CHIP>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::buffer<uint64_t>&, states )
{
    return;
}

///
/// @brief Updates the initial delays based upon the total delays passed in - EXP specialization
/// @param[in] i_target the target type on which to operate
/// @param[in] i_delay the calculated delays from CCS
/// @param[in,out] io_program the program for which to update the delays
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode update_initial_delays<fapi2::TARGET_TYPE_OCMB_CHIP, mss::mc_type::EXPLORER>
( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
  const uint64_t i_delay,
  ccs::program& io_program)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Check our program for any delays. If there isn't a iv_initial_delay configured, then
    // we use the delay we just summed from the instructions.
    if (io_program.iv_poll.iv_initial_delay == 0)
    {
        io_program.iv_poll.iv_initial_delay = cycles_to_ns(i_target, i_delay, l_rc);
        FAPI_TRY(l_rc, "%s cycles_to_ns failed", mss::c_str(i_target));
    }

    if (io_program.iv_poll.iv_initial_sim_delay == 0)
    {
        io_program.iv_poll.iv_initial_sim_delay = cycles_to_simcycles(i_delay);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Select the port(s) to be used by the CCS - EXPLORER specialization
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
///
template<>
fapi2::ReturnCode select_ports<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint64_t i_ports)
{
    // No broadcast mode, only one port, so no port selection
    return fapi2::FAPI2_RC_SUCCESS;
}

} // namespace ccs
} // namespace mss
