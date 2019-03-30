/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training_helper.H $ */
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
/// @file lib/phy/mss_lrdimm_training_helper.H
/// @brief Common helper functions for LRDIMM training
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_LRDIMM_TRAINING_HELPER_H
#define MSS_LRDIMM_TRAINING_HELPER_H

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>
#include <lib/phy/seq.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <lib/mcbist/mcbist.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/fir/fir.H>

//
// Note: The LRDIMM support has NOT been characterized or qualified by IBM
// LRDIMM development was done in conjunction with an OpenPower partner and is being released to all of OpenPower
// As IBM has not characterized or qualified LRDIMM, IBM will not be able to offer technical expertise to debug any LRDIMM side issues
// As such, the OpenPower partner using LRDIMM assumes ownership and associated risk for using LRDIMM's in their system
// Additionally, LRDIMM will see a large IPL time increase compared to RDIMM, as all of the LRDIMM training has to be enabled in software
//

namespace mss
{

namespace training
{

namespace lrdimm
{

static constexpr uint8_t MREP_DWL_MAX_DELAY = 64;
static constexpr uint8_t MREP_DWL_LOOP_TIMES = 0x05;
static constexpr uint8_t MREP_DWL_THRESHOLD = 0x05;
static constexpr uint8_t RANK_PRESENCE_BIT = 1;
static constexpr uint8_t RANK_PRESENCE_MASK = 0xf;

///
/// @brief Records the results for a given nibble
///
struct mrep_dwl_recorder
{
    static constexpr uint64_t CLEAN = 0;
    ///
    /// @brief Default constructor
    ///
    mrep_dwl_recorder() :
        iv_seen0(false),
        iv_seen1(false),
        iv_delay(0),
        iv_invalid_data_count(CLEAN)
    {}

    ///
    /// @brief constructor
    ///
    mrep_dwl_recorder(const bool i_seen0, const bool i_seen1, const uint8_t i_delay,
                      const uint64_t i_invalid_count = CLEAN) :
        iv_seen0(i_seen0),
        iv_seen1(i_seen1),
        iv_delay(i_delay),
        iv_invalid_data_count(i_invalid_count)
    {}

    bool iv_seen0;
    bool iv_seen1;
    uint8_t iv_delay;
    uint64_t iv_invalid_data_count;
};

class mrep_dwl_result
{
    public:

        //Noise can create issues for finding the correct 0->1 transition
        //Therefore,we repeat the MREP algorithm multiple times and filter out bad transitions
        std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> iv_results;

        ///
        /// @brief save result for each buffer and each delay
        /// @param[in] i_target the DIMM target
        /// @param[in] i_calibration the current calibration step - used for error logging
        /// @param[in] i_buffer - buffer number
        /// @param[in] i_delay - delay value
        /// @param[in] i_nibble0_result - nibble0's result
        /// @param[in] i_nibble1_result - nibble1's result
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode add_results(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const uint64_t i_calibration,
                                      const uint8_t i_buffer,
                                      const uint8_t i_delay,
                                      const bool i_nibble0_result,
                                      const bool i_nibble1_result)
        {
            FAPI_ASSERT(i_buffer < MAX_LRDIMM_BUFFERS,
                        fapi2::MSS_INVALID_INDEX_PASSED()
                        .set_INDEX(i_buffer)
                        .set_TARGET(i_target)
                        .set_FUNCTION((i_calibration == mss::cal_steps::MREP) ? MREP_CALL_OUT : DWL_CALL_OUT),
                        "%s Invalid buffer index passed to mrep_dwl_result::add_results(%d)",
                        mss::c_str(i_target), i_buffer);

            {
                // Const here refers to the iterator, so we only get the iterator for our individual bit and cannot change to a different bit
                const auto l_it = iv_results.begin() + i_buffer;
                FAPI_TRY(l_it->first.writeBit(i_nibble0_result, i_delay));
                FAPI_TRY(l_it->second.writeBit(i_nibble1_result,  i_delay));
            }

        fapi_try_exit :
            return fapi2::current_err;
        }

        ///
        /// @brief Default constructor
        ///
        mrep_dwl_result()
        {
            iv_results = std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> (MAX_LRDIMM_BUFFERS);
        }


};

///
/// @class coarse_recorder
/// @brief Records results on a per-nibble level for coarse calibration algorithms
/// @note Each vector's array position represents one nibble
/// @note Each bit in an element represents whether the data compared or mis-compared at that delay
/// @note Coarse calibration algorithms refer to sub-cycle calibration algorithms (MRD_COARSE and MWD_COARSE)
///
struct coarse_recorder
{
    public:
        static constexpr uint64_t CLEAN = 0;

        // Default delay value 2 is for 0 nck
        static constexpr uint8_t DEFAULT_DELAYS = 2;
        static constexpr uint8_t DEFAULT_TO_PASS = 0xF8;
        static constexpr uint8_t PASSING_RESULT = 0x0f;
        static constexpr uint8_t FAILING_RESULT = 0x00;

