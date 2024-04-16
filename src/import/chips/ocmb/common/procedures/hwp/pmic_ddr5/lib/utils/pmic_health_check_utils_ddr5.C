/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_health_check_utils_ddr5.C $ */
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
/// @file pmic_health_check_utils_ddr5.C
/// @brief To be run periodically at runtime to determine health of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/utils/pmic_health_check_utils_ddr5.H>
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <mss_generic_attribute_getters.H>

///
/// @brief Reset bread crumbs for all PMICs
///
/// @param[in,out] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                      mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using DT_REGS  = mss::dt::regs;

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, l_dt_count]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            // Clear breadcrumb reg
            mss::pmic::ddr5::dt_reg_write(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::ALL_GOOD);
            return fapi2::FAPI2_RC_SUCCESS;
        });

        // Resetting the struct bread crumb variable
        io_health_check_info.iv_dt[l_dt_count].iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    }
}

///
/// @brief Attempt recovery for a specific DT/PMIC pair
///
/// @param[in,out] io_pmic_dt_target_info PMIC and DT target info struct
/// @return None
///
void attempt_recovery(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_target_info)
{
    using DT_REGS  = mss::dt::regs;
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;
    fapi2::buffer<uint8_t> l_dt_data_to_write[NUM_BYTES_TO_WRITE];
    fapi2::buffer<uint8_t> l_pmic_buffer;
    fapi2::buffer<uint8_t> l_data_recovery_count;
    // Disable efuse
    mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::EN_REGISTER, 0x00);

    // Delay for 100 ms. Less delay is affecting recovery procedure for current imbalance
    // This amount should be ok as the recovery will rarely be used
    fapi2::delay(100 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Clear faults 0 reg
    l_dt_data_to_write[0] = 0xFF;
    l_dt_data_to_write[1] = 0xFF;
    mss::pmic::ddr5::dt_reg_write_contiguous(io_pmic_dt_target_info, DT_REGS::FAULTS_CLEAR_0, l_dt_data_to_write);

    // Clear faults 1 reg
    l_dt_data_to_write[0] = 0xFF;
    l_dt_data_to_write[1] = 0xFF;
    mss::pmic::ddr5::dt_reg_write_contiguous(io_pmic_dt_target_info, DT_REGS::FAULTS_CLEAR_1, l_dt_data_to_write);

    // Disable VR Enable (0 --> Bit 7)
    mss::pmic::ddr5::pmic_reg_read_reverse_buffer(io_pmic_dt_target_info, REGS::R32, l_pmic_buffer);
    l_pmic_buffer.clearBit<FIELDS::R32_VR_ENABLE>();
    mss::pmic::ddr5::pmic_reg_write_reverse_buffer(io_pmic_dt_target_info, REGS::R32, l_pmic_buffer);

    // Enable efuse
    mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::EN_REGISTER, 0x01);

    // Read register Recovery Count register 0xE1
    mss::pmic::ddr5::dt_reg_read(io_pmic_dt_target_info, DT_REGS::RECOVERY_COUNT, l_data_recovery_count);
    // Increment by 1, but reset to 0 when the counter is 0xFF(255)
    // Since it is a uint8_t buffer, it will automatically reset to 0 when incremented from 0XFF
    l_data_recovery_count++;
    // Write the incremented value back to the register
    mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::RECOVERY_COUNT, l_data_recovery_count);

    // Delay for 10 ms. Might remove this if natural delay is sufficient
    fapi2::delay(10 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Clear global status reg
    mss::pmic::ddr5::pmic_reg_write(io_pmic_dt_target_info, REGS::R14, 0x01);

    // Start VR Enable (1 --> Bit 7)
    mss::pmic::ddr5::pmic_reg_read_reverse_buffer(io_pmic_dt_target_info, REGS::R32, l_pmic_buffer);
    l_pmic_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    mss::pmic::ddr5::pmic_reg_write_reverse_buffer(io_pmic_dt_target_info, REGS::R32, l_pmic_buffer);
}

///
/// @brief Check bread crumbs for a specific DT/PMIC
///
/// @param[in,out] io_pmic_dt_target_info PMIC and DT target info struct
/// @param[in,out] io_dt_health_check struct which contains DT regs info
/// None
///
void check_and_advance_breadcrumb_reg(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_target_info,
                                      mss::pmic::ddr5::dt_health_check_telemetry& io_dt_health_check)
{
    using DT_REGS  = mss::dt::regs;

    switch(io_dt_health_check.iv_breadcrumb)
    {
        case mss::pmic::ddr5::bread_crumb::ALL_GOOD:
            {
                // Set breadcrumb to FIRST_ATTEMPT
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT;
                mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT);
                break;
            }

        case mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT:
            {
                // Set breadcrumb to RECOVERY_ATTEMPTED
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED;
                mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::BREADCRUMB,
                                              mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED);
                attempt_recovery(io_pmic_dt_target_info);
                break;
            }

        case mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED:
            {
                // Set breadcrumb to STILL_A_FAIL
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::STILL_A_FAIL;
                mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::STILL_A_FAIL);
                break;
            }

        case mss::pmic::ddr5::bread_crumb::STILL_A_FAIL:
            {
                // Do nothing. Keep the state as is
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::STILL_A_FAIL;
                mss::pmic::ddr5::dt_reg_write(io_pmic_dt_target_info, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::STILL_A_FAIL);
                break;
            }
    }
}

