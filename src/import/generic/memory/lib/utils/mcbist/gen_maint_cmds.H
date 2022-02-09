/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_maint_cmds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
// EKB-Mirror-To: hostboot
///
/// @file gen_maint_cmds.H
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Geetha Pisapati Geetha.Pisapati@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

#ifndef _GEN_MAINT_CMDS_H_
#define _GEN_MAINT_CMDS_H_

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/ecc/galois.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/mss_rank.H>

namespace mss
{
namespace steer
{
///
/// @brief Used to specify steer type
///
enum steer_type : size_t
{
    DRAM_SPARE0 = 0,    // Spare DRAM0
    DRAM_SPARE1 = 1,    // Spare DRAM1
};


///
/// @brief Used to specify read or write steer mux
///
enum class mux_type : size_t
{
    READ_MUX,
    WRITE_MUX,
};

///
/// @class genSteerTraits
/// @brief Generic Steer Mux Register traits
/// @tparam MC the memory controller type
///
template<mss::mc_type MC>
class genSteerTraits;

///
/// @class steerTraits
/// @brief Steer Mux Register traits
/// @tparam MC the memory controller type
/// @tparam MT the read-write steer_mux type
///
template<mss::mc_type MC, mux_type MT >
class steerTraits;

///
/// @class steerTraits
/// @brief MC Steer Traits
/// @tparam MC the memory controller type
/// @tparam MT the read-write steer_mux type
///
template<mss::mc_type MC, mux_type MT>
class steerTraits
{
    public:
        static const std::vector<uint32_t> muxregs_left;
        static const std::vector<uint32_t> muxregs_right;

};

///
/// @brief Returns the location of the spare mux for this rank
/// @tparam MC the memory controller type
/// @tparam MT the read-write mux_type
/// @tparam TT SteerTraits class with mc_type and mux_type
/// @param[in] i_rank the port rank to get the spare location for
/// @note Must be verified as valid port rank by calling function
/// @return the spare mux location in the mux reg
///
template<mss::mc_type MC, mux_type MT, typename TT = steerTraits<MC, MT> >
static uint32_t get_muxregs_left( const uint8_t i_rank )
{
    return TT::muxregs_left[i_rank];
}

///
/// @brief Returns the location of the rank spare mux
/// @tparam MC the memory controller type
/// @tparam MT the read-write mux_type
/// @tparam TT SteerTraits class with mc_type and mux_type
/// @param[in] i_rank the port rank to get the spare location for
/// @note Must be verified as valid port rank by calling function
/// @return the spare mux location in the read mux reg
///
template<mss::mc_type MC, mux_type MT, typename TT = steerTraits<MC, MT> >
static uint32_t get_muxregs_right( const uint8_t i_rank )
{
    return TT::muxregs_right[i_rank];
}

namespace check
{

///
/// @brief Checks the rank input for steer functions
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target Mem Port target
/// @param[in] i_rank Rank input to verify
/// @return <MC>_MAINT_BAD_RANK_INPUT for an invalid rank, SUCCESS otherwise.
///
template<mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode rank(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_port_rank)
{
    // TODO: Zen-1554: Remove EXP_* error codes
    // Check for i_port_rank out of range
    FAPI_ASSERT(i_port_rank < TT::MAX_MRANK_PER_PORT,
                fapi2::EXP_MAINT_BAD_RANK_INPUT()
                .set_PORT_TARGET(i_target)
                .set_RANK(i_port_rank),
                "i_port_rank input to exp steer function out of range on %s.", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks the steer mux input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_steer_type Check for DRAM_SPARE0 or DRAM_SPARE1
/// @return <MC>_MAINT_BAD_STEER_MUX_TYPE for an invalid steer type, SUCCESS otherwise.
///
inline fapi2::ReturnCode mux_type(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const steer_type i_steer_type)
{
    // TODO: Zen-1554: Remove EXP_* error codes
    // Check for i_steer_type out of range
    FAPI_ASSERT(((i_steer_type == steer_type::DRAM_SPARE0)
                 || (i_steer_type == steer_type::DRAM_SPARE1)),
                fapi2::EXP_MAINT_BAD_STEER_MUX_TYPE()
                .set_PORT_TARGET(i_target)
                .set_STEER_TYPE(i_steer_type),
                "i_steer_type input to exp steer function out of range on %s.",
                mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks the symbol input for steer functions
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target Mem Port target
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @return <MC>_MAINT_INVALID_SYMBOL for an invalid symbol, SUCCESS otherwise.
///
template<mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode symbol(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                         const uint8_t i_symbol)
{
    // TODO: Zen-1554: Remove EXP_* error codes
    // Check for i_symbol out of range
    FAPI_ASSERT((i_symbol < TT::MAX_SYMBOLS_PER_PORT),
                fapi2::EXP_MAINT_INVALID_SYMBOL()
                .set_PORT_TARGET(i_target)
                .set_SYMBOL(i_symbol),
                "i_symbol input to put_steer_mux out of range on %s.",
                mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Checks the spare index inputs for steer functions
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target Mem Port target
/// @param[in] i_dram_spare0_index First symbol index of the DRAM fixed by the
///                                spare on port0 (if no steer, return 0xff)
/// @param[in] i_dram_spare1_index First symbol index of the DRAM fixed by the
///                                spare on port1 (if no steer, return 0xff)
/// @return <MC>_MAINT_BAD_SPARE_INDEX for an invalid index, SUCCESS otherwise.
///
template<mss::mc_type MC, typename TT = genSteerTraits<MC> >
fapi2::ReturnCode spare_index(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_dram_spare0_index,
    const uint8_t i_dram_spare1_index )
{
    // TODO: Zen-1554: Remove EXP_* error codes
    // Check for spare indeces out of range
    FAPI_ASSERT(((i_dram_spare0_index < TT::spare_to_symbol.size() || i_dram_spare0_index == TT::SPARE_UNUSED) &&
                 (i_dram_spare1_index < TT::spare_to_symbol.size() || i_dram_spare1_index == TT::SPARE_UNUSED)),
                fapi2::EXP_MAINT_BAD_SPARE_INDEX()
                .set_PORT_TARGET(i_target)
                .set_SPARE0_INDEX(i_dram_spare0_index)
                .set_SPARE1_INDEX(i_dram_spare1_index),
                "Out of range spare index returned from mux register on %s.", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Checks the symbol input for steer functions, but also allows the user to program a value to clear the spare
/// @tparam MC the memory controller
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target Mem Port target
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @return <MC>_MAINT_INVALID_SYMBOL for an invalid symbol, SUCCESS otherwise.
/// @note the value to clear the spare is enumerated by <MC>_INVALID_SYMBOL
///
template<mss::mc_type MC, typename TT = genSteerTraits<MC> >
fapi2::ReturnCode symbol_or_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_symbol)
{
    // If the user passed in a symbol as "clear the spares," return success
    if(i_symbol == TT::INVALID_SYMBOL)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for i_symbol out of range
    return symbol<MC>(i_target,  i_symbol);
}

}// ns check

///
/// @brief Figure out if selected nibble is a non-existent spare in restore_repairs, mc_type specialization
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @param[in] i_byte logical byte index
/// @param[in] i_nibble logical nibble index
/// @return true if selected nibble is a non-existent spare and needs to be skipped
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
bool skip_dne_spare_nibble(const uint8_t i_spare_support,
                           const uint64_t i_byte,
                           const size_t i_nibble)
{

    // The spare nibble is always on the same byte for mc_type, so return false if we're not there
    if (i_byte != TT::SPARE_DQ_BYTE)
    {
        return false;
    }

    // If the spare is the low nibble skip the high nibble, and vice versa
    return (((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_LOW_NIBBLE) && (i_nibble == 1)) ||
            ((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_HIGH_NIBBLE) && (i_nibble == 0)) ||
            (i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE));
}


///
/// @brief Grab a vector of non-spare nibbles - specialization for mc_type
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[out] o_nonspare_nibbles vector of nonspare nibble indices
/// @note mc_type specialization
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
void get_nonspare_nibbles(std::vector<uint8_t>& o_nonspare_nibbles)
{
    o_nonspare_nibbles = TT::NON_SPARE_NIBBLES;
}


///
/// @brief Grab a vector of non-spare nibbles - specialization for mc_type
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target A target representing a DIMM
/// @param[in] i_dimm_rank The DIMM rank for this target
/// @param[out] o_spare_nibbles a vector of bytes/nibbles based upon the MC type
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Vector is a pair of uint8_t's. First is byte. Second is nibble
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode get_spare_nibbles( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const mss::rank::info<MC>& i_rank,
                                     std::vector<uint8_t>& o_spare_nibbles)
{
    // Clear this out. Just. In. Case.
    o_spare_nibbles.clear();

    // Safety check so we don't need an assert here
    const auto l_dimm_rank = i_rank.get_dimm_rank();

    // Grab our spare attribute for this DIMM and rank
    uint8_t l_spare_attr[mss::MAX_RANK_PER_DIMM_ATTR] = {};
    FAPI_TRY(mss::attr::get_dimm_spare(i_target, l_spare_attr));

    // Checks that the nibbles exist and assembles our vector
    for (const auto l_nibble_idx : TT::SPARE_NIBBLES)
    {
        const auto l_byte = l_nibble_idx / NIBBLES_PER_BYTE;
        const auto l_nibble = l_nibble_idx % NIBBLES_PER_BYTE;

        // Skips non-existant spares
        if (skip_dne_spare_nibble<MC>(
                l_spare_attr[l_dimm_rank],
                l_byte,
                l_nibble))
        {
            FAPI_DBG("%s Skip processing bits on rank:%d nibble%d because they are non-existent spares",
                     mss::c_str(i_target), l_dimm_rank, (l_byte * NIBBLES_PER_BYTE) + l_nibble);
            continue;
        }

        // Otherwise, add this to our spare nibbles vector
        o_spare_nibbles.push_back(l_nibble_idx);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Round the symbol from dq_to_symbol to its base multiple of 4, for use with steering
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_symbol symbol from dq_to_symbol
/// @return uint8_t rounded DQ symbol
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
uint8_t symbol_rounder(const uint8_t i_symbol)
{
    // Round down to the multiple of 4
    uint8_t l_symbol = i_symbol;
    l_symbol /= TT::SYMBOL_ROUNDER;
    l_symbol *= TT::SYMBOL_ROUNDER;

    return l_symbol;
}

///
/// @brief Returns the spare index of the symbol passed in
/// @tparam MC the memory controller type
/// @tparam TT genSteerTraits class with mc_type
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @param[out] o_spare_index Index of the spare
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template<mss::mc_type MC, typename TT = genSteerTraits<MC> >
fapi2::ReturnCode symbol_to_spare( const uint8_t i_symbol, uint8_t& o_spare_index )
{
    // If the user passed in the value asking us to clear the spare, then mass back the clear the spare encoding
    if(i_symbol == TT::INVALID_SYMBOL)
    {
        o_spare_index = TT::SPARE_UNUSED;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check if symbol is in table
    const auto l_it = std::find(TT::spare_to_symbol.begin(), TT::spare_to_symbol.end(), i_symbol);

    // TODO: Zen-1554: Remove EXP_* error codes
    FAPI_ASSERT(l_it != TT::spare_to_symbol.end(),
                fapi2::EXP_MAINT_SYMBOL_NOT_FOUND()
                .set_SYMBOL(i_symbol),
                "Invalid symbol for spare index %d.", i_symbol);

    // Get index of spare from iterator
    o_spare_index = std::distance(TT::spare_to_symbol.begin(), l_it);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Gets either the read or write steer mux control register for the given rank
/// @tparam MC the memory controller type
/// @tparam MT the read-write mux_type
/// @tparam TT steerTraits class with mc_type and mux_type
/// @param[in]  i_target Mem Port target
/// @param[in]  i_port_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template<mss::mc_type MC, mss::steer::mux_type MT, typename TT = steerTraits<MC, MT> >
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

    o_dram_spare0_symbol = genSteerTraits<MC>::INVALID_SYMBOL;
    o_dram_spare1_symbol = genSteerTraits<MC>::INVALID_SYMBOL;

    // Check for i_port_rank out of range
    // TODO:ZEN306 Add HWP support for planar OCMB
    // Update this function to decode the port rank to be 0-3 for dual drop cases
    //    As of right now, dual drop should be 0,1,4,5
    //    We cannot use DIMM rank as we would have overlap on ranks 0/1
    //    We cannot use PHY rank due to rank swizzling caused by JIRA355
    FAPI_TRY( check::rank<MC>(i_target, i_port_rank) );

    // Read Steer Mux
    FAPI_TRY(fapi2::getScom(i_target, TT::MUX_REGISTER, l_steer_mux));

    // Get correct ranks spare data for spare0
    FAPI_TRY(l_steer_mux.extractToRight(l_dramSpare0Index,
                                        TT::muxregs_left[i_port_rank],
                                        TT::SPARE_MUX_LEN));

    // Get correct ranks spare data for spare1
    FAPI_TRY(l_steer_mux.extractToRight(l_dramSpare1Index,
                                        TT::muxregs_right[i_port_rank],
                                        TT::SPARE_MUX_LEN));

    // Check for spare indeces out of range
    FAPI_TRY( check::spare_index<MC>(i_target, l_dramSpare0Index, l_dramSpare1Index) );

    // Return symbol from index or 0xff for unused
    if (l_dramSpare0Index != genSteerTraits<MC>::SPARE_UNUSED)
    {
        o_dram_spare0_symbol = genSteerTraits<MC>::spare_to_symbol[l_dramSpare0Index];
    }

    if (l_dramSpare1Index != genSteerTraits<MC>::SPARE_UNUSED)
    {
        o_dram_spare1_symbol = genSteerTraits<MC>::spare_to_symbol[l_dramSpare1Index];
    }

    FAPI_INF("get_steer_mux(): target = %s, rank%d, spare0 = %d, spare1 = %d",
             mss::c_str(i_target), i_port_rank, o_dram_spare0_symbol, o_dram_spare1_symbol );

fapi_try_exit:
    return fapi2::current_err;

}


///
/// @brief Updates the read or write steer mux control register with the steer type for the rank.
/// @tparam MC the memory controller type
/// @tparam MT the re-write mux_type
/// @tparam TT steerTraits class with mc_type and mux_type
/// @param[in] i_target MEM_PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_steer_type DRAM_SPARE0 or DRAM_SPARE1
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template<mss::mc_type MC, mss::steer::mux_type MT, typename TT = steerTraits<MC, MT> >
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
    mss::rank::info<MC> l_rank_info(i_target, i_port_rank, l_rc);
    FAPI_TRY(l_rc, "%s failed to obtain rank info", mss::c_str(i_target));

    // Check for i_port_rank or i_steer_type or i_symbol out of range
    // TODO:ZEN306 Add HWP support for planar OCMB
    // Update this function to decode the port rank to be 0-3 for dual drop cases
    //    As of right now, dual drop should be 0,1,4,5
    //    We cannot use DIMM rank as we would have overlap on ranks 0/1
    //    We cannot use PHY rank due to rank swizzling caused by JIRA355
    FAPI_TRY( check::rank<MC>(i_target, i_port_rank) );
    FAPI_TRY( check::mux_type(i_target, i_steer_type) );

    // Allow the user to write a "clear this value" constant
    FAPI_TRY( check::symbol_or_clear<MC>(i_target, i_symbol) );

    // Read Write Mux
    FAPI_TRY(fapi2::getScom(i_target, TT::MUX_REGISTER, l_steer_mux));

    // Convert from i_symbol to Dram Spare Index
    FAPI_TRY( symbol_to_spare<MC>(i_symbol, l_dramSpareIndex) );

    // Insert steer data into correct spare
    if (i_steer_type == steer_type::DRAM_SPARE0)
    {
        // Get correct ranks spare data for spare0
        FAPI_TRY(l_steer_mux.insertFromRight(l_dramSpareIndex,
                                             TT::muxregs_left[i_port_rank],
                                             TT::SPARE_MUX_LEN));
    }
    else
    {
        // Get correct ranks spare data for spare1
        FAPI_TRY(l_steer_mux.insertFromRight(l_dramSpareIndex,
                                             TT::muxregs_right[i_port_rank],
                                             TT::SPARE_MUX_LEN));
    }

    // Write to Write Mux
    FAPI_TRY(fapi2::putScom(i_target, TT::MUX_REGISTER, l_steer_mux));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Reads the steer muxes for the given rank
/// @tparam MC the memory controller type
/// @param[in] i_target MEM_PORT target
/// @param[in] i_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template<mss::mc_type MC>
fapi2::ReturnCode check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const uint8_t i_port_rank,
                                 uint8_t& o_dram_spare0_symbol,
                                 uint8_t& o_dram_spare1_symbol )
{
    // Get the read steer mux, with the assuption
    // that the write mux will be the same.
    return get_steer_mux<MC, mux_type::READ_MUX>(i_target,
            i_port_rank,
            o_dram_spare0_symbol,
            o_dram_spare1_symbol);
}


///
/// @brief Checks if a spare can be deployed or not
/// @tparam MC the memory controller type
/// @tparam TT genSteerTraits class with mc_type
/// @param[in] i_target MEM_PORT target
/// @param[in] i_port_rank Rank we want to read steer mux for
/// @param[in] i_ignore_bad_bits True to ignore, otherwise false
/// @param[out] o_spare0_free True if the spare is free, othewise false
/// @param[out] o_spare1_free True if the spare is free, othewise false
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
/// @note Checks that the spare exists, is free of bad bits, and has not been deployed
/// If those three conditions are met, then return true, for that spare, otherwise return false
///
template<mss::mc_type MC, typename TT = genSteerTraits<MC> >
fapi2::ReturnCode check_if_spare_is_free(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_port_rank,
        const bool i_ignore_bad_bits,
        bool& o_spare0_free,
        bool& o_spare1_free )
{
    constexpr uint8_t SPARE0_MASK = 0xf0;
    constexpr uint8_t SPARE1_MASK = 0x0f;
    constexpr uint8_t SPARE_FREE = TT::INVALID_SYMBOL;

    // If we have errors, we can't be sure we have spares, mark em as bad
    o_spare0_free = false;
    o_spare1_free = false;

    // Variable declaration
    uint8_t l_dimm_spare[MAX_RANK_PER_DIMM_ATTR] = {0};
    uint8_t l_bad_bits[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};
    bool l_spare0_exists = false;
    bool l_spare1_exists = false;
    bool l_spare0_is_clean = true;
    bool l_spare1_is_clean = true;
    uint8_t l_dram_spare0_symbol = 0;
    uint8_t l_dram_spare1_symbol = 0;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    mss::rank::info<MC> l_rank_info(i_target, i_port_rank, l_rc);
    FAPI_TRY(l_rc, "%s failed to obtain rank info", mss::c_str(i_target));
    // 1) Checks if the spares exist
    FAPI_TRY(mss::attr::get_dimm_spare(l_rank_info.get_dimm_target(), l_dimm_spare));
    // The logic is inverted to what we want. True means the spare doesn't exist when returned out of the function
    l_spare0_exists = !mss::steer::skip_dne_spare_nibble<MC>(l_dimm_spare[l_rank_info.get_dimm_rank()],
                      portTraits<MC>::SPARE_DQ_BYTE, 0);
    l_spare1_exists = !mss::steer::skip_dne_spare_nibble<MC>(l_dimm_spare[l_rank_info.get_dimm_rank()],
                      portTraits<MC>::SPARE_DQ_BYTE, 1);

    // 2) Checks if the spare is clear of errors (only if we need to)
    if (!i_ignore_bad_bits)
    {
        FAPI_TRY(mss::attr::get_bad_dq_bitmap(l_rank_info.get_dimm_target(), l_bad_bits));

        l_spare0_is_clean = !(l_bad_bits[l_rank_info.get_dimm_rank()][portTraits<MC>::SPARE_DQ_BYTE] & SPARE0_MASK);
        l_spare1_is_clean = !(l_bad_bits[l_rank_info.get_dimm_rank()][portTraits<MC>::SPARE_DQ_BYTE] & SPARE1_MASK);
    }

    // 3) Checks if the spare has been deployed
    FAPI_TRY((check_steering<MC>(i_target, i_port_rank, l_dram_spare0_symbol, l_dram_spare1_symbol)));

    // Assembles all of the information - the spare is only free if all of the bellow are true
    o_spare0_free = l_spare0_exists && l_spare0_is_clean && (l_dram_spare0_symbol == SPARE_FREE);
    o_spare1_free = l_spare1_exists && l_spare1_is_clean && (l_dram_spare1_symbol == SPARE_FREE);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @tparam MC the memory controller type
/// @tparam TT the portTraits class with mc_type
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_steer_type DRAM_SPARE0 or DRAM_SPARE1
/// @param[in] i_symbol First symbol index of the DRAM to steer  around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note Allows the user to manually set or clear one steering mux
///
template<mss::mc_type MC, typename TT = portTraits<MC>>
fapi2::ReturnCode program_steering_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_port_rank,
        const steer_type i_steer_type,
        const uint8_t i_symbol)
{
    // Note: we check the rank and mux type in put_steer_mux, so we're not rechecking them here

    //------------------------------------------------------
    // Update write mux
    //------------------------------------------------------
    FAPI_TRY( (put_steer_mux<MC, mss::steer::mux_type::WRITE_MUX>(
                   i_target,               // MEM PORT
                   i_port_rank,            // Rank: 0-7
                   i_steer_type,           // DRAM_SPARE0/DRAM_SPARE1
                   i_symbol)) );           // First symbol index of DRAM to steer around


    //------------------------------------------------------
    // Wait for a periodic cal.
    //------------------------------------------------------
    fapi2::delay(TT::HW_STEERING_DELAY, TT::SIM_STEERING_DELAY);

    //------------------------------------------------------
    // Update read mux
    //------------------------------------------------------
    FAPI_TRY( (put_steer_mux<MC, mss::steer::mux_type::READ_MUX>(
                   i_target,               // MEM PORT
                   i_port_rank,            // Rank: 0-7
                   i_steer_type,           // DRAM_SPARE0/DRAM_SPARE1
                   i_symbol)) );             // First symbol index of DRAM to steer around

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @tparam MC the memory controller type
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
template<mss::mc_type MC>
fapi2::ReturnCode do_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const uint8_t i_symbol,
                              const bool i_ignore_bad_bits = false)
{
    bool l_spare0_free = false;
    bool l_spare1_free = false;
    steer_type l_target_spare;

    // Check for i_port_rank or i_symbol out of range
    FAPI_TRY( check::rank<MC>(i_target, i_port_rank) );

    // If we're doing steering, we can't be clearing a steer, only check for a valid symbol
    FAPI_TRY( (mss::steer::check::symbol<MC, portTraits<MC>> (i_target, i_symbol)) );

    //------------------------------------------------------
    // Determine which spare is free
    //------------------------------------------------------
    FAPI_TRY( (check_if_spare_is_free<MC>(i_target, i_port_rank, i_ignore_bad_bits, l_spare0_free, l_spare1_free)) );

    // TODO: Zen-1554: Remove EXP_* error codes
    // If neither spare is free, assert out
    FAPI_ASSERT(l_spare0_free || l_spare1_free,
                fapi2::EXP_MAINT_DO_STEER_ALL_SPARES_DEPLOYED()
                .set_PORT_TARGET(i_target)
                .set_RANK(i_port_rank)
                .set_SYMBOL(i_symbol),
                "Both Spare0 and Spare1 are already deployed on %s rank %u symbol %u.",
                mss::c_str(i_target), i_port_rank, i_symbol);

    // Default to using spare 0 first
    l_target_spare = l_spare0_free ? steer_type::DRAM_SPARE0 : steer_type::DRAM_SPARE1;
    FAPI_TRY( (program_steering_helper<MC>(i_target, i_port_rank, l_target_spare, i_symbol)) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Deploys a spare and marks it as deployed
/// @tparam MC the memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_target A target representing a DIMM
/// @param[in] i_dimm_rank The DIMM rank for this target
/// @param[in] i_nibble_idx Index of the nibble to spare out
/// @param[in] i_spare_nibbles a vector of bytes/nibbles for the spare nibbles
/// @param[in,out] io_deployed_spares a vector of bytes/nibbles containing which byte/nibble is spared out
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Vector is a pair of uint8_t's. First is byte. Second is nibble
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode deploy_spare_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const mss::rank::info<MC>& i_rank,
                                       const uint8_t i_nibble_idx,
                                       const std::vector<uint8_t>& i_spare_nibbles,
                                       std::vector<uint8_t>& io_deployed_spares,
                                       const bool i_ignore_bad_bits)
{

    const auto MAX_NIBBLE_IDX = TT::MAX_NIBBLE_IDX;

    // Sanity check that we have not gone out of bounds. This shouldn't occur
    FAPI_ASSERT((i_nibble_idx <= MAX_NIBBLE_IDX),
                fapi2::MSS_RESTORE_REPAIRS_NIBBLE_OUT_OF_RANGE()
                .set_DIMM_TARGET(i_target)
                .set_NIBBLE_IDX(i_nibble_idx)
                .set_MAX_NIBBLE_IDX(MAX_NIBBLE_IDX),
                "%s Nibble index %u provided to deploy_spare_helper was beyond the max nibble index %u",
                mss::c_str(i_target), i_nibble_idx, MAX_NIBBLE_IDX);

    {
        // Grab nibble and byte
        const auto l_byte = i_nibble_idx / NIBBLES_PER_BYTE;
        const auto l_nibble = i_nibble_idx % NIBBLES_PER_BYTE;

        // Deploy that spare
        uint8_t l_symbol = 0;
        const uint8_t l_dq = (l_byte * BITS_PER_BYTE) + (l_nibble * BITS_PER_NIBBLE);

        FAPI_TRY( mss::ecc::dq_to_symbol<MC>(l_dq, l_symbol));

        // Round the symbol down to the nearest multiple of 4
        l_symbol = (symbol_rounder<MC>(l_symbol));

        // Conversion from DQ -> Symbol -> Spare goes like this:
        //
        // The mapping table for a set of 4 DQ bits / symbols / spare index looks like this:
        // Arbitrarily choosing spare index 5 as an example
        //
        // +---------+--------------+-------------+
        // | OCMB DQ | Symbol Index | Spare Index |
        // +---------+--------------+-------------+
        // |      20 |           31 |           5 |
        // |      21 |           30 |           5 |
        // |      22 |           29 |           5 |
        // |      23 |           28 |           5 |
        // +---------+--------------+-------------+
        // The DQ values are generated from the byte and nibble index and will always be the "first" value
        // in the DQ list for a spare index, in this case the one divisible by 4 (20 in the above example)
        // When fed into dq_to_symbol, we get out a 31. However, our symbol_to_spare table makes use of the
        // "last" value in the symbol index column (28), and the translation to that one is always to subtract
        // 3. So our translation looks like this for the above example:

        // DQ 20 -> Symbol Index 31 -> Symbol Index 28 -> Spare Index 5

        FAPI_TRY( (mss::steer::do_steering<MC>(i_rank.get_port_target(),
                                               i_rank.get_port_rank(),
                                               l_symbol,
                                               i_ignore_bad_bits)) );

        // Mark this spare as deployed and note which nibble is deployed
        io_deployed_spares.push_back(i_nibble_idx);
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Undeploy the specified spare on the provided rank
/// @tparam MC memory controller type
/// @tparam TT portTraits class with mc_type
/// @param[in] i_spare spare number (0 or 1 for mc_type)
/// @param[in] i_rank rank info object
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template< mss::mc_type MC, typename TT = portTraits<MC> >
fapi2::ReturnCode unspare(const size_t i_spare,
                          const mss::rank::info<MC>& i_rank)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    using WM = mss::steer::steerTraits<MC, mss::steer::mux_type::WRITE_MUX>;
    using RM = mss::steer::steerTraits<MC, mss::steer::mux_type::READ_MUX>;

    fapi2::buffer<uint64_t> l_steer_mux_wr;
    fapi2::buffer<uint64_t> l_steer_mux_rd;

    const auto& l_port = i_rank.get_port_target();
    const auto l_port_rank = i_rank.get_port_rank();

    // Check for i_port_rank or i_spare or i_symbol out of range
    FAPI_TRY(mss::steer::check::rank<MC>(l_port, i_rank.get_port_rank()));
    FAPI_TRY(mss::steer::check::mux_type(l_port,
                                         static_cast<mss::steer::steer_type>(i_spare)));

    FAPI_TRY(fapi2::getScom(l_port, WM::MUX_REGISTER, l_steer_mux_wr));
    FAPI_TRY(fapi2::getScom(l_port, RM::MUX_REGISTER, l_steer_mux_rd));

    // Insert steer data into correct spare
    if (i_spare == 0)
    {
        // Get correct ranks spare data for spare0
        FAPI_TRY(l_steer_mux_wr.insertFromRight(mss::steer::genSteerTraits<MC>::SPARE_UNUSED,
                                                mss::steer::get_muxregs_left<MC, mss::steer::mux_type::WRITE_MUX>(l_port_rank),
                                                WM::SPARE_MUX_LEN));

        FAPI_TRY(l_steer_mux_rd.insertFromRight(mss::steer::genSteerTraits<MC>::SPARE_UNUSED,
                                                mss::steer::get_muxregs_left<MC, mss::steer::mux_type::READ_MUX>(l_port_rank),
                                                RM::SPARE_MUX_LEN));
    }
    else
    {
        // Get correct ranks spare data for spare1
        FAPI_TRY(l_steer_mux_wr.insertFromRight(mss::steer::genSteerTraits<MC>::SPARE_UNUSED,
                                                mss::steer::get_muxregs_right<MC, mss::steer::mux_type::WRITE_MUX>(l_port_rank),
                                                WM::SPARE_MUX_LEN));

        FAPI_TRY(l_steer_mux_rd.insertFromRight(mss::steer::genSteerTraits<MC>::SPARE_UNUSED,
                                                mss::steer::get_muxregs_right<MC, mss::steer::mux_type::READ_MUX>(l_port_rank),
                                                RM::SPARE_MUX_LEN));
    }

    FAPI_TRY(fapi2::putScom(l_port, WM::MUX_REGISTER, l_steer_mux_wr));
    FAPI_TRY(fapi2::putScom(l_port, RM::MUX_REGISTER, l_steer_mux_rd));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns steer

} // ns mss

#endif
