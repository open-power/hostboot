/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_enable_utils.C $ */
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
/// @file pmic_enable_utils.C
/// @brief Utility functions for PMIC enable operation
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_enable_utils.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/poll.H>

namespace mss
{
namespace gpio
{

///
/// @brief Poll for the GPIO input port ready on the bit corresponding to the PMIC pair
///
/// @param[in] i_gpio_target GPIO target
/// @param[in] i_pmic_pair_bit the PMIC pair bit INPUT_PORT_REG_PMIC_PAIR0/1
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_input_port_ready(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio_target,
    const uint8_t i_pmic_pair_bit)
{
    // We want a 50ms timeout, so let's poll 10 times at 5ms a piece
    mss::poll_parameters l_poll_params;
    l_poll_params.iv_delay = 5 * mss::common_timings::DELAY_1MS;
    l_poll_params.iv_poll_count = 10;

    FAPI_ASSERT( mss::poll(i_gpio_target, l_poll_params, [&i_gpio_target, i_pmic_pair_bit]()->bool
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(
            i_gpio_target,
            mss::gpio::regs::INPUT_PORT_REG,
            l_reg_contents),
        "pmic_enable: Could not read 0x%02X on %s",
        mss::gpio::regs::INPUT_PORT_REG,
        mss::c_str(i_gpio_target));

        // Want to receive a 1 (good)
        return l_reg_contents.getBit(i_pmic_pair_bit);

    fapi_try_exit:
        // No ack, return false and continue polling
        return false;
    }),
    fapi2::MSS_PMIC_I2C_POLLING_TIMEOUT()
    .set_TARGET(i_gpio_target)
    .set_FUNCTION(mss::POLL_INPUT_PORT_READY),
    "I2C read from %s either did not ACK or did not respond with good status",
    mss::c_str(i_gpio_target) );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}