///
/// @brief Compare 4 phases provided from 4 pmics, update pmic states if needed
///
/// @tparam N size of the phase value data buffer
/// @tparam M size of the number of pmics
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] array of phase values
/// @param[in] array of pmics to do phase comparison on
/// @return None
///
template <size_t N, size_t M>
void phase_comparison(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                      mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                      const uint32_t (&i_phase_values)[N],
                      const uint8_t (&i_pmic)[M])
{
    uint8_t l_phase_min_index = 0;
    uint8_t l_phase_max_index = 0;

    l_phase_min_index = check_phase_min(i_phase_values);
    l_phase_max_index = check_phase_max(i_phase_values);

    if (i_phase_values[l_phase_min_index] < mss::pmic::ddr5::PHASE_MIN_MA)
    {
        if (i_phase_values[l_phase_max_index] > mss::pmic::ddr5::PHASE_MAX_MA)
        {
            io_target_info.iv_pmic_dt_map[i_pmic[l_phase_min_index]].iv_pmic_state |=
                mss::pmic::ddr5::pmic_state::PMIC_CURRENT_IMBALANCE;
        }
    }
}

///
/// @brief Calculate VDDQ current and determine if any current imbalance
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivddq(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[4] = {};
    const uint8_t l_pmic[] = {0, 1, 2, 3};

    using CONSTS = mss::pmic::id;

    // IVDDQ is made up of the following phase currents
    // (SWA0 + SWB0)
    // (SWA1 + SWB1)
    // (SWA2 + SWB2)
    // (SWA3 + SWB2)

    l_phase[0] = (io_health_check_info.iv_pmic[CONSTS::PMIC0].iv_swa_current_mA) +
                 (io_health_check_info.iv_pmic[CONSTS::PMIC0].iv_swb_current_mA);

    l_phase[1] = (io_health_check_info.iv_pmic[CONSTS::PMIC1].iv_swa_current_mA) +
                 (io_health_check_info.iv_pmic[CONSTS::PMIC1].iv_swb_current_mA);

    l_phase[2] = (io_health_check_info.iv_pmic[CONSTS::PMIC2].iv_swa_current_mA) +
                 (io_health_check_info.iv_pmic[CONSTS::PMIC2].iv_swb_current_mA);

    l_phase[3] = (io_health_check_info.iv_pmic[CONSTS::PMIC3].iv_swa_current_mA) +
                 (io_health_check_info.iv_pmic[CONSTS::PMIC3].iv_swb_current_mA);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

///
/// @brief Calculate VIO current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivio(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[2] = {};
    const uint8_t l_pmic[] = {1, 2};

    using CONSTS = mss::pmic::id;

    // IVIO is made up of SWD1 and SWC2
    l_phase[0] = io_health_check_info.iv_pmic[CONSTS::PMIC1].iv_swd_current_mA;
    l_phase[1] = io_health_check_info.iv_pmic[CONSTS::PMIC2].iv_swc_current_mA;

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

///
/// @brief Calculate VPP current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivpp(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[2] = {};
    const uint8_t l_pmic[] = {0, 2};

    using CONSTS = mss::pmic::id;

    // IVPP is made up of SWD0 and SWD2
    l_phase[0] = (io_health_check_info.iv_pmic[CONSTS::PMIC0].iv_swd_current_mA);
    l_phase[1] = (io_health_check_info.iv_pmic[CONSTS::PMIC2].iv_swd_current_mA);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

///
/// @brief Calculate VDD current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///       PMIC3 SWC (supplied VDD) has a misplaced sensing signal.
///       That misplacement will cause a current imbalance where PMIC3 SWC may not contribute much current to VDD although it is functional.
///       The SPD was fixed but some of the RAW cards still have this issue.
///       In order to be sure that the RAW cards dont cause the system to go into n-mode at IPL and during run time,
///       we're skipping VDD current imbalance check only for raw card C (which per SPD is 0x02), revision 0
///
void read_ivdd(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[3] = {};
    const uint8_t l_pmic[] = {0, 1, 3};
    uint8_t l_raw_card_ref_design = 0;
    uint8_t l_raw_card_design = 0;

    static constexpr uint8_t RAW_CARD_REF_DESIGN_C = 0x02;
    static constexpr uint8_t RAW_CARD_REV = 0x00;

    using CONSTS = mss::pmic::id;

    // Get the RAW card attribute
#ifndef __PPE__
    // Get OCMB target
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(io_target_info.iv_pmic_dt_map[0].iv_pmic);
    FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_RAW_CARD_REFERENCE_DESIGN, l_ocmb, l_raw_card_ref_design);
    FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_RAW_CARD_DESIGN_REVISION,  l_ocmb, l_raw_card_design);
