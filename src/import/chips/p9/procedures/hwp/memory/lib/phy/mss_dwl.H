/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_dwl.H $ */
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
/// @file lib/phy/mss_dwl.H
/// @brief DWL LRDIMM training
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_DWL_H
#define MSS_DWL_H

#include <lib/phy/mss_lrdimm_training.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief DWL training step
///
class dwl : public step
{
    public:
        dwl() :
            step("DWL")
        {}

        static constexpr uint64_t MAX_DELAY = 64;

        ///
        /// @brief Default virtual destructor
        ///
        ~dwl() = default;

        ///
        /// @brief Records the results for a given nibble
        ///
        struct recorder
        {
            ///
            /// @brief Default constructor
            ///
            recorder() :
                iv_seen0(false),
                iv_seen1(false),
                iv_delay(0)
            {}

            ///
            /// @brief constructor
            ///
            recorder(const bool i_seen0, const bool i_seen1, const uint8_t i_delay) :
                iv_seen0(i_seen0),
                iv_seen1(i_seen1),
                iv_delay(i_delay)
            {}

            bool iv_seen0;
            bool iv_seen1;
            uint8_t iv_delay;
        };

        ///
        /// @brief Sets the rank to calibrate for WR LVL in the buffer
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the rank target on which to operate
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_rank(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint64_t i_rank) const;

        ///
        /// @brief Configures the given rank into WR LVL mode
        /// @param[in] i_target DIMM target on which to operate
        /// @paran[in] i_rank the rank on which to operate
        /// @paran[in] i_mode mode for the WR LVL
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode dram_wr_lvl( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint64_t i_rank,
                                       const mss::states i_mode) const;

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
        /// @brief Sets MREP Delay value
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank to operate on - drives the function space select
        /// @param[in] delay value /64 Tck - MREP delay value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Sets DA setting for buffer control word (F[3:0]BC2x, F[3:0]BC3x)
        ///
        fapi2::ReturnCode set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_rank,
                                    const uint8_t i_delay ) const;

        ///
        /// @brief Processes the results for a given DWL run
        /// @param[in] i_target the MCA target on which to operate
        /// @param[in] i_rank rank for test
        /// @param[in] i_delay the current delay
        /// @param[in,out] io_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode process_results( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rank,
                                           const uint8_t i_delay,
                                           std::vector<std::pair<recorder, recorder>>& io_recorders) const;

        ///
        /// @brief Processes the results for a given DWL run
        /// @param[in] i_target the target on which the code is operating
        /// @param[in] i_rank rank for test
        /// @param[in] i_buffer the buffer associated with the data
        /// @param[in] i_nibble the nibble associated with the data
        /// @param[in] i_result the results for the current nibble
        /// @param[in] i_delay the current delay
        /// @param[in,out] io_recorder the recorder on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode process_results( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rank,
                                           const uint8_t i_buffer,
                                           const uint8_t i_nibble,
                                           const uint8_t i_result,
                                           const uint8_t i_delay,
                                           recorder& io_recorder) const;

        ///
        /// @brief Analyzes the results for a given DWL run
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode analyze_results( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           const uint8_t i_rank,
                                           const std::vector<std::pair<recorder, recorder>>& i_recorders) const;

        ///
        /// @brief Write the results to buffer generate PBA commands
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank number
        /// @param[in] i_recorders a vector of the MREP result
        /// @param[out] o_container the PBA commands structure
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note a little helper to allow us to unit test that we generate the PBA commands ok
        ///
        fapi2::ReturnCode write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<recorder, recorder>>& i_recorders,
                mss::ddr4::pba::commands& o_container) const;

        ///
        /// @brief Writes the results to the buffers for a given DIMM-rank
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<recorder, recorder>>& i_recorders) const;


        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;
};

} // ns training

} // ns lrdimm

} // ns mss

#endif