namespace pmic
{

///
/// @breif set VR enable bit for system startup via R32 (not broadcast)
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode start_vr_enable(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;
    using CONSTS = mss::pmic::consts<J>;

    fapi2::buffer<uint8_t> l_programmable_mode_buffer;
    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    // Enable programmable mode
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2F, l_programmable_mode_buffer));

    l_programmable_mode_buffer.writeBit<FIELDS::R2F_SECURE_MODE>(CONSTS::PROGRAMMABLE_MODE);

    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R2F, l_programmable_mode_buffer));

    // Next, start VR_ENABLE
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // Start VR Enable (1 --> Bit 7)
    l_vr_enable_buffer.setBit<FIELDS::R32_VR_ENABLE>();

    FAPI_INF("Executing VR_ENABLE for PMIC %s", mss::c_str(i_pmic_target));
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // At this point, the PWR_GOOD pin should begin to rise to high. This can't directly be checked via a register
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief bias PMIC with spd settings for phase combination (SWA, SWB or SWA+SWB)
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target - OCMB parent target of pmic
/// @param[in] i_id - PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_phase_comb(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using FIELDS = pmicFields<J>;
    using REGS = pmicRegs<J>;

    uint8_t l_phase_comb = 0;
    fapi2::buffer<uint8_t> l_phase;
    FAPI_TRY(mss::attr::get_phase_comb[i_id](i_ocmb_target, l_phase_comb));

    // Read, replace bit, and then re-write
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R4F, l_phase));
    l_phase.writeBit<FIELDS::SWA_SWB_PHASE_MODE_SELECT>(l_phase_comb);
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R4F, l_phase));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief bias PMIC with SPD settings for voltage ranges
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_volt_ranges(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using FIELDS = pmicFields<J>;
    using REGS = pmicRegs<J>;

    uint8_t l_swa_range = 0;
    uint8_t l_swb_range = 0;
    uint8_t l_swc_range = 0;
    uint8_t l_swd_range = 0;

    fapi2::buffer<uint8_t> l_volt_range_buffer;

    FAPI_TRY(mss::attr::get_swa_voltage_range_select[i_id](i_ocmb_target, l_swa_range));
    FAPI_TRY(mss::attr::get_swb_voltage_range_select[i_id](i_ocmb_target, l_swb_range));
    FAPI_TRY(mss::attr::get_swc_voltage_range_select[i_id](i_ocmb_target, l_swc_range));
    FAPI_TRY(mss::attr::get_swd_voltage_range_select[i_id](i_ocmb_target, l_swd_range));

    // Read in what the register has, as to not overwrite any default values
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));

    // Set the buffer bits appropriately
    l_volt_range_buffer.writeBit<FIELDS::SWA_VOLTAGE_RANGE>(l_swa_range);
    l_volt_range_buffer.writeBit<FIELDS::SWB_VOLTAGE_RANGE>(l_swb_range);
    l_volt_range_buffer.writeBit<FIELDS::SWC_VOLTAGE_RANGE>(l_swc_range);
    l_volt_range_buffer.writeBit<FIELDS::SWD_VOLTAGE_RANGE>(l_swd_range);

    // Write back to PMIC
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief bias PMIC with SPD settings for startup sequence
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_startup_seq(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using CONSTS = mss::pmic::consts<J>;

    static const std::vector<uint8_t> SEQUENCE_REGS =
    {
        0, // 0 would imply no sequence config (won't occur due to assert in bias_with_spd_startup_seq)
        REGS::R40_POWER_ON_SEQUENCE_CONFIG_1,
        REGS::R41_POWER_ON_SEQUENCE_CONFIG_2,
        REGS::R42_POWER_ON_SEQUENCE_CONFIG_3,
        REGS::R43_POWER_ON_SEQUENCE_CONFIG_4
    };

    // Arrays to store the attribute data
    uint8_t l_sequence_orders[CONSTS::NUMBER_OF_RAILS];
    uint8_t l_sequence_delays[CONSTS::NUMBER_OF_RAILS];

    // Loop through each rail to populate the order and delay arrays
    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        // We know after these FAPI_TRY's that all 4 entries must be populated, else the TRYs fail
        FAPI_TRY(((mss::attr::get_sequence_order[l_rail_index][i_id]))(i_ocmb_target, l_sequence_orders[l_rail_index]));
        FAPI_TRY(((mss::attr::get_sequence_delay[l_rail_index][i_id]))(i_ocmb_target, l_sequence_delays[l_rail_index]));

        // The SPD allows for up to 8 sequences, but there are only 4 on the PMIC. The SPD defaults never go higher than 2.
        // We put this check in here as with anything over 4, we don't really know what we can do.
        FAPI_ASSERT(((l_sequence_orders[l_rail_index] < CONSTS::ORDER_LIMIT)),
                    fapi2::PMIC_ORDER_OUT_OF_RANGE()
                    .set_TARGET(i_pmic_target)
                    .set_RAIL(l_rail_index)
                    .set_ORDER(l_sequence_orders[l_rail_index]),
                    "PMIC sequence order specified by the SPD was out of range for PMIC: %s Rail: %s Order: %u",
                    mss::c_str(i_pmic_target),
                    PMIC_RAIL_NAMES[l_rail_index],
                    l_sequence_orders[l_rail_index]);
    }

    {
        fapi2::buffer<uint8_t> l_power_on_sequence_config;
        uint8_t l_highest_sequence = 0;

        // Zero out sequence registers first
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R40_POWER_ON_SEQUENCE_CONFIG_1, l_power_on_sequence_config));
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R41_POWER_ON_SEQUENCE_CONFIG_2, l_power_on_sequence_config));
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R42_POWER_ON_SEQUENCE_CONFIG_3, l_power_on_sequence_config));
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R43_POWER_ON_SEQUENCE_CONFIG_4, l_power_on_sequence_config));

        // Set the registers appropriately. We kind of need to do this greedy algorithm here since
        // the SPD has fields of sequence per rail, the PMIC wants rails per sequence.
        // 1. For each rail, set that bit in the corresponding sequence, and enable that sequence
        // 2. Set that rail bit for each of the following sequences
        // 3. Record the highest sequence used throughout the run
        // 4. Clear out registers of sequences higher than the highest used (clear the set rail bits)
        // We do this because for each rail, we may not know what the highest sequence will be yet.
        // It makes the most sense to assume all sequences, then clear those that aren't used.
        for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
        {
            static constexpr uint8_t NO_SEQUENCE = 0;
            const uint8_t l_rail_sequence = l_sequence_orders[l_rail_index];

            if (l_rail_sequence != NO_SEQUENCE) // If 0, it will not be sequenced
            {
                // Update the new highest working sequence
                l_highest_sequence = std::max(l_rail_sequence, l_highest_sequence);
                // Set the register contents appropriately
                FAPI_TRY(mss::pmic::set_startup_seq_register(i_pmic_target, l_rail_index,
                         l_rail_sequence, l_sequence_delays[l_rail_index]));
            }

            // else, zero, do nothing.
        }

        // Now erase the registers that are higher than our highest sequence (in order to satisfy note 2
        // for registers R40 - R43):
        // - 2. If bit [7] = ‘0’, bits [6:3] must be programmed as ‘0000’. If bit [7] = ‘1’,
        // - at least one of the bits [6:3] must be programmed as ‘1’.
        for (++l_highest_sequence; l_highest_sequence < SEQUENCE_REGS.size(); ++l_highest_sequence)
        {
            fapi2::buffer<uint8_t> l_clear;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, SEQUENCE_REGS[l_highest_sequence], l_power_on_sequence_config));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the current limiter warning registers via attributes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_current_limiter_warnings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    const mss::pmic::id l_id = get_relative_pmic_id(i_pmic_target);

    // Quick handy array for the current limiter warning threshold registers
    static const std::vector<uint8_t> CURRENT_LIMITER_REGS =
    {
        REGS::R1C, // SWA
        REGS::R1D, // SWB
        REGS::R1E, // SWC
        REGS::R1F  // SWD
    };

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_warning_threshold = 0;
        FAPI_TRY(mss::attr::get_current_warning[l_rail_index][l_id](i_ocmb_target, l_warning_threshold));

        // If we have 0, then we either have an old SPD (< 0.4), or some bad values in there.
        // In which case, we will leave the register alone at its default (3000mA warning)
        if (l_warning_threshold > 0)
        {
            fapi2::buffer<uint8_t> l_reg_contents(l_warning_threshold);
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, CURRENT_LIMITER_REGS[l_rail_index], l_reg_contents));
        }
        else
        {
            FAPI_INF("%s Warning: Current limiter attribute / SPD value for rail %s "
                     "was read as 0mA, will not modify register (default: 3000mA)",
                     mss::c_str(i_pmic_target), PMIC_RAIL_NAMES[l_rail_index]);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the startup seq register with the given parameters
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_rail rail to
/// @param[in] i_round sequence round 1-4
/// @param[in] i_delay delay after round
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode set_startup_seq_register(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rail,
    const uint8_t i_round,
    const uint8_t i_delay)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;
    using CONSTS = mss::pmic::consts<J>;

    // PMIC registers are indexed [7:0], so from the buffer point of view, our bit fields need to be flipped
    static constexpr uint8_t RIGHT_ALIGN_OFFSET = 7;

    // Starts at bit 0 (right aligned) with length 3. So we need to take length 3 from bit 5 in our buffer
    static constexpr uint8_t DELAY_START = 5;

    static const std::vector<uint8_t> SEQUENCE_REGS =
    {
        0, // 0 would imply no sequence config (won't occur due to assert in bias_with_spd_startup_seq)
        REGS::R40_POWER_ON_SEQUENCE_CONFIG_1,
        REGS::R41_POWER_ON_SEQUENCE_CONFIG_2,
        REGS::R42_POWER_ON_SEQUENCE_CONFIG_3,
        REGS::R43_POWER_ON_SEQUENCE_CONFIG_4
    };

    // Manual reversing of sequence bits
    static const std::vector<uint8_t> SEQUENCE_BITS =
    {
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWA_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWB_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWC_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWD_ENABLE
    };

    fapi2::buffer<uint8_t> l_power_on_sequence_config;

    // Check and make sure the given delay is less than the bitmask (else, we overflow later on)
    FAPI_ASSERT(i_delay <= CONSTS::MAX_DELAY_BITMAP,
                fapi2::PMIC_DELAY_OUT_OF_RANGE()
                .set_TARGET(i_pmic_target)
                .set_RAIL(i_rail)
                .set_DELAY(i_delay),
                "PMIC sequence delay from the SPD attribute was out of range for PMIC: %s Rail: %s Delay: %u Max: %u",
                mss::c_str(i_pmic_target),
                PMIC_RAIL_NAMES[i_rail],
                i_delay,
                CONSTS::MAX_DELAY_BITMAP);

    // PMIC registers are indexed [7:0], so from the buffer point of view, our bit fields need to be flipped
    static constexpr uint8_t SEQUENCE_ENABLE_REVERSED = (RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_ENABLE);

    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, SEQUENCE_REGS[i_round], l_power_on_sequence_config));

    // Adding on the sequence delays (which are the far right 3 bits).

    // Note: The SPD has sequence delays per rail NOT per sequence (PMIC is by sequence). Here,
    // if two rails on the same sequence have different delays, the last rail's delay (ex. SWD) will take precedence.
    // In other words, they will be made to match. Otherwise, the SPD is flawed.
    l_power_on_sequence_config.clearBit<DELAY_START, FIELDS::DELAY_FLD_LENGTH>();
    l_power_on_sequence_config = l_power_on_sequence_config + i_delay;

    FAPI_TRY(l_power_on_sequence_config.setBit(SEQUENCE_BITS[i_rail]));
    FAPI_TRY(l_power_on_sequence_config.setBit(SEQUENCE_ENABLE_REVERSED));

    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, SEQUENCE_REGS[i_round], l_power_on_sequence_config));

    // The startup sequence registers after the provided one must set the bits of the rail we just enabled in
    // the current sequence. So here, we iterate through the remaining sequences and set those bits.
    // since we don't know the information about all the rails within this one function (others may be
    // set in later calls to this function) we will set these for each sequence register now, and then
    // clear them out later when we know exactly which sequences will be enabled and which ones won't
    for (uint8_t l_round_modify = i_round; l_round_modify < SEQUENCE_REGS.size(); ++l_round_modify)
    {
        l_power_on_sequence_config.flush<0>();
        FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, SEQUENCE_REGS[l_round_modify], l_power_on_sequence_config));
        FAPI_TRY(l_power_on_sequence_config.setBit(SEQUENCE_BITS[i_rail]));
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, SEQUENCE_REGS[l_round_modify], l_power_on_sequence_config));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Order PMICs by sequence defined in the SPD
///
/// @param[in] i_ocmb_target OCMB target to pull SPD fields from
/// @param[in,out] io_pmics vector of PMICs that will be re-ordered in place
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode order_pmics_by_sequence(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& io_pmics)
{
    fapi2::ReturnCode l_rc_0_out = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc_1_out = fapi2::FAPI2_RC_SUCCESS;

    std::sort(io_pmics.begin(), io_pmics.end(), [&l_rc_0_out, &l_rc_1_out, i_ocmb_target] (
                  const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& l_first_pmic,
                  const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& l_second_pmic) -> bool
    {
        // Here we should only be dealing with PMICs of the same DIMM. So we can just check the first one which dimm we're on
        uint8_t l_sequence_pmic_0 = 0;
        uint8_t l_sequence_pmic_1 = 0;

        // If we have redundant PMICs, this will result in a redundant pair being treated as the same ID,
        // so we will end up enabling a redundant pair first, then the other pair

        // Need to pull out the RC's manually. Goto's in lambdas apparently don't play nicely
        fapi2::ReturnCode l_rc_0 = mss::attr::get_sequence[get_relative_pmic_id(l_first_pmic)](i_ocmb_target, l_sequence_pmic_0);
        fapi2::ReturnCode l_rc_1 = mss::attr::get_sequence[get_relative_pmic_id(l_second_pmic)](i_ocmb_target, l_sequence_pmic_1);

        // Hold on to an error if we see one
        if (l_rc_0 != fapi2::FAPI2_RC_SUCCESS)
        {
            l_rc_0_out = l_rc_0;
        }
        if (l_rc_1 != fapi2::FAPI2_RC_SUCCESS)
        {
            l_rc_1_out = l_rc_1;
        }

        return l_sequence_pmic_0 < l_sequence_pmic_1;
    });

    FAPI_TRY(l_rc_0_out, "Error getting sequencing attributes for PMICs associated with OCMB %s",
             mss::c_str(i_ocmb_target));
    FAPI_TRY(l_rc_1_out, "Error getting sequencing attributes for PMICs associated with OCMB%s",
             mss::c_str(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable pmics using manual mode (direct VR enable, no SPD fields)
/// @param[in] i_pmics vector of PMICs to enable
/// @return FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode enable_manual(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmics)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    for (const auto& l_pmic : i_pmics)
    {
        fapi2::buffer<uint8_t> l_programmable_mode;
        l_programmable_mode.writeBit<FIELDS::R2F_SECURE_MODE>(CONSTS::PROGRAMMABLE_MODE);

        FAPI_INF("Enabling PMIC %s with default settings", mss::c_str(l_pmic));

        // Check to make sure VIN_BULK measures above minimum voltage tolerance, ensuring the PMIC
        // will function as expected
        FAPI_TRY(mss::pmic::check_vin_bulk_good(l_pmic),
                 "%s pmic_enable: check for VIN_BULK good either failed, or was below minimum voltage tolerance",
                 mss::c_str(l_pmic));

        // Enable programmable mode
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmic, REGS::R2F, l_programmable_mode));

        // Start VR Enable
        FAPI_TRY(mss::pmic::start_vr_enable(l_pmic),
                 "Error starting VR_ENABLE on PMIC %s", mss::c_str(l_pmic));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to enable PMIC using SPD settings
///
/// @param[in] i_pmic_target - the pmic target
/// @param[in] i_ocmb_target - the OCMB parent target of the pmic
/// @param[in] i_vendor_id - the vendor ID of the PMIC to bias
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode enable_spd(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint16_t i_vendor_id)
{
    FAPI_INF("Setting PMIC %s settings from SPD", mss::c_str(i_pmic_target));

    // Make sure it is TI or IDT
    FAPI_ASSERT((i_vendor_id == mss::pmic::vendor::IDT ||
                 i_vendor_id == mss::pmic::vendor::TI),
                fapi2::PMIC_CHIP_NOT_RECOGNIZED()
                .set_TARGET(i_pmic_target)
                .set_VENDOR_ID(i_vendor_id),
                "Unknown PMIC: %s with vendor ID 0x%04hhX",
                mss::c_str(i_pmic_target),
                uint16_t(i_vendor_id) );

    // Check that the PMIC vendor ID register matches the attribute
    // (and therefore has the correct settings)
    FAPI_TRY(mss::pmic::check::matching_vendors(i_ocmb_target, i_pmic_target));

    if (i_vendor_id == mss::pmic::vendor::IDT)
    {
        FAPI_TRY(mss::pmic::check::valid_idt_revisions(i_ocmb_target, i_pmic_target));
        FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::IDT>(i_pmic_target, i_ocmb_target),
                 "enable_spd (IDT): Error biasing PMIC %s with SPD settings",
                 mss::c_str(i_pmic_target));
    }
    else
    {
        FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(i_pmic_target, i_ocmb_target),
                 "enable_spd (TI): Error biasing PMIC %s with SPD settings",
                 mss::c_str(i_pmic_target));
    }

    // Start VR Enable
    FAPI_TRY(mss::pmic::start_vr_enable(i_pmic_target),
             "Error starting VR_ENABLE on PMIC %s", mss::c_str(i_pmic_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disable PMICs and clear status bits in preparation for enable
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // First, grab the PMIC targets in REL_POS order
    auto l_pmics = mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

    // Reverse loop
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];

        // First, disable
        {
            fapi2::buffer<uint8_t> l_reg_contents;

            // Redundant clearBit, but just so it's clear what we're doing
            l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

            // We are opting here to log RC's here as recovered. If this register write fails,
            // the ones later in the procedure will fail as well. The action to perform in
            // such a case is dependent on whether we do or do not have redundancy, which we
            // will know later in the procedure. As a result, we will not worry about failures here.
            l_rc = mss::pmic::i2c::reg_write_reverse_buffer(PMIC, REGS::R32, l_reg_contents);

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }

        // Now that it's disabled, let's clear the status bits so errors don't hang over into the next enable
        {
            // Similarly, we will log bad ReturnCodes here as recoverable for the reasons mentioned above
            l_rc = mss::pmic::status::clear(PMIC);

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable PMIC for 1U/2U
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_mode manual/SPD enable mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode enable_1u_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::enable_mode i_mode)
{
    auto l_pmics = mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

    // Now the PMICs are in the right order of DIMM and the right order by their defined SPD sequence within each dimm
    // Let's kick off the enables

    if (i_mode == mss::pmic::enable_mode::MANUAL)
    {
        for (const auto& l_pmic : l_pmics)
        {
            // Check to make sure VIN_BULK reports good, then we can enable the chip and write/read registers
            FAPI_TRY(check_vin_bulk_good(l_pmic),
                     "pmic_enable: Check for VIN_BULK good either failed, or returned not good status on PMIC %s",
                     mss::c_str(l_pmic));
            FAPI_TRY(start_vr_enable(l_pmic));
        }
    }
    else
    {
        // Ensure the PMICs are in sorted order
        FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

        // 1U/2U enable process
        for (const auto& l_pmic : l_pmics)
        {
            uint16_t l_vendor_id = 0;

            // Get vendor ID
            FAPI_TRY(mss::attr::get_mfg_id[get_relative_pmic_id(l_pmic)](i_ocmb_target, l_vendor_id));

            // Call the enable procedure
            FAPI_TRY((enable_spd(l_pmic, i_ocmb_target, l_vendor_id)),
                     "pmic_enable: Error enabling PMIC %s", mss::c_str(l_pmic));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup ADC1
///
/// @param[in] i_adc ADC1
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode setup_adc1(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc)
{
    for (const auto& l_pair : ADC1_CH_INIT)
    {
        const fapi2::buffer<uint8_t> l_data(l_pair.second);
        FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, l_pair.first, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup ADC2
///
/// @param[in] i_adc ADC2
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode setup_adc2(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc)
{
    for (const auto& l_pair : ADC2_CH_INIT)
    {
        const fapi2::buffer<uint8_t> l_data(l_pair.second);
        FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, l_pair.first, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Validate that the efuse appears off by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS
///
fapi2::ReturnCode validate_efuse_off(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_reg_contents;
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents));

    FAPI_DBG("R31 VIN_BULK Reading: 0x%02X", l_reg_contents);

    // Prior to turning on the efuse via the GPIO expander, we expect to see VIN below the
    // EFUSE_OFF_HIGH threshold, as power will not be applied.
    // Otherwise the efuse must be blown, and we should declare N-mode.
    if (l_reg_contents > CONSTS::R31_VIN_BULK_EFUSE_OFF_HIGH)
    {
        // FAPI INF as we will have a fail-in-place model. Don't alert the user with an ERR
        FAPI_MFG("EFUSE for %s appears blown, declaring N-Mode", mss::c_str(i_pmic_target));
        FAPI_TRY(mss::attr::set_pmic_n_mode(i_pmic_target, fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE));
    }

fapi_try_exit:
    return fapi2::current_err;
};

///
/// @brief Validate that the efuse appears on by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS
///
fapi2::ReturnCode validate_efuse_on(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_reg_contents;
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents));

    FAPI_DBG("R31 VIN_BULK Reading: 0x%02X", l_reg_contents);

    // After we turn on the efuse via the GPIO expander, power is applied to VIN_BULK,
    // and we should see a valid value within the range of EFUSE_ON_LOW --> HIGH, otherwise,
    // most likely the fuse is blown, so we should declare N-mode.
    if ((l_reg_contents < CONSTS::R31_VIN_BULK_EFUSE_ON_LOW) ||
        (l_reg_contents > CONSTS::R31_VIN_BULK_EFUSE_ON_HIGH))
    {
        FAPI_MFG("EFUSE for %s did not appear on, declaring N-Mode", mss::c_str(i_pmic_target));
        FAPI_TRY(mss::attr::set_pmic_n_mode(i_pmic_target, fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable EFUSE according to 4U Functional Specification
///
/// @param[in] i_gpio GPIO target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Corresponds to steps (6,7,8) & (16,17,18) in 4U DDIMM Functional Spec
///
fapi2::ReturnCode enable_efuse(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio)
{
    FAPI_DBG("Enabling EFUSE on %s", mss::c_str(i_gpio));
    fapi2::buffer<uint8_t> l_reg_contents;

    // Step 6 / 16
    l_reg_contents = mss::gpio::fields::EFUSE_OUTPUT_SETTING;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents));

    // Step 7 / 17
    l_reg_contents = mss::gpio::fields::EFUSE_POLARITY_SETTING;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_POLARITY, l_reg_contents));

    // Step 8 / 18
    // Set pin to output type (this will turn on the E-Fuse)
    l_reg_contents = mss::gpio::fields::CONFIGURATION_IO_MAP;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::CONFIGURATION, l_reg_contents));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the up PMIC pair and matching GPIO expander prior to PMIC enable
///
/// @param[in] i_pmic0 PMIC target connected to GPIO expander
/// @param[in] i_pmic1 PMIC target connected to GPIO expander
/// @param[in] i_gpio GPIO expander
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note the PMIC pair is NOT a redundant pair, this is the independent pair connected to one GPIO
///
fapi2::ReturnCode setup_pmic_pair_and_gpio(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic0,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    // The sequence below is defined in section 6.1.1 of the
    // Redundant Power on DIMM – Functional Specification document

    // Set up PMIC0 & PMIC1 to sample VIN_BULK
    fapi2::buffer<uint8_t> l_reg_contents(CONSTS::R30_SAMPLE_VIN_BULK_ENABLE_ADC);

    FAPI_TRY(run_if_not_disabled(i_pmic0, [&i_pmic0, &l_reg_contents]()
    {
        return mss::pmic::i2c::reg_write(i_pmic0, REGS::R30, l_reg_contents);
    }));

    FAPI_TRY(run_if_not_disabled(i_pmic1, [&i_pmic1, &l_reg_contents]()
    {
        return mss::pmic::i2c::reg_write(i_pmic1, REGS::R30, l_reg_contents);
    }));

    // Delay 25ms
    fapi2::delay(25 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Now, sampling VIN_BULK, which is protected by a fuse, we check that VIN_BULK does not read
    // more than 0.28V. If it does, then the fuse must be bad/blown, and we will declare N-mode.

    FAPI_TRY(run_if_not_disabled(i_pmic0, [&i_pmic0]()
    {
        return mss::pmic::validate_efuse_off(i_pmic0);
    }));

    FAPI_TRY(run_if_not_disabled(i_pmic1, [&i_pmic1]()
    {
        return mss::pmic::validate_efuse_off(i_pmic1);
    }));

    // Enable E-Fuse
    FAPI_TRY(enable_efuse(i_gpio));

    // Delay 30ms looked consistantly good in testing
    fapi2::delay(30 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // E-Fuse turned on, so now we should expect to see VIN_BULK within the valid on-range,
    // else, outside limit we will declare N-mode
    FAPI_TRY(run_if_not_disabled(i_pmic0, [&i_pmic0]()
    {
        return mss::pmic::validate_efuse_on(i_pmic0);
    }));

    FAPI_TRY(run_if_not_disabled(i_pmic1, [&i_pmic1]()
    {
        return mss::pmic::validate_efuse_on(i_pmic1);
    }));

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Reset N Mode attributes
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS, else error code
/// @note For 4U only. Has no effect on 1U/2U.
///
fapi2::ReturnCode reset_n_mode_attrs(const target_info_redundancy& i_target_info)
{
    uint8_t l_n_mode = fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_PLUS_1_MODE;

    FAPI_TRY(mss::attr::set_pmic_n_mode(i_target_info.iv_pmic0, l_n_mode));
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_target_info.iv_pmic1, l_n_mode));
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_target_info.iv_pmic2, l_n_mode));
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_target_info.iv_pmic3, l_n_mode));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if the GPIOs are already enabled (efuse is on)
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @param[out] o_already_enabled true if efuse already on, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else
///
fapi2::ReturnCode gpios_already_enabled(const target_info_redundancy& i_target_info, bool& o_already_enabled)
{
    fapi2::buffer<uint8_t> l_reg_contents;

    // The procedure enables GPIO1 then GPIO2. If something went wrong enabling GPIO1,
    // we couldn't proceed at all, so it would've bombed out by that point.
    // (Ex. a fail on an i2c write or something). So, we check that GPIO2 is enabled to move forward.
    FAPI_TRY(mss::pmic::i2c::reg_read(i_target_info.iv_gpio2, mss::gpio::regs::CONFIGURATION, l_reg_contents));

    o_already_enabled = gpios_already_enabled_helper(l_reg_contents);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check for the given 4 PMICs that their n-mode declarations are safe to continue the procedure
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode RC_PMIC_REDUNDANT_PAIR_DOWN if pair declares n-mode, else SUCCESS if no issue
///
fapi2::ReturnCode valid_n_mode(const target_info_redundancy& i_target_info)
{
    // If both PMICs in a pair have declared N-mode, enables will not be successful.
    // Deconfig and gard the OCMB
    constexpr auto NUM_PMICS_4U = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::NUM_PMICS_4U;

    uint8_t l_n_mode_pmic[NUM_PMICS_4U] = {0};
    uint8_t l_force_n_mode = 0;
    fapi2::buffer<uint8_t> l_force_n_mode_buffer;

    FAPI_TRY(mss::attr::get_pmic_n_mode(i_target_info.iv_pmic0, l_n_mode_pmic[0]));
    FAPI_TRY(mss::attr::get_pmic_n_mode(i_target_info.iv_pmic1, l_n_mode_pmic[1]));
    FAPI_TRY(mss::attr::get_pmic_n_mode(i_target_info.iv_pmic2, l_n_mode_pmic[2]));
    FAPI_TRY(mss::attr::get_pmic_n_mode(i_target_info.iv_pmic3, l_n_mode_pmic[3]));

    FAPI_TRY(mss::attr::get_pmic_force_n_mode(i_target_info.iv_ocmb, l_force_n_mode));
    l_force_n_mode_buffer = l_force_n_mode;

    for (uint8_t l_pmic_idx = 0; l_pmic_idx < NUM_PMICS_4U; ++l_pmic_idx)
    {
        if (!l_force_n_mode_buffer.getBit(l_pmic_idx))
        {
            // Hardcode it to N-Mode, since this pmic is disabled.
            // This allows valid_n_mode_helper to operate normally, with the
            // assumption that two PMICs are "dead"
            l_n_mode_pmic[l_pmic_idx] = fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE;
        }
    }

    FAPI_TRY(valid_n_mode_helper(
                 i_target_info.iv_ocmb,
                 l_n_mode_pmic[0],
                 l_n_mode_pmic[1],
                 l_n_mode_pmic[2],
                 l_n_mode_pmic[3]));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check for valid N-mode given the status of all 4 PMICs, assert out otherwise
///
/// @param[in] i_ocmb_target OCMB target (for FFDC)
/// @param[in] i_n_mode_pmic0 N-mode state for pmic
/// @param[in] i_n_mode_pmic1 N-mode state for pmic
/// @param[in] i_n_mode_pmic2 N-mode state for pmic
/// @param[in] i_n_mode_pmic3 N-mode state for pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else RC_PMIC_REDUNDANT_PAIR_DOWN
///
fapi2::ReturnCode valid_n_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint8_t i_n_mode_pmic0,
    const uint8_t i_n_mode_pmic1,
    const uint8_t i_n_mode_pmic2,
    const uint8_t i_n_mode_pmic3)
{
    // If both PMICs declare n-mode, the pair is not ok and enable will not proceed
    const bool l_pair0_ok =
        !((i_n_mode_pmic0 == fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE) &&
          (i_n_mode_pmic2 == fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE));

    const bool l_pair1_ok =
        !((i_n_mode_pmic1 == fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE) &&
          (i_n_mode_pmic3 == fapi2::ENUM_ATTR_MEM_PMIC_4U_N_MODE_N_MODE));

    FAPI_ASSERT(l_pair0_ok && l_pair1_ok,
                fapi2::PMIC_REDUNDANT_PAIR_DOWN()
                .set_OCMB_TARGET(i_ocmb_target)
                .set_N_MODE_PMIC0(i_n_mode_pmic0)
                .set_N_MODE_PMIC1(i_n_mode_pmic1)
                .set_N_MODE_PMIC2(i_n_mode_pmic2)
                .set_N_MODE_PMIC3(i_n_mode_pmic3),
                "A pair of redundant PMICs have both declared N-Mode. Procedure will not be able "
                "to turn either on and provide power to the OCMB %s "
                "N_MODE_PMIC0: %u N_MODE_PMIC1: %u N_MODE_PMIC2: %u N_MODE_PMIC3: %u",
                mss::c_str(i_ocmb_target),
                i_n_mode_pmic0, i_n_mode_pmic1, i_n_mode_pmic2, i_n_mode_pmic3);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check that the vendor ID register and attribute match
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode matching_vendors(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    const uint8_t l_pmic_id = static_cast<uint8_t>(get_relative_pmic_id(i_pmic_target));

    uint16_t l_vendor_attr = 0;
    fapi2::buffer<uint8_t> l_vendor_reg0;
    fapi2::buffer<uint8_t> l_vendor_reg1;

    // Get attribute
    FAPI_TRY(mss::attr::get_mfg_id[l_pmic_id](i_ocmb_target, l_vendor_attr));

    // Now check the register
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3C_VENDOR_ID_BYTE_0, l_vendor_reg0));
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3D_VENDOR_ID_BYTE_1, l_vendor_reg1));

    FAPI_TRY(mss::pmic::check::matching_vendors_helper(
                 i_pmic_target,
                 l_vendor_attr,
                 l_vendor_reg0(),
                 l_vendor_reg1()));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unit testable helper function: Check matching vendor ID between attr and reg values
///
/// @param[in] i_pmic_target PMIC target for FFDC
/// @param[in] i_vendor_attr vendor attribute value
/// @param[in] i_vendor_reg_lo vendor register low byte
/// @param[in] i_vendor_reg_hi vendor register high byte
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode matching_vendors_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint16_t i_vendor_attr,
    const uint8_t i_vendor_reg_lo,
    const uint8_t i_vendor_reg_hi)
{
    static constexpr uint8_t HI_BYTE_START = 0;
    static constexpr uint8_t HI_BYTE_LEN = 8;

    fapi2::buffer<uint16_t> l_vendor_reg(i_vendor_reg_lo);
    l_vendor_reg.insert<HI_BYTE_START, HI_BYTE_LEN>(i_vendor_reg_hi);

    FAPI_ASSERT(l_vendor_reg == i_vendor_attr,
                fapi2::PMIC_MISMATCHING_VENDOR_IDS()
                .set_VENDOR_ATTR(i_vendor_attr)
                .set_VENDOR_REG(l_vendor_reg)
                .set_PMIC_TARGET(i_pmic_target),
                "Mismatching vendor IDs for %s. ATTR: 0x%04X REG: 0x%04X",
                mss::c_str(i_pmic_target),
                i_vendor_attr,
                l_vendor_reg());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check that the IDT revision # register and attribute match
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode valid_idt_revisions(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    uint8_t l_pmic_id = mss::index(i_pmic_target);
    uint8_t l_rev = 0;
    fapi2::buffer<uint8_t> l_rev_reg;

    // Get attribute
    FAPI_TRY(mss::attr::get_revision[l_pmic_id](i_ocmb_target, l_rev));

    // Now check the register
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_rev_reg));

    FAPI_TRY(mss::pmic::check::valid_idt_revisions_helper(i_pmic_target, l_rev, l_rev_reg()));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unit testable helper function: Check that the IDT revision # register and attribute match