#else
    l_raw_card_design = fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_DIMM_RAW_CARD_REFERENCE_DESIGN;
    l_raw_card_design = fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_DIMM_RAW_CARD_DESIGN_REVISION;
#endif


    if (!((l_raw_card_ref_design == RAW_CARD_REF_DESIGN_C) && (l_raw_card_design == RAW_CARD_REV)))
    {
        // IVDD is made up of SWC0, SWC1 and SWC3
        l_phase[0] = (io_health_check_info.iv_pmic[CONSTS::PMIC0].iv_swc_current_mA);
        l_phase[1] = (io_health_check_info.iv_pmic[CONSTS::PMIC1].iv_swc_current_mA);
        l_phase[2] = (io_health_check_info.iv_pmic[CONSTS::PMIC3].iv_swc_current_mA);

        phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
    }
}

///
/// @brief Check PMIC faults for all given PMICs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @note As per the document provided by the Power team "Redundant PoD5 - Functional Specification
///      dated 20230412 version 0.07", the only data needed from the PMICs for health determination
///      are the rail currents to detect current imbalances and VIN_OK_Z bit fo R73. Other status
///      faults are summed up into the DT IC “GPI_1” bit.
///
void check_pmic_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                       mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    // Check current imbalance first
    // VDDQ
    FAPI_INF_NO_SBE("Checking voltage domain VDDQ");
    read_ivddq(io_target_info, io_health_check_info);

    // VIO
    FAPI_INF_NO_SBE("Checking voltage domain VIO");
    read_ivio(io_target_info, io_health_check_info);

    // VPP
    FAPI_INF_NO_SBE("Checking voltage domain VPP");
    read_ivpp(io_target_info, io_health_check_info);

    // VDD
    FAPI_INF_NO_SBE("Checking voltage domain VDD");
    read_ivdd(io_target_info, io_health_check_info);

    set_pmic_states(io_target_info, io_health_check_info);
}

///
/// @brief Check for DT faults in regs of a specific DT
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void get_dt_state(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using DT_FIELDS  = mss::dt::fields;
    mss::pmic::ddr5::dt_state l_state = mss::pmic::ddr5::dt_state::DT_ALL_GOOD;

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        fapi2::buffer<uint16_t> l_reg0 = io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_0;
        fapi2::buffer<uint16_t> l_reg1 = io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_1;

        if(!l_reg1.getBit<DT_FIELDS::GPI_1>())
        {
            l_state = mss::pmic::ddr5::dt_state::DT_GPI_1;
        }
        else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_A>())
        {
            l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_A;
        }
        else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_B>())
        {
            l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_B;
        }
        else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_C>())
        {
            l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_C;
        }
        else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_D>())
        {
            l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_D;
        }

        io_target_info.iv_pmic_dt_map[l_dt_count].iv_dt_state = l_state;
    }
}

///
/// @brief Reverse the DT regs. When performing bit operations on DT regs,
///        we have to flip the buffer from PMIC style[7:0], to fapi2-style [0:7].
///        After the operations have been performed, we would like to revert
///        the style so as to print the data in PMIC style.
///
/// @param[in] i_number_of_target_infos_present number of DT targets to reverse regs
/// @param[in,out] io_health_check_info struct to be filled in
/// @return None
///
void reverse_dt_regs(const uint8_t i_number_of_target_infos_present,
                     mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    fapi2::buffer<uint16_t> l_reg = 0;

    for (auto l_dt_count = 0; l_dt_count < i_number_of_target_infos_present; l_dt_count++)
    {
        // Re-reverse the I2C read data
        l_reg = io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_1;
        l_reg.reverse();
        io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_1 = l_reg;

        l_reg = io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_0;
        l_reg.reverse();
        io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_0 = l_reg;
    }
}

///
/// @brief Check DT faults for all given DTs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::dt_state aggregrate state of all DTs
///
mss::pmic::ddr5::dt_state check_dt_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS = mss::dt::dt_i2c_devices;
    FAPI_INF_NO_SBE("Checking DT faults");

    get_dt_state(io_target_info, io_health_check_info);

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        if (io_target_info.iv_pmic_dt_map[l_dt_count].iv_dt_state)
        {
            check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[l_dt_count], io_health_check_info.iv_dt[l_dt_count]);
        }
    }

    reverse_dt_regs(io_target_info.iv_number_of_target_infos_present, io_health_check_info);

    return static_cast<mss::pmic::ddr5::dt_state>(std::max(std::max(io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt_state,
            io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt_state),
            std::max(io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt_state,
                     io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt_state)));
}

