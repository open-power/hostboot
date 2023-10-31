/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <lib/utils/pmic_common_utils_ddr4.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <lib/utils/pmic_enable_4u_settings.H>

namespace mss
{
namespace pmic
{
///
/// @brief Checks PMIC for VIN_BULK above minimum tolerance
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode success if good, else, error code
///
fapi2::ReturnCode check_vin_bulk_good(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;

    const uint16_t ADC_VIN_BULK_SELECT = 5;
    const uint16_t ADC_VIN_BULK_STEP = 70;

    fapi2::buffer<uint8_t> l_reg_contents;
    uint16_t l_adc_readout = 0;
    uint16_t l_calculated_vin_bulk = 0;
    uint16_t l_vin_bulk_min = 0;

    // Program the ADC select bits
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R30, l_reg_contents));
    l_reg_contents.insertFromRight<FIELDS::R30_ADC_SELECT_START, FIELDS::R30_ADC_SELECT_LENGTH>(ADC_VIN_BULK_SELECT);
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, l_reg_contents));

    // Enable the PMIC ADC
    FAPI_TRY(enable_pmic_adc(i_pmic_target));

    // Get PMIC ADC_READ register contents
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents));
    l_reg_contents.extractToRight<FIELDS::R31_ADC_READ_SETTING_START, FIELDS::R31_ADC_READ_SETTING_LENGTH>(l_adc_readout);

    // Calculate ADC_READ value
    l_calculated_vin_bulk = l_adc_readout * ADC_VIN_BULK_STEP;
    FAPI_TRY(get_minimum_vin_bulk_threshold(i_pmic_target, l_vin_bulk_min));

    // Disable the PMIC ADC
    FAPI_TRY(disable_pmic_adc(i_pmic_target));

    FAPI_DBG("VIN_BULK voltage %umV, minimum threshold %umV", l_calculated_vin_bulk, l_vin_bulk_min);

    // Now verify the value is good (above minimum tolerance)
    FAPI_ASSERT(l_calculated_vin_bulk >= l_vin_bulk_min,
                fapi2::VIN_BULK_BELOW_TOLERANCE()
                .set_MINIMUM_MV(l_vin_bulk_min)
                .set_ACTUAL_MV(l_calculated_vin_bulk),
                "%s VIN_BULK voltage %umV was lower than minimum threshold %umV",
                mss::c_str(i_pmic_target), l_calculated_vin_bulk, l_vin_bulk_min);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the minimum vin bulk threshold
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_vin_bulk_min VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_minimum_vin_bulk_threshold(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    uint16_t& o_vin_bulk_min)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_pmic_rev;
    fapi2::buffer<uint8_t> l_vin_bulk_min_threshold;
    bool l_pmic_is_ti = false;

    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_pmic_rev));
    FAPI_TRY(pmic_is_ti(i_pmic_target, l_pmic_is_ti));

    // Use R1A value
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R1A, l_vin_bulk_min_threshold));

    o_vin_bulk_min = get_minimum_vin_bulk_threshold_helper(
                         l_vin_bulk_min_threshold,
                         l_pmic_is_ti,
                         l_pmic_rev);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @param[in] i_is_ti PMIC is TI
/// @param[in] i_rev PMIC revision
/// return VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold,
    const bool i_is_ti,
    const uint8_t i_rev)
{
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    const uint8_t IDT_C1_REV = 0x33;

    static std::map<uint8_t, uint16_t> VIN_BULK_BITMAP =
    {
        // Reserved bitmaps are excluded. The PMICs will not allow writes of reserved bitmaps,
        // so these could never appear.
        {0b00100000, 9500},
        {0b01000000, 8500},
        {0b01100000, 7500},
        {0b10000000, 6500},
        {0b10100000, 5500},
        {0b11000000, 4250},
    };

    // If TI or IDT >= C1
    if (i_is_ti || (i_rev >= IDT_C1_REV))
    {
        uint16_t l_mapped_vin_bulk = 0;

        // The 3 relevant bits are left-aligned, so they will line up with the VIN_BULK_BITMAP
        l_mapped_vin_bulk = VIN_BULK_BITMAP[i_vin_bulk_min_threshold
                                            & FIELDS::R1A_VIN_BULK_POWER_GOOD_THRESHOLD_VOLTAGE_MASK];

        return l_mapped_vin_bulk;

    }
    else // IDT Pre-C1. Bug in the ADC in these parts means that we should check 4V flat.
    {
        return 4000;
    }
}

