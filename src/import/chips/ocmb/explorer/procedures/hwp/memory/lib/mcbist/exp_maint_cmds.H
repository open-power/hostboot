/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_maint_cmds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_maint_cmds.H
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef _EXP_MAINT_CMDS_H
#define _EXP_MAINT_CMDS_H

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace exp
{

namespace steer
{

///
/// @brief Used to specify read or write steer mux
///
enum class mux_type : size_t
{
    READ_MUX,
    WRITE_MUX,
};

///
/// @brief Used to specify steer type
///
enum steer_type : size_t
{
    DRAM_SPARE0 = 0,    // Spare DRAM on port0
    DRAM_SPARE1 = 1,    // Spare DRAM on port1
};

static constexpr uint8_t SPARE_INDICES = 18;
static constexpr uint8_t SPARE_UNUSED = 31;
static constexpr uint8_t EXP_INVALID_SYMBOL = 0xff;

///
/// @brief Table matching spare index to last symbol
/// @note the vector index matches the spare index and holds the symbol value
///       the vector index also matches the Spare values for Steer mux registers
///

static const std::vector<uint8_t> spare_to_symbol(
{
    68,    36,    64,    32,    60,
    28,    56,    24,    52,    20,
    48,    16,    44,    12,    40,
    8,     4,     0
});


///
/// @class steerTraits
/// @brief Steer Mux Register traits
/// @tparam MT the steer_mux type
///
template< mux_type MT >
class steerTraits;

///
/// @class steerTraits
/// @brief Exp Steer Traits
///
template<>
class steerTraits< mux_type::READ_MUX >
{
    public:

        static const std::vector<uint32_t> read_muxregs_left;
        static const std::vector<uint32_t> read_muxregs_right;

        ///
        /// @brief Returns the location of the spare mux for this rank
        /// @param[in] i_rank the port rank to get the spare location for
        /// @note Must be verified as valid port rank by calling function
        /// @return the spare mux location in the read mux reg
        ///
        static uint32_t get_muxregs_left( const uint8_t i_rank )
        {
            return read_muxregs_left[i_rank];
        }

        ///
        /// @brief Returns the location of the rank spare mux
        /// @param[in] i_rank the port rank to get the spare location for
        /// @note Must be verified as valid port rank by calling function
        /// @return the spare mux location in the read mux reg
        ///
        static uint32_t get_muxregs_right( const uint8_t i_rank )
        {
            return read_muxregs_right[i_rank];
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = EXPLR_RDF_RSPAR,
            SPARE_MUX_LEN = EXPLR_RDF_RSPAR_CFG_STEERING_R0_LEFT_LEN,
        };

};

///
/// @class steerTraits
/// @brief Exp Steer Traits
///
template<>
class steerTraits< mux_type::WRITE_MUX >
{
    public:

        static const std::vector<uint32_t> write_muxregs_left;
        static const std::vector<uint32_t> write_muxregs_right;

        ///
        /// @brief Returns the location of the spare mux for this rank
        /// @param[in] i_rank the port rank to get the spare location for
        /// @note Must be verified as valid port rank by calling function
        /// @return the spare mux location in the write mux reg
        ///
        static uint32_t get_muxregs_left( const uint8_t i_rank )
        {
            return write_muxregs_left[i_rank];
        }

        ///
        /// @brief Returns the location of the spare mux for this rank
        /// @param[in] i_rank the port rank to get the spare location for
        /// @note Must be verified as valid port rank by calling function
        /// @return the spare mux location in the write mux reg
        ///
        static uint32_t get_muxregs_right( const uint8_t i_rank )
        {
            return write_muxregs_right[i_rank];
        }

        // Mux Register and Spare value definitions
        enum mux_registers : size_t
        {
            // Function spaces
            MUX_REGISTER = EXPLR_WDF_WSPAR,
            SPARE_MUX_LEN = EXPLR_WDF_WSPAR_CFG_STEERING_R0_LEFT_LEN,
        };

};

namespace check
{

///
/// @brief Checks the rank input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_rank Rank input to verify
/// @return EXP_MAINT_BAD_RANK_INPUT for an invalid rank, SUCCESS otherwise.
///
fapi2::ReturnCode rank(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_rank);

///
/// @brief Checks the spare index inputs for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_dram_spare0_index First symbol index of the DRAM fixed by the
///                                spare on port0 (if no steer, return 0xff)
/// @param[in] i_dram_spare1_index First symbol index of the DRAM fixed by the
///                                spare on port1 (if no steer, return 0xff)
/// @return EXP_MAINT_BAD_SPARE_INDEX for an invalid index, SUCCESS otherwise.
///
fapi2::ReturnCode spare_index(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_dram_spare0_index,
    const uint8_t i_dram_spare1_index );

///
/// @brief Checks the steer mux input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_steer_type Check for DRAM_SPARE0 or DRAM_SPARE1
/// @return EXP_MAINT_BAD_STEER_MUX_TYPE for an invalid steer type, SUCCESS otherwise.
///
fapi2::ReturnCode mux_type(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const steer_type i_steer_type);

///
/// @brief Checks the symbol input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @return EXP_MAINT_INVALID_SYMBOL for an invalid symbol, SUCCESS otherwise.
///
fapi2::ReturnCode symbol(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_symbol);

///
/// @brief Checks the symbol input for steer functions, but also allows the user to program a value to clear the spare
/// @param[in] i_target Mem Port target
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @return EXP_MAINT_INVALID_SYMBOL for an invalid symbol, SUCCESS otherwise.
/// @note the value to clear the spare is enumerated by EXP_INVALID_SYMBOL
///
fapi2::ReturnCode symbol_or_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_symbol);

} // ns check

///
/// @brief Returns the spare index of the symbol passed in
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @param[out] o_spare_index Index of the spare
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode symbol_to_spare( const uint8_t i_symbol, uint8_t& o_spare_index );

///
/// @brief Gets either the read or write steer mux control register for the given rank
///
/// @tparam mc_type MT - the Mux Type of the registers
/// @tparam steerTraits TT - the traits for the mux rgisters
///
/// @param[in]  i_target Mem Port target
/// @param[in]  i_port_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template< mux_type MT, typename TT = steerTraits<MT> >
fapi2::ReturnCode get_steer_mux(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_port_rank,
    uint8_t& o_dram_spare0_symbol,
    uint8_t& o_dram_spare1_symbol )
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_steer_mux;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramSpare0Index = 0;
    uint8_t l_dramSpare1Index = 0;

    o_dram_spare0_symbol = EXP_INVALID_SYMBOL;
    o_dram_spare1_symbol = EXP_INVALID_SYMBOL;

    // Check for i_port_rank out of range
    // TODO:ZEN306 Add HWP support for planar OCMB
    // Update this function to decode the port rank to be 0-3 for dual drop cases
    //    As of right now, dual drop should be 0,1,4,5
    //    We cannot use DIMM rank as we would have overlap on ranks 0/1
    //    We cannot use PHY rank due to rank swizzling caused by JIRA355
    FAPI_TRY( check::rank(i_target, i_port_rank) );

    // Read Steer Mux
    FAPI_TRY(fapi2::getScom(i_target, TT::MUX_REGISTER, l_steer_mux));

    // Get correct ranks spare data for spare0
    FAPI_TRY(l_steer_mux.extractToRight(l_dramSpare0Index,
                                        TT::get_muxregs_left(i_port_rank),
                                        TT::SPARE_MUX_LEN));

    // Get correct ranks spare data for spare1
    FAPI_TRY(l_steer_mux.extractToRight(l_dramSpare1Index,
                                        TT::get_muxregs_right(i_port_rank),
                                        TT::SPARE_MUX_LEN));

    // Check for spare indeces out of range
    FAPI_TRY( check::spare_index(i_target, l_dramSpare0Index, l_dramSpare1Index) );

    // Return symbol from index or 0xff for unused
    if (l_dramSpare0Index != SPARE_UNUSED)
    {
        o_dram_spare0_symbol = spare_to_symbol[l_dramSpare0Index];
    }

    if (l_dramSpare1Index != SPARE_UNUSED)
    {
        o_dram_spare1_symbol = spare_to_symbol[l_dramSpare1Index];
    }

    FAPI_INF("get_steer_mux(): target = %s, rank%d, spare0 = %d, spare1 = %d",
             mss::c_str(i_target), i_port_rank, o_dram_spare0_symbol, o_dram_spare1_symbol );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the read or write steer mux control register with the steer type for the rank.
///
/// @tparam mc_type MT - the Mux Type of the registers
/// @tparam steerTraits TT - the traits for the mux rgisters
///
/// @param[in] i_target MEM_PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_steer_type DRAM_SPARE0 or DRAM_SPARE1
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template< mux_type MT, typename TT = steerTraits<MT> >
fapi2::ReturnCode put_steer_mux(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_port_rank,
    const steer_type i_steer_type,
    const uint8_t i_symbol )
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_steer_mux;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramSpareIndex = 0;

    // Get rank information
    mss::rank::info<> l_rank_info(i_target, i_port_rank, l_rc);
    FAPI_TRY(l_rc, "%s failed to obtain rank info", mss::c_str(i_target));

    // Check for i_port_rank or i_steer_type or i_symbol out of range
    // TODO:ZEN306 Add HWP support for planar OCMB
    // Update this function to decode the port rank to be 0-3 for dual drop cases
    //    As of right now, dual drop should be 0,1,4,5
    //    We cannot use DIMM rank as we would have overlap on ranks 0/1
    //    We cannot use PHY rank due to rank swizzling caused by JIRA355
    FAPI_TRY( check::rank(i_target, i_port_rank) );
    FAPI_TRY( check::mux_type(i_target, i_steer_type) );

    // Allow the user to write a "clear this value" constant
    FAPI_TRY( check::symbol_or_clear(i_target, i_symbol) );

    // Read Write Mux
    FAPI_TRY(fapi2::getScom(i_target, TT::MUX_REGISTER, l_steer_mux));

    // Convert from i_symbol to Dram Spare Index
    FAPI_TRY( symbol_to_spare(i_symbol, l_dramSpareIndex) );

    // Insert steer data into correct spare
    if (i_steer_type == steer_type::DRAM_SPARE0)
    {
        // Get correct ranks spare data for spare0
        FAPI_TRY(l_steer_mux.insertFromRight(l_dramSpareIndex,
                                             TT::get_muxregs_left(i_port_rank),
                                             TT::SPARE_MUX_LEN));
    }
    else
    {
        // Get correct ranks spare data for spare1
        FAPI_TRY(l_steer_mux.insertFromRight(l_dramSpareIndex,
                                             TT::get_muxregs_right(i_port_rank),
                                             TT::SPARE_MUX_LEN));
    }

    // Write to Write Mux
    FAPI_TRY(fapi2::putScom(i_target, TT::MUX_REGISTER, l_steer_mux));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the steer muxes for the given rank
/// @param[in] i_target MEM_PORT target
/// @param[in] i_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const uint8_t i_rank,
                                 uint8_t& o_dram_spare0_symbol,
                                 uint8_t& o_dram_spare1_symbol );

///
/// @brief Checks if a spare can be deployed or not
/// @param[in] i_target MEM_PORT target
/// @param[in] i_port_rank Rank we want to read steer mux for.
/// @param[out] o_spare0_free True if the spare is free, othewise false
/// @param[out] o_spare1_free True if the spare is free, othewise false
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note Checks that the spare exists, is free of bad bits, and has not been deployed
/// If those three conditions are met, then return true, for that spare, otherwise return false
///
fapi2::ReturnCode check_if_spare_is_free(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_port_rank,
        bool& o_spare0_free,
        bool& o_spare1_free );

///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_steer_type DRAM_SPARE0 or DRAM_SPARE1
/// @param[in] i_symbol First symbol index of the DRAM to steer  around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note Allows the user to manually set or clear one steering mux
///
fapi2::ReturnCode program_steering_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_port_rank,
        const steer_type i_steer_type,
        const uint8_t i_symbol);

///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode do_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const uint8_t i_symbol,
                              const bool i_ignore_bad_bits = false);
} // ns steer

} // ns exp

} // ns mss

#endif