///
/// @brief Store the read regs into struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    for (auto l_pmic_count = 0; l_pmic_count < io_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present(io_target_info, l_pmic_count, [&io_target_info, l_pmic_count, &io_health_check_info]
                                        (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
            using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
            using FIELDS = pmicFields<mss::pmic::product::TPS5383X>;
            fapi2::buffer<uint8_t> l_data_buffer[NUMBER_PMIC_REGS_READ];

            FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Raeding PMIC data", GENTARGTID(io_target_info.iv_pmic_dt_map[l_pmic_count].iv_pmic));

            mss::pmic::ddr5::pmic_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R04, l_data_buffer);

            io_health_check_info.iv_pmic[l_pmic_count].iv_r04 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_0];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r05 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_1];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r06 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_2];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r07 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_3];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r08 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_4];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r09 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_5];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r0a = l_data_buffer[mss::pmic::ddr5::data_position::DATA_6];
            io_health_check_info.iv_pmic[l_pmic_count].iv_r0b = l_data_buffer[mss::pmic::ddr5::data_position::DATA_7];
            io_health_check_info.iv_pmic[l_pmic_count].iv_swa_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_8] *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_health_check_info.iv_pmic[l_pmic_count].iv_swb_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_9] *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_health_check_info.iv_pmic[l_pmic_count].iv_swc_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_10] *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
            io_health_check_info.iv_pmic[l_pmic_count].iv_swd_current_mA = l_data_buffer[mss::pmic::ddr5::data_position::DATA_11] *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;

            mss::pmic::ddr5::pmic_reg_read_reverse_buffer(io_target_info.iv_pmic_dt_map[l_pmic_count], TPS_REGS::R73, l_data_buffer[mss::pmic::ddr5::data_position::DATA_0]);

            if (l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].getBit<FIELDS::R73_VIN_OK_Z>())
            {
                io_target_info.iv_pmic_dt_map[l_pmic_count].iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_VIN_OK_Z;
            }

            io_health_check_info.iv_pmic[l_pmic_count].iv_r73_status_5 = l_data_buffer[mss::pmic::ddr5::data_position::DATA_0].reverse();

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Read all DT regs and store in the array of structs
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, l_dt_count, &io_health_check_info]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_pmic) -> fapi2::ReturnCode
        {
            static constexpr uint8_t BITS_PER_BYTE = 8;
            using DT_REGS  = mss::dt::regs;
            fapi2::buffer<uint8_t> l_data_buffer[NUMBER_DT_REGS_READ];
            fapi2::buffer<uint8_t> l_data_breadcrumb = 0;

            FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Reading DT data", GENTARGTID(io_target_info.iv_pmic_dt_map[l_dt_count].iv_dt));

            mss::pmic::ddr5::dt_reg_read_contiguous_reverse(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::RO_INPUTS_1, l_data_buffer);
            io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_1 = (l_data_buffer[mss::pmic::ddr5::data_position::DATA_0] << BITS_PER_BYTE) | l_data_buffer[mss::pmic::ddr5::data_position::DATA_1];

            mss::pmic::ddr5::dt_reg_read_contiguous_reverse(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::RO_INPUTS_0, l_data_buffer);
            io_health_check_info.iv_dt[l_dt_count].iv_ro_inputs_0 = (l_data_buffer[mss::pmic::ddr5::data_position::DATA_0] << BITS_PER_BYTE) | l_data_buffer[mss::pmic::ddr5::data_position::DATA_1];

            mss::pmic::ddr5::dt_reg_read(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::BREADCRUMB, l_data_breadcrumb);
            io_health_check_info.iv_dt[l_dt_count].iv_breadcrumb = l_data_breadcrumb;

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Check if n mode is detected from the states of the individual PMIC/DT pair
///
/// @param[in,out] io_health_check_info health check struct
/// @return aggregate state of the DIMM
///
mss::pmic::ddr5::aggregate_state check_n_mode(mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    const auto l_max_breadcrumb = std::max(std::max(io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT0].iv_breadcrumb,
                                           io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT1].iv_breadcrumb),
                                           std::max(io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT2].iv_breadcrumb,
                                                   io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT3].iv_breadcrumb));

    mss::pmic::ddr5::bread_crumb l_breadcrumb_value = static_cast<mss::pmic::ddr5::bread_crumb>(l_max_breadcrumb);

    switch(l_breadcrumb_value)
    {
        case mss::pmic::ddr5::bread_crumb::ALL_GOOD:
            {
                io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_PLUS_1;
                break;
            }

        case mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT:
            {
                io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_MODE_POSSIBLE;
                break;
            }

        case mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED:
            {
                io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_MODE_RECOVERY_ATTEMPTED;
                break;
            }

        case mss::pmic::ddr5::bread_crumb::STILL_A_FAIL:
            {
                io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_MODE;
                break;
            }
    }

    return io_health_check_info.iv_aggregate_state;
}

