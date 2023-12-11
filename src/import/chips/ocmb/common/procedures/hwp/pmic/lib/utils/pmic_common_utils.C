/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file pmic_common_utils.C
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>

namespace mss
{
namespace pmic
{
///
/// @brief Declare N-Mode and log fapi2::current_err as recoverable
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_id PMIC ID (0-3)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS
/// @note expected to be called in a fapi_try_exit with bad current_err
///
fapi2::ReturnCode declare_n_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    uint8_t i_pmic_id)
{
#ifndef __PPE__
    // Log as recoverable, set N mode attribute, all will be checked later
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
#endif
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    return mss::attr::set_n_mode_helper(
               i_ocmb_target,
               i_pmic_id,
               mss::pmic::n_mode::N_MODE);
}

///
/// @brief Determine if PMIC is disabled based on ATTR_MEM_PMIC_FORCE_N_MODE attribute setting
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_disabled true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else, error code
///
fapi2::ReturnCode disabled(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_disabled)
{
    uint8_t l_pmic_force_n_mode_attr = 0;
    fapi2::buffer<uint8_t> l_force_n_mode;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    FAPI_TRY(mss::attr::get_pmic_force_n_mode(l_ocmb, l_pmic_force_n_mode_attr));
    l_force_n_mode = l_pmic_force_n_mode_attr;

    o_disabled = !(l_force_n_mode.getBit(mss::index(i_pmic_target)));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unlocks PMIC vendor region
///
/// @param[in] i_pmic_target JEDEC-COMPLIANT PMIC to unlock
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode unlock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Unlock
    const fapi2::buffer<uint8_t> l_password_low(CONSTS::VENDOR_PASSWORD_LOW);
    const fapi2::buffer<uint8_t> l_password_high(CONSTS::VENDOR_PASSWORD_HIGH);
    const fapi2::buffer<uint8_t> l_unlock_code(CONSTS::UNLOCK_VENDOR_REGION);

    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R37_PASSWORD_LOWER_BYTE_0, l_password_low));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R38_PASSWORD_UPPER_BYTE_1, l_password_high));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R39_COMMAND_CODES, l_unlock_code));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Locks PMIC vendor region
///
/// @param[in] i_pmic_target - JEDEC-COMPLIANT PMIC to lock
/// @param[in] i_rc - return code from the end of the caller function (if applicable)
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff i_rc == SUCCESS && no errors in unlocking, else return current_err
///
fapi2::ReturnCode lock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                     const fapi2::ReturnCode i_rc)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Lock vendor region, password registers are cleared automatically
    const fapi2::buffer<uint8_t> l_lock_code(CONSTS::LOCK_VENDOR_REGION);
    const fapi2::buffer<uint8_t> l_zero_code(0);

    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R39_COMMAND_CODES, l_lock_code));

    return i_rc;

fapi_try_exit:
    // Since we could have 2 possible errors at the same time here, we are letting the caller's i_rc take precedence.
    // So, if we find an error while locking, we will report it here. We will only "return" this error if the
    // caller's error is success, as to not overwrite it.
    FAPI_ERR("Error code 0x%0llx: Error while trying to lock vendor region", uint64_t(fapi2::current_err));
    return ((i_rc == fapi2::FAPI2_RC_SUCCESS) ? fapi2::current_err : i_rc);
}

