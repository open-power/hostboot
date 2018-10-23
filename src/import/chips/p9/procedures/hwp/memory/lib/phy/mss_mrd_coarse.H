/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_mrd_coarse.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

        mrd_coarse() :
            step("MRD_COARSE")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        virtual ~mrd_coarse() = default;

        ///
        /// @class mrd_coarse::recorder
        /// @brief Records the results for a given nibble
        ///
        struct recorder
        {
            static constexpr uint64_t CLEAN = 0;

            ///
            /// @brief Default constructor
            ///
            recorder() :
                iv_results(0),
                iv_final_delay(2), // 2 is for 0 delay
                iv_invalid_data_count(CLEAN)
            {}

            ///
            /// @brief constructor
            ///
            recorder(const fapi2::buffer<uint8_t> i_results, const uint8_t i_final_delay, const uint64_t i_invalid_count = CLEAN) :
                iv_results(i_results),
                iv_final_delay(i_final_delay),
                iv_invalid_data_count(i_invalid_count)
            {}

            // Records a given bit per nibble per delay
            // 1 = compare
            // 0 = miscompare
            // Fun thing is the LRDIMM spec sends out 1's for compares, so no enums needed
            fapi2::buffer<uint8_t> iv_results;
            uint8_t iv_final_delay;
            uint64_t iv_invalid_data_count;

            ///
            /// @brief Adds results to the recorder
            /// @param[in] i_delay the current delay
            /// @param[in] i_result the result for the current nibble - right aligned
            /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
            ///
            fapi2::ReturnCode add_results(const uint8_t i_delay, const uint8_t i_result)
            {
                bool l_passed = false;

                // 0 is not passed
                if(i_result == 0x00)
                {
                    l_passed = false;
                }

                // F is passed
                else if(i_result == 0x0f)
                {
                    l_passed = true;
                }

                // Anything else is an error case just call it not passed for now
                // TK RAS
                else
                {
                    l_passed = false;
                    FAPI_ERR("delay%u has a bad result of 0x%02x", i_delay, i_result);
                }

                FAPI_TRY(iv_results.writeBit(l_passed, i_delay));

            fapi_try_exit:
                return fapi2::current_err;
            }

            ///
            /// @brief Finds the final result for the whole buffer
            /// @param[in] i_target the DIMM target for the data
            /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
            /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
            ///
            fapi2::ReturnCode find_final_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               const uint64_t i_dimm_rank)
            {
                // uint8_t() is to make the bit count compile as it's expecting an integral type
                // buffers don't count as an integral type as they're classes
                const uint8_t l_results(iv_results);

                // If we never find a passing region, just log an error and set a 2
                if(iv_results == 0)
                {
                    iv_final_delay = 2;
                    FAPI_ERR("%s rank%u found no passing regions setting to an offset of 0 data:0x%02x", mss::c_str(i_target), i_dimm_rank,
                             iv_results);
                    return fapi2::FAPI2_RC_SUCCESS;
                }

                // Otherwise, find our first passing region
                // We should really only have 1, so let's log an error if that's not the case
                if(bit_count(l_results) > 1)
                {
                    FAPI_ERR("%s rank%u found more than one passing region data:0x%02x", mss::c_str(i_target), i_dimm_rank, iv_results);
                }

                iv_final_delay = first_bit_set(l_results);

                return fapi2::FAPI2_RC_SUCCESS;
            }
        };

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
            return (i_dimm_rank % 2) ? FUNC_SPACE_1 : FUNC_SPACE_0;
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
            return (i_dimm_rank < 2) ? 0x0c : 0x0e;
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
                                          std::vector<std::pair<recorder, recorder>>& io_results) const;

        ///
        /// @brief Finds the final results for the whole DIMM rank
        /// @param[in] i_target the DIMM target
        /// @param[in] i_dimm_rank the DIMM rank on which to set the delay
        /// @param[in,out] io_results the results
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode find_final_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint64_t i_dimm_rank,
                                             std::vector<std::pair<recorder, recorder>>& io_results) const;

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
                const std::vector<std::pair<recorder, recorder>>& i_results,
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
                                           const std::vector<std::pair<recorder, recorder>>& i_results) const;

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
