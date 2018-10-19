/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file lib/phy/mss_lrdimm_training.C
/// @brief LRDIMM training implementation
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/phy/mss_lrdimm_training.H>
#include <lib/phy/mss_training.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/workarounds/ccs_workarounds.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Issues initial pattern write to all ranks in the rank pair
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rp the rank pair on which to operate
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_all_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint32_t i_pattern)
{
    std::vector<uint64_t> l_ranks;

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in mrep::run %s",
              mss::c_str(i_target) );

    // Loops over all ranks within this rank pair
    for (const auto l_rank : l_ranks)
    {
        FAPI_TRY(mpr_pattern_wr_rank(i_target, l_rank, i_pattern));
    };

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Issues initial pattern write a specific rank
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rank the rank to setup for initial pattern write
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_rank(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rank,
                                      const uint32_t i_pattern)
{
    // Skip over invalid ranks (NO_RANK)
    if(i_rank == NO_RANK)
    {
        FAPI_DBG("%s NO_RANK was passed in %u. Skipping", mss::c_str(i_target), i_rank)
        return fapi2::FAPI2_RC_SUCCESS;
    }

    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // The below code expects us to have ranks in terms of the DIMM values, so index 'em
    const auto l_rank = mss::index(i_rank);

    // Gets the DIMM target
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm),
             "%s failed to get DIMM target for rank %u", mss::c_str(i_target), i_rank);

    // Ok, MPR write
    // We need to
    // 1) MRS into MPR mode
    // 2) Disable address inversion, so we set our values correctly
    //    We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    // 3) Write the patterns in according to the bank address
    // 4) Restore the default address inversion
    // 5) MRS out of MPR mode

    // 1) MRS into MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // 2) Disable address inversion
    // We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    FAPI_TRY(disable_address_inversion(l_dimm, l_program.iv_instructions));

    // 3) Write the patterns in according to the bank address
    FAPI_TRY(add_mpr_pattern_writes(l_dimm,
                                    l_rank,
                                    i_pattern,
                                    l_program.iv_instructions));

    // 4) Restore the default address inversion
    FAPI_TRY(restore_address_inversion(l_dimm, l_program.iv_instructions));

    // 5) MRS out of MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrep::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const uint64_t i_rp,
                             const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrep::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rp,
                                 const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrep::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dwl::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t dwl::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrd::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrd::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrd::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                            const uint64_t i_rp,
                            const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Executes a cal step with workarounds
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mwd::execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint8_t i_abort_on_error ) const
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mwd::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type, const bool i_sim, fapi2::buffer<uint32_t>& io_cal_steps)
{
    // If the DIMM type is an LRDIMM, configure for LRDIMM
    if(i_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
    {
        FAPI_INF("LRDIMM: deconfigure WR VREF 2D");
        // We clear WRITE_CTR_2D_VREF as the HW calibration algorithm will not work with LRDIMM
        io_cal_steps.clearBit<WRITE_CTR_2D_VREF>();
        return;
    }

    FAPI_INF("Not LRDIMM: deconfigure all LRDIMM specific steps");
    // Otherwise, clear all LRDIMM calibration steps
    io_cal_steps.clearBit<DB_ZQCAL>()
    .clearBit<MREP>()
    .clearBit<MRD_COARSE>()
    .clearBit<MRD_FINE>()
    .clearBit<DWL>()
    .clearBit<MWD_COARSE>()
    .clearBit<MWD_FINE>()
    .clearBit<HWL>();
}


} // ns lrdimm

} // ns training

} // ns mss