///
/// @brief Disable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_reg_contents;

    // Disable the ADC
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R30, l_reg_contents));

    if (l_reg_contents.getBit<FIELDS::R30_ADC_ENABLE>() == mss::ON)
    {
        l_reg_contents.clearBit<FIELDS::R30_ADC_ENABLE>();
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, l_reg_contents));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode enable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_reg_contents;
    const uint8_t ADC_DELAY_AFTER_ENABLE_MS = 25;

    // Enable the ADC
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R30, l_reg_contents));

    if (l_reg_contents.getBit<FIELDS::R30_ADC_ENABLE>() == mss::OFF)
    {
        l_reg_contents.setBit<FIELDS::R30_ADC_ENABLE>();
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, l_reg_contents));
    }

    // wait for result registers to be updated
    // could be a newly programmed ADC_SELECT value, so delay even if ADC was already enabled
    FAPI_TRY(fapi2::delay((mss::DELAY_1MS * ADC_DELAY_AFTER_ENABLE_MS),
                          (mss::DELAY_1US * ADC_DELAY_AFTER_ENABLE_MS)));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculate nominal rail voltages
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id ID of pmic, will be normalized to 0 or 1
/// @param[in] i_rail SWA through SWD mapped as 0 to 3
/// @param[out] o_nominal_voltage calculated nominal voltage, shifted in place for register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calculate_4u_nominal_voltage(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_id,
    const uint8_t i_rail,
    uint8_t& o_nominal_voltage)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);
    uint8_t l_relative_id = (i_id % CONSTS::NUM_PRIMARY_PMICS);

    uint8_t l_volt = 0;
    int8_t l_volt_offset = 0;
    int8_t l_efd_volt_offset = 0;
    uint8_t l_nominal_voltage = 0;

    // Mod divided by two will leave either PMIC0 or PMIC1
    if (l_relative_id == mss::pmic::id::PMIC0)
    {
        l_volt = PMIC0_NOMINALS[i_rail];
    }
    else
    {
        l_volt = PMIC1_NOMINALS[i_rail];
    }

    // The actual voltage setting is shifted to the left by 1 bit in the regsiter,
    // so to apply the offsets, let's right adjust it
    l_volt >>= CONSTS::SHIFT_VOLTAGE_FOR_REG;

    FAPI_TRY(mss::attr::get_volt_offset[i_rail][l_relative_id](l_ocmb, l_volt_offset));
    FAPI_TRY(mss::attr::get_efd_volt_offset[i_rail][l_relative_id](l_ocmb, l_efd_volt_offset));

    l_nominal_voltage = l_volt + l_volt_offset + l_efd_volt_offset;

    // Since l_volt was really 7 bits, and the offsets are also a maximum of 7 bits,
    // even the max bitmaps for each - 0b01111111 added together would not exceed the uint8_t bounds,
    // so for both an overflow or underflow of the max 7 bits, we are guaranteed to see that reflected
    // in the MSB. So, we have over or underflowed if and only if the resulting bitmap is less than 0x80

    // If we were to underflow, we are guaranteed to see it wrapped around in the MSB
    FAPI_ASSERT(l_nominal_voltage <= CONSTS::MAX_VOLT_BITMAP,
                fapi2::PMIC_VOLTAGE_OUT_OF_RANGE()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb)
                .set_VOLTAGE_BITMAP(l_nominal_voltage)
                .set_RAIL(mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail])
                .set_BASE_VOLTAGE(l_volt)
                .set_SPD_OFFSET(l_volt_offset)
                .set_EFD_OFFSET(l_efd_volt_offset),
                "Voltage bitmap 0x%02X out of range as determined by base voltage +/- offset for %s of %s"

// PPE only supports a few fields per printout, so we will do the 3 most important for PPE,
// and then 3 additional for FW
#ifndef __PPE__
                // Space is intentional here as this is concatenated on the previous string
                " BASE_VOLT: %u SPD_OFFSET: %d EFD_OFFSET: %d"
#endif
                , l_nominal_voltage, PMIC_RAIL_NAMES[i_rail], mss::c_str(i_pmic_target)

#ifndef __PPE__
                , l_volt, l_volt_offset, l_efd_volt_offset
#endif
               );

    // Shift over a bit for the voltage setting register
    o_nominal_voltage = l_nominal_voltage << CONSTS::SHIFT_VOLTAGE_FOR_REG;

fapi_try_exit:
    return fapi2::current_err;
}

} // pmic
} // mss
