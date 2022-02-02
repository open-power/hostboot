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
#include <generic/memory/lib/utils/find.H>

#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/spd/spd_checker.H>

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
            // DDR5 SPD Document
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
            // DDR5 SPD Document
            // Byte 3 (0x003): Key Byte / Module Type - Hybrid
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MEMORY_TYPE_MAP =
            {

                //{key byte, dimm type}
                {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NONE},
                {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NVDIMM_N},
                {2, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NVDIMM_P},
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
            // DDR5 SPD Document
            // Byte 3 (0x003): Key Byte / Module Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP =
            {
                //{key byte, dimm type}
                {10, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM},
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
        /// @brief Gets the number of package ranks per channel
        ///
        /// @param[in] i_spd SPD binary
        /// @param[out] o_die_per_package number of DRAM dies included in a package
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode get_package_ranks_per_channel(const std::vector<uint8_t>& i_spd,
                uint8_t& o_die_per_package) const
        {
            uint8_t l_field = 0;
            o_die_per_package = 0;

            const std::vector<uint8_t> l_reserved_bits{0b001, 0b110, 0b111};

            // =========================================================
            // DDR5 SPD Document
            // Byte 4 (0x004): First SDRAM Density and Package
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DIE_PER_PACKAGE_MAP =
            {
                //{key byte, dimm type}
                {0b000, 1},
                {0b010, 2},
                {0b011, 4},
                {0b100, 8},
                {0b101, 16},
                // All others reserved or not supported
            };

            FAPI_TRY( mss::spd::get_field_spd(iv_ocmb, FIELDS::PACKAGE_RANKS_PER_CHANNEL, i_spd, SET_PRIM_DIE_COUNT, l_field));
            FAPI_TRY( mss::spd::check::reserved_values(iv_ocmb, l_reserved_bits, SET_PRIM_DIE_COUNT, l_field) );

            FAPI_TRY( lookup_table_check(iv_dimm, DIE_PER_PACKAGE_MAP, SET_PRIM_DIE_COUNT, l_field, o_die_per_package),
                      "%s failed DIE_PER_PACKAGE lookup check", spd::c_str(iv_dimm) );

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
            // DDR5 SPD Document Release Preliminary
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
            // TODO:ZEN:MST-1421 Add DDR5 SPD support for set_host_to_ddr_speed_ratio
            // Note:  really a DDIMM trait instead of a base trait, as such this code might need to be moved
            // FAPI_TRY(set_host_to_ddr_speed_ratio(i_spd));
            FAPI_TRY(set_num_master_ranks_per_dimm(i_spd)); // AKA mranks
            FAPI_TRY(set_hybrid(i_spd));
            FAPI_TRY(set_hybrid_media(i_spd));
            FAPI_TRY(set_dimm_type(i_spd));

            // Generic_metadata_fields
            // TODO:ZEN:MST-1373 Create dimmPosTraits specialization for Odyssey
            // TK FAPI_TRY(set_dimm_pos_metadata(i_spd));
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
            // TK fill this in - just looking to get it so we can compile now
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Process derived attributes (processed after all others)
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode set_FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process_derived(const std::vector<uint8_t>& i_spd) const
        {
            // TK fill this in - just looking to get it so we can compile now
            return fapi2::FAPI2_RC_SUCCESS;
        }

};

} // ddr5

} // spd

} // mss

#endif
