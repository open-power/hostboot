/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_types_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file pmic_common_types_ddr5.H
/// @brief Types common for several PMIC DDR5 procedures
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_COMMON_TYPES_DDR5_H__
#define __PMIC_COMMON_TYPES_DDR5_H__

#include "pmic_consts.H"
#include <stdint.h>

namespace mss
{
namespace pmic
{
namespace ddr5
{

using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

// Extra constants
static constexpr uint16_t CURRENT_MULTIPLIER = 125;
static constexpr uint16_t PHASE_MIN_MA = 250;
static constexpr uint16_t PHASE_MAX_MA = 1500;

///
/// @brief
///
enum data_position : uint8_t
{
    DATA_0   = 0,
    DATA_1   = 1,
    DATA_2   = 2,
    DATA_3   = 3,
    DATA_4   = 4,
    DATA_5   = 5,
    DATA_6   = 6,
    DATA_7   = 7,
    DATA_8   = 8,
    DATA_9   = 9,
    DATA_10  = 10,
    DATA_11  = 11,
    DATA_12  = 12,
    DATA_13  = 13,
    DATA_14  = 14,
    DATA_15  = 15,
};

///
/// @brief Trim read reset data
///
enum trim_rd_reset : uint16_t
{
    TRIM_UNLOCK            = 0x000E,
    TRIM_LOCK              = 0x000F,
    TRIM_RD_INIT           = 0x3F21,
    EXTENDABLE_RD_PULSE_EN = 0x4080,
    TRIM_PASSWORD          = 0xA55A,
};

///
/// @brief Bread crumb values to return
///
enum bread_crumb : uint8_t
{
    ALL_GOOD             = 0,
    FIRST_ATTEMPT        = 0x51,
    RECOVERY_ATTEMPTED   = 0x52,
    STILL_A_FAIL         = 0x53,
};

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
    PMIC_DECONFIGURED       = 0b10000000,
    PMIC_VIN_OK_Z           = 0b00010000,
    PMIC_NOT_PRESENT        = 0b00001000,
    PMIC_I2C_FAIL           = 0b00000100,
    PMIC_CURRENT_IMBALANCE  = 0b00000010,
    PMIC_PWR_NOT_GOOD       = 0b00000001,
    PMIC_ALL_GOOD           = 0b00000000,
};

///
/// @brief States for the dts to be returned in a uint8_t bitmap
///
enum dt_state : uint8_t
{
    DT_DECONFIGURED  = 0b10000000,
    DT_NOT_PRESENT   = 0b01000000,
    DT_I2C_FAIL      = 0b00100000,
    DT_SWIN_FAULT_D  = 0b00010000,
    DT_SWIN_FAULT_C  = 0b00001000,
    DT_SWIN_FAULT_B  = 0b00000100,
    DT_SWIN_FAULT_A  = 0b00000010,
    DT_GPI_1         = 0b00000001,
    DT_ALL_GOOD      = 0b00000000,
};

///
/// @brief States for the adc to be returned in a uint8_t bitmap
///
enum adc_state : uint8_t
{
    ADC_I2C_FAIL      = 0b00000001,
    ADC_ALL_GOOD      = 0b00000000,
};

///
/// @brief Struct of DT health check telemetry to populate
///
struct __attribute__((__packed__)) dt_health_check_telemetry
{
    // Run time Health check was returning N_MODE_POSSIBLE state after
    // host_set_mem_volt put the dimm into N_MODE. As per the flow,
    // once, dimm has been declared as n_mode, the only data reported
    // by health check should be aggregate state as N_MODE. But health
    // check was setting the state to be N_MODE_POSSIBLE and the dimm state
    // was not reaching N_MODE at all. It was stuck at N_MODE_POSSIBLE.
    // Hence setting the default state of breadcrumb to the max so that
    // comparison in check_breadcrumbs_subsequent_n_modes() will work
    uint8_t  iv_breadcrumb  = bread_crumb::STILL_A_FAIL;
    uint8_t  reserved0      = 0;
    uint16_t iv_ro_inputs_1 = 0;

