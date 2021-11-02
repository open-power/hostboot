/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_enable_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
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
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/poll.H>
#include <lib/utils/pmic_enable_4u_settings.H>

namespace mss
{
namespace gpio
{

///
/// @brief Poll for the GPIO input port ready on the bit corresponding to the PMIC pair
///
/// @param[in] i_gpio_target GPIO target
/// @param[in] i_pmic_target PMIC target that the input line is connecting to
/// @param[in] i_pmic_pair_bit the PMIC pair bit INPUT_PORT_REG_PMIC_PAIR0/1
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_input_port_ready(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_pmic_pair_bit)
{
    const char* l_gpio_string = mss::c_str(i_gpio_target);

    // We want a 50ms timeout, so let's poll 10 times at 5ms a piece
    mss::poll_parameters l_poll_params;
    l_poll_params.iv_delay = 5 * mss::common_timings::DELAY_1MS;
    l_poll_params.iv_poll_count = 10;

    const bool l_success = mss::poll(i_gpio_target, l_poll_params, [&i_gpio_target, i_pmic_pair_bit, l_gpio_string]()->bool
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
        // Getting here implies we've nacked, which should not occur unless the GPIO has suddenly
        // died in the last few milliseconds. We'll throw a FAPI_DBG in for debug purposes
        // (as now we're guaranteed to not get past this istep), but this should never occur.
        FAPI_DBG("%s did not ACK, will cause PMICs to drop into N-Mode", l_gpio_string);
        return false;
    });

    if (!l_success)
    {
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::GPIO_INPUT_PORT_TIMEOUT(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_TARGET(i_pmic_target)
                           .set_GPIO(i_gpio_target)
                           .set_PMIC_PAIR_BIT(i_pmic_pair_bit),
                           "%s Did not report input bit %u ready, %s did not report PWR_GOOD, declaring N-Mode",
                           l_gpio_string, i_pmic_pair_bit, mss::c_str(i_pmic_target));

        // Set current_err back to success
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // As the trace implies, now we will declare N-mode
        FAPI_TRY(mss::attr::set_n_mode_helper(
                     mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                     mss::index(i_pmic_target),
                     mss::pmic::n_mode::N_MODE));
    }

    // If we get here, we are good
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // This should only be reached in the case of an attribute set error
    return fapi2::current_err;
}

}
namespace pmic
{

///
/// @brief Set PWR_GOOD pin to I/O
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is intended for use on 1U/2U DDIMMs
///
fapi2::ReturnCode set_pwr_good_pin_io(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;
    using CONSTS = mss::pmic::consts<J>;

    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // Enable I/O PWR_GOOD pin (1 --> Bit 5)
    l_vr_enable_buffer.writeBit<FIELDS::R32_PWR_GOOD_IO_TYPE>(CONSTS::PWR_GOOD_IO_TYPE_IO);
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set EXECUTE_VR_ENABLE_CONTROL to execute VR enable command,
///        clear VR execute disable command for camp fail_n function,
///        clear CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL so that PMIC can control PWR_GOOD output on its own based on internal status
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is intended for use on IDT 1U/2U DDIMMs with revision greater than 0x31
///
fapi2::ReturnCode set_vr_enable_clear_camp_pwr_good_pins(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;

    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // Set EXECUTE_VR_ENABLE_CONTROL to execute VR enable command (1 --> Bit 5)
    l_vr_enable_buffer.setBit<FIELDS::R32_EXECUTE_VR_ENABLE_CONTROL>();
    // Clear VR execute disable command for camp fail_n function (0 --> Bit 4)
    l_vr_enable_buffer.clearBit<FIELDS::R32_EXECUTE_CAMP_FAIL_N_FUNCTION_CONTROL>();
    // Clear CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL so that PMIC can control PWR_GOOD output on its own based on internal status
    // (0 --> Bit 3)
    l_vr_enable_buffer.clearBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set PWR_GOOD pin to Output
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_pwr_good_pin_output(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;
    using CONSTS = mss::pmic::consts<J>;

    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // Enable Output PWR_GOOD pin (0 --> Bit 5)
    l_vr_enable_buffer.writeBit<FIELDS::R32_PWR_GOOD_IO_TYPE>(CONSTS::PWR_GOOD_IO_TYPE_OUTPUT);
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Toggle the VR enable bit (0->1)
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode toggle_vr_enable(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;
    using FIELDS = pmicFields<J>;

    fapi2::buffer<uint8_t> l_vr_enable_buffer;

    // delay 20ms to make sure PMIC rails are on from previous VR enable, otherwise pmic
    //   rails may not go through the pmic power off sequence when VR disable is done below
    //   which can cause VDDR to be greater than VPP for a short time at low voltages (this was seen on 16GB 2U)
    // power on sequence and idle delays add up to 12 ms for 2U DDIMMs, so have this delay be > 12 ms)
    fapi2::delay(20 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Toggle VR enable bit (0->1)
    // VR disable
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));
    l_vr_enable_buffer.clearBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    // delay 40ms to make sure PMIC rails are off before VR enable is done
    // Note that 16GB 2U uses 24 ms idle time after power off sequence0, so make sure this is accounted for
    //   along with the 4ms soft stop times  (adds up to 32 ms, so have this delay be > 32 ms)
    fapi2::delay(40 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // VR enable
    l_vr_enable_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R32, l_vr_enable_buffer));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workaround for PMIC high current consumption false errors seen with IDT PMICs
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note Issue with IDT PMIC revision C (R3B=0x21) or earlier version
/// @note Workaround:  Before VR enable, set R30=0x03, then set R30=0x00
///
fapi2::ReturnCode workaround_high_current_consumption_false_errors(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    static constexpr auto J = mss::pmic::product::JEDEC_COMPLIANT;
    using REGS = pmicRegs<J>;

    fapi2::buffer<uint8_t> l_rev_reg;
    constexpr uint8_t WORKAROUND_R30_BEFORE_VR_ENABLE_STEP1 = 0x03;
    constexpr uint8_t WORKAROUND_R30_BEFORE_VR_ENABLE_STEP2 = 0x00;
    constexpr uint8_t IDT_C1_REV = 0x21;

    // Get revision
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_rev_reg));

    // Only do workaround for revisions that have the issue
    // Register write only should be fine to do here for R30 (vs read/modify/write)
    // If register is used for ADC readings, it will be reconfigured when those are done
    // After the register writes are done here, it will be at the default state
    if (l_rev_reg <= IDT_C1_REV)
    {
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, WORKAROUND_R30_BEFORE_VR_ENABLE_STEP1));
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, WORKAROUND_R30_BEFORE_VR_ENABLE_STEP2));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set VR enable bit for system startup via R32 (not broadcast)
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

    // Perform last-minute pre-enable steps, workarounds, etc. common to 1U/2U/4U PMICs
    FAPI_TRY(mss::pmic::pre_enable_steps(i_pmic_target));

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
    // Log as recoverable, set N mode attribute, all will be checked later
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    return mss::attr::set_n_mode_helper(
               i_ocmb_target,
               i_pmic_id,
               mss::pmic::n_mode::N_MODE);
}

///
/// @brief Set the up VIN latch bit for TPS pmics
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_tps_vin_latch(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;
    bool l_pmic_is_ti = false;

    FAPI_TRY(mss::pmic::pmic_is_ti(i_pmic_target, l_pmic_is_ti));

    // If we're TI, set the TPS-specific R9C_EN_VINUV_FLT_LATCH bit, which we should use from
    // initial poweron, onwards. This handles a FW corner case where loss of 12V prior to enable,
    // and then a poweron, the TPS parts get stuck in a lockout state requiring a VR_Enable toggle.
    // This in conjunction with a EEPROM update should prevent such an issue
    if (l_pmic_is_ti)
    {
        fapi2::buffer<uint8_t> l_reg_contents;
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(
                     i_pmic_target, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_contents));

        // Update the bit
        l_reg_contents.setBit<TPS_FIELDS::R9C_EN_VINUV_FLT_LATCH>();

        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(
                     i_pmic_target, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_contents));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set the soft start times to 4ms for the provided PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is used for 4U in order to avoid the issue of too-high current sink during a VR_DISABLE
