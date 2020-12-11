/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_base_engine.H $ */
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
/// @file p10_base_engine.H
/// @brief Base cnfg eff_config engine
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_BASE_ENGINE_H_
#define _P10_BASE_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/utils/find.H>

#include <lib/utils/pmic_consts.H>
#include <lib/shared/exp_consts.H>

#include <mss_pmic_attribute_setters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/data_engine/attr_engine_traits.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>

namespace mss
{
namespace spd
{

///
/// @brief Class for base module section of SPD Rev 0.3
///
class base_0_3
{
        using F = mss::spd::fields<DDR4, BASE_CNFG>;

    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    public:

        ///
        /// @brief Construct a new base rev 0.3 object
        /// @param[in] i_dimm DIMM target
        ///
        base_0_3(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            iv_dimm(i_dimm),
            iv_port(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm)),
            iv_ocmb(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm)) {}

        ///
        /// @brief Destroy the ddimm_0_3 object
        ///
        virtual ~base_0_3() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const
        {
            return mss::spd::rev::V0_3;
        }

        // Check functions here return true when any value is valid (0x00 through 0xFF)

        ///
        /// @brief Traits for revision
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_revision(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for prim signal loading
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_prim_signal_loading(const uint8_t i_field) const
        {
            return (i_field <= 0b10);
        }

        ///
        /// @brief Traits for cont codes
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_continuation_codes(const uint8_t i_field) const
        {
            return (i_field <= 0x89);
        }

        ///
        /// @brief Traits for last non zero byte
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_last_non_zero_byte(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits for MFR ID Code LSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_dram_mfr_id_code_lsb(const uint8_t i_field) const
        {
            return (i_field <= 0x89);
        }

        ///
        /// @brief Traits MFR ID Code MSB
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_dram_mfr_id_code_msb(const uint8_t i_field) const
        {
            return (i_field >= 0x00);
        }

// Unused fields
#if 0
        virtual bool check_bus_ext_width(const uint8_t i_field) const
        {
            return (i_field <= 0b001);
        }

        virtual bool check_therm_sensor(const uint8_t i_field) const
        {
            return (i_field <= 0b1);
        }

        virtual bool check_extended_module_type(const uint8_t i_field) const
        {
            return (i_field == 0);
        }

        // TK needs to be ported from old engine to new engine
        virtual bool check_fine_timebase(const uint8_t i_field) const
        {
            return (i_field == 0);
        }

        virtual bool check_medium_timebase(const uint8_t i_field) const
        {
            return (i_field == 0);
        }

        virtual bool check_tck_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_tck_max(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_taa_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trcd_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trp_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trasmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trasmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trcmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trcmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc1min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc1min_msb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc2min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc2min_msb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc4min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trfc4min_msb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_tfawmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_tfawmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trrd_s_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trrd_l_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_tccd_l_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twrmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twrmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twtrmin_s_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twtrmin_s_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twtrmin_l_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_twtrmin_l_lsb(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_tccd_l_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_trrd_l_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_trrd_s_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_trc_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_trp_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_trcd_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_taa_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_tck_max(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_offset_tck_min(const uint8_t i_field) const
        {
            return true;
        }
#endif

        ///
        /// @brief Set the revision field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_revision(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::REVISION, i_spd, SET_SPD_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_revision(l_field),
                                  F::REVISION.get_byte(i_spd),
                                  l_field,
                                  SET_SPD_REVISION,
                                  "SPD Revision"));

            FAPI_TRY(mss::attr::set_spd_revision(iv_port, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the dram gen field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_dram_gen(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            uint8_t l_dram_gen = 0;
            // Sparsed reserved bits within valid SPD field range
            const std::vector<uint8_t> l_reserved_bits{0x00, 0x0D};

            // =========================================================
            // DDR4 SPD Document Release 4
            // Byte 2 (0x002): Key Byte / DRAM Device Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_GEN_MAP =
            {
                //{key value, dram gen}
                {0x0C, fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4}
                // Other key bytes reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::DEVICE_TYPE, i_spd, SET_DRAM_GEN, l_field));
            FAPI_TRY(check::reserved_values(iv_ocmb, l_reserved_bits, DEVICE_TYPE, l_field) );

            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_GEN_MAP, SET_DRAM_GEN, l_field, l_dram_gen),
                     "%s failed DRAM_GEN lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_dram_gen(iv_dimm, l_dram_gen));

        fapi_try_exit:
            return fapi2::current_err;
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

            const std::vector<uint8_t> l_reserved_bits{0b0111, 0b1011, 0b1110, 0b1111};

            // =========================================================
            // DDR4 SPD Document Release 4
            // Byte 3 (0x003): Key Byte / Module Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP =
            {
                //{key byte, dimm type}
                {1, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM},
                {2, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM},
                {10, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM},
                // All others reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::BASE_MODULE, i_spd, SET_DIMM_TYPE, l_field));
            FAPI_TRY( check::reserved_values(iv_ocmb, l_reserved_bits, BASE_MODULE_TYPE, l_field) );

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
            // DDR4 SPD Document Release 4
            // Byte 3 (0x003): Key Byte / Module Type - Hybrid
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MAP =
            {
                //{key byte, dimm type}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_NOT_HYBRID},
                {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_IS_HYBRID},

                // All others reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::HYBRID, i_spd, SET_HYBRID, l_field));

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

            // =========================================================
            // DDR4 SPD Document Release 4
            // Byte 3 (0x003): Key Byte / Module Type - Hybrid
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MEMORY_TYPE_MAP =
            {

                //{key byte, dimm type}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NONE},
                {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NVDIMM},
                {3, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_MDS},
                // All others reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::HYBRID_MEDIA, i_spd, SET_HYBRID_MEDIA, l_field));

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
            // DDR4 SPD Document Release 4
            // Byte 2 (0x002): Key Byte / DRAM Device Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_DENSITY_MAP =
            {
                // {key byte, capacity in GBs}
                {4, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_4G},
                {5, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_8G},
                {6, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G},
            };
            FAPI_TRY(get_field_spd(iv_ocmb, F::SDRAM_CAPACITY, i_spd, SET_DRAM_DENSITY, l_field));

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

            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_COL_MAP =
            {
                {0b001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_COLUMN_BITS_NUM10},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::COL_ADDR_BITS, i_spd, SET_COL_ADDR_BITS, l_field));
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

            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_ROW_MAP =
            {
                {0b010, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM14},
                {0b011, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM15},
                {0b100, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM16},
                {0b101, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM17},
                {0b110, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM18},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::ROW_ADDR_BITS, i_spd, SET_ROW_ADDR_BITS, l_field));
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

            FAPI_TRY(get_field_spd(iv_ocmb, F::PRIM_SIGNAL_LOADING, i_spd, SET_PRIM_STACK_TYPE, l_field));
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_revision(l_field),
                                  F::PRIM_SIGNAL_LOADING.get_byte(i_spd),
                                  l_field,
                                  SET_PRIM_STACK_TYPE,
                                  "Primary Signal Loading"));

            FAPI_TRY(mss::attr::set_prim_stack_type(iv_dimm, l_field));
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

            // =========================================================
            // Byte 6 maps
            // Item JC-45-2220.01x
            // Page 19
            // DDR4 SPD Document Release 3
            // Byte 6 (0x006): Primary SDRAM Package Type
            // =========================================================
            const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP =
            {
                // {key byte, number of die}
                {0, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D1},
                {1, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D2},
                {2, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D3},
                {3, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D4},
                {4, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D5},
                {5, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D6},
                {6, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D7},
                {7, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D8},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::PRIM_DIE_COUNT, i_spd, SET_PRIM_DIE_COUNT, l_field));
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

            // =========================================================
            // Byte 12 maps
            // Item JC-45-2220.01x
            // Page 23
            // DDR4 SPD Document Release 3
            // Byte 12 (0x00C): Module Organization
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_WIDTH_MAP =
            {
                // {key byte, device width (bits)}
                {0, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4},
                {1, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8},
                {2, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X16},
                {3, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X32},
                // All others reserved
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::SDRAM_WIDTH, i_spd, SET_DRAM_WIDTH, l_field));
            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_WIDTH_MAP, SET_DRAM_WIDTH, l_field, l_sdram_width));
            FAPI_TRY(mss::attr::set_dram_width(iv_dimm, l_sdram_width));
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
            // DDR4 SPD Document Release 4
            // Byte 12 (0x00C): Module Organization
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP =
            {
                // {key byte, num of package ranks per DIMM (package ranks)}
                {0, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_1R},
                {1, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_2R},
                {3, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R},
            };

            FAPI_TRY(get_field_spd(iv_ocmb, F::PACKAGE_RANKS, i_spd, SET_MRANKS, l_field));
            FAPI_TRY( lookup_table_check(iv_dimm, NUM_PACKAGE_RANKS_MAP, SET_MRANKS, l_field, l_rpd),
                      "%s failed MASTER_RANKS lookup check", spd::c_str(iv_dimm) );

            FAPI_TRY(mss::attr::set_num_master_ranks_per_dimm(iv_dimm, l_rpd));
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
            // Byte 13 maps
            // Item JC-45-2220.01x
            // Page 27
            // DDR4 SPD Document Release 3
            // Byte 13 (0x00D): Module Memory Bus Width
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

            FAPI_TRY(get_field_spd(iv_ocmb, F::BUS_WIDTH, i_spd, SET_PRIM_BUS_WIDTH, l_field));
            FAPI_TRY(lookup_table_check(iv_dimm, BUS_WIDTH_MAP, SET_PRIM_BUS_WIDTH, l_field, l_bus_width));
            FAPI_TRY(mss::attr::set_prim_bus_width(iv_dimm, l_bus_width));

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
            uint8_t l_first_raw_byte = 0;
            uint8_t l_sec_raw_byte = 0;
            uint8_t l_third_raw_byte = 0;
            uint8_t l_fourth_raw_byte = 0;
            uint8_t l_dimm_type = 0;
            uint32_t l_field = 0;
            uint8_t l_rev = get_spd_revision();

            FAPI_TRY(get_field_spd(iv_ocmb, F::CL_FIRST_BYTE, i_spd, exp::SET_SPD_CL_SUPPORTED, l_first_raw_byte));
            FAPI_TRY(get_field_spd(iv_ocmb, F::CL_SECOND_BYTE, i_spd, exp::SET_SPD_CL_SUPPORTED, l_sec_raw_byte));
            FAPI_TRY(get_field_spd(iv_ocmb, F::CL_THIRD_BYTE, i_spd, exp::SET_SPD_CL_SUPPORTED, l_third_raw_byte));
            FAPI_TRY(get_field_spd(iv_ocmb, F::CL_FOURTH_BYTE, i_spd, exp::SET_SPD_CL_SUPPORTED, l_fourth_raw_byte));

            FAPI_TRY(mss::attr::get_dimm_type(iv_dimm, l_dimm_type));

            {
                // Buffers used for bit manipulation
                // Combine Bytes to create bitmap - right aligned
                fapi2::buffer<uint64_t> l_buffer;
                right_aligned_insert(l_buffer, l_fourth_raw_byte, l_third_raw_byte, l_sec_raw_byte, l_first_raw_byte);

                // According to the JEDEC spec:
                // Byte 22 (Bits 7~0) and Byte 23 are reserved in the base revision SPD general section
                // Only bit 6 (right-aligned) for Byte 23 is reserved for subsequent SPD revisions
                // Check for a valid value, and that reserved bit is not set
                // We return Byte 23 arbitrarily as the failed byte, but any byte (20 - 23) would work
                // This rev 1.0 does not apply to DDIMM 1.0 - so make sure we are not a ddimm
                const size_t MAX_VALID_VAL = mss::gen::get_max_valid_cl_val(l_rev, l_dimm_type);

                constexpr uint64_t DATA_START_OFFSET  = 32;
                constexpr uint64_t RESERVED_BIT = DATA_START_OFFSET + 1;
                // Bit 6 of byte 23 must be 0 (reserved for future use)
                const bool RESERVED_BIT_VALUE = l_buffer.getBit<RESERVED_BIT>();

                FAPI_TRY( mss::check::invalid_value(iv_dimm,
                                                    l_buffer <= MAX_VALID_VAL && !RESERVED_BIT_VALUE,
                                                    23,
                                                    l_buffer,
                                                    mss::BAD_SPD_DATA,
                                                    "Failed check on CAS latencies supported") );

                // Update output value only if range check passes
                l_field = uint32_t(l_buffer);

                FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
                         spd::c_str(iv_dimm),
                         l_field);
            }
            FAPI_TRY(mss::attr::set_exp_spd_cl_supported(iv_port, l_field));
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

