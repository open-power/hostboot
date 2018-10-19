/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.H $ */
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
/// @file lib/phy/mss_lrdimm_training.H
/// @brief High level LRDIMM training
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_LRDIMM_TRAINING_H
#define MSS_LRDIMM_TRAINING_H

#include <lib/phy/mss_training.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/dimm/ddr4/data_buffer_ddr4.H>
#include <lib/phy/seq.H>
#include <generic/memory/lib/utils/buffer_ops.H>

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
        const uint32_t i_pattern);

///
/// @brief Adds all write commands for the passed in pattern
/// @tparam fapi2::TargetType T target type for the CCS instruction
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_rank the DIMM rank to set the MPR on
/// @param[in] i_pattern the pattern to write into the MPRS
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode add_mpr_pattern_writes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_pattern,
        std::vector<mss::ccs::instruction_t<T>>& io_insts)
{

    constexpr uint64_t NUM_MPR_PATTERNS = 4;
    constexpr uint64_t MPR_WR_BG = 0;
    // First, swizzle the pattern
    fapi2::buffer<uint32_t> l_swizzled_pattern;
    FAPI_TRY(mss::seq::swizzle_mpr_pattern(i_pattern, l_swizzled_pattern),
             "%s rank%u failed to swizzle pattern", mss::c_str(i_target), i_rank);

    // Now add in writes with the appropriate data involved + the good old swizzle that we do based upon the ranks
    // Swizzle is required as we want the expected data for mirrored and non-mirrored ranks to be the same
    // For MPR writes the expected data is carried by the addresses, so mirroring matters

    // Loop through all MPR patterns and generate writes for 'em
    // The MPR number is defined by the bank address
    for(uint8_t l_ba = 0; l_ba < NUM_MPR_PATTERNS; ++l_ba)
    {
        constexpr uint64_t ADDR_START = 54;
        constexpr uint64_t PATTERN_LEN = 8;
        constexpr uint64_t MPR_WR_SAFE_DELAY = 0xff;
        uint64_t l_pattern = 0;
        FAPI_TRY(l_swizzled_pattern.extract(l_pattern, l_ba * PATTERN_LEN, PATTERN_LEN, ADDR_START), "%s ba%u",
                 mss::c_str(i_target), l_ba);
        {
            auto l_wr = mss::ccs::wr_command<fapi2::TARGET_TYPE_MCBIST>( i_target,
                        i_rank,
                        l_ba,
                        MPR_WR_BG,
                        l_pattern);
            // Swaps the bank addresses so they're a true to the BA we tried to pass in above
            swap<BA0, BA1>(l_wr.arr0);

            l_wr.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(MPR_WR_SAFE_DELAY);
            FAPI_TRY(address_mirror(i_target, i_rank, l_wr));
            io_insts.push_back(l_wr);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Helper function to disable address inversion
/// @tparam fapi2::TargetType T target type for the CCS instruction
/// @param[in] i_target DIMM target on which to operate
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode disable_address_inversion(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector<mss::ccs::instruction_t<T>>& io_insts)
{
    // Declares the default control word that handles address inversion
    // Data of 0 as we're going to override it below
    constexpr uint64_t CW_INVERSION = 0;
    // uint64_t(0) is to avoid compile errors from overloaded functions
    cw_data l_cw(FUNC_SPACE_0, CW_INVERSION, static_cast<uint64_t>(0), mss::tmrd());
    constexpr uint64_t CKE_HIGH = mss::ON;

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Gets default values
    FAPI_TRY(eff_dimm_ddr4_rc00(i_target, l_cw.iv_data));

    // Modifies inversion
    set_address_inversion(l_cw, mss::states::OFF_N);

    // Creates the CCS instructions
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_cw, l_sim, io_insts, CKE_HIGH),
              "Failed to generate control words for %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to restore default address inversion
/// @tparam fapi2::TargetType T target type for the CCS instruction
/// @param[in] i_target DIMM target on which to operate
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode restore_address_inversion(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector<mss::ccs::instruction_t<T>>& io_insts)
{
    // Declares the default control word that handles address inversion
    // Data of 0 as we're going to override it below
    constexpr uint64_t CW_INVERSION = 0;
    cw_data l_cw(FUNC_SPACE_0, CW_INVERSION, eff_dimm_ddr4_rc00, mss::tmrd());
    constexpr uint64_t CKE_HIGH = mss::ON;

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Creates the CCS instructions
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_cw, l_sim, io_insts, CKE_HIGH),
              "Failed to generate control words for %s", mss::c_str(i_target));

fapi_try_exit:
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
                                      const uint32_t i_pattern);

// TK:LRDIMM Do we need separate coarse vs fine steps?
///
/// @brief MREP training step
///
class mrep : public step
{
    public:
        mrep() :
            step("MREP")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        ~mrep() = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;
};

///
/// @brief DWL training step
///
class dwl : public step
{
    public:
        dwl() :
            step("DWL")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        ~dwl() = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;
};

///
/// @brief MPR training step
///
class mrd : public step
{
    public:
        mrd() :
            step("MRD")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        ~mrd() = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;
};

///
/// @brief MPR training step
///
class mwd : public step
{
    public:
        mwd() :
            step("MWD")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        ~mwd() = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;
};

// TK:LRDIMM Identify if Host Interface Write Leveling (HWL) Mode needs to be updated or if the PHY can handle it
// TK:LRDIMM Identify if Host Interface Read Training is any different
// TK:LRDIMM Identify if Host Interface Write training Training is any different

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type, const bool i_sim, fapi2::buffer<uint32_t>& io_cal_steps);

} // ns training

} // ns lrdimm

} // ns mss

#endif
