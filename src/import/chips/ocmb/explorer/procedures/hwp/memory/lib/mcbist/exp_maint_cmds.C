/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_maint_cmds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_maint_cmds.C
/// @brief Utility functions for accessing steer muxes.
///
/// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <lib/mcbist/exp_maint_cmds.H>
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
/// @brief Used to determine spare info for Spare0 WriteMux
///
const std::vector< uint32_t > steerTraits< mux_type::WRITE_MUX >::write_muxregs_left =
{
    EXPLR_WDF_WSPAR_CFG_STEERING_R0_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R1_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R2_LEFT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R3_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 WriteMux
///
const std::vector< uint32_t > steerTraits< mux_type::WRITE_MUX >::write_muxregs_right =
{
    EXPLR_WDF_WSPAR_CFG_STEERING_R0_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R1_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R2_RIGHT,
    EXPLR_WDF_WSPAR_CFG_STEERING_R3_RIGHT,
};

///
/// @brief Used to determine spare info for Spare0 ReadMux
///
const std::vector< uint32_t > steerTraits< mux_type::READ_MUX >::read_muxregs_left =
{
    EXPLR_RDF_RSPAR_CFG_STEERING_R0_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R1_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R2_LEFT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R3_LEFT,
};

///
/// @brief Used to determine spare info for Spare1 ReadMux
///
const std::vector< uint32_t > steerTraits< mux_type::READ_MUX >::read_muxregs_right =
{
    EXPLR_RDF_RSPAR_CFG_STEERING_R0_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R1_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R2_RIGHT,
    EXPLR_RDF_RSPAR_CFG_STEERING_R3_RIGHT,
};

namespace check
{

///
/// @brief Checks the rank input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_port_rank Rank input to verify
/// @return EXP_MAINT_BAD_RANK_INPUT for an invalid rank, SUCCESS otherwise.
///
fapi2::ReturnCode rank(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_port_rank)
{
    // Check for i_port_rank out of range
    FAPI_ASSERT(i_port_rank < MAX_MRANK_PER_PORT,
                fapi2::EXP_MAINT_BAD_RANK_INPUT()
                .set_PORT_TARGET(i_target)
                .set_RANK(i_port_rank),
                "i_port_rank input to exp steer function out of range on %s.", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

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
    const uint8_t i_dram_spare1_index )
{
    // Check for spare indeces out of range
    FAPI_ASSERT(((i_dram_spare0_index < spare_to_symbol.size() || i_dram_spare0_index == SPARE_UNUSED) &&
                 (i_dram_spare1_index < spare_to_symbol.size() || i_dram_spare1_index == SPARE_UNUSED)),
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
/// @brief Checks the steer mux input for steer functions
/// @param[in] i_target Mem Port target
/// @param[in] i_steer_type Check for DRAM_SPARE0 or DRAM_SPARE1
/// @return EXP_MAINT_BAD_STEER_MUX_TYPE for an invalid steer type, SUCCESS otherwise.
///
fapi2::ReturnCode mux_type(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const steer_type i_steer_type)
{
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
/// @param[in] i_target Mem Port target
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @return EXP_MAINT_INVALID_SYMBOL for an invalid symbol, SUCCESS otherwise.
///
fapi2::ReturnCode symbol(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint8_t i_symbol)
{
    // Check for i_symbol out of range
    FAPI_ASSERT((i_symbol < mss::exp::MAX_SYMBOLS_PER_PORT),
                fapi2::EXP_MAINT_INVALID_SYMBOL()
                .set_PORT_TARGET(i_target)
                .set_SYMBOL(i_symbol),
                "i_symbol input to put_steer_mux out of range on %s.",
                mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns check

///
/// @brief  Returns the spare index of the symbol passed in
/// @param[in] i_symbol First symbol index of the DRAM Spare
/// @param[out] o_spare_index Index of the spare
/// @note The index of the symbol in the vector matches the spare index
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode symbol_to_spare( const uint8_t i_symbol, uint8_t& o_spare_index )
{
    // Check if symbol is in table
    const auto l_it = std::find(spare_to_symbol.begin(), spare_to_symbol.end(), i_symbol);

    FAPI_ASSERT(l_it != spare_to_symbol.end(),
                fapi2::EXP_MAINT_SYMBOL_NOT_FOUND()
                .set_SYMBOL(i_symbol),
                "Invalid symbol for spare index %d.", i_symbol);

    // Get index of spare from iterator
    o_spare_index = std::distance(spare_to_symbol.begin(), l_it);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the steer muxes for the given rank
/// @param[in] i_target MEM_PORT target
/// @param[in] i_port_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 const uint8_t i_port_rank,
                                 uint8_t& o_dram_spare0_symbol,
                                 uint8_t& o_dram_spare1_symbol )
{
    // Get the read steer mux, with the assuption
    // that the write mux will be the same.
    return get_steer_mux<mux_type::READ_MUX>(i_target,
            i_port_rank,
            o_dram_spare0_symbol,
            o_dram_spare1_symbol);
}

///
/// @brief  Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_symbol First symbol index of the DRAM to steer  around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode do_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const uint8_t i_symbol)
{
    constexpr uint64_t  HW_MODE_DELAY = (250 * mss::DELAY_1MS);
    // 200000 sim cycle delay for SIM mode
    constexpr uint64_t  SIM_MODE_DELAY = (2 * mss::DELAY_100US);

    uint8_t l_spare0_symbol = 0;
    uint8_t l_spare1_symbol = 0;
    steer_type l_target_spare;

    // Check for i_port_rank or i_symbol out of range
    FAPI_TRY( check::rank(i_target, i_port_rank) );
    FAPI_TRY( check::symbol(i_target, i_symbol) );

    //------------------------------------------------------
    // Determine which spare is free
    //------------------------------------------------------
    FAPI_TRY(check_steering(i_target, i_port_rank, l_spare0_symbol, l_spare1_symbol));

    if (l_spare0_symbol == EXP_INVALID_SYMBOL)
    {
        l_target_spare = steer_type::DRAM_SPARE0;
    }
    else if (l_spare1_symbol == EXP_INVALID_SYMBOL)
    {
        l_target_spare = steer_type::DRAM_SPARE1;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::EXP_MAINT_DO_STEER_ALL_SPARES_DEPLOYED()
                    .set_PORT_TARGET(i_target)
                    .set_RANK(i_port_rank)
                    .set_SYMBOL(i_symbol),
                    "Both Spare0 and Spare1 are already deployed on %s.",
                    mss::c_str(i_target));
    }

    //------------------------------------------------------
    // Update write mux
    //------------------------------------------------------
    FAPI_TRY(put_steer_mux<mux_type::WRITE_MUX>(
                 i_target,               // MEM PORT
                 i_port_rank,            // Rank: 0-7
                 l_target_spare,         // DRAM_SPARE0/DRAM_SPARE1
                 i_symbol));             // First symbol index of DRAM to steer around


    //------------------------------------------------------
    // Wait for a periodic cal.
    //------------------------------------------------------
    fapi2::delay(HW_MODE_DELAY, SIM_MODE_DELAY);

    //------------------------------------------------------
    // Update read mux
    //------------------------------------------------------
    FAPI_TRY(put_steer_mux<mux_type::READ_MUX>(
                 i_target,               // MEM PORT
                 i_port_rank,            // Rank: 0-7
                 l_target_spare,         // DRAM_SPARE0/DRAM_SPARE1
                 i_symbol));             // First symbol index of DRAM to steer around

fapi_try_exit:
    return fapi2::current_err;
}

} // ns steer

} // ns exp

} // ns mss
