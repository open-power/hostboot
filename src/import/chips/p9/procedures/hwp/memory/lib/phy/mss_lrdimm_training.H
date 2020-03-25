/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.H $ */
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

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/mss_const.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/phy/mss_training.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>
#include <lib/phy/seq.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <lib/mcbist/mcbist.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/phy/ddr_phy.H>


// Disables LRDIMM support for HB
#ifndef __HOSTBOOT_MODULE
    #define CONFIG_LRDIMM_CAPABLE 1
#endif

#ifdef CONFIG_LRDIMM_CAPABLE
    #define LRDIMM_CAPABLE 1
#endif

#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_lrdimm_training_helper.H>
#endif

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
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_rank the DIMM rank to set the MPR on
/// @param[in] i_pattern the pattern to write into the MPRS
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode add_mpr_pattern_writes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_pattern,
        std::vector<mss::ccs::instruction_t>& io_insts)
{
    using TT = ccsTraits<mss::mc_type::NIMBUS>;

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
            auto l_wr = mss::ccs::wr_command( i_rank,
                                              l_ba,
                                              MPR_WR_BG,
                                              l_pattern);
            // Swaps the bank addresses so they're a true to the BA we tried to pass in above
            swap<TT::BA0, TT::BA1>(l_wr.arr0);

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
/// @param[in] i_target DIMM target on which to operate
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode disable_address_inversion(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector<mss::ccs::instruction_t>& io_insts)
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
/// @param[in] i_target DIMM target on which to operate
/// @param[in,out] io_insts CCS instructions
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode restore_address_inversion(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector<mss::ccs::instruction_t>& io_insts)
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

///
/// @brief Swizzles a DQ from the MC perspective to the DIMM perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_dimm_dq(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_mc_dq,
                                uint64_t& o_buffer_dq);

///
/// @brief Swizzles a DQ from the MC perspective to the buffer's perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_buffer(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_mc_dq,
                               uint64_t& o_buffer_dq);

///
/// @brief Checks if a buffer's nibbles are swizzled
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_buffer the buffer on which to see if the nibbles are swizzled
/// @param[out] o_are_swizzled true if the buffer's nibbles are swizzled
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode are_buffers_nibbles_swizzled(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_buffer,
        bool& o_are_swizzled);

///
/// @class data_response
/// @brief A structure that stores the results from the CCS on a per-buffer per-beat level
///
struct data_response
{
    static constexpr uint64_t MAX_NUM_BEATS = 8;
    uint8_t iv_buffer_beat[MAX_LRDIMM_BUFFERS][MAX_NUM_BEATS];