///
/// @brief Check if PMIC is IDT vendor
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_is_idt true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Can't unit test this properly as R3D is hardcoded in simics
///
fapi2::ReturnCode pmic_is_idt(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_is_idt)
{
    o_is_idt = false;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    fapi2::buffer<uint8_t> l_reg_contents;

    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3D_VENDOR_ID_BYTE_1, l_reg_contents));

    o_is_idt = (l_reg_contents == mss::pmic::vendor::IDT_SHORT);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if PMIC is TI vendor
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_is_ti true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Can't unit test this properly as R3D is hardcoded in simics
///
fapi2::ReturnCode pmic_is_ti(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_is_ti)
{
    o_is_ti = false;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    fapi2::buffer<uint8_t> l_reg_contents;

    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3D_VENDOR_ID_BYTE_1, l_reg_contents));

    o_is_ti = (l_reg_contents == mss::pmic::vendor::TI_SHORT);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check number of pmics received for 2U. If < 2, then throw an error
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_pmics_size number of PMIC received
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_number_pmics_received_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint8_t i_pmics_size)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    const auto NUM_PRIMARY_PMICS = CONSTS::NUM_PRIMARY_PMICS;

    FAPI_ASSERT(i_pmics_size == NUM_PRIMARY_PMICS,
                fapi2::INVALID_2U_PMIC_TARGET_CONFIG()
                .set_OCMB_TARGET(i_ocmb_target)
                .set_NUM_PMICS(i_pmics_size)
                .set_EXPECTED_PMICS(NUM_PRIMARY_PMICS),
                GENTARGTIDFORMAT " pmic_enable for 2U requires %u PMICs. "
                "Given %u PMICs",
                GENTARGTID(i_ocmb_target),
                NUM_PRIMARY_PMICS,
                i_pmics_size);

    return fapi2::FAPI2_RC_SUCCESS;

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

    static const uint8_t SEQUENCE_REGS[] =
    {
        0, // 0 would imply no sequence config (won't occur due to assert in bias_with_spd_startup_seq)
        REGS::R40_POWER_ON_SEQUENCE_CONFIG_1,
        REGS::R41_POWER_ON_SEQUENCE_CONFIG_2,
        REGS::R42_POWER_ON_SEQUENCE_CONFIG_3,
        REGS::R43_POWER_ON_SEQUENCE_CONFIG_4
    };

    // Manual reversing of sequence bits
    static const uint8_t SEQUENCE_BITS[] =
    {
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWA_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWB_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWC_ENABLE,
        RIGHT_ALIGN_OFFSET - FIELDS::SEQUENCE_SWD_ENABLE
    };

    fapi2::buffer<uint8_t> l_power_on_sequence_config;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    // Check and make sure the given delay is less than the bitmask (else, we overflow later on)
    FAPI_ASSERT(i_delay <= CONSTS::MAX_DELAY_BITMAP,
                fapi2::PMIC_DELAY_OUT_OF_RANGE()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb)
                .set_RAIL(i_rail)
                .set_DELAY(i_delay),
                "PMIC sequence delay from the SPD attribute was out of range for PMIC: " GENTARGTIDFORMAT " Rail: %s Delay: %u Max: %u",
                GENTARGTID(i_pmic_target),
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
    for (uint8_t l_round_modify = i_round; l_round_modify < (sizeof(SEQUENCE_REGS) / sizeof(uint8_t)); ++l_round_modify)
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
/// @brief Calculate target voltage for PMIC from attribute settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @param[in] i_rail RAIL to calculate voltage for
/// @param[out] o_volt_bitmap output bitmap
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calculate_voltage_bitmap_from_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::id i_id,
    const uint8_t i_rail,
    uint8_t& o_volt_bitmap)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    uint8_t l_volt = 0;
    int8_t l_volt_offset = 0;
    int8_t l_efd_volt_offset = 0;

    // Get the attributes corresponding to the rail and PMIC indices
    FAPI_TRY(mss::attr::get_volt_setting[i_rail][i_id](l_ocmb, l_volt));
    FAPI_TRY(mss::attr::get_volt_offset[i_rail][i_id](l_ocmb, l_volt_offset));
    FAPI_TRY(mss::attr::get_efd_volt_offset[i_rail][i_id](l_ocmb, l_efd_volt_offset));

    // Set output buffer
    o_volt_bitmap = l_volt + l_volt_offset + l_efd_volt_offset;

    FAPI_ASSERT((o_volt_bitmap <= CONSTS::MAX_VOLT_BITMAP),
                fapi2::PMIC_VOLTAGE_OUT_OF_RANGE()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb)
                .set_VOLTAGE_BITMAP(o_volt_bitmap)
                .set_RAIL(mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail])
                .set_BASE_VOLTAGE(l_volt)
                .set_SPD_OFFSET(l_volt_offset)
                .set_EFD_OFFSET(l_efd_volt_offset),
#ifndef __PPE__
                "Voltage bitmap 0x%02X out of range as determined by SPD voltage +/- offset for %s of " GENTARGTIDFORMAT
                " SPD_VOLT: %u SPD_OFFSET: %d EFD_OFFSET: %d",
                o_volt_bitmap, PMIC_RAIL_NAMES[i_rail], GENTARGTID(i_pmic_target),
                l_volt, l_volt_offset, l_efd_volt_offset);

// PPE has a cap string format specifiers
#else
                "Voltage bitmap 0x%02X out of range as determined by SPD voltage +/- offset for %s of " GENTARGTIDFORMAT,
                o_volt_bitmap, PMIC_RAIL_NAMES[i_rail], GENTARGTID(i_pmic_target));
