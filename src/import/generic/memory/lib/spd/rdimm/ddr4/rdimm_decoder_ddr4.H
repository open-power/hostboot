/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/rdimm/ddr4/rdimm_decoder_ddr4.H $ */
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
/// @file rdimm_decoder_ddr4.H
/// @brief RDIMM module SPD decoder declarations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RDIMM_DECODER_DDR4_H_
#define _MSS_RDIMM_DECODER_DDR4_H_

#include <fapi2.H>
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
/// @brief RDIMM module SPD DRAM decoder
///
template < rev R >
class decoder<DDR4, RDIMM_MODULE, R > : public dimm_module_decoder
{
    private:

        using fields_t = fields<DDR4, RDIMM_MODULE>;
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
            static_assert( R <= rev::RDIMM_MAX, " R > rev::RDIMM_MAX");
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
        /// @brief Decodes module nominal height max, in mm
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 48
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_NOMINAL_HEIGHT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::FRONT_MODULE_THICKNESS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BACK_MODULE_THICKNESS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode reference_raw_card(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::REF_RAW_CARD, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::NUM_REGS_USED, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of rows of DRAMs on RDIMM
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 50
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ROWS_OF_DRAMS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Decodes register types
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 63
        ///
        virtual fapi2::ReturnCode register_and_buffer_type(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::REGISTER_TYPE, R>(iv_target, iv_data, o_output)) );
        fapi_try_exit:
            return fapi2::current_err;

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
        virtual fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HEAT_SPREADER_CHAR, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HEAT_SPREADER_SOL, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 133 (bit 6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode reg_manufacturer_id_code(uint16_t& o_output) const override
        {
            uint8_t l_cont_codes = 0;
            uint8_t l_last_nonzero_byte = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::CONTINUATION_CODES, R>(iv_target, iv_data, l_cont_codes)) );
            FAPI_TRY( (mss::spd::reader<fields_t::LAST_NON_ZERO_BYTE, R>(iv_target, iv_data, l_last_nonzero_byte)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_last_nonzero_byte, l_cont_codes);

                o_output = l_buffer;

                FAPI_INF("%s. Register Manufacturer ID Code: 0x%04x",
                         spd::c_str(iv_target),
                         o_output);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 136 (bit 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 51
        ///
        virtual fapi2::ReturnCode register_rev_num(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::REGISTER_REV, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ADDR_MAP_REG_TO_DRAM, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CKE_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ODT_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CA_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for control signal (CS) signal
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (bit 6~7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 53
        ///
        virtual fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CS_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::YO_Y2_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
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
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::Y1_Y3_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }
#endif
};// decoder

}// spd
}// mss

#endif //_MSS_RDIMM_DECODER_DDR4_H_
