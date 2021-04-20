/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddimm_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file p10_ddimm_engine.H
/// @brief DDIMM Module section eff_config engine
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDIMM_ENGINE_H_
#define _P10_DDIMM_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/utils/find.H>

#include <lib/utils/pmic_consts.H>
#include <lib/shared/exp_consts.H>

#include <mss_pmic_attribute_setters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <exp_attribute_accessors_manual.H>
#include <lib/workarounds/exp_quad_encoded_cs_workarounds.H>

namespace mss
{
namespace spd
{

///
/// @brief Class for DDIMM SPD Rev 0.3
///
class ddimm_0_3
{
        using F = mss::spd::fields<DDR4, DDIMM_MODULE>;

    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    public:

        ///
        /// @brief Construct a new ddimm rev 0.3 object
        /// @param[in] i_dimm DIMM target
        ///
        ddimm_0_3(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            iv_dimm(i_dimm),
            iv_port(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm)),
            iv_ocmb(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm)) {}

        ///
        /// @brief Destroy the ddimm_0_3 object
        ///
        virtual ~ddimm_0_3() = default;

        // Check functions here return true when any value is valid (0x00 through 0xFF)

        ///
        /// @brief Traits for spd rev ddimm module
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_spd_rev_ddimm_module(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for module base height
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_module_base_height(const uint8_t i_field) const
        {
            return (i_field <= 0x04);
        }

        ///
        /// @brief Traits for mod thermal sensor
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_mod_thermal_sensor(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits for address mirror
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_address_mirror(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits byte enables LSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_byte_enables_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits byte enables MSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_byte_enables_msb(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits nibble enables LSB0
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_nibble_enables_lsb0(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits nibble enables MSB0
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_nibble_enables_msb0(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits nibble enables LSB1
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_nibble_enables_lsb1(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits DDIMM compat
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_ddimm_compat(const uint8_t i_field) const
        {
            return (i_field <= 0x1F);
        }

        ///
        /// @brief Trais num P states
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_num_p_states(const uint8_t i_field) const
        {
            return (i_field <= 0x04);
        }

        ///
        /// @brief Traits spare device LSB0
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_spare_device_lsb0(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits spare device MSB0
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_spare_device_msb0(const uint8_t i_field) const
        {
            // Mask to ensure all bits except 4:5 (which is 2:3 in SPD) are not set for x4 device spare mapping
            // Allows only nibbles 10 and 11 to be spares as per Explorer config
            constexpr uint8_t REVERSE_MASK = 0xF3;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits spare device LSB1
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_spare_device_lsb1(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        ///
        /// @brief Traits hi ddr speed ratio
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_hi_ddr_speed_ratio(const uint8_t i_field) const
        {
            return (i_field <= 0x07);
        }

        ///
        /// @brief Traits spd content revision
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_spd_content_revision(const uint8_t i_field) const
        {
            // Mask to ensure bit 2 is unset (bit 5 in SPD) since it is reserved
            constexpr uint8_t REVERSE_MASK = 0x20;
            return ((i_field & REVERSE_MASK) == 0);
        }

        // Traits common to all 4 PMIC rails on both PMIC0 and PMIC1

        ///
        /// @brief Traits pmic sequence
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_sequence(const uint8_t i_field) const
        {
            return (i_field <= 0x04);
        }

        ///
        /// @brief Traits pmic cont code
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_cont_code(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits pmic last non zero
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_last_non_zero(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits pmic rev
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rev(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits pmic rail volt set
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_volt_set(const uint8_t i_field) const
        {
            return (i_field <= 0x7F);
        }

        ///
        /// @brief Traits pmic rail range select
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_range_select(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits pmic rail volt offset
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_volt_off(const uint8_t i_field) const
        {
            return (i_field <= 0x3F);
        }

        ///
        /// @brief Traits pmic rail volt offset direction
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_off_direction(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits for pmic rail delay
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_delay(const uint8_t i_field) const
        {
            return (i_field <= 0x07);
        }

        ///
        /// @brief Traits for pmic rail order
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_rail_order(const uint8_t i_field) const
        {
            return (i_field <= 0x04);
        }

        ///
        /// @brief Traits for pmic redundancy
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_redundancy(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits pmic phase combin
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_pmic_phase_combin(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits them sensor 0 avail
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_avail(const uint8_t i_field) const
        {
            return (i_field <= 0b1);
        }

        ///
        /// @brief Traits therm sensor 0 second avail
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_second_avail(const uint8_t i_field_secondary, const uint8_t i_field_primary) const
        {
            // Disallow availability of secondary thermal sensor if primary thermal sensor is not available
            return (i_field_secondary != 0b1) || (i_field_primary == 0b1);
        }

        ///
        /// @brief Traits therm sensor 0 usage
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_usage(const uint8_t i_field) const
        {
            return (i_field <= 0b101);
        }

        ///
        /// @brief Traits therm sensor 0 type
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_type(const uint8_t i_field) const
        {
            return (i_field <= 0b0010);
        }

        ///
        /// @brief Traits therm sensor 0 i2c address
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor 0 location
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_location(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits therm sensor 1 avail
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_avail(const uint8_t i_field) const
        {
            return (i_field <= 0b1);
        }

        ///
        /// @brief Traits therm sensor 1 second avail
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_second_avail(const uint8_t i_field_secondary, const uint8_t i_field_primary) const
        {
            // Disallow availability of secondary thermal sensor if primary thermal sensor is not available
            return (i_field_secondary != 0b1) || (i_field_primary == 0b1);
        }

        ///
        /// @brief Traits therm sensor 1 usage
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_usage(const uint8_t i_field) const
        {
            return (i_field <= 0b101);
        }

        ///
        /// @brief Traits therm sensor 1 type
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_type(const uint8_t i_field) const
        {
            return (i_field <= 0b0010);
        }

        ///
        /// @brief Traits therm sensor 1 i2c address
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor 1 location
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_location(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits therm sensor diff avail
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_diff_avail(const uint8_t i_field) const
        {
            return (i_field <= 0b1);
        }

        ///
        /// @brief Traits therm sensor diff usage
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_diff_usage(const uint8_t i_field) const
        {
            return (i_field <= 0b10);
        }

        ///
        /// @brief Traits therm sensor diff type
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_diff_type(const uint8_t i_field) const
        {
            return (i_field <= 0b0010);
        }

        ///
        /// @brief Traits therm sensor diff i2c addr
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_diff_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor 0 second i2c addr
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_second_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor 1 second i2c addr
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_second_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor 0 second location
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_0_second_location(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits therm sensor 1 second location
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_1_second_location(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        ///
        /// @brief Traits module mfg id code LSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_module_mfg_id_code_lsb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

        ///
        /// @brief Traits module MFG ID Code MSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_module_mfg_id_code_msb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

        ///
        /// @brief Traits dram MFR id code lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_dram_mfr_id_code_lsb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

        ///
        /// @brief Traits dram MFR id code msb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_dram_mfr_id_code_msb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

        ///
        /// @brief Traits module RCD
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_module_rcd(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        ///
        /// @brief Traits RCD MFG ID LSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_rcd_mfg_id_lsb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

        ///
        /// @brief Traits RCD MFG ID MSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_rcd_mfg_id_msb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

#if 0 // Fields are currently unused
        virtual bool check_module_height_max(const uint8_t i_field) const
        {
            return (i_field <= 0x1F);
        }

        virtual bool check_max_thickness_back(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        virtual bool check_max_thickness_front(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        virtual bool check_design_rev(const uint8_t i_field) const
        {
            return (i_field <= 0xBF);
        }

        virtual bool check_num_rows(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        virtual bool check_num_buffers(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        virtual bool check_heat_spreader_sol(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        virtual bool check_heat_spreader_char(const uint8_t i_field) const
        {
            return (i_field <= 0x7F);
        }

        virtual bool check_continuation_code(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_last_non_zero(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_dmb_rev(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_data_width(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        virtual bool check_num_dimm_channels(const uint8_t i_field) const
        {
            return (i_field <= 0x01);
        }

        virtual bool check_bus_width_ext(const uint8_t i_field) const
        {
            return (i_field <= 0x03);
        }

        virtual bool check_channel_data_width(const uint8_t i_field) const
        {
            return (i_field <= 0x05);
        }

        virtual bool check_protocol_support(const uint8_t i_field) const
        {
            return (i_field <= 0x0F);
        }

        virtual bool check_speed_supported_lsb(const uint8_t i_field) const
        {
            return (i_field <= 0x7F);
        }

        virtual bool check_vin_mgmt_nominal(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        virtual bool check_vin_mgmt_operable(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        virtual bool check_vin_mgmt_endurant(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        virtual bool check_vin_bulk_nominal(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        virtual bool check_vin_bulk_operable(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

        virtual bool check_vin_bulk_endurant(const uint8_t i_field) const
        {
            return (i_field == 0x00);
        }

#endif

        ///
        /// @brief Set the module base height field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_module_base_height(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_BASE_HEIGHT, i_spd, SET_DRAM_MODULE_HEIGHT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_base_height(l_field),
                                  F::MODULE_BASE_HEIGHT.get_byte(i_spd),
                                  l_field,
                                  SET_DRAM_MODULE_HEIGHT,
                                  "Module Base Height"));

            FAPI_TRY(mss::attr::set_dram_module_height(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the mod thermal sensor field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_mod_thermal_sensor(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MOD_THERMAL_SENSOR, i_spd, exp::SET_MODULE_THERMAL_SENSORS, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_mod_thermal_sensor(l_field),
                                  F::MOD_THERMAL_SENSOR.get_byte(i_spd),
                                  l_field,
                                  exp::SET_MODULE_THERMAL_SENSORS,
                                  "Thermal Sensors"));

            FAPI_TRY(mss::attr::set_module_thermal_sensors(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the address mirror field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_address_mirror(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            bool l_is_quad_encoded_cs = false;
            FAPI_TRY(get_field_spd(iv_ocmb, F::ADDRESS_MIRROR, i_spd, exp::SET_EXP_DRAM_ADDRESS_MIRRORING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_address_mirror(l_field),
                                  F::ADDRESS_MIRROR.get_byte(i_spd),
                                  l_field,
                                  exp::SET_EXP_DRAM_ADDRESS_MIRRORING,
                                  "Address Mirror"));

            // Swaps the bitmap to the IBM perspective if needed
            FAPI_TRY(mss::is_quad_encoded_cs(iv_dimm, l_is_quad_encoded_cs));
            mss::exp::workarounds::fix_mirroring_bitmap_for_quad_encoded_cs(l_is_quad_encoded_cs, l_field);

            FAPI_TRY(mss::attr::set_exp_dram_address_mirroring(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the byte enables field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_byte_enables(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::BYTE_ENABLES_LSB, i_spd, exp::SET_BYTE_ENABLES, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::BYTE_ENABLES_MSB, i_spd, exp::SET_BYTE_ENABLES, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_byte_enables_lsb(l_byte0),
                                  F::BYTE_ENABLES_LSB.get_byte(i_spd),
                                  l_byte0,
                                  exp::SET_BYTE_ENABLES,
                                  "Address Mirror"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_byte_enables_msb(l_byte1),
                                  F::BYTE_ENABLES_MSB.get_byte(i_spd),
                                  l_byte1,
                                  exp::SET_BYTE_ENABLES,
                                  "Address Mirror"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. Byte enables: 0x%04x",
                     spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_byte_enables(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the nibble enables field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_nibble_enables(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint8_t l_byte2 = 0;
            uint8_t l_byte3 = 0;
            uint32_t l_field = 0;
            fapi2::buffer<uint32_t> l_buffer;

            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_LSB0, i_spd, exp::SET_NIBBLE_ENABLES, l_byte0)) );
            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_MSB0, i_spd, exp::SET_NIBBLE_ENABLES, l_byte1)) );
            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_LSB1, i_spd, exp::SET_NIBBLE_ENABLES, l_byte2)) );
            // Note: There is no l_byte3 (MSB1) for this field. We will leave it 0 for when we call right_aligned_insert

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_lsb0(l_byte0),
                                  F::NIBBLE_ENABLES_LSB0.get_byte(i_spd),
                                  l_byte0,
                                  exp::SET_NIBBLE_ENABLES,
                                  "Nibble enables LSB0"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_msb0(l_byte1),
                                  F::NIBBLE_ENABLES_MSB0.get_byte(i_spd),
                                  l_byte1,
                                  exp::SET_NIBBLE_ENABLES,
                                  "Nibble enables MSB0"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_lsb1(l_byte2),
                                  F::NIBBLE_ENABLES_LSB1.get_byte(i_spd),
                                  l_byte2,
                                  exp::SET_NIBBLE_ENABLES,
                                  "Nibble enables LSB1"));

            right_aligned_insert(l_buffer, l_byte3, l_byte2, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. Nibble Enables: 0x%04x",
                     spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_nibble_enables(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the mram support field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_mram_support(const std::vector<uint8_t>& i_spd) const
        {
            constexpr auto MRAM_SUPPORT_BIT = 3; // From SPEC
            constexpr auto MRAM_SUPPORT_LEN = 2;
            uint8_t l_field = 0;
            uint8_t l_mram_sup = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DDIMM_COMPAT, i_spd, exp::SET_MRAM_SUPPORT, l_mram_sup));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_ddimm_compat(l_mram_sup),
                                  F::DDIMM_COMPAT.get_byte(i_spd),
                                  l_mram_sup,
                                  exp::SET_MRAM_SUPPORT,
                                  "DDIMM compatability"));

            fapi2::buffer<uint8_t>(l_mram_sup).extractToRight<MRAM_SUPPORT_BIT, MRAM_SUPPORT_LEN>(l_field);

            FAPI_TRY(mss::attr::set_mram_support(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tsv 8h support field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_tsv_8h_support(const std::vector<uint8_t>& i_spd) const
        {
            constexpr auto TSV_8H_BIT = 5; // From SPEC
            uint8_t l_field = 0;
            uint8_t l_tsv_8h = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::DDIMM_COMPAT, i_spd, exp::SET_TSV_8H_SUPPORT, l_tsv_8h));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_ddimm_compat(l_tsv_8h),
                                  F::DDIMM_COMPAT.get_byte(i_spd),
                                  l_tsv_8h,
                                  exp::SET_TSV_8H_SUPPORT,
                                  "DDIMM compatability"));

            l_field = fapi2::buffer<uint8_t>(l_tsv_8h).getBit<TSV_8H_BIT>();

            FAPI_TRY(mss::attr::set_tsv_8h_support(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the ddp compatibility field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_ddp_compatibility(const std::vector<uint8_t>& i_spd) const
        {
            constexpr auto DDP_COMPATIBILITY_BIT = 6; // From SPEC
            uint8_t l_field = 0;
            uint8_t l_ddp_compat = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DDIMM_COMPAT, i_spd, exp::SET_DDP_COMPATIBILITY, l_ddp_compat));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_ddimm_compat(l_ddp_compat),
                                  F::DDIMM_COMPAT.get_byte(i_spd),
                                  l_field,
                                  exp::SET_DDP_COMPATIBILITY,
                                  "DDIMM compatability"));

            l_field = fapi2::buffer<uint8_t>(l_ddp_compat).getBit<DDP_COMPATIBILITY_BIT>();
            FAPI_TRY(mss::attr::set_ddp_compatibility(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the four rank mode field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_four_rank_mode(const std::vector<uint8_t>& i_spd) const
        {
            constexpr auto FOUR_RANK_MODE_BIT = 7; // From SPEC
            uint8_t l_field = 0;
            uint8_t l_spd_four_rank_mode = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DDIMM_COMPAT, i_spd, exp::SET_FOUR_RANK_MODE, l_spd_four_rank_mode));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_ddimm_compat(l_spd_four_rank_mode),
                                  F::DDIMM_COMPAT.get_byte(i_spd),
                                  l_field,
                                  exp::SET_FOUR_RANK_MODE,
                                  "DDIMM compatability"));

            l_field = fapi2::buffer<uint8_t>(l_spd_four_rank_mode).getBit<FOUR_RANK_MODE_BIT>();
            FAPI_TRY(mss::attr::set_four_rank_mode(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the num p states field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_num_p_states(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::NUM_P_STATES, i_spd, exp::SET_PSTATES, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_num_p_states(l_field),
                                  F::NUM_P_STATES.get_byte(i_spd),
                                  l_field,
                                  exp::SET_PSTATES,
                                  "Number of P-States"));

            FAPI_TRY(mss::attr::set_pstates(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the spare device mapping field
        ///
        /// @param[in] i_spd spd binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_spare(const std::vector<uint8_t>& i_spd) const
        {
            // Get the data
            uint8_t l_field[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_value = 0;
            uint8_t l_master_ranks_per_dimm = 0;
            uint8_t l_attr_enum_val = 0;
            const uint8_t CHAN0_NIBBLE_10 = 2;

            // Update the values
            FAPI_TRY(get_field_spd(iv_ocmb, F::SPARE_DEVICE_MSB0, i_spd, SET_DIMM_SPARE, l_value));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_spare_device_msb0(l_value),
                                  F::SPARE_DEVICE_MSB0.get_byte(i_spd),
                                  l_value,
                                  SET_DIMM_SPARE,
                                  "Spare Device Mapping Byte 1"));

            // Convert to attribute enum value
            l_attr_enum_val = (l_value >> CHAN0_NIBBLE_10);
            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(iv_dimm, l_master_ranks_per_dimm));

            for (uint8_t l_dimm_rank = 0; l_dimm_rank < l_master_ranks_per_dimm; ++l_dimm_rank)
            {
                l_field[l_dimm_rank] = l_attr_enum_val;
            }

            // Set the attribute
            FAPI_TRY(mss::attr::set_dimm_spare(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the spd content revision field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_spd_content_revision(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::SPD_CONTENT_REVISION, i_spd, SET_SPD_CONTENT_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_spd_content_revision(l_field),
                                  F::SPD_CONTENT_REVISION.get_byte(i_spd),
                                  l_field,
                                  SET_SPD_CONTENT_REVISION,
                                  "SPD content revision"));

            FAPI_TRY(mss::attr::set_spd_content_revision(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 sequence field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_sequence(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SEQUENCE, i_spd, pmic::SET_PMIC0_SEQUENCE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_sequence(l_field),
                                  F::PMIC0_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SEQUENCE,
                                  "PMIC0 Sequence"));

            FAPI_TRY(mss::attr::set_pmic0_sequence(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_CONT_CODE, i_spd, pmic::SET_PMIC0_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_LAST_NON_ZERO, i_spd, pmic::SET_PMIC0_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC0_CONT_CODE.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC0_MFG_ID,
                                  "PMIC0 Cont Code"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC0_LAST_NON_ZERO.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC0_MFG_ID,
                                  "PMIC0 Last Non-Zero"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. PMIC Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_ocmb),
                     l_field);

            FAPI_TRY(mss::attr::set_pmic0_mfg_id(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 rev field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_REV, i_spd, pmic::SET_PMIC0_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC0_REV.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_REVISION,
                                  "PMIC0 Revision"));

            FAPI_TRY(mss::attr::set_pmic0_revision(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 sequence field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_sequence(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SEQUENCE, i_spd, pmic::SET_PMIC1_SEQUENCE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_sequence(l_field),
                                  F::PMIC1_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SEQUENCE,
                                  "PMIC1 Sequence"));

            FAPI_TRY(mss::attr::set_pmic1_sequence(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_CONT_CODE, i_spd, pmic::SET_PMIC1_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_LAST_NON_ZERO, i_spd, pmic::SET_PMIC1_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC1_CONT_CODE.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC1_MFG_ID,
                                  "PMIC1 Cont Code"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC1_LAST_NON_ZERO.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC1_MFG_ID,
                                  "PMIC1 Last Non-Zero"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. PMIC Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_ocmb),
                     l_field);

            FAPI_TRY(mss::attr::set_pmic1_mfg_id(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 rev field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_REV, i_spd, pmic::SET_PMIC1_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC1_REV.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_REVISION,
                                  "PMIC1 Revision"));

            FAPI_TRY(mss::attr::set_pmic1_revision(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_VOLT_SET, i_spd, pmic::SET_PMIC0_SWA_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC0_SWA_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWA_VOLTAGE_SETTING,
                                  "PMIC0 SWA voltage settting"));

            FAPI_TRY(mss::attr::set_pmic0_swa_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_RANGE_SELECT, i_spd, pmic::SET_PMIC0_SWA_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC0_SWA_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWA_VOLTAGE_RANGE_SELECT,
                                  "PMIC0 SWA range select"));

            FAPI_TRY(mss::attr::set_pmic0_swa_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_VOLT_OFF, i_spd, pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_OFF_DIRECTION, i_spd, pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWA_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                  "PMIC0 SWA offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC0_SWA_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET,
                                  "PMIC0 SWA offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic0_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_DELAY, i_spd, pmic::SET_PMIC0_SWA_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC0_SWA_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWA_SEQUENCE_DELAY,
                                  "PMIC0 SWA delay"));

            FAPI_TRY(mss::attr::set_pmic0_swa_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swa order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_ORDER, i_spd, pmic::SET_PMIC0_SWA_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWA_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWA_SEQUENCE_ORDER,
                                  "PMIC0 SWA order"));

            FAPI_TRY(mss::attr::set_pmic0_swa_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_VOLT_SET, i_spd, pmic::SET_PMIC0_SWB_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC0_SWB_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWB_VOLTAGE_SETTING,
                                  "PMIC0 SWB voltage settting"));

            FAPI_TRY(mss::attr::set_pmic0_swb_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_RANGE_SELECT, i_spd, pmic::SET_PMIC0_SWB_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC0_SWB_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWB_VOLTAGE_RANGE_SELECT,
                                  "PMIC0 SWB range select"));

            FAPI_TRY(mss::attr::set_pmic0_swb_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_VOLT_OFF, i_spd, pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_OFF_DIRECTION, i_spd, pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWB_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                  "PMIC0 SWB offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC0_SWB_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET,
                                  "PMIC0 SWB offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic0_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_DELAY, i_spd, pmic::SET_PMIC0_SWB_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC0_SWB_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWB_SEQUENCE_DELAY,
                                  "PMIC0 SWB delay"));

            FAPI_TRY(mss::attr::set_pmic0_swb_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_ORDER, i_spd, pmic::SET_PMIC0_SWB_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWB_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWB_SEQUENCE_ORDER,
                                  "PMIC0 SWB order"));

            FAPI_TRY(mss::attr::set_pmic0_swb_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_VOLT_SET, i_spd, pmic::SET_PMIC0_SWC_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC0_SWC_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWC_VOLTAGE_SETTING,
                                  "PMIC0 SWC voltage settting"));

            FAPI_TRY(mss::attr::set_pmic0_swc_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_RANGE_SELECT, i_spd, pmic::SET_PMIC0_SWC_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC0_SWC_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWC_VOLTAGE_RANGE_SELECT,
                                  "PMIC0 SWC range select"));

            FAPI_TRY(mss::attr::set_pmic0_swc_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_VOLT_OFF, i_spd, pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_OFF_DIRECTION, i_spd, pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWC_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                  "PMIC0 SWC offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC0_SWC_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET,
                                  "PMIC0 SWC offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic0_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_DELAY, i_spd, pmic::SET_PMIC0_SWC_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC0_SWC_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWC_SEQUENCE_DELAY,
                                  "PMIC0 SWC delay"));

            FAPI_TRY(mss::attr::set_pmic0_swc_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_ORDER, i_spd, pmic::SET_PMIC0_SWC_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWC_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWC_SEQUENCE_ORDER,
                                  "PMIC0 SWC order"));

            FAPI_TRY(mss::attr::set_pmic0_swc_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_VOLT_SET, i_spd, pmic::SET_PMIC0_SWD_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC0_SWD_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWD_VOLTAGE_SETTING,
                                  "PMIC0 SWD voltage settting"));

            FAPI_TRY(mss::attr::set_pmic0_swd_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_RANGE_SELECT, i_spd, pmic::SET_PMIC0_SWD_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC0_SWD_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWD_VOLTAGE_RANGE_SELECT,
                                  "PMIC0 SWD range select"));

            FAPI_TRY(mss::attr::set_pmic0_swd_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_VOLT_OFF, i_spd, pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_OFF_DIRECTION, i_spd, pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC0_SWD_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                  "PMIC0 SWD offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC0_SWD_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET,
                                  "PMIC0 SWD offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic0_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_DELAY, i_spd, pmic::SET_PMIC0_SWD_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC0_SWD_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWD_SEQUENCE_DELAY,
                                  "PMIC0 SWD delay"));

            FAPI_TRY(mss::attr::set_pmic0_swd_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_ORDER, i_spd, pmic::SET_PMIC0_SWD_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWD_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SWD_SEQUENCE_ORDER,
                                  "PMIC0 SWD order"));

            FAPI_TRY(mss::attr::set_pmic0_swd_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 redundancy field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_redundancy(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_REDUNDANCY, i_spd, pmic::SET_PMIC0_REDUNDANCY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_redundancy(l_field),
                                  F::PMIC0_REDUNDANCY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_REDUNDANCY,
                                  "PMIC0 redundancy"));

            FAPI_TRY(mss::attr::set_pmic0_redundancy(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 phase combin field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_phase_combin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_PHASE_COMBIN, i_spd, pmic::SET_PMIC0_PHASE_COMB, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_phase_combin(l_field),
                                  F::PMIC0_PHASE_COMBIN.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_PHASE_COMB,
                                  "PMIC0 phase comb"));

            FAPI_TRY(mss::attr::set_pmic0_phase_comb(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa volt set field
        ///
        /// @param[in] i_spd
        /// @return fapi2::ReturnCode
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_VOLT_SET, i_spd, pmic::SET_PMIC1_SWA_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC1_SWA_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWA_VOLTAGE_SETTING,
                                  "PMIC1 SWA voltage settting"));

            FAPI_TRY(mss::attr::set_pmic1_swa_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_RANGE_SELECT, i_spd, pmic::SET_PMIC1_SWA_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC1_SWA_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWA_VOLTAGE_RANGE_SELECT,
                                  "PMIC1 SWA range select"));

            FAPI_TRY(mss::attr::set_pmic1_swa_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_VOLT_OFF, i_spd, pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_OFF_DIRECTION, i_spd, pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWA_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                  "PMIC1 SWA offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC1_SWA_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET,
                                  "PMIC1 SWA offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic1_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_DELAY, i_spd, pmic::SET_PMIC1_SWA_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC1_SWA_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWA_SEQUENCE_DELAY,
                                  "PMIC1 SWA delay"));

            FAPI_TRY(mss::attr::set_pmic1_swa_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_ORDER, i_spd, pmic::SET_PMIC1_SWA_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWA_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWA_SEQUENCE_ORDER,
                                  "PMIC1 SWA order"));

            FAPI_TRY(mss::attr::set_pmic1_swa_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_VOLT_SET, i_spd, pmic::SET_PMIC1_SWB_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC1_SWB_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWB_VOLTAGE_SETTING,
                                  "PMIC1 SWB voltage settting"));

            FAPI_TRY(mss::attr::set_pmic1_swb_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_RANGE_SELECT, i_spd, pmic::SET_PMIC1_SWB_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC1_SWB_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWB_VOLTAGE_RANGE_SELECT,
                                  "PMIC1 SWB range select"));

            FAPI_TRY(mss::attr::set_pmic1_swb_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_VOLT_OFF, i_spd, pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_OFF_DIRECTION, i_spd, pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWB_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                  "PMIC1 SWB offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC1_SWB_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET,
                                  "PMIC1 SWB offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic1_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_DELAY, i_spd, pmic::SET_PMIC1_SWB_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC1_SWB_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWB_SEQUENCE_DELAY,
                                  "PMIC1 SWB delay"));

            FAPI_TRY(mss::attr::set_pmic1_swb_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_ORDER, i_spd, pmic::SET_PMIC1_SWB_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWB_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWB_SEQUENCE_ORDER,
                                  "PMIC1 SWB order"));

            FAPI_TRY(mss::attr::set_pmic1_swb_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_VOLT_SET, i_spd, pmic::SET_PMIC1_SWC_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC1_SWC_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWC_VOLTAGE_SETTING,
                                  "PMIC1 SWC voltage settting"));

            FAPI_TRY(mss::attr::set_pmic1_swc_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_RANGE_SELECT, i_spd, pmic::SET_PMIC1_SWC_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC1_SWC_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWC_VOLTAGE_RANGE_SELECT,
                                  "PMIC1 SWC range select"));

            FAPI_TRY(mss::attr::set_pmic1_swc_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_VOLT_OFF, i_spd, pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_OFF_DIRECTION, i_spd, pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWC_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                  "PMIC1 SWC offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC1_SWC_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET,
                                  "PMIC1 SWC offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic1_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_DELAY, i_spd, pmic::SET_PMIC1_SWC_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC1_SWC_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWC_SEQUENCE_DELAY,
                                  "PMIC1 SWC delay"));

            FAPI_TRY(mss::attr::set_pmic1_swc_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_ORDER, i_spd, pmic::SET_PMIC1_SWC_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWC_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWC_SEQUENCE_ORDER,
                                  "PMIC1 SWC order"));

            FAPI_TRY(mss::attr::set_pmic1_swc_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_VOLT_SET, i_spd, pmic::SET_PMIC1_SWD_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC1_SWD_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWD_VOLTAGE_SETTING,
                                  "PMIC1 SWD voltage settting"));

            FAPI_TRY(mss::attr::set_pmic1_swd_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_RANGE_SELECT, i_spd, pmic::SET_PMIC1_SWD_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC1_SWD_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWD_VOLTAGE_RANGE_SELECT,
                                  "PMIC1 SWD range select"));

            FAPI_TRY(mss::attr::set_pmic1_swd_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_VOLT_OFF, i_spd, pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_OFF_DIRECTION, i_spd, pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC1_SWD_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                  "PMIC1 SWD offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC1_SWD_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET,
                                  "PMIC1 SWD offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic1_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_DELAY, i_spd, pmic::SET_PMIC1_SWD_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC1_SWD_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWD_SEQUENCE_DELAY,
                                  "PMIC1 SWD delay"));

            FAPI_TRY(mss::attr::set_pmic1_swd_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_ORDER, i_spd, pmic::SET_PMIC1_SWD_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWD_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SWD_SEQUENCE_ORDER,
                                  "PMIC1 SWD order"));

            FAPI_TRY(mss::attr::set_pmic1_swd_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 redundancy field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_redundancy(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_REDUNDANCY, i_spd, pmic::SET_PMIC1_REDUNDANCY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_redundancy(l_field),
                                  F::PMIC1_REDUNDANCY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_REDUNDANCY,
                                  "PMIC1 redundancy"));

            FAPI_TRY(mss::attr::set_pmic1_redundancy(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 phase combin field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_phase_combin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_PHASE_COMBIN, i_spd, pmic::SET_PMIC1_PHASE_COMB, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_phase_combin(l_field),
                                  F::PMIC1_PHASE_COMBIN.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_PHASE_COMB,
                                  "PMIC1 phase comb"));

            FAPI_TRY(mss::attr::set_pmic1_phase_comb(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_AVAIL, i_spd, exp::SET_THERM_SENSOR_0_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_avail(l_field),
                                  F::THERM_SENSOR_0_AVAIL.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_AVAIL,
                                  "Thermal Sensor 0 Availability"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_availability(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 second avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_second_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field_secondary = 0;
            uint8_t l_field_primary = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_SECOND_AVAIL, i_spd, exp::SET_THERM_SENSOR_0_SECOND_AVAIL,
                                   l_field_secondary));
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_AVAIL, i_spd, exp::SET_THERM_SENSOR_0_AVAIL, l_field_primary));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_second_avail(l_field_secondary, l_field_primary),
                                  F::THERM_SENSOR_0_SECOND_AVAIL.get_byte(i_spd),
                                  l_field_secondary,
                                  exp::SET_THERM_SENSOR_0_SECOND_AVAIL,
                                  "Thermal Sensor 0 Second Availability"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_secondary_availability(iv_port, l_field_secondary));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 usage field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_usage(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            // This attribute enum no longer exists, so we can use a constexpr
            constexpr uint8_t THERM_SENSOR_USAGE_DRAM_AND_PMIC = 0x03;

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_USAGE, i_spd, exp::SET_THERM_SENSOR_0_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_usage(l_field),
                                  F::THERM_SENSOR_0_USAGE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_USAGE,
                                  "Thermal Sensor 0 Usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC :
                      l_field;

            FAPI_TRY(mss::attr::set_therm_sensor_0_usage(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_TYPE, i_spd, exp::SET_THERM_SENSOR_0_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_type(l_field),
                                  F::THERM_SENSOR_0_TYPE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_TYPE,
                                  "Thermal Sensor 0 Type"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_type(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_I2C_ADDRESS, i_spd, exp::SET_THERM_SENSOR_0_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_i2c_address(l_field),
                                  F::THERM_SENSOR_0_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_I2C_ADDR,
                                  "Thermal Sensor 0 I2C addr"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_i2c_addr(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_LOCATION, i_spd, exp::SET_THERM_SENSOR_0_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_location(l_field),
                                  F::THERM_SENSOR_0_LOCATION.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_LOCATION,
                                  "Thermal Sensor 0 Location"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_location(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_AVAIL, i_spd, exp::SET_THERM_SENSOR_1_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_avail(l_field),
                                  F::THERM_SENSOR_1_AVAIL.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_AVAIL,
                                  "Thermal Sensor 1 Avail"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_availability(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 second avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_second_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field_secondary = 0;
            uint8_t l_field_primary = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_SECOND_AVAIL, i_spd, exp::SET_THERM_SENSOR_1_SECOND_AVAIL,
                                   l_field_secondary));
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_AVAIL, i_spd, exp::SET_THERM_SENSOR_1_AVAIL, l_field_primary));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_second_avail(l_field_secondary, l_field_primary),
                                  F::THERM_SENSOR_1_SECOND_AVAIL.get_byte(i_spd),
                                  l_field_secondary,
                                  exp::SET_THERM_SENSOR_1_SECOND_AVAIL,
                                  "Thermal Sensor 1 Second Avail"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_secondary_availability(iv_port, l_field_secondary));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 usage field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_usage(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            // This attribute enum no longer exists, so we can use a constexpr
            constexpr uint8_t THERM_SENSOR_USAGE_DRAM_AND_PMIC = 0x03;

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_USAGE, i_spd, exp::SET_THERM_SENSOR_1_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_usage(l_field),
                                  F::THERM_SENSOR_1_USAGE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_USAGE,
                                  "Thermal Sensor 1 usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_PMIC :
                      l_field;

            FAPI_TRY(mss::attr::set_therm_sensor_1_usage(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_TYPE, i_spd, exp::SET_THERM_SENSOR_1_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_type(l_field),
                                  F::THERM_SENSOR_1_TYPE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_TYPE,
                                  "Thermal Sensor 1 type"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_type(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_I2C_ADDRESS, i_spd, exp::SET_THERM_SENSOR_1_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_i2c_address(l_field),
                                  F::THERM_SENSOR_1_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_I2C_ADDR,
                                  "Thermal Sensor 1 I2C Address"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_i2c_addr(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_LOCATION, i_spd, exp::SET_THERM_SENSOR_1_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_location(l_field),
                                  F::THERM_SENSOR_1_LOCATION.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_LOCATION,
                                  "Thermal Sensor 1 I2C Address"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_location(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor diff avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_diff_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_DIFF_AVAIL, i_spd, exp::SET_THERM_SENSOR_DIFF_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_avail(l_field),
                                  F::THERM_SENSOR_DIFF_AVAIL.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_DIFF_AVAIL,
                                  "Thermal Sensor Diff Avail"));

            FAPI_TRY(mss::attr::set_therm_sensor_differential_availability(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor diff usage field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_diff_usage(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_DIFF_USAGE, i_spd, exp::SET_THERM_SENSOR_DIFF_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_usage(l_field),
                                  F::THERM_SENSOR_DIFF_USAGE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_DIFF_USAGE,
                                  "Thermal Sensor Diff Usage"));

            FAPI_TRY(mss::attr::set_therm_sensor_differential_usage(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor diff type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_diff_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_DIFF_TYPE, i_spd, exp::SET_THERM_SENSOR_DIFF_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_type(l_field),
                                  F::THERM_SENSOR_DIFF_TYPE.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_DIFF_TYPE,
                                  "Thermal Sensor Diff Type"));

            FAPI_TRY(mss::attr::set_therm_sensor_differential_type(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor diff i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_diff_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_DIFF_I2C_ADDRESS, i_spd, exp::SET_THERM_SENSOR_DIFF_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_i2c_address(l_field),
                                  F::THERM_SENSOR_DIFF_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_DIFF_I2C_ADDR,
                                  "Thermal Sensor Diff I2C Addr"));

            FAPI_TRY(mss::attr::set_therm_sensor_differential_i2c_addr(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 second i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_second_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_SECOND_I2C_ADDRESS, i_spd, exp::SET_THERM_SENSOR_0_SECOND_I2C_ADDR,
                                   l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_second_i2c_address(l_field),
                                  F::THERM_SENSOR_0_SECOND_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_SECOND_I2C_ADDR,
                                  "Thermal Sensor 0 Second I2C Addr"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_secondary_i2c_addr(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 second i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_second_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_SECOND_I2C_ADDRESS, i_spd, exp::SET_THERM_SENSOR_1_SECOND_I2C_ADDR,
                                   l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_second_i2c_address(l_field),
                                  F::THERM_SENSOR_1_SECOND_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_SECOND_I2C_ADDR,
                                  "Thermal Sensor 1 Second I2C Addr"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_secondary_i2c_addr(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 0 second location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_0_second_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_0_SECOND_LOCATION, i_spd, exp::SET_THERM_SENSOR_0_SECOND_LOCATION,
                                   l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_0_second_location(l_field),
                                  F::THERM_SENSOR_0_SECOND_LOCATION.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_0_SECOND_LOCATION,
                                  "Thermal Sensor 0 Second location"));

            FAPI_TRY(mss::attr::set_therm_sensor_0_secondary_location(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 1 second location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_1_second_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR_1_SECOND_LOCATION, i_spd, exp::SET_THERM_SENSOR_1_SECOND_LOCATION,
                                   l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_1_second_location(l_field),
                                  F::THERM_SENSOR_1_SECOND_LOCATION.get_byte(i_spd),
                                  l_field,
                                  exp::SET_THERM_SENSOR_1_SECOND_LOCATION,
                                  "Thermal Sensor 1 Second location"));

            FAPI_TRY(mss::attr::set_therm_sensor_1_secondary_location(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the module mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_module_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            // These fields overwrite those set by the base cnfg decoder - for DDIMMS, these
            // fields live in different bytes, so long as this module section is performed after
            // the base cnfg section, this will work as-is.
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_MFG_ID_CODE_LSB, i_spd, SET_MODULE_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_MFG_ID_CODE_MSB, i_spd, SET_MODULE_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_mfg_id_code_lsb(l_byte0),
                                  F::MODULE_MFG_ID_CODE_LSB.get_byte(i_spd),
                                  l_byte0,
                                  SET_MODULE_MFG_ID,
                                  "Module MFG ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_mfg_id_code_msb(l_byte1),
                                  F::MODULE_MFG_ID_CODE_MSB.get_byte(i_spd),
                                  l_byte1,
                                  SET_MODULE_MFG_ID,
                                  "Module MFG ID MSB"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;

            fapi2::endian_swap(l_field);
            FAPI_INF("%s. Module Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_module_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            // These fields overwrite those set by the base cnfg decoder - for DDIMMS, these
            // fields live in different bytes, so long as this module section is performed after
            // the base cnfg section, this will work as-is.
            uint8_t l_mfgid_lsb = 0;
            uint8_t l_mfgid_msb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DRAM_MFR_ID_CODE_LSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::DRAM_MFR_ID_CODE_MSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_msb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_lsb(l_mfgid_lsb),
                                  F::DRAM_MFR_ID_CODE_LSB.get_byte(i_spd),
                                  l_mfgid_lsb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM MFR ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_msb(l_mfgid_msb),
                                  F::DRAM_MFR_ID_CODE_MSB.get_byte(i_spd),
                                  l_mfgid_msb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM MFR ID MSB"));

            right_aligned_insert(l_buffer, l_mfgid_msb, l_mfgid_lsb);

            l_field = l_buffer;

            fapi2::endian_swap(l_field);
            FAPI_INF("%s.DRAM Manufacturer ID Code: %x",
                     mss::spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_dram_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the module rcd field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_module_rcd(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_RCD, i_spd, exp::SET_SUPPORTED_RCD, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_rcd(l_field),
                                  F::MODULE_RCD.get_byte(i_spd),
                                  l_field,
                                  exp::SET_SUPPORTED_RCD,
                                  "Supported RCD"));

            FAPI_TRY(mss::attr::set_supported_rcd(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the rcd mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_rcd_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_lsb = 0;
            uint8_t l_msb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::RCD_MFG_ID_LSB, i_spd, SET_RCD_MFG_ID, l_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::RCD_MFG_ID_MSB, i_spd, SET_RCD_MFG_ID, l_msb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_mfg_id_lsb(l_lsb),
                                  F::RCD_MFG_ID_LSB.get_byte(i_spd),
                                  l_lsb,
                                  SET_RCD_MFG_ID,
                                  "RCD MFG ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_mfg_id_msb(l_msb),
                                  F::RCD_MFG_ID_MSB.get_byte(i_spd),
                                  l_msb,
                                  SET_RCD_MFG_ID,
                                  "RCD MFG ID MSB"));

            right_aligned_insert(l_buffer, l_msb, l_lsb);

            l_field = l_buffer;

            // The RCD MFG ID attribute is a different endianness from the other MSB/LSB attributes
            // so in this case, we do not need to do an endian swap
            FAPI_INF("%s. RCD Manufacturer ID Code: %x",
                     mss::spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_rcd_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

#if 0 // Fields are currently unused

        virtual fapi2::ReturnCode set_module_height_max(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_HEIGHT_MAX, i_spd, l_field));

            FAPI_TRY(mss::attr::set_module_height_max(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_max_thickness_back(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MAX_THICKNESS_BACK, i_spd, l_field));

            FAPI_TRY(mss::attr::set_max_thickness_back(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_max_thickness_front(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MAX_THICKNESS_FRONT, i_spd, l_field));

            FAPI_TRY(mss::attr::set_max_thickness_front(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_design_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::DESIGN_REV, i_spd, l_field));

            FAPI_TRY(mss::attr::set_design_rev(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_num_rows(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::NUM_ROWS, i_spd, l_field));

            FAPI_TRY(mss::attr::set_num_rows(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_num_buffers(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::NUM_BUFFERS, i_spd, l_field));

            FAPI_TRY(mss::attr::set_num_buffers(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_heat_spreader_sol(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::HEAT_SPREADER_SOL, i_spd, l_field));

            FAPI_TRY(mss::attr::set_heat_spreader_sol(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_heat_spreader_char(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::HEAT_SPREADER_CHAR, i_spd, l_field));

            FAPI_TRY(mss::attr::set_heat_spreader_char(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_dmb_manufacturer_id_code(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_cont_code = 0;
            uint8_t l_last_non_zero = 0;
            uint16_t l_reg_mfg_id_code = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::CONTINUATION_CODE, i_spd, l_cont_code));
            FAPI_TRY(get_field_spd(iv_ocmb, F::LAST_NON_ZERO, i_spd, l_last_non_zero));

            right_aligned_insert(l_buffer, l_last_non_zero, l_cont_code);
            l_reg_mfg_id_code = l_buffer;
            FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_dimm),
                     l_reg_mfg_id_code);

        }

        virtual fapi2::ReturnCode set_dmb_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::DMB_REV, i_spd, l_field));

            FAPI_TRY(mss::attr::set_dmb_rev(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_data_width(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::DATA_WIDTH, i_spd, l_field));

            FAPI_TRY(mss::attr::set_data_width(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_num_dimm_channels(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::NUM_DIMM_CHANNELS, i_spd, l_field));

            FAPI_TRY(mss::attr::set_num_dimm_channels(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_bus_width_ext(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::BUS_WIDTH_EXT, i_spd, l_field));

            FAPI_TRY(mss::attr::set_bus_width_ext(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_channel_data_width(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::CHANNEL_DATA_WIDTH, i_spd, l_field));

            FAPI_TRY(mss::attr::set_channel_data_width(iv_ocmb, l_field));
        }


        virtual fapi2::ReturnCode set_protocol_support(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PROTOCOL_SUPPORT, i_spd, l_field));

            FAPI_TRY(mss::attr::set_protocol_support(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_speed_supported_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::SPEED_SUPPORTED_LSB, i_spd, l_field));

            FAPI_TRY(mss::attr::set_speed_supported_lsb(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_hi_ddr_speed_ratio(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::HI_DDR_SPEED_RATIO, i_spd, l_field));

            FAPI_TRY(mss::attr::set_hi_ddr_speed_ratio(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_mgmt_nominal(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_MGMT_NOMINAL, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_mgmt_nominal(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_mgmt_operable(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_MGMT_OPERABLE, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_mgmt_operable(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_mgmt_endurant(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_MGMT_ENDURANT, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_mgmt_endurant(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_bulk_nominal(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_BULK_NOMINAL, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_bulk_nominal(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_bulk_operable(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_BULK_OPERABLE, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_bulk_operable(iv_ocmb, l_field));
        }

        virtual fapi2::ReturnCode set_vin_bulk_endurant(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::VIN_BULK_ENDURANT, i_spd, l_field));

            FAPI_TRY(mss::attr::set_vin_bulk_endurant(iv_ocmb, l_field));
        }

#endif

        ///
        /// @brief Process the fields for ddimm rev 0.3
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            // This needs to be run first as it will be consumed for a workaround below
            FAPI_TRY(set_module_rcd(i_spd));

            FAPI_TRY(set_module_base_height(i_spd));
            FAPI_TRY(set_mod_thermal_sensor(i_spd));
            FAPI_TRY(set_address_mirror(i_spd));
            FAPI_TRY(set_byte_enables(i_spd));
            FAPI_TRY(set_nibble_enables(i_spd));
            FAPI_TRY(set_mram_support(i_spd));
            FAPI_TRY(set_tsv_8h_support(i_spd));
            FAPI_TRY(set_ddp_compatibility(i_spd));
            FAPI_TRY(set_four_rank_mode(i_spd));
            FAPI_TRY(set_num_p_states(i_spd));
            FAPI_TRY(set_dimm_spare(i_spd));
            FAPI_TRY(set_spd_content_revision(i_spd));
            FAPI_TRY(set_pmic0_sequence(i_spd));
            FAPI_TRY(set_pmic0_mfg_id(i_spd));
            FAPI_TRY(set_pmic0_rev(i_spd));
            FAPI_TRY(set_pmic1_sequence(i_spd));
            FAPI_TRY(set_pmic1_mfg_id(i_spd));
            FAPI_TRY(set_pmic1_rev(i_spd));
            FAPI_TRY(set_pmic0_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swa_range_select(i_spd));
            FAPI_TRY(set_pmic0_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swa_delay(i_spd));
            FAPI_TRY(set_pmic0_swa_order(i_spd));
            FAPI_TRY(set_pmic0_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swb_range_select(i_spd));
            FAPI_TRY(set_pmic0_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swb_delay(i_spd));
            FAPI_TRY(set_pmic0_swb_order(i_spd));
            FAPI_TRY(set_pmic0_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swc_range_select(i_spd));
            FAPI_TRY(set_pmic0_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swc_delay(i_spd));
            FAPI_TRY(set_pmic0_swc_order(i_spd));
            FAPI_TRY(set_pmic0_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swd_range_select(i_spd));
            FAPI_TRY(set_pmic0_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swd_delay(i_spd));
            FAPI_TRY(set_pmic0_swd_order(i_spd));
            FAPI_TRY(set_pmic0_redundancy(i_spd));
            FAPI_TRY(set_pmic0_phase_combin(i_spd));
            FAPI_TRY(set_pmic1_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swa_range_select(i_spd));
            FAPI_TRY(set_pmic1_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swa_delay(i_spd));
            FAPI_TRY(set_pmic1_swa_order(i_spd));
            FAPI_TRY(set_pmic1_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swb_range_select(i_spd));
            FAPI_TRY(set_pmic1_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swb_delay(i_spd));
            FAPI_TRY(set_pmic1_swb_order(i_spd));
            FAPI_TRY(set_pmic1_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swc_range_select(i_spd));
            FAPI_TRY(set_pmic1_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swc_delay(i_spd));
            FAPI_TRY(set_pmic1_swc_order(i_spd));
            FAPI_TRY(set_pmic1_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swd_range_select(i_spd));
            FAPI_TRY(set_pmic1_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swd_delay(i_spd));
            FAPI_TRY(set_pmic1_swd_order(i_spd));
            FAPI_TRY(set_pmic1_redundancy(i_spd));
            FAPI_TRY(set_pmic1_phase_combin(i_spd));
            FAPI_TRY(set_therm_sensor_0_avail(i_spd));
            FAPI_TRY(set_therm_sensor_0_second_avail(i_spd));
            FAPI_TRY(set_therm_sensor_0_usage(i_spd));
            FAPI_TRY(set_therm_sensor_0_type(i_spd));
            FAPI_TRY(set_therm_sensor_0_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_0_location(i_spd));
            FAPI_TRY(set_therm_sensor_1_avail(i_spd));
            FAPI_TRY(set_therm_sensor_1_second_avail(i_spd));
            FAPI_TRY(set_therm_sensor_1_usage(i_spd));
            FAPI_TRY(set_therm_sensor_1_type(i_spd));
            FAPI_TRY(set_therm_sensor_1_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_1_location(i_spd));
            FAPI_TRY(set_therm_sensor_diff_avail(i_spd));
            FAPI_TRY(set_therm_sensor_diff_usage(i_spd));
            FAPI_TRY(set_therm_sensor_diff_type(i_spd));
            FAPI_TRY(set_therm_sensor_diff_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_0_second_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_1_second_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_0_second_location(i_spd));
            FAPI_TRY(set_therm_sensor_1_second_location(i_spd));
            FAPI_TRY(set_module_mfg_id(i_spd));
            FAPI_TRY(set_dram_mfg_id(i_spd));
            FAPI_TRY(set_rcd_mfg_id(i_spd));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Class for DDIMM SPD Rev 0.4
///
class ddimm_0_4 : public ddimm_0_3
{
    public:
        ///
        /// @brief Construct a new ddimm rev 0.4 object
        ///
        /// @param[in] i_dimm
        ///
        ddimm_0_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) : ddimm_0_3(i_dimm)
        {
        }

        virtual ~ddimm_0_4() = default;

        // Virtual function overloads go here

        /// @brief Process the fields for ddimm rev 0.3
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            // The naming here is a bit tricky: 0.3 process will process fields
            // that originated in 0.3, but will use any field processors/traits
            // that were overridden for the current class type (ex. ddimm_0_4)

            // Only brand new fields for this revision should be explicitly
            // called here below the call to this function
            FAPI_TRY(ddimm_0_3::process(i_spd));

            // DDIMM 0.4 new field processing goes here

        fapi_try_exit:
            return fapi2::current_err;
        }
};

//
// Can be updated with the earliest supported ddimm module revision
//
using ddimm_base = ddimm_0_3;
using ddimm_base_latest = ddimm_0_4;

} // spd

}// mss

#endif
