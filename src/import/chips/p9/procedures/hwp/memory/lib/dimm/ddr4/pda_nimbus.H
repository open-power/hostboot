/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pda_nimbus.H $ */
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
/// @file pda_nimbus.H
/// @brief Code to support per-DRAM addressability (PDA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _MSS_PDA_NIMBUS_H_
#define _MSS_PDA_NIMBUS_H_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/dimm/ddr4/pda.H>

namespace mss
{

namespace ddr4
{

namespace pda
{

///
/// @brief Holds all PDA specific constants
///
enum consts : uint64_t
{
    // Note: the delay is taken from the PDA timing register's maximum value 2^6
    MAX_PDA_REG = 64,
    // 10 cycles for safety
    SAFETY = 10,
    // Total delay is your register max + safety
    SAFE_COMMAND_DELAY = MAX_PDA_REG + SAFETY,

    // PDA on/off settings
    START_DELAY_VALUE = 0,
    HOLD_DELAY_VALUE = 0xff,

    // Each enable is just 1 bit and there are 4 per reg.  Adding a length here to make the code look better
    NUM_DRAM_PER_REG = 4,

    // DRAM bit constants
    DRAM0 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0,
    DRAM1 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1,
    DRAM2 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2,
    DRAM3 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3,
    DRAM_START = DRAM0,
};

///
/// @class pdaBitTraits
/// @brief Write bit traits class
/// @tparam W the DRAM's width
///
template < uint8_t W >
class pdaBitTraits;

///
/// @brief Write bit for PDA specialization for x4 devices
///
template < >
class pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4>
{
    public:
        // One nibble is needed - the register has one nibble per bit, so one bit
        static constexpr uint64_t NUM_BITS = 1;
        static constexpr uint64_t NUM_DRAMS = MAX_DRAMS_X4;
        static const std::vector<std::pair<uint64_t, uint64_t>> BIT_MAP;
};

///
/// @brief Write bit for PDA specialization for x8 devices
///
template < >
class pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8>
{
    public:
        // Two nibbles are needed - the register has one nibble per bit, so two bits
        static constexpr uint64_t NUM_BITS = 2;
        static constexpr uint64_t NUM_DRAMS = MAX_DRAMS_X8;
        static const std::vector<std::pair<uint64_t, uint64_t>> BIT_MAP;
};

///
/// @brief PDA traits class
/// @tparam MC the memory controller type
///
template<>
class pda_traits<mss::mc_type::NIMBUS>
{
    public:
        typedef std::pair<fapi2::Target<fapi2::TARGET_TYPE_DIMM>, uint64_t> RANK_TARGET;

        ///
        /// @brief Gets the rank target information for PDA
        /// @param[in] i_target MCA target
        /// @param[in] i_rank rank on which to operate
        /// @param[out] o_rank_target the rank target for this MCA/rank
        ///
        static fapi2::ReturnCode get_rank_target(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                const uint64_t i_rank,
                RANK_TARGET& o_rank_target)
        {
            fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
            FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target,
                     i_rank,
                     l_dimm));

            // Check for a valid rank
            FAPI_ASSERT(mss::rank::is_rank_on_dimm(l_dimm, i_rank),
                        fapi2::MSS_INVALID_RANK().
                        set_PORT_TARGET(i_target).
                        set_RANK(i_rank).
                        set_FUNCTION(mss::ffdc_function_codes::PDA_ADD_COMMAND),
                        "%s does not have rank %lu", mss::c_str(i_target), i_rank);

            o_rank_target = {l_dimm, i_rank};

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Gets the rank target information for PDA
        /// @param[in] i_target DIMM target
        /// @param[in] i_rank rank on which to operate
        /// @param[out] o_rank_target the rank target for this MCA/rank
        ///
        static fapi2::ReturnCode get_rank_target(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const uint64_t i_rank,
                RANK_TARGET& o_rank_target)
        {
            // Check for a valid rank
            FAPI_ASSERT(mss::rank::is_rank_on_dimm(i_target, i_rank),
                        fapi2::MSS_INVALID_RANK().
                        set_PORT_TARGET(mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target)).
                        set_RANK(i_rank).
                        set_FUNCTION(mss::ffdc_function_codes::PDA_ADD_COMMAND),
                        "%s does not have rank %lu", mss::c_str(i_target), i_rank);

