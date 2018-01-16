/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pda.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file pda.H
/// @brief Code to support per-DRAM addressability (PDA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _MSS_PDA_H_
#define _MSS_PDA_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ccs/ccs.H>
#include <lib/phy/write_cntrl.H>
#include <lib/dimm/mrs_load.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>

#include <map>

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
/// @brief Write bit for PDA specialization for x4 devices
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
/// @brief Enables or disables a given DRAM
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
/// @brief Configures PDA timings
/// @param[in] i_target a fapi2::Target MCA
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_timings( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Configures all DRAM level configuration bits to the inputted settings
/// @param[in] i_target a fapi2::Target MCA
/// @param[in] i_state - OFF - 1's, ON - 0's
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note PDA is LOW enable, so 0's means ON. ON will configure the register to 0's
///
fapi2::ReturnCode blast_dram_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
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
                              std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst );

///
/// @brief Enters into and configures PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const uint64_t i_rank );

///
/// @brief Adds a PDA disable command
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst the CCS instructions to update
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_disable( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               const uint64_t i_rank,
                               std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst );

///
/// @brief Exits out of and disables PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank );

///
/// @brief Writes the data bit enable for the properly inputted DRAM
/// @param[in] i_target - the MCA target
/// @param[in] i_dram - the DRAM on which to operate
/// @param[in] i_state - the state to write the bit(s) to
/// @param[in] i_delay the delay to use for the PDA command
/// @note PDA is LOW enable, so 0's means ON. ON will configure the register to 0's
///
fapi2::ReturnCode change_dram_bit( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_dram,
                                   const mss::states& i_state);

///
/// @brief PDA commands container that also has compression
/// @tparam D the MRS command type
///
template< typename D >
class commands
{
    public:
        // Typdefs to make the code more readable
        typedef std::pair<fapi2::Target<fapi2::TARGET_TYPE_DIMM>, uint64_t> rank_target;
        typedef std::map<D, std::vector<uint64_t> > mrs_drams;

        ///
        /// @brief Base constructor
        ///
        commands() = default;

        ///
        /// @brief Base destructor
        ///
        ~commands() = default;

        ///
        /// @brief Adds in a PDA command if need be
        /// @param[in] i_target the MCS target
        /// @param[in] i_rank the rank
        /// @param[in] i_mrs_container the MRS container to add
        /// @param[in] i_dram the DRAM to issue the PDA command to
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode add_command( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rank,
                                       const D& i_mrs,
                                       const uint64_t i_dram )
        {
            fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
            FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target,
                      i_rank,
                      l_dimm));

            FAPI_TRY(add_command(l_dimm, i_rank, i_mrs, i_dram));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Adds in a PDA command if need be
        /// @param[in] i_target the DIMM target
        /// @param[in] i_rank the rank
        /// @param[in] i_mrs_container the MRS container to add
        /// @param[in] i_dram the DRAM to issue the PDA command to
        /// @return FAPI2_RC_SUCCESS if and only if ok
        ///
        fapi2::ReturnCode add_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint64_t i_rank,
                                       const D& i_mrs,
                                       const uint64_t i_dram )
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

            // Check for a valid rank
            FAPI_ASSERT(mss::rank::is_rank_on_dimm(i_target, i_rank),
                        fapi2::MSS_INVALID_RANK().
                        set_MCA_TARGET(mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target)).
                        set_RANK(i_rank).
                        set_FUNCTION(mss::ffdc_function_codes::PDA_ADD_COMMAND),
                        "%s does not have rank %lu", mss::c_str(i_target), i_rank);

            // Does the compression
            iv_commands[ {i_target, i_rank}][i_mrs].push_back(i_dram);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Checks whether the map is empty
        /// @return bool true if empty
        ///
        inline bool empty() const
        {
            return iv_commands.empty();
        }

        ///
        /// @brief Clears the commands
        ///
        inline void clear()
        {
            iv_commands.clear();
        }

        ///
        /// @brief Returns the command information
        /// @return iv_commands
        ///
        inline const typename std::map<rank_target, mrs_drams>& get() const
        {
            return iv_commands;
        }

    private:
        // The following is a map of target/DIMM pairs as the key to a map of
        // the MRS command as the key to the DRAM's to toggle. An explanation as to the data structure is included below
        // Note: due to HB compile, a vector is used instead of a map

        // PDA compression is a little complex, but is organized to allow us to minimize the number of commands run
        // Each individual map is designed to further minimize the number of commands run
        // The compressed commands consist of a map of pairs within a map
        // The outside map, maps the DIMM/rank to the MRS command and DRAM's that need to be run
        // Basically, it's a list of a specific rank target with all the commands that need to be run
        // The rank-specific target information allows us to just issue the enter/exit commands for PDA for each rank once
        // The MRS commands to the DRAM are then looped over in the inside loop
        // The inside map has a key of the MRS and a value of a map of DRAM's to issue the MRS to
        // CCS does not allow the user to toggle the DQ during an MRS command
        // The DQ information is stored in separate registers in the PHY
        // What this means for issuing the commands is that we have to issue an invocation of CCS for each different MRS command we issue
        // We can issue a single MRS command for multiple DRAM's however
        // Each invocation of CCS creates a noticable increase in time, as the registers need to be configured, CCS needs to be started, and we need to poll for done
        // By only entering into PDA on a DIMM-rank once and by issuing the PDA MRS's to multiple DRAM's at a time, we can save a lot of runtime
        // Note: in shmoo, adding the compression reduced runtime from about 13 minutes down to 3 minutes
        typename std::map<rank_target, mrs_drams> iv_commands;
};

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
        const mss::ddr4::mrs06_data& i_mrs,
        const std::vector<uint64_t>& i_drams );

///
/// @brief Performs a PDA WR VREF latch
/// @param[in] i_commands the PDA commands to issue and DRAM
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note A PDA latch of WR VREF settings is the most common PDA operations
/// This function adds a bit of fanciness (compression) to speed up the overall runtime
///
fapi2::ReturnCode execute_wr_vref_latch( const commands<mss::ddr4::mrs06_data>& i_commands );

} // ns pda

} // ns ddr4

} // ns mss

#endif