#endif

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the current limiter warning registers via attributes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_relative_pmic_id relative PMIC position (0/1 if DDR4, 0/1/2/3 if DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_current_limiter_warnings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_relative_pmic_id)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    // Quick handy array for the current limiter warning threshold registers
    static const uint8_t CURRENT_LIMITER_REGS[] =
    {
        REGS::R1C, // SWA
        REGS::R1D, // SWB
        REGS::R1E, // SWC
        REGS::R1F  // SWD
    };

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_warning_threshold = 0;
        FAPI_TRY(mss::attr::get_current_warning[l_rail_index][i_relative_pmic_id](i_ocmb_target, l_warning_threshold));

        // If we have 0, then we either have an old SPD (< 0.4), or some bad values in there.
        // In which case, we will leave the register alone at its default (3000mA warning)
        if (l_warning_threshold > 0)
        {
            fapi2::buffer<uint8_t> l_reg_contents(l_warning_threshold);
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, CURRENT_LIMITER_REGS[l_rail_index], l_reg_contents));
        }
        else
        {
            FAPI_INF(GENTARGTIDFORMAT " Warning: Current limiter attribute / SPD value for rail %s "
                     "was read as 0mA, will not modify register (default: 3000mA)",
                     GENTARGTID(i_pmic_target), PMIC_RAIL_NAMES[l_rail_index]);
        }
    }

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

    FAPI_TRY(l_rc_0_out, "Error getting sequencing attributes for PMICs associated with OCMB " GENTARGTIDFORMAT,
             GENTARGTID(i_ocmb_target));
    FAPI_TRY(l_rc_1_out, "Error getting sequencing attributes for PMICs associated with OCMB " GENTARGTIDFORMAT,
             GENTARGTID(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update PMIC sequence based on SPD rev 0.0
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode update_seq_with_order_and_delay_attr(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using CONSTS = mss::pmic::consts<J>;

    static const uint8_t SEQUENCE_REGS[] =
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
        FAPI_ASSERT((l_sequence_orders[l_rail_index] < CONSTS::ORDER_LIMIT ),
                    fapi2::PMIC_ORDER_OUT_OF_RANGE()
                    .set_PMIC_TARGET(i_pmic_target)
                    .set_OCMB_TARGET(i_ocmb_target)
                    .set_RAIL(l_rail_index)
                    .set_ORDER(l_sequence_orders[l_rail_index]),
                    "PMIC sequence order specified by the SPD was out of range for PMIC: " GENTARGTIDFORMAT " Rail: %s Order: %u",
                    GENTARGTID(i_pmic_target),
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
        // - 2. If bit [7] = '0', bits [6:3] must be programmed as '0000'. If bit [7] = '1',
        // - at least one of the bits [6:3] must be programmed as '1'.
        for (++l_highest_sequence; l_highest_sequence < (sizeof(SEQUENCE_REGS) / sizeof(uint8_t)); ++l_highest_sequence)
        {
            fapi2::buffer<uint8_t> l_clear;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, SEQUENCE_REGS[l_highest_sequence], l_power_on_sequence_config));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update PMIC sequence based on the SPD version 0.7.0
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_id PMIC2 or PMIC3
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode update_seq_with_reg_attr(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        const mss::pmic::id i_id)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;

    uint8_t l_pmic_seq_cfg0_r40 = 0;
    uint8_t l_pmic_seq_cfg1_r41 = 0;
    uint8_t l_pmic_seq_cfg2_r42 = 0;
    uint8_t l_pmic_seq_cfg3_r43 = 0;

    // Get PMIC register attributes that is for defined for SPD rev 0.7.0
    // The power-on-sequence is controlled by register 0x40 to 0x43
    // The controller executes Power On Sequence Config0 to Power On Sequence Config3
    // as configured in registers R40 to R43 to enable its
    // output regulators in the sequence as specified.
    FAPI_TRY(mss::attr::get_sequence_order_reg40[i_id](i_ocmb_target, l_pmic_seq_cfg0_r40));
    FAPI_TRY(mss::attr::get_sequence_order_reg41[i_id](i_ocmb_target, l_pmic_seq_cfg1_r41));
    FAPI_TRY(mss::attr::get_sequence_order_reg42[i_id](i_ocmb_target, l_pmic_seq_cfg2_r42));
    FAPI_TRY(mss::attr::get_sequence_order_reg43[i_id](i_ocmb_target, l_pmic_seq_cfg3_r43));

    // Write the attribute values to the PMIC regs
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R40_POWER_ON_SEQUENCE_CONFIG_1, l_pmic_seq_cfg0_r40));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R41_POWER_ON_SEQUENCE_CONFIG_2, l_pmic_seq_cfg1_r41));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R42_POWER_ON_SEQUENCE_CONFIG_3, l_pmic_seq_cfg2_r42));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R43_POWER_ON_SEQUENCE_CONFIG_4, l_pmic_seq_cfg3_r43));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief bias PMIC with spd settings for phase combination (SWA, SWB or SWA+SWB)
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target - OCMB parent target of pmic
/// @param[in] i_id - PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
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
/// @param[in] i_id PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
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
/// @brief bias PMIC with SPD settings for coarse voltage offset
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_coarse_volt_offset(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    using FIELDS = pmicFields<mss::pmic::product::TPS5383X>;
    using REGS = pmicRegs<mss::pmic::product::TPS5383X>;

    uint8_t l_swa_coarse_offset = 0;
    uint8_t l_swb_coarse_offset = 0;
    uint8_t l_swc_coarse_offset = 0;
    uint8_t l_swd_coarse_offset = 0;

    fapi2::buffer<uint8_t> l_volt_coarse_offset_buffer;

    FAPI_TRY(mss::attr::get_swa_voltage_coarse_offset[i_id](i_ocmb_target, l_swa_coarse_offset));
    FAPI_TRY(mss::attr::get_swb_voltage_coarse_offset[i_id](i_ocmb_target, l_swb_coarse_offset));
    FAPI_TRY(mss::attr::get_swc_voltage_coarse_offset[i_id](i_ocmb_target, l_swc_coarse_offset));
    FAPI_TRY(mss::attr::get_swd_voltage_coarse_offset[i_id](i_ocmb_target, l_swd_coarse_offset));

    // Read in what the register has, as to not overwrite any default values
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R78_VID_OFFSET_COARSE,
                                      l_volt_coarse_offset_buffer));

    // Set the buffer bits appropriately
    // Note that the SPD and attributes are numbered right-to-left, so we access the register without reversing it
    l_volt_coarse_offset_buffer.insertFromRight<FIELDS::R78_SWA_VID_OFFSET_COARSE_START_NON_REVERSED,
                                                FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_swa_coarse_offset);
    l_volt_coarse_offset_buffer.insertFromRight<FIELDS::R78_SWB_VID_OFFSET_COARSE_START_NON_REVERSED,
                                                FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_swb_coarse_offset);
    l_volt_coarse_offset_buffer.insertFromRight<FIELDS::R78_SWC_VID_OFFSET_COARSE_START_NON_REVERSED,
                                                FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_swc_coarse_offset);
    l_volt_coarse_offset_buffer.insertFromRight<FIELDS::R78_SWD_VID_OFFSET_COARSE_START_NON_REVERSED,
                                                FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_swd_coarse_offset);

    // Write back to PMIC
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R78_VID_OFFSET_COARSE,
                                       l_volt_coarse_offset_buffer));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief bias PMIC with SPD settings for startup sequence either with
