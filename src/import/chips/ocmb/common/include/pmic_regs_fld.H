/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/include/pmic_regs_fld.H $        */
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
/// @file pmic_regs_fld.H
/// @brief PMIC Register Fields
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_REGS_FLD__
#define __PMIC_REGS_FLD__

#include <lib/utils/pmic_consts.H>

///
/// @brief Register fields for PMIC devices
/// @class pmicFields
/// @tparam P pmic_product
///
template<mss::pmic::product P>
struct pmicFields;

///
/// @brief Fields for TPS5383X PMICs
///
template<>
struct pmicFields<mss::pmic::product::TPS5383X>
{
    static constexpr uint8_t R9C_EN_VINUV_FLT_LATCH = 7;
};

///
/// @brief Fields for JEDEC_COMPLIANT PMICs
/// @note Unless otherwise specified, these are single bit positions whose numerical values
///       match those in the respective spec. For use with fapi2::buffer, the bit values will
///       be reversed.
///
template<>
struct pmicFields<mss::pmic::product::JEDEC_COMPLIANT>
{
    static constexpr uint8_t PMIC_DEVICE                    = 0;

    static constexpr uint8_t SWA_SWB_PHASE_MODE_SELECT      = 0;

    static constexpr uint8_t SWA_VOLTAGE_RANGE              = 5;
    static constexpr uint8_t SWB_VOLTAGE_RANGE              = 4;
    static constexpr uint8_t SWC_VOLTAGE_RANGE              = 3;
    static constexpr uint8_t SWD_VOLTAGE_RANGE              = 0;

    static constexpr uint8_t SEQUENCE_ENABLE                = 7;
    static constexpr uint8_t SEQUENCE_SWA_ENABLE            = 6;
    static constexpr uint8_t SEQUENCE_SWB_ENABLE            = 5;
    static constexpr uint8_t SEQUENCE_SWC_ENABLE            = 4;
    static constexpr uint8_t SEQUENCE_SWD_ENABLE            = 3;

    // R04
    static constexpr uint8_t R04_GLOBAL_ERROR_COUNT                     = 7;
    static constexpr uint8_t R04_GLOBAL_ERROR_LOG_BUCK_OV_OR_UV         = 6;
    static constexpr uint8_t R04_GLOBAL_ERROR_LOG_VIN_BULK_OVER_VOLTAGE = 5;
    static constexpr uint8_t R04_GLOBAL_ERROR_LOG_CRITICAL_TEMPERATURE  = 4;

    // R05
    static constexpr uint8_t R05_SWA_POWER_GOOD      = 6;
    static constexpr uint8_t R05_SWB_POWER_GOOD      = 5;
    static constexpr uint8_t R05_SWC_POWER_GOOD      = 4;
    static constexpr uint8_t R05_SWD_POWER_GOOD      = 3;
    static constexpr uint8_t R05_PMIC_ERROR_LOG      = 2; // TK ARRAY

    // R06
    static constexpr uint8_t R06_SWA_UNDER_VOLTAGE_LOCKOUT  = 7;
    static constexpr uint8_t R06_SWB_UNDER_VOLTAGE_LOCKOUT  = 6;
    static constexpr uint8_t R06_SWC_UNDER_VOLTAGE_LOCKOUT  = 5;
    static constexpr uint8_t R06_SWD_UNDER_VOLTAGE_LOCKOUT  = 4;
    static constexpr uint8_t R06_SWA_OVER_VOLTAGE           = 3;
    static constexpr uint8_t R06_SWB_OVER_VOLTAGE           = 2;
    static constexpr uint8_t R06_SWC_OVER_VOLTAGE           = 1;
    static constexpr uint8_t R06_SWD_OVER_VOLTAGE           = 0;

    // R07 all reserved

    // R08
    static constexpr uint8_t R08_VIN_BULK_INPUT_PWR_GOOD_STATUS = 7;
    static constexpr uint8_t R08_CRITICAL_TEMP_SHUTDOWN_STATUS  = 6;
    static constexpr uint8_t R08_SWA_PWR_GOOD_STATUS            = 5;
    static constexpr uint8_t R08_SWB_PWR_GOOD_STATUS            = 4;
    static constexpr uint8_t R08_SWC_PWR_GOOD_STATUS            = 3;
    static constexpr uint8_t R08_SWD_PWR_GOOD_STATUS            = 2;
    static constexpr uint8_t R08_VIN_MGMT_INPUT_OVER_VOLTAGE    = 1;
    static constexpr uint8_t R08_VIN_BULK_INPUT_OVER_VOLTAGE    = 0;

    // R09
    static constexpr uint8_t R09_PMIC_HIGH_TEMP_WARNING_STATUS                      = 7;
    static constexpr uint8_t R09_VBIAS_PWR_GOOD_STATUS                              = 6;
    static constexpr uint8_t R09_VOUT_1_8_V_PWR_GOOD_STATUS                         = 5;
    static constexpr uint8_t R09_VIN_MGMT_TO_VIN_BULK_SWITCHOVER_STATUS             = 4;
    static constexpr uint8_t R09_SWA_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 3;
    static constexpr uint8_t R09_SWB_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 2;
    static constexpr uint8_t R09_SWC_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 1;
    static constexpr uint8_t R09_SWD_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 0;

