/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/pmic_n_mode_detect.H $ */
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

#ifndef __PMIC_N_MODE_DETECT_H__
#define __PMIC_N_MODE_DETECT_H__

#include <fapi2.H>
#include <lib/utils/pmic_consts.H>
#include <hwp_data_stream.H>

// Extra constants
static constexpr uint16_t CURRENT_MULTIPLIER = 125;
static constexpr uint16_t PHASE_MIN = 250;
static constexpr uint16_t PHASE_MAX = 1250;
static constexpr uint8_t  CLEAR_STATUS = 0x01;
static constexpr uint8_t  CLEAR_LOW_EVENT_FLAGS = 0xFF;


///
/// @brief N Mode State to return
///
enum aggregate_state : uint8_t
{
    N_PLUS_1                  = 0,
    N_MODE_POSSIBLE           = 1,
    N_MODE_RECOVERY_ATTEMPTED = 2,
    N_MODE                    = 3,
    LOST                      = 4,
    GI2C_I2C_FAIL             = 5,
    DIMM_NOT_4U               = 6,
};

///
/// @brief States for the pmics to be returned in a uint8_t bitmap
///
enum pmic_state : uint8_t
{
    DECONFIGURED       = 0b10000000,
    ADC_ERROR          = 0b00010000,
    NOT_PRESENT        = 0b00001000,
    I2C_FAIL           = 0b00000100,
    CURRENT_IMBALANCE  = 0b00000010,
    PWR_NOT_GOOD       = 0b00000001,
    ALL_GOOD           = 0b00000000,
};

///
/// @brief Bread crumb values to return
/// @note It is assumed that "worse" breadcrumb has a larger value
///
enum bread_crumb : uint8_t
{
    BREAD_CRUMB_ALL_GOOD = 0,
    FIRST_ATTEMPT        = 0x51,
    RECOVERY_ATTEMPTED   = 0x52,
    STILL_A_FAIL         = 0x53,
};

///
/// @brief PMIC pair uint8_t bitmap
///
enum pmic_pair : uint8_t
{
    PAIR0       = 0,
    PAIR1       = 1,
};

typedef fapi2::ReturnCode (*pmic_n_mode_detect_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::hwp_data_ostream&);

///
/// @brief Struct of telemetry data to populate from ADC
///
struct __attribute__((__packed__)) adc_telemetry
{
    uint8_t iv_event_low_flag = 0;

    uint8_t reserved0 = 0;

    // These are the MSB and LSB,
    // two combined 8 bit registers
    uint16_t iv_recent_ch0_mV = 0;
    uint16_t iv_recent_ch1_mV = 0;
    uint16_t iv_recent_ch2_mV = 0;
    uint16_t iv_recent_ch3_mV = 0;
    uint16_t iv_recent_ch4_mV = 0;
    uint16_t iv_recent_ch5_mV = 0;
    uint16_t iv_recent_ch6_mV = 0;
    uint16_t iv_recent_ch7_mV = 0;

    uint16_t iv_max_ch0_mV = 0;
    uint16_t iv_max_ch1_mV = 0;
    uint16_t iv_max_ch2_mV = 0;
    uint16_t iv_max_ch3_mV = 0;
    uint16_t iv_max_ch4_mV = 0;
    uint16_t iv_max_ch5_mV = 0;
    uint16_t iv_max_ch6_mV = 0;
    uint16_t iv_max_ch7_mV = 0;

    uint16_t iv_min_ch0_mV = 0;
    uint16_t iv_min_ch1_mV = 0;
    uint16_t iv_min_ch2_mV = 0;
    uint16_t iv_min_ch3_mV = 0;
    uint16_t iv_min_ch4_mV = 0;
    uint16_t iv_min_ch5_mV = 0;
    uint16_t iv_min_ch6_mV = 0;
    uint16_t iv_min_ch7_mV = 0;

    uint8_t iv_system_status = 0;
    uint8_t iv_auto_seq_ch_sel = 0;

    uint32_t reserved1 = 0;
};

///
/// @brief Struct of telemetry data to populate from PMICs
///
struct __attribute__((__packed__)) pmic_telemetry
{
    // Status register
    // Direct read from 8 bit register
    uint8_t iv_r08 = 0;
    uint8_t iv_r09 = 0;
    uint8_t iv_r0a = 0;
    uint8_t iv_r0b = 0;

    // Values in mA
    uint16_t iv_swa_current_mA = 0;
    uint16_t iv_swb_current_mA = 0;
    uint16_t iv_swc_current_mA = 0;
    uint16_t iv_swd_current_mA = 0;

