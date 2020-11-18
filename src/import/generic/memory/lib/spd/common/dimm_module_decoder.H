/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/dimm_module_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file dimm_module_decoder.H
/// @brief base dimm module SPD decoder declarations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _MSS_DIMM_MODULE_DECODER_H_
#define _MSS_DIMM_MODULE_DECODER_H_

#include <fapi2.H>
#include <cstdint>

namespace mss
{
namespace spd
{

///
/// @class dimm_module_decoder
/// @brief Abstract class for DIMM module SPD DRAM decoders
/// @note This would include for example, RDIMM and LRDIMM
///
class dimm_module_decoder
{
    private:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;

    public:

        ///
        /// @brief default ctor
        ///
        dimm_module_decoder() = default;

        ///
        /// @brief ctor
        ///
        dimm_module_decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            const std::vector<uint8_t>& i_spd_data):
            iv_target(i_target),
            iv_data(i_spd_data)
        {
        }

        ///
        /// @brief default dtor
        ///
        virtual ~dimm_module_decoder() = default;

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

        ///
        /// @brief Decodes SPD Revision -> SPD_REVISION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode revision(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes module nominal height max
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode raw_card_extension(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes front module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes back module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes reference raw card used
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode reference_raw_card(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of rows of DRAMs on RDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register and buffer type for LRDIMMs
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode register_and_buffer_type(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes heat spreader thermal characteristics
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCEawSS if okay
        ///
        virtual fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_output) const
        {
            // Undefined must be coded as 0x00
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes heat spreader solution
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode reg_manufacturer_id_code(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode register_rev_num(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes address mapping from register to dram
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for command/address (CA) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for control signal (CS) signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCOM, BODT, BKCE)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bcom_bcke_bodt_drive_strength(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;

        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCK)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bck_output_drive_strength(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes RCD output slew rate control
        /// @param[out] o_output encoded slew rate
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode slew_rate_control(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes data buffer revision number
        /// @param[out] o_output revision number
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_rev(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 0
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 1
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 2
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank2(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 3
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank3(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes data buffer VrefDQ for DRAM interface
        /// @param[out] o_output encoding of F5BC6x in DDR4DB01 spec
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM interface MDQ Drive Strenth
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output encoding of F5BC6x in
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_mdq_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM interface MDQ read termination strength
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output encoding of F5BC6x in
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_mdq_rtt(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM drive strenth
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output DRAM drive strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_NOM
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_nom(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_WR
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_wr(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 0 & 1
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_ranks0_1(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 2 & 3
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_rtt_park_ranks2_3(const uint64_t i_dimm_speed, uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_vref_dq_range(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes data buffer VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq_range(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes data buffer gain adjustment
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_gain_adjustment(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes data buffer Decision Feedback Equalization (DFE)
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode data_buffer_dfe(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        //////////////////////////////////////////
        // DDIMM information from here on out
        //////////////////////////////////////////
        ///
        /// @brief Decodes SPD Revision for bytes 192->447 -> SPD_REV_DDIMM_MODULE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ddimm_module_spd_revision(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Module Height -> MODULE_BASE_HEIGHT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_base_height(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DIMM attributes -> NUM_BUFFERS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_buffers_used(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DMB Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 198: CONTINUATION_CODE
        /// Byte 199: LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode dmb_manufacturer_id_code(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DMB Revision Number -> DMB_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dmb_rev_num(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> RANK_MIX
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode rank_mix(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> PACKAGE_RANK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode package_ranks_per_channel(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> DATA_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode dram_component_width_per_channel(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> NUM_DIMM_CHANNELS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_channels_per_dimm(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> BUS_WIDTH_EXT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode bus_width_extension(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> DEVICE_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode memory_width_per_channel(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Module Thermal Sensors -> MOD_THERMAL_SENSOR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_thermal_sensors(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Host Interface Protocols -> PROTOCOL_SUPPORT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_protocol_support(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Host Interface Speed Supported -> SPEED_SUPPORTED_LSB
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_speed_supported(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Address Mirroring -> ADDRESS_MIRROR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode address_mirroring(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Byte enables MSB
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 208: BYTE_ENABLES_LSB
        /// Byte 209: BYTE_ENABLES_MSB
        ///
        virtual fapi2::ReturnCode byte_enables(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
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
        virtual fapi2::ReturnCode nibble_enables(uint32_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Four Rank Mode - DDP Compatibility - TSV 8 High Support - MRAM Support -> DDIMM_COMPAT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode compatabilty_modes(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Number of P-States -> NUM_P_STATES
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_p_states(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
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
        virtual fapi2::ReturnCode spare_device_mapping(uint32_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Host Interface Speed to DDR Interface Speed Ratio -> HI_DDR_SPEED_RATIO
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode host_to_ddr_speed_ratio(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SPD Content Revision -> SPD_CONTENT_REVISION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode spd_content_revision(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_nominal(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_operable(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_mgmt_endurant(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_nominal(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_operable(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vin_bulk_endurant(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes VDD_Core PMIC0 -> VDD_CORE_PMIC0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vdd_core_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 227: PMIC0_CONT_CODE
        /// Byte 228: PMIC0_LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode mfg_id_pmic0(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 Revision Number -> PMIC0_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode revision_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes VDD_Core PMIC1 -> VDD_CORE_PMIC1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode vdd_core_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 231: PMIC1_CONT_CODE
        /// Byte 232: PMIC1_LAST_NON_ZERO
        ///
        virtual fapi2::ReturnCode mfg_id_pmic1(uint16_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 Revision Number -> PMIC1_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode revision_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Delay -> PMIC0_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWA Delay Sequence Order -> PMIC0_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swa_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Delay -> PMIC0_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWB Sequence Order -> PMIC0_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swb_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Delay -> PMIC0_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWC Sequence Order -> PMIC0_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swc_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Delay -> PMIC0_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 SWD Sequence Order -> PMIC0_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swd_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 Phase Combination -> PMIC0_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phase_combination_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Delay -> PMIC1_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWA Sequence Order -> PMIC1_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swa_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Delay -> PMIC1_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWB Sequence Order -> PMIC1_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swb_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Delay -> PMIC1_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWC Sequence Order -> PMIC1_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swc_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_RANGE_SETTING
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_setpoint_range_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_OFF_DIRECTION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_offset_direction_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Delay -> PMIC1_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_delay_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 SWD Sequence Order -> PMIC1_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode volt_order_swd_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 Phase Combination -> PMIC1_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode phase_combination_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 Redundancy
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic0_redundancy(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC0 Sequence Order
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sequence_pmic0(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 Redundancy
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode pmic1_redundancy(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes PMIC1 Sequence Order
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sequence_pmic1(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Availability
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_availability(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Secondary Sensor Availability
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_availability(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Type
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_type(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Usage
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_usage(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 I2C Address
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_i2c_address(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Availability
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_availability(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Secondary Sensor Availability
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_availability(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Type
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_type(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Usage
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_usage(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 I2C Address
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_i2c_address(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Availability
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_availability(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Type
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_type(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Usage
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_usage(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential I2C Address
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_differential_i2c_address(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 I2C Address
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_i2c_address(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 I2C Address
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_i2c_address(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 Location
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_secondary_location(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 Location
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_secondary_location(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Location
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_1_location(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Location
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode therm_sensor_0_location(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes module Manufacturer ID code
        /// @param[out] o_value module manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[out] o_value dram manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }


        ///
        /// @brief Decodes Registered Clock Drivers (RCD)
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode module_rcd(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

}// spd
}// mss

#endif //_MSS_DIMM_MODULE_DECODER_H_