    // R0A
    static constexpr uint8_t R0A_SWA_OUTPUT_OVER_VOLTAGE_STATUS = 7;
    static constexpr uint8_t R0A_SWB_OUTPUT_OVER_VOLTAGE_STATUS = 6;
    static constexpr uint8_t R0A_SWC_OUTPUT_OVER_VOLTAGE_STATUS = 5;
    static constexpr uint8_t R0A_SWD_OUTPUT_OVER_VOLTAGE_STATUS = 4;
    static constexpr uint8_t R0A_PEC_ERROR_STATUS               = 3;
    static constexpr uint8_t R0A_PARITY_ERROR_STATUS            = 2;
    static constexpr uint8_t R0A_IBI_STATUS                     = 1; // 0x00 reserved

    // R0B
    static constexpr uint8_t R0B_SWA_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 7;
    static constexpr uint8_t R0B_SWB_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 6;
    static constexpr uint8_t R0B_SWC_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 5;
    static constexpr uint8_t R0B_SWD_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 4;
    static constexpr uint8_t R0B_SWA_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 3;
    static constexpr uint8_t R0B_SWB_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 2;
    static constexpr uint8_t R0B_SWC_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 1;
    static constexpr uint8_t R0B_SWD_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 0;

    // R14
    static constexpr uint8_t R14_GLOBAL_CLEAR_STATUS = 0;

    // R1A
    static constexpr uint8_t R1A_OUTPUT_POWER_SELECT = 1;
    static constexpr uint8_t R1A_VIN_BULK_POWER_GOOD_THRESHOLD_VOLTAGE_MASK = 0b11100000;

    // R1B
    static constexpr uint8_t R1B_CURRENT_OR_POWER_METER_SELECT = 6;

    // R1C/R1D/R1E/R1F - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t HIGH_CURRENT_WARNING_START          = 0;
    static constexpr uint8_t HIGH_CURRENT_WARNING_LENGTH         = 6;

    // R20 - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t R20_SWA_OUTPUT_CURRENT_LIMITER_WARNING_THRESHOLD_SETTING_START     = 0;
    static constexpr uint8_t R20_SWB_OUTPUT_CURRENT_LIMITER_WARNING_THRESHOLD_SETTING_START     = 2;
    static constexpr uint8_t R20_SWC_OUTPUT_CURRENT_LIMITER_WARNING_THRESHOLD_SETTING_START     = 4;
    static constexpr uint8_t R20_SWD_OUTPUT_CURRENT_LIMITER_WARNING_THRESHOLD_SETTING_START     = 6;
    static constexpr uint8_t R20_OUTPUT_CURRENT_LIMITER_WARNING_THRESHOLD_SETTING_LENGTH        = 2;

    // R22, R24, R26, R28 soft stop time field
    static constexpr uint8_t SOFT_STOP_TIME = 0;
    static constexpr uint8_t SOFT_STOP_TIME_LEN = 2;

    // R2B - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t R2B_LDO_1P8_VOLT_SETTING_START     = 0;
    static constexpr uint8_t R2B_LDO_1P8_VOLT_SETTING_LENGTH    = 2;
    static constexpr uint8_t R2B_LDO_1P1_VOLT_SETTING_START     = 5;
    static constexpr uint8_t R2B_LDO_1P1_VOLT_SETTING_LENGTH    = 2;

    // R2F
    static constexpr uint8_t R2F_SWA_REGULATOR_CONTROL = 6;
    static constexpr uint8_t R2F_SWB_REGULATOR_CONTROL = 5;
    static constexpr uint8_t R2F_SWC_REGULATOR_CONTROL = 4;
    static constexpr uint8_t R2F_SWD_REGULATOR_CONTROL = 3;
    static constexpr uint8_t R2F_SECURE_MODE           = 2;

    // R32
    static constexpr uint8_t R32_PWR_GOOD_IO_TYPE      = 5;
    static constexpr uint8_t R32_VR_ENABLE             = 7;

    // R3B
    static constexpr uint8_t R3B_PMIC_CURRENT_CAPABILITY = 0;

    // R4F
    static constexpr uint8_t R4F_SWA_SWB_PHASE_MODE_SELECT = 0;

    // R30 - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t R30_ADC_ENABLE        = 0;
    static constexpr uint8_t R30_ADC_SELECT_START  = 1;
    static constexpr uint8_t R30_ADC_SELECT_LENGTH = 4;

    // R31 - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t R31_ADC_READ_SETTING_START         = 0;
    static constexpr uint8_t R31_ADC_READ_SETTING_LENGTH        = 8;

    // R33 - bit positions flipped (0 is for bit7, 1 is for bit6, etc)
    static constexpr uint8_t R33_TEMPERATURE_SETTING_START      = 0;
    static constexpr uint8_t R33_TEMPERATURE_SETTING_LENGTH     = 3;

    static constexpr uint8_t DELAY_FLD_LENGTH               = 3;
    static constexpr uint8_t VOLTAGE_SETTING_START          = 0;
    static constexpr uint8_t VOLTAGE_SETTING_LENGTH         = 7;
};

#endif
