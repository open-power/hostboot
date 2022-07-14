/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_ddr5_base_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file p10_ddr5_base_engine.H
/// @brief DDR5 base cnfg eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_DDR5_BASE_ENGINE_H_
#define _P10_DDR5_BASE_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_fields_ddr5.H>
#include <generic/memory/lib/spd/spd_utils_ddr5.H>
#include <generic/memory/lib/utils/find.H>

#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <lib/eff_config/ody_attr_engine_traits.H>

namespace mss
{
namespace spd
{
namespace ddr5
{
///
/// @brief Class for base module section of SPD Rev 0.0
/// @note Not sure what our base revision is... We'll need an SPD spec + binary for our use case first. For now, 0.0
///
class base_0_0 : public mss::spd::base
{
        using FIELDS = mss::spd::fields<DDR5, BASE_CNFG>;

    public:

        ///
        /// @brief Construct a new base rev 0.0 object
        /// @param[in] i_dimm DIMM target
        ///
        base_0_0(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :  base(i_dimm) {}

        ///
        /// @brief Destroy the base_0_0 object
        ///
        virtual ~base_0_0() = default;

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
        /// @return attribute enumeration value for DRAM generation
        ///
        virtual uint8_t get_dram_generation() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5;
        }

        ///
        /// @brief Set the dimm type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_dimm_type = 0;

            const std::vector<uint8_t> l_reserved_bits{0b0000, 0b0101, 0b0110, 0b0111, 0b1000, 0b1001, 0b1100, 0b1101, 0b1110, 0b1111};

            // =========================================================
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Release 1
            // Byte 3 (0x003): Key Byte / Module Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP =
            {
                //{key byte, dimm type}
                {0b1010, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM},
                // All others reserved or not supported
            };

            FAPI_TRY( mss::spd::get_field_spd(iv_ocmb, FIELDS::BASE_MODULE, i_spd, SET_DIMM_TYPE, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_DIMM_TYPE, l_field) );

            FAPI_TRY( lookup_table_check(iv_dimm, BASE_MODULE_TYPE_MAP, SET_DIMM_TYPE, l_field, l_dimm_type),
                      "%s failed DIMM_TYPE lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_dimm_type(iv_dimm, l_dimm_type));

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the hybrid field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_hybrid(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_hybrid = 0;


            // =========================================================
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Revision 1
            // Byte 3 (0x003): Key Byte / Module Type - Hybrid
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MAP =
            {
                //{key byte, dimm type}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_NOT_HYBRID},
                {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_IS_HYBRID},

                // All others reserved or not supported
            };

            FAPI_TRY( mss::spd::get_field_spd(iv_ocmb, FIELDS::HYBRID, i_spd, SET_HYBRID, l_field));

            FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_HYBRID, l_field, l_hybrid),
                     "%s failed HYBRID lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_hybrid(iv_dimm, l_hybrid));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the hybrid media field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_hybrid_media(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_hybrid_media = 0;

            static const std::vector<uint8_t> RESERVED_BITS = {0b011, 0b100, 0b101, 0b110, 0b111};

            // =========================================================
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Revision 1
            // Byte 3 (0x003): Key Byte / Module Type - Hybrid
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MEMORY_TYPE_MAP =
            {

                //{key byte, dimm type}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NONE},
                // All others reserved or not supported
            };

            FAPI_TRY( mss::spd::get_field_spd(iv_ocmb, FIELDS::HYBRID_MEDIA, i_spd, SET_HYBRID_MEDIA, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, RESERVED_BITS, SET_HYBRID_MEDIA, l_field) );

            FAPI_TRY( lookup_table_check(iv_dimm, HYBRID_MEMORY_TYPE_MAP, SET_HYBRID_MEDIA, l_field, l_hybrid_media),
                      "%s failed HYBRID_MEMORY_TYPE lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_hybrid_memory_type(iv_dimm, l_hybrid_media));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the sdram density field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_sdram_density(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_sdram_density = 0;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Revision 1
            // Byte 4 (0x004): Key Byte / First SDRAM Density & Package
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_DENSITY_MAP =
            {
                // {key byte, capacity in GBs}
                {0b00001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_4G},
                {0b00010, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_8G},
                {0b00011, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_12G},
                {0b00100, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G},
                {0b00101, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_24G},
                {0b00110, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_32G},
                {0b00111, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_48G},
                {0b01000, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_64G},
            };
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DENSITY_PER_DIE, i_spd, SET_DRAM_DENSITY, l_field));