            o_rank_target = {i_target, i_rank};

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;

        }

};

///
/// @brief Sets the enable bit for a dram
/// @tparam D the DRAM to enable or disable
/// @param[in,out] io_data the data buffer to modify
/// @param[in] i_state the state to modify the buffer to
///
template< uint64_t D >
inline void set_dram_enable( fapi2::buffer<uint64_t>& io_data, const mss::states& i_state)
{
    io_data.writeBit<D>(i_state);
}

///
/// @brief Enters into and configures PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const uint64_t i_rank );

///
/// @brief Exits out of and disables PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank );

///
/// @brief Helper function for changing the DRAM bit
/// @tparam W the DRAM width
/// @tparam TT the DRAM width traits class
/// @param[in] i_target - the MCA target
/// @param[in] i_dram - the DRAM on which to operate
/// @param[in] i_state - the state to write the bit(s) to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< uint8_t W, typename TT = pdaBitTraits<W> >
fapi2::ReturnCode change_dram_bit_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_dram,
        const mss::states& i_state)
{
    fapi2::buffer<uint64_t> l_data;

    // Note: the following avoids "undefined reference to" errors due to the set max dram below
    // The use of traits and a const reference messes with it
    constexpr auto NUM_DRAM = TT::NUM_DRAMS;

    // Check bounds
    FAPI_ASSERT(i_dram < NUM_DRAM,
                fapi2::MSS_PDA_DRAM_OUT_OF_RANGE().
                set_TARGET(i_target).
                set_DRAM(i_dram).
                set_MAX_DRAM(NUM_DRAM),
                "%s was passed DRAM value of %lu which is not below the max value of %lu",
                mss::c_str(i_target), i_dram, NUM_DRAM);

    FAPI_TRY(mss::getScom(i_target, TT::BIT_MAP[i_dram].first, l_data));
    FAPI_TRY(l_data.writeBit(i_state, TT::BIT_MAP[i_dram].second, TT::NUM_BITS));
    FAPI_TRY(mss::putScom(i_target, TT::BIT_MAP[i_dram].first, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the data bit enable for the properly inputted DRAM
/// @param[in] i_target - the MCA target
/// @param[in] i_dram - the DRAM on which to operate
/// @param[in] i_state - the state to write the bit(s) to
/// @note PDA is LOW enable, so 0's means ON. ON will configure the register to 0's
///
fapi2::ReturnCode change_dram_bit( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_dram,
                                   const mss::states& i_state);

///
/// @brief Performs a PDA WR VREF latch
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in] i_mrs the MRS data to update
/// @param[in] i_drams the DRAM to update
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note A PDA latch of WR VREF settings is the most common PDA operations
/// This function adds a bit of fanciness (compression) to speed up the overall runtime
///
fapi2::ReturnCode execute_wr_vref_latch( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const mss::ddr4::mrs06_data<mss::mc_type::NIMBUS>& i_mrs,
        const std::vector<uint64_t>& i_drams );

///
/// @brief Configures PDA timings
/// @param[in,out] io_buffer buffer on which the PDA timings live
/// @note Configuring timings is a helper function, as it is used both in PDA and PBA
/// PBA requires that we set the timings, but not enable PDA mode in the WC config, so we have a helper function
///
void configure_timings( fapi2::buffer<uint64_t>& io_buffer );


///
/// @brief Configures PDA timings
/// @param[in] i_target a fapi2::Target MCA
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_timings_and_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Configures all DRAM level configuration bits to the inputted settings
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target MCA
/// @param[in] i_state - OFF - 1's, ON - 0's
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note PDA is LOW enable, so 0's means ON. ON will configure the register to 0's
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode blast_dram_config( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
                                     const mss::states& i_state );

///
/// @brief Adds a PDA enable command
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst the CCS instructions to update
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_enable( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t >& io_inst );

///
/// @brief Adds a PDA disable command
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst the CCS instructions to update
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_disable( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               const uint64_t i_rank,
                               std::vector< ccs::instruction_t >& io_inst );

} // ns pda

} // ns ddr4

} // ns mss

#endif
