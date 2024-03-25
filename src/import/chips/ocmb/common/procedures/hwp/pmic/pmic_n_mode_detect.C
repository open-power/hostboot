/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_n_mode_detect.C $ */
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
/// @file pmic_n_mode_detect.H
/// @brief To be run periodically at runtime to determine n-mode states of 4U parts
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB

#include <fapi2.H>
#include <pmic_n_mode_detect.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

#ifdef __PPE__
    #include <ppe42_string.h>
#endif

///
/// @brief Write a register of a PMIC target, helper function for pmic_info type
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void reg_write(pmic_info& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic.iv_state & pmic_state::NOT_PRESENT))
    {
        if (mss::pmic::i2c::reg_write(io_pmic.iv_pmic, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_state |= pmic_state::I2C_FAIL;
        }
    }
}

///
/// @brief Read a register of a PMIC target, helper function for pmic_info type
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
void reg_read(pmic_info& io_pmic, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_output)
{
    if (!(io_pmic.iv_state & pmic_state::NOT_PRESENT))
    {
        if (mss::pmic::i2c::reg_read(io_pmic.iv_pmic, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_state |= pmic_state::I2C_FAIL;
            o_output = 0x00;
        }
    }
}
///
/// @brief Check if we are 4U by checking for 4 GI2C targets
///
/// @param[in] i_ocmb_target OCMB target
/// @return true if 4U, false if not
///
bool is_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    // SBE is expected to provide exactly 4 GI2C targets
    // All 4U DDIMMs have 4 GI2C targets, and all 1U/2U DDIMMs have zero, so checking those is sufficient to say if we have a 4U
    const auto GI2CS = i_ocmb_target.getChildren<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>(fapi2::TARGET_STATE_PRESENT);

    return (GI2CS.size() == mss::generic_i2c_responder_ddr4::NUM_TOTAL_DEVICES);
}

///
/// @brief Clear or set GPIO EFUSE bit of corresponding PMIC
///
/// @param[in] i_clear_set_bit clear of set EFUSE bit
/// @param[in] i_pmic_pos relative positio of PMIC
/// @param[in,out] io_reg value of EFUSE register
/// @return None
///
void clear_set_efuse(bool i_clear_set_bit,
                     const uint8_t i_pmic_pos,
                     fapi2::buffer<uint8_t>& io_reg)
{
    // Clear or set PMIC0 or PMIC2
    if ( i_pmic_pos == mss::pmic::id::PMIC0 || i_pmic_pos == mss::pmic::id::PMIC2 )
    {
        io_reg.writeBit<mss::gpio::fields::EFUSE_P0_P2_ENABLE>(i_clear_set_bit);
    }

    // Clear or set PMIC1 or PMIC3
    if ( i_pmic_pos == mss::pmic::id::PMIC1 || i_pmic_pos == mss::pmic::id::PMIC3 )
    {
        io_reg.writeBit<mss::gpio::fields::EFUSE_P1_P3_ENABLE>(i_clear_set_bit);
    }
}

///
/// @brief Attempt recovery for a specific PMIC
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_gpio GPIO target
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @return None
///
void attempt_recovery(pmic_info& io_pmic,
                      const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio,
                      const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                      const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    fapi2::buffer<uint8_t> l_reg;

    FAPI_INF(TARGTIDFORMAT " Attempting Recovery", MSSTARGID(io_pmic.iv_pmic));

    // Clear EFUSE
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg));
    clear_set_efuse(false, io_pmic.iv_rel_pos, l_reg);
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg));

    // Delay for 100 ms. Less delay is affecting recovery procedure.
    // This amount should be ok as the recovery will rarely be used
    fapi2::delay(100 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Set EFUSE
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg));
    clear_set_efuse(true, io_pmic.iv_rel_pos, l_reg);
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_gpio, mss::gpio::regs::EFUSE_OUTPUT, l_reg));

    // Delay for 50 ms. Less delay is affecting recovery procedure.
    // This amount should be ok as the recovery will rarely be used
    fapi2::delay(50 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Clear VR_ENABLE
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(io_pmic.iv_pmic, REGS::R32, l_reg));
    l_reg.clearBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(io_pmic.iv_pmic, REGS::R32, l_reg));

    // Clear Global Status
    FAPI_TRY(mss::pmic::i2c::reg_write(io_pmic.iv_pmic, REGS::R14, CLEAR_STATUS));

    // Set VR_ENABLE
    l_reg.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(io_pmic.iv_pmic, REGS::R32, l_reg));

    // Delay for 200 ms. Less delay is affecting recovery procedure.
    // This amount should be ok as the recovery will rarely be used
    fapi2::delay(200 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Clear ADC1 Events
    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc1, mss::adc::regs::LOW_EVENT_FLAGS, CLEAR_LOW_EVENT_FLAGS));
    // Clear ADC2 Events
    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc2, mss::adc::regs::LOW_EVENT_FLAGS, CLEAR_LOW_EVENT_FLAGS));

    return;

fapi_try_exit:
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    io_pmic.iv_state = pmic_state::I2C_FAIL;
    return;
}

///
/// @brief Update breadcrumb register
/// @param[in,out] aggregate_state Aggregate state
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_gpio GPIO target
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in,out] io_pmic_tele_data pmic telemetry data struct
/// @return None
///
void update_breadcrumb(aggregate_state& io_state,
                       pmic_info& io_pmic,
                       const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio,
                       const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                       const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
                       pmic_telemetry& io_pmic_tele_data)
{
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;

    fapi2::buffer<uint8_t> l_reg;

    FAPI_INF(TARGTIDFORMAT " Updating bread crumb", MSSTARGID(io_pmic.iv_pmic));

    switch(io_pmic_tele_data.iv_breadcrumb)
    {
        case bread_crumb::BREAD_CRUMB_ALL_GOOD:
            {
                // Set breadcrumb to FIRST_ATTEMPT
                io_pmic_tele_data.iv_breadcrumb = bread_crumb::FIRST_ATTEMPT;
                reg_write(io_pmic, TPS_REGS::RA3_BREADCRUMB, bread_crumb::FIRST_ATTEMPT);
                io_state = aggregate_state::N_MODE_POSSIBLE;
                break;
            }

        case bread_crumb::FIRST_ATTEMPT:
            {
                // Set breadcrumb to RECOVERY_ATTEMPTED
                io_pmic_tele_data.iv_breadcrumb = bread_crumb::RECOVERY_ATTEMPTED;
                reg_write(io_pmic, TPS_REGS::RA3_BREADCRUMB, bread_crumb::RECOVERY_ATTEMPTED);
                attempt_recovery(io_pmic, i_gpio, i_adc1, i_adc2);
                io_state = aggregate_state::N_MODE_RECOVERY_ATTEMPTED;
                break;
            }

        case bread_crumb::RECOVERY_ATTEMPTED:
        case bread_crumb::STILL_A_FAIL:
            {
                // Set breadcrumb to STILL_A_FAIL if previous state was RECOVERY_ATTEMPTED
                // Do nothing if still a STILL_A_FAIL. Keep the state as is
                io_pmic_tele_data.iv_breadcrumb = bread_crumb::STILL_A_FAIL;
                reg_write(io_pmic, TPS_REGS::RA3_BREADCRUMB, bread_crumb::STILL_A_FAIL);
                io_state = aggregate_state::N_MODE;
                break;
            }
    }
}

