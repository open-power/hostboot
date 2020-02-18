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

namespace mss
{
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


    fapi2::buffer<uint8_t> l_programmable_mode_buffer;
    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    // Enable programmable mode
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2F, l_programmable_mode_buffer),
             "start_vr_enable: Error reading address 0x%02hhX of %s to enable programmable mode operation",
             REGS::R2F, mss::c_str(i_pmic_target));

    l_programmable_mode_buffer.writeBit<FIELDS::R2F_SECURE_MODE>(
        mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::PROGRAMMABLE_MODE);

    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R2F, l_programmable_mode_buffer),
             "start_vr_enable: Error writing address 0x%02hhX of %s to enable programmable mode operation",
             REGS::R2F, mss::c_str(i_pmic_target));

    // Start VR Enable
    // Write 1 to R2F(2)
    l_vr_enable_buffer.setBit<FIELDS::R32_VR_ENABLE>();

    FAPI_INF("Executing VR_ENABLE for PMIC %s", mss::c_str(i_pmic_target));
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer),
             "start_vr_enable: Could not write to address 0x%02hhX of %s to execute VR Enable",
             REGS::R32,
             mss::c_str(i_pmic_target));

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

        // Need to pull out the RC's manually. Goto's in lambdas apparently don't play nicely
        fapi2::ReturnCode l_rc_0 = mss::attr::get_sequence[mss::index(l_first_pmic)](i_ocmb_target, l_sequence_pmic_0);
        fapi2::ReturnCode l_rc_1 = mss::attr::get_sequence[mss::index(l_second_pmic)](i_ocmb_target, l_sequence_pmic_1);

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

        // Make sure power is applied and we can read the PMIC
        FAPI_TRY(mss::pmic::poll_for_pbulk_good(l_pmic),
                 "pmic_enable: poll for pbulk good either failed, or returned not good status on PMIC %s",
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
/// @brief Function to enable 1U and 2U pmics
///
/// @param[in] i_pmic_target - the pmic target
/// @param[in] i_ocmb_target - the OCMB parent target of the pmic
/// @param[in] i_vendor_id - the vendor ID of the PMIC to bias
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode enable_chip_1U_2U(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
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
                uint8_t(i_vendor_id) );

    if (i_vendor_id == mss::pmic::vendor::IDT)
    {
        FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::IDT>(i_pmic_target, i_ocmb_target),
                 "enable_chip<IDT, 1U/2U>: Error biasing PMIC %s with SPD settings",
                 mss::c_str(i_pmic_target));
    }
    else // assert done in pmic_enable.C that vendor is IDT or TI
    {
        FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(i_pmic_target, i_ocmb_target),
                 "enable_chip<TI, 1U/2U>: Error biasing PMIC %s with SPD settings",
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
/// @param[in] i_pmics vector of PMIC targets
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmics)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    for (const auto& l_pmic : i_pmics)
    {
        // First, disable
        {
            fapi2::buffer<uint8_t> l_reg_contents;

            // Redundant clearBit, but just so it's clear what we're doing
            l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

            FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmic, REGS::R32, l_reg_contents));
        }

        // Now that it's disabled, let's clear the status bits so errors don't hang over into the next enable
        {
            FAPI_TRY(mss::pmic::status::clear(l_pmic));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check for supported module height for the DIMMs on the provided OCMB
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok, else error code
///
fapi2::ReturnCode check_for_valid_module_height(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    uint8_t l_module_height = 0;

    // Check that we are on a supported module height
    FAPI_TRY(mss::attr::get_dram_module_height(i_ocmb_target, l_module_height));

    FAPI_ASSERT(l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U ||
                l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U,
                fapi2::PMIC_DIMM_SPD_UNSUPPORTED_MODULE_HEIGHT()
                .set_TARGET(i_ocmb_target)
                .set_VALUE(l_module_height),
                "%s module height attribute not identified as 1U or 2U. "
                "ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT of %u . Not supported yet.",
                mss::c_str(i_ocmb_target), l_module_height);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Enable PMIC for SPD mode
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in,out] io_pmics vector of PMICs sorted by mss::index. Expected to be non-empty, sorted again by sequence ATTR
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_enable_SPD(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& io_pmics)
{
    FAPI_TRY(mss::pmic::check_for_valid_module_height(i_ocmb_target));

    // Ensure the PMICs are in sorted order
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, io_pmics));

    // Now the PMICs are in the right order of DIMM and the right order by their defined SPD sequence within each dimm
    // Let's kick off the enables
    for (const auto& l_pmic : io_pmics)
    {
        uint16_t l_vendor_id = 0;

        // Get vendor ID
        FAPI_TRY(mss::attr::get_mfg_id[mss::index(l_pmic)](i_ocmb_target, l_vendor_id));

        // Poll to make sure PBULK reports good, then we can enable the chip and write/read registers
        FAPI_TRY(mss::pmic::poll_for_pbulk_good(l_pmic),
                 "pmic_enable: poll for pbulk good either failed, or returned not good status on PMIC %s",
                 mss::c_str(l_pmic));

        // Call the enable procedure
        FAPI_TRY((mss::pmic::enable_chip_1U_2U(l_pmic, i_ocmb_target, l_vendor_id)),
                 "pmic_enable: Error enabling PMIC %s", mss::c_str(l_pmic));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
} // pmic
} // mss