/// sequence order and delay attr or sequence order attr depending on the
/// SPD revision
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_startup_seq(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    // Variables to store the attribute data
    uint8_t l_sequence_order_swa;
    uint8_t l_dram_gen = 0;
    static constexpr uint8_t SEQ_ORDER_RESERVED_VALUE = 15;

    // Get the dram generation
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_ocmb_target))
    {
        uint8_t l_value[2] = {};
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_GEN, l_port, l_value) );
        l_dram_gen = l_value[0];
        break;
    }

    // Get the SWA attribute value just for checking purposes
    // We are keying off the sequence order attribute (which is set to invalid/reserved value when SPD rev is 0.7.0)
    // and when the dram_gen attribute is DDR5
    // So just getting one attribute is good enough to check for that, since all of the attributes that are
    // defined for SPD rev 0.0 are made invalid/reserved
    FAPI_TRY(((mss::attr::get_sequence_order[mss::pmic::rail::SWA][i_id]))(i_ocmb_target, l_sequence_order_swa));

    // Checking for the sequence order attribute for an invalid value
    // And if the dram gen is DDR5, only then use the attributes defined for SPD rev 0.7.0
    if (l_sequence_order_swa == SEQ_ORDER_RESERVED_VALUE &&
        l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5)
    {
        // Call the update seq to use attributes that are defined for SPD rev 0.7.0
        FAPI_INF("Call pmic_sequencing with reg attr with dram_gen: %d for " GENTARGTIDFORMAT, l_dram_gen,
                 GENTARGTID(i_pmic_target));
        return(update_seq_with_reg_attr(i_pmic_target, i_ocmb_target, i_id));
    }
    else
    {
        // Call the update seq to use original attributes that are defined for SPD rev 0.0
        FAPI_INF("Call pmic_sequencing with original attributes with dram_gen: %d for " GENTARGTIDFORMAT, l_dram_gen,
                 GENTARGTID(i_pmic_target));
        return(update_seq_with_order_and_delay_attr(i_pmic_target, i_ocmb_target, i_id));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bias with spd voltages for IDT pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode bias_with_spd_voltages<mss::pmic::vendor::IDT>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_volt_bitmap;
        FAPI_TRY(mss::pmic::calculate_voltage_bitmap_from_attr(i_pmic_target, i_id, l_rail_index, l_volt_bitmap));

        {
            fapi2::buffer<uint8_t> l_volt_buffer = l_volt_bitmap << CONSTS::SHIFT_VOLTAGE_FOR_REG;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index], l_volt_buffer),
                     "Error writing address 0x%02hhX of PMIC " GENTARGTIDFORMAT, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index],
                     GENTARGTID(i_pmic_target));
        }

    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bias with spd voltages for TI pmic with revision less than 0x23
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @param[in] i_rail_index SWA/SWB/SWC/SWD rails of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode bias_with_spd_voltages_TI_rev_less_then_23(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id,
    const uint8_t i_rail_index)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    uint8_t l_volt_bitmap;
    uint8_t l_volt_range_select = 0;

    FAPI_TRY(mss::pmic::calculate_voltage_bitmap_from_attr(i_pmic_target, i_id, i_rail_index, l_volt_bitmap));

    FAPI_TRY(mss::attr::get_volt_range_select[i_rail_index][i_id](i_ocmb_target, l_volt_range_select));

    // SWD supports a RANGE 1, but NOT SWA-C
    if (i_rail_index == mss::pmic::rail::SWD)
    {
        // Can set range and voltage directly
        fapi2::buffer<uint8_t> l_volt_range_buffer;

        // Read in what the register has, as to not overwrite any default values
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));

        l_volt_range_buffer.writeBit<FIELDS::SWD_VOLTAGE_RANGE>(l_volt_range_select);

        // Write to PMIC
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));
    }
    else
    {
        // Check if the range is range 1, in which case we will need to convert to range 0 (thanks TI)
        if (l_volt_range_select == CONSTS::RANGE_1)
        {
            // Convert from RANGE1 -> RANGE0

            // Since both ranges are 5mV (at least they're supposed to be)
            // we can just subtract the difference between range 1 and 0
            // which is 600mV -> 800mV
            // 200mV / 5 = 40
            uint8_t l_old_voltage = l_volt_bitmap;
            l_volt_bitmap = l_volt_bitmap - CONSTS::CONVERT_RANGE1_TO_RANGE0;

            // Check for overflow (the old voltage should be larger unless we rolled over)
            FAPI_ASSERT(l_volt_bitmap < l_old_voltage ,
                        fapi2::PMIC_RANGE_CONVERSION_OVERFLOW()
                        .set_PMIC_TARGET(i_pmic_target)
                        .set_RANGE_0_VOLT(l_volt_bitmap)
                        .set_RANGE_1_VOLT(l_old_voltage)
                        .set_RAIL(mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail_index]),
                        "Voltage appeared overflowed during conversion from range 1 to 0 on rail %s of " GENTARGTIDFORMAT
                        "RANGE_1_VOLT: 0x%02X RANGE_0_VOLT: 0x%02X",
                        PMIC_RAIL_NAMES[i_rail_index], GENTARGTID(i_pmic_target), l_old_voltage, l_volt_bitmap);
        }
    }

    {
        fapi2::buffer<uint8_t> l_volt_buffer = l_volt_bitmap << CONSTS::SHIFT_VOLTAGE_FOR_REG;
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail_index], l_volt_buffer),
                 "Error writing address 0x%02hhX of PMIC " GENTARGTIDFORMAT , mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail_index],
                 GENTARGTID(i_pmic_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bias with spd voltages for TI pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode bias_with_spd_voltages<mss::pmic::vendor::TI>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    fapi2::buffer<uint8_t> l_pmic_rev;
    constexpr uint8_t TI_REV_23 = 0x23;

    // Get revision number
    FAPI_TRY(mss::pmic::check::validate_and_return_pmic_revisions(i_ocmb_target, i_pmic_target, mss::pmic::vendor::TI,
             l_pmic_rev));

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        if (l_pmic_rev < TI_REV_23)
        {
            FAPI_TRY(bias_with_spd_voltages_TI_rev_less_then_23(i_pmic_target, i_ocmb_target, i_id, l_rail_index));
        }
        else
        {
            // Voltage ranges in R2B
            FAPI_TRY(mss::pmic::bias_with_spd_volt_ranges(i_pmic_target, i_ocmb_target, i_id));

            // Voltage Coarse Offset in R78
            FAPI_TRY(mss::pmic::bias_with_spd_coarse_volt_offset(i_pmic_target, i_ocmb_target, i_id));

            // Voltage settings
            uint8_t l_volt_bitmap;
            FAPI_TRY(mss::pmic::calculate_voltage_bitmap_from_attr(i_pmic_target, i_id, l_rail_index, l_volt_bitmap));

            fapi2::buffer<uint8_t> l_volt_buffer = l_volt_bitmap << CONSTS::SHIFT_VOLTAGE_FOR_REG;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index], l_volt_buffer),
                     "Error writing address 0x%02hhX of PMIC " GENTARGTIDFORMAT, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index],
                     GENTARGTID(i_pmic_target));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Bias IDT PMIC from SPD settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_relative_pmic_id relative PMIC position (0/1 if DDR4, 0/1/2/3 if DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<>
fapi2::ReturnCode bias_with_spd_settings<mss::pmic::vendor::IDT>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_relative_pmic_id)
{
    // Unlock Vendor Region
    FAPI_TRY(mss::pmic::unlock_vendor_region(i_pmic_target),
             "Error unlocking vendor region on PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic_target));

    {
        // Phase combination
        FAPI_TRY(mss::pmic::bias_with_spd_phase_comb(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Voltage ranges
        FAPI_TRY(mss::pmic::bias_with_spd_volt_ranges(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Voltages
        FAPI_TRY(mss::pmic::bias_with_spd_voltages<mss::pmic::IDT>(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Startup sequence
        FAPI_TRY(mss::pmic::bias_with_spd_startup_seq(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Current consumption
        FAPI_TRY(mss::pmic::set_current_limiter_warnings(i_pmic_target, i_ocmb_target, i_relative_pmic_id));
    }

fapi_try_exit:
    // Try to lock vendor region even in the case of an error in this function
    return mss::pmic::lock_vendor_region(i_pmic_target, fapi2::current_err);
}

///
/// @brief Bias TI PMIC from SPD settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_relative_pmic_id relative PMIC position (0/1 if DDR4, 0/1/2/3 if DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<>
fapi2::ReturnCode bias_with_spd_settings<mss::pmic::vendor::TI>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_relative_pmic_id)
{
    // Unlock Vendor Region
    FAPI_TRY(mss::pmic::unlock_vendor_region(i_pmic_target),
             "Error unlocking vendor region on PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic_target));
    {
        // Phase combination
        FAPI_TRY(mss::pmic::bias_with_spd_phase_comb(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Voltages
        // For TI pmic revision < 0x23, the PMIC only has range 0 for SWA-C.
        // We need to convert anything SPD that says range 1 --> range 0
        // For revision >= 0x23, use the SPD data
        FAPI_TRY(mss::pmic::bias_with_spd_voltages<mss::pmic::TI>(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Startup sequence
        FAPI_TRY(mss::pmic::bias_with_spd_startup_seq(i_pmic_target, i_ocmb_target, i_relative_pmic_id));

        // Current consumption
        FAPI_TRY(mss::pmic::set_current_limiter_warnings(i_pmic_target, i_ocmb_target, i_relative_pmic_id));
    }

fapi_try_exit:
    // Try to lock vendor region even in the case of an error in this function
    return mss::pmic::lock_vendor_region(i_pmic_target, fapi2::current_err);
}

///
/// @brief Get the mnfg thresholds policy setting
///
/// @param[out] o_thresholds thresholds policy setting
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_mnfg_thresholds(bool& o_thresholds)
{
    o_thresholds = false;

    // Consts and vars
    fapi2::ATTR_MFG_FLAGS_Type l_mfg_array = {0};
    fapi2::buffer<uint32_t> l_mfg_flags;
    static constexpr uint32_t MNFG_THRESHOLDS_ARR_IDX = 0;
    static constexpr uint32_t MNFG_THRESHOLDS_BIT = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS;

    // Grab THRESHOLDS setting
    FAPI_TRY(mss::attr::get_mfg_flags(l_mfg_array));
    l_mfg_flags = l_mfg_array[MNFG_THRESHOLDS_ARR_IDX];
    o_thresholds = l_mfg_flags.getBit<MNFG_THRESHOLDS_BIT>();

fapi_try_exit:
    return fapi2::current_err;
}

namespace status
{

///
/// @brief Unlock PMIC registers R70 to RA3
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode unlock_pmic_r70_to_ra3(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;

    // make sure it is locked to make sure unlock will work afterwards
    FAPI_TRY(lock_pmic_r70_to_ra3(i_pmic_target));

    // unlock R78 to RA3 by writing RA2=0x95 followed by RA2=0x64
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, TPS_REGS::RA2_REG_LOCK, 0x95));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, TPS_REGS::RA2_REG_LOCK, 0x64));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Lock PMIC registers R70 to RA3
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode lock_pmic_r70_to_ra3(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;

    // lock R78 to RA3 by writing RA2=0x00
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, TPS_REGS::RA2_REG_LOCK, 0x00));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks that the PMIC is enabled via VR Enable bit
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_for_vr_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer),
             "start_vr_enable: Could not read address 0x%02hhX of " GENTARGTIDFORMAT " to check for VR Enable",
             REGS::R32,
             GENTARGTID(i_pmic_target));

    // Make sure we are enabled
    FAPI_ASSERT(l_vr_enable_buffer.getBit<FIELDS::R32_VR_ENABLE>(),
                fapi2::PMIC_NOT_ENABLED()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(i_ocmb_target),
                "PMIC " GENTARGTIDFORMAT " was not identified as enabled by checking VR Enable bit",
                GENTARGTID(i_pmic_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear PMIC status registers
///
/// @param[in] i_pmic_target PMIC to clear
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode clear(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_reg_contents;
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R14, l_reg_contents));

    // Write to clear
    l_reg_contents.setBit<FIELDS::R14_GLOBAL_CLEAR_STATUS>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R14, l_reg_contents));

    // Clear host region codes
    l_reg_contents = CONSTS::CLEAR_R04_TO_R07;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R39_COMMAND_CODES, l_reg_contents));

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__
///
/// @brief Helper function for check_all_pmics, returns one RC
///
/// @param[in] i_ocmb_target OCMB targer
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode Returns the first bad RC found, otherwise, success
///
fapi2::ReturnCode check_all_pmics_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    bool l_pmic_error = false;
    status_regs l_values = {0};
    FAPI_TRY(check_for_vr_enable(i_ocmb_target, i_pmic_target),
             "PMIC" GENTARGTIDFORMAT " did not return enabled status", GENTARGTID(i_pmic_target));

    // Now check if we had any bad status bits
    FAPI_TRY(mss::pmic::status::check_pmic(i_pmic_target, l_values, l_pmic_error));

    FAPI_ASSERT(!l_pmic_error,
                fapi2::PMIC_STATUS_ERRORS()
                .set_OCMB_TARGET(i_ocmb_target)
                .set_PMIC_TARGET(i_pmic_target)
                .set_R04_VALUE(l_values.iv_r04)
                .set_R05_VALUE(l_values.iv_r05)
                .set_R06_VALUE(l_values.iv_r06)
                .set_R08_VALUE(l_values.iv_r08)
                .set_R09_VALUE(l_values.iv_r09)
                .set_R0A_VALUE(l_values.iv_r0A)
                .set_R0B_VALUE(l_values.iv_r0B)
                .set_R33_VALUE(l_values.iv_r33)
                .set_R73_VALUE(l_values.iv_r73),
#ifndef __PPE__
                "PMIC on OCMB " GENTARGTIDFORMAT " had one or more status bits set after running pmic_enable(). "
                "One of possibly several bad PMICs: " GENTARGTIDFORMAT " R04=0x%02X R05=0x%02X R06=0x%02X"
                " R08=0x%02X R09=0x%02X R0A=0x%02X R0B=0x%02X  R33=0x%02X  R73=0x%02X",
                GENTARGTID(i_ocmb_target), GENTARGTID(i_pmic_target), l_values.iv_r04, l_values.iv_r05,
                l_values.iv_r06, l_values.iv_r08, l_values.iv_r09, l_values.iv_r0A, l_values.iv_r0B,
                l_values.iv_r33, l_values.iv_r73);
#else // PPE plat supports a maximum of 4 arguments in trace
                "PMIC on OCMB " GENTARGTIDFORMAT " had one or more status bits set after running pmic_enable(). "
                "One of possibly several bad PMICs: " GENTARGTIDFORMAT,
                GENTARGTID(i_ocmb_target), GENTARGTID(i_pmic_target));
#endif

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note To be used with 1U/2U Enable sequence
///
fapi2::ReturnCode check_all_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    // Start success so we can't log and return the same error in loop logic
    // We will hold onto the first fail seen to return, and log any others
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc_return = fapi2::FAPI2_RC_SUCCESS;

    // Check that the PMICs are enabled and without errors
    // NOTE: not checking TARGET_STATE_PRESENT here since we already check that we have
    // at least 2 functional PMICs at the beginning of the procedure, and this is 1U/2U
    for (const auto& l_pmic : mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target))
    {
        // Redundant set of current_err as this is set automatically by the
        // return of the function in a case where there was a failure
        fapi2::current_err = check_all_pmics_helper(i_ocmb_target, l_pmic);

        // RC processing
        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            // Is this the first error?
            if (l_rc_return == fapi2::FAPI2_RC_SUCCESS)
            {
                // We will return this error
                l_rc_return = fapi2::current_err;
            }

#ifndef __PPE__
            else
            {
                // We already have an error to return, log this one.
                fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
            }

#endif
        }

        // Reset for next loop
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    // Else, exit on whatever RC we had
    FAPI_TRY(l_rc_return);

    // If we get here, statuses are good
    FAPI_INF("All post-enable statuses reported good for " GENTARGTIDFORMAT, GENTARGTID(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the PMIC's status codes and report back if an error occurred
///
/// @param[in] i_pmic_target PMIC target
/// @param[in,out] io_values value of status registers on this PMIC
/// @param[out] o_error true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode check_pmic(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    status_regs& io_values,
    bool& o_error)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_CONSTS = mss::pmic::consts<mss::pmic::product::TPS5383X>;

    o_error = false;
    bool l_pmic_is_idt = false;
    bool l_pmic_is_ti = false;
    fapi2::buffer<uint8_t> l_pmic_rev;

    FAPI_TRY(pmic_is_idt(i_pmic_target, l_pmic_is_idt));
    FAPI_TRY(pmic_is_ti(i_pmic_target, l_pmic_is_ti));

    // If TI PMIC get the revision
    if (l_pmic_is_ti)
    {
        FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_pmic_rev));
    }

    // Check error log register fields
    // Applies to IDT or TI rev >= 0x23
    if ((l_pmic_is_idt) || (l_pmic_is_ti && (l_pmic_rev >= TPS_CONSTS::TI_REV_23)))
    {
        // These registers reflect the previous power down cycle of the PMIC. Therefore, they may
        // not necessarily cause issues on this life. So, we do not need to worry about keeping track if
        // these failed with l_status_error, but the check_fields() function will still print them out.
        bool l_status_error = false;

        // if we exit from this try, there were i2c errors
        FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "PMIC_WARNING_BIT",
                 mss::pmic::status::ERROR_LOG_REG_FIELDS, io_values, l_status_error));
    }

    {
        bool l_status_error = false;

        // Check statuses for specific vendors that have unique status bits
        // TI REV < 0x23
        if (l_pmic_is_ti && (l_pmic_rev < TPS_CONSTS::TI_REV_23))
        {
            FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "ERROR",
                     mss::pmic::status::STATUS_FIELDS_TI_LT_REV23, io_values, l_status_error));
            o_error |= l_status_error;
        }
        // All others (IDT and TI REV >=0x23)
        else
        {
            FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "ERROR",
                     mss::pmic::status::STATUS_FIELDS_NOT_TI_LT_REV23, io_values, l_status_error));
            o_error |= l_status_error;
        }

        // TI REV >= 0x23
        if (l_pmic_is_ti && (l_pmic_rev >= TPS_CONSTS::TI_REV_23))
        {
            // unlock register R73 for reading as that is in STATUS_FIELDS_TI_GTE_REV23
            FAPI_TRY(unlock_pmic_r70_to_ra3(i_pmic_target));

            FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "ERROR",
                     mss::pmic::status::STATUS_FIELDS_TI_GTE_REV23, io_values, l_status_error));
            o_error |= l_status_error;
        }

        // if we exit from this try, there were i2c errors
        FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "ERROR",
                 mss::pmic::status::STATUS_FIELDS, io_values, l_status_error));
        o_error |= l_status_error;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to fill in pmic::status::status_regs struct