///
/// @brief Check the GPIO for n mode detection
///
/// @param[in] i_gpio GPIO Expander target
/// @param[in,out] io_pmic1 PMIC1/3 pmic_info class including target / state info
/// @param[in,out] io_pmic2 PMIC2/4 pmic_info class including target / state info
/// @param[in,out] io_failed_pmics Bit map of failed PMICS on a GPIO
/// @param[in,out] io_pmic_data1 PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_pmic_data2 PMIC2/3 pmic telemetry data struct
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @return aggregate_state N mode state according to the status of GPIO and ADC only
///
aggregate_state gpio_check(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio,
                           pmic_info& io_pmic1,
                           pmic_info& io_pmic2,
                           fapi2::buffer<uint8_t>& io_failed_pmics,
                           pmic_telemetry& io_pmic_data1,
                           pmic_telemetry& io_pmic_data2,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2)
{
    FAPI_INF(TARGTIDFORMAT " Performing GPIO N-Mode Detection", MSSTARGID(i_gpio));

    aggregate_state l_state = aggregate_state::N_PLUS_1;

    fapi2::buffer<uint8_t> l_reg;

    // I2C read failing here would cause a fail for the check on 56-59,
    // so the handling behavior will be the same
    if (mss::pmic::i2c::reg_read_reverse_buffer(i_gpio, mss::gpio::regs::INPUT_PORT_REG, l_reg)
        != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF(TARGTIDFORMAT " INPUT_PORT_REG register read failed", MSSTARGID(i_gpio));
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        l_state = aggregate_state::GI2C_I2C_FAIL;
        // no recovery
        return l_state;
    }

    FAPI_DBG(TARGTIDFORMAT " GPIO INPUT_PORT_REG data: 0x%02X", MSSTARGID(i_gpio), l_reg);

    // The 2 pimcs on each GPIO are from a different pair. So in order to declare a
    // PMIC pair as lost, we will need to check both the pmics in a pair. This logic sets a fail
    // for one of the pmics in a pair
    io_failed_pmics.writeBit<PAIR0>(!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0>());
    io_failed_pmics.writeBit<PAIR1>(!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1>());

    if (!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR0>())
    {
        FAPI_INF(TARGTIDFORMAT " PMIC PWR_NOT_GOOD", MSSTARGID(i_gpio));
        io_pmic1.iv_state |= PWR_NOT_GOOD;
        update_breadcrumb(l_state, io_pmic1, i_gpio, i_adc1, i_adc2, io_pmic_data1);
    }

    if (!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1>())
    {
        FAPI_INF(TARGTIDFORMAT " PMIC PWR_NOT_GOOD", MSSTARGID(i_gpio));
        io_pmic2.iv_state |= PWR_NOT_GOOD;
        update_breadcrumb(l_state, io_pmic2, i_gpio, i_adc1, i_adc2, io_pmic_data2);
    }

    return l_state;
}

///
/// @brief Check ADC1 event bits
///
/// @param[in] i_reg_data register read data from reg 0x18 (EVENT_FLAG)
/// @param[in,out] io_state aggregate state
/// @param[in,out] io_pmic1 PMIC1/3 pmic_info class including target / state info
/// @param[in,out] io_pmic2 PMIC2/4 pmic_info class including target / state info
/// @param[in,out] io_pmic_data1 PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_pmic_data2 PMIC2/3 pmic telemetry data struct
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @return None
///
void check_adc1_event_bits(const fapi2::buffer<uint8_t>& i_reg_data,
                           aggregate_state& io_state,
                           pmic_info& io_pmic1,
                           pmic_info& io_pmic2,
                           pmic_telemetry& io_pmic_data1,
                           pmic_telemetry& io_pmic_data2,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2)
{
    // Check for ADC1 PMIC0 fails
    if (i_reg_data.getBit<mss::adc::fields::ADC1_PMIC0_SWA_SWB_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC1_PMIC0_SWC_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC1_PMIC0_SWD_FAIL>())
    {
        io_pmic1.iv_state |= ADC_ERROR;
        update_breadcrumb(io_state, io_pmic1, i_gpio1, i_adc1, i_adc2, io_pmic_data1);
    }

    // Check for ADC1 PMIC2 fails
    if (i_reg_data.getBit<mss::adc::fields::ADC1_PMIC2_SWC_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC1_PMIC2_SWD_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC1_PMIC2_SWA_SWB_FAIL>())
    {
        io_pmic2.iv_state |= ADC_ERROR;
        update_breadcrumb(io_state, io_pmic2, i_gpio2, i_adc1, i_adc2, io_pmic_data2);
    }
}

///
/// @brief Check ADC2 event bits
///
/// @param[in] i_reg_data register read data from reg 0x18 (EVENT_FLAG)
/// @param[in,out] io_state aggregate state
/// @param[in,out] io_pmic1 PMIC1/3 pmic_info class including target / state info
/// @param[in,out] io_pmic2 PMIC2/4 pmic_info class including target / state info
/// @param[in,out] io_pmic_data1 PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_pmic_data2 PMIC2/3 pmic telemetry data struct
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @return None
///
void check_adc2_event_bits(const fapi2::buffer<uint8_t>& i_reg_data,
                           aggregate_state& io_state,
                           pmic_info& io_pmic1,
                           pmic_info& io_pmic2,
                           pmic_telemetry& io_pmic_data1,
                           pmic_telemetry& io_pmic_data2,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2)
{
    // Check for ADC1 PMIC0 fails
    if (i_reg_data.getBit<mss::adc::fields::ADC2_PMIC1_SWC_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC2_PMIC1_SWA_SWB_FAIL>())
    {
        io_pmic1.iv_state |= ADC_ERROR;
        update_breadcrumb(io_state, io_pmic1, i_gpio1, i_adc1, i_adc2, io_pmic_data1);
    }

    // Check for ADC1 PMIC2 fails
    if (i_reg_data.getBit<mss::adc::fields::ADC2_PMIC3_SWA_SWB_FAIL>() ||
        i_reg_data.getBit<mss::adc::fields::ADC2_PMIC3_SWC_FAIL>())
    {
        io_pmic2.iv_state |= ADC_ERROR;
        update_breadcrumb(io_state, io_pmic2, i_gpio2, i_adc1, i_adc2, io_pmic_data2);
    }
}

