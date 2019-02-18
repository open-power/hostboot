/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_mrd_coarse.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file lib/phy/mss_mrd_coarse.H
/// @brief MRD coarse LRDIMM training step
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_MRD_COARSE_H
#define MSS_MRD_COARSE_H

#include <lib/phy/mss_training.H>
#include <lib/phy/mss_lrdimm_training_helper.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @class mrd_coarse
/// @brief MRD coarse adjustment training step
///
class mrd_coarse : public step
{
    public:
        // From the LRDIMM spec - we only have 5 delays -2->+2
        static constexpr uint64_t NUM_DELAYS = 5;

        static constexpr uint64_t RANKS_PER_FUNCTION_SPACE = 2;
        mrd_coarse() :
            step("MRD_COARSE")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        virtual ~mrd_coarse() = default;

        ///
        /// @brief Converts the indexed delay to the BCW value
        /// @param[in] i_delay_index the indexed delay to set
        /// @return the BCW value for the inputted delay
        ///
        inline uint8_t convert_delay_to_bcw(const uint8_t i_delay_index) const
        {
            // Ok so the delay goes from a -2 all the way up to a +2
            // We made this to be 0->4
            // The spec states that the delays take up 3 bits
            // They are converted as follows
            // Real value -> BCW value
            //         -2 -> 0b110 (6)
            //         -1 -> 0b101 (5)
            //          0 -> 0b000 (0)
            //         +1 -> 0b001 (1)
            //         +2 -> 0b010 (2)
            // So the formula is broken up into two parts
            // 1) negative delay: 6 - index
            // 2) positive delay: index - 2
            constexpr uint8_t NEGATIVE_POS = 6;
            constexpr uint8_t ZERO_INDEX   = 2;
            return (i_delay_index < ZERO_INDEX) ?
                   (NEGATIVE_POS - i_delay_index) :
                   (i_delay_index - ZERO_INDEX);
        }

        ///
        /// @brief Converts the rank to the function space
        /// @param[in] i_dimm_rank the DIMM rank to convert
        /// @return the function space from the DIMM rank
        ///
        inline uint8_t generate_func_space(const uint64_t i_dimm_rank) const
        {
            // So, odd ranks are on function space 0
            // Even ranks are on function space 1
            // Just mod it by 2...
            return (i_dimm_rank % RANKS_PER_FUNCTION_SPACE) ? FUNC_SPACE_1 : FUNC_SPACE_0;
        }

        ///
        /// @brief Converts the rank to the BCW number
        /// @param[in] i_dimm_rank the DIMM rank to convert
        /// @return the BCW number from the DIMM rank
        ///
        inline uint8_t generate_bcw_number(const uint64_t i_dimm_rank) const
        {
            // The spec says that ranks 0/1 share a BCW number and that 2/3 share a BCW number
            // Taken from the spec ~page 60->64
            // Ranks 0/1: 0x0c
            // Ranks 2/3: 0x0e
            constexpr uint8_t RANK01 = 0x0c;
            constexpr uint8_t RANK23 = 0x0e;
            return (i_dimm_rank < RANKS_PER_FUNCTION_SPACE) ? RANK01 : RANK23;
        }

        ///
        /// @brief Sets the delay for a given rank
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in] i_delay the indexed delay to set
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        /// @note Sets up buffer control word F6BC4x to do compares on a per-nibble level
        ///
        fapi2::ReturnCode set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint64_t i_dimm_rank,
                                    const uint8_t i_delay) const;

        ///
        /// @brief Analyzes the results for a given run
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in] i_delay the delay for this run
        /// @param[in,out] io_results the results
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode analyze_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                          const uint64_t i_dimm_rank,
                                          const uint8_t i_delay,
                                          std::vector<std::pair<coarse_recorder, coarse_recorder>>& io_results) const;

        ///
        /// @brief Creates the nibble flags for the invalid data callout
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @param[out] o_invalid_count number of invalid data occurances seen
        /// @return invalid data nibble flags
        /// @note Invalid data is defined as not having all zeros or all ones
        ///
        uint32_t flag_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_rank,
                                    const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders,
                                    uint64_t& o_invalid_count) const;

        ///
        /// @brief Calls out if invalid data is seen during this calibration step
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Invalid data is defined as not having all zeros or all ones
        ///
        fapi2::ReturnCode callout_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                const uint8_t i_rank,
                                                const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const;

        ///
        /// @brief Creates the nibble flags for the not one passing region callout
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return passing region nibble flags
        ///
        uint32_t flag_not_one_passing_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                              const uint8_t i_rank,
                                              const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const;

        ///
        /// @brief Calls out if a rank found not one passing region
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode callout_not_one_passing_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_recorders) const;

        ///
        /// @brief Finds the final results for the whole DIMM rank, and callsout
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in,out] io_results the results
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode find_final_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint64_t i_dimm_rank,
                                             std::vector<std::pair<coarse_recorder, coarse_recorder>>& io_results) const;

        ///
        /// @brief Sets the final delays for a DIMM/rank target
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in] i_results the results
        /// @param[out] o_container the PBA commands structure
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_final_delays_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint64_t i_dimm_rank,
                const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_results,
                mss::ddr4::pba::commands& o_container) const;

        ///
        /// @brief Sets the final delays for a DIMM/rank target
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in] i_results the results
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_final_delays(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           const uint64_t i_dimm_rank,
                                           const std::vector<std::pair<coarse_recorder, coarse_recorder>>& i_results) const;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const;

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
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;
};

} // ns lrdimm

} // ns training

} // ns mss

#endif
