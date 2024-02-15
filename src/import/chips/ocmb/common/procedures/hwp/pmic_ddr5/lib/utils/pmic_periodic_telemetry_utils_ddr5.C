/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_periodic_telemetry_utils_ddr5.C $ */
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
/// @file pmic_periodic_telemetry_utils_ddr5.C
/// @brief To be run periodically at runtime to collect telemetry data of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

///
/// @brief Read and store serial number and CCIN number
///
/// @param[in] i_ocmb_target OCMB target info struct
/// @param[in,out] io_serial_number serail number array
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
void read_serial_ccin_number(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                             uint8_t io_serial_number[])
{
    uint8_t l_serial_number[26] = {0};

    FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_SERIAL_NUMBER, i_ocmb_target, l_serial_number);

    memcpy(io_serial_number, l_serial_number, sizeof(l_serial_number));
}

///
/// @brief Scale the ADC regs (value * 38147) / 1000000 to get the value in mV
///
/// @param[in,out] io_adc_fill_array scaled values to be written to
/// @param[in] i_data_buffer read ADC values
/// None
///
void scale_adc_readings(uint16_t* (&io_adc_fill_array)[ADC_U16_MAP_LEN],
                        const fapi2::buffer<uint8_t> (&i_data_buffer)[NUM_BYTES_TO_READ])
{
    static constexpr uint32_t ADC_LSB_nV = 38147;
    static constexpr uint64_t TO_MV = 1000000;
    static constexpr uint8_t REG_SIZE_BITS = 8;
    static constexpr uint8_t INCREMENT_BYTES_BUFFER = 2;

    uint8_t l_reg_count = 0;

    // Set each one
    for (const auto& l_adc_fill_array : io_adc_fill_array)
    {
        uint16_t l_channel_field = 0;
        constexpr uint8_t REG_MSB_OFFSET = 1;

        // MSB then LSB
        i_data_buffer[l_reg_count + REG_MSB_OFFSET].extract<0, REG_SIZE_BITS, 0>(l_channel_field);
        i_data_buffer[l_reg_count].extract<0, REG_SIZE_BITS, REG_SIZE_BITS>(l_channel_field);

        // scale
        const uint64_t l_field_unscaled = l_channel_field * ADC_LSB_nV;
        (*l_adc_fill_array) = static_cast<uint16_t>(l_field_unscaled / TO_MV);

        l_reg_count += INCREMENT_BYTES_BUFFER;
    }
}

///
/// @brief Read and store ADC regs
///
/// @param[in,out] io_target_info PMIC, DT and ADC target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_adc_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                   mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    FAPI_INF(GENTARGTIDFORMAT " Populating ADC data", GENTARGTID(io_target_info.iv_adc));

    fapi2::buffer<uint8_t> l_reg_contents[NUM_BYTES_TO_READ] = {0};

    mss::pmic::i2c::reg_read_reverse_buffer(io_target_info.iv_adc, mss::adc::regs::GENERAL_CFG,
                                            l_reg_contents[mss::pmic::ddr5::data_position::DATA_0]);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    l_reg_contents[mss::pmic::ddr5::data_position::DATA_0].clearBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(io_target_info.iv_adc, mss::adc::regs::GENERAL_CFG,
            l_reg_contents[mss::pmic::ddr5::data_position::DATA_0]);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Fields that map a LSB register to the uint16_t destination in io_periodic_tele_info.iv_adc.
    uint16_t* l_adc_fill_array_max[ADC_U16_MAP_LEN] =
    {
        &io_periodic_tele_info.iv_adc.iv_max_ch0_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch1_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch2_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch3_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch4_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch5_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch6_mV,
        &io_periodic_tele_info.iv_adc.iv_max_ch7_mV
    };
    // First read the LSB reg. Then the MSB reg is the next one
    mss::pmic::i2c::reg_read_contiguous(io_target_info.iv_adc, mss::adc::regs::MAX_CH0_LSB, l_reg_contents);
    scale_adc_readings(l_adc_fill_array_max, l_reg_contents);

    uint16_t* l_adc_fill_array_min[ADC_U16_MAP_LEN] =
    {
        &io_periodic_tele_info.iv_adc.iv_min_ch0_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch1_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch2_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch3_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch4_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch5_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch6_mV,
        &io_periodic_tele_info.iv_adc.iv_min_ch7_mV
    };
    // First read the LSB reg. Then the MSB reg is the next one
    mss::pmic::i2c::reg_read_contiguous(io_target_info.iv_adc, mss::adc::regs::MIN_CH0_LSB, l_reg_contents);
    scale_adc_readings(l_adc_fill_array_min, l_reg_contents);

    uint16_t* l_adc_fill_array_recent[ADC_U16_MAP_LEN] =
    {
        &io_periodic_tele_info.iv_adc.iv_recent_ch0_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch1_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch2_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch3_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch4_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch5_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch6_mV,
        &io_periodic_tele_info.iv_adc.iv_recent_ch7_mV
    };
    // First read the LSB reg. Then the MSB reg is the next one
    mss::pmic::i2c::reg_read_contiguous(io_target_info.iv_adc, mss::adc::regs::RECENT_CH0_LSB, l_reg_contents);
    scale_adc_readings(l_adc_fill_array_recent, l_reg_contents);

    mss::pmic::i2c::reg_read_reverse_buffer(io_target_info.iv_adc, mss::adc::regs::GENERAL_CFG,
                                            l_reg_contents[mss::pmic::ddr5::data_position::DATA_0]);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    l_reg_contents[mss::pmic::ddr5::data_position::DATA_0].setBit<mss::adc::fields::GENERAL_CFG_STATUS_ENABLE>();
    mss::pmic::i2c::reg_write_reverse_buffer(io_target_info.iv_adc, mss::adc::regs::GENERAL_CFG,
            l_reg_contents[mss::pmic::ddr5::data_position::DATA_0]);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return;
}

