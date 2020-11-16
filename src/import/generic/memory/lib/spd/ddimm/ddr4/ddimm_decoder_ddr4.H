/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/ddimm_decoder_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file ddimm_decoder_ddr4.H
/// @brief RDIMM module SPD decoder declarations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DDIMM_DECODER_DDR4_H_
#define _MSS_DDIMM_DECODER_DDR4_H_

#include <fapi2.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/spd/common/dimm_module_decoder.H>
#include <generic/memory/lib/spd/spd_decoder_def.H>
#include <generic/memory/lib/spd/spd_traits_ddr4.H>
#include <generic/memory/lib/spd/spd_reader.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{
namespace spd
{

///
/// @class decoder
/// @tparam R SPD revision - partial specialization
/// @brief DDIMM module SPD DRAM decoder
///
template < rev R >
class decoder< DDR4, DDIMM_MODULE, R > : public dimm_module_decoder
{
    private:

        using fields_t = fields<DDR4, DDIMM_MODULE>;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;

    public:

        // deleted default ctor
        decoder() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const std::vector<uint8_t>& i_spd_data):
            dimm_module_decoder(i_target, i_spd_data),
            iv_target(i_target),
            iv_data(i_spd_data)
        {
            static_assert( R <= rev::DDIMM_MAX, " R > rev::DDIMM_MAX");
        }

        ///
        /// @brief default dtor
        ///
        virtual ~decoder() = default;

        ///
        /// @brief Gets decoder target
        /// @return fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        ///
        virtual fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target() const
        {
            return iv_target;
        }

        ///
        /// @brief Gets decoder SPD data
        /// @return std::vector<uint8_t>
        ///
        virtual std::vector<uint8_t> get_data() const
        {
            return iv_data;
        }