            FAPI_TRY(get_field_spd(iv_ocmb, F::CONTINUATION_CODES, i_spd, SET_MODULE_MFG_ID, l_cont_codes));
            FAPI_TRY(get_field_spd(iv_ocmb, F::LAST_NON_ZERO_BYTE, i_spd, SET_MODULE_MFG_ID, l_last_nonzero_byte));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_continuation_codes(l_cont_codes),
                                  F::CONTINUATION_CODES.get_byte(i_spd),
                                  l_cont_codes,
                                  SET_MODULE_MFG_ID,
                                  "Number of continuation codes, module manufacturer"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_last_non_zero_byte(l_last_nonzero_byte),
                                  F::LAST_NON_ZERO_BYTE.get_byte(i_spd),
                                  l_last_nonzero_byte,
                                  SET_MODULE_MFG_ID,
                                  "Last non-zero byte"));

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

            FAPI_TRY(get_field_spd(iv_ocmb, F::DRAM_MFR_ID_CODE_LSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::DRAM_MFR_ID_CODE_MSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_msb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_lsb(l_mfgid_lsb),
                                  F::DRAM_MFR_ID_CODE_LSB.get_byte(i_spd),
                                  l_mfgid_lsb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM manufacturer ID code, LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_msb(l_mfgid_msb),
                                  F::DRAM_MFR_ID_CODE_MSB.get_byte(i_spd),
                                  l_mfgid_msb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM manufacturer ID code, MSB"));

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
        /// @brief Set the host to ddr speed ratio field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note Uses DDIMM module fields instead of base cnfg fields.
        ///       This is required for later fields so we parse this one here.
        ///
        virtual fapi2::ReturnCode set_host_to_ddr_speed_ratio(const std::vector<uint8_t>& i_spd) const
        {
            using DF = mss::spd::fields<DDR4, DDIMM_MODULE>;
            uint8_t l_field = 0;
            uint8_t l_host_to_ddr_speed_ratio = 0;

            // =========================================================
            // DDR4 SPD Document Release 4
            // Byte 220 (0x0DC): Host Interface Speed to DDR Interface Speed Ratio
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HOST_TO_DDR_SPEED_RATIO_MAP =
            {
                // {key byte, speed ratio}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_1_TO_1},
                {1, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_2_TO_1},
                {2, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_4_TO_1},
                {3, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_8_TO_1},
                {4, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_16_TO_1},
                {5, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_32_TO_1},
                {6, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_64_TO_1},
                {7, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_128_TO_1},
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

            mss::attr::set_dimm_ranks_configed(iv_dimm, l_field);

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
            uint8_t l_field = 0;

            // Taken from DDR4 JEDEC spec 1716.78C
            // Proposed DDR4 Full spec update(79-4A)
            // Page 26, Table 7
            const std::vector<std::pair<uint64_t, uint8_t> > CWL_TABLE_1 =
            {
                {1866, 10},
                {2133, 11},
                {2400, 12},
                {2666, 14},
                {2933, 16},
                {3200, 16},
            };

            const std::vector<std::pair<uint64_t, uint8_t> > CWL_TABLE_2 =
            {
                // Note that 2tCK write preamble is not valid for 1866 or 2133 speed grades
                {2400, 14},
                {2666, 16},
                {2933, 18},
                {3200, 18},
            };

            // TK This could change but not sure where to get this from
            uint64_t l_freq = 0;
            uint8_t l_preambles[mss::exp::sizes::MAX_RANK_PER_DIMM] = {0};
            fapi2::buffer<uint8_t> l_preamble;

            FAPI_TRY( mss::attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( mss::attr::get_si_dram_preamble(iv_dimm, l_preambles) );

            // TK Using the preamble for rank0 for now
            l_preamble = l_preambles[0];

            if (!l_preamble.getBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_WRITE_PREAMBLE_BIT>())
            {
                FAPI_TRY(lookup_table_check(iv_dimm, CWL_TABLE_1, SET_DRAM_CWL, l_freq, l_field));
            }
            else
            {
                FAPI_TRY(lookup_table_check(iv_dimm, CWL_TABLE_2, SET_DRAM_CWL, l_freq, l_field));
            }

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

            using TT = mss::dimmPosTraits<mss::mc_type::EXPLORER>;
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
                // For single-load-stack(3DS) the logical ranks per package ends up being the same as the die count.
                // For MONOLITHIC & MULTI_LOAD_STACK
                // The die count isn't guaranteed to be 1 (e.g. SDP - 1 die package, DDP - 2 die package).
                // Value of 1 has no meaning and is used for calculation purposes as defined by the SPD spec.
                const auto l_multiplier = (l_prim_stack_type == fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS) ? l_die_count : 1;
                l_field = (l_master_ranks * l_multiplier);
                FAPI_DBG("%s Num Logical Ranks %d", spd::c_str(iv_dimm), l_field);
            }

            FAPI_TRY(mss::attr::set_logical_ranks_per_dimm(iv_dimm, l_field));

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
            uint8_t l_dram_width = 0;
            uint8_t l_dram_density = 0;
            uint8_t l_logical_rank_per_dimm = 0;
            uint8_t l_bus_width = 0;

            FAPI_TRY( mss::attr::get_dram_width(iv_dimm, l_dram_width) );
            FAPI_TRY( mss::attr::get_dram_density(iv_dimm, l_dram_density) );
            FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(iv_dimm, l_logical_rank_per_dimm) );
            FAPI_TRY( mss::attr::get_prim_bus_width(iv_dimm, l_bus_width) );

            // Calculate dimm size
            // Formula from SPD Spec (seriously, they don't have parenthesis in the spec)
            // Total = SDRAM Capacity / 8 * Primary Bus Width / SDRAM Width * Logical Ranks per DIMM
            l_field = (l_dram_density * l_bus_width * l_logical_rank_per_dimm) / (8 * l_dram_width);

            FAPI_DBG("%s DIMM size = %d => (%d * %d * %d) / (8 * %d)",
                     spd::c_str(iv_dimm), l_field, l_dram_density, l_bus_width, l_logical_rank_per_dimm, l_dram_width);

            FAPI_TRY(mss::attr::set_dimm_size(iv_dimm, l_field));

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
            uint16_t l_field = 0;
            uint8_t l_master_ranks_per_dimm = 0;
            uint8_t l_logical_ranks_per_dimm = 0;

            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(iv_dimm, l_master_ranks_per_dimm));
            FAPI_TRY(mss::attr::get_logical_ranks_per_dimm(iv_dimm, l_logical_ranks_per_dimm));
            {
                const uint16_t l_result = l_logical_ranks_per_dimm / l_master_ranks_per_dimm;

                const std::vector< std::pair<uint16_t, uint16_t> > HEIGHT_3DS_MAP =
                {
                    // {key byte, 3DS HEIGHT}
                    {1, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_PLANAR},
                    {2, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H2},
                    {4, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4},
                    {8, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8},
                    // All others reserved
                };

                // Map SPD value to desired setting
                FAPI_TRY(lookup_table_check(iv_dimm, HEIGHT_3DS_MAP, mss::SET_3DS_HEIGHT, l_result, l_field));
            }

            FAPI_TRY(mss::attr::set_3ds_height(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

// Unused fields
// XXXXX here is for the FFDC value, which should be filled in when these are needed.
// Currently, no enum exists for them
#if 0
        fapi2::ReturnCode set_dram_stepping(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::DRAM_STEPPING, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_dram_stepping(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_bus_ext_width(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::BUS_EXT_WIDTH, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_bus_ext_width(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_therm_sensor(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::THERM_SENSOR, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_therm_sensor(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_extended_module_type(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::EXTENDED_MODULE_TYPE, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_extended_module_type(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_fine_timebase(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::FINE_TIMEBASE, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_fine_timebase(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_medium_timebase(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::MEDIUM_TIMEBASE, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_medium_timebase(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_tck_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TCK_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_tck_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_tck_max(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TCK_MAX, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_tck_max(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        // TK populate these when timing fields are ported to the new API
        virtual fapi2::ReturnCode set_taa_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TAA_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_exp_spd_taa_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trcd_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRCD_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trcd_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trp_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRP_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trp_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trasmin_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRASMIN_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trasmin_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trasmin_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRASMIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trasmin_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trcmin_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRCMIN_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trcmin_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trcmin_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRCMIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trcmin_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc1min_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC1MIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc1min_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc1min_msb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC1MIN_MSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc1min_msb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc2min_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC2MIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc2min_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc2min_msb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC2MIN_MSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc2min_msb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc4min_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC4MIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc4min_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trfc4min_msb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC4MIN_MSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trfc4min_msb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_tfawmin_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TFAWMIN_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_tfawmin_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_tfawmin_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TFAWMIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_tfawmin_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trrd_s_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRRD_S_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trrd_s_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_trrd_l_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRRD_L_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_trrd_l_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_tccd_l_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TCCD_L_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_tccd_l_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twrmin_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWRMIN_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twrmin_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twrmin_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWRMIN_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twrmin_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twtrmin_s_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_S_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twtrmin_s_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twtrmin_s_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_S_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twtrmin_s_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twtrmin_l_msn(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_L_MSN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twtrmin_l_msn(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_twtrmin_l_lsb(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_L_LSB, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_twtrmin_l_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_tccd_l_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TCCD_L_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_tccd_l_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_trrd_l_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRRD_L_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_trrd_l_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_trrd_s_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRRD_S_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_trrd_s_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_trc_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRC_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_trc_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_trp_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRP_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_trp_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_trcd_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRCD_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_trcd_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_taa_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TAA_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_taa_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_tck_max(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TCK_MAX, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_tck_max(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        virtual fapi2::ReturnCode set_offset_tck_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TCK_MIN, i_spd, XXXXX, l_field));

            FAPI_TRY(mss::attr::set_offset_tck_min(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }

        fapi2::ReturnCode set_crc(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_crc_msb = 0;
            uint8_t l_crc_lsb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;
            FAPI_TRY(get_field_spd(iv_ocmb, F::CRC_LSB, i_spd, XXXXX, l_crc_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::CRC_MSB, i_spd, XXXXX, l_crc_msb));

            // Combining bits to create timing value (in a buffer)
            right_aligned_insert(l_buffer, l_crc_msb, l_crc_lsb);

            // This value isn't bounded in the SPD document
            l_field = l_buffer;

            FAPI_INF("%s. Cyclical Redundancy Code (CRC): %d",
                     spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_crc_lsb(iv_dimm, l_field));
        fapi_try_exit:
            return fapi2::current_err;
        }
#endif

        ///
        /// @brief Process the data init fields - these fields should be processed first
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_data_init_fields(const std::vector<uint8_t>& i_spd) const
        {
            // These fields are formerly known as the data_init_traits
            // They should be set first, as these are used for many
            // fields later on
            FAPI_TRY(set_revision(i_spd));
            FAPI_TRY(set_dimm_ranks_cnfgd(i_spd));
            FAPI_TRY(set_host_to_ddr_speed_ratio(i_spd));
            FAPI_TRY(set_num_master_ranks_per_dimm(i_spd)); // AKA mranks
            FAPI_TRY(set_hybrid_media(i_spd));
            FAPI_TRY(set_hybrid(i_spd));
            FAPI_TRY(set_dram_gen(i_spd));
            FAPI_TRY(set_dimm_type(i_spd));

            // Generic_metadata_fields
            FAPI_TRY(set_dimm_pos_metadata(i_spd));
            FAPI_TRY(set_dram_gen_metadata(i_spd));
            FAPI_TRY(set_dimm_type_metadata(i_spd));

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
            // Order here matters!
            FAPI_TRY(set_logical_ranks(i_spd));
            FAPI_TRY(set_height_3ds(i_spd)); // 3ds must be calculated after logical ranks
            FAPI_TRY(set_mem_dimm_size(i_spd));

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
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            auto l_facade = mss::spd::facade(iv_dimm, i_spd, l_rc);

            // These likely should have been done already, but just in case
            FAPI_TRY(process_data_init_fields(i_spd));

            // Base cnfg fields
            FAPI_TRY(set_sdram_density(i_spd));
            FAPI_TRY(set_col_addr_bits(i_spd));
            FAPI_TRY(set_row_addr_bits(i_spd));
            FAPI_TRY(set_prim_stack_type(i_spd));
            FAPI_TRY(set_prim_die_count(i_spd));
            FAPI_TRY(set_sdram_width(i_spd));
            FAPI_TRY(set_bus_width(i_spd));
            FAPI_TRY(set_supported_cas_latencies(i_spd));

            // Use engine for these until we replace it
            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::exp::attr_eff_engine_fields, mss::exp::attr_eff_engine_fields::SPD_TAA_MIN>::single_set(
                l_facade);

            mss::gen::attr_engine<proc_type::PROC_P10, mss::attr_eff_engine_fields>::set(l_facade);

// TK populate when timing fields are ported to the new API
#if 0
            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRFC_DLR>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRCD>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRP>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRAS>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRFC>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TFAW>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRRD_S>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRRD_L>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TCCD_L>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TWR>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TWTR_S>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TWTR_L>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TRTP>::single_set(
                l_facade);

            mss::gen::attr_engine
            <proc_type::PROC_P10, mss::attr_eff_engine_fields, mss::attr_eff_engine_fields::DRAM_TREFI>::single_set(
                l_facade);
#endif

// TK populate functions when timing fields are ported to the new API
#if 0
            FAPI_TRY(set_taa_min(i_spd)); // eng
            FAPI_TRY(set_trcd_min(i_spd)); // eng
            FAPI_TRY(set_trp_min(i_spd)); // eng
            FAPI_TRY(set_trasmin_msn(i_spd));// eng
            FAPI_TRY(set_trasmin_lsb(i_spd)); //eng
            FAPI_TRY(set_trcmin_msn(i_spd)); // skip
            FAPI_TRY(set_trcmin_lsb(i_spd)); // skip
            FAPI_TRY(set_trfc1min_lsb(i_spd)); // eng
            FAPI_TRY(set_trfc1min_msb(i_spd)); // eng
            FAPI_TRY(set_trfc2min_lsb(i_spd)); // eng
            FAPI_TRY(set_trfc2min_msb(i_spd)); // eng
            FAPI_TRY(set_trfc4min_lsb(i_spd)); // eng
            FAPI_TRY(set_trfc4min_msb(i_spd)); // eng
            FAPI_TRY(set_tfawmin_msn(i_spd)); //  eng
            FAPI_TRY(set_tfawmin_lsb(i_spd)); //  eng
            FAPI_TRY(set_trrd_s_min(i_spd)); // eng
            FAPI_TRY(set_trrd_l_min(i_spd)); // eng
            FAPI_TRY(set_tccd_l_min(i_spd)); // eng
            FAPI_TRY(set_twrmin_msn(i_spd)); // eng
            FAPI_TRY(set_twrmin_lsb(i_spd)); // eng
            FAPI_TRY(set_twtrmin_s_msn(i_spd)); // eng
            FAPI_TRY(set_twtrmin_s_lsb(i_spd)); // eng
            FAPI_TRY(set_twtrmin_l_msn(i_spd)); // eng
            FAPI_TRY(set_twtrmin_l_lsb(i_spd)); // eng
            FAPI_TRY(set_offset_tck_max(i_spd)); // skip
            FAPI_TRY(set_offset_tck_min(i_spd)); // skip
#endif


            FAPI_TRY(set_module_mfg_id(i_spd));
            FAPI_TRY(set_dram_mfg_id(i_spd));
            FAPI_TRY(set_dram_cwl(i_spd));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Class for base module section of SPD Rev 0.4
///
class base_0_4 : public base_0_3
{
    public:
        ///
        /// @brief Construct a new base rev 0.4 object
        ///
        /// @param[in] i_dimm DIMM target
        ///
        base_0_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) : base_0_3(i_dimm)
        {
        }

        virtual ~base_0_4() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        /// @note Rev 0.4
        ///
        virtual mss::spd::rev get_spd_revision() const override
        {
            return mss::spd::rev::V0_4;
        }

        // Virtual function overloads go here

        /// @brief Process the fields for base cnfg rev 0.4
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {

            // The naming here is a bit tricky: 0.3 process will process fields
            // that originated in 0.3, but will use any field processors/traits
            // that were overridden for the current class type (ex. base_0_4)

            // Only brand new fields for this revision should be explicitly
            // called here below the call to this function
            FAPI_TRY(base_0_3::process(i_spd));

            // Base Cnfg 0.4 new field processing goes here

        fapi_try_exit:
            return fapi2::current_err;
        }
};

//
// Can be updated with the earliest supported base cnfg revision
//
using base_cnfg_base = base_0_3;

} // spd

}// mss

#endif
