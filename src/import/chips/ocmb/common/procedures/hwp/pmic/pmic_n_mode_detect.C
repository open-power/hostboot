/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_n_mode_detect.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
// *HWP Consumed by: SBE
// EKB-Mirror-To: hw/ppe

#include <fapi2.H>
#include <pmic_n_mode_detect.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>

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
    const auto GI2CS = i_ocmb_target.getChildren<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(fapi2::TARGET_STATE_PRESENT);

    return (GI2CS.size() == mss::generic_i2c_slave::NUM_TOTAL_DEVICES);
}

///
/// @brief Check the GPIO for n mode detection
///
/// @param[in] i_gpio GPIO Expander target
/// @param[in,out] io_pmic1 PMIC1/3 pmic_info class including target / state info
/// @param[in,out] io_pmic2 PMIC2/4 pmic_info class including target / state info
/// @param[in,out] io_failed_pmics Bit map of failed PMICS on a GPIO
/// @return aggregate_state N mode state according to the status of GPIO and ADC only
///
aggregate_state gpio_check(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio,
                           pmic_info& io_pmic1,
                           pmic_info& io_pmic2,
                           fapi2::buffer<uint8_t>& io_failed_pmics)
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
        FAPI_INF(TARGTIDFORMAT " Primary PMIC PWR_NOT_GOOD", MSSTARGID(i_gpio));
        io_pmic1.iv_state |= PWR_NOT_GOOD;
    }

    if (!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_PMIC_PAIR1>())
    {
        FAPI_INF(TARGTIDFORMAT " Secondary PMIC PWR_NOT_GOOD", MSSTARGID(i_gpio));
        io_pmic2.iv_state |= PWR_NOT_GOOD;
    }

    // Check ADC_ALERT bit and declare n-mode if it is not set
    if (!l_reg.getBit<mss::gpio::fields::INPUT_PORT_REG_FAULT_N>())
    {
        FAPI_INF(TARGTIDFORMAT " ADC_ALERT bit flagged. Declaring n-mode", MSSTARGID(i_gpio));
        l_state = static_cast<aggregate_state>(std::max(l_state, aggregate_state::N_MODE));
    }

    return l_state;
}

///
/// @brief Check the ADC device for EVENT_FLAG
///
/// @param[in] i_adc ADC target
///
aggregate_state adc_check(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc)
{
    FAPI_INF(TARGTIDFORMAT " Checking ADC for EVENT_FLAG", MSSTARGID(i_adc));

    constexpr uint8_t EVENT_FLAG_GOOD = 0x00;

    // Start with the buffer polluted. If the reg read fails, we assume l_reg will
    // be left unchanged, so 0xFF will force an n-mode declaration
    fapi2::buffer<uint8_t> l_reg(0xFF);

    // We don't care if this read fails. We would treat it the same as a bad EVENT_FLAG reg
    if (mss::pmic::i2c::reg_read(i_adc, mss::adc::regs::EVENT_FLAG, l_reg) != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF(TARGTIDFORMAT " EVENT_FLAG register read failed", MSSTARGID(i_adc));
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        return aggregate_state::GI2C_I2C_FAIL;
    }

    // If the EVENT_FLAG register is not all zero, declare n-mode
    if (l_reg != EVENT_FLAG_GOOD)
    {
        FAPI_INF(TARGTIDFORMAT " One or more EVENT_FLAG bits set. Declaring n-mode", MSSTARGID(i_adc));
        return aggregate_state::N_MODE;
    }

    return aggregate_state::N_PLUS_1;
}

