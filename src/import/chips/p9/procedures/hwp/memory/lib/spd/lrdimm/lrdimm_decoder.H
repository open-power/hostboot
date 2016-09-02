/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/lrdimm/lrdimm_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file lrdimm_decoder.H
/// @brief LRDIMM module SPD decoder declarations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP


#ifndef _MSS_LRDIMM_DECODER_H_
#define _MSS_LRDIMM_DECODER_H_

#include <fapi2.H>
#include <vector>
#include <lib/spd/common/dimm_module_decoder.H>

namespace mss
{
namespace spd
{
namespace lrdimm
{

///
/// @brief LRDIMM module decoder for revision 1.0
///
class decoder_v1_0 : public dimm_module_decoder
{
    protected:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;

        constexpr static field_t MODULE_NOMINAL_HEIGHT{128, 3, 5};
        constexpr static field_t RAW_CARD_EXTENSION{128, 0, 3};

        constexpr static field_t FRONT_MODULE_THICKNESS{129, 4, 4};
        constexpr static field_t BACK_MODULE_THICKNESS{129, 0, 4};

        constexpr static field_t NUM_REGISTERS_USED{131, 6, 2};
        constexpr static field_t NUM_ROWS_OF_DRAMS{131, 4, 2};
        constexpr static field_t REGISTER_TYPE{131, 0, 4};

        constexpr static field_t HEAT_SPREADER_THERM_CHAR{132, 1, 7};
        constexpr static field_t HEAT_SPREADER_SOLUTION{132, 0, 1};

        constexpr static field_t CONTINUATION_CODES{133, 1, 7};
        constexpr static field_t ADDR_MAPPING{136, 7, 1};

        constexpr static field_t CKE_DRIVE_STRENGTH{137, 6, 2};
        constexpr static field_t ODT_DRIVE_STRENGTH{137, 4, 2};
        constexpr static field_t CA_DRIVE_STRENGTH{137, 2, 2};
        constexpr static field_t CS_DRIVE_STRENGTH{137, 0, 2};

        constexpr static field_t B_SIDE_DRIVE_STRENGTH{138, 6, 2};
        constexpr static field_t A_SIDE_DRIVE_STRENGTH{138, 4, 2};
        constexpr static field_t BCOM_BODT_BCKE_DRIVE_STRENGTH{138, 3, 1};
        constexpr static field_t BCK_DRIVE_STRENGTH{138, 2, 1};
        constexpr static field_t RCD_SLEW_CNTRL{138, 1, 1 };

        constexpr static field_t VREF_DQ_RANK0{140, 2, 6};
        constexpr static field_t VREF_DQ_RANK1{141, 2, 6};
        constexpr static field_t VREF_DQ_RANK2{142, 2, 6};
        constexpr static field_t VREF_DQ_RANK3{143, 2, 6};

        constexpr static field_t DATA_BUFFER_MDQ{145, 1, 3};

        constexpr static field_t DRAM_VREF_DQ_RANGE{155, 4, 4};
        constexpr static field_t DATA_BUFFER_VREF_DQ{155, 3, 1};

        constexpr static field_t DATA_BUFFER_GAIN_ADJUST{156, 7, 1};
        constexpr static field_t DATA_BUFFER_DFE{156, 6, 1};

    public:
        // Allows injection of errors for testing
        // TK - Consider API change to use setter/getters
        // for this instance variable, RDIMM decoder
        // uses this interface so they have to match - AAM
        std::vector<uint8_t> iv_spd_data;

        // deleted default ctor
        decoder_v1_0() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        decoder_v1_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const std::vector<uint8_t>& i_spd_data)
            : iv_target(i_target), iv_spd_data(i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        virtual ~decoder_v1_0() = default;

        ///
        /// @brief Decodes module nominal height max
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) override;

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_output raw card rev. encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 7~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode raw_card_extension(uint8_t& o_output) override;

        ///
        /// @brief Decodes front module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) override;

        ///
        /// @brief Decodes back module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of registers used on LRDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 57
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of rows of DRAMs on LRDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 57
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) override;

