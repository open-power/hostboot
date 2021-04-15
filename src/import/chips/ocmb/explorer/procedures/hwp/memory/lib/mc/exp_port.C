/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.C $ */
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
/// @file exp_port.C
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <exp_port.H>
#include <lib/mcbist/exp_maint_cmds.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>

namespace mss
{

///
/// @brief Set up memory controller specific settings for ECC registers (at the end of draminit_mc)
/// @param[in] i_target the target
/// @param[in,out] io_data contents of RECR register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note mc_type::EXPLORER specialization
///
template< >
fapi2::ReturnCode ecc_reg_settings_draminit_mc<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& io_data )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_ctcr_data;

    // Explorer specific settings for RECR
    io_data.setBit<TT::RECR_ENABLE_MPE_NOISE_WINDOW>();
    io_data.setBit<TT::RECR_RETRY_UNMARKED_ERRORS>();
    io_data.clearBit<TT::RECR_CFG_MAINT_USE_TIMERS>();

    // Set up CTCR timers to 20x4^3 (1280 clock cycles; typical read latency is 120ish, so this is about 10x)
    // This is a preliminary guess from the design team. Also enable UE lockout window
    // CTCR -> 51A8E00000000000
    FAPI_TRY( mss::getScom(i_target, TT::CTCR_REG, l_ctcr_data) );

    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMER, TT::CTCR_MPE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMEBASE, TT::CTCR_MPE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMER, TT::CTCR_UE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMEBASE, TT::CTCR_UE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.setBit<TT::CTCR_UE_LOCKOUT_ENABLE>();

    FAPI_TRY( mss::putScom(i_target, TT::CTCR_REG, l_ctcr_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable the MC Periodic calibration functionality
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note EXPLORER, OCMB_CHIP specialization
///
template<>
fapi2::ReturnCode enable_periodic_cal<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    // Settings: INTERVAL = 16K * 128 = 2M cycles, CTRLUPD_MIN = 128
    constexpr uint8_t CAL_INTERVAL_TB_16384_CYCLES = 0x02;
    constexpr uint16_t CAL_INTERVAL_VALUE = 0x0080;
    constexpr uint16_t CAL_CTRLUPD_MIN_VALUE = 0x0080;

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::FARB9Q_REG, l_data) );

    // Set up noise window triggered calibration
    l_data.setBit<TT::CFG_CTRLUPD_AFTER_ERR>();

    // Set up periodic calibration
    l_data.setBit<TT::CFG_MC_PER_CAL_ENABLE>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL_TB,
                           TT::CFG_MC_PER_CAL_INTERVAL_TB_LEN>(CAL_INTERVAL_TB_16384_CYCLES);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_INTERVAL,
                           TT::CFG_MC_PER_CAL_INTERVAL_LEN>(CAL_INTERVAL_VALUE);
    l_data.clearBit<TT::CFG_MC_PER_CAL_FIXED_RUN_LENGTH_EN>();
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_RUN_LENGTH,
                           TT::CFG_MC_PER_CAL_RUN_LENGTH_LEN>(0);
    l_data.insertFromRight<TT::CFG_MC_PER_CAL_CTRLUPD_MIN,
                           TT::CFG_MC_PER_CAL_CTRLUPD_MIN_LEN>(CAL_CTRLUPD_MIN_VALUE);

    FAPI_TRY( mss::putScom(i_target, TT::FARB9Q_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the number of bytes to check in restore_repairs, mc_type EXPLORER specialization
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @return total number of bytes
///
template<>
uint64_t get_total_bytes<mss::mc_type::EXPLORER>(const uint8_t i_spare_support)
{
    using MT = mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

    constexpr uint64_t MAX_DQ_BYTES = MT::MAX_DQ_NIBBLES / mss::conversions::NIBBLES_PER_BYTE;

    return MAX_DQ_BYTES;
}

///
/// @brief Figure out if selected nibble is a non-existent spare in restore_repairs, mc_type EXPLORER specialization
/// @param[in] i_spare_support value of ATTR_DIMM_SPARE for this [DIMM][RANK] combo
/// @param[in] i_byte logical byte index
/// @param[in] i_nibble logical nibble index
/// @return true if selected nibble is a non-existent spare and needs to be skipped
///
template<>
bool skip_dne_spare_nibble<mss::mc_type::EXPLORER>(const uint8_t i_spare_support,
        const uint64_t i_byte,
        const size_t i_nibble)
{
    // Note: restore repairs and our ECC logic use the MC/DFI perspective
    // As such, our spare is located on byte 5
    constexpr uint64_t SPARE_DQ_BYTE = 5;

    // The spare nibble is always on the same byte for Explorer, so return false if we're not there
    if (i_byte != SPARE_DQ_BYTE)
    {
        return false;
    }

    // If the spare is the low nibble skip the high nibble, and vice versa
    return (((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_LOW_NIBBLE) && (i_nibble == 1)) ||
            ((i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_HIGH_NIBBLE) && (i_nibble == 0)) ||
            (i_spare_support == fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE));
}

///
/// @brief Grab a vector of non-spare nibbles - specialization for explorer
/// @param[out] o_nonspare_nibbles vector of nonspare nibble indices
/// @note EXPLORER specialization
///
template<>
void get_nonspare_nibbles<mss::mc_type::EXPLORER>(std::vector<uint8_t>& o_nonspare_nibbles)
{
    static const std::vector<uint8_t> NIBBLES =
    {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        // Byte 5 contains the spares (if they exist) for explorer
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        19,
    };

    o_nonspare_nibbles = NIBBLES;
}

///
/// @brief Grab a vector of non-spare nibbles - specialization for explorer
/// @param[in] i_target A target representing a DIMM
/// @param[in] i_dimm_rank The DIMM rank for this target
/// @param[out] o_spare_nibbles a vector of bytes/nibbles based upon the MC type
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Vector is a pair of uint8_t's. First is byte. Second is nibble
///
template<>
fapi2::ReturnCode get_spare_nibbles<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::rank::info<mss::mc_type::EXPLORER>& i_rank,
        std::vector<uint8_t>& o_spare_nibbles)
{
    static const std::vector<uint8_t> NIBBLES =
    {
        // Byte 5 contains the spares (if they exist) for explorer
        10,
        11
    };

    // Clear this out. Just. In. Case.
    o_spare_nibbles.clear();

    // Safety check so we don't need an assert here
    const auto l_dimm_rank = i_rank.get_dimm_rank();

    // Grab our spare attribute for this DIMM and rank
    uint8_t l_spare_attr[mss::MAX_RANK_PER_DIMM_ATTR] = {};
    FAPI_TRY(mss::attr::get_dimm_spare(i_target, l_spare_attr));

    // Checks that the nibbles exist and assembles our vector
    for (const auto l_nibble_idx : NIBBLES)
    {
        const auto l_byte = l_nibble_idx / NIBBLES_PER_BYTE;
        const auto l_nibble = l_nibble_idx % NIBBLES_PER_BYTE;

        // Skips non-existant spares
        if (skip_dne_spare_nibble<mss::mc_type::EXPLORER>(
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
/// @param[in] i_symbol symbol from dq_to_symbol
/// @return uint8_t rounded DQ symbol
///
uint8_t symbol_rounder(const uint8_t i_symbol)
{
    constexpr uint8_t SYMBOL_ROUNDER = 4;

    // Round down to the multiple of 4
    uint8_t l_symbol = i_symbol;
    l_symbol /= SYMBOL_ROUNDER;
    l_symbol *= SYMBOL_ROUNDER;

    return l_symbol;
}

///
/// @brief Deploys a spare and marks it as deployed
/// @tparam MC the memory controller type
/// @param[in] i_target A target representing a DIMM
/// @param[in] i_dimm_rank The DIMM rank for this target
/// @param[in] i_nibble_idx Index of the nibble to spare out
/// @param[in] i_spare_nibbles a vector of bytes/nibbles for the spare nibbles
/// @param[in,out] io_deployed_spares a vector of bytes/nibbles containing which byte/nibble is spared out
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Vector is a pair of uint8_t's. First is byte. Second is nibble
///
template<>
fapi2::ReturnCode deploy_spare_helper<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::rank::info<mss::mc_type::EXPLORER>& i_rank,
        const uint8_t i_nibble_idx,
        const std::vector<uint8_t>& i_spare_nibbles,
        std::vector<uint8_t>& io_deployed_spares,
        const bool i_ignore_bad_bits)
{
    using PT = mss::portTraits<mss::mc_type::EXPLORER>;

    const auto MAX_NIBBLE_IDX = PT::MAX_NIBBLE_IDX;

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

        FAPI_TRY( mss::ecc::dq_to_symbol<mss::mc_type::EXPLORER>(l_dq, l_symbol));

        // Round the symbol down to the nearest multiple of 4
        l_symbol = symbol_rounder(l_symbol);

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

        FAPI_TRY(mss::exp::steer::do_steering(i_rank.get_port_target(),
                                              i_rank.get_port_rank(),
                                              l_symbol,
                                              i_ignore_bad_bits));

        // Grab the next free spare to deploy
        io_deployed_spares.push_back(i_nibble_idx);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Undeploy the specified spare on the provided rank
/// @tparam MC MC type
/// @param[in] i_spare spare number (0 or 1 for explorer)
/// @param[in] i_rank rank info object
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<>
fapi2::ReturnCode unspare<mss::mc_type::EXPLORER>(const size_t i_spare, const mss::rank::info<>& i_rank)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    using WM = mss::exp::steer::steerTraits<mss::exp::steer::mux_type::WRITE_MUX>;
    using RM = mss::exp::steer::steerTraits<mss::exp::steer::mux_type::READ_MUX>;

    fapi2::buffer<uint64_t> l_steer_mux_wr;
    fapi2::buffer<uint64_t> l_steer_mux_rd;

    const auto& l_port = i_rank.get_port_target();
    const auto l_port_rank = i_rank.get_port_rank();

    // Check for i_port_rank or i_spare or i_symbol out of range
    FAPI_TRY(mss::exp::steer::check::rank(l_port, i_rank.get_port_rank()));
    FAPI_TRY(mss::exp::steer::check::mux_type(l_port,
             static_cast<mss::exp::steer::steer_type>(i_spare)));

    FAPI_TRY(fapi2::getScom(l_port, WM::MUX_REGISTER, l_steer_mux_wr));
    FAPI_TRY(fapi2::getScom(l_port, RM::MUX_REGISTER, l_steer_mux_rd));

    // Insert steer data into correct spare
    if (i_spare == 0)
    {
        // Get correct ranks spare data for spare0
        FAPI_TRY(l_steer_mux_wr.insertFromRight(mss::exp::steer::SPARE_UNUSED,
                                                WM::get_muxregs_left(l_port_rank),
                                                WM::SPARE_MUX_LEN));

        FAPI_TRY(l_steer_mux_rd.insertFromRight(mss::exp::steer::SPARE_UNUSED,
                                                RM::get_muxregs_left(l_port_rank),
                                                RM::SPARE_MUX_LEN));
    }
    else
    {
        // Get correct ranks spare data for spare1
        FAPI_TRY(l_steer_mux_wr.insertFromRight(mss::exp::steer::SPARE_UNUSED,
                                                WM::get_muxregs_right(l_port_rank),
                                                WM::SPARE_MUX_LEN));

        FAPI_TRY(l_steer_mux_rd.insertFromRight(mss::exp::steer::SPARE_UNUSED,
                                                RM::get_muxregs_right(l_port_rank),
                                                RM::SPARE_MUX_LEN));
    }

    FAPI_TRY(fapi2::putScom(l_port, WM::MUX_REGISTER, l_steer_mux_wr));
    FAPI_TRY(fapi2::putScom(l_port, RM::MUX_REGISTER, l_steer_mux_rd));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure clock stabilization time field
/// @param[in] i_target the OCMB target to operate on
/// @param[in] i_has_rcd flag to signify existence of RCD on DIMM
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode configure_tstab(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const bool i_has_rcd)
{
    fapi2::buffer<uint64_t> l_reg_data = 0;
    // Clock stabilization time with an RCD on the DIMM is 5us
    constexpr uint8_t tstab_val = 5;

    FAPI_TRY(mss::getScom(i_target, EXPLR_SRQ_MBAREFAQ, l_reg_data));

    // tSTAB should be 5us if RCD exists, otherwise default of 0
    l_reg_data.insertFromRight<EXPLR_SRQ_MBAREFAQ_CFG_TSTAB,
                               EXPLR_SRQ_MBAREFAQ_CFG_TSTAB_LEN>
                               (i_has_rcd ? tstab_val : 0);

    FAPI_TRY(mss::putScom(i_target, EXPLR_SRQ_MBAREFAQ, l_reg_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


}// namespace mss