    // Value in mV
    uint16_t iv_vin_bulk_mV = 0;

    // Temperature in C
    uint16_t iv_temp_c = 0;

    // Status register
    // Direct read from 8 bit register
    uint8_t iv_r33 = 0;

    uint8_t iv_r1b = 0;
    uint8_t iv_r2e = 0;
    uint8_t iv_r2f = 0;
    uint8_t iv_r32 = 0;
    uint8_t iv_r9c = 0;

    uint8_t iv_breadcrumb = 0;
    uint8_t reserved      = 0;
};

///
/// @brief Struct of telemetry data
///
struct __attribute__((__packed__)) telemetry_data
{
    uint8_t iv_gpio1_port_state = 0;
    uint8_t iv_gpio1_r01_efuse_output = 0;
    uint8_t iv_gpio1_r02_efuse_polarity = 0;
    uint8_t iv_gpio1_r03_configuration = 0;

    uint8_t iv_gpio2_port_state = 0;
    uint8_t iv_gpio2_r01_efuse_output = 0;
    uint8_t iv_gpio2_r02_efuse_polarity = 0;
    uint8_t iv_gpio2_r03_configuration = 0;

    pmic_telemetry iv_pmic1;
    pmic_telemetry iv_pmic2;
    pmic_telemetry iv_pmic3;
    pmic_telemetry iv_pmic4;

    adc_telemetry iv_adc1;
    adc_telemetry iv_adc2;
};

///
/// @brief Runtime N-Mode Detect / Telemetry Info to return to SBE
/// Revision history:
///     0x03: Added the following ADC, PMIC and GPIO regs to the structure:
///             ADC:  0x00, 0x12
///             PMIC: 0x1B, 0x2E, 0x2F, 0x32, 0x9C
///             GPIO: 0x01, 0x02, 0x03
///     0x04: ADC 0x00 and 0x12 regs read in revision 0x03 were using reg_read_reverse_buffer()
///             which made the regs print values in reverse. Changed the regs to be read using
///             reg_read()
///           For GPIO1 and GPIO2, iv_gpio1_port_state and iv_gpio2_port_state were getting the
///             values of iv_gpio1_r03_configuration and iv_gpio2_r03_configuration respectively.
///             Fixed that by assigning them the correct values
///     0x05: Added bread crumb and recovery procedure to the tool based on "Redundant Power
///             on DIMM – Functional Specification dated 01-20-2023"
///
struct __attribute__((__packed__)) runtime_n_mode_telem_info
{
    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision = 0x05;

    aggregate_state iv_aggregate_error = aggregate_state::N_PLUS_1;
    uint8_t iv_pmic1_errors = 0;
    uint8_t iv_pmic2_errors = 0;
    uint8_t iv_pmic3_errors = 0;
    uint8_t iv_pmic4_errors = 0;

    uint16_t reserved = 0;

    telemetry_data iv_telemetry_data;
};

///
/// @brief PMIC struct to emulate an "optional" type
///
struct pmic_info
{
    ///
    /// @brief Default ctor
    ///
    pmic_info() = default;

    ///
    /// @brief Construct a new pmic state object
    /// @param[in] i_pmic present PMIC target
    /// @param[in] i_state default ALL_GOOD else present PMIC state
    ///
    pmic_info(fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic, const uint8_t i_state = pmic_state::ALL_GOOD,
              const uint8_t i_rel_pos = mss::pmic::id::PMIC0) :
        iv_pmic(i_pmic),
        iv_state(i_state),
        iv_rel_pos(i_rel_pos)
    {}

    ///
    /// @brief Copy constructor
    /// @param[in] pmic_info struct
    ///
    pmic_info(const pmic_info& i_pmic_info) :
        iv_pmic(i_pmic_info.iv_pmic),
        iv_state(i_pmic_info.iv_state),
        iv_rel_pos(i_pmic_info.iv_rel_pos)
    {}

    fapi2::Target<fapi2::TARGET_TYPE_PMIC> iv_pmic;
    uint8_t iv_state = pmic_state::DECONFIGURED;
    uint8_t iv_rel_pos = 0;

    uint16_t reserved1 = 0;
};

///
/// @brief Struct type for pair
///
typedef struct
{
    uint8_t first;
    uint16_t* second;
} adu_map_t;


