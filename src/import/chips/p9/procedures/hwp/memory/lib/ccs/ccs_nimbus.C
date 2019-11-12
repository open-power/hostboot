/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ccs/ccs_nimbus.C $ */
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
/// @file ccs_nimbus.C
/// @brief Run and manage the CCS engine
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
#include <lib/fir/check.H>
#include <lib/phy/mss_lrdimm_training.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/ccs/ccs_nimbus.H>

#ifdef LRDIMM_CAPABLE
    #include <lib/workarounds/quad_encode_workarounds.H>
#endif

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::FAPI2_RC_SUCCESS;

// Generates linkage
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::NIMBUS>::CS_N[];
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::NIMBUS>::CS_ND[];

namespace mss
{
namespace ccs
{

///
/// @brief Select the port(s) to be used by the CCS - EXPLORER specialization
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
///
template<>
fapi2::ReturnCode select_ports<mss::mc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        uint64_t i_ports)
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_ports;

    // Not handling multiple ports here, can't do that for CCS. BRS
    FAPI_TRY( l_ports.setBit(i_ports) );

    FAPI_TRY( mss::getScom(i_target, TT::MCB_CNTL_REG, l_data) );
    l_data.insert<TT::MCB_CNTL_PORT_SEL, TT::MCB_CNTL_PORT_SEL_LEN>(l_ports);
    FAPI_TRY( mss::putScom(i_target, TT::MCB_CNTL_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions - multiple ports - NIMBUS specialization
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode cleanup_from_execute<fapi2::TARGET_TYPE_MCA, mss::mc_type::NIMBUS>(const ccs::program& i_program,
        const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >& i_ports)
{
#if LRDIMM_CAPABLE

    if(mss::workarounds::contains_command_mrs(i_program.iv_instructions))
    {
        // Get ranks in pair bombs out if we can't get any ranks in this pair, so we should be safe here
        for (const auto& p : i_ports)
        {
            FAPI_TRY(mss::workarounds::fix_shadow_register_corruption(p));
        }
    }

fapi_try_exit:
    return fapi2::current_err;

#else
    return fapi2::FAPI2_RC_SUCCESS;

#endif
}

///
/// @brief Determine the CCS failure type
/// @param[in] i_target MCBIST target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template<>
fapi2::ReturnCode fail_type( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                             const uint64_t i_type,
                             const fapi2::Target<TARGET_TYPE_MCA>& i_port )
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;

    fapi2::ReturnCode l_failing_rc(fapi2::FAPI2_RC_SUCCESS);
    // Including the MCA_TARGET here and below at CAL_TIMEOUT since these problems likely lie at the MCA level
    // So we disable the PORT and hopefully that's it
    // If the problem lies with the MCBIST, it'll just have to loop
    FAPI_ASSERT(TT::STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_NIMBUS_CCS_READ_MISCOMPARE()
                .set_MCBIST_TARGET(i_target)
                .set_FAIL_TYPE(i_type)
                .set_MCA_TARGET(i_port),
                "%s CCS FAIL Read Miscompare", mss::c_str(i_port));

    // This error is likely due to a bad CCS engine/ MCBIST
    FAPI_ASSERT(TT::STAT_UE_SUE != i_type,
                fapi2::MSS_NIMBUS_CCS_UE_SUE()
                .set_FAIL_TYPE(i_type)
                .set_MCBIST_TARGET(i_target),
                "%s CCS FAIL UE or SUE Error", mss::c_str(i_target));

    FAPI_ASSERT(TT::STAT_CAL_TIMEOUT != i_type,
                fapi2::MSS_NIMBUS_CCS_CAL_TIMEOUT()
                .set_FAIL_TYPE(i_type)
                .set_MCBIST_TARGET(i_target)
                .set_MCA_TARGET(i_port),
                "%s CCS FAIL Calibration Operation Time Out", mss::c_str(i_port));

    // Problem with the CCS engine
    FAPI_ASSERT(TT::STAT_HUNG != i_type,
                fapi2::MSS_NIMBUS_CCS_HUNG().set_MCBIST_TARGET(i_target),
                "%s CCS appears hung", mss::c_str(i_target));
fapi_try_exit:
    // Due to the PRD update, we need to check for FIR's
    // If any FIR's have lit up, this CCS fail could have been caused by the FIR
    // So, let PRD retrigger this step to see if we can resolve the issue
    return mss::check::fir_or_pll_fail<mss::mc_type::NIMBUS, mss::check::firChecklist::GENERIC>(i_target,
            fapi2::current_err);
}

///
/// @brief Create, initialize an instruction which indicates an initial cal
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_rp the rank-pair (rank) to cal
/// @return the initial cal instruction
///
instruction_t initial_cal_command(const uint64_t i_rp)
{
    using TT = ccsTraits<mss::mc_type::NIMBUS>;

    // An initial cal arr0 looks just like a DES, but we set the initial cal bits
    instruction_t l_inst = des_command();

    // ACT is low - per Centaur spec (Shelton to confirm for Nimbus) BRS
    l_inst.arr0.template clearBit<TT::ARR0_DDR_ACTN>();

    l_inst.arr0.template insertFromRight<TT::ARR0_DDR_CAL_TYPE, TT::ARR0_DDR_CAL_TYPE_LEN>(0b1100);
    l_inst.arr1.template setBit<TT::ARR1_DDR_CALIBRATION_ENABLE>();

#ifdef USE_LOTS_OF_IDLES
    // Idles is 0xFFFF - per Centaur spec (Shelton to confirm for Nimbus) BRS
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(0xFFFF);
#else
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(0x0);
#endif

    // The rank we're calibrating is enacoded - it's an int. So rank 3 is 0011 not 0001
    l_inst.arr1.template insertFromRight<TT::ARR1_DDR_CAL_RANK, TT::ARR1_DDR_CAL_RANK_LEN>(i_rp);

    return l_inst;
}

///
/// @brief Nimbus specialization for modeq_copy_cke_to_spare_cke
/// @param[in] fapi2::Target<TARGET_TYPE_MCBIST>& the target to effect
/// @param[in,out] the buffer representing the mode register
/// @param[in] mss::states - mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
///
template<>
void copy_cke_to_spare_cke<TARGET_TYPE_MCBIST>( const fapi2::Target<TARGET_TYPE_MCBIST>&,
        fapi2::buffer<uint64_t>&, states )
{
    return;
}

///
/// @brief Updates the initial delays based upon the total delays passed in - Nimbus specialization
/// @param[in] i_target the target type on which to operate
/// @param[in] i_delay the calculated delays from CCS
/// @param[in,out] io_program the program for which to update the delays
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode update_initial_delays<fapi2::TARGET_TYPE_MCBIST, mss::mc_type::NIMBUS>
( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
  const uint64_t i_delay,
  ccs::program& io_program)
{
    // Check our program for any delays. If there isn't a iv_initial_delay configured, then
    // we use the delay we just summed from the instructions.
    if (io_program.iv_poll.iv_initial_delay == 0)
    {
        io_program.iv_poll.iv_initial_delay = cycles_to_ns(i_target, i_delay);
    }

    if (io_program.iv_poll.iv_initial_sim_delay == 0)
    {
        io_program.iv_poll.iv_initial_sim_delay = cycles_to_simcycles(i_delay);
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

} // namespace ccs
} // namespace mss