///
fapi2::ReturnCode set_soft_start_time(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    // Just a direct write
    // If this ever increases from 4ms, need to consider changing delay used for 1U/2U DDIMMs
    //   before the function call set_pwr_good_pin_io for TI PMICs.  See enable_1u_2u for more details.
    fapi2::buffer<uint8_t> l_reg_contents(CONSTS::R2C_R2D_4MS_ALL);
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R2C, l_reg_contents));
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R2D, l_reg_contents));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the soft stop time to maximum for the provided PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is used for 4U in order to avoid the issue of too-high current sink during a VR_DISABLE
///
fapi2::ReturnCode set_soft_stop_time(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_CONSTS = mss::pmic::consts<mss::pmic::product::TPS5383X>;

    static constexpr uint8_t NUM_REGS = 4;

    // Static as this is the same for all PMICs, and each run of this function
    static constexpr std::array<uint8_t, NUM_REGS> SOFT_STOP_TIME_REGS =
    {REGS::R22, REGS::R24, REGS::R26, REGS::R28};

    static constexpr std::array<uint8_t, NUM_REGS> TPS_SOFT_STOP_CFG_REGS =
    {
        TPS_REGS::R94_SOFT_STOP_CFG_SWA,
        TPS_REGS::R95_SOFT_STOP_CFG_SWB,
        TPS_REGS::R96_SOFT_STOP_CFG_SWC,
        TPS_REGS::R97_SOFT_STOP_CFG_SWD
    };

    // First we will set the host region registers. This will be a fallback in case
    // for some reason the fixed slew settings don't take effect
    for (const uint8_t l_reg : SOFT_STOP_TIME_REGS)
    {
        fapi2::buffer<uint8_t> l_reg_contents;
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, l_reg, l_reg_contents));

        // Setting these two bits ensures the largest soft stop time
        l_reg_contents.setBit<FIELDS::SOFT_STOP_TIME, FIELDS::SOFT_STOP_TIME_LEN>();

        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, l_reg, l_reg_contents));
    }

    // Next, perform the TPS-specific fixed-slew rate workaround. When these registers are set,
    // the SOFT_STOP_TIME_REGS settings are ignored, so these are most important.
    for (const auto l_reg : TPS_SOFT_STOP_CFG_REGS)
    {
        fapi2::buffer<uint8_t> l_reg_contents(TPS_CONSTS::MAX_SOFT_STOP_CFG);
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, l_reg, l_reg_contents));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform pre-enable steps, workarounds, etc.
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pre_enable_steps(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    // TPS VIN Latch workaround
    FAPI_TRY(setup_tps_vin_latch(i_pmic_target));

    // Increase soft start times to 4ms to avoid overcurrent warnings
    FAPI_TRY(mss::pmic::set_soft_start_time(i_pmic_target));

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
        FAPI_ASSERT((l_sequence_orders[l_rail_index] < CONSTS::ORDER_LIMIT),
                    fapi2::PMIC_ORDER_OUT_OF_RANGE()
                    .set_PMIC_TARGET(i_pmic_target)
                    .set_OCMB_TARGET(i_ocmb_target)
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
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    // Check and make sure the given delay is less than the bitmask (else, we overflow later on)
    FAPI_ASSERT(i_delay <= CONSTS::MAX_DELAY_BITMAP,
                fapi2::PMIC_DELAY_OUT_OF_RANGE()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb)
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
    fapi2::buffer<uint8_t> l_rev_reg;

    FAPI_INF("Setting PMIC %s settings from SPD", mss::c_str(i_pmic_target));

    // Make sure it is TI or IDT
    FAPI_ASSERT((i_vendor_id == mss::pmic::vendor::IDT ||
                 i_vendor_id == mss::pmic::vendor::TI),
                fapi2::PMIC_CHIP_NOT_RECOGNIZED()
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(i_ocmb_target)
                .set_VENDOR_ID(i_vendor_id),
                "Unknown PMIC: %s with vendor ID 0x%04hhX",
                mss::c_str(i_pmic_target),
                uint16_t(i_vendor_id) );

    // Check that the PMIC vendor ID register matches the attribute
    // (and therefore has the correct settings)
    FAPI_TRY(mss::pmic::check::matching_vendors(i_ocmb_target, i_pmic_target));

    if (i_vendor_id == mss::pmic::vendor::IDT)
    {
        FAPI_TRY(mss::pmic::check::validate_and_return_idt_revisions(i_ocmb_target, i_pmic_target, l_rev_reg));
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
/// @brief PMIC power down sequence for 1U/2U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode power_down_sequence_1u_2u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_target);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_target, l_pmics));

    // Reverse loop, so we disable in the opposite order as the enable
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];
        fapi2::buffer<uint8_t> l_reg_contents;

        // Redundant clearBit, but just so it's clear what we're doing
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(PMIC, REGS::R32, l_reg_contents));
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        // Due to long soft stop time in 4U (~8ms), let's delay for 10ms to be safe
        fapi2::delay(10 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

        // We are opting here to log RC's here as recovered. If this register write fails,
        // the ones later in the procedure will fail as well.
        l_rc = mss::pmic::i2c::reg_write_reverse_buffer(PMIC, REGS::R32, l_reg_contents);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PMIC power down sequence for 4U parts for pmic
///
/// @param[in,out] io_target_info Target info struct
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode pmic_clear_vr_swa_swc_en(target_info_redundancy& io_target_info)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    // Regardless of the N-Mode states, we want to try to do a full disable of all parts
    // so if we do hit a failure on a PMIC write, we will just continue. enable_with_redundancy
    // on the next run of pmic_enable should catch read/write failures and handle them correctly
    // with the correct N-Mode declaration logic

    // These PMIC writes have the potential to fail in N-Mode configs. We will not do any
    // N-mode declarations here as the runtime detection or next enable will catch all of these.
    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC3, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // VR Disable PMIC3
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC1, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // VR Disable PMIC1
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC2, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // Disable SWA and SWC of PMIC2
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R2F, l_reg_contents);

        l_reg_contents.clearBit<FIELDS::R2F_SWA_REGULATOR_CONTROL>();
        l_reg_contents.clearBit<FIELDS::R2F_SWC_REGULATOR_CONTROL>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R2F, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC0, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // Disable SWA and SWC of PMIC0
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R2F, l_reg_contents);

        l_reg_contents.clearBit<FIELDS::R2F_SWA_REGULATOR_CONTROL>();
        l_reg_contents.clearBit<FIELDS::R2F_SWC_REGULATOR_CONTROL>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R2F, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    // Delay 700ms to allow more time for VDDR to ramp down before VPP ramps down.
    fapi2::delay(700 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC0, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // VR Disable
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    FAPI_TRY_NO_TRACE(run_if_present(io_target_info.iv_pmic_map, mss::pmic::id::PMIC2, []
                                     (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
    {
        fapi2::buffer<uint8_t> l_reg_contents;

        // VR Disable
        mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_reg_contents);

        return fapi2::FAPI2_RC_SUCCESS;
    }));

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PMIC power down sequence for 4U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode power_down_sequence_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    const auto I2C_DEVICES =
        mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_target);

    // Grab the targets as a struct, if they exist
    target_info_redundancy l_target_info(i_target, l_rc);

    // If platform did not provide a usable (functional) set of targets (4 GENERICI2CSLAVE, at least 2 PMICs),
    // Then we can't properly disable, the part is as good as dead, since re-enable would fail
    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        // We don't fail here because we could be looking at a DIMM that's been deconfigured already
        FAPI_INF("Non-functional targets found from %s", mss::c_str(i_target));
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // ADC or GPIO fails are hard fails.
    // ADCs and GPIOs are guaranted to exist as asserted by l_rc above
    FAPI_TRY(mss::pmic::i2c::reg_write(l_target_info.iv_adc1, mss::adc::regs::GENERAL_CFG,
                                       mss::adc::fields::GENERAL_CFG_CLEAR_STATS_EN));
    FAPI_TRY(mss::pmic::i2c::reg_write(l_target_info.iv_adc1, mss::adc::regs::SEQUENCE_CFG,
                                       mss::adc::fields::SEQUENCE_CFG_AUTO_SEQUENCE));

    FAPI_TRY(mss::pmic::i2c::reg_write(l_target_info.iv_adc2, mss::adc::regs::GENERAL_CFG,
                                       mss::adc::fields::GENERAL_CFG_CLEAR_STATS_EN));
    FAPI_TRY(mss::pmic::i2c::reg_write(l_target_info.iv_adc2, mss::adc::regs::SEQUENCE_CFG,
                                       mss::adc::fields::SEQUENCE_CFG_AUTO_SEQUENCE));

    FAPI_TRY(pmic_clear_vr_swa_swc_en(l_target_info));

    // Finally, disable the GPIOs, and delay
    FAPI_TRY(mss::pmic::i2c::reg_write(I2C_DEVICES[mss::GPIO1], mss::gpio::regs::EFUSE_OUTPUT,
                                       mss::gpio::fields::EFUSE_OUTPUT_OFF));
    FAPI_TRY(mss::pmic::i2c::reg_write(I2C_DEVICES[mss::GPIO2], mss::gpio::regs::EFUSE_OUTPUT,
                                       mss::gpio::fields::EFUSE_OUTPUT_OFF));

    // Delay 2 seconds. FW and cronus run pmic_enable in parallel. So the overall delay will only be 2 secs
    // across all the targets during IPL
    fapi2::delay(2000 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Power down function for 4U pmics
/// @param[in] i_target ocmb target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pmic_power_down(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_module_height = 0;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::attr::get_dram_module_height(i_target, l_module_height));

    // For non 4U configs, let's just VR disable down the line
    if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        // For 4U, do our defined disable sequence
        FAPI_TRY(mss::pmic::power_down_sequence_4u(i_target));
    }
    else
    {
        FAPI_TRY(mss::pmic::power_down_sequence_1u_2u(i_target));
    }

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
    // Make sure to grab all pmics - functional or not, in case the parent OCMB
    // was deconfigured. That may have marked the PMICs as non-functional
    bool l_pmic_is_ti = false;
    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

    // First, we have to clear the PWR_GOOD IO Mode for all TI PMICs, then we will VR Disable for
    // all PMICs. These have to be done in separate loops, as once a PMIC is disabled, it may drive
    // PWR_GOOD low which would cause the other PMIC to immediately turn off (if it was still
    // configured in I/O mode)

    // Iterate in the reverse order of the sequence attributes, so we disable in the reverse sequence
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];

        // TI PMICS, we need to reset the PWR_GOOD_IO_TYPE to OUTPUT (instead of I/O) before we VR_DISABLE
        // For 4U this is essentially a no-op since we'll always be in Output mode, but is required for 2U
        FAPI_TRY(pmic_is_ti(PMIC, l_pmic_is_ti));

        if (l_pmic_is_ti)
        {
            fapi2::buffer<uint8_t> l_reg_contents;

            FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(PMIC, REGS::R32, l_reg_contents));
            l_reg_contents.writeBit<FIELDS::R32_PWR_GOOD_IO_TYPE>(CONSTS::PWR_GOOD_IO_TYPE_OUTPUT);
            FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(PMIC, REGS::R32, l_reg_contents));

        }
    }

    // Call the new PMIC power down sequence
    FAPI_TRY(pmic_power_down(i_ocmb_target));

    // Reverse loop
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];

        // Now that it's disabled, let's clear the status bits so errors don't hang over into the next enable
        // Similarly, we will log bad ReturnCodes here as recoverable for the reasons mentioned above
        l_rc = mss::pmic::status::clear(PMIC);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
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
    constexpr uint8_t IDT_D0_REV = 0x31;

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

    // We're guaranteed to have at least one PMIC here due to the check in pmic_enable
    auto l_current_pmic = l_pmics[0];

    // Now the PMICs are in the right order of DIMM and the right order by their defined SPD sequence within each dimm
    // Let's kick off the enables

    // We must consider the PWR_GOOD mode. The enable sequence must be in this order:
    // Note that before VR disable in disable_and_reset_pmics, TI PMICs get pgood set as output only
    // For IDT:
    // Revision < IDT_D0_REV
    // PMIC0:  pgood=output        (IDT ONLY, could be intput+output but will setup the same way as TI)
    // PMIC1:  pgood=input+output  (IDT ONLY)
    // Revision >= IDT_D0_REV Power good pin has been paired with Camp functionality
    // PMIC0,1:  PMIC CAMP PWR_GOOD=PMIC controls PWR_GOOD output on its own based on internal status
    //           PMIC CAMP Fail_n function=Execute VR Disable Command
    // IDT/TI all revisions
    // PMIC0,1:  VR enable
    // PMIC0:  pgood=output        (TI ONLY - already set to output only in disable_and_reset_pmics)
    // PMIC1:  pgood=input+output  (TI ONLY)

    // We should never have PMICs from both vendors on a dimm, so we shouldn't have to worry about any
    // interleaving. However, we do check the vendor on each PMIC anyway.

    // Ensure the PMICs are in sorted order
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

    // Before VR enable is done, enable appropriate bits on IDT PMICs w.r.t. the revision of the PMICs
    for (const auto& l_pmic : l_pmics)
    {
        l_current_pmic = l_pmic;
        uint16_t l_vendor_id = 0;
        fapi2::buffer<uint8_t> l_idt_rev;

        // Get vendor ID
        FAPI_TRY(mss::attr::get_mfg_id[get_relative_pmic_id(l_pmic)](i_ocmb_target, l_vendor_id));

        // Get revision number
        FAPI_TRY(mss::pmic::check::validate_and_return_idt_revisions(i_ocmb_target, l_pmic, l_idt_rev));

        // For revision less than 0x31: Call the procedure to configure power good pin to I/O for last PMIC in power on sequence in
        // order to have DDR4 SDRAM VPP/VDDR power sequencing spec met (VPP >= VDDR) when a PMIC fails
        // TI PMICs violate this power sequencing spec if both PMICs have PWR_GOOD=I/O when system
        //   does a power off/on.  IDT does not, but will set both up the same way.
        // TI PMICs PWR_GOOD I/O mode must be enabled after VR Enable
        // IDT PMICs PWR_GOOD I/O mode must be enabled before VR Enable for revisions less than 0x31

        // For IDT PMIC revisions >= 0x31, following should be done before VR Enable:
        //          EXECUTE_VR_ENABLE_CONTROL_=Execute VR Enable Command
        //          PMIC CAMP PWR_GOOD=PMIC controls PWR_GOOD output on its own based on internal status
        //          PMIC CAMP Fail_n function=Execute VR Disable Command

        if (l_vendor_id == mss::pmic::vendor::IDT)
        {
            if (l_idt_rev >= IDT_D0_REV)
            {
                FAPI_TRY(set_vr_enable_clear_camp_pwr_good_pins(l_pmic));
            }
            // Have first IDT PMIC in power on sequence set power good as output only to match what TI will have
            // Added this because we have different default values depending on IDT chip revision
            else if (l_pmic == l_pmics[0])
            {
                FAPI_TRY(set_pwr_good_pin_output(l_pmic));
            }
            else
            {
                FAPI_TRY(set_pwr_good_pin_io(l_pmic));
            }
        }

        // Call the workaround procedure for IDT PMIC high current consumption false errors
        // Workaround only needed for IDT PMICs revision C or earlier version
        // Needs to be called before VR is enabled
        if (l_vendor_id == mss::pmic::vendor::IDT)
        {
            FAPI_TRY(workaround_high_current_consumption_false_errors(l_pmic));
        }

    }

    // So we will need a few loops, VR will be enabled here (in the if or else block here)
    if (i_mode == mss::pmic::enable_mode::MANUAL)
    {
        for (const auto& l_pmic : l_pmics)
        {
            l_current_pmic = l_pmic;
            uint16_t l_vendor_id = 0;

            // Get vendor ID
            FAPI_TRY(mss::attr::get_mfg_id[get_relative_pmic_id(l_pmic)](i_ocmb_target, l_vendor_id));

            // Check to make sure VIN_BULK reports good, then we can enable the chip and write/read registers
            FAPI_TRY(check_vin_bulk_good(l_pmic),
                     "pmic_enable: Check for VIN_BULK good either failed, or returned not good status on PMIC %s",
                     mss::c_str(l_pmic));
            FAPI_TRY(start_vr_enable(l_pmic));

            // Toggle VR enable bit for TI PMIC regardless of how pgood is configured
            // Have seen some TI PMICs fail to power on outputs when VR enable bit is set
            //   and a VR enable bit toggle allows the outputs to successfully power on
            if (l_vendor_id == mss::pmic::vendor::TI)
            {
                FAPI_TRY(toggle_vr_enable(l_pmic));
            }
        }
    }
    else
    {
        // 1U/2U enable process
        for (const auto& l_pmic : l_pmics)
        {
            l_current_pmic = l_pmic;
            uint16_t l_vendor_id = 0;

            // Get vendor ID
            FAPI_TRY(mss::attr::get_mfg_id[get_relative_pmic_id(l_pmic)](i_ocmb_target, l_vendor_id));

            // Call the enable procedure
            FAPI_TRY((enable_spd(l_pmic, i_ocmb_target, l_vendor_id)),
                     "pmic_enable: Error enabling PMIC %s", mss::c_str(l_pmic));

            // Toggle VR enable bit for TI PMIC regardless of how pgood is configured
            // Have seen some TI PMICs fail to power on outputs when VR enable bit is set
            //   and a VR enable bit toggle allows the outputs to successfully power on
            if (l_vendor_id == mss::pmic::vendor::TI)
            {
                FAPI_TRY(toggle_vr_enable(l_pmic));
            }
        }
    }

    // After VR has been enabled, enable PWR_GOOD on TI PMICs
    // Configure PWR_GOOD for TI PMIC
    for (const auto& l_pmic : l_pmics)
    {
        l_current_pmic = l_pmic;
        uint16_t l_vendor_id = 0;

        // Get vendor ID
        FAPI_TRY(mss::attr::get_mfg_id[get_relative_pmic_id(l_pmic)](i_ocmb_target, l_vendor_id));

        // Only do for last TI PMIC in power on sequence as that is the one that will have PWR_GOOD set to I/O
        if ((l_vendor_id == mss::pmic::vendor::TI) && (l_pmic != l_pmics[0]))
        {
            // Setting PWR_GOOD to I/O too soon after VR enable causes PMIC to fail to power on successfully
            // Seen failure to power on rails with delay of 3ms with soft start time 4ms in a system with 2U DDIMMs
            // Seen failure to power on rails with delay of 29ms with soft start time 14ms in a system with 2U DDIMMs
            //   These are lower than calculated, but in sytems there will be delay time in sending commands
            // This delay needs to account for the time for all rails to power up per the power on sequence
            //   config 0-3 registers because after all PMIC output regulators are on it will release PWR_GOOD
            //   Want to configure PWR_GOOD to I/O after PMIC has released PWR_GOOD (ie.  after it goes high)
            //   When choosing a delay value, make sure it also accounts for the PMIC soft start times
            // 1U/2U DDIMM settings use 4ms soft start time and two power on sequence config registers with 2ms idle delay
            //    Power on sequence config0 (soft start time + delay time) = 4 + 2 = 6 ms
            //    Power on sequence config1 (soft start time + delay time) = 4 + 0 = 4 ms (delay time shouldn't apply)
            //    Total time = 10 ms, but soft start time depends on voltage level so need to account for that
            //      If we double this to 20 ms, that should be more than enough for 1U/2U DDIMMs settings in use today
            //    Worst case time would account for 14ms soft start time, 24ms delay time, and 4 power seq config regs
            //      [4 * (14 + 24)] = 152  (last delay time may not be needed, but we need margin for soft start times
            // Let's use 50ms to account for some (not worst case) increases in soft start time and idle delay time
            // If we wanted to really play it safe, we'd have to read registers/attributes and base this delay on that
            fapi2::delay(50 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

            // Call the procedure to configure power good pin to I/O for last PMIC in power on sequence in
            // order to have DDR4 SDRAM VPP/VDDR power sequencing spec met (VPP >= VDDR) when a PMIC fails
            // TI PMICs violate this power sequencing spec if both PMICs have PWR_GOOD=I/O when system
            //   does a power off/on.  IDT does not, but will set both up the same way.
            // TI PMICs PWR_GOOD I/O mode must be enabled after VR Enable
            // IDT PMICs PWR_GOOD I/O mode must be enabled before VR Enable

            FAPI_TRY(set_pwr_good_pin_io(l_pmic));
        }
    }

    // delay after final VR enable and before checking status
    // soft start time and idle delays add up to 12 ms for 2U DDIMMs, so have this delay be > 12 ms)
    fapi2::delay(20 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Check that all the PMIC statuses are good post-enable
    FAPI_TRY(mss::pmic::status::check_all_pmics(i_ocmb_target),
             "Bad statuses returned, or error checking statuses of PMICs on %s", mss::c_str(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // Logs the current error as prective, as it predicts that we had a PMIC enable fail
    // Deconfigures happen at the end of an istep, so this should be ok with hostboot
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_ASSERT_NOEXIT(false,
                       fapi2::PMIC_ENABLE_FAIL()
                       .set_OCMB_TARGET(i_ocmb_target)
                       .set_PMIC_TARGET(l_current_pmic)
                       .set_RETURN_CODE(static_cast<uint32_t>(fapi2::current_err)),
                       "PMIC %s failed to enable. See previous errors for details.",
                       mss::c_str(l_current_pmic));
    return fapi2::current_err;
}

///
/// @brief Read adc min voltage registers so that they can track any dips in the voltages after
///        power on as they are self resetting
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode adc_min_vltg_read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target)
{
    fapi2::buffer<uint8_t> l_reg;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Grab the targets as a struct, if they exist
    target_info_redundancy l_target_info(i_ocmb_target, l_rc);
    FAPI_TRY(l_rc, "Unusable PMIC/GENERICI2CSLAVE child target configuration found from %s",
             mss::c_str(i_ocmb_target));

    // ADC1
    mss::pmic::i2c::reg_read_reverse_buffer(l_target_info.iv_adc1, mss::adc::regs::GENERAL_CFG, l_reg);
    l_reg.clearBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(l_target_info.iv_adc1, mss::adc::regs::GENERAL_CFG, l_reg);

    // Read adc1 Min voltage regs
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH0_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH1_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH2_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH3_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH4_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH5_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH6_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc1, mss::adc::regs::MIN_CH7_LSB, l_reg));

    mss::pmic::i2c::reg_read_reverse_buffer(l_target_info.iv_adc1, mss::adc::regs::GENERAL_CFG, l_reg);
    l_reg.setBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(l_target_info.iv_adc1, mss::adc::regs::GENERAL_CFG, l_reg);

    // ADC2
    mss::pmic::i2c::reg_read_reverse_buffer(l_target_info.iv_adc2, mss::adc::regs::GENERAL_CFG, l_reg);
    l_reg.clearBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(l_target_info.iv_adc2, mss::adc::regs::GENERAL_CFG, l_reg);

    // Read adc2 Min voltage regs
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH0_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH1_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH2_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH3_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH4_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH5_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH6_LSB, l_reg));
    FAPI_TRY(mss::pmic::i2c::reg_read(l_target_info.iv_adc2, mss::adc::regs::MIN_CH7_LSB, l_reg));

    mss::pmic::i2c::reg_read_reverse_buffer(l_target_info.iv_adc2, mss::adc::regs::GENERAL_CFG, l_reg);
    l_reg.setBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(l_target_info.iv_adc2, mss::adc::regs::GENERAL_CFG, l_reg);

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
/// @brief Set the up PMIC ADC to read VIN_BULK
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
/// @note Will set N-Mode attribute on i_pmic_target in case of recoverable error.
///       N-mode states will be handled in process_n_mode_results() later
///
fapi2::ReturnCode setup_adc_vin_bulk_read(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    // Set up PMIC to sample VIN_BULK
    fapi2::buffer<uint8_t> l_reg_contents(CONSTS::R30_SAMPLE_VIN_BULK_ENABLE_ADC);
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R30, l_reg_contents));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return mss::pmic::declare_n_mode(
               mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
               mss::index(i_pmic_target));
}