///
/// @param[in] i_pmic_target PMIC target (for FFDC)
/// @param[in] i_rev_attr revision value from attribute
/// @param[in] i_rev_reg revision value from register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode valid_idt_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg)
{
    // At the moment, we only care that if we have C1 revision in either the SPD, or
    // in the revision register, that the other matches. That way we use new C1 settings
    // on C1 PMICs only, and vice-versa.
    constexpr uint8_t IDT_C1_REV = 0x21;

    // If neither are IDT_C1, return
    if (i_rev_attr != IDT_C1_REV && i_rev_reg != IDT_C1_REV)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_ASSERT(i_rev_attr == i_rev_reg,
                fapi2::PMIC_MISMATCHING_REVISIONS()
                .set_REVISION_ATTR(i_rev_attr)
                .set_REVISION_REG(i_rev_reg)
                .set_PMIC_TARGET(i_pmic_target),
                "Mismatching revisions for %s. ATTR: 0x%02X REG: 0x%02X",
                mss::c_str(i_pmic_target),
                i_rev_attr,
                i_rev_reg);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns check

///
/// @brief Set the up GPIOs, ADCs, PMICs for a redundancy configuration / 4U
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_mode manual/SPD enable mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode enable_with_redundancy(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::enable_mode i_mode)
{
    bool l_already_enabled = false;
    fapi2::buffer<uint8_t> l_reg_contents;

    // Grab the targets as a struct if they exist
    // Platform is required to provide 2 GPIOs and 2 ADCs
    target_info_redundancy l_target_info(i_ocmb_target);

    // We can loop on these to pick out the PMIC, connected GPIO, and input port bit to use later
    // when we VR_ENABLE (via manual or SPD), and then check the GPIO input port reg
    const std::vector<mss::pmic::enable_fields_4u> l_enable_loop_fields =
    {
        {l_target_info.iv_pmic0, l_target_info.iv_gpio1, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0},
        {l_target_info.iv_pmic2, l_target_info.iv_gpio2, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0},
        {l_target_info.iv_pmic1, l_target_info.iv_gpio1, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1},
        {l_target_info.iv_pmic3, l_target_info.iv_gpio2, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1},
    };

    // First set up independent PMIC pairs with their GPIO expander
    FAPI_TRY(check::gpios_already_enabled(l_target_info, l_already_enabled));

    // If we are already enabled (12V on), skip all the GPIO initialization,
    // 12V being on will cause the efuse N-mode checks to fail, anyway
    if (!l_already_enabled)
    {
        // Reset N Mode attributes
        FAPI_TRY(check::reset_n_mode_attrs(l_target_info));

        FAPI_TRY(setup_pmic_pair_and_gpio(l_target_info.iv_pmic0, l_target_info.iv_pmic1, l_target_info.iv_gpio1));
        FAPI_TRY(setup_pmic_pair_and_gpio(l_target_info.iv_pmic2, l_target_info.iv_pmic3, l_target_info.iv_gpio2));

        // Now make sure the resulting n-mode states are valid before continuing
        FAPI_TRY(check::valid_n_mode(l_target_info));
    }

    // Now we're ready to kick off the regular PMIC enable. This process already includes setting
    // R2F bit 1 to set the PMIC into programmable/diagnostic mode

    // If we're enabling via internal settings (manual), we can just run VR ENABLE down the line
    if (i_mode == mss::pmic::enable_mode::MANUAL)
    {
        for (const auto l_enable_fields : l_enable_loop_fields)
        {
            FAPI_TRY(run_if_not_disabled(l_enable_fields.iv_pmic, [&l_target_info, &l_enable_fields]()
            {
                FAPI_TRY_LAMBDA(mss::pmic::start_vr_enable(l_enable_fields.iv_pmic));
                FAPI_TRY_LAMBDA(mss::gpio::poll_input_port_ready(l_enable_fields.iv_gpio, l_enable_fields.iv_input_port_bit));

            fapi_try_exit_lambda:
                return fapi2::current_err;
            }));
        }
    }
    else // SPD enable process
    {
        // 4U will only be using TI PMICs, until we know of otherwise
        uint16_t l_vendor_id = static_cast<uint16_t>(mss::pmic::vendor::TI);

        // Enable SPD and then check input port ready for each not-disabled pmic
        for (const auto l_enable_fields : l_enable_loop_fields)
        {
            FAPI_TRY(run_if_not_disabled(l_enable_fields.iv_pmic, [&l_target_info, &l_enable_fields, l_vendor_id]()
            {
                FAPI_TRY_LAMBDA(mss::pmic::enable_spd(l_enable_fields.iv_pmic, l_target_info.iv_ocmb, l_vendor_id));
                FAPI_TRY_LAMBDA(mss::gpio::poll_input_port_ready(l_enable_fields.iv_gpio, l_enable_fields.iv_input_port_bit));

            fapi_try_exit_lambda:
                return fapi2::current_err;
            }));
        }

        // TK / TODO: #476 PMIC 4U Enable Error/RC Processing
        // Add error / RC processing here when we/HB/RAS agree on how asserts should be handled
    }

    // Finally, set up the ADCs post-enable
    {
        FAPI_TRY(setup_adc1(l_target_info.iv_adc1));
        FAPI_TRY(setup_adc2(l_target_info.iv_adc2));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}

} // pmic
} // mss