///
/// @brief Get the gpio data
///
/// @param[in] i_gpio1 GPIO1
/// @param[in] i_gpio2 GPIO2
/// @param[out] o_data data struct
///
void populate_gpio_data(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2,
    telemetry_data& o_data);

///
/// @brief Populate the pmic_data struct for the given pmic
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[out] o_pmic_data pmic_data struct
///
void populate_pmic_data(
    pmic_info& io_pmic,
    pmic_telemetry& o_pmic_data);

///
/// @brief Get the adc scale factor object
///
/// @param[in] i_adc_num ADC device enum (expected to be ADC1 or ADC2)
/// @param[in] i_adc_reg Register
/// @return double scale factor
///
uint32_t get_adc_scale_factor(const mss::generic_i2c_responder_ddr4 i_adc_num, const uint8_t i_adc_reg);

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
    adc_telemetry& o_adc_data);

///
/// @brief Write a register of a PMIC target, helper function for pmic_info type
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data Input  buffer
/// @return fapi2::ReturnCode
///
void reg_write(pmic_info& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Read a register of a PMIC target, helper function for pmic_info type
///
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
/// @return fapi2::ReturnCode
///
void reg_read(pmic_info& io_pmic, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_output);

///
/// @brief Check if we are 4U by pinging the GI2C targets
///
/// @param[in] i_ocmb_target OCMB target
/// @return true if 4U, false if not
///
bool is_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

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
                     fapi2::buffer<uint8_t>& io_reg);

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
                      const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2);

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
                       pmic_telemetry& io_pmic_tele_data);

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
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2);

///
/// @brief Get the gpio pmic state for each pair
///
/// @param[in,out] aggregate_state state according to validation check pass
/// @param[in] i_failed_pmics_1 bit map of failing pmics from GPIO1
/// @param[in] i_failed_pmics_2 bit map of failing pmics from GPIO2
///
template <pmic_pair PAIR>
void get_gpio_pmic_state( aggregate_state& io_output_state,
                          const fapi2::buffer<uint8_t>& i_failed_pmics_1,
                          const fapi2::buffer<uint8_t>& i_failed_pmics_2)
{
    // If GPIO itself failed then keep the state as is i.e. GI2C_I2C_FAIL
    if (io_output_state != GI2C_I2C_FAIL)
    {
        // 1 part dead == N_MODE, 2 == LOST
        if (i_failed_pmics_1.getBit<PAIR>() && i_failed_pmics_2.getBit<PAIR>())
        {
            io_output_state = LOST;
        }
    }
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
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2);

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
                           const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc2);

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
                          pmic_telemetry& io_pmic_data2);

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
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2);

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
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2);

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
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2);

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
                               const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_gpio2);

///
/// @brief Get the pmics object
///
/// @param[in] i_ocmb_target OCMB target
/// @return std::vector<pmic_info>
///
std::vector<pmic_info> get_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Send the runtime_n_mode_telem_info struct
///
/// @param[in] i_info runtime_n_mode_telem_info struct
/// @param[out] o_data hwp_data_ostream data stream
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode send_struct(runtime_n_mode_telem_info& i_info, fapi2::hwp_data_ostream& o_data);

///
/// @brief Get bread crumb reg value for individual PMIC
/// @param[in,out] io_pmic pmic_info class including target / state info
/// @param[out] o_pmic_data pmic_data struct
/// @return None
///
void get_bread_crumb_pmic(pmic_info& io_pmic,
                          pmic_telemetry& o_pmic_data);

///
/// @brief Get bread crumb reg value for all PMIC target
/// @param[in,out] vector of io_pmic pmic_info class including target / state info
/// @param[out] o_tele_data telemetry_data struct
/// @return bread_crumb value
///
bread_crumb get_bread_crumbs(std::vector<pmic_info>& io_pmics,
                             telemetry_data& o_tele_data);

///
/// @brief Check and reset bread crumb reg value if PMIC status is clean
/// @param[in,out] vector of io_pmic pmic_info class including target / state info
/// @param[in,out] io_tele_data telemetry_data struct
/// @return bread_crumb value
///
void check_and_reset_breadcrumb(std::vector<pmic_info>& io_pmics,
                                telemetry_data& io_tele_data);

extern "C"
{
    ///
    /// @brief Runtime N-Mode detection for 4U parts
    /// @param[in] i_ocmb_target ocmb target
    /// @param[out] o_data hwp_data_ostream of struct information
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode pmic_n_mode_detect(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        fapi2::hwp_data_ostream& o_data);
}
#endif