///
/// @brief Validate that the efuse appears off by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
/// @note Will set N-Mode attribute on i_pmic_target in case of recoverable error.
///       N-mode states will be handled in process_n_mode_results() later
///
fapi2::ReturnCode validate_efuse_off(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_reg_contents;

    // Reset current_err, just in case
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents);

    // Check the error on the reg_read
    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        return mss::pmic::declare_n_mode(
                   mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                   mss::index(i_pmic_target));
    }

    FAPI_DBG("%s EFUSE OFF VIN_BULK Reading: 0x%02X", mss::c_str(i_pmic_target), l_reg_contents);

    // Prior to turning on the efuse via the GPIO expander, we expect to see VIN below the
    // EFUSE_OFF_HIGH threshold, as power will not be applied.
    // Otherwise the efuse must be blown, and we should declare N-mode.
    // Will poll for 2.5 seconds for the VIN to go below EFUSE_OFF_HIGH. If not then will declare N-mode.
    // 25ms * 100 = 2.5 Seconds
    constexpr uint8_t POLL_2_5_SECS = 100;
    constexpr uint8_t THRESHOLD_HIGH = CONSTS::R31_VIN_BULK_EFUSE_OFF_HIGH;
    auto l_vin_below_efuse_off_high = false;

    for (auto count = 0; count < POLL_2_5_SECS; count++)
    {
        if (l_reg_contents > THRESHOLD_HIGH)
        {
            // Delay 25ms and read R31 for VIN value again
            fapi2::delay(25 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);
            fapi2::current_err = mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents);

            // Check the error on the reg_read
            if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
            {
                return mss::pmic::declare_n_mode(
                           mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                           mss::index(i_pmic_target));
            }

            FAPI_DBG("%s EFUSE OFF VIN_BULK Reading: 0x%02X", mss::c_str(i_pmic_target), l_reg_contents);
        }
        else
        {
            l_vin_below_efuse_off_high = true;
            break;
        }
    }

    if (!l_vin_below_efuse_off_high)
    {
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::PMIC_EFUSE_BLOWN(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_PMIC_TARGET(i_pmic_target)
                           .set_EFUSE_DATA(l_reg_contents)
                           .set_THRESHOLD_LOW(0)
                           .set_THRESHOLD_HIGH(THRESHOLD_HIGH),
                           "EFUSE for %s appears blown (data:0x%02X), declaring N-Mode",
                           mss::c_str(i_pmic_target), l_reg_contents);

        // Set current_err back to success
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        return mss::attr::set_n_mode_helper(
                   mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                   mss::index(i_pmic_target),
                   mss::pmic::n_mode::N_MODE);
    }

    return fapi2::FAPI2_RC_SUCCESS;
};