///
/// @param[in] i_reg status register address
/// @param[in] i_value status register value
/// @param[in,out] io_values value of status registers on this PMIC
///
void status_reg_save_helper(
    const uint8_t i_reg,
    const uint8_t i_value,
    status_regs& io_values)
{
    switch (i_reg)
    {
        case REGS::R04:
            io_values.iv_r04 = i_value;
            break;

        case REGS::R05:
            io_values.iv_r05 = i_value;
            break;

        case REGS::R06:
            io_values.iv_r06 = i_value;
            break;

        case REGS::R08:
            io_values.iv_r08 = i_value;
            break;

        case REGS::R09:
            io_values.iv_r09 = i_value;
            break;

        case REGS::R0A:
            io_values.iv_r0A = i_value;
            break;

        case REGS::R0B:
            io_values.iv_r0B = i_value;
            break;

        case REGS::R33:
            io_values.iv_r33 = i_value;
            break;

        case TPS_REGS::R73:
            io_values.iv_r73 = i_value;
            break;

        default:
            break;
    }
}

///
/// @brief Check an individual set of PMIC status codes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_error_type error type for the PMIC in question
/// @param[in] i_statuses STATUS object to check
/// @param[in,out] io_values value of status registers on this PMIC
/// @param[out] o_error At least one error bit was found to be set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error in case of an I2C read error
///
fapi2::ReturnCode check_fields(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const char* i_error_type,
    const std::vector<std::pair<uint8_t, std::vector<status_field>>>& i_statuses,
    status_regs& io_values,
    bool& o_error)
{
    o_error = false;

    for (const auto& l_reg_bit_pair : i_statuses)
    {
        fapi2::buffer<uint8_t> l_reg_contents;
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, l_reg_bit_pair.first, l_reg_contents));

        for (const auto& l_status : l_reg_bit_pair.second)
        {
            if (l_reg_contents.getBit(l_status.iv_reg_field))
            {
                // Print it out
                FAPI_ERR("%s %s :: REG 0x%02x bit %u was set on " GENTARGTIDFORMAT,
                         l_status.iv_error_description,
                         i_error_type,
                         l_reg_bit_pair.first,
                         l_status.iv_reg_field,
                         GENTARGTID(i_pmic_target));

                // We don't want to exit out in this exact spot: Errors can be independent of
                // each other and we should check them all. Since there's no easy way to FFDC each
                // individual error, we will FAPI_ERR them here and then worry about return codes in
                // the caller of this function.
                if (l_status.iv_assert_out)
                {
                    // Only assert out if the error is deemed fatal
                    o_error = true;
                }
            }
        }

        status_reg_save_helper(l_reg_bit_pair.first, l_reg_contents, io_values);

        l_reg_contents.flush<0>();
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
#endif

} // status