///
/// @brief Collect additional ADC data in case of N_MODE detected
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_adc_data(const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info,
                                 mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info)
{
    using ADC_REGS = mss::adc::regs;
    static constexpr uint8_t NUM_BYTES_TO_READ = 16;

    fapi2::buffer<uint8_t> l_data_adc[NUM_BYTES_TO_READ];

    mss::pmic::i2c::reg_read_contiguous(i_target_info.iv_adc, ADC_REGS::SYSTEM_STATUS, l_data_adc);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    io_additional_info.iv_adc.iv_system_status = l_data_adc[mss::pmic::ddr5::data_position::DATA_0];
    io_additional_info.iv_adc.iv_general_cfg   = l_data_adc[mss::pmic::ddr5::data_position::DATA_1];
    io_additional_info.iv_adc.iv_data_cfg      = l_data_adc[mss::pmic::ddr5::data_position::DATA_2];
    io_additional_info.iv_adc.iv_osr_cfg       = l_data_adc[mss::pmic::ddr5::data_position::DATA_3];
    io_additional_info.iv_adc.iv_opmode_cfg    = l_data_adc[mss::pmic::ddr5::data_position::DATA_4];
    io_additional_info.iv_adc.iv_pin_cfg       = l_data_adc[mss::pmic::ddr5::data_position::DATA_5];
    io_additional_info.iv_adc.iv_dummy_0       = l_data_adc[mss::pmic::ddr5::data_position::DATA_6];
    io_additional_info.iv_adc.iv_gpio_cfg      = l_data_adc[mss::pmic::ddr5::data_position::DATA_7];
    io_additional_info.iv_adc.iv_dummy_1       = l_data_adc[mss::pmic::ddr5::data_position::DATA_8];
    io_additional_info.iv_adc.iv_gpo_drive_cfg = l_data_adc[mss::pmic::ddr5::data_position::DATA_9];
    io_additional_info.iv_adc.iv_dummy_2       = l_data_adc[mss::pmic::ddr5::data_position::DATA_10];
    io_additional_info.iv_adc.iv_gpo_value_cfg = l_data_adc[mss::pmic::ddr5::data_position::DATA_11];
    io_additional_info.iv_adc.iv_dummy_3       = l_data_adc[mss::pmic::ddr5::data_position::DATA_12];
    io_additional_info.iv_adc.iv_gpi_value     = l_data_adc[mss::pmic::ddr5::data_position::DATA_13];
    io_additional_info.iv_adc.iv_dummy_4       = l_data_adc[mss::pmic::ddr5::data_position::DATA_14];
    io_additional_info.iv_adc.iv_dummy_5       = l_data_adc[mss::pmic::ddr5::data_position::DATA_15];
}

///
/// @brief Collect additional PMIC data in case of N_MODE detected
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_pmic_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                  mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    static constexpr uint8_t NUM_BYTES_TO_READ = 2;

    for (auto l_pmic_count = 0; l_pmic_count < io_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present(io_target_info, l_pmic_count, [&io_target_info, &io_additional_info, l_pmic_count]
                                        (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            fapi2::buffer<uint8_t> l_pmic_buffer;
            fapi2::buffer<uint8_t> l_pmic_buffer1[NUM_BYTES_TO_READ];

            mss::pmic::ddr5::pmic_reg_read(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R2F, l_pmic_buffer);
            io_additional_info.iv_pmic[l_pmic_count].iv_r2f_pmic_config = l_pmic_buffer;

            mss::pmic::ddr5::pmic_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R32, l_pmic_buffer1);
            io_additional_info.iv_pmic[l_pmic_count].iv_r32_pmic_enable = l_pmic_buffer1[0];
            io_additional_info.iv_pmic[l_pmic_count].iv_r33_temp_status = l_pmic_buffer1[1];

            mss::pmic::ddr5::pmic_reg_read(io_target_info.iv_pmic_dt_map[l_pmic_count], TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_pmic_buffer);
            io_additional_info.iv_pmic[l_pmic_count].iv_r9c_on_off_config = l_pmic_buffer;

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Collect additional DT data in case of N_MODE detected
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_dt_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info)
{
    using DT_REGS  = mss::dt::regs;
    static constexpr uint8_t NUM_BYTES_TO_READ = 2;
    static constexpr uint8_t BITS_PER_BYTE = 8;

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the corresponding PMIC in the PMIC/DT pair is not overridden to disabled, run the enable
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, &io_additional_info, l_dt_count]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            fapi2::buffer<uint8_t> l_dt_buffer[NUM_BYTES_TO_READ];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::OPS_STATE, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_r90_ops_state = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::FAULTS_STATUS_0, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_r92_faults_status_0 = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::FAULTS_STATUS_1, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_r94_faults_status_1 = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::FIRST_FAULT_STATUS_0, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_r96_first_faults_status_0 = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::FIRST_FAULT_STATUS_1, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_r98_first_faults_status_1 = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::INFET_POWER_MTP_ADDR, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_ra6_infet_mpt_addr = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::NVM_DATA, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_ra8_nvm_data = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::VCC_VIN_VINP, l_dt_buffer);
            io_additional_info.iv_dt[l_dt_count].iv_rb4_vcc_vin_vinp = (l_dt_buffer[0] << BITS_PER_BYTE) | l_dt_buffer[1];

            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
}