        ///
        /// @brief Default constructor
        ///
        coarse_recorder() :
            iv_results(DEFAULT_TO_PASS),
            iv_final_delay(DEFAULT_DELAYS),
            iv_invalid_data_count(CLEAN)
        {}

        ///
        /// @brief constructor
        /// @param[in] i_results results from the COARSE run
        /// @param[in] i_final final delay chosen by the COARSE run
        /// @param[in] i_invalid_count invalid data count from COARSE run
        ///
        coarse_recorder(const fapi2::buffer<uint8_t> i_results, const uint8_t i_final_delay,
                        const uint64_t i_invalid_count = CLEAN) :
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
            if(i_result == FAILING_RESULT)
            {
                l_passed = false;
            }

            // F is passed - only if we had already passed at this location
            else if(i_result == PASSING_RESULT)
            {
                l_passed = iv_results.getBit(i_delay);
            }

            // Anything else is an error case
            else
            {
                l_passed = false;
                FAPI_DBG("delay%u has a invalid result of 0x%02x", i_delay, i_result);
                iv_invalid_data_count++;
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
/// @class fine_recorder
/// @brief Records results on a per-bit level for fine calibration algorithms
/// @note Each vector's array position represents one bit
/// @note Each bit in an element represents whether the data compared or mis-compared at that delay
/// @note Fine calibration algorithms refer to sub-cycle calibration algorithms (MRD_FINE and MWD_FINE)
///
class fine_recorder
{
    public:
        // Both MRD and MWD fine have the same maximum delay of 31
        enum
        {
            MAX_FINE_DELAY = 31
        };


        ///
        /// @brief Recorder default constructor
        ///
        fine_recorder()
        {
            iv_results = std::vector<fapi2::buffer<uint32_t>>(MAX_DQ_BITS);
        }

        ///
        /// @brief Default destructor
        ///
        ~fine_recorder() = default;

        ///
        /// @brief add results
        /// @tparam fapi2::TargetType T target type on which to operate
        /// @param[in] i_target target for error logging if needed
        /// @param[in] i_bit dq number
        /// @param[in] i_delay current calibration delay for which to set the result
        /// @param[in] i_result true if passing false if failing
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template<fapi2::TargetType T>
        fapi2::ReturnCode add_results(const fapi2::Target<T>& i_target,
                                      const uint64_t i_bit,
                                      const uint64_t i_delay,
                                      const bool i_result)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            // Ensure that the bit is within the range (programming error otherwise)
            FAPI_ASSERT(i_bit < MAX_DQ_BITS,
                        fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                        .set_TARGET(i_target)
                        .set_INDEX(i_bit)
                        .set_LIST_SIZE(MAX_DQ_BITS)
                        .set_FUNCTION(FINE_RECORDER_ADD_RESULTS),
                        "%s has DQ bit input (%u) out of bounds: %u",
                        mss::c_str(i_target), i_bit, MAX_DQ_BITS);

            // Ensure that the delay is in range
            // We check this as our delay does not fill up the full buffer
            // So we need to ensure we don't accidentally put results into non-existant delays
            FAPI_ASSERT(i_delay < MAX_FINE_DELAY,
                        fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                        .set_TARGET(i_target)
                        .set_INDEX(i_delay)
                        .set_LIST_SIZE(MAX_FINE_DELAY)
                        .set_FUNCTION(FINE_RECORDER_ADD_RESULTS),
                        "%s has delay input (%u) out of bounds: %u",
                        mss::c_str(i_target), i_delay, MAX_FINE_DELAY);

            {
                // Const here refers to the iterator, so we only get the iterator for our individual bit and cannot change to a different bit
                const auto l_it = iv_results.begin() + i_bit;
                FAPI_TRY(l_it->writeBit(i_result, i_delay));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Finds a vector of the passing eyes
        /// @tparam fapi2::TargetType T target type on which to operate
        /// @param[in] i_target target for error logging if needed
        /// @param[in] i_bit dq number
        /// @param[in] i_calibration the current calibration step - used for error logging
        /// @param[out] o_data raw data - used for debug prints
        /// @param[out] o_eyes vector of pairs - pair first is left edge pair second is right edge
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        template<fapi2::TargetType T>
        fapi2::ReturnCode find_eyes(const fapi2::Target<T>& i_target,
                                    const uint64_t i_calibration,
                                    const uint64_t i_bit,
                                    uint32_t& o_data,
                                    std::vector<std::pair<uint16_t, uint16_t>>& o_eyes) const
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            o_eyes.clear();

            // Ensure that the bit is within the range (programming error otherwise)
            FAPI_ASSERT(i_bit < MAX_DQ_BITS,
                        fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                        .set_TARGET(i_target)
                        .set_INDEX(i_bit)
                        .set_LIST_SIZE(MAX_DQ_BITS)
                        .set_FUNCTION(FINE_RECORDER_ADD_RESULTS),
                        "%s has DQ bit input (%u) out of bounds: %u in cal step %u",
                        mss::c_str(i_target), i_bit, MAX_DQ_BITS, i_calibration);

            {
                // Gets our current bit
                const auto l_it = iv_results.begin() + i_bit;
                o_data = *l_it;
                uint16_t l_left_edge = 0;
                uint16_t l_right_edge = 0;

                // Seen 0 can be set to true. We have two edge cases:
                // 1) We have a 0 at our edge - setting seen0 to true has no effect
                // 2) We have a 1 at our edge - we want to note that we have an "edge" at the 0th delay
                // The way we do that is by showing that we've seen a 0 then a 1, so setting to true is needed
                bool l_seen0 = true;
                bool l_seen1 = false;
                bool l_found_left_edge = false;
                bool l_found_right_edge = false;

                // Loops through all of the delays and assembles a vector of the eyes
                // The vector contains a pair and has the left and right edge noted
                for(uint16_t l_delay = 0; l_delay < MAX_FINE_DELAY; l_delay++)
                {
                    // We've found that we're at a 0 (miscompare)
                    if(l_it->getBit(l_delay) == false)
                    {
                        l_seen0 = true;

                        // We're at a 0 now, and if we've found a 1 prior (1->0) transition
                        // And have not found a right edge, so note that we've found a right edge and set the delay
                        if((l_seen1 == true) && (l_found_right_edge == false))
                        {
                            // Right edge is our current delay - 1
                            // This is the last time we saw a compare on the eye
                            l_right_edge = l_delay - 1;
                            l_found_right_edge = true;

                        }

                        l_seen1 = false;
                    }

                    // We've found that we're at a 1 (compare)
                    if(l_it->getBit(l_delay) == true)
                    {
                        l_seen1 = true;

                        // We're at a 1, have found a 0 prior (so 0->1 transition)
                        // and not have a left edge, so note that we've found a left edge and set the delay
                        if(l_seen0 == true && l_found_left_edge == false)
                        {
                            l_left_edge = l_delay;
                            l_found_left_edge = true;
                        }

                        l_seen0 = false;
                    }

                    // If we've found a left and a right edge, then we've found an eye, so note it as such
                    // We should always find our right edge after our first edge, set seen0 to true
                    if(l_found_left_edge && l_found_right_edge)
                    {
                        o_eyes.push_back({l_left_edge, l_right_edge});
                        l_found_left_edge = l_found_right_edge = false;
                        l_seen0 = true;
                        l_seen1 = false;
                    }
                }

                // If we have a case where we pass at the maximum delay
                // This means that we are in a passing eye but have not recorded the eye above
                // Our "edge" then becomes the right most delay as we want to note
                if(l_found_left_edge && !l_found_right_edge)
                {
                    o_eyes.push_back({l_left_edge, MAX_FINE_DELAY - 1});
                }
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief find eye size and delay value for one dq
        /// @param[in] i_delay_eyes left/right edges for each eye in the vector
        /// @param[out] o_delay mid point of eye
        /// @param[out] o_eye_size eye size
        ///
        void find_eye_size_and_delay(const std::vector<std::pair<uint16_t, uint16_t>>& i_delay_eyes,
                                     uint16_t& o_delay,
                                     uint16_t& o_eye_size) const
        {
            o_delay = 0;
            o_eye_size = 0;

            // Loops through and finds the best case eye
            for(const auto& l_delay_eye : i_delay_eyes)
            {
                // Our eye size is our right minus our left edge + 1 to account that our edges are passing
                const auto l_cur_eye_size = (l_delay_eye.second - l_delay_eye.first) + 1;

                if(o_eye_size < l_cur_eye_size)
                {
                    o_eye_size = l_cur_eye_size;

                    // Our setpoint for the eye is the average of our left and right edges
                    o_delay = (l_delay_eye.second + l_delay_eye.first) / 2;
                }
            }
        }

        ///
        /// @brief find eye size and delay value for one dq
        /// @tparam fapi2::TargetType T target type on which to operate
        /// @param[in] i_target target for error logging if needed
        /// @param[in] i_bit dq number
        /// @param[in] i_calibration the current calibration step - used for error logging
        /// @param[out] o_delay mid point of eye
        /// @param[out] o_eye_size eye size
        /// @param[out] o_no_pass_region if no pass region, true or false
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        template<fapi2::TargetType T>
        fapi2::ReturnCode find_eye_size_and_delay(const fapi2::Target<T>& i_target,
                const uint64_t i_calibration,
                const uint64_t i_bit,
                uint16_t& o_delay,
                uint16_t& o_eye_size,
                bool& o_no_pass_region) const
        {
            const char* CAL_STEP_PRINT = i_calibration == mss::cal_steps::MRD_FINE ? "MRD_FINE" : "MWD_FINE";
            o_delay = 0;
            o_eye_size = 0;
            o_no_pass_region = false;
            std::vector<std::pair<uint16_t, uint16_t>> l_delay_eyes;
            uint32_t l_data = 0;
            FAPI_TRY(find_eyes(i_target,
                               i_calibration,
                               i_bit,
                               l_data,
                               l_delay_eyes));

            find_eye_size_and_delay(l_delay_eyes, o_delay, o_eye_size);

            // Note: we just blindly return the eye sizes
            // The individual calibration steps will check and verify that we:
            // 1) saw at least one passing region
            // 2) saw a failing region

            if(l_delay_eyes.size() == 0)
            {
                o_no_pass_region = true;
            }

            if(o_eye_size == MAX_FINE_DELAY)
            {
                o_no_pass_region = true;
            }

            FAPI_DBG("%s %s bit%u found %u eyes. best case eye size%u with setpoint delay of %u from data 0x%08x",
                     mss::c_str(i_target), CAL_STEP_PRINT, i_bit, l_delay_eyes.size(), o_eye_size, o_delay, l_data);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief get the iv_results
        /// @return the vector of iv_results
        ///
        const std::vector<fapi2::buffer<uint32_t>>& get()const
        {
            return iv_results;
        }

        std::vector<fapi2::buffer<uint32_t>> iv_results;
};

///
/// @brief Enums for clean bitmap
///
enum errors : uint64_t
{
    CLEAN_BITMAP = 0,
};

///
/// @brief Appends a buffer's error callouts per-nibble onto the nibble bitmap
/// @param[in] i_nibble0 flag for nibble 0 - true is fail
/// @param[in] i_nibble1 flag for nibble 1 - true is fail
/// @param[in,out] io_bitmap bitmap to update
/// @note Bit flags are used for the nibbles to simplify the error callouts
/// We can callout one bitmap or 18 bits
///
inline void append_nibble_flags(const bool i_nibble0, const bool i_nibble1, uint32_t& io_bitmap)
{
    // Update the bitmap -
    // bit logic shifts the bits to the right then OR's in the given nibble
    // This forces nibble 0 to be the leftmost bit in the flag, while nibble 17 is the right most bit in the flag
    io_bitmap <<= 1;
    io_bitmap |= i_nibble0 ? 1 : 0;
    io_bitmap <<= 1;
    io_bitmap |= i_nibble1 ? 1 : 0;
}

///
/// @brief Appends a dq's error callouts per-dq onto the nibble bitmap
/// @param[in] i_dq flag for one dq - true is fail
/// @param[in,out] io_bitmap bitmap to update
/// @note Bit flags are used for the nibbles to simplify the error callouts
/// We can callout one bitmap
///
inline void append_dq_flags(const bool i_dq, uint8_t& io_bitmap)
{

    // Update the bitmap
    // bit logic shifts the bit to the left then OR's in the given dq
    // This forces dq 0 to be the leftmost bit in the flag(bit 3), while dq 3 is the right most bit in the flag

    io_bitmap <<= 1;
    io_bitmap |= i_dq ? 1 : 0;
}

///
/// @brief Appends a nibble's error callouts per-nibble (4 dq) onto the all dq bitmap
/// @param[in] i_nibble0 flag for nibble 0 - low 4 bit valid ,true is fail
/// @param[in] i_nibble1 flag for nibble 1 - low 4 bit valid ,true is fail
/// @param[in,out] io_bitmap bitmap to update
/// @note Bit flags are used for the dq to simplify the error callouts
/// We can callout one bitmap
///
inline void append_four_dq_flags(const uint8_t i_nibble0, const uint8_t i_nibble1, uint64_t& io_bitmap)
{
    constexpr uint8_t MAX_DQ_PER_BUFFER = 8;
    // Update the bitmap
    // bit logic shifts the 8 bits for one buffer to the left then OR's in the given nibble
    // This forces 8 dq of buffer 0 to be the leftmost bit in the flag, while 8 dq of buffer 7 is the right most bit in the flag
    io_bitmap <<= MAX_DQ_PER_BUFFER;
    io_bitmap |= (i_nibble1 & 0x0F) | ((i_nibble0 & 0x0F) << BITS_PER_NIBBLE);
}

///
/// @brief Enums for per-nibble or per-bit level for LRDIMM training
/// @note Values taken from the buffer spec
///
enum training_level : uint64_t
{
    NIBBLE = 0,
    BIT = 1,
};

///
/// @brief Get the results for loop
/// @param[in] i_target the DIMM target
/// @param[in] i_buffer the buffer to operate on
/// @param[in] i_nibble the nibble to operate on
/// @param[in] i_delay the delay value
/// @param[in] i_result_nibble the nibble result value to analyze
/// @param[in,out] io_invalid_data_count the invalid data count
/// @param[out] o_result_nibble_bool the bool result value
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode get_result_nibble_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_buffer,
        const uint8_t i_nibble,
        const uint8_t i_delay,
        const uint8_t i_result_nibble,
        uint64_t& io_invalid_data_count,
        bool& o_result_nibble_bool);

///
/// @brief Get the results for loop
/// @param[in] i_target the DIMM target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_delay the delay value
/// @param[in,out] io_loop_result the result for all delay
/// @param[in,out] io_results_recorder a vector of the DWL final results
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode get_result( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint64_t i_calibration,
                              const uint8_t i_delay,
                              mrep_dwl_result& io_loop_result,
                              std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& io_results_recorder);

///
/// @brief analyze with each nibble
/// @param[in] i_target the DIMM target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_result_nibble the result need to analyze
/// @param[in] i_buffer the buffer number
/// @param[in] i_nibble the nibble number
/// @param[in, out] io_recorder we need to get and record
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode analyze_result_for_each_nibble( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_calibration,
        const fapi2::buffer<uint64_t>& i_result_nibble,
        const uint8_t i_buffer,
        const uint8_t i_nibble,
        mrep_dwl_recorder& io_recorder ) ;

///
/// @brief smoothing the result
/// @param[in] i_loop_results the results of loop times
/// @param[in, out] io_filter_result the result after smoothing
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode smoothing(const std::vector<mrep_dwl_result>& i_loop_results,
                            mrep_dwl_result& io_final_result);

///
/// @brief analyze the result
/// @param[in] i_target the MCA target
/// @param[in] i_calibration the current calibration step - used for error logging
/// @param[in] i_loop_results the results of loop times
/// @param[in, out] io_recorders a vector of the results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode analyze_result( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_calibration,
                                  const std::vector<mrep_dwl_result>& i_loop_results,
                                  std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& io_recorders);

///
/// @brief Sets the comparison on a per-nibble or per-bit level
/// @param[in] i_target the DIMM target
/// @param[in] i_training_level the buffer's training level
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F6BC4x to do compares on a per-bit level
///
fapi2::ReturnCode set_training_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_training_level);

///
/// @brief Sets preamble mode enable or disable
/// @param[in] i_target the DIMM target
/// @param[in] i_mode preamble mode enable or disable
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F0BC1x to do preamble mode enable or disable
///
fapi2::ReturnCode set_buffer_rd_preamble_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_mode);

///
/// @brief Enter read preamble training mode
/// @param[in] i_target the DIMM target
/// @param[in] i_mode mode value 0/1
/// @param[in,out] io_inst the instruction to fixup
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets MR4 A10 for read preamble training mode
///
fapi2::ReturnCode set_dram_rd_preamble_mode_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_mode,
        const uint64_t i_rank,
        std::vector<ccs::instruction_t>& io_inst);

///
/// @brief Enter read preamble training mode
/// @param[in] i_target the DIMM target
/// @param[in] i_mode mode value 0/1
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets MR4 A10 for read preamble training mode
///
fapi2::ReturnCode set_dram_rd_preamble_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_mode,
        const uint64_t i_rank);

///
/// @brief Perform the bcw_load_ddr4 operations
/// @param[in] i_target a DIMM target
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode set_rank_presence( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_rank);

///
/// @brief Converts the rank to the final rank presence value
/// @param[in] i_dimm_rank the DIMM rank to convert
/// @return the final presence value for the dimm rank
///
inline uint8_t generate_rank_presence_value(const uint8_t i_dimm_rank)
{
    // The spec says that need to set BC07 to the final value according to dimm rank
    // one rank dimm  : 0x0e
    // Two rank dimm  : 0x0c
    // four rank dimm : 0x00
    constexpr uint8_t ONE_RANK = 0x01;
    constexpr uint8_t TWO_RANK = 0x02;
    constexpr uint8_t ONE_RANK_PRESENCE_VALUE = 0x0e;
    constexpr uint8_t TWO_RANK_PRESENCE_VALUE = 0x0c;
    constexpr uint8_t FOUR_RANK_PRESENCE_VALUE = 0x00;

    if (i_dimm_rank == ONE_RANK)
    {
        return ONE_RANK_PRESENCE_VALUE;
    }
    else if (i_dimm_rank == TWO_RANK)
    {
        return TWO_RANK_PRESENCE_VALUE;
    }
    else
    {
        return FOUR_RANK_PRESENCE_VALUE;
    }
}

///
/// @brief Creates the control words to set the expected MPR pattern into the buffer
/// @param[in] i_pattern the pattern to program into the buffer
/// @return cw_info vector containing the control words used to setup the MPR pattern into the buffer
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
std::vector<cw_info> set_expected_mpr_pattern(const fapi2::buffer<uint8_t>& i_pattern );

///
/// @brief Sets expected mpr pattern into the buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_pattern the pattern to program into the buffer
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
fapi2::ReturnCode set_expected_mpr_pattern(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const fapi2::buffer<uint8_t>& i_pattern );

///
/// @brief Generates rank presence for a specific rank
/// @param[in] i_rank the rank to generate rank presence
/// @return returns the rank presence value
///
inline uint64_t generate_rank_presence(const uint64_t i_rank)
{
    return RANK_PRESENCE_MASK & ~(lrdimm::RANK_PRESENCE_BIT << mss::index(i_rank));
}

// Namespace for any helper functions for calling out errors
namespace callout
{

///
/// @brief Calls out if invalid data is seen during this calibration step
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_nibble_flags flags for which nibbles are failing
/// @param[in] i_invalid_data_count count for the number of times fails were seen
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
/// @note Invalid data is defined as not having all zeros or all ones
/// To only be used during per-nibble training steps (MREP, DWL, MRD coarse, MWD coarse)
///
inline fapi2::ReturnCode invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t i_rank,
                                       const uint32_t i_per_nibble_flags,
                                       const uint64_t i_invalid_data_count,
                                       const uint64_t i_calibration_step,
                                       const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT(i_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_INVALID_DATA()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_NIBBLE_FLAGS(i_per_nibble_flags)
                .set_INVALID_DATA_COUNT(i_invalid_data_count),
                "%s rank%u has counted %u invalid data on nibbles 0x%x in %s",
                mss::c_str(i_target), i_rank, i_invalid_data_count, i_per_nibble_flags, i_name);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_nibble_flags flags for which nibbles are failing
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
///
inline fapi2::ReturnCode no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_rank,
                                        const uint32_t i_per_nibble_flags,
                                        const uint64_t i_calibration_step,
                                        const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT(i_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_NO_TRANSITION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_NIBBLE_FLAGS(i_per_nibble_flags),
                "%s rank%u has found no transitions on nibbles 0x%x in %s",
                mss::c_str(i_target), i_rank, i_per_nibble_flags, i_name);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Calls out if a rank see more than one passing region
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_nibble_flags flags for which nibbles are failing
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
///
inline fapi2::ReturnCode not_one_passing_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const uint32_t i_per_nibble_flags,
        const uint64_t i_calibration_step,
        const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT(i_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_NOT_ONE_PASSING_REGION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_NIBBLE_FLAGS(i_per_nibble_flags),
                "%s rank%u has found not only one passing region on nibbles 0x%x in %s",
                mss::c_str(i_target), i_rank, i_per_nibble_flags, i_name);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_per_dq_flags_msb flags for which dqs are failing
/// @param[in] i_per_dq_flags_lsb flags for which dqs are failing
/// @param[in] i_calibration_step calibration step number
/// @param[in] i_name string of the calibration steps name
/// @return FAPI2_RC_SUCCESS if okay
///
inline fapi2::ReturnCode no_pass_region( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const uint64_t i_per_dq_flags_msb,
        const uint64_t i_per_dq_flags_lsb,
        const uint64_t i_calibration_step,
        const char* i_name)
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    FAPI_ASSERT((i_per_dq_flags_msb | i_per_dq_flags_lsb) == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_NO_PASS_REGION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(i_calibration_step)
                .set_DQ_FLAGS_MSB(i_per_dq_flags_msb)
                .set_DQ_FLAGS_LSB(i_per_dq_flags_lsb),
                "%s rank%u has found no pass region on dqs msb:0x%16lx lsb:0x%16lx in %s",
                mss::c_str(i_target), i_rank, i_per_dq_flags_msb, i_per_dq_flags_lsb, i_name);


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

} // ns callout

namespace workarounds
{
static const std::vector<std::vector<std::vector<int8_t>>> OFFSET_RD_DELAY_D_SAM =
{
    //P0 MCA0
    {
        // RANK_PAIR0
        {
            2,  2,  1,  0,  4,  4,  2,  2,  5,  4,  5,  5,  2,  2,  2,  2,  0,  1,  1,  1,  1,  1,  1,  3,
            2,  2,  0,  1,  -1, 0,  0,  -2, 1,  2,  2,  3,  2,  2,  2,  1,  0,  2,  -1, 2,  0,  0,  -1, 0,
            2,  2,  2,  5,  2,  1,  1,  1,  2,  4,  4,  4,  2,  1,  4,  2,  2,  3,  1,  1,  -1, -1, 1,  1,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            5,  4,  2,  2,  6,  6,  2,  3,  6,  5,  5,  5,  5,  6,  5,  5,  4,  6,  4,  4,  6,  6,  4,  6,
            2,  4,  1,  2,  1,  1,  1,  0,  4,  5,  5,  6,  4,  6,  6,  4,  4,  4,  2,  5,  2,  2,  1,  2,
            6,  6,  4,  7,  6,  5,  4,  5,  6,  7,  6,  6,  6,  5,  6,  5,  1,  3,  1,  2,  1,  1,  4,  4,

        },
        // RANK_PAIR3
        {
        },
    },

    //P0 MCA1
    {
        // RANK_PAIR0
        {
            3,  4,  3,  0,  4,  4,  1,  3,  0,  0,  0,  0,  2,  3,  1,  4,  4,  3,  4,  6,  3,  4,  6,  5,
            3,  3,  6,  5,  1,  3,  5,  4,  1,  1,  3,  3,  2,  2,  3,  3,  4,  4,  4,  5,  3,  3,  4,  4,
            1,  2,  3,  3,  2,  2,  2,  3,  3,  3,  6,  6,  4,  3,  3,  2,  2,  2,  4,  4,  2,  2,  4,  3,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            5,  7,  3,  2,  6,  6,  4,  6,  0,  1,  -2, 0,  2,  5,  1,  4,  8,  7,  8,  10, 7,  8,  9,  7,
            7,  7,  7,  9,  6,  6,  7,  5,  5,  5,  5,  7,  5,  6,  5,  5,  9,  8,  7,  8,  6,  7,  7,  6,
            6,  6,  5,  6,  7,  7,  6,  6,  6,  5,  7,  6,  6,  5,  6,  6,  5,  5,  5,  6,  5,  6,  6,  5,

        },
        // RANK_PAIR3
        {
        },
    },
    //P0 MCA2
    {
    },
    //P0 MCA3
    {
    },

    //P0 MCA4
    {
        // RANK_PAIR0
        {
            7,  4,  5,  5,  6,  4,  4,  3,  4,  4,  5,  4,  4,  3,  4,  4,  1,  2,  0,  1,  1,  0,  0,  1,
            2,  2,  4,  4,  2,  3,  5,  4,  4,  2,  4,  4,  2,  1,  2,  1,  0,  1,  0,  1,  1,  2,  -2, -2,
            1,  1,  3,  2,  0,  1,  1,  1,  0,  1,  5,  0,  1,  1,  3,  2,  4,  2,  4,  3,  2,  1,  0,  0,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            10, 8,  8,  8,  10, 10, 8,  8,  6,  6,  6,  7,  6,  4,  7,  6,  6,  5,  3,  4,  4,  2,  3,  3,
            7,  6,  6,  6,  6,  7,  6,  6,  6,  4,  6,  6,  5,  2,  4,  3,  4,  3,  4,  3,  3,  1,  1,  1,
            6,  6,  5,  4,  4,  3,  3,  3,  5,  5,  6,  3,  5,  4,  5,  4,  7,  5,  5,  4,  4,  2,  1,  1,

        },
        // RANK_PAIR3
        {
        },
    },

    //P0 MCA5
    {
        // RANK_PAIR0
        {
            4,  1,  1,  0,  3,  4,  -1, 0,  4,  3,  4,  3,  3,  3,  3,  4,  4,  5,  6,  5,  3,  3,  4,  6,
            5,  6,  6,  6,  4,  3,  5,  5,  2,  3,  3,  2,  3,  1,  2,  2,  5,  5,  8,  7,  4,  4,  3,  5,
            3,  2,  3,  2,  2,  2,  2,  1,  4,  4,  7,  6,  4,  2,  3,  3,  3,  2,  4,  4,  3,  3,  4,  5,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            6,  4,  2,  4,  5,  5,  1,  2,  6,  5,  4,  4,  5,  4,  4,  3,  8,  8,  8,  8,  6,  6,  6,  8,
            7,  7,  7,  7,  7,  7,  7,  7,  4,  5,  4,  4,  5,  3,  4,  3,  6,  7,  7,  7,  7,  7,  6,  7,
            7,  6,  5,  4,  6,  7,  5,  5,  7,  7,  8,  8,  6,  5,  6,  6,  7,  5,  5,  5,  7,  6,  8,  7,

        },
        // RANK_PAIR3
        {
        },
    },
    //P0 MCA6
    {
    },
    //P0 MCA7
    {
    },

    //P1 MCA0
    {
        // RANK_PAIR0
        {
            4,  3,  1,  0,  4,  4,  3,  3,  3,  3,  4,  3,  2,  2,  2,  3,  0,  2,  2,  2,  0,  0,  1,  2,
            2,  2,  0,  0,  -2, -1, -2, -2, 1,  2,  2,  4,  2,  3,  2,  2,  1,  2,  -1, 3,  0,  0,  -1, 0,
            1,  1,  3,  4,  2,  2,  2,  3,  1,  3,  4,  4,  3,  2,  5,  4,  2,  3,  2,  2,  0,  0,  2,  1,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            6,  4,  2,  2,  6,  6,  2,  3,  6,  6,  5,  6,  5,  6,  5,  5,  4,  6,  3,  3,  5,  5,  3,  5,
            2,  5,  2,  2,  2,  2,  1,  0,  4,  5,  5,  6,  5,  6,  6,  5,  3,  3,  3,  5,  2,  2,  2,  3,
            6,  6,  4,  6,  6,  4,  4,  4,  6,  7,  6,  7,  6,  5,  5,  5,  1,  3,  1,  3,  1,  1,  5,  4,

        },
        // RANK_PAIR3
        {
        },
    },

    //P1 MCA1
    {
        // RANK_PAIR0
        {
            2,  4,  2,  0,  4,  4,  2,  3,  1,  0,  -1, -1, 2,  3,  1,  4,  4,  3,  4,  5,  3,  3,  5,  4,
            5,  4,  7,  5,  1,  3,  5,  4,  2,  1,  4,  4,  2,  3,  3,  3,  4,  3,  3,  5,  3,  3,  3,  3,
            2,  3,  4,  4,  2,  2,  2,  4,  3,  3,  6,  6,  4,  2,  4,  3,  2,  2,  4,  4,  1,  2,  3,  3,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            4,  7,  4,  1,  6,  6,  3,  6,  1,  1,  -1, 0,  2,  5,  1,  4,  8,  6,  8,  10, 7,  8,  9,  8,
            6,  6,  7,  8,  7,  7,  8,  6,  5,  6,  5,  6,  5,  6,  6,  6,  9,  9,  7,  8,  7,  8,  8,  6,
            6,  7,  6,  7,  6,  6,  5,  6,  6,  6,  8,  8,  5,  4,  5,  5,  5,  5,  5,  6,  5,  6,  6,  6,

        },
        // RANK_PAIR3
        {
        },
    },
    //P1 MCA2
    {
    },
    //P1 MCA3
    {
    },

    //P1 MCA4
    {
        // RANK_PAIR0
        {
            7,  4,  5,  4,  6,  5,  4,  3,  4,  4,  4,  4,  4,  2,  4,  4,  2,  2,  1,  2,  2,  1,  0,  2,
            2,  2,  5,  4,  3,  3,  5,  5,  3,  1,  2,  2,  1,  0,  0,  -1, 1,  2,  1,  1,  2,  1,  -1, -1,
            2,  2,  3,  2,  2,  1,  2,  2,  1,  2,  5,  1,  2,  1,  4,  2,  4,  2,  5,  2,  2,  1,  0,  0,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            10, 7,  8,  8,  9,  8,  7,  6,  6,  6,  5,  7,  7,  4,  7,  6,  5,  4,  4,  4,  5,  2,  3,  3,
            6,  5,  5,  5,  6,  6,  6,  5,  7,  4,  6,  6,  5,  2,  4,  3,  4,  3,  5,  3,  3,  1,  1,  1,
            7,  6,  5,  4,  5,  3,  3,  3,  5,  6,  6,  3,  5,  4,  5,  3,  6,  4,  5,  3,  3,  2,  1,  1,

        },
        // RANK_PAIR3
        {
        },
    },

    //P1 MCA5
    {
        // RANK_PAIR0
        {
            5,  2,  3,  1,  3,  3,  1,  1,  5,  4,  5,  4,  3,  4,  3,  5,  4,  4,  6,  5,  2,  2,  4,  6,
            5,  6,  7,  6,  4,  4,  5,  5,  2,  3,  3,  2,  3,  2,  2,  2,  4,  4,  7,  6,  4,  4,  4,  5,
            3,  3,  3,  2,  3,  3,  3,  2,  5,  5,  8,  7,  4,  3,  4,  4,  3,  2,  5,  4,  3,  3,  5,  5,

        },
        // RANK_PAIR1
        {
        },
        // RANK_PAIR2
        {
            6,  4,  3,  3,  5,  5,  1,  2,  7,  6,  4,  4,  5,  5,  3,  3,  6,  8,  7,  7,  7,  6,  5,  7,
            8,  9,  9,  9,  8,  7,  8,  8,  6,  6,  6,  5,  7,  5,  6,  5,  7,  7,  8,  8,  7,  6,  6,  7,
            7,  6,  5,  4,  7,  7,  5,  5,  8,  8,  8,  9,  6,  5,  7,  6,  6,  5,  5,  6,  6,  6,  7,  6,

        },
        // RANK_PAIR3
        {
        },
    },
    //P1 MCA6
    {
    },
    //P1 MCA7
    {
    },
};

///
/// @brief Record the offset and the corresponding DQ
///
struct shift_offset
{
    uint8_t mca_num;
    uint8_t rp_num;
    uint8_t dq_reg_num;
    int8_t offset;

