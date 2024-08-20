/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_periodic_telemetry_utils_ddr5.H $ */
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
/// @file pmic_periodic_telemetry_utils_ddr5.H
/// @brief To be run periodically at runtime to collect telemetry data of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_PERIODIC_TELEMETRY_UTILS_DDR5_H__
#define __PMIC_PERIODIC_TELEMETRY_UTILS_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <hwp_data_stream.H>

// TODO: Zen:MST-2652 Enable DQS drift track in Metis
// Need to make this chip-op available in ZSBE
#ifndef __PPE__
    #include <ody_tsns_dqs_period.H>
#endif

typedef fapi2::ReturnCode (*pmic_periodic_telemetry_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::hwp_data_ostream&);

static constexpr uint8_t NUMBER_PMIC_REGS_READ_TELE = 8;

static constexpr uint8_t ADC_U16_MAP_LEN = 8;
static constexpr uint8_t NUM_BYTES_TO_READ = 16;
static constexpr uint8_t NUMBER_PMIC_2U_REGS_READ = 12;
static constexpr uint16_t ADC_VIN_BULK_STEP = 70;
static constexpr uint16_t ADC_TEMP_STEP = 2;

static constexpr uint8_t NUM_REG_TO_OR = 5;

static constexpr uint8_t NUM_BITS_IN_BYTE = 8;

///
/// @brief Read and store serial number and CCIN number
///
/// @param[in] i_ocmb_target OCMB target info struct
/// @param[in,out] io_serial_number serial number array
/// @return None
///
void read_serial_ccin_number(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                             uint8_t io_serial_number[]);

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N (scom access) or mss::states::OFF_N (training access)
/// @param[in] i_runtime true if running at runtime, meaning the UCCLK needs to be switched on/off (default: false)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.C since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
inline fapi2::ReturnCode configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state,
        const bool i_runtime)
{
    static const uint64_t DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL = 0x800D00000801303Full;
    static const uint32_t DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL = 63;
    static const uint64_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES = 0x800C00800801303Full;
    static const uint32_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN = 63;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

    l_data.writeBit<DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);
    FAPI_TRY(fapi2::putScom(i_target, DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

    // Turn UCCLK on/off if at runtime
    if (i_runtime)
    {
        FAPI_TRY(fapi2::getScom(i_target, DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES, l_data));

        if (i_state == mss::states::ON_N)
        {
            l_data.setBit<DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN>();
        }
        else
        {
            l_data.clearBit<DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN>();
        }

        FAPI_TRY(fapi2::putScom(i_target, DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Suspend DQS drift track and poll MCBIST until it's done executing
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.H since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
inline fapi2::ReturnCode suspend_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_thermal_init_complete = 0;
    uint32_t l_tsns_period_ms = 0;
    uint8_t l_dqs_period = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_THERMAL_INIT_COMPLETE,
                           i_target,
                           l_thermal_init_complete));

    // Do not send the chip-op if we haven't yet run mss_thermal_init
    if (l_thermal_init_complete == fapi2::ENUM_ATTR_MEM_THERMAL_INIT_COMPLETE_NO)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT,
                           i_target,
                           l_tsns_period_ms));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_PERIOD_INIT,
                           i_target,
                           l_dqs_period));

// TODO: Zen:MST-2652 Enable DQS drift track in Metis
// Need to make this chip-op available in ZSBE
#ifndef __PPE__
    FAPI_EXEC_HWP(l_rc,
                  ody_tsns_dqs_period,
                  i_target,
                  l_tsns_period_ms,
                  0);
    FAPI_TRY(l_rc);
#endif

    // Wait for few polling cycles to ensure any currently-running recal is complete
    // Found this delay via experimentation. This value had the best chance of avoiding contention
    fapi2::delay((l_tsns_period_ms * l_dqs_period * mss::DELAY_1MS) / 2, 200);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resume DQS drift track
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.H since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
inline fapi2::ReturnCode resume_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_thermal_init_complete = 0;
    uint32_t l_tsns_period_ms = 0;
    uint8_t l_dqs_period = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_THERMAL_INIT_COMPLETE,
                           i_target,
                           l_thermal_init_complete));

    // Do not send the chip-op if we haven't yet run mss_thermal_init
    if (l_thermal_init_complete == fapi2::ENUM_ATTR_MEM_THERMAL_INIT_COMPLETE_NO)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT,
                           i_target,
                           l_tsns_period_ms));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_PERIOD_INIT,
                           i_target,
                           l_dqs_period));

// TODO: Zen:MST-2652 Enable DQS drift track in Metis
// Need to make this chip-op available in ZSBE
#ifndef __PPE__
    FAPI_EXEC_HWP(l_rc,
                  ody_tsns_dqs_period,
                  i_target,
                  l_tsns_period_ms,
                  l_dqs_period);
    FAPI_TRY(l_rc);
#endif

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read and store DQS drift tracking data
///
/// @param[in] i_ocmb_target OCMB target info struct
/// @param[in,out] io_dqs_tracking_log DQS drift track log array
/// @return DQS tracking recal count
///
uint16_t read_dqs_drift_tracking_log(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                     uint64_t io_dqs_tracking_log[]);

///
/// @brief Scale the ADC regs (value * 38147) / 1000000 to get the value in mV
///
/// @param[in,out] io_adc_fill_array scaled values to be written to
/// @param[in] i_data_buffer read ADC values
/// None
///
void scale_adc_readings(uint16_t* (&io_adc_fill_array)[ADC_U16_MAP_LEN],
                        const fapi2::buffer<uint8_t> (&i_data_buffer)[NUM_BYTES_TO_READ]);

///
/// @brief Read and store ADC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_adc_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                   mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

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
                        fapi2::buffer<uint8_t>& io_data_buffer);
///
/// @brief Scale DT VAUX regs
///
/// @param[in] i_reg_value reg DT VAUX raw value
/// @param[in] i_scaling_factor scaling factor from reg 0x62 of DT
/// None
///
uint16_t scale_dt_vaux_regs(const uint8_t& i_reg_value,
                            const uint8_t& i_scaling_factor);

///
/// @brief Read and neg orfet value
///
/// @param[in,out] io_pmic_dt_pair PMIC and DT target info struct
/// @param[in,out] io_periodic_dt_tele_info DT struct
/// None
///
void read_store_vaux_values(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_pair,
                            mss::pmic::ddr5::dt_periodic_telemetry_data& io_periodic_dt_tele_info);

///
/// @brief Read and store DT regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store PMIC regs
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Set ADC/PMIC/DT I2C error states if any
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// None
///
void set_i2c_error_states(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                          mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store ADC/PMIC/DT
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_periodic_tele_info periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode collect_periodic_tele_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

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
                              fapi2::hwp_data_ostream& o_data);

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
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info);

///
/// @brief Read and store PMIC data
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_info 2U periodic telemetry struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode collect_periodic_tele_data_2U(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::periodic_2U_telemetry_data& io_info);

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
        mss::pmic::ddr5::periodic_2U_telemetry_data& io_info);

#endif
