/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddr5_ddimm_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file p10_ddr5_ddimm_engine.H
/// @brief DDR5 DDIMM Module section eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDR5_DDIMM_ENGINE_H_
#define _P10_DDR5_DDIMM_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/utils/pmic_consts.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/utils/bit_count.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/bit_count.H>

#include <lib/eff_config/p10_module_specific_engine.H>
#include <lib/eff_config/p10_base_engine.H>
#include <mss_generic_attribute_setters.H>
#include <mss_pmic_attribute_setters.H>
#include <mss_odyssey_attribute_setters.H>
#include <mss_odyssey_attribute_getters.H>


namespace mss
{
namespace spd
{
namespace ddr5
{

///
/// @brief Class for DDIMM SPD Rev 0.0
///
class ddimm_0_0 : public mss::spd::module_specific_base
{
        using F = mss::spd::fields<DDR5, DDIMM_MODULE>;

    public:

        ///
        /// @brief Construct a new ddimm rev 0.0 object
        /// @param[in] i_dimm DIMM target
        ///
        ddimm_0_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            module_specific_base(i_dimm) {}

        ///
        /// @brief Destroy the ddimm_0_0 object
        ///
        virtual ~ddimm_0_0() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const
        {
            return mss::spd::rev::V0_0;
        }

        ///
        /// @brief Get the DRAM generation
        /// @return DRAM generation value
        ///
        virtual uint8_t get_dram_generation() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5;
        }

        ///
        /// @brief Get the DIMM type
        /// @return DIMM type value
        ///
        virtual uint8_t get_dimm_type() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM;
        }