///
/// @brief Validate that the efuse appears on by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
/// @note Will set N-Mode attribute on i_pmic_target in case of recoverable error.
///       N-mode states will be handled in process_n_mode_results() later
///
fapi2::ReturnCode validate_efuse_on(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    fapi2::buffer<uint8_t> l_reg_contents;

    // Reset current_err, just in case
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_reg_contents);

    // Check the error on the reg_read
    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        return mss::pmic::declare_n_mode(
                   mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                   mss::index(i_pmic_target));
    }

    FAPI_DBG("%s EFUSE ON VIN_BULK Reading: 0x%02X", mss::c_str(i_pmic_target), l_reg_contents);

    // After we turn on the efuse via the GPIO expander, power is applied to VIN_BULK,
    // and we should see a valid value within the range of EFUSE_ON_LOW --> HIGH, otherwise,
    // most likely the fuse is blown, so we should declare N-mode.
    if ((l_reg_contents < CONSTS::R31_VIN_BULK_EFUSE_ON_LOW) ||
        (l_reg_contents > CONSTS::R31_VIN_BULK_EFUSE_ON_HIGH))
    {
        constexpr uint8_t THRESHOLD_LOW = CONSTS::R31_VIN_BULK_EFUSE_ON_LOW;
        constexpr uint8_t THRESHOLD_HIGH = CONSTS::R31_VIN_BULK_EFUSE_ON_HIGH;
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::PMIC_EFUSE_BLOWN(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_PMIC_TARGET(i_pmic_target)
                           .set_EFUSE_DATA(l_reg_contents)
                           .set_THRESHOLD_LOW(THRESHOLD_LOW)
                           .set_THRESHOLD_HIGH(THRESHOLD_HIGH),
                           "EFUSE for %s did not appear on (data:0x%02X), declaring N-Mode",
                           mss::c_str(i_pmic_target), l_reg_contents);

        // Set current_err back to success
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        return mss::attr::set_n_mode_helper(
                   mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target),
                   mss::index(i_pmic_target),
                   mss::pmic::n_mode::N_MODE);
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Enable EFUSE according to 4U Functional Specification
///
/// @param[in] i_gpio GPIO target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Corresponds to steps (6,7,8) & (16,17,18) in 4U DDIMM Functional Spec
///
fapi2::ReturnCode setup_gpio_efuse(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio)
{
    fapi2::buffer<uint8_t> l_reg_contents;

    // Step 1 / 7
    // Set EFUSE#_EN signals to LOW (eFuse off)
    l_reg_contents = mss::gpio::fields::EFUSE_OUTPUT_OFF;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents));

    // Step 2 / 8
    // Setting Default (in case of bad POR)
    l_reg_contents = mss::gpio::fields::EFUSE_POLARITY_SETTING;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_POLARITY, l_reg_contents));

    // Step 3 / 9
    // Set EFUSE#_EN to OUTPUT.
    l_reg_contents = mss::gpio::fields::CONFIGURATION_IO_MAP;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::CONFIGURATION, l_reg_contents));

    // Step 4 / 10
    // Enable eFuse
    l_reg_contents = mss::gpio::fields::EFUSE_OUTPUT_ON;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents));

    // Step 5 / 11
    // Disable eFuse, this ensures off state in case Latch gets stuck
    l_reg_contents = mss::gpio::fields::EFUSE_OUTPUT_OFF;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents));

    // Step 6 / 12
    // Enable eFuse
    l_reg_contents = mss::gpio::fields::EFUSE_OUTPUT_ON;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the up PMIC pair and matching GPIO expander prior to PMIC enable
