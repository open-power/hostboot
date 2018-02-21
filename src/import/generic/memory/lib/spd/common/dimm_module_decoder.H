/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/dimm_module_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
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
    public:
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;

        //
        std::vector<uint8_t> iv_spd_data;

        ///
        /// @brief default ctor
        ///
        dimm_module_decoder() = default;

        ///
        /// @brief ctor
        ///
        dimm_module_decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            const std::vector<uint8_t>& i_spd_data): iv_target(i_target), iv_spd_data(i_spd_data)
        {
            fapi2::toString(iv_target, iv_target_str_storage, fapi2::MAX_ECMD_STRING_LEN);
        }

        ///
        /// @brief default dtor
        ///
        virtual ~dimm_module_decoder() = default;

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
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_output  encoding from SPD
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
        /// @param[out] o_output  encoding from SPD
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
        /// @brief Decodes number of continuation codes
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode num_continuation_codes(uint8_t& o_output) const
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode reg_manufacturer_id_code(uint8_t& o_output) const
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
        /// @param[out] o_output encoded drive strength
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

    protected:

        char iv_target_str_storage[fapi2::MAX_ECMD_STRING_LEN];

};

///
/// @brief data structure for byte fields
/// @note holds byte index, start bit and length of decoded field
///
struct field_t
{
    const uint64_t iv_byte;
    const uint64_t iv_start;
    const uint64_t iv_length;

    // default ctor deleted
    constexpr field_t() = delete;

    ///
    /// @brief ctor
    /// @param[in] i_byte_index
    /// @param[in] i_start_bit
    /// @param[in] i_bit_length
    ///
    constexpr field_t(const uint64_t i_byte_index,
                      const uint64_t i_start_bit,
                      const uint64_t i_bit_length)
        : iv_byte(i_byte_index), iv_start(i_start_bit), iv_length(i_bit_length)
    {}

    ///
    /// @brief default dtor
    ///
    ~field_t() = default;

};// field_t

}// spd
}// mss

#endif //_MSS_DIMM_MODULE_DECODER_H_