    uint16_t iv_ro_inputs_0 = 0;
    uint16_t reserved1      = 0;
};

///
/// @brief Struct of PMIC health check telemetry to populate
///
struct __attribute__((__packed__)) pmic_health_check_telemetry
{
    // Error register
    // Direct read from 8 bit register
    uint8_t iv_r04 = 0;
    uint8_t iv_r05 = 0;
    uint8_t iv_r06 = 0;
    uint8_t iv_r07 = 0;

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

    uint8_t iv_r73_status_5    = 0;
    uint8_t reserved = 0;
    uint16_t reserved1 = 0;
};

///
/// @brief Struct of health check telemetry data
/// Revision history:
///     0x51: Initial revision supporting health check logic from
///           "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///           document provided by the Power team
///     0x52: Added ADC i2c error state to consolidated structure
///     0x53: Swapped reading of regs R96 and R98 with regs R92 and R94 in struct
///           dt_additional_n_mode_telemetry_data as reading R96 and R98 after R92 and
///           R94 was causing R96 and R98 regs to get cleared causing potential loss of
///           data.
///
struct __attribute__((__packed__)) health_check_telemetry_data
{
    aggregate_state iv_aggregate_state = aggregate_state::N_PLUS_1;

    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision = 0x53;
    uint16_t reserved   = 0;

    dt_health_check_telemetry iv_dt[CONSTS::NUM_DTS_4U];

    pmic_health_check_telemetry iv_pmic[CONSTS::NUM_PMICS_4U];
};

///
/// @brief Struct of adc data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) adc_additional_n_mode_telemetry_data
{
    uint8_t iv_system_status = 0;
    uint8_t iv_general_cfg   = 0;
    uint8_t iv_data_cfg      = 0;
    uint8_t iv_osr_cfg       = 0;

    uint8_t iv_opmode_cfg    = 0;
    uint8_t iv_pin_cfg       = 0;
    uint8_t iv_dummy_0       = 0;
    uint8_t iv_gpio_cfg      = 0;

    uint8_t iv_dummy_1       = 0;
    uint8_t iv_gpo_drive_cfg = 0;
    uint8_t iv_dummy_2       = 0;
    uint8_t iv_gpo_value_cfg = 0;

    uint8_t iv_dummy_3       = 0;
    uint8_t iv_gpi_value     = 0;
    uint8_t iv_dummy_4       = 0;
    uint8_t iv_dummy_5       = 0;
};

///
/// @brief Struct of pmic data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) pmic_additional_n_mode_telemetry_data
{
    uint8_t iv_r2f_pmic_config   = 0;
    uint8_t iv_r32_pmic_enable   = 0;
    uint8_t iv_r33_temp_status   = 0;
    uint8_t iv_r9c_on_off_config = 0;
};

///
/// @brief Struct of dt data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) dt_additional_n_mode_telemetry_data
{
    uint16_t iv_r90_ops_state              = 0;
    uint16_t iv_r96_first_faults_status_0  = 0;

    uint16_t iv_r98_first_faults_status_1  = 0;
    uint16_t iv_r92_faults_status_0        = 0;

    uint16_t iv_r94_faults_status_1        = 0;
    uint16_t iv_ra6_infet_mpt_addr         = 0;

    uint16_t iv_ra8_nvm_data               = 0;
    uint16_t iv_rb4_vcc_vin_vinp           = 0;
};

///
/// @brief Struct of additional health check telemetry data in case of n-mode
///
struct __attribute__ ((__packed__)) additional_n_mode_telemetry_data
{
    adc_additional_n_mode_telemetry_data iv_adc;

    pmic_additional_n_mode_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U];