    ///
    /// @brief Reads the data response for the LRDIMM
    /// @param[in] i_target the MCA target on which to operate
    /// @return fapi2::ReturnCode SUCCESS iff code exectutes successfully
    ///
    fapi2::ReturnCode read(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
    {
        // Magic number is
        // 1) read from the read buffer
        // 2) read from the magic CCS start addres
        // 3) auto-increment the addresses to read from
        constexpr uint64_t CCS_READ_CONFIGURE = 0x7c20000000000000;
        FAPI_TRY(mss::putScom(i_target, MCA_WREITE_AACR, CCS_READ_CONFIGURE));

        // Now read out all 8 beats
        for(uint8_t l_beat = 0; l_beat < MAX_NUM_BEATS; ++l_beat)
        {
            // Read out the data
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY(mss::getScom(i_target, MCA_AADR, l_data));

            // Parse the data out into the buffers for this beat
            // Each data buffer is 8 bits wide, so we parse each buffer by 8 bits
            l_data.extractToRight<0, BITS_PER_BYTE>(iv_buffer_beat[0][l_beat])
            .extractToRight< 8, BITS_PER_BYTE>(iv_buffer_beat[1][l_beat])
            .extractToRight<16, BITS_PER_BYTE>(iv_buffer_beat[2][l_beat])
            .extractToRight<24, BITS_PER_BYTE>(iv_buffer_beat[3][l_beat])
            .extractToRight<32, BITS_PER_BYTE>(iv_buffer_beat[4][l_beat])
            .extractToRight<40, BITS_PER_BYTE>(iv_buffer_beat[5][l_beat])
            .extractToRight<48, BITS_PER_BYTE>(iv_buffer_beat[6][l_beat])
            .extractToRight<56, BITS_PER_BYTE>(iv_buffer_beat[7][l_beat]);

            // Read out the ECC buffer
            FAPI_TRY(mss::getScom(i_target, MCA_AAER, l_data));
            l_data.extractToRight<0, BITS_PER_BYTE>(iv_buffer_beat[8][l_beat]);
        }

        // Added in for cronus debug - not needed for hostboot
#ifndef __HOSTBOOT_MODULE
        FAPI_TRY(buffer_print(i_target));
#endif

    fapi_try_exit:
        return fapi2::current_err;
    }

    // Added in for cronus debug - not needed for hostboot
#ifndef __HOSTBOOT_MODULE
    ///
    /// @brief Prints out the response data for LRDIMM's in terms of the DRAM position
    /// @param[in] i_target MCA target on which to operate
    /// @return fapi2::ReturnCode SUCCESS iff code exectutes successfully
    /// @note Should be for an RC B2 - swizzle might not be good for non-RC B2
    ///
    fapi2::ReturnCode buffer_print(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
    {
        // The below list is taken from rawcard B's JEDEC specification
        // Assuming it remains the same for other raw card's, but this is just for debug prints for cronus anways
        static constexpr uint8_t NIBBLE_TO_DRAM[MAX_DRAMS_X4] =
        {
            0,
            5,
            1,
            6,
            7,
            2,
            8,
            3,
            10,
            14,
            11,
            15,
            12,
            16,
            17,
            13,
            9,
            4,
        };
        uint8_t l_results[MAX_DRAMS_X4] = {};

        // Loops through all buffers
        for(uint8_t l_buffer = 0; l_buffer < MAX_LRDIMM_BUFFERS; ++l_buffer)
        {
            uint64_t l_buffer_nibble0_dq = 0;
            uint64_t l_buffer_nibble1_dq = 0;
            uint64_t l_dram_0 = 0;
            uint64_t l_dram_1 = 0;
            FAPI_TRY(mc_to_dimm_dq(i_target, l_buffer * BITS_PER_BYTE, l_buffer_nibble0_dq));
            FAPI_TRY(mc_to_dimm_dq(i_target, l_buffer * BITS_PER_BYTE + BITS_PER_NIBBLE, l_buffer_nibble1_dq));

            l_dram_0 = NIBBLE_TO_DRAM[l_buffer_nibble0_dq / BITS_PER_NIBBLE];
            l_dram_1 = NIBBLE_TO_DRAM[l_buffer_nibble1_dq / BITS_PER_NIBBLE];

            l_results[l_dram_0] = iv_buffer_beat[l_buffer][0] & 0x0f;
            l_results[l_dram_1] = (iv_buffer_beat[l_buffer][0] & 0xf0) >> BITS_PER_NIBBLE;
        }

        FAPI_DBG("%s CARDU %x%x%x%x%x RCD %x%x%x%x", mss::c_str(i_target),
                 l_results[0], l_results[1], l_results[2], l_results[3], l_results[4], l_results[10], l_results[11], l_results[12],
                 l_results[13]);

        FAPI_DBG("%s CARDL %x%x%x%x%x RCD %x%x%x%x", mss::c_str(i_target),
                 l_results[5], l_results[6], l_results[7], l_results[8], l_results[9], l_results[14], l_results[15], l_results[16],
                 l_results[17]);

    fapi_try_exit:
        return fapi2::current_err;
    }
#endif
};

#ifdef LRDIMM_CAPABLE
// TK:LRDIMM Do we need separate coarse vs fine steps?
///
/// @brief MREP training step
///
class mrep : public step
{
    public:
        // Per the LRDIMM spec, the MREP training values have one cycle per 64 ticks
        static constexpr uint8_t NIBBLE0_BCW_NUMBER = 0x02;
        static constexpr uint8_t NIBBLE1_BCW_NUMBER = 0x03;

        mrep() :
            step("MREP")
        {}

        ///
        /// @brief Default virtual destructor
        ///
        virtual ~mrep() = default;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        /// TODO:RTC200368 Update MREP for RAS - add in unit tests for this funtion
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
        /// TODO:RTC200368 Update MREP for RAS - add in unit tests for this funtion
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
        /// @brief write the result to buffer
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank number
        /// @param[in] i_mrep_result a vector of the MREP result
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_mrep_result) const;

        ///
        /// @brief Write the results to buffer generate PBA commands
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank number
        /// @param[in] i_mrep_result a vector of the MREP result
        /// @param[out] o_container the PBA commands structure
        /// @return FAPI2_RC_SUCCESS if and only if ok
        /// @note a little helper to allow us to unit test that we generate the PBA commands ok
        ///
        fapi2::ReturnCode write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>&
                i_mrep_result,
                mss::ddr4::pba::commands& o_container) const;

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
                                    const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders,
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
                                                const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const;

        ///
        /// @brief Creates the nibble flags for the no transition callout
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return no transition nibble flags
        ///
        uint32_t flag_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint8_t i_rank,
                                     const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const;

        ///
        /// @brief Calls out if a rank does not see a 0->1 transition
        /// @param[in] i_target the DIMM target on which to operate
        /// @param[in] i_rank the current rank
        /// @param[in] i_recorders the recorders on which to process the data
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode callout_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint8_t i_rank,
                const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const;