namespace check
{

///
/// @brief Unit testable helper function: Check that the IDT revision # register and attribute match
///
/// @param[in] i_pmic_target PMIC target (for FFDC)
/// @param[in] i_rev_attr revision value from attribute
/// @param[in] i_rev_reg revision value from register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_and_return_idt_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg)
{
    // At the moment, we only care that if we have revisions less than C1 in either the SPD, or
    // in the revision register, that the other matches. That way we use C1 and above revision settings
    // on C1 and above PMICs only, and vice-versa.
    constexpr uint8_t IDT_C1_REV = 0x21;

    // Check for revisions less than IDT_C1, return if true
    if ( (i_rev_attr < IDT_C1_REV && i_rev_reg < IDT_C1_REV) )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    FAPI_ASSERT(i_rev_attr == i_rev_reg,
                fapi2::PMIC_MISMATCHING_REVISIONS()
                .set_REVISION_ATTR(i_rev_attr)
                .set_REVISION_REG(i_rev_reg)
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb),
                "Mismatching revisions for " GENTARGTIDFORMAT ". ATTR: 0x%02X REG: 0x%02X",
                GENTARGTID(i_pmic_target),
                i_rev_attr,
                i_rev_reg);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check that the IDT revision # register and attribute match and return revision number.
///        In case of TI, just return the revision number
///
/// @param[in]  i_ocmb_target OCMB target
/// @param[in]  i_pmic_target PMIC target to check
/// @param[in]  i_vendor_id to run IDT revision check
/// @param[out] o_rev_reg revision number of PMIC
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_and_return_pmic_revisions(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint16_t i_vendor_id,
    fapi2::buffer<uint8_t>& o_rev_reg)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    uint8_t l_pmic_id = mss::index(i_pmic_target);
    uint8_t l_rev = 0;
    uint8_t l_simics = 0;