///
/// @brief Compare two phases provided from two pmics, declaring N-mode & pmic states as needed
///
/// @param[in,out] io_first_pmic First pmic_info class including target / state info
/// @param[in,out] io_second_pmic Second pmic_info class including target / state info
/// @param[in] i_phase0 One phase
/// @param[in] i_phase1 Other phase
/// @param[out] o_aggregate_state Aggregate state, to be updated if needed
///
void phase_comparison(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint32_t i_phase0,
    const uint32_t i_phase1,
    aggregate_state& o_aggregate_state)
{
    if ((io_first_pmic.iv_state & pmic_state::NOT_PRESENT) || (io_second_pmic.iv_state & pmic_state::NOT_PRESENT))
    {
        o_aggregate_state = aggregate_state::N_MODE;
        return;
    }

    if (((i_phase0 < PHASE_MIN) && i_phase1 > PHASE_MAX) || ((i_phase1 < PHASE_MIN) && (i_phase0 > PHASE_MAX)))
    {
        o_aggregate_state = aggregate_state::N_MODE;

        // Set the flag for whichever had the imbalance
        if (i_phase0 < PHASE_MIN)
        {
            io_first_pmic.iv_state |= CURRENT_IMBALANCE;
        }
        else
        {
            io_second_pmic.iv_state |= CURRENT_IMBALANCE;
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
/// @return aggregate_state Aggregate state, updated to N-Mode if failed checks
///
void read_double_domain(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint8_t i_rail_1,
    const uint8_t i_rail_2,
    aggregate_state& o_aggregate_state)
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

    phase_comparison(io_first_pmic, io_second_pmic, l_phase0, l_phase1, o_aggregate_state);
}

///
/// @brief Read a single phase voltage domain, check for N-Mode
///
/// @param[in,out] io_first_pmic First pmic_info class including target / state info
/// @param[in,out] io_second_pmic Second pmic_info class including target / state info
/// @param[in] i_rail_1 Rail register to read
/// @param[out] o_aggregate_state Aggregate state output, to be updated if needed
/// @return aggregate_state Aggregate state, updated to N-Mode if failed checks
///
void read_single_domain(
    pmic_info& io_first_pmic,
    pmic_info& io_second_pmic,
    const uint8_t i_rail_1,
    aggregate_state& o_aggregate_state)
{
    uint32_t l_phase0 = 0;
    uint32_t l_phase1 = 0;

    fapi2::buffer<uint8_t> l_reg0;
    fapi2::buffer<uint8_t> l_reg1;

    reg_read(io_first_pmic, i_rail_1, l_reg0);
    reg_read(io_second_pmic, i_rail_1, l_reg1);

    l_phase0 = (l_reg0 * CURRENT_MULTIPLIER);
    l_phase1 = (l_reg1 * CURRENT_MULTIPLIER);

    phase_comparison(io_first_pmic, io_second_pmic, l_phase0, l_phase1, o_aggregate_state);
}

///
/// @brief Perform voltage n mode checks
///
/// @param[in] i_pmics PMICS in sorted order
/// @return aggregate_state state of the part
///
aggregate_state voltage_checks(std::vector<pmic_info>& i_pmics)
{
    aggregate_state l_aggregate_state = aggregate_state::N_PLUS_1;

    // Required regs
    static constexpr uint8_t SWA_CURRENT = 0x0C;
    static constexpr uint8_t SWB_CURRENT = 0x0D;
    // SWC used for VIO, which we will not check as per spec
    static constexpr uint8_t SWD_CURRENT = 0x0F;

    // VDDR1
    // Note that for RCDless dimms this voltage domain does not exist, but this is fine.
    // We should read out close to 0A for both currents and therefore should not trigger
    // the N-mode condition.
    FAPI_INF("Checking voltage domain VDDR1");
    read_double_domain(i_pmics[mss::pmic::id::PMIC0], i_pmics[mss::pmic::id::PMIC2], SWA_CURRENT, SWB_CURRENT,
                       l_aggregate_state);

    // VPP
    FAPI_INF("Checking voltage domain VPP");
    read_single_domain(i_pmics[mss::pmic::id::PMIC0], i_pmics[mss::pmic::id::PMIC2], SWD_CURRENT, l_aggregate_state);

    // VDDR2 (or VDDR for RCDless dimms)
    FAPI_INF("Checking voltage domain VDDR2");
    read_double_domain(i_pmics[mss::pmic::id::PMIC1], i_pmics[mss::pmic::id::PMIC3], SWA_CURRENT, SWB_CURRENT,
                       l_aggregate_state);

    // VDD
    FAPI_INF("Checking voltage domain VDD");
    read_single_domain(i_pmics[mss::pmic::id::PMIC1], i_pmics[mss::pmic::id::PMIC3], SWD_CURRENT, l_aggregate_state);

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
        l_pmics.push_back(pmic_info(l_pmic, pmic_state::ALL_GOOD));
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
/// @brief Get the gpio port states
///
/// @param[in] i_gpio1 GPIO1
/// @param[in] i_gpio2 GPIO2
/// @param[out] o_data telemetry data struct
///
void populate_gpio_port_states(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio2,
    telemetry_data& o_data)
{
    fapi2::buffer<uint8_t> l_reg_contents_1;
    fapi2::buffer<uint8_t> l_reg_contents_2;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Input Port State", MSSTARGID(i_gpio1));
    mss::pmic::i2c::reg_read(i_gpio1, mss::gpio::regs::INPUT_PORT_REG, l_reg_contents_1);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(TARGTIDFORMAT " Reading GPIO Input Port State", MSSTARGID(i_gpio2));
    mss::pmic::i2c::reg_read(i_gpio2, mss::gpio::regs::INPUT_PORT_REG, l_reg_contents_2);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // In the case of an I2C read failure, we don't want to abort the procedure. The
    // struct values will remain zeroed, which is fine for telemetry collection.
    // reg_read has an informative trace in case of an error that will be sufficient.
    // We already handled earlier i2c failures on these parts and how to log them
    // appropriately. We will op to skip error handling now.
    o_data.iv_gpio1_port_state = l_reg_contents_1;
    o_data.iv_gpio2_port_state = l_reg_contents_2;
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
    }
}

///
/// @brief Get the adc scale factor object
///
/// @param[in] i_adc_num ADC device enum (expected to be ADC1 or ADC2)
/// @param[in] i_adc_reg Register
/// @return double scale factor
///
uint32_t get_adc_scale_factor(const mss::generic_i2c_slave i_adc_num, const uint8_t i_adc_reg)
{
    // mul by 5

    // All these values * 10^-9
    static constexpr uint32_t DUAL_PHASE_SCALE   = 75531;
    static constexpr uint32_t SINGLE_PHASE_SCALE = 37765;

    // Specific channels need specific scale factors due to the dual phasing
    if (i_adc_num == mss::generic_i2c_slave::ADC1)
    {
        // CH5 or CH3, we need to use a different scale factor
        if ((i_adc_reg == mss::adc::regs::RECENT_CH3_LSB) || (i_adc_reg == mss::adc::regs::RECENT_CH5_LSB) ||
            (i_adc_reg == mss::adc::regs::MAX_CH3_LSB) || (i_adc_reg == mss::adc::regs::MAX_CH5_LSB) ||
            (i_adc_reg == mss::adc::regs::MIN_CH3_LSB) || (i_adc_reg == mss::adc::regs::MIN_CH5_LSB))
        {
            return DUAL_PHASE_SCALE;
        }
    }
    else if (i_adc_num == mss::generic_i2c_slave::ADC2) // ADC2
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
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc,
    const mss::generic_i2c_slave i_adc_num,
    adc_telemetry& o_adc_data)
{
    FAPI_INF(TARGTIDFORMAT " Populating ADC data", MSSTARGID(i_adc));

    static constexpr uint64_t TO_MV = 1000000;
    static constexpr uint8_t ADC_U16_MAP_LEN = 24;
    static constexpr uint8_t REG_SIZE_BITS = 8;
    fapi2::buffer<uint8_t> l_reg_contents;

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
///
void send_struct(runtime_n_mode_telem_info& i_info, fapi2::hwp_data_ostream& o_data)
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
        o_data.put(l_data_unit);
    }
}

///
/// @brief Runtime N-Mode detection for 4U parts
/// @param[in] i_ocmb_target ocmb target
/// @param[out] o_data hwp_data_ostream of struct information
/// @return FAPI2_RC_SUCCESS (0)
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
    const auto GI2C_DEVICES = i_ocmb_target.getChildren<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(fapi2::TARGET_STATE_PRESENT);
    auto PMICS = get_pmics(i_ocmb_target);

    if (PMICS.empty())
    {
        l_info.iv_aggregate_error = aggregate_state::LOST;
        send_struct(l_info, o_data);
        return fapi2::FAPI2_RC_FALSE;
    }

    // Platform (SBE) has asserted we will receive exactly 4 GI2C targets iff 4U
    // Do a check to see if we are 4U by checking for 4 GI2C targets
    if (!is_4u(i_ocmb_target))
    {
        l_info.iv_aggregate_error = aggregate_state::DIMM_NOT_4U;
        send_struct(l_info, o_data);
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Grab the targets
    const auto& ADC1 = GI2C_DEVICES[mss::generic_i2c_slave::ADC1];
    const auto& ADC2 = GI2C_DEVICES[mss::generic_i2c_slave::ADC2];
    const auto& GPIO1 = GI2C_DEVICES[mss::generic_i2c_slave::GPIO1];
    const auto& GPIO2 = GI2C_DEVICES[mss::generic_i2c_slave::GPIO2];

    aggregate_state l_output_state_1 = aggregate_state::N_PLUS_1;
    aggregate_state l_output_state_2 = aggregate_state::N_PLUS_1;

    // Start with the GPIOs
    l_output_state_1 = gpio_check(GPIO1, PMICS[mss::pmic::id::PMIC0], PMICS[mss::pmic::id::PMIC1], l_failed_pmics_1);
    l_output_state_2 = gpio_check(GPIO2, PMICS[mss::pmic::id::PMIC2], PMICS[mss::pmic::id::PMIC3], l_failed_pmics_2);

    get_gpio_pmic_state<PAIR0>(l_output_state_1, l_failed_pmics_1, l_failed_pmics_2);
    get_gpio_pmic_state<PAIR1>(l_output_state_2, l_failed_pmics_1, l_failed_pmics_2);

    // Choose the largest of the two states, a double N-Mode declaration here is
    // still just only N-Mode since the two GPIOs handle a separate set of redundant pmics
    l_state = static_cast<aggregate_state>(std::max(l_output_state_1, l_output_state_2));

    l_output_state_1 = adc_check(ADC1);
    l_output_state_2 = adc_check(ADC2);

    // Pick the largest error so far
    l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_1));
    l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_2));

    // Now, the voltages
    l_output_state_1 = voltage_checks(PMICS);
    l_state = static_cast<aggregate_state>(std::max(l_state, l_output_state_1));

    // This numbering is using the numbering as defined in the "Redundant Power
    // on DIMM – Functional Specification" in order to match the I2C command sequence
    // in section 6.3.1 This differs from the numbering used in pmic_enable and in lab tools,
    // so there is a translation between the two here
    l_info.iv_pmic1_errors = PMICS[mss::pmic::id::PMIC0].iv_state;
    l_info.iv_pmic2_errors = PMICS[mss::pmic::id::PMIC2].iv_state;
    l_info.iv_pmic3_errors = PMICS[mss::pmic::id::PMIC1].iv_state;
    l_info.iv_pmic4_errors = PMICS[mss::pmic::id::PMIC3].iv_state;
    l_info.iv_aggregate_error = l_state;

    // Get GPIO port states
    populate_gpio_port_states(GPIO1, GPIO2, l_info.iv_telemetry_data);

    // Similar to above, this numbering translation is using the numbering
    // as defined in the "Redundant Power on DIMM – Functional Specification"
    populate_pmic_data(PMICS[mss::pmic::id::PMIC0], l_info.iv_telemetry_data.iv_pmic1);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC2], l_info.iv_telemetry_data.iv_pmic2);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC1], l_info.iv_telemetry_data.iv_pmic3);
    populate_pmic_data(PMICS[mss::pmic::id::PMIC3], l_info.iv_telemetry_data.iv_pmic4);

    // Finally, the ADCs
    populate_adc_data(ADC1, mss::generic_i2c_slave::ADC1, l_info.iv_telemetry_data.iv_adc1);
    populate_adc_data(ADC2, mss::generic_i2c_slave::ADC2, l_info.iv_telemetry_data.iv_adc2);

    send_struct(l_info, o_data);

    FAPI_INF(TARGTIDFORMAT " Compeleted pmic_n_mode_detect procedure", MSSTARGID(i_ocmb_target));
    return fapi2::FAPI2_RC_SUCCESS;
}
