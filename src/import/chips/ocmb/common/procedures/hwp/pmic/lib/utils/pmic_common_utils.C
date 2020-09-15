/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.C $ */
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
/// @file pmic_common_utils.C
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{
namespace pmic
{


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

    fapi2::ReturnCode l_lock_return_code = fapi2::FAPI2_RC_SUCCESS;

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
/// @brief Calculate target voltage for PMIC from attribute settings
///
/// @param[in] i_ocmb_target OCMB parent target of pmic of PMIC (holds the attributes)
/// @param[in] i_id ID of pmic (0,1)
/// @param[in] i_rail RAIL to calculate voltage for
/// @param[out] o_volt_bitmap output bitmap
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode calculate_voltage_bitmap_from_attr(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id,
    const uint8_t i_rail,
    uint8_t& o_volt_bitmap)
{
    uint8_t l_volt = 0;
    int8_t l_volt_offset = 0;
    int8_t l_efd_volt_offset = 0;

    // Get the attributes corresponding to the rail and PMIC indices
    FAPI_TRY(mss::attr::get_volt_setting[i_rail][i_id](i_ocmb_target, l_volt));
    FAPI_TRY(mss::attr::get_volt_offset[i_rail][i_id](i_ocmb_target, l_volt_offset));
    FAPI_TRY(mss::attr::get_efd_volt_offset[i_rail][i_id](i_ocmb_target, l_efd_volt_offset));

    // Set output buffer
    o_volt_bitmap = l_volt + l_volt_offset + l_efd_volt_offset;

fapi_try_exit:
    return fapi2::current_err;
}

namespace status
{

///
/// @brief Checks that the PMIC is enabled via VR Enable bit
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_for_vr_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer),
             "start_vr_enable: Could not read address 0x%02hhX of %s to check for VR Enable",
             REGS::R32,
             mss::c_str(i_pmic_target));

    // Make sure we are enabled
    FAPI_ASSERT(l_vr_enable_buffer.getBit<FIELDS::R32_VR_ENABLE>(),
                fapi2::PMIC_NOT_ENABLED()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(i_ocmb_target),
                "PMIC %s was not identified as enabled by checking VR Enable bit",
                mss::c_str(i_pmic_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note the returned target is only valid if o_errors returns as true. Else, the target is an uninitialized blank target!
///
fapi2::ReturnCode check_all_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    const char* l_ocmb_c_str = mss::c_str(i_ocmb_target);

    // Initialize returnable PMIC with a blank target. This blank target won't be used if there's no error.
    // If there is an error, this will be overwritten with a valid erroneous PMIC
    bool l_pmic_error = false;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Start success so we can't log and return the same error in loop logic
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Check that the PMICs are enabled and without errors
    for (const auto& l_pmic : mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target))
    {
        // Don't run if our N Mode configuration has been overridden to skip this pmic
        // (in which case it was never enabled)
        FAPI_TRY(run_if_not_disabled(l_pmic, [&i_ocmb_target, &l_pmic, &l_pmic_error]()
        {
            FAPI_TRY_LAMBDA(check_for_vr_enable(i_ocmb_target, l_pmic));
            FAPI_TRY_LAMBDA(mss::pmic::status::check_pmic(l_pmic, l_pmic_error));

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));


        FAPI_ASSERT_NOEXIT(!l_pmic_error,
                           fapi2::PMIC_STATUS_ERRORS()
                           .set_OCMB_TARGET(i_ocmb_target)
                           .set_PMIC_TARGET(l_pmic),
                           "PMIC on OCMB %s had one or more status bits set after running pmic_enable(). "
                           "One of possibly several bad PMICs: %s",
                           l_ocmb_c_str, mss::c_str(l_pmic));

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
        }

        // Reset for next loop
        l_rc = fapi2::current_err;
        l_pmic_error = false;
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    // Else, exit on whatever RC we had
    FAPI_TRY(l_rc);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the PMIC's status codes and report back if an error occurred
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_error true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode check_pmic(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    bool& o_error)
{
    o_error = false;
    bool l_pmic_is_idt = false;

    FAPI_TRY(pmic_is_idt(i_pmic_target, l_pmic_is_idt));

    if (l_pmic_is_idt)
    {
        // These registers reflect the previous power down cycle of the PMIC. Therefore, they may
        // not necessarily cause issues on this life. So, we do not need to worry about keeping track if
        // these failed with l_status_error, but the check_fields() function will still print them out.
        bool l_status_error = false;

        // if we exit from this try, there were i2c errors
        FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "PMIC_WARNING_BIT",
                 mss::pmic::status::IDT_SPECIFIC_STATUS_FIELDS, l_status_error));
    }

    {
        bool l_status_error = false;

        // if we exit from this try, there were i2c errors
        FAPI_TRY(mss::pmic::status::check_fields(i_pmic_target, "ERROR", mss::pmic::status::STATUS_FIELDS, l_status_error));
        o_error = l_status_error;
    }

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

///
/// @brief Check an individual set of PMIC status codes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_error_type error type for the PMIC in question
/// @param[in] i_statuses STATUS object to check
/// @param[out] o_error At least one error bit was found to be set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error in case of an I2C read error
///
fapi2::ReturnCode check_fields(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const char* i_error_type,
    const std::vector<std::pair<uint8_t, std::vector<status_field>>>& i_statuses,
    bool& o_error)
{
    o_error = false;

    for (const auto& l_reg_bit_pair : i_statuses)
    {
        fapi2::buffer<uint8_t> l_reg_contents;
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, l_reg_bit_pair.first, l_reg_contents));

        for (const auto& l_status : l_reg_bit_pair.second)
        {
            if (l_reg_contents.getBit(l_status.l_reg_field))
            {
                // Print it out
                FAPI_ERR("%s %s :: REG 0x%02x bit %u was set on %s",
                         l_status.l_error_description,
                         i_error_type,
                         l_reg_bit_pair.first,
                         l_status.l_reg_field,
                         mss::c_str(i_pmic_target));
                // We don't want to exit out here, errors can be independent of each other and we should check them all.
                // Since there's no easy way to FFDC each individual error, we will report them here and then worry about
                // return codes in the caller of this function
                o_error = true;
            }
        }

        l_reg_contents.flush<0>();
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // status
} // pmic
} // mss