///
/// @brief Check the ADC device for EVENT_FLAG
///
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @param[in,out] io_pmic1 First pmic_info class including target / state info
/// @param[in,out] io_pmic2 Second pmic_info class including target / state info
/// @param[in] i_adc_number ADC number to process
/// @param[in,out] io_pmic_data1 PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_pmic_data2 PMIC2/3 pmic telemetry data struct
/// @return aggregate_state Aggregate state
///
aggregate_state adc_check(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                          const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
                          const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
                          const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2,
                          pmic_info& io_pmic1,
                          pmic_info& io_pmic2,
                          const uint8_t i_adc_number,
                          pmic_telemetry& io_pmic_data1,
                          pmic_telemetry& io_pmic_data2)
{
    FAPI_INF(TARGTIDFORMAT " Checking ADC for EVENT_FLAG", MSSTARGID(i_adc1));

    aggregate_state l_state = aggregate_state::N_PLUS_1;
    constexpr uint8_t EVENT_FLAG_GOOD = 0x00;

    // Start with the buffer polluted. If the reg read fails, we assume l_reg will
    // be left unchanged, so 0xFF will force an n-mode declaration
    fapi2::buffer<uint8_t> l_reg(0xFF);

    // We don't care if this read fails. We would treat it the same as a bad EVENT_FLAG reg
    if (mss::pmic::i2c::reg_read_reverse_buffer(i_adc1, mss::adc::regs::EVENT_FLAG, l_reg) != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF(TARGTIDFORMAT " EVENT_FLAG register read failed", MSSTARGID(i_adc1));
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        return aggregate_state::GI2C_I2C_FAIL;
    }

    // If the EVENT_FLAG register is not all zero, declare n-mode
    if (l_reg != EVENT_FLAG_GOOD)
    {
        if (i_adc_number == mss::generic_i2c_responder_ddr4::ADC1)
        {
            check_adc1_event_bits(l_reg, l_state, io_pmic1, io_pmic2, io_pmic_data1, io_pmic_data2, i_gpio1, i_gpio2, i_adc1,
                                  i_adc2);
        }
        else if (i_adc_number == mss::generic_i2c_responder_ddr4::ADC2)
        {
            check_adc2_event_bits(l_reg, l_state, io_pmic1, io_pmic2, io_pmic_data1, io_pmic_data2, i_gpio1, i_gpio2, i_adc1,
                                  i_adc2);
        }

        return l_state;
    }
    else
    {
        return aggregate_state::N_PLUS_1;
    }
}

///
/// @brief Compare two phases provided from two pmics, decide state based on breadcrumb
///
/// @param[in,out] io_first_pmic First pmic_info class including target / state info
/// @param[in,out] io_second_pmic Second pmic_info class including target / state info
/// @param[in] i_phase0 One phase
/// @param[in] i_phase1 Other phase
/// @param[out] o_aggregate_state Aggregate state, to be updated if needed
/// @param[in,out] io_first_pmic_data First pmic_info class including target / state info
/// @param[in,out] io_second_pmic_data Second pmic_info class including target / state info
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @return None
///
void phase_comparison(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint32_t i_phase0,
    const uint32_t i_phase1,
    aggregate_state& o_aggregate_state,
    pmic_telemetry& io_first_pmic_data,
    pmic_telemetry& io_second_pmic_data,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2)
{
    uint8_t l_rel_pos = 0;

    if ((io_first_pmic.iv_state & pmic_state::NOT_PRESENT) || (io_second_pmic.iv_state & pmic_state::NOT_PRESENT))
    {
        o_aggregate_state = aggregate_state::N_MODE;
        return;
    }

    if (((i_phase0 < PHASE_MIN) && i_phase1 > PHASE_MAX) || ((i_phase1 < PHASE_MIN) && (i_phase0 > PHASE_MAX)))
    {
        // Set the flag for whichever had the imbalance
        if (i_phase0 < PHASE_MIN)
        {
            l_rel_pos = io_first_pmic.iv_rel_pos;
        }
        else
        {
            l_rel_pos = io_second_pmic.iv_rel_pos;
        }

        switch (l_rel_pos)
        {
            case mss::pmic::id::PMIC0:
            case mss::pmic::id::PMIC1:
                {
                    io_first_pmic.iv_state |= CURRENT_IMBALANCE;
                    update_breadcrumb(o_aggregate_state, io_first_pmic, i_gpio1, i_adc1, i_adc2, io_first_pmic_data);
                    break;
                }

            case mss::pmic::id::PMIC2:
            case mss::pmic::id::PMIC3:
                {
                    io_second_pmic.iv_state |= CURRENT_IMBALANCE;
                    update_breadcrumb(o_aggregate_state, io_second_pmic, i_gpio2, i_adc1, i_adc2, io_second_pmic_data);
                    break;
                }
        }

    }
}

///
/// @brief Read a double phase voltage domain, check for N-Mode
///
/// @param[in,out] io_first_pmic First pmic_info class including target / state info
/// @param[in,out] io_second_pmic Second pmic_info class including target / state info
/// @param[in] i_rail_1 One phase of voltage - register to read
/// @param[in] i_rail_2 Other phase of voltage - register to read
/// @param[out] o_aggregate_state Aggregate state output, to be updated if needed
/// @param[in,out] io_first_pmic_data PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_second_pmic_data PMIC2/3 pmic telemetry data struct
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @return none
///
void read_double_domain(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint8_t i_rail_1,
    const uint8_t i_rail_2,
    aggregate_state& o_aggregate_state,
    pmic_telemetry& io_first_pmic_data,
    pmic_telemetry& io_second_pmic_data,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2)
{
    uint32_t l_phase0 = 0;
    uint32_t l_phase1 = 0;

    fapi2::buffer<uint8_t> l_reg0;
    fapi2::buffer<uint8_t> l_reg1;
    fapi2::buffer<uint8_t> l_reg2;
    fapi2::buffer<uint8_t> l_reg3;

    reg_read(io_first_pmic, i_rail_1, l_reg0);
    reg_read(io_first_pmic, i_rail_2, l_reg1);
    reg_read(io_second_pmic, i_rail_1, l_reg2);
    reg_read(io_second_pmic, i_rail_2, l_reg3);

    l_phase0 = (l_reg0 * CURRENT_MULTIPLIER) + (l_reg1 * CURRENT_MULTIPLIER);
    l_phase1 = (l_reg2 * CURRENT_MULTIPLIER) + (l_reg3 * CURRENT_MULTIPLIER);

    phase_comparison(io_first_pmic, io_second_pmic, l_phase0, l_phase1, o_aggregate_state,
                     io_first_pmic_data, io_second_pmic_data, i_adc1, i_adc2, i_gpio1, i_gpio2);
}

