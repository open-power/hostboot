/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_common_engine.H $ */
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
/// @file p10_common_engine.H
/// @brief Configuration for common SPD fields
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_COMMON_ENGINE_H_
#define _P10_COMMON_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/utils/find.H>

#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/dimm/mss_ddr4_timing.H>
#include <generic/memory/lib/spd/spd_checker.H>

namespace mss
{
namespace spd
{

///
/// @brief Class for setting up attributes from fields common to all DRAM generations
///
class common_engine
{
        using FIELDS = mss::spd::common_init_fields;

    protected:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> iv_port;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    public:

        ///
        /// @brief Construct a new common_engine object
        /// @param[in] i_dimm DIMM target
        ///
        common_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) :
            iv_dimm(i_dimm),
            iv_port(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm)),
            iv_ocmb(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm)) {}

        ///
        /// @brief Destroy the common_engine object
        ///
        virtual ~common_engine() = default;

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
        /// @brief Set the revision field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode set_revision(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;
            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::REVISION, i_spd, SET_SPD_REVISION, l_field));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_revision(l_field),
                                  FIELDS::REVISION.get_byte(i_spd),
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
            // DDR5 SPD Document
            // Byte 2 (0x002): Key Byte / DRAM Device Type
            // =========================================================
            const std::vector< std::pair<uint8_t, uint8_t> > DRAM_GEN_MAP =
            {
                //{key value, dram gen}
                {0x0C, fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4},
                {0x12, fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5},
                // Other key bytes reserved or not supported
            };

            FAPI_TRY(get_field_spd(iv_ocmb, FIELDS::DEVICE_TYPE, i_spd, SET_DRAM_GEN, l_field));
            FAPI_TRY(check::reserved_values(iv_ocmb, l_reserved_bits, SET_DRAM_GEN, l_field) );

            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_GEN_MAP, SET_DRAM_GEN, l_field, l_dram_gen),
                     "%s failed DRAM_GEN lookup check", spd::c_str(iv_dimm) );
            FAPI_TRY(mss::attr::set_dram_gen(iv_dimm, l_dram_gen));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Process the common fields
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        virtual fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            FAPI_TRY(set_revision(i_spd));
            FAPI_TRY(set_dram_gen(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }

};

} // spd
} // mss

#endif