///
/// @param[in] i_pmic_map PMIC position to target map
/// @param[in] i_pmic_id_0 ID for "pmic0" (0/2) connected to i_gpio
/// @param[in] i_pmic_id_1 ID for "pmic1" (1/3) connected to i_gpio
/// @param[in] i_gpio GPIO target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note the PMIC pair is NOT a redundant pair, this is the independent pair connected to one GPIO
///
fapi2::ReturnCode setup_pmic_pair_and_gpio(
    const std::map<size_t, fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmic_map,
    const uint8_t i_pmic_id_0,
    const uint8_t i_pmic_id_1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio)
{
    bool l_already_enabled = false;
    // The sequence below is defined in section 6.1.1 of the
    // Redundant Power on DIMM – Functional Specification document
    // Check if GPIO is already enabled
    FAPI_TRY(check::efuses_already_enabled(i_gpio, l_already_enabled));

    // First set up the ADCs on the PMICs to measure VIN_BULK
    FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_0, [&i_pmic_map, i_pmic_id_0]
                            (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
    {
        // PMIC0/2
        return mss::pmic::setup_adc_vin_bulk_read(i_pmic);
    }));

    FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_1, [&i_pmic_map, i_pmic_id_1]
                            (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
    {
        // PMIC1/3
        return mss::pmic::setup_adc_vin_bulk_read(i_pmic);
    }));

    // Delay 25ms
    fapi2::delay(25 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    if (!l_already_enabled)
    {
        // Now, sampling VIN_BULK, which is protected by a fuse, we check that VIN_BULK does not read
        // more than 0.56V. If it does, then the fuse must be bad/blown, and we will declare N-mode.

        // Validate the EFUSE readings for both PMICs
        FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_0, [&i_pmic_map, i_pmic_id_0]
                                (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
        {
            // PMIC0/2
            return mss::pmic::validate_efuse_off(i_pmic);
        }));

        FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_1, [&i_pmic_map, i_pmic_id_1]
                                (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
        {
            // PMIC1/3
            return mss::pmic::validate_efuse_off(i_pmic);
        }));
    }

    // Enable E-Fuse via GPIO
    FAPI_TRY(setup_gpio_efuse(i_gpio));

    // Delay 30ms looked consistantly good in testing
    fapi2::delay(30 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // E-Fuse turned on, so now we should expect to see VIN_BULK within the valid on-range,
    // else, outside limit we will declare N-mode
    FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_0, [&i_pmic_map, i_pmic_id_0]
                            (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
    {
        // PMIC0/2
        return mss::pmic::validate_efuse_on(i_pmic);
    }));

    FAPI_TRY(run_if_present(i_pmic_map, i_pmic_id_1, [&i_pmic_map, i_pmic_id_1]
                            (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic)
    {
        // PMIC1/3
        return mss::pmic::validate_efuse_on(i_pmic);
    }));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Log recoverable errors for each PMIC that declared N-mode