///
/// @brief Read a single phase voltage domain, check for N-Mode
///
/// @param[in,out] io_first_pmic First pmic_info class including target / state info
/// @param[in,out] io_second_pmic Second pmic_info class including target / state info
/// @param[in] i_rail_1 Rail register to read
/// @param[out] o_aggregate_state Aggregate state output, to be updated if needed
/// @param[in,out] io_first_pmic_data PMIC1/3 pmic telemetry data struct
/// @param[in,out] io_second_pmic_data PMIC2/3 pmic telemetry data struct
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in] i_gpio GPIO1 target
/// @param[in] i_gpio GPIO2 target
/// @return none
///
void read_single_domain(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint8_t i_rail_1,
    aggregate_state& o_aggregate_state,
    pmic_telemetry& io_first_pmic_data,
    pmic_telemetry& io_second_pmic_data,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2)
{
    uint32_t l_phase0 = 0;
    uint32_t l_phase1 = 0;

    fapi2::buffer<uint8_t> l_reg0;
    fapi2::buffer<uint8_t> l_reg1;

    reg_read(io_first_pmic, i_rail_1, l_reg0);
    reg_read(io_second_pmic, i_rail_1, l_reg1);

    l_phase0 = (l_reg0 * CURRENT_MULTIPLIER);
    l_phase1 = (l_reg1 * CURRENT_MULTIPLIER);

    phase_comparison(io_first_pmic, io_second_pmic, l_phase0, l_phase1, o_aggregate_state,
                     io_first_pmic_data, io_second_pmic_data, i_adc1, i_adc2, i_gpio1, i_gpio2);
}

///
/// @brief Perform voltage n mode checks
///
/// @param[in] io_pmics PMICS in sorted order
/// @param[in,out] io_tele_data telemetry data struct
/// @param[in] i_adc1 ADC target
/// @param[in] i_adc2 ADC target
/// @param[in] i_gpio1 GPIO target
/// @param[in] i_gpio2 GPIO target
/// @return aggregate_state state of the part
///
aggregate_state voltage_checks(std::vector<pmic_info>& io_pmics,
                               telemetry_data& io_tele_data,
                               const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc1,
                               const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2,
                               const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
                               const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2)
{
    aggregate_state l_aggregate_state = aggregate_state::N_PLUS_1;

    // Required regs
    static constexpr uint8_t SWA_CURRENT = 0x0C;
    static constexpr uint8_t SWB_CURRENT = 0x0D;
    static constexpr uint8_t SWC_CURRENT = 0x0E;
    static constexpr uint8_t SWD_CURRENT = 0x0F;

    // VDDR1
    // Note that for RCDless dimms this voltage domain does not exist, but this is fine.
    // We should read out close to 0A for both currents and therefore should not trigger
    // the N-mode condition.
    FAPI_INF("Checking voltage domain VDDR1");
    read_double_domain(io_pmics[mss::pmic::id::PMIC0], io_pmics[mss::pmic::id::PMIC2], SWA_CURRENT, SWB_CURRENT,
                       l_aggregate_state, io_tele_data.iv_pmic1, io_tele_data.iv_pmic2, i_adc1, i_adc2, i_gpio1, i_gpio2);
    // VPP
    FAPI_INF("Checking voltage domain VPP");
    read_single_domain(io_pmics[mss::pmic::id::PMIC0], io_pmics[mss::pmic::id::PMIC2], SWD_CURRENT, l_aggregate_state,
                       io_tele_data.iv_pmic1, io_tele_data.iv_pmic2, i_adc1, i_adc2, i_gpio1, i_gpio2);

    // VDDR2 (or VDDR for RCDless dimms)
    FAPI_INF("Checking voltage domain VDDR2");
    read_double_domain(io_pmics[mss::pmic::id::PMIC1], io_pmics[mss::pmic::id::PMIC3], SWA_CURRENT, SWB_CURRENT,
                       l_aggregate_state, io_tele_data.iv_pmic3, io_tele_data.iv_pmic4, i_adc1, i_adc2, i_gpio1, i_gpio2);

    // VDD
    FAPI_INF("Checking voltage domain VDD");
    read_single_domain(io_pmics[mss::pmic::id::PMIC1], io_pmics[mss::pmic::id::PMIC3], SWC_CURRENT, l_aggregate_state,
                       io_tele_data.iv_pmic3, io_tele_data.iv_pmic4, i_adc1, i_adc2, i_gpio1, i_gpio2);

    // VIO is intentionally skipped as the current draw
    // is too low to draw any meaningful conclusions

    return l_aggregate_state;
}

///
/// @brief Get the pmics object
///
/// @param[in] i_ocmb_target OCMB target
/// @return std::vector<pmic_info>
///
std::vector<pmic_info> get_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    std::vector<pmic_info> l_pmics;

    // HB has passed SBE the targets in sorted pos order, so the targets
    // will already be in the correct order for our usage.
    // Not a const reference as the pmic_info ctor discards qualifiers
    for (auto& l_pmic : i_ocmb_target.getChildren<fapi2::TARGET_TYPE_PMIC>(fapi2::TARGET_STATE_PRESENT))
    {
        uint8_t l_relative_pmic_id = 0;
#ifndef __PPE__
        FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmic, l_relative_pmic_id);
#else
        l_relative_pmic_id = l_pmic.get().fields.chiplet_num % 4;
#endif
        l_pmics.push_back(pmic_info(l_pmic, pmic_state::ALL_GOOD, l_relative_pmic_id));
    }

    // If less then 4 PMICs then padd the vector with NOT_PRESENT pmics
    if (l_pmics.size() >= 1)
    {
        while (l_pmics.size() < mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::NUM_PMICS_4U)
        {
            pmic_info l_pmic_info(l_pmics[0]);
            l_pmic_info.iv_state = pmic_state::NOT_PRESENT;
            l_pmics.push_back(l_pmic_info);
        }
    }

    return l_pmics;
}

