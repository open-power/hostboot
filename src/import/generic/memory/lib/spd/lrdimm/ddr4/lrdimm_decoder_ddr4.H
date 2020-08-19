/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4.H $ */
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
/// @file lrdimm_decoder_ddr4.H
/// @brief LRDIMM module SPD decoder declarations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _MSS_LRDIMM_DECODER_DDR4_H_
#define _MSS_LRDIMM_DECODER_DDR4_H_

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/spd/spd_decoder_def.H>
#include <generic/memory/lib/spd/common/dimm_module_decoder.H>
#include <generic/memory/lib/spd/spd_reader.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{
namespace spd
{

///
/// @brief LRDIMM module decoder
/// @tparam R SPD revision  - partial specialization
///
template < rev R >
class decoder<DDR4, LRDIMM_MODULE, R > : public dimm_module_decoder
{
    private:

        using fields_t = fields<DDR4, LRDIMM_MODULE>;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;

        ///
        /// @brief Helper function to check for reserved values for DRAM interface MDQ Drive Strenth
        /// @tparam T SPD revision
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[in] i_input value to check reserved bits against
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template < rev T >
        fapi2::ReturnCode check_for_reserved_values(const uint64_t i_dimm_speed,
                const uint8_t i_input) const
        {
            static_assert(T <= LRDIMM_MAX, "Invalid SPD revision");
            const std::vector<size_t> l_reserved_bits{0b011, 0b100, 0b110, 0b111};

            // Lets make an additinal check that we aren't being set to a reserved field
            FAPI_ASSERT( !std::binary_search(l_reserved_bits.begin(), l_reserved_bits.end(), i_input),
                         fapi2::MSS_INVALID_DB_MDQ_DRIVE_STRENGTH()
                         .set_DATA_RATE(i_dimm_speed)
                         .set_TARGET(iv_target),
                         "Reserved settings for data buffer MDQ drive strength received for dimm speed %d on %s",
                         i_dimm_speed,
                         spd::c_str(iv_target) );

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

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
            static_assert( R <= rev::LRDIMM_MAX, " R > rev::LRDIMM_MAX");
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

        ///
        /// @brief Decodes module nominal height max
        /// @param[out] o_output height range encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 4~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode max_module_nominal_height(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::MODULE_NOMINAL_HEIGHT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_output raw card rev. encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 128 (Bits 7~5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode raw_card_extension(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::RAW_CARD_EXT, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes front module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode front_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::FRONT_MODULE_THICKNESS, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Decodes back module maximum thickness max
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 129 (Bits 7~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 55
        ///
        virtual fapi2::ReturnCode back_module_max_thickness(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::BACK_MODULE_THICKNESS, R>(iv_target, iv_data, o_output)) );

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
        /// @brief Decodes number of registers used on LRDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 57
        ///
        virtual fapi2::ReturnCode num_registers_used(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::NUM_REGS_USED, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of rows of DRAMs on LRDIMM
        /// @param[out] o_output  encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 131 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 57
        ///
        virtual fapi2::ReturnCode num_rows_of_drams(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::ROWS_OF_DRAMS, rev::V1_0>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;

        }

        ///
        /// @brief Decodes register and data buffer types
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
        /// @brief Decodes heat spreader solution
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 132 (Bit 7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
        ///
        virtual fapi2::ReturnCode heat_spreader_solution(uint8_t& o_output) const override
        {
            FAPI_TRY(  (mss::spd::reader<fields_t::HEAT_SPREADER_SOL, rev::V1_0>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register manufacturer ID code
        /// @param[out] o_output drive strength encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 134 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
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

                FAPI_INF("%s.Module Manufacturer ID Code: 0x%04x",
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
        /// @note SPD Byte 135 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 58
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
        /// @note SPD Byte 136 (Bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 59
        ///
        virtual fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ADDR_MAP_REG_TO_DRAM, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CKE_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
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
        /// @note SPD Byte 137 (Bits 5~4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::CA_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for control signal (CS) signal
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 137 (Bits 6~7)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
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
        /// @note SPD Byte 138 (Bits 1~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
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
        /// @note SPD Byte 138 (Bits 3~2)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::Y1_Y3_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCOM, BODT, BKCE)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode bcom_bcke_bodt_drive_strength(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BCOM_BODT_BCKE_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCK)
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 5)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12.3 - 66
        ///
        virtual fapi2::ReturnCode bck_output_drive_strength(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BCK_DRIVER, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes RCD output slew rate control
        /// @param[out] o_output encoded drive strength
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 138 (Bit 6)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 70
        ///
        virtual fapi2::ReturnCode slew_rate_control(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::RCD_SLEW_CNTRL, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Decodes data buffer revision number
        /// @param[out] o_output revision number
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 139 (Bits 7~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 60
        ///
        virtual fapi2::ReturnCode data_buffer_rev(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_BUFFER_REV, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 0
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 140 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank0(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VREF_DQ_RANK0, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 1
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 141 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank1(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VREF_DQ_RANK1, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 2
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 142 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank2(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VREF_DQ_RANK2, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 3
        /// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 143 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode dram_vref_dq_rank3(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::VREF_DQ_RANK3, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer VrefDQ for DRAM interface
        /// @param[out] o_output encoding of F5BC6x in DDR4DB01 spec
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 144 (Bits 5~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12.2 - 61
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_BUFFER_VREF_DQ, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

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
                uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_LTE_1866, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_LTE_2400, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_LTE_3200, R>(iv_target, iv_data, o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));
                    break;
            }

            // Lets make an additinal check that we aren't being set to a reserved field
            FAPI_TRY((check_for_reserved_values<R>(i_dimm_speed, o_output)),
                     "Failed reserved bit check for %s", spd::c_str(iv_target));

            // If we are here we have a valid output, exit
            // to avoid error path of fapi_try_exit
            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            // A little output clean up if we fail out
            o_output = 0;
            return fapi2::current_err;
        }


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
        virtual fapi2::ReturnCode data_buffer_mdq_rtt(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_RTT_LTE_1866, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_RTT_LTE_2400, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DB_MDQ_RTT_LTE_3200, R>(iv_target, iv_data, o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;


        fapi_try_exit:
            return fapi2::current_err;
        }

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
        virtual fapi2::ReturnCode dram_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_DRIVE_STRENGTH_LTE_1866, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_DRIVE_STRENGTH_LTE_2400, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_DRIVE_STRENGTH_LTE_3200, R>(iv_target, iv_data, o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));
                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }


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
        virtual fapi2::ReturnCode dram_rtt_nom(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_NOM_LTE_1866, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_NOM_LTE_2400, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_NOM_LTE_3200, R>(iv_target, iv_data, o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));

                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }


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
        virtual fapi2::ReturnCode dram_rtt_wr(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_WR_LTE_1866, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_WR_LTE_2400, R>(iv_target, iv_data, o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_WR_LTE_3200, R>(iv_target, iv_data, o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));

                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

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
        virtual fapi2::ReturnCode dram_rtt_park_ranks0_1(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R01_LTE_1866, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R01_LTE_2400, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R01_LTE_3200, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));

                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }


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
        virtual fapi2::ReturnCode dram_rtt_park_ranks2_3(const uint64_t i_dimm_speed, uint8_t& o_output) const override
        {
            switch(i_dimm_speed)
            {
                case mss::DIMM_SPEED_1600:
                case mss::DIMM_SPEED_1866:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R23_LTE_1866, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                case mss::DIMM_SPEED_2133:
                case mss::DIMM_SPEED_2400:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R23_LTE_2400, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                case mss::DIMM_SPEED_2666:
                case mss::DIMM_SPEED_2933:
                case mss::DIMM_SPEED_3200:
                    FAPI_TRY( (mss::spd::reader<fields_t::DRAM_ODT_RTT_PARK_R23_LTE_3200, R>(iv_target, iv_data,
                               o_output)) );
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_DIMM_SPEED()
                                .set_DIMM_SPEED(i_dimm_speed)
                                .set_TARGET(iv_target),
                                "Invalid dimm speed received: %d for %s", i_dimm_speed, spd::c_str(iv_target));

                    break;
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 155 (Bits 3~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 76
        ///
        virtual fapi2::ReturnCode dram_vref_dq_range(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_VREF_DQ_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Decodes data buffer VrefDQ range for DRAM interface range
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 155 (Bit 4)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 76
        ///
        virtual fapi2::ReturnCode data_buffer_vref_dq_range(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_BUFFER_VREF_DQ_RANGE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer gain adjustment
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 156 (Bit 0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 77
        ///
        virtual fapi2::ReturnCode data_buffer_gain_adjustment(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_BUFFER_GAIN_ADJUST, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer Decision Feedback Equalization (DFE)
        /// @param[out] o_output spd encoding
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 156 (Bit 1)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 4
        /// @note Page 4.1.2.L-4 - 77
        ///
        virtual fapi2::ReturnCode data_buffer_dfe(uint8_t& o_output) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DATA_BUFFER_DFE, R>(iv_target, iv_data, o_output)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes the module partnumber
        /// @param[out] o_output partnumber value as read from the SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Needed for LRDIMM decodes to workaround a specific PN's SI issues
        ///
        fapi2::ReturnCode module_partnumber(uint8_t o_output[mss::MODULE_PARTNUMBER_ATTR]) const override
        {
            constexpr uint64_t MODULE_PARTNUMBER_START = 329;
            const auto EXPECTED_SIZE = MODULE_PARTNUMBER_START + mss::MODULE_PARTNUMBER_ATTR;
            FAPI_ASSERT(iv_data.size() >= EXPECTED_SIZE,
                        fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                        .set_TARGET(iv_target)
                        .set_INDEX(EXPECTED_SIZE)
                        .set_LIST_SIZE(iv_data.size())
                        .set_FUNCTION(mss::GET_FIELD),
                        "%s invalid SPD size of %lu. Expected a size of at least %lu",
                        mss::spd::c_str(iv_target), iv_data.size(), EXPECTED_SIZE);

            // Loops through and grabs the fields
            // Not doing the fields traits method as we would need 20 traits
            for(uint64_t l_index = 0; l_index < mss::MODULE_PARTNUMBER_ATTR; ++l_index)
            {
                o_output[l_index] = iv_data[MODULE_PARTNUMBER_START + l_index];
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

};//decoder

}// spd
}// mss


#endif //_MSS_LRDIMM_DECODER_DDR4_H_
