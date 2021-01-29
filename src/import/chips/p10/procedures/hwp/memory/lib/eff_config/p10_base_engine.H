/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_base_engine.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
// *HWP Level: 3
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
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/dimm/mss_timing.H>
#include <generic/memory/lib/spd/spd_checker.H>

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

#endif

        ///
        /// @brief Traits tck min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_tck_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits tck max
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_tck_max(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits taa min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_taa_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trcd min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trcd_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trp min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trp_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trasmin msn
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trasmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trasmin lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trasmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

#if 0

        virtual bool check_trcmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trcmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

#endif
        ///
        /// @brief Traits trfc1min lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc1min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trfc1min msb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc1min_msb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trfc2min lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc2min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trfc2min msb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc2min_msb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trfc4min lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc4min_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits trfc4min msb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_trfc4min_msb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits tfawmin msn
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_tfawmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits tfawmin lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_tfawmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

#if 0
        virtual bool check_trrd_s_min(const uint8_t i_field) const
        {
            return true;
        }

        virtual bool check_trrd_l_min(const uint8_t i_field) const
        {
            return true;
        }
#endif
        ///
        /// @brief Traits tccd l min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_tccd_l_min(const uint8_t i_field) const
        {
            return (i_field > 0);
        }

        ///
        /// @brief Traits twrmin msn
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twrmin_msn(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits twrmin lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twrmin_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits twtrmin s msn
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twtrmin_s_msn(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits twtrmin s lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twtrmin_s_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits twtrmin l msn
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twtrmin_l_msn(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits twtrmin l lsb
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_twtrmin_l_lsb(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits offset tccd l min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_offset_tccd_l_min(const uint8_t i_field) const
        {
            return true;
        }
#if 0
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

#endif
        ///
        /// @brief Traits offset trp min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_offset_trp_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits offset trcd min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_offset_trcd_min(const uint8_t i_field) const
        {
            return true;
        }

        ///
        /// @brief Traits offset taa min
        ///
        /// @param[in] i_field field value
        /// @return true/false in specified range
        ///
        virtual bool check_offset_taa_min(const uint8_t i_field) const
        {
            return true;
        }
#if 0
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
            uint32_t l_field = 0;

            FAPI_TRY(mss::gen::get_supported_cas_latencies(iv_dimm, i_spd, get_spd_revision(), l_field))

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

#endif

        ///
        /// @brief Set the taa field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_taa(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_timing_mtb = 0;
            uint8_t l_timing_ftb = 0;
            uint8_t l_mtb = 0;
            uint8_t l_ftb = 0;
            uint16_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TAA_MIN, i_spd, exp::SET_TAA_MIN, l_timing_mtb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TAA_MIN, i_spd, exp::SET_TAA_MIN, l_timing_ftb));

            // Range checks
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_taa_min(l_timing_mtb),
                                  F::TAA_MIN.get_byte(i_spd),
                                  l_timing_mtb,
                                  exp::SET_TAA_MIN,
                                  "TAA Min"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_offset_taa_min(l_timing_ftb),
                                  F::OFFSET_TAA_MIN.get_byte(i_spd),
                                  l_timing_ftb,
                                  exp::SET_TAA_MIN,
                                  "Offset TAA Min"));

            FAPI_TRY( spd::get_timebases(iv_ocmb, i_spd, l_mtb, l_ftb) );
            FAPI_DBG("%s medium timebase (ps): %ld, fine timebase (ps): %ld, %s (MTB): %ld, (FTB): %ld",
                     spd::c_str(iv_dimm), l_mtb, l_ftb, "TAA", l_timing_mtb, l_timing_ftb );

            l_field = spd::calc_timing_from_timebase(l_timing_mtb, l_mtb, l_timing_ftb, l_ftb);

            FAPI_TRY(mss::attr::set_exp_spd_taa_min(iv_port, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tcd min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trcd_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_timing_mtb = 0;
            uint8_t l_timing_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRCD_MIN, i_spd, SET_DRAM_TRCD, l_timing_mtb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRCD_MIN, i_spd, SET_DRAM_TRCD, l_timing_ftb));

            // Range checks
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trcd_min(l_timing_mtb),
                                  F::TRCD_MIN.get_byte(i_spd),
                                  l_timing_mtb,
                                  SET_DRAM_TRCD,
                                  "TRCD Min"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_offset_trcd_min(l_timing_ftb),
                                  F::OFFSET_TRCD_MIN.get_byte(i_spd),
                                  l_timing_ftb,
                                  SET_DRAM_TRCD,
                                  "Offset TRCD Min"));

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_timing_mtb, l_timing_ftb, SET_DRAM_TRCD, "TRCDmin", l_field));

            FAPI_TRY(mss::attr::set_dram_trcd(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tcp min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trp_min(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_timing_mtb = 0;
            uint8_t l_timing_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRP_MIN, i_spd, SET_DRAM_TRP, l_timing_mtb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TRP_MIN, i_spd, SET_DRAM_TRP, l_timing_ftb));

            // Range checks
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trp_min(l_timing_mtb),
                                  F::TRP_MIN.get_byte(i_spd),
                                  l_timing_mtb,
                                  SET_DRAM_TRP,
                                  "TRP Min"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_offset_trp_min(l_timing_ftb),
                                  F::OFFSET_TRP_MIN.get_byte(i_spd),
                                  l_timing_ftb,
                                  SET_DRAM_TRP,
                                  "Offset TRP Min"));

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_timing_mtb, l_timing_ftb, SET_DRAM_TRP, "TRPmin", l_field));

            FAPI_TRY(mss::attr::set_dram_trp(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tras min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trasmin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_trasmin_msn = 0;
            uint8_t l_trasmin_lsb = 0;
            uint32_t l_trasmin = 0;

            // There is no fine offset for this field, this will remain 0
            uint32_t l_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRASMIN_MSN, i_spd, SET_DRAM_TRAS, l_trasmin_msn));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRASMIN_LSB, i_spd, SET_DRAM_TRAS, l_trasmin_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trasmin_msn(l_trasmin_msn),
                                  F::TRASMIN_MSN.get_byte(i_spd),
                                  l_trasmin_msn,
                                  SET_DRAM_TRAS,
                                  "TRAS MSN"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trasmin_lsb(l_trasmin_lsb),
                                  F::TRASMIN_LSB.get_byte(i_spd),
                                  l_trasmin_lsb,
                                  SET_DRAM_TRAS,
                                  "TRAS LSB"));

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_trasmin_msn, l_trasmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_ocmb, l_buffer, get_spd_revision(), SET_DRAM_TRAS));
                l_trasmin = l_buffer;

                FAPI_INF("%s. Minimum Active to Precharge Delay Time (tRASmin) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         l_trasmin);
            }

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_trasmin, l_ftb, SET_DRAM_TRAS, "TRASmin", l_field));

            FAPI_TRY(mss::attr::set_dram_tras(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[in] i_spd SPD binary
        /// @param[out] o_value tRFC1min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc1(const std::vector<uint8_t>& i_spd, int64_t& o_value) const
        {
            uint8_t l_trfc1min_msb = 0;
            uint8_t l_trfc1min_lsb = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC1MIN_MSB, i_spd, SET_DRAM_TRFC, l_trfc1min_msb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC1MIN_LSB, i_spd, SET_DRAM_TRFC, l_trfc1min_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc1min_msb(l_trfc1min_msb),
                                  F::TRFC1MIN_MSB.get_byte(i_spd),
                                  l_trfc1min_msb,
                                  SET_DRAM_TRFC,
                                  "TRFC1 MSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc1min_lsb(l_trfc1min_lsb),
                                  F::TRFC1MIN_LSB.get_byte(i_spd),
                                  l_trfc1min_lsb,
                                  SET_DRAM_TRFC,
                                  "TRFC1 LSB"));
            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc1min_msb, l_trfc1min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_ocmb, l_buffer, get_spd_revision(), TRFC1MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[in] i_spd SPD binary
        /// @param[out] o_value tRFC2min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc2(const std::vector<uint8_t>& i_spd, int64_t& o_value) const
        {
            uint8_t l_trfc2min_msb = 0;
            uint8_t l_trfc2min_lsb = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC2MIN_MSB, i_spd, SET_DRAM_TRFC, l_trfc2min_msb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC2MIN_LSB, i_spd, SET_DRAM_TRFC, l_trfc2min_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc2min_msb(l_trfc2min_msb),
                                  F::TRFC2MIN_MSB.get_byte(i_spd),
                                  l_trfc2min_msb,
                                  SET_DRAM_TRFC,
                                  "TRFC2 MSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc2min_lsb(l_trfc2min_lsb),
                                  F::TRFC2MIN_LSB.get_byte(i_spd),
                                  l_trfc2min_lsb,
                                  SET_DRAM_TRFC,
                                  "TRFC2 LSB"));
            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc2min_msb, l_trfc2min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_ocmb, l_buffer, get_spd_revision(), TRFC2MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[in] i_spd SPD binary
        /// @param[out] o_value tRFC4min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc4(const std::vector<uint8_t>& i_spd, int64_t& o_value) const
        {
            uint8_t l_trfc4min_msb = 0;
            uint8_t l_trfc4min_lsb = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC4MIN_MSB, i_spd, SET_DRAM_TRFC, l_trfc4min_msb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TRFC4MIN_LSB, i_spd, SET_DRAM_TRFC, l_trfc4min_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc4min_msb(l_trfc4min_msb),
                                  F::TRFC4MIN_MSB.get_byte(i_spd),
                                  l_trfc4min_msb,
                                  SET_DRAM_TRFC,
                                  "TRFC4 MSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_trfc4min_lsb(l_trfc4min_lsb),
                                  F::TRFC4MIN_LSB.get_byte(i_spd),
                                  l_trfc4min_lsb,
                                  SET_DRAM_TRFC,
                                  "TRFC4 LSB"));

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc4min_msb, l_trfc4min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_ocmb, l_buffer, get_spd_revision(), TRFC4MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the trfc field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trfc(const std::vector<uint8_t>& i_spd) const
        {
            int64_t l_tck_in_ps = 0;
            uint64_t l_freq = 0;
            uint8_t l_refresh_mode = 0;
            int64_t l_trfc_mtb = 0;
            int64_t l_trfc_in_ps = 0;
            uint16_t l_trfc_in_nck = 0;

            FAPI_TRY( attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                      "%s Failed to calculate clock period (tCK)", spd::c_str(iv_dimm) );

            FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );

            // Selects appropriate tRFC based on fine refresh mode
            switch(l_refresh_mode)
            {
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
                    FAPI_TRY(min_trfc1(i_spd, l_trfc_mtb),
                             "%s Failed to decode SPD for tRFC1", spd::c_str(iv_dimm) );
                    break;

                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
                    FAPI_TRY(min_trfc2(i_spd, l_trfc_mtb),
                             "%s Failed to decode SPD for tRFC2", spd::c_str(iv_dimm) );
                    break;

                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
                    FAPI_TRY(min_trfc4(i_spd, l_trfc_mtb),
                             "%s Failed to decode SPD for tRFC4", spd::c_str(iv_dimm) );
                    break;

                default:
                    // Fine Refresh Mode will be a platform attribute set by the MRW,
                    // which they "shouldn't" mess up as long as use "attribute" enums.
                    // if openpower messes this up we can at least catch it
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                                set_FINE_REF_MODE(l_refresh_mode),
                                "%s Incorrect Fine Refresh Mode received: %d ",
                                spd::c_str(iv_dimm),
                                l_refresh_mode);
                    break;
            }// switch

            // Calculate trfc (in ps)
            {
                uint8_t l_trfc_ftb = 0;
                uint8_t l_ftb = 0;
                uint8_t l_mtb = 0;

                FAPI_TRY( spd::get_timebases(iv_ocmb, i_spd, l_mtb, l_ftb) );

                FAPI_INF( "%s medium timebase (ps): %ld, fine timebase (ps): %ld, tRFC (MTB): %ld, tRFC(FTB): %ld",
                          spd::c_str(iv_dimm), l_mtb, l_ftb, l_trfc_mtb, l_trfc_ftb );

                l_trfc_in_ps = spd::calc_timing_from_timebase(l_trfc_mtb, l_mtb, l_trfc_ftb, l_ftb);
            }

            {
                // Calculate refresh cycle time in nCK & set attribute

                // Calculate nck
                FAPI_TRY( spd::calc_nck(mss::generic_ffdc_codes::SET_TREFC, l_trfc_in_ps, l_tck_in_ps,
                                        spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_in_nck),
                          "%s Error in calculating l_tRFC, with value of l_trfc_in_ps: %d", spd::c_str(iv_dimm), l_trfc_in_ps);

                FAPI_INF("%s tCK (ps): %d, tRFC (ps): %d, tRFC (nck): %d",
                         spd::c_str(iv_dimm), l_tck_in_ps, l_trfc_in_ps, l_trfc_in_nck);

                FAPI_DBG("%s DRAM TRFC %d", spd::c_str(iv_dimm), l_trfc_in_nck);
            }

            FAPI_TRY(mss::attr::set_dram_trfc(iv_port, l_trfc_in_nck));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tfawmin msn object
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_tfawmin(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_tfawmin_msn = 0;
            uint8_t l_tfawmin_lsb = 0;
            uint32_t l_tfawmin = 0;

            // There is no fine offset for this field, this will remain 0
            uint32_t l_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TFAWMIN_MSN, i_spd, SET_DRAM_TFAW, l_tfawmin_msn));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TFAWMIN_LSB, i_spd, SET_DRAM_TFAW, l_tfawmin_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_tfawmin_msn(l_tfawmin_msn),
                                  F::TFAWMIN_MSN.get_byte(i_spd),
                                  l_tfawmin_msn,
                                  SET_DRAM_TFAW,
                                  "TFAW S MSN"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_tfawmin_lsb(l_tfawmin_lsb),
                                  F::TFAWMIN_LSB.get_byte(i_spd),
                                  l_tfawmin_lsb,
                                  SET_DRAM_TFAW,
                                  "TFAW S LSB"));

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_tfawmin_msn, l_tfawmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_ocmb, l_buffer, get_spd_revision(), SET_DRAM_TFAW));
                l_tfawmin = l_buffer;

                FAPI_INF("%s. TFAW_MIN in MTB units: %d",
                         spd::c_str(iv_dimm),
                         l_tfawmin);
            }

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_tfawmin, l_ftb, SET_DRAM_TFAW, "TFAW", l_field));

            FAPI_TRY(mss::attr::set_dram_tfaw(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the trrd l min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trrd_l(const std::vector<uint8_t>& i_spd) const
        {
            // Taking the worst case required minimum JEDEC value
            // instead of calculating proposed value from SPD -- which selects optimistic values
            // leading to errors in expected timing values
            uint8_t l_dram_width = 0;
            uint64_t l_trrd_l_in_nck = 0;
            uint64_t l_freq = 0;

            FAPI_TRY( attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( attr::get_dram_width(iv_dimm, l_dram_width) );
            FAPI_TRY( trrd_l( iv_dimm, l_dram_width, l_freq, l_trrd_l_in_nck) );

            FAPI_INF("%s SDRAM width: %d, tRRD_L (nck): %d",
                     spd::c_str(iv_dimm), l_dram_width, l_trrd_l_in_nck);

            FAPI_DBG("%s DRAM TRRD_L %d", spd::c_str(iv_dimm), l_trrd_l_in_nck);

            FAPI_TRY(mss::attr::set_dram_trrd_l(iv_port, l_trrd_l_in_nck));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the tccd l min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_tccd_l(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_timing_mtb = 0;
            uint8_t l_timing_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TCCD_L_MIN, i_spd, SET_DRAM_TCCD_L, l_timing_mtb));
            FAPI_TRY(get_field_spd(iv_ocmb, F::OFFSET_TCCD_L_MIN, i_spd, SET_DRAM_TCCD_L, l_timing_ftb));

            // Range checks
            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_tccd_l_min(l_timing_mtb),
                                  F::TCCD_L_MIN.get_byte(i_spd),
                                  l_timing_mtb,
                                  SET_DRAM_TCCD_L,
                                  "TCCD_L Min"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_offset_tccd_l_min(l_timing_ftb),
                                  F::OFFSET_TCCD_L_MIN.get_byte(i_spd),
                                  l_timing_ftb,
                                  SET_DRAM_TCCD_L,
                                  "Offset TCCD_L Min"));

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_timing_mtb, l_timing_ftb, SET_DRAM_TCCD_L, "TCCD_l", l_field));

            // If our uint8_t equals our uint32_t, we do not have an overflow
            // Otherwise, assert out
            FAPI_ASSERT(static_cast<uint8_t>(l_field) == l_field,
                        fapi2::MSS_TCCDL_OVERFLOW_CALC()
                        .set_MTB(l_timing_mtb)
                        .set_FTB(l_timing_ftb)
                        .set_RESULT(l_field)
                        .set_DIMM_TARGET(iv_dimm),
                        "%s had a tCCD_l overflow of %u. MTB:%u FTB:%u",
                        mss::c_str(iv_dimm), l_timing_mtb, l_timing_ftb, l_field);

            FAPI_TRY(mss::attr::set_dram_tccd_l(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the twr min field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_twrmin(const std::vector<uint8_t>& i_spd) const
        {

            uint8_t l_twrmin_msn = 0;
            uint8_t l_twrmin_lsb = 0;
            uint32_t l_twrmin = 0;

            // There is no fine offset for this field, this will remain 0
            uint32_t l_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TWRMIN_MSN, i_spd, SET_DRAM_TWR, l_twrmin_msn));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWRMIN_LSB, i_spd, SET_DRAM_TWR, l_twrmin_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twrmin_msn(l_twrmin_msn),
                                  F::TWRMIN_MSN.get_byte(i_spd),
                                  l_twrmin_msn,
                                  SET_DRAM_TWR,
                                  "TWR S MSN"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twrmin_lsb(l_twrmin_lsb),
                                  F::TWRMIN_LSB.get_byte(i_spd),
                                  l_twrmin_lsb,
                                  SET_DRAM_TWR,
                                  "TWR S LSB"));

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_twrmin_msn, l_twrmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_ocmb, l_buffer, get_spd_revision(), SET_DRAM_TWR));
                l_twrmin = l_buffer;

                FAPI_INF("%s. TWR_MIN in MTB units: %d",
                         spd::c_str(iv_dimm),
                         l_twrmin);
            }

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_twrmin, l_ftb, SET_DRAM_TWR, "TWRmin", l_field));

            FAPI_TRY(mss::attr::set_dram_twr(iv_port, static_cast<uint8_t>(l_field)));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the trtp field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trtp(const std::vector<uint8_t>& i_spd) const
        {
            int64_t l_tck_in_ps = 0;
            uint64_t l_freq = 0;

            // Values from proposed DDR4 Full spec update(79-4A)
            // Item No. 1716.78C
            // Page 241 & 246
            constexpr int64_t l_max_trtp_in_ps = trtp();
            uint8_t l_calc_trtp_in_nck = 0;

            FAPI_TRY(mss::attr::get_freq(iv_port, l_freq));
            FAPI_TRY(freq_to_ps(l_freq, l_tck_in_ps),
                     "%s Failed to calculate clock period (tCK)", spd::c_str(iv_dimm) );

            // Calculate nck
            FAPI_TRY(spd::calc_nck(mss::generic_ffdc_codes::SET_TRTP, l_max_trtp_in_ps, l_tck_in_ps,
                                   spd::INVERSE_DDR4_CORRECTION_FACTOR, l_calc_trtp_in_nck),
                     "%s Error in calculating trtp, with value of l_twtr_in_ps: %d",
                     spd::c_str(iv_dimm), l_max_trtp_in_ps);

            FAPI_INF("%s tCK (ps): %d, tRTP (ps): %d, tRTP (nck): %d",
                     spd::c_str(iv_dimm), l_tck_in_ps, l_max_trtp_in_ps, l_calc_trtp_in_nck);

            FAPI_DBG("%s DRAM TRTP %d", spd::c_str(iv_dimm), l_calc_trtp_in_nck);

            FAPI_TRY(mss::attr::set_dram_trtp(iv_port, l_calc_trtp_in_nck));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the twtr min s
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_twtrmin_s(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_twtrmin_s_msn = 0;
            uint8_t l_twtrmin_s_lsb = 0;
            uint32_t l_twtrmin_s = 0;

            // There is no fine offset for this field, this will remain 0
            uint32_t l_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_S_MSN, i_spd, SET_DRAM_TWTR_S, l_twtrmin_s_msn));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_S_LSB, i_spd, SET_DRAM_TWTR_S, l_twtrmin_s_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twtrmin_s_msn(l_twtrmin_s_msn),
                                  F::TWTRMIN_S_MSN.get_byte(i_spd),
                                  l_twtrmin_s_msn,
                                  SET_DRAM_TWTR_S,
                                  "TWTRMIN S MSN"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twtrmin_s_lsb(l_twtrmin_s_lsb),
                                  F::TWTRMIN_S_LSB.get_byte(i_spd),
                                  l_twtrmin_s_lsb,
                                  SET_DRAM_TWTR_S,
                                  "TWTRMIN S LSB"));

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_twtrmin_s_msn, l_twtrmin_s_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_ocmb, l_buffer, get_spd_revision(), SET_DRAM_TWTR_S));
                l_twtrmin_s = l_buffer;

                FAPI_INF("%s. Minimum Write to Read Time - Different Bank Group (tWTR_Smin) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         l_twtrmin_s);
            }

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_twtrmin_s, l_ftb, SET_DRAM_TWTR_S, "TWTRmin s", l_field));

            FAPI_TRY(mss::attr::set_dram_twtr_s(iv_port, static_cast<uint8_t>(l_field)));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the twtr min l
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_twtrmin_l(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_twtrmin_l_msn = 0;
            uint8_t l_twtrmin_l_lsb = 0;
            uint32_t l_twtrmin_l = 0;

            // There is no fine offset for this field, this will remain 0
            uint32_t l_ftb = 0;
            uint32_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_L_MSN, i_spd, SET_DRAM_TWTR_L, l_twtrmin_l_msn));
            FAPI_TRY(get_field_spd(iv_ocmb, F::TWTRMIN_L_LSB, i_spd, SET_DRAM_TWTR_L, l_twtrmin_l_lsb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twtrmin_l_msn(l_twtrmin_l_msn),
                                  F::TWTRMIN_L_MSN.get_byte(i_spd),
                                  l_twtrmin_l_msn,
                                  SET_DRAM_TWTR_L,
                                  "TWTRMIN L MSN"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_twtrmin_l_lsb(l_twtrmin_l_lsb),
                                  F::TWTRMIN_L_LSB.get_byte(i_spd),
                                  l_twtrmin_l_lsb,
                                  SET_DRAM_TWTR_L,
                                  "TWTRMIN L LSB"));

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_twtrmin_l_msn, l_twtrmin_l_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_ocmb, l_buffer, get_spd_revision(), SET_DRAM_TWTR_L));
                l_twtrmin_l = l_buffer;

                FAPI_INF("%s. Minimum Write to Read Time - Different Bank Group (tWTR_Lmin) in MTB units: %d",
                         spd::c_str(iv_dimm),
                         l_twtrmin_l);
            }

            FAPI_TRY(mss::calc_spd_time_in_nck(iv_dimm, i_spd, l_twtrmin_l, l_ftb, SET_DRAM_TWTR_L, "TWTRmin l", l_field));

            FAPI_TRY(mss::attr::set_dram_twtr_l(iv_port, static_cast<uint8_t>(l_field)));
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the trrd s field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_offset_trrd_s(const std::vector<uint8_t>& i_spd) const
        {
            // Taking the worst case required minimum JEDEC value
            // instead of calculating proposed value from SPD -- which selects optimistic values
            // leading to errors in expected timing values
            uint64_t l_trrd_s_in_nck = 0;
            uint64_t l_freq = 0;
            uint8_t l_dram_width = 0;
            FAPI_TRY( attr::get_dram_width(iv_dimm, l_dram_width) );
            FAPI_TRY( attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( trrd_s( iv_dimm, l_dram_width, l_freq, l_trrd_s_in_nck) );

            FAPI_INF("%s SDRAM width: %d, tRRD_S (nck): %d",
                     spd::c_str(iv_dimm), l_dram_width, l_trrd_s_in_nck);

            FAPI_DBG("%s DRAM TRRD_S %d", spd::c_str(iv_dimm), l_trrd_s_in_nck);

            FAPI_TRY(mss::attr::set_dram_trrd_s(iv_port, l_trrd_s_in_nck));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the offset trfc dlr field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_offset_trfc_dlr(const std::vector<uint8_t>& i_spd) const
        {
            int64_t l_tck_in_ps = 0;
            uint64_t l_freq = 0;
            uint8_t l_refresh_mode = 0;
            uint8_t l_dram_density = 0;
            uint64_t l_trfc_dlr_in_ps = 0;
            uint16_t l_trfc_dlr_in_nck = 0;

            FAPI_TRY( attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                      "%s Failed to calculate clock period (tCK)", spd::c_str(iv_dimm) );

            FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );
            FAPI_TRY( mss::attr::get_dram_density(iv_dimm, l_dram_density) );

            // Calculate refresh cycle time in ps
            FAPI_TRY( calc_trfc_dlr(iv_dimm, l_refresh_mode, l_dram_density, l_trfc_dlr_in_ps),
                      "%s Failed calc_trfc_dlr()", spd::c_str(iv_dimm) );

            // Calculate refresh cycle time in nck
            FAPI_TRY( spd::calc_nck(mss::generic_ffdc_codes::OFFSET_TRFC_DLR, l_trfc_dlr_in_ps, static_cast<uint64_t>(l_tck_in_ps),
                                    spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                    l_trfc_dlr_in_nck));

            FAPI_INF("%s tCK (ps): %d, tRFC_DLR (ps): %d, tRFC_DLR (nck): %d",
                     spd::c_str(iv_dimm), l_tck_in_ps, l_trfc_dlr_in_ps, l_trfc_dlr_in_nck);

            FAPI_DBG("%s DRAM TRFC_DLR %d", spd::c_str(iv_dimm), l_trfc_dlr_in_nck);

            FAPI_TRY(mss::attr::set_dram_trfc_dlr(iv_port, l_trfc_dlr_in_nck));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the offset trfc dlr field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_trefi(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_refresh_mode = 0;
            uint8_t l_refresh_rate = 0;
            uint64_t l_trefi_in_ps = 0;
            int64_t l_tck_in_ps = 0;
            uint64_t l_freq = 0;

            FAPI_TRY( attr::get_freq(iv_port, l_freq) );
            FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                      "%s Failed to calculate clock period (tCK)", spd::c_str(iv_dimm) );

            FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );
            FAPI_TRY( mss::attr::get_mrw_refresh_rate_request(l_refresh_rate) );

            switch(l_refresh_mode)
            {
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:

                    FAPI_TRY( calc_trefi( mss::refresh_rate::REF1X,
                                          l_refresh_rate,
                                          l_trefi_in_ps),
                              "%s Failed to calculate tREF1", spd::c_str(iv_dimm) );
                    break;

                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:

                    FAPI_TRY( calc_trefi( mss::refresh_rate::REF2X,
                                          l_refresh_rate,
                                          l_trefi_in_ps),
                              "%s Failed to calculate tREF2", spd::c_str(iv_dimm) );
                    break;

                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
                case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:

                    FAPI_TRY( calc_trefi( mss::refresh_rate::REF4X,
                                          l_refresh_rate,
                                          l_trefi_in_ps),
                              "%s Failed to calculate tREF4", spd::c_str(iv_dimm) );
                    break;

                default:
                    // Fine Refresh Mode will be a platform attribute set by the MRW,
                    // which they "shouldn't" mess up as long as use "attribute" enums.
                    // if openpower messes this up we can at least catch it
                    FAPI_ASSERT(false,
                                fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                                set_FINE_REF_MODE(l_refresh_mode),
                                "%s Incorrect Fine Refresh Mode received: %d ",
                                spd::c_str(iv_dimm),
                                l_refresh_mode);
                    break;
            };

            {
                // Calculate refresh cycle time in nCK & set attribute
                constexpr double PERCENT_ADJUST = 0.99;

                // Calculate nck
                uint64_t l_trefi_in_nck = 0;
                FAPI_TRY(  spd::calc_nck( mss::generic_ffdc_codes::SET_TREFI,
                                          l_trefi_in_ps,
                                          static_cast<uint64_t>(l_tck_in_ps),
                                          spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                          l_trefi_in_nck),
                           "%s Error in calculating tREFI, with value of l_trefi_in_ps: %d", spd::c_str(iv_dimm), l_trefi_in_ps);

                // Lab requested 99% of tREFI calculation to avoid any latency impact and violation of any
                // refresh specification (across all number of ranks and frequencies) observed
                // during lab power/thermal tests.

                FAPI_INF("%s adjusting tREFI calculation by 99%, calculated tREFI (nck): %lu, adjusted tREFI (nck): %lu,",
                         spd::c_str(iv_dimm), l_trefi_in_nck, l_trefi_in_nck * PERCENT_ADJUST);

                // The compiler does this under the covers but just to be explicit on intent:
                // Floating point arithmetic and truncation of result saved to an unsigned integer
                l_trefi_in_nck = static_cast<double>(l_trefi_in_nck * PERCENT_ADJUST);

                FAPI_INF("%s tCK (ps): %d, tREFI (ps): %d, tREFI (nck): %d",
                         spd::c_str(iv_dimm), l_tck_in_ps, l_trefi_in_ps, l_trefi_in_nck);

                FAPI_TRY(mss::attr::set_dram_trefi(iv_port, l_trefi_in_nck));

                FAPI_DBG("%s DRAM TREFI %d", spd::c_str(iv_dimm), l_trefi_in_nck);
            }

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

            // Timing fields
            FAPI_TRY(set_taa(i_spd));
            FAPI_TRY(set_trcd_min(i_spd));
            FAPI_TRY(set_trp_min(i_spd));
            FAPI_TRY(set_trasmin(i_spd));
            FAPI_TRY(set_trfc(i_spd));
            FAPI_TRY(set_tfawmin(i_spd));
            FAPI_TRY(set_trrd_l(i_spd));
            FAPI_TRY(set_tccd_l(i_spd));
            FAPI_TRY(set_twrmin(i_spd));
            FAPI_TRY(set_trtp(i_spd));
            FAPI_TRY(set_twtrmin_s(i_spd));
            FAPI_TRY(set_twtrmin_l(i_spd));
            FAPI_TRY(set_offset_trrd_s(i_spd));
            FAPI_TRY(set_offset_trfc_dlr(i_spd));
            FAPI_TRY(set_trefi(i_spd));

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