    ///
    /// @brief constructor
    ///
    shift_offset(const uint8_t i_mca_num, const uint8_t i_rp_num, const uint8_t i_dq_reg_num,
                 const int8_t i_offset) :
        mca_num(i_mca_num),
        rp_num(i_rp_num),
        dq_reg_num(i_dq_reg_num),
        offset(i_offset)
    {}
};

// c1 4 2 0 3 need shift for dubai,  dimm dq is 19, register is 56
static std::vector<shift_offset> WR_DELAY_OFFSET =
{
    {1, 2, 56, -4},
    {9, 2, 56, -5},
};


///
/// @brief Clears error firs
/// @param[in] i_target The MCA Target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode clear_firs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);
///
/// @brief Clears error firs
/// @param[in] i_target The MCA Target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode clear_firs_mcbist_out_of_sync(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Check if all mca have dimm populated on mcbist
/// @param[in] i_target The MCA Target
/// @return fapi2::ReturnCode
///
bool all_mca_config(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target);

///
/// @brief Modify the write delay and read delay using offset table
/// @param[in] i_target the MCA target
/// @param[in] i_rp the rank pair on which to operate
/// @param[in] i_offset_rd_delay_d_sam the offset table of read delay
/// @param[in] i_wr_delay_offset the offset table of write delay
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode timing_workaround_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const std::vector<std::vector<std::vector<int8_t>>>& i_offset_rd_delay_d_sam,
        const std::vector<shift_offset>& i_wr_delay_offset,
        const uint8_t i_abort_on_error);

///
/// @brief Modify the write delay and read delay
/// @param[in] i_target the MCA target
/// @param[in] i_rp the rank pair on which to operate
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode timing_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const uint64_t i_rp,
                                     const uint8_t i_abort_on_error);

} // ns workarounds

} // ns training

} // ns lrdimm

} // ns mss

#endif
