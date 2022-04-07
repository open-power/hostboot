/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_planar_rdimm_engine.H $ */
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
/// @file p10_planar_rdimm_engine.H
/// @brief RDIMM Module section eff_config engine for planar config
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI
// EKB-Mirror-To: hostboot

#ifndef _P10_PLANAR_RDIMM_ENGINE_H_
#define _P10_PLANAR_RDIMM_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/utils/find.H>

#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <lib/eff_config/p10_ddimm_engine.H>

namespace mss
{
namespace spd
{

///
/// @brief Class for DDR4 Planar RDIMM SPD Rev 1.1
///
class planar_rdimm_ddr4_1_1 : public ddimm_0_4
{
        using ISDIMM_F = mss::spd::fields<DDR4, BASE_CNFG>;
        using RDIMM_F = mss::spd::fields<DDR4, RDIMM_MODULE>;

    public:
        ///
        /// @brief Construct a new planar rdimm rev 1.1 object
        ///
        /// @param[in] i_dimm
        ///
        planar_rdimm_ddr4_1_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm) : ddimm_0_4(i_dimm)
        {
        }

        virtual ~planar_rdimm_ddr4_1_1() = default;

        ///
        /// @brief Get the spd revision
        /// @return mss::spd::rev enum value
        ///
        virtual mss::spd::rev get_spd_revision() const
        {
            return mss::spd::rev::V1_1;
        }

        // Virtual function overloads go here

        ///
        /// @brief Get the DIMM type
        /// @return DIMM type value
        ///
        virtual uint8_t get_dimm_type() const
        {
            return fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM;
        }