///
/// @param[in] i_target_info Target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
///
void log_n_modes_as_recoverable_errors(
    const target_info_redundancy& i_target_info,
    const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic)
{
    for (uint8_t l_idx = PMIC0; l_idx < CONSTS::NUM_PMICS_4U; ++l_idx)
    {
        // Only log N-mode if we have a redundant PMIC
        if (i_target_info.iv_pmic_redundancy[l_idx % CONSTS::NUM_PRIMARY_PMICS])
        {
            // FAPI_ASSERT_NOEXIT's behavior differs from FAPI_ASSERT:
            // NOEXIT commits the error log as soon as the FFDC execute function is called,
            // so we do not need to manually log the error, like with FAPI_ASSERT,
            // so long as we pass in the right severity as an argument
            FAPI_ASSERT_NOEXIT((i_n_mode_pmic[l_idx] == mss::pmic::n_mode::N_PLUS_1_MODE),
                               fapi2::PMIC_DROPPED_INTO_N_MODE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_OCMB_TARGET(i_target_info.iv_ocmb)
                               .set_PMIC_ID(l_idx),
                               "%s PMIC%u had errors which caused a drop into N-Mode",
                               mss::c_str(i_target_info.iv_ocmb), l_idx);

            // Set back to success
            if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
            {
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
    }
}

///
/// @brief Assert the resulting n-mode states with the proper error FFDC
///
/// @param[in] i_target_info target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
/// @param[in] i_mnfg_thresholds thresholds policy setting
/// @return fapi2::ReturnCode iff no n-modes, else, relevant error FFDC
///
fapi2::ReturnCode assert_n_mode_states(
    const target_info_redundancy& i_target_info,
    const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic,
    const bool i_mnfg_thresholds)
{
    // Checks for a 4U with redundant PMICs
    if (i_target_info.iv_pmic_redundancy[0] && i_target_info.iv_pmic_redundancy[1])
    {
        // Check if we have lost a redundant pair :(
        FAPI_ASSERT(!(mss::pmic::check::bad_pair(i_n_mode_pmic)),
                    fapi2::PMIC_REDUNDANCY_FAIL()
                    .set_OCMB_TARGET(i_target_info.iv_ocmb)
                    .set_N_MODE_PMIC0(i_n_mode_pmic[PMIC0])
                    .set_N_MODE_PMIC1(i_n_mode_pmic[PMIC1])
                    .set_N_MODE_PMIC2(i_n_mode_pmic[PMIC2])
                    .set_N_MODE_PMIC3(i_n_mode_pmic[PMIC3]),
                    "A pair of redundant PMICs have both declared N-Mode. Procedure will not be able "
                    "to turn either on and provide power to the OCMB %s N-Mode States:"
                    "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                    mss::c_str(i_target_info.iv_ocmb),
                    i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);

        // Now in the other case, if at least one is down, assert this error. However, depending on the
        // thresholds policy setting, in most cases this error will be logged as recoverable in the
        // fapi_try_exit of process_n_mode_results(...)
        FAPI_ASSERT(!(mss::pmic::check::bad_any(i_n_mode_pmic)),
                    fapi2::DIMM_RUNNING_IN_N_MODE()
                    .set_OCMB_TARGET(i_target_info.iv_ocmb)
                    .set_N_MODE_PMIC0(i_n_mode_pmic[PMIC0])
                    .set_N_MODE_PMIC1(i_n_mode_pmic[PMIC1])
                    .set_N_MODE_PMIC2(i_n_mode_pmic[PMIC2])
                    .set_N_MODE_PMIC3(i_n_mode_pmic[PMIC3]),
                    "%s Warning: At least one of the 4 PMICs had errors which caused a drop into N-Mode. "
                    "MNFG_THRESHOLDS has asserted that we %s. N-Mode States:"
                    "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                    mss::c_str(i_target_info.iv_ocmb),
                    (i_mnfg_thresholds) ? "EXIT." : "DO NOT EXIT. Continuing boot normally with redundant parts.",
                    i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);
    }
    // Checks for a 4U without redundant PMICs
    else
    {
        // Note that we can confidently use iv_pmic_map[0] and [1] here since we know
        // that we have no redundancy and prior checks told us we have at least two
        // present PMIC targets
        const auto& l_failing_pmic = i_n_mode_pmic[PMIC0] ?
                                     i_target_info.iv_pmic_map.find(PMIC0)->second :
                                     i_target_info.iv_pmic_map.find(PMIC1)->second;
        FAPI_ASSERT(!(mss::pmic::check::bad_primary(i_n_mode_pmic)),
                    fapi2::PMIC_NON_REDUNDANT_FAIL()
                    .set_OCMB_TARGET(i_target_info.iv_ocmb)
                    .set_PMIC_TARGET(l_failing_pmic),
                    "PMIC %s failed to enable, and has no redundant back-up. "
                    "See previous errors for details.",
                    mss::c_str(l_failing_pmic));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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

///
/// @brief Process the results of the N-Mode declarations (if any)
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, or error code based on the
///                           n mode results + policy settings
/// @note Logs a recoverable error per bad PMIC to aid FW, but will return good/bad code
///       whether we are able to continue or not given those states
///
fapi2::ReturnCode process_n_mode_results(const target_info_redundancy& i_target_info)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using mss::pmic::id;

    // Hold N-Mode states
    std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U> l_n_mode_pmic =
    {
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE
    };

    // Force an n-mode configuration via lab override
    uint8_t l_force_n_mode = 0;
    fapi2::buffer<uint8_t> l_force_n_mode_buffer;

    // MFG flags vars/consts
    bool l_mnfg_thresholds = false;

    // Grab N mode attributes
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC0, l_n_mode_pmic[PMIC0]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC1, l_n_mode_pmic[PMIC1]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC2, l_n_mode_pmic[PMIC2]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC3, l_n_mode_pmic[PMIC3]));

    // Overridden to an N mode configuration
    FAPI_TRY(mss::attr::get_pmic_force_n_mode(i_target_info.iv_ocmb, l_force_n_mode));
    l_force_n_mode_buffer = l_force_n_mode;

    // Check map entries, missing ones will be declared N-Mode
    // If we don't have the PMIC in the map, then platform never provided it as present,
    // so we should just exit, do not run i_func()

    // Check N-mode override attribute states
    for (uint8_t l_idx = PMIC0; l_idx < CONSTS::NUM_PMICS_4U; ++l_idx)
    {
        // l_force_n_mode_buffer is expected to have an "n-mode configuration" as high bits.
        // in other words, a setting such as 0b11000000 would say to use the n-mode configuration of
        // PMIC0 and PMIC1. Therefore, if bits are not set, we are considering those overridden
        // to be disabled. (Default value is 0xF0). (This logic is not the same as the live n-mode states)
        if (!l_force_n_mode_buffer.getBit(l_idx) ||
            (i_target_info.iv_pmic_map.find(l_idx) == i_target_info.iv_pmic_map.end()))
        {
            // Hardcode it to N-Mode, since this pmic is disabled or not-present.
            // This allows valid_n_mode_helper to operate normally, with the
            // assumption that two PMICs are "dead"
            l_n_mode_pmic[l_idx] = mss::pmic::n_mode::N_MODE;
        }
    }

    // First, we want to log a recoverable error for each PMIC that is in an N-mode state.
    // This helps FW identify which parts are bad if we do have a full redundancy fail which
    // causes a procedure exit. No RC from this function.
    log_n_modes_as_recoverable_errors(i_target_info, l_n_mode_pmic);

    // Easy case first, return success if they're all N_PLUS1_MODE (not N-mode)
    if (!l_n_mode_pmic[PMIC0] &&
        !l_n_mode_pmic[PMIC1] &&
        !l_n_mode_pmic[PMIC2] &&
        !l_n_mode_pmic[PMIC3])
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get mnfg thresholds policy setting
    FAPI_TRY(mss::pmic::get_mnfg_thresholds(l_mnfg_thresholds));

    // If we have any n-modes, we will jump to fapi_try_exit, where either
    // 1. We have lost a redundant pair, so we must exit
    // 2. We have not lost a pair, but the MNFG_THRESHOLDS setting asserts we exit anyway
    FAPI_TRY(assert_n_mode_states(i_target_info, l_n_mode_pmic, l_mnfg_thresholds));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // If we are allowing redundancy, log the N_MODE error as recovered
    if (fapi2::current_err == static_cast<uint32_t>(fapi2::RC_DIMM_RUNNING_IN_N_MODE)
        && !l_mnfg_thresholds)
    {
        fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    return fapi2::current_err;
}

namespace check
{

///
/// @brief Check for a bad pair given the n-mode states of the 4 4U pmics
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false pair bad
///
bool bad_pair(const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic)
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;

    // Return false if both in a pair are bad, in which case we will
    // be unable to continue booting
    return ((i_n_mode_pmic[0] == N_MODE && i_n_mode_pmic[2] == N_MODE) ||
            (i_n_mode_pmic[1] == N_MODE && i_n_mode_pmic[3] == N_MODE));
}

///
/// @brief Check if at least one PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false at least one pmic is bad
///
bool bad_any(const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic)
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;

    // True if any are N_MODE
    return i_n_mode_pmic[0] == N_MODE ||
           i_n_mode_pmic[1] == N_MODE ||
           i_n_mode_pmic[2] == N_MODE ||
           i_n_mode_pmic[3] == N_MODE;
}

///
/// @brief Check if at least one primary PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false at least one primary pmic is bad
///
bool bad_primary(const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic)
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;

    // True if either primary PMIC is N_MODE
    return i_n_mode_pmic[0] == N_MODE ||
           i_n_mode_pmic[1] == N_MODE;
}


