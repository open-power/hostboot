/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/rdimm/rdimm_decoder.H $ */
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
/// @file rdimm_decoder.H
/// @brief RDIMM module SPD decoder declarations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RDIMM_DECODER_H_
#define _MSS_RDIMM_DECODER_H_

#include <fapi2.H>
#include <cstdint>

namespace mss
{
namespace spd
{

enum rdimm_byte_extract
{
    // Byte 128
    MODULE_NOM_HEIGHT_START = 3,
    MODULE_NOM_HEIGHT_LEN = 5,
    RAW_CARD_EXT_START = 0,
    RAW_CARD_EXT_LEN = 3,

    // Byte 129
    FRONT_MODULE_THICKNESS_START = 4,
    FRONT_MODULE_THICKNESS_LEN = 4,
    BACK_MODULE_THICKNESS_START = 0,
    BACK_MODULE_THICKNESS_LEN = 4,

    // Byte 130
    REF_RAW_CARD_START = 3,
    REF_RAW_CARD_LEN = 5,
    REF_RAW_CARD_REV_START = 1,
    REF_RAW_CARD_REV_LEN = 2,
    REF_RAW_CARD_EXT_START = 0,
    REF_RAW_CARD_EXT_LEN = 1,

    // Byte 131
    REGS_USED_START = 6,
    REGS_USED_LEN = 2,
    ROWS_OF_DRAMS_START = 4,
    ROWS_OF_DRAMS_LEN = 2,

    // Byte 132
    HEAT_SPREADER_CHAR_START = 1,
    HEAT_SPREADER_CHAR_LEN = 7,
    HEAT_SPREADER_SOL_START = 0,
    HEAT_SPREADER_SOL_LEN = 1,

    // Byte 133
    CONTINUATION_CODES_START = 1,
    CONTINUATION_CODES_LEN = 7,

    // Byte 134 - whole byte taken
    // Byte 135 - whole byte taken

    // Byte 136
    ADDR_MAPPING_START = 7,
    ADDR_MAPPING_LEN = 1,

    // Byte 137
    CKE_DRIVER_START = 6,
    CKE_DRIVER_LEN = 2,
    ODT_DRIVER_START = 4,
    ODT_DRIVER_LEN = 2,
    CA_DRIVER_START = 2,
    CA_DRIVER_LEN = 2,
    CS_DRIVER_START = 0,
    CS_DRIVER_LEN = 2,

    // Byte 138
    YO_Y2_DRIVER_START = 6,
    YO_Y2_DRIVER_LEN = 2,
    Y1_Y3_DRIVER_START = 4,
    Y1_Y3_DRIVER_LEN = 2,

};

enum addr_mapping
{
    STANDARD = 0,
    MIRRORED = 1,
};

///
/// @class dimm_module_decoder
/// @brief Abstract class for RDIMM module SPD DRAM decoder
///
class dimm_module_decoder
{
    public:

        ///
        /// @brief default ctor
        ///
        dimm_module_decoder() = default;

        ///
        /// @brief default dtor
        ///
        virtual ~dimm_module_decoder() = default;

        ///
        /// @brief Decodes module nominal height max, in mm
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_output raw card rev
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 7~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode raw_card_extension(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes front module maximum thickness max, in mm
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes back module maximum thickness max, in mm
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes reference raw card
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes reference raw card revision
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bits 6~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card_rev(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes reference raw card extension
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card_extension(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of rows of DRAMs on RDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes heat spreader thermal characteristics
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCEawSS if okay
        /// @note SPD Byte 132 (Bits 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes heat spreader solution
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 132 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of continuation codes
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (bit 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode num_continuation_codes(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (bit 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode manufacturer_id_code(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 135 (bit 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode register_rev_num(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes address mapping from register to dram
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 136 (bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 52
        ///
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for command/address (CA) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 5~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for chip select (CS) signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 6~7)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output)
        {
            o_output = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

///
/// @class decoder
/// @brief RDIMM module SPD DRAM decoder for rev 1.0
///
class rdimm_decoder_v1_0 : public dimm_module_decoder
{
    public:
        // deleted default ctor
        rdimm_decoder_v1_0() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        rdimm_decoder_v1_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const std::vector<uint8_t>& i_spd_data): iv_target(i_target), iv_spd_data(i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        virtual ~rdimm_decoder_v1_0() = default;

        ///
        /// @brief Decodes module nominal height max, in mm
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) override;

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_output raw card rev
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 7~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode raw_card_extension(uint8_t& o_output) override;

        ///
        /// @brief Decodes front module maximum thickness max, in mm
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) override;

        ///
        /// @brief Decodes back module maximum thickness max, in mm
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) override;

        ///
        /// @brief Decodes reference raw card
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card(uint8_t& o_output) override;

        ///
        /// @brief Decodes reference raw card revision
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bits 6~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card_rev(uint8_t& o_output) override;

        ///
        /// @brief Decodes reference raw card extension
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 130 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 49
        ///
        virtual fapi2::ReturnCode reference_raw_card_extension(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of rows of DRAMs on RDIMM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) override;

        ///
        /// @brief Decodes heat spreader thermal characteristics
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCEawSS if okay
        /// @note SPD Byte 132 (Bits 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_output) override;

        ///
        /// @brief Decodes heat spreader solution
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 132 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) override;

        ///
        /// @brief Decodes number of continuation codes
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (bit 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode num_continuation_codes(uint8_t& o_output) override;

        ///
        /// @brief Decodes manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (bit 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode manufacturer_id_code(uint8_t& o_output) override;

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 136 (bit 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode register_rev_num(uint8_t& o_output) override;

        ///
        /// @brief Decodes address mapping from register to dram
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 136 (bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 52
        ///
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for command/address (CA) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 5~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for chip select (CS) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 6~7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) override;

    protected:
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        const std::vector<uint8_t> iv_spd_data;

};// rdimm_decoder_v1_0

///
/// @class decoder
/// @brief RDIMM module SPD DRAM decoder for rev 1.1
///
class rdimm_decoder_v1_1 :  public rdimm_decoder_v1_0
{
    public:

        // deleted default ctor
        rdimm_decoder_v1_1() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data vector DIMM SPD data
        ///
        rdimm_decoder_v1_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const std::vector<uint8_t>& i_spd_data): rdimm_decoder_v1_0(i_target, i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        virtual ~rdimm_decoder_v1_1() = default;

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for chip select (CS) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 6~7)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) override;

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (bit 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 76
        /// @note DDR4 SPD Document Release 4
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) override;

};//rdimm_decoder_v1_1

}// spd
}// mss

#endif //_MSS_RDIMM_DECODER_H_