        ///
        /// @brief Decodes heat spreader solution
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 132 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of continuation codes
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (Bits 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
        ///
        virtual fapi2::ReturnCode num_continuation_codes(uint8_t& o_output) override;

        ///
        /// @brief Decodes manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 134 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
        ///
        virtual fapi2::ReturnCode manufacturer_id_code(uint8_t& o_output) override;

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 135 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
        ///
        virtual fapi2::ReturnCode register_rev_num(uint8_t& o_output) override;

        ///
        /// @brief Decodes address mapping from register to dram
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 136 (Bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 59
        ///
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for command/address (CA) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 5~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for chip select (CS) signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 6~7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes data buffer revision number
        /// @param[out] o_output revision number
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 139 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode data_buffer_rev(uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 0
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 140 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank0(uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 1
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 141 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank1(uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 2
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 142 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank2(uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 3
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 143 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank3(uint8_t& o_output) override;

        ///
        /// @brief Decodes data buffer VrefDQ for DRAM interface
        /// @param[out] o_output encoding of F5BC6x in DDR4DB01 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 144 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq(uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM interface MDQ Drive Strenth
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output encoding of F5BC6x in
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 145 - 147 (Bits 6~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 62
        ///
        virtual fapi2::ReturnCode data_buffer_mdq_drive_strength(const uint64_t i_dimm_speed,
                uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM interface MDQ read termination strength
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output encoding of F5BC6x in
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 145 - 147 (Bits 2~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 62
        ///
        virtual fapi2::ReturnCode data_buffer_mdq_rtt(const uint64_t i_dimm_speed, uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM drive strenth
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output DRAM drive strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 148 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 63
        ///
        virtual fapi2::ReturnCode dram_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM ODT for RTT_NOM
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 149 - 151 (Bits 2~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - (64 - 65)
        ///
        virtual fapi2::ReturnCode dram_rtt_nom(const uint64_t i_dimm_speed, uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM ODT for RTT_WR
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 149 - 151 (Bits 5~3)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - (64 - 65)
        ///
        virtual fapi2::ReturnCode dram_rtt_wr(const uint64_t i_dimm_speed, uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 0 & 1
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 152 - 154 (Bits 2~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 65
        ///
        virtual fapi2::ReturnCode dram_rtt_park_ranks0_1(const uint64_t i_dimm_speed, uint8_t& o_output) override;

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 2 & 3
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_output ODT termination strength (in ohms)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 152 - 154 (Bits 5~3)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 65
        ///
        virtual fapi2::ReturnCode dram_rtt_park_ranks2_3(const uint64_t i_dimm_speed, uint8_t& o_output) override;

};//decoder

///
/// @brief LRDIMM module decoder for revision 1.1
///
class decoder_v1_1 : public decoder_v1_0
{
    public:

        // deleted default ctor
        decoder_v1_1() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        decoder_v1_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const std::vector<uint8_t>& i_spd_data)
            : decoder_v1_0(i_target, i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        virtual ~decoder_v1_1() = default;

        ///
        /// @brief Decodes register and data buffer types
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 63
        ///
        virtual fapi2::ReturnCode register_and_buffer_type(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 65
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 65
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for chip select (CS) signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 6~7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 65
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCOM, BODT, BKCE)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode bcom_bcke_bodt_drive_strength(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCK)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode bck_output_drive_strength(uint8_t& o_output) override;

};

///
/// @brief LRDIMM module decoder for revision 1.2
///
class decoder_v1_2 : public  decoder_v1_1
{
    public:

        // deleted default ctor
        decoder_v1_2() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        decoder_v1_2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const std::vector<uint8_t>& i_spd_data)
            : decoder_v1_1(i_target, i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        virtual ~decoder_v1_2() = default;

        ///
        /// @brief Decodes RCD output slew rate control
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 6)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 70
        ///
        virtual fapi2::ReturnCode slew_rate_control(uint8_t& o_output) override;

        ///
        /// @brief Decodes VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 155 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 76
        ///
        virtual fapi2::ReturnCode dram_vref_dq_range(uint8_t& o_output) override;

        ///
        /// @brief Decodes data buffer VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 155 (Bit 4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 76
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq_range(uint8_t& o_output) override;

        ///
        /// @brief Decodes data buffer gain adjustment
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 156 (Bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 77
        ///
        virtual fapi2::ReturnCode data_buffer_gain_adjustment(uint8_t& o_output) override;

        ///
        /// @brief Decodes data buffer Decision Feedback Equalization (DFE)
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 156 (Bit 1)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 77
        ///
        virtual fapi2::ReturnCode data_buffer_dfe(uint8_t& o_output) override;
};

}// lrdimm
}// spd
}// mss

#endif //_MSS_LRDIMM_DECODER_H_