///
/// @brief Reset N Mode attributes
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS, else error code
/// @note For 4U only. Has no effect on 1U/2U.
///
fapi2::ReturnCode reset_n_mode_attrs(const target_info_redundancy& i_target_info)
{
    uint8_t l_n_mode = 0x00;
    FAPI_TRY(mss::attr::set_pmic_n_mode(i_target_info.iv_ocmb, l_n_mode));

fapi_try_exit:
    return fapi2::current_err;
}

///
///
/// @param[in] i_gpio GPIO target
/// @param[out] o_already_enabled true if efuses already on, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else
///
fapi2::ReturnCode efuses_already_enabled(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio,
        bool& o_already_enabled)
{
    fapi2::buffer<uint8_t> l_polarity;
    fapi2::buffer<uint8_t> l_output;
    fapi2::buffer<uint8_t> l_config;

    FAPI_TRY(mss::pmic::i2c::reg_read(i_gpio, mss::gpio::regs::EFUSE_POLARITY, l_polarity));
    FAPI_TRY(mss::pmic::i2c::reg_read(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_output));
    FAPI_TRY(mss::pmic::i2c::reg_read(i_gpio, mss::gpio::regs::CONFIGURATION, l_config));

    o_already_enabled = efuses_already_enabled_helper(l_polarity, l_output, l_config);

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
                "Mismatching vendor IDs for %s. ATTR: 0x%04X REG: 0x%04X",
                mss::c_str(i_pmic_target),
                i_vendor_attr,
                l_vendor_reg());

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check that the IDT revision # register and attribute match and return revision number
///
/// @param[in]  i_ocmb_target OCMB target
/// @param[in]  i_pmic_target PMIC target to check
/// @param[out] o_rev_reg revision number of IDT PMIC
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_and_return_idt_revisions(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
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

    // The simics check has been added here to skip simics testing of the below function as
    // simics is throwing error for the attribute and revision register mismatch condition.
    // Updating simics is not recommended as there are no real PMICs on the simulation model
    // and skipping this check will not affect rest of the pmic_enable functionality in simics
    FAPI_TRY(mss::attr::get_is_simics(l_simics));

    if (!l_simics)
    {
        FAPI_TRY(mss::pmic::check::validate_and_return_idt_revisions_helper(i_pmic_target, l_rev, o_rev_reg()));
    }
    else
    {
        FAPI_DBG("Simulation mode detected. Skipping IDT revision check");
    }

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
/// @brief Step 1 of enable_with_redundancy: set up the GPIO EFUSE's
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode redundancy_gpio_efuse_setup(const target_info_redundancy& i_target_info)
{
    // Reset N Mode attributes
    FAPI_TRY(check::reset_n_mode_attrs(i_target_info));

    // Set up both trios of devices
    FAPI_TRY(setup_pmic_pair_and_gpio(
                 i_target_info.iv_pmic_map,
                 mss::pmic::id::PMIC0, // PMIC 1
                 mss::pmic::id::PMIC1, // PMIC 3
                 i_target_info.iv_gpio1));


    FAPI_TRY(setup_pmic_pair_and_gpio(
                 i_target_info.iv_pmic_map,
                 mss::pmic::id::PMIC2, // PMIC 2
                 mss::pmic::id::PMIC3, // PMIC 4
                 i_target_info.iv_gpio2));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the 4U PMIC to pre-determined settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_pmic_id PMIC ID (0-3)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_4u_settings(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, const uint8_t i_pmic_id)
{
    // This function should be provided a relative ID (0 or 1),
    // but it doesn't hurt to recalculate it anyway
    const uint8_t l_relative_id = (i_pmic_id % CONSTS::NUM_PRIMARY_PMICS);

    fapi2::buffer<uint8_t> l_reg_contents;
    std::vector<std::pair<uint8_t, uint8_t>> l_fields;

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_volt_bitmap = 0;

        // Calculate 4U nominal voltages from default values + SPD/EFD offsets
        FAPI_TRY(calculate_4u_nominal_voltage(
                     i_pmic_target,
                     l_relative_id,
                     l_rail_index,
                     l_volt_bitmap));

        l_reg_contents = l_volt_bitmap;
        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index], l_reg_contents));
    }

    // Grab the fields for either PMIC0 or PMIC1
    l_fields = (l_relative_id == mss::pmic::id::PMIC0) ? PMIC0_SETTINGS : PMIC1_SETTINGS;

    // Loop through and apply all the pmic settings as defined in the 4U settings file
    for (const auto& l_field : l_fields)
    {
        const auto REG = l_field.first;
        const auto VAL = l_field.second;

        l_reg_contents.flush<0>();
        l_reg_contents = VAL;

        FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REG, l_reg_contents));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Kick off VR_ENABLE's for a redundancy PMIC config in the provided mode
