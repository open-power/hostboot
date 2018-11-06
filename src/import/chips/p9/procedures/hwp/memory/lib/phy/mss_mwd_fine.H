/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_mwd_fine.H $ */
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
/// @file lib/phy/mss_mwd_fine.H
/// @brief MWD fine LRDIMM training step
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_MWD_FINE_H
#define MSS_MWD_FINE_H

#include <lib/phy/mss_training.H>
#include <lib/phy/mss_lrdimm_training_helper.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief MWD fine training step
///
class mwd_fine : public step
{
    public:
        mwd_fine() :
            step("MWD_FINE")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        virtual ~mwd_fine() = default;

        // Per the LRDIMM spec, the MWD training values have one cycle per 32 ticks
        static constexpr uint8_t MWD_MAX_DELAY = 31;
        static constexpr uint8_t MAX_DQ_PER_BUFFER = 8;

        ///
        /// @class final_nibble_delay
        /// @brief A structure that stores the record of DQS value
        ///
        struct final_nibble_delay
        {
            uint8_t iv_nibble_delay;
            int8_t iv_offset[BITS_PER_NIBBLE];
        };

        ///
        /// @brief Sets MWD Delay value
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank to operate on - drives the function space select
        /// @param[in] delay value /64 Tck - MWD delay value on a per-nibble basis
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Sets up the MWD delay values in buffer control word (F[3:0]BC8x, F[3:0]BC9x)
        ///
        fapi2::ReturnCode set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_rank,
                                    const uint8_t i_delay ) const;

        ///
        /// @brief Analyze mwd result
        /// @param[in] i_target the MCA target
        /// @param[in] i_delay delay value /64 Tck - MWD delay value
        /// @param[in] i_data dq values
        /// @param[in,out] io_recorders dq value for all DQs and all delays
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode analyze_mwd_result_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                const uint8_t i_delay,
                const data_response i_data,
                lrdimm::fine_recorder& io_recorders) const;

        ///
        /// @brief Analyze mwd result
        /// @param[in] i_target the MCA target
        /// @param[in] i_delay delay value /64 Tck - MWD delay value
        /// @param[in] io_recorders dq value for all DQs and all delays
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode analyze_mwd_result( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                              const uint8_t i_delay,
                                              lrdimm::fine_recorder& io_recorders) const;

        ///
        /// @brief write the result to buffer
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank number
        /// @param[in] i_final_nibble_delays_buffer a vector of the MWD results,pair for nibble0 and nibble1
        /// @param[in,out] io_container pba command
        /// @return FAPI2_RC_SUCCESS if and only if ok
        //  @note Sets up buffer control word F[4:7]BCCx F[4:7]BCDx F[4:7]BCEx F[4:7]BCFx  to for best delay of each dq
        //        and F[0:3]BC8x,F[0:3]BC9x for best delay of each nibble
        ///
        fapi2::ReturnCode write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& i_final_nibble_delays_buffer,
                mss::ddr4::pba::commands& io_container) const;


        ///
        /// @brief write the result to buffer
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank number
        /// @param[in] i_final_nibble_delays_buffer a vector of the MWD results,pair for nibble0 and nibble1
        /// @return FAPI2_RC_SUCCESS if and only if ok
        //  @note Sets up buffer control word F[4:7]BCCx F[4:7]BCDx F[4:7]BCEx F[4:7]BCFx  to for best delay of each dq
        //        and F[0:3]BC8x,F[0:3]BC9x for best delay of each nibble
        ///
        fapi2::ReturnCode write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& i_final_nibble_delays_buffer) const;

        ///
        /// @brief find best delay for one nibble
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank to operate on
        /// @param[in] i_recorder mwd training recorder for each delay
        /// @param[in] i_buffer the buffer number
        /// @param[in] i_nibble the nibble number
        /// @param[in,out] io_eye_sizes_dq a vector of eye size for all dq
        /// @param[out] o_final_nibble_delays_buffer  the best delay value of one nibble and all dq
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode find_best_delay_for_nibble(
            const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
            const uint64_t i_rank,
            const lrdimm::fine_recorder& i_recorder,
            const uint64_t i_buffer,
            const uint64_t i_nibble,
            std::vector<uint16_t>& io_eye_sizes_dq,
            final_nibble_delay& o_final_nibble_delays_buffer)const;

        ///
        /// @brief find best delay for each DQ
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank to operate on
        /// @param[in] i_recorder mwd training recorder for each delay
        /// @param[in,out] io_eye_sizes_dq a vector of eye size for all dq
        /// @param[in,out] io_final_nibble_delays_buffer a vector of the MWD results
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode find_best_delay_for_each_dq(
            const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
            const uint64_t i_rank,
            const lrdimm::fine_recorder& i_recorder,
            std::vector<uint16_t>& io_eye_sizes_dq,
            std::vector<std::pair<final_nibble_delay, final_nibble_delay>>& io_final_nibble_delays_buffer) const;

        ///
        /// @brief convert loop value to register definition for nibble
        /// @param[in] i_delay the value to convert
        /// @return the value after convert
        //  @note BCW F[0:3]BC8x,F[0:3]BC9x
        ///
        uint8_t convert_loop_value_to_register_definition_nibble( const uint8_t& i_delay) const;

        ///
        /// @brief Converts per bit offset to register value
        /// @param[in] i_delay the value to convert
        /// @return the value after convert
        /// @note F[4:7]BCCx F[4:7]BCDx F[4:7]BCEx F[4:7]BCFx
        ///
        uint8_t convert_delay_dq( const int8_t& i_delay) const;

        ///
        /// @brief convert loop value to register definition for DQ
        /// @param[in] i_target the port on which we are operating
        /// @param[in] i_final_buffer_delay a pair variable for 8 dq offset delay of one buffer
        /// @param[in] i_buffer the buffer on which we are operating
        /// @param[out] io_bcw_bc8x_setting register F[4:7]BCCx setting
        /// @param[out] io_bcw_bc9x_setting register F[4:7]BCDx setting
        /// @param[out] io_bcw_bcax_setting register F[4:7]BCEx setting
        /// @param[out] io_bcw_bcbx_setting register F[4:7]BCFx setting
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note F[4:7]BCCx F[4:7]BCEx F[4:7]BCEx F[4:7]BCFx
        ///
        fapi2::ReturnCode convert_loop_value_to_register_definition_dq(
            const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
            const std::pair<final_nibble_delay, final_nibble_delay>& i_final_buffer_delay,
            const uint64_t i_buffer,
            uint8_t& o_bcw_bccx_setting,
            uint8_t& o_bcw_bcdx_setting,
            uint8_t& o_bcw_bcex_setting,
            uint8_t& o_bcw_bcfx_setting) const;

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

        ///
        /// @brief Returns the eye sizes for the latest MWD run
        /// @return iv_eye_sizes eye sizes for each bit
        /// @note This will be used for the buffer RD VREF calibration
        /// Not needed for 1D calibration
        ///
        const std::vector<uint16_t>& get_minimum_eye_sizes() const
        {
            return iv_minimum_eye_sizes;
        }

        ///
        /// @brief Sets up the minimum eye sizes for the latest MWD run
        /// @note This will be used for the buffer RD VREF calibration
        /// Not needed for 1D calibration
        ///
        void setup_minimum_eye_sizes() const
        {
            iv_minimum_eye_sizes.clear();
            // Note: we want the minimum values at the end of the run, so set this up to be the maximum value
            iv_minimum_eye_sizes = std::vector<uint16_t>(MAX_DQ_BITS, ~0);
        }

        ///
        /// @brief conduct write then read
        /// @param[in] i_target the DIMM target for the data
        /// @param[in] i_rank the DIMM rank on which to set the delay
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode conduct_write_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                              const uint64_t i_rank) const;

    private:
        mutable std::vector<uint16_t> iv_minimum_eye_sizes;
};

} // ns training

} // ns lrdimm

} // ns mss

#endif