            FAPI_TRY( lookup_table_check(iv_dimm, DRAM_DENSITY_MAP, SET_DRAM_DENSITY, l_field, l_sdram_density),
                      "%s failed DRAM_DENSITY lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_dram_density(iv_dimm, l_sdram_density));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the col addr bits field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_col_addr_bits(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_col_addr_bits  = 0;
            const std::vector<uint8_t> l_reserved_bits{0b010, 0b011, 0b100, 0b0101, 0b110, 0b111};
            // =========================================================
            // Item JC-45-2260.01M
            // Page 28
            // DDR5 SPD Document Revision 1
            // Byte 5 (0x005): Key Byte / First SDRAM Addressing
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_COL_MAP =
            {
                {0b000, fapi2::ENUM_ATTR_MEM_EFF_DRAM_COLUMN_BITS_NUM10},
                {0b001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_COLUMN_BITS_NUM11},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::COL_ADDR_BITS, i_spd, SET_COL_ADDR_BITS, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_COL_ADDR_BITS, l_field) );
            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_ADDR_COL_MAP, SET_COL_ADDR_BITS, l_field, l_col_addr_bits));
            FAPI_TRY(mss::attr::set_dram_column_bits(iv_dimm, l_col_addr_bits));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the row addr bits field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_row_addr_bits(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_row_addr_bits = 0;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 28
            // DDR5 SPD Document Revision 1
            // Byte 5 (0x005): Key Byte / First SDRAM Addressing
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_ROW_MAP =
            {
                {0b00000, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM16},
                {0b00001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM17},
                {0b00010, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM18},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::ROW_ADDR_BITS, i_spd, SET_ROW_ADDR_BITS, l_field));
            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_ADDR_ROW_MAP, SET_ROW_ADDR_BITS, l_field, l_row_addr_bits));
            FAPI_TRY(mss::attr::set_dram_row_bits(iv_dimm, l_row_addr_bits));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the prim stack type field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_prim_stack_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_prim_stack_type = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DIE_PER_PACKAGE, i_spd, SET_PRIM_STACK_TYPE, l_field));

            // =========================================================
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Revision 1
            // Byte 4 (0x004): Key Byte / First SDRAM Density & Package
            // =========================================================
            // Note: This byte's validity gets checked in set_prim_die_count
            l_prim_stack_type = (l_field == 0) ? fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_SDP
                                : fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS;

            FAPI_TRY(mss::attr::set_prim_stack_type(iv_dimm, l_prim_stack_type));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the prim die count field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_prim_die_count(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_prim_die_count = 0;

            const std::vector<uint8_t> l_reserved_bits{0b001, 0b110, 0b111};

            // =========================================================
            // Byte 4 maps
            // Item JC-45-2260.01M
            // Page 27
            // DDR5 SPD Document Release 3
            // Byte 4 (0x004): First SDRAM Density and Package Type
            // =========================================================
            const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP =
            {
                // {key byte, number of die}
                {0b000, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D1},
                {0b010, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D2},
                {0b011, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D4},
                {0b100, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D8},
                {0b101, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D16},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DIE_PER_PACKAGE, i_spd, SET_PRIM_DIE_COUNT, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_PRIM_DIE_COUNT, l_field) );
            FAPI_TRY(lookup_table_check(iv_dimm, PRIM_DIE_COUNT_MAP, SET_PRIM_DIE_COUNT, l_field, l_prim_die_count));
            FAPI_TRY(mss::attr::set_prim_die_count(iv_dimm, l_prim_die_count));
        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Set the sdram width field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_sdram_width(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_sdram_width = 0;

            const std::vector<uint8_t> l_reserved_bits{0b100, 0b101, 0b110, 0b111};

            // =========================================================
            // Item JC-45-2260.01M
            // Page 28
            // DDR5 SPD Document Release 1
            // Byte 6 (0x06) : First SDRAM I/O Width
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_WIDTH_MAP =
            {
                // {key byte, device width (bits)}
                {0b000, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4},
                {0b001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8},
                // All others reserved
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::SDRAM_WIDTH, i_spd, SET_DRAM_WIDTH, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_DRAM_WIDTH, l_field) );
            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_WIDTH_MAP, SET_DRAM_WIDTH, l_field, l_sdram_width));
            FAPI_TRY(mss::attr::set_dram_width(iv_dimm, l_sdram_width));
        fapi_try_exit:
            return fapi2::current_err;
        }

        /// @brief Set the burst length field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_burst_length(const std::vector<uint8_t>& i_spd) const
        {
            // =========================================================
            // Item JC-45-2260.01M
            // Page 32
            // DDR5 SPD Document Release 1
            // Byte 12 (0x00C) : SDRAM BL32 & Post Package Repair
            // =========================================================
            // We are harcoding burst length to support 16 clks
            constexpr uint8_t l_burst_length = fapi2::ENUM_ATTR_MEM_BURST_LENGTH_BL16;

            FAPI_TRY(mss::attr::set_burst_length(iv_port, l_burst_length));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the channels per dimm field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_channels_per_dimm(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_channels_per_dimm = 0;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 75
            // DDR5 SPD Document Release 1.0
            // Byte 235 (0x0EB): Memory Channel Bus Width
            // =========================================================
            const std::vector<std::pair<uint8_t, uint8_t> > CHANNELS_PER_DIMM_MAP =
            {
                // {key byte, bus width (in bits)
                {0b00, fapi2::ENUM_ATTR_MEM_EFF_CHANNELS_PER_DIMM_1_CHANNEL},
                {0b01, fapi2::ENUM_ATTR_MEM_EFF_CHANNELS_PER_DIMM_2_CHANNELS},
                // All others reserved
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::CHANNELS_PER_DIMM, i_spd, SET_CHANNELS_PER_DIMM, l_field));
            FAPI_TRY(lookup_table_check(iv_dimm, CHANNELS_PER_DIMM_MAP, SET_CHANNELS_PER_DIMM, l_field, l_channels_per_dimm));
            FAPI_TRY(mss::attr::set_channels_per_dimm(iv_dimm, l_channels_per_dimm));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the bus width field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_bus_width(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_bus_width = 0;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 75
            // DDR5 SPD Document Release 1.0
            // Byte 235 (0x0EB): Memory Channel Bus Width
            // =========================================================
            const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_MAP =
            {
                // {key byte, bus width (in bits)
                {0, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_8_BITS},
                {1, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_16_BITS},
                {2, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_32_BITS},
                {3, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_64_BITS},
                // All others reserved
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::BUS_WIDTH, i_spd, SET_PRIM_BUS_WIDTH, l_field));
            FAPI_TRY(lookup_table_check(iv_dimm, BUS_WIDTH_MAP, SET_PRIM_BUS_WIDTH, l_field, l_bus_width));
            FAPI_TRY(mss::attr::set_prim_bus_width(iv_dimm, l_bus_width));

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
            uint8_t l_cont_codes = 0;
            uint8_t l_last_nonzero_byte = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 95
            // DDR5 SPD Document Release 1.0
            // Byte 512 (0x0200): Module Manufacturer ID Code, First Byte
            // Byte 513 (0x0201): Module Manufacturer ID Code, Second Byte
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::CONTINUATION_CODES, i_spd, SET_MODULE_MFG_ID, l_cont_codes));
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::LAST_NON_ZERO_BYTE, i_spd, SET_MODULE_MFG_ID, l_last_nonzero_byte));

            // Align and endian swap
            right_aligned_insert(l_buffer, l_last_nonzero_byte, l_cont_codes);
            l_field = l_buffer;
            fapi2::endian_swap(l_field);

            FAPI_INF("%s.Module Manufacturer ID Code: %x",
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
            uint8_t l_mfgid_msb = 0;
            uint8_t l_mfgid_lsb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 96
            // DDR5 SPD Document Release 1.0
            // Byte 552 (0x228): DRAM Manufacturer ID code, First Byte
            // Byte 553 (0x229): DRAM Manufacturer ID code, Second Byte
            // =========================================================
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DRAM_MFR_ID_CODE_LSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DRAM_MFR_ID_CODE_MSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_msb));

            // Align and endian swap
            right_aligned_insert(l_buffer, l_mfgid_msb, l_mfgid_lsb);
            l_field = l_buffer;
            fapi2::endian_swap(l_field);

            FAPI_INF("%s.DRAM Manufacturer ID Code: %x",
                     spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_dram_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the supported cas latencies field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_supported_cas_latencies(const std::vector<uint8_t>& i_spd) const
        {
            uint64_t l_field = 0;

            FAPI_TRY(mss::gen::ddr5::get_supported_cas_latencies(iv_dimm, i_spd, get_spd_revision(), l_field))

            FAPI_TRY(mss::attr::set_ddr5_spd_cl_supported(iv_port, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }



        ///
        /// @brief Set the host to ddr speed ratio field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note Uses DDIMM module fields instead of base cnfg fields.
        ///       This is required for later fields so we parse this one here.
        ///
        virtual fapi2::ReturnCode set_host_to_ddr_speed_ratio(const std::vector<uint8_t>& i_spd) const
        {
            using DF = mss::spd::fields<DDR5, DDIMM_MODULE>;
            uint8_t l_field = 0;
            uint8_t l_host_to_ddr_speed_ratio = 0;

            // Continuing with following DDR4 info.
            // =========================================================
            // DDR4 SPD Document Release 4
            // Byte 220 (0x0DC): Host Interface Speed to DDR Interface Speed Ratio
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HOST_TO_DDR_SPEED_RATIO_MAP =
            {
                // {key byte, speed ratio}
                {0b0000, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_1_TO_1},
                {0b0001, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_2_TO_1},
                {0b0010, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_4_TO_1},
                {0b0011, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_8_TO_1},
                {0b0100, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_16_TO_1},
                {0b0101, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_32_TO_1},
                {0b0110, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_64_TO_1},
                {0b0111, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_128_TO_1},
                // All others reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, DF::HI_DDR_SPEED_RATIO, i_spd, SET_HOST_TO_DDR_SPEED_RATIO, l_field));

            FAPI_TRY( lookup_table_check(iv_dimm, HOST_TO_DDR_SPEED_RATIO_MAP, SET_HOST_TO_DDR_SPEED_RATIO, l_field,
                                         l_host_to_ddr_speed_ratio),
                      "%s failed HOST_TO_DDR_SPEED_RATIO lookup check", spd::c_str(iv_dimm) );


            FAPI_TRY(mss::attr::set_host_to_ddr_speed_ratio(iv_dimm, l_host_to_ddr_speed_ratio));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the num master ranks per dimm field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_num_master_ranks_per_dimm(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_rpd = 0;

            // =========================================================
            // Item JC-45-2260.01M
            // Page 72
            // DDR5 SPD Document Revision 1
            // Byte 234 (0x0EA): Module Organization
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP =
            {
                // {key byte, num of package ranks per DIMM (package ranks)}
                {0, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_1R},
                {1, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_2R},
            };

            FAPI_TRY( mss::spd::get_field_spd(iv_ocmb, FIELDS::PACKAGE_RANKS_PER_CHANNEL, i_spd, SET_MRANKS, l_field));
            FAPI_TRY( lookup_table_check(iv_dimm, NUM_PACKAGE_RANKS_MAP, SET_MRANKS, l_field, l_rpd),
                      "%s failed MASTER_RANKS lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_num_master_ranks_per_dimm(iv_dimm, l_rpd));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm ranks cnfgd field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_ranks_cnfgd(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            // Set configed ranks. Set the bit representing the master rank configured (0 being left most.) So,
            // a 4R DIMM would be 0b11110000 (0xF0). This is used by PRD.
            fapi2::buffer<uint8_t> l_ranks_configed;

            // Make sure the number of master ranks is setup
            uint8_t l_master_ranks = 0;
            FAPI_TRY(set_num_master_ranks_per_dimm(i_spd));
            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(iv_dimm, l_master_ranks));

            FAPI_TRY(l_ranks_configed.setBit(0, l_master_ranks),
                     "%s. Failed to setBit", spd::c_str(iv_dimm));

            l_field = l_ranks_configed;

            FAPI_TRY(mss::attr::set_dimm_ranks_configed(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram cwl field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_cwl(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_dram_cl = 0;
            uint8_t l_field = 0;

            // =========================================================
            // Taken from DDR5 SDRAM
            // JESD79-5A
            // Page 389, Table 258
            // The DDR5 CWL is given as CL-2 for all speed bins
            // =========================================================
            FAPI_TRY(mss::attr::get_dram_cl(iv_port, l_dram_cl));
            FAPI_DBG("%s DRAM CL %d", spd::c_str(iv_dimm), l_dram_cl);

            l_field = l_dram_cl - 2;
            FAPI_DBG("%s DRAM CWL %d", spd::c_str(iv_dimm), l_field);

            FAPI_TRY(mss::attr::set_dram_cwl(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm pos metadata field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_pos_metadata(const std::vector<uint8_t>& i_spd) const
        {
            uint32_t l_field = 0;

            using TT = mss::dimmPosTraits<mss::mc_type::ODYSSEY>;
            FAPI_TRY(gen::dimm_pos<TT>(iv_dimm, l_field));

            FAPI_TRY(mss::attr::set_dimm_pos_metadata(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram gen metadata field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_gen_metadata(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(mss::attr::get_dram_gen(iv_dimm, l_field));
            FAPI_TRY(mss::attr::set_dram_gen_metadata(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dimm type metadata field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dimm_type_metadata(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(mss::attr::get_dimm_type(iv_dimm, l_field));
            FAPI_TRY(mss::attr::set_dimm_type_metadata(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the logical ranks field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_logical_ranks(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_prim_stack_type = 0;
            uint8_t l_master_ranks = 0;
            uint8_t l_die_count = 0;

            FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(iv_dimm, l_master_ranks) );
            FAPI_TRY( mss::attr::get_prim_die_count(iv_dimm, l_die_count) );
            FAPI_TRY( mss::attr::get_prim_stack_type(iv_dimm, l_prim_stack_type) );

            {
                // For 3DS parts, the number of die per package is the primary die count
                // For non-3DS parts, only 1 die is present per package.
                // The number of logical ranks is the die count multiplied by the number of ranks
                const auto l_multiplier = (l_prim_stack_type == fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS) ? l_die_count : 1;
                l_field = (l_master_ranks * l_multiplier);
                FAPI_DBG("%s Num Logical Ranks %d", spd::c_str(iv_dimm), l_field);
            }

            FAPI_TRY(mss::attr::set_logical_ranks_per_dimm(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the height 3ds field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_height_3ds(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint16_t l_3ds_height = 0;

            {
                const std::vector< std::pair<uint8_t, uint16_t> > HEIGHT_3DS_MAP =
                {
                    // {key byte, 3DS HEIGHT}
                    {0b000, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_PLANAR},
                    {0b010, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H2},
                    {0b011, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4},
                    {0b100, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8},
                    {0b101, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H16},
                    // All others reserved
                };

                FAPI_TRY( get_field_spd(iv_ocmb, FIELDS::HEIGHT_3DS, i_spd, SET_3DS_HEIGHT, l_field));
                FAPI_TRY( lookup_table_check(iv_dimm, HEIGHT_3DS_MAP, SET_3DS_HEIGHT, l_field, l_3ds_height),
                          "%s failed HEIGHT_3DS lookup check", spd::c_str(iv_dimm) );
            }

            FAPI_TRY(mss::attr::set_3ds_height(iv_dimm, l_3ds_height));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the mem dimm size field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_mem_dimm_size(const std::vector<uint8_t>& i_spd) const
        {
            uint32_t l_field = 0;
            uint8_t l_channels_per_dimm = 0;
            uint8_t l_bus_width_per_channel = 0;
            uint8_t l_dram_width = 0;
            uint8_t l_prim_die_count = 0;
            uint8_t l_dram_density = 0;
            uint8_t l_logical_rank_per_dimm = 0;

            FAPI_TRY( mss::attr::get_channels_per_dimm(iv_dimm, l_channels_per_dimm) );
            FAPI_TRY( mss::attr::get_prim_bus_width(iv_dimm, l_bus_width_per_channel) );
            FAPI_TRY( mss::attr::get_dram_width(iv_dimm, l_dram_width) );
            FAPI_TRY( mss::attr::get_prim_die_count(iv_dimm, l_prim_die_count) );
            FAPI_TRY( mss::attr::get_dram_density(iv_dimm, l_dram_density) );
            FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(iv_dimm, l_logical_rank_per_dimm) );

            // Calculate dimm size
            // Formula from SPD Spec (seriously, they don't have parenthesis in the spec)
            // Total = l_channels_per_dimm * l_bus_width_per_channel / l_dram_width * l_die_per_package *
            //         l_dram_density / 8 * l_ranks_per_channel
            l_field = (l_channels_per_dimm * l_bus_width_per_channel * l_prim_die_count * l_dram_density * l_logical_rank_per_dimm)
                      / (8 * l_dram_width);

            FAPI_DBG("%s DIMM size = %d => %d * (%d / %d) * %d * (%d / 8) * %d",
                     spd::c_str(iv_dimm), l_field, l_channels_per_dimm, l_bus_width_per_channel, l_dram_width,
                     l_prim_die_count, l_dram_density, l_logical_rank_per_dimm );

            FAPI_TRY(mss::attr::set_dimm_size(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process the data init fields - these fields should be processed first
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_data_init_fields(const std::vector<uint8_t>& i_spd) const
        {
            // These fields need to be set first, as these are used for many
            // fields later on
            FAPI_TRY(set_dimm_ranks_cnfgd(i_spd));
            FAPI_TRY(set_host_to_ddr_speed_ratio(i_spd));
            FAPI_TRY(set_num_master_ranks_per_dimm(i_spd)); // AKA mranks
            FAPI_TRY(set_hybrid(i_spd));
            FAPI_TRY(set_hybrid_media(i_spd));
            FAPI_TRY(set_dimm_type(i_spd));

            // Generic_metadata_fields
            FAPI_TRY(set_dimm_pos_metadata(i_spd));
            FAPI_TRY(set_dram_gen_metadata(i_spd));
            FAPI_TRY(set_dimm_type_metadata(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process the fields for base rev 0.3
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            // These likely should have been done already, but just in case
            FAPI_TRY(process_data_init_fields(i_spd));

            // Base cnfg fields
            FAPI_TRY(set_sdram_density(i_spd));
            FAPI_TRY(set_col_addr_bits(i_spd));
            FAPI_TRY(set_row_addr_bits(i_spd));
            FAPI_TRY(set_prim_stack_type(i_spd));
            FAPI_TRY(set_channels_per_dimm(i_spd));
            FAPI_TRY(set_prim_die_count(i_spd));
            FAPI_TRY(set_sdram_width(i_spd));
            FAPI_TRY(set_bus_width(i_spd));
            FAPI_TRY(set_supported_cas_latencies(i_spd));

            // TODO: Zen:MST-1427 Processing for DDR5 EFD module
            // Timing fields

            FAPI_TRY(set_module_mfg_id(i_spd));
            FAPI_TRY(set_dram_mfg_id(i_spd));
            FAPI_TRY(set_dram_cwl(i_spd));
            FAPI_TRY(set_burst_length(i_spd));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process derived attributes (processed after all others)
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_derived(const std::vector<uint8_t>& i_spd) const
        {
            FAPI_TRY(set_logical_ranks(i_spd));
            FAPI_TRY(set_height_3ds(i_spd));
            FAPI_TRY(set_mem_dimm_size(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }

};

} // ddr5

} // spd

} // mss

#endif