///
/// @param[in] i_target_info target info struct
/// @param[in] i_enable_loop_fields Parameters/fields to iterate over
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode redundancy_vr_enable_kickoff(
    const target_info_redundancy& i_target_info,
    const mss::pmic::enable_loop_fields_t& i_enable_loop_fields)
{
    for (const auto& l_enable_fields : i_enable_loop_fields)
    {
        // No trace for these so HB does not try to shove the entirety of the lambda into an error trace.
        // The internal function calls have descriptive error ouptuts that should be sufficient in the
        // case of an error
        FAPI_TRY_NO_TRACE(run_if_present(i_target_info.iv_pmic_map, l_enable_fields.iv_pmic_id,
                                         [&i_target_info, &l_enable_fields]
                                         (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            // Perform VR Enable steps
            FAPI_TRY_LAMBDA(mss::pmic::set_4u_settings(i_pmic, l_enable_fields.iv_pmic_id));
            FAPI_TRY_LAMBDA(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(i_pmic, i_target_info.iv_ocmb));
            fapi2::delay(10 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

            FAPI_TRY_LAMBDA(mss::pmic::start_vr_enable(i_pmic));

            // Poll for the GPIO bit corresponding to the provided PMIC target, ensure polls good
            FAPI_TRY_LAMBDA(mss::gpio::poll_input_port_ready(
                l_enable_fields.iv_gpio,
                i_pmic,
                l_enable_fields.iv_input_port_bit));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return mss::pmic::declare_n_mode(
                i_target_info.iv_ocmb,
                l_enable_fields.iv_pmic_id);
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note To be used with 4U/Redundant Enable sequence
///
fapi2::ReturnCode redundancy_check_all_pmics(const target_info_redundancy& i_target_info)
{
    // Start success so we can't log and return the same error in loop logic
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // For each PMIC ID
    for (uint8_t l_idx = mss::pmic::id::PMIC0; l_idx < CONSTS::NUM_PMICS_4U; ++l_idx)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(run_if_present(i_target_info.iv_pmic_map, l_idx, [&i_target_info, l_idx]
                                         (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            mss::pmic::n_mode l_n_mode_pmic = mss::pmic::n_mode::N_PLUS_1_MODE;
            FAPI_TRY_LAMBDA(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, mss::index(i_pmic), l_n_mode_pmic));

            // Only check the vr enable status if the PMIC didn't declare N-mode, otherwise, don't bother
            // as it's unlikely it succeeded anyway, and setting n-mode twice is a no-op
            if (!(l_n_mode_pmic == mss::pmic::n_mode::N_MODE))
            {
                // Redundant setting of current_err, just so it's clear what we're trying to do
                fapi2::current_err = mss::pmic::status::check_for_vr_enable(i_target_info.iv_ocmb, i_pmic);

                // TK ZEN659 add in status bit checking when we achieve stability on powerup
            }

            // If we aren't success, then either VR-Enable did not occur or the register read failed.
            // In either case, declare N-Mode, and continue
            if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
            {
                FAPI_TRY_LAMBDA(mss::pmic::declare_n_mode(i_target_info.iv_ocmb, l_idx));
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the up GPIOs, ADCs, PMICs for a redundancy configuration / 4U
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode enable_with_redundancy(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    FAPI_INF("Enabling PMICs on %s with 4U/redundancy mode", mss::c_str(i_ocmb_target));

    fapi2::buffer<uint8_t> l_reg_contents;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Grab the targets as a struct, if they exist
    target_info_redundancy l_target_info(i_ocmb_target, l_rc);

    // If platform did not provide a usable set of targets (4 GENERICI2CSLAVE, at least 2 PMICs),
    // Then we can't properly enable
    FAPI_TRY(l_rc, "Unusable PMIC/GENERICI2CSLAVE child target configuration found from %s",
             mss::c_str(i_ocmb_target));

    {
        // We can loop on these to pick out the PMIC, connected GPIO, and input port bit to use later
        // when we VR_ENABLE (via manual or SPD), and then check the GPIO input port reg
        const enable_loop_fields_t l_enable_loop_fields =
        {
            {
                {mss::pmic::id::PMIC0, l_target_info.iv_gpio1, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0},
                {mss::pmic::id::PMIC2, l_target_info.iv_gpio2, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0},
                {mss::pmic::id::PMIC1, l_target_info.iv_gpio1, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1},
                {mss::pmic::id::PMIC3, l_target_info.iv_gpio2, mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1}
            }
        };

        // Set up GPIO expanders: Turn on the EFUSEs to supply 12V to the pmics. Declares N-Mode
        // for any failed 12V checks.
        FAPI_TRY(mss::pmic::redundancy_gpio_efuse_setup(l_target_info));

        // Now, perform any needed workarounds, kick off VR_ENABLEs, and check GPIO input port bits,
        // declaring N-Mode wherever necessary.
        FAPI_TRY(mss::pmic::redundancy_vr_enable_kickoff(l_target_info, l_enable_loop_fields));

        // Next, set up the ADC devices post-enable
        FAPI_TRY(setup_adc1(l_target_info.iv_adc1));
        FAPI_TRY(setup_adc2(l_target_info.iv_adc2));

        // Now, check that the PMICs were enabled properly. If any don't report on that are expected
        // to be on, declare N-mode there too.
        FAPI_TRY(mss::pmic::redundancy_check_all_pmics(l_target_info));

        // Step 184: Delay 200ms - SKIPPED, as IPL duration should be sufficient
        // Step 185: Telemetry Collection - SKIPPED, to be run at end of IPL

        // Finally, pocess the N-Mode results
        FAPI_TRY(mss::pmic::process_n_mode_results(l_target_info));
    }

    FAPI_INF("Successfully enabled PMICs on %s with 4U/redundancy mode", mss::c_str(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // pmic
} // mss