        ///
        /// @brief Traits for address mirror
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_address_mirror(const uint8_t i_field) const
        {
            return true;
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
            return (i_field <=  0x1);
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
            // Allows only channel B: nibbles 0 and 1 to be spares as per Odyssey config
            // IBM USE   PORT   DQS
            //---------------------
            // spare     B0/B1   0
            // spare     B0/B1   1
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
        /// @brief Traits therm sensor avail for all: 0,1,2,3
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_avail(const uint8_t i_field) const
        {
            return (i_field <= 0b1);
        }


        ///
        /// @brief Traits therm sensor usage for all: 0,1,2,3
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_usage(const uint8_t i_field) const
        {
            return (i_field <= 0b101);
        }

        ///
        /// @brief Traits therm sensor 1 type
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_type(const uint8_t i_field) const
        {
            return (i_field <= 0b0010);
        }

        ///
        /// @brief Traits therm sensor i2c address for all: 0,1,2,3
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_i2c_address(const uint8_t i_field) const
        {
            // Mask to ensure the R/W bit (bit 7) is unset
            constexpr uint8_t REVERSE_MASK = 0x01;
            return ((i_field & REVERSE_MASK) == 0);
        }

        ///
        /// @brief Traits therm sensor location for all: 0,1,2,3
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_therm_sensor_location(const uint8_t i_field) const
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

        ///
        /// @brief Traits CONTINUATION CODE
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_continuation_code(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits LAST NON ZERO
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_last_non_zero(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits DMB REVISION
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_dmb_rev(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits NUMBER DIMM CHANNELS
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_num_dimm_channels(const uint8_t i_field) const
        {
            return (i_field <= 0b10);
        }

        ///
        /// @brief Traits ENABLED PHY AND CHANNEL
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_enabled_phy_ch(const uint8_t i_field) const
        {
            return (i_field <= 0b10);
        }

        ///
        /// @brief Traits CHANNEL BUS WIDTH FOR CHA CHB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_channel_bus_width(const uint8_t i_field) const
        {
            return (i_field <= 0b011);
        }

        ///
        /// @brief Traits PROTOCOL SUPPORT
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_protocol_support(const uint8_t i_field) const
        {
            return (i_field <= 0x07);
        }

        ///
        /// @brief Traits SUPPORTED SPEED
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_speed_supported_lsb(const uint8_t i_field) const
        {
            return (i_field <= 0x07);
        }

        ///
        /// @brief Set the module base height field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_module_base_height(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_height = 0;
            const std::vector<uint8_t> l_reserved_bits{0b010, 0b011, 0b0101, 0b110, 0b111};
            // =========================================================
            // Byte 230: Module Height
            // Attribute: ATTR_MEM_EFF_DRAM_MODULE_HEIGHT
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 68
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > BASE_MODULE_HEIGHT_MAP =
            {
                //{key byte, dimm type}
                {0b000, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U},
                {0b001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U},
                {0b100, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U},
                // All others reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_BASE_HEIGHT, i_spd, SET_DRAM_MODULE_HEIGHT, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_DRAM_MODULE_HEIGHT, l_field) );
            FAPI_TRY( lookup_table_check(iv_ocmb, BASE_MODULE_HEIGHT_MAP, SET_DRAM_MODULE_HEIGHT, l_field, l_height),
                      "%s failed MODULE_HEIGHT lookup check", spd::c_str(iv_ocmb) );

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, iv_ocmb, l_field));

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
            uint8_t l_value = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSORS_CFG_DEVICES, i_spd, ody::SET_MODULE_THERMAL_SENSORS, l_field));

            // Count the number of bits to get the number of configured devices
            l_value = mss::bit_count(l_field);

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_MODULE_THERMAL_SENSORS, iv_ocmb, l_value));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the mem alert enable field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_mem_alert_en(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_mem_alert_a0_b0_en;
            uint8_t l_mem_alert_a1_b1_en;
            uint8_t l_field = 0;

            // =========================================================
            // Byte 364: Mem Alert Enable and Pull-Up
            // Attribute: ATTR_MEM_EFF_MEMALERTEN
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 96
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::PHY_A0_B0_MEM_ALERT, i_spd, ody::SET_MEM_ALERT_EN, l_mem_alert_a0_b0_en));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PHY_A1_B1_MEM_ALERT, i_spd, ody::SET_MEM_ALERT_EN, l_mem_alert_a1_b1_en));
            l_field = l_mem_alert_a0_b0_en || l_mem_alert_a1_b1_en;

            FAPI_TRY(mss::attr::set_memalerten(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        // TODO: MST-1997: ATTR_MEM_SI_MC_RCV_IMP_ALERT_N need to be updated
        //                 to read from either efd byte 59 or byte 364
        ///
        /// @brief Set the memory alert pull up field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_mem_alert_pullup(const std::vector<uint8_t>& i_spd) const
        {
            // Get the memport relative position
            // The relative_pos() only returns 0 or 1 for this type of function
            // to decide whether to use port0 or port1
            const uint8_t l_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(iv_port);
            uint8_t l_field[mss::ody::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_memalert_pullup_val = 0;
            uint8_t l_memalert_pullup_attr = 0;

            // =========================================================
            // Byte 364: Mem Alert Enable and Pull-Up
            // Attribute: ATTR_MEM_SI_MC_RCV_IMP_ALERT_N
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 96
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > MEM_ALERT_PULL_UP_MAP =
            {
                // {key byte, MEM ALERT PULL UP VALUES (ohms)}
                {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_DISABLE},
                {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_40},
                {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_48},
                {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_60},
                {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_80},
                {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_120},
                {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_240},
                // All others reserved/not used for DDR5

            };

            // Get the appropriate port's attribute value
            if (l_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE, i_spd, SET_MEM_ALERT_PULL_UP,
                                                 l_memalert_pullup_val));
            }
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE, i_spd, SET_MEM_ALERT_PULL_UP,
                                                 l_memalert_pullup_val));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_dimm, MEM_ALERT_PULL_UP_MAP, SET_MEM_ALERT_PULL_UP, l_memalert_pullup_val,
                                        l_memalert_pullup_attr),
                     "%s failed MEM_ALERT_PULL_UP_MAP lookup check", spd::c_str(iv_dimm) );

            // Assign the array with same attr value
            memset(l_field, l_memalert_pullup_attr, mss::ody::sizes::MAX_RANK_PER_DIMM);

            FAPI_TRY(mss::attr::set_si_mc_rcv_imp_alert_n(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the external phy calibration resistor value field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_extcal_res_val(const std::vector<uint8_t>& i_spd) const
        {
            // Get the memport relative position
            // The relative_pos() only returns 0 or 1 for this type of function
            // to decide whether to use port0 or port1
            const uint8_t l_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(iv_port);
            uint8_t l_field = 0;
            uint8_t l_extcalres_val = 0;

            // =========================================================
            // Byte 378: External PHY Calibration Resistor Value
            // Attribute: ATTR_MEM_EFF_EXTCALRESVAL
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 101
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > EXTCALRESVAL_MAP =
            {
                // {key byte, EXT CALIBRATION RESISTOR VAL (ohms)}
                {0b0001, fapi2::ENUM_ATTR_MEM_EFF_EXTCALRESVAL_40_OHM},
                {0b0101, fapi2::ENUM_ATTR_MEM_EFF_EXTCALRESVAL_120_OHM},
                {0b0110, fapi2::ENUM_ATTR_MEM_EFF_EXTCALRESVAL_240_OHM},
                // All others reserved/not used for DDR5
            };

            // Get the appropriate port's attribute value
            if (l_rel_pos == 0)
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_A0_B0_CAL_RESISTOR, i_spd, SET_EXTCALRESVAL, l_field));
            }
            else
            {
                FAPI_TRY(mss::spd::get_field_spd(iv_ocmb, F::PHY_A1_B1_CAL_RESISTOR, i_spd, SET_EXTCALRESVAL, l_field));
            }

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(iv_dimm, EXTCALRESVAL_MAP, SET_EXTCALRESVAL, l_field, l_extcalres_val),
                     "%s failed EXTCALRESVAL_MAP lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_extcalresval(iv_port, l_extcalres_val));

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
            // Bit positions within attribute
            constexpr uint8_t ATTR_CS1 = 6;
            constexpr uint8_t ATTR_CS0 = 7;

            // Bit positions within SPD field
            constexpr uint8_t SPD_B1_CS1 = 0;
            constexpr uint8_t SPD_B1_CS0 = 1;
            constexpr uint8_t SPD_A1_CS1 = 2;
            constexpr uint8_t SPD_A1_CS0 = 3;
            constexpr uint8_t SPD_B0_CS1 = 4;
            constexpr uint8_t SPD_B0_CS0 = 5;
            constexpr uint8_t SPD_A0_CS1 = 6;
            constexpr uint8_t SPD_A0_CS0 = 7;

            const uint8_t l_rel_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(iv_port);
            uint8_t l_num_channel = 0;
            uint8_t l_mirroring = 0;
            fapi2::buffer<uint8_t> l_mirroring_buf;
            fapi2::buffer<uint8_t> l_field;
            uint8_t l_mirror_cha_cs0 = 0;
            uint8_t l_mirror_chb_cs0 = 0;
            uint8_t l_mirror_cha_cs1 = 0;
            uint8_t l_mirror_chb_cs1 = 0;

            // =========================================================
            // Byte 365: Address Mirroring
            // Attribute: ATTR_MEM_DRAM_ADDRESS_MIRRORING
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 96
            // =========================================================
            FAPI_TRY(mss::attr::get_channels_per_dimm(iv_dimm, l_num_channel));

            FAPI_TRY(get_field_spd(iv_ocmb, F::ADDRESS_MIRROR, i_spd, ody::SET_ODY_DRAM_ADDRESS_MIRRORING, l_mirroring));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_address_mirror(l_mirroring),
                                  F::ADDRESS_MIRROR.get_byte(i_spd),
                                  l_mirroring,
                                  ody::SET_ODY_DRAM_ADDRESS_MIRRORING,
                                  "Address Mirror"));

            l_mirroring_buf = l_mirroring;

            // Get the bits from the SPD byte for the port in question
            if (l_rel_pos == 0)
            {
                l_mirror_cha_cs0 = l_mirroring_buf.getBit<SPD_A0_CS0>();
                l_mirror_chb_cs0 = l_mirroring_buf.getBit<SPD_B0_CS0>();
                l_mirror_cha_cs1 = l_mirroring_buf.getBit<SPD_A0_CS1>();
                l_mirror_chb_cs1 = l_mirroring_buf.getBit<SPD_B0_CS1>();
            }
            else
            {
                l_mirror_cha_cs0 = l_mirroring_buf.getBit<SPD_A1_CS0>();
                l_mirror_chb_cs0 = l_mirroring_buf.getBit<SPD_B1_CS0>();
                l_mirror_cha_cs1 = l_mirroring_buf.getBit<SPD_A1_CS1>();
                l_mirror_chb_cs1 = l_mirroring_buf.getBit<SPD_B1_CS1>();
            }

            // First check that our mirroring setting matches between channels if both channels are enabled
            FAPI_ASSERT((l_num_channel != mss::ddr5::ATTR_NUM_CHANNELS) ||
                        (l_mirror_cha_cs0 == l_mirror_chb_cs0),
                        fapi2::MSS_CHANNEL_MIRROR_SETTINGS_MISMATCH_RANK0().
                        set_PORT_TARGET(iv_port).
                        set_VALUE_CHA_CS0(l_mirror_cha_cs0).
                        set_VALUE_CHB_CS0(l_mirror_chb_cs0),
                        GENTARGTIDFORMAT "Mirroring settings mismatch between channels: rank0 CHA/B: %d/%d",
                        GENTARGTID(iv_port), l_mirror_cha_cs0, l_mirror_chb_cs0);

            // First check that our mirroring setting matches between channels if both channels are enabled
            FAPI_ASSERT((l_num_channel != mss::ddr5::ATTR_NUM_CHANNELS) ||
                        (l_mirror_cha_cs1 == l_mirror_chb_cs1),
                        fapi2::MSS_CHANNEL_MIRROR_SETTINGS_MISMATCH_RANK1().
                        set_PORT_TARGET(iv_port).
                        set_VALUE_CHA_CS1(l_mirror_cha_cs1).
                        set_VALUE_CHB_CS1(l_mirror_chb_cs1),
                        GENTARGTIDFORMAT "Mirroring settings mismatch between channels: rank1 CHA/B: %d/%d",
                        GENTARGTID(iv_port), l_mirror_cha_cs1, l_mirror_chb_cs1);

            // Combine the settings between channels so the attribute is set up the same as on DDR4
            l_field.writeBit<ATTR_CS0>(l_mirror_cha_cs0 | l_mirror_chb_cs0);
            l_field.writeBit<ATTR_CS1>(l_mirror_cha_cs1 | l_mirror_chb_cs1);

            FAPI_TRY(mss::attr::set_dram_address_mirroring(iv_dimm, l_field));

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

            // =========================================================
            // Bytes 366~367 Bytes Enables
            // Attribute: ATTR_MEM_EFF_BYTE_ENABLES
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 97
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::BYTE_ENABLES_LSB, i_spd, ody::SET_BYTE_ENABLES, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::BYTE_ENABLES_MSB, i_spd, ody::SET_BYTE_ENABLES, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_byte_enables_lsb(l_byte0),
                                  F::BYTE_ENABLES_LSB.get_byte(i_spd),
                                  l_byte0,
                                  ody::SET_BYTE_ENABLES,
                                  "Byte Enable Byte 0"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_byte_enables_msb(l_byte1),
                                  F::BYTE_ENABLES_MSB.get_byte(i_spd),
                                  l_byte1,
                                  ody::SET_BYTE_ENABLES,
                                  "Byte Enable Byte 1"));

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
            constexpr uint8_t CHA_NIBBLES_START = 22;
            constexpr uint8_t CHB_NIBBLES_START = 12;
            constexpr uint8_t CH_NIBBLE_LEN = 10;

            // =========================================================
            // Bytes 368~371 Nibble Enables
            // Attribute: ATTR_MEM_EFF_NIBBLE_ENABLES
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 98
            // =========================================================
            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_LSB0, i_spd, ody::SET_NIBBLE_ENABLES, l_byte0)) );
            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_MSB0, i_spd, ody::SET_NIBBLE_ENABLES, l_byte1)) );
            FAPI_TRY( (get_field_spd(iv_ocmb, F::NIBBLE_ENABLES_LSB1, i_spd, ody::SET_NIBBLE_ENABLES, l_byte2)) );
            // Note: There is no l_byte3 (MSB1) for this field. We will leave it 0 for when we call right_aligned_insert

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_lsb0(l_byte0),
                                  F::NIBBLE_ENABLES_LSB0.get_byte(i_spd),
                                  l_byte0,
                                  ody::SET_NIBBLE_ENABLES,
                                  "Nibble enables LSB0"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_msb0(l_byte1),
                                  F::NIBBLE_ENABLES_MSB0.get_byte(i_spd),
                                  l_byte1,
                                  ody::SET_NIBBLE_ENABLES,
                                  "Nibble enables MSB0"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_nibble_enables_lsb1(l_byte2),
                                  F::NIBBLE_ENABLES_LSB1.get_byte(i_spd),
                                  l_byte2,
                                  ody::SET_NIBBLE_ENABLES,
                                  "Nibble enables LSB1"));

            right_aligned_insert(l_buffer, l_byte3, l_byte2, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. Nibble Enables: 0x%04x",
                     spd::c_str(iv_dimm),
                     l_field);

            // Set the nibble enables
            FAPI_TRY(mss::attr::set_nibble_enables(iv_dimm, l_field));

            // The PHY handles the nibble enables and number of DQ per channel in an odd way
            // The number of DQ enabled per channel deconfigures the largest DBYTE on the channel
            // The nibble enables disable a specific dbyte
            // For example if a channel has the following nibble enables 0x3fc and 32 bits on the channel,
            //    then two DBYTE's will be disabled: dbyte 0 (missing bits on the right) and the MSB dbyte due to missing 8 bits
            // As such, we only want to decrease DQ on a specific channel for the most significant missing nibbles

            // Set the phy dq enables for ch A
            {
                // Gets the first present nibble
                const auto l_first_nibble_pos = mss::first_bit_set(l_field, CHA_NIBBLES_START);

                // Decreases the number of nibbles on the channel for each deconfigured nibble
                const auto l_num_nibbles = CH_NIBBLE_LEN - (l_first_nibble_pos - CHA_NIBBLES_START);
                const auto l_num_dq = l_num_nibbles * mss::conversions::BITS_PER_NIBBLE;

                // Each nibble is 4 bits, hence 4 times the count is put in the attr
                FAPI_TRY(mss::attr::set_phy_enabled_dq_cha(iv_port, l_num_dq));
            }

            // Set the phy dq enables for ch A
            {
                // Gets the first present nibble
                const auto l_first_nibble_pos = mss::first_bit_set(l_field, CHB_NIBBLES_START);

                // Decreases the number of nibbles on the channel for each deconfigured nibble
                const auto l_num_nibbles = CH_NIBBLE_LEN - (l_first_nibble_pos - CHB_NIBBLES_START);
                const auto l_num_dq = l_num_nibbles * mss::conversions::BITS_PER_NIBBLE;

                // Each nibble is 4 bits, hence 4 times the count is put in the attr
                FAPI_TRY(mss::attr::set_phy_enabled_dq_chb(iv_port, l_num_dq));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the redundant chip select field for channel a0
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_redundant_cs_en(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_redundant_cs_a0 = 0;
            uint8_t l_redundant_cs_b0 = 0;
            uint8_t l_redundant_cs_a1 = 0;
            uint8_t l_redundant_cs_b1 = 0;
            uint8_t l_field = 0;

            // =========================================================
            // Bytes Byte 372: Memory Channel Enable
            // Attribute: ATTR_MEM_EFF_REDUNDANT_CS_EN
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 98
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::REDUNDANT_CS_EN_CHA0, i_spd, ody::SET_REDUNDANT_CS_EN, l_redundant_cs_a0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::REDUNDANT_CS_EN_CHB0, i_spd, ody::SET_REDUNDANT_CS_EN, l_redundant_cs_b0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::REDUNDANT_CS_EN_CHA1, i_spd, ody::SET_REDUNDANT_CS_EN, l_redundant_cs_a1));
            FAPI_TRY(get_field_spd(iv_ocmb, F::REDUNDANT_CS_EN_CHB1, i_spd, ody::SET_REDUNDANT_CS_EN, l_redundant_cs_b1));
            l_field = l_redundant_cs_a0 || l_redundant_cs_b0 || l_redundant_cs_a1 || l_redundant_cs_b1;

            FAPI_TRY(mss::attr::set_ddr5_redundant_cs_en(iv_dimm, l_field));

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
            uint8_t l_field[mss::ody::sizes::MAX_RANK_PER_DIMM] = {0};
            uint8_t l_value = 0;
            uint8_t l_master_ranks_per_dimm = 0;
            uint8_t l_attr_enum_val = 0;
            const uint8_t CHAN0_NIBBLE_10 = 2;

            // =========================================================
            // Bytes 373~376: Spare Device Mapping
            // Attribute: ATTR_MEM_EFF_DIMM_SPARE
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 99
            // =========================================================
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

            // =========================================================
            // Byte 277: SPD Content Revision
            // Attribute: ATTR_MEM_EFF_SPD_CONTENT_REVISION
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 78
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::SPD_CONTENT_REVISION, i_spd, SET_SPD_CONTENT_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_spd_content_revision(l_field),
                                  F::SPD_CONTENT_REVISION.get_byte(i_spd),
                                  l_field,
                                  SET_SPD_CONTENT_REVISION,
                                  "SPD content revision"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_SPD_CONTENT_REVISION, iv_port, l_field));

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

            // =========================================================
            // Byte 294: PMIC0 Supply Voltage and Master Sequence Order
            // Attribute: ATTR_MEM_EFF_PMIC0_SEQUENCE
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 82
            // =========================================================
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

            // =========================================================
            // Byte 198: MFG ID Code, First Byte
            // Attribute: ATTR_MEM_EFF_PMIC0_MFG_ID
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 65
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_MFG_CODE_FIRST, i_spd, pmic::SET_PMIC0_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_MFG_CODE_SECOND, i_spd, pmic::SET_PMIC0_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC0_MFG_CODE_FIRST.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC0_MFG_ID,
                                  "PMIC0 First byte"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC0_MFG_CODE_SECOND.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC0_MFG_ID,
                                  "PMIC0 Second byte"));

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

            // =========================================================
            // Byte 198: MFG ID Code, First Byte
            // Attribute: ATTR_MEM_EFF_PMIC0_MFG_ID
            // DDR5 DDIMM SPD Document Release 1.21
            // Page 65
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_DEVICE_REV_NUM, i_spd, pmic::SET_PMIC0_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC0_DEVICE_REV_NUM.get_byte(i_spd),
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

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_MFG_CODE_FIRST, i_spd, pmic::SET_PMIC1_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_MFG_CODE_SECOND, i_spd, pmic::SET_PMIC1_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC1_MFG_CODE_FIRST.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC1_MFG_ID,
                                  "PMIC1 First byte"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC1_MFG_CODE_SECOND.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC1_MFG_ID,
                                  "PMIC1 Second byte"));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_DEVICE_REV_NUM, i_spd, pmic::SET_PMIC1_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC1_DEVICE_REV_NUM.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_REVISION,
                                  "PMIC1 Revision"));

            FAPI_TRY(mss::attr::set_pmic1_revision(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 sequence field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_sequence(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SEQUENCE, i_spd, pmic::SET_PMIC2_SEQUENCE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_sequence(l_field),
                                  F::PMIC2_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SEQUENCE,
                                  "PMIC2 Sequence"));

            FAPI_TRY(mss::attr::set_pmic2_sequence(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_MFG_CODE_FIRST, i_spd, pmic::SET_PMIC2_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_MFG_CODE_SECOND, i_spd, pmic::SET_PMIC2_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC2_MFG_CODE_FIRST.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC2_MFG_ID,
                                  "PMIC2 First byte"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC2_MFG_CODE_SECOND.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC2_MFG_ID,
                                  "PMIC2 Second byte"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. PMIC Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_ocmb),
                     l_field);

            FAPI_TRY(mss::attr::set_pmic2_mfg_id(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 rev field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_DEVICE_REV_NUM, i_spd, pmic::SET_PMIC2_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC2_DEVICE_REV_NUM.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_REVISION,
                                  "PMIC2 Revision"));

            FAPI_TRY(mss::attr::set_pmic2_revision(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 sequence field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_sequence(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SEQUENCE, i_spd, pmic::SET_PMIC3_SEQUENCE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_sequence(l_field),
                                  F::PMIC3_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SEQUENCE,
                                  "PMIC3 Sequence"));

            FAPI_TRY(mss::attr::set_pmic3_sequence(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_MFG_CODE_FIRST, i_spd, pmic::SET_PMIC3_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_MFG_CODE_SECOND, i_spd, pmic::SET_PMIC3_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_cont_code(l_byte0),
                                  F::PMIC3_MFG_CODE_FIRST.get_byte(i_spd),
                                  l_byte0,
                                  pmic::SET_PMIC3_MFG_ID,
                                  "PMIC3 First byte"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_last_non_zero(l_byte1),
                                  F::PMIC3_MFG_CODE_SECOND.get_byte(i_spd),
                                  l_byte1,
                                  pmic::SET_PMIC3_MFG_ID,
                                  "PMIC3 Second byte"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;
            FAPI_INF("%s. PMIC Manufacturer ID Code: 0x%04x",
                     spd::c_str(iv_ocmb),
                     l_field);

            FAPI_TRY(mss::attr::set_pmic3_mfg_id(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 rev field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_rev(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_DEVICE_REV_NUM, i_spd, pmic::SET_PMIC3_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rev(l_field),
                                  F::PMIC3_DEVICE_REV_NUM.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_REVISION,
                                  "PMIC3 Revision"));

            FAPI_TRY(mss::attr::set_pmic3_revision(iv_ocmb, l_field));

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
        /// @brief Set the pmic0 swa volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_VOLT_RANGE_OFFSET_SWA, i_spd, pmic::SET_PMIC0_SWA_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic0_swa_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic0 swb volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_VOLT_RANGE_OFFSET_SWB, i_spd, pmic::SET_PMIC0_SWB_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic0_swb_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic0 swc volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_VOLT_RANGE_OFFSET_SWC, i_spd, pmic::SET_PMIC0_SWC_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic0_swc_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic0 swd volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_VOLT_RANGE_OFFSET_SWD, i_spd, pmic::SET_PMIC0_SWD_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic0_swd_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic1 swa volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_VOLT_RANGE_OFFSET_SWA, i_spd, pmic::SET_PMIC1_SWA_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic1_swa_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic1 swb volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_VOLT_RANGE_OFFSET_SWB, i_spd, pmic::SET_PMIC1_SWB_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic1_swb_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic1 swc volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_VOLT_RANGE_OFFSET_SWC, i_spd, pmic::SET_PMIC1_SWC_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic1_swc_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic1 swd volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_VOLT_RANGE_OFFSET_SWD, i_spd, pmic::SET_PMIC1_SWD_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic1_swd_voltage_coarse_offset(iv_ocmb, l_field));

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
        /// @brief Set the pmic2 swa volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_VOLT_SET, i_spd, pmic::SET_PMIC2_SWA_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC2_SWA_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWA_VOLTAGE_SETTING,
                                  "PMIC2 SWA voltage settting"));

            FAPI_TRY(mss::attr::set_pmic2_swa_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_RANGE_SELECT, i_spd, pmic::SET_PMIC2_SWA_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC2_SWA_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWA_VOLTAGE_RANGE_SELECT,
                                  "PMIC2 SWA range select"));

            FAPI_TRY(mss::attr::set_pmic2_swa_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_VOLT_RANGE_OFFSET_SWA, i_spd, pmic::SET_PMIC2_SWA_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic2_swa_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_VOLT_OFF, i_spd, pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_OFF_DIRECTION, i_spd, pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWA_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET,
                                  "PMIC2 SWA offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC2_SWA_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC2_SWA_VOLTAGE_OFFSET,
                                  "PMIC2 SWA offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic2_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_DELAY, i_spd, pmic::SET_PMIC2_SWA_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC2_SWA_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWA_SEQUENCE_DELAY,
                                  "PMIC2 SWA delay"));

            FAPI_TRY(mss::attr::set_pmic2_swa_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_ORDER, i_spd, pmic::SET_PMIC2_SWA_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWA_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWA_SEQUENCE_ORDER,
                                  "PMIC2 SWA order"));

            FAPI_TRY(mss::attr::set_pmic2_swa_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_VOLT_SET, i_spd, pmic::SET_PMIC2_SWB_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC2_SWB_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWB_VOLTAGE_SETTING,
                                  "PMIC2 SWB voltage settting"));

            FAPI_TRY(mss::attr::set_pmic2_swb_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_RANGE_SELECT, i_spd, pmic::SET_PMIC2_SWB_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC2_SWB_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWB_VOLTAGE_RANGE_SELECT,
                                  "PMIC2 SWB range select"));

            FAPI_TRY(mss::attr::set_pmic2_swb_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_VOLT_RANGE_OFFSET_SWB, i_spd, pmic::SET_PMIC2_SWB_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic2_swb_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_VOLT_OFF, i_spd, pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_OFF_DIRECTION, i_spd, pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWB_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET,
                                  "PMIC2 SWB offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC2_SWB_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC2_SWB_VOLTAGE_OFFSET,
                                  "PMIC2 SWB offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic2_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_DELAY, i_spd, pmic::SET_PMIC2_SWB_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC2_SWB_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWB_SEQUENCE_DELAY,
                                  "PMIC2 SWB delay"));

            FAPI_TRY(mss::attr::set_pmic2_swb_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_ORDER, i_spd, pmic::SET_PMIC2_SWB_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWB_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWB_SEQUENCE_ORDER,
                                  "PMIC2 SWB order"));

            FAPI_TRY(mss::attr::set_pmic2_swb_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_VOLT_SET, i_spd, pmic::SET_PMIC2_SWC_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC2_SWC_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWC_VOLTAGE_SETTING,
                                  "PMIC2 SWC voltage settting"));

            FAPI_TRY(mss::attr::set_pmic2_swc_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_RANGE_SELECT, i_spd, pmic::SET_PMIC2_SWC_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC2_SWC_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWC_VOLTAGE_RANGE_SELECT,
                                  "PMIC2 SWC range select"));

            FAPI_TRY(mss::attr::set_pmic2_swc_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_VOLT_RANGE_OFFSET_SWC, i_spd, pmic::SET_PMIC2_SWC_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic2_swc_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_VOLT_OFF, i_spd, pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_OFF_DIRECTION, i_spd, pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWC_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET,
                                  "PMIC2 SWC offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC2_SWC_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC2_SWC_VOLTAGE_OFFSET,
                                  "PMIC2 SWC offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic2_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_DELAY, i_spd, pmic::SET_PMIC2_SWC_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC2_SWC_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWC_SEQUENCE_DELAY,
                                  "PMIC2 SWC delay"));

            FAPI_TRY(mss::attr::set_pmic2_swc_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_ORDER, i_spd, pmic::SET_PMIC2_SWC_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWC_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWC_SEQUENCE_ORDER,
                                  "PMIC2 SWC order"));

            FAPI_TRY(mss::attr::set_pmic2_swc_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_VOLT_SET, i_spd, pmic::SET_PMIC2_SWD_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC2_SWD_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWD_VOLTAGE_SETTING,
                                  "PMIC2 SWD voltage settting"));

            FAPI_TRY(mss::attr::set_pmic2_swd_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_RANGE_SELECT, i_spd, pmic::SET_PMIC2_SWD_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC2_SWD_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWD_VOLTAGE_RANGE_SELECT,
                                  "PMIC2 SWD range select"));

            FAPI_TRY(mss::attr::set_pmic2_swd_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_VOLT_RANGE_OFFSET_SWD, i_spd, pmic::SET_PMIC2_SWD_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic2_swd_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_VOLT_OFF, i_spd, pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_OFF_DIRECTION, i_spd, pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC2_SWD_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET,
                                  "PMIC2 SWD offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC2_SWD_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC2_SWD_VOLTAGE_OFFSET,
                                  "PMIC2 SWD offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic2_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_DELAY, i_spd, pmic::SET_PMIC2_SWD_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC2_SWD_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWD_SEQUENCE_DELAY,
                                  "PMIC2 SWD delay"));

            FAPI_TRY(mss::attr::set_pmic2_swd_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_ORDER, i_spd, pmic::SET_PMIC2_SWD_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWD_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SWD_SEQUENCE_ORDER,
                                  "PMIC2 SWD order"));

            FAPI_TRY(mss::attr::set_pmic2_swd_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 phase combin field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_phase_combin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_PHASE_COMBIN, i_spd, pmic::SET_PMIC2_PHASE_COMB, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_phase_combin(l_field),
                                  F::PMIC2_PHASE_COMBIN.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_PHASE_COMB,
                                  "PMIC2 phase comb"));

            FAPI_TRY(mss::attr::set_pmic2_phase_comb(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic3 swa volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_VOLT_SET, i_spd, pmic::SET_PMIC3_SWA_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC3_SWA_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWA_VOLTAGE_SETTING,
                                  "PMIC3 SWA voltage settting"));

            FAPI_TRY(mss::attr::set_pmic3_swa_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_RANGE_SELECT, i_spd, pmic::SET_PMIC3_SWA_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC3_SWA_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWA_VOLTAGE_RANGE_SELECT,
                                  "PMIC3 SWA range select"));

            FAPI_TRY(mss::attr::set_pmic3_swa_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_VOLT_RANGE_OFFSET_SWA, i_spd, pmic::SET_PMIC3_SWA_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic3_swa_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_VOLT_OFF, i_spd, pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_OFF_DIRECTION, i_spd, pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWA_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET,
                                  "PMIC3 SWA offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC3_SWA_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC3_SWA_VOLTAGE_OFFSET,
                                  "PMIC3 SWA offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic3_swa_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_DELAY, i_spd, pmic::SET_PMIC3_SWA_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC3_SWA_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWA_SEQUENCE_DELAY,
                                  "PMIC3 SWA delay"));

            FAPI_TRY(mss::attr::set_pmic3_swa_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_ORDER, i_spd, pmic::SET_PMIC3_SWA_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWA_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWA_SEQUENCE_ORDER,
                                  "PMIC3 SWA order"));

            FAPI_TRY(mss::attr::set_pmic3_swa_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_VOLT_SET, i_spd, pmic::SET_PMIC3_SWB_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC3_SWB_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWB_VOLTAGE_SETTING,
                                  "PMIC3 SWB voltage settting"));

            FAPI_TRY(mss::attr::set_pmic3_swb_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_RANGE_SELECT, i_spd, pmic::SET_PMIC3_SWB_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC3_SWB_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWB_VOLTAGE_RANGE_SELECT,
                                  "PMIC3 SWB range select"));

            FAPI_TRY(mss::attr::set_pmic3_swb_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_VOLT_RANGE_OFFSET_SWB, i_spd, pmic::SET_PMIC3_SWB_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic3_swb_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_VOLT_OFF, i_spd, pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_OFF_DIRECTION, i_spd, pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWB_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET,
                                  "PMIC3 SWB offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC3_SWB_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC3_SWB_VOLTAGE_OFFSET,
                                  "PMIC3 SWB offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic3_swb_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_DELAY, i_spd, pmic::SET_PMIC3_SWB_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC3_SWB_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWB_SEQUENCE_DELAY,
                                  "PMIC3 SWB delay"));

            FAPI_TRY(mss::attr::set_pmic3_swb_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_ORDER, i_spd, pmic::SET_PMIC3_SWB_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWB_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWB_SEQUENCE_ORDER,
                                  "PMIC3 SWB order"));

            FAPI_TRY(mss::attr::set_pmic3_swb_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_VOLT_SET, i_spd, pmic::SET_PMIC3_SWC_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC3_SWC_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWC_VOLTAGE_SETTING,
                                  "PMIC3 SWC voltage settting"));

            FAPI_TRY(mss::attr::set_pmic3_swc_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_RANGE_SELECT, i_spd, pmic::SET_PMIC3_SWC_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC3_SWC_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWC_VOLTAGE_RANGE_SELECT,
                                  "PMIC3 SWC range select"));

            FAPI_TRY(mss::attr::set_pmic3_swc_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_VOLT_RANGE_OFFSET_SWC, i_spd, pmic::SET_PMIC3_SWC_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic3_swc_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_VOLT_OFF, i_spd, pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_OFF_DIRECTION, i_spd, pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWC_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET,
                                  "PMIC3 SWC offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC3_SWC_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC3_SWC_VOLTAGE_OFFSET,
                                  "PMIC3 SWC offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic3_swc_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_DELAY, i_spd, pmic::SET_PMIC3_SWC_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC3_SWC_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWC_SEQUENCE_DELAY,
                                  "PMIC3 SWC delay"));

            FAPI_TRY(mss::attr::set_pmic3_swc_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_ORDER, i_spd, pmic::SET_PMIC3_SWC_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWC_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWC_SEQUENCE_ORDER,
                                  "PMIC3 SWC order"));

            FAPI_TRY(mss::attr::set_pmic3_swc_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd volt set field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_volt_set(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_VOLT_SET, i_spd, pmic::SET_PMIC3_SWD_VOLTAGE_SETTING, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_set(l_field),
                                  F::PMIC3_SWD_VOLT_SET.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWD_VOLTAGE_SETTING,
                                  "PMIC3 SWD voltage settting"));

            FAPI_TRY(mss::attr::set_pmic3_swd_voltage_setting(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd range select field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_range_select(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_RANGE_SELECT, i_spd, pmic::SET_PMIC3_SWD_VOLTAGE_RANGE_SELECT, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_range_select(l_field),
                                  F::PMIC3_SWD_RANGE_SELECT.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWD_VOLTAGE_RANGE_SELECT,
                                  "PMIC3 SWD range select"));

            FAPI_TRY(mss::attr::set_pmic3_swd_voltage_range_select(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd volt coarse offset field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_volt_coarse_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_VOLT_RANGE_OFFSET_SWD, i_spd, pmic::SET_PMIC3_SWD_VOLTAGE_COARSE_OFFSET,
                                   l_field));

            FAPI_TRY(mss::attr::set_pmic3_swd_voltage_coarse_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd volt off field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_volt_off(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_offset = 0;
            uint8_t l_direction = 0;

            int8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_VOLT_OFF, i_spd, pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET, l_offset));
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_OFF_DIRECTION, i_spd, pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET, l_direction));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_volt_off(l_offset),
                                  F::PMIC3_SWD_VOLT_OFF.get_byte(i_spd),
                                  l_offset,
                                  pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET,
                                  "PMIC3 SWD offset"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_off_direction(l_direction),
                                  F::PMIC3_SWD_OFF_DIRECTION.get_byte(i_spd),
                                  l_direction,
                                  pmic::SET_PMIC3_SWD_VOLTAGE_OFFSET,
                                  "PMIC3 SWD offset direction"));

            l_field = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

            FAPI_TRY(mss::attr::set_pmic3_swd_voltage_offset(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd delay field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_delay(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_DELAY, i_spd, pmic::SET_PMIC3_SWD_SEQUENCE_DELAY, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_delay(l_field),
                                  F::PMIC3_SWD_DELAY.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWD_SEQUENCE_DELAY,
                                  "PMIC3 SWD delay"));

            FAPI_TRY(mss::attr::set_pmic3_swd_sequence_delay(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd order field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_ORDER, i_spd, pmic::SET_PMIC3_SWD_SEQUENCE_ORDER, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWD_ORDER.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SWD_SEQUENCE_ORDER,
                                  "PMIC3 SWD order"));

            FAPI_TRY(mss::attr::set_pmic3_swd_sequence_order(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the pmic3 phase combin field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_phase_combin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_PHASE_COMBIN, i_spd, pmic::SET_PMIC3_PHASE_COMB, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_phase_combin(l_field),
                                  F::PMIC3_PHASE_COMBIN.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_PHASE_COMB,
                                  "PMIC3 phase comb"));

            FAPI_TRY(mss::attr::set_pmic3_phase_comb(iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_0_AVAIL, i_spd, ody::SET_THERM_SENSOR_0_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_avail(l_field),
                                  F::THERMAL_SENSOR_0_AVAIL.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_0_AVAIL,
                                  "Thermal Sensor 0 Availability"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL, iv_ocmb, l_field));

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

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_0_USAGE, i_spd, ody::SET_THERM_SENSOR_0_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_usage(l_field),
                                  F::THERMAL_SENSOR_0_USAGE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_0_USAGE,
                                  "Thermal Sensor 0 Usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC :
                      l_field;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_USAGE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_0_TYPE, i_spd, ody::SET_THERM_SENSOR_0_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_type(l_field),
                                  F::THERMAL_SENSOR_0_TYPE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_0_TYPE,
                                  "Thermal Sensor 0 Type"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_TYPE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_0_I2C_ADDRESS, i_spd, ody::SET_THERM_SENSOR_0_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_i2c_address(l_field),
                                  F::THERMAL_SENSOR_0_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_0_I2C_ADDR,
                                  "Thermal Sensor 0 I2C addr"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_I2C_ADDR, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_0_LOCATION, i_spd, ody::SET_THERM_SENSOR_0_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_location(l_field),
                                  F::THERMAL_SENSOR_0_LOCATION.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_0_LOCATION,
                                  "Thermal Sensor 0 Location"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_LOCATION, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_1_AVAIL, i_spd, ody::SET_THERM_SENSOR_1_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_avail(l_field),
                                  F::THERMAL_SENSOR_1_AVAIL.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_1_AVAIL,
                                  "Thermal Sensor 1 Avail"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_AVAIL, iv_ocmb, l_field));

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

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_1_USAGE, i_spd, ody::SET_THERM_SENSOR_1_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_usage(l_field),
                                  F::THERMAL_SENSOR_1_USAGE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_1_USAGE,
                                  "Thermal Sensor 1 usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_PMIC :
                      l_field;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_USAGE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_1_TYPE, i_spd, ody::SET_THERM_SENSOR_1_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_type(l_field),
                                  F::THERMAL_SENSOR_1_TYPE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_1_TYPE,
                                  "Thermal Sensor 1 type"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_TYPE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_1_I2C_ADDRESS, i_spd, ody::SET_THERM_SENSOR_1_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_i2c_address(l_field),
                                  F::THERMAL_SENSOR_1_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_1_I2C_ADDR,
                                  "Thermal Sensor 1 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_I2C_ADDR, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_1_LOCATION, i_spd, ody::SET_THERM_SENSOR_1_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_location(l_field),
                                  F::THERMAL_SENSOR_1_LOCATION.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_1_LOCATION,
                                  "Thermal Sensor 1 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_LOCATION, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 2 avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_2_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_2_AVAIL, i_spd, ody::SET_THERM_SENSOR_2_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_avail(l_field),
                                  F::THERMAL_SENSOR_2_AVAIL.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_2_AVAIL,
                                  "Thermal Sensor 2 Avail"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_2_AVAIL, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the therm sensor 2 usage field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_2_usage(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            // This attribute enum no longer exists, so we can use a constexpr
            constexpr uint8_t THERM_SENSOR_USAGE_DRAM_AND_PMIC = 0x03;

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_2_USAGE, i_spd, ody::SET_THERM_SENSOR_2_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_usage(l_field),
                                  F::THERMAL_SENSOR_2_USAGE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_2_USAGE,
                                  "Thermal Sensor 2 usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_2_USAGE_PMIC :
                      l_field;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_2_USAGE, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 2 type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_2_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_2_TYPE, i_spd, ody::SET_THERM_SENSOR_2_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_type(l_field),
                                  F::THERMAL_SENSOR_2_TYPE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_2_TYPE,
                                  "Thermal Sensor 2 type"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_2_TYPE, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 2 i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_2_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_2_I2C_ADDRESS, i_spd, ody::SET_THERM_SENSOR_2_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_i2c_address(l_field),
                                  F::THERMAL_SENSOR_2_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_2_I2C_ADDR,
                                  "Thermal Sensor 2 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_2_I2C_ADDR, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 2 location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_2_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_2_LOCATION, i_spd, ody::SET_THERM_SENSOR_2_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_location(l_field),
                                  F::THERMAL_SENSOR_2_LOCATION.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_2_LOCATION,
                                  "Thermal Sensor 2 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_2_LOCATION, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 3 avail field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_3_avail(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_3_AVAIL, i_spd, ody::SET_THERM_SENSOR_3_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_avail(l_field),
                                  F::THERMAL_SENSOR_3_AVAIL.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_3_AVAIL,
                                  "Thermal Sensor 3 Avail"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_3_AVAIL, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the therm sensor 3 usage field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_3_usage(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            // This attribute enum no longer exists, so we can use a constexpr
            constexpr uint8_t THERM_SENSOR_USAGE_DRAM_AND_PMIC = 0x03;

            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_3_USAGE, i_spd, ody::SET_THERM_SENSOR_3_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_usage(l_field),
                                  F::THERMAL_SENSOR_3_USAGE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_3_USAGE,
                                  "Thermal Sensor 3 usage"));

            // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
            l_field = (l_field == THERM_SENSOR_USAGE_DRAM_AND_PMIC ) ?
                      fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_3_USAGE_PMIC :
                      l_field;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_3_USAGE, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 3 type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_3_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_3_TYPE, i_spd, ody::SET_THERM_SENSOR_3_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_type(l_field),
                                  F::THERMAL_SENSOR_3_TYPE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_3_TYPE,
                                  "Thermal Sensor 3 type"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_3_TYPE, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 3 i2c address field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_3_i2c_address(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_3_I2C_ADDRESS, i_spd, ody::SET_THERM_SENSOR_3_I2C_ADDR, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_i2c_address(l_field),
                                  F::THERMAL_SENSOR_3_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_3_I2C_ADDR,
                                  "Thermal Sensor 3 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_3_I2C_ADDR, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the therm sensor 3 location field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_therm_sensor_3_location(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_3_LOCATION, i_spd, ody::SET_THERM_SENSOR_3_LOCATION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_location(l_field),
                                  F::THERMAL_SENSOR_3_LOCATION.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_3_LOCATION,
                                  "Thermal Sensor 3 I2C Address"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_3_LOCATION, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_DIFF_AVAIL, i_spd, ody::SET_THERM_SENSOR_DIFF_AVAIL, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_avail(l_field),
                                  F::THERMAL_SENSOR_DIFF_AVAIL.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_DIFF_AVAIL,
                                  "Thermal Sensor Diff Avail"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_AVAIL, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_DIFF_USAGE, i_spd, ody::SET_THERM_SENSOR_DIFF_USAGE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_usage(l_field),
                                  F::THERMAL_SENSOR_DIFF_USAGE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_DIFF_USAGE,
                                  "Thermal Sensor Diff Usage"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_DIFF_TYPE, i_spd, ody::SET_THERM_SENSOR_DIFF_TYPE, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_type(l_field),
                                  F::THERMAL_SENSOR_DIFF_TYPE.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_DIFF_TYPE,
                                  "Thermal Sensor Diff Type"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_TYPE, iv_ocmb, l_field));

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
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERMAL_SENSOR_DIFF_I2C_ADDRESS, i_spd, ody::SET_THERM_SENSOR_DIFF_I2C_ADDR,
                                   l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_therm_sensor_diff_i2c_address(l_field),
                                  F::THERMAL_SENSOR_DIFF_I2C_ADDRESS.get_byte(i_spd),
                                  l_field,
                                  ody::SET_THERM_SENSOR_DIFF_I2C_ADDR,
                                  "Thermal Sensor Diff I2C Addr"));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_I2C_ADDR, iv_ocmb, l_field));

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
            FAPI_INF("%s.DRAM Manufacturer ID Code: 0x%04x",
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
            FAPI_TRY(get_field_spd(iv_ocmb, F::MODULE_RCD, i_spd, ody::SET_SUPPORTED_RCD, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_rcd(l_field),
                                  F::MODULE_RCD.get_byte(i_spd),
                                  l_field,
                                  ody::SET_SUPPORTED_RCD,
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
            FAPI_INF("%s. RCD Manufacturer ID Code: 0x%04x",
                     mss::spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_rcd_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the 11s serial number field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_serial_number(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field[F::SERIAL_NUMBER_LEN] = {0};

            for ( uint64_t l_count = 0; l_count < F::SERIAL_NUMBER_LEN; l_count++)
            {
                FAPI_TRY(get_field_spd(iv_ocmb, F::SERIAL_NUMBER_FIELDS[l_count], i_spd, SET_EFF_DIMM_SERIAL_NUMBER, l_field[l_count]));
            }

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_DIMM_SERIAL_NUMBER, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the raw card reference design revision number
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_raw_card_reference_design(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DESIGN_REF_CARD, i_spd, SET_EFF_DIMM_RAW_CARD_REF_DESIGN_REV, l_field));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_DIMM_RAW_CARD_REFERENCE_DESIGN, iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the raw card design revision number
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_raw_card_design_revision(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::DESIGN_REV, i_spd, SET_EFF_DIMM_RAW_CARD_DESIGN_REVISION, l_field));

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_DIMM_RAW_CARD_DESIGN_REVISION, iv_ocmb, l_field));

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
            FAPI_TRY(set_module_base_height(i_spd));
            FAPI_TRY(set_mod_thermal_sensor(i_spd));
            FAPI_TRY(set_mem_alert_en(i_spd));
            FAPI_TRY(set_mem_alert_pullup(i_spd));
            FAPI_TRY(set_extcal_res_val(i_spd));
            FAPI_TRY(set_address_mirror(i_spd));
            FAPI_TRY(set_byte_enables(i_spd));
            FAPI_TRY(set_nibble_enables(i_spd));
            FAPI_TRY(set_redundant_cs_en(i_spd));
            FAPI_TRY(set_dimm_spare(i_spd));
            FAPI_TRY(set_spd_content_revision(i_spd));
            FAPI_TRY(set_pmic0_sequence(i_spd));
            FAPI_TRY(set_pmic0_mfg_id(i_spd));
            FAPI_TRY(set_pmic0_rev(i_spd));
            FAPI_TRY(set_pmic1_sequence(i_spd));
            FAPI_TRY(set_pmic1_mfg_id(i_spd));
            FAPI_TRY(set_pmic1_rev(i_spd));
            FAPI_TRY(set_pmic2_sequence(i_spd));
            FAPI_TRY(set_pmic2_mfg_id(i_spd));
            FAPI_TRY(set_pmic2_rev(i_spd));
            FAPI_TRY(set_pmic3_sequence(i_spd));
            FAPI_TRY(set_pmic3_mfg_id(i_spd));
            FAPI_TRY(set_pmic3_rev(i_spd));
            FAPI_TRY(set_pmic0_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swa_range_select(i_spd));
            FAPI_TRY(set_pmic0_swa_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic0_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swa_delay(i_spd));
            FAPI_TRY(set_pmic0_swa_order(i_spd));
            FAPI_TRY(set_pmic0_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swb_range_select(i_spd));
            FAPI_TRY(set_pmic0_swb_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic0_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swb_delay(i_spd));
            FAPI_TRY(set_pmic0_swb_order(i_spd));
            FAPI_TRY(set_pmic0_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swc_range_select(i_spd));
            FAPI_TRY(set_pmic0_swc_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic0_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swc_delay(i_spd));
            FAPI_TRY(set_pmic0_swc_order(i_spd));
            FAPI_TRY(set_pmic0_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic0_swd_range_select(i_spd));
            FAPI_TRY(set_pmic0_swd_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic0_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic0_swd_delay(i_spd));
            FAPI_TRY(set_pmic0_swd_order(i_spd));
            FAPI_TRY(set_pmic0_phase_combin(i_spd));
            FAPI_TRY(set_pmic1_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swa_range_select(i_spd));
            FAPI_TRY(set_pmic1_swa_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic1_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swa_delay(i_spd));
            FAPI_TRY(set_pmic1_swa_order(i_spd));
            FAPI_TRY(set_pmic1_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swb_range_select(i_spd));
            FAPI_TRY(set_pmic1_swb_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic1_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swb_delay(i_spd));
            FAPI_TRY(set_pmic1_swb_order(i_spd));
            FAPI_TRY(set_pmic1_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swc_range_select(i_spd));
            FAPI_TRY(set_pmic1_swc_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic1_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swc_delay(i_spd));
            FAPI_TRY(set_pmic1_swc_order(i_spd));
            FAPI_TRY(set_pmic1_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic1_swd_range_select(i_spd));
            FAPI_TRY(set_pmic1_swd_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic1_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic1_swd_delay(i_spd));
            FAPI_TRY(set_pmic1_swd_order(i_spd));
            FAPI_TRY(set_pmic1_phase_combin(i_spd));
            FAPI_TRY(set_pmic2_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic2_swa_range_select(i_spd));
            FAPI_TRY(set_pmic2_swa_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic2_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic2_swa_delay(i_spd));
            FAPI_TRY(set_pmic2_swa_order(i_spd));
            FAPI_TRY(set_pmic2_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic2_swb_range_select(i_spd));
            FAPI_TRY(set_pmic2_swb_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic2_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic2_swb_delay(i_spd));
            FAPI_TRY(set_pmic2_swb_order(i_spd));
            FAPI_TRY(set_pmic2_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic2_swc_range_select(i_spd));
            FAPI_TRY(set_pmic2_swc_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic2_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic2_swc_delay(i_spd));
            FAPI_TRY(set_pmic2_swc_order(i_spd));
            FAPI_TRY(set_pmic2_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic2_swd_range_select(i_spd));
            FAPI_TRY(set_pmic2_swd_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic2_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic2_swd_delay(i_spd));
            FAPI_TRY(set_pmic2_swd_order(i_spd));
            FAPI_TRY(set_pmic2_phase_combin(i_spd));
            FAPI_TRY(set_pmic3_swa_volt_set(i_spd));
            FAPI_TRY(set_pmic3_swa_range_select(i_spd));
            FAPI_TRY(set_pmic3_swa_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic3_swa_volt_off(i_spd));
            FAPI_TRY(set_pmic3_swa_delay(i_spd));
            FAPI_TRY(set_pmic3_swa_order(i_spd));
            FAPI_TRY(set_pmic3_swb_volt_set(i_spd));
            FAPI_TRY(set_pmic3_swb_range_select(i_spd));
            FAPI_TRY(set_pmic3_swb_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic3_swb_volt_off(i_spd));
            FAPI_TRY(set_pmic3_swb_delay(i_spd));
            FAPI_TRY(set_pmic3_swb_order(i_spd));
            FAPI_TRY(set_pmic3_swc_volt_set(i_spd));
            FAPI_TRY(set_pmic3_swc_range_select(i_spd));
            FAPI_TRY(set_pmic3_swc_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic3_swc_volt_off(i_spd));
            FAPI_TRY(set_pmic3_swc_delay(i_spd));
            FAPI_TRY(set_pmic3_swc_order(i_spd));
            FAPI_TRY(set_pmic3_swd_volt_set(i_spd));
            FAPI_TRY(set_pmic3_swd_range_select(i_spd));
            FAPI_TRY(set_pmic3_swd_volt_coarse_off(i_spd));
            FAPI_TRY(set_pmic3_swd_volt_off(i_spd));
            FAPI_TRY(set_pmic3_swd_delay(i_spd));
            FAPI_TRY(set_pmic3_swd_order(i_spd));
            FAPI_TRY(set_pmic3_phase_combin(i_spd));
            FAPI_TRY(set_therm_sensor_0_avail(i_spd));
            FAPI_TRY(set_therm_sensor_0_usage(i_spd));
            FAPI_TRY(set_therm_sensor_0_type(i_spd));
            FAPI_TRY(set_therm_sensor_0_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_0_location(i_spd));
            FAPI_TRY(set_therm_sensor_1_avail(i_spd));
            FAPI_TRY(set_therm_sensor_1_usage(i_spd));
            FAPI_TRY(set_therm_sensor_1_type(i_spd));
            FAPI_TRY(set_therm_sensor_1_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_1_location(i_spd));
            FAPI_TRY(set_therm_sensor_2_avail(i_spd));
            FAPI_TRY(set_therm_sensor_2_usage(i_spd));
            FAPI_TRY(set_therm_sensor_2_type(i_spd));
            FAPI_TRY(set_therm_sensor_2_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_2_location(i_spd));
            FAPI_TRY(set_therm_sensor_3_avail(i_spd));
            FAPI_TRY(set_therm_sensor_3_usage(i_spd));
            FAPI_TRY(set_therm_sensor_3_type(i_spd));
            FAPI_TRY(set_therm_sensor_3_i2c_address(i_spd));
            FAPI_TRY(set_therm_sensor_3_location(i_spd));
            FAPI_TRY(set_therm_sensor_diff_avail(i_spd));
            FAPI_TRY(set_therm_sensor_diff_usage(i_spd));
            FAPI_TRY(set_therm_sensor_diff_type(i_spd));
            FAPI_TRY(set_therm_sensor_diff_i2c_address(i_spd));
            FAPI_TRY(set_module_rcd(i_spd));
            FAPI_TRY(set_module_mfg_id(i_spd));
            FAPI_TRY(set_dram_mfg_id(i_spd));
            FAPI_TRY(set_rcd_mfg_id(i_spd));
            FAPI_TRY(set_serial_number(i_spd));
            FAPI_TRY(set_raw_card_reference_design(i_spd));
            FAPI_TRY(set_raw_card_design_revision(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Class for DDIMM SPD Rev 0.7
///
class ddimm_0_7 : public ddimm_0_0
{
        using F = mss::spd::fields<DDR5, DDIMM_MODULE>;

    public:
        ///
        /// @brief Construct a new ddimm rev 0.7 object
        ///
        /// @param[in] i_dimm
        ///
        ddimm_0_7(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) : ddimm_0_0(i_dimm)
        {
        }

        virtual ~ddimm_0_7() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const override
        {
            return mss::spd::rev::V0_7;
        }

        ///
        /// @brief Set the pmic0 swa order field to write to PMIC0 reg R40
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWA_SEQUENCE, i_spd, pmic::SET_PMIC0_SEQUENCE_CFG0_R40, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWA_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SEQUENCE_CFG0_R40,
                                  "PMIC0 SEQUENCE CFG0 R40"));

            // Write reserved/invalid(0x0f) value to the attributes that are used in SPD rev 0.0
            // Combination of reserved value and DDR5 dram_gen triggers pmic_enable to use the
            // sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic0_swa_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic0_sequence_cfg0_r40(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swb order field to write to PMIC0 reg R40
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWB_SEQUENCE, i_spd, pmic::SET_PMIC0_SEQUENCE_CFG1_R41, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWB_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SEQUENCE_CFG1_R41,
                                  "PMIC0 SEQUENCE CFG1 R41"));
            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic0_swb_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic0_sequence_cfg1_r41(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swc order field to write to PMIC0 reg R40
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWC_SEQUENCE, i_spd, pmic::SET_PMIC0_SEQUENCE_CFG2_R42, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWC_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SEQUENCE_CFG2_R42,
                                  "PMIC0 SEQUENCE CFG2 R42"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic0_swc_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic0_sequence_cfg2_r42(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic0 swd order field to write to PMIC0 reg R40
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic0_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC0_SWD_SEQUENCE, i_spd, pmic::SET_PMIC0_SEQUENCE_CFG3_R43, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC0_SWD_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC0_SEQUENCE_CFG3_R43,
                                  "PMIC0 SEQUENCE CFG3 R43"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic0_swd_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic0_sequence_cfg3_r43(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swa order field to write to PMIC1 reg R41
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWA_SEQUENCE, i_spd, pmic::SET_PMIC1_SEQUENCE_CFG0_R40, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWA_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SEQUENCE_CFG0_R40,
                                  "PMIC1 SEQUENCE CFG0 R40"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic1_swa_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic1_sequence_cfg0_r40(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swb order field to write to PMIC1 reg R41
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWB_SEQUENCE, i_spd, pmic::SET_PMIC1_SEQUENCE_CFG1_R41, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWB_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SEQUENCE_CFG1_R41,
                                  "PMIC1 SEQUENCE CFG1 R41"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic1_swb_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic1_sequence_cfg1_r41(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swc order field to write to PMIC1 reg R42
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWC_SEQUENCE, i_spd, pmic::SET_PMIC1_SEQUENCE_CFG2_R42, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWC_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SEQUENCE_CFG2_R42,
                                  "PMIC1 SEQUENCE CFG2 R42"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic1_swc_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic1_sequence_cfg2_r42(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic1 swd order field to write to PMIC1 reg R41
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic1_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC1_SWD_SEQUENCE, i_spd, pmic::SET_PMIC1_SEQUENCE_CFG3_R43, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC1_SWD_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC1_SEQUENCE_CFG3_R43,
                                  "PMIC1 SEQUENCE CFG3 R43"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic1_swd_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic1_sequence_cfg3_r43(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swa order field to write to PMIC2 reg R42
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWA_SEQUENCE, i_spd, pmic::SET_PMIC2_SEQUENCE_CFG0_R40, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWA_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SEQUENCE_CFG0_R40,
                                  "PMIC2 SEQUENCE CFG0 R40"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic2_swa_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic2_sequence_cfg0_r40(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swb order field to write to PMIC2 reg R42
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWB_SEQUENCE, i_spd, pmic::SET_PMIC2_SEQUENCE_CFG1_R41, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWB_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SEQUENCE_CFG1_R41,
                                  "PMIC2 SEQUENCE CFG1 R41"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic2_swb_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic2_sequence_cfg1_r41(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swc order field to write to PMIC2 reg R42
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWC_SEQUENCE, i_spd, pmic::SET_PMIC2_SEQUENCE_CFG2_R42, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWC_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SEQUENCE_CFG2_R42,
                                  "PMIC2 SEQUENCE CFG2 R42"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic2_swc_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic2_sequence_cfg2_r42(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic2 swd order field to write to PMIC2 reg R42
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic2_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC2_SWD_SEQUENCE, i_spd, pmic::SET_PMIC2_SEQUENCE_CFG3_R43, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC2_SWD_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC2_SEQUENCE_CFG3_R43,
                                  "PMIC2 SEQUENCE CFG3 R43"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            FAPI_TRY(mss::attr::set_pmic2_swd_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic2_sequence_cfg3_r43(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swa order field to write to PMIC3 reg R43
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swa_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWA_SEQUENCE, i_spd, pmic::SET_PMIC3_SEQUENCE_CFG0_R40, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWA_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SEQUENCE_CFG0_R40,
                                  "PMIC3 SEQUENCE CFG0 R40"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic3_swa_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic3_sequence_cfg0_r40(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swb order field to write to PMIC3 reg R43
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swb_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWB_SEQUENCE, i_spd, pmic::SET_PMIC3_SEQUENCE_CFG1_R41, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWB_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SEQUENCE_CFG1_R41,
                                  "PMIC3 SEQUENCE CFG1 R41"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic3_swb_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic3_sequence_cfg1_r41(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swc order field to write to PMIC3 reg R43
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swc_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWC_SEQUENCE, i_spd, pmic::SET_PMIC3_SEQUENCE_CFG2_R42, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWC_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SEQUENCE_CFG2_R42,
                                  "PMIC3 SEQUENCE CFG2 R42"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic3_swc_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic3_sequence_cfg2_r42(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the pmic3 swd order field to write to PMIC3 reg R43
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_pmic3_swd_order(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::PMIC3_SWD_SEQUENCE, i_spd, pmic::SET_PMIC3_SEQUENCE_CFG3_R43, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_pmic_rail_order(l_field),
                                  F::PMIC3_SWD_SEQUENCE.get_byte(i_spd),
                                  l_field,
                                  pmic::SET_PMIC3_SEQUENCE_CFG3_R43,
                                  "PMIC3 SEQUENCE CFG3 R43"));

            // Write reserved/invalid value to the attributes that are used in SPD rev 0.0
            // Reserved value triggeres pmic_enable to use the sequence_cfg attributes
            FAPI_TRY(mss::attr::set_pmic3_swd_sequence_order(iv_ocmb, mss::ddr5::pmic_consts::SEQ_ORDER_RESERVED_VALUE));
            // Write the SPD vale to the attributes that are used in SPD rev 0.7.0
            FAPI_TRY(mss::attr::set_pmic3_sequence_cfg3_r43(iv_ocmb, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        // Virtual function overloads go here

        /// @brief Process the fields for ddimm rev 0.7
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            // The naming here is a bit tricky: 0.0 process will process fields
            // that originated in 0.0, but will use any field processors/traits
            // that were overridden for the current class type (ex. ddimm_0_7)

            // Only brand new fields for this revision should be explicitly
            // called here below the call to this function
            FAPI_TRY(ddimm_0_0::process(i_spd));

            // DDIMM 0.7 new field processing goes here
            FAPI_TRY(set_pmic0_swa_order(i_spd));
            FAPI_TRY(set_pmic0_swb_order(i_spd));
            FAPI_TRY(set_pmic0_swc_order(i_spd));
            FAPI_TRY(set_pmic0_swd_order(i_spd));
            FAPI_TRY(set_pmic1_swa_order(i_spd));
            FAPI_TRY(set_pmic1_swb_order(i_spd));
            FAPI_TRY(set_pmic1_swc_order(i_spd));
            FAPI_TRY(set_pmic1_swd_order(i_spd));
            FAPI_TRY(set_pmic2_swa_order(i_spd));
            FAPI_TRY(set_pmic2_swb_order(i_spd));
            FAPI_TRY(set_pmic2_swc_order(i_spd));
            FAPI_TRY(set_pmic2_swd_order(i_spd));
            FAPI_TRY(set_pmic3_swa_order(i_spd));
            FAPI_TRY(set_pmic3_swb_order(i_spd));
            FAPI_TRY(set_pmic3_swc_order(i_spd));
            FAPI_TRY(set_pmic3_swd_order(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }

};


//
// Can be updated with the earliest supported ddimm module revision
//
using ddimm_base_latest = ddimm_0_0;

} // ddr5

} // spd

}// mss

#endif