        ///
        /// @brief error check during the MREP training
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank to operate on
        /// @param[in] i_recorders the recorders for error check
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Check each nibble to ensure seen0/seen1 are true
        ///
        inline fapi2::ReturnCode error_check(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_rank,
                                             const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
        {
            FAPI_TRY(callout_no_transition(i_target, i_rank, i_recorders));
            FAPI_TRY(callout_invalid_data(i_target, i_rank, i_recorders));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Apply MREP offset to ranks based upon tCK RD preamble mode
        /// @param[in] i_target the DIMM target
        /// @param[in,out] io_results the recorders for error check
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Check each nibble to ensure seen0/seen1 are true
        ///
        inline fapi2::ReturnCode apply_final_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& io_results) const
        {
            // Per the LRDIMM spec, we need to add an offset of 32 for 1 tCK and 64 for 2 tCK
            constexpr uint8_t OFFSET_1TCK = 32;
            constexpr uint8_t OFFSET_2TCK = 64;
            uint8_t l_tck = 0;
            uint8_t l_buffer = 0;

            // try to get rd preamble
            FAPI_TRY(mss::eff_rd_preamble(i_target, l_tck));

            // Loop for all buffer results, apply the rd pramble
            for(auto& l_result : io_results)
            {
                const auto OFFSET = l_tck == fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK ? OFFSET_1TCK : OFFSET_2TCK;

                // Could make this math into a function - that way we can test it
                l_result.first.iv_delay = (l_result.first.iv_delay + OFFSET) % MREP_DWL_MAX_DELAY;
                l_result.second.iv_delay = (l_result.second.iv_delay + OFFSET) % MREP_DWL_MAX_DELAY;
                FAPI_DBG("%s buffer:%u final values for nibble0:0x%02x nibble1:0x%02x",
                         mss::c_str(i_target), l_buffer, l_result.first.iv_delay, l_result.second.iv_delay);
                l_buffer++;
            }

        fapi_try_exit:
            return fapi2::current_err;
        }
};
#endif

///
/// @brief Sets data buffer training mode control word
/// @param[in] i_target the DIMM target
/// @param[in] i_mode buffer training mode
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word (BC0C) setting
///
inline fapi2::ReturnCode set_buffer_training(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::ddr4::training i_mode )
{

    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_TRY(mss::ddr4::set_buffer_training(i_target, i_mode, l_program.iv_instructions));
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set MPR Mode
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in] i_rank DIMM rank
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode mpr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_mode,
                                  const uint64_t i_rank)
{
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_TRY( mss::ddr4::mpr_load(i_target,
                                  i_mode,
                                  i_rank,
                                  l_program.iv_instructions) );

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction for an MPR read
/// @param[in] i_target a DIMM target
/// @param[in] i_mode MPR location
/// @param[in] i_rank DIMM rank
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode mpr_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint64_t i_mpr_loc,
                                   const uint64_t i_rank)
{
    // We don't know our coarse adjust at this point, so send the ODT two cycles early and hold it two cycles late
    // Two is the maximum coarse adjust for the LRDIMM
    constexpr uint64_t SAFETY_CYCLES = 2;
    constexpr uint64_t ODT_CYCLE_LEN = 5 + SAFETY_CYCLES * 2;

    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    uint8_t l_cl = 0;
    uint8_t l_cwl = 0;
    uint64_t l_delay = 0;
    uint8_t l_rd_odt[MAX_RANK_PER_DIMM] = {};
    const auto l_dimm_rank = mss::index(i_rank);
    FAPI_TRY( mss::eff_dram_cwl(l_mca, l_cwl) );
    FAPI_TRY( mss::eff_dram_cl(l_mca, l_cl) );
    l_delay  = l_cl - l_cwl - SAFETY_CYCLES;

    FAPI_TRY(mss::eff_odt_rd(i_target, &l_rd_odt[0]));

    FAPI_TRY( ddr4::mpr_read(i_target, i_mpr_loc, i_rank, l_program.iv_instructions));

    l_program.iv_instructions[0].arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                              MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(l_delay);

    // Holds the RD ODT's for 5 cycles
    {
        uint8_t l_ccs_value = 0;
        FAPI_TRY(mss::ccs::convert_odt_attr_to_ccs(
                     fapi2::buffer<uint8_t>(l_rd_odt[l_dimm_rank]),
                     l_mca,
                     l_ccs_value));

        auto l_odt = mss::ccs::odt_command(l_ccs_value, ODT_CYCLE_LEN);
        l_program.iv_instructions.push_back(l_odt);
    }

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type,
                       const bool i_sim,
                       fapi2::buffer<uint32_t>& io_cal_steps);

///
/// @brief Does a CCS NTTM mode read
/// @param[in] i_target - the MCA target on which to operate
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode execute_nttm_mode_read(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

} // ns training

} // ns lrdimm

} // ns mss

#endif
