/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/dt_trim_read_restart_ddr5.C $ */
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
/// @file dt_trim_read_restart_ddr5.C
/// @brief To be run when a DT is unreachable
///
// *HWP HWP Owner: David J. Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <dt_trim_read_restart_ddr5.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

///
/// @brief Trim read sequence to reset DT's
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode dt_trim_read_restart_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    using DT_REGS  = mss::dt::regs;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;

    fapi2::buffer<uint8_t> l_data_trim[NUM_BYTES_TO_WRITE];
    FAPI_INF(GENTARGTIDFORMAT " Running dt_trim_read_restart_ddr5 HWP", GENTARGTID(i_ocmb_target));

    // The Default DT i2c address is the same as the ADC's i2c address on ODY
    // For our case the ADC is unaffected by any of the commands needed for this sequence
    // DT restart seq via Trim Read

    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER> l_default_dt;
    const auto& l_adc = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>(i_ocmb_target);
    // If we are given < 1 ADC, exit now
    FAPI_ASSERT((l_adc.size() > mss::generic_i2c_responder::ADC),
                fapi2::INVALID_GI2C_DDR5_TARGET_CONFIG()
                .set_OCMB_TARGET(i_ocmb_target)
                .set_NUM_GI2CS(l_adc.size())
                .set_EXPECTED_GI2CS(mss::generic_i2c_responder::NUM_TOTAL_DEVICES_I2C_DDR5),
                GENTARGTIDFORMAT " dt_trim_read_restart requires %u ADC. "
                "Given %u ADC",
                GENTARGTID(i_ocmb_target),
                mss::generic_i2c_responder::NUM_TOTAL_DEVICES_I2C_DDR5,
                l_adc.size());
    l_default_dt = l_adc[mss::generic_i2c_responder::ADC];

    // Unlock Trim section
    FAPI_TRY(mss::pmic::i2c::reg_write_default_dt(l_default_dt, DT_REGS::TRIM_LOCK, trim_data::TRIM_UNLOCK));

    // Enter Password
    l_data_trim[0] = trim_data::TRIM_PASSWORD_1;
    l_data_trim[1] = trim_data::TRIM_PASSWORD_0;
    FAPI_TRY(mss::pmic::i2c::reg_write_default_dt_contiguous(l_default_dt, DT_REGS::TRIM_TRY_PASSWORD, l_data_trim));

    // Enable extendable read pulse
    l_data_trim[0] = trim_data::EXTENDABLE_RD_PULSE_EN_1;
    l_data_trim[1] = trim_data::EXTENDABLE_RD_PULSE_EN_0;
    FAPI_TRY(mss::pmic::i2c::reg_write_default_dt_contiguous(l_default_dt, DT_REGS::NVM_TRIM_RP_MAX, l_data_trim));

    // Initiate Trim read
    l_data_trim[0] = trim_data::TRIM_RD_INIT_1;
    l_data_trim[1] = trim_data::TRIM_RD_INIT_0;
    FAPI_TRY(mss::pmic::i2c::reg_write_default_dt_contiguous(l_default_dt, DT_REGS::NVM_COMMAND, l_data_trim));

    // Delay before locking trims
    fapi2::delay(5 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Lock Trim section for each DT
    for(const auto& l_dt : mss::find_targets<fapi2::TARGET_TYPE_POWER_IC>(i_ocmb_target))
    {
        FAPI_TRY(mss::pmic::i2c::reg_write(l_dt, DT_REGS::TRIM_LOCK, trim_data::TRIM_LOCK));
    }

    FAPI_INF(GENTARGTIDFORMAT " Finished dt_trim_read_restart_ddr5 HWP", GENTARGTID(i_ocmb_target));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