    dt_additional_n_mode_telemetry_data iv_dt[CONSTS::NUM_DTS_4U];
};

///
/// @brief Struct of adc data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) adc_periodic_telemetry_data
{
    // These are the MSB and LSB,
    // two combined 8 bit registers
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

    uint16_t iv_recent_ch0_mV = 0;
    uint16_t iv_recent_ch1_mV = 0;
    uint16_t iv_recent_ch2_mV = 0;
    uint16_t iv_recent_ch3_mV = 0;
    uint16_t iv_recent_ch4_mV = 0;
    uint16_t iv_recent_ch5_mV = 0;
    uint16_t iv_recent_ch6_mV = 0;
    uint16_t iv_recent_ch7_mV = 0;
};

///
/// @brief Struct of pmic data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) pmic_periodic_telemetry_data
{
    // Status register
    // Direct read from 8 bit register
    uint8_t iv_r08 = 0;
    uint8_t iv_r09 = 0;
    uint8_t iv_r0a = 0;
    uint8_t iv_r0b = 0;

    // Values in mA
    uint16_t iv_swa_current_mA     = 0;
    uint16_t iv_swb_current_mA     = 0;
    uint16_t iv_swc_current_mA     = 0;
    uint16_t iv_swd_current_mA     = 0;

    uint16_t iv_r31_sample_vin     = 0;
    uint16_t iv_r31_sample_temp    = 0;

    uint8_t iv_r73_status_5       = 0;
    uint8_t iv_r7c_set_swa_offset = 0;
    uint8_t iv_r7d_set_swb_offset = 0;
    uint8_t iv_r7e_set_swc_offset = 0;

    uint8_t iv_r7f_set_swd_offset = 0;
    uint8_t reserved              = 0;
    uint16_t reserved1            = 0;
};

///
/// @brief Struct of dt data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) dt_periodic_telemetry_data
{
    uint16_t iv_r9a_iin  = 0;
    uint16_t iv_r9b_vcc  = 0;

    uint16_t iv_r9c_vinp = 0;
    uint16_t iv_r9d_vin  = 0;

    uint16_t iv_r9e_vaux_b = 0;
    uint16_t iv_r9f_vaux_a = 0;

    uint16_t iv_ra0_vaux_d = 0;
    uint16_t iv_ra1_vaux_c = 0;

    uint16_t iv_ra2_vinp_min = 0;
    uint16_t iv_ra3_vinp_max = 0;

    uint16_t iv_ra4_iin_min  = 0;
    uint16_t iv_ra5_iin_max  = 0;

    uint8_t iv_breadcrumb        = 0;
    uint8_t iv_recovery_count    = 0;
    uint8_t iv_neg_orfet_cnt_swa = 0;
    uint8_t iv_neg_orfet_cnt_swc = 0;

    uint8_t iv_neg_orfet_cnt_swd = 0;
    uint8_t iv_reserved0         = 0;
    uint16_t iv_reserved1        = 0;
};

///
/// @brief Struct of periodic telemetry data collected once every 24 hours
/// Revision history:
///     0x51: Initial revision supporting periodic data collection logic from
///           "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///           document provided by the Power team
///     0x52: Added aggregate PMIC state (byte 2) which is calculated by ORing
///           0x08-0x0B and 0x73 of all PMICs
///     0x53: Added PMIC/DT/ADC I2C fail logs. Each bit in iv_pmic_dt_i2c_state represents
///           a PMIC/DT target state. PMIC0 is bit0 .. PMIC3 is bit3, DT0 is bit4 .. DT3 is bit7
///           iv_adc_i2c_state represents ADC i2c state
///     0x54: Added DQS drift tracking data
///     0x55: Added DTS data
///
struct __attribute__ ((__packed__)) periodic_telemetry_data
{
    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision             = 0x55;
    uint8_t iv_aggregate_pmic_state = 0;
    uint16_t reserved               = 0;

    uint8_t iv_serial_number[26] = {0};
    uint8_t iv_pmic_dt_i2c_state = 0;
    uint8_t iv_adc_i2c_state     = 0;

    uint16_t iv_dqs_tracking_recal_count = 0;
    uint16_t reserved1                   = 0;

    uint64_t iv_dqs_tracking_log[24]     = {0};

    uint64_t iv_dts_data[5]              = {0};

    adc_periodic_telemetry_data iv_adc;

    pmic_periodic_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U];

    dt_periodic_telemetry_data iv_dt[CONSTS::NUM_DTS_4U];
};