        ///
        /// @brief Sets decoder SPD data
        /// @param[in] i_spd_data SPD data in a vector reference
        ///
        virtual void set_data(const std::vector<uint8_t>& i_spd_data)
        {
            iv_data = i_spd_data;
        }

#if 0
        ///
        /// @brief Decodes SPD Revision for bytes 192->447 -> SPD_REV_DDIMM_MODULE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ddimm_module_spd_revision(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SPD_REV_DDIMM_MODULE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Height -> MODULE_BASE_HEIGHT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_base_height(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_BASE_HEIGHT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Height -> MODULE_HEIGHT_MAX
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_HEIGHT_MAX, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Maximum Thickness -> MAX_THICKNESS_BACK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MAX_THICKNESS_BACK, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Maximum Thickness -> MAX_THICKNESS_FRONT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MAX_THICKNESS_FRONT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Reference Raw Card used -> DESIGN_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode reference_raw_card(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DESIGN_REV, R>(iv_target, iv_data, o_output)) );

            // Checks that we don't hit the reserved field for the RC design
            {
                static constexpr uint8_t RC_DESIGN_START = 3;
                static constexpr uint8_t RC_DESIGN_LEN   = 5;
                static constexpr uint8_t RESERVED = 0x1f;
                fapi2::buffer<uint8_t> l_buff(o_output);
                uint8_t l_rc_design = 0;
                l_buff.extractToRight<RC_DESIGN_START, RC_DESIGN_LEN>(l_rc_design);

                // Lets make an additional check that we aren't being set to a reserved field
                FAPI_ASSERT( l_rc_design != RESERVED,
                             fapi2::MSS_INVALID_SPD_RESERVED_BITS()
                             .set_FUNCTION_CODE(DDIMM_RAWCARD_DECODE)
                             .set_TARGET(iv_target),
                             "Reserved bits seen on %s",
                             spd::c_str(iv_target) );
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM attributes -> NUM_ROWS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::NUM_ROWS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM attributes -> NUM_BUFFERS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_buffers_used(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::NUM_BUFFERS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Heat Spreader Solution -> HEAT_SPREADER_SOL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HEAT_SPREADER_SOL, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Heat Spreader Solution -> HEAT_SPREADER_CHAR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HEAT_SPREADER_CHAR, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DMB Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 198: CONTINUATION_CODE
        /// Byte 199: LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode dmb_manufacturer_id_code(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::CONTINUATION_CODE, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::LAST_NON_ZERO, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DMB Revision Number -> DMB_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dmb_rev_num(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DMB_REV, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> RANK_MIX
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode rank_mix(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::RANK_MIX, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> PACKAGE_RANK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode package_ranks_per_channel(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PACKAGE_RANK, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> DATA_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_component_width_per_channel(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_WIDTH, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> NUM_DIMM_CHANNELS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_channels_per_dimm(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::NUM_DIMM_CHANNELS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> BUS_WIDTH_EXT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bus_width_extension(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BUS_WIDTH_EXT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> CHANNEL_DATA_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode memory_width_per_channel(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CHANNEL_DATA_WIDTH, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Thermal Sensors -> MOD_THERMAL_SENSOR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_thermal_sensors(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MOD_THERMAL_SENSOR, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Protocols -> PROTOCOL_SUPPORT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_protocol_support(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PROTOCOL_SUPPORT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Speed Supported -> SPEED_SUPPORTED_LSB
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_speed_supported(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SPEED_SUPPORTED_LSB, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Address Mirroring -> ADDRESS_MIRROR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode address_mirroring(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ADDRESS_MIRROR, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Byte enables MSB
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 208: BYTE_ENABLES_LSB
        /// Byte 209: BYTE_ENABLES_MSB
        ///
        virtual fapi2::ReturnCode byte_enables(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::BYTE_ENABLES_LSB, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::BYTE_ENABLES_MSB, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Byte enables: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Nibble enables LSB1
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 210: NIBBLE_ENABLES_LSB0
        /// Byte 211: NIBBLE_ENABLES_MSB0
        /// Byte 212: NIBBLE_ENABLES_LSB1
        ///
        virtual fapi2::ReturnCode nibble_enables(uint32_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint8_t l_byte2 = 0;
            uint8_t l_byte3 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::NIBBLE_ENABLES_LSB0, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::NIBBLE_ENABLES_MSB0, R>(iv_target, iv_data, l_byte1)) );
            FAPI_TRY( (mss::spd::reader<fields_t::NIBBLE_ENABLES_LSB1, R>(iv_target, iv_data, l_byte2)) );

            {
                fapi2::buffer<uint32_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte3, l_byte2, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Nibble Enables: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Four Rank Mode - DDP Compatibility - TSV 8 High Support - MRAM Support -> DDIMM_COMPAT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode compatabilty_modes(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DDIMM_COMPAT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Number of P-States -> NUM_P_STATES
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_p_states(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::NUM_P_STATES, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Spare Device Mapping LSB1
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 216: SPARE_DEVICE_LSB0
        /// Byte 217: SPARE_DEVICE_MSB0
        /// Byte 218: SPARE_DEVICE_LSB1
        ///
        virtual fapi2::ReturnCode spare_device_mapping(uint32_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint8_t l_byte2 = 0;
            uint8_t l_byte3 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::SPARE_DEVICE_LSB0, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::SPARE_DEVICE_MSB0, R>(iv_target, iv_data, l_byte1)) );
            FAPI_TRY( (mss::spd::reader<fields_t::SPARE_DEVICE_LSB1, R>(iv_target, iv_data, l_byte2)) );

            {
                fapi2::buffer<uint32_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte3, l_byte2, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Speed to DDR Interface Speed Ratio -> HI_DDR_SPEED_RATIO
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_to_ddr_speed_ratio(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HI_DDR_SPEED_RATIO, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SPD Content Revision -> SPD_CONTENT_REVISION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode spd_content_revision(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SPD_CONTENT_REVISION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_nominal(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_MGMT_NOMINAL, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_operable(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_MGMT_OPERABLE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_endurant(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_MGMT_ENDURANT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_nominal(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_BULK_NOMINAL, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_operable(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_BULK_OPERABLE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_endurant(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VIN_BULK_ENDURANT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 227: PMIC0_CONT_CODE
        /// Byte 228: PMIC0_LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode mfg_id_pmic0(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_CONT_CODE, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_LAST_NON_ZERO, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Revision Number -> PMIC0_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode revision_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_REV, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 231: PMIC1_CONT_CODE
        /// Byte 232: PMIC1_LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode mfg_id_pmic1(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_CONT_CODE, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_LAST_NON_ZERO, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Revision Number -> PMIC1_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode revision_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_REV, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Sequence Delay -> PMIC0_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Sequence Order -> PMIC0_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swa_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWA_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Sequence Delay -> PMIC0_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Sequence Order -> PMIC0_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swb_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWB_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Sequence Delay -> PMIC0_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Sequence Order -> PMIC0_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swc_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWC_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Sequence Delay -> PMIC0_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Sequence Order -> PMIC0_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swd_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_SWD_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Redundancy -> PMIC0_REDUNDANCY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_redundancy(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_REDUNDANCY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Phase Combination -> PMIC0_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phase_combination_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC0_PHASE_COMBIN, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Sequence Delay -> PMIC1_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Sequence Order -> PMIC1_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swa_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWA_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Sequence Delay -> PMIC1_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Sequence Order -> PMIC1_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swb_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWB_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Sequence Delay -> PMIC1_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Sequence Order -> PMIC1_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swc_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWC_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_VOLT_SET, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_RANGE_SELECT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_RANGE_SELECT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_VOLT_OFF, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_OFF_DIRECTION, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Sequence Delay -> PMIC1_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_DELAY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Sequence Order -> PMIC1_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swd_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_SWD_ORDER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Redundancy -> PMIC1_REDUNDANCY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_redundancy(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_REDUNDANCY, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Phase Combination -> PMIC1_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phase_combination_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PMIC1_PHASE_COMBIN, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Sequence -> PMIC0_SEQUENCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sequence_pmic0(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::PMIC0_SEQUENCE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Sequence -> PMIC1_SEQUENCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sequence_pmic1(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::PMIC1_SEQUENCE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Registered Clock Drivers (RCD)
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Byte 264 DDIMM SPD
        ///
        virtual fapi2::ReturnCode module_rcd(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::MODULE_RCD, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Availability -> THERM_SENSOR_0_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_availability(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_AVAIL, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Secondary Sensor Availability -> THERM_SENSOR_0_SECOND_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_availability(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_SECOND_AVAIL, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Type -> THERM_SENSOR_0_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_type(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_TYPE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Usage -> THERM_SENSOR_0_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_usage(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_USAGE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 I2C Address -> THERM_SENSOR_0_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_i2c_address(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_I2C_ADDRESS, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Availability -> THERM_SENSOR_1_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_availability(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_AVAIL, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Secondary Sensor Availability -> THERM_SENSOR_1_SECOND_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_availability(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_SECOND_AVAIL, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Type -> THERM_SENSOR_1_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_type(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_TYPE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Usage -> THERM_SENSOR_1_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_usage(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_USAGE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 I2C Address -> THERM_SENSOR_1_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_i2c_address(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_I2C_ADDRESS, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 2 Availability -> THERM_SENSOR_DIFF_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_availability(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_DIFF_AVAIL, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 2 Type -> THERM_SENSOR_DIFF_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_type(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_DIFF_TYPE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Usage -> THERM_SENSOR_DIFF_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_usage(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_DIFF_USAGE, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential I2C Address -> THERM_SENSOR_DIFF_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_i2c_address(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_DIFF_I2C_ADDRESS, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 I2C Address -> THERM_SENSOR_0_SECOND_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_i2c_address(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_SECOND_I2C_ADDRESS, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 I2C Address -> THERM_SENSOR_1_SECOND_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_i2c_address(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_SECOND_I2C_ADDRESS, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 Location -> THERM_SENSOR_1_SECOND_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_location(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_SECOND_LOCATION, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 Location -> THERM_SENSOR_0_SECOND_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_location(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_SECOND_LOCATION, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Location -> THERM_SENSOR_1_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_location(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_1_LOCATION, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Location -> THERM_SENSOR_0_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_location(uint8_t& o_output) const override
        {
            FAPI_TRY((mss::spd::reader<fields_t::THERM_SENSOR_0_LOCATION, R>(iv_target, iv_data, o_output)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM manufacturing ID Code
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_MFG_ID_CODE_LSB, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_MFG_ID_CODE_MSB, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Module Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM manufacturing ID Code
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code(uint16_t& o_output) const override
        {
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_MFR_ID_CODE_LSB, R>(iv_target, iv_data, l_byte0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_MFR_ID_CODE_MSB, R>(iv_target, iv_data, l_byte1)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_byte1, l_byte0);
                o_output = l_buffer;
                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }
#endif
};// decoder

}// spd
}// mss

#endif //_MSS_DDIMM_DECODER_DDR4_H_