///
/// @brief Scale DT VAUX regs
///
/// @param[in] i_reg_value reg DT VAUX raw value
/// @param[in] i_scaling_factor scaling factor from reg 0x62 of DT
/// None
///
uint16_t scale_dt_vaux_regs(const uint8_t& i_reg_value,
                            const uint8_t& i_scaling_factor)
{
    static constexpr uint16_t TO_MV = 10000;
    static constexpr uint64_t TO_1200_MV = 78125;
    static constexpr uint64_t TO_2400_MV = 156250;
    static constexpr uint64_t TO_3600_MV = 208330;
    static constexpr uint64_t TO_4800_MV = 312500;
    static constexpr uint8_t SCALE_1200_MV = 0x00;
    static constexpr uint8_t SCALE_2400_MV = 0x01;
    static constexpr uint8_t SCALE_3600_MV = 0x02;
    static constexpr uint8_t SCALE_4800_MV = 0x03;
    uint64_t l_scaling_factor = 0;
    uint16_t l_scaled_value = 0;

    switch(i_scaling_factor)
    {
        case SCALE_1200_MV:
            l_scaling_factor = TO_1200_MV;
            break;

        case SCALE_2400_MV:
            l_scaling_factor = TO_2400_MV;
            break;

        case SCALE_3600_MV:
            l_scaling_factor = TO_3600_MV;
            break;

        case SCALE_4800_MV:
            l_scaling_factor = TO_4800_MV;
            break;
    }

    return l_scaled_value = static_cast<uint16_t>((i_reg_value * l_scaling_factor) / TO_MV);
}

///
/// @brief Read and store neg orfet value
///
/// @param[in,out] io_pmic_dt_pair PMIC and DT target info struct
/// @param[in] i_reg_sel reg selection
/// @param[in,out] read data
/// None
///
void read_neg_orfet_cnt(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_pair,
                        const uint8_t i_reg_sel,
                        fapi2::buffer<uint8_t>& io_data_buffer)
{
    using DT_REGS  = mss::dt::regs;
    fapi2::buffer<uint8_t> l_dt_buffer = 0;

    mss::pmic::ddr5::dt_reg_write(io_pmic_dt_pair, DT_REGS::OR_FET_CNT_SEL, i_reg_sel);
    mss::pmic::ddr5::dt_reg_read(io_pmic_dt_pair, DT_REGS::NEG_ORFET_CNT, io_data_buffer);
}