        ///
        /// @brief Set the module rcd field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note we always have an RCD for this config
        ///
        virtual fapi2::ReturnCode set_module_rcd(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = fapi2::ENUM_ATTR_MEM_EFF_SUPPORTED_RCD_RCD_PER_CHANNEL_1;

            FAPI_TRY(mss::attr::set_supported_rcd(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the address mirror field
        ///
        /// @param[in] i_spd SPD
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note this comes from byte 136 from the ISDIMM SPD
        ///
        virtual fapi2::ReturnCode set_address_mirror(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_field = 0;

            FAPI_TRY(get_field_spd(iv_ocmb, RDIMM_F::ADDR_MAP_REG_TO_DRAM, i_spd, exp::SET_EXP_DRAM_ADDRESS_MIRRORING, l_field));

            // Copy the mirroring setting to all odd ranks
            l_field = (l_field == 0x01) ? 0x0A : 0x00;

            FAPI_TRY(mss::attr::set_exp_dram_address_mirroring(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the module mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note this comes from bytes 320-321 in the ISDIMM SPD
        ///
        virtual fapi2::ReturnCode set_module_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            // These fields overwrite those set by the base cnfg decoder - for DDIMMS, these
            // fields live in different bytes, so long as this module section is performed after
            // the base cnfg section, this will work as-is.
            uint8_t l_byte0 = 0;
            uint8_t l_byte1 = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, ISDIMM_F::CONTINUATION_CODES, i_spd, SET_MODULE_MFG_ID, l_byte0));
            FAPI_TRY(get_field_spd(iv_ocmb, ISDIMM_F::LAST_NON_ZERO_BYTE, i_spd, SET_MODULE_MFG_ID, l_byte1));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_mfg_id_code_lsb(l_byte0),
                                  ISDIMM_F::CONTINUATION_CODES.get_byte(i_spd),
                                  l_byte0,
                                  SET_MODULE_MFG_ID,
                                  "Module MFG ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_module_mfg_id_code_msb(l_byte1),
                                  ISDIMM_F::LAST_NON_ZERO_BYTE.get_byte(i_spd),
                                  l_byte1,
                                  SET_MODULE_MFG_ID,
                                  "Module MFG ID MSB"));

            right_aligned_insert(l_buffer, l_byte1, l_byte0);
            l_field = l_buffer;

            fapi2::endian_swap(l_field);
            FAPI_INF("%s. Module Manufacturer ID Code: 0x%04x",
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
        /// @note this comes from bytes 350-351 in the ISDIMM SPD
        ///
        virtual fapi2::ReturnCode set_dram_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            // These fields overwrite those set by the base cnfg decoder - for DDIMMS, these
            // fields live in different bytes, so long as this module section is performed after
            // the base cnfg section, this will work as-is.
            uint8_t l_mfgid_lsb = 0;
            uint8_t l_mfgid_msb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, ISDIMM_F::DRAM_MFR_ID_CODE_LSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, ISDIMM_F::DRAM_MFR_ID_CODE_MSB, i_spd, SET_DRAM_MFG_ID, l_mfgid_msb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_lsb(l_mfgid_lsb),
                                  ISDIMM_F::DRAM_MFR_ID_CODE_LSB.get_byte(i_spd),
                                  l_mfgid_lsb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM MFR ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_dram_mfr_id_code_msb(l_mfgid_msb),
                                  ISDIMM_F::DRAM_MFR_ID_CODE_MSB.get_byte(i_spd),
                                  l_mfgid_msb,
                                  SET_DRAM_MFG_ID,
                                  "DRAM MFR ID MSB"));

            right_aligned_insert(l_buffer, l_mfgid_msb, l_mfgid_lsb);

            l_field = l_buffer;

            fapi2::endian_swap(l_field);
            FAPI_INF("%s.DRAM Manufacturer ID Code: %x",
                     mss::spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_dram_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set the rcd mfg id field
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        /// @note this comes from bytes 133-134 in the ISDIMM SPD
        ///
        virtual fapi2::ReturnCode set_rcd_mfg_id(const std::vector<uint8_t>& i_spd) const
        {
            uint8_t l_lsb = 0;
            uint8_t l_msb = 0;
            uint16_t l_field = 0;
            fapi2::buffer<uint16_t> l_buffer;

            FAPI_TRY(get_field_spd(iv_ocmb, RDIMM_F::CONTINUATION_CODES, i_spd, SET_RCD_MFG_ID, l_lsb));
            FAPI_TRY(get_field_spd(iv_ocmb, RDIMM_F::LAST_NON_ZERO_BYTE, i_spd, SET_RCD_MFG_ID, l_msb));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_mfg_id_lsb(l_lsb),
                                  RDIMM_F::CONTINUATION_CODES.get_byte(i_spd),
                                  l_lsb,
                                  SET_RCD_MFG_ID,
                                  "RCD MFG ID LSB"));

            FAPI_TRY_NO_TRACE(mss::check::invalid_value(
                                  iv_ocmb,
                                  check_rcd_mfg_id_msb(l_msb),
                                  RDIMM_F::LAST_NON_ZERO_BYTE.get_byte(i_spd),
                                  l_msb,
                                  SET_RCD_MFG_ID,
                                  "RCD MFG ID MSB"));

            right_aligned_insert(l_buffer, l_msb, l_lsb);

            l_field = l_buffer;

            // The RCD MFG ID attribute is a different endianness from the other MSB/LSB attributes
            // so in this case, we do not need to do an endian swap
            FAPI_INF("%s. RCD Manufacturer ID Code: %x",
                     mss::spd::c_str(iv_dimm),
                     l_field);

            FAPI_TRY(mss::attr::set_rcd_mfg_id(iv_dimm, l_field));

        fapi_try_exit:
            return fapi2::current_err;
        }


        /// @brief Process the fields for ddimm rev 0.4, then the ISDIMM overrides
        ///
        /// @param[in] i_spd SPD binary
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
        ///
        fapi2::ReturnCode process(const std::vector<uint8_t>& i_spd) const
        {
            FAPI_TRY(ddimm_0_4::process(i_spd));

        fapi_try_exit:
            return fapi2::current_err;
        }

};

//
// Can be updated with the earliest supported ddimm module revision
//
using planar_rdimm_base_latest = planar_rdimm_ddr4_1_1;

} // spd

}// mss

#endif