///
/// @brief Get the gpio data
///
/// @param[in] i_gpio1 GPIO1
/// @param[in] i_gpio2 GPIO2
/// @param[out] o_data telemetry data struct
///
void populate_gpio_data(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2,
    telemetry_data& o_data)
{
    fapi2::buffer<uint8_t> l_reg_contents_1;
    fapi2::buffer<uint8_t> l_reg_contents_2;

    // In the case of an I2C read failure, we don't want to abort the procedure. The
    // struct values will remain zeroed, which is fine for telemetry collection.
    // reg_read has an informative trace in case of an error that will be sufficient.
    // We already handled earlier i2c failures on these parts and how to log them
    // appropriately. We will op to skip error handling now.

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Input Port State", MSSTARGID(i_gpio1));
    mss::pmic::i2c::reg_read(i_gpio1, mss::gpio::regs::INPUT_PORT_REG, l_reg_contents_1);
    o_data.iv_gpio1_port_state = l_reg_contents_1;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Input Port State", MSSTARGID(i_gpio2));
    mss::pmic::i2c::reg_read(i_gpio2, mss::gpio::regs::INPUT_PORT_REG, l_reg_contents_2);
    o_data.iv_gpio2_port_state = l_reg_contents_2;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO EFUSE output", MSSTARGID(i_gpio1));
    mss::pmic::i2c::reg_read(i_gpio1, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents_1);
    o_data.iv_gpio1_r01_efuse_output = l_reg_contents_1;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO EFUSE output", MSSTARGID(i_gpio2));
    mss::pmic::i2c::reg_read(i_gpio2, mss::gpio::regs::EFUSE_OUTPUT, l_reg_contents_2);
    o_data.iv_gpio2_r01_efuse_output = l_reg_contents_2;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO EFUSE Polarity", MSSTARGID(i_gpio1));
    mss::pmic::i2c::reg_read(i_gpio1, mss::gpio::regs::EFUSE_POLARITY, l_reg_contents_1);
    o_data.iv_gpio1_r02_efuse_polarity = l_reg_contents_1;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO EFUSE Polarity", MSSTARGID(i_gpio2));
    mss::pmic::i2c::reg_read(i_gpio2, mss::gpio::regs::EFUSE_POLARITY, l_reg_contents_2);
    o_data.iv_gpio2_r02_efuse_polarity = l_reg_contents_2;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Configuration", MSSTARGID(i_gpio1));
    mss::pmic::i2c::reg_read(i_gpio1, mss::gpio::regs::CONFIGURATION, l_reg_contents_1);
    o_data.iv_gpio1_r03_configuration = l_reg_contents_1;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Configuration", MSSTARGID(i_gpio2));
    mss::pmic::i2c::reg_read(i_gpio2, mss::gpio::regs::CONFIGURATION, l_reg_contents_2);
    o_data.iv_gpio2_r03_configuration = l_reg_contents_2;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief Populate the pmic_data struct for the given pmic
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[out] o_pmic_data pmic_data struct
///
void populate_pmic_data(
    pmic_info& io_pmic,
    pmic_telemetry& o_pmic_data)
{
    if (!(io_pmic.iv_state & pmic_state::NOT_PRESENT))
    {
        FAPI_INF(TARGTIDFORMAT " Populating PMIC data", MSSTARGID(io_pmic.iv_pmic));

        // Required regs
        static constexpr uint8_t R08 = 0x08;
        static constexpr uint8_t R09 = 0x09;
        static constexpr uint8_t R0A = 0x0A;
        static constexpr uint8_t R0B = 0x0B;
        static constexpr uint8_t R33 = 0x33;
        static constexpr uint8_t R0C = 0x0C;
        static constexpr uint8_t R0D = 0x0D;
        static constexpr uint8_t R0E = 0x0E;
        static constexpr uint8_t R0F = 0x0F;
        static constexpr uint8_t R30 = 0x30;
        static constexpr uint8_t R31 = 0x31;
        static constexpr uint8_t R1B = 0x1B;
        static constexpr uint8_t R2E = 0x2E;
        static constexpr uint8_t R2F = 0x2F;
        static constexpr uint8_t R32 = 0x32;
        static constexpr uint8_t R9C = 0x9C;


        // 125mA * bitmap = Current value
        static constexpr uint16_t CURRENT_BITMAP_MULTIPLIER = 125;

        // PMIC's internal ADC: Measure VIN_BULK
        static constexpr uint8_t ADC_READ_VIN_BULK = 0xA8;
        static constexpr uint8_t ADC_READ_TEMP = 0xD0;

        static constexpr uint16_t ADC_VIN_BULK_STEP = 70;
        static constexpr uint16_t ADC_TEMP_STEP = 2;

        static constexpr uint32_t ADC_CNFG_DELAY = mss::DELAY_1MS * 25;

        fapi2::buffer<uint8_t> l_reg_contents;

        // First, the status registers, R08 to R0B, and R33
        {
            reg_read(io_pmic, R08, l_reg_contents);
            o_pmic_data.iv_r08 = l_reg_contents;

            reg_read(io_pmic, R09, l_reg_contents);
            o_pmic_data.iv_r09 = l_reg_contents;

            reg_read(io_pmic, R0A, l_reg_contents);
            o_pmic_data.iv_r0a = l_reg_contents;

            reg_read(io_pmic, R0B, l_reg_contents);
            o_pmic_data.iv_r0b = l_reg_contents;

            reg_read(io_pmic, R33, l_reg_contents);
            o_pmic_data.iv_r33 = l_reg_contents;
        }

        // Next, the current registers
        {
            // Overflow is not possible here as CURRENT_BITMAP_MULTIPLIER of 125 results in a max of
            // 125 * 0xFF = 0x7C83 which is within the uint16_t bounds

            // SWA
            reg_read(io_pmic, R0C, l_reg_contents);
            o_pmic_data.iv_swa_current_mA = static_cast<uint16_t>(l_reg_contents()) * CURRENT_BITMAP_MULTIPLIER;

            // SWB
            reg_read(io_pmic, R0D, l_reg_contents);
            o_pmic_data.iv_swb_current_mA = static_cast<uint16_t>(l_reg_contents()) * CURRENT_BITMAP_MULTIPLIER;

            // SWC
            reg_read(io_pmic, R0E, l_reg_contents);
            o_pmic_data.iv_swc_current_mA = static_cast<uint16_t>(l_reg_contents()) * CURRENT_BITMAP_MULTIPLIER;

            // SWD
            reg_read(io_pmic, R0F, l_reg_contents);
            o_pmic_data.iv_swd_current_mA = static_cast<uint16_t>(l_reg_contents()) * CURRENT_BITMAP_MULTIPLIER;
        }

        // Next, measure VIN Bulk by setting up the PMIC's internal ADC
        {
            l_reg_contents = ADC_READ_VIN_BULK;
            reg_write(io_pmic, R30, l_reg_contents);

            // Delay to let the ADC configure itself
            fapi2::delay(ADC_CNFG_DELAY, mss::DELAY_1MS);

            // Now read out the VIN_BULK value in mV
            reg_read(io_pmic, R31, l_reg_contents);
            o_pmic_data.iv_vin_bulk_mV = static_cast<uint16_t>(l_reg_contents()) * ADC_VIN_BULK_STEP;
        }

        // Next, temperature
        {
            l_reg_contents = ADC_READ_TEMP;
            reg_write(io_pmic, R30, l_reg_contents);

            // Delay to let the ADC configure itself
            fapi2::delay(ADC_CNFG_DELAY, mss::DELAY_1MS);

            // Now read out the TEMP value in mV
            reg_read(io_pmic, R31, l_reg_contents);
            o_pmic_data.iv_temp_c = static_cast<uint16_t>(l_reg_contents()) * ADC_TEMP_STEP;
        }

        //
        {
            reg_read(io_pmic, R1B, l_reg_contents);
            o_pmic_data.iv_r1b = l_reg_contents;

            reg_read(io_pmic, R2E, l_reg_contents);
            o_pmic_data.iv_r2e = l_reg_contents;

            reg_read(io_pmic, R2F, l_reg_contents);
            o_pmic_data.iv_r2f = l_reg_contents;

            reg_read(io_pmic, R32, l_reg_contents);
            o_pmic_data.iv_r32 = l_reg_contents;

            reg_read(io_pmic, R9C, l_reg_contents);
            o_pmic_data.iv_r9c = l_reg_contents;
        }
    }
}

///
/// @brief Get the adc scale factor object
///
/// @param[in] i_adc_num ADC device enum (expected to be ADC1 or ADC2)
/// @param[in] i_adc_reg Register
/// @return double scale factor
///
uint32_t get_adc_scale_factor(const mss::generic_i2c_responder_ddr4 i_adc_num, const uint8_t i_adc_reg)
{
    // mul by 5

    // All these values * 10^-9
    static constexpr uint32_t DUAL_PHASE_SCALE   = 75531;
    static constexpr uint32_t SINGLE_PHASE_SCALE = 37765;

    // Specific channels need specific scale factors due to the dual phasing
    if (i_adc_num == mss::generic_i2c_responder_ddr4::ADC1)
    {
        // CH5 or CH3, we need to use a different scale factor
        if ((i_adc_reg == mss::adc::regs::RECENT_CH3_LSB) || (i_adc_reg == mss::adc::regs::RECENT_CH5_LSB) ||
            (i_adc_reg == mss::adc::regs::MAX_CH3_LSB) || (i_adc_reg == mss::adc::regs::MAX_CH5_LSB) ||
            (i_adc_reg == mss::adc::regs::MIN_CH3_LSB) || (i_adc_reg == mss::adc::regs::MIN_CH5_LSB))
        {
            return DUAL_PHASE_SCALE;
        }
    }
    else if (i_adc_num == mss::generic_i2c_responder_ddr4::ADC2) // ADC2
    {
        if ((i_adc_reg == mss::adc::regs::RECENT_CH0_LSB) ||
            (i_adc_reg == mss::adc::regs::MAX_CH0_LSB) ||
            (i_adc_reg == mss::adc::regs::MIN_CH0_LSB))
        {
            return DUAL_PHASE_SCALE;
        }
    }

    // Otherwise, we will use the single phase scale
    return SINGLE_PHASE_SCALE;
}

///
/// @brief Populate the ADC data struct
///
/// @param[in] i_adc ADC target
/// @param[in] i_adc_num ADC number enum
/// @param[out] o_adc_data data struct
///
void populate_adc_data(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc,
    const mss::generic_i2c_responder_ddr4 i_adc_num,
    adc_telemetry& o_adc_data)
{
    FAPI_INF(TARGTIDFORMAT " Populating ADC data", MSSTARGID(i_adc));

    static constexpr uint64_t TO_MV = 1000000;
    static constexpr uint8_t ADC_U16_MAP_LEN = 24;
    static constexpr uint8_t REG_SIZE_BITS = 8;
    fapi2::buffer<uint8_t> l_reg_contents;

    mss::pmic::i2c::reg_read(i_adc, mss::adc::regs::LOW_EVENT_FLAGS, l_reg_contents);
    o_adc_data.iv_event_low_flag = l_reg_contents;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    mss::pmic::i2c::reg_read(i_adc, mss::adc::regs::SYSTEM_STATUS, l_reg_contents);
    o_adc_data.iv_system_status = l_reg_contents;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    mss::pmic::i2c::reg_read(i_adc, mss::adc::regs::AUTO_SEQ_CH_SEL, l_reg_contents);
    o_adc_data.iv_auto_seq_ch_sel = l_reg_contents;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Fields that map a LSB register to the uint16_t destination in o_adc_data
    const adu_map_t ADC_U16_MAP[ADC_U16_MAP_LEN] =
    {
        {mss::adc::regs::RECENT_CH0_LSB, &o_adc_data.iv_recent_ch0_mV},
        {mss::adc::regs::RECENT_CH1_LSB, &o_adc_data.iv_recent_ch1_mV},
        {mss::adc::regs::RECENT_CH2_LSB, &o_adc_data.iv_recent_ch2_mV},
        {mss::adc::regs::RECENT_CH3_LSB, &o_adc_data.iv_recent_ch3_mV},
        {mss::adc::regs::RECENT_CH4_LSB, &o_adc_data.iv_recent_ch4_mV},
        {mss::adc::regs::RECENT_CH5_LSB, &o_adc_data.iv_recent_ch5_mV},
        {mss::adc::regs::RECENT_CH6_LSB, &o_adc_data.iv_recent_ch6_mV},
        {mss::adc::regs::RECENT_CH7_LSB, &o_adc_data.iv_recent_ch7_mV},

        {mss::adc::regs::MAX_CH0_LSB, &o_adc_data.iv_max_ch0_mV},
        {mss::adc::regs::MAX_CH1_LSB, &o_adc_data.iv_max_ch1_mV},
        {mss::adc::regs::MAX_CH2_LSB, &o_adc_data.iv_max_ch2_mV},
        {mss::adc::regs::MAX_CH3_LSB, &o_adc_data.iv_max_ch3_mV},
        {mss::adc::regs::MAX_CH4_LSB, &o_adc_data.iv_max_ch4_mV},
        {mss::adc::regs::MAX_CH5_LSB, &o_adc_data.iv_max_ch5_mV},
        {mss::adc::regs::MAX_CH6_LSB, &o_adc_data.iv_max_ch6_mV},
        {mss::adc::regs::MAX_CH7_LSB, &o_adc_data.iv_max_ch7_mV},

        {mss::adc::regs::MIN_CH0_LSB, &o_adc_data.iv_min_ch0_mV},
        {mss::adc::regs::MIN_CH1_LSB, &o_adc_data.iv_min_ch1_mV},
        {mss::adc::regs::MIN_CH2_LSB, &o_adc_data.iv_min_ch2_mV},
        {mss::adc::regs::MIN_CH3_LSB, &o_adc_data.iv_min_ch3_mV},
        {mss::adc::regs::MIN_CH4_LSB, &o_adc_data.iv_min_ch4_mV},
        {mss::adc::regs::MIN_CH5_LSB, &o_adc_data.iv_min_ch5_mV},
        {mss::adc::regs::MIN_CH6_LSB, &o_adc_data.iv_min_ch6_mV},
        {mss::adc::regs::MIN_CH7_LSB, &o_adc_data.iv_min_ch7_mV}
    };

    mss::pmic::i2c::reg_read_reverse_buffer(i_adc, mss::adc::regs::GENERAL_CFG, l_reg_contents);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    l_reg_contents.clearBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(i_adc, mss::adc::regs::GENERAL_CFG, l_reg_contents);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Set each one
    for (const auto& l_adc_pair : ADC_U16_MAP)
    {
        fapi2::buffer<uint8_t> l_channel_msb;
        fapi2::buffer<uint8_t> l_channel_lsb;

        uint16_t l_channel_field = 0;
        constexpr uint8_t REG_MSB_OFFSET = 1;

        const auto REG = l_adc_pair.first;

        // First read the LSB reg. Then the MSB reg is the next one
        mss::pmic::i2c::reg_read(i_adc, REG, l_channel_lsb);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        mss::pmic::i2c::reg_read(i_adc, REG + REG_MSB_OFFSET, l_channel_msb);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // MSB then LSB
        l_channel_msb.extract<0, REG_SIZE_BITS, 0>(l_channel_field);
        l_channel_lsb.extract<0, REG_SIZE_BITS, REG_SIZE_BITS>(l_channel_field);

        // scale
        const uint64_t l_field_unscaled = l_channel_field * get_adc_scale_factor(i_adc_num, REG);
        (*l_adc_pair.second) = static_cast<uint16_t>(l_field_unscaled / TO_MV);
    }

    mss::pmic::i2c::reg_read_reverse_buffer(i_adc, mss::adc::regs::GENERAL_CFG, l_reg_contents);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    l_reg_contents.setBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(i_adc, mss::adc::regs::GENERAL_CFG, l_reg_contents);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return;
}

///
/// @brief Send the runtime_n_mode_telem_info struct
///
/// @param[in] i_info runtime_n_mode_telem_info struct
/// @param[out] o_data hwp_data_ostream data stream
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode send_struct(runtime_n_mode_telem_info& i_info, fapi2::hwp_data_ostream& o_data)
{
    // Casted to char pointer so we can increment in single bytes
    char* i_info_casted  = reinterpret_cast<char*>(&i_info);

    // Loop through in increments of hwp_data_unit size (currently uint32_t)
    // Until we have copied the entire structure
    for (uint16_t l_byte = 0; l_byte < sizeof(i_info); l_byte += sizeof(fapi2::hwp_data_unit))
    {
        fapi2::hwp_data_unit l_data_unit = 0;

        // The number of bytes to copy is either always 4 (size of hwp_data_unit),
        // OR less if we have fewer than 4 bytes left in the struct, in which case we copy
        // that amount.
        const size_t l_bytes_to_copy = std::min(sizeof(fapi2::hwp_data_unit), sizeof(i_info) - l_byte);

        memcpy(&l_data_unit, i_info_casted + l_byte, l_bytes_to_copy);
        FAPI_TRY(o_data.put(l_data_unit));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get bread crumb reg value for individual PMIC
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[out] o_pmic_data pmic_data struct
/// @return None
///
void get_bread_crumb_pmic(pmic_info& io_pmic,
                          pmic_telemetry& o_pmic_data)
{
    fapi2::buffer<uint8_t> l_reg_contents;
    static constexpr uint8_t RA3_BREADCRUMB = 0xA3;

    reg_read(io_pmic, RA3_BREADCRUMB, l_reg_contents);

    // 0xA3 register is not defaulted to 0. This logic is to set it to 0
    // if there are no breadcrumbs present.
    if((l_reg_contents < bread_crumb::FIRST_ATTEMPT) ||
       (l_reg_contents > bread_crumb::STILL_A_FAIL))
    {
        l_reg_contents = bread_crumb::BREAD_CRUMB_ALL_GOOD;
    }

    o_pmic_data.iv_breadcrumb = l_reg_contents;
}

///
/// @brief Get bread crumb reg value for all PMIC target
/// @param[in,out] vector of io_pmic pmic_info class including target / state info
/// @param[out] o_tele_data telemetry_data struct
/// @return bread_crumb value
///
bread_crumb get_bread_crumbs(std::vector<pmic_info>& io_pmics,
                             telemetry_data& o_tele_data)
{
    fapi2::buffer<uint8_t> l_reg_contents;

    get_bread_crumb_pmic(io_pmics[mss::pmic::id::PMIC0], o_tele_data.iv_pmic1);
    get_bread_crumb_pmic(io_pmics[mss::pmic::id::PMIC1], o_tele_data.iv_pmic3);
    get_bread_crumb_pmic(io_pmics[mss::pmic::id::PMIC2], o_tele_data.iv_pmic2);
    get_bread_crumb_pmic(io_pmics[mss::pmic::id::PMIC3], o_tele_data.iv_pmic4);

    return static_cast<bread_crumb>(std::max(std::max(o_tele_data.iv_pmic1.iv_breadcrumb,
                                    o_tele_data.iv_pmic2.iv_breadcrumb),
                                    std::max(o_tele_data.iv_pmic3.iv_breadcrumb,
                                            o_tele_data.iv_pmic4.iv_breadcrumb)));
}

///
/// @brief Check and reset bread crumb reg value if PMIC status is clean
/// @param[in,out] vector of io_pmic pmic_info class including target / state info
/// @param[in,out] io_tele_data telemetry_data struct
/// @return bread_crumb value
///
void check_and_reset_breadcrumb(std::vector<pmic_info>& io_pmics,
                                telemetry_data& io_tele_data)
{
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;

    if (io_pmics[mss::pmic::id::PMIC0].iv_state == aggregate_state::N_PLUS_1)
    {
        reg_write(io_pmics[mss::pmic::id::PMIC0], TPS_REGS::RA3_BREADCRUMB, bread_crumb::BREAD_CRUMB_ALL_GOOD);
        io_tele_data.iv_pmic1.iv_breadcrumb = bread_crumb::BREAD_CRUMB_ALL_GOOD;
    }

    if (io_pmics[mss::pmic::id::PMIC1].iv_state == aggregate_state::N_PLUS_1)
    {
        reg_write(io_pmics[mss::pmic::id::PMIC1], TPS_REGS::RA3_BREADCRUMB, bread_crumb::BREAD_CRUMB_ALL_GOOD);
        io_tele_data.iv_pmic3.iv_breadcrumb = bread_crumb::BREAD_CRUMB_ALL_GOOD;
    }

    if (io_pmics[mss::pmic::id::PMIC2].iv_state == aggregate_state::N_PLUS_1)
    {
        reg_write(io_pmics[mss::pmic::id::PMIC2], TPS_REGS::RA3_BREADCRUMB, bread_crumb::BREAD_CRUMB_ALL_GOOD);
        io_tele_data.iv_pmic2.iv_breadcrumb = bread_crumb::BREAD_CRUMB_ALL_GOOD;
    }

    if (io_pmics[mss::pmic::id::PMIC3].iv_state == aggregate_state::N_PLUS_1)
    {
        reg_write(io_pmics[mss::pmic::id::PMIC3], TPS_REGS::RA3_BREADCRUMB, bread_crumb::BREAD_CRUMB_ALL_GOOD);
        io_tele_data.iv_pmic4.iv_breadcrumb = bread_crumb::BREAD_CRUMB_ALL_GOOD;
    }
}

///
/// @brief Runtime N-Mode detection for 4U parts
/// @param[in] i_ocmb_target ocmb target
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode pmic_n_mode_detect(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    fapi2::hwp_data_ostream& o_data)
{
    FAPI_INF(TARGTIDFORMAT " Running pmic_n_mode_detect HWP", MSSTARGID(i_ocmb_target));

    fapi2::buffer<uint8_t> l_failed_pmics_1;
    fapi2::buffer<uint8_t> l_failed_pmics_2;

    runtime_n_mode_telem_info l_info;
    aggregate_state l_state = aggregate_state::N_PLUS_1;

    // Expecting to receive 4 GI2C targets and 4 PMICs from PPE platform
    const auto GI2C_DEVICES = i_ocmb_target.getChildren<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>
                              (fapi2::TARGET_STATE_PRESENT);
    auto PMICS = get_pmics(i_ocmb_target);

    // Grab the targets
    const auto& ADC1 = GI2C_DEVICES[mss::generic_i2c_responder_ddr4::ADC1];
    const auto& ADC2 = GI2C_DEVICES[mss::generic_i2c_responder_ddr4::ADC2];
    const auto& GPIO1 = GI2C_DEVICES[mss::generic_i2c_responder_ddr4::GPIO1];
    const auto& GPIO2 = GI2C_DEVICES[mss::generic_i2c_responder_ddr4::GPIO2];

    if (PMICS.empty())
    {
        l_info.iv_aggregate_error = aggregate_state::LOST;
        FAPI_TRY(send_struct(l_info, o_data));
        return fapi2::FAPI2_RC_FALSE;
    }

    // Platform (SBE) has asserted we will receive exactly 4 GI2C targets iff 4U
    // Do a check to see if we are 4U by checking for 4 GI2C targets
    if (!is_4u(i_ocmb_target))
    {
        l_info.iv_aggregate_error = aggregate_state::DIMM_NOT_4U;
        FAPI_TRY(send_struct(l_info, o_data));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Skip to telemetry collection if already in n-mode
    if (get_bread_crumbs(PMICS, l_info.iv_telemetry_data) != bread_crumb::STILL_A_FAIL)
    {
        // Start with the GPIOs
        aggregate_state l_output_state_1 = gpio_check(GPIO1, PMICS[mss::pmic::id::PMIC0], PMICS[mss::pmic::id::PMIC1],
                                           l_failed_pmics_1, l_info.iv_telemetry_data.iv_pmic1, l_info.iv_telemetry_data.iv_pmic3, ADC1, ADC2);
        aggregate_state l_output_state_2 = gpio_check(GPIO2, PMICS[mss::pmic::id::PMIC2], PMICS[mss::pmic::id::PMIC3],
                                           l_failed_pmics_2, l_info.iv_telemetry_data.iv_pmic2, l_info.iv_telemetry_data.iv_pmic4, ADC1, ADC2);

        get_gpio_pmic_state<PAIR0>(l_output_state_1, l_failed_pmics_1, l_failed_pmics_2);
        get_gpio_pmic_state<PAIR1>(l_output_state_2, l_failed_pmics_1, l_failed_pmics_2);

        // Choose the largest of the two states
        l_state = static_cast<aggregate_state>(std::max(l_output_state_1, l_output_state_2));

        if (l_state == aggregate_state::N_PLUS_1)
        {
            l_output_state_1 = adc_check(ADC1, ADC2, GPIO1, GPIO2, PMICS[mss::pmic::id::PMIC0], PMICS[mss::pmic::id::PMIC2],
                                         mss::generic_i2c_responder_ddr4::ADC1, l_info.iv_telemetry_data.iv_pmic1, l_info.iv_telemetry_data.iv_pmic2);
            l_output_state_2 = adc_check(ADC2, ADC1, GPIO1, GPIO2, PMICS[mss::pmic::id::PMIC1], PMICS[mss::pmic::id::PMIC3],
                                         mss::generic_i2c_responder_ddr4::ADC2, l_info.iv_telemetry_data.iv_pmic3, l_info.iv_telemetry_data.iv_pmic4);

            // Pick the largest error so far
            l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_1));
            l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_2));

            if (l_state == aggregate_state::N_PLUS_1)
            {
                // Now, the voltages
                l_output_state_1 = voltage_checks(PMICS, l_info.iv_telemetry_data, ADC1, ADC2, GPIO1, GPIO2);
                l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_1));
            }
        }

        // This numbering is using the numbering as defined in the "Redundant Power
        // on DIMM – Functional Specification" in order to match the I2C command sequence
        // in section 6.3.1 This differs from the numbering used in pmic_enable and in lab tools,
        // so there is a translation between the two here
        l_info.iv_pmic1_errors = PMICS[mss::pmic::id::PMIC0].iv_state;
        l_info.iv_pmic2_errors = PMICS[mss::pmic::id::PMIC2].iv_state;
        l_info.iv_pmic3_errors = PMICS[mss::pmic::id::PMIC1].iv_state;
        l_info.iv_pmic4_errors = PMICS[mss::pmic::id::PMIC3].iv_state;
        l_info.iv_aggregate_error = l_state;

        check_and_reset_breadcrumb(PMICS, l_info.iv_telemetry_data);
    }
    else
    {
        l_info.iv_aggregate_error = aggregate_state::N_MODE;
    }

    // Get GPIO data
    populate_gpio_data(GPIO1, GPIO2, l_info.iv_telemetry_data);

    // Similar to above, this numbering translation is using the numbering
    // as defined in the "Redundant Power on DIMM – Functional Specification"
    populate_pmic_data(PMICS[mss::pmic::id::PMIC0], l_info.iv_telemetry_data.iv_pmic1);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC2], l_info.iv_telemetry_data.iv_pmic2);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC1], l_info.iv_telemetry_data.iv_pmic3);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC3], l_info.iv_telemetry_data.iv_pmic4);

    // Finally, the ADCs
    populate_adc_data(ADC1, mss::generic_i2c_responder_ddr4::ADC1, l_info.iv_telemetry_data.iv_adc1);
    populate_adc_data(ADC2, mss::generic_i2c_responder_ddr4::ADC2, l_info.iv_telemetry_data.iv_adc2);

    FAPI_TRY(send_struct(l_info, o_data));

    FAPI_INF(TARGTIDFORMAT " Compeleted pmic_n_mode_detect procedure", MSSTARGID(i_ocmb_target));

fapi_try_exit:
    return fapi2::current_err;
}