///
/// @brief Read and neg orfet value
///
/// @param[in,out] io_pmic_dt_pair PMIC and DT target info struct
/// @param[in,out] io_periodic_dt_tele_info DT struct
/// None
///
void read_store_vaux_values(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_pair,
                            mss::pmic::ddr5::dt_periodic_telemetry_data& io_periodic_dt_tele_info)
{
    using DT_REGS = mss::dt::regs;
    using FIELDS = mss::dt::fields;
    static constexpr uint8_t NUM_BYTES_TO_READ = 2;
    fapi2::buffer<uint8_t> l_dt_buffer[NUM_BYTES_TO_READ];
    fapi2::buffer<uint8_t> l_vaux_a_scaler = 0;
    fapi2::buffer<uint8_t> l_vaux_b_scaler = 0;
    fapi2::buffer<uint8_t> l_vaux_c_scaler = 0;
    fapi2::buffer<uint8_t> l_vaux_d_scaler = 0;

    // VAUX A/B/C/D regs have to be scaled wrt 0x62 reg values. Below logic deciphers 0x62 values and scales accordingly
    mss::pmic::ddr5::dt_reg_read(io_pmic_dt_pair, DT_REGS::VAUX_RANGE, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
    l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0].extractToRight<FIELDS::VAUX_A_SCALER_POSITION, FIELDS::VAUX_SCALER_LENGTH>
    (l_vaux_a_scaler);
    l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0].extractToRight<FIELDS::VAUX_B_SCALER_POSITION, FIELDS::VAUX_SCALER_LENGTH>
    (l_vaux_b_scaler);
    l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0].extractToRight<FIELDS::VAUX_C_SCALER_POSITION, FIELDS::VAUX_SCALER_LENGTH>
    (l_vaux_c_scaler);
    l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0].extractToRight<FIELDS::VAUX_D_SCALER_POSITION, FIELDS::VAUX_SCALER_LENGTH>
    (l_vaux_d_scaler);

    // Scale VAUX wrt to 0x62
    mss::pmic::ddr5::dt_reg_read_contiguous(io_pmic_dt_pair, DT_REGS::VUAX_B_A, l_dt_buffer);
    io_periodic_dt_tele_info.iv_r9e_vaux_b = scale_dt_vaux_regs(l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0],
            l_vaux_b_scaler);
    io_periodic_dt_tele_info.iv_r9f_vaux_a = scale_dt_vaux_regs(l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1],
            l_vaux_a_scaler);

    mss::pmic::ddr5::dt_reg_read_contiguous(io_pmic_dt_pair, DT_REGS::VUAX_D_C, l_dt_buffer);
    io_periodic_dt_tele_info.iv_ra0_vaux_d = scale_dt_vaux_regs(l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0],
            l_vaux_d_scaler);
    io_periodic_dt_tele_info.iv_ra1_vaux_c = scale_dt_vaux_regs(l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1],
            l_vaux_c_scaler);
}
///
/// @brief Read and store DT regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    using DT_REGS  = mss::dt::regs;
    static constexpr uint8_t NUM_BYTES_TO_READ = 2;

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the corresponding PMIC in the PMIC/DT pair is not overridden to disabled, run the enable
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, &io_periodic_tele_info, l_dt_count]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            static constexpr uint8_t SEL_SWA_ORFET_CNT = 0x00;
            static constexpr uint8_t SEL_SWC_ORFET_CNT = 0x10;
            static constexpr uint8_t SEL_SWD_ORFET_CNT = 0x18;
            static constexpr uint32_t VOLT_SCALE = 31250;
            static constexpr uint32_t VIN_VINP_SCALE = 62500;
            static constexpr uint64_t TO_MV = 1000;
            fapi2::buffer<uint8_t> l_dt_buffer[NUM_BYTES_TO_READ];

            FAPI_INF(GENTARGTIDFORMAT " Populating DT data", GENTARGTID(io_target_info.iv_pmic_dt_map[l_dt_count].iv_dt));

            // IIN scale = (value * 31250) / 1000
            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::IIN_VCC, l_dt_buffer);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_r9a_iin = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0] * VOLT_SCALE) / TO_MV);
            // VCC scale = (value * 31250) / 1000
            io_periodic_tele_info.iv_dt[l_dt_count].iv_r9b_vcc = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1] * VOLT_SCALE) / TO_MV);

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::VINP_VIN, l_dt_buffer);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_r9c_vinp = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0] * VIN_VINP_SCALE) / TO_MV);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_r9d_vin = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1] * VIN_VINP_SCALE) / TO_MV);

            read_store_vaux_values(io_target_info.iv_pmic_dt_map[l_dt_count], io_periodic_tele_info.iv_dt[l_dt_count]);

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::VINP_MIN_MAX, l_dt_buffer);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_ra2_vinp_min = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0] * VIN_VINP_SCALE) / TO_MV);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_ra3_vinp_max = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1] * VIN_VINP_SCALE) / TO_MV);

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::IIN_MIN_MAX, l_dt_buffer);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_ra4_iin_min = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0] * VOLT_SCALE) / TO_MV);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_ra5_iin_max = static_cast<uint16_t>((l_dt_buffer[mss::pmic::ddr5::data_position::DATA_1] * VOLT_SCALE) / TO_MV);

            mss::pmic::ddr5::dt_reg_read(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::BREADCRUMB, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_breadcrumb = l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0];

            mss::pmic::ddr5::dt_reg_read(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::RECOVERY_COUNT, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_recovery_count = l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0];

            // Read neg orfet cnt for SWA
            read_neg_orfet_cnt(io_target_info.iv_pmic_dt_map[l_dt_count], SEL_SWA_ORFET_CNT, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_neg_orfet_cnt_swa = l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0];

            // We don't use SWB here (except in current readings)
            // Read neg orfet cnt for SWA
            read_neg_orfet_cnt(io_target_info.iv_pmic_dt_map[l_dt_count], SEL_SWC_ORFET_CNT, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_neg_orfet_cnt_swc = l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0];

            // Read neg orfet cnt for SWA
            read_neg_orfet_cnt(io_target_info.iv_pmic_dt_map[l_dt_count], SEL_SWD_ORFET_CNT, l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_dt[l_dt_count].iv_neg_orfet_cnt_swd = l_dt_buffer[mss::pmic::ddr5::data_position::DATA_0];

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Read and store PMIC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    for (auto l_pmic_count = 0; l_pmic_count < io_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present(io_target_info, l_pmic_count, [&io_target_info, l_pmic_count, &io_periodic_tele_info]
                                        (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
            using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
            fapi2::buffer<uint8_t> l_data_buffer[NUMBER_PMIC_REGS_READ_TELE];

            FAPI_INF(GENTARGTIDFORMAT " Populating PMIC data", GENTARGTID(io_target_info.iv_pmic_dt_map[l_pmic_count].iv_pmic));

            // Read SWA/B/C/D
            mss::pmic::ddr5::pmic_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R0C, l_data_buffer);
            // Convert raw value
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_swa_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_0] * mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_swb_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_1] * mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_swc_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_2] * mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_swd_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_3] * mss::pmic::ddr5::CURRENT_MULTIPLIER;

            // Set PMIC internal ADC to sample VIN
            mss::pmic::ddr5::pmic_reg_read_reverse_buffer(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R30, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<6>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<5>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<4>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<3>();
            mss::pmic::ddr5::pmic_reg_write_reverse_buffer(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R30, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            // VIN
            mss::pmic::ddr5::pmic_reg_read(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R31, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r31_sample_vin = static_cast<uint16_t>(l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]()) * ADC_VIN_BULK_STEP;

            // Set PMIC internal ADC to sample temp
            mss::pmic::ddr5::pmic_reg_read_reverse_buffer(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R30, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<6>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<5>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<4>();
            l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<3>();
            mss::pmic::ddr5::pmic_reg_write_reverse_buffer(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R30, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            // Temp
            mss::pmic::ddr5::pmic_reg_read(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R31, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r31_sample_temp = static_cast<uint16_t>(l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]()) * ADC_TEMP_STEP;

            // Read SWA/B/C/D offsets
            mss::pmic::ddr5::pmic_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_pmic_count], TPS_REGS::R7C_SET_SWA_OFFSET, l_data_buffer);
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r7c_set_swa_offset = l_data_buffer[mss::pmic::ddr5::data_position::DATA_0];
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r7d_set_swb_offset = l_data_buffer[mss::pmic::ddr5::data_position::DATA_1];
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r7e_set_swc_offset = l_data_buffer[mss::pmic::ddr5::data_position::DATA_2];
            io_periodic_tele_info.iv_pmic[l_pmic_count].iv_r7f_set_swd_offset = l_data_buffer[mss::pmic::ddr5::data_position::DATA_3];

            // GLOBAL_CLEAR_STATUS
            mss::pmic::ddr5::pmic_reg_write(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R14, 0x01);

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Read and store ADC/PMIC/DT
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void collect_periodic_tele_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    // Read and store serial number and CCIN number
    read_serial_ccin_number(io_target_info.iv_ocmb, io_periodic_tele_info.iv_serial_number);

    // Read and store ADC regs
    read_adc_regs(io_target_info, io_periodic_tele_info);

    // Read and store DT regs
    read_dt_regs(io_target_info, io_periodic_tele_info);

    // Read and store PMIC regs
    read_pmic_regs(io_target_info, io_periodic_tele_info);
}

///
/// @brief Send the periodic_telemetry_data struct
///
/// @param[in] i_info periodic telemetry struct
/// @param[in] i_size size of telemetry struct
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode send_struct(const uint8_t* i_info,
                              const uint16_t i_size,
                              fapi2::hwp_data_ostream& o_data)
{
    // Loop through in increments of hwp_data_unit size (currently uint32_t)
    // Until we have copied the entire structure
    for (uint16_t l_byte = 0; l_byte < i_size; l_byte += sizeof(fapi2::hwp_data_unit))
    {
        fapi2::hwp_data_unit l_data_unit = 0;

        // The number of bytes to copy is either always 4 (size of hwp_data_unit),
        // OR less if we have fewer than 4 bytes left in the struct, in which case we copy
        // that amount.
        const size_t l_bytes_to_copy = std::min(sizeof(fapi2::hwp_data_unit), static_cast<size_t>(i_size - l_byte));

        memcpy(&l_data_unit, i_info + l_byte, l_bytes_to_copy);
        FAPI_TRY(o_data.put(l_data_unit));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Runtime periodic telemetry data collection helper for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_periodic_telemetry_ddr5_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info)
{
    mss::pmic::ddr5::aggregate_state l_aggregate_state_not_used = mss::pmic::ddr5::aggregate_state::N_PLUS_1;

    // Check for all the asserts (correct PMIC/DT pair received, DIMM is 4U)
    FAPI_TRY(health_check_tele_tool_assert_helper(i_ocmb_target,
             io_target_info,
             l_aggregate_state_not_used));

    // Read and store ADC/DT/PMIC regs
    collect_periodic_tele_data(io_target_info, io_periodic_tele_info);

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__
///
/// @brief Read and store PMIC data
///
/// @param[in] i_pmic_target PMIC target
/// @param[in,out] io_info 2U periodic telemetry struct
/// None
///
fapi2::ReturnCode collect_periodic_tele_data_2U(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
        mss::pmic::ddr5::pmic_periodic_2u_telemetry_data& io_info)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_data_buffer[NUMBER_PMIC_2U_REGS_READ];

    FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(i_pmic_target, REGS::R04, l_data_buffer));

    io_info.iv_r04 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_0];
    io_info.iv_r05 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_1];
    io_info.iv_r06 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_2];
    io_info.iv_r07 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_3];
    io_info.iv_r08 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_4];
    io_info.iv_r09 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_5];
    io_info.iv_r0a = l_data_buffer[mss::pmic::ddr5::data_position::DATA_6];
    io_info.iv_r0b = l_data_buffer[mss::pmic::ddr5::data_position::DATA_7];
    io_info.iv_swa_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_8] *
                                mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_info.iv_swb_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_9] *
                                mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_info.iv_swc_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_10] *
                                mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_info.iv_swd_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_11] *
                                mss::pmic::ddr5::CURRENT_MULTIPLIER;

    // Set PMIC internal ADC to sample VIN
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R30,
             l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<6>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<5>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<4>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<3>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R30,
             l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));

    // Delay
    fapi2::delay(2 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // VIN
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));
    io_info.iv_r31_sample_vin = static_cast<uint16_t>(l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]()) *
                                ADC_VIN_BULK_STEP;

    // Set PMIC internal ADC to sample temp
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R30,
             l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<6>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<5>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].setBit<4>();
    l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].clearBit<3>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R30,
             l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));

    // Delay
    fapi2::delay(2 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Temp
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R31, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]));
    io_info.iv_r31_sample_temp = static_cast<uint16_t>(l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]()) *
                                 ADC_TEMP_STEP;

    // GLOBAL_CLEAR_STATUS
    FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, REGS::R14, 0x01));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Runtime periodic telemetry data collection helper for 2U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_periodic_telemetry_ddr5_2U_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_ocmb_target,
        mss::pmic::ddr5::periodic_2U_telemetry_data& io_info)
{
    fapi2::buffer<uint8_t> l_pmic_buffer;

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

    read_serial_ccin_number(i_ocmb_target, io_info.iv_serial_number);

    for (const auto& l_pmic : l_pmics)
    {
        // PMIC position/ID under OCMB target
        uint8_t l_relative_pmic_id = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmic, l_relative_pmic_id));

        collect_periodic_tele_data_2U(l_pmic, io_info.iv_pmic[l_relative_pmic_id]);
    }

fapi_try_exit:
    return fapi2::current_err;
}
#endif