    // Get attribute
    FAPI_TRY(mss::attr::get_revision[l_pmic_id](i_ocmb_target, l_rev));

    // Now check the register
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, o_rev_reg));

    if (i_vendor_id == mss::pmic::vendor::IDT)
    {
        // The simics check has been added here for IDT to skip simics testing of the below function as
        // simics is throwing error for the attribute and revision register mismatch condition.
        // Updating simics is not recommended as there are no real PMICs on the simulation model
        // and skipping this check will not affect rest of the pmic_enable functionality in simics
        //FAPI_TRY(mss::attr::get_is_simics(l_simics));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_simics));

        if (!l_simics)
        {
            FAPI_TRY(mss::pmic::check::validate_and_return_idt_revisions_helper(i_pmic_target, l_rev, o_rev_reg()));
        }
        else
        {
            FAPI_DBG("Simulation mode detected. Skipping IDT revision check");
        }
    }

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
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    fapi2::buffer<uint16_t> l_vendor_reg(i_vendor_reg_lo);
    l_vendor_reg.insert<HI_BYTE_START, HI_BYTE_LEN>(i_vendor_reg_hi);

    FAPI_ASSERT(l_vendor_reg == i_vendor_attr,
                fapi2::PMIC_MISMATCHING_VENDOR_IDS()
                .set_VENDOR_ATTR(i_vendor_attr)
                .set_VENDOR_REG(l_vendor_reg)
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb_target),
                "Mismatching vendor IDs for " GENTARGTIDFORMAT ". ATTR: 0x%04X REG: 0x%04X",
                GENTARGTID(i_pmic_target),
                i_vendor_attr,
                l_vendor_reg());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset N Mode attributes
///
/// @param[in] i_ocmb OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS, else error code
/// @note For 4U only. Has no effect on 1U/2U.
///
fapi2::ReturnCode reset_n_mode_attrs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    uint8_t l_n_mode = 0x00;
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_ocmb, l_n_mode));

fapi_try_exit:
    return fapi2::current_err;
}

} // check
} // pmic
} // mss