///
/// @brief Collect additional data in case of N_MODE detected
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_n_mode_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                    mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info)
{
    collect_additional_adc_data(io_target_info, io_additional_info);
    collect_additional_pmic_data(io_target_info, io_additional_info);
    collect_additional_dt_data(io_target_info, io_additional_info);
}

///
/// @brief Send the consolidated_health_check_data struct in case of n-mode
///
/// @param[in] i_info consolidated_health_check_data struct
/// @oaram[in] i_length_of_data number of bytes to be trasmitted
/// @param[out] o_data hwp_data_ostream data stream
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode send_struct(mss::pmic::ddr5::consolidated_health_check_data& i_info,
                              const uint16_t i_length_of_data,
                              fapi2::hwp_data_ostream& o_data)
{
    // Casted to char pointer so we can increment in single bytes
    char* i_info_casted  = reinterpret_cast<char*>(&i_info);

    // Loop through in increments of hwp_data_unit size (currently uint32_t)
    // Until we have copied the entire structure
    for (uint16_t l_byte = 0; l_byte < i_length_of_data; l_byte += sizeof(fapi2::hwp_data_unit))
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
/// @brief Generate and send the io_consolidated_data struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in] i_health_check_info health check struct
/// @param[in] i_additional_info additional data collected struct in case of n-mode detected
/// @param[in] i_periodic_tele_info periodic telemetry data collected struct in case of n-mode detected
/// @param[in,out] io_consolidated_data consolidate data of all the structs to be sent
/// @param[in] i_number_bytes_to_send number of bytes to send as response to this HWP
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode generate_and_send_response(const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info,
        const mss::pmic::ddr5::health_check_telemetry_data& i_health_check_info,
        const mss::pmic::ddr5::additional_n_mode_telemetry_data& i_additional_info,
        const mss::pmic::ddr5::periodic_telemetry_data& i_periodic_tele_info,
        mss::pmic::ddr5::consolidated_health_check_data& io_consolidated_data,
        const uint8_t i_number_bytes_to_send,
        fapi2::hwp_data_ostream& o_data)
{
    using CONSTS  = mss::pmic::id;
    using CONSTS_DT = mss::dt::dt_i2c_devices;

    io_consolidated_data.iv_health_check = i_health_check_info;

    if(i_number_bytes_to_send == SIZEOF_AGGREGATE_STATE)
    {
        FAPI_TRY(send_struct(io_consolidated_data, SIZEOF_AGGREGATE_STATE, o_data));
    }
    else
    {
        io_consolidated_data.iv_additional_data = i_additional_info;
        io_consolidated_data.iv_periodic_telemetry_data = i_periodic_tele_info;

        io_consolidated_data.iv_pmic0_errors = i_target_info.iv_pmic_dt_map[CONSTS::PMIC0].iv_pmic_state;
        io_consolidated_data.iv_pmic1_errors = i_target_info.iv_pmic_dt_map[CONSTS::PMIC1].iv_pmic_state;
        io_consolidated_data.iv_pmic2_errors = i_target_info.iv_pmic_dt_map[CONSTS::PMIC2].iv_pmic_state;
        io_consolidated_data.iv_pmic3_errors = i_target_info.iv_pmic_dt_map[CONSTS::PMIC3].iv_pmic_state;

        io_consolidated_data.iv_dt0_errors = i_target_info.iv_pmic_dt_map[CONSTS_DT::DT0].iv_dt_state;
        io_consolidated_data.iv_dt1_errors = i_target_info.iv_pmic_dt_map[CONSTS_DT::DT1].iv_dt_state;
        io_consolidated_data.iv_dt2_errors = i_target_info.iv_pmic_dt_map[CONSTS_DT::DT2].iv_dt_state;
        io_consolidated_data.iv_dt3_errors = i_target_info.iv_pmic_dt_map[CONSTS_DT::DT3].iv_dt_state;

        FAPI_TRY(send_struct(io_consolidated_data, sizeof(io_consolidated_data), o_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if at least one PMIC has issues
///
/// @param[in] i_failed_pmics n-mode states of the 4 PMICs
/// @return true/false at least one pmic is bad
///
bool mnfg_mode_check_failed_pmics (const mss::pmic::n_mode i_failed_pmics[mss::dt::dt_i2c_devices::NUM_TOTAL_DEVICES])
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;

    // True if any are N_MODE
    return i_failed_pmics[mss::dt::dt_i2c_devices::DT0] == N_MODE ||
           i_failed_pmics[mss::dt::dt_i2c_devices::DT1] == N_MODE ||
           i_failed_pmics[mss::dt::dt_i2c_devices::DT2] == N_MODE ||
           i_failed_pmics[mss::dt::dt_i2c_devices::DT3] == N_MODE;
}

///
/// @brief Resets breadcrumb for PMIC/DT pair if both PMIC and DT states are ALL_GOOD
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] i_mnfg_thresholds mnfg attribute flag
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_and_reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
        const bool i_mnfg_thresholds)
{
    using CONSTS = mss::dt::dt_i2c_devices;
    using DT_REGS  = mss::dt::regs;

    mss::pmic::n_mode l_failed_pmics[CONSTS::NUM_TOTAL_DEVICES] =
    {
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
    };

    if (!io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_pmic_state
        && !io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt_state )
    {
        mss::pmic::ddr5::dt_reg_write(io_target_info.iv_pmic_dt_map[CONSTS::DT0], DT_REGS::BREADCRUMB,
                                      mss::pmic::ddr5::bread_crumb::ALL_GOOD);
        // Resetting the struct bread crumb variable
        io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT0].iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    }
    else
    {
        // This is just to show that the PMIC/DT state was something other than ALL_GOOD.
        // This state will be checked if in mnfg mode. Ignored otherwise.
        l_failed_pmics[CONSTS::DT0] = mss::pmic::n_mode::N_MODE;
    }

    if (!io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_pmic_state
        && !io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt_state )
    {
        mss::pmic::ddr5::dt_reg_write(io_target_info.iv_pmic_dt_map[CONSTS::DT1], DT_REGS::BREADCRUMB,
                                      mss::pmic::ddr5::bread_crumb::ALL_GOOD);
        // Resetting the struct bread crumb variable
        io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT1].iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    }
    else
    {
        // This is just to show that the PMIC/DT state was something other than ALL_GOOD.
        // This state will be checked if in mnfg mode. Ignored otherwise.
        l_failed_pmics[CONSTS::DT1] = mss::pmic::n_mode::N_MODE;
    }

    if (!io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_pmic_state
        && !io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt_state )
    {
        mss::pmic::ddr5::dt_reg_write(io_target_info.iv_pmic_dt_map[CONSTS::DT2], DT_REGS::BREADCRUMB,
                                      mss::pmic::ddr5::bread_crumb::ALL_GOOD);
        // Resetting the struct bread crumb variable
        io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT2].iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    }
    else
    {
        // This is just to show that the PMIC/DT state was something other than ALL_GOOD.
        // This state will be checked if in mnfg mode. Ignored otherwise.
        l_failed_pmics[CONSTS::DT2] = mss::pmic::n_mode::N_MODE;
    }

    if (!io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_pmic_state
        && !io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt_state )
    {
        mss::pmic::ddr5::dt_reg_write(io_target_info.iv_pmic_dt_map[CONSTS::DT3], DT_REGS::BREADCRUMB,
                                      mss::pmic::ddr5::bread_crumb::ALL_GOOD);
        // Resetting the struct bread crumb variable
        io_health_check_info.iv_dt[mss::dt::dt_i2c_devices::DT3].iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    }
    else
    {
        // This is just to show that the PMIC/DT state was something other than ALL_GOOD.
        // This state will be checked if in mnfg mode. Ignored otherwise.
        l_failed_pmics[CONSTS::DT3] = mss::pmic::n_mode::N_MODE;
    }

    // If any of the PMIC/DTs are in state other than N_PLUS_1, the procedure will fail
    // in case if we are in manufacturing mode.
    if (i_mnfg_thresholds)
    {
        FAPI_ASSERT(!(mnfg_mode_check_failed_pmics(l_failed_pmics)),
                    fapi2::PMIC_HEALTH_CHECK_FAIL_MNFG_MODE_DDR5_4U()
                    .set_OCMB_TARGET(io_target_info.iv_ocmb)
                    .set_N_MODE_PMIC0(l_failed_pmics[CONSTS::DT0])
                    .set_N_MODE_PMIC1(l_failed_pmics[CONSTS::DT1])
                    .set_N_MODE_PMIC2(l_failed_pmics[CONSTS::DT2])
                    .set_N_MODE_PMIC3(l_failed_pmics[CONSTS::DT3]),
#ifndef __PPE__
                    GENTARGTIDFORMAT " Warning: At least one of the 4 PMIC/DTs had errors running health check. "
                    "MNFG_THRESHOLDS has asserted that we %s. N-Mode States:"
                    "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                    GENTARGTID(io_target_info.iv_ocmb),
                    (i_mnfg_thresholds) ? "EXIT." : "DO NOT EXIT. Continuing boot normally with redundant parts.",
                    l_failed_pmics[CONSTS::DT0], l_failed_pmics[CONSTS::DT1], l_failed_pmics[CONSTS::DT2], l_failed_pmics[CONSTS::DT3]);
#else
                    "Warning: At least one of the 4 PMICs had errors which caused a drop into N-Mode. "
                    "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                    l_failed_pmics[CONSTS::DT0], l_failed_pmics[CONSTS::DT1], l_failed_pmics[CONSTS::DT2], l_failed_pmics[CONSTS::DT3]);
#endif
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Runs the actual health check for 4U parts
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in,out] io_additional_info additional health check data
/// @param[in,out] io_periodic_tele_info periodic telemetry data
/// @param[in,out] io_number_bytes_to_send number of bytes to send as response to this HWP
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode health_check_ddr5(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                    mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                                    mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info,
                                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info,
                                    uint8_t& io_number_bytes_to_send)
{
    mss::pmic::ddr5::dt_state l_dt_state = mss::pmic::ddr5::dt_state::DT_ALL_GOOD;
    mss::pmic::ddr5::aggregate_state l_n_mode = mss::pmic::ddr5::aggregate_state::N_PLUS_1;

    // MFG flags vars/consts
    bool l_mnfg_thresholds = false;

    // Get mnfg thresholds policy setting
    mss::pmic::get_mnfg_thresholds(l_mnfg_thresholds);

    // Read and store DT regs for fault calculations
    read_dt_regs(io_target_info, io_health_check_info);

    l_n_mode = check_breadcrumbs_subsequent_n_modes(io_health_check_info);

    // If subsequent n-mode detected, then no need to perform any calculations.
    // Just return 1 byte of aggregate state
    if(l_n_mode == mss::pmic::ddr5::aggregate_state::N_MODE)
    {
        io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_MODE;
        io_number_bytes_to_send = SIZEOF_AGGREGATE_STATE;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Read and store PMIC regs for fault calculations
    read_pmic_regs(io_target_info, io_health_check_info);

    // Check DT faults and set aggregate state
    l_dt_state = check_dt_faults(io_target_info, io_health_check_info);

    // If not faults on DT, then check for PMIC faults
    if (!l_dt_state)
    {
        check_pmic_faults(io_target_info, io_health_check_info);
    }

    FAPI_TRY(check_and_reset_breadcrumb(io_target_info, io_health_check_info, l_mnfg_thresholds));

    l_n_mode = check_n_mode(io_health_check_info);

    // If n_mode or n_mode_possible detected, then collect additional data
    if((l_n_mode == mss::pmic::ddr5::aggregate_state::N_MODE)
       || (l_n_mode == mss::pmic::ddr5::aggregate_state::N_MODE_POSSIBLE))
    {
        collect_additional_n_mode_data(io_target_info, io_additional_info);
        collect_periodic_tele_data(io_target_info, io_periodic_tele_info);
    }
    else
    {
        io_number_bytes_to_send = SIZEOF_AGGREGATE_STATE;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // Do not log error if not in mnfg mode
    if (fapi2::current_err == static_cast<uint32_t>(fapi2::RC_PMIC_HEALTH_CHECK_FAIL_MNFG_MODE_DDR5_4U)
        && !l_mnfg_thresholds)
    {
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    return fapi2::current_err;
}

///
/// @brief Runtime Health check helper for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in,out] io_additional_info additional health check data
/// @param[in,out] io_periodic_tele_info periodic telemetry data
/// @param[in,out] io_consolidated_data consolidate data of all the structs to be sent
/// @param[in,out] io_number_bytes_to_send number of bytes to send as response to this HWP
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_health_check_ddr5_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
        mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info,
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info,
        mss::pmic::ddr5::consolidated_health_check_data& io_consolidated_health_check_data,
        uint8_t& io_number_bytes_to_send)
{
    io_health_check_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_PLUS_1;

    // Check for all the asserts (correct PMIC/DT pair received, DIMM is 4U)
    FAPI_TRY(health_check_tele_tool_assert_helper(i_ocmb_target,
             io_target_info,
             io_consolidated_health_check_data.iv_health_check.iv_aggregate_state));

    if((io_consolidated_health_check_data.iv_health_check.iv_aggregate_state ==
        mss::pmic::ddr5::aggregate_state::DIMM_NOT_4U) ||
       (io_consolidated_health_check_data.iv_health_check.iv_aggregate_state == mss::pmic::ddr5::aggregate_state::N_MODE))
    {
        io_number_bytes_to_send = SIZEOF_AGGREGATE_STATE;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(health_check_ddr5(io_target_info, io_health_check_info, io_additional_info, io_periodic_tele_info,
                               io_number_bytes_to_send));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