///
/// @brief Struct of consolidated health check data which includes the following:
///        1. Health check
///        2. Additional data collected in case of n-mode detected
///        3. Periodic telemetry data in case of n-mode detected
///
struct __attribute__ ((__packed__)) consolidated_health_check_data
{
    health_check_telemetry_data iv_health_check;
    additional_n_mode_telemetry_data iv_additional_data;
    periodic_telemetry_data iv_periodic_telemetry_data;

    uint8_t iv_pmic0_errors = 0;
    uint8_t iv_pmic1_errors = 0;
    uint8_t iv_pmic2_errors = 0;
    uint8_t iv_pmic3_errors = 0;

    uint8_t iv_dt0_errors = 0;
    uint8_t iv_dt1_errors = 0;
    uint8_t iv_dt2_errors = 0;
    uint8_t iv_dt3_errors = 0;

    uint8_t iv_adc_errors = 0;
    uint8_t reserved      = 0;
    uint16_t reserved1    = 0;
};

///
/// @brief Struct of 2U pmic data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) pmic_periodic_2u_telemetry_data
{
    // Error register
    // Direct read from 8 bit register
    uint8_t iv_r04 = 0;
    uint8_t iv_r05 = 0;
    uint8_t iv_r06 = 0;
    uint8_t iv_r07 = 0;

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

    uint16_t iv_r31_sample_vin  = 0;
    uint16_t iv_r31_sample_temp = 0;

    uint8_t iv_r73_status_5     = 0;
    uint8_t reserved            = 0;
    uint16_t reserved1          = 0;
};

///
/// @brief Struct of 2U periodic telemetry data collected once every 24 hours
/// Revision history:
///     0x21: Initial revision supporting periodic data collection logic from
///       "Non-Redundant PoD5 - Functional Specification dated 20230818 version 0.03"
///       document provided by the Power team
///     0x22: Added aggregate PMIC state (byte 2) which is calculated by ORing
///           0x08-0x0B and 0x73 of all PMICs
///     0x23: Added PMIC I2C fail logs. Each bit in iv_pmic_i2c_state represents
///           a PMIC target state. PMIC0 is bit0 and PMIC1 is bit1
///     0x24: Added DQS drift tracking data
///     0x25: Added DTS data
///
struct __attribute__ ((__packed__)) periodic_2U_telemetry_data
{
    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision             = 0x25;
    uint8_t iv_aggregate_pmic_state = 0;
    uint16_t reserved               = 0;

    uint8_t iv_serial_number[26] = {0};
    uint8_t iv_pmic_i2c_state    = 0;
    uint8_t reserved0            = 0;

    uint16_t iv_dqs_tracking_recal_count = 0;
    uint16_t reserved1                   = 0;

    uint64_t iv_dqs_tracking_log[24]     = {0};

    uint64_t iv_dts_data[5]              = {0};

    pmic_periodic_2u_telemetry_data iv_pmic[CONSTS::NUM_PMICS_2U];
};


///
/// @brief Struct of data to be sent in case aggregate state is GI2C_FAIL
/// @note: The revision is set to 0 here as this revision will mimic health check
///        revision when called in health check HWP. The PMIC/DT/ADC errors and the
///        aggregate state will also reflect from the health check HWP. This sturcture
///        is just a place holder
///
struct __attribute__ ((__packed__)) gi2c_fail_state_data
{
    aggregate_state iv_aggregate_state = aggregate_state::N_PLUS_1;
    uint8_t iv_revision                = 0;
    uint8_t iv_pmic0_errors            = 0;
    uint8_t iv_pmic1_errors            = 0;

    uint8_t iv_pmic2_errors = 0;
    uint8_t iv_pmic3_errors = 0;
    uint8_t iv_dt0_errors   = 0;
    uint8_t iv_dt1_errors   = 0;

    uint8_t iv_dt2_errors   = 0;
    uint8_t iv_dt3_errors   = 0;
    uint8_t iv_adc_errors   = 0;
    uint8_t reserved0       = 0;
};

} // ddr5
} // pmic
} // mss

#endif
