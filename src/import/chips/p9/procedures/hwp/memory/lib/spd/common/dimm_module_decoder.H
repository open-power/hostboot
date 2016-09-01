/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/dimm_module_decoder.H $ */
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
/// @file dimm_module_decoder.H
/// @brief base dimm module SPD decoder declarations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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

}// spd
}// mss

#endif //_MSS_DIMM_MODULE_DECODER_H_
